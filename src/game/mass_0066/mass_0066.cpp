// Reconstruction batch mass_0066 — Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers/globals referenced by the observed listings (names preserved).
extern void* PTR_FUN_00710388;
extern void* PTR_FUN_007103a4;
extern void* PTR_FUN_0071037c;
extern void* PTR_LAB_00710370;
extern void* PTR_FUN_00710328;
extern int32_t DAT_008ea08c;
extern void* DAT_00727c30;
extern int32_t DAT_008cacf0;
extern int32_t DAT_008cace8;
extern int32_t DAT_008cacec;
extern int32_t DAT_008cacc4;
extern int32_t DAT_008ca338;
extern int32_t DAT_008c84d0;
extern int32_t DAT_008ca340;
extern float _DAT_007264c4;
extern int32_t DAT_007264c8;
extern int32_t DAT_008ea008;
extern int32_t DAT_00727444;
extern int32_t DAT_00726380;
extern int32_t DAT_0072637c;
extern int32_t DAT_008caba8;
extern int32_t DAT_008cabac;
extern int32_t DAT_00869b48;
extern int32_t DAT_008c84d8;
extern int32_t DAT_008c84dc;
extern int32_t DAT_008c8b64;
extern int32_t DAT_008c8ba4;
extern int32_t DAT_008cacc1;
extern void* PTR_FUN_006fd14c;
void FUN_004e6420();
void operator_delete(void* p);
void operator_delete__(void* p);
uint32_t FUN_00547730(uint32_t a, int32_t b, int32_t c);
uint32_t FUN_005012b0(int32_t id, int32_t a, uint32_t b);
void FUN_004d47f0(uint32_t a, int32_t b);
void FUN_00501370(int32_t id, int32_t a, uint32_t b);
uint32_t FUN_004f8e40(void* p);
uint32_t FUN_004f0280(const char* fmt, int32_t a, int32_t b);
void FUN_004f0ba0();
void FUN_004ac910(float v);
uint32_t FUN_005f0ddc();
void FUN_00533c78();
void FUN_00533d10(int32_t a, int32_t b);
void FUN_00534350();
void FUN_00534130();
void FUN_0050baf0();
void FUN_004bd640();
void FUN_0050bbc0(int32_t a);
void FUN_0050ba80();
void FUN_004bdca0();
void FUN_004baae0();
void FUN_004be3f0();
void FUN_004baca0();
void FUN_004bba60();
void FUN_004f6090(const char* fmt, ...);
void FUN_004b06c0();
void FUN_004f0420();
void FUN_0042e1d0(int32_t a);
void FUN_004d0cd0(int32_t a, int32_t b, int32_t c);
void FUN_004baf50();
void FUN_004f0d80(const char* fmt, ...);
void FUN_004f1700();
int32_t FUN_00533c78b();
void FUN_00412f10();

// 0x4eff80 — observed shape: sets vtable ptr twice (00710388 then 007103a4),
// invokes base dtor twice, deletes member at +8, conditionally deletes self.
void FUN_004eff80(void* self, uint8_t param_1) {
    uint32_t* v = (uint32_t*)self;
    *(void**)v = &PTR_FUN_00710388;
    FUN_004e6420();
    *(void**)v = &PTR_FUN_007103a4;
    FUN_004e6420();
    operator_delete__(*(void**)((uint8_t*)self + 8));
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x4effc0 — observed shape: index via vtable+4; free-list walk via vtable+8;
// insert new node via vtable+0x14 / vtable+0xc or reuse found node.
void FUN_004effc0(uint32_t* self) {
    int32_t index = ((int32_t(*)(uint32_t*))(*(void***)(*self + 4)))(self);
    (void)index;
    uint32_t* obj = *(uint32_t**)(self[2] + index * 4);
    for (;;) {
        if (obj == nullptr) {
            uint32_t* node = (uint32_t*)((void*(*)(uint32_t*))(*(void***)(*self + 0x14)))(self);
            ((void(*)(uint32_t*))(*(void***)(*self + 0xc)))(node);
            *node = *(uint32_t*)(self[2] + index * 4);
            *(uint32_t**)(self[2] + index * 4) = node;
            self[3] = self[3] + 1;
            return;
        }
        uint8_t c = ((uint8_t(*)(uint32_t*))(*(void***)(*self + 8)))(obj);
        if (c != 0) break;
        obj = (uint32_t*)*obj;
    }
    ((void(*)(uint32_t*))(*(void***)(*self + 0x10)))(obj);
    ((void(*)(uint32_t*))(*(void***)(*self + 0xc)))(obj);
}

// 0x4f0040 — observed shape: same free-list walk as 4effc0; on match copies
// uint16 at node+6 to out-retaddr param and returns 1 else 0.
uint32_t FUN_004f0040(uint32_t* self, uint16_t* out) {
    int32_t index = ((int32_t(*)(uint32_t*))(*(void***)(*self + 4)))(self);
    uint32_t* obj = *(uint32_t**)(self[2] + index * 4);
    while (obj != nullptr) {
        uint8_t c = ((uint8_t(*)(uint32_t*))(*(void***)(*self + 8)))(obj);
        if (c != 0) break;
        obj = (uint32_t*)*obj;
    }
    if (obj == nullptr) return 0;
    *out = *(uint16_t*)((uint8_t*)obj + 6);
    return 1;
}

// 0x4f0090 — observed shape: clear list via vtable+8 per node, zero +4..+12,
// reset vtable to 00710370 (00014).
void FUN_004f0090(uint32_t* self) {
    *(void**)self = &PTR_FUN_0071037c;
    uint32_t* node = (uint32_t*)self[1];
    while (node != nullptr) {
        uint32_t* next = (uint32_t*)*node;
        ((void(*)(uint32_t*))(*(void***)(*self + 8)))(node);
        node = next;
    }
    self[3] = 0; self[1] = 0; self[2] = 0;
    *(void**)self = &PTR_LAB_00710370;
}

// 0x4f00d0 — observed shape: vtable 007103a4, base dtor, delete +8, cond delete self.
void FUN_004f00d0(void* self, uint8_t param_1) {
    uint32_t* v = (uint32_t*)self;
    *(void**)v = &PTR_FUN_007103a4;
    FUN_004e6420();
    operator_delete__(*(void**)((uint8_t*)self + 8));
    if ((param_1 & 1) != 0) operator_delete(self);
}
// 0x4f0130 — observed shape: vtable+0x18 query into self[1]; if zero return 0 else FUN_00547730(id,0).
uint32_t FUN_004f0130(uint32_t* self, uint32_t param_1, uint32_t param_2) {
    int32_t id = ((int32_t(*)(uint32_t*))(*(void***)(*self + 0x18)))(param_2);
    self[1] = (uint32_t)id;
    if (id == 0) return 0;
    return FUN_00547730(param_1, id, 0);
}

// 0x4f0160 — observed shape: same vtable+0x18 pattern, tail-calls FUN_005012b0(id,0).
uint32_t FUN_004f0160(uint32_t* self, uint32_t param_1, uint32_t param_2) {
    int32_t id = ((int32_t(*)(uint32_t*))(*(void***)(*self + 0x18)))(param_2);
    self[1] = (uint32_t)id;
    if (id == 0) return 0;
    return FUN_005012b0(id, 0, param_1);
}

// 0x4f0190 — observed shape: vtable+0x18 into self[1], then FUN_004d47f0(0).
void FUN_004f0190(uint32_t* self, uint32_t param_1, uint32_t param_2) {
    int32_t id = ((int32_t(*)(uint32_t*))(*(void***)(*self + 0x18)))(param_2);
    self[1] = (uint32_t)id;
    FUN_004d47f0(param_1, 0);
}

// 0x4f01c0 — observed shape: vtable+0x18 into self[1], then FUN_00501370(id,0).
void FUN_004f01c0(uint32_t* self, uint32_t param_1, uint32_t param_2) {
    int32_t id = ((int32_t(*)(uint32_t*))(*(void***)(*self + 0x18)))(param_2);
    self[1] = (uint32_t)id;
    FUN_00501370(id, 0, param_1);
}

// 0x4f0230 — observed shape: ESI struct init (vtable 00710328, ECX at +8), optional DAT_00727c30+0x60 peer call vtable+0x1c into stack buffer; byte at +0x43 from stack byte.
void FUN_004f0230(uint32_t* self, uint32_t in_ecx, uint32_t in_esi) {
    (void)in_ecx;
    uint32_t* s = (uint32_t*)in_esi;
    uint8_t local_130[228];
    uint8_t bStack_4c = 0;
    uint32_t* piVar1 = nullptr;
    s[1] = 0; s[2] = in_ecx;
    *(void**)s = &PTR_FUN_00710328;
    if (DAT_008ea08c != 0) piVar1 = *(uint32_t**)((uint8_t*)&DAT_00727c30 + 0x60);
    ((void(*)(uint32_t*, uint8_t*))(*(void***)(*piVar1 + 0x1c)))(piVar1, local_130);
    *(uint8_t*)((uint8_t*)s + 0x43 * 4) = (uint8_t)((~bStack_4c) & 1);
}
// 0x4f0280 — observed shape: guard on DAT_008cacf0 and in_EAX vs DAT_008cace8/ec; else FUN_004f8e40(&param_2).
uint32_t FUN_004f0280(uint32_t param_1, uint8_t param_2, uint32_t in_eax) {
    (void)param_1;
    if ((DAT_008cacf0 == 0) || ((in_eax != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) return 0;
    return FUN_004f8e40(&param_2);
}

// 0x4f02c0 — observed shape: 4 slots x 0x19 uint32 zeroed; bit test vs iVar4; set slot0=1, bump DAT_008cacc4, log "Opening GamePad[%d] (0x%X)".
uint32_t FUN_004f02c0() {
    int32_t iVar4 = 0;
    uint32_t* puVar2 = (uint32_t*)&DAT_008ca338;
    int32_t iVar3 = 4;
    do {
        uint32_t* puVar5 = puVar2;
        for (int32_t iVar1 = 0x19; iVar1 != 0; iVar1--) { *puVar5 = 0; puVar5++; }
        if (((1u << ((uint8_t)iVar4 & 0x1f)) & 1u) != 0) {
            DAT_008cacc4 = DAT_008cacc4 + 1;
            *puVar2 = 1;
            FUN_004f0280((uint32_t)"Opening GamePad[%d] (0x%X)", iVar4, 1);
        }
        iVar4++; puVar2 += 0x19; iVar3--;
    } while (iVar3 != 0);
    return 1;
}

// 0x4f0320 — observed shape: stride 100 over 4 slots at DAT_008ca338; if nonzero call FUN_004f0ba0; store bool to DAT_008c84d0[i].
void FUN_004f0320() {
    uint32_t uVar1 = 0; int32_t iVar2 = 0;
    do {
        if (*(int32_t*)((int32_t)&DAT_008ca338 + uVar1) != 0) FUN_004f0ba0();
        (&DAT_008c84d0)[iVar2] = (*(int32_t*)((int32_t)&DAT_008ca338 + uVar1) != 0) ? 1 : 0;
        uVar1 += 100; iVar2++;
    } while (uVar1 < 400);
}

// 0x4f0420 — observed shape: per nonzero slot: 8 bit-pushes, 8 byte-pushes *0.003921569, 4 deadzone-normalized int16*3.05e-5 pushes via FUN_004ac910.
void FUN_004f0420() {
    uint16_t* puVar3 = (uint16_t*)&DAT_008ca340;
    int32_t local_c = 4;
    do {
        if (*(int32_t*)((uint8_t*)puVar3 - 4) != 0) {
            int32_t iVar2 = 0;
            do { FUN_004ac910((float)((*puVar3 >> ((uint8_t)iVar2 & 0x1f)) & 1)); iVar2++; } while (iVar2 < 8);
            uint16_t* puVar4 = puVar3 + 1; int32_t local_14 = 8;
            do { FUN_004ac910((float)(uint8_t)*puVar4 * 0.003921569f); puVar4 = (uint16_t*)((int32_t)puVar4 + 1); local_14--; } while (local_14 != 0);
            iVar2 = 0;
            do {
                float local_10 = (float)(int16_t)puVar3[iVar2 + 5] * 3.051851e-05f;
                float fVar1 = local_10 < 0 ? -local_10 : local_10;
                if ((fVar1 != fVar1) || (_DAT_007264c4 != _DAT_007264c4) || fVar1 < _DAT_007264c4 || fVar1 == _DAT_007264c4) {
                    if (local_10 <= 0.0f) local_10 = local_10 + _DAT_007264c4; else local_10 = local_10 - _DAT_007264c4;
                    local_10 = local_10 / (1.0f - _DAT_007264c4);
                } else local_10 = 0.0f;
                FUN_004ac910(local_10); iVar2++;
            } while (iVar2 < 4);
        }
        puVar3 += 0x32; local_c--;
    } while (local_c != 0);
}

// 0x4f0560 — observed shape: see full body below (allocates control state, builds two 0xC0 views, then "Press Start" loop with Sleep(10)).
void FUN_004f0560(uint32_t* param_1) {
    int32_t* local_c = (int32_t*)FUN_00533c78(0x14);
    if (local_c != nullptr) { local_c[0] = 0; local_c[1] = 0; }
    bool bVar9 = ((*param_1 & (1u << ((DAT_008caba8 - 1) & 0x1f))) == 0);
    bool bVar10 = false;
    if (DAT_008cabac != 0) bVar10 = ((*param_1 & (1u << ((DAT_008cabac - 1) & 0x1f))) != 0);
    bool bVar3 = !bVar10;
    uint32_t* local_10 = (uint32_t*)FUN_00533c78(0xc0);
    uint32_t uVar5m = (uint32_t)DAT_008ea008;
    if (local_10 != nullptr) {
        local_10[1] = 0; *(void**)local_10 = &PTR_FUN_006fd14c; local_10[7] = 0; local_10[0x19] = 0;
        DAT_00727444++; local_10[0x2f] = 0;
        FUN_004bdca0(uVar5m, 0, 0, 0x140, 0xf0, 0xffffffff, 0, 0, 0x80, 0x80);
    }
    uint32_t* local_8 = (uint32_t*)FUN_00533c78(0xc0);
    uint32_t uVar11m = (uint32_t)DAT_008ea008;
    uint32_t uVar6m = (uint32_t)DAT_00726380;
    uint32_t uVar5n = (uint32_t)DAT_0072637c;
    if (local_8 != nullptr) {
        local_8[1] = 0; *(void**)local_8 = &PTR_FUN_006fd14c; local_8[7] = 0;
        DAT_00727444++; local_8[0x19] = 0; local_8[0x2f] = 0;
        GetCurrentThreadId();
        FUN_004baae0(uVar11m); local_8[8] = 0;
        FUN_004be3f0(local_8, 0, 0, 0, uVar5n, uVar6m, 0x80ffffff, 0, 0, 0, 0, 0);
        if ((*(uint8_t*)((uint8_t*)local_8 + 8 * 4) & 1) == 0) FUN_004baca0();
    }
    FUN_00533d10(0, 1); FUN_00534350(); FUN_00534130(); FUN_0050baf0();
    uint32_t* puVar2 = (uint32_t*)*local_c;
    if (puVar2 != nullptr) puVar2[1]++;
    FUN_004bd640(puVar2);
    if (puVar2 != nullptr) { int32_t* pi = (int32_t*)puVar2 + 1; *pi--; if (*pi == 0) ((void(*)(uint32_t*))(*(void**)*puVar2))(1); }
    FUN_0050bbc0(0);
    bool bVar4 = bVar9;
    while (!bVar4 || !bVar3) {
        uint32_t uVar7 = 0;
        do { if (*(int32_t*)((int32_t)&DAT_008ca338 + uVar7) != 0) FUN_004f0ba0(); uVar7 += 100; } while (uVar7 < 400);
        int32_t iVar8 = (int32_t)((-(uint32_t)(DAT_008cabac != 0) & 0xffffff60u) + 0x140);
        if (local_8 != nullptr) { uint32_t u12 = 0, u11 = 0x42c80000; uint32_t u5 = FUN_005f0ddc(0x42c80000, 0); uint32_t u6 = FUN_005f0ddc(u5); FUN_004bba60(local_8, u6, u5, u11, u12); }
        if (!bVar4) {
            if (bVar9) {
                FUN_004f6090("Player 1,\nPress Start to continue");
                FUN_004b06c0(&DAT_00869b48, iVar8, 0xdc, 0x96, 0xff000000, 4, 0xffffffff, 0);
                FUN_004f0420(); FUN_0042e1d0(0);
                if ((DAT_008c84d8 < *(uint32_t*)((int32_t)&DAT_008c8b64 + DAT_008c84dc * 0x140)) || (DAT_008c84d8 < *(uint32_t*)((int32_t)&DAT_008c8ba4 + DAT_008c84dc * 0x140))) bVar4 = true;
            } else {
                if (local_10 != nullptr) { uint32_t u12 = 0, u11 = 0x42c80000; uint32_t u5 = FUN_005f0ddc(0x42c80000, 0); uint32_t u6 = FUN_005f0ddc(u5); FUN_004bba60(local_10, u6, u5, u11, u12); }
                FUN_004f6090("Player 1,\nPlease reconnect the\ncontroller to port @NUM.", DAT_008caba8);
                FUN_004b06c0(&DAT_00869b48, iVar8, 200, 0x96, 0xffff4040, 4, 0xffffffff, 0);
            }
        }
        if (DAT_008cabac != 0 && !bVar3) {
            if (bVar10) {
                if (local_10 != nullptr) { uint32_t u12 = 0, u11 = 0x42c80000; uint32_t u5 = FUN_005f0ddc(0x42c80000, 0); uint32_t u6 = FUN_005f0ddc(u5); FUN_004bba60(local_10, u6, u5, u11, u12); }
                FUN_004f6090("Player 2,\nPlease reconnect the\ncontroller to port @NUM.", DAT_008caba8);
                FUN_004b06c0(&DAT_00869b48, 0x1e0, 200, 0x96, 0xffff4040, 4, 0xffffffff, 0);
            } else {
                FUN_004f6090("Player 2,\nPress Start to continue");
                FUN_004b06c0(&DAT_00869b48, 0x1e0, 0xdc, 0x96, 0xff000000, 4, 0xffffffff, 0);
                FUN_004f0420(); FUN_0042e1d0(0);
                if ((DAT_008c84d8 < *(uint32_t*)((int32_t)&DAT_008c8b64 + DAT_008c84dc * 0x140)) || (DAT_008c84d8 < *(uint32_t*)((int32_t)&DAT_008c8ba4 + DAT_008c84dc * 0x140))) bVar3 = true;
            }
        }
        FUN_004d0cd0(0, 0, 0); Sleep(10);
    }
    FUN_0050ba80(); operator_delete(local_c); FUN_004baf50();
    if (local_8 != nullptr) ((void(*)(uint32_t*))(*(void**)*local_8))(1);
    FUN_004baf50();
    if (local_10 != nullptr) ((void(*)(uint32_t*))(*(void**)*local_10))(1);
    DAT_008cacc1 = 0;
}
// 0x4f0af0 — observed shape: clamp params to <=1.0; if slot enabled, write FUN_005f0ddc() to +0x60 / +0x62 offsets; return HRESULT-shaped CONCAT31(6 or 0x3e5).
uint32_t FUN_004f0af0(float param_1, float param_2, uint32_t in_ecx) {
    if (param_1 > 1.0f) param_1 = 1.0f;
    if (param_2 > 1.0f) param_2 = 1.0f;
    uint32_t iVar2 = 6;
    if ((&DAT_008ca338)[in_ecx * 0x19] != 0) {
        if (param_1 >= 0.0f) *(uint16_t*)((int32_t)&DAT_008ca398 + in_ecx * 100) = (uint16_t)FUN_005f0ddc();
        if (param_2 >= 0.0f) *(uint16_t*)((int32_t)&DAT_008ca39a + in_ecx * 100) = (uint16_t)FUN_005f0ddc();
        iVar2 = 0x3e5;
    }
    uint32_t hi = (iVar2 >> 8) & 0xffffffu;
    uint32_t lo = (iVar2 == 0x3e5) ? 1u : (iVar2 & 0xffu);
    return (hi << 8) | lo;
}

// 0x4f0ba0 — observed shape: joyGetPosEx(0) into zeroed JOYINFOEX; axes bias -0x7fff (0xffff->0x7fff), inverted Y/U; Z/R to bytes; buttons/POV to bitmask at self+4..; returns 1 on success else 0.
uint32_t FUN_004f0ba0(uint32_t* self) {
    JOYINFOEX local_34;
    uint8_t* b = (uint8_t*)self;
    uint32_t* d = (uint32_t*)self;
    uint32_t* p = (uint32_t*)&local_34;
    for (int i = 0xd; i != 0; i--) { *p = 0; p = (uint32_t*)((int32_t)p + 4); }
    local_34.dwSize = 0x34; local_34.dwFlags = 0x8ff;
    if (DAT_007264c8 == 0) {
        if (joyGetPosEx(0, &local_34) == 0) {
            d[0] = 0; d[1] = 0; d[2] = 0; d[3] = 0; d[4] = 0; d[5] = 0;
            int16_t s;
            if (local_34.dwXpos == 0xffff) s = 0x7fff; else s = (int16_t)local_34.dwXpos - (int16_t)0x7fff;
            *(int16_t*)(b + 0xe) = s;
            if (local_34.dwYpos == 0xffff) s = 0x7fff; else s = (int16_t)local_34.dwYpos - (int16_t)0x7fff;
            *(int16_t*)(b + 0x10) = -s;
            if (local_34.dwVpos == 0xffff) s = 0x7fff; else s = (int16_t)local_34.dwVpos - (int16_t)0x7fff;
            *(int16_t*)(b + 0x12) = s;
            if (local_34.dwUpos == 0xffff) s = 0x7fff; else s = (int16_t)local_34.dwUpos - (int16_t)0x7fff;
            *(int16_t*)(b + 0x14) = -s;
            b[0xc] = (uint8_t)(local_34.dwZpos & 0xff);
            b[0xd] = (uint8_t)(local_34.dwRpos & 0xff);
            if (local_34.dwButtons & 1) b[6] = 0xff;
            if (local_34.dwButtons & 2) b[7] = 0xff;
            if (local_34.dwButtons & 4) b[8] = 0xff;
            if (local_34.dwButtons & 8) b[9] = 0xff;
            if (local_34.dwButtons & 0x10) b[10] = 0xff;
            if (local_34.dwButtons & 0x20) b[11] = 0xff;
            if (local_34.dwButtons & 0x40) b[4] |= 0x10;
            if ((int8_t)local_34.dwButtons < 0) b[4] |= 0x20;
            if (local_34.dwButtons & 0x100) b[4] |= 0x40;
            if (local_34.dwButtons & 0x200) b[4] |= 0x80;
            uint32_t pov = local_34.dwPOV;
            if (pov == 0) { b[4] |= 1; return 1; }
            if (pov == 0x1194) { b[4] |= 9; return 1; }
            if (pov == 9000) { b[4] |= 8; return 1; }
            if (pov == 0x34bc) { b[4] |= 10; return 1; }
            if (pov == 18000) { b[4] |= 2; return 1; }
            if (pov == 0x57e4) { b[4] |= 6; return 1; }
            if (pov == 27000) { b[4] |= 4; return 1; }
            if (pov == 0x7b0c) b[4] |= 5;
            return 1;
        }
    }
    return 0;
}

// 0x4f0d80 — observed shape: identical guard to 0x4f0280 (duplicate address body), else FUN_004f8e40(&param_2).
uint32_t FUN_004f0d80(uint32_t param_1, uint8_t param_2, uint32_t in_eax) {
    (void)param_1;
    if ((DAT_008cacf0 == 0) || ((in_eax != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) return 0;
    return FUN_004f8e40(&param_2);
}

// 0x4f0dc0 — observed shape: log Closing, UnmapView(+0xc), CloseHandle(+8), release (+0x18), CloseHandle(+4), clear refcounted string at +0x1c.
uint32_t FUN_004f0dc0(uint32_t* self) {
    FUN_004f0d80((uint32_t)"Closing %s", *(uint32_t*)((uint8_t*)self + 0x1c));
    if (*(void**)((uint8_t*)self + 0xc) != nullptr) {
        UnmapViewOfFile(*(void**)((uint8_t*)self + 0xc));
        *(uint32_t*)((uint8_t*)self + 0x14) = 0;
        *(uint32_t*)((uint8_t*)self + 0x10) = 0;
        *(uint32_t*)((uint8_t*)self + 0xc) = 0;
    }
    if (*(HANDLE*)((uint8_t*)self + 8) != nullptr) { CloseHandle(*(HANDLE*)((uint8_t*)self + 8)); *(uint32_t*)((uint8_t*)self + 8) = 0; }
    if (*(uint32_t**)((uint8_t*)self + 0x18) != nullptr) { ((void(*)(int32_t))(*(void***)(**(void**)((uint8_t*)self + 0x18))))(1); *(uint32_t*)((uint8_t*)self + 0x18) = 0; }
    if (*(HANDLE*)((uint8_t*)self + 4) != nullptr) { CloseHandle(*(HANDLE*)((uint8_t*)self + 4)); *(uint32_t*)((uint8_t*)self + 4) = 0; }
    uint8_t* s = *(uint8_t**)((uint8_t*)self + 0x1c);
    if (*(int32_t*)(s - 4) != 0) { *s = 0; *(int32_t*)(s - 4) = 0; }
    return 0;
}

// 0x4f0e40 — observed shape: open file with access/disposition by param_2&3; size log; optional memory-map via FUN_00533c78/FUN_004f1700; returns 1/3/0.
uint32_t FUN_004f0e40(uint32_t* self, uint32_t param_1, uint32_t param_2, uint8_t param_3, uint32_t param_4) {
    (void)param_1;
    if (param_1 == 0) return 1;
    uint8_t** pp = (uint8_t**)((uint8_t*)self + 0x1c);
    FUN_00412f10();
    uint8_t* pcVar3 = *pp;
    uint8_t* pcVar6 = pcVar3 + *(int32_t*)(pcVar3 - 4);
    for (; pcVar3 < pcVar6; pcVar3++) if (*pcVar3 == '/') *pcVar3 = '\\';
    *(uint32_t*)((uint8_t*)self + 0x20) = param_2;
    param_2 = param_2 & 3;
    uint32_t DVar7; uint32_t dwCreationDisposition;
    if (param_2 == 1) { DVar7 = 0x80000000; dwCreationDisposition = 3; }
    else if (param_2 == 2) { DVar7 = 0xc0000000; dwCreationDisposition = 2; }
    else { if (param_2 != 3) return 3; DVar7 = 0xc0000000; dwCreationDisposition = 4; }
    HANDLE hFile = CreateFileA((const char*)*pp, DVar7, 1, nullptr, dwCreationDisposition,
        (uint32_t)((-(uint32_t)((param_3 & 2) != 0) & 0x8000000u) + 0x8000080u), nullptr);
    if (hFile == (HANDLE)-1) return 1;
    *(HANDLE*)((uint8_t*)self + 4) = hFile;
    uint32_t DVar8 = GetFileSize(hFile, nullptr);
    float fVar2 = (float)(int32_t)DVar8;
    *(uint32_t*)((uint8_t*)self + 0x24) = DVar8;
    if ((int32_t)DVar8 < 0) fVar2 += 4.2949673e+09f;
    FUN_004f0d80((uint32_t)"Opening %s (%.1fKb)", *(uint32_t*)pp, (double)(fVar2 * 0.0009765625f));
    if (param_4 != 0 && *(uint32_t*)((uint8_t*)self + 0x20) != 3) {
        if (FUN_00533c78b() != 0) {
            FUN_004f1700(); *(uint32_t*)((uint8_t*)self + 0x18) = (uint32_t)0; return 0;
        }
        *(uint32_t*)((uint8_t*)self + 0x18) = 0;
    }
    return 0;
}
