// Reconstruction batch mass_0003 — Sid Meier's Pirates! (2004), PE32 i386
// image 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
// Ghidra 12.2 pseudocode corpus translations. Register receivers rendered as void* self.
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <cstdlib>

// ---- globals referenced by the assigned listings ----
extern int DAT_0072c698;
extern int DAT_0072c67c, DAT_0072c69c, DAT_0072c680, DAT_0072c660;
extern int DAT_00869ab8, DAT_00869abc, DAT_00869ac0, DAT_00869ac4, DAT_00869ac8;
extern int DAT_00869aa8;
extern int DAT_0085a268, DAT_0085a26c;
extern int DAT_008be9c8, DAT_008be9c0, DAT_008cac38, DAT_008caccc;
extern int DAT_008c8200, DAT_008cadec;
extern std::uint8_t DAT_0085bf9c[], DAT_0085bf94[], DAT_0085bfb6[], DAT_0085bfb8[], DAT_0085bfba[], DAT_0085bfbc[], DAT_0085bfbe[];
extern std::uint8_t DAT_00860b74[], DAT_006f5896[], DAT_008cacd0[], DAT_008cacc8[];
extern std::uint8_t DAT_008e8eff, DAT_008ca904;
extern std::int8_t DAT_0085a164;
extern std::uint32_t DAT_007268f4[], DAT_007263bc, DAT_00726a84;
extern std::uint32_t DAT_0085a11c;
extern void* PTR_FUN_006f5814, PTR_FUN_006f583c, PTR_FUN_006f5864;

// ---- helpers ----
extern std::uint8_t FUN_0040fe00();
extern void FUN_00430190();
extern void FUN_00486990();
extern void FUN_004f6090();
extern void FUN_00487850();
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern std::uint32_t FUN_00533c78();
extern void* FUN_004dcf20();
extern void FUN_004dd090();
extern void* FUN_004d5a50();
extern void FUN_004d5b90();
extern void FUN_00428570();
extern void FUN_00488fc0();
extern void FUN_004108a0();
extern void FUN_004f2600();
extern std::uint32_t FUN_00430190_();
extern void FUN_004ae4f0();
extern void FUN_004b06c0();
extern void FUN_004ff590();
extern void FUN_004ad820();
extern std::uint32_t FUN_005f0ddc();
extern std::uint32_t FUN_004bba60();
extern void FUN_004f4de0();
extern void FUN_004f0dc0();
extern void FUN_004f3350();
extern void FUN_00412f10();
extern void FUN_00412df0();
extern void FUN_00412f90();
extern void operator_delete(void*);
extern void operator_delete__(void*);
std::uint32_t FUN_00430190_wrap(std::uint32_t a, std::uint32_t b, void* c) { (void)a;(void)b;(void)c; return 0; }
extern int DAT_0072c774, DAT_0072c658, DAT_0072c654, DAT_0072c65c, DAT_0072c64c, DAT_0072c650, DAT_0072cd78[], DAT_0072cd74;
extern int DAT_0085a154, DAT_0085a158, DAT_0085a164;
extern int DAT_00862008, DAT_00869ab0, DAT_00869ab4, DAT_00869b1a, DAT_00869b48, DAT_00869b34, DAT_008142f8, DAT_0081431e;
extern int DAT_00723b14[], DAT_008dbd08[], DAT_008dbd0c[], DAT_008dbd10[], DAT_008cb100[], DAT_008cb104[], DAT_008cb108[];
extern std::uint8_t DAT_00860b70[], DAT_00860b74[], DAT_00860b7c[], DAT_00860b80[], DAT_00860b75[], DAT_0086201e[], DAT_00814350[], DAT_00814336[], DAT_00862006[], DAT_00869a78[], DAT_00869a88[];
extern std::uint8_t DAT_0085bf74[], DAT_0085bf7c[], DAT_0085bf7e[], DAT_0085bf98[], DAT_0085bfb4[], DAT_0085bfc2[];
extern std::uint8_t DAT_008e9fec[], DAT_008ecd78[];
extern float DAT_008cac44;
extern float DAT_008cab0c;
extern std::uint8_t DAT_008cac27, DAT_008c7328, DAT_008c732c[], DAT_008c7330[], DAT_008c8288[], DAT_008c827f, DAT_008c827e;
extern HCURSOR DAT_008cacd8;
extern void* PTR_DAT_00726640;
extern int DAT_00726638, DAT_0072663c;
extern void FUN_00412710(), FUN_004a29c0(), FUN_004a78a0(), FUN_004888e0(), FUN_004054a0(), FUN_0043a970(), FUN_00488840(), FUN_0046b790(), FUN_004a7bc0(), FUN_00428950(), FUN_004f60b0(), FUN_004879f0(), FUN_00489130(), FUN_004d0cd0(), FUN_004a7a40(), FUN_004a24b0(), FUN_004e43c0(), FUN_0040c730(), FUN_00406f60(), FUN_004b21a0(), FUN_0045b5d0(), FUN_0045bbf0(), FUN_004102a0(), FUN_00404810(), FUN_004048a0();

// 0x40fe90 — observed shape: self is in_ECX index; 5 guarded short compares <= DAT_0072c698; returns 0/1.
unsigned char FUN_0040fe90(void* self) {
    unsigned char uVar1 = 0;
    int index = (int)(intptr_t)self;
    if ((DAT_00869ab8 != 0) && ((std::int16_t)DAT_0085bfb6[index * 0x4a] <= DAT_0072c698)) uVar1 = 1;
    if ((DAT_00869abc != 0) && ((std::int16_t)DAT_0085bfb8[index * 0x4a] <= DAT_0072c698)) uVar1 = 1;
    if ((DAT_00869ac0 != 0) && (*(std::int16_t*)(DAT_0085bfba + index * 0x94) <= DAT_0072c698)) uVar1 = 1;
    if ((DAT_00869ac4 != 0) && ((std::int16_t)DAT_0085bfbc[index * 0x4a] <= DAT_0072c698)) uVar1 = 1;
    if ((DAT_00869ac8 != 0) && ((std::int16_t)DAT_0085bfbe[index * 0x4a] <= DAT_0072c698)) uVar1 = 1;
    return uVar1;
}

// 0x40ff40 — trade execution; early-out heretics path; copies 7 dwords; 5-int accumulation loop (0x14 bytes).
void FUN_0040ff40(int param_1) {
    if (FUN_0040fe00() == 0) {
        FUN_00486990((std::uint32_t)param_1, 1);
        DAT_008be9c8 = 0; DAT_008be9c0 = 10;
        FUN_004f6090("We do not trade with @NATIONALITY heretics.\n", (int)DAT_00869aa8);
        FUN_00430190((int)(DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3U)) >> 2, DAT_0085a268 / 0xc, DAT_006f5896, 0, 0xffffffff, 0, 0, 0xffffffff, 0, 0);
        FUN_00487850();
        return;
    }
    if (DAT_008c8200 != 5 && DAT_008c8200 != 6 && DAT_008e8eff == 0) { FUN_004985e0(); FUN_004a14b0(); }
    {
        std::uint32_t* src = (std::uint32_t*)&DAT_0072c698;
        std::uint32_t* dst = (std::uint32_t*)&DAT_0072c67c;
        for (int i = 7; i != 0; i--) { *dst++ = *src++; }
    }
    if (FUN_00533c78(0xe8) != 0) {
        void* pv = FUN_004dcf20(0xe8, 0, &DAT_0072c698, &DAT_0072c660, 0xffffffff);
        if (pv) { FUN_004dd090(); operator_delete(pv); }
    }
    DAT_008cac38 = 1;
    {
        std::int32_t* pi = (std::int32_t*)(DAT_0085bf9c + param_1 * 0x25 * 4);
        for (int off = 0; off < 0x14; off += 4) {
            *pi += *(std::int32_t*)((std::uint8_t*)&DAT_0072c69c + off) - *(std::int32_t*)((std::uint8_t*)&DAT_0072c680 + off);
            pi++;
        }
    }
    *(std::int32_t*)(DAT_0085bf94 + param_1 * 0x25 * 4) += (DAT_0072c698 - DAT_0072c67c);
    FUN_00428570(param_1);
    if (DAT_008c8200 != 5 && DAT_008c8200 != 6) { FUN_00488fc0(&DAT_008c7340, 0xffffffff, 0xbf800000); FUN_004985e0(); FUN_004a14b0(); }
}

// 0x410180 — guarded on DAT_008e8eff; alloc 100 via FUN_00533c78; runs action if DAT_00860b74[param_1*0x20] < 5; unconditional epilogue.
void FUN_00410180(int param_1) {
    if (DAT_008e8eff == 0) { FUN_004985e0(); FUN_004a14b0(); }
    if ((std::int8_t)DAT_00860b74[param_1 * 0x20] < 5 && FUN_00533c78(100) != 0) {
        void* pv = FUN_004d5a50(param_1);
        if (pv) { FUN_004d5b90(); operator_delete(pv); }
    }
    FUN_004985e0(); FUN_004a14b0();
}

// 0x410bf0 — self is in_ECX index; selects background texture by DAT_00860b74[idx*0x20] value 0-4/5/6/default.
void FUN_00410bf0(void* self) {
    std::int8_t c = (std::int8_t)DAT_00860b74[(int)(intptr_t)self * 0x20];
    if (c >= 0 && c < 5) { FUN_004108a0(); return; }
    if (c == 5) { FUN_004f2600("native_back.dds"); return; }
    if (c == 6) { FUN_004f2600("mission_back.dds"); return; }
    FUN_004f2600("Tm_f_townback_rich.dds");
}

// 0x410c50 — calls FUN_00410bf0; chooses buffer by DAT_008ca904; draws via FUN_00430190; releases DAT_008cadec refcount ptr.
std::uint32_t FUN_00410c50() {
    FUN_00410bf0(nullptr);
    std::uint8_t* local = DAT_008cacd0;
    if (DAT_008ca904 != 0) local = DAT_006f5896;
    std::uint32_t r = FUN_00430190_(DAT_0085a26c / 0xc, DAT_0085a268 / 0x18, local);
    if (DAT_008cadec != 0) {
        FUN_004ae4f0();
        std::uint32_t* p = (std::uint32_t*)DAT_008cadec;
        if (DAT_008cadec != 0) {
            int v = (int)p[1] - 1; p[1] = (std::uint32_t)v;
            if (v == 0) { void** vt = (void**)p; ((void(*)(int))vt[0])(1); }
        }
        DAT_008cadec = 0; DAT_008ca904 = 0;
    }
    return r;
}

// 0x412710 — pushes DAT_007263bc to table indexed by DAT_00726a84; sets/clears bit 0x20 by sign of DAT_0085a164.
void FUN_00412710() {
    DAT_007268f4[DAT_00726a84++] = DAT_007263bc;
    if (DAT_0085a164 < 0) DAT_007263bc = (DAT_007263bc & 0xfffffffa) | 0x20;
    else DAT_007263bc &= 0xfffffffa;
}

// 0x412770 — calls param_4 param_3 times (param_3-1 >= 0 guard).
void FUN_00412770(std::uint32_t, std::uint32_t, int param_3, void(*param_4)()) {
    if (param_3 - 1 >= 0) do { param_4(); } while (--param_3 != 0);
}

// 0x4127b0 — identical shape to 0x412770.
void FUN_004127b0(std::uint32_t, std::uint32_t, int param_3, void(*param_4)()) {
    if (param_3 - 1 >= 0) do { param_4(); } while (--param_3 != 0);
}

// 0x4127e0 — forwards to FUN_004b06c0 with fixed tail (DAT_0085a11c, 1, 0xffffffff, 0).
void FUN_004127e0(std::uint32_t p1, std::uint32_t p2, std::uint32_t p3, std::uint32_t p4) {
    FUN_004b06c0(p1, p2, p3, DAT_0085a11c, p4, 1, 0xffffffff, 0);
}

// 0x412810 — self: in_EAX/in_ECX pair; abs both; weighted average (2*max+min)/2.
int FUN_00412810(int in_EAX, int in_ECX) {
    if (in_ECX < 0) in_ECX = -in_ECX;
    if (in_EAX < 0) in_EAX = -in_EAX;
    if (in_EAX < in_ECX) return (in_EAX + in_ECX * 2) / 2;
    return (in_ECX + in_EAX * 2) / 2;
}

// 0x412840 — self is in_EAX base; copies 7 dwords at self+0x128; calls FUN_004ff590/FUN_004ad820 if last two words differ.
void FUN_00412840(float param_1, float param_2, void* self) {
    std::uint32_t local[7];
    std::uint32_t* src = (std::uint32_t*)((std::uint8_t*)self + 0x128);
    for (int i = 0; i < 7; i++) local[i] = src[i];
    float local_c = *(float*)&local[5]; float local_8 = *(float*)&local[6];
    if (local_8 != param_2 || local_c != param_1) { FUN_004ff590(param_1, param_2); FUN_004ad820(); }
}

// 0x4128a0 — self is unaff_ESI; f=(param_3*100)/param_4; null-check; double FUN_005f0ddc; FUN_004bba60.
std::uint32_t FUN_004128a0(std::uint32_t, std::uint32_t, int param_3, int param_4, void* self) {
    float f = ((float)param_3 * 100.0f) / (float)param_4;
    if (self == nullptr) return 0;
    std::uint32_t u1 = FUN_005f0ddc(f, 0);
    std::uint32_t u2 = FUN_005f0ddc(u1);
    return FUN_004bba60((std::uint32_t)(intptr_t)self, u2, u1, f, 0);
}

// 0x412900 — like 0x4128a0 but f=(float)param_3.
std::uint32_t FUN_00412900(std::uint32_t, std::uint32_t, int param_3, void* self) {
    float f = (float)param_3;
    if (self == nullptr) return 0;
    std::uint32_t u1 = FUN_005f0ddc(f, 0);
    std::uint32_t u2 = FUN_005f0ddc(u1);
    return FUN_004bba60((std::uint32_t)(intptr_t)self, u2, u1, f, 0);
}

// 0x412950 — self is unaff_ESI bound; returns rand() % bound, 0 if bound < 1.
int FUN_00412950(void* self) {
    int bound = (int)(intptr_t)self;
    if (bound < 1) return 0;
    return std::rand() % bound;
}

// 0x412970 — self is in_ECX; resets string fields at +0x34/+0x38 to DAT_008cacd0 (deleting old unless empty/1); calls FUN_004f4de0.
void FUN_00412970(void* self) {
    std::uint8_t* b = (std::uint8_t*)self;
    {
        std::uint32_t* p = (std::uint32_t*)(*(std::int32_t*)(b + 0x34) - 8);
        if (p && p != (std::uint32_t*)DAT_008cacc8) operator_delete__(p);
        *(void**)(b + 0x34) = DAT_008cacd0;
    }
    {
        std::uint32_t* p = (std::uint32_t*)(*(std::int32_t*)(b + 0x38) - 8);
        if (p && p != (std::uint32_t*)DAT_008cacc8) operator_delete__(p);
        *(void**)(b + 0x38) = DAT_008cacd0;
    }
    FUN_004f4de0();
}

// 0x4129c0 — appends *param_2 string (size at src-4) to static buffer DAT_008cacd0 at DAT_008caccc; wraps FUN_00412f10/FUN_00412df0.
std::uint32_t FUN_004129c0(std::uint32_t param_1, void** param_2) {
    FUN_00412f10();
    int cur = DAT_008caccc;
    void* src = *param_2;
    std::size_t size = *(std::size_t*)((std::uint8_t*)src - 4);
    if (size > 0 && cur >= 0 && src != nullptr) {
        if (cur < (int)(cur + size)) { FUN_004f3350(); DAT_008cacd0[cur] = 0; }
        std::memmove(DAT_008cacd0 + cur, src, size);
    }
    FUN_00412df0();
    return param_1;
}

// 0x412a60 — appends self string + param_2 (strlen) to static buffer; handles empty cases via FUN_00412f90.
std::uint32_t FUN_00412a60(std::uint32_t param_1, char* param_2, void** self) {
    std::uint8_t* src = (std::uint8_t*)*self;
    std::size_t size = *(std::size_t*)(src - 4);
    if ((std::int64_t)size >= 0 && src != nullptr && src != DAT_008cacd0) {
        if (size == 0) FUN_00412f90();
        else { FUN_004f3350(); std::memmove(DAT_008cacd0, src, size); DAT_008cacd0[DAT_008caccc] = 0; }
    }
    int cur = DAT_008caccc;
    std::size_t len = 0;
    if (param_2 != nullptr) { const char* p = param_2; while (*p++ != 0) len++; }
    if (len > 0 && cur >= 0 && param_2 != nullptr) {
        if (cur < (int)(cur + len)) { FUN_004f3350(); DAT_008cacd0[cur] = 0; }
        std::memmove(DAT_008cacd0 + cur, param_2, len);
    }
    FUN_00412df0();
    return param_1;
}

// 0x412b40 — self is in_ECX vtable object; retargets PTR_FUN_006f5814->006f583c->006f5864; resets string slots 0xe/0xd/7.
void FUN_00412b40(void* self) {
    std::uint32_t* base = (std::uint32_t*)self;
    *base = (std::uint32_t)(intptr_t)PTR_FUN_006f5814;
    {
        std::uint32_t* p = (std::uint32_t*)(base[0xe] - 8);
        if (p && p != (std::uint32_t*)DAT_008cacc8) operator_delete__(p);
        base[0xe] = (std::uint32_t)(intptr_t)DAT_008cacd0;
    }
    {
        std::uint32_t* p = (std::uint32_t*)(base[0xd] - 8);
        if (p && p != (std::uint32_t*)DAT_008cacc8) operator_delete__(p);
        base[0xd] = (std::uint32_t)(intptr_t)DAT_008cacd0;
    }
    *base = (std::uint32_t)(intptr_t)PTR_FUN_006f583c;
    FUN_004f4de0();
    *base = (std::uint32_t)(intptr_t)PTR_FUN_006f5864;
    FUN_004f0dc0();
    {
        std::uint32_t* p = (std::uint32_t*)(base[7] - 8);
        if (p && p != (std::uint32_t*)DAT_008cacc8) operator_delete__(p);
        base[7] = (std::uint32_t)(intptr_t)DAT_008cacd0;
    }
}

// 0x412bc0 — scalar delete wrapper: calls FUN_00412b40, deletes self if param_1&1.
void FUN_00412bc0(unsigned char param_1, void* self) {
    FUN_00412b40(self);
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x410d30 — observed shape: main town-visit loop (849 lines); entry guards 0x2c/0x80000; FUN_00412710 push/pop; cursor swap; 5 audio param blocks; switch on menu result 0-5 and default governorship/crew events; returns 0 on FUN_004054a0 fail, 1 on exit.
int FUN_00410d30(int param_1) {
    FUN_00412710();
    if (param_1 < 0x2c && ((DAT_00860b70[param_1 * 8] & 0x80000) == 0)) {
        int iVar14 = (int)(std::int16_t)DAT_0085bf7c[param_1 * 0x4a];
        int iVar8 = (int)(std::int8_t)DAT_00860b74[param_1 * 0x20] * 2;
        if ((DAT_00869a78[(std::int8_t)DAT_00860b74[param_1 * 0x20]] + iVar14 < DAT_0085a158 - 4)
            || ((iVar14 + 5 + (DAT_00869a88[iVar8] - DAT_0085a158)) * 0x32 <= (int)(std::int16_t)DAT_0085bf7e[param_1 * 0x4a] || DAT_0085a164 < 0)) {
            if ((DAT_00869a78[(std::int8_t)DAT_00860b74[param_1 * 0x20]] + iVar14 < DAT_0085a158 - 4)
                || (((DAT_00869a88[iVar8] - DAT_0085a158) + 5 + iVar14) * 0x32 <= (int)(std::int16_t)DAT_0085bf7e[param_1 * 0x4a]))
                FUN_004888e0(0x56, 0xffffffff, 0xffffffff, 0xbf800000);
            DAT_00726a84--; DAT_007263bc = DAT_007268f4[DAT_00726a84];
            DAT_0072cd78[0x17] = 10;
            if (FUN_004054a0(param_1) == 0) return 0;
            FUN_00412710(); FUN_004a29c0(); FUN_004a78a0(0);
            goto draw_header;
        }
    }
    FUN_004a29c0(); FUN_004a78a0(0);
draw_header:
    HCURSOR hCursor = DAT_008cacd8 ? DAT_008cacd8 : LoadCursorA(nullptr, (LPCSTR)nullptr);
    HCURSOR hCursor_00 = GetCursor(); SetCursor(hCursor);
    FUN_0043a970(0x23, param_1, 0, 0);
    {
        int uVar12 = DAT_008c8200;
        if ((bool(*)(DAT_008ecd78))() == 0) FUN_00488840("The audio manager has not been properly initialized yet", 0);
        else if (DAT_008e8eff == 0) { FUN_004985e0(); FUN_004a14b0(); (void)uVar12; }
    }
    int iVar8 = param_1 * 0x20; DAT_0072c774 = param_1;
reinit:
    DAT_0072c658 = (DAT_0085bf74[param_1 * 0x25] + param_1) & 0x80000007;
    if (DAT_0072c658 < 0) DAT_0072c658 = (DAT_0072c658 - 1 | 0xfffffff8) + 1;
    DAT_0072c654 = std::rand() % 0x11;
    if (std::rand() % 3 == 0 && DAT_00869b2c == 0) DAT_0072c654 = 0xc;
    DAT_0072c698 = 0; DAT_0072c69c = 0; DAT_0072c6a0 = 0; DAT_0072c660 = 0; DAT_0072c6a4 = 0;
    DAT_0072c664 = 0; DAT_0072c6a8 = 0; DAT_0072c64c = (DAT_0072c65c > 2) - 1;
    DAT_0072c6ac = 0; DAT_0072c668 = 0; DAT_0072c6b0 = 0; DAT_0072c66c = 0; DAT_0072c670 = 0; DAT_0072c674 = 0; DAT_0072c650 = 0;
    DAT_00860b70[param_1 * 8] &= 0xfffffddf; DAT_0072c678 = 0;
    {
        std::int8_t cVar6 = (std::int8_t)DAT_00860b74[iVar8];
        if (cVar6 == 4) {
            DAT_0072c698 = std::rand() % 100; DAT_0072c660 = 1; DAT_0072c664 = 5; DAT_0072c670 = 5;
            DAT_0072c668 = 10; DAT_0072c66c = 2; DAT_0072c674 = 2;
            DAT_0072c69c = std::rand() % 10 + 5; DAT_0072c65c = (int)(std::int16_t)DAT_0085bfc2[param_1 * 0x4a];
        } else if (cVar6 == 5) {
            DAT_0072c698 = std::rand() % 0x32; DAT_0072c660 = 1;
            DAT_0072c69c = std::rand() % 10 + 5;
            DAT_0072c664 = 0x19 / (std::rand() % 10 + 6);
            DAT_0072c668 = 10; DAT_0072c66c = 10; DAT_0072c6a8 = std::rand() % 5; DAT_0072c670 = 2;
            DAT_0072c6ac = std::rand() % 10; DAT_0072c674 = 1; DAT_0072c65c = 0; DAT_0072c64c = -1;
            goto have_prices;
        } else if (cVar6 == 6) {
            DAT_0072c698 = std::rand() % 100; DAT_0072c660 = 1; DAT_0072c664 = 10; DAT_0072c668 = 2;
            DAT_0072c670 = 2; DAT_0072c66c = 2; DAT_0072c674 = 1; DAT_0072c65c = 0; DAT_0072c64c = -1;
            DAT_0072c69c = std::rand() % 10 + 2;
            goto have_prices;
        } else {
            DAT_0072c698 = (int)(std::int32_t)DAT_0085bf94[param_1 * 0x25] / 3;
            DAT_0072c660 = 1; FUN_00428570(param_1);
            for (int k = 1; k < 7; k++) {
                std::int16_t s = *(std::int16_t*)(DAT_0085bfb4 + (k + param_1 * 0x4a) * 2);
                int v = (std::int32_t)DAT_0085bf98[param_1 * 0x25 + k];
                (&DAT_0072c660)[k] = s; if (v < 0) v = 0; else if (v > 99) v = 99;
                (&DAT_0072c698)[k] = v;
                if (DAT_00860b80[param_1 * 8] == 7) {
                    int lim = 200 / (s + 1); int w = lim < 1 ? 0 : std::rand() % lim; (&DAT_0072c698)[k] = w;
                }
                if (k == 2 || k == 4) (&DAT_0072c698)[k] /= 2;
                if (k == 6) DAT_0072c6b0 = (DAT_0072c6b0 + ((DAT_0072c6b0 >> 0x1f) & 3)) >> 2;
            }
            DAT_0072c65c = ((FUN_00404810() * (std::int16_t)DAT_0085bfc2[param_1 * 0x4a] * 0x14) / (DAT_00862008 + 10)) / (FUN_004048a0() + 3);
            if (DAT_0072c65c < 3) DAT_0072c65c = 0;
            if (DAT_00860b80[param_1 * 8] == 7) { DAT_0072c698 = std::rand() % 100 + 0x32; DAT_0072c69c = std::rand() % 10 + 5; }
            if (std::rand() % 0x28 <= DAT_0085a158 + 2 && DAT_00869ab4 > 1000 && param_1 < 0x2c) DAT_00860b70[param_1 * 8] |= 0x2000;
        }
    }
    if (DAT_0072c65c != 0) DAT_0072c64c = 0; else DAT_0072c64c = -1;
have_prices:;
    {
        int iStack_424 = -1; std::int8_t kind = (std::int8_t)DAT_00860b74[iVar8];
        if (kind == 4) {
            int idx = 1; std::int16_t* row = (std::int16_t*)DAT_0086201e;
            for (int* p = (int*)row; (int)(intptr_t)p < 0x86211a; p += 7, idx++) if (p[-5] != 0 && *p == param_1) iStack_424 = idx;
        }
        DAT_0085a164 |= 0x400; DAT_008cac44 = 1.0f; FUN_0046b790(0x5dc); DAT_0085a164 &= 0xfffffbff;
        SetCursor(hCursor_00);
        for (;;) {
            FUN_004a7bc0();
            DAT_00860b70[param_1 * 8] |= 1;
            int mood = (int)(std::int8_t)DAT_00860b7c[param_1 * 8] / 0x14;
            const char* text = "The @NATIONALITY @CITYTYPE of @CITYNAME (pop. @NUM). ";
            if (mood <= 1) text = "The @NATIONALITY @CITYTYPE of @CITYNAME (pop. @NUM) is quiet and desolate. ";
            else if (mood <= 3) text = "The @NATIONALITY @CITYTYPE of @CITYNAME (pop. @NUM) is baking in the sun. ";
            else if (mood <= 5) text = "The @NATIONALITY @CITYTYPE of @CITYNAME (pop. @NUM) is bustling with activity. ";
            else if (mood <= 7) text = "The @NATIONALITY @CITYTYPE of @CITYNAME (pop. @NUM) is clean and prosperous. ";
            else if (mood <= 9) text = "The @NATIONALITY @CITYTYPE of @CITYNAME (pop. @NUM) is brimming with wealth. ";
            int mood_arg = FUN_00428950(DAT_008dbd08[param_1 * 3], DAT_008dbd0c[param_1 * 3], DAT_008dbd10[param_1 * 3], (unsigned)(unsigned char)DAT_00860b75[iVar8] * 200);
            FUN_004f6090(text, (int)(std::int8_t)DAT_00860b74[iVar8], mood_arg);
            if (param_1 < 0x2c && ((DAT_00860b70[param_1 * 8] & 0x20000) == 0)) FUN_004f60b0("@UNIQUES", param_1);
            FUN_004879f0(0x2c, 0);
            const char* menu = nullptr;
            switch (DAT_00860b80[param_1 * 8]) {
            case 4:
                FUN_004f60b0("\nDo you...\n");
                if (iStack_424 == -1) { FUN_004f60b0(" Talk to the Captain\n"); menu = " Visit the Tavern\n Trade with the Merchant\n Consult with the Shipwright\n Divide the Plunder\n"; }
                else { int slot = *(std::int16_t*)(DAT_00862006 + iStack_424 * 0x1c);
                    if (slot == -1 || ((DAT_00814350[slot * 0x117] & 0x200) != 0)) { FUN_004f60b0(" Talk to @TOP10\n", DAT_008cb100[iStack_424 * 3], DAT_008cb104[iStack_424 * 3], DAT_008cb108[iStack_424 * 3]); menu = " Visit the Tavern\n Trade with the Merchant\n Consult with the Shipwright\n Divide the Plunder\n"; }
                    else { FUN_004f60b0(" Talk to @TOP10 (at sea)\n", DAT_008cb100[iStack_424 * 3], DAT_008cb104[iStack_424 * 3], DAT_008cb108[iStack_424 * 3]); DAT_00814350[slot * 0x117] |= 0x80; DAT_00814336[slot * 0x22e] = FUN_0045b5d0(); menu = " Visit the Tavern\n Trade with the Merchant\n Consult with the Shipwright\n Divide the Plunder\n"; } }
                FUN_004f60b0(menu); break;
            case 5: FUN_004f60b0("\nDo you...\n Talk to the Chief\n Trade with the Chief\n"); break;
            case 6: FUN_004f60b0("\nDo you...\n Talk to the Abbot\n Trade with the Abbot\n"); break;
            case 7: FUN_004f60b0("\nDo you...\n Talk to the Mayor\n Visit the Tavern\n Trade with the Merchant\n Consult with the Shipwright\n Divide the Plunder\n"); break;
            default: FUN_004f60b0(" Do you...\n Talk to the Governor\n Visit the Tavern\n Trade with the Merchant\n Consult with the Shipwright\n Divide the Plunder\n"); break;
            }
            FUN_004f60b0(" Check Status\n");
            if (DAT_0085a164 < 0) {
                int k = DAT_00860b80[param_1 * 8];
                FUN_004f60b0(k == 4 ? " Leave Pirate Haven\n" : k == 5 ? " Leave Village\n" : k == 6 ? " Leave Mission\n" : " Leave Town\n");
            } else FUN_004f60b0(" Sail away\n");
            if (DAT_008cac44 != 0.0f) { DAT_007268f4[DAT_00726a84] = DAT_007263bc; DAT_007263bc |= 5; FUN_004d0cd0(0, DAT_008cac44, 0); DAT_00726a84--; DAT_007263bc = DAT_007268f4[DAT_00726a84]; }
            int pick = FUN_00410c50();
            if ((DAT_00860b80[param_1 * 8] == 6 || DAT_00860b80[param_1 * 8] == 5) && pick > 0) pick += (pick != 1) * 2 + 1;
            {
                std::uint32_t* tmp = nullptr;
                ((void(*)(std::uint32_t**))(*(void***)DAT_008e9fec))[0x1d](&tmp, DAT_0072cd78[0x17]);
                if (tmp && --tmp[1] == 0) ((void(*)(std::uint32_t*, int))tmp[0])(tmp, 1);
            }
            int iVar9 = *(int*)(DAT_0072cd74 + 0xf4); if (iVar9 > 0) FUN_004e43c0(1);
            switch (pick) {
            case 0:
                if ((std::int8_t)DAT_00860b74[iVar8] == 5 || (DAT_008cac44 = 2.0f, (std::int8_t)DAT_00860b74[iVar8] == 6)) DAT_008cac44 = 1.0f;
                FUN_00410c50();
            case 6:
                if ((std::int8_t)DAT_00860b74[iVar8] < 5 || (std::int8_t)DAT_00860b74[iVar8] > 6) { FUN_004985e0(); FUN_004a14b0(); FUN_0040c730(param_1); }
                if (DAT_00860b80[param_1 * 8] == 7) { FUN_004985e0(); FUN_004a14b0(); }
                if (((std::int8_t)DAT_00860b74[iVar8] < 5 || (std::int8_t)DAT_00860b74[iVar8] > 6) && DAT_008c7328 == 0) { FUN_004985e0(); FUN_004a14b0(); }
                DAT_008c7328 = 0; break;
            case 1:
                FUN_004985e0(); FUN_004a14b0(); DAT_0085a164 |= 0x100000; FUN_00406f60(param_1); DAT_0085a164 &= 0xffefffff; FUN_004985e0(); FUN_004a14b0(); break;
            case 2:
                FUN_004985e0(); FUN_004a14b0();
                if ((std::int8_t)DAT_00860b74[iVar8] == 5 || (std::int8_t)DAT_00860b74[iVar8] == 6) { DAT_008cab0c = 0x3f800000; DAT_008c827f = 0; DAT_008c827e = 0; }
                FUN_0040ff40(param_1); FUN_004985e0(); FUN_004a14b0();
                if ((std::int8_t)DAT_00860b74[iVar8] == 5 || (std::int8_t)DAT_00860b74[iVar8] == 6) { if (DAT_008c827f) { FUN_00489130(DAT_008c8288); DAT_008c827f = 0; } } else if ((std::int8_t)DAT_00860b74[iVar8] < 4) FUN_00489130(DAT_008c7330);
                break;
            case 3:
                FUN_004985e0(); FUN_004a14b0(); FUN_00410180(param_1); FUN_004985e0(); FUN_004a14b0(); break;
            case 4: if (FUN_004102a0() != 0) goto reinit; break;
            case 5: FUN_004b21a0(1, 0, 1, 0); break;
            default: {
                if (DAT_0085a158 == 0) {
                    if (DAT_0072c65c < 5 || (*(int*)(DAT_00723b14 + DAT_008142f8 * 0x44) << 1) / 3 <= DAT_0081431e || DAT_0085a154 > 11999 || DAT_0072c650 != 0) {
                        if (param_1 < 0x2c && ((DAT_00860b70[param_1 * 8] & 0x20) == 0)) {
                            int b = DAT_00869a88[(int)(std::int8_t)DAT_00860b74[iVar8] * 2];
                            if (b < 9 && b != 0 && ((std::int16_t)DAT_0085bf7c[param_1 * 0x4a] + (std::int16_t)DAT_00869a78[(std::int8_t)DAT_00860b74[iVar8]] - (b + 1) * (b + 1) / 2 - *(std::int16_t*)(DAT_00869a88 + (int)(std::int8_t)DAT_00860b74[iVar8] * 2)) >= 0) {
                                FUN_004f6090("\'@RANK @PCNAME, the governor requests the pleasure of your company!\'\n", b, DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
                                FUN_004879f0(0x20, 0); FUN_004f60b0(" Very well, tell him I\'m coming.\n No matter, cast off!\n");
                                if (FUN_00410c50() == 0) { FUN_004985e0(); FUN_004a14b0(); goto walk_out; }
                                goto crew_events;
                            }
                        }
                        goto merchant_events;
                    }
                    FUN_004f6090("\'Captain, there\'s a group of @NUM men back at the tavern eager to join our crew.\'\n", DAT_0072c65c);
                    FUN_004879f0(0x20, 0); FUN_004f60b0(" Let\'s sign them up.\n No matter, cast off!\n");
                    if (FUN_00410c50() == 0) { FUN_004985e0(); FUN_004a14b0(); DAT_0085a164 |= 0x100000; FUN_00406f60(param_1); DAT_0085a164 &= 0xffefffff; FUN_004985e0(); FUN_004a14b0(); break; }
                }
merchant_events:
                if (DAT_0085a158 == 0) {
                    int looted = 0; for (int* q = &DAT_00869abc; (int)(intptr_t)q < 0x869ac9; q++) looted += *q;
                    if (FUN_0040fe00() != 0 && FUN_0040fe90() != 0 && DAT_0085a158 == 0 && looted > 99 && DAT_0085a154 < 36000) {
                        FUN_004f6090("\'Captain, the merchant will offer a good price for those goods we\'re hauling.\'\n");
                        FUN_004879f0(0x20, 0); FUN_004f60b0(" Let\'s sell them then.\n No matter, cast off!\n");
                        if (FUN_00410c50() == 0) { FUN_004985e0(); FUN_004a14b0(); if ((std::int8_t)DAT_00860b74[iVar8] == 5 || (std::int8_t)DAT_00860b74[iVar8] == 6) { DAT_008cab0c = 0x3f800000; DAT_008c827f = 0; DAT_008c827e = 0; } FUN_0040ff40(param_1); FUN_004985e0(); FUN_004a14b0(); break; }
                    }
                }
crew_events:
                if (FUN_00404810() == 0 && DAT_00869ab0 > 0x28) {
                    int desert = (DAT_00869ab0 + ((DAT_00869ab0 >> 0x1f) & 3)) >> 2;
                    desert = desert < 1 ? 0 : std::rand() % desert; desert += 2;
                    if ((DAT_00869b34 & 0x40) != 0) desert /= 2;
                    if (desert == 1) FUN_004f6090("The crew is mutinous after @NUM months of sailing. Roll call reveals that 1 crewman has deserted.\n", DAT_00869b1a);
                    else FUN_004f6090("The crew is mutinous after @NUM months of sailing. Roll call reveals that @NUM crewmen have deserted.\n", DAT_00869b1a, desert);
                    FUN_004879f0(0x2c, 0); FUN_00410c50(); DAT_00869ab0 -= desert; FUN_0045bbf0(0); DAT_00869b48 = 0;
                }
walk_out:
                DAT_00860b70[param_1 * 8] &= 0xfffffddf; DAT_008cac44 = 1.0f;
                FUN_004e43c0(iVar9); ((void(*)(int))(DAT_008e9fec[0x70]))(DAT_0072cd78[0x17], 1);
                FUN_00410c50();
                if (DAT_008cac27 == 0) break;
                DAT_00726a84--; DAT_007263bc = DAT_007268f4[DAT_00726a84]; DAT_0072cd78[0x17] = 10;
                FUN_004a7a40(0); FUN_004a24b0(); SetCursor(hCursor_00);
                return 1;
            }
            }
            FUN_004e43c0(iVar9); ((void(*)(int))(DAT_008e9fec[0x70]))(DAT_0072cd78[0x17], 1);
            if (DAT_008cac27 != 0) { DAT_00726a84--; DAT_007263bc = DAT_007268f4[DAT_00726a84]; DAT_0072cd78[0x17] = 10; FUN_004a7a40(0); FUN_004a24b0(); SetCursor(hCursor_00); return 1; }
        }
    }
}
