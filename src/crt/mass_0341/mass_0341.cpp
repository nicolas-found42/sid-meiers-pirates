// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// Batch mass_0341 - layer/descriptor emission helpers, 0x6a5c6c..0x6a6bb4.
// The reconstruction target is the 32-bit PE image; every offset below is the
// self-relative byte offset observed in the supplied listings.
// Status: unverified; no byte-match claim.

#include <cstdint>
#include <cstddef>

// ---- helpers whose bodies live outside this batch --------------------------
int32_t FUN_006a48dd(uint32_t opcode);
int32_t FUN_0069fcf5(void);
int32_t FUN_006a4aab(int32_t op, const int32_t* a, uint32_t aCount,
                     const int32_t* b, const int32_t* c, const int32_t* d,
                     uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i);
void    FUN_0065cc6f(int32_t slot, int32_t* out);
void    FUN_0065e1b9(int32_t (*compare)(const void*, const void*), int32_t* base,
                     uint32_t count, int32_t flags);
int32_t FUN_0065de5f(const void*, const void*);

// ---- observed data shapes ---------------------------------------------------
// Graph node descriptor: 0x80-byte records reached through Receiver::nodes.
struct Node {
    uint32_t flags00;      // +0x00  (0x6a6662 merges bits 25..27 of this word)
    uint32_t word04;       // +0x04  class/format key
    uint32_t word08;       // +0x08  sibling link (-1 terminates)
    uint32_t word0c;       // +0x0c
    uint32_t word10;       // +0x10  sort/bucket key
    int32_t  link14;       // +0x14  secondary chain (-1 when absent)
    uint8_t  pad018[0x18];
    int32_t  word30;       // +0x30  emitted marker (set to -1)
    uint8_t  pad034[0x04];
    int32_t  parent38;     // +0x38  parent id (-1 terminates the climb)
    int32_t  word3c;       // +0x3c
    uint8_t  pad040[0x18];
    int32_t  owner58;      // +0x58
    int32_t  word5c;       // +0x5c
    int32_t  word60;       // +0x60
    uint8_t  pad064[0x10];
    int32_t  group74;      // +0x74  assigned group
    uint8_t  pad078[0x08];
};

// Per-layer descriptor selection state reached through Receiver::state.
struct LayerState {
    uint32_t  header;      // +0x00  low 20 bits = element count
    uint32_t  unk04;       // +0x04
    int32_t*  srcIds;      // +0x08  id array, source side
    uint32_t  count0c;     // +0x0c
    int32_t*  dstIds;      // +0x10  id array, destination side
};

// Receiver of the 0x6a5c6c..0x6a6877 family.
struct Receiver {
    void**      vtbl;      // +0x000
    uint8_t     pad004[0x10];
    Node**      nodes;     // +0x014  id -> Node*
    uint8_t     pad018[0x56];
    uint8_t     flags6e;   // +0x06e
    uint8_t     pad06f[0x19];
    int32_t     mode88;    // +0x088
    int32_t     unk8c;     // +0x08c
    uint8_t     pad090[0x3c];
    uint8_t     flagscc;   // +0x0cc
    uint8_t     pad0cd[0x2f];
    int32_t     keyfc;     // +0x0fc  key handed to slot 0x80
    LayerState* state;     // +0x100
};

// Class record reached through GraphPool::classes.
struct ClassRec {
    uint32_t unk00;        // +0x00
    uint8_t  flags4;       // +0x04  bit 4 / bit 5 tested by 0x6a69ff, 0x6a6a74
};

// Per-node metadata record reached through GraphPool::meta18.
struct NodeMeta {
    uint16_t word0;        // +0x00
    uint16_t flags2;       // +0x02
};

struct GraphPool {
    uint8_t    pad000[0x10];
    ClassRec** classes;    // +0x10  indexed by Node::word04
    Node**     nodes;      // +0x14  indexed by node id
    NodeMeta** meta18;     // +0x18  indexed by node id (0x6a6bb4)
};

// Graph evaluation context of the 0x6a69ff..0x6a6bb4 family.
struct Graph {
    uint8_t    pad000[0x04];
    GraphPool* pool;       // +0x04
    int32_t*   countA;     // +0x08  per-group emitted count
    int32_t*   baseA;      // +0x0c  per-group running offset
    int32_t*   listA;      // +0x10  output list (may be null)
    int32_t    unk14;      // +0x14
    int32_t    pad018;     // +0x18
    uint32_t*  countB;     // +0x1c  per-group emitted count
    int32_t*   baseB;      // +0x20  per-group running offset
    int32_t*   listB;      // +0x24  output list (may be null)
    int32_t*   delta;      // +0x28  per-node delta
    uint32_t*  score;      // +0x2c  per-node score
    uint8_t    pad030[0x08];
    uint32_t   count38;    // +0x38  number of ids in order[]
    int32_t*   order;      // +0x3c  node order
};

// 13-dword record built/cleared by 0x6a6952 and 0x6a699a.
struct DwordRecord {
    int32_t slot[13];
};

// ---- vtable slot call shapes (ECX receiver modelled as first parameter) ----
typedef int32_t (*Slot5C)(void* self, int32_t arg);
typedef int32_t (*Slot60)(void* self);
typedef int32_t (*Slot64)(void* self, uint32_t a, uint32_t b, uint32_t c);
typedef int32_t (*Slot68)(void* self, uint32_t a, uint32_t b, uint32_t c);
typedef int32_t (*Slot6C)(void* self, Node* id, uint32_t* out0, uint32_t* out1,
                          uint32_t* out2);
typedef int32_t (*Slot70)(void* self, const int32_t* ids, uint32_t count,
                          uint32_t* out, uint32_t hint);
typedef int32_t (*Slot74)(void* self, Node* id, void* out0, void* out1);
typedef int32_t (*Slot78)(void* self, const int32_t* ids, uint32_t count,
                          uint32_t arg, uint32_t* out);
typedef int32_t (*Slot80)(void* self, int32_t key, void* out, uint32_t count,
                          int32_t a, int32_t b);

template <typename Fn>
static Fn vfn(void* obj, unsigned byteOffset)
{
    void** vtbl = *static_cast<void***>(obj);
    return reinterpret_cast<Fn>(vtbl[byteOffset / 4u]);
}

// 0x6a5c6c — observed shape
int32_t FUN_006a5c6c(Receiver* self)
{
    uint32_t primary = 0;    // local_8
    uint32_t aux0 = 0;       // local_1c
    uint32_t aux1 = 0;       // local_18
    uint32_t secondary = 0;  // local_c
    uint32_t bindArg = 0;    // local_10
    uint32_t extraFlags = 0; // local_14

    int32_t status = FUN_006a48dd(1);
    if (status < 0) return status;

    status = vfn<Slot6C>(self, 0x6c)(self, self->nodes[self->state->dstIds[0]],
                                     &primary, &aux0, &aux1);
    if (status < 0) return status;

    status = vfn<Slot70>(self, 0x70)(self, self->state->dstIds, self->state->count0c,
                                     &secondary, aux1);
    if (status < 0) return status;

    status = vfn<Slot64>(self, 0x64)(self, primary, secondary, aux0);
    if (status < 0) return status;

    status = vfn<Slot74>(self, 0x74)(self, self->nodes[self->state->srcIds[0]],
                                     &primary, &bindArg);
    if (status < 0) return status;

    status = vfn<Slot78>(self, 0x78)(self, self->state->srcIds, self->state->count0c,
                                     secondary, &extraFlags);
    if (status < 0) return status;

    if ((primary & 0x0b000000u) == 0) {
        extraFlags |= 0x01000000u;
    } else {
        extraFlags |= 0x0c000000u;
        primary &= 0xf4ffffffu;
    }

    status = vfn<Slot68>(self, 0x68)(self, primary, extraFlags, bindArg);
    if (status < 0) return status;

    status = vfn<Slot60>(self, 0x60)(self);
    if (status < 0) return status;

    status = FUN_0069fcf5();
    if (status < 0) return status;

    return 0;
}

// 0x6a5d79 — observed shape
int32_t FUN_006a5d79(Receiver* self)
{
    uint32_t count = self->state->header & 0xfffffu;
    if (count == 0) return 0;

    int32_t* srcBase = self->state->srcIds;   // +0x08
    uint32_t span = count << 2;               // local_c
    uint32_t i = 0;                           // local_8
    do {
        int32_t status = FUN_006a4aab(
            0x20,
            (int32_t*)((uint8_t*)self->state->dstIds + i * 4),
            1,
            (int32_t*)((uint8_t*)srcBase + i * 4),
            (int32_t*)((uint8_t*)srcBase + span),
            0, count, 0, 0, 0, 0);
        if (status < 0) return status;
        i = i + 1;
        span = span + 4;
    } while (i < count);

    return 0;
}

// 0x6a5deb — observed shape
int32_t FUN_006a5deb(Receiver* self)
{
    uint32_t count = self->state->header & 0xfffffu;   // uVar3
    uint32_t opcode = vfn<Slot5C>(self, 0x5c)(self, 0x12);

    int32_t status = FUN_006a48dd(opcode);
    if (status < 0) return status;

    uint32_t primary = 0;    // local_8
    uint32_t aux0 = 0;       // local_1c
    uint32_t aux1 = 0;       // local_18
    uint32_t secondary = 0;  // local_14
    uint32_t bindArg = 0;    // local_20
    uint32_t extraFlags = 0; // local_24

    status = vfn<Slot6C>(self, 0x6c)(self, self->nodes[self->state->dstIds[0]],
                                     &primary, &aux0, &aux1);
    if (status < 0) return status;

    status = vfn<Slot70>(self, 0x70)(self, self->state->dstIds, count, &secondary, aux1);
    if (status < 0) return status;

    status = vfn<Slot64>(self, 0x64)(self, primary, secondary, aux0);
    if (status < 0) return status;

    uint32_t index = 0;      // local_10
    int32_t byteOffset = 0;  // local_c
    do {
        int32_t* ids = (int32_t*)((uint8_t*)self->state->srcIds + byteOffset);

        status = vfn<Slot74>(self, 0x74)(self, self->nodes[ids[0]], &primary, &bindArg);
        if (status < 0) return status;

        status = vfn<Slot78>(self, 0x78)(self, ids, count, secondary, &extraFlags);
        if (status < 0) return status;

        status = vfn<Slot68>(self, 0x68)(self, primary, extraFlags, bindArg);
        if (status < 0) return status;

        index = index + 1;
        byteOffset = byteOffset + (int32_t)(count * 4);
    } while (index < 3);

    status = vfn<Slot60>(self, 0x60)(self);
    if (status < 0) return status;

    status = FUN_0069fcf5();
    if (status < 0) return status;

    return 0;
}

// 0x6a5f06 — observed shape
int32_t FUN_006a5f06(Receiver* self)
{
    int32_t scratch[4] = {0, 0, 0, 0};
    int32_t* ids = self->state->dstIds;
    uint32_t count = self->state->header & 0xfffffu;

    if (self->mode88 != self->nodes[ids[0]]->word04) {
        int32_t status = vfn<Slot80>(self, 0x80)(self, self->keyfc, scratch, count, 0, 0);
        if (status < 0) return status;
        ids = scratch;
    }

    int32_t status = FUN_006a4aab(0x24, ids, count, self->state->srcIds,
                                  0, 0, count, 0, 0, 0, 0);
    if (status < 0) return status;

    if (ids == scratch) {
        status = FUN_006a4aab(1, self->state->dstIds, count, scratch, 0, 0, count,
                              0, 0, 0, 0);
        if (status < 0) return status;
    }

    return 0;
}

// 0x6a5fac — observed shape
int32_t FUN_006a5fac(Receiver* self)
{
    uint32_t count = self->state->header & 0xfffffu;   // uVar4
    uint32_t opcode = vfn<Slot5C>(self, 0x5c)(self, 4);

    int32_t status = FUN_006a48dd(opcode);
    if (status < 0) return status;

    uint32_t primary = 0;    // local_c (also reused as slot 0x74 output)
    uint32_t aux0 = 0;       // local_1c
    uint32_t aux1 = 0;       // local_18
    uint32_t secondary = 0;  // local_10
    uint32_t bindArg = 0;    // local_20
    uint32_t extraFlags = 0; // local_24
    uint32_t toggle = 0;     // local_14

    status = vfn<Slot6C>(self, 0x6c)(self, self->nodes[self->state->dstIds[0]],
                                     &primary, &aux0, &aux1);
    if (status < 0) return status;

    status = vfn<Slot70>(self, 0x70)(self, self->state->dstIds, count, &secondary, aux1);
    if (status < 0) return status;

    status = vfn<Slot64>(self, 0x64)(self, primary, secondary, aux0);
    if (status < 0) return status;

    uint32_t index = 0;   // local_8
    do {
        int32_t* ids =
            (int32_t*)((uint8_t*)self->state->srcIds + index * count * 4);

        if ((index == 1) && ((self->state->header & 0xfff00000u) == 0x70400000u)) {
            toggle = 0x01000000u;
        } else {
            toggle = 0;
        }

        status = vfn<Slot74>(self, 0x74)(self, self->nodes[ids[0]], &primary, &bindArg);
        if (status < 0) return status;

        status = vfn<Slot78>(self, 0x78)(self, ids, count, secondary, &extraFlags);
        if (status < 0) return status;

        status = vfn<Slot68>(self, 0x68)(self, toggle ^ primary, extraFlags, bindArg);
        if (status < 0) return status;

        index = index + 1;
    } while (index < 3);

    status = vfn<Slot60>(self, 0x60)(self);
    if (status < 0) return status;

    status = FUN_0069fcf5();
    if (status < 0) return status;

    return 0;
}

// The corpus renders this callee as void but every call site (0x6a6375,
// 0x6a6662, 0x6a6877) consumes its result, so the status is returned here.
int32_t FUN_006a629c(Receiver* self, int32_t op, uint32_t scanGroups);

// 0x6a60ea — observed shape
int32_t FUN_006a60ea(Receiver* self)
{
    uint32_t header = self->state->header;
    uint32_t count = header & 0xfffffu;
    uint32_t aux0 = 0;       // local_1c; also feeds the opcode on the default path
    uint32_t opcode;

    if (header == 0x70500003u)      opcode = 0x18;
    else if (header == 0x70600003u) opcode = 0x17;
    else if (header == 0x70600004u) opcode = 0x15;
    else if (header == 0x70700003u) opcode = 0x16;
    else if (header == 0x70700004u) opcode = 0x14;
    // NEEDS_MANUAL: on the default path the listing reads the never-written
    // local_1c as the opcode; the original value is undetermined, so it keeps
    // the initialised value here.
    else                            opcode = aux0;

    uint32_t primary = 0;    // local_8
    uint32_t aux1 = 0;       // local_18
    uint32_t secondary = 0;  // local_c
    uint32_t bindArg = 0;    // local_10
    uint32_t extraFlags = 0; // local_14

    int32_t status = FUN_006a48dd(opcode);
    if (status < 0) return status;

    status = vfn<Slot6C>(self, 0x6c)(self, self->nodes[self->state->dstIds[0]],
                                     &primary, &aux0, &aux1);
    if (status < 0) return status;

    status = vfn<Slot70>(self, 0x70)(self, self->state->dstIds, self->state->count0c,
                                     &secondary, aux1);
    if (status < 0) return status;

    status = vfn<Slot64>(self, 0x64)(self, primary, secondary, aux0);
    if (status < 0) return status;

    secondary = (((uint32_t)(count != 3) - 1u) & 0xfff80000u) + 0x000f0000u;

    status = vfn<Slot74>(self, 0x74)(self, self->nodes[self->state->srcIds[0]],
                                     &primary, &bindArg);
    if (status < 0) return status;

    status = vfn<Slot78>(self, 0x78)(self, self->state->srcIds, count, secondary,
                                     &extraFlags);
    if (status < 0) return status;

    status = vfn<Slot68>(self, 0x68)(self, primary, extraFlags, bindArg);
    if (status < 0) return status;

    status = vfn<Slot74>(self, 0x74)(self, self->nodes[self->state->srcIds[count]],
                                     &primary, &bindArg);
    if (status < 0) return status;

    status = vfn<Slot78>(self, 0x78)(self, self->state->srcIds + count, count,
                                     secondary, &extraFlags);
    if (status < 0) return status;

    status = vfn<Slot68>(self, 0x68)(self, primary, extraFlags, bindArg);
    if (status < 0) return status;

    status = vfn<Slot60>(self, 0x60)(self);
    if (status < 0) return status;

    status = FUN_0069fcf5();
    if (status < 0) return status;

    return 0;
}

// 0x6a629c — observed shape
int32_t FUN_006a629c(Receiver* self, int32_t op, uint32_t scanGroups)
{
    LayerState* state = self->state;
    uint32_t count = state->header & 0xfffffu;   // uVar3
    int32_t local_24[4] = {0, 0, 0, 0};
    uint32_t local_14 = state->count0c;
    local_24[3] = (int32_t)(intptr_t)state->dstIds;

    FUN_0065cc6f(0, local_24);
    FUN_0065cc6f(1, local_24 + 1);
    FUN_0065cc6f(2, local_24 + 2);

    int32_t hit = 0;   // local_10
    if (scanGroups != 0) {
        uint32_t group = 0;
        do {
            if (hit != 0) break;
            if ((local_24[group] != 0) && (count != 0)) {
                uint32_t index = 0;      // local_c
                int32_t stride = 0;      // iVar2
                int32_t* ids = (int32_t*)(intptr_t)local_24[group];
                do {
                    // The listing adds the 0x80 stride to the resolved node
                    // pointer as well as advancing the id cursor.
                    if ((((const uint8_t*)self->nodes[ids[index]])[stride + 3] & 1) != 0) {
                        hit = 1;
                        break;
                    }
                    index = index + 1;
                    ids = ids + 1;
                    stride = stride + 0x80;
                } while (index < count);
            }
            group = group + 1;
        } while (group < 3);
    }

    FUN_006a4aab(op,
                 (const int32_t*)(intptr_t)local_24[3], local_14,
                 (const int32_t*)(intptr_t)local_24[0],
                 (const int32_t*)(intptr_t)local_24[1],
                 (const int32_t*)(intptr_t)local_24[2],
                 count, 0, 0, 0, (uint32_t)hit);
    return 0;
}

// 0x6a6375 — observed shape
int32_t FUN_006a6375(Receiver* self, int32_t op, int32_t* left, int32_t* right,
                     uint32_t count, uint32_t span, uint32_t flags)
{
    int32_t  local_34[4] = {0, 0, 0, 0};
    int32_t  local_24[4] = {0, 0, 0, 0};
    int32_t* savedLeft = nullptr;   // local_14
    int32_t  groupKey = 0;          // local_10
    uint32_t relabel = 0;           // local_c
    uint32_t cursor = 0;            // local_8
    int32_t  status = 0;

    if ((span < count) && (span == 1) && (self->state->srcIds[0] == right[0])) {
        return FUN_006a629c(self, op, 0);
    }

    if ((self->nodes[left[0]]->word04 == self->nodes[right[0]]->word04) &&
        (self->nodes[left[0]]->word08 == self->nodes[right[0]]->word08) &&
        (self->nodes[left[0]]->word0c == self->nodes[right[0]]->word0c)) {
        uint32_t probe = 0;
        bool     sharedKey = false;
        if (count != 0) {
            do {
                span = 0;
                if (probe != 0) {
                    do {
                        if (self->nodes[right[probe]]->word10 ==
                            self->nodes[left[span]]->word10) break;
                        span = span + 1;
                    } while (span < probe);
                    if (span < probe) break;
                }
                probe = probe + 1;
            } while (probe < count);
            sharedKey = probe < count;
        }
        relabel = sharedKey ? 1u : 0u;
        if (relabel != 0) {
            uint32_t walk = 0;
            uint32_t maxKey = 0;
            if (count != 0) {
                do {
                    uint32_t key = (uint32_t)self->nodes[left[walk]]->word10;
                    if (maxKey <= key) maxKey = key + 1;
                    walk = walk + 1;
                } while (walk < count);
            }
            status = vfn<Slot80>(self, 0x80)(self, self->keyfc, local_34, maxKey, 0, 0);
            walk = 0;
            if (status < 0) return status;
            if (count != 0) {
                Node** table = self->nodes;
                do {
                    local_24[walk] = local_34[table[left[walk]]->word10];
                    walk = walk + 1;
                } while (walk < count);
            }
            savedLeft = left;
            left = local_24;
        }
    } else {
        relabel = 0;
    }

    uint32_t index = 0;
    if (count != 0) {
        do {
            span = 1;
            if (index + 1 < count) {
                int32_t* rightIds = right + index;
                groupKey = self->nodes[*rightIds]->word10;
                cursor = index + 1;
                do {
                    rightIds = rightIds + 1;
                    if (self->nodes[*rightIds]->word10 != (uint32_t)groupKey) break;
                    span = span + 1;
                    cursor = cursor + 1;
                } while (cursor < count);
            }
            status = FUN_006a4aab(op, left + index, span, right + index, 0, 0, span,
                                  flags, flags, flags, 0);
            if (status < 0) return status;
            index = index + span;
        } while (index < count);
    }

    if (relabel == 0) {
        status = 0;
    } else {
        status = FUN_006a4aab(1, savedLeft, count, left, 0, 0, count, 0, 0, 0, 0);
        if (status >= 0) status = 0;
    }
    return status;
}

// 0x6a6574 — observed shape
int32_t FUN_006a6574(Receiver* self)
{
    void* local_c = self;
    void* local_8 = self;

    int32_t status = FUN_006a48dd(0x26);
    if (status < 0) return status;

    status = vfn<Slot74>(self, 0x74)(self, self->nodes[self->state->srcIds[0]],
                                     &local_c, &local_8);
    if (status < 0) return status;

    status = vfn<Slot68>(self, 0x68)(self, (uint32_t)(uintptr_t)local_c, 0x00e40000u,
                                     (uint32_t)(uintptr_t)local_8);
    if (status < 0) return status;

    status = vfn<Slot60>(self, 0x60)(self);
    if (status < 0) return status;

    status = FUN_0069fcf5();
    if (status < 0) return status;

    return 0;
}

// 0x6a65de — observed shape
int32_t FUN_006a65de(Receiver* self)
{
    void*    local_c = self;
    uint32_t local_8 = 0;

    int32_t status = FUN_006a48dd(0x1b);
    if (status < 0) return status;

    status = vfn<Slot68>(self, 0x68)(self, 0xf0000800u, 0x00e40000u, 0);
    if (status < 0) return status;

    status = vfn<Slot74>(self, 0x74)(self, self->nodes[self->state->srcIds[0]],
                                     &local_8, &local_c);
    if (status < 0) return status;

    status = vfn<Slot68>(self, 0x68)(self, local_8, 0x00e40000u,
                                     (uint32_t)(uintptr_t)local_c);
    if (status < 0) return status;

    status = vfn<Slot60>(self, 0x60)(self);
    if (status < 0) return status;

    status = FUN_0069fcf5();
    if (status < 0) return status;

    return 0;
}

// 0x6a6662 — observed shape
int32_t FUN_006a6662(Receiver* self)
{
    LayerState* state = self->state;

    if (self->unk8c == (int32_t)self->nodes[state->dstIds[0]]->word04) {
        return FUN_006a629c(self, 0x2e, 0);
    }

    if ((self->flags6e & 0x10) == 0) {
        uint32_t count = state->count0c;
        uint32_t index = 0;      // local_8
        if (count != 0) {
            int32_t* dstIds = state->dstIds;
            int32_t* srcIds = state->srcIds;
            do {
                Node* src = self->nodes[srcIds[index]];
                Node* dst = self->nodes[dstIds[index]];
                if ((src->word04 != dst->word04) ||
                    (src->word08 != dst->word08) ||
                    (src->word0c != dst->word0c) ||
                    (src->word10 != dst->word10) ||
                    (src->word3c != dst->word3c) ||
                    (((self->flagscc & 4) != 0) && (dst->word60 != 0))) break;
                index = index + 1;
            } while (index < count);
        }
        if (index == count) return 0;
    }

    uint32_t index = 0;   // local_8, reused
    if (state->count0c != 0) {
        do {
            Node*    dst = self->nodes[state->dstIds[index]];
            Node*    src = self->nodes[state->srcIds[index]];
            uint32_t* dstFlags = &dst->flags00;   // listing writes node->+0x00
            if ((*dstFlags & 0x0e000000u) == 0) {
                *dstFlags = (src->flags00 & 0x0e000000u) | *dstFlags;
            }
            index = index + 1;
        } while (index < state->count0c);
    }

    return FUN_006a4aab(1, state->dstIds, state->count0c, state->srcIds, 0, 0,
                        state->count0c, 0, 0, 0, 0);
}

// 0x6a6877 — observed shape
int32_t FUN_006a6877(Receiver* self)
{
    uint32_t count = self->state->header & 0xfffffu;
    int32_t  local_c[2] = {0, 0};
    int32_t  local_8[2] = {0, 0};

    if (count == 1) return FUN_006a629c(self, 5, 0);
    if (count == 3) return FUN_006a629c(self, 8, 0);
    if (count == 4) return FUN_006a629c(self, 9, 0);

    int32_t status = vfn<Slot80>(self, 0x80)(self, self->keyfc, local_c, 2, 0, 0);
    if (status < 0) return status;

    status = FUN_006a4aab(5, local_c, 2, self->state->srcIds,
                          self->state->srcIds + 2, 0, 2, 0, 0, 0, 0);
    if (status < 0) return status;

    status = FUN_006a4aab(2, self->state->dstIds, self->state->count0c, local_c,
                          local_8, 0, 1, 0, 0, 0, 0);
    if (status < 0) return status;

    return 0;
}

// 0x6a6952 — observed shape
void FUN_006a6952(DwordRecord* self, uint32_t param_1, uint32_t param_2,
                  uint32_t param_3, uint32_t param_4)
{
    if (param_4 > 4) param_4 = 4;

    self->slot[6]  = -1;
    self->slot[9]  = -1;
    self->slot[0]  = (int32_t)param_1;
    self->slot[1]  = (int32_t)param_2;
    self->slot[3]  = (int32_t)param_4;
    self->slot[10] = -1;
    self->slot[2]  = (int32_t)param_3;
    self->slot[4]  = 0;
    self->slot[5]  = 0;
    self->slot[7]  = 0;
    self->slot[8]  = 0;
    self->slot[11] = 0;
    self->slot[12] = 0;
}

// 0x6a699a — observed shape
int32_t FUN_006a699a(DwordRecord* self, const int32_t* source)
{
    if (source == nullptr) {
        return (int32_t)0x80004005u;   // E_FAIL
    }
    for (int32_t i = 0; i < 13; i = i + 1) {
        self->slot[i] = source[i];
    }
    return 0;
}

// 0x6a69ff — observed shape
void FUN_006a69ff(Graph* self, int32_t group, int32_t id)
{
    do {
        Node* node;
        for (;;) {
            node = self->pool->nodes[id];
            if (node->parent38 == -1) break;
            id = node->parent38;
        }
        node->word30 = -1;
        node->group74 = group;
        if ((self->pool->classes[node->word04]->flags4 & 0x10) == 0) {
            if (self->listA != nullptr) {
                self->listA[self->baseA[group] + self->countA[group]] = id;
            }
            self->countA[group] = self->countA[group] + 1;
        }
        id = node->word08;
    } while (id != -1);
}

// 0x6a6a74 — observed shape
void FUN_006a6a74(Graph* self, int32_t group, int32_t id)
{
    Node* node = self->pool->nodes[id];

    if (((self->pool->classes[node->word04]->flags4 & 0x20) == 0) &&
        (node->word5c != 0)) {
        if (self->listB != nullptr) {
            self->listB[self->baseB[group] + (int32_t)self->countB[group]] = id;
        }
        self->countB[group] = self->countB[group] + 1;
    }
    if (node->link14 != -1) {
        FUN_006a69ff(self, group, node->link14);
    }
}

// 0x6a6add — observed shape
void FUN_006a6add(Graph* self, int32_t first, uint32_t last)
{
    uint32_t half = (last - (uint32_t)first) >> 1;   // uVar4

    if (half == 0) return;

    int32_t* order = self->order;
    uint32_t low = (uint32_t)first << 2;    // byte offset
    uint32_t high = last << 2;              // byte offset
    uint32_t remaining = half;
    do {
        high = high - 4;
        int32_t* front = (int32_t*)((uint8_t*)order + low);
        int32_t  saved = *front;
        *front = *(int32_t*)((uint8_t*)order + high);
        *(int32_t*)((uint8_t*)order + high) = saved;
        low = low + 4;
        remaining = remaining - 1;
    } while (remaining != 0);
}

// 0x6a6b27 — observed shape
uint32_t FUN_006a6b27(int32_t param_1, int32_t param_2, Graph* ctx)
{
    uint32_t leftId = (uint32_t)ctx->order[param_1];
    uint32_t rightId = (uint32_t)ctx->order[param_2];

    if (ctx->score[leftId] <= ctx->score[rightId]) {
        if (ctx->score[leftId] < ctx->score[rightId]) {
            return 1;
        }
        if (rightId <= leftId) {
            return (uint32_t)(rightId < leftId);
        }
    }
    return 0xffffffffu;
}

// 0x6a6b6e — observed shape
void FUN_006a6b6e(int32_t* base, uint32_t* count)
{
    if (*count > 1) {
        FUN_0065e1b9(FUN_0065de5f, base, *count, 0);

        uint32_t read = 1;
        uint32_t write = 1;
        if (*count > 1) {
            do {
                int32_t value = base[read];
                if (value != base[read - 1]) {
                    base[write] = value;
                    write = write + 1;
                }
                read = read + 1;
            } while (read < *count);
        }
        *count = write;
    }
}

// 0x6a6bb4 — observed shape
void FUN_006a6bb4(Graph* self, int32_t* outTotal, uint32_t* outMax)
{
    uint32_t running = 0;   // uVar6
    uint32_t saved = 0;     // local_1c
    uint32_t total = 0;     // local_10
    uint32_t maxRun = 0;    // local_14
    uint32_t nodeIdx = 0;   // local_c

    if (self->count38 != 0) {
        do {
            int32_t    id = self->order[nodeIdx];
            NodeMeta*  meta = self->pool->meta18[id];

            self->score[id] = running;
            self->delta[id] = 0;

            if ((meta->flags2 & 0xfff0) != 0) {
                int32_t  baseIndex = self->baseA[id];          // +0x0c
                uint32_t predCount = (uint32_t)self->countA[id]; // +0x08
                uint32_t probe = 0;                            // local_8
                if (predCount != 0) {
                    do {
                        if (id == self->pool->nodes[self->listA[baseIndex + (int32_t)probe]]->owner58) {
                            self->delta[id] = self->delta[id] - 1;
                        }
                        probe = probe + 1;
                    } while (probe < predCount);
                    running = saved;
                }

                int32_t  succBase = self->baseB[id];             // +0x20
                uint32_t succCount = self->countB[id];           // +0x1c
                uint32_t succProbe = 0;                          // local_18
                if (succCount != 0) {
                    do {
                        if (self->pool->nodes[self->listB[succBase + (int32_t)succProbe]]->word5c != 0) {
                            self->delta[id] = self->delta[id] + 1;
                        }
                        succProbe = succProbe + 1;
                    } while (succProbe < succCount);
                }

                total = total + running;
                if (maxRun < running) maxRun = running;
                running = running + (uint32_t)self->delta[id];
                saved = running;
            }

            nodeIdx = nodeIdx + 1;
        } while (nodeIdx < self->count38);
    }

    if (outTotal != nullptr) *outTotal = (int32_t)total;
    if (outMax != nullptr) *outMax = maxRun;
}

