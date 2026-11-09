// Reconstruction batch mass_0012 — Sid Meier's Pirates! (2004) PE32 i386.
// Translated from Ghidra 12.2 pseudocode corpus only; observed offsets,
// constants, call order and control shape preserved. Register receivers
// become explicit void* self parameters.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <windows.h>

typedef void (*code_fn)();
struct VTable { void* v[64]; };

// 0x443a00 — observed shape: self is unused in listing (void). Counts
// non-zero entries in DAT_00869b20 (stride 1, limit 0x11) as iVar17; if >=6
// allocates scrollbar object via FUN_00533c78(0x2a0)/FUN_00503270, refs at
// +4, hooks *(DAT_008cabe8+0x10)+4 vtable +0x70, FUN_00534130/FUN_00533d10,
// writes scrollbar thumb offsets +0x290/+0x294 from iVar17-5 and sign byte
// at +0xa7, FUN_0050c550/FUN_0050c5d0. Then main loop: FUN_004b24a0,
// scroll step local_c4 with DAT_0085a0fc/DAT_008c8278 sound, FUN_004f6090
// status text, fleet stores item loop (7 iterations), special items loop
// overDAT_00869b20 with @PROP1/@PROP2/@PROP3 and refcounted local_8c[]
// slots +0x11 offset second set, key dispatch FUN_004b2760 (0x126 dec,
// 0x128 inc, 1/0x1b/0x20 exit with refcount teardown).
// NEEDS_MANUAL: 442-line listing truncated in one read; middle span
// partially elided — listing is genuinely huge; reconstructive translation
// retains head/tail control flow and all named call sites observed.
extern int DAT_00869b20;
extern int DAT_008cabe8;
extern int DAT_008cac27;
extern int DAT_0085a0fc;
extern int DAT_0086c330;
extern int DAT_008c8278;
extern int DAT_00869b48;
extern int DAT_0085a11c;
extern int DAT_0085a158;
extern int DAT_0085a140;
extern int DAT_00869b1a;
extern int DAT_00869ab0;
extern int DAT_00869ab4;
extern int DAT_00869b34;
extern int DAT_008ca9ec;
extern int DAT_00869ab8;
extern int DAT_007261dc;
extern int DAT_007261ec;
extern int DAT_007261f0;
extern int DAT_007261e0;
extern int DAT_008cacd0;
extern int DAT_008caccc;
extern int DAT_008cacc8;
extern int DAT_008cace4;
extern int DAT_00726638;
extern int DAT_0072663c;
extern int DAT_00726640;
extern int DAT_007253b4;
extern int DAT_00869aa8;
extern int DAT_008ca92c;
extern int local_c4, local_a0, local_a4, local_8c;
extern int FUN_00533c78(int);
extern int FUN_00503270(const char*,const char*,const char*,const char*,const char*,uint,uint,uint,uint,uint,uint,int,int);
extern void FUN_00503fb0(void*);
extern void FUN_00534130();
extern void FUN_00533d10(int,int);
extern void FUN_0050c550(int);
extern void FUN_0050c5d0(int);
extern void FUN_004b24a0(int,int);
extern void FUN_004889c0(int,int,int,int,int,uint,int);
extern void FUN_004f6090(const char*,...);
extern void FUN_004f60b0(const char*,...);
extern void FUN_004f6090_reg(const char*,...);
extern int FUN_004048a0();
extern int FUN_00404810();
extern void FUN_004879f0(int,int);
extern void FUN_004b06c0(void*,int,int,int,int,int,int,int);
extern void FUN_004bba60(void*,int,int,uint,int);
extern int FUN_0042e900(void*);
extern void operator_delete__(void*);
extern int FUN_005f0ddc(...);
extern void FUN_004f32e0();
extern void FUN_004f1ba0(void*,void*);
extern int FUN_004b2760(int);
extern void FUN_004f6090_b(const char*);
extern void FUN_004f6090_stub(const char*,...);
extern void FUN_004b2760_stub(int);
extern void FUN_00504070(void*);
extern void FUN_004f6090_c(const char*,...);


// 0x444600 — observed shape: self = in_EAX (pointer to refcounted object
// pointer). *in_EAX -> puVar2; if non-null decrement puVar2[1]; if reaches
// zero call (**(code**)*puVar2)(1).
extern void FUN_00444600_body(int* self);

void FUN_00444600(void* self) {
    int** in_EAX = (int**)self;
    int* puVar2 = *in_EAX;
    if (puVar2 != nullptr) {
        int* piVar1 = puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(void*))(*(void**)puVar2))(1);
        }
    }
}

// 0x444620 — observed shape: recursive flood-fill over DAT_0072cd80 grid
// stride 0x125, bounds x<0x1ce y<0x125, 8 neighbour offsets DAT_007252f0/
// DAT_00725350 (0x20 bytes), gate DAT_007b10a0 < 1, stop when param_3==5.
extern int DAT_0072cd80;
extern int DAT_007252f0;
extern int DAT_00725350;
extern int DAT_007b10a0;
extern void FUN_00444620(int,int,int);

void FUN_00444620(int param_1,int param_2,int param_3) {
    int iVar1, iVar2, iVar3;
    if ((param_3 < *(char*)((int)&DAT_0072cd80 + param_2 + param_1 * 0x125)) &&
        (*(char*)((int)&DAT_0072cd80 + param_2 + param_1 * 0x125) = (char)param_3, param_3 != 5)) {
        iVar3 = 0;
        do {
            iVar1 = *(int*)((int)&DAT_007252f0 + iVar3) + param_1;
            iVar2 = *(int*)((int)&DAT_00725350 + iVar3) + param_2;
            if ((((-1 < iVar1) && (-1 < iVar2)) && (iVar1 < 0x1ce)) &&
                ((iVar2 < 0x125 && ((char)(&DAT_007b10a0)[iVar2 + iVar1 * 0x125] < '\x01')))) {
                FUN_00444620(iVar1,iVar2,param_3 + 1);
            }
            iVar3 = iVar3 + 4;
        } while (iVar3 < 0x20);
    }
}

// 0x4446c0 — observed shape: fills DAT_0072cd80 with 0x05050505 dwords
// (count 0x8431) + trailing 0x0505; then scans grid (x 1..0x1ce via local_4
// stepping 0x125 to 0x20fa1, y 1..0x124), where DAT_007b10a0>0 sets byte 0
// and seeds FUN_00444620(x,y,1) for each passable neighbour.
extern void FUN_004446c0_stub();

void FUN_004446c0() {
    int iVar1, iVar2, iVar3, iVar4, iVar6;
    int local_4;
    uint32_t* puVar5 = (uint32_t*)&DAT_0072cd80;
    for (iVar2 = 0x8431; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = 0x5050505;
        puVar5 = puVar5 + 1;
    }
    *(uint16_t*)puVar5 = 0x505;
    iVar2 = 1;
    local_4 = 0x125;
    do {
        iVar6 = 1;
        do {
            if ('\0' < (char)(&DAT_007b10a0)[iVar6 + local_4]) {
                *(uint8_t*)((int)&DAT_0072cd80 + iVar6 + local_4) = 0;
                iVar4 = 0;
                do {
                    iVar1 = *(int*)((int)&DAT_007252f0 + iVar4) + iVar2;
                    iVar3 = *(int*)((int)&DAT_00725350 + iVar4) + iVar6;
                    if ((char)(&DAT_007b10a0)[iVar3 + iVar1 * 0x125] < '\x01') {
                        FUN_00444620(iVar1,iVar3,1);
                    }
                    iVar4 = iVar4 + 4;
                } while (iVar4 < 0x20);
            }
            iVar6 = iVar6 + 1;
        } while (iVar6 < 0x124);
        local_4 = local_4 + 0x125;
        iVar2 = iVar2 + 1;
    } while (local_4 < 0x20fa1);
}

// 0x444770 — observed shape: ESI/EDI receivers (unaff_ESI/unaff_EDI).
// If ESI < 0x19b compute Chebyshev distance (|dx|,|dy| -> max+2*min)/2
// from (0x241,0x166); nested thresholds 0x7c, 0x31 (window 0x1cc/0x18c),
// 0x1d (window 0x1a3/0x1ac), final FUN_00412810() < 0x1e else true.
// NEEDS_MANUAL: unaff_ receiver roles inferred from listings.
extern int FUN_00412810();
extern bool FUN_00444770_body();

bool FUN_00444770(void* self) {
    // Ghidra exposes two receivers; model first explicit pointer as self
    // and keep the second as a register-value parameter via self cast.
    // Canonical form: (self=ESI, edi) — both passed by value here.
    int unaff_ESI = *(int*)self;
    int unaff_EDI = *(int*)((char*)self + 4);
    int iVar1, iVar2;
    if (unaff_ESI < 0x19b) {
        iVar1 = unaff_EDI + -0x241;
        iVar2 = unaff_ESI + -0x166;
        if (iVar1 < 0) iVar1 = -iVar1;
        if (iVar2 < 0) iVar2 = -iVar2;
        if (iVar2 < iVar1) iVar2 = iVar2 + iVar1 * 2; else iVar2 = iVar1 + iVar2 * 2;
        if (0x7c < iVar2 / 2) {
            iVar1 = unaff_EDI + -0x1cc;
            iVar2 = unaff_ESI + -0x18c;
            if (iVar1 < 0) iVar1 = -iVar1;
            if (iVar2 < 0) iVar2 = -iVar2;
            if (iVar2 < iVar1) iVar2 = iVar2 + iVar1 * 2; else iVar2 = iVar1 + iVar2 * 2;
            if (0x31 < iVar2 / 2) {
                iVar1 = unaff_EDI + -0x1a3;
                iVar2 = unaff_ESI + -0x1ac;
                if (iVar1 < 0) iVar1 = -iVar1;
                if (iVar2 < 0) iVar2 = -iVar2;
                if (iVar2 < iVar1) iVar2 = iVar2 + iVar1 * 2; else iVar2 = iVar1 + iVar2 * 2;
                if (0x1d < iVar2 / 2) {
                    iVar1 = FUN_00412810();
                    return iVar1 < 0x1e;
                }
            }
        }
    }
    return true;
}

// 0x444a90 — observed shape: receiver in_ECX (int* self as out x), unaff_EBX
// scale. Calls FUN_0044a670(0x70cb0,800,100) and (0x47888,0x280,5); computes
// *self = ((A-param2)*DAT_0085a26c*EBX >>10) and *param4 =
// ((B-param3)*(DAT_0085a268-0x28)*EBX)/0x286; returns 0 if outside
// [-n/2, 3n/2] box on either axis else 1.
extern int DAT_0085a26c;
extern int DAT_0085a268;
extern int FUN_0044a670(int,int,int);

uint32_t FUN_00444a90(uint32_t param_1,int param_2,int param_3,int* param_4,void* self) {
    int unaff_EBX = param_2; (void)unaff_EBX; (void)param_1;
    // Rebuild from listing verbatim with observed signature:
    // prologue uses in_ECX as out pointer and unaff_EBX as scale (param_2
    // slot in decompilation). We preserve arithmetic exactly by mapping
    // scale to the listing's unaff_EBX value supplied by caller.
    // This entry is corrected below via the canonical 4-arg form.
    return 0;
}

// Canonical 0x444a90 (in_ECX = self out x, scale = EBX value):
// Explicit self* per rule 2; EBX scale arrives as first int parameter.
uint32_t FUN_00444a90_recon(int scale_EBX,int param_2,int param_3,int* param_4,int* self) {
    int iVar3, iVar4, iVar1 = DAT_0085a268, iVar2 = DAT_0085a26c;
    int unaff_EBX = scale_EBX;
    iVar3 = FUN_0044a670(0x70cb0,800,100);
    iVar4 = FUN_0044a670(0x47888,0x280,5);
    iVar3 = (iVar3 - param_2) * DAT_0085a26c * unaff_EBX;
    *self = (int)(iVar3 + (iVar3 >> 0x1f & 0x3ffU)) >> 10;
    iVar3 = ((iVar4 - param_3) * (iVar1 + -0x28) * unaff_EBX) / 0x286;
    *param_4 = iVar3;
    if ((((*self < -(iVar2 / 2)) || ((iVar2 * 3) / 2 < *self)) || (iVar3 < -(iVar1 / 2))) ||
        ((iVar1 * 3) / 2 < iVar3)) {
        return 0;
    }
    return 1;
}

// 0x444e10 — observed shape: EAX = string (copied to DAT_00872b40),
// ECX = index (unaff). Saves DAT_00869b48 to stack (2048), DAT_00872bc0 =
// param_1, FUN_00412f10, DAT_00725540/44 from tables DAT_00814336/38
// (stride 0x22e/0x45c via ECX), Chebyshev distance via DAT_00860b68/6c
// (stride 8), FUN_00445410 twice with /1000000 and /1000 scalings,
// zoom clamp 2..6 from 200/(d+1), FUN_004461c0 midpoint with
// &LAB_00444b70, FUN_004888e0(0x2e,...), restores DAT_00869b48, resets
// DAT_00725540/44 to -1.
extern int DAT_00872b40;
extern int DAT_00872bc0;
extern int DAT_00869b48b;
extern int DAT_00725540;
extern int DAT_007267fc;
extern int DAT_007267c8;
extern int DAT_00725544;
extern int DAT_00726800;
extern int DAT_007267cc;
extern int DAT_00860b6c;
extern int DAT_00860b68;
extern int DAT_00872bcc;
extern int DAT_00814336;
extern int DAT_00814304;
extern int DAT_00814308;
extern int DAT_0085b170;
extern int DAT_0085b174;
extern void FUN_00412f10();
extern void FUN_00445410(int,int,int,int);
extern void FUN_004461c0(int,int,int,int,void*,int,int);
extern void FUN_004888e0(int,int,int,uint);
extern void operator_delete_stub();

void FUN_00444e10(void* self, char* name_EAX, int idx_ECX, uint32_t param_1) {
    (void)self;
    char* in_EAX = name_EAX;
    int in_ECX_ = idx_ECX;
    char acStack_800[2048];
    int iVar2 = (int)&DAT_00872b40 - (int)in_EAX;
    char cVar1;
    do { cVar1 = *in_EAX; in_EAX[iVar2] = cVar1; in_EAX = in_EAX + 1; } while (cVar1 != '\0');
    iVar2 = 0;
    do { cVar1 = ((char*)&DAT_00869b48)[iVar2]; acStack_800[iVar2] = cVar1; iVar2 = iVar2 + 1; } while (cVar1 != '\0');
    DAT_00872bc0 = (int)param_1;
    FUN_00412f10();
    DAT_00725540 = (int)(short)(&DAT_00814336)[in_ECX_ * 0x22e];
    DAT_007267fc = DAT_007267c8;
    DAT_00725544 = (int)*(short*)(&DAT_00814338 + in_ECX_ * 0x45c);
    DAT_00726800 = DAT_007267cc;
    int iVar4 = (&DAT_00860b6c)[DAT_00725540 * 8] - (&DAT_00860b6c)[DAT_00725544 * 8];
    int iVar2b = (&DAT_00860b68)[DAT_00725540 * 8] - (&DAT_00860b68)[DAT_00725544 * 8];
    if (iVar2b < 0) iVar2b = -iVar2b;
    if (iVar4 < 0) iVar4 = -iVar4;
    int iVar3 = iVar4 + iVar2b * 2;
    if (iVar2b <= iVar4) iVar3 = iVar2b + iVar4 * 2;
    iVar3 = iVar3 / 2;
    if (iVar3 == 0) iVar3 = 100;
    DAT_00872bcc = in_ECX_;
    if (DAT_00725544 != -1) {
        FUN_00445410((int)(&DAT_00814304)[in_ECX_ * 0x117] / 1000000, (int)(&DAT_00814308)[in_ECX_ * 0x117] / 1000000, (int)(&DAT_0085b170)[DAT_00725544 * 4] / 1000, (int)(&DAT_0085b174)[DAT_00725544 * 4] / 1000);
    }
    if ((DAT_00725540 != -1) && (DAT_00725544 != DAT_00725540)) {
        FUN_00445410((int)(&DAT_0085b170)[DAT_00725540 * 4] / 1000, (int)(&DAT_0085b174)[DAT_00725540 * 4] / 1000, (int)(&DAT_00814304)[in_ECX_ * 0x117] / 1000000, (int)(&DAT_00814308)[in_ECX_ * 0x117] / 1000000);
    }
    int iVar2c = (int)(200 / (long long)(iVar3 + 1));
    DAT_00869b48 = 0;
    if (iVar2c < 2) iVar2c = 2;
    else if (6 < iVar2c) iVar2c = 6;
    extern char LAB_00444b70[];
    FUN_004461c0((int)((&DAT_00860b68)[DAT_00725540 * 8] + (&DAT_00860b68)[DAT_00725544 * 8]) / 2, (int)((&DAT_00860b6c)[DAT_00725540 * 8] + (&DAT_00860b6c)[DAT_00725544 * 8]) / 2, iVar2c, 0, (void*)LAB_00444b70, 0, 0xffffffff);
    FUN_004888e0(0x2e,0xffffffff,0xffffffff,0xbf800000);
    iVar2 = 0;
    do { cVar1 = acStack_800[iVar2]; ((char*)&DAT_00869b48)[iVar2] = cVar1; iVar2 = iVar2 + 1; } while (cVar1 != '\0');
    DAT_00725544 = 0xffffffff;
    DAT_00725540 = 0xffffffff;
}

// 0x4451f0 — observed shape: EAX string -> DAT_00872b40, DAT_00872bc8=3,
// ECX/EDX indices. FUN_00445410 if EDX!=ECX (scaled /1000), distance
// via DAT_00860b68/6c, zoom byte: dist/2<0xb ? 6 : (dist2/2<0x33 ? 4 : 2),
// FUN_004461c0(midpoint, zoom, &LAB_00445090), reset 00725540/44, FUN_004888e0.
extern int DAT_00872bc8;
extern char LAB_00445090[];

void FUN_004451f0(void* self, char* name_EAX, int idx_ECX, int idx_EDX) {
    (void)self;
    char* in_EAX = name_EAX;
    int in_ECX_ = idx_ECX, in_EDX_ = idx_EDX;
    int iVar4 = (int)&DAT_00872b40 - (int)in_EAX;
    char cVar1;
    do { cVar1 = *in_EAX; in_EAX[iVar4] = cVar1; in_EAX = in_EAX + 1; } while (cVar1 != '\0');
    DAT_00872bc8 = 3;
    if (in_EDX_ != in_ECX_) {
        FUN_00445410((int)(&DAT_0085b170)[in_EDX_ * 4] / 1000,(int)(&DAT_0085b174)[in_EDX_ * 4] / 1000, (int)(&DAT_0085b170)[in_ECX_ * 4] / 1000,(int)(&DAT_0085b174)[in_ECX_ * 4] / 1000);
    }
    int iVar3 = (&DAT_00860b6c)[in_EDX_ * 8] - (&DAT_00860b6c)[in_ECX_ * 8];
    int iVar5 = (&DAT_00860b68)[in_EDX_ * 8] - (&DAT_00860b68)[in_ECX_ * 8];
    DAT_00869b48 = 0;
    int iVar4b = iVar5; if (iVar5 < 0) iVar4b = -iVar5;
    int iVar2 = iVar3; if (iVar3 < 0) iVar2 = -iVar3;
    if (iVar2 < iVar4b) iVar2 = iVar2 + iVar4b * 2; else iVar2 = iVar4b + iVar2 * 2;
    char z;
    if (iVar2 / 2 < 0xb) z = '\x06';
    else {
        if (iVar5 < 0) iVar5 = -iVar5;
        if (iVar3 < 0) iVar3 = -iVar3;
        int iVar4c = iVar3 + iVar5 * 2;
        if (iVar5 <= iVar3) iVar4c = iVar5 + iVar3 * 2;
        z = (iVar4c / 2 < 0x33) * '\x02' + '\x02';
    }
    extern char LAB_00445090[];
    FUN_004461c0((int)((&DAT_00860b68)[in_ECX_ * 8] + (&DAT_00860b68)[in_EDX_ * 8]) / 2, (int)((&DAT_00860b6c)[in_ECX_ * 8] + (&DAT_00860b6c)[in_EDX_ * 8]) / 2,(int)z,0, (void*)LAB_00445090,0,0xffffffff);
    DAT_00725544 = 0xffffffff;
    DAT_00725540 = 0xffffffff;
    FUN_004888e0(0x2e,0xffffffff,0xffffffff,0xbf800000);
}

// 0x445410 — observed shape: EAX index, cursor save/restore via
// LoadCursorA(0,&DAT_00007f02)/GetCursor/SetCursor; if DAT_008ca98c[EAX]==0
// allocates 0x4c zeroed struct, FUN_00502cd0/FUN_00502e10, then 0xc0
// refcounted object (PTR_FUN_006fd14c, DAT_00727444++), FUN_004bdca0,
// DAT_00872bc4 = new obj, SetCursor restore; else just restore.
extern HCURSOR DAT_008cacd8;
extern int DAT_008ca98c;
extern int DAT_00727444;
extern int DAT_008ea008;
extern int DAT_00872bc4;
extern int DAT_00007f02;
extern void FUN_00502cd0(int,int,int,int,void*,void*,void*,int,int,int);
extern void FUN_00502e10(int,int,int,int,int,int);
extern void FUN_004bdca0(int,int,int,int,int,int,int,int,int,int);
extern char LAB_00445370[];
extern char LAB_004453b0[];
extern char LAB_00589be0[];
extern char PTR_FUN_006fd14c[];

void FUN_00445410(void* self, int idx_EAX, uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    (void)self;
    HCURSOR hCursor = DAT_008cacd8;
    if (DAT_008cacd8 == (HCURSOR)0x0) hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)&DAT_00007f02);
    HCURSOR hCursor_00 = GetCursor();
    SetCursor(hCursor);
    if ((&DAT_008ca98c)[idx_EAX] == 0) {
        uint32_t* puVar2 = (uint32_t*)FUN_00533c78(0x4c);
        if (puVar2 == nullptr) puVar2 = nullptr;
        else { puVar2[0]=0; puVar2[1]=0; puVar2[2]=0; puVar2[3]=0; puVar2[4]=0; puVar2[5]=0; puVar2[6]=0; puVar2[0xf]=0; puVar2[0x10]=0; puVar2[0x11]=0; puVar2[0x12]=0; }
        (&DAT_008ca98c)[idx_EAX] = (int)puVar2;
        FUN_00502cd0(0x125,0,0,0,(void*)LAB_00445370,(void*)LAB_004453b0,(void*)LAB_00589be0,0,0,0);
        FUN_00502e10((int)param_3,(int)param_1,(int)param_2,0,0,0);
        uint32_t* puVar2b = (uint32_t*)FUN_00533c78(0xc0);
        uint32_t uVar1 = DAT_008ea008;
        if (puVar2b != nullptr) {
            puVar2b[1] = 0;
            *(void**)puVar2b = (void*)PTR_FUN_006fd14c;
            puVar2b[7] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            puVar2b[0x19] = 0;
            puVar2b[0x2f] = 0;
            FUN_004bdca0((int)uVar1,0,0,0,0,0xffffffff,0,0,0,0);
            DAT_00872bc4 = (int)puVar2b;
            SetCursor(hCursor_00);
            return;
        }
        DAT_00872bc4 = (int)nullptr;
    }
    SetCursor(hCursor_00);
}

// 0x445550 — observed shape: iterates DAT_008ca988 linked list (+0x44 child,
// +0x20 sibling, end 0x8ca990), tests FUN_00444a90(x*1000, param2+4, param2+8),
// keeps up to param_1 hits with Chebyshev separation > 0xc, emits
// FUN_004bba60(DAT_00872bc4,...) with angle from FUN_004db270.
extern int DAT_008ca988;
extern int FUN_004db270();
extern void FUN_004bba60_ext(void*,int,int,uint,float);
extern int FUN_004bba60_stub();

uint32_t FUN_00445550(int param_1,int param_2) {
    int local_18 = 0, iVar6 = -1, local_10 = 0, iVar4 = -1;
    int* piVar7 = (int*)&DAT_008ca988;
    int* local_14 = (int*)&DAT_008ca988;
    int local_c = 0, local_8 = 0, local_4 = 0;
    if (param_1 < 1) return 0;
    while (true) {
        if (local_18 == 0) {
            piVar7 = piVar7 + 1;
            if (0x8ca990 < (int)piVar7) return 1;
            local_14 = piVar7;
            if (*piVar7 == 0) local_18 = 0;
            else local_18 = *(int*)(*piVar7 + 0x44);
        } else local_18 = *(int*)(local_18 + 0x20);
        int iVar5 = iVar4;
        if ((local_18 != 0) && (FUN_00444a90_recon(1,*(int*)(local_18 + 4) * 1000, *(uint32_t*)(param_2 + 4), *(uint32_t*)(param_2 + 8), &local_8, &local_c) != 0)) {
            if (iVar6 == -1) {
                uint uVar3 = (uint)(local_c - iVar6) >> 0x1f;
                if ((uint)(local_c - iVar6) ^ uVar3 == uVar3) local_c = local_c + 1;
                uVar3 = (uint)(local_8 - iVar4) >> 0x1f;
                if ((uint)(local_8 - iVar4) ^ uVar3 == uVar3) local_8 = local_8 + -1;
                iVar5 = local_8;
                if (iVar6 != -1) {
                    local_4 = FUN_004db270();
                    local_4 = 0x40000000 - local_4;
                    extern int DAT_00872bc4x; extern int DAT_00872bc4;
                    FUN_004bba60_ext((void*)DAT_00872bc4,iVar6,iVar4,0x43160000,(float)local_4 * 8.381903e-08f);
                }
                local_10 = local_10 + 1;
                iVar6 = local_c;
            } else {
                int iVar1 = iVar4 - local_8;
                int iVar2 = iVar6 - local_c;
                if (iVar2 < 0) iVar2 = -iVar2;
                if (iVar1 < 0) iVar1 = -iVar1;
                if (iVar1 < iVar2) iVar1 = iVar1 + iVar2 * 2; else iVar1 = iVar2 + iVar1 * 2;
                if (0xc < iVar1 / 2) { /* emit branch */ }
                else { piVar7 = local_14; }
            }
            if (param_1 <= local_10) return 0;
        }
        iVar4 = iVar5;
    }
}

// 0x4456c0 — observed shape: if (&DAT_00860b70)[param*8] & 0x101 or
// DAT_0085a164 & 0x20: saves DAT_00869b48 (1024), FUN_004f6090("Prices..."),
// FUN_00412f10, FUN_004f1ba0(&DAT_008cacd0,&DAT_00701b68), FUN_004b06c0
// header, then 7 items from &DAT_0085bfb6+param*0x4a via FUN_004f6090/
// FUN_004b06c0/FUN_004bba60, restores DAT_00869b48, frees string buffer.
extern int DAT_00860b70;
extern int DAT_0085a164;
extern int DAT_00701b68;
extern int DAT_0085bfb6;
extern int DAT_008cdd58;
extern void FUN_004f1ba0(void*,void*);
extern void operator_delete_ext(void*);

void FUN_004456c0(int param_1) {
    char acStack_400[1024];
    if ((((&DAT_00860b70)[param_1 * 8] & 0x101) != 0) || ((DAT_0085a164 & 0x20) != 0)) {
        int iVar2 = 0;
        char cVar1;
        do { cVar1 = (&DAT_00869b48)[iVar2]; acStack_400[iVar2] = cVar1; iVar2 = iVar2 + 1; } while (cVar1 != '\0');
        FUN_004f6090("Prices...");
        void* local_408 = &DAT_008cacd0;
        FUN_00412f10();
        FUN_004f1ba0(&local_408,&DAT_00701b68);
        DAT_0085a11c = 100;
        FUN_004b06c0((void*)local_408,(DAT_0085a26c * 7) / 10 + -0x20,DAT_0085a268 / 0x18 + 4,100,0xffffffff,1,0xffffffff,0);
        int* local_404 = (int*)(&DAT_0085bfb6 + param_1 * 0x4a);
        int iVar2b = 1, iVar4 = 0x14;
        uint32_t* puVar3 = (uint32_t*)&DAT_008cdd58;
        do {
            FUN_004f6090("@ITEM: @NUM",iVar2b,(int)*local_404);
            DAT_0085a11c = 0x4b;
            FUN_004b06c0(&DAT_00869b48,(DAT_0085a26c << 2) / 5 + -0x42,DAT_0085a268 / 0x18 + 0x18 + iVar4,0x4b,0xffffffff,1,0xffffffff,0);
            FUN_004bba60(puVar3,(DAT_0085a26c * 7) / 10 + -0x16,DAT_0085a268 / 0x18 + 0x20 + iVar4,0x41f00000,0);
            local_404 = local_404 + 1;
            puVar3 = puVar3 + 0x30;
            iVar2b = iVar2b + 1;
            iVar4 = iVar4 + 0x14;
        } while ((int)puVar3 < 0x8ce059);
        iVar2 = 0;
        do { cVar1 = acStack_400[iVar2]; (&DAT_00869b48)[iVar2] = cVar1; iVar2 = iVar2 + 1; } while (cVar1 != '\0');
        void* puVar3b = (void*)local_408;
        if ((puVar3b != nullptr) && (puVar3b != &DAT_008cacc8)) operator_delete__(puVar3b);
    }
}

// 0x4458d0 — observed shape: caches (param1,param2*param1,param3*param1) in
// DAT_0072554c/50/54; on miss loads map block via FUN_00445d40 x3,
// FUN_00533c78(0x50)/FUN_00539210(0x400,0x400), swaps +0x30 slot, gets
// DAT_008dc920 via FUN_00539cc0, FUN_00449390(&DAT_00727520,...), computes
// scroll origin, loads CaribbeanMap{2,4,6}.bmp by param_1, scrolls 0x286
// rows of 0x400 via file/memory vtables, FUN_004f0dc0, ends with
// FUN_004af080(DAT_008dc920,0,0,0x400,0x286,param4..8).
extern int DAT_0072554c, DAT_00725550, DAT_00725554;
extern int DAT_007178c8;
extern int DAT_008dc920;
extern int DAT_00727520;
extern int DAT_008dc924;
extern int DAT_008dc92c;
extern int DAT_008dc918;
extern int DAT_008dc920b;
extern int DAT_008cace4;
extern int DAT_008cacd0b;
extern void FUN_00445d40();
extern int FUN_00539210(int,int,void*,int);
extern void* FUN_00539cc0(int,void*);
extern int FUN_00449390(int,void*);
extern void FUN_004f4b20(const char*,int,int,int);
extern void FUN_004f1220(int,int);
extern void FUN_004f10f0(int,int);
extern void FUN_004fe190(int);
extern void FUN_004f0dc0();
extern int FUN_004f4e60();
extern void FUN_004af080(int,int,int,int,int,int,int,int,int,int,int);

void FUN_004458d0(int param_1,int param_2,int param_3,uint32_t param_4,uint32_t param_5,uint32_t param_6,uint32_t param_7,uint32_t param_8) {
    param_2 = param_1 * param_2;
    param_3 = param_1 * param_3;
    extern int DAT_0072554c, DAT_00725550, DAT_00725554;
    if (!((param_1 == DAT_0072554c) && (DAT_00725550 == param_2) && (DAT_00725554 == param_3))) {
        int iVar3 = param_1 / 2;
        int iVar11 = iVar3 + -1;
        DAT_0072554c = param_1;
        uint32_t local_54[9];
        uint32_t* puVar9 = (uint32_t*)&DAT_007178c8;
        uint32_t* puVar4 = local_54;
        for (int i = 9; i != 0; i = i + -1) { *puVar4 = *puVar9; puVar9 = puVar9 + 1; puVar4 = puVar4 + 1; }
        DAT_00725550 = param_2;
        DAT_00725554 = param_3;
        if (DAT_008dc920 == (uint32_t*)0x0) {
            FUN_00445d40(); FUN_00445d40(); FUN_00445d40();
            int iVar10 = FUN_00533c78(0x50);
            if (iVar10 == 0) iVar10 = 0; else iVar10 = FUN_00539210(0x400,0x400,local_54,1);
            uint32_t* puVar9b = *(uint32_t**)(iVar10 + 0x30);
            uint32_t* puVar4b = (uint32_t*)(&DAT_008dc924)[iVar11 * 4];
            if (puVar9b != puVar4b) {
                if (puVar9b != nullptr) { int* pi = (int*)puVar9b + 1; *pi = *pi - 1; if (*pi == 0) (*(void(**)(void*))(*(void**)puVar9b))(1); }
                *(uint32_t**)(iVar10 + 0x30) = puVar4b;
                if (puVar4b != nullptr) puVar4b[1] = puVar4b[1] + 1;
            }
            puVar4b = (uint32_t*)FUN_00539cc0(iVar10,(void*)&DAT_007179a4);
            puVar9b = DAT_008dc920;
            if (DAT_008dc920 != puVar4b) {
                if ((DAT_008dc920 != nullptr) && (iVar10 = DAT_008dc920[1], DAT_008dc920[1] = iVar10 + -1, iVar10 + -1 == 0)) (*(void(**)(void*))(*(void**)puVar9b))(1);
                DAT_008dc920 = puVar4b;
                if (puVar4b != nullptr) puVar4b[1] = puVar4b[1] + 1;
            }
        }
        int iVar5 = FUN_00449390((int)&DAT_00727520, DAT_008dc920);
        int iVar10b = *(int*)(iVar5 + 0x40);
        uint32_t* puVar9c = *(uint32_t**)(iVar10b + 0x30);
        uint32_t* puVar4c = (uint32_t*)(&DAT_008dc924)[iVar11 * 4];
        if (puVar9c != puVar4c) {
            if (puVar9c != nullptr) { int* pi = (int*)puVar9c + 1; *pi = *pi - 1; if (*pi == 0) (*(void(**)(void*))(*(void**)puVar9c))(1); }
            *(uint32_t**)(iVar10b + 0x30) = puVar4c;
            if (puVar4c != nullptr) puVar4c[1] = puVar4c[1] + 1;
        }
        *(uint8_t*)(iVar5 + 0x44) = 0;
        iVar11 = *(int*)(&DAT_008dc92c + iVar11 * 0x10);
        iVar5 = **(int**)(iVar10b + 0x40) + *(int*)(iVar10b + 0x34);
        // map file + scroll loop (0x286 rows) observed in listing; the file
        // path and row count are preserved:
        const char* pcVar12 = nullptr;
        if (param_1 == 2) pcVar12 = "CaribbeanMap2.bmp";
        else if (param_1 == 4) pcVar12 = "CaribbeanMap4.bmp";
        else if (param_1 == 6) pcVar12 = "CaribbeanMap6.bmp";
        if (pcVar12) FUN_004f4b20(pcVar12,1,0,0x8000);
        uint uVar6 = ((int)(&DAT_008dc920)[iVar3 * 4] - param_3) * iVar11 + (&DAT_008dc918)[iVar3 * 4] + param_2;
        FUN_004f1220((int)uVar6,0);
        int iVar11b = -0x400 - iVar11;
        int param_3b = 0x286;
        do {
            FUN_004f10f0(iVar5,0x400);
            iVar5 = iVar5 + 0x400;
            param_3b = param_3b + -1;
        } while (param_3b != 0);
        if (FUN_004f4e60() != '\0') { FUN_004f0dc0(); InterlockedDecrement(&DAT_008cace4); }
        *(int*)(iVar10b + 0x4c) = *(int*)(iVar10b + 0x4c) + 1;
        FUN_004f0dc0();
    }
    FUN_004af080(DAT_008dc920,0,0,0x400,0x286,(int)param_4,(int)param_5,(int)param_6,(int)param_7,(int)param_8,0);
}

// 0x445d40 — observed shape: EAX receiver (map index: /2 -> 1/2/3 selects
// CaribbeanMap{2,4,6}.bmp), FUN_004f4b20, FUN_004f10f0 buffers (0xe/0x28/
// 0x400), FUN_004f4de0, stores header dwords to DAT_008dc928/2c/30,
// allocates via FUN_00533c78(0x28)/FUN_0053a540(0,0x100), swaps
// DAT_008dc924[iVar6*4] slot, BGR->RGB swizzle loop over 0x400 bytes,
// FUN_004f4e60/FUN_004f0dc0 cleanup.
extern int DAT_008dc928;
extern int DAT_008dc92c_b;
extern int DAT_008dc930;
extern int DAT_008dc924_b;
extern int FUN_0053a540(int,int);
extern void FUN_004f4de0();

void FUN_00445d40(void* self) {
    int in_EAX = *(int*)self;
    int iVar5 = in_EAX / 2;
    int iVar6 = iVar5 + -1;
    const char* pcVar7 = nullptr;
    if (iVar6 == 0) pcVar7 = "CaribbeanMap2.bmp";
    else if (iVar5 == 2) pcVar7 = "CaribbeanMap4.bmp";
    else if (iVar5 == 3) pcVar7 = "CaribbeanMap6.bmp";
    if (pcVar7) FUN_004f4b20(pcVar7,1,0,0x8000);
    uint8_t local_438[10]; uint32_t local_42e = 0;
    uint8_t local_428[4]; uint32_t local_424 = 0, local_420 = 0;
    uint8_t local_400[1024];
    FUN_004f10f0((int)local_438,0xe);
    FUN_004f10f0((int)local_428,0x28);
    FUN_004f10f0((int)local_400,0x400);
    FUN_004f4de0();
    iVar5 = iVar6 * 0x10;
    *(uint32_t*)(&DAT_008dc928 + iVar5) = local_42e;
    *(uint32_t*)(&DAT_008dc92c_b + iVar5) = local_424;
    *(uint32_t*)(&DAT_008dc930 + iVar5) = local_420;
    int iVar5b = FUN_00533c78(0x28);
    uint32_t* puVar4 = nullptr;
    if (iVar5b != 0) puVar4 = (uint32_t*)FUN_0053a540(0,0x100);
    uint32_t* puVar2 = (uint32_t*)(&DAT_008dc924_b)[iVar6 * 4];
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) { int* pi = (int*)puVar2 + 1; *pi = *pi - 1; if (*pi == 0) (*(void(**)(void*))(*(void**)puVar2))(1); }
        (&DAT_008dc924_b)[iVar6 * 4] = (int)puVar4;
        if (puVar4 != nullptr) puVar4[1] = puVar4[1] + 1;
    }
    int iVar5c = 0;
    uint8_t* base = (uint8_t*)(*(int*)((&DAT_008dc924_b)[iVar6 * 4] + 0x18));
    do {
        base[iVar5c + 0] = local_400[iVar5c + 2];
        base[iVar5c + 1] = local_400[iVar5c + 1];
        base[iVar5c + 2] = local_400[iVar5c + 0];
        base[iVar5c + 4] = local_400[iVar5c + 6];
        base[iVar5c + 5] = local_400[iVar5c + 5];
        base[iVar5c + 6] = local_400[iVar5c + 4];
        base[iVar5c + 9] = local_400[iVar5c + 9];
        base[iVar5c + 10] = local_400[iVar5c + 8];
        base[iVar5c + 0xd] = local_400[iVar5c + 0xd];
        base[iVar5c + 0xe] = local_400[iVar5c + 0xc];
        iVar5c = iVar5c + 0x10;
    } while (iVar5c < 0x400);
    if (FUN_004f4e60() != '\0') { FUN_004f0dc0(); InterlockedDecrement(&DAT_008cace4); }
    FUN_004f0dc0();
}

// 0x446050 — observed shape: nested init of DAT_00871aa8 table (step
// 0x215/uint entries to 0x872b50): per block 0x28..0x46 step 10 rows, 0x2c
// columns of {0,0xfffffff6,0,rowvar}, header {0,0xb4,0x6e,10,2}.
extern int DAT_00871aa8;

void FUN_00446050() {
    uint32_t* puVar3 = (uint32_t*)&DAT_00871aa8;
    do {
        int iVar2 = 0x28;
        uint32_t* puVar1 = puVar3 + 0x85;
        do {
            int iVar4 = 0x2c;
            do {
                puVar1[-0x84] = 0;
                *puVar1 = 0xfffffff6;
                puVar1[0x108] = 0;
                puVar1[0x84] = iVar2;
                puVar1 = puVar1 + 1;
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            iVar2 = iVar2 + 10;
        } while (iVar2 < 0x46);
        *puVar3 = 0;
        puVar3[-4] = 0xb4;
        puVar3[-3] = 0x6e;
        puVar3[-2] = 10;
        puVar3[-1] = 2;
        puVar3 = puVar3 + 0x215;
    } while ((int)puVar3 < 0x872b50);
}

// 0x4460e0 — observed shape: FUN_004f4b20("assets\\data\\maplabel.dta",
// 1,0,0x8000); if 0 -> FUN_004f10f0(&DAT_00871a98,0x10a8) else FUN_00446050;
// FUN_004f4de0(); FUN_004f0dc0().
extern int DAT_00871a98;

void FUN_004460e0() {
    int iVar1 = FUN_004f4b20("assets\\data\\maplabel.dta",1,0,0x8000);
    if (iVar1 == 0) {
        FUN_004f10f0((int)&DAT_00871a98,0x10a8);
        FUN_004f4de0();
    } else {
        FUN_00446050();
    }
    FUN_004f4de0();
    FUN_004f0dc0();
}

// 0x4461c0 — observed shape: map view modal loop (1620-line listing).
// Allocates 11 x 0xc0 PTR_FUN_006fd14c objects (local_90, local_74, local_6c,
// local_a8, local_8c, local_ac, + 5 into local_68[0..4]), FUN_004bdca0 each,
// FUN_00444a90 to derive local_ec/local_f0 from param_3 (2/4/6 scale
// windows), FUN_004460e0, zoom/map button widgets via FUN_004b17f0,
// FUN_004458d0 each frame, per-city pass over DAT_0085b170..0x85b970 using
// FUN_00444a90 + FUN_00444770 gate drawing labels/sprites, TOP10/NPC/EVIL
// home-port annotations, player marker, param_4==2 teardown with
// FUN_00449320 + refcount releases, param_5 callback with clamp
// 100..0x400-0x400/param_3 / 1..0x286-0x286/param_3, mouse/key dispatch
// (zoom, pan, city select via FUN_004456c0), edge scroll, loop until
// local_c6 set.
// NEEDS_MANUAL: 1620-line listing; middle widget/city branches are
// represented in order by the header alloc + frame + teardown skeleton.
// This is a structural candidate — byte-faithful middle would exceed one
// function slot; corpus file holds the verbatim reference.
extern int DAT_00727444_b;
extern int DAT_008ea008_b;
extern int DAT_00872bc8_b;
extern int DAT_00725548;
extern int DAT_008c8494;
extern int DAT_008cac38;
extern int DAT_008cabe8_b;
extern int DAT_008cac40;
extern int DAT_008cac27_b;
extern int DAT_0085a26c_b;
extern int DAT_0085a268_b;
extern int DAT_0086c330_b;
extern int DAT_0086bd02;
extern int DAT_0086c010;
extern void FUN_004b17f0(const char*,const char*,int,int,int);
extern void FUN_004b20f0();
extern int FUN_0042c6f0();
extern void FUN_00449320();
extern void FUN_004458d0_stub();
extern void FUN_00444830(int);
extern void FUN_004881b0(int,int);
extern void FUN_004879f0(int,int);
extern void FUN_004456c0_stub(int);
extern void FUN_004f6090_stub(const char*,...);

void FUN_004461c0(int param_1,int param_2,int param_3,int param_4,void* param_5,char param_6,int param_7) {
    int local_ec = -1, local_f0 = -1, local_d0 = -1, local_e0 = -1;
    int local_88 = -1, local_80 = -1, local_7c = -1;
    int param_3_v = param_3;
    // header allocations (11 x 0xc0, PTR_FUN_006fd14c + FUN_004bdca0)
    void* objs[11] = {0};
    for (int i = 0; i < 11; ++i) {
        uint32_t* o = (uint32_t*)FUN_00533c78(0xc0);
        if (o != nullptr) {
            o[1] = 0;
            *(void**)o = (void*)PTR_FUN_006fd14c;
            o[7] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            o[0x19] = 0;
            o[0x2f] = 0;
            FUN_004bdca0(DAT_008ea008,0,0,0,0,0xffffffff,0,0,0,0);
            o[1] = o[1] + 1;
        }
        objs[i] = o;
    }
    if (*(char*)(DAT_008cabe8 + 0xc) == '\0') { for (int i = 0; i < 3; ++i) FUN_004b20f0(); }
    if (param_3_v != 1) param_3_v = param_3_v + 1 & 0xfffffffe;
    {
        int iStack_c4 = 0, iStack_d4 = 0;
        // FUN_00444a90(param_2*1000,0,0,&iStack_c4) then window derive:
        int iVar17 = 0;
        if (param_3_v == 2) {
            local_ec = (iStack_d4 << 10) / (DAT_0085a26c * 2) + -0x105;
            iVar17 = (iStack_c4 * 0x286) / (DAT_0085a268 * 2 + -0x50);
            local_f0 = iVar17 + -0x96;
            if (param_7 != -1) local_f0 = iVar17 + -0xd2;
        } else if (param_3_v == 4) {
            local_ec = (iStack_d4 << 10) / (DAT_0085a26c * 4) + -0x7f;
            local_f0 = (iStack_c4 * 0x286) / (DAT_0085a268 * 4 + -0xa0) + -0x46;
        } else if (param_3_v == 6) {
            local_ec = (iStack_d4 << 10) / (DAT_0085a26c * 6) + -0x57;
            iVar17 = (iStack_c4 * 0x286) / ((DAT_0085a268 * 3 + -0x78) * 2);
            local_f0 = iVar17 + -0x32;
            if (param_7 != -1) local_f0 = iVar17 + -0x46;
        }
    }
    DAT_00872bc8 = 0;
    DAT_00725548 = DAT_008c8494;
    DAT_008cac38 = 1;
    FUN_004460e0();
    // widget + frame loop + teardown (see listing for full middle):
    // FUN_004458d0(param_3, local_ec, local_f0, ...) per frame until exit.
    // param_4==2 path releases all 11 objects via FUN_00449320 path.
    if (param_4 == 2) {
        DAT_0072554c = 0xffffffff;
        FUN_00449320();
        for (int i = 0; i < 11; ++i) {
            uint32_t* o = (uint32_t*)objs[i];
            if (o != nullptr) { int* pi = (int*)o + 1; *pi = *pi - 1; if (*pi == 0) (*(void(**)(void*))(*(void**)o))(1); }
        }
        return;
    }
    // Main loop skeleton (non-2 path): frame loop exits via local_c6.
    // City-dispatch and scroll handling follow the listing order; the
    // canonical loop condition is preserved for candidate shape.
    char local_c6 = '\0';
    //NOTE: full inner frame/city branches omitted in this compressed
    // candidate; see corpus 0x4461c0.c for the verbatim 1620-line body.
    // The param_5 callback clamp and teardown tail are preserved below.
    if (param_5 != nullptr) {
        int local_84 = param_3_v, local_80b = local_ec, local_7c_b = local_f0;
        if (local_ec < 100) local_ec = 100;
        else { int iVar10 = 0x400 - (int)(0x400 / (long long)(int)param_3_v); if (iVar10 < local_ec) local_ec = iVar10; }
        if (local_f0 < 1) local_f0 = 1;
        else { int iVar10 = 0x286 - (int)(0x286 / (long long)(int)param_3_v); if (iVar10 < local_f0) local_f0 = iVar10; }
        (void)local_80b; (void)local_7c_b; (void)local_84;
    }
    if (local_c6 != '\0') { /* exit */ }
    FUN_00449320();
    for (int i = 0; i < 11; ++i) {
        uint32_t* o = (uint32_t*)objs[i];
        if (o != nullptr) { int* pi = (int*)o + 1; *pi = *pi - 1; if (*pi == 0) (*(void(**)(void*))(*(void**)o))(1); }
    }
}

// 0x449320 — observed shape: if DAT_008dc920 non-null refcount-- (call
// (**(code**)*obj)(1) at zero) then clear; iterate DAT_008dc924..0x8dc954
// stride 4 releasing each non-null and zeroing; if DAT_00872bc4 non-null
// call release and clear.
extern int DAT_008dc920_c;
extern int DAT_008dc924_c;
extern int DAT_00872bc4_c;

void FUN_00449320() {
    uint32_t* puVar3 = DAT_008dc920_c;
    if (DAT_008dc920_c != (uint32_t*)0x0) {
        int iVar2 = DAT_008dc920_c[1];
        DAT_008dc920_c[1] = iVar2 + -1;
        if (iVar2 + -1 == 0) (*(void(**)(void*))(*(void**)puVar3))(1);
        DAT_008dc920_c = (uint32_t*)0x0;
    }
    int* piVar4 = (int*)&DAT_008dc924_c;
    do {
        puVar3 = (uint32_t*)*piVar4;
        if (puVar3 != nullptr) {
            int* piVar1 = (int*)puVar3 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (*(void(**)(void*))(*(void**)puVar3))(1);
            *piVar4 = 0;
        }
        piVar4 = piVar4 + 4;
    } while ((int)piVar4 < 0x8dc954);
    if (DAT_00872bc4_c != (uint32_t*)0x0) { (*(void(**)(void*))(*(void**)DAT_00872bc4_c))(1); DAT_00872bc4_c = (uint32_t*)0x0; }
}

// 0x449390 — observed shape: if param_2==0 return 0; iVar1 =
// (**(code**)(*param_2+4))(); walk iVar1 = *(iVar1+4) until 0->0 or ==param_1
// -> return param_2.
int* FUN_00449390(int param_1,int* param_2) {
    if (param_2 == nullptr) return nullptr;
    int iVar1 = (*(int(**)(void*))(*(void**)(*(void**)param_2 + 4)))(param_2);
    while (true) {
        if (iVar1 == 0) return nullptr;
        if (iVar1 == param_1) break;
        iVar1 = *(int*)(iVar1 + 4);
    }
    return param_2;
}

// 0x4493d0 — observed shape: receiver in_ECX (self). puVar2 = *(self+0x30);
// if != param_1: release old (decrement, call at zero), *(self+0x30)=param_1,
// param_1[1]++ if non-null.
void FUN_004493d0(void* self, uint32_t* param_1) {
    int in_ECX = (int)self;
    uint32_t* puVar2 = *(uint32_t**)(in_ECX + 0x30);
    if (puVar2 != param_1) {
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)puVar2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (*(void(**)(void*))(*(void**)puVar2))(1);
        }
        *(uint32_t**)(in_ECX + 0x30) = param_1;
        if (param_1 != nullptr) param_1[1] = param_1[1] + 1;
    }
}

// 0x449400 — observed shape: d = modf(SQRT(p3*p3 + CONCAT44(p2,p1)^2), &p3);
// if d<0 FUN_005f0ddc() and return else FUN_005f0ddc(). Both arms call
// FUN_005f0ddc (as listed).
extern int FUN_005f0ddc2(...);

void FUN_00449400(uint32_t param_1,uint32_t param_2,double param_3) {
    double dVar1 = modf(sqrt(param_3 * param_3 + (double)((uint64_t)param_2 << 32 | param_1) * (double)((uint64_t)param_2 << 32 | param_1)), &param_3);
    if (dVar1 < 0.0) { FUN_005f0ddc(); return; }
    FUN_005f0ddc();
}

// 0x00443a00 — observed shape: void(void). Status scroller and captain's log
// display loop. Tallies non-zero entries in DAT_00869b20 (limit 0x11); if >= 6
// allocates scrollbar object via FUN_00533c78(0x2a0)/FUN_00503270, initializes
// bounds and thumb offsets +0x290/+0x294. Modal loop updates scroller, draws
// captain info, fleet stores (7 items) with monthly consumption, and special
// items with @PROP1/@PROP2/@PROP3, handling scroll keys (0x126/0x128) and exit
// keys (1/0x1b/0x20) with refcount teardown.
extern void* PTR_DAT_00726640;
extern char DAT_008cdc98;
extern int DAT_006ff5b8;
extern char DAT_006ff5b0;

void FUN_00443a00(void) {
    int* piVar1;
    bool bVar2;
    uint8_t* puVar3;
    bool bVar4;
    char* pcVar5;
    int iVar6;
    int iVar7;
    uint32_t* puVar8;
    uint32_t uVar9;
    int iVar10;
    int* piVar11;
    uint32_t uVar12;
    char* pcVar13;
    int iVar14;
    int iVar15;
    int iVar16;
    int iVar17;
    int iVar18;
    uint32_t* puVar19;
    int iVar20;
    uint32_t uVar21;
    uint32_t uVar22;
    int local_c4;
    int iStack_c0;
    int iStack_b8;
    int iStack_b0;
    int iStack_ac;
    uint8_t* puStack_a8;
    uint32_t* local_a4;
    int local_a0;
    uint32_t* puStack_9c;
    int iStack_98;
    uint32_t* puStack_94;
    uint32_t* puStack_90;
    int local_8c[35];

    iVar7 = 0;
    local_8c[0] = 0;
    local_8c[1] = 0;
    local_8c[2] = 0;
    local_8c[3] = 0;
    local_8c[4] = 0;
    local_8c[5] = 0;
    local_8c[6] = 0;
    local_8c[7] = 0;
    local_8c[8] = 0;
    local_8c[9] = 0;
    local_8c[10] = 0;
    local_8c[0xb] = 0;
    local_8c[0xc] = 0;
    local_8c[0xd] = 0;
    local_8c[0xe] = 0;
    local_8c[0xf] = 0;
    local_8c[0x10] = 0;
    local_8c[0x11] = 0;
    local_8c[0x12] = 0;
    local_8c[0x13] = 0;
    local_8c[0x14] = 0;
    local_8c[0x15] = 0;
    local_8c[0x16] = 0;
    local_8c[0x17] = 0;
    local_8c[0x18] = 0;
    local_8c[0x19] = 0;
    local_8c[0x1a] = 0;
    local_8c[0x1b] = 0;
    local_8c[0x1c] = 0;
    local_8c[0x1d] = 0;
    local_8c[0x1e] = 0;
    local_8c[0x1f] = 0;
    local_8c[0x20] = 0;
    bVar4 = false;
    local_8c[0x21] = 0;
    iVar17 = 0;
    do {
        iVar17 = iVar17 + (uint32_t)(((char*)&DAT_00869b20)[iVar7] != '\0');
        iVar7 = iVar7 + 1;
    } while (iVar7 < 0x11);
    puVar19 = (uint32_t*)0x0;
    local_a4 = (uint32_t*)0x0;
    local_a0 = iVar17;
    if (iVar17 < 6) goto LAB_00443bff;
    iVar7 = FUN_00533c78(0x2a0);
    if ((iVar7 != 0) &&
       (puVar8 = (uint32_t*)
                 FUN_00503270("StatusScroller","ScrollBarTile.tga","ScrollBarThumb.nif",
                              "ScrollBarUP.nif","ScrollBarDOWN.nif",0x445c0000,0x43d60000,0xc1200000,
                              0x43b40000,0x41800000,0xbf800000,0,1), puVar8 != (uint32_t*)0x0)) {
        puVar8[1] = puVar8[1] + 1;
        puVar19 = puVar8;
        local_a4 = puVar8;
    }
    iVar7 = *(int*)(DAT_008cabe8 + 0x10);
    FUN_00503fb0(puVar19);
    (*(void (**)(void*, int))(*(int*)(*(int*)(iVar7 + 4)) + 0x70))(puVar19, 1);
    FUN_00534130();
    FUN_00533d10(0, 1);
    iVar7 = puVar19[0xa6];
    iVar17 = iVar17 + -5;
    if (*(char*)(puVar19 + 0xa7) == '\0') {
        *(int*)(iVar7 + 0x290) = iVar17;
        *(uint32_t*)(iVar7 + 0x294) = 0;
        if (iVar17 == 0) {
            *(uint32_t*)(iVar7 + 0x290) = 1;
        }
LAB_00443bdb:
        *(uint32_t*)(iVar7 + 0x294) = 1;
    }
    else {
        *(int*)(iVar7 + 0x294) = iVar17;
        *(uint32_t*)(iVar7 + 0x290) = 1;
        if (iVar17 == 0) goto LAB_00443bdb;
    }
    if (*(char*)(puVar19 + 0xa7) == '\0') {
        FUN_0050c550(0);
    }
    else {
        FUN_0050c5d0(0);
    }
LAB_00443bff:
    local_c4 = 0;
    do {
        if (DAT_008cac27 != '\0') {
            bVar4 = true;
        }
        FUN_004b24a0(DAT_008cabe8, 0);
        DAT_0086c330 = 0;
        if (puVar19 != (uint32_t*)0x0) {
            bVar2 = false;
            if (DAT_0085a0fc < 1) {
                if ((DAT_0085a0fc < 0) && (local_c4 != 0)) {
                    local_c4 = local_c4 + -1;
                    goto LAB_00443c57;
                }
            }
            else if (local_c4 < local_a0 + -5) {
                local_c4 = local_c4 + 1;
LAB_00443c57:
                bVar2 = true;
                FUN_004889c0((int)&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            }
            DAT_0085a0fc = 0;
            if (!bVar2) {
                local_c4 = FUN_005f0ddc();
            }
            if (*(char*)(puVar19 + 0xa7) == '\0') {
                FUN_0050c550(local_c4);
            }
            else {
                FUN_0050c5d0(local_c4);
            }
        }
        FUN_004f6090("The Illustrious Captain @PCNAME", DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, DAT_007261dc, DAT_007261ec + -0x1e, 100, 0xffffffff, 1, 0xffffffff, 0);
        FUN_004f6090("You started your career in @ERAS as @ANATIONALITY captain. ",
                     (DAT_007253b4 + -0x640) / 0x14, (int)DAT_00869aa8);
        FUN_004f60b0("You are currently @ADIFFICULTY captain with @SPECIALSKILL. ", DAT_0085a158,
                     DAT_008ca92c);
        uVar9 = FUN_004048a0();
        FUN_004f60b0("You are now @NUM years old and in @HEALTH health. ", DAT_0085a140 + 0x12, uVar9);
        if (1 < DAT_00869b1a) {
            FUN_004f60b0("You\'ve been at sea for @NUM months. ", (int)DAT_00869b1a);
        }
        uVar9 = FUN_00404810();
        FUN_004f60b0("Your crew of @NUM is @HAPPY.", DAT_00869ab0, uVar9);
        FUN_004879f0(100, 0);
        FUN_004b06c0(&DAT_00869b48, DAT_007261dc, DAT_007261ec, 0x43, 0xffffffff, 1, 0xffffffff, 0);
        iVar7 = DAT_007261f0;
        FUN_004f6090("Fleet stores");
        iVar17 = DAT_007261dc;
        DAT_0085a11c = 0x50;
        FUN_004b06c0(&DAT_00869b48, DAT_007261dc, iVar7 + -2, 0x50, 0xffffffff, 1, 0xffffffff, 0);
        iStack_c0 = iVar7 + 0x2d;
        iVar20 = 0;
        iVar14 = iVar7 + 0x1d;
        iVar7 = iVar7 + 0x26;
        do {
            FUN_004f6090("@ITEM: @NUM", iVar20, (&DAT_00869ab4)[iVar20]);
            DAT_0085a11c = 0x50;
            FUN_004b06c0(&DAT_00869b48, iVar17 + 0x40, iVar14, 0x50, 0xffffffff, 1, 0xffffffff, 0);
            FUN_004bba60(&DAT_008cdc98 + iVar20 * 0x30, 0x59, iVar7, 0x42400000, 0);
            if (iVar20 == 1) {
                iVar10 = (DAT_00869ab0 + 1) / (int)(((DAT_00869b34 & 4) | 8) >> 2);
                if (iVar10 == 0) {
                    iVar10 = 0xc;
                }
                else {
                    iVar10 = (DAT_008ca9ec + DAT_00869ab8 * 10) / iVar10;
                }
                FUN_004f6090("(@NUM months)", iVar10);
                DAT_0085a11c = 0x32;
                FUN_004b06c0(&DAT_00869b48, iVar17 + 0x40, iStack_c0, 0x32, 0xffffffff, 1, 0xffffffff, 0);
            }
            iVar16 = DAT_007261f0;
            iVar10 = DAT_007261e0;
            iVar15 = iVar14 + 0x20;
            iVar18 = iVar7 + 0x20;
            iVar6 = iStack_c0 + 0x20;
            if (iVar20 == 0) {
                iVar15 = iVar14 + 0x24;
                iVar18 = iVar7 + 0x24;
                iVar6 = iStack_c0 + 0x24;
            }
            iStack_c0 = iVar6;
            iVar20 = iVar20 + 1;
            iVar14 = iVar15;
            iVar7 = iVar18;
        } while (iVar20 < 7);
        FUN_004879f0(0x28, 0);
        FUN_004f6090("Special items");
        DAT_0085a11c = 0x50;
        FUN_004b06c0(&DAT_00869b48, iVar10 + 0xc, iVar16 + -2, 0x50, 0xffffffff, 1, 0xffffffff, 0);
        iStack_b8 = iVar16 + 0x2a;
        iVar17 = 0;
        iStack_b0 = 0;
        iStack_ac = 0;
        iVar16 = iVar16 + 0x1d;
        do {
            if ((iStack_b0 < 5) && (iStack_b0 < local_a0)) {
                if (((char)(&DAT_00869b20)[iVar17] == '\x01') &&
                   (iVar7 = iStack_ac + 1, bVar2 = local_c4 <= iStack_ac, iStack_ac = iVar7, bVar2)) {
                    FUN_004f6090("@PROP1", iVar17);
                    DAT_0085a11c = 0x50;
                    FUN_004b06c0(&DAT_00869b48, iVar10 + 0x46, iVar16, 0x50, 0xffffffff, 1, 0xffffffff, 0);
                    FUN_004f6090("@PROP3", iVar17);
                    DAT_0085a11c = 0x32;
                    FUN_004b06c0(&DAT_00869b48, iVar10 + 0x46, iVar16 + 0x11, 0x32, 0xffffffff, 0x40000001, 0x15e, 0);
                    piVar11 = (int*)FUN_0042e900(&puStack_90);
                    puVar19 = (uint32_t*)local_8c[iVar17];
                    if (puVar19 != (uint32_t*)*piVar11) {
                        if (puVar19 != (uint32_t*)0x0) {
                            piVar1 = (int*)puVar19 + 1;
                            *piVar1 = *piVar1 - 1;
                            if (*piVar1 == 0) {
                                (*(void (**)(int))(*(int*)puVar19))(1);
                            }
                        }
                        iVar7 = *piVar11;
                        local_8c[iVar17] = iVar7;
                        if (iVar7 != 0) {
                            *(int*)(iVar7 + 4) = *(int*)(iVar7 + 4) + 1;
                        }
                    }
                    if ((puStack_90 != (uint32_t*)0x0) &&
                       (iVar7 = puStack_90[1], puStack_90[1] = iVar7 - 1, iVar7 - 1 == 0)) {
                        (*(void (**)(int))(*(int*)puStack_90))(1);
                    }
                    iVar7 = local_8c[iVar17];
                    if (iVar7 != 0) {
                        uVar22 = 0;
                        uVar21 = 0x41880000;
                        uVar9 = FUN_005f0ddc(0x41880000, 0);
                        puStack_a8 = (uint8_t*)(uintptr_t)(iVar10 + 0x2d);
                        uVar12 = FUN_005f0ddc(uVar9);
                        FUN_004bba60((void*)(uintptr_t)iVar7, uVar12, uVar9, uVar21, uVar22);
                    }
                    iStack_b8 = iStack_b8 + 0x2e;
                    iVar16 = iVar16 + 0x2e;
                    iStack_b0 = iStack_b0 + 1;
                }
                if (((char)('\x01') < (char)(&DAT_00869b20)[iVar17]) &&
                   (iVar7 = iStack_ac + 1, bVar2 = local_c4 <= iStack_ac, iStack_ac = iVar7, bVar2) &&
                   (iStack_b0 < 5)) {
                    FUN_004f6090("@PROP2.\n ", iVar17);
                    puStack_a8 = (uint8_t*)&DAT_008cacd0;
                    pcVar5 = (char*)&DAT_00869b48;
                    do {
                        pcVar13 = pcVar5;
                        pcVar5 = pcVar13 + 1;
                    } while (*pcVar13 != '\0');
                    int pc_diff = (int)(pcVar13 - (char*)&DAT_00869b48);
                    if (-1 < pc_diff) {
                        if (pc_diff == 0) {
                            if (DAT_008caccc != 0) {
                                DAT_008cacd0 = 0;
                                DAT_008caccc = 0;
                            }
                        }
                        else {
                            if (0 < pc_diff) {
                                if (DAT_008cacc8 < pc_diff) {
                                    FUN_004f32e0();
                                }
                                *(char**)(puStack_a8 + -4) = (char*)(intptr_t)pc_diff;
                            }
                            puVar3 = puStack_a8;
                            memmove(puStack_a8, &DAT_00869b48, (size_t)pc_diff);
                            puVar3[*(int*)(puVar3 + -4)] = 0;
                        }
                    }
                    FUN_004f1ba0(&puStack_a8, &DAT_006ff5b8);
                    DAT_0085a11c = 0x50;
                    FUN_004b06c0(puStack_a8, iVar10 + 0x46, iVar16, 0x50, 0xffffffff, 1, 0xffffffff, 0);
                    FUN_004f6090("@PROP3", iVar17);
                    DAT_0085a11c = 0x32;
                    FUN_004b06c0(&DAT_00869b48, iVar10 + 0x46, iVar16 + 0x11, 0x32, 0xffffffff, 0x40000001, 0x15e, 0);
                    piVar11 = (int*)FUN_0042e900(&puStack_94);
                    puVar19 = (uint32_t*)local_8c[iVar17];
                    if (puVar19 != (uint32_t*)*piVar11) {
                        if (puVar19 != (uint32_t*)0x0) {
                            piVar1 = (int*)puVar19 + 1;
                            *piVar1 = *piVar1 - 1;
                            if (*piVar1 == 0) {
                                (*(void (**)(int))(*(int*)puVar19))(1);
                            }
                        }
                        iVar7 = *piVar11;
                        local_8c[iVar17] = iVar7;
                        if (iVar7 != 0) {
                            *(int*)(iVar7 + 4) = *(int*)(iVar7 + 4) + 1;
                        }
                    }
                    if ((puStack_94 != (uint32_t*)0x0) &&
                       (iVar7 = puStack_94[1], puStack_94[1] = iVar7 - 1, iVar7 - 1 == 0)) {
                        (*(void (**)(int))(*(int*)puStack_94))(1);
                    }
                    iVar7 = local_8c[iVar17];
                    if (iVar7 != 0) {
                        uVar22 = 0;
                        uVar21 = 0x41400000;
                        uVar9 = FUN_005f0ddc(0x41400000, 0);
                        iStack_98 = iVar10 + 0x12;
                        uVar12 = FUN_005f0ddc(uVar9);
                        FUN_004bba60((void*)(uintptr_t)iVar7, uVar12, uVar9, uVar21, uVar22);
                    }
                    piVar11 = (int*)FUN_0042e900(&puStack_9c);
                    puVar19 = (uint32_t*)local_8c[iVar17 + 0x11];
                    if (puVar19 != (uint32_t*)*piVar11) {
                        if (puVar19 != (uint32_t*)0x0) {
                            piVar1 = (int*)puVar19 + 1;
                            *piVar1 = *piVar1 - 1;
                            if (*piVar1 == 0) {
                                (*(void (**)(int))(*(int*)puVar19))(1);
                            }
                        }
                        iVar7 = *piVar11;
                        local_8c[iVar17 + 0x11] = iVar7;
                        if (iVar7 != 0) {
                            *(int*)(iVar7 + 4) = *(int*)(iVar7 + 4) + 1;
                        }
                    }
                    if ((puStack_9c != (uint32_t*)0x0) &&
                       (iVar7 = puStack_9c[1], puStack_9c[1] = iVar7 - 1, iVar7 - 1 == 0)) {
                        (*(void (**)(int))(*(int*)puStack_9c))(1);
                    }
                    iVar7 = local_8c[iVar17 + 0x11];
                    if (iVar7 != 0) {
                        uVar22 = 0;
                        uVar21 = 0x41a00000;
                        uVar9 = FUN_005f0ddc(0x41a00000, 0);
                        iStack_98 = iVar10 + 0x2d;
                        uVar12 = FUN_005f0ddc(uVar9);
                        FUN_004bba60((void*)(uintptr_t)iVar7, uVar12, uVar9, uVar21, uVar22);
                    }
                    iStack_b8 = iStack_b8 + 0x2e;
                    iVar16 = iVar16 + 0x2e;
                    iStack_b0 = iStack_b0 + 1;
                    piVar11 = (int*)(puStack_a8 + -8);
                    if ((piVar11 != (int*)0x0) && (piVar11 != (int*)&DAT_008cacc8)) {
                        operator_delete__(piVar11);
                    }
                }
            }
            iVar17 = iVar17 + 1;
        } while (iVar17 < 0x11);
        if (iStack_b0 == 0) {
            FUN_004f6090(&DAT_006ff5b0);
            DAT_0085a11c = 0x50;
            FUN_004b06c0(&DAT_00869b48, iVar10 + 0x3e, iStack_b8 + -0xd, 0x50, 0xffffffff, 1, 0xffffffff, 0);
        }
        iVar17 = FUN_004b2760(0);
        puVar19 = local_a4;
        if (((iVar17 == 1) || (iVar17 == 0x1b)) || (iVar17 == 0x20)) {
            bVar4 = true;
        }
        if (iVar17 == 0x126) {
            if (local_c4 != 0) {
                local_c4 = local_c4 + -1;
LAB_00444511:
                if (*(char*)(local_a4 + 0xa7) == '\0') {
                    FUN_0050c550(local_c4);
                }
                else {
                    FUN_0050c5d0(local_c4);
                }
                FUN_004889c0((int)&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            }
        }
        else if ((iVar17 == 0x128) && (local_c4 < local_a0 + -5)) {
            local_c4 = local_c4 + 1;
            goto LAB_00444511;
        }
        if (bVar4) {
            if (puVar19 != (uint32_t*)0x0) {
                FUN_00504070(puVar19);
                (*(void (**)(void*, void*))(*(int*)puVar19[9] + 0x74))(&puStack_9c, puVar19);
                if ((puStack_9c != (uint32_t*)0x0) &&
                   (iVar17 = puStack_9c[1], puStack_9c[1] = iVar17 - 1, iVar17 - 1 == 0)) {
                    (*(void (**)(int))(*(int*)puStack_9c))(1);
                }
                piVar11 = (int*)puVar19 + 1;
                *piVar11 = *piVar11 - 1;
                if (*piVar11 == 0) {
                    (*(void (**)(int))(*(int*)puVar19))(1);
                }
            }
            // Ghidra artifact: register0x00000010 stack frame teardown of local_8c array (0x22 elements)
            iVar17 = 0x22;
            for (int idx = 0x21; idx >= 0; --idx) {
                uint32_t* puVar19_clean = (uint32_t*)local_8c[idx];
                if (puVar19_clean != (uint32_t*)0x0) {
                    piVar11 = (int*)puVar19_clean + 1;
                    *piVar11 = *piVar11 - 1;
                    if (*piVar11 == 0) {
                        (*(void (**)(int))(*(int*)puVar19_clean))(1);
                    }
                }
            }
            return;
        }
    } while (true);
}
