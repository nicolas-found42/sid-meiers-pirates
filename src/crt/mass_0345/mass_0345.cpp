#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the translated listings.
// ---------------------------------------------------------------------------
extern void FUN_00513ce0(void);
extern int FUN_006923f0(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                        uint32_t param_4, uint32_t param_5, uint32_t param_6);
extern void FUN_006ac7f0(void);
extern void FUN_006ac8d0(void);
extern void FUN_006ac9f0(void);

extern uint8_t LAB_005b6900[];

// 0x6acb30 — observed shape
// The provider resolves the source row pointer through an absolute address
// (param_3 * 4 + table entry); that base is preserved verbatim.
void FUN_006acb30(void* self, const int* param_2, int param_3, int* param_4, int param_5)
{
    const int rowCount = *(const int*)((char*)self + 0x24);
    const int depth = *(const int*)((char*)self + 0x70);
    int byteOffset = param_3 << 2;

    if (param_5 - 1 < 0) return;
    do {
        int iVar6 = 0;
        if (rowCount > 0) {
            uint8_t* dstBase = (uint8_t*)*param_4;
            do {
                uint8_t* src = *(uint8_t**)(uintptr_t)(byteOffset + param_2[iVar6]);
                uint8_t* dst = dstBase + iVar6;
                for (int iVar7 = depth; iVar7 != 0; iVar7 = iVar7 - 1) {
                    *dst = *src;
                    src = src + 1;
                    dst = dst + rowCount;
                }
                iVar6 = iVar6 + 1;
            } while (iVar6 < rowCount);
        }
        byteOffset = byteOffset + 4;
        param_4 = param_4 + 1;
        param_5 = param_5 - 1;
    } while (param_5 != 0);
}

// 0x6acbc0 — observed shape
void FUN_006acbc0(void* self, uint32_t* param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5)
{
    FUN_006923f0(*param_2, param_3, param_4, 0, param_5,
                 *(uint32_t*)((char*)self + 0x70));
}

// 0x6acbf0 — observed shape
void FUN_006acbf0(void* self, int* param_2, int param_3, uint8_t** param_4, int param_5)
{
    const uint32_t depth = *(uint32_t*)((char*)self + 0x70);

    if (param_5 - 1 < 0) return;
    int* rowPtr = (int*)(*param_2 + param_3 * 4);
    int rows = param_5;
    do {
        int srcRow = *rowPtr;
        uint8_t* dst = *param_4;
        param_4 = param_4 + 1;
        rowPtr = rowPtr + 1;
        uint32_t i = 0;
        if (depth != 0) {
            do {
                uint8_t v = *(uint8_t*)(uintptr_t)(i + srcRow);
                dst[2] = v;
                dst[1] = v;
                dst[0] = v;
                dst = dst + 3;
                i = i + 1;
            } while (i < depth);
        }
        rows = rows - 1;
    } while (rows != 0);
}

// 0x6acc50 — observed shape
void FUN_006acc50(void* self, uint8_t** param_2, int param_3, uint8_t** param_4, int param_5)
{
    int* ctx = *(int**)((char*)self + 0x1cc);
    const int depth = *(int*)((char*)self + 0x70);
    const int paletteBase = *(int*)((char*)self + 0x148);
    const int tbl0 = *(int*)((char*)ctx + 0x8);
    const int tbl1 = *(int*)((char*)ctx + 0xc);
    const int tbl2 = *(int*)((char*)ctx + 0x10);
    const int tbl3 = *(int*)((char*)ctx + 0x14);

    if (param_5 - 1 < 0) return;
    const int p1 = (int)(uintptr_t)param_2[1];
    const int p2 = (int)(uintptr_t)param_2[2];
    const int p0 = (int)(uintptr_t)param_2[0];
    const int p3 = (int)(uintptr_t)param_2[3];
    uint32_t* rowPtr = (uint32_t*)(uintptr_t)(p1 + param_3 * 4);
    int rows = param_5;
    do {
        int* qa = (int*)(uintptr_t)((p0 - p1) + (int)(uintptr_t)rowPtr);
        int* qb = (int*)(uintptr_t)((p2 - p1) + (int)(uintptr_t)rowPtr);
        int* qc = (int*)(uintptr_t)((p3 - p1) + (int)(uintptr_t)rowPtr);
        uint8_t* src = (uint8_t*)*rowPtr;
        uint8_t* dst = *param_4;
        param_4 = param_4 + 1;
        rowPtr = rowPtr + 1;
        if (depth != 0) {
            const int offA = *qa - (int)(uintptr_t)src;
            const int offB = *qb - (int)(uintptr_t)src;
            const int offC = *qc - (int)(uintptr_t)src;
            int n = depth;
            for (;;) {
                uint32_t u = src[offA];
                uint8_t b = src[offB];
                dst[0] = *(uint8_t*)(uintptr_t)
                    (((paletteBase - *(int*)(tbl0 + (uint32_t)b * 4)) - u) + 0xff);
                dst[1] = *(uint8_t*)(uintptr_t)
                    (((paletteBase - (*(int*)(tbl3 + (uint32_t)*src * 4) +
                                       *(int*)(tbl2 + (uint32_t)b * 4) >> 0x10)) - u) + 0xff);
                dst[2] = *(uint8_t*)(uintptr_t)
                    (((paletteBase - *(int*)(tbl1 + (uint32_t)*src * 4)) - u) + 0xff);
                dst[3] = src[offC];
                src = src + 1;
                if (--n == 0) break;
                dst = dst + 4;
            }
        }
        rows = rows - 1;
    } while (rows != 0);
}

// 0x6acd90 — observed shape
// Ten 256-entry ramp tables are allocated through the interface stored at
// self+4 and then filled; all index arithmetic is relative to the table at
// ctx+0x1c.
void FUN_006acd90(void* self)
{
    int* ctx = *(int**)((char*)self + 0x1cc);
    int (*alloc)(void*) = *(int (**)(void*))*(void**)((char*)self + 4);

    *(int*)((char*)ctx + 0x18) = alloc(self);
    *(int*)((char*)ctx + 0x1c) = alloc(self);
    *(int*)((char*)ctx + 0x20) = alloc(self);
    *(int*)((char*)ctx + 0x24) = alloc(self);
    *(int*)((char*)ctx + 0x28) = alloc(self);
    *(int*)((char*)ctx + 0x2c) = alloc(self);
    *(int*)((char*)ctx + 0x30) = alloc(self);
    *(int*)((char*)ctx + 0x34) = alloc(self);
    *(int*)((char*)ctx + 0x38) = alloc(self);
    *(int*)((char*)ctx + 0x3c) = alloc(self);

    uint32_t* base = *(uint32_t**)((char*)ctx + 0x1c);
    const int off18 = *(int*)((char*)ctx + 0x18) - (int)(uintptr_t)base;
    const int off20 = *(int*)((char*)ctx + 0x20) - (int)(uintptr_t)base;
    const int off24 = *(int*)((char*)ctx + 0x24) - (int)(uintptr_t)base;
    const int off28 = *(int*)((char*)ctx + 0x28) - (int)(uintptr_t)base;
    const int off2c = *(int*)((char*)ctx + 0x2c) - (int)(uintptr_t)base;
    const int off30 = *(int*)((char*)ctx + 0x30) - (int)(uintptr_t)base;
    const int off34 = *(int*)((char*)ctx + 0x34) - (int)(uintptr_t)base;
    const int off38 = *(int*)((char*)ctx + 0x38) - (int)(uintptr_t)base;
    const int off3c = *(int*)((char*)ctx + 0x3c) - (int)(uintptr_t)base;

    int local_40 = 0xfe81;
    int local_3c = 0xfe81;
    int local_38 = 0xfe81;
    int local_34 = 0xfe81;
    int local_30 = 0xfe81;
    int local_2c = 0xfe81;
    int local_28 = 0xfe81;
    int local_24 = -0x4a24e1;
    int local_20 = -0x447a1;
    int local_1c = -0x2153e1;
    int local_18 = -0x569fe1;
    int local_14 = -0x165be1;
    int local_10 = -0x8f6e1;
    int local_c = -0x1812a1;
    int local_8 = -0x4b5fe1;
    int iVar13 = -0x41cfe1;
    int iVar14 = 0xfe81;

    do {
        int v;
        if (iVar14 < 0x5742) v = 0x57c0 - iVar13 / 0x3f;
        else v = iVar14;
        *(int*)((char*)base + off18) = v;

        if (iVar14 < 0x5742) v = 0x6480 - local_8 / 0x3f;
        else v = local_28;
        *base = (uint32_t)(v * 0x10101) >> 0x10;

        if (iVar14 < 0x5742) v = 0xb880 - local_c / 0x3f;
        else v = local_2c;
        *(uint32_t*)((char*)base + off20) = (uint32_t)(v * 0x10101) >> 0x10;

        if (iVar14 < 0x5742) v = 0xff00 - local_10 / 0x3f;
        else v = 0xfe81;
        *(uint32_t*)((char*)base + off24) = (uint32_t)(v * 0x10101) >> 0x10;

        if (iVar14 < 0x5742) v = 0xed00 - local_14 / 0x3f;
        else v = local_30;
        *(uint32_t*)((char*)base + off28) = (uint32_t)(v * 0x10101) >> 0x10;

        if (iVar14 < 0x5742) v = 0x7380 - local_18 / 0x3f;
        else v = local_34;
        *(uint32_t*)((char*)base + off2c) = (uint32_t)(v * 0x10101) >> 0x10;

        if (iVar14 < 0x5742) v = 0x9c00 - local_1c / 0x3f;
        else v = local_38;
        *(uint32_t*)((char*)base + off30) = (uint32_t)(v * 0x10101) >> 0x10;

        *(uint32_t*)((char*)base + off34) =
            (uint32_t)(((((iVar14 < 0x5742) - 1) & 0xffffff81) + 0xff00) * 0x10101) >> 0x10;

        if (iVar14 < 0x5742) v = 0xf9c0 - local_20 / 0x3f;
        else v = local_3c;
        *(uint32_t*)((char*)base + off38) = (uint32_t)(v * 0x10101) >> 0x10;

        if (iVar14 < 0x5742) v = 0x7ec0 - local_24 / 0x3f;
        else v = local_40;
        *(uint32_t*)((char*)base + off3c) = (uint32_t)(v * 0x10101) >> 0x10;

        local_28 = local_28 + -0xce;
        local_8 = local_8 + 0x6480;
        local_2c = local_2c + -0x5e;
        local_c = local_c + 0x2019;
        local_10 = local_10 + 0xbf4;
        local_30 = local_30 + -0x18;
        local_14 = local_14 + 0x1dd0;
        local_34 = local_34 + -0xba;
        local_18 = local_18 + 0x7380;
        local_38 = local_38 + -0x84;
        local_1c = local_1c + 0x2c70;
        local_3c = local_3c + -7;
        local_20 = local_20 + 0x5b5;
        iVar14 = iVar14 + -0xdf;
        local_40 = local_40 + -0xab;
        local_24 = local_24 + 0x62dc;
        iVar13 = iVar13 + 0x57c0;
        base = base + 1;
    } while (0x205f < iVar14);
}

// 0x6ad1b0 — observed shape
void FUN_006ad1b0(void* self, uint8_t** param_2, int param_3, uint8_t** param_4, int param_5)
{
    int* ctx = *(int**)((char*)self + 0x1cc);
    const int t18 = *(int*)((char*)ctx + 0x18);
    const int depth = *(int*)((char*)self + 0x70);
    const int t1c = *(int*)((char*)ctx + 0x1c);
    const int t20 = *(int*)((char*)ctx + 0x20);
    const int t24 = *(int*)((char*)ctx + 0x24);
    const int t28 = *(int*)((char*)ctx + 0x28);
    const int t2c = *(int*)((char*)ctx + 0x2c);
    const int t30 = *(int*)((char*)ctx + 0x30);
    const int t34 = *(int*)((char*)ctx + 0x34);
    const int t38 = *(int*)((char*)ctx + 0x38);
    const int t3c = *(int*)((char*)ctx + 0x3c);

    if (param_5 - 1 < 0) return;
    const int q1 = (int)(uintptr_t)param_2[1];
    const int q2 = (int)(uintptr_t)param_2[2];
    const int q0 = (int)(uintptr_t)param_2[0];
    const int q3 = (int)(uintptr_t)param_2[3];
    uint32_t* rowPtr = (uint32_t*)(uintptr_t)(q1 + param_3 * 4);
    int rows = param_5;
    do {
        int* qa = (int*)(uintptr_t)((q2 - q1) + (int)(uintptr_t)rowPtr);
        int* qb = (int*)(uintptr_t)((q3 - q1) + (int)(uintptr_t)rowPtr);
        uint8_t* dst = *param_4;
        int* qc = (int*)(uintptr_t)((q0 - q1) + (int)(uintptr_t)rowPtr);
        uint8_t* src = (uint8_t*)*rowPtr;
        param_4 = param_4 + 1;
        rowPtr = rowPtr + 1;
        if (depth != 0) {
            const int offY = *qc - (int)(uintptr_t)src;
            const int offA = *qa - (int)(uintptr_t)src;
            const int offB = *qb - (int)(uintptr_t)src;
            int n = depth;
            for (;;) {
                int a = 0xff - (uint32_t)src[offY];
                int b = 0xff - (uint32_t)*src;
                int c = 0xff - (uint32_t)src[offA];
                int d = *(int*)(t18 + (0xff - (uint32_t)src[offB]) * 4);
                dst[0] = (uint8_t)((((uint32_t)(*(int*)(t1c + a * 4) * d) >> 0x10) *
                                    *(int*)(t28 + b * 4) >> 0x10) *
                                   *(int*)(t34 + c * 4) >> 0x18);
                dst[1] = (uint8_t)((((uint32_t)(*(int*)(t2c + b * 4) * d) >> 0x10) *
                                    *(int*)(t38 + c * 4) >> 0x10) *
                                   *(int*)(t20 + a * 4) >> 0x18);
                dst[2] = (uint8_t)((((uint32_t)(*(int*)(t3c + c * 4) * d) >> 0x10) *
                                    *(int*)(t24 + a * 4) >> 0x10) *
                                   *(int*)(t30 + b * 4) >> 0x18);
                src = src + 1;
                n = n - 1;
                if (n == 0) break;
                dst = dst + 3;
            }
        }
        rows = rows - 1;
    } while (rows != 0);
}

// 0x6ad360 — observed shape
void FUN_006ad360(void* self, uint8_t** param_2, int param_3, uint8_t** param_4, int param_5)
{
    int* ctx = *(int**)((char*)self + 0x1cc);
    const int t18 = *(int*)((char*)ctx + 0x18);
    const int t1c = *(int*)((char*)ctx + 0x1c);
    const int t20 = *(int*)((char*)ctx + 0x20);
    const int t24 = *(int*)((char*)ctx + 0x24);
    const int t28 = *(int*)((char*)ctx + 0x28);
    const int t2c = *(int*)((char*)ctx + 0x2c);
    const int t30 = *(int*)((char*)ctx + 0x30);
    const int t34 = *(int*)((char*)ctx + 0x34);
    const int t38 = *(int*)((char*)ctx + 0x38);
    const int t3c = *(int*)((char*)ctx + 0x3c);
    const int u0 = *(int*)((char*)ctx + 0x8);
    const int u1 = *(int*)((char*)ctx + 0xc);
    const int u2 = *(int*)((char*)ctx + 0x10);
    const int u3 = *(int*)((char*)ctx + 0x14);
    const int depth = *(int*)((char*)self + 0x70);
    const int paletteBase = *(int*)((char*)self + 0x148);

    if (param_5 - 1 < 0) return;
    const int q1 = (int)(uintptr_t)param_2[1];
    const int q2 = (int)(uintptr_t)param_2[2];
    const int q0 = (int)(uintptr_t)param_2[0];
    const int q3 = (int)(uintptr_t)param_2[3];
    uint32_t* rowPtr = (uint32_t*)(uintptr_t)(q1 + param_3 * 4);
    int rows = param_5;
    do {
        int* qa = (int*)(uintptr_t)((q2 - q1) + (int)(uintptr_t)rowPtr);
        int* qb = (int*)(uintptr_t)((q3 - q1) + (int)(uintptr_t)rowPtr);
        uint8_t* src = (uint8_t*)*rowPtr;
        int* qc = (int*)(uintptr_t)((q0 - q1) + (int)(uintptr_t)rowPtr);
        uint8_t* dst = *param_4;
        param_4 = param_4 + 1;
        rowPtr = rowPtr + 1;
        if (depth != 0) {
            const int offY = *qc - (int)(uintptr_t)src;
            const int offA = *qa - (int)(uintptr_t)src;
            const int offB = *qb - (int)(uintptr_t)src;
            int n = depth;
            do {
                uint32_t y = src[offY];
                uint32_t r = *(uint8_t*)(uintptr_t)
                    (*(int*)(u0 + (uint32_t)src[offA] * 4) + y + paletteBase);
                uint32_t g = *(uint8_t*)(uintptr_t)
                    ((*(int*)(u3 + (uint32_t)*src * 4) +
                      *(int*)(u2 + (uint32_t)src[offA] * 4) >> 0x10) + y + paletteBase);
                uint32_t b = *(uint8_t*)(uintptr_t)
                    (*(int*)(u1 + (uint32_t)*src * 4) + y + paletteBase);
                int d = *(int*)(t18 + (0xff - (uint32_t)src[offB]) * 4);
                dst[0] = (uint8_t)((((uint32_t)(*(int*)(t1c + r * 4) * d) >> 0x10) *
                                    *(int*)(t28 + g * 4) >> 0x10) *
                                   *(int*)(t34 + b * 4) >> 0x18);
                dst[1] = (uint8_t)((((uint32_t)(*(int*)(t2c + g * 4) * d) >> 0x10) *
                                    *(int*)(t38 + b * 4) >> 0x10) *
                                   *(int*)(t20 + r * 4) >> 0x18);
                dst[2] = (uint8_t)((((uint32_t)(*(int*)(t3c + b * 4) * d) >> 0x10) *
                                    *(int*)(t24 + r * 4) >> 0x10) *
                                   *(int*)(t30 + g * 4) >> 0x18);
                dst = dst + 3;
                src = src + 1;
                n = n - 1;
            } while (n != 0);
        }
        rows = rows - 1;
    } while (rows != 0);
}

// 0x6ad560 — observed shape
void FUN_006ad560(int* self)
{
    int (*alloc)(int*, int, int) = *(int (**)(int*, int, int))(void*)self[1];
    uintptr_t* entry = (uintptr_t*)alloc(self, 1, 0x40);
    int iVar3 = self[10];
    self[0x73] = (int)(uintptr_t)entry;
    entry[0] = (uintptr_t)&FUN_00513ce0;

    switch (iVar3) {
    case 1:
        if (self[9] != 1) goto LAB_006ad5b0;
        break;
    case 2:
    case 3:
        if (self[9] != 3) goto LAB_006ad5b0;
        break;
    case 4:
    case 5:
        if (self[9] != 4) goto LAB_006ad5b0;
        break;
    default:
        if (self[9] < 1) goto LAB_006ad5b0;
    }

    iVar3 = self[0xb];
    if (iVar3 == 1) {
        self[0x1e] = 1;
        if ((self[10] == 1) || (self[10] == 3)) {
            iVar3 = self[9];
            entry[1] = (uintptr_t)&FUN_006acbc0;
            if (iVar3 > 1) {
                uintptr_t* p = (uintptr_t*)(uintptr_t)(self[0x37] + 0x84);
                iVar3 = self[9] + -1;
                do {
                    *p = 0;
                    p = p + 0x15;
                    iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
            }
            goto LAB_006ad6fd;
        }
    }
    else if (iVar3 == 2) {
        iVar3 = self[10];
        self[0x1e] = 3;
        if (iVar3 == 3) {
            if ((self[0x12] == 5) || (self[0x12] == 6)) {
                entry[1] = (uintptr_t)&FUN_006ac9f0;
                FUN_006ac7f0();
            }
            else {
                entry[1] = (uintptr_t)&FUN_006ac8d0;
                FUN_006ac7f0();
            }
            goto LAB_006ad6fd;
        }
        if (iVar3 == 1) {
            entry[1] = (uintptr_t)&FUN_006acbf0;
            goto LAB_006ad6fd;
        }
        if (iVar3 == 2) {
            entry[1] = (uintptr_t)&FUN_006acb30;
            goto LAB_006ad6fd;
        }
        if (iVar3 == 4) {
            entry[1] = (uintptr_t)&FUN_006ad1b0;
            FUN_006acd90(self);
            goto LAB_006ad6fd;
        }
        if (iVar3 == 5) {
            entry[1] = (uintptr_t)&FUN_006ad360;
            FUN_006ac7f0();
            FUN_006acd90(self);
            goto LAB_006ad6fd;
        }
    }
    else if (iVar3 == 4) {
        self[0x1e] = 4;
        if (self[10] == 5) {
            entry[1] = (uintptr_t)&FUN_006acc50;
            FUN_006ac7f0();
            goto LAB_006ad6fd;
        }
        if (self[10] == 4) {
            entry[1] = (uintptr_t)&FUN_006acb30;
            goto LAB_006ad6fd;
        }
    }
    else if (iVar3 == self[10]) {
        self[0x1e] = self[9];
        entry[1] = (uintptr_t)&FUN_006acb30;
        goto LAB_006ad6fd;
    }

LAB_006ad5b0:
    {
        int* vtable = (int*)(uintptr_t)*self;
        vtable[5] = 0x1b;
        (*(void (**)(int*))(uintptr_t)vtable[0])(self);
    }

LAB_006ad6fd:
    if (self[0x15] == 0) {
        self[0x1f] = self[0x1e];
        return;
    }
    self[0x1f] = 1;
}

// 0x6ad740 — observed shape
void FUN_006ad740(void* self)
{
    int* ctx = *(int**)((char*)self + 0x1c8);
    int (*alloc)(void*) = *(int (**)(void*))*(void**)((char*)self + 4);

    *(int*)((char*)ctx + 0x10) = alloc(self);
    *(int*)((char*)ctx + 0x14) = alloc(self);
    *(int*)((char*)ctx + 0x18) = alloc(self);
    int iVar3 = alloc(self);
    int* piVar5 = *(int**)((char*)ctx + 0x14);
    *(int*)((char*)ctx + 0x1c) = iVar3;
    int iVar9 = *(int*)((char*)ctx + 0x18) - (int)(uintptr_t)piVar5;
    int iVar4 = *(int*)((char*)ctx + 0x10) - (int)(uintptr_t)piVar5;
    iVar3 = iVar3 - (int)(uintptr_t)piVar5;
    uint8_t* local_8 = LAB_005b6900;
    int iVar7 = -0xe25100;
    int iVar8 = -0xb2f480;
    int iVar6 = 0x2c8d00;
    do {
        *(int*)((char*)piVar5 + iVar4) = iVar8 >> 0x10;
        *piVar5 = iVar7 >> 0x10;
        *(uint8_t**)((char*)piVar5 + iVar9) = local_8;
        *(int*)((char*)piVar5 + iVar3) = iVar6;
        local_8 = local_8 - 0xb6d2;
        iVar6 = iVar6 + -0x581a;
        iVar8 = iVar8 + 0x166e9;
        iVar7 = iVar7 + 0x1c5a2;
        piVar5 = piVar5 + 1;
    } while (-0x2b34e7 < iVar6);
}

// 0x6ad820 — observed shape
void FUN_006ad820(void* self)
{
    int* ctx = *(int**)((char*)self + 0x1c8);
    uint32_t uVar2 = *(uint32_t*)((char*)self + 0x74);
    *(uint32_t*)((char*)ctx + 0x24) = 0;
    *(uint32_t*)((char*)ctx + 0x2c) = uVar2;
}

// 0x6ad840 — observed shape
void FUN_006ad840(void* self, uint32_t param_2, int* param_3, uint32_t param_4, int param_5,
                  int* param_6, int param_7)
{
    int* ctx = *(int**)((char*)self + 0x1c8);
    uint32_t uVar4;
    uint32_t local_c;
    uint32_t local_8;

    if (*(int*)((char*)ctx + 0x24) == 0) {
        uVar4 = 2;
        if (*(uint32_t*)((char*)ctx + 0x2c) < 2) {
            uVar4 = *(uint32_t*)((char*)ctx + 0x2c);
        }
        int iVar2 = *param_6;
        if ((uint32_t)(param_7 - iVar2) < uVar4) {
            uVar4 = (uint32_t)(param_7 - iVar2);
        }
        local_c = *(uint32_t*)(uintptr_t)(param_5 + iVar2 * 4);
        if (uVar4 < 2) {
            local_8 = *(uint32_t*)((char*)ctx + 0x20);
            *(uint32_t*)((char*)ctx + 0x24) = 1;
        }
        else {
            local_8 = *(uint32_t*)(uintptr_t)(param_5 + 4 + iVar2 * 4);
        }
        (*(void (**)(void*, uint32_t, int, uint32_t*))(uintptr_t)
            *(uint32_t*)((char*)ctx + 0xc))(self, param_2, *param_3, &local_c);
    }
    else {
        FUN_006923f0((uint32_t)(uintptr_t)((char*)ctx + 0x20), 0,
                     (uint32_t)(param_5 + *param_6 * 4), 0, 1,
                     *(uint32_t*)((char*)ctx + 0x28));
        uVar4 = 1;
        *(uint32_t*)((char*)ctx + 0x24) = 0;
    }
    int iVar2 = *param_6;
    int iVar3 = *(int*)((char*)ctx + 0x24);
    *(uint32_t*)((char*)ctx + 0x2c) = *(int*)((char*)ctx + 0x2c) - uVar4;
    *param_6 = iVar2 + (int)uVar4;
    if (iVar3 == 0) {
        *param_3 = *param_3 + 1;
    }
}

// 0x6ad910 — observed shape
void FUN_006ad910(void* self, uint32_t param_2, int* param_3, uint32_t param_4, int param_5,
                  int* param_6)
{
    int* ctx = *(int**)((char*)self + 0x1c8);

    (*(void (**)(void*, uint32_t, int, uint32_t))(uintptr_t)
        *(uint32_t*)((char*)ctx + 0xc))(self, param_2, *param_3,
                                        (uint32_t)(param_5 + *param_6 * 4));
    int iVar1 = *param_6;
    *param_3 = *param_3 + 1;
    *param_6 = iVar1 + 1;
}

// 0x6ad950 — observed shape
void FUN_006ad950(void* self, int* param_2, int param_3, uint8_t** param_4)
{
    int* ctx = *(int**)((char*)self + 0x1c8);
    const int paletteBase = *(int*)((char*)self + 0x148);
    const uint32_t depth = *(uint32_t*)((char*)self + 0x70);
    const int t10 = *(int*)((char*)ctx + 0x10);
    const int t14 = *(int*)((char*)ctx + 0x14);
    const int t18 = *(int*)((char*)ctx + 0x18);
    const int t1c = *(int*)((char*)ctx + 0x1c);

    uint8_t* yRow = *(uint8_t**)(uintptr_t)(*param_2 + param_3 * 4);
    uint8_t* uRow = *(uint8_t**)(uintptr_t)(param_2[1] + param_3 * 4);
    uint8_t* vRow = *(uint8_t**)(uintptr_t)(param_2[2] + param_3 * 4);
    uint8_t* dst = *param_4;
    uint32_t n = depth >> 1;
    if (n != 0) {
        do {
            uint8_t b1 = *uRow;
            uint8_t b2 = *vRow;
            uRow = uRow + 1;
            vRow = vRow + 1;
            int iVar9 = *(int*)(t10 + (uint32_t)b2 * 4);
            int iVar16 = *(int*)(t1c + (uint32_t)b1 * 4);
            int iVar10 = *(int*)(t18 + (uint32_t)b2 * 4);
            int iVar11 = *(int*)(t14 + (uint32_t)b1 * 4);
            uint32_t yv = *yRow;
            dst[0] = *(uint8_t*)(uintptr_t)(iVar9 + yv + paletteBase);
            iVar16 = iVar16 + iVar10 >> 0x10;
            dst[1] = *(uint8_t*)(uintptr_t)(yv + iVar16 + paletteBase);
            dst[2] = *(uint8_t*)(uintptr_t)(yv + iVar11 + paletteBase);
            yv = yRow[1];
            dst[3] = *(uint8_t*)(uintptr_t)(iVar9 + yv + paletteBase);
            uint8_t tmp = *(uint8_t*)(uintptr_t)(iVar16 + yv + paletteBase);
            dst[5] = *(uint8_t*)(uintptr_t)(yv + iVar11 + paletteBase);
            dst[4] = tmp;
            yRow = yRow + 2;
            dst = dst + 6;
            n = n - 1;
        } while (n != 0);
    }
    if ((depth & 1) != 0) {
        uint8_t b1 = *uRow;
        uint32_t yv = *yRow;
        uint8_t b2 = *vRow;
        dst[0] = *(uint8_t*)(uintptr_t)
            (*(int*)(t10 + (uint32_t)b2 * 4) + yv + paletteBase);
        dst[1] = *(uint8_t*)(uintptr_t)
            ((*(int*)(t1c + (uint32_t)b1 * 4) + *(int*)(t18 + (uint32_t)b2 * 4) >> 0x10) +
             yv + paletteBase);
        dst[2] = *(uint8_t*)(uintptr_t)
            (*(int*)(t14 + (uint32_t)b1 * 4) + yv + paletteBase);
    }
}

// 0x6adaa0 — observed shape
void FUN_006adaa0(void* self, int* planes, int row, uint32_t** param_1)
{
    int* ctx = *(int**)((char*)self + 0x1c8);
    const int t10 = *(int*)((char*)ctx + 0x10);
    const int t14 = *(int*)((char*)ctx + 0x14);
    const int t18 = *(int*)((char*)ctx + 0x18);
    const int t1c = *(int*)((char*)ctx + 0x1c);
    const int paletteBase = *(int*)((char*)self + 0x148);
    const uint32_t depth = *(uint32_t*)((char*)self + 0x70);

    uint32_t* pair = (uint32_t*)(uintptr_t)(*planes + row * 8);
    uint8_t* local_c = (uint8_t*)(uintptr_t)pair[0];
    uint8_t* local_10 = (uint8_t*)(uintptr_t)pair[1];
    uint8_t* uRow = *(uint8_t**)(uintptr_t)(planes[1] + row * 4);
    uint8_t* vRow = *(uint8_t**)(uintptr_t)(planes[2] + row * 4);
    uint8_t* outA = (uint8_t*)(uintptr_t)*param_1;
    uint8_t* outB = (uint8_t*)(uintptr_t)param_1[1];
    uint32_t n = depth >> 1;

    while (n != 0) {
        uint8_t b2 = *uRow;
        uint8_t b3 = *vRow;
        uRow = uRow + 1;
        vRow = vRow + 1;
        int iVar9 = *(int*)(t10 + (uint32_t)b3 * 4);
        int iVar10 = *(int*)(t14 + (uint32_t)b2 * 4);
        uint32_t u = *local_c;
        int iVar17 = *(int*)(t1c + (uint32_t)b2 * 4) + *(int*)(t18 + (uint32_t)b3 * 4) >> 0x10;
        outA[0] = *(uint8_t*)(uintptr_t)(iVar9 + u + paletteBase);
        outA[1] = *(uint8_t*)(uintptr_t)(u + iVar17 + paletteBase);
        outA[2] = *(uint8_t*)(uintptr_t)(u + iVar10 + paletteBase);
        u = local_c[1];
        local_c = local_c + 2;
        outA[3] = *(uint8_t*)(uintptr_t)(iVar9 + u + paletteBase);
        outA[4] = *(uint8_t*)(uintptr_t)(u + iVar17 + paletteBase);
        outA[5] = *(uint8_t*)(uintptr_t)(u + iVar10 + paletteBase);
        u = *local_10;
        outA = outA + 6;
        outB[0] = *(uint8_t*)(uintptr_t)(iVar9 + u + paletteBase);
        outB[1] = *(uint8_t*)(uintptr_t)(u + iVar17 + paletteBase);
        outB[2] = *(uint8_t*)(uintptr_t)(u + iVar10 + paletteBase);
        u = local_10[1];
        local_10 = local_10 + 2;
        outB[3] = *(uint8_t*)(uintptr_t)(iVar9 + u + paletteBase);
        outB[4] = *(uint8_t*)(uintptr_t)(iVar17 + u + paletteBase);
        outB[5] = *(uint8_t*)(uintptr_t)(u + iVar10 + paletteBase);
        outB = outB + 6;
        n = n - 1;
    }
    if ((depth & 1) != 0) {
        int tR = *(int*)(t10 + (uint32_t)*vRow * 4);
        int tG1 = *(int*)(t1c + (uint32_t)*uRow * 4);
        int tG2 = *(int*)(t18 + (uint32_t)*vRow * 4);
        int tB = *(int*)(t14 + (uint32_t)*uRow * 4);
        uint32_t u = *local_c;
        outA[0] = *(uint8_t*)(uintptr_t)(tR + u + paletteBase);
        tG1 = tG1 + tG2 >> 0x10;
        outA[1] = *(uint8_t*)(uintptr_t)(u + tG1 + paletteBase);
        outA[2] = *(uint8_t*)(uintptr_t)(u + tB + paletteBase);
        u = *local_10;
        outB[0] = *(uint8_t*)(uintptr_t)(tR + u + paletteBase);
        uint8_t tmp = *(uint8_t*)(uintptr_t)(u + tB + paletteBase);
        outB[1] = *(uint8_t*)(uintptr_t)(u + tG1 + paletteBase);
        outB[2] = tmp;
    }
}

// ---------------------------------------------------------------------------
// Helpers reproducing the packed-word operations used by 0x6adc90.
// cat() mirrors Ghidra's CONCAT<hi><lo> operator (hi byte count, lo byte count);
// the four lane helpers mirror psubsw/psllw/paddsw/pmulhw on four 16-bit lanes.
// ---------------------------------------------------------------------------
static inline uint64_t cat(unsigned hiBytes, uint64_t hi, unsigned loBytes, uint64_t lo)
{
    const uint64_t hiMask = (hiBytes >= 8) ? ~0ull : ((1ull << (hiBytes * 8)) - 1);
    const uint64_t loMask = (loBytes >= 8) ? ~0ull : ((1ull << (loBytes * 8)) - 1);
    return ((hi & hiMask) << (loBytes * 8)) | (lo & loMask);
}

static inline int16_t lane16(uint64_t v, unsigned i)
{
    return (int16_t)((v >> (16 * i)) & 0xffff);
}

static inline uint64_t psubsw(uint64_t a, uint64_t b)
{
    uint64_t r = 0;
    for (unsigned i = 0; i < 4; ++i) {
        int32_t d = (int32_t)lane16(a, i) - (int32_t)lane16(b, i);
        if (d > 32767) d = 32767;
        if (d < -32768) d = -32768;
        r |= (uint64_t)(uint16_t)(int16_t)d << (16 * i);
    }
    return r;
}

static inline uint64_t paddsw(uint64_t a, uint64_t b)
{
    uint64_t r = 0;
    for (unsigned i = 0; i < 4; ++i) {
        int32_t d = (int32_t)lane16(a, i) + (int32_t)lane16(b, i);
        if (d > 32767) d = 32767;
        if (d < -32768) d = -32768;
        r |= (uint64_t)(uint16_t)(int16_t)d << (16 * i);
    }
    return r;
}

static inline uint64_t pmulhw(uint64_t a, uint64_t b)
{
    uint64_t r = 0;
    for (unsigned i = 0; i < 4; ++i) {
        int32_t p = (int32_t)lane16(a, i) * (int32_t)lane16(b, i);
        r |= (uint64_t)(uint16_t)(int16_t)(p >> 16) << (16 * i);
    }
    return r;
}

static inline uint64_t psllw(uint64_t a, unsigned n)
{
    uint64_t r = 0;
    for (unsigned i = 0; i < 4; ++i) {
        r |= (uint64_t)(uint16_t)(lane16(a, i) << n) << (16 * i);
    }
    return r;
}

// CONCAT52((int5)(CONCAT43((int)(((uint7)CONCAT21((short)(((uint7)bCatHi << 0x30) >> 0x28),bCatLo)
//                                 << 0x20) >> 0x18),CONCAT12(bLow,CONCAT11(bLow,bLow))) >> 0x10),
//          CONCAT11(bLow,bLow))
static inline uint64_t dupWord3(uint8_t bCatHi, uint8_t bCatLo, uint8_t bLow)
{
    const uint64_t cat21 = cat(3, (uint64_t)(((uint64_t)bCatHi << 0x30) >> 0x28), 1, bCatLo);
    const uint64_t cat43 = cat(4, (uint64_t)(uint32_t)((cat21 << 0x20) >> 0x18), 3,
                               cat(1, bLow, 2, cat(1, bLow, 1, bLow)));
    return cat(5, cat43 >> 0x10, 2, cat(1, bLow, 1, bLow));
}

static inline uint64_t dupWord(uint8_t b)
{
    return dupWord3(b, b, b);
}

// CONCAT16(b,(uint6)CONCAT14(b,(uint)(CONCAT12(b,CONCAT11(b,b)) & 0xff00ff)))
static inline uint64_t dupByteWord(uint8_t b)
{
    return cat(1, b, 6, cat(1, b, 5,
               (uint32_t)(cat(1, b, 2, cat(1, b, 1, b)) & 0xff00ff)));
}

// CONCAT62(CONCAT51((int5)(((uint64_t)CONCAT31((int3)(((uint64_t)bCatHi << 0x30) >> 0x28),bCatLo)
//                          << 0x20) >> 0x18),bCatLo),(ushort)low)
static inline uint64_t laneWord3(uint8_t bCatHi, uint8_t bCatLo, uint16_t low)
{
    const uint64_t cat31 = cat(3, (uint64_t)(((uint64_t)bCatHi << 0x30) >> 0x28), 1, bCatLo);
    return cat(6, cat(5, cat31 << 0x8, 1, bCatLo), 2, low);
}

static inline uint64_t laneWord(uint8_t b0, uint8_t b1)
{
    return laneWord3(b1, b0, b0);
}

// Observed saturation used before each byte store:
//   (0 < s) * (s < 0x100) * (char)s - (0xff < s)
static inline uint8_t pack8(int16_t s)
{
    return (uint8_t)((0 < s) * (s < 0x100) * (char)(uint8_t)s - (0xff < s));
}

// CONCAT17(pack8(h3), CONCAT16(pack8(h2), ... CONCAT11(pack8(l1), pack8(l0))))
static inline uint64_t packWords(uint64_t lo4, uint64_t hi4)
{
    uint64_t r = 0;
    for (unsigned i = 0; i < 4; ++i) {
        r |= (uint64_t)pack8(lane16(lo4, i)) << (8 * i);
        r |= (uint64_t)pack8(lane16(hi4, i)) << (8 * (4 + i));
    }
    return r;
}

// 0x6adc90 — observed shape
void FUN_006adc90(void* self, uint32_t** outPair, int row, int* planes)
{
    const int paletteBase = *(int*)((char*)self + 0x148);
    int* ctx = *(int**)((char*)self + 0x1c8);
    const int t10 = *(int*)((char*)ctx + 0x10);
    const int t14 = *(int*)((char*)ctx + 0x14);
    const int t18 = *(int*)((char*)ctx + 0x18);
    const int t1c = *(int*)((char*)ctx + 0x1c);
    const int iVar24 = *(int*)((char*)self + 0x70) >> 3;
    const uint32_t uVar21 = (uint32_t)(*(int*)((char*)self + 0x70) + iVar24 * -8);

    int* piVar1 = (int*)(uintptr_t)(planes[0] + row * 8);
    uint32_t* puVar6 = (uint32_t*)(uintptr_t)piVar1[0];
    uint32_t* puVar7 = (uint32_t*)(uintptr_t)piVar1[1];
    uint32_t* puVar8 = *(uint32_t**)(uintptr_t)(planes[1] + row * 4);
    uint32_t* puVar9 = *(uint32_t**)(uintptr_t)(planes[2] + row * 4);
    uint64_t* puVar33 = (uint64_t*)(uintptr_t)outPair[1];
    uint64_t* puVar31 = (uint64_t*)(uintptr_t)outPair[0];
    uint32_t* puVar22 = puVar7;
    uint32_t* puVar25 = puVar8;
    uint64_t* puVar27 = puVar33;
    uint32_t* puVar29 = puVar9;
    uint32_t* puVar30 = puVar6;
    uint64_t* puVar32 = puVar31;
    int local_1c = iVar24;

    do {
        uint8_t uVar37 = (uint8_t)((uint32_t)*puVar29 >> 8);
        uint8_t bVar34 = (uint8_t)*puVar29;
        uint64_t uVar35 = psubsw(dupWord(bVar34) & 0xffff00ff00ff00ffull,
                                 0x80008000800080ull);
        uVar35 = psllw(uVar35, 2);
        uint8_t uVar39 = (uint8_t)((uint32_t)*puVar25 >> 8);
        bVar34 = (uint8_t)*puVar25;
        uVar35 = paddsw(uVar35, 0x1000000000001ull);
        uVar35 = pmulhw(uVar35, 0x59ba0000d24b59baull);
        uint64_t uVar38 = psubsw(dupWord(bVar34) & 0xffff00ff00ff00ffull,
                                 0x80008000800080ull);
        uVar38 = psllw(uVar38, 2);
        uVar38 = paddsw(uVar38, 0x1fffa0000ull);
        uint64_t uVar44 = psubsw(dupByteWord(uVar37), 0x80008000800080ull);
        uint64_t uVar46 = psubsw(dupByteWord(uVar39), 0x80008000800080ull);
        uVar38 = pmulhw(uVar38, 0x7168e9fa0000ull);
        uVar44 = psllw(uVar44, 2);
        uVar46 = psllw(uVar46, 2);
        uVar44 = paddsw(uVar44, 0x10000ull);
        uint32_t uVar10 = *puVar30;
        uVar44 = pmulhw(uVar44, 0xd24b59ba0000ull);
        uint8_t bVar49 = (uint8_t)((uint32_t)uVar10 >> 0x18);
        uint8_t bVar48 = (uint8_t)((uint32_t)uVar10 >> 0x10);
        uint8_t bVar41 = (uint8_t)((uint32_t)uVar10 >> 8);
        bVar34 = (uint8_t)uVar10;
        uVar46 = paddsw(uVar46, 0x1fffa00000001ull);
        uint64_t uVar36 = paddsw(uVar35, uVar38);
        uVar35 = pmulhw(uVar46, 0x7168e9fa00007168ull);
        uint64_t uVar45 = paddsw(uVar44, uVar35);
        uVar38 = paddsw(laneWord(bVar34, bVar41), uVar36);
        uint64_t uVar40 = (uVar36 & 0xffffffff0000ull) >> 0x10 |
                          (uVar45 & 0xffffffff0000ull) << 0x10;
        uVar10 = *puVar22;
        uVar35 = paddsw(laneWord(bVar41, bVar48), uVar40);
        *puVar32 = packWords(uVar38, uVar35);

        uint8_t bVar43 = (uint8_t)((uint32_t)uVar10 >> 0x18);
        uint8_t bVar42 = (uint8_t)((uint32_t)uVar10 >> 0x10);
        bVar41 = (uint8_t)((uint32_t)uVar10 >> 8);
        bVar34 = (uint8_t)uVar10;
        uVar35 = paddsw(laneWord(bVar34, bVar41), uVar36);
        uVar38 = paddsw(laneWord(bVar41, bVar42), uVar40);
        *puVar27 = packWords(uVar35, uVar38);

        uVar38 = paddsw(laneWord3(bVar49, bVar49, bVar48), uVar45);
        uVar37 = (uint8_t)((uint32_t)*puVar29 >> 0x18);
        bVar34 = (uint8_t)((uint32_t)*puVar29 >> 0x10);
        uVar46 = paddsw(laneWord3(bVar43, bVar43, bVar42), uVar45);
        uVar35 = psubsw(dupWord(bVar34) & 0xffff00ff00ff00ffull,
                        0x80008000800080ull);
        uVar39 = (uint8_t)((uint32_t)*puVar25 >> 0x18);
        bVar34 = (uint8_t)((uint32_t)*puVar25 >> 0x10);
        uVar35 = psllw(uVar35, 2);
        uVar35 = paddsw(uVar35, 0x1000000000001ull);
        uVar35 = pmulhw(uVar35, 0x59ba0000d24b59baull);
        uVar44 = psubsw(dupWord(bVar34) & 0xffff00ff00ff00ffull,
                        0x80008000800080ull);
        uVar44 = psllw(uVar44, 2);
        uVar44 = paddsw(uVar44, 0x1fffa0000ull);
        uVar44 = pmulhw(uVar44, 0x7168e9fa0000ull);
        uint64_t uVar47 = psubsw(dupByteWord(uVar39), 0x80008000800080ull);
        uVar36 = paddsw(uVar35, uVar44);
        uVar44 = psllw(uVar47, 2);
        uVar35 = psubsw(dupByteWord(uVar37), 0x80008000800080ull);
        uVar10 = puVar30[1];
        uVar35 = psllw(uVar35, 2);
        uVar44 = paddsw(uVar44, 0x1fffa00000001ull);
        bVar34 = (uint8_t)uVar10;
        uVar35 = paddsw(uVar35, 0x10000ull);
        uVar35 = pmulhw(uVar35, 0xd24b59ba0000ull);
        uVar44 = pmulhw(uVar44, 0x7168e9fa00007168ull);
        bVar41 = (uint8_t)((uint32_t)uVar10 >> 8);
        uVar45 = paddsw(uVar35, uVar44);
        uVar35 = paddsw(laneWord(bVar34, bVar41), uVar36);
        uint32_t uVar11 = puVar22[1];
        puVar32[1] = packWords(uVar38, uVar35);

        uVar40 = (uVar36 & 0xffffffff0000ull) >> 0x10 |
                 (uVar45 & 0xffffffff0000ull) << 0x10;
        uVar37 = (uint8_t)uVar11;
        bVar34 = (uint8_t)((uint32_t)uVar11 >> 8);
        uVar35 = paddsw(dupWord3(bVar34, uVar37, uVar37) & 0xffffffff00ff00ffull, uVar36);
        bVar43 = (uint8_t)((uint32_t)uVar11 >> 0x10);
        puVar27[1] = packWords(uVar46, uVar35);

        bVar42 = (uint8_t)((uint32_t)uVar10 >> 0x10);
        uVar46 = paddsw(dupWord3(bVar43, bVar43, bVar34) & 0xffffffff00ff00ffull, uVar40);
        uVar44 = paddsw(dupWord3(bVar42, bVar42, bVar41) & 0xffffffff00ff00ffull, uVar40);
        bVar41 = (uint8_t)((uint32_t)uVar10 >> 0x18);
        puVar30 = puVar30 + 2;
        puVar22 = puVar22 + 2;
        bVar34 = (uint8_t)((uint32_t)uVar11 >> 0x18);
        uVar35 = paddsw(laneWord3(bVar41, bVar41,
                                    (uint16_t)((uint32_t)uVar10 >> 0x10)) &
                            0xffffffff00ff00ffull, uVar45);
        puVar29 = puVar29 + 1;
        uVar38 = paddsw(laneWord3(bVar34, bVar34,
                                    (uint16_t)((uint32_t)uVar11 >> 0x10)) &
                            0xffffffff00ff00ffull, uVar45);
        puVar32[2] = packWords(uVar44, uVar35);
        puVar25 = puVar25 + 1;
        puVar27[2] = packWords(uVar46, uVar38);

        local_1c = local_1c + -1;
        puVar27 = puVar27 + 3;
        puVar32 = puVar32 + 3;
    } while (local_1c != 0);

    uint8_t* local_10 = (uint8_t*)(uintptr_t)(puVar8 + iVar24);
    uint8_t* local_14 = (uint8_t*)(uintptr_t)(puVar9 + iVar24);
    uint8_t* lumaA = (uint8_t*)(uintptr_t)(puVar6 + iVar24 * 2);
    uint8_t* local_8 = (uint8_t*)(uintptr_t)(puVar7 + iVar24 * 2);
    puVar31 = puVar31 + iVar24 * 3;
    puVar33 = puVar33 + iVar24 * 3;
    int local_20 = (int)uVar21 >> 1;
    if (local_20 != 0) {
        do {
            uint8_t bVar34 = *local_10;
            local_10 = local_10 + 1;
            uint8_t bVar41 = *local_14;
            local_14 = local_14 + 1;
            int iVar24b = *(int*)(t10 + (uint32_t)bVar41 * 4);
            int iVar12 = *(int*)(t14 + (uint32_t)bVar34 * 4);
            uint32_t uVar28 = *lumaA;
            int iVar26 = *(int*)(t1c + (uint32_t)bVar34 * 4) +
                         *(int*)(t18 + (uint32_t)bVar41 * 4) >> 0x10;
            *(uint8_t*)(uintptr_t)puVar31 =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar24b + paletteBase);
            *(uint8_t*)((int)(uintptr_t)puVar31 + 1) =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar26 + paletteBase);
            *(uint8_t*)((int)(uintptr_t)puVar31 + 2) =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar12 + paletteBase);
            uVar28 = lumaA[1];
            lumaA = lumaA + 2;
            *(uint8_t*)((int)(uintptr_t)puVar31 + 3) =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar24b + paletteBase);
            *(uint8_t*)((int)(uintptr_t)puVar31 + 4) =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar26 + paletteBase);
            *(uint8_t*)((int)(uintptr_t)puVar31 + 5) =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar12 + paletteBase);
            uVar28 = *local_8;
            puVar31 = (uint64_t*)(uintptr_t)((int)(uintptr_t)puVar31 + 6);
            *(uint8_t*)(uintptr_t)puVar33 =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar24b + paletteBase);
            *(uint8_t*)((int)(uintptr_t)puVar33 + 1) =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar26 + paletteBase);
            *(uint8_t*)((int)(uintptr_t)puVar33 + 2) =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar12 + paletteBase);
            uVar28 = local_8[1];
            local_8 = local_8 + 2;
            *(uint8_t*)((int)(uintptr_t)puVar33 + 3) =
                *(uint8_t*)(uintptr_t)(iVar24b + uVar28 + paletteBase);
            *(uint8_t*)((int)(uintptr_t)puVar33 + 4) =
                *(uint8_t*)(uintptr_t)(iVar26 + uVar28 + paletteBase);
            *(uint8_t*)((int)(uintptr_t)puVar33 + 5) =
                *(uint8_t*)(uintptr_t)(uVar28 + iVar12 + paletteBase);
            puVar33 = (uint64_t*)(uintptr_t)((int)(uintptr_t)puVar33 + 6);
            local_20 = local_20 + -1;
        } while (local_20 != 0);
    }
    if ((uVar21 & 1) != 0) {
        int iVar3 = *(int*)(t10 + (uint32_t)*local_14 * 4);
        int iVar23 = *(int*)(t1c + (uint32_t)*local_10 * 4);
        int iVar5 = *(int*)(t18 + (uint32_t)*local_14 * 4);
        int iVar4 = *(int*)(t14 + (uint32_t)*local_10 * 4);
        uint32_t uVar28 = *lumaA;
        *(uint8_t*)(uintptr_t)puVar31 =
            *(uint8_t*)(uintptr_t)(uVar28 + iVar3 + paletteBase);
        iVar23 = iVar23 + iVar5 >> 0x10;
        *(uint8_t*)((int)(uintptr_t)puVar31 + 1) =
            *(uint8_t*)(uintptr_t)(uVar28 + iVar23 + paletteBase);
        *(uint8_t*)((int)(uintptr_t)puVar31 + 2) =
            *(uint8_t*)(uintptr_t)(uVar28 + iVar4 + paletteBase);
        uVar28 = *local_8;
        *(uint8_t*)(uintptr_t)puVar33 =
            *(uint8_t*)(uintptr_t)(iVar3 + uVar28 + paletteBase);
        uint8_t uVar37 = *(uint8_t*)(uintptr_t)(uVar28 + iVar4 + paletteBase);
        *(uint8_t*)((int)(uintptr_t)puVar33 + 1) =
            *(uint8_t*)(uintptr_t)(iVar23 + uVar28 + paletteBase);
        *(uint8_t*)((int)(uintptr_t)puVar33 + 2) = uVar37;
    }
}

// 0x6ae1a0 — observed shape
// NEEDS_MANUAL: the two conversion routines are entered with further arguments
// in registers (ECX receiver plus EAX/EDX); only this stack argument is visible
// in the listing, so it is forwarded unchanged through a matching cast.
void FUN_006ae1a0(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    if ((*(int*)((char*)self + 0x48) == 5) || (*(int*)((char*)self + 0x48) == 6)) {
        reinterpret_cast<void (*)(uint32_t)>(&FUN_006adc90)(param_2);
        return;
    }
    reinterpret_cast<void (*)(uint32_t)>(&FUN_006adaa0)(param_4);
}

// 0x6ae1f0 — observed shape
void FUN_006ae1f0(int* self)
{
    // The listing calls *(code*)**(undefined4**)(param_1 + 4): two
    // dereferences, i.e. slot 0 of the allocator vtable held at self[1].
    void** allocVtbl = (void**)(uintptr_t)self[1];
    int (*alloc)(int*, int, int) = (int (*)(int*, int, int))allocVtbl[0];
    uint32_t* puVar2 = (uint32_t*)alloc(self, 1, 0x30);
    int iVar1 = *(int*)((char*)self + 0x13c);
    int iVar3 = *(int*)((char*)self + 0x78) * *(int*)((char*)self + 0x70);
    *(uint32_t**)((char*)self + 0x1c8) = puVar2;
    puVar2[0] = (uint32_t)(uintptr_t)&FUN_006ad820;
    puVar2[2] = 0;
    puVar2[10] = (uint32_t)iVar3;

    if (iVar1 == 2) {
        puVar2[1] = (uint32_t)(uintptr_t)&FUN_006ad840;
        puVar2[3] = (uint32_t)(uintptr_t)&FUN_006ae1a0;
        uint32_t uVar4 = (*(int (**)(int*, int, int))allocVtbl[1])(self, 1, iVar3);
        puVar2[8] = uVar4;
        FUN_006ad740(self);
        return;
    }
    puVar2[1] = (uint32_t)(uintptr_t)&FUN_006ad910;
    puVar2[3] = (uint32_t)(uintptr_t)&FUN_006ad950;
    puVar2[8] = 0;
    FUN_006ad740(self);
}

// 0x6ae280 — observed shape
void FUN_006ae280(uint32_t param_1, int param_2)
{
    void* pvVar1 = malloc((size_t)(param_2 + 0x10));
    if (pvVar1 == nullptr) {
        return;
    }
    uint32_t uVar2 = ((uint32_t)(uintptr_t)pvVar1 + 0x10u) & 0xfffffff0u;
    *(uint8_t*)(uintptr_t)(uVar2 - 1) =
        (uint8_t)((char)uVar2 - (char)(uintptr_t)pvVar1);
}

// 0x6ae2b0 — observed shape
void FUN_006ae2b0(uint32_t param_1, int param_2)
{
    if (param_2 != 0) {
        free((void*)(uintptr_t)(param_2 - (uint32_t)*(uint8_t*)(uintptr_t)(param_2 - 1)));
    }
}

// 0x6ae2f0 — observed shape
void FUN_006ae2f0(int* param_1, int param_2, void* param_3, long param_4, size_t param_5)
{
    int iVar2 = fseek(*(FILE**)(uintptr_t)(param_2 + 0xc), param_4, 0);
    if (iVar2 != 0) {
        int* puVar1 = (int*)(uintptr_t)*param_1;
        puVar1[5] = 0x41;
        (*(void (**)(int*))(uintptr_t)puVar1[0])(param_1);
    }
    size_t sVar3 = fread(param_3, 1, param_5, *(FILE**)(uintptr_t)(param_2 + 0xc));
    if (sVar3 != param_5) {
        int* puVar1 = (int*)(uintptr_t)*param_1;
        puVar1[5] = 0x40;
        (*(void (**)(int*))(uintptr_t)puVar1[0])(param_1);
    }
}
