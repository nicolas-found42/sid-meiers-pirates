// Reconstruction batch mass_0058 — Sid Meier's Pirates! (2004), PE32 i386.
// Target image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern declarations (only symbols referenced by the observed listings)
// ---------------------------------------------------------------------------
extern int32_t  DAT_00869ab0;
extern int32_t  DAT_00869ad0;
extern int32_t  DAT_00869ab4;
extern int32_t  DAT_00869ab8;
extern int32_t  DAT_00869abc;
extern int32_t  DAT_00869ac0;
extern int32_t  DAT_00869ac4;
extern int32_t  DAT_00869ac8;
extern int32_t  DAT_00869acc;
extern int32_t  DAT_008142f8;
extern int32_t  DAT_00814318;
extern int32_t  DAT_0081431a;
extern int32_t  DAT_0085a158;
extern uint32_t DAT_008c8278[0x40];
extern int32_t  DAT_008cacf0;
extern int32_t  DAT_008cace8;
extern int32_t  DAT_008cacec;
extern int32_t  DAT_00723b08;
extern int32_t  DAT_00723b14;
extern int32_t  DAT_00726490;
extern int32_t  DAT_00726494;
extern int32_t  DAT_00726498;
extern int32_t  DAT_0072649c;
extern int32_t  DAT_007264a0;
extern int32_t  DAT_0071779c;
extern int32_t  DAT_007177a0;
extern int32_t  DAT_007177a4;
extern int32_t  DAT_007177a8;
extern int32_t  DAT_0072cd78;
extern int32_t  DAT_00727430;
extern int32_t  DAT_008ca120;
extern int32_t  DAT_008cac5c;
extern uint8_t  DAT_00814324[0x4300];
extern uint8_t  DAT_008c99d8[0x100];
extern uint8_t  DAT_008ea04c[0x18];
extern void*    DAT_008e9fe8;
extern int32_t  DAT_008ea050;
extern void*    PTR_FUN_007108ac;
extern void*    PTR_FUN_00717a84;
extern void*    PTR_FUN_0070bf10;
extern void*    PTR_FUN_0070bf4c;
extern void*    PTR_FUN_0070bed4;
extern void*    PTR_s_WakeSpreadFunc_00727308;
extern uint32_t _DAT_00726490;
extern uint32_t _DAT_00726494;
extern uint32_t _DAT_00726498;
extern uint32_t _DAT_0072649c;
extern uint32_t _DAT_007264a0;
extern uint32_t _DAT_007276... // (globals declared below use observed DAT_* names)

// Helpers referenced by the listings (signatures preserved from the decompiler).
extern void     FUN_004889c0(void* pAddr, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t a7);
extern int32_t  FUN_004e0880(void* self);
extern int32_t  FUN_004e0350(void* self);
extern int32_t  FUN_00404910(uint32_t flags);
extern int32_t  FUN_004dff80(void* self);
extern uint32_t FUN_004f8e40(void* pParam);
extern void*    FUN_0054aad0(void);
extern uint32_t FUN_004e08d0(const char* fmt, ...);
extern int32_t  FUN_005f0ddc(void);
extern void     FUN_004f8fa0(void* a, void* b);
extern char     FUN_004f96a0(void);
extern void     FUN_004f8f50(void);
extern void     FUN_004f9820(void* p);
extern void     FUN_004f98b0(const char* name, void* pOut);
extern char     FUN_004f9790(void* p);
extern void     FUN_004e1470(void* self);
extern void     FUN_004e0d10(void);
extern int32_t  FUN_00533c78(uint32_t n);
extern void*    FUN_005473e0(uint32_t sz, void* a, void* b, void* c, void* d, int32_t e, int32_t f, int32_t g, int32_t h, int32_t i, int32_t j);
extern void*    FUN_00542a40(void* pName);
extern void     FUN_00540c50(void);
extern int32_t  FUN_005426d0(void);
extern void     FUN_00534130(void);
extern void     FUN_00534350(void);
extern void     FUN_004e4ea0(void);
extern void     FUN_004e2c10(void);
extern void     FUN_00491640(void);
extern char     FUN_004284c0(void* p);
extern int32_t  FUN_005412c0(int32_t v);
extern char     FUN_00514ae0(float a, float b, float c, float d, float e, float f, float g, float h);
extern uint32_t FUN_00548120(uint32_t v, void* p);
extern void     FUN_00533d10(float v, int32_t flag);
extern void     operator_delete(void* p);

// ---------------------------------------------------------------------------
// 0x4e02a0 — observed shape: self is int32 array at in_ESI; field 0x12 selects
// next state; calls FUN_004e0880 / FUN_004e0350; emits DAT_008c8278 with 0x36.
// ---------------------------------------------------------------------------
// 0x4e02a0 — observed shape
void FUN_004e02a0(void* self)
{
    int32_t* s = static_cast<int32_t*>(self);
    int32_t  sel = s[0x12];
    int32_t  next = 0;
    switch (sel) {
    default:
        next = sel - 1;
        break;
    case 0x12:
    case 0x13:
        s[0x12] = 6;
        goto after;
    case 0x14:
    case_d_14: {
        char c = static_cast<char>(FUN_004e0880(self));
        next = ((-(uint32_t)(c != '\0') & 0xdu) + 6);
        break;
    }
    case -1:
    case 1:
        if (s[0] == 0) {
            int32_t r = FUN_004e0350(self);
            next = ((r < 1 ? 1 : 0) - 1 & 0xc) + 6;
        } else {
            if (s[0x15] == -1) goto case_d_14;
            next = 0x15;
        }
        break;
    }
    s[0x12] = next;
after:
    FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xbf800000u, 0xffffffffu);
}

// ---------------------------------------------------------------------------
// 0x4e0350 — observed shape: self at in_EDX+0x34; computes weighted sum of four
// int fields when +0x34 != 0, clamps to min with +0x10.
// ---------------------------------------------------------------------------
// 0x4e0350 — observed shape
int32_t FUN_004e0350(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t  total = 0;
    auto rd = [&](uintptr_t off) -> int32_t {
        return *reinterpret_cast<int32_t*>(base + off);
    };
    if (rd(0x34) != 0) {
        total = rd(0x38) * DAT_00869ac0 + rd(0x3c) * DAT_00869ac4 +
                rd(0x40) * DAT_00869ac8 + rd(0x34) * DAT_00869abc;
    }
    if (rd(0x10) < total) {
        total = rd(0x10);
    }
    return total;
}

// ---------------------------------------------------------------------------
// 0x4e0390 — observed shape: writes four uint32 outputs via in_EAX/in_ECX/
// in_ESI/in_EDI (receiver slots) and switches on param_1 % 9.
// ---------------------------------------------------------------------------
// 0x4e0390 — observed shape
uint32_t FUN_004e0390(void* self, int32_t param_1, uint32_t* out_eax, uint32_t* out_ecx, uint32_t* out_esi, uint32_t* out_edi)
{
    (void)self;
    *out_eax = 0;
    *out_esi = 0;
    *out_ecx = 5;
    *out_edi = 0xe71c71c8u;
    switch (param_1 % 9) {
    case 0:
        *out_esi = 0xfffffffbu;
        *out_ecx = 0xc;
        return 0;
    case 1:
        *out_ecx = 10;
        *out_edi = 0xeaaaaaabu;
        return 0;
    case 2:
        *out_ecx = 9;
        *out_esi = 2;
        return 0;
    case 3:
        *out_ecx = 9;
        *out_edi = 0xe0000000u;
        return 0;
    case 4:
        *out_ecx = 8;
        *out_esi = 4;
        return 0;
    case 5:
        *out_esi = 2;
        *out_ecx = 8;
        return 0;
    case 6:
        *out_ecx = 6;
        break;
    case 7:
    case 8:
        *out_ecx = 5;
        return 0;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x4e0460 — observed shape: param_1+0x54 indexes DAT_008142f8 table (0x22e
// stride); local_20 budget array; second loop strides bytes 0x1170 with four
// per-slot adjustments; final compare against ((DAT_00814318+DAT_0081431a)*
// (DAT_0085a158+2)*iVar4*2)/300 + iVar4*2.
// ---------------------------------------------------------------------------
// 0x4e0460 — observed shape
bool FUN_004e0460(int32_t param_1)
{
    int32_t iVar4 = DAT_00869ab0;
    int32_t iVar7 = 0;
    int16_t* psVar6 = reinterpret_cast<int16_t*>(&DAT_008142f8);
    int32_t local_20[8] = {0,0,0,0,0,0,0,0};
    int32_t iVar2, iVar3;
    do {
        int16_t s = *psVar6;
        local_20[iVar7] = static_cast<int32_t>(psVar6[0x13]);
        if (s != -1) {
            iVar2 = 0; // FUN_0045ba40() — referenced helper
            (void)iVar2;
            local_20[iVar7] = iVar2;
            iVar4 = iVar4 - iVar2;
        }
        psVar6 = psVar6 + 0x22e;
        iVar7 = iVar7 + 1;
    } while (reinterpret_cast<intptr_t>(psVar6) < 0x8165d8);
    if (iVar4 < 0) {
        return true;
    }
    if (1 < DAT_00869ad0) {
        iVar4 = -iVar4;
        while (0 < iVar4) {
            iVar7 = 0;
            iVar2 = -1;
            iVar3 = 0;
            if (0 < DAT_00869ad0) {
                do {
                    if (iVar7 <= local_20[iVar3]) {
                        iVar7 = local_20[iVar3];
                        iVar2 = iVar3;
                    }
                    iVar3 = iVar3 + 1;
                } while (iVar3 < DAT_00869ad0);
                if (iVar2 != -1) {
                    local_20[iVar3] = local_20[iVar3] + -1;
                }
            }
            iVar4 = iVar4 + -1;
        }
    }
    iVar4 = 0;
    int32_t* piVar8 = local_20 + 1;
    uint8_t* pbVar5 = &DAT_00814324;
    int32_t table_base = reinterpret_cast<int32_t>(&DAT_00723b14);
    uint8_t* p1 = reinterpret_cast<uint8_t*>(param_1);
    int32_t p1_54 = *reinterpret_cast<int32_t*>(p1 + 0x54);
    do {
        if (*reinterpret_cast<int16_t*>(pbVar5 + -0x2c) != -1) {
            iVar7 = *reinterpret_cast<int32_t*>(table_base + (&DAT_008142f8)[p1_54 * 0x22e] * 0x44);
            if ((*pbVar5 & 4) != 0) iVar7 = iVar7 + iVar7 / 2;
            iVar2 = piVar8[-1];
            if (iVar7 < iVar2) { iVar4 = iVar2 - iVar7; piVar8[-1] = iVar7; }
            else if (0 < iVar4) {
                iVar3 = iVar4;
                if (iVar7 - iVar2 < iVar4) iVar3 = iVar7 - iVar2;
                piVar8[-1] = iVar2 + iVar3; iVar4 = iVar4 - iVar3;
            }
        }
        if (*reinterpret_cast<int16_t*>(pbVar5 + 0x430) != -1) {
            iVar7 = *reinterpret_cast<int32_t*>(table_base + (&DAT_008142f8)[p1_54 * 0x22e] * 0x44);
            if ((pbVar5[0x45c] & 4) != 0) iVar7 = iVar7 + iVar7 / 2;
            iVar2 = *piVar8;
            if (iVar7 < iVar2) { iVar4 = iVar2 - iVar7; *piVar8 = iVar7; }
            else if (0 < iVar4) {
                iVar3 = iVar4;
                if (iVar7 - iVar2 < iVar4) iVar3 = iVar7 - iVar2;
                *piVar8 = iVar2 + iVar3; iVar4 = iVar4 - iVar3;
            }
        }
        if (*reinterpret_cast<int16_t*>(pbVar5 + 0x88c) != -1) {
            iVar7 = *reinterpret_cast<int32_t*>(table_base + (&DAT_008142f8)[p1_54 * 0x22e] * 0x44);
            if ((pbVar5[0x8b8] & 4) != 0) iVar7 = iVar7 + iVar7 / 2;
            iVar2 = piVar8[1];
            if (iVar7 < iVar2) { iVar4 = iVar2 - iVar7; piVar8[1] = iVar7; }
            else if (0 < iVar4) {
                iVar3 = iVar4;
                if (iVar7 - iVar2 < iVar4) iVar3 = iVar7 - iVar2;
                piVar8[1] = iVar2 + iVar3; iVar4 = iVar4 - iVar3;
            }
        }
        if (*reinterpret_cast<int16_t*>(pbVar5 + 0xce8) != -1) {
            iVar7 = *reinterpret_cast<int32_t*>(table_base + (&DAT_008142f8)[p1_54 * 0x22e] * 0x44);
            if ((pbVar5[0xd14] & 4) != 0) iVar7 = iVar7 + iVar7 / 2;
            iVar2 = piVar8[2];
            if (iVar7 < iVar2) { iVar4 = iVar2 - iVar7; piVar8[2] = iVar7; }
            else if (0 < iVar4) {
                iVar3 = iVar4;
                if (iVar7 - iVar2 < iVar4) iVar3 = iVar7 - iVar2;
                piVar8[2] = iVar2 + iVar3; iVar4 = iVar4 - iVar3;
            }
        }
        pbVar5 = pbVar5 + 0x1170;
        piVar8 = piVar8 + 4;
    } while (reinterpret_cast<intptr_t>(pbVar5) < 0x816604);
    int32_t tbl08 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(&DAT_00723b08) + static_cast<intptr_t>(DAT_008142f8) * 0x44);
    iVar4 = (DAT_008142f8 / 9) * tbl08;
    iVar4 = tbl08 + ((iVar4 + (static_cast<uint32_t>(iVar4) >> 0x1f & 3u)) >> 2);
    int32_t rhs = (((DAT_00814318 + DAT_0081431a) * (DAT_0085a158 + 2) * iVar4 * 2) / 300 + iVar4 * 2);
    return local_20[0] < rhs;
}

// ---------------------------------------------------------------------------
// 0x4e0700 — observed shape: self at in_ESI; loop over inventory globals
// DAT_00869ab*/ac*; decrements counts, adds to DAT_00869ab4, updates +0x10
// stock, +0x50=400 on underflow; emits FUN_00404910 each iteration.
// ---------------------------------------------------------------------------
// 0x4e0700 — observed shape
void FUN_004e0700(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    auto rd = [&](uintptr_t off) -> uint32_t {
        return *reinterpret_cast<uint32_t*>(base + off);
    };
    auto wr = [&](uintptr_t off, uint32_t v) {
        *reinterpret_cast<uint32_t*>(base + off) = v;
    };
    uint32_t uVar1;
    if ((rd(0x54) == 0xffffffffu) || (base[0x58] != '\0')) {
        uVar1 = 1;
    } else {
        uVar1 = rd(0x54) & 0xffffff00u;
    }
    uVar1 = static_cast<uint32_t>(FUN_00404910(uVar1));
    for (;;) {
        if (static_cast<int32_t>(uVar1) >= 0) {
            return;
        }
        if (DAT_00869ac0 < 1) {
            if (DAT_00869ac8 < 1) {
                if (DAT_00869ac4 < 1) {
                    if (DAT_00869abc < 1) {
                        if ((0 < DAT_00869ab8) || (0 < DAT_00869acc)) {
                            uVar1 = static_cast<uint32_t>(FUN_004dff80(self));
                        }
                    } else {
                        uVar1 = rd(0x10);
                        if (static_cast<int32_t>(uVar1) < static_cast<int32_t>(rd(0x34))) goto underflow;
                        wr(0x18, rd(0x18) + 1);
                        DAT_00869abc = DAT_00869abc - 1;
                        DAT_00869ab4 = DAT_00869ab4 + static_cast<int32_t>(rd(0x34));
                        wr(0x10, rd(0x10) - rd(0x34));
                        wr(4, 0);
                    }
                } else {
                    uVar1 = rd(0x10);
                    if (static_cast<int32_t>(uVar1) < static_cast<int32_t>(rd(0x3c))) goto underflow;
                    wr(0x20, rd(0x20) + 1);
                    DAT_00869ac4 = DAT_00869ac4 - 1;
                    DAT_00869ab4 = DAT_00869ab4 + static_cast<int32_t>(rd(0x3c));
                    wr(0x10, rd(0x10) - rd(0x3c));
                    wr(4, 0);
                }
            } else {
                uVar1 = rd(0x10);
                if (static_cast<int32_t>(uVar1) < static_cast<int32_t>(rd(0x40))) goto underflow;
                wr(0x24, rd(0x24) + 1);
                DAT_00869ac8 = DAT_00869ac8 - 1;
                DAT_00869ab4 = DAT_00869ab4 + static_cast<int32_t>(rd(0x40));
                wr(0x10, rd(0x10) - rd(0x40));
                wr(4, 0);
            }
        } else {
            uVar1 = rd(0x10);
            if (static_cast<int32_t>(uVar1) < static_cast<int32_t>(rd(0x38))) {
            underflow:
                wr(0x50, 400);
            } else {
                wr(0x1c, rd(0x1c) + 1);
                DAT_00869ac0 = DAT_00869ac0 - 1;
                DAT_00869ab4 = DAT_00869ab4 + static_cast<int32_t>(rd(0x38));
                wr(0x10, rd(0x10) - rd(0x38));
                wr(4, 0);
            }
        }
        if ((rd(0x54) == static_cast<uint32_t>(-1)) || (base[0x58] != '\0')) {
            uVar1 = 1;
        } else {
            uVar1 = uVar1 & 0xffffff00u;
        }
        uVar1 = static_cast<uint32_t>(FUN_00404910(uVar1));
    }
}

// ---------------------------------------------------------------------------
// 0x4e0880 — observed shape: self at in_ECX; sums fields 5..10; flag at
// 0x15/0x16; returns 1 iff sum>0, self[0]!=0 and FUN_00404910>0.
// ---------------------------------------------------------------------------
// 0x4e0880 — observed shape
uint32_t FUN_004e0880(void* self)
{
    int32_t* s = static_cast<int32_t*>(self);
    uint32_t uVar1 = static_cast<uint32_t>(s[10] + s[9] + s[8] + s[7] + s[6] + s[5]);
    if ((0 < static_cast<int32_t>(uVar1)) && (s[0] != 0)) {
        if ((s[0x15] == -1) || (static_cast<char>(s[0x16]) != '\0')) {
            uVar1 = 1;
        } else {
            uVar1 = uVar1 & 0xffffff00u;
        }
        int32_t r = FUN_00404910(uVar1);
        if (0 < r) {
            return 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x4e08d0 — observed shape: guards on DAT_008cacf0 / DAT_008cace8/ec and
// in_EAX; forwards to FUN_004f8e40(&param_2).
// ---------------------------------------------------------------------------
// 0x4e08d0 — observed shape
uint32_t FUN_004e08d0(void* self, uint32_t param_1, uint8_t param_2, int32_t in_eax)
{
    (void)self; (void)param_1;
    if ((DAT_008cacf0 == 0) || ((in_eax != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
        return 0;
    }
    return FUN_004f8e40(&param_2);
}

// ---------------------------------------------------------------------------
// 0x4e0910 — observed shape: self at in_ESI; stores params into slots 1/2;
// ref-counted pointer swap via FUN_0054aad0 vtable+8; checks byte at +0x24
// == 8; otherwise logs via FUN_004e08d0 and clears.
// ---------------------------------------------------------------------------
// 0x4e0910 — observed shape
uint32_t FUN_004e0910(void* self, int32_t param_1, int32_t param_2)
{
    int32_t* s = static_cast<int32_t*>(self);
    struct RefObj { void* vtbl; int32_t refs; };
    void* obj = FUN_0054aad0();
    (void)obj;
    s[2] = param_2;
    s[1] = param_1;
    uint32_t* next = reinterpret_cast<uint32_t*>(obj);
    uint32_t* cur = reinterpret_cast<uint32_t*>(s[0]);
    if (cur != next) {
        if (cur != nullptr) {
            // Decrement ref; destroy at zero via vtable call.
            int32_t* rc = reinterpret_cast<int32_t*>(cur + 1);
            *rc = *rc - 1;
            if (*rc == 0) {
                using Fn = void (__cdecl*)(uint32_t);
                auto fn = *reinterpret_cast<Fn*>(cur);
                fn(1);
            }
        }
        s[0] = reinterpret_cast<int32_t>(next);
        if (next == nullptr) goto no_image;
        reinterpret_cast<int32_t*>(next)[1] += 1;
    }
    {
        int32_t img = s[0];
        if (img != 0) {
            if (*reinterpret_cast<char*>(img + 0x24) == '\b') {
                return static_cast<uint32_t>((img >> 8) & 0xffffff) | 1u;
            }
            uint32_t msg = FUN_004e08d0("Expecting 8BPP function image: %s");
            uint32_t* p = reinterpret_cast<uint32_t*>(s[0]);
            if (p != nullptr) {
                int32_t* rc = reinterpret_cast<int32_t*>(p + 1);
                *rc = *rc - 1;
                if (*rc == 0) {
                    using Fn = void (__cdecl*)(uint32_t);
                    auto fn = *reinterpret_cast<Fn*>(p);
                    fn(1);
                }
                s[0] = 0;
            }
            return msg & 0xffffff00u;
        }
    }
no_image:
    {
        uint32_t msg = FUN_004e08d0("Could not load wake function image: %s");
        return msg & 0xffffff00u;
    }
}

// ---------------------------------------------------------------------------
// 0x4e09b0 — observed shape: self at in_ESI; param_1 scaled vs frame count at
// (**self+0x38)-1, rounded via modf; indexes byte image at +0x34/+0x40 via
// FUN_005f0ddc(); returns byte*0.003921569*scale + offset.
// ---------------------------------------------------------------------------
// 0x4e09b0 — observed shape
long double FUN_004e09b0(void* self, float param_1)
{
    int32_t* s = static_cast<int32_t*>(self);
    if (s[0] == 0) {
        return static_cast<long double>(static_cast<float>(s[2]));
    }
    int32_t img = s[0];
    int32_t n = **(int32_t**)(img + 0x38) - 1;
    float f = static_cast<float>(n);
    if (n < 0) f = f + 4294967296.0f;
    double integral = 0.0;
    double frac = modf(static_cast<double>(f * param_1), &integral);
    (void)frac;
    int32_t data = **(int32_t**)(img + 0x40);
    int32_t off  = *(int32_t*)(img + 0x34);
    int32_t k = FUN_005f0ddc();
    uint8_t byte = *reinterpret_cast<uint8_t*>(data + off + k);
    return static_cast<long double>(byte) * (long double)0.003921569f *
           static_cast<long double>(static_cast<float>(s[1])) +
           static_cast<long double>(static_cast<float>(s[2]));
}

// ---------------------------------------------------------------------------
// 0x4e0a80 — observed shape: self at in_EDI; floor-based fractional index
// via _CIfmod; two byte samples from image (+0x34/+0x40 via FUN_005f0ddc);
// bilinear-style blend scaled by 0.003921569.
// ---------------------------------------------------------------------------
// 0x4e0a80 — observed shape
long double FUN_004e0a80(void* self, float param_1)
{
    int32_t* s = static_cast<int32_t*>(self);
    int32_t img = s[0];
    if (img == 0) {
        return static_cast<long double>(static_cast<float>(s[2]));
    }
    int32_t n = **(int32_t**)(img + 0x38) - 1;
    float f = static_cast<float>(n);
    if (n < 0) f = f + 4294967296.0f;
    (void)floor(static_cast<double>(f * param_1));
    float frac = static_cast<float>((terrainCIfmodStub()));
    int32_t data = **(int32_t**)(img + 0x40);
    int32_t off  = *(int32_t*)(img + 0x34);
    int32_t k = FUN_005f0ddc();
    uint8_t b0 = *reinterpret_cast<uint8_t*>(data + off + k);
    img = s[0];
    (void)floor(static_cast<double>(f * param_1));
    int32_t data2 = *(int32_t*)(img + 0x40);
    int32_t k2 = FUN_005f0ddc();
    uint8_t b1 = *reinterpret_cast<uint8_t*>(data2 + k2 + *(int32_t*)(img + 0x34));
    long double t = static_cast<long double>(frac);
    long double v = (static_cast<long double>(b1) * t +
                     (1.0L - t) * static_cast<long double>(b0));
    return v * (long double)0.003921569f *
           static_cast<long double>(static_cast<float>(s[1])) +
           static_cast<long double>(static_cast<float>(s[2]));
}

// ---------------------------------------------------------------------------
// 0x4e0b60 — observed shape: in_EAX receiver; initializes 512-byte buffers,
// opens wake ini via FUN_004f8fa0/FUN_004f96a0; reads WakeSpreadFunc table
// (2 entries) building "%sScale"/"%sOffset" keys, loads via FUN_004e0910.
// ---------------------------------------------------------------------------
// 0x4e0b60 — observed shape
uint32_t FUN_004e0b60(void* self, void* in_eax)
{
    (void)self;
    uint32_t uVar2 = 0;
    int32_t local_424 = 0;
    void* local_420 = &PTR_FUN_007108ac;
    uint32_t local_418 = 0;
    uint32_t local_40c = 1;
    uint32_t local_414 = 0;
    uint32_t local_410 = 0;
    uint32_t local_41c = 0;
    uint32_t local_404 = 0;
    char local_400[512] = {};
    char local_200[512] = {};
    (void)local_404; (void)local_418; (void)local_40c; (void)local_414;
    (void)local_410; (void)local_41c;
    FUN_004f8fa0(&local_420, in_eax);
    char ok = FUN_004f96a0();
    if (ok == '\0') {
        if (PTR_FUN_00717a84 != nullptr) {
            using Fn = void (__cdecl*)(const char*, const char*, int);
            auto fn = reinterpret_cast<Fn>(PTR_FUN_00717a84);
            fn("Error loading wake .ini file!", "Error", 0);
        }
        FUN_004f8f50();
        return 0;
    }
    FUN_004f9820(&DAT_00726490);
    FUN_004f9820(&DAT_00726494);
    FUN_004f98b0("WakeTexture", &DAT_008ca120);
    char got = FUN_004f9790(&local_424);
    if (got != '\0') {
        DAT_008cac5c = local_424 != 0;
    }
    FUN_004f9820(&DAT_00726498);
    FUN_004f9820(&DAT_0072649c);
    FUN_004f9820(&DAT_007264a0);
    do {
        void* base = PTR_s_WakeSpreadFunc_00727308;
        const char* name = *reinterpret_cast<char* const*>(
            reinterpret_cast<uint8_t*>(base) + uVar2);
        FUN_004f98b0(name, local_200);
        sprintf(local_400, "%sScale", name);
        FUN_004f9820(&local_404);
        sprintf(local_400, "%sOffset", name);
        FUN_004f9820(&local_424);
        FUN_004e0910(&local_404, local_424);
        uVar2 = uVar2 + 4;
    } while (uVar2 < 8);
    FUN_004f8f50();
    return 1;
}

// ---------------------------------------------------------------------------
// 0x4e0d10 — observed shape: iterates pointer table at DAT_008c99d8 (step 4)
// up to 0x8c9dd8; for each nonzero calls FUN_004e1470, operator_delete,
// nulls the slot.
// ---------------------------------------------------------------------------
// 0x4e0d10 — observed shape
void FUN_004e0d10(void)
{
    uint32_t* p = reinterpret_cast<uint32_t*>(&DAT_008c99d8);
    do {
        void* obj = reinterpret_cast<void*>(*p);
        if (obj != nullptr) {
            FUN_004e1470(obj);
            operator_delete(obj);
            *p = 0;
        }
        p = p + 1;
    } while (reinterpret_cast<intptr_t>(p) < 0x8c9dd8);
}

// ---------------------------------------------------------------------------
// 0x4e0d40 — observed shape: calls FUN_004e0d10 then walks DAT_008ea04c
// (stride 12) up to 0x8ea064 doing refcount release with vtable destroy.
// ---------------------------------------------------------------------------
// 0x4e0d40 — observed shape
void FUN_004e0d40(void)
{
    FUN_004e0d10();
    int32_t* slot = reinterpret_cast<int32_t*>(&DAT_008ea04c);
    do {
        uint32_t* obj = reinterpret_cast<uint32_t*>(*slot);
        if (obj != nullptr) {
            int32_t* rc = reinterpret_cast<int32_t*>(obj + 1);
            *rc = *rc - 1;
            if (*rc == 0) {
                using Fn = void (__cdecl*)(int);
                auto fn = *reinterpret_cast<Fn*>(obj);
                fn(1);
            }
            *slot = 0;
        }
        slot = slot + 3;
    } while (reinterpret_cast<intptr_t>(slot) < 0x8ea064);
}

// ---------------------------------------------------------------------------
// 0x4e0d80 — observed shape: param_1+4/0x358 tombstone; reads ship node
// "Dummy_Wake" via vtable+0x40; spawns 0x1d wake samples at +0x14 (stride
// 0x1c = 7 floats); allocates 0x2e8/0x1f0/0x3e0 buffers, inits 0x3e verts;
// builds geometry via thunk_FUN_00533c78 / FUN_005473e0 / FUN_00542a40 and
// three small refcounted descriptors; links into operator list at +0xa0/
// +0xa4/+0xa8/+0xac; sets flag 0x3a; returns iStack_4 (param_1-derived).
// ---------------------------------------------------------------------------
// 0x4e0d80 — observed shape
int32_t FUN_004e0d80(int32_t param_1, int32_t* param_2, void* self)
{
    (void)self;
    uint8_t* base = reinterpret_cast<uint8_t*>(param_1);
    *reinterpret_cast<uint32_t*>(base + 4) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x358) = 0;
    int32_t* ship = param_2;
    int32_t* local_40 = nullptr;
    {
        using Fn = int32_t* (__cdecl*)(int32_t*, const char*);
        int32_t vtbl = *param_2;
        auto fn = *reinterpret_cast<Fn*>(vtbl + 0x40);
        local_40 = fn(param_2, "Dummy_Wake");
    }
    if (local_40 == nullptr) {
        local_40 = param_2;
        FUN_004e08d0("[Wake] couldn't find \"Dummy_Wake\" node on the ship!");
    }
    *reinterpret_cast<uint32_t*>(base + 0x350) = 0;
    float fVar3 = static_cast<float>(local_40[0x24]);
    float fVar4 = static_cast<float>(local_40[0x25]);
    float fVar5 = static_cast<float>(local_40[0x26]);
    *reinterpret_cast<uint32_t*>(base + 0x360) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x368) = 0;
    uint32_t uVar13 = 0;
    float* pfVar8 = reinterpret_cast<float*>(param_1 + 0x14);
    do {
        float fVar7 = static_cast<float>(static_cast<int32_t>(uVar13));
        *reinterpret_cast<uint8_t*>(pfVar8 + 3) = 0;
        if (static_cast<int32_t>(uVar13) < 0) fVar7 = fVar7 + 4294967296.0f;
        fVar7 = fVar7 * 0.0f; // _DAT_00726490
        (void)fVar7;
        pfVar8[-3] = fVar3;
        pfVar8[-2] = fVar4;
        *pfVar8 = 0.0f;
        pfVar8[-1] = fVar5;
        uVar13 = uVar13 + 1;
        pfVar8[2] = 1.0f;
        pfVar8 = pfVar8 + 7;
    } while (uVar13 < 0x1d);
    *reinterpret_cast<uint8_t*>(uVar13 * 0x1c + 0x20 + param_1) = 0;
    uint32_t* puVar9  = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2e8));
    uint32_t* puVar10 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2e8));
    uint32_t* puVar11 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x1f0));
    uint32_t* puVar12 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x3e0));
    if (puVar12 != nullptr) {
        uint32_t* puVar14 = puVar12 + 2;
        int32_t iVar16 = 0x3e;
        do {
            puVar14[-2] = 0; puVar14[-1] = 0; *puVar14 = 0; puVar14[1] = 0;
            puVar14 = puVar14 + 4;
            iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
    }
    uVar13 = 0;
    uint32_t* puVar14 = puVar10;
    uint32_t* puVar17 = puVar11;
    uint32_t* puVar18 = puVar12;
    do {
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(
            reinterpret_cast<intptr_t>(puVar9) - reinterpret_cast<intptr_t>(puVar10) +
            reinterpret_cast<intptr_t>(puVar14));
        *puVar2 = 0; puVar2[1] = 0; puVar2[2] = 0;
        *puVar14 = 0; puVar14[1] = 0; puVar14[2] = 0x3f800000u;
        uint32_t uVar6 = ((uVar13 & 1) == 0) ? 0u : 0x3f800000u;
        float fVar3b = static_cast<float>(static_cast<int32_t>(uVar13));
        if (static_cast<int32_t>(uVar13) < 0) fVar3b = fVar3b + 4294967296.0f;
        *puVar17 = uVar6;
        uVar13 = uVar13 + 1;
        puVar14 = puVar14 + 3;
        puVar17[1] = static_cast<uint32_t>(fVar3b * 0.5f);
        *puVar18 = DAT_0071779c; puVar18[1] = DAT_007177a0; puVar18[2] = DAT_007177a4;
        puVar17 = puVar17 + 2;
        puVar18[3] = DAT_007177a8;
        puVar18 = puVar18 + 4;
    } while (uVar13 < 0x3e);
    // local_40 kept as unaff_retaddr[0]; unaff_retaddr[1] receives built mesh.
    uint32_t mesh = 0;
    int32_t alloc = FUN_00533c78(0xcc);
    if (alloc != 0) {
        mesh = static_cast<uint32_t>(reinterpret_cast<intptr_t>(FUN_005473e0(0x3c, puVar9, puVar10, puVar12, puVar11, 1, 0, 0, 0, 0, 0)));
    }
    uint32_t oldMesh = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(local_40) + 4);
    if (oldMesh != mesh) {
        if (oldMesh != 0) {
            uint32_t* o = reinterpret_cast<uint32_t*>(oldMesh);
            int32_t* rc = reinterpret_cast<int32_t*>(o + 1);
            *rc = *rc - 1;
            if (*rc == 0) {
                using Fn = void (__cdecl*)(int);
                auto fn = *reinterpret_cast<Fn*>(o);
                fn(1);
            }
        }
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(local_40) + 4) = mesh;
        if (mesh != 0) reinterpret_cast<int32_t*>(mesh)[1] += 1;
    }
    {
        uint16_t* flags = reinterpret_cast<uint16_t*>(
            *reinterpret_cast<uint8_t**>(mesh + 0xbc) + 0x32);
        *flags = static_cast<uint16_t>((*flags & 0xfffu) | 0x8000u);
        int32_t vtbl = *reinterpret_cast<int32_t*>(mesh + 0xbc);
        using Fn = void (__cdecl*)(int);
        auto fn = *reinterpret_cast<Fn*>(vtbl + 0x34);
        fn(0);
    }
    int32_t texAlloc = FUN_00533c78(0x48);
    uint32_t* tex = nullptr;
    if ((texAlloc != 0) && ((tex = reinterpret_cast<uint32_t*>(FUN_00542a40(&DAT_008ca120))) != nullptr)) {
        reinterpret_cast<int32_t*>(tex)[1] += 1;
        // puVar9 alias for texture binding (observed).
        puVar9 = tex;
    }
    uint32_t* d1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2c));
    if (d1 != nullptr) {
        FUN_00540c50();
        *d1 = reinterpret_cast<uint32_t>(&PTR_FUN_0070bf10);
        *reinterpret_cast<uint16_t*>(d1 + 8) = 0;
        d1[9] = 0; d1[10] = 1;
        reinterpret_cast<int32_t*>(d1)[1] += 1;
    }
    uint32_t* d2 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x24));
    if (d2 != nullptr) {
        FUN_00540c50();
        *d2 = reinterpret_cast<uint32_t>(&PTR_FUN_0070bf4c);
        *reinterpret_cast<uint16_t*>(d2 + 8) = 0xec;
        *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(d2) + 0x22) = 0;
        reinterpret_cast<int32_t*>(d2)[1] += 1;
    }
    uint32_t* d3 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x28));
    if (d3 != nullptr) {
        FUN_00540c50();
        *reinterpret_cast<uint16_t*>(d3 + 8) = 3;
        d3[9] = 3;
        *d3 = reinterpret_cast<uint32_t>(&PTR_FUN_0070bed4);
        reinterpret_cast<int32_t*>(d3)[1] += 1;
    }
    // Texture refcount bookkeeping at puVar9[0xb/0xc/0xd/0xe] (two identical
    // blocks in the original; preserved once plus LAB_004e11b3 constants).
    auto texFix = [&](uint32_t* t) {
        int32_t cur = *reinterpret_cast<int32_t*>(t[0xb]);
        int32_t fresh = 0;
        if (cur == 0) {
            int32_t a = FUN_00533c78(0x1c);
            if (a != 0) a = FUN_005426d0();
            fresh = a;
            if (t[0xc] != 0) {
                if (t[0xd] == 0) {
                    t[0xd] = 1;
                    if (fresh != 0) t[0xe] = t[0xe] + 1;
                } else if (fresh == 0) {
                    if (*reinterpret_cast<int32_t*>(t[0xb]) != 0) t[0xe] = t[0xe] - 1;
                } else if (*(reinterpret_cast<int32_t*>(t[0xb])) == 0) {
                    t[0xe] = t[0xe] + 1;
                }
                *reinterpret_cast<int32_t*>(t[0xb]) = fresh;
            }
        }
        *reinterpret_cast<int32_t*>(fresh + 8) = 1;
        *reinterpret_cast<int32_t*>(fresh + 0xc) = 2;
    };
    if (puVar9 != nullptr) texFix(puVar9);
    if (d1 != nullptr) { d1[9] = 2; d1[10] = 1; }
    if (d2 != nullptr) *reinterpret_cast<uint16_t*>(d2 + 8) =
        static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(d2 + 8) & 0xfcedu) | 0x20edu);
    if (d3 != nullptr) *reinterpret_cast<uint16_t*>(d3 + 8) =
        static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(d3 + 8) & 0xfffdu) | 1u);
    // Operator-list linking helper (identical 4x block at +0xa0/+0xa4).
    auto linkOp = [&](int32_t op) {
        int32_t host = *reinterpret_cast<int32_t*>(param_1 + 0x358 /* stack slot +4 */);
        (void)host;
        // Observed: call host vtbl+0xa0, swap slot2, splice into +0xa4 list,
        // bump +0xac, then release the operator reference.
        int32_t h2 = *reinterpret_cast<int32_t*>(param_1 + 0x358);
        uint32_t* node = nullptr;
        {
            int32_t vtbl = *reinterpret_cast<int32_t*>(h2 + 0xa0);
            using Fn = uint32_t* (__cdecl*)();
            auto fn = *reinterpret_cast<Fn*>(vtbl + 4);
            node = fn();
        }
        uint32_t slot2 = node[2];
        if (slot2 != static_cast<uint32_t>(op)) {
            if (slot2 != 0) {
                uint32_t* o = reinterpret_cast<uint32_t*>(slot2);
                int32_t* rc = reinterpret_cast<int32_t*>(o + 1);
                *rc = *rc - 1;
                if (*rc == 0) {
                    using Fn = void (__cdecl*)(int);
                    auto fn = *reinterpret_cast<Fn*>(o);
                    fn(1);
                }
            }
            node[2] = static_cast<uint32_t>(op);
            reinterpret_cast<int32_t*>(op)[1] += 1;
        }
        node[1] = 0;
        int32_t tail = *reinterpret_cast<int32_t*>(h2 + 0xa4);
        *node = static_cast<uint32_t>(tail);
        if (tail == 0) *reinterpret_cast<uint32_t*>(h2 + 0xa8) = reinterpret_cast<uint32_t>(node);
        else *reinterpret_cast<uint32_t*>(tail + 4) = reinterpret_cast<uint32_t>(node);
        *reinterpret_cast<uint32_t*>(h2 + 0xa4) = reinterpret_cast<uint32_t>(node);
        *reinterpret_cast<int32_t*>(h2 + 0xac) += 1;
        int32_t* rc = reinterpret_cast<int32_t*>(op + 1);
        *rc = *rc - 1;
        if (*rc == 0) {
            using Fn = void (__cdecl*)(int);
            auto fn = *reinterpret_cast<Fn*>(op);
            fn(1);
        }
    };
    if (d1 != nullptr) linkOp(reinterpret_cast<int32_t>(d1));
    if (d2 != nullptr) linkOp(reinterpret_cast<int32_t>(d2));
    if (tex != nullptr) linkOp(reinterpret_cast<int32_t>(tex));
    if (d3 != nullptr) linkOp(reinterpret_cast<int32_t>(d3));
    {
        int32_t h3 = *reinterpret_cast<int32_t*>(param_1 + 0x358);
        *reinterpret_cast<uint16_t*>(*reinterpret_cast<uint8_t**>(h3 + 0xbc) + 0x3c) = 0x3a;
        int32_t vtbl = *reinterpret_cast<int32_t*>(DAT_008e9fe8);
        using Fn = void (__cdecl*)(int32_t, int);
        auto fn = *reinterpret_cast<Fn*>(vtbl + 0x70);
        fn(h3, 1);
    }
    FUN_00534130();
    FUN_00534350();
    {
        uint32_t* slot = reinterpret_cast<uint32_t*>(param_1 + 0x358);
        uint32_t* obj = reinterpret_cast<uint32_t*>(*slot);
        if (obj != nullptr) {
            int32_t* rc = reinterpret_cast<int32_t*>(obj + 1);
            *rc = *rc - 1;
            if (*rc == 0) {
                using Fn = void (__cdecl*)(int);
                auto fn = *reinterpret_cast<Fn*>(obj);
                fn(1);
            }
            *slot = 0;
        }
    }
    auto release = [&](uint32_t* o) {
        int32_t* rc = reinterpret_cast<int32_t*>(o + 1);
        *rc = *rc - 1;
        if (*rc == 0) {
            using Fn = void (__cdecl*)(int);
            auto fn = *reinterpret_cast<Fn*>(o);
            fn(1);
        }
    };
    if (d3 != nullptr) release(d3);
    if (puVar9 != nullptr) release(puVar9);
    if (d1 != nullptr) release(d1);
    return param_1;
}

// ===========================================================================
// Appended retry batch (mass_0058 retry) — see TASK_RETRY.md
// ===========================================================================

extern void*    FUN_0053bb30(uint32_t arg);   // placement factory (receiver in register)

// Refcounted release idiom observed across this batch:
//   rc = obj[1]; --rc; if (rc == 0) (*(void (__cdecl**)(int))obj)(1);
static void mass0058_release(void* obj)
{
    if (obj == nullptr) return;
    uint32_t* o = static_cast<uint32_t*>(obj);
    int32_t*  rc = reinterpret_cast<int32_t*>(o + 1);
    *rc = *rc - 1;
    if (*rc == 0) {
        using Fn = void (__cdecl*)(int);
        auto fn = *reinterpret_cast<Fn*>(o);
        fn(1);
    }
}

static void mass0058_release(int32_t objAddr)
{
    mass0058_release(reinterpret_cast<void*>(static_cast<intptr_t>(objAddr)));
}

// Loads a function pointer from the vtable of the object whose address is
// objAddr (object word 0 is its vtable pointer).
template <typename Fn>
static Fn mass0058_vfn(int32_t objAddr, int32_t offset)
{
    int32_t vtbl = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(objAddr));
    return *reinterpret_cast<Fn*>(static_cast<intptr_t>(vtbl) + offset);
}

// ---------------------------------------------------------------------------
// 0x4e1470 — observed shape: self at in_ESI; looks up the object at +4 via its
// +0x24 sub-object vtable+0x74 (result is a refcounted handle, released when the
// count reaches zero), then releases and clears +4 and +0x358. The listing then
// repeats the +0x358 and +4 releases once more against the just-zeroed slots.
// ---------------------------------------------------------------------------
// 0x4e1470 — observed shape
void FUN_004e1470(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    void* ship = *reinterpret_cast<void**>(base + 4);
    if (ship != nullptr) {
        int32_t holder = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(ship) + 0x24);
        if (holder != 0) {
            void* local_4 = nullptr;
            using Fn = void (__cdecl*)(int32_t, void**, void*);
            auto fn = mass0058_vfn<Fn>(holder, 0x74);
            fn(holder, &local_4, ship);
            mass0058_release(local_4);      // decrement, destroy when count hits 0
        }
        mass0058_release(*reinterpret_cast<int32_t*>(base + 4));
        *reinterpret_cast<uint32_t*>(base + 4) = 0;
    }
    mass0058_release(*reinterpret_cast<int32_t*>(base + 0x358));
    *reinterpret_cast<uint32_t*>(base + 0x358) = 0;
    // Repeated guards on the now-cleared slots (observed verbatim).
    mass0058_release(*reinterpret_cast<int32_t*>(base + 0x358));
    mass0058_release(*reinterpret_cast<int32_t*>(base + 4));
}

// ---------------------------------------------------------------------------
// 0x4e1510 — observed shape: wake-trail emitter. Receivers: self (in_ESI, the
// wake manager; 0x1e trail points of 7 int32 at +8, stride 0x1c) and the ship
// object (in_EAX, vtable+0x40 resolves the "Dummy_Wake" node). `now` is read
// from the slot the decompiler prints as unaff_retaddr (an extra trailing
// argument it did not attribute). Trail vertices are written through the mesh
// at ship+0xbc ([8] = vertex xyz buffer, [10] = per-vertex attribute buffer,
// ushort @ +0x3c = vertex count). Constants _DAT_00726494/98/9c/a0 are floats.
// ---------------------------------------------------------------------------
// 0x4e1510 — observed shape
void FUN_004e1510(void* self, void* ship_obj, float param_1, uint8_t param_2, float now)
{
    int32_t* s = static_cast<int32_t*>(self);
    // Float constants loaded from the globals referenced by the listing.
    const float kOff  = *reinterpret_cast<const float*>(&_DAT_00726494);
    const float kDiv  = *reinterpret_cast<const float*>(&_DAT_00726498);
    const float k9c   = *reinterpret_cast<const float*>(&_DAT_0072649c);
    const float kBias = *reinterpret_cast<const float*>(&_DAT_007264a0);
    if (*reinterpret_cast<int32_t*>(static_cast<intptr_t>(DAT_0072cd78) + 0xc) < 1) {
        return;
    }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(s) + 0xd9) = param_2;
    if (param_1 < static_cast<float>(s[0xd7])) {
        return;
    }
    if (FUN_004284c0(&DAT_00727430) != '\0') {
        return;
    }

    int32_t shipAddr = static_cast<int32_t>(reinterpret_cast<intptr_t>(ship_obj));
    int32_t* node;
    {
        using Fn = int32_t* (__cdecl*)(int32_t, const char*);
        auto fn = mass0058_vfn<Fn>(shipAddr, 0x40);
        node = fn(shipAddr, "Dummy_Wake");
    }
    if (node == nullptr) {
        FUN_004e08d0("[Wake] couldn't find \"Dummy_Wake\" node on the ship!");
        node = reinterpret_cast<int32_t*>(ship_obj);
    }
    if (reinterpret_cast<int32_t*>(static_cast<intptr_t>(s[0])) != node) {
        for (int32_t i = 0; i < 0x1e; ++i) {
            *reinterpret_cast<uint8_t*>(s + 8 + i * 7) = 0;
        }
    }
    s[0xd7] = static_cast<int32_t>(now);
    s[0] = static_cast<int32_t>(reinterpret_cast<intptr_t>(node));

    int32_t  meshAddr = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(s[1]) + 0xbc);
    int32_t* mesh = reinterpret_cast<int32_t*>(static_cast<intptr_t>(meshAddr));
    float*   verts = reinterpret_cast<float*>(static_cast<intptr_t>(mesh[8]));
    float    vertHalf = static_cast<float>(
        static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(mesh + 0xf)) >> 1);
    int32_t  attrBase = mesh[10];
    int32_t  vcolorBase = FUN_005412c0(0);
    int32_t  slot = s[0xd4];
    float*   nodePos = reinterpret_cast<float*>(node + 0x24);   // floats at node+0x90

    {
        float dx = static_cast<float>(s[slot * 7 + 2]) - nodePos[0];
        float dy = static_cast<float>(s[slot * 7 + 3]) - static_cast<float>(node[0x25]);
        float dz = static_cast<float>(s[slot * 7 + 4]) - static_cast<float>(node[0x26]);
        if (1.0e6f < dx * dx + dy * dy + dz * dz) {
            for (int32_t i = 0; i < 0x1e; ++i) {
                *reinterpret_cast<uint8_t*>(s + 8 + i * 7) = 0;
            }
        }
    }

    slot = s[0xd4];
    if (*reinterpret_cast<uint8_t*>(s + slot * 7 + 8) == 0) {
        *reinterpret_cast<uint8_t*>(s + slot * 7 + 8) = 1;
        float* e = reinterpret_cast<float*>(s + s[0xd4] * 7 + 2);
        e[0] = nodePos[0];
        e[1] = static_cast<float>(node[0x25]);
        e[2] = static_cast<float>(node[0x26]);
        s[s[0xd4] * 7 + 5] = static_cast<int32_t>(now);
        s[s[0xd4] * 7 + 6] = 0;
        s[(s[0xd4] + 1) * 7] = 0;
        s[0xd5] = 0;
        vertHalf = static_cast<float>(static_cast<int32_t>(vertHalf) + 1);
    }
    else {
        float dx = static_cast<float>(s[slot * 7 + 4]) - static_cast<float>(node[0x26]);
        float dy = static_cast<float>(s[slot * 7 + 2]) - nodePos[0];
        float dz = static_cast<float>(s[slot * 7 + 3]) - static_cast<float>(node[0x25]);
        if (sqrt(dx * dx + dy * dy + dz * dz) <= k9c * static_cast<float>(s[0xd8])) {
            return;
        }
        uint32_t next = (static_cast<uint32_t>(slot) + 1u) % 0x1e;
        s[0xd4] = static_cast<int32_t>(next);
        if (*reinterpret_cast<uint8_t*>(s + next * 7 + 8) == 0) {
            vertHalf = static_cast<float>(static_cast<int32_t>(vertHalf) + 1);
        }
        else {
            FUN_004e08d0("Wake [0x%x] - destroying active point (buffer is full).\n");
            s[0xd5] = static_cast<int32_t>(static_cast<float>(s[0xd5]) -
                                           static_cast<float>(s[s[0xd4] * 7 + 6]));
        }
        *reinterpret_cast<uint8_t*>(s + s[0xd4] * 7 + 8) = 1;
        int32_t head = s[0];
        s[s[0xd4] * 7 + 2] = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(head) + 0x90);
        s[s[0xd4] * 7 + 3] = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(head) + 0x94);
        s[s[0xd4] * 7 + 4] = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(head) + 0x98);
        s[s[0xd4] * 7 + 5] = static_cast<int32_t>(now);
        int32_t ni = s[0xd4];
        float segX = static_cast<float>(s[ni * 7 + 3]) - static_cast<float>(s[slot * 7 + 3]);
        float segY = static_cast<float>(s[ni * 7 + 4]) - static_cast<float>(s[slot * 7 + 4]);
        float segZ = static_cast<float>(s[ni * 7 + 2]) - static_cast<float>(s[slot * 7 + 2]);
        s[ni * 7 + 6] = static_cast<int32_t>(sqrt(segX * segX + segY * segY + segZ * segZ));
        s[s[0xd4] * 7 + 7] = static_cast<int32_t>(
            static_cast<float>(s[s[0xd4] * 7 + 6]) / kDiv +
            static_cast<float>(s[slot * 7 + 7]));
        s[0xd5] = static_cast<int32_t>(static_cast<float>(s[s[0xd4] * 7 + 6]) +
                                       static_cast<float>(s[0xd5]));
    }

    s[0xda] = s[0xda] + 1;
    {
        uint32_t count = static_cast<uint32_t>(static_cast<int32_t>(vertHalf) * 2);
        if (count != static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(mesh + 0xf))) {
            if (count < 2u) {
                count = 2u;
            }
            else if (count >= 0x3au) {
                count = 0x3au;
            }
            using Fn = void (__cdecl*)(int32_t, uint32_t);
            auto fn = mass0058_vfn<Fn>(meshAddr, 0x34);
            fn(meshAddr, count);
        }
    }

    int32_t  trailSlot = s[0xd4];
    int32_t  remaining = 0x1e;
    float    baseDist;
    {
        float ex = static_cast<float>(s[trailSlot * 7 + 3]) - static_cast<float>(node[0x25]);
        float ey = static_cast<float>(s[trailSlot * 7 + 4]) - static_cast<float>(node[0x26]);
        float ez = static_cast<float>(s[trailSlot * 7 + 2]) - nodePos[0];
        baseDist = static_cast<float>(sqrt(ex * ex + ey * ey + ez * ez));
    }
    float runDist = baseDist;
    do {
        uint32_t      pt    = static_cast<uint32_t>(
            static_cast<uint32_t>(s[0xd4]) + static_cast<uint32_t>(remaining)) % 0x1e;
        int32_t       vi    = 0x1e - remaining;
        uint32_t      stride = static_cast<uint32_t>(vi * 2);
        if (*reinterpret_cast<uint8_t*>(s + pt * 7 + 8) == 0) {
            float* v = verts + vi * 6;
            if (stride == 0) {
                v[0] = nodePos[0];
                v[1] = static_cast<float>(node[0x25]);
                v[2] = static_cast<float>(node[0x26]);
                v[3] = nodePos[0];
                v[4] = static_cast<float>(node[0x25]);
                v[5] = static_cast<float>(node[0x26]);
            }
            else {
                float* prev = verts + vi * 6 - 6;
                v[0] = prev[0];
                v[1] = prev[1];
                v[2] = prev[2];
                v[3] = v[-3];
                v[4] = v[-2];
                v[5] = v[-1];
            }
            uint32_t* q = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(attrBase + vi * 0x20));
            q[0] = 0x3f800000u; q[1] = 0x3f800000u; q[2] = 0x3f800000u; q[3] = 0;
            q[4] = 0x3f800000u; q[5] = 0x3f800000u; q[6] = 0x3f800000u; q[7] = 0;
        }
        else {
            float age = (now - static_cast<float>(s[pt * 7 + 5])) / kOff;
            float along = runDist / (baseDist + static_cast<float>(s[0xd5]));
            runDist = runDist + static_cast<float>(s[pt * 7 + 6]);
            if (age < 0.0f)     age = 0.0f;
            else if (age > 1.0f) age = 1.0f;
            if (along < 0.0f)     along = 0.0f;
            else if (along > 1.0f) along = 1.0f;

            float dx, dy, dz;
            if (pt == static_cast<uint32_t>(s[0xd4])) {
                int32_t head = s[0];
                dx = *reinterpret_cast<float*>(static_cast<intptr_t>(head) + 0x90) -
                     static_cast<float>(s[pt * 7 + 2]);
                dy = *reinterpret_cast<float*>(static_cast<intptr_t>(head) + 0x94) -
                     static_cast<float>(s[pt * 7 + 3]);
                dz = *reinterpret_cast<float*>(static_cast<intptr_t>(head) + 0x98) -
                     static_cast<float>(s[pt * 7 + 4]);
            }
            else {
                float tmp[3];
                if (pt == 0) {
                    tmp[0] = static_cast<float>(s[pt * 7 + 2]) - static_cast<float>(s[0xcd]);
                    tmp[1] = static_cast<float>(s[3]) - static_cast<float>(s[0xce]);
                    tmp[2] = static_cast<float>(s[4]) - static_cast<float>(s[0xcf]);
                }
                else {
                    tmp[0] = static_cast<float>(s[pt * 7 + 2]) - static_cast<float>(s[pt * 7 - 5]);
                    tmp[1] = static_cast<float>(s[pt * 7 + 3]) - static_cast<float>(s[pt * 7 - 4]);
                    tmp[2] = static_cast<float>(s[pt * 7 + 4]) - static_cast<float>(s[pt * 7 - 3]);
                }
                dx = tmp[0];
                dy = tmp[1];
                dz = tmp[2];
            }
            if (remaining == 1) {
                dx = -dx;
                dy = -dy;
                dz = -dz;
            }
            FUN_00491640();
            float  negDy = -dy;
            *reinterpret_cast<float*>(&DAT_008ea050) = runDist * 0.0025f * 250.0f;
            long double curve = FUN_004e0a80(nullptr, 1.0f - along * age);
            float* v = verts + vi * 6;
            if (static_cast<float>(s[0xd8]) >= 0.4f) {
                long double widen = (static_cast<long double>(kBias) + curve) *
                                    static_cast<long double>(static_cast<float>(s[0xd8]));
                v[0] = static_cast<float>(static_cast<long double>(static_cast<float>(s[pt * 7 + 2])) -
                                          static_cast<long double>(negDy) * widen);
                v[1] = static_cast<float>(s[pt * 7 + 3]) -
                       static_cast<float>(widen * static_cast<long double>(dx));
                v[2] = static_cast<float>(s[pt * 7 + 4]) -
                       static_cast<float>(widen * static_cast<long double>(dz));
                curve = (curve + static_cast<long double>(kBias)) *
                        static_cast<long double>(static_cast<float>(s[0xd8]));
                v[3] = static_cast<float>(static_cast<long double>(negDy) * curve +
                                          static_cast<long double>(static_cast<float>(s[pt * 7 + 2])));
                v[4] = static_cast<float>(curve * static_cast<long double>(dx)) +
                       static_cast<float>(s[pt * 7 + 3]);
                v[5] = static_cast<float>(curve * static_cast<long double>(dz)) +
                       static_cast<float>(s[pt * 7 + 4]);
            }
            else {
                float widen = kBias * static_cast<float>(s[0xd8]);
                float oy = widen * dx;
                float oz = widen * dz;
                v[0] = static_cast<float>(s[pt * 7 + 2]) - negDy * widen;
                v[1] = static_cast<float>(s[pt * 7 + 3]) - oy;
                v[2] = static_cast<float>(s[pt * 7 + 4]) - oz;
                widen = kBias * static_cast<float>(s[0xd8]);
                oy = widen * dx;
                oz = widen * dz;
                v[3] = negDy * widen + static_cast<float>(s[pt * 7 + 2]);
                v[4] = oy + static_cast<float>(s[pt * 7 + 3]);
                v[5] = oz + static_cast<float>(s[pt * 7 + 4]);
            }
            if (stride == 2) {
                float len = static_cast<float>(s[pt * 7 + 6]);
                verts[0] = verts[6] - dx * len;
                verts[1] = verts[7] - len * dy;
                verts[2] = verts[8] - len * dz;
                len = static_cast<float>(s[pt * 7 + 6]);
                verts[3] = verts[9] - dx * len;
                verts[4] = verts[10] - len * dy;
                verts[5] = verts[11] - len * dz;
            }
            uint32_t ageCount = static_cast<uint32_t>(s[0xda]) - 0x1eu;
            uint32_t ageMask = (static_cast<int32_t>(ageCount) < 0) ? 0u : ageCount;
            float    fade = static_cast<float>(static_cast<int32_t>(ageMask)) * 0.05f;
            if (fade > 1.0f) fade = 1.0f;
            int32_t  rev = vi * -2 + 0x3c;
            float    revF = static_cast<float>(rev);
            if (rev < 0) revF = revF + 4294967296.0f;
            fade = revF * fade * 0.016666668f;
            {
                uint32_t* q = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(attrBase + vi * 0x20));
                q[0] = 0x3f800000u; q[1] = 0x3f800000u; q[2] = 0x3f800000u;
                q[4] = 0x3f800000u; q[5] = 0x3f800000u; q[6] = 0x3f800000u;
                if (stride < 3) {
                    q[3] = 0;
                    q[7] = 0;
                }
                else {
                    uint32_t bits = *reinterpret_cast<uint32_t*>(&fade);
                    q[3] = bits;
                    q[7] = bits;
                }
            }
            (void)FUN_004e0a80(nullptr, 1.0f - age);
            int32_t* vc = reinterpret_cast<int32_t*>(static_cast<intptr_t>(vcolorBase + vi * 0x10));
            vc[1] = s[pt * 7 + 7];
            vc[0] = 0;
            int32_t vcol = s[pt * 7 + 7];
            vc[2] = 0x3f800000;
            vc[3] = vcol;
        }
        remaining = remaining + -1;
    } while (0 < remaining);

    // ---- vertex cleanup pass (11 steps of 2, offset written after each) ----
    int32_t step = 4;
    float*  cur = verts + 7;              // observed pfVar22 = pfVar25 + 7
    int32_t outer = 0x1d;
    // fStack_168 / fStack_164 are read below but never assigned in the listing:
    // FUN_00514ae0's out-parameters are not materialized by the decompiler.
    float out168;
    float out164;
    do {
        float keepX = cur[-1];
        float keepY = cur[0];
        if (step < 0x3c) {
            float*  scan = cur;
            int32_t inner = step;
            do {
                if (step + 6 <= inner) break;
                float f5 = scan[5];
                float f6 = scan[6];
                float f7 = scan[8];
                float f8 = scan[9];
                if (FUN_00514ae0(keepX, keepY, keepX, keepY, f5, f6, f7, f8) != '\0') {
                    f5 = f5 - out168;
                    f6 = f6 - out164;
                    f7 = f7 - out168;
                    f8 = f8 - out164;
                    if (f8 * f8 + f7 * f7 <= f6 * f6 + f5 * f5) {
                        cur[2] = cur[-4];
                        cur[3] = cur[-3];
                        cur[4] = cur[-2];
                    }
                    else {
                        cur[-1] = cur[-7];
                        cur[0]  = cur[-6];
                        cur[1]  = cur[-5];
                    }
                }
                inner = inner + 2;
                scan = scan + 6;
            } while (inner < 0x3c);
        }
        step = step + 2;
        cur = cur + 6;
        outer = outer + -1;
        if (outer == 0) {
            uint16_t prim = [&]() -> uint16_t {
                using Fn = uint16_t (__cdecl*)(int32_t, float*);
                auto fn = mass0058_vfn<Fn>(
                    *reinterpret_cast<int32_t*>(static_cast<intptr_t>(s[1]) + 0xbc), 0x38);
                return fn(*reinterpret_cast<int32_t*>(static_cast<intptr_t>(s[1]) + 0xbc),
                          verts);
            }();
            FUN_00548120(prim, verts);
            // uStack_14/uStack_10/uStack_c/uStack_8 are never assigned in the
            // listing (caller stack slots consumed here, not expressed by the
            // decompiler); stored verbatim into mesh +0x10..+0x1c.
            float uStack_14;
            float uStack_10;
            float uStack_c;
            float uStack_8;
            int32_t meshNow = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(s[1]) + 0xbc);
            *reinterpret_cast<float*>(static_cast<intptr_t>(meshNow) + 0x10) = uStack_14;
            *reinterpret_cast<float*>(static_cast<intptr_t>(meshNow) + 0x14) = uStack_10;
            *reinterpret_cast<float*>(static_cast<intptr_t>(meshNow) + 0x18) = uStack_c;
            *reinterpret_cast<float*>(static_cast<intptr_t>(meshNow) + 0x1c) = uStack_8;
            FUN_00533d10(now, 1);
            uint8_t* flags = reinterpret_cast<uint8_t*>(
                static_cast<intptr_t>(*reinterpret_cast<int32_t*>(
                    static_cast<intptr_t>(s[1]) + 0xbc)) + 0x32);
            *flags = static_cast<uint8_t>(*flags | 5);
            return;
        }
    } while (true);
}

// ---------------------------------------------------------------------------
// 0x4e24b0 — observed shape: constructor-style reset of the 0x3f-word object at
// in_ESI; zeroes scalar fields, seeds four refcounted/owned slots, installs two
// inline self-referencing sub-objects (+0x13 -> self+0xc, +0x22 -> self+0x1b)
// with float constant words 0x3f350481 / 0x3f800000, then releases every owned
// slot (0,1,2,5,6,7,0x33..0x38) and finally the 9-entry table at +0x2a.
// ---------------------------------------------------------------------------
// 0x4e24b0 — observed shape
void FUN_004e24b0(void* self)
{
    int32_t* s = static_cast<int32_t*>(self);
    s[0] = 0; s[1] = 0; s[2] = 0; s[3] = 0; s[4] = 0;
    s[5] = 0; s[6] = 0; s[7] = 0; s[8] = 0; s[9] = 0;
    s[0xd] = 0;
    s[0x13] = 7;
    s[0x19] = 0;
    *reinterpret_cast<uint8_t*>(s + 0x1a) = 0;
    *reinterpret_cast<uint8_t*>(s + 0xc) = 0;
    s[0xe] = 0;
    s[0x13] = static_cast<int32_t>(reinterpret_cast<intptr_t>(s + 0xc));
    s[0x11] = 0x3f350481;
    s[0x15] = 0x3f800000;
    s[0x12] = 0x3f350481;
    s[0x1c] = 0;
    s[0x22] = 7;
    s[0x28] = 0;
    s[0x24] = 0x3f800000;
    *reinterpret_cast<uint8_t*>(s + 0x29) = 0;
    *reinterpret_cast<uint8_t*>(s + 0x1b) = 0;
    s[0x1d] = 0;
    s[0x22] = static_cast<int32_t>(reinterpret_cast<intptr_t>(s + 0x1b));
    s[0x20] = 0x3f350481;
    s[0x21] = 0x3f350481;
    int32_t* slot = s + 0x2a;
    *slot = 0;
    s[0x2b] = 0;
    s[0x2c] = 0;
    s[0x2d] = 0;
    s[0x2e] = 0;
    s[0x2f] = 0;
    s[0x30] = 0;
    s[0x31] = 0;
    s[0x32] = 0;
    s[0x33] = 0;
    s[0x34] = 0;
    s[0x36] = 0;
    s[0x37] = 0;
    s[0x38] = 0;

    mass0058_release(s[0]);  s[0] = 0;
    mass0058_release(s[1]);  s[1] = 0;
    mass0058_release(s[0x34]); s[0x34] = 0;
    mass0058_release(s[0x38]); s[0x38] = 0;
    mass0058_release(s[0x37]); s[0x37] = 0;
    mass0058_release(s[0x33]); s[0x33] = 0;
    mass0058_release(s[0x36]); s[0x36] = 0;
    mass0058_release(s[2]);  s[2] = 0;

    s[0x39] = 0;
    s[0x3a] = 0;
    *reinterpret_cast<uint8_t*>(s + 0x3c) = 0;
    s[0x35] = 0;
    s[0x3b] = 0;

    mass0058_release(s[5]); s[5] = 0;
    mass0058_release(s[6]); s[6] = 0;

    s[10] = 100;
    s[0xb] = 0;

    mass0058_release(s[7]); s[7] = 0;

    *reinterpret_cast<uint8_t*>(s + 0x3e) = 0;

    int32_t* walk = slot;
    for (int32_t i = 9; i != 0; --i) {
        mass0058_release(*walk);
        *walk = 0;
        walk = walk + 1;
    }
}

// ---------------------------------------------------------------------------
// 0x4e2730 — observed shape: destructor-style teardown at in_EAX; calls
// FUN_004e2c10 first, releases +0x38/+0x37/+0x36/+0x34/+0x33, then the 9-slot
// table ending at +0x33 (indices 0x32 down to 0x2a), runs FUN_004e4ea0 twice,
// and releases indices 9 down to 0.
// ---------------------------------------------------------------------------
// 0x4e2730 — observed shape
void FUN_004e2730(void* self)
{
    int32_t* s = static_cast<int32_t*>(self);
    FUN_004e2c10();
    mass0058_release(s[0x38]);
    mass0058_release(s[0x37]);
    mass0058_release(s[0x36]);
    mass0058_release(s[0x34]);
    mass0058_release(s[0x33]);
    {
        int32_t* walk = s + 0x33;
        for (int32_t i = 9; i != 0; --i) {
            walk = walk - 1;
            mass0058_release(*walk);
        }
    }
    for (int32_t i = 2; i != 0; --i) {
        FUN_004e4ea0();
    }
    mass0058_release(s[9]);
    mass0058_release(s[8]);
    mass0058_release(s[7]);
    mass0058_release(s[6]);
    mass0058_release(s[5]);
    mass0058_release(s[4]);
    mass0058_release(s[3]);
    mass0058_release(s[2]);
    mass0058_release(s[1]);
    mass0058_release(s[0]);
}

// ---------------------------------------------------------------------------
// 0x4e28a0 — observed shape: lazily creates the helper object at self+0xd8
// (0xec-byte allocation via FUN_00533c78, then FUN_0053bb30 — the decompiler
// shows only its 0 argument, the allocated block travels in a register), swaps
// it into +0xd8 with refcount handling, then dispatches vtable+0x70 with
// (param_1, 1) and releases param_1.
// ---------------------------------------------------------------------------
// 0x4e28a0 — observed shape
void FUN_004e28a0(void* self, uint32_t* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<int32_t*>(base + 0xd8) == 0) {
        int32_t  alloc = FUN_00533c78(0xec);
        void*    created = nullptr;
        if (alloc != 0) {
            created = FUN_0053bb30(0);
        }
        void* prev = *reinterpret_cast<void**>(base + 0xd8);
        if (prev != created) {
            mass0058_release(prev);
            *reinterpret_cast<void**>(base + 0xd8) = created;
            if (created != nullptr) {
                reinterpret_cast<int32_t*>(created)[1] += 1;
            }
        }
    }
    {
        int32_t helper = *reinterpret_cast<int32_t*>(base + 0xd8);
        using Fn = void (__cdecl*)(int32_t, uint32_t*, int32_t);
        auto fn = mass0058_vfn<Fn>(helper, 0x70);
        fn(helper, param_1, 1);
    }
    mass0058_release(param_1);
}

// ---------------------------------------------------------------------------
// 0x4e2920 — observed shape: at in_EAX receiver; when self+0xd8 exists, asks its
// vtable+0x74 to produce a handle from param_1 (writing the result back over
// param_1), releases that handle, then releases the original param_1.
// ---------------------------------------------------------------------------
// 0x4e2920 — observed shape
void FUN_004e2920(void* self, uint32_t* param_1)
{
    uint32_t* puVar3 = param_1;
    uint8_t*  base = static_cast<uint8_t*>(self);
    int32_t   helper = *reinterpret_cast<int32_t*>(base + 0xd8);
    if (helper != 0) {
        using Fn = void (__cdecl*)(int32_t, uint32_t**, uint32_t*);
        auto fn = mass0058_vfn<Fn>(helper, 0x74);
        fn(helper, &param_1, param_1);
        mass0058_release(param_1);
    }
    mass0058_release(puVar3);
}
