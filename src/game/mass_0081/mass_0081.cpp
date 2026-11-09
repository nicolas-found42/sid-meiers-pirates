// Reconstruction batch mass_0081 — Sid Meier's Pirates! (2004) PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers referenced by the corpus listings
extern int FUN_00517f90();
extern void *FUN_00533c78(std::size_t n);
extern void operator_delete__(void *p);
extern void operator_delete(void *p) noexcept;
extern void *thunk_FUN_00533c78(std::size_t n);

// 0x5009f0 — D3D9 probe: LoadLibraryA + Direct3DCreate9(0x20); vtable+0x38 unknown adapter check, +0x14 adapter info, vendor/device checks (0x8086, 0x2582/0x2782/0x2572/0x3582/0x2562/0x3577); returns 3 (block) / 1 (no 0x10000 flag)
int FUN_005009f0() {
    HMODULE hModule = LoadLibraryA("D3D9.DLL");
    FARPROC pFVar1 = GetProcAddress(hModule, "Direct3DCreate9");
    int *piVar2 = (int*)(*reinterpret_cast<int(**)(int)>(reinterpret_cast<int*>(&pFVar1)))(0x20);
    unsigned char auStack_57a[6];
    uint32_t uStack_574 = 0;
    unsigned char auStack_460[1048];
    int iStack_48 = 0;
    int iStack_44 = 0;
    // piVar2 vtable calls: +0x38 unknown adapter check, +0x14 adapter info, +8 release
    using CreateFn = int (*)(int*, int, int, void*);
    auto *vtable = *reinterpret_cast<int**>(piVar2);
    int iVar3 = reinterpret_cast<CreateFn>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 0x38))(piVar2, 0, 1, auStack_57a - 6);
    if (iVar3 != 0) {
        reinterpret_cast<void(*)(int*)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 8))(piVar2);
        FreeLibrary(hModule);
        return 3;
    }
    if ((uStack_574 & 0x10000) != 0) {
        reinterpret_cast<void(*)(int*)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 8))(piVar2);
        FreeLibrary(hModule);
        return 1;
    }
    iVar3 = reinterpret_cast<CreateFn>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 0x14))(piVar2, 0, 0, auStack_460);
    if (iVar3 == 0) {
        if ((iStack_48 == 0x8086) &&
            (((iStack_44 == 0x2582 || (iStack_44 == 0x2782)) || (iStack_44 == 0x2572)) ||
             (((iStack_44 == 0x3582 || (iStack_44 == 0x2562)) || (iStack_44 == 0x3577))))) {
            reinterpret_cast<void(*)(int*)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 8))(piVar2);
            FreeLibrary(hModule);
            return 3;
        }
        reinterpret_cast<void(*)(int*)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 8))(piVar2);
    } else {
        reinterpret_cast<void(*)(int*)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 8))(piVar2);
    }
    FreeLibrary(hModule);
    return 3;
}

// 0x500b10 — vtable reset + child list teardown: self[0]=PTR_FUN_00710ac8; release each entry via vtable+8; zero self[3,1,2]; self[0]=PTR_LAB_00710b3c
void FUN_00500b10(void *self_) {
    int *in_ECX = static_cast<int*>(self_);
    in_ECX[0] = reinterpret_cast<int>(static_cast<void*>(&PTR_FUN_00710ac8));
    int *puVar2 = reinterpret_cast<int*>(in_ECX[1]);
    while (puVar2 != nullptr) {
        int *puVar1 = reinterpret_cast<int*>(*puVar2);
        auto *vtable = reinterpret_cast<int*>(*in_ECX);
        reinterpret_cast<void(*)(int*)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 8))(puVar2);
        puVar2 = puVar1;
    }
    in_ECX[3] = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[0] = reinterpret_cast<int>(static_cast<void*>(&PTR_LAB_00710b3c));
}

// 0x500b50 — search self+4 list for node with node[2]==*EBX; if found call FUN_00517f90(), else return *EBX
int FUN_00500b50(void *self_, int *ebx_value) {
    int *self = static_cast<int*>(self_);
    int *piVar3 = nullptr;
    if (reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 4)) != nullptr) {
        piVar3 = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 4);
        do {
            int *piVar1 = reinterpret_cast<int*>(*piVar3);
            if (*ebx_value == piVar3[2]) goto LAB_00500b74;
            piVar3 = piVar1;
        } while (piVar1 != nullptr);
    }
    piVar3 = nullptr;
LAB_00500b74:
    if (piVar3 == nullptr) {
        return *ebx_value;
    }
    int iVar2 = FUN_00517f90();
    return iVar2;
}

// 0x500bf0 — replace global DAT_00728de8 with copy of param_1 (skipped if param_1 empty string)
void FUN_00500bf0(char *param_1) {
    operator_delete__(DAT_00728de8);
    DAT_00728de8 = nullptr;
    if (param_1 != nullptr) {
        int iVar3 = 1;
        bool bVar5 = true;
        char *pcVar2 = param_1;
        const char *pcVar4 = "";
        do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 - 1;
            bVar5 = *pcVar2 == *pcVar4;
            pcVar2 = pcVar2 + 1;
            pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (!bVar5) {
            pcVar2 = param_1;
            char cVar1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            DAT_00728de8 = thunk_FUN_00533c78(static_cast<std::size_t>(pcVar2 - param_1 + 1));
            std::ptrdiff_t iVar3b = static_cast<char*>(DAT_00728de8) - param_1;
            do {
                cVar1 = *param_1;
                param_1[iVar3b] = cVar1;
                param_1 = param_1 + 1;
            } while (cVar1 != '\0');
        }
    }
}

// 0x500c60 — delete globals DAT_008cad40/44/48/70/64 and null them
void FUN_00500c60() {
    if (DAT_008cad40 != nullptr) {
        operator_delete(DAT_008cad40);
        DAT_008cad40 = nullptr;
    }
    if (DAT_008cad44 != nullptr) {
        operator_delete(DAT_008cad44);
        DAT_008cad44 = nullptr;
    }
    if (DAT_008cad48 != nullptr) {
        operator_delete(DAT_008cad48);
        DAT_008cad48 = nullptr;
    }
    if (DAT_008cad70 != nullptr) {
        operator_delete(DAT_008cad70);
        DAT_008cad70 = nullptr;
    }
    if (DAT_008cad64 != nullptr) {
        operator_delete(DAT_008cad64);
        DAT_008cad64 = nullptr;
    }
}

// 0x500ce0 — construct EDI object: alloc 0x80 -> FUN_005202b0, alloc 0x238 -> FUN_004ff360(0x42340000); store retaddr at +2, AL at +4; if AL!=0 set +3=param_1 and call vtable+0x10/+0xc; then 0x44 refcount dance around FUN_004ff450, FUN_00533db0(0xb) with flag clear at +0x20 (0xfd), scale ABS(fVar(param_2+0x13c)*self[2]) at +0x1a, FUN_00534350, FUN_00534130, FUN_00533d10(0,1); finish FUN_004cce40, FUN_004ff6b0(0x3f800000)
void FUN_00500ce0(void *self_, int param_1, int param_2, unsigned char in_AL, int unaff_retaddr) {
    int *unaff_EDI = static_cast<int*>(self_);
    float fVar1, fVar2;
    *unaff_EDI = 0;
    unaff_EDI[1] = param_2;
    int iVar4 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x80)));
    int *piVar5 = (iVar4 == 0) ? nullptr : reinterpret_cast<int*>(FUN_005202b0());
    unaff_EDI[5] = reinterpret_cast<int>(piVar5);
    auto *vtable = *reinterpret_cast<int**>(piVar5);
    reinterpret_cast<void(*)(int*,int,int,int)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(vtable) + 8))(piVar5, param_1, 0, 0);
    iVar4 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x238)));
    int *puVar6 = (iVar4 == 0) ? nullptr : reinterpret_cast<int*>(FUN_004ff360(0x42340000));
    int *puVar3 = reinterpret_cast<int*>(*unaff_EDI);
    if (puVar3 != puVar6) {
        if (puVar3 != nullptr) {
            int *piVar5b = puVar3 + 1;
            *piVar5b = *piVar5b - 1;
            if (*piVar5b == 0) reinterpret_cast<void(*)(int*,int)>(*puVar3)(puVar3, 1);
        }
        *unaff_EDI = reinterpret_cast<int>(puVar6);
        if (puVar6 != nullptr) puVar6[1] = puVar6[1] + 1;
    }
    unaff_EDI[2] = unaff_retaddr;
    *(char*)(unaff_EDI + 4) = static_cast<char>(in_AL);
    if (in_AL != '\0') {
        unaff_EDI[3] = param_1;
        auto *v5 = *reinterpret_cast<int**>(unaff_EDI[5]);
        reinterpret_cast<void(*)(int*,int,int,int)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(v5) + 0x10))(reinterpret_cast<int*>(*unaff_EDI), 0, 0, param_1);
        reinterpret_cast<void(*)(int*,int)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(v5) + 0xc))(reinterpret_cast<int*>(*unaff_EDI), 0);
    }
    auto refcall = [](int *p, auto fn) {
        if (p) { p[1] = p[1] + 1; fn(); int *q = p + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*p)(p, 1); }
    };
    int *tmp;
    tmp = *reinterpret_cast<int**>(reinterpret_cast<char*>(*unaff_EDI) + 0x44);
    if (tmp) { tmp[1] = tmp[1] + 1; FUN_004ff450(); int *q = tmp + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*tmp)(tmp, 1); }
    tmp = *reinterpret_cast<int**>(reinterpret_cast<char*>(*unaff_EDI) + 0x44);
    if (tmp) { tmp[1] = tmp[1] + 1; iVar4 = FUN_00533db0(0xb); int *q = tmp + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*tmp)(tmp, 1); }
    *(unsigned char*)(iVar4 + 0x20) = static_cast<unsigned char>(*(unsigned char*)(iVar4 + 0x20) & 0xfd);
    fVar1 = *(float*)(param_2 + 0x13c);
    fVar2 = static_cast<float>(unaff_EDI[2]);
    tmp = *reinterpret_cast<int**>(reinterpret_cast<char*>(*unaff_EDI) + 0x44);
    if (tmp) tmp[1] = tmp[1] + 1;
    tmp[0x1a] = *reinterpret_cast<int*>(&tmp[0x1a]); // placeholder replaced below
    // store float ABS into word at +0x1a
    float fAbs = (fVar1 * fVar2) < 0 ? -(fVar1 * fVar2) : (fVar1 * fVar2);
    *reinterpret_cast<float*>(&tmp[0x1a]) = fAbs;
    { int *q = tmp + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*tmp)(tmp, 1); }
    tmp = *reinterpret_cast<int**>(reinterpret_cast<char*>(*unaff_EDI) + 0x44);
    if (tmp) { tmp[1] = tmp[1] + 1; FUN_00534350(); int *q = tmp + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*tmp)(tmp, 1); }
    tmp = *reinterpret_cast<int**>(reinterpret_cast<char*>(*unaff_EDI) + 0x44);
    if (tmp) { tmp[1] = tmp[1] + 1; FUN_00534130(); int *q = tmp + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*tmp)(tmp, 1); }
    tmp = *reinterpret_cast<int**>(reinterpret_cast<char*>(*unaff_EDI) + 0x44);
    if (tmp) { tmp[1] = tmp[1] + 1; FUN_00533d10(0, 1); int *q = tmp + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*tmp)(tmp, 1); }
    FUN_004cce40();
    FUN_004ff6b0(0x3f800000);
}

// 0x500ea0 — EBX object refcount swap: release *EBX then take *(EBX[5]+0x44) ref, release chain, if puVar1[9]!=0 do vtable+0x74 call; final release EBX[5] via vtable[0] and *EBX
void FUN_00500ea0(void *self_) {
    int *unaff_EBX = static_cast<int*>(self_);
    int *puVar1 = reinterpret_cast<int*>(*unaff_EBX);
    if (puVar1 != nullptr) {
        int *piVar5 = puVar1 + 1;
        *piVar5 = *piVar5 - 1;
        if (*piVar5 == 0) reinterpret_cast<void(*)(int*,int)>(*puVar1)(puVar1, 1);
        *unaff_EBX = 0;
    }
    puVar1 = *reinterpret_cast<int**>(unaff_EBX[5] + 0x44);
    if (puVar1 != nullptr) puVar1[1] = puVar1[1] + 1;
    int iVar2 = puVar1[1];
    int iVar3 = puVar1[9];
    puVar1[1] = iVar2 - 1;
    if (iVar2 - 1 == 0) reinterpret_cast<void(*)(int*,int)>(*puVar1)(puVar1, 1);
    if (iVar3 != 0) {
        puVar1 = *reinterpret_cast<int**>(unaff_EBX[5] + 0x44);
        if (puVar1 != nullptr) puVar1[1] = puVar1[1] + 1;
        int *puVar4 = *reinterpret_cast<int**>(unaff_EBX[5] + 0x44);
        int *piVar5 = reinterpret_cast<int*>(puVar1[9]);
        if (puVar4 != nullptr) puVar4[1] = puVar4[1] + 1;
        int *puStack_4 = nullptr;
        reinterpret_cast<void(*)(int*,int*)>(*reinterpret_cast<int*>(reinterpret_cast<char*>(*piVar5) + 0x74))(&puStack_4, puVar4);
        if ((puStack_4 != nullptr) && ((iVar2 = puStack_4[1], puStack_4[1] = iVar2 - 1, iVar2 - 1 == 0))) {
            reinterpret_cast<void(*)(int*,int)>(*puStack_4)(puStack_4, 1);
        }
        piVar5 = puVar1 + 1;
        *piVar5 = *piVar5 - 1;
        if (*piVar5 == 0) reinterpret_cast<void(*)(int*,int)>(*puVar1)(puVar1, 1);
        if (puVar4 != nullptr) {
            piVar5 = puVar4 + 1;
            *piVar5 = *piVar5 - 1;
            if (*piVar5 == 0) reinterpret_cast<void(*)(int*,int)>(*puVar4)(puVar4, 1);
        }
    }
    if (reinterpret_cast<int*>(unaff_EBX[5]) != nullptr) {
        reinterpret_cast<void(*)(int*,int)>(*reinterpret_cast<int*>(unaff_EBX[5]))(reinterpret_cast<int*>(unaff_EBX[5]), 1);
        unaff_EBX[5] = 0;
    }
    puVar1 = reinterpret_cast<int*>(*unaff_EBX);
    if (puVar1 != nullptr) {
        int *piVar5 = puVar1 + 1;
        *piVar5 = *piVar5 - 1;
        if (*piVar5 == 0) reinterpret_cast<void(*)(int*,int)>(*puVar1)(puVar1, 1);
    }
}

// 0x500f70 — EDI object: if *(EDI+0x14)!=0 && EAX!=0 call vtable+8, then 0x44 dance around FUN_004ff450, FUN_00533db0(0xb) with flag clear at +0x20 (0xfd), FUN_00534350, FUN_00534130; finally *(EDI+8)=0
void FUN_00500f70(void *self_, int in_EAX) {
    int unaff_EDI = reinterpret_cast<int>(self_);
    if ((*(int**)(unaff_EDI + 0x14) != nullptr) && (in_EAX != 0)) {
        reinterpret_cast<void(*)()>(**reinterpret_cast<int**>(unaff_EDI + 0x14) + 8)();
        int *puVar2 = *reinterpret_cast<int**>(*(int*)(unaff_EDI + 0x14) + 0x44);
        if (puVar2) puVar2[1] = puVar2[1] + 1;
        FUN_004ff450();
        if (puVar2) { int *q = puVar2 + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*puVar2)(puVar2, 1); }
        puVar2 = *reinterpret_cast<int**>(*(int*)(unaff_EDI + 0x14) + 0x44);
        if (puVar2) puVar2[1] = puVar2[1] + 1;
        int iVar3 = FUN_00533db0(0xb);
        if (puVar2) { int *q = puVar2 + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*puVar2)(puVar2, 1); }
        *(unsigned char*)(iVar3 + 0x20) = static_cast<unsigned char>(*(unsigned char*)(iVar3 + 0x20) & 0xfd);
        puVar2 = *reinterpret_cast<int**>(*(int*)(unaff_EDI + 0x14) + 0x44);
        if (puVar2) puVar2[1] = puVar2[1] + 1;
        FUN_00534350();
        if (puVar2) { int *q = puVar2 + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*puVar2)(puVar2, 1); }
        puVar2 = *reinterpret_cast<int**>(*(int*)(unaff_EDI + 0x14) + 0x44);
        if (puVar2) puVar2[1] = puVar2[1] + 1;
        FUN_00534130();
        if (puVar2) { int *q = puVar2 + 1; *q = *q - 1; if (*q == 0) reinterpret_cast<void(*)(int*,int)>(*puVar2)(puVar2, 1); }
        *(int*)(unaff_EDI + 8) = 0;
    }
}

// 0x501040 — param_1[5]+0x44 ref dance: store ABS(f*(param_1[1]+0x13c)*(float)param_1[2]) at +0x1a; FUN_00533d10(0,1); copy 9 words from (param_1[1]+0x6c) to (*param_1+0x38); if (char)param_1[4]==0 branch copying +100 else param_1[3] to +100 with +0x5c/+0x60 zeroed; FUN_004ff6b0(0); vtable(*param_1)+0x70 call
void FUN_00501040(int *param_1) {
    FUN_004cce40();
    int *puVar7 = *reinterpret_cast<int**>(param_1[5] + 0x44);
    float fVar2 = *(float*)(param_1[1] + 0x13c);
    float fVar3 = static_cast<float>(param_1[2]);
    if (puVar7) puVar7[1] = puVar7[1] + 1;
    float fAbs = (fVar2 * fVar3) < 0 ? -(fVar2 * fVar3) : (fVar2 * fVar3);
    *reinterpret_cast<float*>(&puVar7[0x1a]) = fAbs;
    int *piVar1 = puVar7 + 1;
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) reinterpret_cast<void(*)(int*,int)>(*puVar7)(puVar7, 1);
    puVar7 = *reinterpret_cast<int**>(param_1[5] + 0x44);
    if (puVar7) puVar7[1] = puVar7[1] + 1;
    FUN_00533d10(0, 1);
    if (puVar7) { piVar1 = puVar7 + 1; *piVar1 = *piVar1 - 1; if (*piVar1 == 0) reinterpret_cast<void(*)(int*,int)>(*puVar7)(puVar7, 1); }
    int *puSrc = reinterpret_cast<int*>(param_1[1] + 0x6c);
    int *puDst = reinterpret_cast<int*>(*param_1 + 0x38);
    for (int iVar6 = 9; iVar6 != 0; iVar6 = iVar6 - 1) { *puDst = *puSrc; puSrc = puSrc + 1; puDst = puDst + 1; }
    if (static_cast<char>(param_1[4]) == '\0') {
        int uVar5 = *(int*)(param_1[1] + 100);
        int iVar6 = *param_1;
        *(int*)(iVar6 + 0x5c) = 0;
        *(int*)(iVar6 + 0x60) = 0;
        *(int*)(iVar6 + 100) = uVar5;
    } else {
        int iVar6 = param_1[3];
        int iVar4 = *param_1;
        *(int*)(iVar4 + 0x5c) = 0;
        *(int*)(iVar4 + 0x60) = 0;
        *(int*)(iVar4 + 100) = iVar6;
    }
    FUN_004ff6b0(0);
    reinterpret_cast<void(*)()>(*reinterpret_cast<int*>(*param_1) + 0x70)();
}

// 0x501140 — recursive search param_1 subtree for param_2 via child list (vtable+4 chain), type markers &DAT_007273fc / &DAT_007275d8 / &DAT_00727560 with FUN_00449390 lookups, returns found node or null
int *FUN_00501140(int *param_1, int param_2) {
    int iVar3 = reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1);
    for (; iVar3 != 0; iVar3 = *(int*)(iVar3 + 4)) {
        if (iVar3 == param_2) return param_1;
    }
    int *puVar4 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
    while (true) {
        if (puVar4 == nullptr) goto LAB_005011c2;
        if (puVar4 == reinterpret_cast<int*>(&DAT_007273fc)) break;
        puVar4 = reinterpret_cast<int*>(puVar4[1]);
    }
    iVar3 = FUN_00449390(reinterpret_cast<int*>(&DAT_007273fc), param_1);
    puVar4 = *reinterpret_cast<int**>(iVar3 + 0xa4);
    while (puVar4 != nullptr) {
        int *puVar1 = puVar4 + 2;
        puVar4 = reinterpret_cast<int*>(*puVar4);
        int *piVar5 = FUN_00501140(*puVar1, param_2);
        if (piVar5 != nullptr) return piVar5;
    }
LAB_005011c2:;
    puVar4 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
    while (true) {
        if (puVar4 == nullptr) goto LAB_00501210;
        if (puVar4 == reinterpret_cast<int*>(&DAT_007275d8)) break;
        puVar4 = reinterpret_cast<int*>(puVar4[1]);
    }
    iVar3 = FUN_00449390(reinterpret_cast<int*>(&DAT_007275d8), param_1);
    for (iVar3 = *(int*)(iVar3 + 0x10); iVar3 != 0; iVar3 = *(int*)(iVar3 + 0x38)) {
        int *piVar5 = FUN_00501140(reinterpret_cast<int*>(iVar3), param_2);
        if (piVar5 != nullptr) return piVar5;
    }
LAB_00501210:;
    puVar4 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
    if (puVar4 == nullptr) return nullptr;
    while (puVar4 != reinterpret_cast<int*>(&DAT_00727560)) {
        puVar4 = reinterpret_cast<int*>(puVar4[1]);
        if (puVar4 == nullptr) return nullptr;
    }
    iVar3 = FUN_00449390(reinterpret_cast<int*>(&DAT_00727560), param_1);
    puVar4 = *reinterpret_cast<int**>(iVar3 + 0xd0);
    do {
        int *piVar5 = nullptr;
        if (puVar4 == nullptr) {
            unsigned uVar6 = 0;
            if (*(int*)(iVar3 + 0xc0) == 0) return nullptr;
            if (*(int*)(iVar3 + 0xc0) == 0) goto LAB_00501298;
            while (((iVar3 = *(int*)(*(int*)(iVar3 + 0xb8) + uVar6 * 4), iVar3 == 0) || ((piVar5 = FUN_00501140(reinterpret_cast<int*>(iVar3), param_2), piVar5 == nullptr))) {
            LAB_00501298:
                uVar6 = uVar6 + 1;
                if (*(uint*)(iVar3 + 0xc0) <= uVar6) return piVar5;
            }
            return piVar5;
        }
        int *puVar1 = puVar4 + 2;
        puVar4 = reinterpret_cast<int*>(*puVar4);
        piVar5 = FUN_00501140(*puVar1, param_2);
    } while (piVar5 == nullptr);
    return piVar5;
}

// 0x5012b0 — if child list contains &DAT_00727598 delegate to FUN_00547730; else if &DAT_00727560 present recurse over param_3[0x2e] array (count param_3[0x30]) AND-ing results; default 1
unsigned char FUN_005012b0(int param_1, int param_2, int *param_3) {
    unsigned char bVar2 = 1;
    unsigned char local_4 = 1;
    if (param_3 != nullptr) {
        int *puVar4 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_3) + 4)(param_3));
        for (; puVar4 != nullptr; puVar4 = reinterpret_cast<int*>(puVar4[1])) {
            if (puVar4 == reinterpret_cast<int*>(&DAT_00727598)) {
                bVar2 = FUN_00547730(param_3, param_1, param_2);
                return bVar2;
            }
        }
        puVar4 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_3) + 4)(param_3));
        if (puVar4 != nullptr) {
            while (puVar4 != reinterpret_cast<int*>(&DAT_00727560)) {
                puVar4 = reinterpret_cast<int*>(puVar4[1]);
                if (puVar4 == nullptr) return 1;
            }
            uint32_t uVar5 = 0;
            bVar2 = 1;
            if (param_3[0x30] != 0) {
                bVar2 = 1;
                if (param_3[0x30] == 0) goto LAB_0050135d;
                do {
                    int iVar1 = *(int*)(param_3[0x2e] + uVar5 * 4);
                    if (iVar1 != 0) {
                        char cVar3 = static_cast<char>(FUN_005012b0(param_1, param_2, reinterpret_cast<int*>(iVar1)));
                        bVar2 = static_cast<unsigned char>(-((cVar3 != '\0') ? 1 : 0) & local_4);
                        local_4 = bVar2;
                    }
                LAB_0050135d:
                    uVar5 = uVar5 + 1;
                } while (uVar5 < static_cast<uint32_t>(param_3[0x30]));
            }
        }
    }
    return bVar2;
}

// 0x501370 — byte* compare via FUN_005dbd60 against param_1, check FUN_005dbd70()==param_2 then FUN_00547760; else recurse type-0x7560 children AND-ing; defaults 1
unsigned char FUN_00501370(unsigned char *param_1, int param_2, int *param_3) {
    unsigned char bVar1 = 1;
    unsigned char local_4 = 1;
    if (param_3 == nullptr) return 1;
    int *puVar3 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_3) + 4)(param_3));
    while (true) {
        if (puVar3 == nullptr) {
            puVar3 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_3) + 4)(param_3));
            if (puVar3 == nullptr) return 1;
            while (puVar3 != reinterpret_cast<int*>(&DAT_00727560)) {
                puVar3 = reinterpret_cast<int*>(puVar3[1]);
                if (puVar3 == nullptr) return 1;
            }
            uint32_t uVar7 = 0;
            if (param_3[0x30] == 0) return 1;
            if (param_3[0x30] == 0) goto LAB_0050147c;
            do {
                int iVar4 = *(int*)(param_3[0x2e] + uVar7 * 4);
                if (iVar4 != 0) {
                    char cVar2 = static_cast<char>(FUN_00501370(param_1, param_2, reinterpret_cast<int*>(iVar4)));
                    bVar1 = static_cast<unsigned char>(-((cVar2 != '\0') ? 1 : 0) & local_4);
                    local_4 = bVar1;
                }
            LAB_0050147c:
                uVar7 = uVar7 + 1;
            } while (uVar7 < static_cast<uint32_t>(param_3[0x30]));
            return bVar1;
        }
        if (puVar3 == reinterpret_cast<int*>(&DAT_00727598)) break;
        puVar3 = reinterpret_cast<int*>(puVar3[1]);
    }
    int iVar4 = FUN_00449390(reinterpret_cast<int*>(&DAT_00727598), param_3);
    if (*(int*)(iVar4 + 200) == 0) return 1;
    unsigned char *pbVar5 = FUN_005dbd60();
    int iVar6;
    unsigned char bVar8_;
    do {
        bVar1 = *pbVar5;
        bVar8_ = static_cast<unsigned char>(bVar1 < *param_1);
        if (bVar1 != *param_1) {
        LAB_00501417:
            iVar6 = static_cast<int>(1 - static_cast<uint32_t>(bVar8_)) - static_cast<uint32_t>(bVar8_ != 0);
            goto LAB_0050141c;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar8_ = static_cast<unsigned char>(bVar1 < param_1[1]);
        if (bVar1 != param_1[1]) goto LAB_00501417;
        pbVar5 = pbVar5 + 2;
        param_1 = param_1 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_0050141c:
    if ((iVar6 == 0) && ((iVar6 = FUN_005dbd70()), iVar6 == param_2)) {
        bVar1 = FUN_00547760(iVar4);
        return bVar1;
    }
    return 1;
}

// 0x501490 — clear param_2 backing: if type 0x7560 present recurse children first; then if child-chain contains param_3: if param_4==0 FUN_00533db0 + maybe FUN_004aac10; else FUN_00534a90 + FUN_004aac50 ref dance
void FUN_00501490(int *param_1, int *param_2, int param_3, int param_4, char param_5) {
    int iVar6 = param_3;
    int *piVar2 = param_2;
    int *piVar1 = param_1;
    if (param_1 != nullptr) {
        int *puVar3 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
        for (; puVar3 != nullptr; puVar3 = reinterpret_cast<int*>(puVar3[1])) {
            if (puVar3 == reinterpret_cast<int*>(&DAT_00727560)) {
                uint32_t uVar7 = 0;
                if (piVar1[0x30] != 0) {
                    if (piVar1[0x30] == 0) goto LAB_005014ef;
                    do {
                        int iVar4 = *(int*)(piVar1[0x2e] + uVar7 * 4);
                        if (iVar4 != 0) FUN_00501490(reinterpret_cast<int*>(iVar4), piVar2, iVar6, param_4, 1);
                    LAB_005014ef:
                        uVar7 = uVar7 + 1;
                    } while (uVar7 < static_cast<uint32_t>(piVar1[0x30]));
                }
                break;
            }
        }
    }
    int iVar4 = reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*piVar1) + 4)(piVar1);
    if (iVar4 != 0) {
        while (iVar4 != iVar6) {
            iVar4 = *(int*)(iVar4 + 4);
            if (iVar4 == 0) return;
        }
        if (static_cast<char>(param_4) == '\0') {
            int uVar5 = reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*piVar2) + 0x34)(piVar2);
            iVar6 = FUN_00533db0(uVar5);
            if ((iVar6 == 0) && (param_5 != '\0')) FUN_004aac10(piVar2);
        } else {
            int uVar5 = reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*piVar2) + 0x34)(piVar2);
            iVar6 = FUN_00533db0(uVar5);
            if ((iVar6 != 0) || (param_5 != '\0')) {
                uVar5 = reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*piVar2) + 0x34)(piVar2);
                FUN_00534a90(&param_1, uVar5);
                if ((param_1 != nullptr) && ((iVar6 = param_1[1], param_1[1] = iVar6 - 1, iVar6 - 1 == 0))) {
                    reinterpret_cast<void(*)(int*,int)>(*param_1)(param_1, 1);
                }
                param_1 = piVar2;
                piVar2[1] = piVar2[1] + 1;
                FUN_004aac50(&param_1);
                int *q = piVar2 + 1;
                *q = *q - 1;
                if (*q == 0) { reinterpret_cast<void(*)(int*,int)>(*piVar2)(piVar2, 1); return; }
            }
        }
    }
}

// 0x5015e0 — max float in subtree: start -3.4028235e+38; recurse 0x7560 children, scan param_1[0x29] list (*[+0x10] chain, +0x1c floats) and param_1[4] chain (+0x1c); return max as float10
long double FUN_005015e0(int *param_1) {
    float local_4 = -3.4028235e+38f;
    if (param_1 != nullptr) {
        int *puVar3 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
        for (; puVar3 != nullptr; puVar3 = reinterpret_cast<int*>(puVar3[1])) {
            if (puVar3 == reinterpret_cast<int*>(&DAT_00727560)) {
                int iVar4 = FUN_00449390(reinterpret_cast<int*>(&DAT_00727560), param_1);
                uint32_t uVar5 = 0;
                if (*(int*)(iVar4 + 0xc0) != 0) {
                    if (*(int*)(iVar4 + 0xc0) == 0) goto LAB_0050165b;
                    do {
                        int iVar2 = *(int*)(*(int*)(iVar4 + 0xb8) + uVar5 * 4);
                        if ((iVar2 != 0) && ((static_cast<long double>(local_4) < FUN_005015e0(reinterpret_cast<int*>(iVar2))))) {
                            local_4 = static_cast<float>(FUN_005015e0(reinterpret_cast<int*>(iVar2)));
                        }
                    LAB_0050165b:
                        uVar5 = uVar5 + 1;
                    } while (uVar5 < *reinterpret_cast<uint32_t*>(iVar4 + 0xc0));
                }
                break;
            }
        }
    }
    int *puVar3b = reinterpret_cast<int*>(param_1[0x29]);
    while (puVar3b != nullptr) {
        int *piVar1 = puVar3b + 2;
        puVar3b = reinterpret_cast<int*>(*puVar3b);
        for (int iVar4 = *(int*)(*piVar1 + 0x10); iVar4 != 0; iVar4 = *(int*)(iVar4 + 0x38)) {
            if (local_4 < *(float*)(iVar4 + 0x1c)) local_4 = *(float*)(iVar4 + 0x1c);
        }
    }
    for (int iVar4 = param_1[4]; iVar4 != 0; iVar4 = *(int*)(iVar4 + 0x38)) {
        if (local_4 < *(float*)(iVar4 + 0x1c)) local_4 = *(float*)(iVar4 + 0x1c);
    }
    return static_cast<long double>(local_4);
}

// 0x5016d0 — recurse 0x7560 children then if 0x7598 present: flags at param_1[0x2f]+0x32 (mask 0xfff | param_2), +0x35/+0x34 guarded by -1, call (*DAT_008ea08c+0xa4)(param_1,0,...)
void FUN_005016d0(int *param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    if (param_1 != nullptr) {
        int *puVar2 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
        for (; puVar2 != nullptr; puVar2 = reinterpret_cast<int*>(puVar2[1])) {
            if (puVar2 == reinterpret_cast<int*>(&DAT_00727560)) {
                int iVar3 = FUN_00449390(reinterpret_cast<int*>(&DAT_00727560), param_1);
                uint32_t uVar4 = 0;
                if (*(int*)(iVar3 + 0xc0) != 0) {
                    if (*(int*)(iVar3 + 0xc0) == 0) goto LAB_00501752;
                    do {
                        int iVar1 = *(int*)(*(int*)(iVar3 + 0xb8) + uVar4 * 4);
                        if (iVar1 != 0) FUN_005016d0(reinterpret_cast<int*>(iVar1), param_2, param_3, param_4, param_5, param_6, param_7);
                    LAB_00501752:
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *reinterpret_cast<uint32_t*>(iVar3 + 0xc0));
                }
                break;
            }
        }
        puVar2 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
        if (puVar2 != nullptr) {
            while (puVar2 != reinterpret_cast<int*>(&DAT_00727598)) {
                puVar2 = reinterpret_cast<int*>(puVar2[1]);
                if (puVar2 == nullptr) return;
            }
            int iVar3 = param_1[0x2f];
            *(uint16_t*)(iVar3 + 0x32) = static_cast<uint16_t>((*(uint16_t*)(iVar3 + 0x32) & 0xfff) | static_cast<uint16_t>(param_2));
            if (param_3 != -1) *(char*)(iVar3 + 0x35) = static_cast<char>(param_3);
            if (param_4 != -1) *(char*)(iVar3 + 0x34) = static_cast<char>(param_4);
            reinterpret_cast<void(*)(int*,int,int,int,int)>(*reinterpret_cast<int*>(*DAT_008ea08c) + 0xa4)(param_1, 0, param_5, param_6, param_7);
        }
    }
}


// 0x5017e0 — mesh combine: call FUN_00501b40 twice, allocate puVar7/uVar21*0xc, puVar8/uVar21*0xc, puVar9/uVar21*8, puVar10/uVar22*2, local_28/uVar21<<4; concatenate +0x20 (pos) and +0x24 (nrm) arrays from EAX/param_1 +0xbc blocks; append FUN_005412c0(0) index pairs into puVar9; append +0x28 quads into local_28; copy +0x48 indices into puVar10 with +sVar3 bias; finish FUN_005473e0
int FUN_005017e0(int param_1) {
    int in_EAX = reinterpret_cast<int>(FUN_00501b40());
    FUN_00501b40();
    int iVar14 = *(int*)(in_EAX + 0xbc);
    int iVar17 = *(int*)(param_1 + 0xbc);
    int16_t sVar1 = *(int16_t*)(iVar17 + 0x3c);
    int16_t sVar2 = *(int16_t*)(iVar14 + 0x3c);
    uint32_t uVar21 = static_cast<uint16_t>(*(int16_t*)(iVar17 + 0xc) + *(int16_t*)(iVar14 + 0xc));
    int16_t sVar3 = *(int16_t*)(iVar14 + 0x40);
    uint16_t uVar22 = static_cast<uint16_t>((*(int16_t*)(iVar17 + 0x40) + *(int16_t*)(iVar14 + 0x40)) * 2 + 2 + *(int16_t*)(iVar17 + 0x3c) + *(int16_t*)(iVar14 + 0x3c));
    int16_t sVar4 = *(int16_t*)(iVar14 + 0x3c);
    int *puVar7 = reinterpret_cast<int*>(thunk_FUN_00533c78(uVar21 * 0xc));
    int *puVar8 = reinterpret_cast<int*>(thunk_FUN_00533c78(uVar21 * 0xc));
    int *puVar9 = reinterpret_cast<int*>(thunk_FUN_00533c78(uVar21 * 8));
    int *puVar10 = reinterpret_cast<int*>(thunk_FUN_00533c78(uVar22 * 2));
    int *local_28 = reinterpret_cast<int*>(thunk_FUN_00533c78(uVar21 << 4));
    if (local_28 == nullptr) {
        local_28 = nullptr;
    } else if (static_cast<int>(uVar21 - 1) >= 0) {
        int *puVar12 = local_28 + 2;
        uint32_t uVar18 = uVar21;
        do {
            puVar12[-2] = 0; puVar12[-1] = 0; *puVar12 = 0; puVar12[1] = 0;
            puVar12 = puVar12 + 4;
            uVar18 = uVar18 - 1;
        } while (uVar18 != 0);
    }
    uint16_t *puVar11 = reinterpret_cast<uint16_t*>(thunk_FUN_00533c78(2));
    int *puVar12 = *reinterpret_cast<int**>(*(int*)(in_EAX + 0xbc) + 0x20);
    int *puVar23 = puVar7;
    for (uint32_t uVar18 = static_cast<uint32_t>(*(uint16_t*)(*(int*)(in_EAX + 0xbc) + 0xc)) * 0xc >> 2; uVar18 != 0; uVar18 = uVar18 - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (int i = 0; i != 0; i = i - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    puVar12 = *reinterpret_cast<int**>(*(int*)(param_1 + 0xbc) + 0x20);
    puVar23 = puVar7 + static_cast<uint32_t>(*(uint16_t*)(*(int*)(in_EAX + 0xbc) + 0xc)) * 3;
    for (uint32_t uVar18 = static_cast<uint32_t>(*(uint16_t*)(*(int*)(param_1 + 0xbc) + 0xc)) * 0xc >> 2; uVar18 != 0; uVar18 = uVar18 - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (int i = 0; i != 0; i = i - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    puVar12 = *reinterpret_cast<int**>(*(int*)(in_EAX + 0xbc) + 0x24);
    puVar23 = puVar8;
    for (uint32_t uVar18 = static_cast<uint32_t>(*(uint16_t*)(*(int*)(in_EAX + 0xbc) + 0xc)) * 0xc >> 2; uVar18 != 0; uVar18 = uVar18 - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (int i = 0; i != 0; i = i - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    puVar12 = *reinterpret_cast<int**>(*(int*)(param_1 + 0xbc) + 0x24);
    puVar23 = puVar8 + static_cast<uint32_t>(*(uint16_t*)(*(int*)(in_EAX + 0xbc) + 0xc)) * 3;
    for (uint32_t uVar18 = static_cast<uint32_t>(*(uint16_t*)(*(int*)(param_1 + 0xbc) + 0xc)) * 0xc >> 2; uVar18 != 0; uVar18 = uVar18 - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (int i = 0; i != 0; i = i - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    uint32_t uVar5 = *(uint16_t*)(*(int*)(in_EAX + 0xbc) + 0xc);
    puVar12 = reinterpret_cast<int*>(FUN_005412c0(0));
    puVar23 = puVar9;
    for (int i = static_cast<int>(uVar5 << 1); i != 0; i = i - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (int i = 0; i != 0; i = i - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    uVar5 = *(uint16_t*)(*(int*)(param_1 + 0xbc) + 0xc);
    uint32_t uVar6 = *(uint16_t*)(*(int*)(in_EAX + 0xbc) + 0xc);
    puVar12 = reinterpret_cast<int*>(FUN_005412c0(0));
    puVar23 = puVar9 + uVar6 * 2;
    for (int i = static_cast<int>(uVar5 << 1); i != 0; i = i - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (int i = 0; i != 0; i = i - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    puVar12 = *reinterpret_cast<int**>(*(int*)(in_EAX + 0xbc) + 0x28);
    puVar23 = local_28;
    for (int i = static_cast<int>(static_cast<uint32_t>(*(uint16_t*)(*(int*)(in_EAX + 0xbc) + 0xc)) << 2); i != 0; i = i - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (int i = 0; i != 0; i = i - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    uint32_t uVar18b = static_cast<uint16_t>((sVar3 + 1) * 2 + sVar4);
    puVar12 = *reinterpret_cast<int**>(*(int*)(param_1 + 0xbc) + 0x28);
    puVar23 = local_28 + static_cast<uint32_t>(*(uint16_t*)(*(int*)(in_EAX + 0xbc) + 0xc)) * 4;
    for (int i = static_cast<int>(static_cast<uint32_t>(*(uint16_t*)(*(int*)(param_1 + 0xbc) + 0xc)) << 2); i != 0; i = i - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (int i = 0; i != 0; i = i - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    uint32_t uVar16 = uVar18b * 2 - 4;
    puVar12 = *reinterpret_cast<int**>(*(int*)(in_EAX + 0xbc) + 0x48);
    puVar23 = puVar10;
    for (uint32_t uVar15 = uVar16 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) { *puVar23 = *puVar12; puVar12 = puVar12 + 1; puVar23 = puVar23 + 1; }
    for (uint32_t r = uVar16 & 3; r != 0; r = r - 1) { *(unsigned char*)puVar23 = *(unsigned char*)puVar12; puVar12 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar12) + 1); puVar23 = reinterpret_cast<int*>(reinterpret_cast<char*>(puVar23) + 1); }
    int iVar14b = *(int*)(*(int*)(param_1 + 0xbc) + 0x48);
    int16_t sVar3b = *(int16_t*)(*(int*)(in_EAX + 0xbc) + 0xc);
    int iVar17b = static_cast<int>(uVar22) - static_cast<int>(uVar18b);
    int iVar19 = 0;
    if (iVar17b > 0) {
        int16_t *psVar20 = reinterpret_cast<int16_t*>(reinterpret_cast<char*>(puVar10) + uVar18b * 2);
        do {
            *psVar20 = static_cast<int16_t>(*(int16_t*)(iVar14b + iVar19 * 2) + sVar3b);
            iVar19 = iVar19 + 1;
            psVar20 = psVar20 + 1;
        } while (iVar19 < iVar17b);
    }
    *puVar11 = uVar22;
    *(uint16_t*)(reinterpret_cast<char*>(puVar10) + uVar18b * 2 - 4) = *(uint16_t*)(reinterpret_cast<char*>(puVar10) + uVar18b * 2 - 6);
    *(uint16_t*)(reinterpret_cast<char*>(puVar10) + uVar18b * 2 - 2) = *(uint16_t*)(reinterpret_cast<char*>(puVar10) + uVar18b * 2);
    int iVar14c = FUN_00533c78(0xcc);
    if (iVar14c == 0) return 0;
    int uVar13 = FUN_005473e0(uVar21, puVar7, puVar8, local_28, puVar9, 1, 0, static_cast<uint16_t>(sVar1 + sVar2) + 4, 1, puVar11, puVar10);
    return uVar13;
}

// 0x501b40 — ECX struct transform: copy 0xd dwords from ECX+0x6c; AL==0 branch does 00727c3c lookup/refcount; vertex loop with FUN_0053ca60 mixing local_4*2D transforms; flag bytes at +0x32/+0x33 (0x4000 bit); return ECX
int FUN_00501b40(void *self_, unsigned char in_AL) {
    int in_ECX = reinterpret_cast<int>(self_);
    int local_68;
    float local_64, local_60, local_5c, local_50, local_10, local_c, local_8, local_4;
    int *local_6c = nullptr;
    unsigned char local_4c[12];
    unsigned char local_40[12];
    int local_34[9];
    int *puVar7 = reinterpret_cast<int*>(in_ECX + 0x6c);
    int *puVar4 = local_34;
    for (int i = 0xd; i != 0; i = i - 1) { *puVar4 = *puVar7; puVar7 = puVar7 + 1; puVar4 = puVar4 + 1; }
    int *puVar7b;
    if (in_AL == '\0') {
        FUN_00538580(&local_6c);
        in_ECX = FUN_00449390(reinterpret_cast<int*>(&DAT_00727c3c), local_6c);
        *(int*)(in_ECX + 4) = *(int*)(in_ECX + 4) + 1;
        local_68 = *(int*)(*(int*)(in_ECX + 0xbc) + 0x20);
        puVar7b = *reinterpret_cast<int**>(*(int*)(in_ECX + 0xbc) + 0x24);
        if ((local_6c != nullptr) && ((local_68 = local_6c[1], local_6c[1] = local_68 - 1, local_68 - 1 == 0))) {
            reinterpret_cast<void(*)(int*,int)>(*local_6c)(local_6c, 1);
        }
    } else {
        local_68 = *(int*)(*(int*)(in_ECX + 0xbc) + 0x20);
        puVar7b = *reinterpret_cast<int**>(*(int*)(in_ECX + 0xbc) + 0x24);
    }
    puVar7 = puVar7b;
    uint32_t uVar6 = 0;
    if (*(int16_t*)(*(int*)(in_ECX + 0xbc) + 0xc) != 0) {
        local_68 = local_68 - reinterpret_cast<int>(puVar7b);
        do {
            float fVar2 = local_4;
            float *pfVar8 = reinterpret_cast<float*>(local_68 + reinterpret_cast<int>(puVar7b));
            float *pfVar3 = reinterpret_cast<float*>(FUN_0053ca60(local_4c, pfVar8));
            local_50 = fVar2 * pfVar3[2];
            local_64 = local_10 + fVar2 * pfVar3[0];
            local_60 = local_c + fVar2 * pfVar3[1];
            *pfVar8 = local_64;
            local_5c = local_8 + local_50;
            pfVar8[1] = local_60;
            pfVar8[2] = local_5c;
            int *puVar4b = reinterpret_cast<int*>(FUN_0053ca60(local_40, puVar7b));
            *puVar7b = *puVar4b;
            puVar7b[1] = puVar4b[1];
            puVar7b[2] = puVar4b[2];
            uVar6 = uVar6 + 1;
            puVar7b = puVar7b + 3;
        } while (uVar6 < static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(*(int*)(in_ECX + 0xbc) + 0xc)));
    }
    unsigned char *pbVar1 = reinterpret_cast<unsigned char*>(*(int*)(in_ECX + 0xbc) + 0x33);
    *pbVar1 = static_cast<unsigned char>(*pbVar1 & 0xf);
    pbVar1 = reinterpret_cast<unsigned char*>(*(int*)(in_ECX + 0xbc) + 0x32);
    *pbVar1 = static_cast<unsigned char>(*pbVar1 | 3);
    *(uint16_t*)(*(int*)(in_ECX + 0xbc) + 0x32) = static_cast<uint16_t>((*(uint16_t*)(*(int*)(in_ECX + 0xbc) + 0x32) & 0xfff) | 0x4000);
    return in_ECX;
}

// 0x501cc0 — reverse recurse 0x7560 children; if name matches (strnicmp) and param_1[9]!=0 call vtable(param_1[9])+0x74 with &param_1 and release returned ref
void FUN_00501cc0(int *param_1, char *param_2, std::size_t param_3) {
    std::size_t _MaxCount = param_3;
    int *piVar3 = param_1;
    if (param_1 != nullptr) {
        int *puVar4 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
        for (; puVar4 != nullptr; puVar4 = reinterpret_cast<int*>(puVar4[1])) {
            if (puVar4 == reinterpret_cast<int*>(&DAT_00727560)) {
                int iVar5 = FUN_00449390(reinterpret_cast<int*>(&DAT_00727560), piVar3);
                uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar5 + 0xc0);
                while ((uVar1 = uVar1 - 1, static_cast<int>(uVar1) >= 0)) {
                    if ((uVar1 < *reinterpret_cast<uint32_t*>(iVar5 + 0xc0))) {
                        int iVar2 = *(int*)(*(int*)(iVar5 + 0xb8) + uVar1 * 4);
                        if (iVar2 != 0) FUN_00501cc0(reinterpret_cast<int*>(iVar2), param_2, _MaxCount);
                    }
                }
                break;
            }
        }
    }
    if (((reinterpret_cast<char*>(piVar3[3]) != nullptr) && ((_strnicmp(reinterpret_cast<char*>(piVar3[3]), param_2, _MaxCount) == 0))) &&
        (reinterpret_cast<int*>(piVar3[9]) != nullptr)) {
        int *unaff_EBX = nullptr;
        reinterpret_cast<void(*)(int*,int*)>(*reinterpret_cast<int*>(piVar3[9]) + 0x74)(&unaff_EBX, piVar3);
        if (unaff_EBX != nullptr) {
            int iVar5 = unaff_EBX[1];
            unaff_EBX[1] = iVar5 - 1;
            if (iVar5 - 1 == 0) reinterpret_cast<void(*)(int*,int)>(*unaff_EBX)(unaff_EBX, 1);
        }
    }
}

// 0x501d90 — reverse recurse 0x7560 children; if name _strnicmp-matches and param_1[9]!=0: param_4==0 sets bit |1 at param_1+8 else clears &0xfe
void FUN_00501d90(int *param_1, char *param_2, std::size_t param_3, int param_4) {
    if (param_1 != nullptr) {
        int *puVar3 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
        for (; puVar3 != nullptr; puVar3 = reinterpret_cast<int*>(puVar3[1])) {
            if (puVar3 == reinterpret_cast<int*>(&DAT_00727560)) {
                int iVar4 = FUN_00449390(reinterpret_cast<int*>(&DAT_00727560), param_1);
                uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar4 + 0xc0);
                while ((uVar1 = uVar1 - 1, static_cast<int>(uVar1) >= 0)) {
                    if ((uVar1 < *reinterpret_cast<uint32_t*>(iVar4 + 0xc0))) {
                        int iVar2 = *(int*)(*(int*)(iVar4 + 0xb8) + uVar1 * 4);
                        if (iVar2 != 0) FUN_00501d90(reinterpret_cast<int*>(iVar2), param_2, param_3, param_4);
                    }
                }
                break;
            }
        }
    }
    if (((reinterpret_cast<char*>(param_1[3]) != nullptr) && ((_strnicmp(reinterpret_cast<char*>(param_1[3]), param_2, param_3) == 0))) && (param_1[9] != 0)) {
        if (static_cast<char>(param_4) == '\0') {
            *(unsigned char*)(reinterpret_cast<char*>(param_1) + 8) = static_cast<unsigned char>(*(unsigned char*)(reinterpret_cast<char*>(param_1) + 8) | 1);
            return;
        }
        *(unsigned char*)(reinterpret_cast<char*>(param_1) + 8) = static_cast<unsigned char>(*(unsigned char*)(reinterpret_cast<char*>(param_1) + 8) & 0xfe);
    }
}

// 0x501e50 — if 0x7560 present walk its +0xd0 list, for type 00727c54 nodes with [0x54]==2 do FUN_005353a0 + vtable(param[9])+0x74/release; then reverse-recurse 0x7560 children
void FUN_00501e50(int *param_1) {
    int *piVar1 = param_1;
    if ((param_1 != nullptr) && ((reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1)) != nullptr))) {
        int *puVar4 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*param_1) + 4)(param_1));
        while (puVar4 != reinterpret_cast<int*>(&DAT_00727560)) {
            puVar4 = reinterpret_cast<int*>(puVar4[1]);
            if (puVar4 == nullptr) return;
        }
        int iVar5 = FUN_00449390(reinterpret_cast<int*>(&DAT_00727560), piVar1);
        puVar4 = *reinterpret_cast<int**>(iVar5 + 0xd0);
        while (true) {
            if (puVar4 == nullptr) break;
            piVar1 = reinterpret_cast<int*>(puVar4[2]);
            puVar4 = reinterpret_cast<int*>(*puVar4);
            if (piVar1 != nullptr) {
                int *puVar6 = reinterpret_cast<int*>(reinterpret_cast<int(*)(int*)>(*reinterpret_cast<int*>(*piVar1) + 4)(piVar1));
                for (; puVar6 != nullptr; puVar6 = reinterpret_cast<int*>(puVar6[1])) {
                    if (puVar6 == reinterpret_cast<int*>(&DAT_00727c54)) {
                        if (piVar1[0x54] == 2) {
                            FUN_005353a0();
                            reinterpret_cast<void(*)(int*,int*)>(*reinterpret_cast<int*>(piVar1[9]) + 0x74)(&param_1, piVar1);
                            if (param_1 != nullptr) {
                                int iVar3 = param_1[1];
                                param_1[1] = iVar3 - 1;
                                if (iVar3 - 1 == 0) reinterpret_cast<void(*)(int*,int)>(*param_1)(param_1, 1);
                            }
                        }
                        break;
                    }
                }
            }
        }
        uint32_t uVar2 = *reinterpret_cast<uint32_t*>(iVar5 + 0xc0);
        while ((uVar2 = uVar2 - 1, static_cast<int>(uVar2) >= 0)) {
            if ((uVar2 < *reinterpret_cast<uint32_t*>(iVar5 + 0xc0))) {
                int iVar3 = *(int*)(*(int*)(iVar5 + 0xb8) + uVar2 * 4);
                if (iVar3 != 0) FUN_00501e50(reinterpret_cast<int*>(iVar3));
            }
        }
    }
}
