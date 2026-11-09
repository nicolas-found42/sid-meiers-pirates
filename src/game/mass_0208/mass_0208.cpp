#include <cstdint>
#include <cstddef>

extern void FUN_005bbee0(int param_1);
extern bool FUN_005bd960(int param_1, int* param_2);
extern void FUN_005afda0(int param_1);
extern int FUN_00557b10(int param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t param_1, int* param_2);
extern int FUN_00557d80(const char* text, int param_2);
extern int DAT_00728cd8;
extern void FUN_005ae700();
extern void* PTR_FUN_006c6e18;
extern bool FUN_00568540(int param_1);
extern char FUN_005823b0(int param_1, int param_2, uint32_t param_3, uint32_t* param_4);
// 0x5bcb70 — observed shape
void FUN_005bcb70(void* self_ecx, int param_1)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    int saved;
    bool ok;
    FUN_005bbee0(param_1);
    FUN_005bd960(static_cast<int>(reinterpret_cast<intptr_t>(self_ecx)), &param_1);
    saved = param_1;
    if (*reinterpret_cast<int*>(self + 0x50) != 0) {
        ok = FUN_005bd960(*reinterpret_cast<int*>(self + 0x50), &param_1);
        if (ok) {
            *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(saved)) + 0x50) = param_1;
            return;
        }
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(saved)) + 0x50) =
            *reinterpret_cast<uint32_t*>(self + 0x50);
    }
    return;
}

// 0x5bcc80 — observed shape
void FUN_005bcc80(void* self_ecx, int param_1)
{
    uint32_t uVar1;
    int iVar2;
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    iVar2 = param_1;
    FUN_005afda0(param_1);
    param_1 = FUN_00557b10(DAT_00728cd8);
    uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x0c);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x08) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &param_1);
    if (*reinterpret_cast<int*>(self + 0x50) != 0) {
        // Ghidra: param_1 = FUN_00557d80("Emitter Object", *(undefined4*)(*(int*)(in_ECX+0x50)+0xc))
        int emitter = *reinterpret_cast<int*>(self + 0x50);
        int emitter_field = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(emitter)) + 0x0c);
        param_1 = FUN_00557d80("Emitter Object", emitter_field);
        uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x0c);
        if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x08) <= uVar1) {
            FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14) + static_cast<int>(uVar1));
        }
        FUN_005606f0(uVar1, &param_1);
    }
    return;
}

// 0x5bcd80 — observed shape
void FUN_005bcd80(void* self_ecx)
{
    uint32_t* self = static_cast<uint32_t*>(self_ecx);
    FUN_005ae700();
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_006c6e18);
    self[0x13] = 0;
    self[0x14] = 0;
    self[0x15] = 0;
    reinterpret_cast<uint8_t*>(self)[0x16 * 4] = 0;
    return;
}

// 0x5bcdb0 — observed shape
void FUN_005bcdb0(void* self_ecx, int param_1)
{
    uint32_t* puVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    char cVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t* self = static_cast<uint32_t*>(self_ecx);
    char* pcVar9;
    bool found = false;
    bool check = FUN_00568540(param_1);
    if (check) {
        return;
    }
    iVar2 = static_cast<int>(self[0x13]);
    if (iVar2 == 0) {
        return;
    }
    iVar3 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x10);
    uVar7 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x0c);
    if (iVar3 == 0) {
        return;
    }
    puVar1 = self + 0x14;
    self[0x15] = self[0x14];
    cVar5 = FUN_005823b0(static_cast<int>(self[0x0b]), iVar3, uVar7, puVar1);
    if ((cVar5 == '\0') && (static_cast<char>(self[0x16]) == '\0')) {
        uVar8 = self[0x15];
        uVar4 = *puVar1;
        if ((uVar8 == uVar4) || (uVar6 = uVar8 + 1, uVar6 <= uVar4)) {
            uVar8 = uVar8 + 1;
            if (uVar8 < uVar4) {
                pcVar9 = reinterpret_cast<char*>(static_cast<intptr_t>(iVar3) + 4 + uVar8 * 8);
                do {
                    if (uVar7 <= uVar8) break;
                    if (*pcVar9 != '\0') {
                        cVar5 = '\x01';
                        goto LAB_005bce7a;
                    }
                    uVar8 = uVar8 + 1;
                    pcVar9 = pcVar9 + 8;
                } while (uVar8 < *puVar1);
            }
        } else {
            if (uVar6 < uVar7) {
                pcVar9 = reinterpret_cast<char*>(static_cast<intptr_t>(iVar3) + 4 + uVar6 * 8);
                do {
                    if (*pcVar9 != '\0') {
                        cVar5 = '\x01';
                        goto LAB_005bce7a;
                    }
                    uVar6 = uVar6 + 1;
                    pcVar9 = pcVar9 + 8;
                } while (uVar6 < uVar7);
            }
            uVar7 = 0;
            if (uVar4 != 0) {
                pcVar9 = reinterpret_cast<char*>(static_cast<intptr_t>(iVar3) + 4);
                do {
                    if (*pcVar9 != '\0') {
                        cVar5 = '\x01';
                        goto LAB_005bce7a;
                    }
                    uVar7 = uVar7 + 1;
                    pcVar9 = pcVar9 + 8;
                } while (uVar7 < *puVar1);
            }
        }
    }
LAB_005bce7a:
    {
        uint32_t vtable = *self;
        using fn_type = void(*)(char);
        fn_type fn = *reinterpret_cast<fn_type*>(static_cast<intptr_t>(vtable) + 0x6c);
        fn(cVar5);
    }
    // Ghidra: *(undefined1*)(in_ECX+0x16) = unaff_retaddr (return address byte)
    return;
}

// 0x5bcea0 — observed shape
void FUN_005bcea0(void* self_ecx)
{
    int iVar1;
    float* pfVar2;
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    iVar1 = *reinterpret_cast<int*>(self + 0x4c);
    *reinterpret_cast<uint32_t*>(self + 0x18) = 0x7f7fffff;
    *reinterpret_cast<uint32_t*>(self + 0x1c) = 0xff7fffff;
    if (iVar1 == 0) {
        *reinterpret_cast<uint32_t*>(self + 0x54) = 0;
        return;
    }
    pfVar2 = *reinterpret_cast<float**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x10);
    iVar1 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x0c);
    if (pfVar2 != nullptr) {
        if (*pfVar2 < 3.4028235e+38f) {
            *reinterpret_cast<float*>(self + 0x18) = *pfVar2;
        }
        if (-3.4028235e+38f < pfVar2[iVar1 * 2 + -2]) {
            *reinterpret_cast<float*>(self + 0x1c) = pfVar2[iVar1 * 2 + -2];
        }
    }
    *reinterpret_cast<uint32_t*>(self + 0x54) = 0;
    return;
}

extern void FUN_005e4780();
extern void FUN_005ae720();
extern void operator_delete(void* p);
extern void* FUN_00533c78(uint32_t size);
extern void FUN_005383d0();
extern void FUN_00577450(int p1, int p2);
extern int* FUN_00538580(uint32_t** out);
extern int FUN_00538680();
extern void FUN_00552ef0(int self, int p1, int p2, int p3);
extern void FUN_00582420(int p1, int p2, int p3, int p4, uint32_t* out1, uint32_t* out2);
extern void FUN_00582080(int p1, int p2);
extern void FUN_005ae9c0(int p1);
extern int DAT_00728ce0;
extern void* PTR_FUN_006c4618;

// 0x5bcf00 — observed shape
void FUN_005bcf00(void* self_ecx, uint8_t param_1)
{
    FUN_005e4780();
    FUN_005ae720();
    if ((param_1 & 1) != 0) {
        operator_delete(self_ecx);
    }
    return;
}

// 0x5bcf30 — observed shape
void FUN_005bcf30(void* self_ecx, int param_1, int param_2)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    int* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    if (*reinterpret_cast<int*>(self + 0x4c) == 0) {
        puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x14));
        if (puVar3 != nullptr) {
            FUN_005383d0();
            *puVar3 = reinterpret_cast<uint32_t>(&PTR_FUN_006c4618);
            puVar3[3] = 0;
            puVar3[4] = 0;
        }
        puVar2 = *reinterpret_cast<uint32_t**>(self + 0x4c);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    using fn_type = void(*)(int);
                    fn_type fn = *reinterpret_cast<fn_type*>(*puVar2);
                    fn(1);
                }
            }
            *reinterpret_cast<uint32_t**>(self + 0x4c) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
    FUN_00577450(param_1, param_2);
    FUN_005bcea0(self_ecx);
    return;
}

// 0x5bcfb0 — observed shape
int FUN_005bcfb0(int param_1, int param_2, int param_3)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    int iVar3;
    int* piVar4;
    int iVar5;
    uint32_t uStack_c = 0;
    uint32_t uStack_8 = 0;
    uint32_t* local_4 = nullptr;
    piVar4 = FUN_00538580(&local_4);
    puVar1 = reinterpret_cast<uint32_t*>(*piVar4);
    if (puVar1 != nullptr) {
        puVar1[1] = puVar1[1] + 1;
    }
    if (local_4 != nullptr) {
        int prev = static_cast<int>(local_4[1]);
        local_4[1] = static_cast<uint32_t>(prev - 1);
        if (prev - 1 == 0) {
            using fn_type = void(*)(int);
            fn_type fn = *reinterpret_cast<fn_type*>(*local_4);
            fn(1);
        }
    }
    iVar5 = FUN_00538680();
    FUN_00552ef0(iVar5, param_1, param_2, param_3);
    puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x4c);
    if (puVar2 != puVar1) {
        if (puVar2 != nullptr) {
            piVar4 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar4 = *piVar4 - 1;
            if (*piVar4 == 0) {
                using fn_type = void(*)(int);
                fn_type fn = *reinterpret_cast<fn_type*>(*puVar2);
                fn(1);
            }
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x4c) = puVar1;
        if (puVar1 != nullptr) {
            puVar1[1] = puVar1[1] + 1;
        }
    }
    FUN_005bcea0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar5)));
    iVar3 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x4c);
    if (iVar3 != 0) {
        if (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x0c) != 0) {
            FUN_00582420(
                *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x10),
                *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x0c),
                param_1, param_2, &uStack_8, &uStack_c);
            FUN_005bcf30(reinterpret_cast<void*>(static_cast<intptr_t>(iVar5)),
                         static_cast<int>(uStack_8), static_cast<int>(uStack_c));
        }
    }
    if (puVar1 != nullptr) {
        piVar4 = reinterpret_cast<int*>(puVar1 + 1);
        *piVar4 = *piVar4 - 1;
        if (*piVar4 == 0) {
            using fn_type = void(*)(int);
            fn_type fn = *reinterpret_cast<fn_type*>(*puVar1);
            fn(1);
        }
    }
    return iVar5;
}

// 0x5bd0a0 — observed shape
void FUN_005bd0a0(void* self_ecx, int param_1, int param_2)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    int* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    FUN_00582080(param_1, param_2);
    if (*reinterpret_cast<int**>(self + 0x4c) != nullptr) {
        using get_fn = uint32_t*(*)(int);
        int* inner = *reinterpret_cast<int**>(self + 0x4c);
        get_fn fn = *reinterpret_cast<get_fn*>(reinterpret_cast<uint8_t*>(inner) + 8);
        puVar3 = fn(param_2);
        puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x4c);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    using rel_fn = void(*)(int);
                    rel_fn rfn = *reinterpret_cast<rel_fn*>(*puVar2);
                    rfn(1);
                }
            }
            *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x4c) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
        FUN_005bcea0(self_ecx);
    }
    return;
}

// 0x5bd0f0 — observed shape
void FUN_005bd0f0(void* self_ecx, int param_1)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    uint32_t uVar1;
    int iVar2;
    iVar2 = param_1;
    FUN_005ae9c0(param_1);
    param_1 = FUN_00557b10(DAT_00728ce0);
    uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x0c);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x08) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &param_1);
    {
        int* inner = *reinterpret_cast<int**>(self + 0x4c);
        using fn_type = void(*)(int);
        fn_type fn = *reinterpret_cast<fn_type*>(reinterpret_cast<uint8_t*>(inner) + 0x20);
        fn(iVar2);
    }
    return;
}

extern void* PTR_FUN_006c6ea0;
extern void* PTR_FUN_006fe39c;
extern void FUN_00577d90(int p1, int p2, int p3);
extern void FUN_00576320(int p1, int p2, int p3, int p4, int p5, int p6, uint32_t* out1, uint32_t* out2);
extern int DAT_00728ce8;
extern void FUN_00535110(int p1);
extern void FUN_00535150(int p1);
extern int DAT_00727430;
extern int DAT_00727434;
extern int DAT_00727438;
extern int DAT_007177ac;
extern int DAT_007177b0;
extern int DAT_007177b4;

// 0x5bd150 — observed shape
void FUN_005bd150(void* self_ecx)
{
    uint32_t* self = static_cast<uint32_t*>(self_ecx);
    FUN_005ae700();
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_006c6ea0);
    self[0x13] = 0;
    self[0x14] = 0;
    self[0x15] = 0xff7fffff;
    return;
}

// 0x5bd190 — observed shape
uint32_t FUN_005bd190(void* self_ecx, uint32_t* param_1, uint32_t* param_2)
{
    int iVar1;
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    iVar1 = *reinterpret_cast<int*>(self + 0x4c);
    if (iVar1 == 0) {
        *param_1 = 0;
        *param_2 = 0;
        return 0;
    }
    *param_1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x0c);
    *param_2 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x14);
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x10);
}

// 0x5bd1d0 — observed shape
void FUN_005bd1d0(void* self_ecx, int param_1, uint32_t* param_2, uint32_t param_3)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    int* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    if (*reinterpret_cast<int*>(self + 0x4c) == 0) {
        puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x18));
        if (puVar3 == nullptr) {
            puVar3 = nullptr;
        } else {
            FUN_005383d0();
            *puVar3 = reinterpret_cast<uint32_t>(&PTR_FUN_006fe39c);
            puVar3[3] = 0;
            puVar3[4] = 0;
            puVar3[5] = 0;
        }
        puVar2 = *reinterpret_cast<uint32_t**>(self + 0x4c);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using fn_type = void(*)(int);
                    fn_type fn = *reinterpret_cast<fn_type*>(*puVar2);
                    fn(1);
                }
            }
            *reinterpret_cast<uint32_t**>(self + 0x4c) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
    FUN_00577d90(static_cast<int>(reinterpret_cast<intptr_t>(param_2)), param_1, static_cast<int>(param_3));
    *reinterpret_cast<uint32_t*>(self + 0x50) = 0;
    *reinterpret_cast<uint32_t*>(self + 0x18) = *param_2;
    *reinterpret_cast<uint32_t*>(self + 0x1c) =
        *reinterpret_cast<uint32_t*>(
            static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(
                reinterpret_cast<uint8_t*>(param_2) + 4)) * (param_1 - 1) +
            reinterpret_cast<intptr_t>(param_2));
    return;
}

// 0x5bd2c0 — observed shape
void FUN_005bd2c0(void* self_ecx, uint32_t* param_1)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    int* piVar1;
    int iVar2;
    uint32_t* puVar3;
    int iVar4;
    puVar3 = *reinterpret_cast<uint32_t**>(self + 0x4c);
    if (puVar3 != param_1) {
        if (puVar3 != nullptr) {
            piVar1 = reinterpret_cast<int*>(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using fn_type = void(*)(int);
                fn_type fn = *reinterpret_cast<fn_type*>(*puVar3);
                fn(1);
            }
        }
        *reinterpret_cast<uint32_t**>(self + 0x4c) = param_1;
        if (param_1 == nullptr) {
            return;
        }
        param_1[1] = param_1[1] + 1;
    }
    if (param_1 != nullptr) {
        iVar2 = *reinterpret_cast<int*>(self + 0x4c);
        if (iVar2 == 0) {
            iVar4 = 0;
            puVar3 = nullptr;
        } else {
            iVar4 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x0c);
            puVar3 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x10);
        }
        *reinterpret_cast<uint32_t*>(self + 0x18) = *puVar3;
        *reinterpret_cast<uint32_t*>(self + 0x1c) =
            *reinterpret_cast<uint32_t*>(
                static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(
                    reinterpret_cast<uint8_t*>(puVar3) + 4)) * (iVar4 - 1) +
                reinterpret_cast<intptr_t>(puVar3));
    }
    return;
}

// 0x5bd390 — observed shape
int FUN_005bd390(int param_1, int param_2, int param_3)
{
    uint32_t* puVar1;
    int iVar2;
    uint32_t uVar3;
    int* piVar4;
    int iVar5;
    uint32_t uStack_c = 0;
    uint32_t uStack_8 = 0;
    uint32_t* local_4 = nullptr;
    piVar4 = FUN_00538580(&local_4);
    puVar1 = reinterpret_cast<uint32_t*>(*piVar4);
    if (puVar1 != nullptr) {
        puVar1[1] = puVar1[1] + 1;
    }
    if ((local_4 != nullptr) &&
        (iVar2 = static_cast<int>(local_4[1]), local_4[1] = static_cast<uint32_t>(iVar2 - 1), iVar2 - 1 == 0)) {
        using fn_type = void(*)(int);
        fn_type fn = *reinterpret_cast<fn_type*>(*local_4);
        fn(1);
    }
    iVar5 = FUN_00538680();
    FUN_00552ef0(iVar5, param_1, param_2, param_3);
    FUN_005bd2c0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar5)), puVar1);
    uStack_8 = 0;
    uStack_c = 0;
    iVar2 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x4c);
    if (iVar2 != 0) {
        uVar3 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14);
        if (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x0c) != 0) {
            FUN_00576320(0, static_cast<int>(uVar3),
                         *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x10),
                         *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x0c),
                         param_1, param_2, &uStack_c, &uStack_8);
            FUN_005bd1d0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar5)), static_cast<int>(uStack_8),
                         &uStack_c, uVar3);
        }
    }
    if (puVar1 != nullptr) {
        piVar4 = reinterpret_cast<int*>(puVar1 + 1);
        *piVar4 = *piVar4 + -1;
        if (*piVar4 == 0) {
            using fn_type = void(*)(int);
            fn_type fn = *reinterpret_cast<fn_type*>(*puVar1);
            fn(1);
        }
    }
    return iVar5;
}

// 0x5bd460 — observed shape
void FUN_005bd460(void* self_ecx, int param_1, int param_2)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    uint32_t* uVar1;
    FUN_00582080(param_1, param_2);
    if (*reinterpret_cast<int**>(self + 0x4c) != nullptr) {
        int* inner = *reinterpret_cast<int**>(self + 0x4c);
        using fn_type = uint32_t*(*)(int);
        fn_type fn = *reinterpret_cast<fn_type*>(reinterpret_cast<uint8_t*>(inner) + 8);
        uVar1 = fn(param_2);
        FUN_005bd2c0(self_ecx, uVar1);
    }
    return;
}

// 0x5bd490 — observed shape
void FUN_005bd490(void* self_ecx, int param_1)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    uint32_t uVar1;
    int iVar2;
    iVar2 = param_1;
    FUN_005ae9c0(param_1);
    param_1 = FUN_00557b10(DAT_00728ce8);
    uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x0c);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x08) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14) +
                     static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &param_1);
    {
        int* inner = *reinterpret_cast<int**>(self + 0x4c);
        using fn_type = void(*)(int);
        fn_type fn = *reinterpret_cast<fn_type*>(reinterpret_cast<uint8_t*>(inner) + 0x20);
        fn(iVar2);
    }
    return;
}

// 0x5bd4f0 — observed shape
void FUN_005bd4f0(void* self_ecx)
{
    uint32_t* self = static_cast<uint32_t*>(self_ecx);
    uint8_t* bytes = static_cast<uint8_t*>(self_ecx);
    *self = static_cast<uint32_t>(DAT_00727430);
    self[1] = static_cast<uint32_t>(DAT_00727434);
    self[2] = static_cast<uint32_t>(DAT_00727438);
    self[3] = static_cast<uint32_t>(DAT_007177ac);
    self[4] = static_cast<uint32_t>(DAT_007177b0);
    self[5] = static_cast<uint32_t>(DAT_007177b4);
    self[6] = 0;
    self[7] = 0;
    self[8] = 0;
    *reinterpret_cast<uint16_t*>(bytes + 0x24) = 0;
    *reinterpret_cast<uint16_t*>(bytes + 0x26) = 0;
    return;
}

// 0x5bd540 — observed shape
void FUN_005bd540(void* self_ecx, int param_1)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    int* reader_vt;
    FUN_00535110(param_1);
    FUN_00535110(param_1);
    reader_vt = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x15c);
    {
        using fn_type = void(*)(void*, int);
        fn_type fn = *reinterpret_cast<fn_type*>(reinterpret_cast<uint8_t*>(reader_vt) + 8);
        fn(self + 0x18, 4);
        fn(self + 0x1c, 4);
        fn(self + 0x20, 4);
        fn(self + 0x24, 2);
        fn(self + 0x26, 2);
    }
    return;
}

// 0x5bd5c0 — observed shape
void FUN_005bd5c0(void* self_ecx, int param_1)
{
    uint8_t* self = static_cast<uint8_t*>(self_ecx);
    int* writer_vt;
    FUN_00535150(param_1);
    FUN_00535150(param_1);
    writer_vt = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x160);
    {
        using fn_type = void(*)(void*, int);
        fn_type fn = *reinterpret_cast<fn_type*>(reinterpret_cast<uint8_t*>(writer_vt) + 0x0c);
        fn(self + 0x18, 4);
        fn(self + 0x1c, 4);
        fn(self + 0x20, 4);
        fn(self + 0x24, 2);
        fn(self + 0x26, 2);
    }
    return;
}
