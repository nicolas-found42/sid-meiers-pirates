// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// Batch mass_0314 — assigned addresses 0x65b822 .. 0x65ca23.
// No byte-match claim: no toolchain parity on this host. Status: unverified.
// Field offsets, constants, call order and conditional order are transcribed
// from the corpus listings; struct layouts, types and parameter names are
// inferred. Every `self` is a register receiver lifted out of the listing.

#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <windows.h>

// ---- corpus data labels (vtable slots; addresses as named by the corpus) ----
extern void* PTR_FUN_006ee090;
extern void* PTR_FUN_006ee09c;
extern void* PTR_FUN_006ee20c;

// ---- corpus callees referenced by this batch ----
void*    FUN_0065ab96(uint32_t kind);       // base initialiser; returns the object under construction
uint32_t FUN_0065abb5(int32_t p);
uint32_t FUN_0065ad6e();
uint32_t FUN_0065abd0(uint32_t a, uint32_t b);
void*    FUN_0060d19b(uint32_t size);
void*    FUN_0065ac33();
void*    FUN_0065aaac(uint32_t size, uint32_t align);
void     FUN_0060fcd3(uint32_t ctx, const void* obj, uint32_t code, const char* fmt, ...);
void     operator_delete(void* p);          // corpus label (MSVC scalar deleting dtor)
void*    FUN_00533c78(uint32_t size);
int32_t  FUN_005f7fa4(int32_t typeNode, int32_t flags, void* out);
int32_t  FUN_00636edb(int32_t a, const void* desc, int32_t b, int32_t c,
                      uint32_t d, int32_t e, void* out, int32_t f);
int32_t  FUN_0069ee3f(uint32_t ctx, uint32_t typeNode, int32_t a, int32_t b, void* out);
void*    FUN_0065abf1(uint32_t handle);
void*    FUN_0065b1db();
void*    FUN_0065b377();
void*    FUN_0065b4f3();
void*    FUN_0065b5fa();

// ---- observed node/container layouts shared by the buffer routines ----
struct BufNode {              // 0x14 bytes
    char*    data;            // +0x00
    uint32_t length;          // +0x04
    uint32_t flags;           // +0x08
    uint32_t offset;          // +0x0c
    BufNode* next;            // +0x10
};

struct BufContainer {         // 0x10 bytes
    void*     owner;          // +0x00
    uint32_t  size;           // +0x04
    BufNode*  head;           // +0x08
    BufNode** tail;           // +0x0c  (points at head, then at last->next)
};

// ---- address/field helpers (offsets are the corpus byte offsets) ----
static inline uint32_t addr(const void* p)
{
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p));
}

static inline uint32_t ld32(uint32_t base, size_t off)
{
    return *reinterpret_cast<const uint32_t*>(static_cast<uintptr_t>(base + off));
}

static inline void st32(uint32_t base, size_t off, uint32_t v)
{
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(base + off)) = v;
}

static inline uint16_t ld16(uint32_t base, size_t off)
{
    return *reinterpret_cast<const uint16_t*>(static_cast<uintptr_t>(base + off));
}

static inline void st16(uint32_t base, size_t off, uint16_t v)
{
    *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(base + off)) = v;
}

static inline uint8_t ld8(uint32_t base, size_t off)
{
    return *reinterpret_cast<const uint8_t*>(static_cast<uintptr_t>(base + off));
}

static inline void st8(uint32_t base, size_t off, uint8_t v)
{
    *reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(base + off)) = v;
}

// Corpus form: `(**(code **)(*(int *)obj + 4))()` with the receiver in ECX.
static inline uint32_t call_vtbl1(void* obj)
{
    void** vtbl = *reinterpret_cast<void***>(obj);
    return reinterpret_cast<uint32_t (*)(void*)>(vtbl[1])(obj);
}

// 0x65b822 — observed shape
// Cluster constructor: stamps the vtable for a kind-0x0f base object, copies an
// 8-dword payload into +0x10, then stores two words at +0x30/+0x34.
void* FUN_0065b822(const uint32_t* param_1, uint32_t param_2, uint32_t param_3)
{
    // Observed: the destination arrives in EDX from the base-init call.
    uint32_t* obj = static_cast<uint32_t*>(FUN_0065ab96(0xf));
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006ee090));
    uint32_t* dst = obj + 4;
    for (int iVar1 = 8; iVar1 != 0; iVar1 = iVar1 - 1) {
        *dst = *param_1;
        param_1 = param_1 + 1;
        dst = dst + 1;
    }
    obj[0xc] = param_2;
    obj[0xd] = param_3;
    return obj;
}

// 0x65b857 — observed shape
// Predicate over two helpers followed by two trailing word comparisons.
bool FUN_0065b857(void* self, int32_t param_1)
{
    int32_t iVar1 = static_cast<int32_t>(FUN_0065abb5(param_1));
    if (iVar1 == 0) return false;
    iVar1 = static_cast<int32_t>(FUN_0065ad6e());
    if (iVar1 == 0) return false;
    if (ld32(static_cast<uint32_t>(param_1), 0x30) != ld32(addr(self), 0x30)) return false;
    return ld32(static_cast<uint32_t>(param_1), 0x34) == ld32(addr(self), 0x34);
}

// 0x65b8b3 — observed shape
// Cluster constructor: base init 0x11, two words at +0x10/+0x14, vtable stamp.
void* FUN_0065b8b3(uint32_t param_1, uint32_t param_2)
{
    uint32_t* obj = static_cast<uint32_t*>(FUN_0065ab96(0x11));
    obj[4] = param_1;
    obj[5] = param_2;
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006ee09c));
    return obj;
}

// 0x65b8d9 — observed shape
// Predicate: helper, then two compared word pairs at +0x10 and +0x14.
uint32_t FUN_0065b8d9(void* self, uint32_t param_1)
{
    if (static_cast<int32_t>(FUN_0065abb5(static_cast<int32_t>(param_1))) == 0) return 0;
    if (FUN_0065abd0(ld32(param_1, 0x10), ld32(addr(self), 0x10)) == 0) return 0;
    if (FUN_0065abd0(ld32(param_1, 0x14), ld32(addr(self), 0x14)) == 0) return 0;
    return 1;
}

// 0x65b93a — observed shape
// Walks a descriptor chain (kind word at +0x04 must be 1), allocates 0x14-byte
// nodes, copies the chain's +0x10 word, and clones a sub-object through vtable
// slot 1 when the +0x08 word is non-null. `local_8` accumulates the chain head;
// the walk cursor advances through node+0x0c of each produced node.
int32_t FUN_0065b93a(void* self)
{
    uint32_t local_8 = 0;
    uint32_t* piVar3 = &local_8;
    uint32_t node = addr(self);
    for (;;) {
        if (node == 0) return static_cast<int32_t>(local_8);
        if (ld32(node, 4) != 1) break;
        int32_t iVar1;
        if (FUN_0060d19b(0x14) == nullptr) iVar1 = 0;
        else iVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_0065ac33()));
        *piVar3 = static_cast<uint32_t>(iVar1);
        if (iVar1 == 0) return static_cast<int32_t>(local_8);
        st32(static_cast<uint32_t>(iVar1), 0x10, ld32(node, 0x10));
        if (ld32(node, 8) != 0) {
            uint32_t uVar2 = call_vtbl1(
                reinterpret_cast<void*>(static_cast<uintptr_t>(ld32(node, 8))));
            st32(static_cast<uint32_t>(iVar1), 8, uVar2);
            if (ld32(static_cast<uint32_t>(iVar1), 8) == 0) {
                *piVar3 = 0;
                return static_cast<int32_t>(local_8);
            }
        }
        node = ld32(node, 0x0c);
        piVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*piVar3 + 0x0c));
    }
    *piVar3 = call_vtbl1(reinterpret_cast<void*>(static_cast<uintptr_t>(node)));
    return static_cast<int32_t>(local_8);
}

// 0x65bc2f — observed shape
// Clone: allocates 0x24, constructs, copies five words (+0x10 .. +0x20).
void FUN_0065bc2f(void* self)
{
    int32_t iVar1;
    if (FUN_0060d19b(0x24) == nullptr) iVar1 = 0;
    else iVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_0065b1db()));
    if (iVar1 == 0) return;
    st32(static_cast<uint32_t>(iVar1), 0x10, ld32(addr(self), 0x10));
    st32(static_cast<uint32_t>(iVar1), 0x14, ld32(addr(self), 0x14));
    st32(static_cast<uint32_t>(iVar1), 0x18, ld32(addr(self), 0x18));
    st32(static_cast<uint32_t>(iVar1), 0x1c, ld32(addr(self), 0x1c));
    st32(static_cast<uint32_t>(iVar1), 0x20, ld32(addr(self), 0x20));
    return;
}

// 0x65bd4d — observed shape
// Clone: allocates 0x40, constructs, copies five words, then deep-copies each of
// the five pointer fields at +0x20..+0x30 through vtable slot 1, and copies the
// two count-sized arrays at +0x38/+0x3c. Any failed clone/allocation aborts 0.
int32_t FUN_0065bd4d(void* self)
{
    void* obj;
    if (FUN_0060d19b(0x40) == nullptr) obj = nullptr;
    else obj = FUN_0065b377();
    if (obj == nullptr) return 0;

    st32(addr(obj), 0x10, ld32(addr(self), 0x10));
    st32(addr(obj), 0x14, ld32(addr(self), 0x14));
    st32(addr(obj), 0x18, ld32(addr(self), 0x18));
    st32(addr(obj), 0x1c, ld32(addr(self), 0x1c));
    st32(addr(obj), 0x34, ld32(addr(self), 0x34));

    static const size_t kCloneOffs[5] = { 0x20, 0x24, 0x28, 0x2c, 0x30 };
    for (size_t k = 0; k < 5; ++k) {
        uint32_t src = ld32(addr(self), kCloneOffs[k]);
        if (src != 0) {
            uint32_t copy = call_vtbl1(reinterpret_cast<void*>(static_cast<uintptr_t>(src)));
            st32(addr(obj), kCloneOffs[k], copy);
            if (copy == 0) return 0;
        }
    }

    if (ld32(addr(self), 0x34) == 0) return static_cast<int32_t>(addr(obj));

    void* a = FUN_0065aaac(ld32(addr(self), 0x34) << 2, 0x10);
    st32(addr(obj), 0x38, static_cast<uint32_t>(addr(a)));
    if (a == nullptr) return 0;

    void* b = FUN_0065aaac(ld32(addr(self), 0x14) << 2, 0x10);
    st32(addr(obj), 0x3c, static_cast<uint32_t>(addr(b)));
    if (b == nullptr) return 0;

    // Observed dword-copy loops over (count << 2) bytes; the byte tails are
    // zero-length because the element size is a multiple of 4.
    const uint32_t* srcA = reinterpret_cast<const uint32_t*>(
        static_cast<uintptr_t>(ld32(addr(self), 0x38)));
    uint32_t* dstA = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(ld32(addr(obj), 0x38)));
    for (uint32_t u = ld32(addr(self), 0x34) & 0x3fffffffu; u != 0; --u) *dstA++ = *srcA++;

    const uint32_t* srcB = reinterpret_cast<const uint32_t*>(
        static_cast<uintptr_t>(ld32(addr(self), 0x3c)));
    uint32_t* dstB = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(ld32(addr(obj), 0x3c)));
    for (uint32_t u = ld32(addr(self), 0x14) & 0x3fffffffu; u != 0; --u) *dstB++ = *srcB++;

    return static_cast<int32_t>(addr(obj));
}

// 0x65bf16 — observed shape
// Clone: allocates 0x50, constructs, copies four words and a 8-dword block at
// +0x30, then clone three sub-objects at +0x10/+0x20/+0x24.
int32_t FUN_0065bf16(void* self)
{
    void* obj;
    if (FUN_0060d19b(0x50) == nullptr) obj = nullptr;
    else obj = FUN_0065b4f3();
    if (obj == nullptr) return 0;

    st32(addr(obj), 0x14, ld32(addr(self), 0x14));
    st32(addr(obj), 0x18, ld32(addr(self), 0x18));
    st32(addr(obj), 0x1c, ld32(addr(self), 0x1c));
    st32(addr(obj), 0x28, ld32(addr(self), 0x28));

    const uint32_t* puVar2 = reinterpret_cast<const uint32_t*>(
        static_cast<uintptr_t>(addr(self) + 0x30));
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(addr(obj) + 0x30));
    for (int iVar1 = 8; iVar1 != 0; iVar1 = iVar1 - 1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }

    if (ld32(addr(self), 0x10) != 0) {
        uint32_t copy = call_vtbl1(
            reinterpret_cast<void*>(static_cast<uintptr_t>(ld32(addr(self), 0x10))));
        st32(addr(obj), 0x10, copy);
        if (copy == 0) return 0;
    }
    if (ld32(addr(self), 0x20) != 0) {
        uint32_t copy = call_vtbl1(
            reinterpret_cast<void*>(static_cast<uintptr_t>(ld32(addr(self), 0x20))));
        st32(addr(obj), 0x20, copy);
        if (copy == 0) return 0;
    }
    if (ld32(addr(self), 0x24) == 0) return static_cast<int32_t>(addr(obj));
    uint32_t copy = call_vtbl1(
        reinterpret_cast<void*>(static_cast<uintptr_t>(ld32(addr(self), 0x24))));
    st32(addr(obj), 0x24, copy);
    if (copy == 0) return 0;
    return static_cast<int32_t>(addr(obj));
}

// 0x65bfbf — observed shape
// Clone: allocates 0x40, constructs, copies four words plus an 8-dword block at
// +0x20. When the source kind is 4 and +0x18 is set, it re-registers the handle
// and writes the result back into the SOURCE object (+0x18) as observed.
int32_t FUN_0065bfbf(void* self)
{
    void* obj;
    if (FUN_0060d19b(0x40) == nullptr) obj = nullptr;
    else obj = FUN_0065b5fa();
    if (obj == nullptr) return 0;

    st32(addr(obj), 0x10, ld32(addr(self), 0x10));
    st32(addr(obj), 0x14, ld32(addr(self), 0x14));
    st32(addr(obj), 0x18, ld32(addr(self), 0x18));
    st32(addr(obj), 0x1c, ld32(addr(self), 0x1c));

    const uint32_t* puVar2 = reinterpret_cast<const uint32_t*>(
        static_cast<uintptr_t>(addr(self) + 0x20));
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(addr(obj) + 0x20));
    for (int iVar1 = 8; iVar1 != 0; iVar1 = iVar1 - 1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }

    if (ld32(addr(self), 0x10) == 4 && ld32(addr(self), 0x18) != 0) {
        uint32_t iVar1 = addr(FUN_0065abf1(ld32(addr(self), 0x18)));
        st32(addr(self), 0x18, iVar1);      // observed: stores back into the source object
        if (iVar1 == 0) obj = nullptr;
    }
    return static_cast<int32_t>(addr(obj));
}

// 0x65c125 — observed shape
// Container constructor: owner word, running size 0, empty head, and the tail
// pointer seeded to the address of the head field.
void FUN_0065c125(void* self, uint32_t param_1)
{
    uint32_t* w = static_cast<uint32_t*>(self);
    w[1] = 0;
    w[0] = param_1;
    w[2] = 0;
    w[3] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(w + 2));
    return;
}

// 0x65c142 — observed shape
// Destroys the container's node list; the owned text is freed unless the node
// carries flag bit 3 or lacks ownership flag bit 1.
void FUN_0065c142(void* self)
{
    BufContainer* c = static_cast<BufContainer*>(self);
    int32_t iVar1 = static_cast<int32_t>(addr(c->head));
    while (iVar1 != 0) {
        BufNode* puVar2 = c->head;
        c->head = puVar2->next;
        if (((puVar2->flags & 8) != 0) || ((puVar2->flags & 1) == 0))
            operator_delete(puVar2->data);
        operator_delete(puVar2);
        iVar1 = static_cast<int32_t>(addr(c->head));
    }
    return;
}

// 0x65c17a — observed shape
// Interns one buffer into the container: validates the (data,len) pair, computes
// the length for a -1 sentinel, dedupes against flag-bit-2 nodes of equal length,
// else allocates a 0x14 node (copying the bytes unless the caller hands over
// ownership) and appends it through the tail pointer.
int32_t FUN_0065c17a(void* self, char* param_1, char* param_2, uint32_t param_3, uint32_t* param_4)
{
    BufContainer* c = static_cast<BufContainer*>(self);

    if (param_2 != nullptr && param_1 == nullptr) return -0x7fffbffb;   // 0x80004005
    if (reinterpret_cast<intptr_t>(param_2) == -1) {
        char* p = param_1;
        char cVar1;
        do {
            cVar1 = *p;
            p = p + 1;
        } while (cVar1 != '\0');
        // observed: p + (1 - (data + 1))
        param_2 = reinterpret_cast<char*>(
            reinterpret_cast<intptr_t>(p)
            + (1 - (reinterpret_cast<intptr_t>(param_1) + 1)));
    }
    if ((param_3 & 1) == 0) param_3 = param_3 | 2;

    if ((param_3 & 2) != 0) {
        for (BufNode* n = c->head; n != nullptr; n = n->next) {
            if (((n->flags & 2) != 0)
                && param_2 == reinterpret_cast<char*>(static_cast<uintptr_t>(n->length))) {
                bool bVar8 = true;
                const char* pcVar6 = param_1;
                const char* pcVar7 = n->data;
                intptr_t pcVar4 = reinterpret_cast<intptr_t>(param_2);
                do {
                    if (pcVar4 == 0) break;
                    pcVar4 = pcVar4 - 1;
                    bVar8 = (*pcVar6 == *pcVar7);
                    pcVar6 = pcVar6 + 1;
                    pcVar7 = pcVar7 + 1;
                } while (bVar8);
                if (bVar8) {
                    if (param_4 != nullptr) *param_4 = n->offset;
                    if (((param_3 & 1) != 0) && ((param_3 & 8) != 0)) operator_delete(param_1);
                    return 0;
                }
            }
        }
    }

    BufNode* node = static_cast<BufNode*>(FUN_00533c78(0x14));
    if (node == nullptr) return -0x7ff8fff2;                            // 0x8007000e

    if ((param_3 & 1) == 0) {
        char* pcVar4 = static_cast<char*>(
            FUN_00533c78(static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_2))));
        node->data = pcVar4;
        if (pcVar4 == nullptr) {
            operator_delete(node);
            return -0x7ff8fff2;
        }
        uint32_t uVar5 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_2)) >> 2;
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            *reinterpret_cast<uint32_t*>(pcVar4) = *reinterpret_cast<const uint32_t*>(param_1);
            param_1 = param_1 + 4;
            pcVar4 = pcVar4 + 4;
        }
        for (uVar5 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_2)) & 3;
             uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar4 = *param_1;
            param_1 = param_1 + 1;
            pcVar4 = pcVar4 + 1;
        }
    } else {
        node->data = param_1;
    }

    if ((param_3 & 4) == 0)
        c->size = (c->size + 3) & 0xfffffffc;

    uint32_t uVar3 = c->size;
    node->flags = param_3;
    node->next = nullptr;
    node->offset = uVar3;
    node->length = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_2));
    c->size = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_2)
                                    + static_cast<intptr_t>(c->size));

    *c->tail = node;
    c->tail = &node->next;

    if (param_4 != nullptr) *param_4 = node->offset;
    return 0;
}

// 0x65c2bf — observed shape
// Serialises the container into a caller buffer: 8-byte header (word0 packs
// ((capacity-1) & 0x7fff) << 16 | 0xfffe, word1 is the owner), then every node
// without flag bit 2, 4-byte aligned and padded with 0xab, then tail padding to
// capacity*4-8 bytes.
int32_t FUN_0065c2bf(void* self, uint32_t* param_1, uint32_t* param_2)
{
    BufContainer* c = static_cast<BufContainer*>(self);
    uint32_t* puVar5 = param_1;
    uint32_t uVar4;

    if (reinterpret_cast<intptr_t>(param_2) == -1) {
        uVar4 = ((c->size + 3) >> 2) + 2;
    } else {
        uVar4 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_2));
        if (static_cast<uintptr_t>(param_2) < (((c->size + 3) >> 2) + 2))
            return -0x7fffbffb;                                          // 0x80004005
    }
    if (uVar4 > 0x8000) return -0x7fffbffb;

    uint32_t written = 0;   // observed: the buffer parameter is reused as a byte counter, reset to 0
    *puVar5 = ((uVar4 - 1) & 0x7fff) << 0x10 | 0xfffe;
    puVar5[1] = ld32(addr(c), 0);
    uint32_t* pOut = puVar5 + 2;

    for (BufNode* puVar1 = c->head; puVar1 != nullptr; puVar1 = puVar1->next) {
        if ((puVar1->flags & 4) == 0) {
            uint32_t uVar2 = ((written + 3u) & 0xfffffffc) - written;
            uint32_t* p32 = pOut;
            for (uint32_t uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                *p32 = 0xabababab;
                p32 = p32 + 1;
            }
            for (uint32_t uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *reinterpret_cast<uint8_t*>(p32) = 0xab;
                p32 = reinterpret_cast<uint32_t*>(
                    reinterpret_cast<uint8_t*>(p32) + 1);
            }
            pOut = reinterpret_cast<uint32_t*>(
                reinterpret_cast<uint8_t*>(pOut) + uVar2);
            written = written + uVar2;
        }

        uint32_t uVar2 = puVar1->length;
        const uint32_t* src = reinterpret_cast<const uint32_t*>(puVar1->data);
        uint32_t* dst = pOut;
        for (uint32_t uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *dst = *src;
            src = src + 1;
            dst = dst + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *reinterpret_cast<char*>(dst) = *reinterpret_cast<const char*>(src);
            src = reinterpret_cast<const uint32_t*>(
                reinterpret_cast<const char*>(src) + 1);
            dst = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(dst) + 1);
        }
        pOut = reinterpret_cast<uint32_t*>(
            reinterpret_cast<uint8_t*>(pOut) + puVar1->length);
        written = written + puVar1->length;
    }

    uint32_t uVar2 = (uVar4 * 4 - 8) - written;
    uint32_t* p32 = pOut;
    for (uint32_t uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *p32 = 0xabababab;
        p32 = p32 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *reinterpret_cast<uint8_t*>(p32) = 0xab;
        p32 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(p32) + 1);
    }
    return 0;
}

// 0x65c3c2 — observed shape
// Recursive type/size walk over the expression tree (node kind at +0x04).
//   kind 1: sum over the sibling chain at +0x0c, tracking the largest element in
//           the out word and the running total in the other;
//   kind 8: recurse into +0x10, then total = chain word at +0x14 * out word;
//   kind 9: constant/vector forms; out = 1 with +0x1c, or +0x1c and +0x18, or 1.
// When the third argument is null the accumulator aliases the first parameter.
int32_t FUN_0065c3c2(int32_t param_1, int32_t* param_2, int32_t* param_3)
{
    int32_t* piVar5 = param_2;
    int32_t iVar1 = param_1;
    int32_t* piVar4 = param_3;
    if (param_3 == nullptr) piVar4 = &param_1;

    int32_t iVar2 = static_cast<int32_t>(ld32(static_cast<uint32_t>(param_1), 4));

    if (iVar2 == 9) {
        iVar2 = static_cast<int32_t>(ld32(static_cast<uint32_t>(param_1), 0x10));
        iVar1 = 1;
        piVar5 = piVar4;
        if (iVar2 == 1 || iVar2 == 0) {
            *param_2 = 1;
            iVar1 = static_cast<int32_t>(ld32(static_cast<uint32_t>(param_1), 0x1c));
        } else if (iVar2 == 2) {
            *param_2 = static_cast<int32_t>(ld32(static_cast<uint32_t>(param_1), 0x1c));
            iVar1 = static_cast<int32_t>(ld32(static_cast<uint32_t>(param_1), 0x18));
        } else {
            if (iVar2 != 3) return -0x7fffbffb;                          // 0x80004005
            *param_2 = 1;
        }
        *piVar5 = iVar1;
        return 0;
    }

    if (iVar2 != 8) {
        if (iVar2 != 1) return -0x7fffbffb;
        *param_2 = 0;
        *piVar4 = 0;
        do {
            // observed: recurse through *(*(*(node+8)+0x18)+0x20); the out slots are
            // the frame's own parameter storage.
            iVar2 = FUN_0065c3c2(
                static_cast<int32_t>(ld32(
                    ld32(ld32(static_cast<uint32_t>(iVar1), 8), 0x18), 0x20)),
                reinterpret_cast<int32_t*>(&param_3),
                reinterpret_cast<int32_t*>(&param_2));
            if (iVar2 < 0) return iVar2;
            *piVar5 = *piVar5 + static_cast<int32_t>(reinterpret_cast<intptr_t>(param_3));
            int32_t* piVar3 = reinterpret_cast<int32_t*>(
                static_cast<intptr_t>(*piVar4));
            if (piVar3 < param_2) piVar3 = param_2;
            *piVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar3));
            iVar1 = static_cast<int32_t>(ld32(static_cast<uint32_t>(iVar1), 0x0c));
        } while (iVar1 != 0);
        return 0;
    }

    iVar2 = FUN_0065c3c2(static_cast<int32_t>(
                             ld32(static_cast<uint32_t>(param_1), 0x10)),
                         param_2, piVar4);
    if (iVar2 < 0) return iVar2;
    iVar1 = static_cast<int32_t>(ld32(static_cast<uint32_t>(iVar1), 0x14)) * *piVar5;
    *piVar5 = iVar1;
    return 0;
}

// 0x65c485 — observed shape
// Declares a constant register (token sigil in the low word of param_2) and
// rejects _b/boolean and _i/integer constants whose declared type is wrong.
int32_t FUN_0065c485(void* self, const uint32_t* param_1, int16_t* param_2, uint32_t* param_3)
{
    const int16_t* psVar1 = param_2;

    // Observed 8-dword descriptor copy, then slots 0 and 2 overwritten.
    uintptr_t local_24[8];
    for (int i = 0; i < 8; ++i) local_24[i] = param_1[i];
    reinterpret_cast<const int16_t**>(local_24)[2] = param_2 + 1;
    reinterpret_cast<const int16_t**>(local_24)[0] =
        reinterpret_cast<const int16_t*>(static_cast<uintptr_t>(0xa));

    int32_t iVar2 = FUN_00636edb(1, local_24, 0, 0, ld32(addr(self), 4), 2, &param_2, 0);
    if (iVar2 == 0) {
        // Observed: 64-bit corpus result (EDX:EAX); the low half is the HRESULT and
        // the listing uses the high half as an out pointer.
        uint64_t uVar6 = static_cast<uint64_t>(static_cast<uint32_t>(
            FUN_0065c3c2(static_cast<int32_t>(ld32(addr(param_2), 0x10)),
                         reinterpret_cast<int32_t*>(param_3), nullptr)));
        int32_t* piVar3 = reinterpret_cast<int32_t*>(
            static_cast<uintptr_t>(uVar6 >> 32));
        if (static_cast<int32_t>(uVar6) < 0) return static_cast<int32_t>(uVar6);

        if (*psVar1 == 0x5f62) {                                        // '_b'
            int32_t iVar1 = 0;
            bool bBad = (*piVar3 != 1);
            if (!bBad) {
                iVar1 = static_cast<int32_t>(ld32(addr(param_2), 0x10));
                bBad = (ld32(static_cast<uint32_t>(iVar1), 4) != 9)
                    || (ld32(static_cast<uint32_t>(iVar1), 0x10) != 0)
                    || (ld32(static_cast<uint32_t>(iVar1), 0x14) != 0);
            }
            if (bBad) {
                FUN_0060fcd3(ld32(ld32(addr(self), 0), 4) + 0x18, param_1, 0xb54,
                             "boolean constant register \'%s\' must be defined as a variable of type bool only",
                             psVar1);
                return -0x7fffbffb;
            }
        } else if (*psVar1 == 0x5f69) {                                 // '_i'
            int32_t iVar1 = 0;
            bool bBad = (*piVar3 != 1);
            if (!bBad) {
                iVar1 = static_cast<int32_t>(ld32(addr(param_2), 0x10));
                bBad = (ld32(static_cast<uint32_t>(iVar1), 4) != 9)
                    || (ld32(static_cast<uint32_t>(iVar1), 0x10) != 1)
                    || (ld32(static_cast<uint32_t>(iVar1), 0x14) != 4)
                    || (ld32(static_cast<uint32_t>(iVar1), 0x1c) < 3);
            }
            if (bBad) {
                FUN_0060fcd3(ld32(ld32(addr(self), 0), 4) + 0x18, param_1, 0xb55,
                             "integer constant register \'%s\' must be defined as a variable of type int3 or int4 only",
                             psVar1);
                return -0x7fffbffb;
            }
        }
    } else {
        *param_3 = 0;
    }
    return 0;
}

// 0x65c580 — observed shape
// NEEDS_MANUAL: this listing materialises no in_ECX, yet the inner FUN_0065c17a
// call requires a container receiver; it is modelled as `self` and forwarded
// (the same container the sibling 0x65c643/0x65c69a paths use). param_1 is
// observed but never read by the body.
// Flattens a kind-0x0d value whose +0x20 chain is a length-4 type list: allocates
// count*16 zeroed bytes, stores either the double or float payload of each type
// node at +0x18, then interns the block with flags 6.
int32_t FUN_0065c580(void* self, uint32_t param_1, float* param_2, int32_t param_3,
                     uint32_t param_4, uint32_t param_5)
{
    int32_t uVar6 = 0;
    float* local_8 = nullptr;

    if (ld32(param_4, 4) == 0xd) {
        uint32_t iVar5 = ld32(param_4, 0x20);
        if (ld32(iVar5, 4) == 1) {
            int32_t iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_2)) << 4;
            local_8 = static_cast<float*>(FUN_00533c78(static_cast<uint32_t>(iVar4)));
            if (local_8 == nullptr) {
                uVar6 = static_cast<int32_t>(0x8007000eu);
            } else {
                float* pfVar3 = local_8;
                for (int32_t iVar2 = static_cast<int32_t>(
                         (static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_2))
                          & 0xfffffffu) << 2);
                     iVar2 != 0; iVar2 = iVar2 - 1) {
                    *pfVar3 = 0.0f;
                    pfVar3 = pfVar3 + 1;
                }
                if (reinterpret_cast<intptr_t>(param_2) != 0) {
                    uint32_t count = static_cast<uint32_t>(
                        reinterpret_cast<uintptr_t>(param_2));
                    float* cursor = local_8;
                    do {
                        if (param_3 != 0) {
                            pfVar3 = cursor;
                            int32_t iVar2 = param_3;
                            do {
                                uint32_t iVar1 = ld32(iVar5, 8);
                                if (ld32(iVar1, 0x10) == 3) {
                                    *pfVar3 = static_cast<float>(
                                        *reinterpret_cast<const double*>(
                                            static_cast<uintptr_t>(iVar1 + 0x18)));
                                } else {
                                    *pfVar3 = *reinterpret_cast<const float*>(
                                        static_cast<uintptr_t>(iVar1 + 0x18));
                                }
                                iVar5 = ld32(iVar5, 0x0c);
                                pfVar3 = pfVar3 + 1;
                                iVar2 = iVar2 - 1;
                            } while (iVar2 != 0);
                        }
                        cursor = cursor + 4;
                        count = count - 1;
                    } while (count != 0);
                }
                uVar6 = FUN_0065c17a(self,
                                     reinterpret_cast<char*>(static_cast<intptr_t>(iVar4)),
                                     reinterpret_cast<char*>(static_cast<intptr_t>(6)),
                                     param_5);
            }
        }
        operator_delete(local_8);
    } else {
        uVar6 = 0;
    }
    return uVar6;
}

// 0x65c643 — observed shape
// NEEDS_MANUAL: no in_ECX in this listing; the inner FUN_0065c17a receiver is
// modelled as `self` (see 0x65c580). param_1 is observed but never read.
// Interns a zero-filled count*16 block with flags 6, then frees the staging
// buffer regardless of the intern result.
int32_t FUN_0065c643(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    void* puVar1 = FUN_00533c78(param_2 << 4);
    int32_t uVar3;
    if (puVar1 == nullptr) {
        uVar3 = static_cast<int32_t>(0x8007000eu);
    } else {
        uint32_t* puVar4 = static_cast<uint32_t*>(puVar1);
        for (uint32_t iVar2 = (param_2 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 - 1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        uVar3 = FUN_0065c17a(self, static_cast<char*>(puVar1),
                             reinterpret_cast<char*>(
                                 static_cast<intptr_t>(param_2 << 4)),
                             6,
                             reinterpret_cast<uint32_t*>(
                                 static_cast<uintptr_t>(param_3)));
    }
    operator_delete(puVar1);
    return uVar3;
}

// 0x65c69a — observed shape
// Resolves one constant-register declaration token (sigils _c/_b/_i/_s in the
// low word of param_3) into the entry at param_2: looks up the declaration,
// handles named-vs-literal register binding (including the >8191 rejection and
// the sampler-type requirement), interns the token string, and writes the
// entry header words (+0x04 kind, +0x06 param_4, +0x08 register/length word).
int32_t FUN_0065c69a(void* self, uint32_t param_1, char* param_2, int16_t* param_3,
                     uint16_t param_4, uint32_t param_5)
{
    int32_t iVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_2));
    param_5 = param_5 | 0x80000000u;
    int32_t local_8 = 0;
    uint32_t local_c = 0;
    uint32_t local_24 = 0;
    uint32_t local_2c = 0;
    uint8_t local_30[4] = { 0, 0, 0, 0 };
    int16_t* local_1c = nullptr;
    int32_t local_10 = 0;
    char* local_14 = nullptr;
    char* local_18 = nullptr;
    int32_t iVar2 = 0;
    int32_t iVar4 = 0;
    char* pcVar5 = nullptr;
    uint32_t uVar3 = 0;

    if ((*param_3 == 0x5f63) || (*param_3 == 0x5f62)
        || (*param_3 == 0x5f69) || (*param_3 == 0x5f73)) {
        int16_t* local_58 = param_3 + 1;
        uint32_t local_60[5];
        local_60[0] = 10;
        local_60[1] = 0;   // observed: this slot is left uninitialised
        reinterpret_cast<const int16_t**>(local_60)[2] = local_58;
        local_60[3] = 0;
        local_60[4] = 0;
        local_1c = local_58;

        FUN_00636edb(1, local_60, 0, 0, ld32(addr(self), 4), 2, &local_8, 0);
        iVar2 = FUN_0065c3c2(static_cast<int32_t>(ld32(static_cast<uint32_t>(local_8), 0x20)),
                             reinterpret_cast<int32_t*>(&local_c),
                             reinterpret_cast<int32_t*>(&local_24));
        if (iVar2 < 0) return iVar2;

        if (ld32(static_cast<uint32_t>(local_8), 0x30) != 0) {
            local_10 = static_cast<int32_t>(ld32(static_cast<uint32_t>(local_8), 0x30));
            param_2 = nullptr;
            local_14 = nullptr;
            local_18 = nullptr;
            if (local_10 == 0) {
                param_2 = local_14;
                if (local_14 == nullptr) {
                    param_2 = local_18;
                    if (local_18 == nullptr) goto LAB_0065c8f3;
                }
            } else {
                do {
                    iVar2 = static_cast<int32_t>(
                        ld32(static_cast<uint32_t>(local_10), 8));
                    if (ld32(static_cast<uint32_t>(iVar2), 4) == 0x11) {
                        if (ld32(static_cast<uint32_t>(iVar2), 0x10) == 0) {
                            iVar4 = 0;
                        } else {
                            iVar4 = static_cast<int32_t>(ld32(
                                ld32(static_cast<uint32_t>(iVar2), 0x10), 0x18));
                        }
                        if (ld32(static_cast<uint32_t>(iVar2), 0x14) == 0) {
                            pcVar5 = nullptr;
                        } else {
                            pcVar5 = reinterpret_cast<char*>(static_cast<uintptr_t>(
                                ld32(ld32(static_cast<uint32_t>(iVar2), 0x14), 0x18)));
                        }
                        if (iVar4 == 0) {
                            if (pcVar5 != nullptr
                                && tolower(static_cast<int>(
                                       static_cast<unsigned char>(*pcVar5)))
                                       == static_cast<char>(*param_3)) {
                                local_18 = pcVar5;
                            }
                        } else {
                            iVar2 = FUN_005f7fa4(iVar4, 0, local_30);
                            if (iVar2 > -1 && pcVar5 != nullptr
                                && tolower(static_cast<int>(
                                       static_cast<unsigned char>(*pcVar5)))
                                       == static_cast<char>(*param_3)) {
                                if (param_5 == local_2c) {
                                    param_2 = pcVar5;
                                } else if (((local_2c ^ param_5) & 0xffff0000u) == 0
                                           && static_cast<int16_t>(local_2c) == 0) {
                                    local_14 = pcVar5;
                                }
                            }
                        }
                    }
                    local_10 = static_cast<int32_t>(
                        ld32(static_cast<uint32_t>(local_10), 0x0c));
                } while (local_10 != 0);
                local_10 = 0;
                if (param_2 == nullptr) {
                    param_2 = local_14;
                    if (local_14 == nullptr) {
                        param_2 = local_18;
                        if (local_18 == nullptr) goto LAB_0065c8f3;
                    }
                }
            }

            iVar2 = tolower(static_cast<int>(
                static_cast<unsigned char>(*param_2)));
            if (static_cast<char>(*param_3) != iVar2) goto LAB_0065c8f3;
            if (isdigit(static_cast<int>(
                    static_cast<unsigned char>(param_2[1]))) == 0) goto LAB_0065c8f3;
            pcVar5 = param_2 + 2;
            while (isdigit(static_cast<int>(
                       static_cast<unsigned char>(*pcVar5))) != 0) {
                pcVar5 = pcVar5 + 1;
            }
            if (*pcVar5 != '\0') goto LAB_0065c8f3;
            uVar3 = static_cast<uint32_t>(atoi(param_2 + 1));
            if (uVar3 < 0x2000) {
                st16(static_cast<uint32_t>(iVar1), 10,
                     static_cast<uint16_t>(
                         ld16(static_cast<uint32_t>(iVar1), 10)
                         | static_cast<uint16_t>(uVar3 << 2) | 2));
                goto LAB_0065c8f3;
            }
            FUN_0060fcd3(ld32(ld32(addr(self), 0), 4) + 0x18, nullptr, 0xb56,
                         "Constant variable \'%s\' bound to register greater than 8191 (%d requested)",
                         local_1c, uVar3);
            iVar2 = -0x7fffbffb;
            return iVar2;
        }

LAB_0065c8f3:
        if ((ld8(static_cast<uint32_t>(local_8), 0x1c) & 2) != 0) {
            st8(static_cast<uint32_t>(iVar1), 10,
                static_cast<uint8_t>(ld8(static_cast<uint32_t>(iVar1), 10) | 1));
        }
        iVar2 = static_cast<int32_t>(ld32(static_cast<uint32_t>(local_8), 0x28));
        if (iVar2 == 0) {
            if (ld32(static_cast<uint32_t>(local_8), 0x24) != 0) {
                iVar2 = FUN_0065c580(
                    self, param_1,
                    reinterpret_cast<float*>(static_cast<uintptr_t>(local_c)),
                    static_cast<int32_t>(local_24),
                    ld32(static_cast<uint32_t>(local_8), 0x24),
                    static_cast<uint32_t>(iVar1 + 0x10));
                if (iVar2 < 0) return iVar2;
            } else if ((ld8(static_cast<uint32_t>(iVar1), 10) & 1) != 0) {
                iVar2 = FUN_0065c643(self, param_1, local_c,
                                     static_cast<uint32_t>(iVar1 + 0x10));
                if (iVar2 < 0) return iVar2;
            }
        } else {
            iVar2 = FUN_0065c580(
                self, param_1,
                reinterpret_cast<float*>(static_cast<uintptr_t>(local_c)),
                static_cast<int32_t>(local_24),
                static_cast<uint32_t>(iVar2),
                static_cast<uint32_t>(iVar1 + 0x10));
            if (iVar2 < 0) return iVar2;
        }

        if ((ld32(ld32(static_cast<uint32_t>(local_8), 0x20), 4) != 9)
            || (ld32(ld32(static_cast<uint32_t>(local_8), 0x20), 0x14) != 0x14)) {
            iVar2 = FUN_0069ee3f(param_1,
                                 ld32(static_cast<uint32_t>(local_8), 0x20),
                                 1, 0,
                                 reinterpret_cast<void*>(
                                     static_cast<uintptr_t>(iVar1 + 0x0c)));
            if (iVar2 < 0) return iVar2;
            goto LAB_0065c991;
        }
        FUN_0060fcd3(ld32(ld32(addr(self), 0), 4) + 0x18, nullptr, 0xb59,
                     "Sampler variable \'%s\' does not specify the sampler type.  Explicit sampler types required for asm fragments.",
                     local_1c);
        return -0x7fffbffb;
    }

    {
        int16_t local_40[8];
        local_40[0] = 1;
        local_40[1] = 3;
        local_40[2] = 1;
        local_40[3] = 4;
        local_40[4] = 1;
        local_40[5] = 0;
        local_40[6] = 0;
        local_40[7] = 0;
        iVar2 = FUN_0065c17a(self, reinterpret_cast<char*>(local_40),
                             reinterpret_cast<char*>(static_cast<intptr_t>(0x10)),
                             6,
                             reinterpret_cast<uint32_t*>(
                                 static_cast<uintptr_t>(iVar1 + 0x0c)));
        if (iVar2 < 0) return iVar2;
        local_c = 1;
    }

LAB_0065c991:
    iVar2 = FUN_0065c17a(self, reinterpret_cast<char*>(param_3),
                         reinterpret_cast<char*>(static_cast<intptr_t>(-1)),
                         7,
                         reinterpret_cast<uint32_t*>(
                             static_cast<uintptr_t>(iVar1)));
    if (iVar2 > -1) {
        if (*param_3 == 0x5f62) {
            st16(static_cast<uint32_t>(iVar1), 4, 0);
        } else {
            st16(static_cast<uint32_t>(iVar1), 4,
                 static_cast<uint16_t>((*param_3 != 0x5f69) + 1));
        }
        st16(static_cast<uint32_t>(iVar1), 6, param_4);
        st16(static_cast<uint32_t>(iVar1), 8, static_cast<uint16_t>(local_c));
    }
    return iVar2;
}

// 0x65c9e5 — observed shape
// Default constructor for the kind-0x12 cluster: base init, vtable stamp, and
// zero the words at +0x30..+0x58 plus the 8-word block at +0x04.
void FUN_0065c9e5(void* self)
{
    FUN_0065ab96(0x12);
    uint32_t w = addr(self);
    st32(w, 0x30, 0);
    st32(w, 0x34, 0);
    st32(w, 0x38, 0);
    st32(w, 0x3c, 0);
    st32(w, 0x40, 0);
    st32(w, 0x54, 0);
    st32(w, 0x58, 0);
    st32(w, 0x00, static_cast<uint32_t>(
                      reinterpret_cast<uintptr_t>(&PTR_FUN_006ee20c)));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(w + 4));
    for (int iVar1 = 8; iVar1 != 0; iVar1 = iVar1 - 1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    st32(w, 0x44, 0);
    st32(w, 0x48, 0);
    st32(w, 0x4c, 0);
    st32(w, 0x50, 0);
    return;
}

// 0x65ca23 — observed shape
// Kind-0x12 constructor variant: base init, vtable stamp, 8-dword payload copy
// into +0x04, three words at +0x30/+0x34/+0x38, remaining fields zeroed.
void FUN_0065ca23(void* self, const uint32_t* param_1, uint32_t param_2,
                  uint32_t param_3, uint32_t param_4)
{
    FUN_0065ab96(0x12);
    uint32_t w = addr(self);
    st32(w, 0x00, static_cast<uint32_t>(
                      reinterpret_cast<uintptr_t>(&PTR_FUN_006ee20c)));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(w + 4));
    for (int iVar1 = 8; iVar1 != 0; iVar1 = iVar1 - 1) {
        *puVar2 = *param_1;
        param_1 = param_1 + 1;
        puVar2 = puVar2 + 1;
    }
    st32(w, 0x30, param_2);
    st32(w, 0x34, param_3);
    st32(w, 0x38, param_4);
    st32(w, 0x3c, 0);
    st32(w, 0x40, 0);
    st32(w, 0x54, 0);
    st32(w, 0x58, 0);
    st32(w, 0x44, 0);
    st32(w, 0x48, 0);
    st32(w, 0x4c, 0);
    st32(w, 0x50, 0);
    return;
}
