#include <cstdint>
#include <cstddef>

extern void operator_delete(void*);
extern void FUN_005511b0(void);
extern void FUN_00538400(void);
extern void* FUN_00533c78(uint32_t);
extern void FUN_00540c50(void);
extern void FUN_0053adc0(int, uint32_t);
extern void FUN_005579c0(void*);
extern void* FUN_00548b20(void*, void*);
extern void FUN_0053c9e0(void*, void*);
extern void FUN_0053ee40(void*, void*, int);

extern void* PTR_FUN_006c291c;
extern void* PTR_FUN_00711820;
extern float DAT_00727430;
extern float DAT_00727434;
extern float DAT_00727438;
extern void* DAT_00727c9c;

// 0x554280 — observed shape
void FUN_00554280(void* self, uint8_t param_1)
{
    uint32_t* obj = static_cast<uint32_t*>(self);
    obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c291c);
    operator_delete(reinterpret_cast<void*>(obj[5]));
    FUN_005511b0();
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(obj[3]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
    }
    FUN_00538400();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5542d0 — observed shape
void FUN_005542d0(void* self, int param_1, int param_2, float* param_3, uint32_t* param_4, uint32_t* param_5,
                  uint32_t* param_6, uint32_t* param_7, int param_8)
{
    float local_188[13];
    float local_148;
    float local_144;
    float local_140;
    float local_13c;
    float local_138;
    float local_134;
    float local_130;
    float local_12c;
    float local_128;
    float local_178;
    float local_174;
    float local_170;
    float local_16c;
    float local_168;
    float local_164;
    float local_160;
    float local_15c;
    float local_164_b;
    float local_160_b;
    float local_15c_b;
    float local_148_b;
    float local_144_b;
    float local_140_b;
    float local_13c_b;
    float local_138_b;
    float local_134_b;
    float local_130_b;
    float local_12c_b;
    float local_128_b;
    float local_100;
    float local_e0;
    float local_e0_b;
    float local_dc;
    float local_ec;
    float local_f8;
    float local_120;
    float local_11c;
    float local_118;
    float local_114;
    float local_110;
    float local_10c;
    float local_108;
    float local_104;
    float local_1a0;
    float local_19c;
    float local_198;
    float local_18c_f;
    float fVar1;
    float fVar2;
    float fVar3;
    uint16_t uVar4;
    void* local_14c = self;
    int iVar10 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0xc);
    int iVar7 = *reinterpret_cast<int*>(iVar10 + 0x48);
    uint32_t local_190 = *reinterpret_cast<uint32_t*>(iVar10 + 0x44);
    uint32_t* puVar5;
    uint32_t local_d0[13];
    uint8_t local_9c[52];
    uint8_t local_68[52];
    uint8_t local_34[52];
    FUN_005579c0(local_9c);
    puVar5 = static_cast<uint32_t*>(FUN_00548b20(local_188, local_9c));
    for (int i = 0xd; i != 0; i--) {
        local_d0[0xd - i] = *puVar5;
        puVar5++;
    }
    // local_158 alias for struct copy used by FUN_0053c9e0
    void* local_158 = local_d0;
    if ((param_2 == 0) || (param_5 == nullptr)) {
        puVar5 = param_4;
        if (param_8 == 0xc) {
            for (uint32_t u = (uint32_t)(static_cast<int>((intptr_t)param_3) * 0xc) >> 2; u != 0; u--) {
                *puVar5 = 0; puVar5++;
            }
        } else {
            float* p = param_3;
            while (p != nullptr) {
                puVar5[0] = static_cast<uint32_t>(DAT_00727430);
                puVar5[1] = static_cast<uint32_t>(DAT_00727434);
                puVar5[2] = static_cast<uint32_t>(DAT_00727438);
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar5) + param_8);
                p = reinterpret_cast<float*>(reinterpret_cast<intptr_t>(p) + -1);
            }
        }
        uint32_t* local_1ac = nullptr;
        if (local_190 != 0) {
            int* piVar12 = reinterpret_cast<int*>(iVar7 + 0x44);
            do {
                uVar4 = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(piVar12) + 4);
                int* piVar16 = piVar12 + -0x11;
                FUN_00548b20(local_68, reinterpret_cast<void*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(local_14c) + 0x14) + (int)(intptr_t)local_1ac * 4) + 0x6c));
                float* pfVar6 = static_cast<float*>(FUN_00548b20(local_34, piVar16));
                float* pfVar14 = local_188;
                for (int i = 0xd; i != 0; i--) { *pfVar14 = *pfVar6; pfVar6++; pfVar14++; }
                FUN_0053c9e0(&local_148, local_158);
                int iVar10b = *piVar12;
                uint32_t uVar8 = 0;
                if (uVar4 != 0) {
                    do {
                        local_18c_f = *reinterpret_cast<float*>(iVar10b + 4 + uVar8 * 8);
                        uint32_t uVar9 = *reinterpret_cast<uint16_t*>(iVar10b + uVar8 * 8);
                        float* local_150 = reinterpret_cast<float*>(uVar9 * param_8 + reinterpret_cast<intptr_t>(param_4));
                        float* pf6 = reinterpret_cast<float*>(param_1 + uVar9 * 0xc);
                        local_1a0 = local_148 * pf6[0] + local_144 * pf6[1] + local_140 * pf6[2] + local_164;
                        local_19c = local_13c * pf6[0] + local_138 * pf6[1] + local_134 * pf6[2] + local_160;
                        local_198 = local_130 * pf6[0] + local_12c * pf6[1] + local_128 * pf6[2] + local_15c;
                        local_150[0] = local_1a0 * local_18c_f + local_150[0];
                        local_150[1] = local_19c * local_18c_f + local_150[1];
                        local_150[2] = local_198 * local_18c_f + local_150[2];
                        uVar8++;
                    } while (uVar8 < uVar4);
                }
                local_1ac = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(local_1ac) + 1);
                piVar12 = piVar12 + 0x13;
            } while (local_1ac < reinterpret_cast<uint32_t*>(local_190));
        }
        return;
    }
    if ((param_6 == nullptr) || (param_7 == nullptr)) {
        if (param_8 == 0xc) {
            puVar5 = param_4;
            for (uint32_t u = (uint32_t)(static_cast<int>((intptr_t)param_3) * 0xc) >> 2; u != 0; u--) { *puVar5 = 0; puVar5++; }
            puVar5 = param_5;
            for (uint32_t u = (uint32_t)(static_cast<int>((intptr_t)param_3) * 0xc) >> 2; u != 0; u--) { *puVar5 = 0; puVar5++; }
        } else if (param_3 != nullptr) {
            float* local_1a8 = param_3;
            puVar5 = param_4;
            uint32_t* puVar11 = param_5;
            do {
                puVar5[0] = static_cast<uint32_t>(DAT_00727430); puVar5[1] = static_cast<uint32_t>(DAT_00727434); puVar5[2] = static_cast<uint32_t>(DAT_00727438);
                puVar11[0] = static_cast<uint32_t>(DAT_00727430); puVar11[1] = static_cast<uint32_t>(DAT_00727434); puVar11[2] = static_cast<uint32_t>(DAT_00727438);
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar5) + param_8);
                puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar11) + param_8);
                local_1a8 = reinterpret_cast<float*>(reinterpret_cast<intptr_t>(local_1a8) + -1);
            } while (local_1a8 != nullptr);
        }
        uint32_t* local_1ac = nullptr;
        if (local_190 != 0) {
            float* local_1b0 = reinterpret_cast<float*>(iVar7 + 0x44);
            do {
                uVar4 = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(local_1b0) + 4);
                float* pfVar6 = local_1b0 + -0x11;
                FUN_00548b20(local_68, reinterpret_cast<void*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(local_14c) + 0x14) + (int)(intptr_t)local_1ac * 4) + 0x6c));
                pfVar6 = static_cast<float*>(FUN_00548b20(local_34, pfVar6));
                float* pfVar14 = local_188;
                for (int i = 0xd; i != 0; i--) { *pfVar14 = *pfVar6; pfVar6++; pfVar14++; }
                float fVar13 = *local_1b0;
                local_18c_f = fVar13;
                FUN_0053c9e0(&local_148, local_158);
                uint32_t uVar8 = 0;
                if (uVar4 != 0) {
                    while (true) {
                        fVar1 = *reinterpret_cast<float*>(static_cast<intptr_t>(fVar13) + 4 + uVar8 * 8);
                        uint32_t uVar9 = *reinterpret_cast<uint16_t*>(static_cast<intptr_t>(fVar13) + uVar8 * 8);
                        int iVar7b = uVar9 * param_8;
                        int iVar10b = uVar9 * 0xc;
                        fVar13 = *reinterpret_cast<float*>(iVar10b + 8 + param_1);
                        fVar2 = *reinterpret_cast<float*>(iVar10b + 4 + param_1);
                        fVar3 = *reinterpret_cast<float*>(iVar10b + param_1);
                        float* pf6 = reinterpret_cast<float*>(iVar10b + 8 + param_2);
                        local_ec = local_130 * *reinterpret_cast<float*>(iVar10b + param_1) + local_12c * *reinterpret_cast<float*>(iVar10b + 4 + param_1) + local_128 * *reinterpret_cast<float*>(iVar10b + 8 + param_1) + local_15c;
                        local_1a0 = local_188[2] * pf6[0] + local_188[0] * *reinterpret_cast<float*>(iVar10b + param_2) + local_188[1] * *reinterpret_cast<float*>(iVar10b + 4 + param_2);
                        local_19c = local_174 * pf6[0] + local_188[3] * *reinterpret_cast<float*>(iVar10b + param_2) + local_178 * *reinterpret_cast<float*>(iVar10b + 4 + param_2);
                        local_198 = local_168 * pf6[0] + local_170 * *reinterpret_cast<float*>(iVar10b + param_2) + local_16c * *reinterpret_cast<float*>(iVar10b + 4 + param_2);
                        local_100 = (local_148 * *reinterpret_cast<float*>(iVar10b + param_1) + local_144 * *reinterpret_cast<float*>(iVar10b + 4 + param_1) + local_140 * *reinterpret_cast<float*>(iVar10b + 8 + param_1) + local_164) * fVar1;
                        *reinterpret_cast<float*>(iVar7b + reinterpret_cast<intptr_t>(param_4)) = local_100 + *reinterpret_cast<float*>(iVar7b + reinterpret_cast<intptr_t>(param_4));
                        *reinterpret_cast<float*>(iVar7b + 4 + reinterpret_cast<intptr_t>(param_4)) = (local_13c * fVar3 + local_138 * fVar2 + local_134 * fVar13 + local_160) * fVar1 + *reinterpret_cast<float*>(iVar7b + 4 + reinterpret_cast<intptr_t>(param_4));
                        *reinterpret_cast<float*>(iVar7b + 8 + reinterpret_cast<intptr_t>(param_4)) = local_ec * fVar1 + *reinterpret_cast<float*>(iVar7b + 8 + reinterpret_cast<intptr_t>(param_4));
                        uVar8++;
                        local_120 = local_19c * fVar1;
                        local_11c = local_198 * fVar1;
                        *reinterpret_cast<float*>(iVar7b + reinterpret_cast<intptr_t>(param_5)) = local_1a0 * fVar1 + *reinterpret_cast<float*>(iVar7b + reinterpret_cast<intptr_t>(param_5));
                        *reinterpret_cast<float*>(iVar7b + 4 + reinterpret_cast<intptr_t>(param_5)) = local_120 + *reinterpret_cast<float*>(iVar7b + 4 + reinterpret_cast<intptr_t>(param_5));
                        *reinterpret_cast<float*>(iVar7b + 8 + reinterpret_cast<intptr_t>(param_5)) = local_11c + *reinterpret_cast<float*>(iVar7b + 8 + reinterpret_cast<intptr_t>(param_5));
                        if (uVar4 <= uVar8) break;
                        fVar13 = local_18c_f;
                    }
                }
                local_1ac = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(local_1ac) + 1);
                local_1b0 = local_1b0 + 0x13;
            } while (local_1ac < reinterpret_cast<uint32_t*>(local_190));
        }
        FUN_0053ee40(param_5, param_3, param_8);
        return;
    }
    uint32_t uVar8 = static_cast<uint32_t>(static_cast<int>((intptr_t)param_3) * 0xc);
    float* local_154 = reinterpret_cast<float*>(uVar8 + param_2);
    float local_18c = static_cast<float>(reinterpret_cast<intptr_t>(local_154) + uVar8);
    if (param_8 == 0xc) {
        puVar5 = param_4;
        for (uint32_t u = uVar8 >> 2; u != 0; u--) { *puVar5 = 0; puVar5++; }
        puVar5 = param_5;
        for (uint32_t u = uVar8 >> 2; u != 0; u--) { *puVar5 = 0; puVar5++; }
        puVar5 = param_6;
        for (uint32_t u = uVar8 >> 2; u != 0; u--) { *puVar5 = 0; puVar5++; }
        puVar5 = param_7;
        for (uint32_t u = uVar8 >> 2; u != 0; u--) { *puVar5 = 0; puVar5++; }
    } else {
        float* local_1b0 = reinterpret_cast<float*>(param_6);
        uint32_t* local_1ac2 = param_7;
        if (param_3 != nullptr) {
            float* local_194 = param_3;
            puVar5 = param_4;
            uint32_t* puVar11 = param_5;
            do {
                puVar5[0] = static_cast<uint32_t>(DAT_00727430); puVar5[1] = static_cast<uint32_t>(DAT_00727434); puVar5[2] = static_cast<uint32_t>(DAT_00727438);
                puVar11[0] = static_cast<uint32_t>(DAT_00727430); puVar11[1] = static_cast<uint32_t>(DAT_00727434); puVar11[2] = static_cast<uint32_t>(DAT_00727438);
                local_1b0[0] = DAT_00727430; local_1b0[1] = DAT_00727434; local_1b0[2] = DAT_00727438;
                local_1b0 = reinterpret_cast<float*>(reinterpret_cast<char*>(local_1b0) + param_8);
                local_1ac2[0] = static_cast<uint32_t>(DAT_00727430); local_1ac2[1] = static_cast<uint32_t>(DAT_00727434); local_1ac2[2] = static_cast<uint32_t>(DAT_00727438);
                local_1ac2 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(local_1ac2) + param_8);
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar5) + param_8);
                puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar11) + param_8);
                local_194 = reinterpret_cast<float*>(reinterpret_cast<intptr_t>(local_194) + -1);
            } while (local_194 != nullptr);
        }
    }
    uint32_t* local_1ac = nullptr;
    if (local_190 != 0) {
        float* local_1b0 = reinterpret_cast<float*>(iVar7 + 0x44);
        do {
            uVar4 = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(local_1b0) + 4);
            uint32_t* puVar5b = reinterpret_cast<uint32_t*>(local_1b0 + -0x11);
            FUN_00548b20(local_34, reinterpret_cast<void*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(local_14c) + 0x14) + (int)(intptr_t)local_1ac * 4) + 0x6c));
            float* pfVar6 = static_cast<float*>(FUN_00548b20(local_68, puVar5b));
            float* pfVar14 = local_188;
            for (int i = 0xd; i != 0; i--) { *pfVar14 = *pfVar6; pfVar6++; pfVar14++; }
            float* pf6b = reinterpret_cast<float*>(*local_1b0);
            float* local_150 = pf6b;
            FUN_0053c9e0(&local_148, local_158);
            uVar8 = 0;
            if (uVar4 != 0) {
                while (true) {
                    float f13 = pf6b[uVar8 * 2 + 1];
                    int i7 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(pf6b) + uVar8 * 4)) * param_8;
                    int i10 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(pf6b) + uVar8 * 4)) * 0xc;
                    fVar1 = *reinterpret_cast<float*>(i10 + 4 + param_1);
                    fVar2 = *reinterpret_cast<float*>(i10 + 8 + param_1);
                    fVar3 = *reinterpret_cast<float*>(i10 + param_1);
                    float* pf11 = reinterpret_cast<float*>(i10 + 8 + (intptr_t)local_154);
                    float* pl194 = reinterpret_cast<float*>(i10 + 4 + (intptr_t)local_154);
                    local_e0 = local_130 * *reinterpret_cast<float*>(i10 + param_1) + local_128 * *reinterpret_cast<float*>(i10 + 8 + param_1) + local_12c * *reinterpret_cast<float*>(i10 + 4 + param_1) + local_15c;
                    local_10c = local_188[0] * *reinterpret_cast<float*>(i10 + param_2) + local_188[1] * *reinterpret_cast<float*>(i10 + 4 + param_2) + local_188[2] * *reinterpret_cast<float*>(i10 + 8 + param_2);
                    local_108 = local_174 * *reinterpret_cast<float*>(i10 + 8 + param_2) + local_188[3] * *reinterpret_cast<float*>(i10 + param_2) + local_178 * *reinterpret_cast<float*>(i10 + 4 + param_2);
                    local_104 = local_168 * *reinterpret_cast<float*>(i10 + 8 + param_2) + local_170 * *reinterpret_cast<float*>(i10 + param_2) + local_16c * *reinterpret_cast<float*>(i10 + 4 + param_2);
                    local_118 = local_188[1] * pl194[0] + local_188[2] * pf11[0] + local_188[0] * *reinterpret_cast<float*>(i10 + (intptr_t)local_154);
                    local_114 = local_178 * pl194[0] + local_174 * pf11[0] + local_188[3] * *reinterpret_cast<float*>(i10 + (intptr_t)local_154);
                    local_110 = local_16c * pl194[0] + local_168 * pf11[0] + local_170 * *reinterpret_cast<float*>(i10 + (intptr_t)local_154);
                    local_1a0 = local_188[0] * *reinterpret_cast<float*>(i10 + (intptr_t)local_18c) + local_188[1] * *reinterpret_cast<float*>(i10 + 4 + (intptr_t)local_18c) + local_188[2] * *reinterpret_cast<float*>(i10 + 8 + (intptr_t)local_18c);
                    local_19c = local_188[3] * *reinterpret_cast<float*>(i10 + (intptr_t)local_18c) + local_178 * *reinterpret_cast<float*>(i10 + 4 + (intptr_t)local_18c) + local_174 * *reinterpret_cast<float*>(i10 + 8 + (intptr_t)local_18c);
                    local_198 = local_170 * *reinterpret_cast<float*>(i10 + (intptr_t)local_18c) + local_16c * *reinterpret_cast<float*>(i10 + 4 + (intptr_t)local_18c) + local_168 * *reinterpret_cast<float*>(i10 + 8 + (intptr_t)local_18c);
                    local_dc = (local_148 * *reinterpret_cast<float*>(i10 + param_1) + local_140 * *reinterpret_cast<float*>(i10 + 8 + param_1) + local_144 * *reinterpret_cast<float*>(i10 + 4 + param_1) + local_164) * f13;
                    *reinterpret_cast<float*>(i7 + (intptr_t)param_4) = local_dc + *reinterpret_cast<float*>(i7 + (intptr_t)param_4);
                    *reinterpret_cast<float*>(i7 + 4 + (intptr_t)param_4) = (local_13c * fVar3 + local_134 * fVar2 + local_138 * fVar1 + local_160) * f13 + *reinterpret_cast<float*>(i7 + 4 + (intptr_t)param_4);
                    *reinterpret_cast<float*>(i7 + 8 + (intptr_t)param_4) = local_e0 * f13 + *reinterpret_cast<float*>(i7 + 8 + (intptr_t)param_4);
                    local_f8 = local_104 * f13;
                    *reinterpret_cast<float*>(i7 + (intptr_t)param_5) = local_10c * f13 + *reinterpret_cast<float*>(i7 + (intptr_t)param_5);
                    *reinterpret_cast<float*>(i7 + 4 + (intptr_t)param_5) = local_108 * f13 + *reinterpret_cast<float*>(i7 + 4 + (intptr_t)param_5);
                    *reinterpret_cast<float*>(i7 + 8 + (intptr_t)param_5) = local_f8 + *reinterpret_cast<float*>(i7 + 8 + (intptr_t)param_5);
                    uVar8++;
                    local_ec = local_110 * f13;
                    *reinterpret_cast<float*>(i7 + (intptr_t)param_6) = local_118 * f13 + *reinterpret_cast<float*>(i7 + (intptr_t)param_6);
                    *reinterpret_cast<float*>(i7 + 4 + (intptr_t)param_6) = local_114 * f13 + *reinterpret_cast<float*>(i7 + 4 + (intptr_t)param_6);
                    *reinterpret_cast<float*>(i7 + 8 + (intptr_t)param_6) = local_ec + *reinterpret_cast<float*>(i7 + 8 + (intptr_t)param_6);
                    local_120 = local_19c * f13;
                    local_11c = local_198 * f13;
                    *reinterpret_cast<float*>(i7 + (intptr_t)param_7) = local_1a0 * f13 + *reinterpret_cast<float*>(i7 + (intptr_t)param_7);
                    *reinterpret_cast<float*>(i7 + 4 + (intptr_t)param_7) = local_120 + *reinterpret_cast<float*>(i7 + 4 + (intptr_t)param_7);
                    *reinterpret_cast<float*>(i7 + 8 + (intptr_t)param_7) = local_11c + *reinterpret_cast<float*>(i7 + 8 + (intptr_t)param_7);
                    if (uVar4 <= uVar8) break;
                    pf6b = local_150;
                }
            }
            local_1ac = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(local_1ac) + 1);
            local_1b0 = local_1b0 + 0x13;
        } while (local_1ac < reinterpret_cast<uint32_t*>(local_190));
    }
    FUN_0053ee40(param_5, param_3, param_8);
    FUN_0053ee40(param_6, param_3, param_8);
    FUN_0053ee40(param_7, param_3, param_8);
}

// 0x554eb0 — observed shape
void FUN_00554eb0(void)
{
    uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x24));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_00540c50();
        puVar3[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711820);
        *reinterpret_cast<uint16_t*>(puVar3 + 8) = 1;
    }
    uint32_t* puVar2 = static_cast<uint32_t*>(DAT_00727c9c);
    if (DAT_00727c9c != puVar3) {
        if ((DAT_00727c9c != nullptr) && (puVar2[1]--, puVar2[1] == 0)) {
            using Fn = void(__cdecl*)(int);
            reinterpret_cast<Fn>(*puVar2)(1);
        }
        DAT_00727c9c = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] += 1;
        }
    }
}

// 0x554f10 — observed shape
void FUN_00554f10(void)
{
    uint32_t* puVar2 = static_cast<uint32_t*>(DAT_00727c9c);
    if (DAT_00727c9c != nullptr) {
        int iVar1 = puVar2[1];
        puVar2[1] = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            using Fn = void(__cdecl*)(int);
            reinterpret_cast<Fn>(*puVar2)(1);
        }
        DAT_00727c9c = nullptr;
    }
}

// 0x554fd0 — observed shape
void FUN_00554fd0(int param_1, uint32_t param_2, void* self)
{
    FUN_0053adc0(param_1, param_2);
    *reinterpret_cast<uint32_t*>(param_1 + 0xec) = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0xec);
    if (*reinterpret_cast<int**>(static_cast<char*>(self) + 0xf0) == nullptr) {
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(param_1 + 0xf0);
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 += -1;
            if (*piVar1 == 0) {
                using Fn = void(__cdecl*)(int);
                reinterpret_cast<Fn>(*puVar2)(1);
            }
            *reinterpret_cast<uint32_t*>(param_1 + 0xf0) = 0;
        }
    } else {
        int** f0 = *reinterpret_cast<int**>(static_cast<char*>(self) + 0xf0);
        using Factory = uint32_t*(__cdecl*)(uint32_t);
        Factory fac = reinterpret_cast<Factory>(*(*f0 + 8));
        uint32_t* puVar3 = fac(param_2);
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(param_1 + 0xf0);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 += -1;
                if (*piVar1 == 0) {
                    using Fn = void(__cdecl*)(int);
                    reinterpret_cast<Fn>(*puVar2)(1);
                }
            }
            *reinterpret_cast<uint32_t**>(param_1 + 0xf0) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] += 1;
                return;
            }
        }
    }
}
extern void FUN_0053bf20(uint32_t);
extern uint32_t* FUN_00545600(void);
extern void* thunk_FUN_00540cf0(void*, uint32_t);
extern void FUN_0053ac80(int);
extern void FUN_00540c90(void);
extern void FUN_00540410(int);
extern void* FUN_00557b10(void*);
extern void FUN_006b34a0(int);
extern void FUN_005606f0(uint32_t, void*);
extern void* PTR_FUN_00712854;
extern void* PTR_FUN_006c2980;
extern void* DAT_00727cb0;
extern void* DAT_00727ca8;

// 0x555060 — observed shape
void FUN_00555060(uint32_t param_1, void* self)
{
    FUN_0053bf20(param_1);
    uint32_t* puVar3 = FUN_00545600();
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0xf0);
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 += -1;
            if (*piVar1 == 0) {
                using Fn = void(__cdecl*)(int);
                reinterpret_cast<Fn>(*puVar2)(1);
            }
        }
        *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0xf0) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] += 1;
        }
    }
}

// 0x555140 — observed shape
void FUN_00555140(int param_1, void* self)
{
    int iVar2 = *reinterpret_cast<int*>(param_1 + 0x188);
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(iVar2 + 0xc);
    if (puVar3 != nullptr) {
        puVar3[1] += 1;
    }
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0xec) == 1) {
        uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(iVar2 + 0xc);
        if (puVar4 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
            *piVar1 += -1;
            if (*piVar1 == 0) {
                using Fn = void(__cdecl*)(int);
                reinterpret_cast<Fn>(*puVar4)(1);
            }
            *reinterpret_cast<uint32_t*>(iVar2 + 0xc) = 0;
        }
    } else if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0xec) == 2) {
        uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0xf0);
        uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(iVar2 + 0xc);
        if (puVar5 != puVar4) {
            if (puVar5 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar5 + 1);
                *piVar1 += -1;
                if (*piVar1 == 0) {
                    using Fn = void(__cdecl*)(int);
                    reinterpret_cast<Fn>(*puVar5)(1);
                }
            }
            *reinterpret_cast<uint32_t**>(iVar2 + 0xc) = puVar4;
            if (puVar4 != nullptr) {
                puVar4[1] += 1;
            }
        }
        int** f0 = *reinterpret_cast<int**>(static_cast<char*>(self) + 0xf0);
        bool cVar6 = false;
        if (f0 != nullptr) {
            using Pred = char(__cdecl*)(int);
            Pred pred = reinterpret_cast<Pred>(*(*f0 + 0x34));
            cVar6 = (pred(param_1) == '\0');
        }
        if ((f0 == nullptr) || cVar6) {
            uint32_t* puVar4b = *reinterpret_cast<uint32_t**>(iVar2 + 0xc);
            if (puVar4b != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar4b + 1);
                *piVar1 += -1;
                if (*piVar1 == 0) {
                    using Fn = void(__cdecl*)(int);
                    reinterpret_cast<Fn>(*puVar4b)(1);
                }
                *reinterpret_cast<uint32_t*>(iVar2 + 0xc) = 0;
            }
            FUN_0053ac80(param_1);
        } else {
            FUN_0053ac80(param_1);
            using After = void(__cdecl*)();
            After after = reinterpret_cast<After>(*(*f0 + 0x38));
            after();
        }
        goto LAB_00555209;
    }
    FUN_0053ac80(param_1);
LAB_00555209:
    iVar2 = *reinterpret_cast<int*>(param_1 + 0x188);
    uint32_t* puVar4c = *reinterpret_cast<uint32_t**>(iVar2 + 0xc);
    if (puVar4c != puVar3) {
        if (puVar4c != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar4c + 1);
            *piVar1 += -1;
            if (*piVar1 == 0) {
                using Fn = void(__cdecl*)(int);
                reinterpret_cast<Fn>(*puVar4c)(1);
            }
        }
        *reinterpret_cast<uint32_t**>(iVar2 + 0xc) = puVar3;
        if (puVar3 == nullptr) {
            return;
        }
        puVar3[1] += 1;
    }
    if (puVar3 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
        *piVar1 += -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            reinterpret_cast<Fn>(*puVar3)(1);
        }
    }
}

// 0x555340 — observed shape
void FUN_00555340(void* self)
{
    *reinterpret_cast<void**>(self) = &PTR_FUN_00712854;
}

// 0x5553b0 — observed shape
void FUN_005553b0(void* self)
{
    FUN_00540c50();
    uint32_t* obj = static_cast<uint32_t*>(self);
    obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c2980);
    obj[8] = 0;
}

// 0x5553f0 — observed shape
uint32_t* FUN_005553f0(uint32_t param_1, void* self)
{
    uint32_t* puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x24));
    if (puVar1 == nullptr) {
        puVar1 = nullptr;
    } else {
        FUN_00540c50();
        puVar1[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c2980);
        puVar1[8] = 0;
    }
    if (*reinterpret_cast<int**>(static_cast<char*>(self) + 0x20) == nullptr) {
        puVar1[8] = 0;
        thunk_FUN_00540cf0(puVar1, param_1);
        return puVar1;
    }
    int** p = *reinterpret_cast<int**>(static_cast<char*>(self) + 0x20);
    using Fac = uint32_t(__cdecl*)(uint32_t);
    Fac fac = reinterpret_cast<Fac>(*(*p + 8));
    puVar1[8] = fac(param_1);
    thunk_FUN_00540cf0(puVar1, param_1);
    return puVar1;
}

// 0x555490 — observed shape
void FUN_00555490(uint8_t param_1, void* self)
{
    uint32_t* obj = static_cast<uint32_t*>(self);
    obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c2980);
    if (static_cast<uint32_t*>(reinterpret_cast<void*>(obj[8])) != nullptr) {
        using Fn = void(__cdecl*)(int);
        uint32_t* t = reinterpret_cast<uint32_t*>(obj[8]);
        reinterpret_cast<Fn>(*t)(1);
    }
    FUN_00540c90();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5554d0 — observed shape
void FUN_005554d0(void)
{
    uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x24));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_00540c50();
        puVar3[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c2980);
        puVar3[8] = 0;
    }
    uint32_t* puVar2 = static_cast<uint32_t*>(DAT_00727cb0);
    if (DAT_00727cb0 != puVar3) {
        if ((DAT_00727cb0 != nullptr) && (puVar2[1]--, puVar2[1] == 0)) {
            using Fn = void(__cdecl*)(int);
            reinterpret_cast<Fn>(*puVar2)(1);
        }
        DAT_00727cb0 = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] += 1;
        }
    }
}

// 0x555530 — observed shape
void FUN_00555530(void)
{
    uint32_t* puVar2 = static_cast<uint32_t*>(DAT_00727cb0);
    if (DAT_00727cb0 != nullptr) {
        int iVar1 = puVar2[1];
        puVar2[1] = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            using Fn = void(__cdecl*)(int);
            reinterpret_cast<Fn>(*puVar2)(1);
        }
        DAT_00727cb0 = nullptr;
    }
}

// 0x555560 — observed shape
void FUN_00555560(int param_1)
{
    int iVar2 = param_1;
    FUN_00540410(param_1);
    int p1 = (int)(intptr_t)FUN_00557b10(DAT_00727ca8);
    uint32_t* pu = reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    uint32_t uVar1 = *pu;
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &p1);
}

// 0x5555b0 — observed shape
void FUN_005555b0(uint16_t param_1, float* param_2, float* param_3, float* param_4)
{
    uint32_t uVar13 = param_1;
    if (uVar13 != 0) {
        do {
            float fVar1 = param_2[0];
            float fVar2 = param_4[3];
            float fVar3 = param_2[1];
            float fVar4 = param_4[4];
            float fVar5 = param_2[2];
            float fVar6 = param_4[5];
            param_3[0] = param_2[1] * param_4[1] + param_2[0] * param_4[0] + param_2[2] * param_4[2];
            float fVar7 = param_2[0];
            float fVar8 = param_4[6];
            float fVar9 = param_2[1];
            float fVar10 = param_4[7];
            float fVar11 = param_2[2];
            float fVar12 = param_4[8];
            param_3[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
            param_2 = param_2 + 3;
            param_3[2] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;
            uVar13 -= 1;
            param_3 = param_3 + 3;
        } while (uVar13 != 0);
    }
}

// 0x555630 — observed shape
void FUN_00555630(uint32_t param_1, float* param_2, float* param_3, float* param_4)
{
    param_1 = param_1 & 0xffff;
    float fVar17 = param_4[9];
    float fVar18 = param_4[10];
    float fVar1 = param_4[0xc];
    float fVar19 = param_4[0xb];
    float fVar2 = param_4[0];
    float fVar3 = param_4[1];
    float fVar4 = param_4[2];
    float fVar5 = param_4[3];
    float fVar6 = param_4[4];
    float fVar7 = param_4[5];
    float fVar8 = param_4[6];
    float fVar9 = param_4[7];
    float fVar10 = param_4[8];
    if (param_1 != 0) {
        do {
            float fVar11 = param_2[0];
            float fVar12 = param_2[1];
            float fVar13 = param_2[2];
            float fVar14 = param_2[0];
            float fVar15 = param_2[1];
            float fVar16 = param_2[2];
            param_3[0] = param_2[1] * fVar1 * fVar3 + param_2[0] * fVar1 * fVar2 + param_2[2] * fVar1 * fVar4 + fVar17;
            param_3[1] = fVar12 * fVar1 * fVar6 + fVar11 * fVar1 * fVar5 + fVar13 * fVar1 * fVar7 + fVar18;
            param_2 = param_2 + 3;
            param_3[2] = fVar1 * fVar9 * fVar15 + fVar1 * fVar8 * fVar14 + fVar1 * fVar10 * fVar16 + fVar19;
            param_1 -= 1;
            param_3 = param_3 + 3;
        } while (param_1 != 0);
    }
}

extern uint32_t DAT_00727cb8;
extern uint32_t DAT_00727cbc;
extern uint32_t DAT_00727cb4;
extern void* PTR_FUN_00717a38;
extern uint32_t* cpuid(uint32_t);
extern uint32_t* cpuid_basic_info(uint32_t);
extern uint32_t* cpuid_Version_info(uint32_t);
extern uint32_t* cpuid_cache_tlb_info(uint32_t);
extern uint32_t* cpuid_serial_info(uint32_t);
extern uint32_t* cpuid_Deterministic_Cache_Parameters_info(uint32_t);
extern uint32_t* cpuid_MONITOR_MWAIT_Features_info(uint32_t);
extern uint32_t* cpuid_Thermal_Power_Management_info(uint32_t);
extern uint32_t* cpuid_Extended_Feature_Enumeration_info(uint32_t);
extern uint32_t* cpuid_Direct_Cache_Access_info(uint32_t);
extern uint32_t* cpuid_Architectural_Performance_Monitoring_info(uint32_t);
extern uint32_t* cpuid_Extended_Topology_info(uint32_t);
extern uint32_t* cpuid_Processor_Extended_States_info(uint32_t);
extern uint32_t* cpuid_Quality_of_Service_info(uint32_t);
extern uint32_t* cpuid_brand_part1_info(uint32_t);
extern uint32_t* cpuid_brand_part2_info(uint32_t);
extern uint32_t* cpuid_brand_part3_info(uint32_t);

// 0x555730 — observed shape
uint64_t FUN_00555730(void)
{
    uint32_t* puVar1;  // array of 4+ uint
    uint32_t uVar2;
    uint32_t uVar3;
    DAT_00727cb8 = 1;
    puVar1 = cpuid(0x80000000);
    uVar2 = puVar1[0] & 0x80000000;
    if (uVar2 != 0) {
        if (uVar2 == 0) {
            puVar1 = cpuid_basic_info(0);
        }
        else if (uVar2 == 1) {
            puVar1 = cpuid_Version_info(1);
        }
        else if (uVar2 == 2) {
            puVar1 = cpuid_cache_tlb_info(2);
        }
        else if (uVar2 == 3) {
            puVar1 = cpuid_serial_info(3);
        }
        else if (uVar2 == 4) {
            puVar1 = cpuid_Deterministic_Cache_Parameters_info(4);
        }
        else if (uVar2 == 5) {
            puVar1 = cpuid_MONITOR_MWAIT_Features_info(5);
        }
        else if (uVar2 == 6) {
            puVar1 = cpuid_Thermal_Power_Management_info(6);
        }
        else if (uVar2 == 7) {
            puVar1 = cpuid_Extended_Feature_Enumeration_info(7);
        }
        else if (uVar2 == 9) {
            puVar1 = cpuid_Direct_Cache_Access_info(9);
        }
        else if (uVar2 == 10) {
            puVar1 = cpuid_Architectural_Performance_Monitoring_info(10);
        }
        else if (uVar2 == 0xb) {
            puVar1 = cpuid_Extended_Topology_info(0xb);
        }
        else if (uVar2 == 0xd) {
            puVar1 = cpuid_Processor_Extended_States_info(0xd);
        }
        else if (uVar2 == 0xf) {
            puVar1 = cpuid_Quality_of_Service_info(0xf);
        }
        else if (uVar2 == 0x80000002) {
            puVar1 = cpuid_brand_part1_info(0x80000002);
        }
        else if (uVar2 == 0x80000003) {
            puVar1 = cpuid_brand_part2_info(0x80000003);
        }
        else if (uVar2 == 0x80000004) {
            puVar1 = cpuid_brand_part3_info(0x80000004);
        }
        else {
            puVar1 = cpuid(uVar2);
        }
        uVar2 = puVar1[0];
        uVar3 = puVar1[2];
        if ((uVar2 & 0x80000000) != 0) {
            DAT_00727cb4 = 6;
            DAT_00727cbc = uVar2;
            goto LAB_005558a0;
        }
    }
    puVar1 = cpuid_Version_info(1);
    uVar2 = puVar1[0];
    DAT_00727cbc = puVar1[2];
    uVar3 = DAT_00727cbc & 0x800000;
    if (uVar3 == 0) {
        uVar2 = DAT_00727cbc & 0x8000;
        if (uVar2 == 0) {
            DAT_00727cb4 = 1;
        }
        else {
            DAT_00727cb4 = 3;
        }
    }
    else if ((DAT_00727cbc & 0x8000) == 0) {
        DAT_00727cb4 = 2;
    }
    else {
        DAT_00727cb4 = 4;
        uVar3 = DAT_00727cbc & 0x2000000;
        if (uVar3 != 0) {
            DAT_00727cb4 = 5;
        }
    }
LAB_005558a0:
    return (static_cast<uint64_t>(uVar3) << 32) | uVar2;
}

// 0x5558c0 — observed shape
void FUN_005558c0(uint16_t param_1, float* param_2, float* param_3, float* param_4)
{
    for (uint32_t local_c = 0; local_c < param_1; local_c++) {
        param_3[0] = (param_2[2] * param_4[2] + param_2[1] * param_4[1] + param_4[0] * param_2[0]) * param_4[0xc] + param_4[9];
        param_3[1] = (param_2[2] * param_4[5] + param_2[1] * param_4[4] + param_4[3] * param_2[0]) * param_4[0xc] + param_4[10];
        param_3[2] = (param_2[2] * param_4[8] + param_2[1] * param_4[7] + param_4[6] * param_2[0]) * param_4[0xc] + param_4[0xb];
        param_2 = param_2 + 3;
        param_3 = param_3 + 3;
    }
}

// 0x5559b0 — observed shape
void FUN_005559b0(uint16_t param_1, float* param_2, float* param_3, float* param_4)
{
    for (uint32_t local_c = 0; local_c < param_1; local_c++) {
        param_3[0] = param_2[2] * param_4[2] + param_2[1] * param_4[1] + param_4[0] * param_2[0];
        param_3[1] = param_2[2] * param_4[5] + param_2[1] * param_4[4] + param_4[3] * param_2[0];
        param_3[2] = param_2[2] * param_4[8] + param_2[1] * param_4[7] + param_4[6] * param_2[0];
        param_2 = param_2 + 3;
        param_3 = param_3 + 3;
    }
}

// 0x555a80 — observed shape
void FUN_00555a80(void* param_1)
{
    PTR_FUN_00717a38 = param_1;
}
