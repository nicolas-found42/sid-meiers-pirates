// Reconstruction batch mass_0115 — Sid Meier's Pirates! (2004) PE32 i386
// Source reconstruction from Ghidra 12.2 pseudocode corpus.
// Receiver registers (in_ECX/in_EAX/in_ESI/in_EDI) are exposed as explicit void* self / first parameter.

#include <cstdint>
#include <cstdarg>
#include <cstddef>
#include <windows.h>

// ---------- shared externs (referenced helpers/globals observed per listing) ----------
extern void operator_delete(void* ptr);
extern void* ExceptionList;
extern void LAB_006ba0a0();
extern void LAB_006ba090();
extern void* FUN_00533c78(uint32_t size);
extern void exception_ctor(void* self);
extern int _CxxThrowException(void* exceptionObject, void* throwInfo);
extern int _vsnprintf(char* buffer, size_t count, const char* format, va_list args);
extern void* PTR_FUN_0070ab54;
extern void* PTR_LAB_00713238;
extern void* PTR_LAB_00713280;
extern void* PTR_LAB_00713268;
extern int DAT_00714938;
extern int* DAT_008ed540;              // list sentinel (head sentinel object)
extern int DAT_008ed544;               // list element count
extern uint32_t DAT_008ed510;          // last reported stream/sample millisecond position
extern int* DAT_008ecd7c;              // global engine object; [0] = vtable pointer
extern void* DAT_008ecd78;             // global dispatch object base
extern uint32_t DAT_008ed4bc;          // table base (8-byte float records)
extern int DAT_008ed4c0;               // table record count
extern void FUN_0052bea0();
extern void FUN_00527cc0();
extern void FUN_00528fe0(void* self);
extern void FUN_005310c0();
extern uint32_t FUN_0052ff60(const char* format, ...);
extern long double FUN_0052c130(long double* extra_out);
extern int _AIL_sample_ms_position_12(uint32_t sample, int32_t ms, void* out);
extern int _AIL_stream_ms_position_12(uint32_t stream, int32_t ms, void* out);

// 28-byte stack object observed for basic_string<char, char_traits<char>, allocator<char>>
struct StdString {
    uint32_t rep[7];
};
extern void std_string_ctor(StdString* self, const char* text);
extern void std_string_ctor_copy(StdString* self, const StdString* other);
extern void std_string_dtor(StdString* self);

// forward declarations for definitions later in this batch
uint32_t* FUN_00530160(uint32_t param_1, uint32_t param_2, StdString* param_3);
void FUN_005301f0(uint32_t in_ECX, int in_EDX);
uint32_t FUN_00530b90(void* self);

// 0x52ffc0 — observed shape: variadic log/format helper; formats into 512-byte buffer via _vsnprintf (empty when format is null), builds a std::string copy, inserts a new list node via FUN_00530160/FUN_005301f0 into the DAT_008ed540 list, then unlinks/destroys the oldest node while DAT_008ed544 > 1000
void FUN_0052ffc0(char* param_1, char param_2)
{
    intptr_t iVar2;
    int* piVar1;
    StdString local_21c;
    char local_200[512];

    if (param_1 == (char*)0x0) {
        local_200[0] = '\0';
    } else {
        _vsnprintf(local_200, 0x200, param_1, (va_list)&param_2);
    }
    std_string_ctor(&local_21c, local_200);
    piVar1 = DAT_008ed540;
    iVar2 = (intptr_t)FUN_00530160(DAT_008ed540, DAT_008ed540[1], &local_21c);
    FUN_005301f0(1, (int)(intptr_t)DAT_008ed540);
    piVar1[1] = (int)iVar2;
    **(int**)(iVar2 + 4) = (int)iVar2;
    std_string_dtor(&local_21c);
    if ((1000 < DAT_008ed544) && (piVar1 = (int*)*DAT_008ed540, piVar1 != DAT_008ed540)) {
        *(int*)piVar1[1] = *piVar1;
        *(int*)(*piVar1 + 4) = piVar1[1];
        std_string_dtor((StdString*)(piVar1 + 2));
        operator_delete(piVar1);
        DAT_008ed544 = DAT_008ed544 - 1;
    }
    return;
}

// 0x530090 — observed shape: self in EDI; re-links the node at self+4 into a single-element ring (prev/next self-pointing), clears self+8 count, then walks the former ring destroying each node's std::string at node+8 and operator_delete-ing the node
void FUN_00530090(void* self)
{
    uint8_t* base = (uint8_t*)self;
    int* piVar1;
    int* piVar2;

    piVar1 = *(int**)(base + 4);
    piVar2 = (int*)*piVar1;
    *piVar1 = (int)(intptr_t)piVar1;
    *(int*)(*(int*)(base + 4) + 4) = *(int*)(base + 4);
    *(uint32_t*)(base + 8) = 0;
    if (piVar2 != *(int**)(base + 4)) {
        do {
            piVar1 = (int*)*piVar2;
            std_string_dtor((StdString*)(piVar2 + 2));
            operator_delete(piVar2);
            piVar2 = piVar1;
        } while (piVar1 != (int*)*(int*)(base + 4));
    }
    return;
}

// 0x5300d0 — observed shape: SEH-guarded 0x24-byte node allocation; stores own address at node+0 and node+4, restoring ExceptionList
void FUN_005300d0(void)
{
    intptr_t iVar1;
    void* local_10;
    void* puStack_c;
    uint32_t local_8;

    local_8 = 0xffffffff;
    puStack_c = (void*)&LAB_006ba0a0;
    local_10 = ExceptionList;
    ExceptionList = &local_10;
    iVar1 = (intptr_t)FUN_00533c78(0x24);
    if (iVar1 != 0) {
        *(int*)iVar1 = (int)iVar1;
    }
    if ((int*)(iVar1 + 4) != (int*)0x0) {
        *(int*)(iVar1 + 4) = (int)iVar1;
    }
    ExceptionList = local_10;
    return;
}

// 0x530160 — observed shape: SEH-guarded 0x24-byte list-node allocation; writes param_1/param_2 at node+0/+4 and copy-constructs the std::string at node+8 from param_3; returns the node
uint32_t* FUN_00530160(uint32_t param_1, uint32_t param_2, StdString* param_3)
{
    uint32_t* puVar1;
    void* local_10;
    void* puStack_c;
    uint32_t local_8;

    local_8 = 0xffffffff;
    puStack_c = (void*)&LAB_006ba090;
    local_10 = ExceptionList;
    ExceptionList = &local_10;
    puVar1 = (uint32_t*)FUN_00533c78(0x24);
    local_8 = 0;
    if (puVar1 != (uint32_t*)0x0) {
        *puVar1 = param_1;
        puVar1[1] = param_2;
        std_string_ctor_copy((StdString*)((uint8_t*)puVar1 + 8), param_3);
    }
    ExceptionList = local_10;
    return puVar1;
}

// 0x5301f0 — observed shape: count in ECX, list in EDX; throws std::length_error "list<T> too long" via _CxxThrowException when 0x9249249 - list->size < count, otherwise adds count to list->size at +8
void FUN_005301f0(uint32_t in_ECX, int in_EDX)
{
    StdString local_44;
    void* local_28[3];
    StdString local_1c;

    if (0x9249249U - *(int*)(in_EDX + 8) < in_ECX) {
        std_string_ctor(&local_44, "list<T> too long");
        exception_ctor(local_28);
        local_28[0] = &PTR_FUN_0070ab54;
        std_string_ctor_copy(&local_1c, &local_44);
        local_28[0] = &PTR_FUN_0070ab54;
        _CxxThrowException(local_28, (void*)&DAT_00714938);
    }
    *(uint32_t*)(in_EDX + 8) = *(int*)(in_EDX + 8) + in_ECX;
    return;
}

// 0x530260 — observed shape: self in ESI; installs vtable PTR_LAB_00713238, zeroes +4..+0x28 with 1.0f at +0x18/+0x20, then (twice) releases the referenced object at +0x28 (refcount at +4, vtable[0](1) on zero) and clears the slot, re-initializing the field block between the two releases
void FUN_00530260(void* self)
{
    uint32_t* p = (uint32_t*)self;
    int* piVar1;
    void** puVar2;

    *p = (uint32_t)(uintptr_t)&PTR_LAB_00713238;
    p[10] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0x3f800000;
    p[7] = 0;
    p[8] = 0x3f800000;
    p[9] = 0;
    puVar2 = (void**)p[10];
    if (puVar2 != (void**)0x0) {
        piVar1 = (int*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))*puVar2)(1);
        }
        p[10] = 0;
    }
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0x3f800000;
    p[7] = 0;
    p[8] = 0x3f800000;
    p[9] = 0;
    puVar2 = (void**)p[10];
    if (puVar2 != (void**)0x0) {
        piVar1 = (int*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))*puVar2)(1);
        }
        p[10] = 0;
    }
    return;
}

// 0x530300 — observed shape: receiver in ECX; installs vtable PTR_LAB_00713238, calls global vtable slot DAT_008ecd7c[0]+0x28, initializes +4..+0x24 (1.0f at +0x18/+0x20), then releases the +0x28 referenced object twice (second release leaves the slot value intact)
void FUN_00530300(void* self)
{
    uint32_t* p = (uint32_t*)self;
    int vtable = *DAT_008ecd7c;
    int* piVar1;
    void** puVar2;

    *p = (uint32_t)(uintptr_t)&PTR_LAB_00713238;
    (*(void(**)(void*))*(void**)(vtable + 0x28))(DAT_008ecd7c);
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0x3f800000;
    p[7] = 0;
    p[8] = 0x3f800000;
    p[9] = 0;
    puVar2 = (void**)p[10];
    if (puVar2 != (void**)0x0) {
        piVar1 = (int*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))*puVar2)(1);
        }
        p[10] = 0;
    }
    puVar2 = (void**)p[10];
    if (puVar2 != (void**)0x0) {
        piVar1 = (int*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))*puVar2)(1);
        }
    }
    return;
}

// 0x5303c0 — observed shape: receiver in ECX (byte arithmetic); calls global vtable slot DAT_008ecd7c[0]+0x28, zeroes +4..+0x24 (1.0f at +0x18/+0x20), then releases the referenced object at +0x28 and clears it
void FUN_005303c0(void* self)
{
    uint8_t* b = (uint8_t*)self;
    int vtable = *DAT_008ecd7c;
    int* piVar1;
    void** puVar2;

    (*(void(**)(void*))*(void**)(vtable + 0x28))(DAT_008ecd7c);
    *(uint32_t*)(b + 4) = 0;
    *(uint32_t*)(b + 8) = 0;
    *(uint32_t*)(b + 0xc) = 0;
    *(uint32_t*)(b + 0x10) = 0;
    *(uint32_t*)(b + 0x14) = 0;
    *(uint32_t*)(b + 0x18) = 0x3f800000;
    *(uint32_t*)(b + 0x1c) = 0;
    *(uint32_t*)(b + 0x20) = 0x3f800000;
    *(uint32_t*)(b + 0x24) = 0;
    puVar2 = *(void***)(b + 0x28);
    if (puVar2 != (void**)0x0) {
        piVar1 = (int*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))*puVar2)(1);
        }
        *(uint32_t*)(b + 0x28) = 0;
    }
    return;
}

// 0x530410 — observed shape: receiver in ECX; assign-with-refcount of the object pointer at self+0x28 from param_1 (release old when different, bump new at +4), then release param_1 unconditionally
void FUN_00530410(void* self, uint32_t* param_1)
{
    uint8_t* b = (uint8_t*)self;
    int* piVar1;
    uint32_t* puVar2;

    puVar2 = *(uint32_t**)(b + 0x28);
    if (puVar2 != param_1) {
        if (puVar2 != (uint32_t*)0x0) {
            piVar1 = (int*)puVar2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void(**)(int))*(void**)puVar2)(1);
            }
        }
        *(uint32_t**)(b + 0x28) = param_1;
        if (param_1 == (uint32_t*)0x0) {
            return;
        }
        param_1[1] = (uint32_t)(param_1[1] + 1);
    }
    if (param_1 != (uint32_t*)0x0) {
        piVar1 = (int*)param_1 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))*(void**)param_1)(1);
        }
    }
    return;
}

// 0x530470 — observed shape: receiver in ECX, float in ESI; when self+0x28 object exists, extracts the +0x38/+0x44/+0x50 column values and +0x3c/+0x48/+0x54 row values, invokes vtable+0x1c on the object's +0x5c sub-object, then negates the ESI/row components and forwards the vector to vtable+0x24
void FUN_00530470(void* self, float unaff_ESI)
{
    int* p = (int*)self;
    int iVar1;
    float fVar2;
    float fVar3;
    float local_1c;
    float fStack_18;
    float fStack_14;
    uint32_t auStack_10[1];
    uint32_t local_c;
    uint32_t local_8;
    uint32_t local_4;

    iVar1 = p[10];
    if (iVar1 != 0) {
        local_c = *(uint32_t*)(iVar1 + 0x38);
        local_8 = *(uint32_t*)(iVar1 + 0x44);
        local_4 = *(uint32_t*)(iVar1 + 0x50);
        fVar2 = *(float*)(iVar1 + 0x3c);
        fVar3 = *(float*)(iVar1 + 0x48);
        local_1c = *(float*)(iVar1 + 0x54);
        (*(void(**)(void*, void*))*(void**)(*p + 0x1c))(self, (void*)(iVar1 + 0x5c));
        local_1c = -unaff_ESI;
        fStack_18 = -fVar2;
        fStack_14 = -fVar3;
        (*(void(**)(void*, void*, void*))*(void**)(*p + 0x24))(
            self, &auStack_10[0], &local_1c);
    }
    return;
}

// 0x530670 — observed shape: state machine keyed on self[0]; states 0..2 return -1; computes (param_1 - self[2] - self[6]); below zero: for state 3 and non-null self[7], polls vtable+0x44 and on false calls +0x20/+0x24, returns self[4]; else polls +0x44 and on false calls +0x1c, interpolates between self[4] and self[5] by (delta/self[1]), stores truncated result at self[3], and at end-of-range advances state ((self[0]==4)+1) returning self[5]
long double FUN_00530670(int* self, float param_1)
{
    int iVar2;
    int* piVar3;
    float fVar1;
    float fVar4;
    char cVar5;
    long double fVar6;

    iVar2 = *self;
    if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
        return (long double)-1.0;
    }
    piVar3 = (int*)self[7];
    fVar4 = (param_1 - (float)self[2]) - (float)self[6];
    if (fVar4 < 0.0f) {
        if ((piVar3 != (int*)0x0) && (iVar2 == 3)) {
            cVar5 = (*(char(**)(void*))*(void**)(*piVar3 + 0x44))(piVar3);
            if (cVar5 == '\0') {
                (*(void(**)(void*))*(void**)(*(int*)self[7] + 0x20))((void*)self[7]);
                (*(void(**)(void*))*(void**)(*(int*)self[7] + 0x24))((void*)self[7]);
            }
        }
        return (long double)(float)self[4];
    }
    if ((piVar3 != (int*)0x0) && (iVar2 == 3)) {
        cVar5 = (*(char(**)(void*))*(void**)(*piVar3 + 0x44))(piVar3);
        if (cVar5 == '\0') {
            (*(void(**)(void*))*(void**)(*(int*)self[7] + 0x1c))((void*)self[7]);
        }
    }
    fVar1 = (float)self[1];
    // Provider forms this as the NaN-aware complement of (delta < self[1]) == (delta == self[1]).
    if ((fVar1 != fVar1) || (fVar4 != fVar4) || (fVar1 > fVar4)) {
        fVar6 = ((long double)fVar4 / (long double)(float)self[1]) *
                ((long double)(float)self[5] - (long double)(float)self[4]) +
                (long double)(float)self[4];
        self[3] = (int)(float)fVar6;
        return fVar6;
    }
    *self = (*self == 4) + 1;
    return (long double)self[5];
}

// 0x530730 — observed shape: receiver in ECX, delete flag in AL; installs vtable PTR_LAB_00713280, calls FUN_00530b90, resets +0xc/+0x10 to -1, byte +0x78 to 0, +8 to 0, FUN_0052bea0, bytes +0x7b/+0x7a to 0, +0x7c to 0, byte +0x79 to 0, installs vtable PTR_LAB_00713268 and conditionally operator_delete self
void FUN_00530730(void* self, uint8_t param_1)
{
    uint32_t* p = (uint32_t*)self;
    uint8_t* b = (uint8_t*)self;

    *p = (uint32_t)(uintptr_t)&PTR_LAB_00713280;
    FUN_00530b90();
    p[3] = 0xffffffff;
    p[4] = 0xffffffff;
    *(uint8_t*)(b + 0x78) = 0;
    p[2] = 0;
    FUN_0052bea0();
    *(uint8_t*)(b + 0x7b) = 0;
    *(uint8_t*)(b + 0x7a) = 0;
    p[0x1f] = 0;
    *(uint8_t*)(b + 0x79) = 0;
    *p = (uint32_t)(uintptr_t)&PTR_LAB_00713268;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x530790 — observed shape: self in ESI; polls DAT_008ecd78+0x18, then via vtable slot self+8[0]+0x10 fetches the +0x6c handle, resolves it through vtable+0x14/+0x10 and global vtable +0x10(0, handle), stores at self+0xc and reports success when != -1
bool FUN_00530790(void* self, uint32_t unaff_retaddr)
{
    uint8_t* b = (uint8_t*)self;
    int* piVar1;
    char cVar2;
    int iVar3;
    int vtable;
    uint32_t uVar4;

    cVar2 = (*(char(**)(void))((uint8_t*)DAT_008ecd78 + 0x18))();
    if (cVar2 != '\0') {
        iVar3 = (*(int(**)(void*, uint32_t))((*(int**)(b + 8))[0] + 0x10))(*(void**)(b + 8), *(uint32_t*)(b + 0x6c));
        if (iVar3 != 0) {
            piVar1 = *(int**)(b + 8);
            vtable = *DAT_008ecd7c;
            uVar4 = (*(uint32_t(**)(void*, uint32_t, uint32_t))(*piVar1 + 0x14))(
                piVar1, *(uint32_t*)(b + 0x6c), unaff_retaddr);
            uVar4 = (*(uint32_t(**)(void*, uint32_t, uint32_t))(*piVar1 + 0x10))(
                piVar1, *(uint32_t*)(b + 0x6c), uVar4);
            iVar3 = (*(int(**)(void*, int, uint32_t))*(void**)(vtable + 0x10))(DAT_008ecd7c, 0, uVar4);
            *(int*)(b + 0xc) = iVar3;
            return iVar3 != -1;
        }
    }
    return false;
}

// 0x530810 — observed shape: receiver in ECX; when vtable+0x44 reports not-playing and byte +0x74 is set, queries the AIL sample or stream millisecond position (based on byte +0x18) into +0x70, stores it in DAT_008ed510, then calls vtable+0xd4 and FUN_005310c0
void FUN_00530810(void* self)
{
    int* p = (int*)self;
    uint8_t* b = (uint8_t*)self;
    int iVar1;
    char cVar2;
    uint32_t uVar3;

    cVar2 = (*(char(**)(void*))*(void**)(*p + 0x44))(self);
    if (cVar2 == '\0') {
        if ((char)p[0x1d] != '\0') {
            if ((char)p[6] == '\0') {
                iVar1 = p[3];
                if ((iVar1 < 0) || (*(int*)((uint8_t*)DAT_008ecd7c + 8) < iVar1)) {
                    uVar3 = 0;
                } else {
                    uVar3 = *(uint32_t*)(*(int*)((uint8_t*)DAT_008ecd7c + 0x58) + iVar1 * 8);
                }
                _AIL_sample_ms_position_12(uVar3, 0, (void*)(p + 0x1c));
            } else {
                _AIL_stream_ms_position_12(
                    *(uint32_t*)(*(int*)((uint8_t*)DAT_008ecd7c + 0x60) + p[4] * 8), 0,
                    (void*)(p + 0x1c));
            }
            DAT_008ed510 = (uint32_t)p[0x1c];
        }
        (*(void(**)(void*))*(void**)(*p + 0xd4))(self);
        FUN_005310c0();
    }
    return;
}

// 0x5308d0 — observed shape: receiver in ECX; calls vtable+0xc, resets +0xc/+0x10 to -1, byte +0x78 to 0, +8 to 0, FUN_0052bea0, bytes +0x7b/+0x7a to 0, +0x7c to 0, byte +0x79 to 0
void FUN_005308d0(void* self)
{
    int* p = (int*)self;
    uint8_t* b = (uint8_t*)self;

    (*(void(**)(void*))*(void**)(*p + 0xc))(self);
    p[3] = -1;
    p[4] = -1;
    *(uint8_t*)(b + 0x78) = 0;
    p[2] = 0;
    FUN_0052bea0();
    *(uint8_t*)(b + 0x7b) = 0;
    *(uint8_t*)(b + 0x7a) = 0;
    p[0x1f] = 0;
    *(uint8_t*)(b + 0x79) = 0;
    return;
}

// 0x530b90 — observed shape: receiver in ECX; returns 0 unless DAT_008ecd78+0x18 poll and byte self+0x79 are both set; selects (channel 0, id +0xc) or (channel 2, id +0x10) by byte self+0x18, calls global vtable +0x14, FUN_00527cc0, resets +0xc/+0x10/+8/+0x14, FUN_00528fe0, clears byte +0x79, returns 1
uint32_t FUN_00530b90(void* self)
{
    uint8_t* b = (uint8_t*)self;
    int vtable;
    char extraout_AL;
    uint32_t uVar1;
    uint32_t uVar2;

    extraout_AL = (*(char(**)(void))((uint8_t*)DAT_008ecd78 + 0x18))();
    if ((extraout_AL == '\0') || (*(char*)(b + 0x79) == '\0')) {
        return 0;
    }
    if (*(char*)(b + 0x18) == '\0') {
        uVar2 = *(uint32_t*)(b + 0xc);
        uVar1 = 0;
    } else {
        uVar2 = *(uint32_t*)(b + 0x10);
        uVar1 = 2;
    }
    vtable = *DAT_008ecd7c;
    (*(void(**)(void*, uint32_t, uint32_t))*(void**)(vtable + 0x14))(DAT_008ecd7c, uVar1, uVar2);
    FUN_00527cc0();
    *(uint32_t*)(b + 0xc) = 0xffffffff;
    *(uint32_t*)(b + 0x10) = 0xffffffff;
    *(uint32_t*)(b + 8) = 0;
    *(uint32_t*)(b + 0x14) = 0xffffffff;
    FUN_00528fe0(self);
    *(uint8_t*)(b + 0x79) = 0;
    return 1;
}

// 0x530cf0 — observed shape: receiver in ECX; returns 1 when vtable+0x40 and vtable+0x44 both report false; otherwise reports "Cannot play sound..." via FUN_0052ff60 when +8 is null, else calls global vtable +0x3c with (0,+0xc) or (2,+0x10) per byte +0x18 and returns 1
uint32_t FUN_00530cf0(void* self)
{
    int* p = (int*)self;
    int vtable;
    char cVar1;
    uint32_t uVar2;

    cVar1 = (*(char(**)(void*))*(void**)(*p + 0x40))(self);
    if ((cVar1 == '\0') &&
        (cVar1 = (*(char(**)(void*))*(void**)(*p + 0x44))(self), cVar1 == '\0')) {
        return 1;
    }
    if (p[2] == 0) {
        uVar2 = FUN_0052ff60("Cannot play sound, buffer and/or handle is NULL.");
        return uVar2;
    }
    vtable = *DAT_008ecd7c;
    if ((char)p[6] == '\0') {
        (*(void(**)(void*, int, int))*(void**)(vtable + 0x3c))(DAT_008ecd7c, 0, p[3]);
        return 1;
    }
    (*(void(**)(void*, int, int))*(void**)(vtable + 0x3c))(DAT_008ecd7c, 2, p[4]);
    return 1;
}

// 0x530e60 — observed shape: receiver in ECX; clears byte +0x7a, reads the DAT_008ecd78+0x14 float value, truncates it to int at +0x64, and when vtable+0x58 reports false with no live +0x5c object calls vtable+0x5c(1)
void FUN_00530e60(void* self)
{
    int* p = (int*)self;
    char cVar1;
    float fVar2;

    *(uint8_t*)((uint8_t*)self + 0x7a) = 0;
    fVar2 = (*(float(**)(void))((uint8_t*)DAT_008ecd78 + 0x14))();
    p[0x19] = (int)fVar2;
    cVar1 = (*(char(**)(void*))*(void**)(*p + 0x58))(self);
    if ((cVar1 == '\0') &&
        ((p[0x17] == 0) || (*(char*)((intptr_t)p[0x17] + 0x2c) == '\0'))) {
        (*(void(**)(void*, int))*(void**)(*p + 0x5c))(self, 1);
    }
    return;
}

// 0x530ea0 — observed shape: receiver in ECX, status byte in EAX; returns CONCAT31(status>>8,1) when byte +0x7a is set, otherwise status>>8<<8, after optionally probing vtable slot self+8[0]+0x10 for the +0x6c handle when byte +0x18 is clear
int FUN_00530ea0(void* self, uint32_t in_EAX)
{
    uint8_t* b = (uint8_t*)self;
    uint32_t uVar2;
    int iVar1;

    uVar2 = (in_EAX >> 8) & 0xffffffU;
    if (*(char*)(b + 0x18) == '\0') {
        uVar2 = 0;
        if (*(int**)(b + 8) != (int*)0x0) {
            iVar1 = (*(int(**)(void*, uint32_t))((*(int**)(b + 8))[0] + 0x10))(
                *(void**)(b + 8), *(uint32_t*)(b + 0x6c));
            uVar2 = 0;
            if (iVar1 != 0) {
                uVar2 = ((uint32_t)iVar1 >> 8) & 0xffffffU;
                if (*(char*)(b + 0x7a) != '\0') {
                    goto LAB_00530ed5;
                }
            }
        }
        if (*(char*)(b + 0x18) == '\0') {
            goto LAB_00530ed9;
        }
    }
    if (*(char*)(b + 0x7a) != '\0') {
    LAB_00530ed5:
        return (int)((uVar2 << 8) | 1u);
    }
LAB_00530ed9:
    return (int)(uVar2 << 8);
}

// 0x531070 — observed shape: receiver in EAX, factor in ST0; resolves the table index from the +0x5c object's +8 field against count DAT_008ed4c0; out-of-range/absent entries yield 1.0, otherwise the record's first float, or (when the record's second float is nonzero) FUN_0052c130's result times the provider's second x87 return times the incoming ST0; product is finally scaled by self+0x34 and self+0x24
float FUN_00531070(void* self, long double in_ST0)
{
    uint8_t* b = (uint8_t*)self;
    float* pfVar1;
    int iVar2;
    long double fVar3;
    long double extraout_ST1;

    if ((((*(int*)(b + 0x5c) == 0) ||
          (iVar2 = *(int*)(*(int*)(b + 0x5c) + 8), iVar2 < 0)) ||
         (DAT_008ed4c0 <= iVar2)) ||
        (pfVar1 = (float*)((uintptr_t)DAT_008ed4bc + (uintptr_t)iVar2 * 8), pfVar1 == (float*)0x0)) {
        fVar3 = (long double)1.0;
    } else {
        fVar3 = (long double)*pfVar1;
        if (pfVar1[1] != 0.0f) {
            // NEEDS_MANUAL: the provider reports extraout_ST1 as the unbound second x87
            // result of FUN_0052c130; captured here through an explicit out-parameter
            // instead of fabricating a value.
            fVar3 = FUN_0052c130(&extraout_ST1);
            return (float)(fVar3 * extraout_ST1 * in_ST0);
        }
    }
    return (float)(fVar3 * (long double)*(float*)(b + 0x34) *
                   (long double)*(float*)(b + 0x24));
}
