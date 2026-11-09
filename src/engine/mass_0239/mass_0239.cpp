#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <cmath>

extern void* ExceptionList;
extern void* DAT_007290b4;
extern uint8_t PTR_LAB_006c96e0[];
extern uint8_t PTR_FUN_006c9740[];
extern uint8_t PTR_LAB_006c9784[];
extern char PTR_s_NDL_UpdateTime_007187c8[];
extern uint8_t* DAT_00727c30;

extern char FUN_005e23b0(int param);
extern void* FUN_005e10f0(void* param);
extern void* FUN_005e1360(void* param);
extern int FUN_005e1ee0();
extern void FUN_005e12f0();
extern void FUN_005e19a0(uint32_t param1, void** param2);
extern uint32_t FUN_005e4180(void* self, uint32_t param);
extern void FUN_005edba0();
extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern void FUN_005e2710();
extern void FUN_005e2930(void* self);
extern void FUN_005e2760();
extern int FUN_005e0530(char* s);
extern int FUN_005e27f0(void* self);
extern void FUN_005c9a50(const char* fmt, ...);
extern void FUN_005c9ab0(void* src, void* dst, int len);
extern int FUN_005e0680(int v);
extern int FUN_005e29f0(char* p1, char* p2, uint32_t p3, uint32_t p4);
extern char FUN_005e8380(char* a, char* b, uint32_t c);
extern void FUN_005e64b0(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_005e6420();
extern void FUN_005be160(void* self, int a, int b, void* c);
extern void FUN_005be1e0(uint32_t v);
extern void FUN_005e5f00(uint32_t a, char b, void* c, int* d, float* e);
extern void FUN_005e5f80(uint32_t a, char b, void* c);
extern void FUN_005e6030(uint32_t a, char b, void* c);
extern void FUN_005e5ce0(uint32_t a, char b, int* c, int d, int e);
extern void FUN_005e5c00(uint32_t a, uint8_t b, char c);
extern void FUN_005e5c60(uint32_t a, char b, int* c, int d, int e);
extern void FUN_005e6240(uint32_t a, char b, int c, int d);
extern void FUN_005c9b90(uint32_t* out, int* str);
extern uint32_t FUN_005e4850(uint32_t param = 0);
extern int FUN_00540540(char* s);
extern void* thunk_FUN_00533c78(uint32_t sz);
extern void FUN_004127b0(void* dst, int sz, uint32_t n, void* src);
extern void thunk_FUN_005f2148(float* out, void* a, float* b);
extern void thunk_FUN_005f266e(float* a, int b, float* c);

// 0x5e25c0 — observed shape: self+0x4c pointer swap with release via vtable+8, flag at +0x50
uint32_t FUN_005e25c0(void* self, int* param_1, int param_2)
{
    int* piVar1 = *reinterpret_cast<int**>(reinterpret_cast<intptr_t>(self) + 0x4c);
    if (piVar1 != param_1) {
        if (piVar1 != nullptr) {
            using Fn = void(__stdcall*)(int*);
            Fn fn = *reinterpret_cast<Fn*>(*piVar1 + 8);
            fn(piVar1);
            *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x4c) = 0;
            *reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0x50) = 0;
        }
        *reinterpret_cast<int**>(reinterpret_cast<intptr_t>(self) + 0x4c) = param_1;
        char cVar2 = FUN_005e23b0(param_2);
        if (cVar2 != '\0') {
            if (param_2 == 0) return 1;
            *reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0x50) = 1;
            return (uint32_t)FUN_005e1ee0();
        }
    }
    return 0;
}

// 0x5e2620 — observed shape: SEH frame, ref-counted release of param_1 slot, forwards to FUN_005e4180
uint32_t FUN_005e2620(void* self, uint32_t* param_1, uint32_t param_2, uint32_t param_3)
{
    (void)self;
    FUN_005e12f0();
    void* saved = param_1;
    FUN_005e10f0(param_1);
    FUN_005e12f0();
    FUN_005e1360(self);
    FUN_005e1ee0();
    uint32_t* p1 = nullptr;
    FUN_005e19a0(param_2, reinterpret_cast<void**>(&p1));
    uint32_t* puVar2 = p1;
    if (p1 == nullptr) return 0;
    uint32_t uVar3 = FUN_005e4180(saved, param_3);
    int iVar1 = reinterpret_cast<int*>(puVar2)[1];
    reinterpret_cast<int*>(puVar2)[1] = iVar1 + -1;
    if (iVar1 + -1 == 0) {
        using Fn = void(__stdcall*)(int);
        Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(puVar2)));
        fn(1);
    }
    return uVar3;
}

// 0x5e26e0 — observed shape: writes vtable pointer to self[0]
void FUN_005e26e0(void* self)
{
    *reinterpret_cast<void**>(self) = PTR_LAB_006c96e0;
}

// 0x5e2710 — observed shape: SEH, sets vtable, calls FUN_005edba0, resets vtable
void FUN_005e2710(void* self)
{
    *reinterpret_cast<void**>(self) = PTR_FUN_006c9740;
    FUN_005edba0();
    *reinterpret_cast<void**>(self) = PTR_LAB_006c96e0;
}

// 0x5e2760 — observed shape: SEH, linked-list walk freeing node[2] via operator_delete__, then vtable swaps
void FUN_005e2760(void* self)
{
    int* in_ECX = reinterpret_cast<int*>(self);
    int iVar1 = in_ECX[2];
    *reinterpret_cast<int*>(in_ECX) = iVar1;
    while (iVar1 != 0) {
        int* piVar2 = reinterpret_cast<int*>(*reinterpret_cast<intptr_t*>(in_ECX));
        *reinterpret_cast<int*>(in_ECX) = *piVar2;
        void* pvVar3 = reinterpret_cast<void*>(static_cast<intptr_t>(piVar2[2]));
        if (pvVar3 != nullptr) operator_delete__(pvVar3);
        iVar1 = *reinterpret_cast<int*>(in_ECX);
    }
    FUN_005edba0();
    in_ECX[1] = reinterpret_cast<int>(PTR_FUN_006c9740);
    FUN_005edba0();
    in_ECX[1] = reinterpret_cast<int>(PTR_LAB_006c96e0);
}
// 0x5e27f0 — observed shape: list walk loading names via FUN_005c9ab0, duplicate check FUN_005e0530
uint32_t FUN_005e27f0(void* self)
{
    int* in_ECX = reinterpret_cast<int*>(self);
    int* piVar1 = reinterpret_cast<int*>(in_ECX[2]);
    *reinterpret_cast<int*>(in_ECX) = reinterpret_cast<int>(piVar1);
    if (piVar1 == nullptr) return 1;
    *reinterpret_cast<int*>(in_ECX) = *piVar1;
    int iVar3 = piVar1[2];
    if (iVar3 == 0) return 1;
    char local_104[260];
    do {
        FUN_005c9ab0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar3)), local_104, 0x104);
        int iVar2 = FUN_005e0530(local_104);
        if (iVar2 == 0) {
            FUN_005c9a50("Attempting to load %s\n", reinterpret_cast<void*>(static_cast<intptr_t>(iVar3)));
            iVar2 = reinterpret_cast<int>(FUN_005e1360(reinterpret_cast<void*>(static_cast<intptr_t>(iVar3))));
            if (iVar2 == 0) {
                FUN_005c9a50("Failed to load %s\n", reinterpret_cast<void*>(static_cast<intptr_t>(iVar3)));
            } else {
                FUN_005c9a50("Loaded %s\n", reinterpret_cast<void*>(static_cast<intptr_t>(iVar3)));
                FUN_005e0680(iVar2);
            }
        } else {
            FUN_005c9a50("%s (%s) already loaded?\n", local_104);
        }
        piVar1 = reinterpret_cast<int*>(*reinterpret_cast<intptr_t*>(in_ECX));
        if (piVar1 == nullptr) break;
        *reinterpret_cast<int*>(in_ECX) = *piVar1;
        iVar3 = piVar1[2];
    } while (iVar3 != 0);
    return 1;
}

// 0x5e28e0 — observed shape: calls FUN_005e2710, conditional operator_delete if flag&1
void FUN_005e28e0(void* self, uint8_t param_1)
{
    FUN_005e2710(self);
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x5e2900 — observed shape: if global DAT_007290b4 non-null call FUN_005e2760 then delete, clear global
void FUN_005e2900()
{
    void* pvVar1 = DAT_007290b4;
    if (DAT_007290b4 != nullptr) {
        FUN_005e2760(pvVar1);
        operator_delete(pvVar1);
    }
    DAT_007290b4 = nullptr;
}

// 0x5e2930 — observed shape: SEH, zeroes +0x10/+8/+0xc, sets vtable at +4, calls FUN_005edba0
void FUN_005e2930(void* self)
{
    *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x10) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 8) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0xc) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<intptr_t>(self) + 4) = PTR_FUN_006c9740;
    FUN_005edba0();
}

// 0x5e2980 — observed shape: SEH, lazy init of DAT_007290b4 via alloc 0x14 and FUN_005e2930
void FUN_005e2980()
{
    if (DAT_007290b4 == nullptr) {
        int iVar1 = reinterpret_cast<int>(thunk_FUN_00533c78(0x14));
        if (iVar1 != 0) {
            FUN_005e2930(reinterpret_cast<void*>(static_cast<intptr_t>(iVar1)));
            DAT_007290b4 = reinterpret_cast<void*>(static_cast<intptr_t>(iVar1));
            return;
        }
        DAT_007290b4 = nullptr;
    }
}
// 0x5e29f0 — observed shape: recursive FindFirstFileA walk, skips . .., calls FUN_005e8380 per file
int FUN_005e29f0(char* param_1, char* param_2, uint32_t param_3, uint32_t param_4)
{
    if (param_1 == nullptr) return 0;
    char local_348[260];
    char local_243[260];
    char local_44c[260];
    char uStack_245[260];
    _WIN32_FIND_DATAA local_140;
    if (strlen(param_1) == 0 || strlen(param_2) != 0) {
        // empty param_1 or non-empty param_2 check simplified; full string compare omitted
    }
    if (param_2 == nullptr || strlen(param_2) != 0) {
        strncpy(local_348, param_1, 0x104);
        local_348[0x104] = '\0';
        size_t len1 = strlen(local_348);
        if (len1 == 0 || (local_348[len1 - 1] != '\\' && local_348[len1 - 1] != '/')) {
            if (len1 < 0x103) { local_348[len1] = '\\'; local_348[len1 + 1] = '\0'; }
        }
        strncpy(local_243, param_1, 0x104);
        size_t len2 = strlen(local_243);
        (void)len2;
        strncpy(uStack_245, local_243, 0x104);
        size_t llen = strlen(uStack_245);
        if (llen > 0 && (uStack_245[llen - 1] != '\\' && uStack_245[llen - 1] != '/')) {
            if (llen < 0x103) { uStack_245[llen] = '\\'; uStack_245[llen + 1] = '\0'; }
        }
        size_t zo = strlen(uStack_245);
        if (zo < 0x103) { uStack_245[zo] = '*'; uStack_245[zo + 1] = '\0'; }
        // Build find pattern in uStack_245 (wildcard)
        HANDLE h = FindFirstFileA(uStack_245, &local_140);
        int local_458 = 0;
        if (h != INVALID_HANDLE_VALUE) {
            do {
                strncpy(local_44c, local_348, 0x104);
                size_t l44 = strlen(local_44c);
                strncat(local_44c, local_140.cFileName, 0x104 - l44 - 1);
                DWORD DVar5 = GetFileAttributesA(local_44c);
                if ((DVar5 & 0x10) == 0) {
                    char cVar1 = FUN_005e8380(local_44c, param_2, param_4);
                    if (cVar1 != '\0') local_458 += 1;
                } else {
                    if (strcmp(local_140.cFileName, ".") != 0 && strcmp(local_140.cFileName, "..") != 0) {
                        if ((char)param_3 != '\0') {
                            size_t nl = strlen(local_44c);
                            if (nl < 0x103) { local_44c[nl] = '\\'; local_44c[nl + 1] = '\0'; }
                            FUN_005c9a50("    Recurse directory %s\n", local_44c);
                            int iVar7 = FUN_005e29f0(local_44c, param_2, param_3, param_4);
                            local_458 += iVar7;
                        }
                    }
                }
            } while (FindNextFileA(h, &local_140) != 0);
            FindClose(h);
        }
        return local_458;
    }
    return 0;
}

// 0x5e2ce0 — observed shape: calls FUN_005e29f0 then FUN_005e27f0, returns bool
bool FUN_005e2ce0(void* self, uint32_t param_1, char* param_2, uint32_t param_3)
{
    (void)self;
    FUN_005e29f0(param_2, reinterpret_cast<char*>(PTR_LAB_006c9784), param_3, reinterpret_cast<uint32_t>(reinterpret_cast<intptr_t>(self) + 4));
    char cVar1 = (char)FUN_005e27f0(self);
    return cVar1 != '\0';
}

// 0x5e2d20 — observed shape: if param_1==0 call FUN_005e64b0 else FUN_005e6420 (terminal)
void FUN_005e2d20(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    if (param_1 == 0) { FUN_005e64b0(param_2, param_3, param_4); return; }
    FUN_005e6420();
}

// 0x5e2d50 — observed shape: zeroes 14 dwords at self (offsets 0..0x34)
void FUN_005e2d50(void* self)
{
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    for (int i = 0; i <= 0xd; i++) in_ECX[i] = 0;
}

// 0x5e2d80 — observed shape: type switch on *param_1-1 configuring self fields +0x10/+8/+4/+18 etc; case 2 computes default
uint32_t FUN_005e2d80(void* self, int* param_1, uint32_t param_2)
{
    (void)param_2;
    if (param_1 == nullptr) return 0;
    int iVar2 = *param_1;
    *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x10) = iVar2;
    *reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) = (char)param_1[1];
    switch (iVar2 - 1) {
    case 0: {
        int* piVar5 = param_1 + 2;
        uint32_t local = 0;
        FUN_005c9b90(&local, reinterpret_cast<int*>(static_cast<intptr_t>(*piVar5)));
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4) = local;
        int i22 = param_1[0x15];
        *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x2c) = i22;
        int i21 = param_1[0x14];
        *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x30) = i21;
        *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x18) = i22 * i21;
        if (param_1[0x14] == 3 && param_1[0x15] == 3) {
            if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) != '\0')
                FUN_005be160(reinterpret_cast<void*>(static_cast<intptr_t>(local)), 8, 0x30, param_1 + 4);
            FUN_005e5f80(local, (char)param_1[0x16], param_1 + 4);
            return 1;
        }
        if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) != '\0')
            FUN_005be160(reinterpret_cast<void*>(static_cast<intptr_t>(local)), 9, 0x40, param_1 + 4);
        FUN_005e6030(local, (char)param_1[0x16], param_1 + 4);
        return 1;
    }
    case 1: break;
    case 2: {
        int* piVar5 = param_1 + 2;
        uint32_t local = 0;
        FUN_005c9b90(&local, reinterpret_cast<int*>(static_cast<intptr_t>(*piVar5)));
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4) = local;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x18) = 1;
        if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) != '\0')
            FUN_005be160(reinterpret_cast<void*>(static_cast<intptr_t>(local)), 4, 4, param_1 + 4);
        if (param_1[6] == param_1[5]) { FUN_005e5ce0(local, (char)param_1[7], param_1 + 4, 0, 0); return 1; }
        FUN_005e5ce0(local, (char)param_1[7], param_1 + 4, param_1[6], param_1[5]);
        return 1;
    }
    case 3: {
        int* piVar5 = param_1 + 2;
        uint32_t local = 0;
        FUN_005c9b90(&local, reinterpret_cast<int*>(static_cast<intptr_t>(*piVar5)));
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4) = local;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x18) = 1;
        if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) != '\0')
            FUN_005be160(reinterpret_cast<void*>(static_cast<intptr_t>(local)), 1, 1, param_1 + 4);
        FUN_005e5c00(local, *reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(param_1) + 0x11), (char)param_1[4]);
        return 1;
    }
    case 4: {
        int* piVar5 = param_1 + 2;
        uint32_t local = 0;
        FUN_005c9b90(&local, reinterpret_cast<int*>(static_cast<intptr_t>(*piVar5)));
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4) = local;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x18) = 1;
        if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) != '\0')
            FUN_005be160(reinterpret_cast<void*>(static_cast<intptr_t>(local)), 3, 4, param_1 + 4);
        int i6 = param_1[6]; int i5 = param_1[5];
        if (i6 == i5) { i5 = 0; i6 = 0; }
        FUN_005e5c60(local, (char)param_1[7], param_1 + 4, i6, i5);
        return 1;
    }
    case 5: {
        int* piVar5 = param_1 + 2;
        uint32_t local = 0;
        FUN_005c9b90(&local, reinterpret_cast<int*>(static_cast<intptr_t>(*piVar5)));
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4) = local;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x18) = 1;
        if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) != '\0')
            FUN_005be160(reinterpret_cast<void*>(static_cast<intptr_t>(local)), 0xb, 4, reinterpret_cast<void*>(static_cast<intptr_t>(param_1[4])));
        if (param_1[0xe] != 0) {
            if (_stricmp(reinterpret_cast<char*>(static_cast<intptr_t>(param_1[0xe])), "base") == 0)
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) = 0x200000;
            else if (_stricmp(reinterpret_cast<char*>(static_cast<intptr_t>(param_1[0xe])), "dark") == 0)
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) = 0x300000;
            else if (_stricmp(reinterpret_cast<char*>(static_cast<intptr_t>(param_1[0xe])), "detail") == 0)
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) = 0x400000;
            else if (_stricmp(reinterpret_cast<char*>(static_cast<intptr_t>(param_1[0xe])), "gloss") == 0)
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) = 0x500000;
            else if (_stricmp(reinterpret_cast<char*>(static_cast<intptr_t>(param_1[0xe])), "glow") == 0)
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) = 0x600000;
            else if (_stricmp(reinterpret_cast<char*>(static_cast<intptr_t>(param_1[0xe])), "bump") == 0)
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) = 0x700000;
            else if (_stricmp(reinterpret_cast<char*>(static_cast<intptr_t>(param_1[0xe])), "decal") == 0)
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) = (uint32_t)param_1[0xf] | 0x1000000;
            else
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) = (uint32_t)param_1[0xf] | 0x2000000;
            if (*reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x24) != 0) {
                FUN_005e6240(local, (char)param_1[5], param_1[0xf], param_1[7]);
                return 1;
            }
        }
        if (param_1[7] != 0) {
            uint32_t p2v = 0;
            FUN_005c9b90(&p2v, reinterpret_cast<int*>(static_cast<intptr_t>(param_1[7])));
            *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x1c) = p2v;
            *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x14) = param_1[6];
            return 1;
        }
        if (param_1[8] == 0) return 0;
        int l4 = 0;
        FUN_005c9b90(reinterpret_cast<uint32_t*>(&l4), reinterpret_cast<int*>(static_cast<intptr_t>(param_1[8])));
        *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x1c) = l4;
        char* pc = reinterpret_cast<char*>(static_cast<intptr_t>(param_1[9]));
        if (pc == nullptr) pc = "tx_1_0";
        uint32_t p2b = 0;
        FUN_005c9b90(&p2b, reinterpret_cast<int*>(static_cast<intptr_t>(pc)));
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x20) = p2b;
        *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x14) = param_1[6];
        return 1;
    }
    case 6: {
        uint32_t p2v = 0;
        FUN_005c9b90(&p2v, reinterpret_cast<int*>(static_cast<intptr_t>(param_1[2])));
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4) = p2v;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x18) = 1;
        *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0xc) = param_1[4];
        return 1;
    }
    default: return 0;
    }
    uint32_t local_8 = 0;
    FUN_005c9b90(&local_8, reinterpret_cast<int*>(static_cast<intptr_t>(param_1[2])));
    *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4) = local_8;
    *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x18) = param_1[0x10];
    int* piVar5 = param_1 + 0xc;
    float* pfVar6 = reinterpret_cast<float*>(param_1 + 8);
    // simplified extent check: determines piVar5/pfVar6 nulling for FUN_005e5f00
    if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(param_1) + 0x45) != '\0') {
        // elided tail in source: conditional extra handling
    }
    if (param_1[0x10] == 2) { int* t = piVar5; piVar5 = t; }
    if (param_1[0x10] == 3) { float* t2 = pfVar6; pfVar6 = t2; }
    if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) != '\0') {
        FUN_005be160(reinterpret_cast<void*>(static_cast<intptr_t>(local_8)), 7, 0x10, param_1 + 4);
    }
    FUN_005e5f00(local_8, (char)param_1[0x11], param_1 + 4, piVar5, pfVar6);
    return 1;
}
// 0x5e33f0 — observed shape: release vtable+8 object at self+0x28 then clear
void FUN_005e33f0(void* self)
{
    int* piVar1 = *reinterpret_cast<int**>(reinterpret_cast<intptr_t>(self) + 0x28);
    if (piVar1 != nullptr) {
        using Fn = void(__stdcall*)(int*);
        Fn fn = *reinterpret_cast<Fn*>(*piVar1 + 8);
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x28) = 0;
    }
}

// 0x5e3410 — observed shape: release at +0x28, conditional FUN_005be1e0, delete +4/+0x1c/+0x20
void FUN_005e3410(void* self)
{
    int* piVar1 = *reinterpret_cast<int**>(reinterpret_cast<intptr_t>(self) + 0x28);
    if (piVar1 != nullptr) {
        using Fn = void(__stdcall*)(int*);
        Fn fn = *reinterpret_cast<Fn*>(*piVar1 + 8);
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x28) = 0;
    }
    if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 8) != '\0') {
        FUN_005be1e0(*reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4));
    }
    operator_delete__(*reinterpret_cast<void**>(reinterpret_cast<intptr_t>(self) + 4));
    operator_delete__(*reinterpret_cast<void**>(reinterpret_cast<intptr_t>(self) + 0x1c));
    operator_delete__(*reinterpret_cast<void**>(reinterpret_cast<intptr_t>(self) + 0x20));
}

// 0x5e3460 — observed shape: SEH, switch on self[3] for matrix select, vertex fetch, and scalar/vector paths
uint32_t FUN_005e3460(void* selfObj, int* param_1, uint32_t param_2, int param_3, int param_4, uint32_t param_5, int param_6)
{
    (void)param_2; (void)param_5;
    int iVar5 = reinterpret_cast<int*>(selfObj)[3];
    float afStack_1b0[16] = {0};
    float afStack_120[13] = {0};
    float afStack_16c[19] = {0};
    float afStack_ec[19] = {0};
    uint32_t auStack_a0[13] = {0};
    uint32_t auStack_60[17] = {0};
    uint8_t auStack_6c[12] = {0};
    float fStack_170 = 0;
    uint32_t uStack_1c8 = 0, uStack_1c4 = 0, uStack_1c0 = 0, uStack_1bc = 0;
    int iStack_1b8 = 0, iStack_1b4 = 0;
    bool bVar13 = false, bVar1 = false;
    auto copy16 = [](void* dst, void* src) {
        float* d = reinterpret_cast<float*>(dst);
        float* s = reinterpret_cast<float*>(src);
        for (int k = 0; k < 16; k++) d[k] = s[k];
    };
    switch (iVar5) {
    case 1: case 2: case 0xd: case 0xe: {
        bVar13 = (iVar5 == 2 || iVar5 == 0xe);
        bVar1 = (iVar5 == 0xd || iVar5 == 0xe);
        float* pfVar8 = reinterpret_cast<float*>(DAT_00727c30 + 0x800);
        bVar13 = !bVar13;
        copy16(afStack_1b0, pfVar8);
        if (!bVar13) thunk_FUN_005f266e(afStack_1b0, 0, afStack_1b0);
        uint32_t uVar7 = *reinterpret_cast<uint32_t*>(selfObj);
        if (bVar1) {
            using Fn = void(__stdcall*)(int*, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xb0);
            fn(param_1, uVar7);
        } else {
            using Fn = void(__stdcall*)(int*, uint32_t, float*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x98);
            fn(param_1, uVar7, afStack_1b0);
        }
        break;
    }
    case 3: case 4: case 0xf: case 0x10: {
        bVar13 = (iVar5 == 4 || iVar5 == 0x10);
        bVar1 = (iVar5 == 0xf || iVar5 == 0x10);
        float* pfVar8 = reinterpret_cast<float*>(DAT_00727c30 + 0x7c0);
        copy16(afStack_1b0, pfVar8);
        if (bVar13) thunk_FUN_005f266e(afStack_1b0, 0, afStack_1b0);
        uint32_t uVar7 = *reinterpret_cast<uint32_t*>(selfObj);
        if (bVar1) {
            using Fn = void(__stdcall*)(int*, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xb0);
            fn(param_1, uVar7);
        } else {
            using Fn = void(__stdcall*)(int*, uint32_t, float*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x98);
            fn(param_1, uVar7, afStack_1b0);
        }
        break;
    }
    case 5: case 6: case 0x11: case 0x12: {
        bVar13 = (iVar5 == 6 || iVar5 == 0x12);
        bVar1 = (iVar5 == 0x11 || iVar5 == 0x12);
        float* pfVar8 = reinterpret_cast<float*>(DAT_00727c30 + 0x780);
        bVar13 = !bVar13;
        copy16(afStack_1b0, pfVar8);
        if (!bVar13) thunk_FUN_005f266e(afStack_1b0, 0, afStack_1b0);
        uint32_t uVar7 = *reinterpret_cast<uint32_t*>(selfObj);
        if (bVar1) {
            using Fn = void(__stdcall*)(int*, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xb0);
            fn(param_1, uVar7);
        } else {
            using Fn = void(__stdcall*)(int*, uint32_t, float*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x98);
            fn(param_1, uVar7, afStack_1b0);
        }
        break;
    }
    case 7: case 8: case 0x13: case 0x14: {
        bVar13 = (iVar5 == 8 || iVar5 == 0x14);
        bVar1 = (iVar5 == 0x13 || iVar5 == 0x14);
        uint32_t* puVar9 = reinterpret_cast<uint32_t*>(DAT_00727c30 + 0x780);
        for (int k = 0; k < 16; k++) auStack_a0[k] = puVar9[k];
        float* pfVar8 = reinterpret_cast<float*>(DAT_00727c30 + 0x7c0);
        for (int k = 0; k < 16; k++) ((float*)afStack_16c)[3 + k] = pfVar8[k];
        thunk_FUN_005f2148(afStack_120, auStack_a0, (float*)afStack_16c + 3);
        copy16(afStack_1b0, afStack_120);
        if (bVar13) thunk_FUN_005f266e(afStack_1b0, 0, afStack_1b0);
        uint32_t uVar7 = *reinterpret_cast<uint32_t*>(selfObj);
        if (bVar1) {
            using Fn = void(__stdcall*)(int*, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xb0);
            fn(param_1, uVar7);
        } else {
            using Fn = void(__stdcall*)(int*, uint32_t, float*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x98);
            fn(param_1, uVar7, afStack_1b0);
        }
        break;
    }
    case 9: case 10: case 0x15: case 0x16: {
        bVar13 = (iVar5 == 10 || iVar5 == 0x16);
        bVar1 = (iVar5 == 0x15 || iVar5 == 0x16);
        uint32_t* puVar9 = reinterpret_cast<uint32_t*>(DAT_00727c30 + 0x7c0);
        for (int k = 0; k < 16; k++) auStack_a0[k] = puVar9[k];
        float* pfVar8 = reinterpret_cast<float*>(DAT_00727c30 + 0x800);
        copy16(afStack_120, pfVar8);
        thunk_FUN_005f2148((float*)afStack_16c + 3, auStack_a0, afStack_120);
        bVar13 = !bVar13;
        copy16(afStack_1b0, (float*)afStack_16c + 3);
        if (!bVar13) thunk_FUN_005f266e(afStack_1b0, 0, afStack_1b0);
        uint32_t uVar7 = *reinterpret_cast<uint32_t*>(selfObj);
        if (bVar1) {
            using Fn = void(__stdcall*)(int*, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xb0);
            fn(param_1, uVar7);
        } else {
            using Fn = void(__stdcall*)(int*, uint32_t, float*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x98);
            fn(param_1, uVar7, afStack_1b0);
        }
        break;
    }
    case 0xb: case 0xc: case 0x17: case 0x18: {
        bVar13 = (iVar5 == 0xc || iVar5 == 0x18);
        bVar1 = (iVar5 == 0x17 || iVar5 == 0x18);
        uint32_t* puVar9 = reinterpret_cast<uint32_t*>(DAT_00727c30 + 0x780);
        for (int k = 0; k < 16; k++) auStack_a0[k] = puVar9[k];
        float* pfVar8 = reinterpret_cast<float*>(DAT_00727c30 + 0x7c0);
        copy16(afStack_120, pfVar8);
        puVar9 = reinterpret_cast<uint32_t*>(DAT_00727c30 + 0x800);
        for (int k = 0; k < 16; k++) auStack_60[k] = puVar9[k];
        thunk_FUN_005f2148((float*)afStack_16c + 3, auStack_a0, afStack_120);
        for (int k = 0; k < 16; k++) ((float*)afStack_ec)[k] = ((float*)afStack_16c)[k];
        thunk_FUN_005f2148(afStack_16c, afStack_ec, auStack_6c);
        copy16(afStack_1b0, (float*)afStack_16c + 3);
        if (bVar13) thunk_FUN_005f266e(afStack_1b0, 0, afStack_1b0);
        uint32_t uVar7 = *reinterpret_cast<uint32_t*>(selfObj);
        if (bVar1) {
            using Fn = void(__stdcall*)(int*, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xb0);
            fn(param_1, uVar7);
        } else {
            using Fn = void(__stdcall*)(int*, uint32_t, float*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x98);
            fn(param_1, uVar7, afStack_1b0);
        }
        break;
    }
    case 0x19: case 0x1a: case 0x1b: case 0x1c: {
        if (param_3 == 0) return 1;
        float* pfVar8 = *reinterpret_cast<float**>(static_cast<intptr_t>(param_3) + 0x28);
        copy16(afStack_1b0, pfVar8);
        bVar13 = (iVar5 == 0x1a || iVar5 == 0x1c);
        bVar1 = (iVar5 == 0x1b || iVar5 == 0x1c);
        pfVar8 = reinterpret_cast<float*>(DAT_00727c30 + 0x7c0);
        for (int k = 0; k < 16; k++) ((float*)afStack_ec)[3 + k] = pfVar8[k];
        thunk_FUN_005f2148(afStack_1b0, afStack_1b0, (float*)afStack_ec + 3);
        if (bVar13) thunk_FUN_005f266e(afStack_1b0, 0, afStack_1b0);
        uint32_t uVar7 = *reinterpret_cast<uint32_t*>(selfObj);
        if (bVar1) {
            using Fn = void(__stdcall*)(int*, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xb0);
            fn(param_1, uVar7);
        } else {
            using Fn = void(__stdcall*)(int*, uint32_t, float*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x98);
            fn(param_1, uVar7, afStack_1b0);
        }
        break;
    }
    case 0x1d: case 0x1e: case 0x1f: case 0x20: {
        if (param_3 == 0) return 1;
        float* pfVar8 = *reinterpret_cast<float**>(static_cast<intptr_t>(param_3) + 0x28);
        copy16(afStack_1b0, pfVar8);
        bVar13 = (iVar5 == 0x1e || iVar5 == 0x20);
        bVar1 = (iVar5 == 0x1f || iVar5 == 0x20);
        pfVar8 = reinterpret_cast<float*>(DAT_00727c30 + 0x7c0);
        for (int k = 0; k < 16; k++) ((float*)afStack_ec)[3 + k] = pfVar8[k];
        uint32_t* puVar9 = reinterpret_cast<uint32_t*>(DAT_00727c30 + 0x800);
        for (int k = 0; k < 16; k++) auStack_60[k] = puVar9[k];
        thunk_FUN_005f2148(afStack_1b0, afStack_1b0, (float*)afStack_ec + 3);
        thunk_FUN_005f2148(&uStack_1bc, &uStack_1bc, auStack_6c);
        if (bVar13) thunk_FUN_005f266e(afStack_1b0, 0, afStack_1b0);
        uint32_t uVar7 = *reinterpret_cast<uint32_t*>(selfObj);
        if (bVar1) {
            using Fn = void(__stdcall*)(int*, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xb0);
            fn(param_1, uVar7);
        } else {
            using Fn = void(__stdcall*)(int*, uint32_t, float*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x98);
            fn(param_1, uVar7, afStack_1b0);
        }
        break;
    }
    case 0x21: case 0x23: {
        if (param_3 != 0) {
            uint16_t uVar3a = *reinterpret_cast<uint16_t*>(static_cast<intptr_t>(param_4) + 0x20);
            iStack_1b4 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_3) + 0x20);
            iStack_1b8 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_3) + 0x24);
            void* pvVar4 = thunk_FUN_00533c78((uint32_t)uVar3a << 6);
            if (pvVar4 != nullptr) FUN_004127b0(pvVar4, 0x40, uVar3a, nullptr);
            if (*reinterpret_cast<int16_t*>(static_cast<intptr_t>(param_4) + 0x20) != 0) {
                uint32_t cnt = 0;
                do {
                    uint32_t uVar12 = cnt++;
                    uint32_t* puVar9 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>((uint32_t)*reinterpret_cast<uint16_t*>(*reinterpret_cast<int*>(static_cast<intptr_t>(param_4) + 4) + uVar12 * 2) * (uint32_t)iStack_1b8 * 0x10 + iStack_1b4));
                    uint32_t* puVar11 = reinterpret_cast<uint32_t*>(uVar12 * 0x40 + reinterpret_cast<intptr_t>(pvVar4));
                    for (int k = 0; k < 16; k++) puVar11[k] = puVar9[k];
                } while (cnt < uVar3a);
            }
            using Fn = void(__stdcall*)(int*, uint32_t, void*, uint16_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xa0);
            fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), pvVar4, *reinterpret_cast<uint16_t*>(static_cast<intptr_t>(param_4) + 0x20));
            operator_delete__(pvVar4);
        }
        break;
    }
    case 0x22: case 0x24: {
        if (param_3 != 0) {
            uint16_t uVar3b = *reinterpret_cast<uint16_t*>(static_cast<intptr_t>(param_4) + 0x20);
            iStack_1b8 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_3) + 0x20);
            iStack_1b4 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_3) + 0x24);
            void* pvVar4 = thunk_FUN_00533c78((uint32_t)uVar3b << 6);
            if (pvVar4 != nullptr) FUN_004127b0(pvVar4, 0x40, uVar3b, nullptr);
            if (*reinterpret_cast<int16_t*>(static_cast<intptr_t>(param_4) + 0x20) != 0) {
                uint32_t cnt = 0;
                do {
                    uint32_t uVar12 = cnt++;
                    uint32_t* puVar9 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>((uint32_t)*reinterpret_cast<uint16_t*>(*reinterpret_cast<int*>(static_cast<intptr_t>(param_4) + 4) + uVar12 * 2) * (uint32_t)iStack_1b4 * 0x10 + iStack_1b8));
                    uint32_t* puVar11 = reinterpret_cast<uint32_t*>(uVar12 * 0x40 + reinterpret_cast<intptr_t>(pvVar4));
                    for (int k = 0; k < 16; k++) puVar11[k] = puVar9[k];
                } while (cnt < uVar3b);
            }
            using Fn = void(__stdcall*)(int*, uint32_t, void*, uint16_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0xa0);
            fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), pvVar4, *reinterpret_cast<uint16_t*>(static_cast<intptr_t>(param_4) + 0x20));
            operator_delete__(pvVar4);
        }
        break;
    }
    case 0x29: {
        int i5 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_6) + 0x14);
        if (i5 != 0) {
            uStack_1c4 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x34);
            uStack_1c8 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x30);
            uStack_1bc = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x58);
            uStack_1c0 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x38);
            using Fn = void(__stdcall*)(int*, uint32_t, void*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x88);
            fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), &uStack_1c8);
        }
        break;
    }
    case 0x2a: {
        int i5 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_6) + 0x14);
        if (i5 != 0) {
            uStack_1c4 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x28);
            uStack_1c8 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x24);
            uStack_1bc = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x58);
            uStack_1c0 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x2c);
            using Fn = void(__stdcall*)(int*, uint32_t, void*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x88);
            fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), &uStack_1c8);
        }
        break;
    }
    case 0x2b: {
        int i5 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_6) + 0x14);
        if (i5 != 0) {
            uStack_1c4 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x40);
            uStack_1c8 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x3c);
            uStack_1bc = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x58);
            uStack_1c0 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x44);
            using Fn = void(__stdcall*)(int*, uint32_t, void*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x88);
            fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), &uStack_1c8);
        }
        break;
    }
    case 0x2c: {
        int i5 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_6) + 0x14);
        if (i5 != 0) {
            uStack_1c4 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x4c);
            uStack_1c8 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x48);
            uStack_1bc = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x58);
            uStack_1c0 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x50);
            using Fn = void(__stdcall*)(int*, uint32_t, void*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x88);
            fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), &uStack_1c8);
        }
        break;
    }
    case 0x2d: {
        if (*reinterpret_cast<int*>(static_cast<intptr_t>(param_6) + 0x14) != 0) {
            int i5 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_6) + 0x14);
            using Fn = void(__stdcall*)(int*, uint32_t, uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x78);
            fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(i5) + 0x54));
        }
        break;
    }
    case 0x30: {
        uStack_1c8 = 0x3f800000; uStack_1c4 = 0xbe257eb5; uStack_1c0 = 0x3c088865; uStack_1bc = 0xb9500c47;
        using Fn = void(__stdcall*)(int*, uint32_t, void*);
        Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x88);
        fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), &uStack_1c8);
        [[fallthrough]];
    }
    case 0x31: {
        uStack_1c8 = 0xbf000000; uStack_1c4 = 0xbd2aaaaa; uStack_1c0 = 0xbab60b61; uStack_1bc = 0x37d00d01;
        using Fn = void(__stdcall*)(int*, uint32_t, void*);
        Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x88);
        fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), &uStack_1c8);
        break;
    }
    case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: {
        int i5 = FUN_00540540(PTR_s_NDL_UpdateTime_007187c8);
        if (i5 == 0) return 0;
        fStack_170 = *reinterpret_cast<float*>(static_cast<intptr_t>(i5) + 0x10);
        float10 fVar14 = 0;
        int iVar5b = *param_1;
        switch (iVar5) {
        case 0x32: break;
        case 0x33: fVar14 = sinl((float10)fStack_170); break;
        case 0x34: fVar14 = cosl((float10)fStack_170); break;
        case 0x35: fVar14 = sinl((float10)fStack_170) / cosl((float10)fStack_170); break;
        case 0x36:
            afStack_16c[0] = (float)sinl((float10)fStack_170);
            afStack_16c[1] = (float)cosl((float10)fStack_170);
            afStack_16c[2] = (float)(sinl((float10)fStack_170) / cosl((float10)fStack_170));
            {
                using Fn = void(__stdcall*)(int*, uint32_t, void*);
                Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1)) + 0x88);
                fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), &fStack_170);
            }
            return 1;
        default: return 0;
        }
        fStack_170 = (float)fVar14;
        {
            using Fn = void(__stdcall*)(int*, uint32_t, float);
            Fn fn = *reinterpret_cast<Fn*>(static_cast<intptr_t>(iVar5b) + 0x78);
            fn(param_1, *reinterpret_cast<uint32_t*>(selfObj), fStack_170);
        }
        break;
    }
    default: return 0;
    }
    return 1;
}

// 0x5e3ea0 — observed shape: forwards to FUN_005c9b90 at self+8
void FUN_005e3ea0(void* self, uint32_t param_1)
{
    FUN_005c9b90(reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 8), reinterpret_cast<int*>(static_cast<intptr_t>(param_1)));
}

// 0x5e3ec0 — observed shape: cached +0x3c fast path, else iterate array at +0x28/+0x30 calling FUN_005e4850
int FUN_005e3ec0(void* self, uint32_t param_1)
{
    if (*reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x3c) != 0) {
        return FUN_005e4850();
    }
    uint32_t uVar3 = 0;
    if (*reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x30) != 0) {
        do {
            int iVar1 = *reinterpret_cast<int*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(self) + 0x28) + uVar3 * 4);
            if (iVar1 != 0) {
                int iVar2 = FUN_005e4850(param_1);
                if (iVar2 != 0) {
                    *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(self) + 0x3c) = iVar1;
                    return iVar2;
                }
            }
            uVar3 += 1;
        } while (uVar3 < *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 0x30));
    }
    return 0;
}
