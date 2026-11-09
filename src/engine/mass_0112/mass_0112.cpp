#include <cstdint>
#include <cstddef>
#include <windows.h>

extern int DAT_008ed4b0;
extern void* DAT_008ecd78;
extern int DAT_00727080;

extern int FUN_005281c0();
extern int FUN_005285f0(void* a1, int a2, int a3);
extern void FUN_0052c690(void* self);
extern void FUN_0052c640(void* self);
extern void FUN_005f0ddc();
extern void FUN_0052c4d0(void* self);
extern void FUN_0052c350(void* self);
extern void FUN_0052c5a0(void* self);
extern void FUN_0052c5f0(void* self);
extern void operator_delete(void* p);

// 0x52c0c0 — observed shape
void FUN_0052c0c0(void* self)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    *(uint32_t*)(p + 4) = 0;
    *(uint32_t*)(p + 8) = 0;
    *p = 0;
    *(uint32_t*)(p + 0xc) = 0;
    *(uint32_t*)(p + 0x10) = 0;
    *(uint32_t*)(p + 0x14) = 0;
    *(uint32_t*)(p + 0x18) = 0;
}

// 0x52c170 — observed shape
void FUN_0052c170(void* self, int in_EAX, float param_1)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    *(int*)(p + 0x24) = in_EAX;
    int iVar3 = in_EAX * 0x5c + DAT_008ed4b0;
    *(int*)(p + 0x20) = iVar3;
    if (iVar3 != 0) {
        int iVar3_loop = 0;
        do {
            int iVar4 = *(int*)(*(int*)(p + 0x20) + 0x10 + iVar3_loop);
            if (iVar4 == 1) {
                iVar4 = FUN_005281c0();
                if (iVar4 != 0) {
                    int iVar1 = *(int*)(p + 4);
                    if ((iVar1 == 0) ||
                        ((uint32_t)(*(int*)(p + 0xc) - iVar1 >> 2) <=
                         (uint32_t)(*(int*)(p + 8) - iVar1 >> 2))) {
                        FUN_0052c690(self);
                        *(int*)(p + 0x34) = *(int*)(p + 0x34) + 1;
                    }
                    else {
                        int* piVar2 = *(int**)(p + 8);
                        *piVar2 = iVar4;
                        *(int**)(p + 8) = piVar2 + 1;
                        *(int*)(p + 0x34) = *(int*)(p + 0x34) + 1;
                    }
                }
            }
            else if ((iVar4 == 2) && (iVar4 = FUN_005285f0(&DAT_008ecd78, 0, 0), iVar4 != 0)) {
                FUN_0052c640(self);
                *(int*)(p + 0x38) = *(int*)(p + 0x38) + 1;
            }
            iVar3_loop = iVar3_loop + 8;
        } while (iVar3_loop < 0x50);
        if (param_1 == -1.0f) {
            DAT_00727080 = DAT_00727080 * 0x343fd + 0x269ec3;
            FUN_005f0ddc();
        }
        FUN_0052c4d0(self);
        *(uint8_t*)(p + 0x32) = 1;
        *(uint8_t*)(p + 0x30) = 1;
    }
}

// 0x52c350 — observed shape
void FUN_0052c350(void* self)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    uint32_t* puVar1 = *(uint32_t**)(p + 4);
    if (puVar1 != *(uint32_t**)(p + 8)) {
        do {
            typedef void(__thiscall* VFn)(void*, int);
            VFn vfn = *(VFn*)(*(int*)*puVar1 + 0x5c);
            vfn(*(void*)*puVar1, 1);
            puVar1 = puVar1 + 1;
        } while (puVar1 != *(uint32_t**)(p + 8));
    }
    puVar1 = *(uint32_t**)(p + 0x14);
    if (puVar1 != *(uint32_t**)(p + 0x18)) {
        do {
            typedef void(__thiscall* VFn2)(void*, int);
            VFn2 vfn = *(VFn2*)(*(int*)*puVar1 + 0x5c);
            vfn(*(void*)*puVar1, 1);
            puVar1 = puVar1 + 1;
        } while (puVar1 != *(uint32_t**)(p + 0x18));
    }
    if (*(void**)(p + 4) != nullptr) {
        operator_delete(*(void**)(p + 4));
    }
    *(uint32_t*)(p + 4) = 0;
    *(uint32_t*)(p + 8) = 0;
    *(uint32_t*)(p + 0xc) = 0;
    if (*(void**)(p + 0x14) != nullptr) {
        operator_delete(*(void**)(p + 0x14));
    }
    *(uint32_t*)(p + 0x14) = 0;
    *(uint32_t*)(p + 0x18) = 0;
    *(uint32_t*)(p + 0x1c) = 0;
    *(uint8_t*)(p + 0x30) = 0;
    *(uint8_t*)(p + 0x31) = 0;
    *(uint8_t*)(p + 0x32) = 0;
    *(uint32_t*)(p + 0x34) = 0;
    *(uint32_t*)(p + 0x38) = 0;
    *(uint32_t*)(p + 0x44) = 0;
    *(uint32_t*)(p + 0x40) = 0;
    *(uint32_t*)(p + 0x48) = 0;
    *(uint32_t*)(p + 0x28) = 0x3f800000;
    *(uint32_t*)(p + 0x3c) = 0xbf800000;
    *(uint32_t*)(p + 0x2c) = 0x3f800000;
}

// 0x52c400 — observed shape
void FUN_0052c400(void* self)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    typedef double(__thiscall* GetF)(void*);
    GetF getf = *(GetF*)(*(uintptr_t*)&DAT_008ecd78 + 0x14);
    float fVar1 = static_cast<float>(getf(DAT_008ecd78));
    if (*(int*)(p + 0x3c) != (int)0xbf800000) {
        if (*(float*)(p + 0x40) + *(float*)(p + 0x3c) < fVar1) {
            if (*(float*)(p + 0x44) == 0.0f) {
                FUN_0052c350(self);
                FUN_0052c5a0(self);
                FUN_0052c5f0(self);
                return;
            }
            *(uint32_t*)(p + 0x2c) = *(uint32_t*)(p + 0x44);
            FUN_0052c5a0(self);
            FUN_0052c5f0(self);
            return;
        }
        *(float*)(p + 0x2c) =
            (*(float*)(p + 0x44) - *(float*)(p + 0x48)) *
            ((fVar1 - *(float*)(p + 0x40)) / *(float*)(p + 0x3c)) +
            *(float*)(p + 0x48);
    }
    FUN_0052c5a0(self);
    FUN_0052c5f0(self);
}

// 0x52c4a0 — observed shape
void FUN_0052c4a0(void* self, uint32_t param_1)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    *(uint32_t*)(p + 0x48) = *(uint32_t*)(p + 0x2c);
    *(uint32_t*)(p + 0x44) = 0;
    typedef double(__thiscall* GetF2)(void*);
    GetF2 getf = *(GetF2*)(*(uintptr_t*)&DAT_008ecd78 + 0x14);
    float fVar1 = static_cast<float>(getf(DAT_008ecd78));
    *(float*)(p + 0x40) = fVar1;
    *(uint32_t*)(p + 0x3c) = param_1;
}

// 0x52c4d0 — observed shape
void FUN_0052c4d0(void* self, uint32_t param_1)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    uint32_t* puVar1 = *(uint32_t**)(p + 4);
    *(uint32_t*)(p + 0x28) = param_1;
    *(uint32_t*)(p + 0x2c) = param_1;
    uint32_t local_1 = 0x3f800000;
    float unaff_retaddr = 0.0f;
    if (puVar1 != *(uint32_t**)(p + 8)) {
        do {
            typedef void(__thiscall* VFn100)(void*, void*);
            typedef void(__thiscall* VFn78)(void*, float);
            VFn100 v100 = *(VFn100*)(*(int*)*puVar1 + 100);
            v100(*(void*)*puVar1, &local_1);
            float f = *(float*)&local_1;
            VFn78 v78 = *(VFn78*)(*(int*)*puVar1 + 0x78);
            v78(*(void*)*puVar1, f * *(float*)(p + 0x28));
            puVar1 = puVar1 + 1;
        } while (puVar1 != *(uint32_t**)(p + 8));
    }
    puVar1 = *(uint32_t**)(p + 0x14);
    if (puVar1 != *(uint32_t**)(p + 0x18)) {
        do {
            typedef void(__thiscall* VFn100b)(void*, void*);
            typedef void(__thiscall* VFn78b)(void*, float);
            VFn100b v100 = *(VFn100b*)(*(int*)*puVar1 + 100);
            v100(*(void*)*puVar1, &local_1);
            float f = *(float*)&local_1;
            VFn78b v78 = *(VFn78b*)(*(int*)*puVar1 + 0x78);
            v78(*(void*)*puVar1, f * *(float*)(p + 0x28));
            puVar1 = puVar1 + 1;
        } while (puVar1 != *(uint32_t**)(p + 0x18));
    }
}

// 0x52c550 — observed shape
void FUN_0052c550(void* self, int in_EDX)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    int* _Dst = *(int**)(p + 4);
    if (_Dst != *(int**)(p + 8)) {
        while (*_Dst != in_EDX) {
            _Dst = _Dst + 1;
            if (_Dst == *(int**)(p + 8)) {
                return;
            }
        }
        *(int*)(p + 0x34) = *(int*)(p + 0x34) + -1;
        memmove(_Dst, _Dst + 1, (size_t)(((*(int**)(p + 8)) - (_Dst + 1)) << 2));
        *(int*)(p + 8) = *(int*)(p + 8) + -4;
    }
}

// 0x52c5a0 — observed shape
void FUN_0052c5a0(void* self, float unaff_ESI)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    uint32_t* puVar2 = *(uint32_t**)(p + 4);
    if (puVar2 != *(uint32_t**)(p + 8)) {
        do {
            typedef char(__thiscall* VFn40)(void*);
            VFn40 v40 = *(VFn40*)(*(int*)*puVar2 + 0x40);
            char cVar1 = v40(*(void*)*puVar2);
            if (cVar1 != 0) {
                uint8_t auStack_4[4] = {0};
                typedef void(__thiscall* VFn100)(void*, void*);
                typedef void(__thiscall* VFn78)(void*, float);
                VFn100 v100 = *(VFn100*)(*(int*)*puVar2 + 100);
                v100(*(void*)*puVar2, auStack_4);
                VFn78 v78 = *(VFn78*)(*(int*)*puVar2 + 0x78);
                v78(*(void*)*puVar2, *(float*)(p + 0x2c) * *(float*)(p + 0x28) * unaff_ESI);
            }
            puVar2 = puVar2 + 1;
        } while (puVar2 != *(uint32_t**)(p + 8));
    }
}

// 0x52c5f0 — observed shape
void FUN_0052c5f0(void* self, float unaff_ESI)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    uint32_t* puVar2 = *(uint32_t**)(p + 0x14);
    if (puVar2 != *(uint32_t**)(p + 0x18)) {
        do {
            typedef char(__thiscall* VFn40)(void*);
            VFn40 v40 = *(VFn40*)(*(int*)*puVar2 + 0x40);
            char cVar1 = v40(*(void*)*puVar2);
            if (cVar1 != 0) {
                uint8_t auStack_4[4] = {0};
                typedef void(__thiscall* VFn100)(void*, void*);
                typedef void(__thiscall* VFn78)(void*, float);
                VFn100 v100 = *(VFn100*)(*(int*)*puVar2 + 100);
                v100(*(void*)*puVar2, auStack_4);
                VFn78 v78 = *(VFn78*)(*(int*)*puVar2 + 0x78);
                v78(*(void*)*puVar2, *(float*)(p + 0x2c) * *(float*)(p + 0x28) * unaff_ESI);
            }
            puVar2 = puVar2 + 1;
        } while (puVar2 != *(uint32_t**)(p + 0x18));
    }
}

// 0x52c640 — observed shape
void FUN_0052c640(void* self, uint32_t* unaff_EDI)
{
    int iVar1 = *(int*)(static_cast<uint8_t*>(self) + 4);
    if ((iVar1 == 0) ||
        ((uint32_t)(*(int*)(static_cast<uint8_t*>(self) + 0xc) - iVar1 >> 2) <= (uint32_t)(*(int*)(static_cast<uint8_t*>(self) + 8) - iVar1 >> 2))) {
        FUN_0052c690(self, *(uint32_t*)(static_cast<uint8_t*>(self) + 8), unaff_EDI);
        return;
    }
    uint32_t* puVar2 = *(uint32_t**)(static_cast<uint8_t*>(self) + 8);
    *puVar2 = *unaff_EDI;
    *(uint32_t**)(static_cast<uint8_t*>(self) + 8) = puVar2 + 1;
}

// 0x52c690 — observed shape
// NEEDS_MANUAL: SEH/exception-list wrapper with elided branches; preserves observed vector-grow arithmetic and call order
void FUN_0052c690(void* self, uint32_t* param_2, uint32_t* param_3, uint32_t in_ECX)
{
    void* pvVar1 = nullptr;
    extern void* ExceptionList;
    extern void _EHFunc;
    void* local_10 = ExceptionList;
    int local_8 = -1;
    void* saved_ex = ExceptionList;
    uint32_t uVar4 = *param_3;
    int param_1 = reinterpret_cast<int>(self);
    int iVar3 = *(int*)(param_1 + 4);
    uint32_t uVar2;
    if (iVar3 == 0) {
        uVar2 = 0;
    } else {
        uVar2 = *(int*)(param_1 + 0xc) - iVar3 >> 2;
    }
    if (in_ECX != 0) {
        int iVar7;
        if (iVar3 == 0) {
            iVar7 = 0;
        } else {
            iVar7 = *(int*)(param_1 + 8) - iVar3 >> 2;
        }
        ExceptionList = &local_10;
        extern int FUN_0052a820();
        if (0x3fffffffU - iVar7 < in_ECX) {
            ExceptionList = &local_10;
            uVar2 = FUN_0052a820();
            iVar3 = 0;
        }
        if (iVar3 == 0) {
            iVar7 = 0;
        } else {
            iVar7 = *(int*)(param_1 + 8) - iVar3 >> 2;
        }
        if (uVar2 < iVar7 + in_ECX) {
            if (0x3fffffff - (uVar2 >> 1) < uVar2) {
                uVar2 = 0;
            } else {
                uVar2 = uVar2 + (uVar2 >> 1);
            }
            if (iVar3 == 0) {
                iVar7 = 0;
            } else {
                iVar7 = *(int*)(param_1 + 8) - iVar3 >> 2;
            }
            if (uVar2 < iVar7 + in_ECX) {
                if (iVar3 == 0) {
                    iVar3 = 0;
                } else {
                    iVar3 = *(int*)(param_1 + 8) - iVar3 >> 2;
                }
                uVar2 = iVar3 + in_ECX;
            }
            extern int FUN_00533c78(int);
            int newbuf = FUN_00533c78(uVar2 * 4);
            local_8 = 0;
            extern void* FUN_0052c8e0(void*);
            FUN_0052c8e0(reinterpret_cast<void*>(newbuf));
            extern int FUN_0052a800();
            (void)FUN_0052a800();
            FUN_0052c8e0(reinterpret_cast<void*>(FUN_0052a800()));
            local_8 = -1;
            pvVar1 = *(void**)(param_1 + 4);
            if (pvVar1 == nullptr) {
                iVar7 = 0;
            } else {
                iVar7 = *(int*)(param_1 + 8) - reinterpret_cast<int>(pvVar1) >> 2;
            }
            if (pvVar1 != nullptr) {
                operator_delete(pvVar1);
            }
            *(uint32_t*)(param_1 + 0xc) = uVar2 * 4 + iVar3;
            *(uint32_t*)(param_1 + 8) = iVar3 + (in_ECX + iVar7) * 4;
            *(int*)(param_1 + 4) = iVar3;
            ExceptionList = local_10;
            return;
        }
        iVar3 = *(int*)(param_1 + 8);
        if ((uint32_t)(iVar3 - reinterpret_cast<int>(param_2) >> 2) < in_ECX) {
            FUN_0052c8e0(param_2 + in_ECX);
            local_8 = 2;
            (void)FUN_0052a800();
            iVar3 = *(int*)(param_1 + 8) + in_ECX * 4;
            *(int*)(param_1 + 8) = iVar3;
            uint32_t* puVar5 = reinterpret_cast<uint32_t*>(iVar3 + in_ECX * -4);
            if (param_2 != puVar5) {
                do {
                    *param_2 = uVar4;
                    param_2 = param_2 + 1;
                } while (param_2 != puVar5);
                ExceptionList = local_10;
                return;
            }
        } else {
            uint32_t uVar6 = reinterpret_cast<uint32_t>(FUN_0052c8e0(reinterpret_cast<void*>(iVar3)));
            *(uint32_t*)(param_1 + 8) = uVar6;
            iVar7 = static_cast<int>((iVar3 + in_ECX * -4) - reinterpret_cast<int>(param_2)) >> 2;
            memmove(reinterpret_cast<void*>(iVar3 + iVar7 * -4), param_2, iVar7 * 4);
            uint32_t* puVar5 = param_2 + in_ECX;
            for (; param_2 != puVar5; param_2 = param_2 + 1) {
                *param_2 = uVar4;
            }
        }
    }
    ExceptionList = local_10;
}

// 0x52c8e0 — observed shape
void* FUN_0052c8e0(void* param_1, void* in_ECX, int in_EAX)
{
    size_t _Size = static_cast<size_t>((in_EAX - reinterpret_cast<int>(in_ECX) >> 2) * 4);
    void* pvVar1 = memmove(param_1, in_ECX, _Size);
    return reinterpret_cast<void*>(reinterpret_cast<int>(pvVar1) + _Size);
}

// 0x52c980 — observed shape
void FUN_0052c980(char* param_1, char* param_2)
{
    extern int FUN_00527d30();
    extern char DAT_008ca640[];
    char local_10[16];
    sprintf(local_10, "-%03d%s", 0, "");
    int iVar6 = reinterpret_cast<int>(&DAT_008ca640[0]) - reinterpret_cast<int>(param_1);
    char* pcVar2 = param_1;
    do {
        char cVar1 = *pcVar2;
        pcVar2[iVar6] = cVar1;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != 0);
    pcVar2 = local_10;
    do {
        char cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != 0);
    uint32_t uVar3 = static_cast<uint32_t>(pcVar2 - local_10);
    pcVar2 = reinterpret_cast<char*>(0x8ca63f);
    do {
        char* pcVar8 = pcVar2 + 1;
        pcVar2 = pcVar2 + 1;
        (void)pcVar8;
    } while (* (pcVar2) != 0);
    pcVar2 = local_10;
    char* pcVar8 = local_10;
    char* pcVar2b = reinterpret_cast<char*>(0x8ca63f);
    for (uint32_t uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(uint32_t*)pcVar2b = *(uint32_t*)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar2b = pcVar2b + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2b = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar2b = pcVar2b + 1;
    }
    int iVar4 = FUN_00527d30();
    if (iVar4 == 0) {
        do {
            char cVar1 = *param_1;
            param_1[iVar6] = cVar1;
            param_1 = param_1 + 1;
        } while (cVar1 != 0);
        pcVar2 = param_2;
        do {
            char cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != 0);
        pcVar8 = reinterpret_cast<char*>(0x8ca63f);
        char* pcVar7 = pcVar8;
        do {
            char* pcVar86 = pcVar8 + 1;
            pcVar8 = pcVar8 + 1;
            pcVar7 = pcVar86;
        } while (*pcVar7 != 0);
        char* pcVar7b = param_2;
        for (uVar3 = static_cast<uint32_t>(pcVar2 - param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(uint32_t*)pcVar8 = *(uint32_t*)pcVar7b;
            pcVar7b = pcVar7b + 4;
            pcVar8 = pcVar8 + 4;
        }
        for (uVar3 = static_cast<uint32_t>(pcVar2 - param_2 & 3); uVar3 != 0; uVar3 = uVar3 - 1) {
            *pcVar8 = *pcVar7b;
            pcVar7b = pcVar7b + 1;
            pcVar8 = pcVar8 + 1;
        }
        FUN_00527d30();
    }
}

// 0x52ccf0 — observed shape
uint8_t FUN_0052ccf0(void* self)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    extern void* DAT_008ecd78;
    typedef char(__thiscall* VFn18)(void*);
    VFn18 v18 = *(VFn18*)(*(uintptr_t*)&DAT_008ecd78 + 0x18);
    char cVar1 = v18(DAT_008ecd78);
    if (cVar1 == 0) {
        return 0;
    }
    if ((*(int*)(p + 0x118) != 2) && (0 < *(int*)(p + 0x108))) {
        int* piVar3 = reinterpret_cast<int*>(p + 8);
        int iVar4 = 0;
        extern int DAT_008ed008;
        extern int DAT_008ed00c;
        extern void operator_delete__(void*);
        do {
            void* _Memory = reinterpret_cast<void*>(*piVar3 - reinterpret_cast<int>(*(char*)(*piVar3 + -1)));
            size_t sVar2 = _msize(_Memory);
            bool bVar5 = DAT_008ed008 < static_cast<int>(sVar2);
            DAT_008ed008 = DAT_008ed008 - static_cast<int>(sVar2);
            DAT_008ed00c = DAT_008ed00c - static_cast<uint32_t>(bVar5);
            operator_delete__(_Memory);
            iVar4 = iVar4 + 1;
            piVar3 = piVar3 + 1;
        } while (iVar4 < *(int*)(p + 0x108));
    }
    extern void FUN_00529120();
    FUN_00529120();
    return 1;
}

// 0x52cd90 — observed shape
uint32_t FUN_0052cd90(void* self)
{
    uint8_t* p = static_cast<uint8_t*>(self);
    if (*(int*)(p + 0x110) < 1) {
        extern void FUN_0052ff60(const char*);
        FUN_0052ff60("Could not decrement instances, too many decrements.");
    }
    *(int*)(p + 0x110) = *(int*)(p + 0x110) + -1;
    return 1;
}

// 0x52cdc0 — observed shape
int FUN_0052cdc0(char* param_1)
{
    extern char FUN_004f4ed0();
    int iVar6 = 0;
    char local_110[15] = {0};
    char* pcVar5 = &local_110[0 - reinterpret_cast<int>(param_1) - (0x110 - 15)];
    while (true) {
        char* pcVar2 = param_1;
        do {
            char cVar1 = *pcVar2;
            pcVar2[reinterpret_cast<int>(pcVar5)] = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != 0);
        sprintf(local_110, "-%03d.wav", iVar6);
        pcVar2 = local_110;
        do {
            char cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != 0);
        uint32_t uVar3 = static_cast<uint32_t>(pcVar2 - local_110);
        char* pcVar2b = &local_110[15];
        do {
            char* pcVar7 = pcVar2b + 1;
            pcVar2b = pcVar2b + 1;
        } while (*(pcVar2b) != 0);
        char* pcVar7 = local_110;
        for (uint32_t uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(uint32_t*)pcVar2b = *(uint32_t*)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar2b = pcVar2b + 4;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *pcVar2b = *pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar2b = pcVar2b + 1;
        }
        char cVar1 = FUN_004f4ed0();
        if (cVar1 == 0) break;
        iVar6 = iVar6 + 1;
    }
    if (iVar6 == 0) {
        char* pcVar2 = param_1;
        do {
            char cVar1 = *pcVar2;
            pcVar2[reinterpret_cast<int>(pcVar5)] = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != 0);
        char* pcVar2b = &local_110[15];
        char* pcVar7 = pcVar2b;
        do {
            pcVar7 = pcVar2b;
            pcVar2b = pcVar7 + 1;
        } while (pcVar7[1] != 0);
        strncpy(pcVar7 + 1, ".wav", 5);
        char cVar1 = FUN_004f4ed0();
        if (cVar1 != 0) {
            return 1;
        }
        while (true) {
            pcVar2 = param_1;
            do {
                cVar1 = *pcVar2;
                pcVar2[reinterpret_cast<int>(pcVar5)] = cVar1;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != 0);
            sprintf(local_110, "-%03d.mp3", iVar6);
            pcVar2 = local_110;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != 0);
            uint32_t uVar3 = static_cast<uint32_t>(pcVar2 - local_110);
            pcVar2b = &local_110[15];
            do {
                char* pcVar7b = pcVar2b + 1;
                pcVar2b = pcVar2b + 1;
            } while (*(pcVar2b) != 0);
            pcVar7 = local_110;
            for (uint32_t uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                *(uint32_t*)pcVar2b = *(uint32_t*)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar2b = pcVar2b + 4;
            }
            for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *pcVar2b = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar2b = pcVar2b + 1;
            }
            cVar1 = FUN_004f4ed0();
            if (cVar1 == 0) break;
            iVar6 = iVar6 + 1;
        }
        if (iVar6 == 0) {
            do {
                cVar1 = *param_1;
                param_1[reinterpret_cast<int>(pcVar5)] = cVar1;
                param_1 = param_1 + 1;
            } while (cVar1 != 0);
            char* pcVar5b = &local_110[15];
            do {
                char* pcVar2b2 = pcVar5b;
                pcVar5b = pcVar2b2 + 1;
            } while (pcVar5b[0] != 0);
            strncpy(pcVar5b - 1 + 1, ".mp3", 5);
            cVar1 = FUN_004f4ed0();
            if (cVar1 != 0) {
                return 1;
            }
        }
    }
    return iVar6;
}

// 0x52cf90 — observed shape
// NEEDS_MANUAL: large non-contiguous body with elided setup, thunk allocation, and SEH locals; preserves observed iteration, suffix-copy shape, and post-loop copy
void FUN_0052cf90(char* param_1, char* param_2, int param_3, int in_EAX)
{
    extern char DAT_008ca640[];
    extern char FUN_004f4ed0();
    int iVar1 = param_3;
    int iVar9 = 0;
    if (in_EAX < 0) {
        while (true) {
            char* pcVar3 = param_1;
            do {
                char cVar2 = *pcVar3;
                pcVar3[reinterpret_cast<int>(&DAT_008ca640[0]) - reinterpret_cast<int>(param_1)] = cVar2;
                pcVar3 = pcVar3 + 1;
            } while (cVar2 != 0);
            char local_40[16] = {0};
            sprintf(local_40, "-%03d%s", *(uint32_t*)(param_3 + 0x100), param_2);
            pcVar3 = local_40;
            do {
                char cVar2 = *pcVar3;
                pcVar3 = pcVar3 + 1;
            } while (cVar2 != 0);
            uint32_t uVar4 = static_cast<uint32_t>(pcVar3 - local_40);
            pcVar3 = reinterpret_cast<char*>(0x8ca63f);
            char* pcVar11 = pcVar3;
            do {
                pcVar11 = pcVar3 + 1;
                pcVar3 = pcVar3 + 1;
            } while (*pcVar11 != 0);
            pcVar11 = local_40;
            for (uint32_t uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(uint32_t*)pcVar3 = *(uint32_t*)pcVar11;
                pcVar11 = pcVar11 + 4;
                pcVar3 = pcVar3 + 4;
            }
            for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *pcVar3 = *pcVar11;
                pcVar11 = pcVar11 + 1;
                pcVar3 = pcVar3 + 1;
            }
            char cVar2 = FUN_004f4ed0();
            iVar9 = reinterpret_cast<int>(&DAT_008ca640[0]) - reinterpret_cast<int>(param_1);
            if (cVar2 == 0) break;
            extern void FUN_004f4b20(char*, int, int, int);
            extern void FUN_004f10f0(uint32_t, int);
            extern void FUN_004fe190(uint32_t);
            extern char FUN_004f4e60();
            extern void FUN_004f0dc0();
            extern void operator_delete__(void*);
            extern uint32_t thunk_FUN_00533c78(uint32_t);
            extern int DAT_008ed008;
            extern int DAT_008ed00c;
            extern int DAT_008cacd0;
            extern int DAT_008cacc8;
            extern int DAT_008cace4;
            extern void* PTR_FUN_006f583c;
            extern void* PTR_FUN_006f5864;
            void** local_30 = nullptr;
            int* local_14 = &DAT_008cacd0;
            uint32_t local_2c = 0; uint32_t local_28 = 0; uint32_t local_24 = 0; uint32_t local_20 = 0; uint32_t local_1c = 0; uint32_t local_18 = 0;
            local_30 = &PTR_FUN_006f583c;
            uint32_t local_8 = 0;
            int local_c = 0;
            int local_4 = 0;
            FUN_004f4b20(&DAT_008ca640[0], 1, 0, 0x8000);
            int iVar9b;
            if (local_4 == 0) {
                iVar9b = local_c;
            } else {
                iVar9b = *(int*)(local_4 + 0x18);
            }
            uint32_t uVar4b = static_cast<uint32_t>(iVar9b + 0x10);
            *(int*)(param_3 + 0x80 + *(int*)(param_3 + 0x100) * 4) = iVar9b;
            uint32_t uVar8 = thunk_FUN_00533c78(uVar4b);
            bool bVar12 = static_cast<unsigned>(DAT_008ed008 + uVar4b) < static_cast<unsigned>(DAT_008ed008);
            DAT_008ed008 = DAT_008ed008 + uVar4b;
            DAT_008ed00c = DAT_008ed00c + static_cast<uint32_t>(bVar12);
            int iVar6;
            if ((uVar8 & 0xf) == 0) {
                iVar6 = uVar8 + 0x10;
                *(uint8_t*)(uVar8 + 0xf) = 0x10;
            } else {
                iVar6 = (uVar8 & 0xfffffff0) + 0x10;
                *(char*)(reinterpret_cast<uintptr_t>(uVar8 & 0xfffffff0) + 0xf) = static_cast<char>(iVar6) - static_cast<char>(uVar8);
            }
            *(int*)(param_3 + *(int*)(param_3 + 0x100) * 4) = iVar6;
            uint32_t uVar5 = *(uint32_t*)(param_3 + *(int*)(param_3 + 0x100) * 4);
            if (local_4 == 0) {
                FUN_004f10f0(uVar5, iVar9b);
            } else {
                FUN_004fe190(uVar5);
            }
            char cVar2b = (*(char(__thiscall*)())local_30[6])();
            if (cVar2b != 0) {
                if (local_4 == 0) {
                    FUN_004f0dc0();
                } else {
                    *(uint32_t*)(local_4 + 0x14) = 0;
                    local_4 = 0;
                    local_8 = 0;
                    if (*(int*)(reinterpret_cast<int>(local_14) + -4) != 0) {
                        *local_14 = 0;
                        *(uint32_t*)(reinterpret_cast<int>(local_14) + -4) = 0;
                    }
                }
            }
            *(int*)(param_3 + 0x100) = *(int*)(param_3 + 0x100) + 1;
            local_30 = &PTR_FUN_006f583c;
            cVar2b = FUN_004f4e60();
            if (cVar2b != 0) {
                if (local_4 == 0) {
                    FUN_004f0dc0();
                } else {
                    *(uint32_t*)(local_4 + 0x14) = 0;
                    local_4 = 0;
                    local_8 = 0;
                    if (*(int*)(reinterpret_cast<int>(local_14) + -4) != 0) {
                        *local_14 = 0;
                        *(uint32_t*)(reinterpret_cast<int>(local_14) + -4) = 0;
                    }
                }
                InterlockedDecrement(reinterpret_cast<volatile LONG*>(&DAT_008cace4));
            }
            local_30 = &PTR_FUN_006f5864;
            FUN_004f0dc0();
            uint32_t* puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(local_14) + -8);
            if ((puVar7 != nullptr) && (reinterpret_cast<int>(puVar7) != &DAT_008cacc8)) {
                operator_delete__(puVar7);
            }
            local_14 = &DAT_008cacd0;
        }
    } else {
        iVar9 = reinterpret_cast<int>(&DAT_008ca640[0]) - reinterpret_cast<int>(param_1);
        char* pcVar3 = param_1;
        do {
            char cVar2 = *pcVar3;
            pcVar3[iVar9] = cVar2;
            pcVar3 = pcVar3 + 1;
        } while (cVar2 != 0);
        char local_40[16] = {0};
        sprintf(local_40, "-%03d%s", 0, "");
        pcVar3 = local_40;
        do {
            char cVar2 = *pcVar3;
            pcVar3 = pcVar3 + 1;
        } while (cVar2 != 0);
        uint32_t uVar4 = static_cast<uint32_t>(pcVar3 - local_40);
        pcVar3 = reinterpret_cast<char*>(0x8ca63f);
        char* pcVar11 = pcVar3;
        do {
            pcVar11 = pcVar3 + 1;
            pcVar3 = pcVar3 + 1;
        } while (*pcVar11 != 0);
        pcVar11 = local_40;
        for (uint32_t uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(uint32_t*)pcVar3 = *(uint32_t*)pcVar11;
            pcVar11 = pcVar11 + 4;
            pcVar3 = pcVar3 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *pcVar3 = *pcVar11;
            pcVar11 = pcVar11 + 1;
            pcVar3 = pcVar3 + 1;
        }
        char cVar2 = FUN_004f4ed0();
        if (cVar2 != 0) {
            extern void FUN_004f4b20(char*, int, int, int);
            extern void FUN_004f10f0(uint32_t, int);
            extern void FUN_004fe190(uint32_t);
            extern void FUN_004f4de0();
            extern uint32_t FUN_00529b00();
            extern void FUN_00412d10();
            FUN_004f4b20(&DAT_008ca640[0], 1, 0, 0x8000);
            int iVar6;
            if (param_3 == 0) {
                iVar6 = 0;
            } else {
                iVar6 = 0;
            }
            *(int*)(param_3 + 0x80 + *(int*)(param_3 + 0x100) * 4) = iVar6;
            uint32_t uVar5 = FUN_00529b00();
            *(uint32_t*)(param_3 + *(int*)(param_3 + 0x100) * 4) = uVar5;
            uVar5 = *(uint32_t*)(param_3 + *(int*)(param_3 + 0x100) * 4);
            FUN_004f10f0(uVar5, iVar6);
            FUN_004f4de0();
            *(int*)(param_3 + 0x100) = *(int*)(param_3 + 0x100) + 1;
            FUN_00412d10();
        }
    }
    param_3 = iVar9;
    if (*(int*)(iVar1 + 0x100) == 0) {
        do {
            char cVar2 = *param_1;
            param_1[param_3] = cVar2;
            param_1 = param_1 + 1;
        } while (cVar2 != 0);
        char* pcVar3 = param_2;
        do {
            char cVar2 = *pcVar3;
            pcVar3 = pcVar3 + 1;
        } while (cVar2 != 0);
        char* pcVar11 = reinterpret_cast<char*>(0x8ca63f);
        char* pcVar10 = pcVar11;
        do {
            pcVar10 = pcVar11 + 1;
            pcVar11 = pcVar11 + 1;
        } while (*pcVar10 != 0);
        pcVar10 = param_2;
        for (uint32_t uVar4 = static_cast<uint32_t>(pcVar3 - param_2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(uint32_t*)pcVar11 = *(uint32_t*)pcVar10;
            pcVar10 = pcVar10 + 4;
            pcVar11 = pcVar11 + 4;
        }
        for (uVar4 = static_cast<uint32_t>(pcVar3 - param_2 & 3); uVar4 != 0; uVar4 = uVar4 - 1) {
            *pcVar11 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            pcVar11 = pcVar11 + 1;
        }
        char cVar2 = FUN_004f4ed0();
        if (cVar2 != 0) {
            FUN_004f4de0();
            *(int*)(iVar1 + 0x100) = *(int*)(iVar1 + 0x100) + 1;
            extern void FUN_00412d10();
            FUN_00412d10();
        }
    }
}

// 0x52d4b0 — observed shape
// NEEDS_MANUAL: nested byte-compare loops with truncated adjacency logic; preserves observed provider enumeration and string-match retry shape
uint32_t FUN_0052d4b0()
{
    extern void FUN_0052d5e0();
    extern uint8_t* DAT_008ecfd0;
    extern uint32_t DAT_008cad88;
    extern uint32_t DAT_008ca700[];
    extern uint32_t DAT_008ca800[];
    extern int _AIL_open_3D_provider_4(uint32_t);
    extern void* PTR_s_Miles_Fast_2D_Positional_Audio_007265e8;
    FUN_0052d5e0();
    uint8_t* pbVar9 = DAT_008ecfd0;
    uint32_t uVar6 = DAT_008cad88;
    if ((*DAT_008ecfd0 != 0) && (DAT_008cad88 != 0)) {
        uint32_t uVar10 = 0;
        while (true) {
            uint8_t* pbVar8 = reinterpret_cast<uint8_t*>(DAT_008ca800[uVar10]);
            uint8_t* pbVar3 = pbVar9;
            while (true) {
                uint8_t bVar2 = *pbVar3;
                bool bVar11 = bVar2 < *pbVar8;
                if (bVar2 != *pbVar8) break;
                if (bVar2 == 0) break;
                bVar2 = pbVar3[1];
                bVar11 = bVar2 < pbVar8[1];
                if (bVar2 != pbVar8[1]) break;
                pbVar3 = pbVar3 + 2;
                pbVar8 = pbVar8 + 2;
            }
            int iVar4 = 0;
            if (iVar4 == 0) {
                uint32_t uVar5 = 0;
                if (uVar10 < uVar6) {
                    uVar5 = DAT_008ca700[uVar10];
                }
                iVar4 = _AIL_open_3D_provider_4(uVar5);
                if (iVar4 == 0) {
                    if (uVar10 < DAT_008cad88) {
                        return DAT_008ca700[uVar10];
                    }
                    return 0;
                }
                uVar6 = DAT_008cad88;
            }
            uVar10 = uVar10 + 1;
            if (uVar6 <= uVar10) break;
        }
    }
    if (PTR_s_Miles_Fast_2D_Positional_Audio_007265e8 != nullptr) {
        void** ppuVar7 = &PTR_s_Miles_Fast_2D_Positional_Audio_007265e8;
        do {
            uint32_t uVar10 = 0;
            if (uVar6 != 0) {
                while (true) {
                    uint8_t* pbVar9b = reinterpret_cast<uint8_t*>(DAT_008ca800[uVar10]);
                    uint8_t* pbVar8 = static_cast<uint8_t*>(*ppuVar7);
                    int iVar4 = 0;
                    if (iVar4 == 0) {
                        uint32_t uVar5 = 0;
                        if (uVar10 < uVar6) {
                            uVar5 = DAT_008ca700[uVar10];
                        }
                        iVar4 = _AIL_open_3D_provider_4(uVar5);
                        if (iVar4 == 0) {
                            if (uVar10 < DAT_008cad88) {
                                return DAT_008ca700[uVar10];
                            }
                            return 0;
                        }
                        uVar6 = DAT_008cad88;
                    }
                    uVar10 = uVar10 + 1;
                    if (uVar6 <= uVar10) break;
                }
            }
            void** ppuVar1 = ppuVar7 + 1;
            ppuVar7 = ppuVar7 + 1;
        } while (*ppuVar1 != nullptr);
    }
    return 0xffffffff;
}

// 0x52d5e0 — observed shape
void FUN_0052d5e0()
{
    extern uint32_t DAT_008cad88;
    extern uint32_t DAT_008ca700[];
    extern uint32_t DAT_008ca800[];
    extern char DAT_008ca6c0[];
    extern int _AIL_enumerate_3D_providers_12(int, void*, void*);
    extern int _AIL_open_3D_provider_4(uint32_t);
    extern void _AIL_close_3D_provider_4(uint32_t);
    uint32_t local_4 = 0;
    DAT_008cad88 = 0;
    int iVar3 = _AIL_enumerate_3D_providers_12(local_4, &DAT_008ca700[0], &DAT_008ca800[0]);
    uint32_t uVar2 = DAT_008cad88;
    while ((iVar3 != 0 && (uVar2 < 0x40))) {
        DAT_008cad88 = uVar2 + 1;
        char cVar6 = 0;
        if (uVar2 < DAT_008cad88) {
            iVar3 = _AIL_open_3D_provider_4(DAT_008ca700[uVar2]);
            cVar6 = static_cast<char>(1 - (iVar3 != 0));
            uint32_t uVar7;
            if (uVar2 < DAT_008cad88) {
                uVar7 = DAT_008ca700[uVar2];
            } else {
                uVar7 = 0;
            }
            _AIL_close_3D_provider_4(uVar7);
        } else {
            cVar6 = 0;
        }
        uint32_t* puVar8 = &DAT_008ca800[DAT_008cad88];
        uint32_t* puVar1 = &DAT_008ca700[DAT_008cad88];
        DAT_008ca6c0[DAT_008cad88] = cVar6;
        iVar3 = _AIL_enumerate_3D_providers_12(0, puVar1, puVar8);
        uVar2 = DAT_008cad88;
    }
    DAT_008cad88 = uVar2;
    if (static_cast<int>(uVar2) < 0x40) {
        uint32_t uVar5 = 0x40 - uVar2;
        uint32_t* puVar8 = reinterpret_cast<uint32_t*>(&DAT_008ca6c0[uVar2]);
        for (uint32_t uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
        }
        for (uint32_t uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(uint8_t*)puVar8 = 0;
            puVar8 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(puVar8) + 1);
        }
        puVar8 = &DAT_008ca800[uVar2];
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
        }
    }
}

// 0x52d6d0 — observed shape
void FUN_0052d6d0(char param_1)
{
    extern void _AIL_set_named_sample_file_20();
    if (param_1 == 0) {
        _AIL_set_named_sample_file_20();
        return;
    }
    _AIL_set_named_sample_file_20();
}
