#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Reconstruction batch mass_0333, image
// 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9.
//
// Addresses 0x6915b0-0x692372: the render-state object at self+0x1b8 (0x1c
// bytes), and the block/row allocator whose 0x54-byte manager sits at self[1].
// The manager vtable is filled in at 0x692220; the row records are 0x248-byte
// structures linked through +0x2c.
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// External helpers observed in the supplied corpus listings.
// ---------------------------------------------------------------------------
extern void      FUN_00691160();
extern void      FUN_00691570(int32_t* self);
extern void      FUN_006916d0(int32_t* self);
extern void*     FUN_006ae280(int32_t* self, uint32_t size);
extern void      FUN_006ae2b0(int32_t* self, void* block, int32_t size);
extern int32_t   FUN_006ae2d0(int32_t* self, int32_t totalA, int32_t totalB, int32_t allocated);
extern void      FUN_006ae3d0(int32_t* self, void* member, uint32_t bytes);
extern int32_t   FUN_006ae430(int32_t* self);
extern void      FUN_00692470(int32_t block, int32_t stride);
extern void      FUN_00513ce0(void* self);

// Size-class top-up amounts indexed by pool (0 = 8bpp rows, 1 = 32bpp rows).
extern uint32_t  DAT_006f0b28[2];
extern uint32_t  DAT_006f0b30[2];

// ---------------------------------------------------------------------------
// Observed layouts.
// ---------------------------------------------------------------------------

// Render-state block allocated at 0x6916f0 (0x1c bytes) and reached through
// self+0x1b8 in the renderer object.
struct RenderState {
    void*   fn0;   // +0x00  update entry (0x6915b0)
    void*   fn1;   // +0x04  init entry   (0x691680)
    void*   fn2;   // +0x08  flush entry  (0x691570)
    void*   fn3;   // +0x0c  shutdown     (0x6916d0)
    int32_t f4;    // +0x10
    int32_t f5;    // +0x14
    int32_t f6;    // +0x18
};
static_assert(sizeof(RenderState) == 0x1c, "RenderState layout");

// Dispatcher table reached through the renderer object's +0x1bc field.
struct RenderDispatch {
    void    (*fn0)(int32_t*);    // +0x00
    int32_t (*begin)(int32_t*);  // +0x04
    void    (*fn2)(int32_t*);    // +0x08
    void    (*fn3)(int32_t*);    // +0x0c
    int32_t f4;                  // +0x10
};

// Allocator manager, allocated at 0x692220 with size 0x54.
struct Arena {
    uint8_t  pad00[0x2c];
    int32_t  link2c;          // +0x2c  previous heap link (FUN_006ae430 result)
    int32_t  limit30;         // +0x30  initialised to 1000000000
    int32_t  freeChain[2];    // +0x34  reusable block chains per pool
    int32_t  blockChain[2];   // +0x3c  slab ownership chains per pool
    int32_t  recordHead44;    // +0x44  8bpp row-record list
    int32_t  recordHead48;    // +0x48  32bpp row-record list
    int32_t  allocatedBytes;  // +0x4c  starts at the 0x54 manager size
    uint32_t chunkLimit;      // +0x50  rows per chunk chosen by 0x691930/0x6919e0
};
static_assert(sizeof(Arena) == 0x54, "Arena layout");
static_assert(offsetof(Arena, freeChain) == 0x34, "Arena::freeChain");
static_assert(offsetof(Arena, blockChain) == 0x3c, "Arena::blockChain");
static_assert(offsetof(Arena, recordHead44) == 0x44, "Arena::recordHead44");
static_assert(offsetof(Arena, recordHead48) == 0x48, "Arena::recordHead48");
static_assert(offsetof(Arena, allocatedBytes) == 0x4c, "Arena::allocatedBytes");
static_assert(offsetof(Arena, chunkLimit) == 0x50, "Arena::chunkLimit");

// Row record allocated at 0x691a90/0x691b00 with size 0x248.
struct ImageRecord {
    int32_t      rowBlockTable;  // +0x00  per-row block pointer array
    uint32_t     height;         // +0x04
    uint32_t     stride;         // +0x08  bytes per row
    uint32_t     rowsPerChunk;   // +0x0c
    uint32_t     usedRows;       // +0x10
    uint32_t     chunkRows;      // +0x14  copied from Arena::chunkLimit
    uint32_t     rowStart;       // +0x18
    uint32_t     rowEnd;         // +0x1c
    int32_t      partial;        // +0x20
    int32_t      dirty;          // +0x24
    int32_t      grown;          // +0x28
    ImageRecord* next;           // +0x2c
    void*        lockFn;         // +0x30  row lock callback
    void*        unlockFn;       // +0x34  row unlock callback
    void*        releaseFn;      // +0x38  release callback
};
static_assert(offsetof(ImageRecord, next) == 0x2c, "ImageRecord::next");
static_assert(offsetof(ImageRecord, lockFn) == 0x30, "ImageRecord::lockFn");
static_assert(offsetof(ImageRecord, releaseFn) == 0x38, "ImageRecord::releaseFn");

// ---------------------------------------------------------------------------
// Small conversion helpers for the 32-bit pointer-in-dword fields.
// ---------------------------------------------------------------------------
static inline int32_t ptr_bits(const void* p)
{
    return static_cast<int32_t>(reinterpret_cast<uintptr_t>(p));
}

template <typename T>
static inline T* bits_ptr(int32_t value)
{
    return reinterpret_cast<T*>(static_cast<uintptr_t>(static_cast<uint32_t>(value)));
}

static inline void* ptr_at(int32_t base, uint32_t offset)
{
    return reinterpret_cast<void*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(base)) + offset);
}

static inline RenderState* state_of(int32_t* self)
{
    return bits_ptr<RenderState>(self[0x6e]);
}

static inline RenderDispatch* disp_of(int32_t* self)
{
    return bits_ptr<RenderDispatch>(self[0x6f]);
}

static inline Arena* arena_of(int32_t* self)
{
    return bits_ptr<Arena>(self[1]);
}

// Error path: the receiver's first field points at a { vtable, code, detail }
// error object; the vtable's first entry is invoked with the receiver.
static void raise_code(int32_t* self, int32_t code)
{
    int32_t* obj = bits_ptr<int32_t>(*self);
    obj[5] = code;
    (*reinterpret_cast<void(**)(int32_t*)>(obj))(self);
}

static void raise_code_detail(int32_t* self, int32_t code, int32_t detail)
{
    int32_t* obj = bits_ptr<int32_t>(*self);
    obj[5] = code;
    obj[6] = detail;
    (*reinterpret_cast<void(**)(int32_t*)>(obj))(self);
}

// 0x6915b0 — observed shape
// Per-frame update of the renderer object: returns 2 while the state block is
// already marked complete, otherwise forwards to the dispatcher's begin entry.
// Step 1 flushes an initialised frame, step 2 clamps the frame counter.
int FUN_006915b0(int32_t* self)
{
    RenderState* state = state_of(self);
    if (state->f5 != 0) {
        return 2;
    }
    int32_t step = disp_of(self)->begin(self);
    if (step == 1) {
        if (state->f6 != 0) {
            FUN_00691160();
            state->f6 = 0;
            return 1;
        }
        if (state->f4 == 0) {
            raise_code(self, 0x23);
        }
        FUN_00691570(self);
    } else if (step == 2) {
        state->f5 = 1;
        if (state->f6 == 0) {
            if (self[0x25] < self[0x27]) {
                self[0x27] = self[0x25];
                return 2;
            }
        } else if (disp_of(self)->f4 != 0) {
            raise_code(self, 0x3b);
            return 2;
        }
    }
    return step;
}

// 0x691680 — observed shape
// Re-installs the state block defaults, notifies the renderer object's +0x10
// entry, calls the dispatcher's first entry, and clears the frame counter.
void FUN_00691680(int32_t* self)
{
    RenderState* state = state_of(self);
    state->fn0 = reinterpret_cast<void*>(&FUN_006915b0);
    state->f4 = 0;
    state->f5 = 0;
    state->f6 = 1;
    (*reinterpret_cast<void(**)(int32_t*)>(ptr_at(*self, 0x10)))(self);
    disp_of(self)->fn0(self);
    self[0x29] = 0;
}

// 0x6916f0 — observed shape
// Allocates the 0x1c-byte state block through the object's first vtable entry,
// hangs it off self+0x1b8 and fills the four entry pointers plus defaults.
void FUN_006916f0(void* self)
{
    int32_t* base = static_cast<int32_t*>(self);
    void** outerVtbl = *reinterpret_cast<void***>(static_cast<char*>(self) + 4);
    void* (*alloc)(void*, int32_t, uint32_t) =
        *reinterpret_cast<void*(**)(void*, int32_t, uint32_t)>(outerVtbl);
    RenderState* state = static_cast<RenderState*>(alloc(self, 0, 0x1c));
    base[0x6e] = ptr_bits(state);
    state->fn0 = reinterpret_cast<void*>(&FUN_006915b0);
    state->fn1 = reinterpret_cast<void*>(&FUN_00691680);
    state->fn2 = reinterpret_cast<void*>(&FUN_00691570);
    state->fn3 = reinterpret_cast<void*>(&FUN_006916d0);
    state->f4 = 0;
    state->f5 = 0;
    state->f6 = 1;
}

// 0x691740 — observed shape
// Carves a size-rounded block of `size` bytes out of pool `pool` (0/1). Blocks
// live in a per-pool freelist of {next, used, remaining} headers; when no block
// fits, a new slab of size + 0x10 plus a pool-specific top-up is requested,
// halving the top-up down to 0x32 on failure. Returns header + 0x10 and
// advances the header's used counter.
int32_t FUN_00691740(int32_t* self, int32_t pool, uint32_t size)
{
    Arena* arena = arena_of(self);
    if (size > 0x3b9ac9f0u) {
        raise_code_detail(self, 0x36, 1);
    }
    if ((size & 7u) != 0) {
        size = size + (8u - (size & 7u));
    }
    if ((pool < 0) || (1 < pool)) {
        raise_code_detail(self, 0xe, pool);
    }

    int32_t* block = bits_ptr<int32_t>(arena->freeChain[pool]);
    int32_t* prev = nullptr;
    while ((block != nullptr) && (size > static_cast<uint32_t>(block[2]))) {
        prev = block;
        block = bits_ptr<int32_t>(block[0]);
    }

    if (block == nullptr) {
        int32_t total = static_cast<int32_t>(size + 0x10u);
        uint32_t extra = (prev == nullptr) ? DAT_006f0b28[pool] : DAT_006f0b30[pool];
        if (1000000000u - static_cast<uint32_t>(total) < extra) {
            extra = 1000000000u - static_cast<uint32_t>(total);
        }
        block = reinterpret_cast<int32_t*>(
            FUN_006ae280(self, extra + static_cast<uint32_t>(total)));
        while (block == nullptr) {
            extra = extra >> 1;
            if (extra < 0x32) {
                raise_code_detail(self, 0x36, 2);
            }
            block = reinterpret_cast<int32_t*>(
                FUN_006ae280(self, extra + static_cast<uint32_t>(total)));
        }
        arena->allocatedBytes += static_cast<int32_t>(extra + static_cast<uint32_t>(total));
        block[0] = 0;
        block[1] = 0;
        block[2] = static_cast<int32_t>(extra + size);
        if (prev == nullptr) {
            arena->freeChain[pool] = ptr_bits(block);
        } else {
            *prev = ptr_bits(block);
        }
    }

    int32_t offset = block[1];
    block[1] = offset + static_cast<int32_t>(size);
    block[2] = block[2] - static_cast<int32_t>(size);
    return offset + 0x10 + ptr_bits(block);
}

// 0x691880 — observed shape
// Allocates a fresh, dedicated slab of size + 0x10 for pool `pool`, links its
// header into the per-pool ownership chain at +0x3c, charges the manager and
// returns the payload at header + 0x10.
int32_t* FUN_00691880(int32_t* self, int32_t pool, uint32_t size)
{
    Arena* arena = arena_of(self);
    if (size > 0x3b9ac9f0u) {
        raise_code_detail(self, 0x36, 3);
    }
    if ((size & 7u) != 0) {
        size = size + (8u - (size & 7u));
    }
    if ((pool < 0) || (1 < pool)) {
        raise_code_detail(self, 0xe, pool);
    }

    int32_t* block = reinterpret_cast<int32_t*>(FUN_006ae280(self, size + 0x10u));
    if (block == nullptr) {
        raise_code_detail(self, 0x36, 4);
    }
    arena->allocatedBytes += static_cast<int32_t>(size + 0x10u);
    int32_t previous = arena->blockChain[pool];
    arena->blockChain[pool] = ptr_bits(block);
    block[1] = static_cast<int32_t>(size);
    block[0] = previous;
    block[2] = 0;
    return block + 4;
}

// 0x691930 — observed shape
// Builds a `count`-entry table of row pointers for pool `pool`. The chunk
// limit is 0x3b9ac9f0 / elemSize clamped to count and stored at manager+0x50;
// the table itself comes from 0x691740 while each chunk of rows is one
// dedicated slab from 0x691880.
int32_t FUN_00691930(int32_t* self, int32_t pool, uint32_t elemSize, uint32_t count)
{
    Arena* arena = arena_of(self);
    uint32_t chunk = static_cast<uint32_t>(0x3b9ac9f0ull / elemSize);
    if (chunk == 0) {
        raise_code(self, 0x46);
    }
    if (static_cast<int32_t>(count) <= static_cast<int32_t>(chunk)) {
        chunk = count;
    }
    arena->chunkLimit = chunk;
    int32_t tableBase = FUN_00691740(self, pool, count * 4u);
    int32_t* table = bits_ptr<int32_t>(tableBase);
    uint32_t done = 0;
    if (count != 0) {
        do {
            if (count - done <= chunk) {
                chunk = count - done;
            }
            int32_t* row = FUN_00691880(self, pool, chunk * elemSize);
            if (chunk != 0) {
                uint32_t left = chunk;
                do {
                    table[done] = ptr_bits(row);
                    done = done + 1;
                    row = reinterpret_cast<int32_t*>(
                        reinterpret_cast<char*>(row) + elemSize);
                    left = left - 1;
                } while (left != 0);
            }
        } while (done < count);
    }
    return tableBase;
}

// 0x6919e0 — observed shape
// Same table builder as 0x691930 for 0x80-byte-per-pixel 32bpp rows: every
// element size is `stride * 0x80` and the chunk limit divides by that product.
int32_t FUN_006919e0(int32_t* self, int32_t pool, int32_t stride, uint32_t count)
{
    Arena* arena = arena_of(self);
    uint32_t rowBytes = static_cast<uint32_t>(stride * 0x80);
    uint32_t chunk = static_cast<uint32_t>(0x3b9ac9f0ull / rowBytes);
    if (chunk == 0) {
        raise_code(self, 0x46);
    }
    if (static_cast<int32_t>(count) <= static_cast<int32_t>(chunk)) {
        chunk = count;
    }
    arena->chunkLimit = chunk;
    int32_t tableBase = FUN_00691740(self, pool, count * 4u);
    int32_t* table = bits_ptr<int32_t>(tableBase);
    uint32_t done = 0;
    if (count != 0) {
        do {
            if (count - done <= chunk) {
                chunk = count - done;
            }
            int32_t* row = FUN_00691880(self, pool,
                chunk * static_cast<uint32_t>(stride) * 0x80u);
            if (chunk != 0) {
                uint32_t left = chunk;
                do {
                    table[done] = ptr_bits(row);
                    done = done + 1;
                    row = reinterpret_cast<int32_t*>(
                        reinterpret_cast<char*>(row) + static_cast<uint32_t>(stride) * 0x80u);
                    left = left - 1;
                } while (left != 0);
            }
        } while (done < count);
    }
    return tableBase;
}

// 0x691a90 — observed shape
// Creates a 0x248-byte 8bpp row record in pool 1 and pushes it on the manager's
// +0x44 list: height, rows-per-chunk, stride, the +0x20 flag, a zeroed +0x28,
// and the previous list head at +0x2c.
void FUN_00691a90(int32_t* self, int32_t pool, int32_t param_3, int32_t param_4,
                  int32_t param_5, int32_t param_6)
{
    Arena* arena = arena_of(self);
    if (pool != 1) {
        raise_code_detail(self, 0xe, pool);
    }
    ImageRecord* rec = bits_ptr<ImageRecord>(FUN_00691740(self, pool, 0x248));
    rec->height = static_cast<uint32_t>(param_5);
    rec->rowsPerChunk = static_cast<uint32_t>(param_6);
    int32_t previous = arena->recordHead44;
    arena->recordHead44 = ptr_bits(rec);
    rec->stride = static_cast<uint32_t>(param_4);
    rec->rowBlockTable = 0;
    rec->partial = param_3;
    rec->grown = 0;
    rec->next = bits_ptr<ImageRecord>(previous);
}

// 0x691b00 — observed shape
// 32bpp twin of 0x691a90: same 0x248-byte record, pushed on the manager's
// +0x48 list instead of +0x44.
void FUN_00691b00(int32_t* self, int32_t pool, int32_t param_3, int32_t param_4,
                  int32_t param_5, int32_t param_6)
{
    Arena* arena = arena_of(self);
    if (pool != 1) {
        raise_code_detail(self, 0xe, pool);
    }
    ImageRecord* rec = bits_ptr<ImageRecord>(FUN_00691740(self, pool, 0x248));
    rec->height = static_cast<uint32_t>(param_5);
    rec->rowsPerChunk = static_cast<uint32_t>(param_6);
    int32_t previous = arena->recordHead48;
    arena->recordHead48 = ptr_bits(rec);
    rec->stride = static_cast<uint32_t>(param_4);
    rec->rowBlockTable = 0;
    rec->partial = param_3;
    rec->grown = 0;
    rec->next = bits_ptr<ImageRecord>(previous);
}

// 0x691b70 — observed shape
// Computes the pixel and row totals of every not-yet-materialised record in
// both lists, asks the budget helper 0xae2d0 how many rows fit, then allocates
// each record's row table, either truncated (marking +0x28) or at full height.
void FUN_00691b70(int32_t* self)
{
    Arena* arena = arena_of(self);
    int32_t pixelTotal = 0;
    int32_t rowTotal = 0;
    for (ImageRecord* rec = bits_ptr<ImageRecord>(arena->recordHead44);
         rec != nullptr; rec = rec->next) {
        if (rec->rowBlockTable == 0) {
            pixelTotal += static_cast<int32_t>(rec->rowsPerChunk * rec->stride);
            rowTotal += static_cast<int32_t>(rec->height * rec->stride);
        }
    }
    for (ImageRecord* rec = bits_ptr<ImageRecord>(arena->recordHead48);
         rec != nullptr; rec = rec->next) {
        if (rec->rowBlockTable == 0) {
            pixelTotal += static_cast<int32_t>(rec->rowsPerChunk * rec->stride * 0x80u);
            rowTotal += static_cast<int32_t>(rec->height * rec->stride * 0x80u);
        }
    }
    if (0 < pixelTotal) {
        int32_t rows = FUN_006ae2d0(self, pixelTotal, rowTotal, arena->allocatedBytes);
        if (rows < rowTotal) {
            rows = rows / pixelTotal;
            if (rows < 1) {
                rows = 1;
            }
        } else {
            rows = 1000000000;
        }
        for (ImageRecord* rec = bits_ptr<ImageRecord>(arena->recordHead44);
             rec != nullptr; rec = rec->next) {
            if (rec->rowBlockTable == 0) {
                uint32_t height = rec->height;
                if (rows < static_cast<int32_t>(
                        (height - 1u) / rec->rowsPerChunk + 1u)) {
                    rec->usedRows = rec->rowsPerChunk * static_cast<uint32_t>(rows);
                    FUN_006ae3d0(self, &rec->lockFn, rec->stride * height);
                    rec->grown = 1;
                } else {
                    rec->usedRows = height;
                }
                rec->rowBlockTable = FUN_00691930(self, 1, rec->stride, rec->usedRows);
                rec->chunkRows = arena->chunkLimit;
                rec->rowStart = 0;
                rec->rowEnd = 0;
                rec->dirty = 0;
            }
        }
        for (ImageRecord* rec = bits_ptr<ImageRecord>(arena->recordHead48);
             rec != nullptr; rec = rec->next) {
            if (rec->rowBlockTable == 0) {
                uint32_t height = rec->height;
                if (rows < static_cast<int32_t>(
                        (height - 1u) / rec->rowsPerChunk + 1u)) {
                    rec->usedRows = rec->rowsPerChunk * static_cast<uint32_t>(rows);
                    FUN_006ae3d0(self, &rec->lockFn, rec->stride * height * 0x80u);
                    rec->grown = 1;
                } else {
                    rec->usedRows = height;
                }
                rec->rowBlockTable = FUN_006919e0(self, 1, static_cast<int32_t>(rec->stride),
                                                  rec->usedRows);
                rec->chunkRows = arena->chunkLimit;
                rec->rowStart = 0;
                rec->rowEnd = 0;
                rec->dirty = 0;
            }
        }
    }
}

// Row callbacks stored in the record's +0x30 sub-object.
typedef void (*RowLockFn)(void*, void*, int32_t, int32_t, int32_t);
typedef void (*RowUnlockFn)(void*, void*, int32_t);

// 0x691d10 — observed shape
// Flushes (param_2 == 0) or closes (param_2 != 0) the visible row range of an
// 8bpp record. The record arrives in ESI, exposed here as `rec`. Rows are
// emitted in chunkRows-sized runs clipped by rowEnd, height and usedRows.
void FUN_00691d10(void* param_1, int32_t param_2, ImageRecord* rec)
{
    uint32_t stride = rec->stride;
    int32_t offset = static_cast<int32_t>(rec->rowStart * stride);
    uint32_t limit = rec->usedRows;
    int32_t y = 0;
    if (static_cast<int32_t>(limit) <= 0) {
        return;
    }
    do {
        int32_t run = static_cast<int32_t>(limit) - y;
        if (static_cast<int32_t>(rec->chunkRows) < static_cast<int32_t>(limit) - y) {
            run = static_cast<int32_t>(rec->chunkRows);
        }
        int32_t clip = static_cast<int32_t>(rec->rowEnd) -
                       static_cast<int32_t>(rec->rowStart + static_cast<uint32_t>(y));
        if (clip <= run) {
            run = clip;
        }
        clip = static_cast<int32_t>(rec->height) -
               static_cast<int32_t>(rec->rowStart + static_cast<uint32_t>(y));
        if (clip <= run) {
            run = clip;
        }
        if (run < 1) {
            return;
        }
        int32_t bytes = run * static_cast<int32_t>(stride);
        int32_t* blocks = bits_ptr<int32_t>(rec->rowBlockTable);
        if (param_2 == 0) {
            reinterpret_cast<RowLockFn>(rec->lockFn)(
                param_1, &rec->lockFn, blocks[y], offset, bytes);
        } else {
            reinterpret_cast<RowUnlockFn>(rec->unlockFn)(
                param_1, &rec->lockFn, blocks[y]);
        }
        offset = offset + bytes;
        y = y + static_cast<int32_t>(rec->chunkRows);
    } while (y < static_cast<int32_t>(limit));
}

// 0x691db0 — observed shape
// 32bpp twin of 0x691d10: the same clipped row walk, with offsets and byte
// counts scaled by 0x80 per pixel.
void FUN_00691db0(void* param_1, int32_t param_2, ImageRecord* rec)
{
    uint32_t stride = rec->stride;
    int32_t offset = static_cast<int32_t>(rec->rowStart * stride * 0x80u);
    uint32_t limit = rec->usedRows;
    int32_t y = 0;
    if (static_cast<int32_t>(limit) <= 0) {
        return;
    }
    do {
        int32_t run = static_cast<int32_t>(limit) - y;
        if (static_cast<int32_t>(rec->chunkRows) < static_cast<int32_t>(limit) - y) {
            run = static_cast<int32_t>(rec->chunkRows);
        }
        int32_t clip = static_cast<int32_t>(rec->rowEnd) -
                       static_cast<int32_t>(rec->rowStart + static_cast<uint32_t>(y));
        if (clip <= run) {
            run = clip;
        }
        clip = static_cast<int32_t>(rec->height) -
               static_cast<int32_t>(rec->rowStart + static_cast<uint32_t>(y));
        if (clip <= run) {
            run = clip;
        }
        if (run < 1) {
            return;
        }
        int32_t bytes = run * static_cast<int32_t>(stride) * 0x80;
        int32_t* blocks = bits_ptr<int32_t>(rec->rowBlockTable);
        if (param_2 == 0) {
            reinterpret_cast<RowLockFn>(rec->lockFn)(
                param_1, &rec->lockFn, blocks[y], offset, bytes);
        } else {
            reinterpret_cast<RowUnlockFn>(rec->unlockFn)(
                param_1, &rec->lockFn, blocks[y]);
        }
        offset = offset + bytes;
        y = y + static_cast<int32_t>(rec->chunkRows);
    } while (y < static_cast<int32_t>(limit));
}

// 0x691e60 — observed shape
// Validates that rows [start, start+count) belong to the 8bpp record, moves
// the record's rowStart window when the request falls outside it (flushing the
// old window first), grows rowEnd when allowed, clears the just-materialised
// rows through 0x692470, and returns the address of the rows[start] slot.
int32_t FUN_00691e60(int32_t* self, ImageRecord* rec, uint32_t start, uint32_t count,
                     int32_t resize)
{
    uint32_t end = start + count;
    if ((static_cast<uint32_t>(rec->height) < end) ||
        (static_cast<uint32_t>(rec->rowsPerChunk) < count) ||
        (rec->rowBlockTable == 0)) {
        raise_code(self, 0x16);
    }
    if ((start < rec->rowStart) || (rec->usedRows + rec->rowStart < end)) {
        if (rec->grown == 0) {
            raise_code(self, 0x45);
        }
        if (rec->dirty != 0) {
            FUN_00691d10(self, 1, rec);
            rec->dirty = 0;
        }
        uint32_t newStart = start;
        if ((start <= rec->rowStart) &&
            ((newStart = end - rec->usedRows), static_cast<int32_t>(newStart) < 0)) {
            newStart = 0;
        }
        rec->rowStart = newStart;
        FUN_00691d10(self, 0, rec);
    }

    uint32_t reached = rec->rowEnd;
    if (reached < end) {
        if (reached < start) {
            if (resize != 0) {
                raise_code(self, 0x16);
            }
            reached = start;
        }
        if (resize != 0) {
            rec->rowEnd = end;
        }
        if (rec->partial != 0) {
            int32_t stride = static_cast<int32_t>(rec->stride);
            uint32_t firstRow = rec->rowStart;
            int32_t* blocks = bits_ptr<int32_t>(rec->rowBlockTable);
            for (uint32_t i = reached - firstRow; i < end - firstRow; i = i + 1) {
                FUN_00692470(blocks[i], stride);
            }
            if (resize == 0) {
                return rec->rowBlockTable +
                       static_cast<int32_t>((start - rec->rowStart) * 4u);
            }
            rec->dirty = 1;
            return rec->rowBlockTable +
                   static_cast<int32_t>((start - rec->rowStart) * 4u);
        }
        if (resize == 0) {
            raise_code(self, 0x16);
            return rec->rowBlockTable +
                   static_cast<int32_t>((start - rec->rowStart) * 4u);
        }
    } else if (resize == 0) {
        return rec->rowBlockTable +
               static_cast<int32_t>((start - rec->rowStart) * 4u);
    }
    rec->dirty = 1;
    return rec->rowBlockTable +
           static_cast<int32_t>((start - rec->rowStart) * 4u);
}

// 0x691fa0 — observed shape
// 32bpp twin of 0x691e60: identical window bookkeeping, but the partial-row
// clear scales the stride by 0x80 and the walk delegates to 0x691db0.
int32_t FUN_00691fa0(int32_t* self, ImageRecord* rec, uint32_t start, uint32_t count,
                     int32_t resize)
{
    uint32_t end = start + count;
    if ((static_cast<uint32_t>(rec->height) < end) ||
        (static_cast<uint32_t>(rec->rowsPerChunk) < count) ||
        (rec->rowBlockTable == 0)) {
        raise_code(self, 0x16);
    }
    if ((start < rec->rowStart) || (rec->usedRows + rec->rowStart < end)) {
        if (rec->grown == 0) {
            raise_code(self, 0x45);
        }
        if (rec->dirty != 0) {
            FUN_00691db0(self, 1, rec);
            rec->dirty = 0;
        }
        uint32_t newStart = start;
        if ((start <= rec->rowStart) &&
            ((newStart = end - rec->usedRows), static_cast<int32_t>(newStart) < 0)) {
            newStart = 0;
        }
        rec->rowStart = newStart;
        FUN_00691db0(self, 0, rec);
    }

    uint32_t reached = rec->rowEnd;
    if (reached < end) {
        if (reached < start) {
            if (resize != 0) {
                raise_code(self, 0x16);
            }
            reached = start;
        }
        if (resize != 0) {
            rec->rowEnd = end;
        }
        if (rec->partial != 0) {
            int32_t stride = static_cast<int32_t>(rec->stride) << 7;
            uint32_t firstRow = rec->rowStart;
            int32_t* blocks = bits_ptr<int32_t>(rec->rowBlockTable);
            for (uint32_t i = reached - firstRow; i < end - firstRow; i = i + 1) {
                FUN_00692470(blocks[i], stride);
            }
            if (resize == 0) {
                return rec->rowBlockTable +
                       static_cast<int32_t>((start - rec->rowStart) * 4u);
            }
            rec->dirty = 1;
            return rec->rowBlockTable +
                   static_cast<int32_t>((start - rec->rowStart) * 4u);
        }
        if (resize == 0) {
            raise_code(self, 0x16);
            return rec->rowBlockTable +
                   static_cast<int32_t>((start - rec->rowStart) * 4u);
        }
    } else if (resize == 0) {
        return rec->rowBlockTable +
               static_cast<int32_t>((start - rec->rowStart) * 4u);
    }
    rec->dirty = 1;
    return rec->rowBlockTable +
           static_cast<int32_t>((start - rec->rowStart) * 4u);
}

// 0x6920e0 — observed shape
// Tears down one pool. For pool 1 both row-record lists are released first
// (each record with a non-zero +0x28 runs its +0x38 callback), then the
// ownership chain at +0x3c and the freelist at +0x34 are freed node by node,
// charging manager+0x4c with the exact node size.
void FUN_006920e0(int32_t* self, int32_t pool)
{
    Arena* arena = arena_of(self);
    if ((pool < 0) || (1 < pool)) {
        raise_code_detail(self, 0xe, pool);
    }
    if (pool == 1) {
        for (ImageRecord* rec = bits_ptr<ImageRecord>(arena->recordHead44);
             rec != nullptr; rec = rec->next) {
            if (rec->grown != 0) {
                rec->grown = 0;
                reinterpret_cast<void(*)(void*, void*)>(rec->releaseFn)(
                    self, &rec->lockFn);
            }
        }
        ImageRecord* rec = bits_ptr<ImageRecord>(arena->recordHead48);
        arena->recordHead44 = 0;
        for (; rec != nullptr; rec = rec->next) {
            if (rec->grown != 0) {
                rec->grown = 0;
                reinterpret_cast<void(*)(void*, void*)>(rec->releaseFn)(
                    self, &rec->lockFn);
            }
        }
        arena->recordHead48 = 0;
    }
    int32_t node = arena->blockChain[pool];
    arena->blockChain[pool] = 0;
    while (node != 0) {
        int32_t* block = bits_ptr<int32_t>(node);
        int32_t next = block[0];
        int32_t bytes = block[2] + 0x10 + block[1];
        FUN_006ae2b0(self, block, bytes);
        arena->allocatedBytes -= bytes;
        node = next;
    }
    node = arena->freeChain[pool];
    arena->freeChain[pool] = 0;
    while (node != 0) {
        int32_t* block = bits_ptr<int32_t>(node);
        int32_t next = block[0];
        int32_t bytes = block[2] + 0x10 + block[1];
        FUN_006ae2b0(self, block, bytes);
        arena->allocatedBytes -= bytes;
        node = next;
    }
}

// 0x6921e0 — observed shape
// Destructor: walks pool 1 down to 0 through 0x6920e0, frees the 0x54-byte
// manager block, clears self+4 and lets 0x513ce0 finish the object teardown.
void FUN_006921e0(void* self)
{
    int32_t* base = static_cast<int32_t*>(self);
    int32_t pool = 1;
    do {
        FUN_006920e0(base, pool);
        pool = pool - 1;
    } while (-1 < pool);
    FUN_006ae2b0(base, bits_ptr<void>(base[1]), 0x54);
    base[1] = 0;
    FUN_00513ce0(self);
}

// 0x692220 — observed shape
// Constructor: allocates the 0x54-byte manager, installs the eleven-entry
// vtable at +0x00..+0x28, seeds +0x30 with 1000000000, records the previous
// heap link at +0x2c, zeroes the four chain heads, publishes the manager at
// self+4, and finishes with record heads 0 plus the 0x54 block size at +0x4c.
void FUN_00692220(int32_t* self)
{
    self[1] = 0;
    int32_t previous = FUN_006ae430(self);
    Arena* arena = static_cast<Arena*>(FUN_006ae280(self, 0x54));
    if (arena == nullptr) {
        FUN_00513ce0(self);
        raise_code_detail(self, 0x36, 0);
    }
    void** vtbl = reinterpret_cast<void**>(arena);
    vtbl[0]  = reinterpret_cast<void*>(&FUN_00691740);
    vtbl[1]  = reinterpret_cast<void*>(&FUN_00691880);
    vtbl[2]  = reinterpret_cast<void*>(&FUN_00691930);
    vtbl[3]  = reinterpret_cast<void*>(&FUN_006919e0);
    vtbl[4]  = reinterpret_cast<void*>(&FUN_00691a90);
    vtbl[5]  = reinterpret_cast<void*>(&FUN_00691b00);
    vtbl[6]  = reinterpret_cast<void*>(&FUN_00691b70);
    vtbl[7]  = reinterpret_cast<void*>(&FUN_00691e60);
    vtbl[8]  = reinterpret_cast<void*>(&FUN_00691fa0);
    vtbl[9]  = reinterpret_cast<void*>(&FUN_006920e0);
    vtbl[10] = reinterpret_cast<void*>(&FUN_006921e0);
    int32_t* raw = reinterpret_cast<int32_t*>(arena);
    raw[0xc] = 1000000000;
    raw[0xb] = previous;
    raw[0xe] = 0;
    raw[0x10] = 0;
    raw[0xd] = 0;
    raw[0xf] = 0;
    self[1] = ptr_bits(arena);
    raw[0x11] = 0;
    raw[0x12] = 0;
    raw[0x13] = 0x54;
}

// 0x6922e0 — observed shape
// Starts a shutdown through the backend object's +0x24 entry, then selects the
// final state value: 200 plus a cleared +0x134 when self+0x10 is set, else 100.
void FUN_006922e0(void* self)
{
    int32_t* base = static_cast<int32_t*>(self);
    if (base[1] != 0) {
        (*reinterpret_cast<void(**)(void*, int32_t)>(ptr_at(base[1], 0x24)))(self, 1);
        if (base[4] != 0) {
            base[5] = 200;
            base[0x4d] = 0;
            return;
        }
        base[5] = 100;
    }
}

// 0x692320 — observed shape
// Releases the backend through its +0x28 entry when present, then clears the
// backend pointer and the +0x14 state value.
void FUN_00692320(void* self)
{
    int32_t* base = static_cast<int32_t*>(self);
    if (base[1] != 0) {
        (*reinterpret_cast<void(**)(void*)>(ptr_at(base[1], 0x28)))(self);
    }
    base[1] = 0;
    base[5] = 0;
}

// 0x692350 — observed shape
// Allocates a 0x84-byte object through the receiver's first vtable entry and
// clears its +0x80 field.
void FUN_00692350(void* self)
{
    void** outerVtbl = *reinterpret_cast<void***>(static_cast<char*>(self) + 4);
    int32_t result = (*reinterpret_cast<int32_t(**)(void*, int32_t, uint32_t)>(
        outerVtbl))(self, 0, 0x84);
    int32_t* object = bits_ptr<int32_t>(result);
    object[0x20] = 0;
}
