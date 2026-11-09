#include <cstdint>
#include <cstddef>
#include <windows.h>

// extern helpers/globals observed in the corpus listings
extern uint32_t thunk_FUN_00540b70(uint32_t param_1);
extern uint32_t thunk_FUN_00540f80(int param_1);
extern char FUN_00542810(int param_1);
extern char FUN_00542780(int param_1);
extern char FUN_00542890(int param_1);
extern int FUN_00533c78(uint32_t size);
extern void* FUN_005428c0();
extern void operator_delete(void* ptr);
extern uint32_t* DAT_007275f0;
extern void* PTR_FUN_006c1430;

// 0x543250 — observed shape
uint32_t FUN_00543250(void* self, uint32_t param_1)
{
    char* ecx = (char*)self;
    uint32_t uVar2 = thunk_FUN_00540b70(param_1);
    if ((char)uVar2 == '\0') {
        return uVar2;
    }
    uint32_t uVar4 = 0;
    int count34 = *(int*)(ecx + 0x34);
    if (count34 != 0) {
        do {
            int iVar3 = *(int*)(*(int*)(ecx + 0x2c) + uVar4 * 4);
            if ((iVar3 != 0) && (*(int**)(iVar3 + 4) != nullptr)) {
                int* piVar1 = *(int**)(iVar3 + 4);
                typedef void (__cdecl *InjFn)(uint32_t);
                InjFn fn = (InjFn)(*(void**)(*piVar1 + 0x14));
                fn(param_1);
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint32_t*)(ecx + 0x34));
    }
    int iVar3 = *(int*)(ecx + 0x44);
    if ((iVar3 != 0) && (uVar4 = 0, *(int*)(iVar3 + 0xc) != 0)) {
        do {
            iVar3 = *(int*)(*(int*)(iVar3 + 4) + uVar4 * 4);
            if ((iVar3 != 0) && (*(int**)(iVar3 + 4) != nullptr)) {
                int* piVar1 = *(int**)(iVar3 + 4);
                typedef void (__cdecl *InjFn)(uint32_t);
                InjFn fn = (InjFn)(*(void**)(*piVar1 + 0x14));
                fn(param_1);
            }
            iVar3 = *(int*)(ecx + 0x44);
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint32_t*)(iVar3 + 0xc));
    }
    return 1;
}

// 0x5433f0 — observed shape
uint32_t FUN_005433f0(void* self, int param_1)
{
    char* ecx = (char*)self;
    char* p1 = (char*)(intptr_t)param_1;
    char cVar3 = (char)thunk_FUN_00540f80(param_1);
    if ((cVar3 == '\0') || (*(int*)(ecx + 0x20) != *(int*)(p1 + 0x20))) {
        return 0;
    }
    uint32_t uVar1 = *(uint32_t*)(ecx + 0x34);
    if (uVar1 != *(uint32_t*)(p1 + 0x34)) {
        return 0;
    }
    uint32_t uVar4 = 0;
    if (uVar1 != 0) {
        do {
            int iVar2 = *(int*)(*(int*)(p1 + 0x2c) + uVar4 * 4);
            if (*(int*)(*(int*)(ecx + 0x2c) + uVar4 * 4) == 0) {
                if (iVar2 != 0) {
                    return 0;
                }
            }
            else {
                if (iVar2 == 0) {
                    return 0;
                }
                if (uVar4 == 5) {
                    cVar3 = FUN_00542810(iVar2);
                }
                else {
                    cVar3 = FUN_00542780(iVar2);
                }
                if (cVar3 == '\0') {
                    return 0;
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
    }
    if (*(int*)(ecx + 0x44) == 0) {
        if (*(int*)(p1 + 0x44) == 0) {
            return 1;
        }
    }
    else if ((*(int*)(p1 + 0x44) != 0) &&
             (uVar1 = *(uint32_t*)(*(int*)(ecx + 0x44) + 0xc),
              uVar1 == *(uint32_t*)(*(int*)(p1 + 0x44) + 0xc))) {
        uVar4 = 0;
        if (uVar1 == 0) {
            return 1;
        }
        do {
            int iVar2 = *(int*)(*(int*)(*(int*)(p1 + 0x44) + 4) + uVar4 * 4);
            if (*(int*)(*(int*)(*(int*)(ecx + 0x44) + 4) + uVar4 * 4) == 0) {
                if (iVar2 != 0) {
                    return 0;
                }
            }
            else {
                if (iVar2 == 0) {
                    return 0;
                }
                cVar3 = FUN_00542890(iVar2);
                if (cVar3 == '\0') {
                    return 0;
                }
            }
            uVar4 = uVar4 + 1;
            if (uVar1 <= uVar4) {
                return 1;
            }
        } while (true);
    }
    return 0;
}

// 0x5434e0 — observed shape
void FUN_005434e0(void)
{
    int iVar2 = FUN_00533c78(0x48);
    uint32_t* puVar3;
    if (iVar2 == 0) {
        puVar3 = nullptr;
    }
    else {
        puVar3 = (uint32_t*)FUN_005428c0();
    }
    uint32_t* puVar1 = DAT_007275f0;
    if (DAT_007275f0 != puVar3) {
        if ((DAT_007275f0 != nullptr) &&
            (iVar2 = (int)DAT_007275f0[1], DAT_007275f0[1] = (uint32_t)(iVar2 + -1), iVar2 + -1 == 0)) {
            typedef void (__cdecl *DelFn)(int);
            DelFn fn = (DelFn)(*(void**)*puVar1);
            fn(1);
        }
        DAT_007275f0 = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x543530 — observed shape
void FUN_00543530(void)
{
    uint32_t* puVar2 = DAT_007275f0;
    if (DAT_007275f0 != nullptr) {
        int iVar1 = (int)DAT_007275f0[1];
        DAT_007275f0[1] = (uint32_t)(iVar1 + -1);
        if (iVar1 + -1 == 0) {
            typedef void (__cdecl *DelFn)(int);
            DelFn fn = (DelFn)(*(void**)*puVar2);
            fn(1);
        }
        DAT_007275f0 = nullptr;
    }
}

// 0x543560 — observed shape
void FUN_00543560(void* self, uint8_t param_1)
{
    uint32_t* ecx = (uint32_t*)self;
    ecx[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c1430;
    operator_delete((void*)(uintptr_t)ecx[6]);
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)ecx[1];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (__cdecl *DelFn)(int);
            DelFn fn = (DelFn)(*(void**)*puVar2);
            fn(1);
        }
    }
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
}

// ---- second batch (addresses 0x5435a0 .. 0x544c00) ----

// extern helpers/globals observed in the second batch of listings
extern void FUN_00545cc0(void);
extern void FUN_00540410(uint32_t param_1);
extern uint32_t FUN_00557b10(uint32_t param_1);
extern void FUN_005606f0(uint32_t index, uint32_t* value);
extern void FUN_006b34a0(int param_1);
extern uint32_t FUN_00557cb0(const char* name, uint32_t param_1);
extern uint32_t FUN_00557cf0(const char* name, uint32_t param_1);
extern uint32_t FUN_00557d40(const char* name, uint32_t param_1);
extern int FUN_00542430(const char* name, uint32_t param_1);
extern int FUN_005424d0(const char* name, uint32_t param_1);
extern uint32_t FUN_00557bf0(const char* name, uint16_t param_1);
extern uint32_t FUN_0054a8f0(uint32_t* param_1, uint32_t param_2, uint32_t* param_3,
                             uint32_t* param_4, uint32_t param_5);
extern void FUN_0054a9a0(int* param_1);
extern void FUN_00542750(void);
extern void FUN_00540c50(void);
extern void FUN_00540c90(void);
extern void FUN_00551150(void);
extern void FUN_00549540(void);
extern void FUN_004db0a0(void);
extern void thunk_FUN_00540cf0(int param_1, uint32_t param_2);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern uint32_t DAT_007275e8;
extern uint32_t* DAT_007275fc;
extern uint32_t DAT_007179dc;
extern char DAT_006c1464;
extern char DAT_006c145c;
extern char UNK_006c14ec;
extern char UNK_006c14dc;
extern void* PTR_FUN_006c143c;
extern void* PTR_FUN_00710bf8;
extern void* PTR_FUN_0070d038;
extern void* PTR_FUN_006c15a8;
extern void* PTR_FUN_006c1630;

// Shared shape of the "grow then store one pointer slot" block that repeats in
// 0x5439c0 and 0x5443c0: object+0x4 = array, +0x8 = capacity, +0xc = count,
// +0x10 = live count, +0x14 = allocation base handed to FUN_006b34a0.
static void Mass133SetEntry(int* arrayObj, uint32_t index, intptr_t value)
{
    if ((index < (uint32_t)arrayObj[2]) ||
        (FUN_006b34a0(arrayObj[5] + (int)index), index < (uint32_t)arrayObj[2])) {
        if (index < (uint32_t)arrayObj[3]) {
            if (value == 0) {
                if (*(int*)(arrayObj[1] + index * 4) != 0) {
                    arrayObj[4] = arrayObj[4] + -1;
                }
            }
            else if (*(int*)(arrayObj[1] + index * 4) == 0) {
                arrayObj[4] = arrayObj[4] + 1;
            }
        }
        else {
            arrayObj[3] = (int)(index + 1);
            if (value != 0) {
                arrayObj[4] = arrayObj[4] + 1;
            }
        }
        *(int*)(arrayObj[1] + index * 4) = (int)value;
    }
}

// Shared slot-2 (+0x8) virtual call of the reader/writer object at stream+0x15c.
static void Mass133StreamRead(void* stream, void* dst, uint32_t size)
{
    int obj = *(int*)((char*)stream + 0x15c);
    uint32_t vtbl = *(uint32_t*)(intptr_t)obj;
    (*(void (__cdecl**)(void*, uint32_t))(vtbl + 8))(dst, size);
}

// 0x5435a0 — observed shape
void FUN_005435a0(void* self, int param_1)
{
    uint32_t* ecx = (uint32_t*)self;
    char* p = (char*)(intptr_t)param_1;
    int iVar2;

    ecx[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c1430;
    ecx[1] = 0;
    if (*(int*)(p + 4) != 0) {
        iVar2 = *(int*)(p + 4);
        ecx[1] = (uint32_t)iVar2;
        if (iVar2 != 0) {
            *(int*)(iVar2 + 4) = *(int*)(iVar2 + 4) + 1;
        }
    }
    ecx[2] = *(uint32_t*)(p + 8);
    ecx[3] = *(uint32_t*)(p + 0xc);
    ecx[4] = *(uint32_t*)(p + 0x10);
    *(uint16_t*)((char*)ecx + 0x14) = *(uint16_t*)(p + 0x14);
    *(uint16_t*)((char*)ecx + 0x16) = *(uint16_t*)(p + 0x16);
    if (*(int*)(p + 0x18) == 0) {
        ecx[6] = 0;
        return;
    }
    // 0x48-byte scratch allocation observed; its result is not retained by the listing
    iVar2 = FUN_00533c78(0x48);
    if (iVar2 == 0) {
        ecx[6] = 0;
        return;
    }
    iVar2 = *(int*)(p + 0x18);
    uint32_t local_18 = *(uint32_t*)(iVar2 + 0x14);
    uint32_t local_14 = *(uint32_t*)(iVar2 + 0x18);
    uint32_t local_10 = *(uint32_t*)(*(int*)(p + 0x18) + 0xc);
    uint32_t* puVar1 = *(uint32_t**)(p + 0x18);
    uint32_t local_c = *(uint32_t*)(*(int*)(p + 0x18) + 0x10);
    uint32_t local_8 = puVar1[0];
    uint32_t local_4 = puVar1[1];
    uint32_t uVar3 = FUN_0054a8f0(&local_8, puVar1[2], &local_10, &local_18,
                                  *(uint32_t*)(iVar2 + 0x44));
    ecx[6] = uVar3;
}

// 0x5436a0 — observed shape
// unaff_ESI is an unaffiliated input register read by the listing; it is modeled
// as the trailing parameter and stored into the object's +0x8 field.
void FUN_005436a0(void* self, int param_1, uint32_t unaff_ESI = 0)
{
    char* ecx = (char*)self;
    int iVar1 = param_1;
    uint32_t uStack_c = 0;
    uint32_t uStack_24 = 0;

    FUN_00545cc0();
    // first 4-byte read; the listing keeps its stack destination and stores ESI
    Mass133StreamRead((void*)(intptr_t)iVar1, &param_1, 4);
    *(uint32_t*)(ecx + 8) = unaff_ESI;
    Mass133StreamRead((void*)(intptr_t)iVar1, &uStack_c, 4);
    *(uint32_t*)(ecx + 0xc) = uStack_c;
    Mass133StreamRead((void*)(intptr_t)iVar1, ecx + 0x10, 4);
    uStack_24 = 2;
    Mass133StreamRead((void*)(intptr_t)iVar1, ecx + 0x14, 2);
    Mass133StreamRead((void*)(intptr_t)iVar1, ecx + 0x16, 2);
    if (*(uint32_t*)(iVar1 + 0x1c) < 0x4010010) {
        Mass133StreamRead((void*)(intptr_t)iVar1, &uStack_24, 2);
    }
    if (0xa000109 < *(uint32_t*)(iVar1 + 0x1c)) {
        *(uint32_t*)(ecx + 0x18) = 0;
        Mass133StreamRead((void*)(intptr_t)iVar1, &uStack_24, 1);
    }
}

// 0x543790 — observed shape
void FUN_00543790(void* self, int* param_1)
{
    char* ecx = (char*)self;
    uint32_t field4 = *(uint32_t*)(ecx + 4);

    (*(void (__cdecl**)(uint32_t))(*(uint32_t*)(intptr_t)param_1 + 0x2c))(field4);
    int writer = param_1[0x58];
    uint32_t vtbl = *(uint32_t*)(intptr_t)writer;
    (*(void (__cdecl**)(void*, int))(vtbl + 0xc))(ecx + 8, 4);
    (*(void (__cdecl**)(void*, int))(vtbl + 0xc))(ecx + 0xc, 4);
    (*(void (__cdecl**)(void*, int))(vtbl + 0xc))(ecx + 0x10, 4);
    (*(void (__cdecl**)(void*, int))(vtbl + 0xc))(ecx + 0x14, 2);
    (*(void (__cdecl**)(void*, int))(vtbl + 0xc))(ecx + 0x16, 2);
    uint32_t uStack_28 = (*(int*)(ecx + 0x18) != 0) ? 1u : 0u;
    (*(void (__cdecl**)(void*, int))(vtbl + 0xc))(&uStack_28, 1);
    if (*(int*)(ecx + 0x18) != 0) {
        FUN_0054a9a0(param_1);
    }
}

// 0x543830 — observed shape
void FUN_00543830(void* self, int param_1)
{
    char* ecx = (char*)self;

    FUN_005436a0(self, param_1);
    Mass133StreamRead((void*)(intptr_t)param_1, ecx + 0x1c, 4);
    Mass133StreamRead((void*)(intptr_t)param_1, ecx + 0x20, 4);
    Mass133StreamRead((void*)(intptr_t)param_1, ecx + 0x24, 4);
    Mass133StreamRead((void*)(intptr_t)param_1, ecx + 0x28, 4);
    Mass133StreamRead((void*)(intptr_t)param_1, ecx + 0x2c, 4);
    Mass133StreamRead((void*)(intptr_t)param_1, ecx + 0x30, 4);
}

// 0x543930 — observed shape
void FUN_00543930(void* self, int param_1)
{
    char* ecx = (char*)self;

    FUN_005436a0(self, param_1);
    Mass133StreamRead((void*)(intptr_t)param_1, ecx + 0x1c, 4);
}

// 0x543990 — observed shape
void FUN_00543990(void* self, uint8_t param_1)
{
    uint32_t* ecx = (uint32_t*)self;

    *ecx = (uint32_t)(uintptr_t)&PTR_FUN_006c143c;
    FUN_00542750();
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
}

// 0x5439c0 — observed shape
void FUN_005439c0(void* self, uint32_t param_1)
{
    char* ecx = (char*)self;
    uint32_t uVar1;
    uint32_t uVar6 = 0;
    int iVar3 = 0;
    int iVar5;
    uint32_t local_5c = 0;
    char local_40[64];
    char* pcVar7 = nullptr;

    int iVar2 = (int)param_1;
    FUN_00540410(param_1);
    param_1 = FUN_00557b10(DAT_007275e8);
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    uVar1 = *(uint32_t*)(ecx + 0x34);
    param_1 = 0;
    if (uVar1 != 0) {
        do {
            iVar5 = *(int*)(*(int*)(ecx + 0x2c) + param_1 * 4);
            if (iVar5 == 0) goto LAB_00543f80;
            switch (param_1) {
            case 1:
                pcVar7 = (char*)"MultiTexture Dark Map";
                goto code_r0x00543a9f;
            case 2:
                local_5c = FUN_00557cb0("MultiTexture Detail Map", param_1);
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                break;
            case 3:
                pcVar7 = (char*)"MultiTexture Gloss Map";
                goto code_r0x00543c7c;
            case 4:
                pcVar7 = (char*)"MultiTexture Glow Map";
            code_r0x00543a9f:
                local_5c = FUN_00557cb0(pcVar7, param_1);
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                break;
            case 5:
                local_5c = FUN_00557cb0("MultiTexture Bump Map", param_1);
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                FUN_005606f0(uVar6, &local_5c);
                local_5c = FUN_00557cf0("m_fLumaScale", *(uint32_t*)(iVar5 + 0x1c));
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                FUN_005606f0(uVar6, &local_5c);
                local_5c = FUN_00557cf0("m_fLumaOffset", *(uint32_t*)(iVar5 + 0x20));
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                FUN_005606f0(uVar6, &local_5c);
                local_5c = FUN_00557cf0(&UNK_006c14ec, *(uint32_t*)(iVar5 + 0x24));
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                FUN_005606f0(uVar6, &local_5c);
                local_5c = FUN_00557cf0(&UNK_006c14dc, *(uint32_t*)(iVar5 + 0x28));
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                FUN_005606f0(uVar6, &local_5c);
                local_5c = FUN_00557cf0("m_fBumpMat10", *(uint32_t*)(iVar5 + 0x2c));
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                FUN_005606f0(uVar6, &local_5c);
                local_5c = FUN_00557cf0("m_fBumpMat11", *(uint32_t*)(iVar5 + 0x30));
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
                break;
            default:
                pcVar7 = (char*)"MultiTexture Decal Map";
            code_r0x00543c7c:
                local_5c = FUN_00557cb0(pcVar7, param_1);
                uVar6 = *(uint32_t*)(iVar2 + 0xc);
                if (*(uint32_t*)(iVar2 + 8) <= uVar6) {
                    FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar6);
                }
            }
            FUN_005606f0(uVar6, &local_5c);
            sprintf(local_40, "m_spTexture ");
            iVar3 = (int)FUN_00557d40(local_40, *(uint32_t*)(iVar5 + 4));
            uVar6 = *(uint32_t*)(iVar2 + 0xc);
            Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
            sprintf(local_40, "m_eClamp ");
            iVar3 = FUN_00542430(local_40, *(uint32_t*)(iVar5 + 8));
            uVar6 = *(uint32_t*)(iVar2 + 0xc);
            Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
            sprintf(local_40, "m_eFilter ");
            iVar3 = FUN_005424d0(local_40, *(uint32_t*)(iVar5 + 0xc));
            uVar6 = *(uint32_t*)(iVar2 + 0xc);
            Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
            sprintf(local_40, "m_uiTexCoord ");
            iVar3 = (int)FUN_00557cb0(local_40, *(uint32_t*)(iVar5 + 0x10));
            uVar6 = *(uint32_t*)(iVar2 + 0xc);
            Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
            iVar3 = (int)FUN_00557bf0(&DAT_006c1464, *(uint16_t*)(iVar5 + 0x14));
            uVar6 = *(uint32_t*)(iVar2 + 0xc);
            Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
            iVar5 = (int)FUN_00557bf0(&DAT_006c145c, *(uint16_t*)(iVar5 + 0x16));
            uVar6 = *(uint32_t*)(iVar2 + 0xc);
            Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar5);
LAB_00543f80:
            param_1 = param_1 + 1;
        } while (param_1 < uVar1);
    }
    if (*(int*)(ecx + 0x44) != 0) {
        uVar1 = *(uint32_t*)(*(int*)(ecx + 0x44) + 0xc);
        param_1 = 0;
        if (uVar1 != 0) {
            do {
                iVar5 = *(int*)(*(int*)(*(int*)(ecx + 0x44) + 4) + param_1 * 4);
                if (iVar5 != 0) {
                    iVar3 = (int)FUN_00557cb0("Shader Map", param_1);
                    uVar6 = *(uint32_t*)(iVar2 + 0xc);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
                    iVar3 = (int)FUN_00557cb0("m_uiID", *(uint32_t*)(iVar5 + 0x1c));
                    uVar6 = *(uint32_t*)(iVar2 + 0xc);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
                    sprintf(local_40, "m_spTexture ");
                    iVar3 = (int)FUN_00557d40(local_40, *(uint32_t*)(iVar5 + 4));
                    uVar6 = *(uint32_t*)(iVar2 + 0xc);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
                    sprintf(local_40, "m_eClamp ");
                    iVar3 = FUN_00542430(local_40, *(uint32_t*)(iVar5 + 8));
                    uVar6 = *(uint32_t*)(iVar2 + 0xc);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
                    sprintf(local_40, "m_eFilter ");
                    iVar3 = FUN_005424d0(local_40, *(uint32_t*)(iVar5 + 0xc));
                    uVar6 = *(uint32_t*)(iVar2 + 0xc);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
                    sprintf(local_40, "m_uiTexCoord ");
                    iVar3 = (int)FUN_00557cb0(local_40, *(uint32_t*)(iVar5 + 0x10));
                    uVar6 = *(uint32_t*)(iVar2 + 0xc);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
                    iVar3 = (int)FUN_00557bf0(&DAT_006c1464, *(uint16_t*)(iVar5 + 0x14));
                    uVar6 = *(uint32_t*)(iVar2 + 0xc);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar3);
                    iVar5 = (int)FUN_00557bf0(&DAT_006c145c, *(uint16_t*)(iVar5 + 0x16));
                    uVar6 = *(uint32_t*)(iVar2 + 0xc);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar6, iVar5);
                }
                param_1 = param_1 + 1;
            } while (param_1 < uVar1);
        }
    }
}

// 0x5443c0 — observed shape
void FUN_005443c0(void* self, int param_1, uint32_t param_2)
{
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t* local_4;
    uint32_t* puVar1;
    int iVar2;
    uint32_t uVar5;
    uint32_t uVar6;

    local_4 = in_ECX;
    thunk_FUN_00540cf0(param_1, param_2);
    *(uint32_t*)(param_1 + 0x20) = in_ECX[8];
    *(uint32_t*)(param_1 + 0x40) = in_ECX[0x10];
    *(uint8_t*)(param_1 + 0x24) = *(uint8_t*)((char*)in_ECX + 0x24);
    uVar5 = in_ECX[0xd];
    uint32_t uVar4 = 0;
    if (uVar5 != 0) {
        do {
            if (*(int*)((intptr_t)in_ECX[0xb] + uVar4 * 4) != 0) {
                if (uVar4 == 5) {
                    puVar1 = (uint32_t*)FUN_00533c78(0x34);
                    if (puVar1 == nullptr) {
                        local_4 = nullptr;
                    }
                    else {
                        int iVar = *(int*)((intptr_t)in_ECX[0xb] + 0x14);
                        FUN_005435a0(puVar1, iVar);
                        puVar1[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c143c;
                        puVar1[7] = *(uint32_t*)(iVar + 0x1c);
                        puVar1[8] = *(uint32_t*)(iVar + 0x20);
                        puVar1[9] = *(uint32_t*)(iVar + 0x24);
                        puVar1[10] = *(uint32_t*)(iVar + 0x28);
                        puVar1[0xb] = *(uint32_t*)(iVar + 0x2c);
                        puVar1[0xc] = *(uint32_t*)(iVar + 0x30);
                        local_4 = puVar1;
                    }
                    if (*(uint32_t*)(param_1 + 0x30) < 6) {
                        FUN_006b34a0(*(int*)(param_1 + 0x3c) + 5);
                    }
                    uVar6 = 5;
                }
                else {
                    iVar2 = FUN_00533c78(0x1c);
                    if (iVar2 == 0) {
                        local_4 = nullptr;
                    }
                    else {
                        // listing drops the receiver of FUN_005435a0; it is the allocation
                        FUN_005435a0((void*)(intptr_t)iVar2,
                                     *(int*)((intptr_t)in_ECX[0xb] + uVar4 * 4));
                        local_4 = (uint32_t*)(intptr_t)iVar2;
                    }
                    if (*(uint32_t*)(param_1 + 0x30) <= uVar4) {
                        FUN_006b34a0(*(int*)(param_1 + 0x3c) + (int)uVar4);
                    }
                    uVar6 = uVar4;
                }
                FUN_005606f0(uVar6, (uint32_t*)&local_4);
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar5);
    }
    uVar5 = 0;
    if (in_ECX[0x11] != 0) {
        if (*(int*)(param_1 + 0x44) == 0) {
            puVar1 = (uint32_t*)FUN_00533c78(0x18);
            if (puVar1 == nullptr) {
                puVar1 = nullptr;
            }
            else {
                puVar1[0] = (uint32_t)(uintptr_t)&PTR_FUN_00710bf8;
                puVar1[2] = 0;
                puVar1[5] = 1;
                puVar1[3] = 0;
                puVar1[4] = 0;
                puVar1[1] = 0;
            }
            *(uint32_t**)(param_1 + 0x44) = puVar1;
        }
        uVar4 = *(uint32_t*)(in_ECX[0x11] + 0xc);
        if (uVar4 != 0) {
            do {
                if (*(int*)(*(int*)(in_ECX[0x11] + 4) + uVar5 * 4) != 0) {
                    puVar1 = (uint32_t*)FUN_00533c78(0x20);
                    if (puVar1 == nullptr) {
                        puVar1 = nullptr;
                    }
                    else {
                        iVar2 = *(int*)(*(int*)(in_ECX[0x11] + 4) + uVar5 * 4);
                        FUN_005435a0(puVar1, iVar2);
                        puVar1[0] = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
                        puVar1[7] = *(uint32_t*)(iVar2 + 0x1c);
                    }
                    iVar2 = *(int*)(param_1 + 0x44);
                    Mass133SetEntry((int*)(intptr_t)iVar2, uVar5, (intptr_t)puVar1);
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < uVar4);
        }
    }
}

// 0x544650 — observed shape
void FUN_00544650(void* self, int param_1, uint32_t param_2)
{
    char* ecx = (char*)self;

    thunk_FUN_00540cf0(param_1, param_2);
    *(uint32_t*)(param_1 + 0x24) = *(uint32_t*)(ecx + 0x24);
    *(uint32_t*)(param_1 + 0x28) = *(uint32_t*)(ecx + 0x28);
    *(uint32_t*)(param_1 + 0x2c) = *(uint32_t*)(ecx + 0x2c);
    *(uint32_t*)(param_1 + 0x30) = *(uint32_t*)(ecx + 0x30);
    *(uint32_t*)(param_1 + 0x34) = *(uint32_t*)(ecx + 0x34);
    *(uint32_t*)(param_1 + 0x38) = *(uint32_t*)(ecx + 0x38);
    *(uint32_t*)(param_1 + 0x3c) = *(uint32_t*)(ecx + 0x3c);
    *(uint32_t*)(param_1 + 0x40) = *(uint32_t*)(ecx + 0x40);
    *(uint32_t*)(param_1 + 0x44) = *(uint32_t*)(ecx + 0x44);
    *(uint32_t*)(param_1 + 0x48) = *(uint32_t*)(ecx + 0x48);
    *(uint32_t*)(param_1 + 0x4c) = *(uint32_t*)(ecx + 0x4c);
    *(uint32_t*)(param_1 + 0x50) = *(uint32_t*)(ecx + 0x50);
    *(uint32_t*)(param_1 + 0x54) = *(uint32_t*)(ecx + 0x54);
    *(uint32_t*)(param_1 + 0x58) = *(uint32_t*)(ecx + 0x58);
}

// 0x5446d0 — observed shape
void FUN_005446d0(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;

    FUN_00540c50();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c15a8;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x14] = 0;
    in_ECX[0xb] = 0x3f000000;
    in_ECX[10] = 0x3f000000;
    in_ECX[9] = 0x3f000000;
    in_ECX[0xe] = 0x3f000000;
    in_ECX[0xd] = 0x3f000000;
    in_ECX[0xc] = 0x3f000000;
    in_ECX[0x11] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x14] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x15] = 0x40800000;
    in_ECX[0x16] = 0x3f800000;
    in_ECX[8] = DAT_007179dc;
    DAT_007179dc = DAT_007179dc + 1;
    in_ECX[0x18] = 0;
    in_ECX[0x17] = 1;
}

// 0x5447f0 — observed shape
void FUN_005447f0(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;

    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c15a8;
    FUN_00551150();
    FUN_00540c90();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x544960 — observed shape
void FUN_00544960(void)
{
    uint32_t* puVar3;

    int iVar2 = FUN_00533c78(100);
    if (iVar2 == 0) {
        puVar3 = nullptr;
    }
    else {
        FUN_005446d0((void*)(intptr_t)iVar2);
        puVar3 = (uint32_t*)(intptr_t)iVar2;
    }
    uint32_t* puVar1 = DAT_007275fc;
    if (DAT_007275fc != puVar3) {
        if ((DAT_007275fc != nullptr) &&
            (iVar2 = (int)DAT_007275fc[1], DAT_007275fc[1] = (uint32_t)(iVar2 + -1), iVar2 + -1 == 0)) {
            typedef void (__cdecl *DelFn)(int);
            DelFn fn = (DelFn)(*(void**)*puVar1);
            fn(1);
        }
        DAT_007275fc = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x5449b0 — observed shape
void FUN_005449b0(void)
{
    uint32_t* puVar2 = DAT_007275fc;
    if (DAT_007275fc != nullptr) {
        int iVar1 = (int)DAT_007275fc[1];
        DAT_007275fc[1] = (uint32_t)(iVar1 + -1);
        if (iVar1 + -1 == 0) {
            typedef void (__cdecl *DelFn)(int);
            DelFn fn = (DelFn)(*(void**)*puVar2);
            fn(1);
        }
        DAT_007275fc = nullptr;
    }
}

// 0x544ba0 — observed shape
void FUN_00544ba0(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;

    FUN_00549540();
    in_ECX[0x44] = 0x3f800000;
    in_ECX[0x45] = 0;
    in_ECX[0x46] = 0;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c1630;
}

// 0x544c00 — observed shape
void FUN_00544c00(void* self)
{
    char* in_ECX = (char*)self;

    FUN_004db0a0();
    *(uint32_t*)(in_ECX + 0x110) = *(uint32_t*)(in_ECX + 0x6c);
    *(uint32_t*)(in_ECX + 0x114) = *(uint32_t*)(in_ECX + 0x78);
    *(uint32_t*)(in_ECX + 0x118) = *(uint32_t*)(in_ECX + 0x84);
    *(int*)(in_ECX + 0xc0) = *(int*)(in_ECX + 0xc0) + 1;
}
