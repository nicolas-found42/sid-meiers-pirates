// UNVERIFIED decompiler-derived reconstruction — Ghidra 12.2 pseudocode corpus,
// PE32 i386. Sources: analysis/pseudocode/functions/0x4b2170.c through
// 0x4b7c70.c (one complete listing per function). No PASS or byte-match claim.
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern "C" void* memmove(void*, const void*, size_t);
extern "C" char* strrchr(const char*, int);
extern "C" char* strncat(char*, const char*, size_t);
extern "C" int sprintf(char*, const char*, ...);
extern "C" int _stricmp(const char*, const char*);
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);

// ---------------------------------------------------------------------------
// Helpers reproducing recurring idioms in the listings.
// ---------------------------------------------------------------------------

// (**(code **)(*obj + slot))(...)): virtual call through the object's vtable.
template <typename Fn>
static Fn vtbl_slot(int* obj, uintptr_t slot)
{
    return reinterpret_cast<Fn>(*reinterpret_cast<void**>(
        static_cast<uintptr_t>(*obj) + slot));
}

// First byte past the HUD scratch string at 0x869b48.
static char* hud_end()
{
    char* p = &DAT_00869b48;
    while (*p != '\0') ++p;
    return p;
}

// Inline dword/byte copy used by the listings to append text to 0x869b48.
static void hud_append(const char* text)
{
    const char* begin = text;
    while (*text != '\0') ++text;
    char* dst = hud_end();
    const size_t bytes = static_cast<size_t>(text - begin);
    size_t i = 0;
    for (; i + 4 <= bytes; i += 4) {
        *reinterpret_cast<uint32_t*>(dst + i) =
            *reinterpret_cast<const uint32_t*>(begin + i);
    }
    for (; i < bytes; ++i) dst[i] = begin[i];
    dst[bytes] = '\0';
}

// piVar = obj + 1; *piVar = *piVar - 1; if (*piVar == 0) (**(*obj))(1);
static void release_obj(void* obj)
{
    int32_t* ref = reinterpret_cast<int32_t*>(obj) + 1;
    *ref = *ref - 1;
    if (*ref == 0) {
        typedef void (*Dtor)(void*, int);
        (*reinterpret_cast<Dtor>(*reinterpret_cast<void**>(obj)))(obj, 1);
    }
}

// ---------------------------------------------------------------------------
// External helpers and globals observed in the supplied listings.
// ---------------------------------------------------------------------------
extern int32_t FUN_00508190(void);
extern int32_t FUN_00412770(void* dst, int32_t elementSize, int32_t count, void* ctor);
extern void FUN_00412cb0(void* a = nullptr, void* b = nullptr);
extern void FUN_00412df0(void* a = nullptr);
extern void FUN_00412ec0(void);
extern void FUN_00412f10(void);
extern void FUN_00412f90(void);
extern void FUN_00412fb0(void);
extern int FUN_00430190(int a, int b, const char* file, int c, int d, int e, int f, int g, int h,
                        int i);
extern int FUN_0042e1d0(const void* arg);
extern int FUN_0042e440(void);
extern void FUN_0042e730(void);
extern int64_t FUN_0042c6f0(void);
extern void FUN_00401d10(int a);
extern char FUN_00401ee0(void* a, const char* b, int c);
extern char FUN_004022e0(void* out, int a, int b, void* c);
extern int FUN_00405d90(void);
extern void FUN_0043cde0(int a, const char* file, int b, int c, int d, uint32_t e);
extern void FUN_0043e550(int a);
extern void FUN_0043ffc0(void);
extern void FUN_00443a00(void);
extern void FUN_004461c0(int a, int b, int c, int d, int e, int f, int g);
extern void FUN_00449390(void* a, int b);
extern int FUN_0044a670(int a, int b, int c);
extern void FUN_00453a20(void);
extern void FUN_0045fcb0(int a, int b, uint32_t c, int d, uint32_t e);
extern void FUN_00471b40(uint32_t a, int b);
extern char FUN_004879c0(const void* a, int b);
extern void FUN_004879f0(int a, int b);
extern void FUN_00487fd0(int a, int b);
extern void FUN_004881b0(int a, int b);
extern void FUN_004888e0(int a, int b, int c, uint32_t d);
extern void FUN_004889c0(void* a, int b, int c, int d, int e, uint32_t f, uint32_t g);
extern void FUN_00494e80(void);
extern void FUN_004a2380(void);
extern void FUN_004aea30(void);
extern void FUN_004af080(int a, int b, int c, int d, int e, int f, int g, int h, int i,
                         uint32_t j, int k);
extern int FUN_004b00e0(void);
extern void FUN_004b06c0(char* text, int x, int y, int a, uint32_t color, int b, uint32_t c,
                         int d);
extern int FUN_004b12e0(void);
extern int FUN_004b17f0(const char* name, const char* file, int x, int y, int z);
extern void FUN_004b1940(void);
extern void FUN_004b1990(int a);
extern void FUN_004b19e0(void* self, int a, int b, int c);
extern void FUN_004b1ec0(void* self);
extern void FUN_004b20f0(void);
extern int32_t FUN_004b2df0(int* out);
extern void FUN_004b2f10(void);
extern void FUN_004b3270(uint32_t* table, int x);
extern void FUN_004b40b0(uint32_t* table, char* last);
extern int FUN_004b3420(int param_1, int* table = nullptr, char flag = 0, int start = 0);
extern bool FUN_004b31e0(int in_EAX = 0);
extern int32_t FUN_004b3590(void);
extern void FUN_004b3640(int a, int b, int c, void* self = nullptr);
extern void FUN_004b4760(char flag);
extern int32_t FUN_004b5d90(int a, int b);
extern void FUN_004b5f80(void* self = nullptr);
extern void FUN_004b6020(void* dst = nullptr, const void* src = nullptr);
extern char FUN_004b6070(char flag);
extern char FUN_004b6f60(char flag);
extern char FUN_004b7c70(char flag, int32_t countSails, int32_t sailsBase, int32_t countFlags,
                         int32_t flagsBase);
extern void FUN_004b5a40(void);
extern void FUN_004b6de0(void* dst, const void* src = nullptr);
extern int FUN_004b9650(void);
extern int FUN_004b2d00(const char* name, const char* file, int id, char checked, float x,
                        float y);
extern int FUN_004b2a70(const char* name, const char* file, int id, float x, float y,
                        uint32_t extra);
extern uint32_t FUN_004b2760(int a, void* self = nullptr);
extern int32_t FUN_004b2170(void);
extern void FUN_004b24a0(int* self, char flag);
extern int FUN_004b2810(int* obj, int a, int b, int c, int key);
extern void FUN_004b21a0(int a, int b, int c, int d, void* self);
extern int FUN_004baaa0(void);
extern int FUN_004bb500(int a);
extern int FUN_004bba60(void* obj, int a, int b, uint32_t c, int d);
extern void FUN_004bbe10(int a, uint32_t b);
extern void FUN_004bcd30(uint32_t a);
extern void FUN_004bdca0(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern int FUN_004bf530(int a, const char* pattern);
extern int FUN_004bf5e0(int a, const char* pattern);
extern void FUN_004bf8c0(int a, void* out);
extern void FUN_004bf940(int a, void* out);
extern void FUN_004c9930(void);
extern int FUN_004cddf0(const char* name, int a, int b, void* w, void* h);
extern void FUN_004d0cd0(int a, int b, int c = 0);
extern void FUN_004d2170(const char* file);
extern void FUN_004d4500(void);
extern void FUN_004dadc0(uint32_t a, int b, int c);
extern void FUN_004e2df0(void);
extern void FUN_004e2e40(void);
extern void FUN_004f1840(void);
extern void FUN_004f18c0(int* out, int delim);
extern void FUN_004f2600(const char* fmt, const char* arg);
extern void FUN_004f3350(void);
extern int FUN_004f6090(const char* fmt, ...);
extern int FUN_00500410(void);
extern int FUN_00500850(void);
extern void FUN_004b1a30(void);
extern int FUN_00502460(void);
extern void FUN_00503fb0(void* obj);
extern void FUN_00504070(int a);
extern void FUN_00505920(void);
extern void FUN_00506040(int a, uint32_t b, int c, int d, uint32_t e);
extern void FUN_00505fc0(uint32_t a, int b, int c, uint32_t d);
extern int FUN_00506440(void);
extern void FUN_00509500(int a, char* text, int b);
extern void FUN_0050c4d0(void);
extern void FUN_0050c550(int a);
extern void FUN_0050c650(void);
extern void FUN_0050c680(void);
extern int FUN_00533c78(int size);
extern int thunk_FUN_00533c78(int size);
extern void FUN_00533d10(int a, int b);
extern void FUN_00534130(void);
extern void FUN_0053c7c0(uint32_t a);
extern int FUN_005426d0(void);
extern void FUN_005451a0(int a);
extern void FUN_005516a0(void);
extern int FUN_00551600(int a);
extern int FUN_005e4780(void);
extern int FUN_005f0ddc(int a = 0, int b = 0);
extern void FUN_00506c60(const char* name, const char* file, float x, float y, uint32_t a,
                         uint32_t b);
extern void FUN_00506e60(const char* name, const char* file, float x, float y, uint32_t a,
                         uint32_t b, int c);

extern int32_t DAT_007226f0;
extern int32_t DAT_007261e8;
extern int32_t DAT_00726238;
extern int32_t DAT_0072623c;
extern int32_t DAT_00726240;
extern int32_t DAT_00726398;
extern int32_t DAT_007263a0;
extern char DAT_007263b0;
extern char DAT_007263b9;
extern char DAT_007263ba;
extern int32_t DAT_007263bc;
extern int32_t DAT_00726b74;
extern char PTR_DAT_00726ba0;
extern int32_t DAT_0072cd78;
extern char DAT_00727520;
extern char DAT_00728d88;
extern int32_t DAT_00727444;
extern const char DAT_0070c664[];
extern const char DAT_0070c700[];
extern const char DAT_0070c79c[];
extern int32_t DAT_0085a0fc;
extern int32_t DAT_0085a11c;
extern uint32_t DAT_0085a164;
extern int32_t DAT_0085a26c;
extern int32_t DAT_0085a268;
extern char DAT_00869b48;
extern int16_t DAT_0086bb52;
extern int16_t DAT_0086bb53;
extern int* DAT_0086bb5c;
extern int16_t DAT_0086bb60[];
extern int16_t DAT_0086bcf0[];
extern int16_t DAT_0086be80[];
extern int16_t DAT_0086c010[];
extern int16_t DAT_0086c1a0[];
extern int32_t DAT_0086c330;
extern int32_t DAT_0086c35c;
extern int32_t DAT_0086c360;
extern uint32_t DAT_008b96b0;
extern uint32_t DAT_008b96b4;
extern char DAT_008ca6c0[];
extern char* DAT_008ca800[];
extern int32_t DAT_008ca4c8[];
extern int32_t DAT_008ca4cc;
extern char DAT_008cabec;
extern char DAT_008cabed;
extern void* DAT_008cabf0;
extern int32_t DAT_008cac00;
extern int32_t DAT_008cac18;
extern int32_t DAT_008cac1c;
extern char DAT_008cac26;
extern char DAT_008cac27;
extern int32_t DAT_008cac34;
extern uint8_t DAT_008cac35;
extern int32_t DAT_008cac38;
extern void* DAT_008cac40;
extern int32_t DAT_008cacc8;
extern int32_t DAT_008caccc;
extern char DAT_008cacd0;
extern int32_t DAT_008cad10;
extern uint32_t DAT_008cad88;
extern int32_t DAT_008cabe8;
extern int32_t DAT_008c8494;
extern int32_t DAT_008c9560;
extern int32_t DAT_008c9564;
extern uint32_t DAT_008c9568[];
extern int32_t DAT_008c9dd8;
extern int32_t DAT_008c9de0;
extern char DAT_008c8274;
extern char DAT_008c8278;
extern char DAT_008d1358;
extern int32_t DAT_008dc30c;
extern int32_t DAT_008dc310;
extern uint32_t* DAT_008e8fb4;
extern uint32_t* DAT_008e8fb8;
extern uint32_t DAT_008ea008;
extern int32_t DAT_008ea08c;
extern char DAT_008ea09c;
extern char DAT_008ea0b4;
extern int32_t DAT_008ed4c0;
extern uint32_t DAT_008ed618;
extern int _DAT_008ed61c;
extern uint32_t DAT_008ed61c;
extern int32_t DAT_008ea08c;
extern char DAT_006f588c;
extern char PTR_FUN_006fd14c;
extern char PTR_FUN_00710c40;
extern char PTR_PTR_00726a90;
extern char PTR_PTR_00726aa8;
extern uint8_t* PTR_DAT_00726a88;
extern uint8_t* PTR_DAT_00726a8c;

// ---------------------------------------------------------------------------
// 0x4b2170 — observed shape
// Destroys the three registered display objects at 0x8c9568..0x8c9574.
// ---------------------------------------------------------------------------
int32_t FUN_004b2170(void)
{
    uint32_t* puVar2 = DAT_008c9568;
    do {
        void* pvVar1 = reinterpret_cast<void*>(*puVar2);
        if (pvVar1 != nullptr) {
            FUN_00508190();
            operator_delete(pvVar1);
            *puVar2 = 0;
        }
        puVar2 = puVar2 + 1;
    } while (reinterpret_cast<intptr_t>(puVar2) < 0x8c9574);
    return 0;
}

// ---------------------------------------------------------------------------
// 0x4b21a0 — observed shape
// Sets the current pane index and services one update of the pane transition.
// ---------------------------------------------------------------------------
void FUN_004b21a0(int param_1, int param_2, int param_3, int param_4, void* self_raw)
{
    int* self = static_cast<int*>(self_raw);
    char cVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar7;
    int32_t uVar8;

    if (-1 < param_1) {
        *self = param_1;
    }
    FUN_004b19e0(self, param_2, param_3, param_4);
    cVar1 = *reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 0xef);
    while (cVar1 != '\0') {
        *reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 0xef) = 0;
        if (self[1] != *self) {
            if (*reinterpret_cast<char*>(self[self[1] + 6] + 0x290) != '\0') {
                FUN_00505920();
                iVar7 = *reinterpret_cast<int*>(self[self[1] + 6] + 0x23c);
                puVar3 = *reinterpret_cast<uint32_t**>(iVar7 + 0x18);
                while (puVar3 != nullptr) {
                    puVar2 = reinterpret_cast<uint32_t*>(*puVar3);
                    vtbl_slot<void (*)(void*)>(
                        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar7 + 0x14)), 8)(puVar3);
                    puVar3 = puVar2;
                }
                *reinterpret_cast<uint32_t*>(iVar7 + 0x20) = 0;
                *reinterpret_cast<uint32_t*>(iVar7 + 0x18) = 0;
                *reinterpret_cast<uint32_t*>(iVar7 + 0x1c) = 0;
                FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
            }
            if (*reinterpret_cast<char*>(self[*self + 6] + 0x290) != '\0') {
                FUN_00505920();
                iVar7 = *reinterpret_cast<int*>(self[*self + 6] + 0x23c);
                puVar3 = *reinterpret_cast<uint32_t**>(iVar7 + 0x18);
                while (puVar3 != nullptr) {
                    puVar2 = reinterpret_cast<uint32_t*>(*puVar3);
                    vtbl_slot<void (*)(void*)>(
                        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar7 + 0x14)), 8)(puVar3);
                    puVar3 = puVar2;
                }
                *reinterpret_cast<uint32_t*>(iVar7 + 0x20) = 0;
                *reinterpret_cast<uint32_t*>(iVar7 + 0x18) = 0;
                *reinterpret_cast<uint32_t*>(iVar7 + 0x1c) = 0;
                FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
                FUN_00505fc0(0x3e4ccccd, 0, 0, 0x3f800000);
            }
        }
        self[1] = *self;
        uVar6 = DAT_008b96b4;
        uVar5 = DAT_008b96b0;
        switch (*self) {
        case 1:
            FUN_00443a00();
            break;
        case 2:
            FUN_0043e550(param_2);
            break;
        case 3:
            FUN_0043ffc0();
            break;
        case 4:
            FUN_0043cde0(2, "shiplog.pcx", 0xff, 0, DAT_0085a26c / 6, 0xff000000);
            break;
        case 5:
            FUN_004e2e40();
            FUN_00494e80();
            FUN_004e2df0();
            break;
        case 6:
            FUN_0045fcb0(DAT_008b96b4, DAT_008b96b0, 0xffffffff, 9999, 0xc0008000);
            uVar4 = DAT_0085a0fc;
            *reinterpret_cast<int32_t*>(&DAT_00869b48) = 0;
            iVar7 = FUN_00405d90();
            if (iVar7 < 0x1f) {
                iVar7 = FUN_00405d90();
                if (iVar7 < 0x10) {
                    uVar8 = 6;
                } else {
                    uVar8 = 4;
                }
            } else {
                uVar8 = 2;
            }
            FUN_004461c0(uVar6, uVar5, uVar8, 0, 0, 1, 0xffffffff);
            DAT_0085a0fc = uVar4;
            break;
        case 7:
            FUN_00453a20();
            break;
        case 8:
            FUN_004c9930();
            break;
        case 9:
            FUN_004b4760(static_cast<char>(param_2));
            break;
        case 10:
            FUN_004b5a40();
            break;
        case 0xc:
            *reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 0xef) = 0;
            break;
        default:
            break;
        }
        cVar1 = *reinterpret_cast<char*>(reinterpret_cast<intptr_t>(self) + 0xef);
    }
    FUN_004b1ec0(self);
    DAT_008cac38 = 1;
}

// ---------------------------------------------------------------------------
// 0x4b24a0 — observed shape
// Draws the pause/pane overlay and the per-entry highlight rows.
// ---------------------------------------------------------------------------
void FUN_004b24a0(int* param_1, char param_2)
{
    uint32_t uVar1;
    char* pcVar2;
    int iVar3;
    char* pcVar4;
    int iVar5;
    int local_c;
    int local_8;
    int* local_4;

    if (param_1[0x3e] != 0) {
        FUN_004af080(param_1[0x3e], 0, 0, 0x400, 0x300, 0, 0, DAT_0085a26c, DAT_0085a268,
                     0xffffffff, 0x200);
        DAT_007263bc = DAT_007263bc | 0x1000;
        FUN_004f6090("@PAUSEMENU", param_1[1]);
        if (param_2 == '\0') {
            DAT_0085a11c = 100;
            FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2, DAT_007261e8 + -0x30, 100, 0xffffffff,
                         4, 0xffffffff, 0);
        }
    }
    local_4 = param_1 + 6;
    local_8 = 0;
    local_c = -0x1e;
    do {
        iVar3 = FUN_00506440();
        uVar1 = DAT_008cac00;
        bool matches = (iVar3 == 7);
        if (!matches) {
            DAT_008cac00 = uVar1;
            matches = (local_8 == param_1[2]);
        }
        if ((((-0x1f < local_c) && (local_c < 0xf00)) && (*local_4 != 0)) &&
            ((local_8 != *param_1 &&
              (*reinterpret_cast<char*>(*local_4 + 0x290) != '\0')) && matches)) {
            DAT_008cac00 = 100;
            FUN_004f6090("@PAUSEMENU", local_8);
            iVar3 = FUN_005f0ddc();
            pcVar2 = &DAT_00869b48;
            do {
                pcVar4 = pcVar2;
                pcVar2 = pcVar4 + 1;
            } while (*pcVar4 != '\0');
            ptrdiff_t len = pcVar4 - &DAT_00869b48;
            if (-1 < static_cast<int>(len)) {
                if (len == 0) {
                    FUN_00412f90();
                } else {
                    FUN_004f3350();
                    memmove(&DAT_008cacd0, &DAT_00869b48, static_cast<size_t>(len));
                    (&DAT_008cacd0)[DAT_008caccc] = 0;
                }
            }
            DAT_0085a11c = 0x43;
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_008cacd0, 0);
            FUN_005f0ddc();
            iVar5 = FUN_005f0ddc();
            if (iVar3 - iVar5 < 5) {
                iVar3 = iVar5 + 5;
            } else if (0x27b < iVar5 + iVar3) {
                iVar3 = 0x27b - iVar5;
            }
            DAT_0085a11c = 0x43;
            FUN_004b06c0(&DAT_00869b48, iVar3, 0x1cc, 0x43, 0xffffffff, 4, 0xffffffff, 0);
            DAT_008cac00 = uVar1;
        }
        local_c = local_c + 0x5a;
        local_8 = local_8 + 1;
        local_4 = local_4 + 1;
    } while (local_c < 0x528);
}

// ---------------------------------------------------------------------------
// 0x4b2760 — observed shape
// One frame of pane input; returns 1 when the pane requests a transition.
// ---------------------------------------------------------------------------
uint32_t FUN_004b2760(int param_1, void* self_raw)
{
    intptr_t self = reinterpret_cast<intptr_t>(self_raw);
    char cVar1;
    uint32_t uVar2;
    DWORD DVar3;
    uint32_t uVar4;
    uint32_t local_4;

    if ((*reinterpret_cast<char*>(self + 0xc) == '\0') ||
        (local_4 = 1, *reinterpret_cast<char*>(self + 0x100) == '\0')) {
        local_4 = 0;
    }
    FUN_004d0cd0(param_1, 0, 0);
    uVar2 = static_cast<uint32_t>(FUN_0042e440());
    cVar1 = FUN_004b2810(reinterpret_cast<int*>(self), 0, static_cast<int>(local_4), 1, param_1);
    if (cVar1 != '\0') {
        DVar3 = timeGetTime();
        *reinterpret_cast<DWORD*>(self + 0xf0) = DVar3;
        uVar2 = 0;
    }
    if (*reinterpret_cast<int*>(self + 0xf0) != 0) {
        DVar3 = timeGetTime();
        if (0xfa < DVar3 - *reinterpret_cast<int*>(self + 0xf0)) {
            *reinterpret_cast<uint32_t*>(self + 0xf0) = 0;
            *reinterpret_cast<char*>(self + 0xef) = 1;
        }
    }
    uVar4 = 1;
    if (*reinterpret_cast<char*>(self + 0xef) != '\x01') {
        uVar4 = uVar2;
    }
    return uVar4;
}

// ---------------------------------------------------------------------------
// 0x4b2810 — observed shape
// Maps a pane key to the next pane index and applies the transition.
// ---------------------------------------------------------------------------
bool FUN_004b2810(int* param_1, int param_2, int param_3, int param_4, int key)
{
    char cVar1;
    int iVar2;

    cVar1 = static_cast<char>(param_1[3]);
    if (cVar1 != '\0') {
        if (key == 0x123) {
            key = 0x17a;
        } else if (key == 0x122) {
            key = 0x17b;
        }
    }
    switch (key) {
    case 0x170:
    switchD_004b2849_caseD_170:
        iVar2 = 1;
        break;
    case 0x171:
        iVar2 = 2;
        break;
    case 0x172:
        iVar2 = param_1[0x10];
        if (iVar2 != 0) {
            if (static_cast<char>(param_3) != '\0') {
                if (*reinterpret_cast<char*>(iVar2 + 0x290) != '\0') goto LAB_004b2884;
                *reinterpret_cast<char*>(iVar2 + 0x290) = 1;
            }
            if (*reinterpret_cast<char*>(iVar2 + 0x290) == '\0') {
            LAB_004b28d1:
                FUN_004888e0(0x2e, 0xffffffff, 0xffffffff, 0xbf800000);
                return false;
            }
        }
    LAB_004b2884:
        iVar2 = 3;
        break;
    case 0x173:
        iVar2 = 4;
        break;
    case 0x174:
        iVar2 = 5;
        break;
    case 0x175:
        iVar2 = 6;
        break;
    case 0x176:
        iVar2 = 7;
        break;
    case 0x177:
        iVar2 = 8;
        break;
    case 0x179:
        if ((param_1[0x10] != 0) &&
            (*reinterpret_cast<char*>(param_1[0x10] + 0x290) == '\0')) {
            goto LAB_004b28d1;
        }
    LAB_004b293a:
        iVar2 = 10;
        break;
    case 0x17a:
        if (cVar1 == '\0') {
        LAB_004b29ac:
            iVar2 = param_3;
            goto LAB_004b29b0;
        }
        iVar2 = *param_1 - 1;
        if (iVar2 == 3) {
            if ((param_1[9] == 0) ||
                (*reinterpret_cast<char*>(param_1[9] + 0x290) == '\0')) {
                iVar2 = *param_1 - 2;
            }
        } else if (10 < iVar2) {
            iVar2 = 10;
            break;
        }
        if (0 < iVar2) goto LAB_004b29b0;
        if ((param_1[0x10] != 0) &&
            (*reinterpret_cast<char*>(param_1[0x10] + 0x290) != '\0')) {
            goto LAB_004b293a;
        }
        /* fall through */
    case 0x178:
        iVar2 = 9;
        break;
    case 0x17b:
        if (cVar1 == '\0') goto LAB_004b29ac;
        iVar2 = *param_1 + 1;
        if (iVar2 == 10) {
            if ((param_1[0x10] == 0) ||
                (*reinterpret_cast<char*>(param_1[0x10] + 0x290) == '\0')) {
                iVar2 = 1;
                break;
            }
        } else if (10 < iVar2) {
            goto switchD_004b2849_caseD_170;
        }
        if ((iVar2 == 3) &&
            ((param_1[9] == 0 ||
              (*reinterpret_cast<char*>(param_1[9] + 0x290) == '\0')))) {
            iVar2 = *param_1 + 2;
        }
    LAB_004b29b0:
        if (iVar2 == -1) goto LAB_004b2a2e;
        break;
    default:
        goto switchD_004b2849_default;
    }
    if (*param_1 == iVar2) {
        FUN_004889c0(&DAT_008c8274, 0x38, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                     0xffffffff);
    } else {
        FUN_004888e0(0x2d, 0xffffffff, 0xffffffff, 0xbf800000);
    }
    if (static_cast<char>(param_1[3]) != '\0') {
        if (iVar2 != *param_1) {
            *param_1 = iVar2;
            *reinterpret_cast<char*>(reinterpret_cast<intptr_t>(param_1) + 0xef) = 1;
            return iVar2 != -1;
        }
    switchD_004b2849_default:
        return false;
    }
    FUN_004b21a0(iVar2, param_2, param_3, param_4, param_1);
LAB_004b2a2e:
    return iVar2 != -1;
}

// ---------------------------------------------------------------------------
// 0x4b2a70 — observed shape
// Allocates and registers a scroll-thumb control, selecting its initial value.
// in_EAX in the listing is the live EAX after FUN_0050c4d0.
// ---------------------------------------------------------------------------
uint32_t* FUN_004b2a70(const char* param_1, const char* param_2, int param_3, float param_4,
                       float param_5, uint32_t /*extra*/)
{
    int iVar1;
    uint32_t* puVar2;
    uint32_t uVar3;
    const int32_t in_EAX = FUN_0050c4d0();

    puVar2 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2b4));
    if (puVar2 == nullptr) {
        puVar2 = nullptr;
    } else {
        FUN_00506e60(param_1, param_2, param_4 * 1.6f, param_5 * 1.6f, 0xc1200000, 0x3f800000, 0);
        *puVar2 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00710c40));
        *reinterpret_cast<uint8_t*>(puVar2 + 0xac) = 0;
        puVar2[0xa4] = 1;
        puVar2[0xa5] = 1;
    }
    puVar2[0xa4] = in_EAX;
    puVar2[0xa5] = 1;
    if (in_EAX == 0) {
        puVar2[0xa4] = 1;
    }
    puVar2[0x3b] = param_3;
    switch (param_3) {
    case 0:
        uVar3 = FUN_005f0ddc();
        break;
    case 1:
        uVar3 = DAT_00726398;
        goto LAB_004b2c8b;
    case 2:
        uVar3 = DAT_007263a0;
        break;
    case 3:
        uVar3 = *reinterpret_cast<uint32_t*>(DAT_0072cd78 + 0xc);
    LAB_004b2c8b:
        break;
    default:
        goto LAB_004b2c91;
    case 10:
        if (DAT_007263b0 == '\0') goto LAB_004b2c91;
        uVar3 = FUN_005f0ddc();
        break;
    case 0xb:
        if (DAT_007263b0 == '\0') goto LAB_004b2c91;
        uVar3 = FUN_005f0ddc();
        break;
    case 0xc:
        if (DAT_007263b0 == '\0') goto LAB_004b2c91;
        uVar3 = FUN_005f0ddc();
        break;
    case 0xd:
        if (DAT_007263b0 == '\0') goto LAB_004b2c91;
        uVar3 = FUN_005f0ddc();
        break;
    }
    FUN_0050c550(uVar3);
LAB_004b2c91:
    iVar1 = *reinterpret_cast<int*>(DAT_008cabe8 + 0x10);
    FUN_00503fb0(puVar2);
    vtbl_slot<void (*)(void*, int)>(
        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar1 + 4)), 0x70)(puVar2, 1);
    FUN_00534130();
    FUN_00533d10(0, 1);
    return puVar2;
}

// ---------------------------------------------------------------------------
// 0x4b2d00 — observed shape
// Allocates and registers a checkbox control.
// ---------------------------------------------------------------------------
int FUN_004b2d00(const char* param_1, const char* param_2, int param_3, char param_4,
                 float param_5, float param_6)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    iVar2 = FUN_00533c78(0x29c);
    if (iVar2 == 0) {
        iVar2 = 0;
    } else {
        FUN_00506c60(param_1, param_2, param_5 * 1.6f, param_6 * 1.6f, 0xc1200000, 0x3f800000);
    }
    *reinterpret_cast<uint32_t*>(iVar2 + 0x294) = 0;
    *reinterpret_cast<uint32_t*>(iVar2 + 0x298) = 1;
    *reinterpret_cast<uint32_t*>(iVar2 + 0xec) = param_3;
    uVar3 = static_cast<uint32_t>(param_4 != '\0');
    if (*reinterpret_cast<uint32_t*>(iVar2 + 0x290) != uVar3) {
        *reinterpret_cast<uint32_t*>(iVar2 + 0x290) = uVar3;
        FUN_00506040(*reinterpret_cast<int*>(iVar2 + 0x294 + uVar3 * 4), 0x3f800000, 0, 0,
                     0x3f800000);
    }
    iVar1 = *reinterpret_cast<int*>(DAT_008cabe8 + 0x10);
    FUN_00503fb0(reinterpret_cast<void*>(iVar2));
    vtbl_slot<void (*)(void*, int)>(
        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar1 + 4)), 0x70)(
        reinterpret_cast<void*>(iVar2), 1);
    FUN_00534130();
    FUN_00533d10(0, 1);
    return iVar2;
}

// ---------------------------------------------------------------------------
// 0x4b2df0 — observed shape
// Collects entries with id 0x16 whose percentage equals 0x4b, optionally
// copying them into the caller array; returns the entry count.
// ---------------------------------------------------------------------------
int FUN_004b2df0(int* param_1)
{
    uint32_t* puVar1;
    uint8_t bVar2;
    int* piVar3;
    uint8_t* puVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;
    int iVar8;
    int local_4;

    piVar3 = reinterpret_cast<int*>(DAT_008ea08c);
    iVar8 = 0;
    local_4 = 0;
    if (DAT_008ea08c != 0) {
        for (puVar4 = reinterpret_cast<uint8_t*>(vtbl_slot<void* (*)(int*)>(
                 piVar3, 4)(piVar3));
             puVar4 != nullptr;
             puVar4 = *reinterpret_cast<uint8_t**>(puVar4 + 4)) {
            if (puVar4 == reinterpret_cast<uint8_t*>(&DAT_00728d88)) {
                bVar2 = 1;
                goto LAB_004b2e34;
            }
        }
        bVar2 = 0;
    LAB_004b2e34:
        if ((((-(uint32_t)bVar2 & static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar3))) !=
              0) &&
             (iVar5 = *reinterpret_cast<int*>(
                  (-(uint32_t)bVar2 & static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar3))) +
                  0x280),
              iVar5 != 0)) &&
            (uVar6 = 0, *reinterpret_cast<int*>(iVar5 + 0x45c) != 0)) {
            iVar7 = 0;
            do {
                puVar1 = *reinterpret_cast<uint32_t**>(
                    *reinterpret_cast<int*>(iVar5 + 0x454) + uVar6 * 4);
                if (((puVar1 != nullptr) && (puVar1[3] == 0x16)) &&
                    ((0x27f < *puVar1 &&
                      ((puVar1[1] * 100) / *puVar1 == 0x4b)))) {
                    if (*param_1 != 0) {
                        *reinterpret_cast<uint32_t*>(iVar7 + *param_1) = uVar6;
                        *reinterpret_cast<uint32_t*>(iVar7 + 4 + *param_1) = *puVar1;
                        *reinterpret_cast<uint32_t*>(iVar7 + 8 + *param_1) = puVar1[1];
                    }
                    local_4 = local_4 + 1;
                    iVar7 = iVar7 + 0xc;
                }
                uVar6 = uVar6 + 1;
                iVar8 = local_4;
            } while (uVar6 < *reinterpret_cast<uint32_t*>(iVar5 + 0x45c));
        }
    }
    if (*param_1 == 0) {
        iVar7 = iVar8 * 0xc;
        iVar5 = thunk_FUN_00533c78(iVar7 + 0xc);
        *param_1 = iVar5;
        FUN_004b2df0(param_1);
        *reinterpret_cast<uint32_t*>(iVar7 + *param_1) = 0xffffffff;
        *reinterpret_cast<uint32_t*>(iVar7 + 4 + *param_1) = 0xffffffff;
        *reinterpret_cast<uint32_t*>(iVar7 + 8 + *param_1) = 0xffffffff;
    }
    return iVar8;
}

// ---------------------------------------------------------------------------
// 0x4b31e0 — observed shape
// Returns whether the control identified by key is currently usable.
// ---------------------------------------------------------------------------
bool FUN_004b31e0(int in_EAX)
{
    char cVar1;

    switch (in_EAX) {
    case 1:
        break;
    default:
        return false;
    case 8:
        cVar1 = static_cast<char>(FUN_00500410());
        return cVar1 == '\0';
    case 0xe:
        return DAT_008cabec == '\0';
    case 0x12:
        return DAT_008cabed == '\0';
    }
    if (((DAT_008cac35 == '\0') && (cVar1 = static_cast<char>(FUN_00500410()), cVar1 != '\0')) &&
        (DAT_008cad10 == '\0')) {
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// 0x4b3420 — observed shape
// Sums the maximum animation length over the control range [start, param_1]
// and adds the focus offsets for slider/checkbox entries.
// ---------------------------------------------------------------------------
int FUN_004b3420(int param_1, int* param_2, char param_3, int start)
{
    int* piVar1;
    bool bVar2;
    bool bVar3;
    int in_EAX = start;
    int iVar4;
    uint8_t* puVar5;
    int iVar6;

    iVar6 = 0;
    bVar2 = false;
    bVar3 = false;
    if (in_EAX <= param_1) {
        do {
            if ((-1 < in_EAX) && (in_EAX < 0x1c)) {
                switch (in_EAX) {
                case 0x13:
                case 0x14:
                    if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) != '\0') goto LAB_004b347b;
                    break;
                default:
                LAB_004b347b:
                    FUN_004b2f10();
                    DAT_0085a11c = 100;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                    iVar4 = FUN_005f0ddc();
                    piVar1 = *reinterpret_cast<int**>(
                        reinterpret_cast<uint8_t*>(param_2) + in_EAX * 4);
                    if (piVar1 != nullptr) {
                        for (puVar5 = reinterpret_cast<uint8_t*>(
                                 vtbl_slot<void* (*)(int*)>(piVar1, 4)(piVar1));
                             puVar5 != nullptr;
                             puVar5 = *reinterpret_cast<uint8_t**>(puVar5 + 4)) {
                            if (puVar5 == reinterpret_cast<uint8_t*>(&DAT_008ea09c)) {
                                bVar3 = true;
                                break;
                            }
                        }
                    }
                    piVar1 = *reinterpret_cast<int**>(
                        reinterpret_cast<uint8_t*>(param_2) + in_EAX * 4);
                    if (piVar1 != nullptr) {
                        for (puVar5 = reinterpret_cast<uint8_t*>(
                                 vtbl_slot<void* (*)(int*)>(piVar1, 4)(piVar1));
                             puVar5 != nullptr;
                             puVar5 = *reinterpret_cast<uint8_t**>(puVar5 + 4)) {
                            if (puVar5 == reinterpret_cast<uint8_t*>(&DAT_008ea0b4)) {
                                bVar2 = true;
                                break;
                            }
                        }
                    }
                    if (iVar6 < iVar4) {
                        iVar6 = iVar4;
                    }
                    break;
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1a:
                case 0x1b:
                    break;
                }
            }
            in_EAX = in_EAX + 1;
        } while (in_EAX <= param_1);
        if ((bVar2) && (param_3 != '\0')) {
            return iVar6 + 0xde;
        }
        if ((bVar3) && (param_3 != '\0')) {
            return iVar6 + 0x30;
        }
    }
    return iVar6;
}

// ---------------------------------------------------------------------------
// 0x4b3590 — observed shape
// Initialises the sound-device/host state and rebuilds the resolution list.
// ---------------------------------------------------------------------------
int32_t FUN_004b3590(void)
{
    uint32_t uVar1;
    // NEEDS_MANUAL: the listing names ECX live-outs (extraout_ECX/_00) of the two
    // FUN_004b9650 calls as the first argument of FUN_00412cb0; those values are
    // never written in the pseudocode.
    int extraout_ECX = 0;
    int extraout_ECX_00 = 0;

    FUN_004b9650();
    FUN_004b9650();
    FUN_00412cb0(reinterpret_cast<void*>(extraout_ECX), &PTR_PTR_00726a90);
    DAT_008c9564 = FUN_004b00e0();
    FUN_00412cb0(reinterpret_cast<void*>(extraout_ECX_00), &PTR_PTR_00726aa8);
    DAT_008c9560 = FUN_004b00e0();
    if ((DAT_008c9560 != 0) || (DAT_008cabed = 0, DAT_008c9564 != 0)) {
        DAT_008cabed = 1;
    }
    uVar1 = 0;
    DAT_008cabec = '\0';
    if (DAT_008cad88 != 0) {
        if (DAT_008cad88 == 0) {
            DAT_008cabec = '\0';
            goto LAB_004b361e;
        }
        do {
            DAT_008cabec = (&DAT_008ca6c0)[uVar1];
        LAB_004b361e:
            ;
        } while ((DAT_008cabec == '\0') &&
                 (uVar1 = uVar1 + 1, uVar1 < DAT_008cad88));
    }
    DAT_00726238 = FUN_004b2df0(reinterpret_cast<int*>(&DAT_008cabf0));
    return 0;
}

extern int32_t DAT_008c9574;
extern void FUN_004c24e0(void);

// ---------------------------------------------------------------------------
// 0x4b3640 — observed shape
// Creates or tears down the option rows for the index range [param_1, param_2]
// (param_3 carries the horizontal centre used for placement).
// self (EBX in the listing) is the pointer array of row controls.
// ---------------------------------------------------------------------------
void FUN_004b3640(int param_1, int param_2, int param_3, void* self_raw)
{
    float fVar1;
    float fVar2;
    float fVar3;
    char cVar4;
    int iVar5;
    uint32_t* puVar6;
    uint32_t uVar7;
    int* piVar8;
    uint8_t* puVar9;
    uint32_t* puStack_64;
    float local_78;
    int local_70;
    intptr_t self = reinterpret_cast<intptr_t>(self_raw);

    local_78 = static_cast<float>(DAT_0085a268) * 0.2f;
    // NEEDS_MANUAL: call site passes only the range end; the table/start registers
    // of FUN_004b3420 are not recovered by the listing.
    iVar5 = FUN_004b3420(param_2);
    fVar1 = static_cast<float>((iVar5 + param_3 * 2) / 2 + -0x3f);
    local_70 = 0;
    do {
        if ((local_70 < param_1) || (param_2 < local_70)) {
        switchD_004b36ce_caseD_16:
            iVar5 = *reinterpret_cast<int*>(self + local_70 * 4);
            if (iVar5 != 0) {
                FUN_00504070(iVar5);
                vtbl_slot<void (*)(void*, int)>(
                    reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar5 + 0x24)), 0x74)(
                    &puStack_64, iVar5);
                if ((puStack_64 != nullptr) &&
                    (iVar5 = static_cast<int>(puStack_64[1]), puStack_64[1] = iVar5 - 1,
                     iVar5 - 1 == 0)) {
                    release_obj(puStack_64);
                }
            }
            puVar6 = *reinterpret_cast<uint32_t**>(self + local_70 * 4);
            if (puVar6 != nullptr) {
                piVar8 = reinterpret_cast<int*>(puVar6 + 1);
                *piVar8 = *piVar8 + -1;
                if (*piVar8 == 0) {
                    release_obj(puVar6);
                }
                *reinterpret_cast<uint32_t*>(self + local_70 * 4) = 0;
            }
        } else {
            switch (local_70) {
            case 0x13:
            case 0x14:
                if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) == '\0') {
                    goto switchD_004b36ce_caseD_16;
                }
                /* fall through */
            default:
                switch (local_70) {
                case 0:
                    FUN_004b2a70("GammaSlider", "ScrollThumb.kfm", 0, fVar1, local_78,
                                 0x42ed8000);
                    FUN_004c24e0();
                    DAT_008c9574 = FUN_005f0ddc();
                    break;
                case 1:
                    FUN_004b2a70("WaterDetail", "ScrollThumb.kfm", 1, fVar1, local_78,
                                 0x42ed8000);
                    FUN_004c24e0();
                    break;
                case 2:
                    FUN_004b2a70("ObjectDetail", "ScrollThumb.kfm", 2, fVar1, local_78,
                                 0x42ed8000);
                    FUN_004c24e0();
                    break;
                case 3:
                    fVar2 = fVar1 * 1.6f;
                    fVar3 = local_78 * 1.6f;
                    puVar6 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2b4));
                    if (puVar6 == nullptr) {
                        puVar6 = nullptr;
                    } else {
                        FUN_00506e60("WorldDetail", "ScrollThumb.kfm", fVar2, fVar3, 0xc1200000,
                                     0x3f800000, 0);
                        *puVar6 = static_cast<uint32_t>(
                            reinterpret_cast<intptr_t>(&PTR_FUN_00710c40));
                        *reinterpret_cast<uint8_t*>(puVar6 + 0xac) = 0;
                        puVar6[0xa4] = 1;
                        puVar6[0xa5] = 1;
                    }
                    FUN_0050c4d0();
                    iVar5 = DAT_0072cd78;
                    puVar6[0xa4] = 5;
                    puVar6[0xa5] = 1;
                    puVar6[0x3b] = 3;
                    FUN_0050c550(*reinterpret_cast<uint32_t*>(iVar5 + 0xc));
                    iVar5 = *reinterpret_cast<int*>(DAT_008cabe8 + 0x10);
                    FUN_00503fb0(puVar6);
                    vtbl_slot<void (*)(void*, int)>(
                        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar5 + 4)), 0x70)(puVar6,
                                                                                          1);
                    FUN_00534130();
                    FUN_00533d10(0, 1);
                    FUN_004c24e0();
                    break;
                case 4:
                    fVar2 = fVar1 * 1.6f;
                    iVar5 = DAT_00726238 + -1;
                    fVar3 = local_78 * 1.6f;
                    puVar6 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2b4));
                    if (puVar6 == nullptr) {
                        puVar6 = nullptr;
                    } else {
                        FUN_00506e60("Resolution", "ScrollThumb.kfm", fVar2, fVar3, 0xc1200000,
                                     0x3f800000, 0);
                        *puVar6 = static_cast<uint32_t>(
                            reinterpret_cast<intptr_t>(&PTR_FUN_00710c40));
                        *reinterpret_cast<uint8_t*>(puVar6 + 0xac) = 0;
                        puVar6[0xa4] = 1;
                        puVar6[0xa5] = 1;
                    }
                    FUN_0050c4d0();
                    puVar6[0xa4] = iVar5;
                    puVar6[0xa5] = 1;
                    if (iVar5 == 0) {
                        puVar6[0xa4] = 1;
                    }
                    iVar5 = DAT_008cabe8;
                    puVar6[0x3b] = 4;
                    iVar5 = *reinterpret_cast<int*>(iVar5 + 0x10);
                    FUN_00503fb0(puVar6);
                    vtbl_slot<void (*)(void*, int)>(
                        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar5 + 4)), 0x70)(puVar6,
                                                                                          1);
                    FUN_00534130();
                    FUN_00533d10(0, 1);
                    FUN_004c24e0();
                    iVar5 = 0;
                    if (0 < DAT_00726238) {
                        piVar8 = reinterpret_cast<int*>(
                            reinterpret_cast<intptr_t>(DAT_008cabf0) + 8);
                        do {
                            if ((piVar8[-1] == DAT_008cac18) && (*piVar8 == DAT_008cac1c)) {
                                FUN_0050c550(iVar5);
                                DAT_0072623c = iVar5;
                                DAT_00726240 = iVar5;
                                break;
                            }
                            iVar5 = iVar5 + 1;
                            piVar8 = piVar8 + 3;
                        } while (iVar5 < DAT_00726238);
                    }
                    break;
                case 5:
                    FUN_004b2d00("ShadowCheckbox", "CheckBox24_24.kfm", 5, DAT_007263b9, fVar1,
                                 local_78 + 4.0f);
                    FUN_004c24e0();
                    break;
                case 6:
                    FUN_004b2d00("AdvancedLightingCheckbox", "CheckBox24_24.kfm", 6,
                                 DAT_008cac34, fVar1, local_78 + 4.0f);
                    FUN_004c24e0();
                    break;
                case 7:
                    FUN_004b2d00("TrilinearCheckbox", "CheckBox24_24.kfm", 7, DAT_007263ba, fVar1,
                                 local_78 + 4.0f);
                    FUN_004c24e0();
                    break;
                case 8:
                    FUN_004b2d00("DisableShadersCheckbox", "CheckBox24_24.kfm", 8, DAT_008cac35,
                                 fVar1, local_78 + 4.0f);
                    FUN_004c24e0();
                    break;
                case 10:
                    fVar2 = fVar1 * 1.6f;
                    fVar3 = local_78 * 1.6f;
                    puVar6 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2b4));
                    if (puVar6 == nullptr) {
                        puVar6 = nullptr;
                    } else {
                        FUN_00506e60("MasterVolume", "ScrollThumb.kfm", fVar2, fVar3, 0xc1200000,
                                     0x3f800000, 0);
                        *puVar6 = static_cast<uint32_t>(
                            reinterpret_cast<intptr_t>(&PTR_FUN_00710c40));
                        *reinterpret_cast<uint8_t*>(puVar6 + 0xac) = 0;
                        puVar6[0xa4] = 1;
                        puVar6[0xa5] = 1;
                    }
                    FUN_0050c4d0();
                    puVar6[0xa4] = 0x13;
                    puVar6[0xa5] = 1;
                    puVar6[0x3b] = 10;
                    if (DAT_007263b0 != '\0') {
                        uVar7 = FUN_005f0ddc();
                        FUN_0050c550(uVar7);
                    }
                    iVar5 = *reinterpret_cast<int*>(DAT_008cabe8 + 0x10);
                    FUN_00503fb0(puVar6);
                    vtbl_slot<void (*)(void*, int)>(
                        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar5 + 4)), 0x70)(puVar6,
                                                                                          1);
                    FUN_00534130();
                    FUN_00533d10(0, 1);
                    FUN_004c24e0();
                    break;
                case 0xb:
                    fVar2 = fVar1 * 1.6f;
                    fVar3 = local_78 * 1.6f;
                    puVar6 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2b4));
                    if (puVar6 == nullptr) {
                        puVar6 = nullptr;
                    } else {
                        FUN_00506e60("MusicVolume", "ScrollThumb.kfm", fVar2, fVar3, 0xc1200000,
                                     0x3f800000, 0);
                        *puVar6 = static_cast<uint32_t>(
                            reinterpret_cast<intptr_t>(&PTR_FUN_00710c40));
                        *reinterpret_cast<uint8_t*>(puVar6 + 0xac) = 0;
                        puVar6[0xa4] = 1;
                        puVar6[0xa5] = 1;
                    }
                    FUN_0050c4d0();
                    puVar6[0xa4] = 0x14;
                    puVar6[0xa5] = 1;
                    puVar6[0x3b] = 0xb;
                    if (DAT_007263b0 != '\0') {
                        uVar7 = FUN_005f0ddc();
                        FUN_0050c550(uVar7);
                    }
                    iVar5 = *reinterpret_cast<int*>(DAT_008cabe8 + 0x10);
                    FUN_00503fb0(puVar6);
                    vtbl_slot<void (*)(void*, int)>(
                        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar5 + 4)), 0x70)(puVar6,
                                                                                          1);
                    FUN_00534130();
                    FUN_00533d10(0, 1);
                    FUN_004c24e0();
                    break;
                case 0xc:
                    fVar2 = fVar1 * 1.6f;
                    fVar3 = local_78 * 1.6f;
                    puVar6 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2b4));
                    if (puVar6 == nullptr) {
                        puVar6 = nullptr;
                    } else {
                        FUN_00506e60("SoundVolume", "ScrollThumb.kfm", fVar2, fVar3, 0xc1200000,
                                     0x3f800000, 0);
                        *puVar6 = static_cast<uint32_t>(
                            reinterpret_cast<intptr_t>(&PTR_FUN_00710c40));
                        *reinterpret_cast<uint8_t*>(puVar6 + 0xac) = 0;
                        puVar6[0xa4] = 1;
                        puVar6[0xa5] = 1;
                    }
                    FUN_0050c4d0();
                    puVar6[0xa4] = 0x14;
                    puVar6[0xa5] = 1;
                    puVar6[0x3b] = 0xc;
                    if (DAT_007263b0 != '\0') {
                        uVar7 = FUN_005f0ddc();
                        FUN_0050c550(uVar7);
                    }
                    iVar5 = *reinterpret_cast<int*>(DAT_008cabe8 + 0x10);
                    FUN_00503fb0(puVar6);
                    vtbl_slot<void (*)(void*, int)>(
                        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar5 + 4)), 0x70)(puVar6,
                                                                                          1);
                    FUN_00534130();
                    FUN_00533d10(0, 1);
                    FUN_004c24e0();
                    break;
                case 0xd:
                    fVar2 = fVar1 * 1.6f;
                    fVar3 = local_78 * 1.6f;
                    puVar6 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2b4));
                    if (puVar6 == nullptr) {
                        puVar6 = nullptr;
                    } else {
                        FUN_00506e60("DanceMusicVolume", "ScrollThumb.kfm", fVar2, fVar3,
                                     0xc1200000, 0x3f800000, 0);
                        *puVar6 = static_cast<uint32_t>(
                            reinterpret_cast<intptr_t>(&PTR_FUN_00710c40));
                        *reinterpret_cast<uint8_t*>(puVar6 + 0xac) = 0;
                        puVar6[0xa4] = 1;
                        puVar6[0xa5] = 1;
                    }
                    FUN_0050c4d0();
                    puVar6[0xa4] = 0x13;
                    puVar6[0xa5] = 1;
                    puVar6[0x3b] = 0xd;
                    if (DAT_007263b0 != '\0') {
                        uVar7 = FUN_005f0ddc();
                        FUN_0050c550(uVar7);
                    }
                    iVar5 = *reinterpret_cast<int*>(DAT_008cabe8 + 0x10);
                    FUN_00503fb0(puVar6);
                    vtbl_slot<void (*)(void*, int)>(
                        reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar5 + 4)), 0x70)(puVar6,
                                                                                          1);
                    FUN_00534130();
                    FUN_00533d10(0, 1);
                    FUN_004c24e0();
                    break;
                default:
                    break;
                }
                piVar8 = *reinterpret_cast<int**>(self + local_70 * 4);
                if (piVar8 != nullptr) {
                    for (puVar9 = reinterpret_cast<uint8_t*>(
                             vtbl_slot<void* (*)(int*)>(piVar8, 4)(piVar8));
                         puVar9 != nullptr;
                         puVar9 = *reinterpret_cast<uint8_t**>(puVar9 + 4)) {
                        if (puVar9 == reinterpret_cast<uint8_t*>(&DAT_008ea09c)) {
                            goto LAB_004b3fc9;
                        }
                    }
                }
                cVar4 = static_cast<char>(FUN_004b31e0());
                if (cVar4 != '\0') {
                LAB_004b3fc9:
                    vtbl_slot<void (*)(void*, int)>(
                        reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(self + local_70 * 4)),
                        0x88)(nullptr, 0);
                }
                local_78 = local_78 + 26.0f;
                break;
            case 0x16:
            case 0x17:
            case 0x18:
            case 0x19:
            case 0x1a:
            case 0x1b:
                goto switchD_004b36ce_caseD_16;
            }
        }
        local_70 = local_70 + 1;
        if (0x1b < local_70) {
            return;
        }
    } while (true);
}

// Destructor call `(**(*obj))(1)` where no refcount update is present.
static void destroy_obj(void* obj)
{
    typedef void (*Dtor)(void*, int);
    (*reinterpret_cast<Dtor>(*reinterpret_cast<void**>(obj)))(obj, 1);
}

// ---------------------------------------------------------------------------
// 0x4b4760 — observed shape
// System options pane: builds the option rows, services input and either
// returns to the game or opens the sound/save/quit sub-dialogs.
// ---------------------------------------------------------------------------
void FUN_004b4760(char param_1)
{
    int* piVar1;
    uint8_t bVar2;
    int iVar3;
    char cVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int iVar8;
    uint8_t* puVar9;
    int16_t sVar10;
    uint32_t uVar11;
    int iVar12;
    char* pcVar13;
    uint32_t uVar14;
    uint8_t* puVar15;
    char* pcVar16;
    int iVar17;
    char* pcVar18;
    char* pcVar19;
    uint32_t* puVar20;
    int16_t* puVar21;
    uint32_t* puVar22;
    uint32_t uVar23;
    uint32_t uVar24;
    char* local_298;
    char* local_294;
    char* local_290;
    uint8_t* local_28c;
    uint32_t* local_288;
    uint32_t local_284;
    int local_280;
    char* local_27c;
    int local_278;
    int local_274;
    uint32_t local_270[92];
    char acStack_100[256];
    // NEEDS_MANUAL: ECX live-outs of the dialog calls are named (extraout_ECX,
    // extraout_ECX_00) by the listing but never written.
    int extraout_ECX = 0;
    uint32_t* extraout_ECX_00 = nullptr;

    local_294 = reinterpret_cast<char*>(0xffffffff);
    local_278 = -1;
    local_274 = -1;
    for (iVar12 = 0; iVar12 <= 0x1b; ++iVar12) local_270[iVar12] = 0;
    puVar15 = reinterpret_cast<uint8_t*>(DAT_0085a26c / 2);
    local_290 = reinterpret_cast<char*>(0x10);
    local_27c = reinterpret_cast<char*>(0x1b);
    local_270[0x1b] = 0;
    local_28c = puVar15;
    FUN_004b3590();
    FUN_004b3640(0x10, 0x1b, static_cast<int>(reinterpret_cast<intptr_t>(puVar15)));
    local_280 = FUN_004b3420(0x1b, reinterpret_cast<int*>(local_270), 1);
    iVar12 = DAT_008cabe8;
    if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) == '\0') {
        iVar5 = FUN_00533c78(4);
        if (iVar5 == 0) {
            DAT_008cac40 = nullptr;
        } else {
            DAT_008cac40 = reinterpret_cast<void*>(FUN_00502460());
        }
        *reinterpret_cast<uint32_t*>(DAT_008cac40) = *reinterpret_cast<uint32_t*>(iVar12 + 0x10);
        iVar12 = 0;
        do {
            FUN_004b20f0();
            iVar12 = iVar12 + 1;
        } while (iVar12 < 3);
    }
switchD_004b55c1_caseD_216:
    pcVar13 = local_294;
switchD_004b5126_default:
    iVar5 = DAT_0085a26c;
    iVar12 = DAT_0085a268;
    if (DAT_008cac27 != '\0') goto LAB_004b5910;
    DAT_0086c330 = 0;
    if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) == '\0') {
        local_298 = reinterpret_cast<char*>(0x300);
        local_284 = 0x400;
        uVar6 = FUN_004cddf0("pauseMenuBG.dds", 0, 0, &local_284, &local_298);
        FUN_004af080(uVar6, 0, 0, static_cast<int>(local_284),
                     static_cast<int>(reinterpret_cast<intptr_t>(local_298)), 0, 0, iVar5, iVar12,
                     0xffffffff, 0);
        FUN_004f6090("@PAUSEMENU", 9);
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2, 0xc, 100, 0xffffffff, 4, 0xffffffff, 0);
    } else {
        FUN_004b24a0(reinterpret_cast<int*>(DAT_008cabe8), 0);
    }
    local_298 = local_290;
    if (static_cast<int>(reinterpret_cast<intptr_t>(local_290)) <=
        static_cast<int>(reinterpret_cast<intptr_t>(local_27c))) {
        iVar12 = 0;
        pcVar18 = local_290;
        do {
            switch (reinterpret_cast<intptr_t>(pcVar18)) {
            case 0x13:
            case 0x14:
                if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) != '\0') {
                    goto switchD_004b4990_caseD_15;
                }
                break;
            default:
            switchD_004b4990_caseD_15:
                local_284 = 0xffffffff;
                local_298 = pcVar18;
                FUN_004b2f10();
                if (pcVar18 == pcVar13) {
                    local_284 = 0xffffcc00;
                    FUN_004af080(
                        0, 0, 0, 0, 0,
                        (static_cast<int>(reinterpret_cast<intptr_t>(local_28c)) * 2 - local_280) / 2,
                        DAT_0085a268 / 5 + iVar12, local_280 + 0x20, 0x18, 0xc0204080, 0xa0);
                }
                // NEEDS_MANUAL: key register for FUN_004b31e0 is not written here.
                cVar4 = static_cast<char>(FUN_004b31e0());
                iVar5 = static_cast<int>(reinterpret_cast<intptr_t>(local_28c)) * 2;
                local_288 = reinterpret_cast<uint32_t*>(DAT_0085a268 / 5 + 0xc + iVar12);
                uVar24 = 0;
                iVar17 = (iVar5 - local_280) / 2;
                uVar23 = 0x41400000;
                uVar6 = FUN_005f0ddc(0x41400000, 0);
                local_288 = reinterpret_cast<uint32_t*>(iVar17 + 0xc);
                uVar7 = FUN_005f0ddc(uVar6);
                FUN_004bba60(&DAT_008d1358, uVar7, uVar6, uVar23, uVar24);
                uVar6 = 0x80ffffff;
                if (cVar4 == '\0') {
                    uVar6 = local_284;
                }
                FUN_004b06c0(&DAT_00869b48, iVar17 + 0x18, DAT_0085a268 / 5 + iVar12, 100, uVar6,
                             1, 0xffffffff, 0);
                iVar3 = local_280;
                if (cVar4 == '\0') {
                    iVar8 = DAT_0086c330;
                    sVar10 = static_cast<int16_t>(DAT_0085a268 / 5) + static_cast<int16_t>(iVar12);
                    (&DAT_0086c1a0)[iVar8] =
                        static_cast<int16_t>(reinterpret_cast<intptr_t>(local_298));
                    (&DAT_0086be80)[iVar8] = sVar10;
                    (&DAT_0086c010)[iVar8] = static_cast<int16_t>(iVar17);
                    DAT_0086c330 = DAT_0086c330 + 1;
                    (&DAT_0086bcf0)[iVar8] =
                        static_cast<int16_t>(local_280) + 0x20 + static_cast<int16_t>(iVar17);
                    (&DAT_0086bb60)[iVar8] = sVar10 + 0x18;
                }
                if (reinterpret_cast<int*>(
                        local_270[static_cast<int>(reinterpret_cast<intptr_t>(local_298))]) !=
                    nullptr) {
                    for (puVar9 = reinterpret_cast<uint8_t*>(vtbl_slot<void* (*)(int*)>(
                             reinterpret_cast<int*>(
                                 local_270[static_cast<int>(reinterpret_cast<intptr_t>(
                                     local_298))]),
                             4)(reinterpret_cast<int*>(
                                 local_270[static_cast<int>(reinterpret_cast<intptr_t>(
                                     local_298))])));
                         puVar9 != nullptr;
                         puVar9 = *reinterpret_cast<uint8_t**>(puVar9 + 4)) {
                        if (puVar9 == reinterpret_cast<uint8_t*>(&DAT_008ea0b4)) {
                            iVar17 = DAT_0085a268 / 5;
                            local_284 = 0x10;
                            local_288 = reinterpret_cast<uint32_t*>(0x100);
                            uVar6 = FUN_004cddf0("SliderBar.dds", 0, 0, &local_288, &local_284);
                            FUN_004af080(uVar6, 0, 0, static_cast<int>(reinterpret_cast<intptr_t>(
                                                       local_288)),
                                         static_cast<int>(local_284), (iVar3 + iVar5) / 2 + -0xae,
                                         iVar17 + 9 + iVar12, 0xbe, 8, 0xffffffff, 0);
                            break;
                        }
                    }
                }
                FUN_004b3270(local_270, (iVar3 + iVar5) / 2 + -0xae);
                FUN_004b40b0(local_270, local_27c);
                iVar12 = iVar12 + 0x1a;
                pcVar13 = local_294;
                pcVar18 = local_298;
                break;
            case 0x16:
            case 0x17:
            case 0x18:
            case 0x19:
            case 0x1a:
            case 0x1b:
                break;
            }
            pcVar18 = pcVar18 + 1;
            local_298 = pcVar18;
        } while (static_cast<int>(reinterpret_cast<intptr_t>(pcVar18)) <=
                 static_cast<int>(reinterpret_cast<intptr_t>(local_27c)));
    }
    pcVar18 = local_27c;
    pcVar19 = local_290;
    if (static_cast<int>(reinterpret_cast<intptr_t>(local_290)) <=
        static_cast<int>(reinterpret_cast<intptr_t>(local_27c))) {
    LAB_004b4c60:
        if ((pcVar13 != reinterpret_cast<char*>(0xffffffff)) &&
            (reinterpret_cast<int*>(local_270[static_cast<int>(
                 reinterpret_cast<intptr_t>(pcVar19))]) != nullptr)) {
            for (puVar9 = reinterpret_cast<uint8_t*>(vtbl_slot<void* (*)(int*)>(
                     reinterpret_cast<int*>(local_270[static_cast<int>(
                         reinterpret_cast<intptr_t>(pcVar19))]),
                     4)(reinterpret_cast<int*>(local_270[static_cast<int>(
                         reinterpret_cast<intptr_t>(pcVar19))])));
                 puVar9 != nullptr; puVar9 = *reinterpret_cast<uint8_t**>(puVar9 + 4)) {
                if (puVar9 == reinterpret_cast<uint8_t*>(&DAT_008ea0b4)) {
                    piVar1 = reinterpret_cast<int*>(
                        local_270[static_cast<int>(reinterpret_cast<intptr_t>(pcVar19))]);
                    uVar14 = 0;
                    if (piVar1 == nullptr) goto LAB_004b4cbf;
                    puVar9 = reinterpret_cast<uint8_t*>(
                        vtbl_slot<void* (*)(int*)>(piVar1, 4)(piVar1));
                    goto joined_r0x004b4ca1;
                }
            }
        }
        goto LAB_004b4cf0;
    }
LAB_004b4cf9:
    if (local_278 == DAT_008dc30c) {
        if (local_274 != DAT_008dc310) goto LAB_004b4d11;
    } else {
    LAB_004b4d11:
        local_278 = DAT_008dc30c;
        local_274 = DAT_008dc310;
        pcVar19 = reinterpret_cast<char*>(FUN_0042c6f0());
        if ((pcVar19 != reinterpret_cast<char*>(0xffffffff)) && (pcVar19 != pcVar13)) {
            FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                         0xffffffff);
        }
    LAB_004b4d47:
        pcVar13 = pcVar19;
        local_294 = pcVar19;
    }
    if (local_290 == reinterpret_cast<char*>(0x10)) {
        local_298 = &DAT_008cacd0;
        if (DAT_00726b74 == 0) {
            pcVar19 = const_cast<char*>("Beta Version %s\n");
        } else {
            pcVar19 = const_cast<char*>("Version %s\n");
        }
        FUN_004f2600(pcVar19, &PTR_DAT_00726ba0);
        pcVar19 = local_298;
        DAT_0085a11c = 0x32;
        FUN_004b06c0(local_298,
                     DAT_0085a26c -
                         ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 0x1fU)) >> 5),
                     DAT_0085a268 - DAT_0085a268 / 6, 0x32, 0xffffff80, 2, 0xffffffff, 0);
        pcVar19 = pcVar19 + -8;
        if ((pcVar19 != nullptr) &&
            (pcVar19 != reinterpret_cast<char*>(&DAT_008cacc8))) {
            operator_delete__(pcVar19);
        }
    }
    if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) == '\0') {
        FUN_004d0cd0(0, 0, 0);
        pcVar19 = reinterpret_cast<char*>(FUN_0042e1d0(&DAT_006f588c));
        if (DAT_0086bb5c != nullptr) {
            sprintf(acStack_100, "%s_%03X", &DAT_006f588c,
                    static_cast<int>(reinterpret_cast<intptr_t>(pcVar19)));
            piVar1 = DAT_0086bb5c;
            iVar12 = vtbl_slot<int (*)(int*, const char*)>(piVar1, 4)(piVar1, acStack_100);
            for (puVar22 = *reinterpret_cast<uint32_t**>(piVar1[2] + iVar12 * 4);
                 puVar22 != nullptr; puVar22 = reinterpret_cast<uint32_t*>(*puVar22)) {
                cVar4 = static_cast<char>(
                    vtbl_slot<char (*)(int*, const char*, int)>(piVar1, 8)(
                        piVar1, acStack_100, static_cast<int>(puVar22[1])));
                if (cVar4 != '\0') {
                    pcVar19 = reinterpret_cast<char*>(puVar22[2]);
                    break;
                }
            }
        }
        pcVar18 = local_27c;
    } else {
        pcVar19 = reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_004b2760(0)));
    }
    pcVar16 = local_290;
    if (pcVar19 == reinterpret_cast<char*>(0xd)) {
        pcVar19 = pcVar13 + 0x200;
    }
    if (pcVar19 == reinterpret_cast<char*>(0x1b)) {
        FUN_004888e0(0x2e, 0xffffffff, 0xffffffff, 0xbf800000);
    LAB_004b4f19:
        if (pcVar19 == reinterpret_cast<char*>(0x1)) goto LAB_004b5910;
        if (pcVar19 == reinterpret_cast<char*>(0x1b)) {
        switchD_004b5126_caseD_209:
            FUN_0042e730();
            if ((local_290 == reinterpret_cast<char*>(0x10)) ||
                (pcVar19 == reinterpret_cast<char*>(0x215))) {
            LAB_004b5910:
                FUN_004b3640(0xffffffff, 0xffffffff, 0);
                if (DAT_008cabf0 != nullptr) {
                    operator_delete(DAT_008cabf0);
                    DAT_008cabf0 = nullptr;
                }
                if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) == '\0') {
                    if (DAT_008cac40 != nullptr) {
                        operator_delete(DAT_008cac40);
                        DAT_008cac40 = nullptr;
                    }
                    FUN_004b2170();
                }
                DAT_0086c330 = 0;
                do {
                    iVar12 = FUN_0042e1d0(0);
                } while (iVar12 != 0);
                DAT_0086c35c = 0;
                DAT_0086c360 = 0;
                FUN_004d2170("Config.ini");
                FUN_00412770(local_270, 4, 0x1c, reinterpret_cast<void*>(&FUN_005e4780));
                return;
            }
            local_28c = reinterpret_cast<uint8_t*>(DAT_0085a26c / 2);
            local_290 = reinterpret_cast<char*>(0x10);
            local_27c = reinterpret_cast<char*>(0x1b);
            FUN_004b3640(0x10, 0x1b,
                         static_cast<int>(reinterpret_cast<intptr_t>(local_28c)));
            uVar6 = 0x1b;
            goto LAB_004b4f87;
        }
        goto switchD_004b5126_default;
    }
    if (0x20e < static_cast<int>(reinterpret_cast<intptr_t>(pcVar19))) {
        switch (reinterpret_cast<intptr_t>(pcVar19)) {
        case 0x20f:
        case 0x215:
            goto switchD_004b5126_caseD_209;
        case 0x210:
            FUN_004888e0(0x2d, 0xffffffff, 0xffffffff, 0xbf800000);
            local_28c = reinterpret_cast<uint8_t*>(DAT_0085a26c / 2 + -0x20);
            local_290 = nullptr;
            local_27c = reinterpret_cast<char*>(9);
            FUN_004b3640(0, 9, static_cast<int>(reinterpret_cast<intptr_t>(local_28c)));
            uVar6 = 9;
            break;
        case 0x211:
            FUN_004888e0(0x2d, 0xffffffff, 0xffffffff, 0xbf800000);
            local_28c = reinterpret_cast<uint8_t*>(DAT_0085a26c / 2);
            local_290 = reinterpret_cast<char*>(0xa);
            local_27c = reinterpret_cast<char*>(0xf);
            FUN_004b3640(10, 0xf, static_cast<int>(reinterpret_cast<intptr_t>(local_28c)));
            uVar6 = 0xf;
            break;
        case 0x212:
            FUN_0042e730();
            cVar4 = FUN_004b7c70(*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) == '\0',
                                 DAT_008c9564,
                                 static_cast<int>(reinterpret_cast<intptr_t>(&PTR_PTR_00726a90)),
                                 DAT_008c9560,
                                 static_cast<int>(reinterpret_cast<intptr_t>(&PTR_PTR_00726aa8)));
            if (cVar4 != '\0') goto LAB_004b5910;
            goto switchD_004b5126_default;
        case 0x213:
            FUN_0042e730();
            puVar22 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
            if (puVar22 != nullptr) {
                puVar22[1] = puVar22[1] + 1;
            }
            *reinterpret_cast<uint8_t*>(puVar22 + 8) =
                *reinterpret_cast<uint8_t*>(puVar22 + 8) | 1;
            piVar1 = reinterpret_cast<int*>(puVar22 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                destroy_obj(puVar22);
            }
            FUN_004f6090(
                "Divide plunder in town and then retire to see the conclusion of your story, "
                "otherwise you will lose all unsaved progress in the current game. Are you sure "
                "you want to quit?\n Yes \n No\n");
            FUN_004879f0(0x28, 0);
            DAT_0086c330 = 0;
            iVar12 = FUN_00430190(
                DAT_0085a26c / 3,
                ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2) + 1, "pauseMenuBG.dds", 0,
                0xffffffff, 0, 0, 0xffffffff, 0, 0);
            puVar22 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
            if (puVar22 != nullptr) {
                puVar22[1] = puVar22[1] + 1;
            }
            *reinterpret_cast<uint8_t*>(puVar22 + 8) =
                *reinterpret_cast<uint8_t*>(puVar22 + 8) & 0xfe;
            piVar1 = reinterpret_cast<int*>(puVar22 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                destroy_obj(puVar22);
            }
            if (iVar12 != 0) goto switchD_004b55c1_caseD_216;
            DAT_008cac27 = '\x01';
            DAT_008cac26 = 1;
            goto switchD_004b5126_default;
        case 0x214:
            FUN_0042e730();
            FUN_004f6090("Are you sure you want to quit?\n Yes \n No\n");
            puVar22 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
            if (puVar22 != nullptr) {
                puVar22[1] = puVar22[1] + 1;
            }
            *reinterpret_cast<uint8_t*>(puVar22 + 8) =
                *reinterpret_cast<uint8_t*>(puVar22 + 8) | 1;
            piVar1 = reinterpret_cast<int*>(puVar22 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                destroy_obj(puVar22);
            }
            DAT_0086c330 = 0;
            iVar12 = FUN_00430190(
                ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3U)) >> 2) + 0x10,
                ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2) + 1, "pauseMenuBG.dds", 0,
                0xffffffff, 0, 0, 0xffffffff, 0, 0);
            puVar22 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
            if (puVar22 != nullptr) {
                puVar22[1] = puVar22[1] + 1;
            }
            *reinterpret_cast<uint8_t*>(puVar22 + 8) =
                *reinterpret_cast<uint8_t*>(puVar22 + 8) & 0xfe;
            piVar1 = reinterpret_cast<int*>(puVar22 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                destroy_obj(puVar22);
            }
            if (iVar12 == 0) {
                if (param_1 == '\0') {
                    local_28c = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
                    FUN_004f6090(DAT_0070c79c);
                    FUN_00412f10();
                    if (DAT_007226f0 == 0) {
                        pcVar13 = const_cast<char*>("arrival");
                    LAB_004b58e0:
                        uVar6 = FUN_004f6090(pcVar13, local_28c, 0);
                        FUN_00401d10(uVar6);
                    } else if (DAT_007226f0 == 1) {
                        pcVar13 = const_cast<char*>("battle");
                        goto LAB_004b58e0;
                    }
                    FUN_00412fb0();
                } else {
                    FUN_004f6090(DAT_0070c79c);
                    FUN_00401ee0(&DAT_00869b48, 0, 1);
                }
                DAT_007226f0 = 2;
                DAT_008cac27 = '\x01';
                goto LAB_004b5910;
            }
            goto switchD_004b5126_default;
        default:
            goto switchD_004b55c1_caseD_216;
        case 0x217:
            DAT_0086bb52 = DAT_0086bb52 == 0;
            goto switchD_004b5126_default;
        case 0x218:
            DAT_0086bb53 = DAT_0086bb53 == 0;
            goto switchD_004b5126_default;
        case 0x21a:
            goto switchD_004b55c1_caseD_21a;
        }
    LAB_004b4f87:
        local_280 = FUN_004b3420(static_cast<int>(uVar6), reinterpret_cast<int*>(local_270), 1);
        pcVar13 = reinterpret_cast<char*>(0xffffffff);
        local_294 = reinterpret_cast<char*>(0xffffffff);
        goto switchD_004b5126_default;
    }
    if (pcVar19 == reinterpret_cast<char*>(0x20e)) {
        FUN_0042e730();
        FUN_004f6090("Select the 3D Sound Driver\n Default\n");
        puVar20 = local_270 + 0x1c;
        for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
            *puVar20 = 0xffffffff;
            puVar20 = puVar20 + 1;
        }
        uVar14 = 0;
        local_298 = &DAT_008cacd0;
        if (DAT_008cad88 != 0) {
            local_288 = local_270 + 0x1d;
            if (DAT_008cad88 == 0) goto LAB_004b5403;
            do {
                if ((&DAT_008ca6c0)[uVar14] != '\0') {
                    FUN_00412f10();
                    FUN_00412df0(reinterpret_cast<void*>(extraout_ECX));
                    cVar4 = static_cast<char>(FUN_004b12e0());
                    pcVar13 = local_298;
                    if (cVar4 != '\0') {
                        iVar12 = _stricmp(local_298, "Miles Fast 2D Positional Audio");
                        if (iVar12 == 0) {
                            local_270[0x1c] = uVar14;
                        } else {
                            *local_288 = uVar14;
                            local_288 = local_288 + 1;
                            *reinterpret_cast<int16_t*>(hud_end()) = 0x20;
                            if (uVar14 < DAT_008cad88) {
                                pcVar18 = (&DAT_008ca800)[uVar14];
                            } else {
                                pcVar18 = nullptr;
                            }
                            pcVar19 = pcVar18 + 1;
                            do {
                                cVar4 = *pcVar18;
                                pcVar18 = pcVar18 + 1;
                            } while (cVar4 != '\0');
                            if (static_cast<uint32_t>(pcVar18 - pcVar19) < 0x2c) {
                                if (*reinterpret_cast<int*>(pcVar13 - 8) < 0) {
                                    iVar12 = *reinterpret_cast<int*>(pcVar13 - 4);
                                    if (iVar12 != 0) {
                                        *pcVar13 = '\0';
                                        pcVar13[-4] = '\0';
                                        pcVar13[-3] = '\0';
                                        pcVar13[-2] = '\0';
                                        pcVar13[-1] = '\0';
                                    }
                                    *reinterpret_cast<int*>(pcVar13 - 4) = iVar12;
                                }
                                hud_append(pcVar13);
                            } else {
                                if (uVar14 < DAT_008cad88) {
                                    pcVar13 = (&DAT_008ca800)[uVar14];
                                } else {
                                    pcVar13 = nullptr;
                                }
                                strncat(&DAT_00869b48, pcVar13, 0x28);
                                *reinterpret_cast<uint32_t*>(hud_end()) = 0x2e2e2e;
                            }
                            *reinterpret_cast<int16_t*>(hud_end()) = 10;
                        }
                    }
                }
            LAB_004b5403:
                uVar14 = uVar14 + 1;
            } while (uVar14 < DAT_008cad88);
        }
        puVar22 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
        if (puVar22 != nullptr) {
            puVar22[1] = puVar22[1] + 1;
        }
        *reinterpret_cast<uint8_t*>(puVar22 + 8) = *reinterpret_cast<uint8_t*>(puVar22 + 8) | 1;
        piVar1 = reinterpret_cast<int*>(puVar22 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            destroy_obj(puVar22);
        }
        DAT_0085a11c = 100;
        DAT_0086c330 = 0;
        iVar12 = FUN_00430190((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3U)) >> 2,
                              ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7U)) >> 3) + 1,
                              "pauseMenuBG.dds", 0, 0xffffffff, 0, 0, 0xffffffff, 0, 0);
        puVar22 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
        if (puVar22 != nullptr) {
            puVar22[1] = puVar22[1] + 1;
        }
        *reinterpret_cast<uint16_t*>(puVar22 + 8) =
            *reinterpret_cast<uint16_t*>(puVar22 + 8) & 0xfffe;
        piVar1 = reinterpret_cast<int*>(puVar22 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            destroy_obj(puVar22);
            puVar22 = extraout_ECX_00;
        }
        if (-1 < iVar12) {
            FUN_00412cb0(puVar22);
            FUN_004d4500();
            FUN_004f6090("You must restart the game for this\nsetting to take full effect.\n");
            FUN_004879f0(0x30, 0);
            puVar22 = *reinterpret_cast<uint32_t**>(
                *reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
            if (puVar22 != nullptr) {
                puVar22[1] = puVar22[1] + 1;
            }
            *reinterpret_cast<uint8_t*>(puVar22 + 8) =
                *reinterpret_cast<uint8_t*>(puVar22 + 8) | 1;
            piVar1 = reinterpret_cast<int*>(puVar22 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                destroy_obj(puVar22);
            }
            FUN_0042e730();
            FUN_00430190(((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3U)) >> 2) + 0x10,
                         ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2) + 1,
                         "pauseMenuBG.dds", 0, 0xffffffff, 0, 0, 0xffffffff, 0, 0);
            puVar22 = *reinterpret_cast<uint32_t**>(
                *reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
            if (puVar22 != nullptr) {
                puVar22[1] = puVar22[1] + 1;
            }
            *reinterpret_cast<uint16_t*>(puVar22 + 8) =
                *reinterpret_cast<uint16_t*>(puVar22 + 8) & 0xfffe;
            piVar1 = reinterpret_cast<int*>(puVar22 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                destroy_obj(puVar22);
            }
        }
        pcVar13 = local_298 + -8;
        if ((pcVar13 != nullptr) && (pcVar13 != reinterpret_cast<char*>(&DAT_008cacc8))) {
            operator_delete__(pcVar13);
        }
    } else {
        if (0x128 < static_cast<int>(reinterpret_cast<intptr_t>(pcVar19))) {
            switch (reinterpret_cast<intptr_t>(pcVar19)) {
            case 0x205:
                DAT_007263b9 = DAT_007263b9 == '\0';
                break;
            case 0x206:
                DAT_008cac34 = DAT_008cac34 == 0;
                FUN_004888e0(0x33, 0xffffffff, 0xffffffff, 0xbf800000);
                goto switchD_004b5126_default;
            case 0x207:
                DAT_007263ba = DAT_007263ba == '\0';
                break;
            case 0x208:
                FUN_0042e730();
                FUN_004f6090("You must restart the game for this\nsetting to take full effect.\n");
                FUN_004879f0(0x30, 0);
                puVar22 = *reinterpret_cast<uint32_t**>(
                    *reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
                if (puVar22 != nullptr) {
                    puVar22[1] = puVar22[1] + 1;
                }
                *reinterpret_cast<uint8_t*>(puVar22 + 8) =
                    *reinterpret_cast<uint8_t*>(puVar22 + 8) | 1;
                piVar1 = reinterpret_cast<int*>(puVar22 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    destroy_obj(puVar22);
                }
                DAT_0086c330 = 0;
                FUN_00430190(((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3U)) >> 2) + 0x10,
                             ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2) + 1,
                             "pauseMenuBG.dds", 0, 0xffffffff, 0, 0, 0xffffffff, 0, 0);
                DAT_008cac35 = DAT_008cac35 == 0;
                puVar22 = *reinterpret_cast<uint32_t**>(
                    *reinterpret_cast<int*>(DAT_008cabe8 + 0x10) + 4);
                if (puVar22 != nullptr) {
                    puVar22[1] = puVar22[1] + 1;
                }
                *reinterpret_cast<uint8_t*>(puVar22 + 8) =
                    *reinterpret_cast<uint8_t*>(puVar22 + 8) & 0xfe;
                piVar1 = reinterpret_cast<int*>(puVar22 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 != 0) goto switchD_004b55c1_caseD_216;
                destroy_obj(puVar22);
                goto switchD_004b5126_default;
            case 0x209:
                goto switchD_004b5126_caseD_209;
            default:
                goto switchD_004b5126_default;
            }
            FUN_004888e0(0x33, 0xffffffff, 0xffffffff, 0xbf800000);
            goto switchD_004b5126_default;
        }
        if (pcVar19 == reinterpret_cast<char*>(0x128)) {
        switchD_004b50ef_caseD_16:
            do {
                if (pcVar13 == reinterpret_cast<char*>(0xffffffff)) {
                    pcVar13 = pcVar16;
                } else {
                    pcVar13 = pcVar13 + 1;
                }
                if (static_cast<int>(reinterpret_cast<intptr_t>(pcVar18)) <
                    static_cast<int>(reinterpret_cast<intptr_t>(pcVar13))) {
                    pcVar13 = pcVar16;
                }
                FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                             0xffffffff);
                switch (reinterpret_cast<intptr_t>(pcVar13)) {
                case 0x13:
                case 0x14:
                    if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) == '\0') {
                        goto switchD_004b50ef_caseD_16;
                    }
                    break;
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1a:
                case 0x1b:
                    goto switchD_004b50ef_caseD_16;
                default:
                    break;
                }
                cVar4 = static_cast<char>(FUN_004b31e0());
            } while (cVar4 != '\0');
            local_294 = pcVar13;
            goto switchD_004b5126_default;
        }
        if (static_cast<int>(reinterpret_cast<intptr_t>(pcVar19)) < 0x126) {
            if (pcVar19 != reinterpret_cast<char*>(0x125)) goto LAB_004b4f19;
            if (pcVar13 != reinterpret_cast<char*>(0xffffffff)) {
                uVar14 = local_270[static_cast<int>(reinterpret_cast<intptr_t>(pcVar13))];
                if ((uVar14 != 0) && (*reinterpret_cast<char*>(uVar14 + 0xf3) == '\0')) {
                    cVar4 = FUN_004879c0(&DAT_008ea0b4, static_cast<int>(uVar14));
                    if (cVar4 != '\0') {
                        FUN_00449390(&DAT_008ea0b4,
                                     static_cast<int>(local_270[static_cast<int>(
                                         reinterpret_cast<intptr_t>(pcVar13))]));
                        FUN_0050c680();
                    }
                }
            }
            goto switchD_004b5126_default;
        }
        if (pcVar19 == reinterpret_cast<char*>(0x126)) {
        switchD_004b5089_caseD_16:
            do {
                if (pcVar13 == reinterpret_cast<char*>(0xffffffff)) {
                    pcVar13 = pcVar18;
                } else {
                    pcVar13 = pcVar13 + -1;
                }
                if (static_cast<int>(reinterpret_cast<intptr_t>(pcVar13)) <
                    static_cast<int>(reinterpret_cast<intptr_t>(pcVar16))) {
                    pcVar13 = pcVar18;
                }
                FUN_004a2380();
                switch (reinterpret_cast<intptr_t>(pcVar13)) {
                case 0x13:
                case 0x14:
                    if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) == '\0') {
                        goto switchD_004b5089_caseD_16;
                    }
                    break;
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1a:
                case 0x1b:
                    goto switchD_004b5089_caseD_16;
                default:
                    break;
                }
                cVar4 = static_cast<char>(FUN_004b31e0());
            } while (cVar4 != '\0');
            local_294 = pcVar13;
            goto switchD_004b5126_default;
        }
        if (pcVar19 == reinterpret_cast<char*>(0x127)) {
            if (pcVar13 != reinterpret_cast<char*>(0xffffffff)) {
                uVar14 = local_270[static_cast<int>(reinterpret_cast<intptr_t>(pcVar13))];
                if ((uVar14 != 0) && (*reinterpret_cast<char*>(uVar14 + 0xf3) == '\0')) {
                    cVar4 = FUN_004879c0(&DAT_008ea0b4, static_cast<int>(uVar14));
                    if (cVar4 != '\0') {
                        FUN_00449390(&DAT_008ea0b4,
                                     static_cast<int>(local_270[static_cast<int>(
                                         reinterpret_cast<intptr_t>(pcVar13))]));
                        FUN_0050c650();
                    }
                }
            }
            goto switchD_004b5126_default;
        }
    }
    goto switchD_004b55c1_caseD_216;
joined_r0x004b4ca1:
    if (puVar9 == nullptr) goto LAB_004b4cb5;
    if (puVar9 == reinterpret_cast<uint8_t*>(&DAT_008ea0b4)) {
        bVar2 = 1;
        goto LAB_004b4cb7;
    }
    puVar9 = *reinterpret_cast<uint8_t**>(puVar9 + 4);
    goto joined_r0x004b4ca1;
LAB_004b4cb5:
    bVar2 = 0;
LAB_004b4cb7:
    uVar14 = -(uint32_t)bVar2 & static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar1));
LAB_004b4cbf:
    if (*reinterpret_cast<char*>(uVar14 + 0xf2) != '\0') {
        local_278 = DAT_008dc30c;
        local_274 = DAT_008dc310;
        goto LAB_004b4d47;
    }
    uVar6 = FUN_005f0ddc();
    FUN_0050c550(uVar6);
LAB_004b4cf0:
    pcVar19 = pcVar19 + 1;
    if (static_cast<int>(reinterpret_cast<intptr_t>(pcVar18)) <
        static_cast<int>(reinterpret_cast<intptr_t>(pcVar19))) {
        goto LAB_004b4cf9;
    }
    goto LAB_004b4c60;
switchD_004b55c1_caseD_21a:
    FUN_004aea30();
    goto switchD_004b5126_default;
}

// ---------------------------------------------------------------------------
// 0x4b5d90 — observed shape
// Formats and loads one save-slot record; returns the caller's param_1.
// ---------------------------------------------------------------------------
int32_t FUN_004b5d90(int param_1, int param_2)
{
    uint8_t uVar1;
    int iVar2;
    char cVar3;
    char* pcVar4;
    uint32_t* puVar5;
    int local_2c;
    int local_28;
    uint8_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint8_t* local_18;
    uint8_t* local_14;
    uint8_t* local_10;
    uint8_t* local_c;
    uint8_t* local_8;

    local_18 = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    local_14 = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    local_10 = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    local_c = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    local_8 = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    FUN_004f6090("@SAVEGAME_SLOT", param_2);
    FUN_00412f10();
    cVar3 = FUN_004022e0(&DAT_00869b48, 1, 0, &local_1c);
    if (cVar3 == '\0') {
        FUN_004b6020();
        FUN_004b5f80();
        return param_1;
    }
    local_24 = 1;
    FUN_00412f10();
    iVar2 = DAT_008caccc;
    if ((DAT_008caccc - 1 < DAT_008caccc) && (-1 < DAT_008caccc - 1)) {
        uVar1 = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(&DAT_008cacd0) +
                                           DAT_008caccc - 1);
        *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(&DAT_008cacd0) + DAT_008caccc - 1) =
            0;
        pcVar4 = strrchr(&DAT_008cacd0, 0x7c);
        *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(&DAT_008cacd0) + iVar2 - 1) = uVar1;
        if ((pcVar4 != nullptr) &&
            (-1 < static_cast<int>(pcVar4 - &DAT_008cacd0))) {
            FUN_004f1840();
            FUN_00412ec0();
            puVar5 = reinterpret_cast<uint32_t*>(local_2c + -8);
            if ((puVar5 != nullptr) &&
                (puVar5 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                operator_delete__(puVar5);
            }
        }
    }
    local_2c = 0;
    FUN_004f18c0(&local_2c, 0x7c);
    FUN_00412ec0();
    puVar5 = reinterpret_cast<uint32_t*>(local_28 + -8);
    if ((puVar5 != nullptr) && (puVar5 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar5);
    }
    FUN_004f18c0(&local_2c, 0x7c);
    FUN_00412ec0();
    puVar5 = reinterpret_cast<uint32_t*>(local_28 + -8);
    if ((puVar5 != nullptr) && (puVar5 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar5);
    }
    FUN_004f18c0(&local_2c, 0x7c);
    FUN_00412ec0();
    puVar5 = reinterpret_cast<uint32_t*>(local_28 + -8);
    if ((puVar5 != nullptr) && (puVar5 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar5);
    }
    FUN_004b6020();
    FUN_004b5f80();
    return param_1;
}

// ---------------------------------------------------------------------------
// 0x4b5f80 — observed shape
// Releases the five slot strings held by the structure in ECX and resets each
// to the empty static string.
// ---------------------------------------------------------------------------
void FUN_004b5f80(void* self_raw)
{
    intptr_t self = reinterpret_cast<intptr_t>(self_raw);
    uint32_t* puVar1;

    puVar1 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(self + 0x1c) - 8);
    if ((puVar1 != nullptr) &&
        (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    *reinterpret_cast<uint8_t**>(self + 0x1c) =
        reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    puVar1 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(self + 0x18) - 8);
    if ((puVar1 != nullptr) &&
        (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    *reinterpret_cast<uint8_t**>(self + 0x18) =
        reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    puVar1 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(self + 0x14) - 8);
    if ((puVar1 != nullptr) &&
        (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    *reinterpret_cast<uint8_t**>(self + 0x14) =
        reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    puVar1 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(self + 0x10) - 8);
    if ((puVar1 != nullptr) &&
        (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    *reinterpret_cast<uint8_t**>(self + 0x10) =
        reinterpret_cast<uint8_t*>(&DAT_008cacd0);
    puVar1 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(self + 0xc) - 8);
    if ((puVar1 != nullptr) &&
        (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    *reinterpret_cast<uint8_t**>(self + 0xc) = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
}

// ---------------------------------------------------------------------------
// 0x4b6020 — observed shape
// Copies the three leading dwords of one slot record and resets five strings
// (ESI destination, EDI source in the listing).
// ---------------------------------------------------------------------------
void FUN_004b6020(void* dst_raw, const void* src_raw)
{
    uint8_t* dst = static_cast<uint8_t*>(dst_raw);
    const uint8_t* src = static_cast<const uint8_t*>(src_raw);

    dst[0] = src[0];
    *reinterpret_cast<uint32_t*>(dst + 4) = *reinterpret_cast<const uint32_t*>(src + 4);
    *reinterpret_cast<uint32_t*>(dst + 8) = *reinterpret_cast<const uint32_t*>(src + 8);
    FUN_00412df0();
    FUN_00412df0();
    FUN_00412df0();
    FUN_00412df0();
    FUN_00412df0();
}

// ---------------------------------------------------------------------------
// 0x4b6de0 — observed shape
// Copies one slot record: three dwords plus the five reference-counted strings
// at +0xc..+0x1c (EBX destination in the listing).
// ---------------------------------------------------------------------------
static void copy_slot_string(void* dst_holder, const void* src_ptr)
{
    const void* pvVar2 = src_ptr;
    size_t sVar3 = *reinterpret_cast<const size_t*>(
        static_cast<const uint8_t*>(pvVar2) - 4);
    uint32_t* dst = reinterpret_cast<uint32_t*>(dst_holder);
    if ((-1 < static_cast<int>(sVar3)) && (pvVar2 != nullptr) &&
        (pvVar2 != reinterpret_cast<const void*>(*dst))) {
        if (sVar3 == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(reinterpret_cast<void*>(*dst), pvVar2, sVar3);
            *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(reinterpret_cast<void*>(*dst)) +
                                        *reinterpret_cast<int*>(static_cast<uint8_t*>(
                                            reinterpret_cast<void*>(*dst)) - 4)) = 0;
        }
    }
}

void FUN_004b6de0(void* dst_raw, const void* src_raw)
{
    uint8_t* dst = static_cast<uint8_t*>(dst_raw);
    const uint8_t* src = static_cast<const uint8_t*>(src_raw);

    dst[0] = src[0];
    *reinterpret_cast<uint32_t*>(dst + 4) = *reinterpret_cast<const uint32_t*>(src + 4);
    *reinterpret_cast<uint32_t*>(dst + 8) = *reinterpret_cast<const uint32_t*>(src + 8);
    copy_slot_string(dst + 0xc, *reinterpret_cast<const void* const*>(src + 0xc));
    copy_slot_string(dst + 0x10, *reinterpret_cast<const void* const*>(src + 0x10));
    copy_slot_string(dst + 0x14, *reinterpret_cast<const void* const*>(src + 0x14));
    copy_slot_string(dst + 0x18, *reinterpret_cast<const void* const*>(src + 0x18));
    copy_slot_string(dst + 0x1c, *reinterpret_cast<const void* const*>(src + 0x1c));
}

// ---------------------------------------------------------------------------
// 0x4b6070 — observed shape
// Save dialog: shows 19 save slots, handles selection and commits the chosen
// slot (or cancels back to the options pane).
// ---------------------------------------------------------------------------
extern char FUN_004b6070(char param_1)
{
    int16_t sVar1;
    int* piVar2;
    char cVar3;
    uint32_t* puVar4;
    uint32_t uVar5;
    char* pcVar6;
    int iVar7;
    uint32_t uVar8;
    int iVar9;
    uint32_t uVar10;
    int16_t sVar11;
    char* pcVar12;
    int iVar13;
    int iVar14;
    char* pcVar15;
    int* piVar16;
    char* pcVar17;
    int iVar18;
    bool bVar19;
    uint64_t uVar20;
    uint32_t uVar21;
    uint32_t uVar22;
    uint8_t local_3a5;
    int local_3a4;
    uint32_t* local_3a0;
    int local_39c;
    int local_398;
    int local_394;
    uint32_t* local_390;
    uint32_t* local_38c;
    int local_388;
    int local_384;
    uint8_t local_380[32];
    uint32_t rec[0x13 * 8 + 2];
    uint32_t* local_35c = rec + 1;
    char* local_360 = reinterpret_cast<char*>(rec);
    char local_100[256];

    puVar4 = local_35c + 3;
    iVar14 = 0x13;
    do {
        puVar4[-1] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        *puVar4 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        puVar4[1] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        puVar4[2] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        puVar4[3] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        *reinterpret_cast<uint8_t*>(puVar4 - 4) = 0;
        puVar4[-3] = 0;
        puVar4[-2] = 0;
        puVar4 = puVar4 + 8;
        iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    iVar14 = 0;
    local_3a4 = -1;
    local_388 = -1;
    local_384 = -1;
    local_394 = 1;
    local_3a5 = 0;
    if (param_1 != '\0') {
        do {
            FUN_004b20f0();
            iVar14 = iVar14 + 1;
        } while (iVar14 < 3);
    }
    iVar14 = 0;
    do {
        uVar5 = FUN_004b5d90(reinterpret_cast<int>(reinterpret_cast<intptr_t>(local_380)), iVar14);
        FUN_004b6de0(reinterpret_cast<void*>(uVar5));
        FUN_004b5f80();
        iVar14 = iVar14 + 1;
    } while (iVar14 < 0x13);
    local_390 = reinterpret_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar5 = static_cast<uint32_t>(DAT_008ea008);
    if (local_390 == nullptr) {
        local_390 = nullptr;
    } else {
        local_390[1] = 0;
        *local_390 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006fd14c));
        local_390[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        local_390[0x19] = 0;
        local_390[0x2f] = 0;
        FUN_004bdca0(static_cast<int>(uVar5), 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_390 != nullptr) {
        local_390[1] = local_390[1] + 1;
    }
    local_38c = reinterpret_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar5 = static_cast<uint32_t>(DAT_008ea008);
    if (local_38c == nullptr) {
        local_38c = nullptr;
    } else {
        local_38c[1] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        *local_38c = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006fd14c));
        local_38c[7] = 0;
        local_38c[0x19] = 0;
        local_38c[0x2f] = 0;
        FUN_004bdca0(static_cast<int>(uVar5), 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_38c != nullptr) {
        local_38c[1] = local_38c[1] + 1;
    }
LAB_004b61d0:
    for (;;) {
        iVar7 = DAT_0085a26c;
        iVar14 = DAT_0085a268;
        if (DAT_008cac27 != '\0') {
        LAB_004b6d75:
            if (param_1 != '\0') {
                FUN_004b2170();
            }
            goto LAB_004b6d85;
        }
        DAT_0086c330 = 0;
        if (param_1 == '\0') {
            FUN_004b24a0(reinterpret_cast<int*>(DAT_008cabe8), 1);
        } else {
            local_39c = 0x300;
            local_3a0 = reinterpret_cast<uint32_t*>(0x400);
            uVar5 = FUN_004cddf0("pauseMenuBG.dds", 0, 0, &local_3a0, &local_39c);
            FUN_004af080(uVar5, 0, 0, static_cast<int>(reinterpret_cast<intptr_t>(local_3a0)),
                         local_39c, 0, 0, iVar7, iVar14, 0xffffffff, 0);
        }
        FUN_004f6090(DAT_0070c700);
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2, 0xc, 100, 0xffffffff, 4, 0xffffffff, 0);
        if (local_3a4 != -1) {
            pcVar12 = local_360 + local_3a4 * 0x20;
            for (; -1 < local_3a4; local_3a4 = local_3a4 + local_394) {
                if ((0x13 < local_3a4) || (*pcVar12 != '\0')) {
                    if ((-1 < local_3a4) && (local_3a4 < 0x14)) goto LAB_004b62fa;
                    break;
                }
                pcVar12 = pcVar12 + local_394 * 0x20;
            }
            local_3a4 = 0x13;
        LAB_004b62fa:
            if (local_3a4 < 0x14) {
                iVar14 = local_3a4;
                if (local_3a4 == 0x13) {
                    iVar14 = 0x14;
                }
                FUN_004af080(0, 0, 0, 0, 0, DAT_0085a26c / 9 + -0x20,
                             (DAT_0085a268 / 0x1e) * iVar14 + -0x30 +
                                 ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2),
                             (DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3U)) >> 2,
                             (DAT_0085a268 / 0x1e) / 2 + 8, 0xff1d5d90, 0xa0);
                if (((-1 < iVar14) && (iVar14 < 0x13)) && (local_360[iVar14 * 0x20] != '\0')) {
                    FUN_004f6090("Name: ");
                    hud_append(reinterpret_cast<char*>(local_35c[iVar14 * 8 + 3]));
                    FUN_00487fd0(DAT_0085a26c / 2, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x10, 100, 0xffffffff, 1, 0xffffffff,
                                 0);
                    FUN_004f6090("Date: ");
                    hud_append(reinterpret_cast<char*>(local_35c[iVar14 * 8 + 4]));
                    FUN_00487fd0(DAT_0085a26c / 2, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x26, 0x44, 0xffffffff, 1, 0xffffffff,
                                 0);
                    FUN_004f6090("Difficulty: ");
                    hud_append(reinterpret_cast<char*>(local_35c[iVar14 * 8 + 5]));
                    FUN_00487fd0(DAT_0085a26c / 2, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x32, 0x44, 0xffffffff, 1, 0xffffffff,
                                 0);
                    FUN_004f6090("Location: ");
                    hud_append(reinterpret_cast<char*>(local_35c[iVar14 * 8 + 6]));
                    FUN_00487fd0(DAT_0085a26c / 2, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x3e, 0x44, 0xffffffff, 1, 0xffffffff,
                                 0);
                    iVar14 = FUN_0044a670(0x1ce, 0x10e, 0x104);
                    iVar7 = FUN_0044a670(0x125, 0xd7, 0x54);
                    DAT_008cac00 = DAT_008cac00 + 100;
                    FUN_004f6090("You are here.");
                    FUN_004b06c0(&DAT_00869b48, iVar14, iVar7 + -0x14, 0x33, 0xffc00000, 4,
                                 0xffffffff, 0);
                    FUN_004bba60(local_38c, iVar14 + 4, iVar7 + 4, 0x42480000, 0);
                    DAT_008cac00 = DAT_008cac00 + -100;
                }
            }
        }
        local_3a0 = local_35c + 2;
        iVar14 = DAT_0085a268;
        iVar7 = 0;
        do {
            iVar18 = iVar7;
            puVar4 = local_3a0;
            local_39c = (iVar14 / 0x1e) * iVar18 + -0x28 +
                        ((iVar14 + (iVar14 >> 0x1f & 3U)) >> 2);
            uVar22 = 0;
            uVar21 = 0x41400000;
            uVar5 = FUN_005f0ddc(0x41400000, 0);
            local_39c = DAT_0085a26c / 9 + -0xc;
            uVar8 = FUN_005f0ddc(uVar5);
            FUN_004bba60(&DAT_008d1358, uVar8, uVar5, uVar21, uVar22);
            if (*reinterpret_cast<char*>(puVar4 - 3) == '\0') {
                FUN_004b06c0(reinterpret_cast<char*>(*puVar4), DAT_0085a26c / 9,
                             (DAT_0085a268 / 0x1e) * iVar18 + -0x32 +
                                 ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2),
                             0x55, 0x80ffffff, 1, 0xffffffff, 0);
                iVar14 = DAT_0085a268;
            } else {
                uVar5 = 0xffffffff;
                if (local_3a4 == iVar18) {
                    uVar5 = 0xffffcc00;
                }
                FUN_004b06c0(reinterpret_cast<char*>(*puVar4), DAT_0085a26c / 9,
                             (DAT_0085a268 / 0x1e) * iVar18 + -0x32 +
                                 ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2),
                             0x55, uVar5, 1, 0xffffffff, 0);
                iVar14 = DAT_0085a268;
                iVar7 = DAT_0085a268 / 0x1e;
                local_398 = iVar7 * iVar18 + -0x32 +
                            ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2);
                iVar13 = DAT_0085a26c / 2;
                local_39c = iVar13 / 2;
                sVar11 = static_cast<int16_t>(DAT_0085a26c / 9) -
                         static_cast<int16_t>(local_39c);
                iVar9 = DAT_0086c330;
                (&DAT_0086c010)[iVar9] = sVar11;
                (&DAT_0086be80)[iVar9] = static_cast<int16_t>(local_398);
                (&DAT_0086c1a0)[iVar9] = static_cast<int16_t>(iVar18);
                (&DAT_0086bcf0)[iVar9] = sVar11 + static_cast<int16_t>(iVar13);
                (&DAT_0086bb60)[iVar9] =
                    static_cast<int16_t>(local_398) + static_cast<int16_t>(iVar7);
                DAT_0086c330 = DAT_0086c330 + 1;
                puVar4 = local_3a0;
            }
            local_3a0 = puVar4 + 8;
            iVar7 = iVar18 + 1;
        } while (iVar18 + 1 < 0x13);
        uVar5 = 0xffffffff;
        if (local_3a4 == 0x13) {
            uVar5 = 0xffffcc00;
        }
        FUN_004f6090("Cancel");
        iVar18 = iVar18 + 2;
        FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 9,
                     (DAT_0085a268 / 0x1e) * iVar18 + -0x32 +
                         ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2),
                     0x55, uVar5, 1, 0xffffffff, 0);
        puVar4 = local_390;
        if (local_390 != nullptr) {
            local_398 = (DAT_0085a268 / 0x1e) * iVar18 + -0x30 +
                        ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2);
            uVar22 = 0;
            uVar21 = 0x42480000;
            uVar5 = FUN_005f0ddc(0x42480000, 0);
            local_398 = DAT_0085a26c / 9 + -0x15;
            uVar8 = FUN_005f0ddc(uVar5);
            FUN_004bba60(puVar4, uVar8, uVar5, uVar21, uVar22);
        }
        iVar7 = DAT_0085a26c;
        iVar14 = DAT_0085a268;
        local_398 = (DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2;
        iVar9 = DAT_0086c330;
        sVar1 = static_cast<int16_t>(DAT_0085a268 / 0x1e);
        local_3a0 = reinterpret_cast<uint32_t*>(
            static_cast<int16_t>(sVar1 * static_cast<int16_t>(iVar18) + -0x32 +
                                 static_cast<int16_t>(local_398)));
        sVar11 = static_cast<int16_t>(DAT_0085a26c / 9);
        (&DAT_0086be80)[iVar9] = static_cast<int16_t>(reinterpret_cast<intptr_t>(local_3a0));
        (&DAT_0086bb60)[iVar9] = static_cast<int16_t>(
            reinterpret_cast<intptr_t>(local_3a0) + static_cast<intptr_t>(sVar1));
        (&DAT_0086c010)[iVar9] = sVar11;
        iVar7 = iVar7 / 2;
        DAT_0086c330 = DAT_0086c330 + 1;
        (&DAT_0086bcf0)[iVar9] = sVar11 + static_cast<int16_t>(iVar7);
        (&DAT_0086c1a0)[iVar9] = 0x13;
        iVar18 = local_398 + -0x32;
        local_3a0 = reinterpret_cast<uint32_t*>(0x1fe);
        local_39c = 0x200;
        uVar5 = FUN_004cddf0("LoadSaveMap.dds", 0, 0, &local_39c, &local_3a0);
        FUN_004af080(uVar5, 0, 0, local_39c,
                     static_cast<int>(reinterpret_cast<intptr_t>(local_3a0)), iVar7 + -0x50,
                     iVar18, iVar7 + 0x28, (iVar14 * 2) / 3 + 0x28, 0xffffffff, 0);
        iVar14 = DAT_008dc30c;
        uVar20 = static_cast<uint64_t>(FUN_0042c6f0());
        iVar18 = static_cast<int>(uVar20 >> 0x20);
        iVar7 = static_cast<int>(uVar20);
        if ((local_388 != iVar14) || (local_384 != iVar18)) {
            local_388 = iVar14;
            local_384 = iVar18;
            if ((iVar7 != -1) && (iVar7 != local_3a4)) {
                FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                             0xffffffff);
            }
            local_3a4 = iVar7;
        }
        if (param_1 == '\0') {
            iVar14 = FUN_004b2760(0);
        } else {
            FUN_004d0cd0(0, 0);
            iVar14 = FUN_0042e1d0(&DAT_006f588c);
            if (DAT_0086bb5c != nullptr) {
                sprintf(local_100, "%s_%03X", &DAT_006f588c, iVar14);
                piVar2 = DAT_0086bb5c;
                iVar7 = vtbl_slot<int (*)(int*, const char*)>(piVar2, 4)(piVar2, local_100);
                piVar16 = *reinterpret_cast<int**>(piVar2[2] + iVar7 * 4);
                if (piVar16 != nullptr) {
                    do {
                        cVar3 = static_cast<char>(
                            vtbl_slot<char (*)(int*, const char*, int)>(piVar2, 8)(
                                piVar2, local_100, piVar16[1]));
                        if (cVar3 != '\0') {
                            iVar14 = piVar16[2];
                            break;
                        }
                        piVar16 = reinterpret_cast<int*>(*piVar16);
                    } while (piVar16 != nullptr);
                }
            }
        }
        if (iVar14 == 0xd) {
            if (local_3a4 != -1) {
                iVar14 = local_3a4 + 0x200;
                goto LAB_004b6be3;
            }
        LAB_004b6bec:
            if (iVar14 != 1) {
                bVar19 = iVar14 == 0x1b;
                goto LAB_004b6c46;
            }
        LAB_004b6d6b:
            FUN_0042e730();
            goto LAB_004b6d75;
        }
    LAB_004b6be3:
        if (0x126 < iVar14) break;
        if (iVar14 != 0x126) goto LAB_004b6bec;
        FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                     0xffffffff);
        local_3a4 = local_3a4 + -1;
        local_394 = -1;
        if (local_3a4 < 0) {
            local_3a4 = 0x13;
        }
    }
    if (iVar14 == 0x128) {
        FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                     0xffffffff);
        local_3a4 = local_3a4 + 1;
        local_394 = 1;
        if (0x13 < local_3a4) {
            local_3a4 = 0;
        }
    } else {
        bVar19 = iVar14 == 0x213;
    LAB_004b6c46:
        if (bVar19) goto LAB_004b6d6b;
        iVar14 = iVar14 + -0x200;
        if ((-1 < iVar14) && (iVar14 < 0x13)) {
            FUN_004a2380();
            if (param_1 != '\0') {
                FUN_00412ec0();
                local_3a5 = 1;
                goto LAB_004b6d75;
            }
            FUN_004f6090(
                "You will lose all unsaved progress in the current game. Are you sure?\n Yes \n No\n");
            FUN_004879f0(0x30, 0);
            DAT_0086c330 = 0;
            iVar7 = FUN_00430190(
                (DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3U)) >> 2,
                (DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2 | 1, "pauseMenuBG.dds", 0,
                0xffffffff, 0, 0, 0xffffffff, 0, 0);
            uVar5 = DAT_0085a164;
            if (iVar7 == 0) {
                FUN_004022e0(reinterpret_cast<void*>(local_35c[iVar14 * 8 + 2]), 0, 1, 0);
                FUN_00471b40(uVar5, 1);
                local_3a5 = 1;
            LAB_004b6d85:
                DAT_0086c330 = 0;
                if (local_38c != nullptr) {
                    release_obj(local_38c);
                }
                if (local_390 != nullptr) {
                    release_obj(local_390);
                }
                iVar14 = 0x13;
                do {
                    FUN_004b5f80();
                    iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
                return static_cast<char>(local_3a5);
            }
        }
    }
    goto LAB_004b61d0;
}

// ---------------------------------------------------------------------------
// 0x4b6f60 — observed shape
// Load dialog: shows 16 save slots, handles selection and loads the chosen
// slot (or cancels back to the options pane).
// ---------------------------------------------------------------------------
char FUN_004b6f60(char param_1)
{
    char* pcVar1;
    int16_t sVar2;
    int* piVar3;
    char cVar4;
    uint32_t* puVar5;
    uint32_t uVar6;
    char* pcVar7;
    int iVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int iVar11;
    uint32_t uVar12;
    int16_t sVar13;
    int iVar14;
    int iVar15;
    char* pcVar16;
    int* piVar17;
    char* pcVar18;
    int iVar19;
    bool bVar20;
    uint64_t uVar21;
    uint8_t* puVar22;
    uint32_t uVar23;
    uint32_t uVar24;
    uint8_t local_341;
    uint32_t* local_340;
    int local_33c;
    int local_338;
    int local_334;
    uint32_t* local_330;
    uint32_t* local_32c;
    int local_328;
    int local_324;
    uint8_t local_320[32];
    uint32_t rec[0x10 * 8 + 2];
    uint32_t* local_2fc = rec + 1;
    char* local_300 = reinterpret_cast<char*>(rec);
    char local_100[256];

    puVar5 = local_2fc + 3;
    iVar15 = 0x10;
    do {
        puVar5[-1] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        *puVar5 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        puVar5[1] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        puVar5[2] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        puVar5[3] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
        *reinterpret_cast<uint8_t*>(puVar5 - 4) = 0;
        puVar5[-3] = 0;
        puVar5[-2] = 0;
        puVar5 = puVar5 + 8;
        iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    iVar15 = 0;
    local_338 = -1;
    local_328 = -1;
    local_324 = -1;
    local_341 = 0;
    if (param_1 != '\0') {
        do {
            FUN_004b20f0();
            iVar15 = iVar15 + 1;
        } while (iVar15 < 3);
    }
    iVar15 = 0;
    do {
        uVar6 = FUN_004b5d90(reinterpret_cast<int>(reinterpret_cast<intptr_t>(local_320)), iVar15);
        FUN_004b6de0(reinterpret_cast<void*>(uVar6));
        FUN_004b5f80();
        iVar15 = iVar15 + 1;
    } while (iVar15 < 0x10);
    local_32c = reinterpret_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar6 = static_cast<uint32_t>(DAT_008ea008);
    if (local_32c == nullptr) {
        local_32c = nullptr;
    } else {
        local_32c[1] = 0;
        *local_32c = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006fd14c));
        local_32c[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        local_32c[0x19] = 0;
        local_32c[0x2f] = 0;
        FUN_004bdca0(static_cast<int>(uVar6), 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_32c != nullptr) {
        local_32c[1] = local_32c[1] + 1;
    }
    local_330 = reinterpret_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar6 = static_cast<uint32_t>(DAT_008ea008);
    if (local_330 == nullptr) {
        local_330 = nullptr;
    } else {
        local_330[1] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        *local_330 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006fd14c));
        local_330[7] = 0;
        local_330[0x19] = 0;
        local_330[0x2f] = 0;
        FUN_004bdca0(static_cast<int>(uVar6), 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_330 != nullptr) {
        local_330[1] = local_330[1] + 1;
    }
LAB_004b70c0:
    for (;;) {
        iVar8 = DAT_0085a26c;
        iVar15 = DAT_0085a268;
        DAT_0086c330 = 0;
        if (DAT_008cac27 != '\0') {
        LAB_004b7c06:
            if (param_1 != '\0') {
                FUN_004b2170();
            }
            goto LAB_004b7c16;
        }
        if (param_1 == '\0') {
            FUN_004b24a0(reinterpret_cast<int*>(DAT_008cabe8), 1);
        } else {
            local_33c = 0x300;
            local_340 = reinterpret_cast<uint32_t*>(0x400);
            uVar6 = FUN_004cddf0("pauseMenuBG.dds", 0, 0, &local_340, &local_33c);
            FUN_004af080(uVar6, 0, 0, static_cast<int>(reinterpret_cast<intptr_t>(local_340)),
                         local_33c, 0, 0, iVar8, iVar15, 0xffffffff, 0);
        }
        FUN_004f6090(DAT_0070c664);
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2, 0xc, 100, 0xffffffff, 4, 0xffffffff, 0);
        if (((local_338 != -1) && (-1 < local_338)) && (local_338 < 0x11)) {
            iVar15 = local_338;
            if (local_338 == 0x10) {
                iVar15 = 0x11;
            }
            FUN_004af080(0, 0, 0, 0, 0, DAT_0085a26c / 9 + -0x20,
                         (DAT_0085a268 / 0x1e) * iVar15 + -0x30 +
                             ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2),
                         (DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3U)) >> 2,
                         (DAT_0085a268 / 0x1e) / 2 + 8, 0xff1d5d90, 0xa0);
            if ((-1 < iVar15) && (iVar15 < 0x10)) {
                if (local_300[iVar15 * 0x20] == '\0') {
                    FUN_004f6090("Empty Slot");
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x10, 100, 0xffffffff, 1, 0xffffffff,
                                 0);
                } else {
                    FUN_004f6090("Name: ");
                    hud_append(reinterpret_cast<char*>(local_2fc[iVar15 * 8 + 3]));
                    FUN_00487fd0(DAT_0085a26c / 2, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x10, 100, 0xffffffff, 1, 0xffffffff,
                                 0);
                    FUN_004f6090("Date: ");
                    hud_append(reinterpret_cast<char*>(local_2fc[iVar15 * 8 + 4]));
                    FUN_00487fd0(DAT_0085a26c / 2, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x26, 0x44, 0xffffffff, 1, 0xffffffff,
                                 0);
                    FUN_004f6090("Difficulty: ");
                    hud_append(reinterpret_cast<char*>(local_2fc[iVar15 * 8 + 5]));
                    FUN_00487fd0(DAT_0085a26c / 2, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x32, 0x44, 0xffffffff, 1, 0xffffffff,
                                 0);
                    FUN_004f6090("Location: ");
                    hud_append(reinterpret_cast<char*>(local_2fc[iVar15 * 8 + 6]));
                    FUN_00487fd0(DAT_0085a26c / 2, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2 + -0x20,
                                 (DAT_0085a268 * 2) / 3 + 0x3e, 0x44, 0xffffffff, 1, 0xffffffff,
                                 0);
                    iVar15 = FUN_0044a670(0x1ce, 0x10e, 0x104);
                    iVar8 = FUN_0044a670(0x125, 0xd7, 0x54);
                    DAT_008cac00 = DAT_008cac00 + 100;
                    FUN_004f6090("You are here.");
                    FUN_004b06c0(&DAT_00869b48, iVar15, iVar8 + -0x14, 0x33, 0xffc00000, 4,
                                 0xffffffff, 0);
                    FUN_004bba60(local_330, iVar15 + 4, iVar8 + 4, 0x42480000, 0);
                    DAT_008cac00 = DAT_008cac00 + -100;
                }
            }
        }
        local_340 = local_2fc + 2;
        iVar15 = DAT_0085a268;
        iVar8 = 0;
        do {
            iVar19 = iVar8;
            puVar5 = local_340;
            uVar6 = 0xffffffff;
            if (local_338 == iVar19) {
                uVar6 = 0xffffcc00;
            }
            local_33c = (iVar15 / 0x1e) * iVar19 + -0x28 +
                        ((iVar15 + (iVar15 >> 0x1f & 3U)) >> 2);
            uVar24 = 0;
            uVar23 = 0x41400000;
            uVar9 = FUN_005f0ddc(0x41400000, 0);
            local_33c = DAT_0085a26c / 9 + -0xc;
            uVar10 = FUN_005f0ddc(uVar9);
            FUN_004bba60(&DAT_008d1358, uVar10, uVar9, uVar23, uVar24);
            if ((*reinterpret_cast<char*>(puVar5 - 3) == '\0') && (iVar19 != 0xf)) {
                FUN_004f6090("Empty Slot");
                iVar15 = (DAT_0085a268 / 0x1e) * iVar19 + -0x32 +
                         ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2);
                puVar22 = reinterpret_cast<uint8_t*>(&DAT_00869b48);
            } else {
                iVar15 = (DAT_0085a268 / 0x1e) * iVar19 + -0x32 +
                         ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2);
                puVar22 = reinterpret_cast<uint8_t*>(*puVar5);
            }
            FUN_004b06c0(reinterpret_cast<char*>(puVar22), DAT_0085a26c / 9, iVar15, 0x55, uVar6,
                         1, 0xffffffff, 0);
            iVar15 = DAT_0085a268;
            iVar8 = DAT_0085a268 / 0x1e;
            local_334 = iVar8 * iVar19 + -0x32 +
                        ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2);
            iVar14 = DAT_0085a26c / 2;
            local_33c = iVar14 / 2;
            sVar13 = static_cast<int16_t>(DAT_0085a26c / 9) -
                     static_cast<int16_t>(local_33c);
            iVar11 = DAT_0086c330;
            (&DAT_0086c010)[iVar11] = sVar13;
            (&DAT_0086be80)[iVar11] = static_cast<int16_t>(local_334);
            DAT_0086c330 = DAT_0086c330 + 1;
            (&DAT_0086c1a0)[iVar11] = static_cast<int16_t>(iVar19);
            local_340 = local_340 + 8;
            (&DAT_0086bcf0)[iVar11] = sVar13 + static_cast<int16_t>(iVar14);
            (&DAT_0086bb60)[iVar11] =
                static_cast<int16_t>(local_334) + static_cast<int16_t>(iVar8);
            iVar8 = iVar19 + 1;
        } while (iVar19 + 1 < 0x10);
        uVar6 = 0xffffffff;
        if (local_338 == 0x10) {
            uVar6 = 0xffffcc00;
        }
        FUN_004f6090("Cancel");
        iVar19 = iVar19 + 2;
        FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 9,
                     (DAT_0085a268 / 0x1e) * iVar19 + -0x32 +
                         ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2),
                     0x55, uVar6, 1, 0xffffffff, 0);
        puVar5 = local_32c;
        if (local_32c != nullptr) {
            local_334 = (DAT_0085a268 / 0x1e) * iVar19 + -0x30 +
                        ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2);
            uVar23 = 0;
            uVar10 = 0x42480000;
            uVar6 = FUN_005f0ddc(0x42480000, 0);
            local_334 = DAT_0085a26c / 9 + -0x15;
            uVar9 = FUN_005f0ddc(uVar6);
            FUN_004bba60(puVar5, uVar9, uVar6, uVar10, uVar23);
        }
        iVar8 = DAT_0085a26c;
        iVar15 = DAT_0085a268;
        local_334 = (DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2;
        iVar11 = DAT_0086c330;
        sVar2 = static_cast<int16_t>(DAT_0085a268 / 0x1e);
        local_340 = reinterpret_cast<uint32_t*>(
            static_cast<int16_t>(sVar2 * static_cast<int16_t>(iVar19) + -0x32 +
                                 static_cast<int16_t>(local_334)));
        sVar13 = static_cast<int16_t>(DAT_0085a26c / 9);
        (&DAT_0086be80)[iVar11] = static_cast<int16_t>(reinterpret_cast<intptr_t>(local_340));
        (&DAT_0086bb60)[iVar11] = static_cast<int16_t>(
            reinterpret_cast<intptr_t>(local_340) + static_cast<intptr_t>(sVar2));
        (&DAT_0086c010)[iVar11] = sVar13;
        iVar8 = iVar8 / 2;
        DAT_0086c330 = DAT_0086c330 + 1;
        (&DAT_0086bcf0)[iVar11] = sVar13 + static_cast<int16_t>(iVar8);
        (&DAT_0086c1a0)[iVar11] = 0x10;
        iVar19 = local_334 + -0x32;
        local_340 = reinterpret_cast<uint32_t*>(0x1fe);
        local_33c = 0x200;
        uVar6 = FUN_004cddf0("LoadSaveMap.dds", 0, 0, &local_33c, &local_340);
        FUN_004af080(uVar6, 0, 0, local_33c,
                     static_cast<int>(reinterpret_cast<intptr_t>(local_340)), iVar8 + -0x50,
                     iVar19, iVar8 + 0x28, (iVar15 * 2) / 3 + 0x28, 0xffffffff, 0);
        iVar15 = DAT_008dc30c;
        uVar21 = static_cast<uint64_t>(FUN_0042c6f0());
        iVar19 = static_cast<int>(uVar21 >> 0x20);
        iVar8 = static_cast<int>(uVar21);
        if ((local_328 != iVar15) || (local_324 != iVar19)) {
            local_328 = iVar15;
            local_324 = iVar19;
            if ((iVar8 != -1) && (iVar8 != local_338)) {
                FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                             0xffffffff);
            }
            local_338 = iVar8;
        }
        iVar15 = local_338;
        if (param_1 == '\0') {
            iVar8 = FUN_004b2760(0);
        } else {
            FUN_004d0cd0(0, 0);
            iVar8 = FUN_0042e1d0(&DAT_006f588c);
            if (DAT_0086bb5c != nullptr) {
                sprintf(local_100, "%s_%03X", &DAT_006f588c, iVar8);
                piVar3 = DAT_0086bb5c;
                iVar19 = vtbl_slot<int (*)(int*, const char*)>(piVar3, 4)(piVar3, local_100);
                piVar17 = *reinterpret_cast<int**>(piVar3[2] + iVar19 * 4);
                if (piVar17 != nullptr) {
                    do {
                        cVar4 = static_cast<char>(
                            vtbl_slot<char (*)(int*, const char*, int)>(piVar3, 8)(
                                piVar3, local_100, piVar17[1]));
                        if (cVar4 != '\0') {
                            iVar8 = piVar17[2];
                            break;
                        }
                        piVar17 = reinterpret_cast<int*>(*piVar17);
                    } while (piVar17 != nullptr);
                }
            }
        }
        if (iVar8 == 0xd) {
            if (iVar15 != -1) {
                iVar8 = iVar15 + 0x200;
                goto LAB_004b7ae3;
            }
        LAB_004b7aec:
            if (iVar8 != 1) {
                bVar20 = iVar8 == 0x1b;
                goto LAB_004b7b3a;
            }
        LAB_004b7bfc:
            FUN_0042e730();
            goto LAB_004b7c06;
        }
    LAB_004b7ae3:
        if (0x126 < iVar8) break;
        if (iVar8 != 0x126) goto LAB_004b7aec;
        FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                     0xffffffff);
        local_338 = iVar15 + -1;
        if (local_338 < 0) {
            local_338 = 0x10;
        }
    }
    if (iVar8 == 0x128) {
        FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                     0xffffffff);
        local_338 = iVar15 + 1;
        if (0x10 < local_338) {
            local_338 = 0;
        }
    } else {
        bVar20 = iVar8 == 0x210;
    LAB_004b7b3a:
        if (bVar20) goto LAB_004b7bfc;
        iVar8 = iVar8 + -0x200;
        if ((-1 < iVar8) && (iVar8 < 0x10)) {
            FUN_004a2380();
            if (param_1 != '\0') {
                FUN_00412ec0();
                local_341 = 1;
                goto LAB_004b7c06;
            }
            puVar22 = reinterpret_cast<uint8_t*>(local_2fc[iVar8 * 8 + 2]);
            if (*reinterpret_cast<int*>(puVar22 - 8) < 0) {
                iVar15 = *reinterpret_cast<int*>(puVar22 - 4);
                if (iVar15 != 0) {
                    *puVar22 = 0;
                    *reinterpret_cast<uint32_t*>(puVar22 - 4) = 0;
                }
                *reinterpret_cast<int*>(puVar22 - 4) = iVar15;
            }
            cVar4 = FUN_00401ee0(puVar22, "pauseMenuBG.dds", 1);
            if (cVar4 != '\0') {
                local_341 = 1;
            LAB_004b7c16:
                DAT_0086c330 = 0;
                if (local_330 != nullptr) {
                    release_obj(local_330);
                }
                if (local_32c != nullptr) {
                    release_obj(local_32c);
                }
                iVar15 = 0x10;
                do {
                    FUN_004b5f80();
                    iVar15 = iVar15 + -1;
                } while (iVar15 != 0);
                return static_cast<char>(local_341);
            }
        }
    }
    goto LAB_004b70c0;
}

// ---------------------------------------------------------------------------
// helpers used by the sail/flag dialog below
// ---------------------------------------------------------------------------

// Raw byte-wise compare matching the unrolled inline comparison emitted by the
// decompiler for the slot-name lookups (standard strcmp ordering).
static int slot_name_cmp(const uint8_t* a, const uint8_t* b)
{
    for (;;) {
        uint8_t ca = *a;
        uint8_t cb = *b;
        if (ca != cb) return (ca < cb) ? -1 : 1;
        if (ca == 0) return 0;
        ++a;
        ++b;
    }
}

// Drains the texture-upload queue hung off a game object at the given dword
// offset. Shared by the sail/flag dialog body and the ship preview.
static void drain_texture_queue_at(uint32_t* obj, int offset)
{
    int iVar6 = static_cast<int>(obj[offset]);
    while (iVar6 != 0) {
        FUN_005516a0();
        if ((DAT_008ca4cc == 0) && (DAT_008ca4c8[3] != 0)) {
            iVar6 = FUN_00551600(0);
            int* piVar16 = DAT_008ca4c8;
            if (iVar6 == 0) {
                int* piVar2 = reinterpret_cast<int*>(DAT_008ca4c8[1]);
                iVar6 = *piVar2;
                DAT_008ca4c8[1] = iVar6;
                if (iVar6 == 0) {
                    piVar16[2] = 0;
                } else {
                    *reinterpret_cast<uint32_t*>(iVar6 + 4) = 0;
                }
                iVar6 = piVar2[2];
                vtbl_slot<void (*)(int*)>(piVar16, 8)(piVar2);
                piVar16[3] = piVar16[3] - 1;
                DAT_008ca4cc = iVar6;
                FUN_005451a0(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(iVar6 + 8) + 8));
            }
        }
        iVar6 = static_cast<int>(obj[offset]);
    }
}

// ---------------------------------------------------------------------------
// 0x4b7c70 - observed shape
// "Change Sails and Flags" dialog. Cycles custom sail and flag selections,
// previews the ship, then commits the picked sail/flag skins back through the
// caller-supplied arrays (param_3 sails, param_5 flags).
// ---------------------------------------------------------------------------
extern char FUN_004b7c70(char param_1,int param_2,int param_3,int param_4,int param_5)
{
    uint8_t bVar1;
    int* piVar2;
    bool bVar3;
    uint32_t* puVar4;
    DWORD DVar5;
    int iVar6;
    uint32_t* puVar7;
    uint8_t* pbVar8;
    uint32_t* puVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    int iVar12;
    int iVar13;
    uint32_t uVar14;
    uint8_t* pbVar15;
    int* piVar16;
    uint32_t** ppuVar17;
    bool bVar18;
    uint32_t uVar19;
    uint32_t uVar20;
    uint8_t local_d6;
    uint32_t local_d4;
    uint32_t uStack_d0;
    uint32_t uStack_cc;
    uint8_t* puStack_c8;
    uint32_t* puStack_c4;
    uint32_t local_c0;
    int local_bc;
    uint32_t* puStack_b8;
    uint8_t* puStack_b4;
    uint32_t* puStack_b0;
    int local_ac;
    uint32_t* local_a8;
    uint32_t* local_a4;
    uint32_t* local_a0;
    uint32_t* local_9c;
    uint32_t* local_98[2];
    uint32_t uStack_90;
    uint32_t uStack_8c;
    int local_88;
    int local_84;
    int local_80;
    int local_7c;
    uint32_t uStack_78;
    int aiStack_74[11];
    uint8_t auStack_48[36];
    uint32_t auStack_24[9];

    local_c0 = 0;
    local_d6 = 0;
    bVar3 = false;
    aiStack_74[8] = 0x50;
    aiStack_74[9] = 0;
    aiStack_74[10] = 0xa0;
    local_88 = 0;
    local_84 = 0;
    local_80 = -1;
    local_bc = 0;
    if ((_DAT_008ed61c & 1) == 0) {
        _DAT_008ed61c = _DAT_008ed61c | 1;
        DAT_008ed618 = timeGetTime();
    }
    DVar5 = timeGetTime();
    local_7c = DVar5 - DAT_008ed618;
    if ((_DAT_008ed61c & 1) == 0) {
        _DAT_008ed61c = _DAT_008ed61c | 1;
        DAT_008ed618 = timeGetTime();
    }
    timeGetTime();
    do {
        iVar6 = FUN_0042e1d0(0);
    } while (iVar6 != 0);
    DAT_0086c35c = 0;
    DAT_0086c360 = 0;
    DAT_0086c330 = 0;
    local_d4 = 0;
    local_98[0] = 0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;

    // previous-sail button
    iVar6 = FUN_004b17f0("SailLeft","button_leftArrow.kfm",0x6e,0x82,0xfffffff6);
    if ((iVar6 != 0) && (local_ac = iVar6, iVar6 != 0)) {
        *reinterpret_cast<int*>(iVar6 + 4) = *reinterpret_cast<int*>(iVar6 + 4) + 1;
    }
    FUN_004b1990(0xf);
    iVar6 = DAT_0086c330;
    DAT_0086c330 = DAT_0086c330 + 1;
    (&DAT_0086c1a0)[iVar6] = 0;
    (&DAT_0086c010)[iVar6] = 0x62;
    (&DAT_0086be80)[iVar6] = 0x76;
    (&DAT_0086bcf0)[iVar6] = 0x76;
    (&DAT_0086bb60)[iVar6] = 0x8a;

    // next-sail button
    puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_004b17f0("SailRight","button_rightArrow.kfm",0x21c,0x82,0xfffffff6)));
    if (local_a8 != puVar7) {
        if (local_a8 != 0) (**(void (***)(int))local_a8)(1);
        local_a8 = puVar7;
        if (puVar7 != 0) puVar7[1] = puVar7[1] + 1;
    }
    FUN_004b1990(0x10);
    iVar6 = DAT_0086c330;
    DAT_0086c330 = DAT_0086c330 + 1;
    (&DAT_0086c1a0)[iVar6] = 1;
    (&DAT_0086c010)[iVar6] = 0x214;
    (&DAT_0086be80)[iVar6] = 0x76;
    (&DAT_0086bcf0)[iVar6] = 0x228;
    (&DAT_0086bb60)[iVar6] = 0x8a;

    // previous-flag button
    puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_004b17f0("FlagLeft","button_leftArrow.kfm",0x6e,0xd2,0xfffffff6)));
    if (local_a4 != puVar7) {
        if (local_a4 != 0) (**(void (***)(int))local_a4)(1);
        local_a4 = puVar7;
        if (puVar7 != 0) puVar7[1] = puVar7[1] + 1;
    }
    FUN_004b1990(0x11);
    iVar6 = DAT_0086c330;
    DAT_0086c330 = DAT_0086c330 + 1;
    (&DAT_0086bcf0)[iVar6] = 0x76;
    (&DAT_0086c1a0)[iVar6] = 2;
    (&DAT_0086c010)[iVar6] = 0x62;
    (&DAT_0086be80)[iVar6] = 199;
    (&DAT_0086bb60)[iVar6] = 0xdb;

    // next-flag button
    puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_004b17f0("FlagRight","button_rightArrow.kfm",0x21c,0xd2,0xfffffff6)));
    if (local_a0 != puVar7) {
        if (local_a0 != 0) (**(void (***)(int))local_a0)(1);
        local_a0 = puVar7;
        if (puVar7 != 0) puVar7[1] = puVar7[1] + 1;
    }
    FUN_004b1990(0x12);
    iVar6 = DAT_0086c330;
    DAT_0086c330 = DAT_0086c330 + 1;
    (&DAT_0086c1a0)[iVar6] = 3;
    (&DAT_0086c010)[iVar6] = 0x214;
    (&DAT_0086be80)[iVar6] = 199;
    (&DAT_0086bcf0)[iVar6] = 0x228;
    (&DAT_0086bb60)[iVar6] = 0xdb;

    // cancel button
    puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_004b17f0("SailCancel","button_abandon.kfm",0xd5,0x168,0xfffffff6)));
    if (local_9c != puVar7) {
        if (local_9c != 0) (**(void (***)(int))local_9c)(1);
        local_9c = puVar7;
        if (puVar7 != 0) puVar7[1] = puVar7[1] + 1;
    }
    FUN_004b1990(0x13);
    iVar6 = DAT_0086c330;
    DAT_0086c330 = DAT_0086c330 + 1;
    (&DAT_0086c1a0)[iVar6] = 4;
    (&DAT_0086c010)[iVar6] = 0xc9;
    (&DAT_0086be80)[iVar6] = 0x15f;
    (&DAT_0086bcf0)[iVar6] = 0xdd;
    (&DAT_0086bb60)[iVar6] = 0x173;

    // accept button
    puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_004b17f0("SailAccept","button_continueExit.kfm",0x197,0x168,0xfffffff6)));
    if (local_98[0] != puVar7) {
        if (local_98[0] != 0) (**(void (***)(int))local_98[0])(1);
        local_98[0] = puVar7;
        if (puVar7 != 0) puVar7[1] = puVar7[1] + 1;
    }
    FUN_004b1990(0x14);
    iVar6 = DAT_0086c330;
    DAT_0086c330 = DAT_0086c330 + 1;
    uVar14 = 0;
    (&DAT_0086c1a0)[iVar6] = 5;
    (&DAT_0086c010)[iVar6] = 0x182;
    (&DAT_0086be80)[iVar6] = 0x153;
    (&DAT_0086bcf0)[iVar6] = 0x1ac;
    (&DAT_0086bb60)[iVar6] = 0x17d;

    uStack_d0 = 0;
    if ((*reinterpret_cast<int*>(PTR_DAT_00726a88 + -4) != 0) && (0 < param_2)) {
        puVar7 = *reinterpret_cast<uint32_t**>(param_3 + 4);
        do {
            pbVar15 = reinterpret_cast<uint8_t*>(*puVar7);
            pbVar8 = reinterpret_cast<uint8_t*>(PTR_DAT_00726a88);
            iVar6 = slot_name_cmp(pbVar8, pbVar15);
            if (iVar6 == 0) {
                uStack_d0 = uVar14;
                break;
            }
            uVar14 = uVar14 + 1;
            puVar7 = puVar7 + 1;
        } while (static_cast<int>(uVar14) < param_2);
    }
    uVar14 = 0;
    uStack_cc = 0;
    if ((*reinterpret_cast<int*>(PTR_DAT_00726a8c + -4) != 0) && (0 < param_4)) {
        puVar7 = *reinterpret_cast<uint32_t**>(param_5 + 4);
        uVar14 = 0;
        do {
            pbVar15 = reinterpret_cast<uint8_t*>(*puVar7);
            pbVar8 = reinterpret_cast<uint8_t*>(PTR_DAT_00726a8c);
            iVar6 = slot_name_cmp(pbVar8, pbVar15);
            if (iVar6 == 0) {
                uStack_cc = uVar14;
                break;
            }
            uVar14 = uVar14 + 1;
            puVar7 = puVar7 + 1;
        } while (static_cast<int>(uVar14) < param_4);
        uVar14 = 0;
    }
    uVar19 = 0xffffffff;
    uStack_78 = 0xffffffff;
    uStack_8c = 0xffffffff;
    aiStack_74[3] = 0;
    aiStack_74[0] = 0;
    aiStack_74[4] = 0;
    aiStack_74[1] = 0;
    uStack_cc = uStack_d0;
    aiStack_74[5] = 0;
    aiStack_74[2] = 0;
    uStack_d0 = uVar14;

    do {
        iVar6 = local_7c;
        if (DAT_008cac27 != '\0') {
            bVar3 = true;
            local_d6 = 1;
        }
        if ((_DAT_008ed61c & 1) == 0) {
            _DAT_008ed61c = _DAT_008ed61c | 1;
            DAT_008ed618 = timeGetTime();
        }
        DVar5 = timeGetTime();
        local_7c = DVar5 - DAT_008ed618;
        aiStack_74[6] = local_7c - iVar6;
        if (param_1 == '\0') {
            FUN_004b24a0(DAT_008cabe8,1);
            uVar11 = DAT_0085a26c;
            uVar10 = DAT_0085a268;
        } else {
            FUN_004af080(reinterpret_cast<uint32_t>(puStack_b0),0,0,0x400,0x300,0,0,DAT_0085a26c,DAT_0085a268,0xffffffff,0x200);
            uVar11 = DAT_0085a26c;
            uVar10 = DAT_0085a268;
            DAT_007263bc = DAT_007263bc | 0x1000;
        }
        FUN_004f6090("Change Sails and Flags");
        DAT_0085a11c = 100;
        FUN_004b06c0(reinterpret_cast<char*>(&DAT_00869b48),static_cast<int>(uVar11) / 2,0x20,100,0xffffffff,4,0xffffffff,0);
        if (local_d4 == 0) {
            FUN_004881b0(static_cast<int>(uVar11) / 2 + -0xd2,static_cast<int>(uVar10) / 5 + -5);
        }
        if (param_2 == 0) {
            FUN_004f6090("You have no custom sails that can be used.");
            DAT_0085a11c = 0x50;
            FUN_004b06c0(reinterpret_cast<char*>(&DAT_00869b48),static_cast<int>(uVar11) / 2,
                         static_cast<int>(uVar10) / 5 + 0x1e,0x50,0xffffffff,4,0xffffffff,0);
        } else {
            if (uStack_cc != uStack_78) {
                iVar6 = -1;
                do {
                    piVar2 = reinterpret_cast<int*>(FUN_00500850());
                    puVar7 = reinterpret_cast<uint32_t*>(aiStack_74[iVar6 + 4]);
                    if (puVar7 != reinterpret_cast<uint32_t*>(piVar2)) {
                        if (puVar7 != 0) (**(void (***)(int))puVar7)(1);
                        aiStack_74[iVar6 + 4] = reinterpret_cast<int>(piVar2);
                        if (piVar2 != 0) piVar2[1] = piVar2[1] + 1;
                    }
                    puVar7 = DAT_008e8fb8;
                    iVar6 = iVar6 + 1;
                } while (iVar6 < 2);
                uStack_78 = uStack_cc;
                puVar9 = reinterpret_cast<uint32_t*>(aiStack_74[(1 % param_2) + 3]);
                if (DAT_008e8fb8 != puVar9) {
                    if (DAT_008e8fb8 != 0) {
                        iVar6 = DAT_008e8fb8[1];
                        DAT_008e8fb8[1] = iVar6 - 1;
                        if (iVar6 - 1 == 0) (**(void (***)(int))puVar7)(1);
                    }
                    DAT_008e8fb8 = puVar9;
                    if (puVar9 != 0) puVar9[1] = puVar9[1] + 1;
                }
            }
            drain_texture_queue_at(puStack_c4,0x14);
            if ((puStack_c4[0x2f] == 0) || (1 < DAT_007263a0)) {
                uVar10 = puStack_c4[7];
            } else {
                uVar10 = static_cast<uint32_t>(FUN_004baaa0());
            }
            iVar6 = FUN_004bf5e0(uVar10,"ship_sail_emblem_lrg*");
            iVar6 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar6 + 0x2c) + 0x18);
            piVar16 = *reinterpret_cast<int**>(iVar6 + 4);
            if (piVar16 != 0) {
                puVar9 = reinterpret_cast<uint32_t*>(vtbl_slot<uint32_t* (*)(int*)>(piVar16, 4)(piVar16));
                puVar4 = DAT_008e8fb8;
                bVar18 = false;
                if (puVar9 != 0) {
                    do {
                        if (puVar9 == reinterpret_cast<uint32_t*>(&DAT_00727520)) {
                            bVar18 = true;
                            break;
                        }
                        puVar9 = reinterpret_cast<uint32_t*>(puVar9[1]);
                    } while (puVar9 != 0);
                }
                uStack_90 = -(uint32_t)bVar18 & static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar16));
                if (uStack_90 != 0) {
                    puVar9 = *reinterpret_cast<uint32_t**>(iVar6 + 4);
                    if (puVar9 != DAT_008e8fb8) {
                        if (puVar9 != 0) {
                            iVar6 = puVar9[1];
                            puVar9[1] = iVar6 - 1;
                            if (iVar6 - 1 == 0) (**(void (***)(int))puVar9)(1);
                        }
                        *reinterpret_cast<uint32_t**>(iVar6 + 4) = puVar4;
                        if (puVar4 != 0) puVar4[1] = puVar4[1] + 1;
                    }
                }
            }
            drain_texture_queue_at(puStack_c4,0x14);
            if ((puStack_c4[0x2f] != 0) && (DAT_007263a0 < 2)) {
                FUN_004baaa0();
            }
            FUN_00534130();
            iVar6 = 0;
            iVar12 = 0;
            do {
                iVar13 = *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(aiStack_74) + iVar12 + 0xc);
                if (iVar13 != 0) {
                    FUN_004af080(static_cast<uint32_t>(iVar13),0,0,0x200,0x200,
                                 static_cast<int>(uVar11) / 2 + -0xa6 + iVar6,
                                 static_cast<int>(uVar10) / 5 + 2,0x40,0x40,0xffffffff,
                                 *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(aiStack_74) + iVar12 + 0x20));
                }
                iVar12 = iVar12 + 4;
                iVar6 = iVar6 + 0x8c;
            } while (iVar12 < 0xc);
        }
        if (local_d4 == 1) {
            FUN_004881b0(static_cast<int>(uVar11) / 2 + -0xd2,static_cast<int>(uVar10) / 5 + 0x4b);
        }
        if (param_4 == 0) {
            FUN_004f6090("You have no custom flags that can be used.");
            DAT_0085a11c = 0x50;
            FUN_004b06c0(reinterpret_cast<char*>(&DAT_00869b48),static_cast<int>(uVar11) / 2,
                         static_cast<int>(uVar10) / 5 + 0x6e,0x50,0xffffffff,4,0xffffffff,0);
            puVar7 = puStack_c4;
        } else {
            if (uStack_d0 != uStack_8c) {
                iVar6 = -1;
                do {
                    piVar2 = reinterpret_cast<int*>(FUN_00500850());
                    puVar7 = reinterpret_cast<uint32_t*>(aiStack_74[iVar6 + 1]);
                    if (puVar7 != reinterpret_cast<uint32_t*>(piVar2)) {
                        if (puVar7 != 0) (**(void (***)(int))puVar7)(1);
                        aiStack_74[iVar6 + 1] = reinterpret_cast<int>(piVar2);
                        if (piVar2 != 0) piVar2[1] = piVar2[1] + 1;
                    }
                    puVar7 = DAT_008e8fb4;
                    iVar6 = iVar6 + 1;
                } while (iVar6 < 2);
                uStack_8c = uStack_d0;
                puVar9 = reinterpret_cast<uint32_t*>(aiStack_74[(1 % param_4) + 0]);
                if (DAT_008e8fb4 != puVar9) {
                    if (DAT_008e8fb4 != 0) {
                        iVar6 = DAT_008e8fb4[1];
                        DAT_008e8fb4[1] = iVar6 - 1;
                        if (iVar6 - 1 == 0) (**(void (***)(int))puVar7)(1);
                    }
                    DAT_008e8fb4 = puVar9;
                    if (puVar9 != 0) puVar9[1] = puVar9[1] + 1;
                }
            }
            drain_texture_queue_at(puStack_c4,0x14);
            if ((puStack_c4[0x2f] == 0) || (1 < DAT_007263a0)) {
                uVar10 = puStack_c4[7];
            } else {
                uVar10 = static_cast<uint32_t>(FUN_004baaa0());
            }
            iVar6 = FUN_004bf530(uVar10,"flag_*");
            if ((*reinterpret_cast<int*>(iVar6 + 0x2c) != 0) &&
                (piVar16 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(iVar6 + 0x2c) + 4), piVar16 != 0)) {
                puVar9 = reinterpret_cast<uint32_t*>(vtbl_slot<uint32_t* (*)(int*)>(piVar16, 4)(piVar16));
                puVar4 = DAT_008e8fb4;
                bVar18 = false;
                if (puVar9 != 0) {
                    do {
                        if (puVar9 == reinterpret_cast<uint32_t*>(&DAT_00727520)) {
                            bVar18 = true;
                            break;
                        }
                        puVar9 = reinterpret_cast<uint32_t*>(puVar9[1]);
                    } while (puVar9 != 0);
                }
                uStack_90 = -(uint32_t)bVar18 & static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar16));
                if (uStack_90 != 0) {
                    iVar12 = *reinterpret_cast<int*>(iVar6 + 0x2c);
                    if (iVar12 == 0) {
                        iVar12 = FUN_00533c78(0x1c);
                        if (iVar12 == 0) {
                            iVar12 = 0;
                        } else {
                            iVar12 = FUN_005426d0();
                        }
                        if (*reinterpret_cast<int*>(iVar6 + 0x30) != 0) {
                            if (*reinterpret_cast<int*>(iVar6 + 0x34) == 0) {
                                *reinterpret_cast<uint32_t*>(iVar6 + 0x34) = 1;
                                if (iVar12 != 0) {
                                    iVar13 = *reinterpret_cast<int*>(iVar6 + 0x38) + 1;
                                    goto LAB_004b8a31;
                                }
                            } else if (iVar12 == 0) {
                                if (*reinterpret_cast<int*>(iVar6 + 0x2c) != 0) {
                                    iVar13 = *reinterpret_cast<int*>(iVar6 + 0x38) - 1;
                                    goto LAB_004b8a31;
                                }
                            } else if (*reinterpret_cast<int*>(iVar6 + 0x2c) == 0) {
                                iVar13 = *reinterpret_cast<int*>(iVar6 + 0x38) + 1;
                            LAB_004b8a31:
                                *reinterpret_cast<int*>(iVar6 + 0x38) = iVar13;
                            }
                            *reinterpret_cast<int*>(iVar6 + 0x2c) = iVar12;
                        }
                    }
                    puVar9 = *reinterpret_cast<uint32_t**>(iVar12 + 4);
                    if (puVar9 != puVar4) {
                        if (puVar9 != 0) {
                            iVar13 = puVar9[1];
                            puVar9[1] = iVar13 - 1;
                            if (iVar13 - 1 == 0) (**(void (***)(int))puVar9)(1);
                        }
                        *reinterpret_cast<uint32_t**>(iVar12 + 4) = puVar4;
                        if (puVar4 != 0) puVar4[1] = puVar4[1] + 1;
                    }
                }
            }
            drain_texture_queue_at(puStack_c4,0x14);
            if ((puStack_c4[0x2f] == 0) || (1 < DAT_007263a0)) {
                FUN_00534130();
            } else {
                FUN_004baaa0();
                FUN_00534130();
            }
            iVar12 = 0;
            iVar6 = 0;
            do {
                iVar13 = *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(aiStack_74) + iVar12);
                if (iVar13 != 0) {
                    FUN_004af080(static_cast<uint32_t>(iVar13),0,0,0x100,0x100,
                                 static_cast<int>(uVar11) / 2 + -0xa6 + iVar6,
                                 static_cast<int>(uVar10) / 5 + 0x52,0x40,0x40,0xffffffff,
                                 *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(aiStack_74) + iVar12 + 0x20));
                }
                iVar12 = iVar12 + 4;
                iVar6 = iVar6 + 0x8c;
            } while (iVar12 < 0xc);
        }

        aiStack_74[7] = static_cast<int>(uVar10 * 6) / 7;
        uStack_90 = uVar11 / 2 - 0x10;
        uVar20 = 0;
        uVar19 = 0x41700000;
        uVar10 = static_cast<uint32_t>(FUN_005f0ddc(0x41700000,0));
        uVar11 = static_cast<uint32_t>(FUN_005f0ddc(uVar10));
        iVar6 = FUN_004bba60(puStack_b0,uVar11,uVar10,uVar19,uVar20);
        FUN_004bbe10(9,DAT_008c8494 >> 1);
        if (*reinterpret_cast<int*>(iVar6 + 0xbc) != 0) {
            FUN_004bcd30(0xe0000000);
        }
        uVar10 = *reinterpret_cast<uint32_t*>(iVar6 + 0x1c);
        FUN_0053c7c0(0xbf490fdb);
        FUN_004bf940(uVar10,auStack_48);
        FUN_004bf8c0(uVar10,auStack_48);
        FUN_004dadc0(0xbf060a92,0,0);
        iVar12 = *reinterpret_cast<int*>(iVar6 + 0x50);
        while (iVar12 != 0) {
            FUN_005516a0();
            if ((DAT_008ca4cc == 0) && (DAT_008ca4c8[3] != 0)) {
                iVar12 = FUN_00551600(0);
                piVar16 = DAT_008ca4c8;
                if (iVar12 == 0) {
                    piVar2 = reinterpret_cast<int*>(DAT_008ca4c8[1]);
                    iVar12 = *piVar2;
                    DAT_008ca4c8[1] = iVar12;
                    if (iVar12 == 0) {
                        piVar16[2] = 0;
                    } else {
                        *reinterpret_cast<uint32_t*>(iVar12 + 4) = 0;
                    }
                    iVar12 = piVar2[2];
                    vtbl_slot<void (*)(int*)>(piVar16, 8)(piVar2);
                    piVar16[3] = piVar16[3] - 1;
                    DAT_008ca4cc = iVar12;
                    FUN_005451a0(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(iVar12 + 8) + 8));
                }
            }
            iVar12 = *reinterpret_cast<int*>(iVar6 + 0x50);
        }
        if ((*reinterpret_cast<int*>(iVar6 + 0xbc) == 0) || (1 < DAT_007263a0)) {
            iVar6 = *reinterpret_cast<int*>(iVar6 + 0x1c);
        } else {
            iVar6 = FUN_004baaa0();
        }
        iVar12 = DAT_008dc30c;
        puVar7 = auStack_24;
        puVar9 = reinterpret_cast<uint32_t*>(iVar6 + 0x38);
        for (iVar13 = 9; (iVar6 = DAT_008dc310, iVar13 != 0); iVar13 = iVar13 - 1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
        }
        if ((local_88 != iVar12) || (iVar13 = local_80, local_84 != DAT_008dc310)) {
            local_88 = iVar12;
            local_84 = DAT_008dc310;
            iVar13 = FUN_0042c6f0();
            iVar12 = static_cast<int>(uVar10) / 5;
            local_80 = iVar13;
            if ((iVar6 < iVar12) || (iVar12 + 0x4b <= iVar6)) {
                if (((iVar12 + 0x4b <= iVar6) && (iVar6 < iVar12 + 0x96)) && (local_d4 != 1)) {
                    FUN_004889c0(&DAT_008c8278,0x36,0xffffffff,0xffffffff,0xffffffff,0xbf800000,0xffffffff);
                    local_d4 = 1;
                }
            } else if (local_d4 != 0) {
                FUN_004889c0(&DAT_008c8278,0x36,0xffffffff,0xffffffff,0xffffffff,0xbf800000,0xffffffff);
                local_d4 = 0;
            }
        }
        switch (iVar13) {
        case 0:
            FUN_004f6090("Select Previous Sail");
            iVar6 = static_cast<int>(uVar10) / 5 + 0x36;
            goto LAB_004b8ee4;
        case 1:
            FUN_004f6090("Select Next Sail");
            DAT_0085a11c = 0x43;
            FUN_004b06c0(reinterpret_cast<char*>(&DAT_00869b48),
                         (static_cast<int>(uVar11) - static_cast<int>((uVar11 + (uVar11 >> 0x1f & 7U)) >> 3)) + -4,
                         static_cast<int>(uVar10) / 5 + 0x36,0x43,0xffffcc00,4,0xffffffff,0);
            break;
        case 2:
            FUN_004f6090("Select Previous Flag");
            iVar6 = static_cast<int>(uVar10) / 5 + 0x86;
        LAB_004b8ee4:
            DAT_0085a11c = 0x43;
            FUN_004b06c0(reinterpret_cast<char*>(&DAT_00869b48),
                         static_cast<int>((uVar11 + (uVar11 >> 0x1f & 7U)) >> 3) + 0x10,iVar6,0x43,0xffffcc00,4,0xffffffff,0);
            break;
        case 3:
            FUN_004f6090("Select Next Flag");
            DAT_0085a11c = 0x43;
            FUN_004b06c0(reinterpret_cast<char*>(&DAT_00869b48),
                         (static_cast<int>(uVar11) - static_cast<int>((uVar11 + (uVar11 >> 0x1f & 7U)) >> 3)) + -4,
                         static_cast<int>(uVar10) / 5 + 0x86,0x43,0xffffcc00,4,0xffffffff,0);
            break;
        case 4:
            FUN_004f6090("Cancel Selection And Return To System Options");
            FUN_004879f0(0x14,0);
            uVar14 = 2;
            iVar12 = static_cast<int>(uVar10) - static_cast<int>((uVar10 + (uVar10 >> 0x1f & 3U)) >> 2);
            iVar6 = static_cast<int>(uVar11) / 3 + -0x10;
            goto LAB_004b903b;
        case 5:
            FUN_004f6090("Accept This Sail And Return To System Options");
            FUN_004879f0(0x14,0);
            iVar12 = static_cast<int>(uVar10) - static_cast<int>((uVar10 + (uVar10 >> 0x1f & 3U)) >> 2);
            uVar14 = 1;
            iVar6 = (static_cast<int>(uVar11) - static_cast<int>(uVar11) / 3) + 0xc;
        LAB_004b903b:
            DAT_0085a11c = 0x43;
            FUN_004b06c0(reinterpret_cast<char*>(&DAT_00869b48),iVar6,iVar12,0x43,0xffffcc00,uVar14,0xffffffff,0);
            break;
        }
        if (param_1 == '\0') {
            iVar6 = FUN_004b2760(0);
        } else {
            FUN_004d0cd0(0,0);
            iVar6 = FUN_0042e440();
        }
        if (((DAT_0086c360 & 1) == 0) || (3 < iVar13)) {
            local_bc = 500;
        } else if (local_bc < 1) {
            iVar6 = iVar13 + 0x200;
            local_bc = 0x32;
        } else {
            local_bc = local_bc - aiStack_74[6];
        }
        if (iVar6 == 0x125) {
            if (local_d4 == 0) {
            LAB_004b91d1:
                FUN_0042e730();
                FUN_00506040(3,0x3f800000,1,0,0x3f800000);
                FUN_00505fc0(0x3f800000,0,0,0x3f800000);
                if (param_2 != 0) {
                    uStack_cc = static_cast<uint32_t>((static_cast<int>(uStack_cc) - 1 + param_2) % param_2);
                }
            } else {
                if (local_d4 == 1) {
                    iVar6 = 0x202;
                    goto LAB_004b90d8;
                }
            LAB_004b91a0:
                if ((iVar6 == 0x126) || (iVar6 == 0x128)) {
                    FUN_0042e730();
                    local_d4 = (local_d4 + 1) & 0x80000001;
                    if (static_cast<int>(local_d4) < 0) {
                        local_d4 = (local_d4 - 1 | 0xfffffffe) + 1;
                    }
                }
            }
            goto switchD_004b90e6_default;
        }
        if (iVar6 != 0x127) {
            if (0x200 < iVar6) goto LAB_004b90d8;
            if (iVar6 == 0x200) goto LAB_004b91d1;
            if (0x1b < iVar6) goto LAB_004b91a0;
            if (iVar6 != 0x1b) {
                if (iVar6 == 1) {
                    local_d6 = 1;
                    goto switchD_004b90e6_caseD_204;
                }
                if (iVar6 != 0xd) goto switchD_004b90e6_default;
                goto switchD_004b90e6_caseD_205;
            }
        switchD_004b90e6_caseD_204:
            FUN_0042e730();
            FUN_00506040(3,0x3f800000,1,0,0x3f800000);
            FUN_00505fc0(0x3f800000,0,0,0x3f800000);
            puVar9 = local_98[1];
            if (DAT_008e8fb8 != local_98[1]) {
                puVar7 = DAT_008e8fb8;
                if (DAT_008e8fb8 != 0) {
                    iVar6 = DAT_008e8fb8[1];
                    DAT_008e8fb8[1] = iVar6 - 1;
                    if (iVar6 - 1 == 0) (**(void (***)(int))puVar7)(1);
                }
                DAT_008e8fb8 = puVar9;
                if (puVar9 != 0) puVar9[1] = puVar9[1] + 1;
            }
            puVar9 = puStack_b8;
            if (DAT_008e8fb4 != puStack_b8) {
                puVar7 = DAT_008e8fb4;
                if (DAT_008e8fb4 != 0) {
                    iVar6 = DAT_008e8fb4[1];
                    DAT_008e8fb4[1] = iVar6 - 1;
                    if (iVar6 - 1 == 0) (**(void (***)(int))puVar7)(1);
                }
                DAT_008e8fb4 = puVar9;
                if (puVar9 != 0) puVar9[1] = puVar9[1] + 1;
            }
            goto LAB_004b94d4;
        }
        if (local_d4 == 0) {
            iVar6 = 0x201;
        } else {
            if (local_d4 != 1) goto LAB_004b91a0;
            iVar6 = 0x203;
        }
    LAB_004b90d8:
        switch (iVar6) {
        case 0x201:
            FUN_0042e730();
            FUN_00506040(3,0x3f800000,1,0,0x3f800000);
            FUN_00505fc0(0x3f800000,0,0,0x3f800000);
            if (param_2 != 0) {
                uStack_cc = static_cast<uint32_t>((static_cast<int>(uStack_cc) + 1) % param_2);
            }
            break;
        case 0x202:
            FUN_0042e730();
            FUN_00506040(3,0x3f800000,1,0,0x3f800000);
            FUN_00505fc0(0x3f800000,0,0,0x3f800000);
            if (param_4 != 0) {
                iVar6 = (static_cast<int>(uStack_d0) - 1) + param_4;
            LAB_004b9349:
                uStack_d0 = static_cast<uint32_t>(iVar6 % param_4);
            }
            break;
        case 0x203:
            FUN_0042e730();
            FUN_00506040(3,0x3f800000,1,0,0x3f800000);
            FUN_00505fc0(0x3f800000,0,0,0x3f800000);
            if (param_4 != 0) {
                iVar6 = static_cast<int>(uStack_d0) + 1;
                goto LAB_004b9349;
            }
            break;
        case 0x204:
            goto switchD_004b90e6_caseD_204;
        case 0x205:
        switchD_004b90e6_caseD_205:
            FUN_0042e730();
            FUN_00506040(3,0x3f800000,1,0,0x3f800000);
            FUN_00505fc0(0x3f800000,0,0,0x3f800000);
            if (*reinterpret_cast<uint32_t*>(param_3 + 0xc) <= uStack_cc) {
                local_c0 = 1;
                FUN_00412cb0();
            }
            FUN_00412ec0();
            uVar14 = local_c0;
            if ((local_c0 & 1) != 0) {
                uVar14 = local_c0 & 0xfffffffe;
                puVar7 = reinterpret_cast<uint32_t*>(puStack_b4 - 8);
                if ((puVar7 != 0) && (puVar7 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                    operator_delete__(puVar7);
                }
                puStack_b4 = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
            }
            if (*reinterpret_cast<uint32_t*>(param_5 + 0xc) <= uStack_d0) {
                local_c0 = uVar14 | 2;
                FUN_00412cb0();
                uVar14 = local_c0;
            }
            FUN_00412ec0();
            if ((uVar14 & 2) != 0) {
                puVar7 = reinterpret_cast<uint32_t*>(puStack_c8 - 8);
                if ((puVar7 != 0) && (puVar7 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                    operator_delete__(puVar7);
                }
                puStack_c8 = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
            }
            goto LAB_004b94d0;
        }
    switchD_004b90e6_default:
        ;
    } while (!bVar3);
LAB_004b94d0:
    puVar9 = puStack_b8;
LAB_004b94d4:
    FUN_004b1940();
    FUN_004b1940();
    FUN_004b1940();
    FUN_004b1940();
    FUN_004b1940();
    FUN_004b1940();
    if (puStack_b0 != 0) (**(void (***)(int))puStack_b0)(1);
    piVar16 = reinterpret_cast<int*>(puStack_c4) + 1;
    *piVar16 = *piVar16 - 1;
    if (*piVar16 == 0) (**(void (***)(int))puStack_c4)(1);
    iVar6 = 3;
    piVar16 = aiStack_74 + 3;
    do {
        puVar7 = reinterpret_cast<uint32_t*>(piVar16[-1]);
        piVar16 = piVar16 - 1;
        if (puVar7 != 0) (**(void (***)(int))puVar7)(1);
        iVar6 = iVar6 - 1;
    } while (iVar6 != 0);
    iVar6 = 3;
    piVar16 = aiStack_74 + 6;
    do {
        puVar7 = reinterpret_cast<uint32_t*>(piVar16[-1]);
        piVar16 = piVar16 - 1;
        if (puVar7 != 0) (**(void (***)(int))puVar7)(1);
        iVar6 = iVar6 - 1;
    } while (iVar6 != 0);
    if (puVar9 != 0) (**(void (***)(int))puVar9)(1);
    if (local_98[1] != 0) (**(void (***)(int))local_98[1])(1);
    iVar6 = 6;
    ppuVar17 = local_98 + 1;
    do {
        puVar7 = ppuVar17[-1];
        ppuVar17 = ppuVar17 - 1;
        if (puVar7 != 0) (**(void (***)(int))puVar7)(1);
        iVar6 = iVar6 - 1;
    } while (iVar6 != 0);
    FUN_004b1a30();
    DAT_0086c35c = 0;
    DAT_0086c360 = 0;
    return static_cast<char>(local_d6);
}

// __APPEND_MARK__

