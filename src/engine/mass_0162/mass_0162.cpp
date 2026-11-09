// Reconstruction batch mass_0162 — Sid Meier's Pirates! (2004), PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* PTR_FUN_006c3a04;
extern void* PTR_FUN_006c3a48;
extern void FUN_00547d10();
extern void FUN_005383d0();
extern void FUN_00538400();

// 0x5673f0 — observed shape
void FUN_005673f0(void* self, uint8_t param_1) {
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c3a04;
    FUN_00547d10();
    if ((param_1 & 1) != 0) {
        ::operator delete(self);
    }
}

// 0x567520 — observed shape
void FUN_00567520(void* self) {
    FUN_005383d0();
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c3a48;
}

// 0x567540 — observed shape
void FUN_00567540(void* self) {
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c3a48;
    FUN_00538400();
}

// 0x567560 — observed shape
void FUN_00567560(void* self, uint8_t param_1) {
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c3a48;
    FUN_00538400();
    if ((param_1 & 1) != 0) {
        ::operator delete(self);
    }
}
// 0x567590 — observed shape
uint32_t FUN_00567590(LPCSTR param_1, LPCSTR param_2) {
    MessageBoxA((HWND)0x0, param_1, param_2, 0x40000);
    return 0;
}

extern void _makepath(char* param_1, char* param_2, char* param_3, char* param_4, char* param_5);
extern void _splitpath(char* param_1, char* param_2, char* param_3, char* param_4, char* param_5);
extern void FUN_00567e70();
extern void FUN_00567e90();
extern void* DAT_00727e74;
extern void* DAT_00727e78;
extern uint32_t DAT_00727e70;
extern void* DAT_00727e30[];
extern void* DAT_00727df0[];

// 0x5675b0 — observed shape
void FUN_005675b0(void* self, char* param_1) {
    char* in_ECX = static_cast<char*>(self);
    if (in_ECX[0x303] == '\0') {
        _makepath(param_1, in_ECX + 0x100, in_ECX, in_ECX + 0x203, in_ECX + 0x103);
        return;
    }
    char local_100[256];
    local_100[0] = '\0';
    char* pcVar2 = in_ECX;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        ++pcVar2;
    } while (cVar1 != '\0');
    char* pcVar6 = local_100 - 1;
    do {
        char* pcVar7 = pcVar6 + 1;
        ++pcVar6;
        if (*pcVar7 == '\0') break;
    } while (true);
    char* pcVar7 = in_ECX;
    uint32_t uVar5 = static_cast<uint32_t>(static_cast<int>(pcVar2 - in_ECX) >> 2);
    while (uVar5 != 0) {
        *reinterpret_cast<uint32_t*>(pcVar6) = *reinterpret_cast<uint32_t*>(pcVar7);
        pcVar7 += 4;
        pcVar6 += 4;
        --uVar5;
    }
    char* pcVar3 = local_100;
    for (uVar5 = static_cast<uint32_t>(static_cast<int>(pcVar2 - in_ECX) & 3); uVar5 != 0; --uVar5) {
        *pcVar6 = *pcVar7;
        ++pcVar7;
        ++pcVar6;
    }
    do {
        cVar1 = *pcVar3;
        ++pcVar3;
    } while (cVar1 != '\0');
    int iVar4 = static_cast<int>(pcVar3 - (local_100 + 1));
    if (iVar4 != 0) {
        if (local_100[iVar4 - 1] != '\\' && local_100[iVar4 - 1] != '/') {
            local_100[iVar4 + 1] = '\0';
            local_100[iVar4] = '\\';
        }
    }
    pcVar2 = in_ECX + 0x303;
    pcVar6 = pcVar2;
    do {
        cVar1 = *pcVar6;
        ++pcVar6;
    } while (cVar1 != '\0');
    pcVar7 = local_100 - 1;
    do {
        pcVar3 = pcVar7 + 1;
        ++pcVar7;
    } while (*pcVar3 != '\0');
    pcVar3 = pcVar2;
    for (uVar5 = static_cast<uint32_t>(static_cast<int>(pcVar6 - pcVar2) >> 2); uVar5 != 0; --uVar5) {
        *reinterpret_cast<uint32_t*>(pcVar7) = *reinterpret_cast<uint32_t*>(pcVar3);
        pcVar3 += 4;
        pcVar7 += 4;
    }
    for (uVar5 = static_cast<uint32_t>(static_cast<int>(pcVar6 - pcVar2) & 3); uVar5 != 0; --uVar5) {
        *pcVar7 = *pcVar3;
        ++pcVar3;
        ++pcVar7;
    }
    _makepath(param_1, in_ECX + 0x100, local_100, in_ECX + 0x203, in_ECX + 0x103);
}

// 0x5676c0 — observed shape
void FUN_005676c0(void* self, char* param_1) {
    char* in_ECX = static_cast<char*>(self);
    in_ECX[0x303] = '\0';
    _splitpath(param_1, in_ECX + 0x100, in_ECX, in_ECX + 0x203, in_ECX + 0x103);
}

// 0x567710 — observed shape
void FUN_00567710() {
    FUN_00567e70();
    if (DAT_00727e74 != nullptr) {
        reinterpret_cast<void (*)()>(DAT_00727e74)();
    }
    uint32_t uVar1 = 0;
    if (DAT_00727e70 != 0) {
        do {
            reinterpret_cast<void (*)()>(&DAT_00727e30[uVar1])();
            ++uVar1;
        } while (uVar1 < DAT_00727e70);
    }
}

// 0x567750 — observed shape
void FUN_00567750() {
    uint32_t uVar1 = 0;
    if (DAT_00727e70 != 0) {
        do {
            reinterpret_cast<void (*)()>(&DAT_00727df0[uVar1])();
            ++uVar1;
        } while (uVar1 < DAT_00727e70);
    }
    if (DAT_00727e78 != nullptr) {
        reinterpret_cast<void (*)()>(DAT_00727e78)();
    }
    FUN_00567e90();
}

// 0x567790 — observed shape
void FUN_00567790(void* param_1, void* param_2) {
    DAT_00727e74 = param_1;
    DAT_00727e78 = param_2;
}
extern void* PTR_LAB_006c3a98;
extern void FUN_00497420(char* param_1);
extern void thunk_FUN_005675b0(char* param_1);
extern void FUN_00567f00();

// 0x5677b0 — observed shape
void FUN_005677b0(void* param_1, void* param_2) {
    (&DAT_00727e30)[DAT_00727e70] = param_1;
    (&DAT_00727df0)[DAT_00727e70] = param_2;
    DAT_00727e70 = DAT_00727e70 + 1;
}

// 0x5677e0 — observed shape
void FUN_005677e0(void* self) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_LAB_006c3a98);
    in_ECX[1] = 0;
    *reinterpret_cast<uint8_t*>(in_ECX + 2) = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 0x43) = 0;
}

// 0x567800 — observed shape
void FUN_00567800(void* self) {
    *reinterpret_cast<void**>(self) = &PTR_LAB_006c3a98;
}

// 0x567810 — observed shape
void FUN_00567810(void* self, char* param_1) {
    if (param_1 == nullptr || *param_1 == '\0') {
        *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 8) = 0;
        return;
    }
    char* dst = static_cast<char*>(self) + 8;
    strncpy(dst, param_1, 0x103);
    FUN_00497420(dst);
}

// 0x567880 — observed shape
void FUN_00567880(void* self, char* param_1) {
    if (param_1 == nullptr || *param_1 == '\0') {
        *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x10c) = 0;
        return;
    }
    FUN_005676c0(self, param_1);
    char acStack_201[513];
    char acStack_301[256];
    extern char DAT_006f5896[];
    int iVar2 = 0;
    char cVar1;
    do {
        cVar1 = (&DAT_006f5896)[iVar2];
        acStack_201[iVar2] = cVar1;
        ++iVar2;
    } while (cVar1 != '\0');
    iVar2 = 0;
    do {
        cVar1 = (&DAT_006f5896)[iVar2];
        acStack_301[iVar2] = cVar1;
        ++iVar2;
    } while (cVar1 != '\0');
    thunk_FUN_005675b0(reinterpret_cast<char*>(self) + 0x10c);
    FUN_00497420(reinterpret_cast<char*>(self) + 0x10c);
}
extern uint32_t DAT_00727f88[];
extern uint32_t DAT_007281c8;
extern void FUN_00567dc0();
extern void* PTR_FUN_006c3aa4;
extern void FUN_00567b70();
extern void FUN_00568140();
extern void thunk_FUN_00567f00(void* param_1);
// NEEDS_MANUAL: 0x567a60 — indirect jump through table from FUN_00568140() result (Ghidra could not recover jumptable at 0x567ac2)
// 0x567a60 — observed shape
void FUN_00567a60(void) {
    DAT_00727f88[0] = 0;
    DAT_00727f88[1] = 0;
    DAT_00727f88[2] = 0;
    DAT_00727f88[3] = 0;
    DAT_00727f88[4] = 0;
    DAT_00727f88[5] = 0;
    DAT_00727f88[6] = 0;
    DAT_00727f88[7] = 0;
    DAT_00727f88[8] = 0;
    DAT_00727f88[9] = 0;
    DAT_00727f88[10] = 0;
    DAT_00727f88[11] = 0;
    DAT_00727f88[12] = 0;
    DAT_00727f88[13] = 0;
    DAT_00727f88[14] = 0;
    DAT_00727f88[15] = 0;
    extern uint32_t DAT_00717a88;
    DAT_00717a88 = 1;
    uint32_t* puVar1 = static_cast<uint32_t*>(FUN_00568140());
    reinterpret_cast<void (*)()>(*puVar1)();
}

// 0x567b70 — observed shape
void FUN_00567b70_recon(void) {
    uint32_t uVar2 = 0;
    do {
        void* pvVar1 = reinterpret_cast<void*>(DAT_00727f88[uVar2 / 4]);
        if (pvVar1 != nullptr) {
            thunk_FUN_00567f00(pvVar1);
            ::operator delete(pvVar1);
        }
        DAT_00727f88[uVar2 / 4] = 0;
        uVar2 += 4;
    } while (uVar2 < 0x40);
    DAT_007281c8 = 0;
}

// 0x567bb0 — observed shape
void FUN_00567bb0(void) {
    FUN_00567b70();
    extern uint32_t DAT_00717a88;
    extern void* DAT_00728350;
    if (DAT_00717a88 != '\0') {
        InitializeCriticalSection(static_cast<LPCRITICAL_SECTION>(DAT_00728350));
        DAT_00717a88 = '\0';
    }
    DeleteCriticalSection(static_cast<LPCRITICAL_SECTION>(DAT_00728350));
}

// 0x567be0 — observed shape
void FUN_00567be0(void* self) {
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c3aa4;
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    if (in_ECX[4] != 0 && *reinterpret_cast<char*>(reinterpret_cast<char*>(in_ECX) + 0x15) == '\0') {
        ::operator delete(reinterpret_cast<void*>(in_ECX[1]));
    }
    FUN_00567dc0();
}

// 0x567cf0 — observed shape
uint32_t FUN_00567cf0(void* self) {
    char* in_ECX = static_cast<char*>(self);
    *(in_ECX + 0x15) = 1;
    return *reinterpret_cast<uint32_t*>(in_ECX + 4);
}
