#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void *ptr);
extern void *FUN_0050f330(void *out, float t);

// 0x50f1e0 — observed shape
void FUN_0050f1e0(void *self)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    uint32_t *p0 = reinterpret_cast<uint32_t *>(s[0]);
    s[7] = 0;
    s[8] = 0;
    if (p0 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p0) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p0[0]);
            dtorFn(1);
        }
        s[0] = 0;
        if (reinterpret_cast<void *>(s[9]) != nullptr) {
            operator_delete(reinterpret_cast<void *>(s[9]));
            s[9] = 0;
        }
    }
    uint32_t *p10 = reinterpret_cast<uint32_t *>(s[10]);
    if (p10 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p10) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p10[0]);
            dtorFn(1);
        }
        s[10] = 0;
    }
    uint32_t *p5 = reinterpret_cast<uint32_t *>(s[5]);
    if (p5 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p5) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p5[0]);
            dtorFn(1);
        }
        s[5] = 0;
    }
    uint32_t *p1 = reinterpret_cast<uint32_t *>(s[1]);
    if (p1 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p1) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p1[0]);
            dtorFn(1);
        }
        s[1] = 0;
    }
    uint32_t *p2 = reinterpret_cast<uint32_t *>(s[2]);
    if (p2 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p2) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p2[0]);
            dtorFn(1);
        }
        s[2] = 0;
    }
    uint32_t *p3 = reinterpret_cast<uint32_t *>(s[3]);
    if (p3 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p3) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p3[0]);
            dtorFn(1);
        }
        s[3] = 0;
    }
    uint32_t *p4 = reinterpret_cast<uint32_t *>(s[4]);
    if (p4 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p4) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p4[0]);
            dtorFn(1);
        }
        s[4] = 0;
    }
    uint32_t *p0b = reinterpret_cast<uint32_t *>(s[0]);
    if (p0b != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p0b) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p0b[0]);
            dtorFn(1);
        }
        s[0] = 0;
    }
    reinterpret_cast<uint8_t *>(self)[24] = 0;
    uint32_t *p10b = reinterpret_cast<uint32_t *>(s[10]);
    if (p10b != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p10b) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p10b[0]);
            dtorFn(1);
        }
    }
    uint32_t *p5b = reinterpret_cast<uint32_t *>(s[5]);
    if (p5b != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p5b) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p5b[0]);
            dtorFn(1);
        }
    }
    uint32_t *p4b = reinterpret_cast<uint32_t *>(s[4]);
    if (p4b != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p4b) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p4b[0]);
            dtorFn(1);
        }
    }
    uint32_t *p3b = reinterpret_cast<uint32_t *>(s[3]);
    if (p3b != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p3b) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p3b[0]);
            dtorFn(1);
        }
    }
    uint32_t *p2b = reinterpret_cast<uint32_t *>(s[2]);
    if (p2b != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p2b) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p2b[0]);
            dtorFn(1);
        }
    }
    uint32_t *p1b = reinterpret_cast<uint32_t *>(s[1]);
    if (p1b != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p1b) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p1b[0]);
            dtorFn(1);
        }
    }
    uint32_t *p0c = reinterpret_cast<uint32_t *>(s[0]);
    if (p0c != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p0c) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p0c[0]);
            dtorFn(1);
        }
    }
}

// 0x50f330 — observed shape
void FUN_0050f330(float *param_1, float param_2, float *self_ecx, float *self_edx, float *self_esi, float *self_edi)
{
    float t2 = param_2 * param_2;
    float t3 = param_2 * t2;
    float e0 = self_ecx[0];
    float e1 = self_ecx[1];
    float e2 = self_ecx[2];
    float d0 = self_edx[0];
    float d1 = self_edx[1];
    float d2 = self_edx[2];
    float s0 = self_esi[0];
    float s1 = self_esi[1];
    float s2 = self_esi[2];
    float i0 = self_edi[0];
    float i1 = self_edi[1];
    float i2 = self_edi[2];
    param_1[0] = (d0 + d0 + (-s0 + e0) * param_2 +
                  (((s0 + s0) - d0 * 5.0f) + e0 * 4.0f - i0) * t2 +
                  ((-s0 + d0 * 3.0f) - e0 * 3.0f + i0) * t3) * 0.5f;
    param_1[1] = (d1 + d1 + (-s1 + e1) * param_2 +
                  (((s1 + s1) - d1 * 5.0f) + e1 * 4.0f - i1) * t2 +
                  ((-(self_esi[1]) + d1 * 3.0f) - e1 * 3.0f + i1) * t3) * 0.5f;
    param_1[2] = (((s2 + s2) - d2 * 5.0f) + e2 * 4.0f - i2) * t2 +
                 d2 + d2 + (-(self_esi[2]) + e2) * param_2 +
                 ((-(self_esi[2]) + d2 * 3.0f) - e2 * 3.0f + i2) * t3;
    param_1[2] = param_1[2] * 0.5f;
}

// 0x50f5b0 — observed shape
void FUN_0050f5b0(int param_1, uint32_t *param_2, uint32_t *param_3, int param_4, int param_5, int param_6, void *self)
{
    float *pfVar1 = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x30);
    int iVar23 = param_1 * 6;
    uint32_t *puVar24 = reinterpret_cast<uint32_t *>(param_4 + param_1 * 0x90);
    puVar24[0] = param_2[0];
    puVar24[1] = param_2[1];
    puVar24[2] = param_2[2];
    puVar24[3] = param_3[0];
    puVar24[4] = param_3[1];
    puVar24[5] = param_3[2];
    float *pfVar21 = reinterpret_cast<float *>(param_1 * 0xc0 + param_5);
    pfVar21[0] = pfVar1[0];
    pfVar21[1] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar21[2] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar21[3] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    pfVar21[4] = pfVar1[0];
    pfVar21[5] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar21[6] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar21[7] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    uint32_t *puVar22 = reinterpret_cast<uint32_t *>(param_1 * 0x60 + param_6);
    puVar22[0] = 0;
    puVar22[1] = 0x3f800000;
    puVar22[2] = 0;
    puVar22[3] = 0;
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0] + param_1 * 0x18) = 0;
    puVar24[6] = param_2[0];
    puVar24[7] = param_2[1];
    puVar24[8] = param_2[2];
    puVar24[9] = param_3[0];
    puVar24[10] = param_3[1];
    puVar24[11] = param_3[2];
    pfVar21[8] = pfVar1[0];
    pfVar21[9] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar21[10] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar21[11] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    pfVar21[12] = pfVar1[0];
    pfVar21[13] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar21[14] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar21[15] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    puVar22[4] = 0;
    puVar22[5] = 0x3f800000;
    puVar22[6] = 0;
    puVar22[7] = 0;
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0] + 4 + param_1 * 0x18) = 0;
    int iVar2 = iVar23 + 2;
    uint32_t *puVar20 = reinterpret_cast<uint32_t *>(param_4 + iVar2 * 0x18);
    puVar20[0] = param_2[0];
    puVar20[1] = param_2[1];
    puVar20[2] = param_2[2];
    puVar24[15] = param_3[0];
    puVar24[16] = param_3[1];
    puVar24[17] = param_3[2];
    float *pfVar25 = reinterpret_cast<float *>(iVar2 * 0x20 + param_5);
    pfVar25[0] = pfVar1[0];
    pfVar25[1] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar25[2] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar25[3] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    pfVar21[20] = pfVar1[0];
    pfVar21[21] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar21[22] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar21[23] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    *reinterpret_cast<uint32_t *>(iVar2 * 0x10 + param_6) = 0;
    *reinterpret_cast<uint32_t *>(iVar2 * 0x10 + 4 + param_6) = 0x3f800000;
    puVar22[10] = 0;
    puVar22[11] = 0;
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0] + iVar2 * 4) = 0;
    iVar2 = iVar23 + 3;
    puVar20 = reinterpret_cast<uint32_t *>(param_4 + iVar2 * 0x18);
    puVar20[0] = param_2[0];
    puVar20[1] = param_2[1];
    puVar20[2] = param_2[2];
    puVar24[21] = param_3[0];
    puVar24[22] = param_3[1];
    puVar24[23] = param_3[2];
    pfVar25 = reinterpret_cast<float *>(iVar2 * 0x20 + param_5);
    pfVar25[0] = pfVar1[0];
    pfVar25[1] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar25[2] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar25[3] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    pfVar21[28] = pfVar1[0];
    pfVar21[29] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar21[30] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar21[31] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    *reinterpret_cast<uint32_t *>(iVar2 * 0x10 + param_6) = 0;
    *reinterpret_cast<uint32_t *>(iVar2 * 0x10 + 4 + param_6) = 0x3f800000;
    puVar22[14] = 0;
    puVar22[15] = 0;
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0] + iVar2 * 4) = 0;
    iVar2 = iVar23 + 4;
    puVar20 = reinterpret_cast<uint32_t *>(param_4 + iVar2 * 0x18);
    puVar20[0] = param_2[0];
    puVar20[1] = param_2[1];
    puVar20[2] = param_2[2];
    puVar24[27] = param_3[0];
    puVar24[28] = param_3[1];
    puVar24[29] = param_3[2];
    pfVar25 = reinterpret_cast<float *>(iVar2 * 0x20 + param_5);
    pfVar25[0] = pfVar1[0];
    pfVar25[1] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar25[2] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar25[3] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    pfVar21[36] = pfVar1[0];
    pfVar21[37] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar21[38] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar21[39] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    *reinterpret_cast<uint32_t *>(iVar2 * 0x10 + param_6) = 0;
    *reinterpret_cast<uint32_t *>(iVar2 * 0x10 + 4 + param_6) = 0x3f800000;
    puVar22[18] = 0;
    puVar22[19] = 0;
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0] + iVar2 * 4) = 0;
    iVar23 = iVar23 + 5;
    puVar20 = reinterpret_cast<uint32_t *>(param_4 + iVar23 * 0x18);
    puVar20[0] = param_2[0];
    puVar20[1] = param_2[1];
    puVar20[2] = param_2[2];
    puVar24[33] = param_3[0];
    puVar24[34] = param_3[1];
    puVar24[35] = param_3[2];
    pfVar25 = reinterpret_cast<float *>(iVar23 * 0x20 + param_5);
    pfVar25[0] = pfVar1[0];
    pfVar25[1] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar25[2] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar25[3] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    pfVar21[44] = pfVar1[0];
    pfVar21[45] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34)[0];
    pfVar21[46] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38)[0];
    pfVar21[47] = reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c)[0];
    *reinterpret_cast<uint32_t *>(iVar23 * 0x10 + param_6) = 0;
    *reinterpret_cast<uint32_t *>(iVar23 * 0x10 + 4 + param_6) = 0x3f800000;
    puVar22[22] = 0;
    puVar22[23] = 0;
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0] + iVar23 * 4) = 0;
    if (param_1 != 0) {
        param_5 = param_1 * 0xc0 + param_5;
        float fVar4 = *reinterpret_cast<float *>(param_5 + -0xb0);
        float fVar5 = *reinterpret_cast<float *>(param_5 + -0xac);
        float fVar6 = *reinterpret_cast<float *>(param_5 + -0xa8);
        float fVar7 = *reinterpret_cast<float *>(param_5 + -0xa4);
        float fVar8 = *reinterpret_cast<float *>(param_5 + -0xc0);
        float fVar9 = *reinterpret_cast<float *>(param_5 + -0xbc);
        float fVar10 = *reinterpret_cast<float *>(param_5 + -0xb8);
        float fVar11 = *reinterpret_cast<float *>(param_5 + -0xb4);
        param_6 = param_1 * 0x60 + param_6;
        float fVar12 = *reinterpret_cast<float *>(param_6 + -0x58);
        float fVar13 = *reinterpret_cast<float *>(param_6 + -0x54);
        float fVar14 = *reinterpret_cast<float *>(param_6 + -0x60);
        float fVar15 = *reinterpret_cast<float *>(param_6 + -0x5c);
        float fVar3 = *reinterpret_cast<float *>(param_1 * 0x18 + -0x18 + reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0]);
        uint32_t *local_fc = reinterpret_cast<uint32_t *>(param_1 * 0x18 + -0x14);
        float *pfVar21b = reinterpret_cast<float *>(param_6 + -0x50);
        int local_110 = 1;
        uint32_t local_18 = 0;
        uint32_t local_14 = 0x3f800000;
        float *pfVar25b = reinterpret_cast<float *>(param_5 + -0xa0);
        do {
            float fVar19 = static_cast<float>(local_110) * 0.16666667f;
            float fVar16 = *reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34);
            float fVar17 = *reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38);
            float fVar18 = *reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c);
            pfVar25b[4] = (pfVar1[0] - fVar4) * fVar19 + fVar4;
            pfVar25b[5] = (fVar16 - fVar5) * fVar19 + fVar5;
            pfVar25b[6] = (fVar17 - fVar6) * fVar19 + fVar6;
            pfVar25b[7] = (fVar18 - fVar7) * fVar19 + fVar7;
            fVar16 = *reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x34);
            fVar17 = *reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x38);
            fVar18 = *reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x3c);
            pfVar25b[0] = (pfVar1[0] - fVar8) * fVar19 + fVar8;
            pfVar25b[1] = (fVar16 - fVar9) * fVar19 + fVar9;
            pfVar25b[2] = (fVar17 - fVar10) * fVar19 + fVar10;
            pfVar25b[3] = (fVar18 - fVar11) * fVar19 + fVar11;
            pfVar21b[2] = (0.0f - fVar12) * fVar19 + fVar12;
            pfVar21b[3] = (0.0f - fVar13) * fVar19 + fVar13;
            float local_c = (0.0f - fVar14) * fVar19;
            float local_8 = (1.0f - fVar15) * fVar19;
            pfVar21b[0] = local_c + fVar14;
            pfVar21b[1] = local_8 + fVar15;
            *reinterpret_cast<float *>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0] + static_cast<intptr_t>(local_fc)) = -fVar3 * fVar19 + fVar3;
            local_110 = local_110 + 1;
            local_fc = local_fc + 1;
            pfVar25b = pfVar25b + 8;
            pfVar21b = pfVar21b + 4;
        } while (local_110 < 6);
        (void)local_18;
        (void)local_14;
    }
    int local_f0 = param_1 + -2;
    if (local_f0 < param_1) {
        uint32_t *local_fc2 = reinterpret_cast<uint32_t *>(local_f0 * 0x90 + 0x18 + param_4);
        int local_10c = param_1 + -1;
        local_f0 = param_1 - local_f0;
        do {
            if (0 < local_10c) {
                int local_110b = 1;
                uint32_t *puVar24b = local_fc2;
                do {
                    float local_c2 = 0.0f;
                    float local_8b = 0.0f;
                    uint32_t *puVar20b = reinterpret_cast<uint32_t *>(FUN_0050f330(&local_c2, static_cast<float>(local_110b) * 0.16666667f));
                    puVar24b[0] = puVar20b[0];
                    puVar24b[1] = puVar20b[1];
                    puVar24b[2] = puVar20b[2];
                    float local_18b = 0.0f;
                    float local_14b = 0.0f;
                    uint32_t *puVar20c = reinterpret_cast<uint32_t *>(FUN_0050f330(&local_18b, static_cast<float>(local_110b) * 0.16666667f));
                    puVar24b[3] = puVar20c[0];
                    puVar24b[4] = puVar20c[1];
                    local_110b = local_110b + 1;
                    puVar24b[5] = puVar20c[2];
                    puVar24b = puVar24b + 6;
                    (void)local_8b;
                    (void)local_14b;
                } while (local_110b < 6);
            }
            local_10c = local_10c + 1;
            local_fc2 = local_fc2 + 0x24;
            local_f0 = local_f0 + -1;
        } while (local_f0 != 0);
    }
}

// 0x510240 — observed shape
void FUN_00510240(int param_1, float param_2, int param_3, int param_4, int param_5)
{
    int iVar13 = param_3 + -1;
    if (-1 < iVar13) {
        float *pfVar12 = reinterpret_cast<float *>(iVar13 * 0x60 + param_5);
        float *local_64 = reinterpret_cast<float *>(iVar13 * 0xc0 + param_4);
        iVar13 = iVar13 * 0x18;
        float *pfVar1 = reinterpret_cast<float *>(param_1 + 0x30);
        int local_60 = param_3;
        int local_5c = 6;
        float *pfVar14 = local_64;
        float *local_58 = pfVar12;
        int local_54 = iVar13;
        while (true) {
            while (true) {
                float fVar2 = param_2 + *reinterpret_cast<float *>(reinterpret_cast<uint32_t *>(param_1 + 0x24)[0] + iVar13);
                if (*reinterpret_cast<float *>(param_1 + 0x54) < fVar2) {
                    fVar2 = *reinterpret_cast<float *>(param_1 + 0x54);
                }
                *reinterpret_cast<float *>(reinterpret_cast<uint32_t *>(param_1 + 0x24)[0] + iVar13) = fVar2;
                fVar2 = fVar2 / *reinterpret_cast<float *>(param_1 + 0x54);
                pfVar12[0] = fVar2 * 1.0f + 0.0f;
                pfVar12[1] = fVar2 * 0.0f + 1.0f;
                pfVar12[2] = fVar2 * 1.0f + 0.0f;
                pfVar12[3] = fVar2 * 0.0f + 0.0f;
                float fVar6 = *reinterpret_cast<float *>(param_1 + 0x44);
                float fVar7 = *reinterpret_cast<float *>(param_1 + 0x48);
                float fVar8 = *reinterpret_cast<float *>(param_1 + 0x4c);
                float fVar3 = *reinterpret_cast<float *>(param_1 + 0x34);
                float fVar4 = *reinterpret_cast<float *>(param_1 + 0x38);
                float fVar5 = *reinterpret_cast<float *>(param_1 + 0x3c);
                float fVar9 = *reinterpret_cast<float *>(param_1 + 0x34);
                float fVar10 = *reinterpret_cast<float *>(param_1 + 0x38);
                float fVar11 = *reinterpret_cast<float *>(param_1 + 0x3c);
                pfVar14[0] = (*reinterpret_cast<float *>(param_1 + 0x40) - pfVar1[0]) * fVar2 + pfVar1[0];
                pfVar14[1] = (fVar6 - fVar3) * fVar2 + fVar9;
                pfVar14[2] = (fVar7 - fVar4) * fVar2 + fVar10;
                pfVar14[3] = (fVar8 - fVar5) * fVar2 + fVar11;
                fVar6 = *reinterpret_cast<float *>(param_1 + 0x44);
                fVar7 = *reinterpret_cast<float *>(param_1 + 0x48);
                fVar8 = *reinterpret_cast<float *>(param_1 + 0x4c);
                iVar13 = iVar13 + 4;
                pfVar12 = pfVar12 + 4;
                fVar3 = *reinterpret_cast<float *>(param_1 + 0x34);
                fVar4 = *reinterpret_cast<float *>(param_1 + 0x38);
                fVar5 = *reinterpret_cast<float *>(param_1 + 0x3c);
                fVar9 = *reinterpret_cast<float *>(param_1 + 0x34);
                fVar10 = *reinterpret_cast<float *>(param_1 + 0x38);
                fVar11 = *reinterpret_cast<float *>(param_1 + 0x3c);
                pfVar14[4] = (*reinterpret_cast<float *>(param_1 + 0x40) - pfVar1[0]) * fVar2 + pfVar1[0];
                pfVar14[5] = (fVar6 - fVar3) * fVar2 + fVar9;
                pfVar14[6] = (fVar7 - fVar4) * fVar2 + fVar10;
                pfVar14[7] = (fVar8 - fVar5) * fVar2 + fVar11;
                local_5c = local_5c + -1;
                if (local_5c == 0) break;
                pfVar14 = pfVar14 + 8;
            }
            iVar13 = local_54 + -0x18;
            local_64 = local_64 + -0x30;
            pfVar12 = local_58 + -0x18;
            local_60 = local_60 + -1;
            if (local_60 == 0) break;
            local_5c = 6;
            pfVar14 = local_64;
            local_58 = pfVar12;
            local_54 = iVar13;
        }
    }
}

// 0x5107e0 — observed shape
int FUN_005107e0(void *param_1, void *param_2, void *param_3, void *self, int count)
{
    int iVar2 = 0;
    if (0 < count) {
        float *pfVar1 = reinterpret_cast<float *>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0] + 0x14);
        do {
            if (*pfVar1 < *reinterpret_cast<float *>(static_cast<intptr_t>(self) + 0x54)) {
                iVar2 = iVar2 + -1;
                if (4 < iVar2) {
                    int iVar3 = count - iVar2;
                    if (iVar3 < 2) {
                        iVar3 = 2;
                        iVar2 = count + -2;
                    }
                    memmove(reinterpret_cast<void **>(static_cast<intptr_t>(self) + 0x24)[0],
                            reinterpret_cast<void *>(reinterpret_cast<intptr_t>(reinterpret_cast<uint32_t *>(static_cast<intptr_t>(self) + 0x24)[0]) + iVar2 * 0x18),
                            static_cast<size_t>(iVar3 * 0x18));
                    memmove(param_1,
                            reinterpret_cast<void *>(iVar2 * 0x90 + reinterpret_cast<intptr_t>(param_1)),
                            static_cast<size_t>(iVar3 * 0x90));
                    memmove(param_2,
                            reinterpret_cast<void *>(iVar2 * 0xc0 + reinterpret_cast<intptr_t>(param_2)),
                            static_cast<size_t>(iVar3 * 0xc0));
                    memmove(param_3,
                            reinterpret_cast<void *>(iVar2 * 0x60 + reinterpret_cast<intptr_t>(param_3)),
                            static_cast<size_t>(iVar3 * 0x60));
                    return iVar3 * 2 + -2;
                }
                break;
            }
            iVar2 = iVar2 + 1;
            pfVar1 = pfVar1 + 6;
        } while (iVar2 < count);
    }
    return count * 2 + -2;
}

// 0x5108a0 — observed shape
extern int FUN_00449390(void *a, int b);
extern void96 FUN_0050f5b0(int a, void *b, void *c, int d, int e, int f, void *self);
extern void FUN_00510240(int a, float b, int c, int d, int e);
extern int FUN_005107e0(void *a, void *b, void *c, void *self, int count);
extern void FUN_00541300(int a, int b, int c, int d, int e, int f, int g);
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_00533d10(int a, int b);
extern uint8_t DAT_007278d4;

bool FUN_005108a0(float param_1, void *self)
{
    int32_t *s = static_cast<int32_t *>(self);
    float local_20 = 0.0f;
    if (s[0] == 0 || (local_20 = param_1 - static_cast<float>(s[0x14]), local_20 == 0.0f)) {
        return false;
    }
    s[0x14] = static_cast<int32_t>(param_1);
    int iVar5 = *reinterpret_cast<int *>(*reinterpret_cast<int *>(self) + 0xbc);
    int iVar10 = FUN_00449390(&DAT_007278d4, iVar5);
    int iVar6 = s[7];
    uint32_t local_18 = *reinterpret_cast<uint32_t *>(iVar6 + 0x90);
    uint32_t local_14 = *reinterpret_cast<uint32_t *>(iVar6 + 0x94);
    uint32_t local_10 = *reinterpret_cast<uint32_t *>(iVar6 + 0x98);
    iVar6 = s[8];
    uint32_t local_c = *reinterpret_cast<uint32_t *>(iVar6 + 0x90);
    uint32_t local_8 = *reinterpret_cast<uint32_t *>(iVar6 + 0x94);
    uint32_t local_4 = *reinterpret_cast<uint32_t *>(iVar6 + 0x98);
    (void)local_18;
    (void)local_14;
    (void)local_10;
    (void)local_c;
    (void)local_8;
    (void)local_4;
    if (iVar10 == 0) {
        return false;
    }
    uint32_t uVar7 = *reinterpret_cast<uint32_t *>(iVar5 + 0x20);
    uint32_t uVar8 = *reinterpret_cast<uint32_t *>(iVar5 + 0x2c);
    uint16_t uVar4 = *reinterpret_cast<uint16_t *>(iVar10 + 0x3c);
    uint32_t uVar9 = *reinterpret_cast<uint32_t *>(iVar5 + 0x28);
    int16_t sVar12 = static_cast<int16_t>((uVar4 >> 1) + 1);
    if ((static_cast<int32_t>(uVar4 + 2) < s[0x17]) && (reinterpret_cast<uint8_t *>(self)[24] != 0)) {
        if (uVar4 == 0) {
            local_20 = 0.0f;
            uint32_t tmpLive[3] = {local_c, local_8, local_4};
            uint32_t tmpVtx[3] = {local_18, local_14, local_10};
            FUN_0050f5b0(0, tmpLive, tmpVtx, static_cast<int>(uVar7), static_cast<int>(uVar9), static_cast<int>(uVar8), self);
            sVar12 = 1;
        }
        uint32_t tmpLive2[3] = {local_c, local_8, local_4};
        uint32_t tmpVtx2[3] = {local_18, local_14, local_10};
        FUN_0050f5b0(sVar12, tmpLive2, tmpVtx2, static_cast<int>(uVar7), static_cast<int>(uVar9), static_cast<int>(uVar8), self);
    }
    FUN_00510240(*reinterpret_cast<int *>(self), local_20, sVar12, static_cast<int>(uVar9), static_cast<int>(uVar8));
    int uVar11 = FUN_005107e0(reinterpret_cast<void *>(uVar7), reinterpret_cast<void *>(uVar9), reinterpret_cast<void *>(uVar8), self, sVar12);
    float fVar2 = static_cast<float>(s[0x15]);
    float fVar3 = *reinterpret_cast<float *>(s[9] + 0x14 + ((uVar11 & 0xffff) >> 1) * 0x18);
    *reinterpret_cast<int16_t *>(iVar10 + 0x3c) = static_cast<int16_t>(uVar11);
    uint8_t *pbVar1 = reinterpret_cast<uint8_t *>(*reinterpret_cast<int *>(self) + 0x20);
    if (static_cast<int16_t>(uVar11) == 0) {
        *pbVar1 = static_cast<uint8_t>(*pbVar1 | 1u);
    } else {
        *pbVar1 = static_cast<uint8_t>(*pbVar1 & 0xfeu);
    }
    FUN_00541300((uVar11 * 3 + 6) * 2, static_cast<int>(uVar7), 0, static_cast<int>(uVar9), static_cast<int>(uVar8), 1, 0);
    *reinterpret_cast<uint16_t *>(iVar10 + 0x32) = static_cast<uint16_t>(*reinterpret_cast<uint16_t *>(iVar10 + 0x32) | 0x0fffu);
    FUN_00534130();
    FUN_00534350();
    FUN_00533d10(0, 1);
    return fVar3 == fVar2;
}

// 0x510a60 — observed shape
extern void *thunk_FUN_00533c78(int size);
extern void FUN_004127b0(void *dst, int elem, int count, void *init);
extern void *FUN_005473e0(short a, void *b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern void FUN_004aac50(void **pp);
extern void FUN_00540460(const char *s);
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_00533d10(int a, int b);

void FUN_00510a60(void *self)
{
    int32_t *s = static_cast<int32_t *>(self);
    if (s[0] == 0) {
        int iVar6 = s[0x16];
        uint32_t *local_4 = static_cast<uint32_t *>(thunk_FUN_00533c78(iVar6 * 0x90));
        if (local_4 == nullptr) {
            local_4 = nullptr;
        } else {
            FUN_004127b0(local_4, 0x90, iVar6, reinterpret_cast<void *>(0x5cea70u));
        }
        iVar6 = s[0x16];
        int iVar3 = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(iVar6 * 0xc0)));
        int iVar7 = 0;
        if (iVar3 != 0) {
            FUN_004127b0(reinterpret_cast<void *>(iVar3), 0xc0, iVar6, reinterpret_cast<void *>(0x510cd0u));
            iVar7 = iVar3;
        }
        iVar6 = s[0x16];
        iVar3 = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(iVar6 * 0x60)));
        if (iVar3 == 0) {
            iVar3 = 0;
        } else {
            FUN_004127b0(reinterpret_cast<void *>(iVar3), 0x60, iVar6, reinterpret_cast<void *>(0x5cea70u));
        }
        uint32_t *puVar4 = static_cast<uint32_t *>(thunk_FUN_00533c78(s[0x16] * 0x18));
        s[9] = static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar4));
        for (uint32_t uVar5 = static_cast<uint32_t>(s[0x16] * 0x18) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        for (int dead = 0; dead != 0; dead = dead + -1) {
            *reinterpret_cast<uint8_t *>(puVar4) = 0;
            puVar4 = reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puVar4) + 1);
        }
        int alloc = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(0xcc)));
        uint32_t *newObj = nullptr;
        if (alloc == 0) {
            newObj = nullptr;
        } else {
            newObj = static_cast<uint32_t *>(FUN_005473e0(static_cast<short>(s[0x16]), local_4, 0, iVar7, iVar3, 0, 0, 0, 0, 0, 0));
        }
        uint32_t *puVar2 = reinterpret_cast<uint32_t *>(s[0]);
        if (puVar2 != newObj) {
            if (puVar2 != nullptr) {
                int32_t *piVar1 = reinterpret_cast<int32_t *>(puVar2) + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using DelFn = void (__cdecl *)(int);
                    DelFn dtorFn = reinterpret_cast<DelFn>(puVar2[0]);
                    dtorFn(1);
                }
            }
            s[0] = static_cast<int32_t>(reinterpret_cast<intptr_t>(newObj));
            if (newObj != nullptr) {
                newObj[1] = newObj[1] + 1;
            }
        }
        int iVar6b = FUN_00449390(&DAT_007278d4, *reinterpret_cast<int *>(*reinterpret_cast<int32_t *>(self) + 0xbc));
        if (iVar6b != 0) {
            *reinterpret_cast<uint16_t *>(iVar6b + 0x3c) = 0;
            *reinterpret_cast<uint8_t *>(*reinterpret_cast<int *>(self) + 0x20) = static_cast<uint8_t>(*reinterpret_cast<uint8_t *>(*reinterpret_cast<int *>(self) + 0x20) | 1u);
        }
        FUN_00540460("FTrail");
        uint32_t *slots[5] = {
            reinterpret_cast<uint32_t *>(s[1]),
            reinterpret_cast<uint32_t *>(s[2]),
            reinterpret_cast<uint32_t *>(s[3]),
            reinterpret_cast<uint32_t *>(s[4]),
            reinterpret_cast<uint32_t *>(s[5]),
        };
        for (int k = 0; k < 5; ++k) {
            uint32_t *pu = slots[k];
            if (pu != nullptr) {
                pu[1] = pu[1] + 1;
            }
            uint32_t *local_copy = pu;
            FUN_004aac50(reinterpret_cast<void **>(&local_copy));
            if (pu != nullptr) {
                int32_t *piVar1 = reinterpret_cast<int32_t *>(pu) + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using DelFn = void (__cdecl *)(int);
                    DelFn dtorFn = reinterpret_cast<DelFn>(pu[0]);
                    dtorFn(1);
                }
            }
        }
        FUN_00534130();
        FUN_00534350();
        FUN_00533d10(0, 1);
    }
}

// 0x510d00 — observed shape
extern int FUN_005f0ddc();
extern void FUN_00510a60(void *self);

void FUN_00510d00(int param_1, void *self)
{
    int32_t *s = static_cast<int32_t *>(self);
    s[0x15] = param_1;
    int iVar3 = FUN_005f0ddc();
    s[0x16] = (iVar3 + 1) * 0x5a0 + 2;
    uint32_t *puVar2 = reinterpret_cast<uint32_t *>(s[0]);
    s[0x17] = (iVar3 + 1) * 0x2d0;
    if (puVar2 != nullptr) {
        int32_t *piVar1 = reinterpret_cast<int32_t *>(puVar2) + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(puVar2[0]);
            dtorFn(1);
        }
        s[0] = 0;
        if (reinterpret_cast<void *>(s[9]) != nullptr) {
            operator_delete(reinterpret_cast<void *>(s[9]));
            s[9] = 0;
        }
        FUN_00510a60(self);
    }
}

// 0x510d70 — observed shape
void FUN_00510d70(float *param_1, float param_2, float *self)
{
    float fVar1 = self[1];
    float fVar2 = self[2];
    float fVar3 = self[3];
    param_1[0] = self[0] * param_2;
    param_1[1] = fVar1 * param_2;
    param_1[2] = fVar2 * param_2;
    param_1[3] = fVar3 * param_2;
}

// 0x510df0 — observed shape
void FUN_00510df0(float *param_1, float *param_2, float *self)
{
    float fVar4 = self[1];
    float fVar5 = self[2];
    float fVar6 = self[3];
    float fVar1 = param_2[1];
    float fVar2 = param_2[2];
    float fVar3 = param_2[3];
    param_1[0] = self[0] + param_2[0];
    param_1[1] = fVar4 + fVar1;
    param_1[2] = fVar5 + fVar2;
    param_1[3] = fVar6 + fVar3;
}

// 0x510e60 — observed shape
void FUN_00510e60(void *self)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;
    s[3] = 0;
    uint32_t *p1 = reinterpret_cast<uint32_t *>(s[1]);
    if (p1 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p1) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p1[0]);
            dtorFn(1);
        }
        s[1] = 0;
    }
    uint32_t *p0 = reinterpret_cast<uint32_t *>(s[0]);
    if (p0 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p0) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p0[0]);
            dtorFn(1);
        }
        s[0] = 0;
    }
    uint32_t *p2 = reinterpret_cast<uint32_t *>(s[2]);
    if (p2 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p2) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p2[0]);
            dtorFn(1);
        }
        s[2] = 0;
    }
    uint32_t *p3 = reinterpret_cast<uint32_t *>(s[3]);
    if (p3 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(p3) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(p3[0]);
            dtorFn(1);
        }
        s[3] = 0;
    }
    s[8] = 0;
}

// 0x510ed0 — observed shape
extern void *thunk_FUN_00533c78(int size);
extern void *FUN_00537950();
extern void FUN_004cce40();
extern void *FUN_0054c210(int a, int b, void *c, void *d);
extern void96 FUN_00551c10();
extern void FUN_00551ce0();
extern void FUN_0054bc90();
extern void FUN_00540c50();
extern void FUN_004aac50(void **pp);
extern void *FUN_005428c0();
extern void *FUN_005446d0();
extern void FUN_00535de0(int n);
extern uint32_t DAT_008ea08c[];
extern uint32_t PTR_FUN_007117c8[];
extern uint32_t PTR_FUN_00711770[];
extern uint32_t PTR_FUN_00711808[];
extern uint32_t PTR_FUN_0070bf10[];
extern uint32_t PTR_FUN_00711820[];

void FUN_00510ed0(void *self, void *self_esi)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    int iVar4 = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(500)));
    uint32_t *puVar5 = nullptr;
    if (iVar4 == 0) {
        puVar5 = nullptr;
    } else {
        puVar5 = static_cast<uint32_t *>(FUN_00537950());
    }
    uint32_t *puVar6 = reinterpret_cast<uint32_t *>(s[0]);
    if (puVar6 != puVar5) {
        if (puVar6 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar6) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar6[0]);
                dtorFn(1);
            }
        }
        s[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar5));
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    uint32_t *src = reinterpret_cast<uint32_t *>(s[0] + 0x128);
    uint32_t local_1c[4];
    uint32_t *dst = local_1c;
    for (int n = 7; n != 0; n = n - 1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
    }
    uint32_t uStack_8 = 0x461c4000;
    uint32_t uStack_c = 0x42c80000;
    (void)uStack_8;
    (void)uStack_c;
    FUN_004cce40();
    uint32_t uStack_24 = 2;
    uint32_t uStack_20 = 3;
    uint32_t uStack_28 = 2;
    uint32_t stackInit[3] = {uStack_28, uStack_24, uStack_20};
    (void)stackInit;
    puVar6 = static_cast<uint32_t *>(FUN_0054c210(0x100, 0x100, DAT_008ea08c, stackInit));
    puVar5 = reinterpret_cast<uint32_t *>(s[1]);
    if (puVar5 != puVar6) {
        if (puVar5 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar5) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar5[0]);
                dtorFn(1);
            }
        }
        s[1] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar6));
        if (puVar6 != nullptr) {
            puVar6[1] = puVar6[1] + 1;
        }
    }
    uint32_t *piVar2 = DAT_008ea08c;
    int holder = s[0];
    uint32_t *piVar7 = reinterpret_cast<uint32_t *>(*reinterpret_cast<uint32_t *>(holder + 0x188));
    if (piVar7 != DAT_008ea08c) {
        if (piVar7 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(piVar7) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(piVar7[0]);
                dtorFn(1);
            }
        }
        *reinterpret_cast<uint32_t *>(holder + 0x188) = static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar2));
        if (piVar2 != nullptr) {
            piVar2[1] = piVar2[1] + 1;
        }
    }
    iVar4 = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(0x180)));
    if (iVar4 == 0) {
        puVar5 = nullptr;
    } else {
        puVar5 = static_cast<uint32_t *>(FUN_00551c10());
    }
    puVar6 = reinterpret_cast<uint32_t *>(s[2]);
    if (puVar6 != puVar5) {
        if (puVar6 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar6) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar6[0]);
                dtorFn(1);
            }
        }
        s[2] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar5));
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    int h2 = static_cast<int>(s[2]);
    puVar5 = reinterpret_cast<uint32_t *>(s[1]);
    puVar6 = reinterpret_cast<uint32_t *>(*reinterpret_cast<uint32_t *>(h2 + 0x144));
    if (puVar6 != puVar5) {
        if (puVar6 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar6) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar6[0]);
                dtorFn(1);
            }
        }
        *reinterpret_cast<uint32_t *>(h2 + 0x144) = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar5));
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    *reinterpret_cast<uint32_t *>(h2 + 0x148) = 1;
    *reinterpret_cast<uint32_t *>(h2 + 0x14c) = 0;
    *reinterpret_cast<uint32_t *>(h2 + 0x150) = 1;
    *reinterpret_cast<uint32_t *>(h2 + 0x154) = 0;
    FUN_00551ce0();
    puVar5 = static_cast<uint32_t *>(thunk_FUN_00533c78(0x30));
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    } else {
        FUN_0054bc90();
        puVar5[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_FUN_007117c8));
        puVar5[7] = 0;
        puVar5[5] = 0;
        puVar5[6] = 0;
        puVar5[4] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_FUN_00711808));
        puVar5[11] = 0;
        puVar5[9] = 0;
        puVar5[10] = 0;
        puVar5[8] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_FUN_00711770));
    }
    puVar6 = reinterpret_cast<uint32_t *>(s[3]);
    if (puVar6 != puVar5) {
        if (puVar6 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar6) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar6[0]);
                dtorFn(1);
            }
        }
        s[3] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar5));
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    puVar5 = static_cast<uint32_t *>(thunk_FUN_00533c78(0x2c));
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    } else {
        FUN_00540c50();
        puVar5[10] = 1;
        puVar5[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_FUN_0070bf10));
        *reinterpret_cast<uint16_t *>(puVar5 + 8) = 0;
        puVar5[9] = 0;
        puVar5[1] = puVar5[1] + 1;
    }
    puVar5[9] = 0;
    puVar5[10] = 0;
    puVar5[1] = puVar5[1] + 1;
    uint32_t *puStack_38 = puVar5;
    FUN_004aac50(reinterpret_cast<void **>(&puStack_38));
    {
        int32_t *rc = reinterpret_cast<int32_t *>(puVar5) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(puVar5[0]);
            dtorFn(1);
        }
    }
    iVar4 = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(100)));
    if (iVar4 == 0) {
        puVar5 = nullptr;
    } else {
        puVar5 = static_cast<uint32_t *>(FUN_005446d0());
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    uint32_t uStack_34 = 0x3f400000;
    puVar5[0x12] = 0x3f400000;
    uint32_t uStack_30 = 0x3f400000;
    puVar5[0x13] = 0x3f400000;
    uint32_t uStack_2c = 0x3f400000;
    puVar5[0x14] = 0x3f400000;
    puVar5[0x17] = puVar5[0x17] + 2;
    puVar5[0x16] = 0x3f800000;
    puVar5[1] = puVar5[1] + 1;
    (void)uStack_34;
    (void)uStack_30;
    (void)uStack_2c;
    puStack_38 = puVar5;
    FUN_004aac50(reinterpret_cast<void **>(&puStack_38));
    {
        int32_t *rc = reinterpret_cast<int32_t *>(puVar5) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(puVar5[0]);
            dtorFn(1);
        }
    }
    iVar4 = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(0x48)));
    if (iVar4 == 0) {
        puVar6 = nullptr;
    } else {
        puVar6 = static_cast<uint32_t *>(FUN_005428c0());
    }
    if (puVar6 != nullptr) {
        puVar6[1] = puVar6[1] + 1;
    }
    puStack_38 = puVar6;
    FUN_004aac50(reinterpret_cast<void **>(&puStack_38));
    if (puVar6 != nullptr) {
        int32_t *rc = reinterpret_cast<int32_t *>(puVar6) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(puVar6[0]);
            dtorFn(1);
        }
    }
    puVar6 = static_cast<uint32_t *>(thunk_FUN_00533c78(0x24));
    if (puVar6 == nullptr) {
        puVar6 = nullptr;
    } else {
        FUN_00540c50();
        puVar6[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_FUN_00711820));
        *reinterpret_cast<uint16_t *>(puVar6 + 8) = 1;
    }
    *reinterpret_cast<uint8_t *>(puVar6 + 8) = static_cast<uint8_t>(*reinterpret_cast<uint8_t *>(puVar6 + 8) & 0xfeu);
    puVar6[1] = puVar6[1] + 1;
    puStack_38 = puVar6;
    FUN_004aac50(reinterpret_cast<void **>(&puStack_38));
    {
        int32_t *rc = reinterpret_cast<int32_t *>(puVar6) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(puVar6[0]);
            dtorFn(1);
        }
    }
    {
        using CallFn = void (__cdecl *)(uint32_t);
        CallFn call40 = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(DAT_008ea08c[0] + 0x40));
        call40(s[1]);
    }
    uint32_t oneStack[3] = {0x3f800000u, 0x3f800000u, 0x3f800000u};
    {
        using CallFn = void (__cdecl *)(void *);
        CallFn call74 = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(DAT_008ea08c[0] + 0x74));
        call74(oneStack);
    }
    FUN_00535de0(5);
    puVar6 = reinterpret_cast<uint32_t *>(DAT_008ea08c[3]);
    uint32_t *puVar3 = reinterpret_cast<uint32_t *>(s[3]);
    uint32_t *piVar7 = DAT_008ea08c + 3;
    if (puVar6 != puVar3) {
        if (puVar6 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar6) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar6[0]);
                dtorFn(1);
            }
        }
        *piVar7 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar3));
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    {
        using CallFn = void (__cdecl *)();
        CallFn call70 = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(s[0] + 0x70));
        call70();
    }
    puVar3 = reinterpret_cast<uint32_t *>(DAT_008ea08c[3]);
    piVar7 = DAT_008ea08c + 3;
    if (puVar3 != puVar6) {
        if (puVar3 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar3) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar3[0]);
                dtorFn(1);
            }
        }
        *piVar7 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar6));
        if (puVar6 != nullptr) {
            puVar6[1] = puVar6[1] + 1;
        }
    }
    {
        using CallFn = void (__cdecl *)(uint32_t);
        CallFn call40 = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(DAT_008ea08c[0] + 0x40));
        call40(0);
    }
    {
        int32_t *rc = reinterpret_cast<int32_t *>(puVar5) + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(puVar5[0]);
            dtorFn(1);
        }
    }
    uint32_t *esi = static_cast<uint32_t *>(self_esi);
    if (esi != nullptr) {
        uint32_t old = esi[1];
        esi[1] = old - 1;
        if (old - 1 == 0) {
            using DelFn = void (__cdecl *)(int);
            DelFn dtorFn = reinterpret_cast<DelFn>(esi[0]);
            dtorFn(1);
        }
    }
}

// 0x511330 — observed shape
extern float DAT_00727430;
extern float DAT_00727434;
extern float DAT_00727438;
extern void FUN_00533d10(int a, int b);

void FUN_00511330(void *self)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    int iVar7 = s[0];
    float local_24[4];
    float local_14f = 0.0f;
    float local_10f = 0.0f;
    float local_cf = 0.0f;
    float local_8f = 0.0f;
    float local_4f = 0.0f;
    local_24[2] = 1.0f / (s[4] * 2.1f);
    local_24[3] = -static_cast<float>(*reinterpret_cast<double *>(iVar7 + 0x110)) * local_24[2];
    local_14f = static_cast<float>(-static_cast<double>(*reinterpret_cast<double *>(iVar7 + 0x114)) * local_24[2]);
    local_10f = local_24[2] * static_cast<float>(-static_cast<double>(*reinterpret_cast<double *>(iVar7 + 0x118)));
    local_cf = DAT_00727430;
    local_24[0] = local_24[2] * *reinterpret_cast<float *>(iVar7 + 0x11c);
    local_8f = DAT_00727434;
    local_24[1] = local_24[2] * *reinterpret_cast<float *>(iVar7 + 0x120);
    local_4f = DAT_00727438;
    local_24[2] = local_24[2] * *reinterpret_cast<float *>(iVar7 + 0x124);
    (void)local_cf;
    (void)local_8f;
    (void)local_4f;
    float fVar1 = *reinterpret_cast<float *>(iVar7 + 0x98);
    float fVar2 = *reinterpret_cast<float *>(iVar7 + 0x94);
    float fVar3 = *reinterpret_cast<float *>(iVar7 + 0x90);
    float fVar4 = *reinterpret_cast<float *>(iVar7 + 0x98);
    float fVar5 = *reinterpret_cast<float *>(iVar7 + 0x94);
    float fVar6 = *reinterpret_cast<float *>(iVar7 + 0x90);
    float *pfVar8 = local_24;
    float *pfVar9 = reinterpret_cast<float *>(s[2] + 0xe4);
    for (int n = 9; n != 0; n = n - 1) {
        *pfVar9 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar9 = pfVar9 + 1;
    }
    iVar7 = static_cast<int>(s[2]);
    *reinterpret_cast<float *>(iVar7 + 0x108) = -((local_24[0] * fVar3 + local_24[1] * fVar2 + local_24[2] * fVar1) - 0.5f);
    *reinterpret_cast<float *>(iVar7 + 0x10c) = -((local_24[3] * fVar6 + local_14f * fVar5 + local_10f * fVar4) - 0.5f);
    *reinterpret_cast<uint32_t *>(iVar7 + 0x110) = 0;
    FUN_00533d10(0, 1);
}

// 0x511480 — observed shape
extern float DAT_007177c4;
extern float DAT_007177b8;
extern float DAT_007177ac;
extern void FUN_00533d10b(int a, int b);
extern void FUN_00536b00(void *a, void *b);
extern void FUN_004cce40b();

void FUN_00511480(void *self)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    int iVar2 = static_cast<int>(s[4]);
    float local_40 = *reinterpret_cast<float *>(iVar2 + 0x28);
    float local_3c = *reinterpret_cast<float *>(iVar2 + 0x2c);
    float local_20 = static_cast<float>(s[7]) * 5000.0f;
    int iVar6 = static_cast<int>(s[0]);
    float local_38 = *reinterpret_cast<float *>(iVar2 + 0x30);
    float local_34 = local_40 - static_cast<float>(s[5]) * 5000.0f;
    float local_30 = local_3c - static_cast<float>(s[6]) * 5000.0f;
    *reinterpret_cast<float *>(iVar6 + 0x5c) = local_34;
    float local_2c = local_38 - local_20;
    *reinterpret_cast<float *>(iVar6 + 0x60) = local_30;
    *reinterpret_cast<float *>(iVar6 + 100) = local_2c;
    FUN_00533d10b(0, 1);
    float fVar1 = static_cast<float>(s[5]) * static_cast<float>(s[5]);
    float fVar3 = static_cast<float>(s[6]) * static_cast<float>(s[6]);
    float fVar4 = static_cast<float>(s[7]) * static_cast<float>(s[7]);
    uint32_t *puVar9 = nullptr;
    if (fVar3 <= fVar1) {
        if (fVar4 < fVar3) {
            puVar9 = reinterpret_cast<uint32_t *>(&DAT_007177c4);
        } else {
            puVar9 = reinterpret_cast<uint32_t *>(&DAT_007177b8);
        }
    } else if (fVar1 <= fVar4) {
        puVar9 = reinterpret_cast<uint32_t *>(&DAT_007177ac);
    } else {
        puVar9 = reinterpret_cast<uint32_t *>(&DAT_007177c4);
    }
    FUN_00536b00(&local_40, puVar9);
    FUN_00533d10b(0, 1);
    iVar2 = static_cast<int>(s[0]);
    fVar3 = local_40 - *reinterpret_cast<float *>(iVar2 + 0x90);
    float fVar5 = local_3c - *reinterpret_cast<float *>(iVar2 + 0x94);
    fVar4 = local_38 - *reinterpret_cast<float *>(iVar2 + 0x98);
    fVar1 = *reinterpret_cast<float *>(static_cast<int>(s[4]) + 0x34);
    float *pfVar7 = reinterpret_cast<float *>(iVar2 + 0x128);
    float local_1c[7];
    float *pfVar8 = local_1c;
    for (int n = 7; n != 0; n = n - 1) {
        *pfVar8 = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pfVar8 = pfVar8 + 1;
    }
    local_1c[1] = (fVar1 / sqrt(fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4)) * 1.05f;
    local_1c[0] = -local_1c[1];
    local_1c[2] = local_1c[1];
    local_1c[3] = local_1c[0];
    FUN_004cce40b();
}

// 0x511610 — observed shape
extern void FUN_00511480c();
extern void FUN_00535de0c(int n);
extern void FUN_00511330c();
extern uint32_t DAT_008ea08c_1610[];

void FUN_00511610(void *self, void *self_esi)
{
    FUN_00511480c();
    uint32_t *s = static_cast<uint32_t *>(self_esi);
    {
        using CallFn = void (__cdecl *)(uint32_t);
        CallFn callFn = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(DAT_008ea08c_1610[0] + 0x40));
        callFn(s[1]);
    }
    uint8_t auStack_a[10];
    {
        using CallFn = void (__cdecl *)(void *);
        CallFn callFn = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(DAT_008ea08c_1610[0] + 0x74));
        callFn(auStack_a - 6);
    }
    FUN_00535de0c(5);
    uint32_t *puVar2 = reinterpret_cast<uint32_t *>(DAT_008ea08c_1610[3]);
    uint32_t *puVar3 = reinterpret_cast<uint32_t *>(s[3]);
    uint32_t *piVar4 = DAT_008ea08c_1610 + 3;
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar2) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar2[0]);
                dtorFn(1);
            }
        }
        *piVar4 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar3));
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    {
        using CallFn = void (__cdecl *)();
        CallFn callFn = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(s[0] + 0x70));
        callFn();
    }
    puVar3 = reinterpret_cast<uint32_t *>(DAT_008ea08c_1610[3]);
    piVar4 = DAT_008ea08c_1610 + 3;
    if (puVar3 != puVar2) {
        if (puVar3 != nullptr) {
            int32_t *rc = reinterpret_cast<int32_t *>(puVar3) + 1;
            *rc = *rc - 1;
            if (*rc == 0) {
                using DelFn = void (__cdecl *)(int);
                DelFn dtorFn = reinterpret_cast<DelFn>(puVar3[0]);
                dtorFn(1);
            }
        }
        *piVar4 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar2));
        if (puVar2 != nullptr) {
            puVar2[1] = puVar2[1] + 1;
        }
    }
    {
        using CallFn = void (__cdecl *)(uint32_t);
        CallFn callFn = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(DAT_008ea08c_1610[0] + 0x40));
        callFn(0);
    }
    FUN_00511330c();
}

// 0x511700 — observed shape
extern void FUN_00538400();
extern uint32_t PTR_FUN_00711788[];
extern void operator_delete_b(void *p);

void FUN_00511700(uint8_t param_1, void *self)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    s[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_FUN_00711788));
    FUN_00538400();
    if ((param_1 & 1u) != 0) {
        operator_delete_b(self);
    }
}

// 0x511740 — observed shape
extern void FUN_00524f10();
extern void operator_delete_c(void *p);

void FUN_00511740(uint8_t param_1, void *self)
{
    FUN_00524f10();
    if ((param_1 & 1u) != 0) {
        operator_delete_c(self);
    }
}

// 0x511790 — observed shape
extern void FUN_005edba0();
extern uint32_t PTR_FUN_00711808[];
extern uint32_t PTR_LAB_00711814[];
extern void operator_delete_d(void *p);

void FUN_00511790(uint8_t param_1, void *self)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    s[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_FUN_00711808));
    FUN_005edba0();
    s[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_LAB_00711814));
    if ((param_1 & 1u) != 0) {
        operator_delete_d(self);
    }
}

// 0x5117e0 — observed shape
extern void FUN_005edba0b();
extern uint32_t PTR_FUN_00711770[];
extern uint32_t PTR_LAB_0071177c[];
extern void operator_delete_e(void *p);

void FUN_005117e0(uint8_t param_1, void *self)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    s[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_FUN_00711770));
    FUN_005edba0b();
    s[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(PTR_LAB_0071177c));
    if ((param_1 & 1u) != 0) {
        operator_delete_e(self);
    }
}

// 0x511810 — observed shape
extern void FUN_0053ad50();
extern uint8_t DAT_00727560[];
extern uint8_t DAT_0072743c[];

void FUN_00511810(void *self)
{
    uint32_t *s = static_cast<uint32_t *>(self);
    if (s != nullptr) {
        uint32_t base = s[0];
        using GetFn = uint32_t *(__cdecl *)();
        GetFn getFn = reinterpret_cast<GetFn>(*reinterpret_cast<uint32_t *>(base + 4));
        uint32_t *puVar3 = getFn();
        if (puVar3 != nullptr) {
            while (puVar3 != reinterpret_cast<uint32_t *>(DAT_00727560)) {
                puVar3 = reinterpret_cast<uint32_t *>(puVar3[1]);
                if (puVar3 == nullptr) {
                    return;
                }
            }
            FUN_0053ad50();
            uint32_t uVar4 = 0;
            if (s[0x30] != 0) {
                if (s[0x30] == 0) goto LAB_005118ac;
                do {
                    uint32_t *piVar1 = reinterpret_cast<uint32_t *>(*reinterpret_cast<uint32_t *>(s[0x2e] + uVar4 * 4));
                    if (piVar1 != nullptr) {
                        for (uint32_t *node = reinterpret_cast<GetFn>(*reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t>(piVar1) + 4))();
                             node != nullptr; node = reinterpret_cast<uint32_t *>(node[1])) {
                            if (node == reinterpret_cast<uint32_t *>(DAT_0072743c)) {
                                uint32_t *puStack_4 = nullptr;
                                {
                                    using CallFn = void (__cdecl *)(uint32_t *, uint32_t *);
                                    CallFn callFn = reinterpret_cast<CallFn>(*reinterpret_cast<uint32_t *>(s[0] + 0x74));
                                    callFn(&puStack_4, reinterpret_cast<uint32_t *>(piVar1));
                                }
                                if (puStack_4 != nullptr) {
                                    uint32_t old = puStack_4[1];
                                    puStack_4[1] = old - 1;
                                    if (old - 1 == 0) {
                                        using DelFn = void (__cdecl *)(int);
                                        DelFn dtorFn = reinterpret_cast<DelFn>(puStack_4[0]);
                                        dtorFn(1);
                                    }
                                }
                                break;
                            }
                        }
                    }
                LAB_005118ac:
                    uVar4 = uVar4 + 1;
                } while (uVar4 < s[0x30]);
            }
        }
    }
}
