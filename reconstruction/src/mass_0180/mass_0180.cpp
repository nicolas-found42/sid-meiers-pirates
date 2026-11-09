#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* DAT_007284fc;
extern void* DAT_007286dc;
extern void* DAT_00728664;
extern void* PTR_FUN_006c49a8;
extern void operator_delete(void* ptr);
extern uint32_t FUN_00538460(int param_1);
extern void FUN_00538400();
extern void FUN_00538430(int param_1);

// 0x57bd80 — observed shape
void FUN_0057bd80(void* self, int param_1, int param_2, uint32_t param_3)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int* pSelf10 = reinterpret_cast<int*>(selfBytes + 0x10);
    if (*pSelf10 != 0) {
        int idx = *reinterpret_cast<int*>(selfBytes + 0x14);
        void** table = static_cast<void**>(DAT_007284fc);
        typedef void (*Fn)(int);
        Fn fn = reinterpret_cast<Fn>(table[idx]);
        fn(*pSelf10);
    }
    if (param_1 == 0 || param_2 == 0) {
        *reinterpret_cast<int*>(selfBytes + 0xc) = 0;
        *reinterpret_cast<int*>(selfBytes + 0x10) = 0;
        *reinterpret_cast<int*>(selfBytes + 0x14) = 0;
        return;
    }
    *reinterpret_cast<int*>(selfBytes + 0xc) = param_2;
    *reinterpret_cast<int*>(selfBytes + 0x10) = param_1;
    *reinterpret_cast<uint32_t*>(selfBytes + 0x14) = param_3;
}

// 0x57be20 — observed shape
uint32_t FUN_0057be20(void* self, int param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint8_t* otherBytes = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    uint32_t uVar2 = FUN_00538460(param_1);
    int selfC = 0;
    uint32_t u14 = 0;
    if (static_cast<char>(uVar2) == 0
        || *reinterpret_cast<int*>(selfBytes + 0xc) != *reinterpret_cast<int*>(otherBytes + 0xc)
        || ((u14 = *reinterpret_cast<uint32_t*>(selfBytes + 0x14)),
            u14 != *reinterpret_cast<uint32_t*>(otherBytes + 0x14))) {
        return uVar2 & 0xffffff00u;
    }
    void** table = static_cast<void**>(DAT_007286dc);
    typedef uint32_t (*Fn)(int, int);
    Fn pcVar1 = reinterpret_cast<Fn>(table[uVar2]);
    uint32_t uVar3 = 0;
    if (*reinterpret_cast<int*>(selfBytes + 0xc) != 0) {
        do {
            int selfPtr = *reinterpret_cast<int*>(selfBytes + 0x10);
            int otherPtr = *reinterpret_cast<int*>(otherBytes + 0x10);
            uint8_t selfStride = *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(selfPtr) + 4);
            uint8_t otherStride = *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(otherPtr) + 4);
            uVar2 = pcVar1(static_cast<int>(selfStride) * static_cast<int>(uVar3) + selfPtr,
                               static_cast<int>(otherStride) * static_cast<int>(uVar3) + otherPtr);
            if (static_cast<char>(uVar2) == 0) {
                return uVar2 & 0xffffff00u;
            }
            uVar2 = *reinterpret_cast<uint32_t*>(selfBytes + 0xc);
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar2);
    }
    return (uVar2 & 0xffffff00u) | 1u;
}

// 0x57bea0 — observed shape
void FUN_0057bea0(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c49a8);
    // *in_ECX = &PTR_FUN_006c49a8;  // vtable assignment (extern symbol)
    if (in_ECX[4] != 0) {
        void** table = static_cast<void**>(DAT_007284fc);
        typedef void (*Fn)(uint32_t);
        Fn fn = reinterpret_cast<Fn>(table[in_ECX[5]]);
        fn(in_ECX[4]);
    }
    FUN_00538400();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x57bf60 — observed shape
void FUN_0057bf60(void* self, int param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint8_t* paramBytes = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    FUN_00538430(param_1);
    int* piVar1 = reinterpret_cast<int*>(selfBytes + 0xc);
    typedef void (*Fn)(int*, int);
    int** vtable = *reinterpret_cast<int***>(paramBytes + 0x160);
    Fn call1 = reinterpret_cast<Fn>(*(reinterpret_cast<uint8_t*>(vtable) + 0xc));
    call1(piVar1, 4);
    if (*piVar1 != 0) {
        Fn call2 = reinterpret_cast<Fn>(*(reinterpret_cast<uint8_t*>(vtable) + 0xc));
        call2(reinterpret_cast<int*>(selfBytes + 0x14), 4);
        void** table = static_cast<void**>(DAT_00728664);
        typedef void (*Fn2)(int, uint32_t, int);
        Fn2 fn = reinterpret_cast<Fn2>(table[*reinterpret_cast<int*>(selfBytes + 0x14)]);
        fn(param_1, *reinterpret_cast<uint32_t*>(selfBytes + 0x10), *piVar1);
    }
}

// 0x57c0a0 — observed shape
void FUN_0057c0a0(void* self, uint32_t* param_1, uint32_t* param_2, uint32_t* param_3)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int iVar1 = *reinterpret_cast<int*>(selfBytes + 0x50);
    if (iVar1 == 0) {
        *param_2 = 0;
        *param_3 = 0;
        *param_1 = 0;
        return;
    }
    uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1));
    *param_2 = *reinterpret_cast<uint32_t*>(p + 0xc);
    *param_3 = *reinterpret_cast<uint32_t*>(p + 0x14);
    *param_1 = *reinterpret_cast<uint32_t*>(p + 0x10);
}

extern void* PTR_FUN_006c49e0;
extern void FUN_00552d20();
extern void* DAT_00728844;
extern void* DAT_007287cc;
extern void* DAT_00717b84;
extern void* DAT_00717b70;
extern void FUN_00552f70(int param_1);
extern void* DAT_00727c5c;
extern void FUN_00545cc0();
extern float DAT_007179b0;
extern uint32_t FUN_00569600(float t, int a, int b, uint32_t c, void* o1, void* o2, void* o3, void* o4);
extern void FUN_004916d0(void* a, void* b);
extern void FUN_00431450(void* a, float w, void* b);
extern void* FUN_00497ca0(void* a, void* b);
extern void FUN_00491640();
extern void* FUN_00497cf0(void* a, void* b);
extern void FUN_0053c800(float a, float b, float c, float d);
extern void* FUN_0053c8d0(void* a, void* b);
extern float DAT_00728a00;
extern float DAT_00727c78;
extern uint8_t DAT_00728a04;

// 0x57c0f0 — observed shape
void FUN_0057c0f0(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    uint32_t* puVar2;
    int* piVar1;
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c49e0);
    puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x14]);
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*Fn)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
        in_ECX[0x14] = 0;
    }
    puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x15]);
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*Fn)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
        in_ECX[0x15] = 0;
    }
    operator_delete(reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[0x16])));
    puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x15]);
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*Fn)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
    }
    puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x14]);
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*Fn)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
    }
    FUN_00552d20();
}

// 0x57c180 — observed shape
void FUN_0057c180(void* self, uint32_t* param_1, int param_2, int param_3, uint32_t param_4)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int iVar1 = *reinterpret_cast<int*>(selfBytes + 0x50);
    int iVar2;
    int dataPtr;
    if (iVar1 == 0) {
        iVar2 = 0;
        dataPtr = 0;
    } else {
        uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1));
        iVar2 = *reinterpret_cast<int*>(p + 0x14);
        dataPtr = *reinterpret_cast<int*>(p + 0x10);
    }
    uint8_t local_c[16] = {0};
    void** table = static_cast<void**>(DAT_00728844);
    typedef void (*Fn)(uint32_t, int, int, void*);
    Fn fn = reinterpret_cast<Fn>(table[iVar2]);
    uint8_t stride = (dataPtr != 0) ? *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(dataPtr) + 4) : 0;
    fn(param_4, static_cast<int>(stride) * param_2 + dataPtr, static_cast<int>(stride) * param_3 + dataPtr, local_c);
    uint32_t* out = reinterpret_cast<uint32_t*>(local_c);
    param_1[0] = out[0];
    param_1[1] = out[1];
    param_1[2] = out[2];
}

// 0x57c1f0 — observed shape
// NEEDS_MANUAL: sub-operations FUN_00569600/FUN_004916d0/FUN_00431450/FUN_00497ca0/FUN_00497cf0/FUN_0053c800/FUN_0053c8d0 are complex interpolation paths; matrix locals preserved structurally, not semantically verified.
void FUN_0057c1f0(void* self, int param_1, uint32_t param_2, float param_3, float* param_4)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    float local_b4[9] = {0};
    float* pfVar9 = &DAT_007179b0;
    float* pfVar12 = local_b4;
    for (int iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) { *pfVar12 = *pfVar9; pfVar9 = pfVar9 + 1; pfVar12 = pfVar12 + 1; }
    int iVar11 = *reinterpret_cast<int*>(selfBytes + 0x50);
    if (iVar11 != 0) {
        uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar11));
        uint32_t uVar2 = *reinterpret_cast<uint32_t*>(p + 0xc);
        uint32_t uVar8 = *reinterpret_cast<uint32_t*>(p + 0x14);
        iVar11 = *reinterpret_cast<int*>(p + 0x10);
        uint8_t* data = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar11));
        if (1 < uVar2) {
            uint32_t uVar7 = static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(data + 4));
            float local_d0 = 0, local_d8 = 0, local_c0 = 0, local_cc = 0, local_c8 = 0, local_bc = 0, local_b8 = 0, local_9c = 0, local_a4 = 0, local_a0 = 0, local_98 = 0, local_88 = 0, local_8c = 0, local_90 = 0, local_78 = 0, local_74 = 0, local_70 = 0, local_c4 = 0, local_d4 = 0, local_7c = 0, local_94 = 0;
            float fVar1 = 0;
            if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 2 & 1) == 0)) {
                FUN_00569600(param_3, static_cast<int>(uVar7) * param_1 + iVar11, static_cast<int>(uVar7) * static_cast<int>(param_2) + iVar11, uVar8, &local_d0, &local_c0, &local_78, &local_d8);
                local_b4[0] = local_d0; local_b4[3] = local_cc; local_9c = local_c8;
                FUN_004916d0(&local_90, &local_d0);
                local_b4[1] = local_90; local_a4 = local_8c;
                local_b4[2] = local_88 * local_cc - local_8c * local_c8;
                local_a0 = local_c8 * local_90 - local_88 * local_d0;
                fVar1 = local_8c * local_d0 - local_cc * local_90;
                local_98 = local_88;
            } else {
                FUN_00569600(param_3, static_cast<int>(uVar7) * param_1 + iVar11, static_cast<int>(uVar7) * static_cast<int>(param_2) + iVar11, uVar8, &local_d0, &local_c0, &local_78, &local_d8);
                if (*reinterpret_cast<float*>(selfBytes + 100) != 0.0f) {
                    float f100 = *reinterpret_cast<float*>(selfBytes + 100);
                    fVar1 = 1.0f - f100;
                    if ((!(fVar1 != fVar1) || !(param_3 != param_3)) && (fVar1 < param_3 == (fVar1 == param_3))) {
                        if ((!(param_3 != param_3) && !(f100 != f100)) && (param_3 < f100 != (param_3 == f100))) {
                            int iVar10b;
                            if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 1 & 1) == 0) && (param_1 == 0)) iVar10b = static_cast<int>(uVar2) - 1; else iVar10b = param_1;
                            if (iVar10b != 0) {
                                // interpolated path: calls preserved in order
                                float local_84buf[4] = {0}; float local_6cbuf[16] = {0}; float local_60buf[16] = {0}; float local_54buf[16] = {0};
                                FUN_00569600(f100, uVar7 * param_1 + iVar11, uVar7 * static_cast<int>(param_2) + iVar11, uVar8, &local_90, &local_c0, &local_78, &local_d8);
                                FUN_00569600(1.0f - f100, (iVar10b - 1) * static_cast<int>(uVar7) + iVar11, static_cast<int>(uVar7) * iVar10b + iVar11, uVar8, &local_90, local_84buf, &local_78, &local_d4);
                                uint32_t u8 = 0; FUN_00431450(local_6cbuf, (f100 - param_3) / (f100 + f100), local_84buf);
                                FUN_00431450(local_54buf, 1.0f - ((f100 - param_3) / (f100 + f100)), &local_c0, local_60buf, u8);
                                float* qp = static_cast<float*>(FUN_00497ca0(local_60buf, u8)); local_c0 = qp[0]; local_bc = qp[1]; local_b8 = qp[2];
                                FUN_00491640(); local_d8 = (1.0f - ((f100 - param_3) / (f100 + f100))) * local_d8 + local_d4 * ((f100 - param_3) / (f100 + f100));
                                float* qp2 = static_cast<float*>(FUN_00497cf0(local_6cbuf, &local_c0)); local_78 = qp2[0]; local_74 = qp2[1]; local_70 = qp2[2];
                            }
                        }
                    } else {
                        uint32_t u7b = param_2;
                        if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 1 & 1) == 0) && (param_2 == uVar2 - 1)) u7b = 0;
                        if (u7b < uVar2 - 1) {
                            float local_84buf[4] = {0}; float local_6cbuf[16] = {0}; float local_60buf[16] = {0}; float local_54buf[16] = {0};
                            FUN_00569600(1.0f - f100, uVar7 * param_1 + iVar11, uVar7 * static_cast<int>(param_2) + iVar11, uVar8, &local_90, &local_c0, &local_78, &local_d8);
                            FUN_00569600(f100, static_cast<int>(uVar7) * static_cast<int>(u7b) + iVar11, (static_cast<int>(u7b) + 1) * static_cast<int>(uVar7) + iVar11, uVar8, &local_90, local_84buf, &local_78, &local_d4);
                            uint32_t u8 = 0; FUN_00431450(local_54buf, 1.0f - (((1.0f - param_3) + f100) / (f100 + f100)), local_84buf);
                            FUN_00431450(local_6cbuf, ((1.0f - param_3) + f100) / (f100 + f100), &local_c0, local_60buf, u8);
                            float* qp = static_cast<float*>(FUN_00497ca0(local_60buf, u8)); local_c0 = qp[0]; local_bc = qp[1]; local_b8 = qp[2];
                            FUN_00491640();
                            float* qp2 = static_cast<float*>(FUN_00497cf0(local_6cbuf, &local_c0)); local_78 = qp2[0]; local_74 = qp2[1]; local_70 = qp2[2];
                        }
                    }
                }
                local_b4[0] = local_d0; local_b4[3] = local_cc; local_9c = local_c8;
                local_b4[1] = -local_c0; local_a4 = -local_bc; local_b4[2] = -local_78;
                local_a0 = -local_74; fVar1 = -local_70; local_98 = -local_b8;
            }
            local_7c = fVar1;
            uint16_t bVar6 = *reinterpret_cast<uint16_t*>(selfBytes + 0x44);
            local_94 = fVar1;
            if (((bVar6 >> 6 & 1) != 0)) { local_9c = -local_c8; local_b4[0] = -local_d0; local_b4[3] = -local_cc; local_7c = -local_98; local_98 = -local_98; local_b4[1] = -local_b4[1]; local_a4 = -local_a4; }
            float fVar5 = local_98; float fVar4 = local_b4[3]; float fVar3 = local_b4[0];
            if (*reinterpret_cast<int16_t*>(selfBytes + 0x68) == 1) { local_7c = local_9c; local_98 = local_9c; local_88 = -fVar5; local_9c = -fVar5; local_b4[0] = -local_b4[1]; local_b4[3] = -local_a4; local_b4[1] = fVar3; local_a4 = fVar4; }
            else if (*reinterpret_cast<int16_t*>(selfBytes + 0x68) == 2) { local_7c = local_9c; local_94 = local_9c; local_88 = -fVar1; local_9c = -fVar1; local_b4[0] = -local_b4[2]; local_b4[3] = -local_a0; local_b4[2] = fVar3; local_a0 = fVar4; }
            if (((bVar6 >> 3 & 1) != 0)) {
                if ((DAT_00728a04 & 1) == 0) { DAT_00728a00 = 4.0f / DAT_00727c78; DAT_00728a04 = DAT_00728a04 | 1; }
                float ld4 = static_cast<float>(*reinterpret_cast<int*>(selfBytes + 0x70)) * *reinterpret_cast<float*>(selfBytes + 0x60);
                if (local_d8 < *reinterpret_cast<float*>(selfBytes + 0x6c)) { double f13 = atan2(static_cast<double>(local_d8) / *reinterpret_cast<float*>(selfBytes + 0x6c), 1.0); ld4 = static_cast<float>(f13 * ld4 * DAT_00728a00); }
                FUN_0053c800(ld4, local_d0, local_cc, local_c8);
                float local_24buf[9] = {0};
                float* q = static_cast<float*>(FUN_0053c8d0(local_24buf, local_b4));
                float* dst = local_b4; float* src = q;
                for (int k = 9; k != 0; k = k - 1) { *dst = *src; src = src + 1; dst = dst + 1; }
            }
        }
    }
    float* src2 = local_b4; float* out = param_4;
    for (int k = 9; k != 0; k = k - 1) { *out = *src2; src2 = src2 + 1; out = out + 1; }
}

// 0x57c880 — observed shape
long double FUN_0057c880(void* self, int param_1, int param_2, float param_3)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    float local_14 = 0.0f;
    int iVar2 = 0;
    int iVar3;
    do {
        int iVar1; int iVar3b;
        int iVar2b = *reinterpret_cast<int*>(selfBytes + 0x50);
        if (iVar2b == 0) { iVar1 = 0; iVar3b = 0; }
        else { uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2b)); iVar1 = *reinterpret_cast<int*>(p + 0x14); iVar3b = *reinterpret_cast<int*>(p + 0x10); }
        float local_cbuf[4] = {0};
        void** table = static_cast<void**>(DAT_007287cc);
        typedef void (*Fn)(float, int, int, void*);
        Fn fn = reinterpret_cast<Fn>(table[iVar1]);
        float* dat = static_cast<float*>(DAT_00717b84);
        uint8_t stride = (iVar3b != 0) ? *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3b) + 4) : 0;
        fn(param_3 * *(reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(dat) + iVar2)),
           static_cast<int>(stride) * param_1 + iVar3b,
           static_cast<int>(stride) * param_2 + iVar3b, local_cbuf);
        iVar3 = iVar2 + 4;
        float* dat70 = static_cast<float*>(DAT_00717b70);
        local_14 = sqrtf(local_cbuf[1] * local_cbuf[1] + local_cbuf[2] * local_cbuf[2] + local_cbuf[0] * local_cbuf[0]) *
                   *(reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(dat70) + iVar2)) + local_14;
        iVar2 = iVar3;
    } while (iVar3 < 0x14);
    return static_cast<long double>(local_14) * static_cast<long double>(param_3);
}

// 0x57c940 — observed shape
void FUN_0057c940(void* self, int param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint8_t* paramBytes = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    int iVar1 = param_1;
    FUN_00552f70(param_1);
    if (*reinterpret_cast<uint32_t*>(paramBytes + 0x1c) < 0x0a000102u) {
        *reinterpret_cast<uint16_t*>(selfBytes + 0x44) = static_cast<uint16_t>(*static_cast<uint16_t*>(DAT_00727c5c));
        *reinterpret_cast<uint16_t*>(selfBytes + 0x44) = static_cast<uint16_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0x44) >> 5);
    } else {
        typedef void (*Fn)(void*, int);
        void** vtable = *reinterpret_cast<void***>(paramBytes + 0x15c);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtable) + 8));
        fn(selfBytes + 0x44, 2);
    }
    {
        typedef void (*Fn)(void*, int);
        void** vtable = *reinterpret_cast<void***>(paramBytes + 0x15c);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtable) + 8));
        int* p32 = &param_1;
        fn(p32, 4);
        *reinterpret_cast<uint32_t*>(selfBytes + 0x70) = static_cast<uint32_t>(*p32);
        fn(selfBytes + 0x60, 4);
        fn(selfBytes + 100, 4);
        fn(selfBytes + 0x68, 2);
    }
    FUN_00545cc0();
    FUN_00545cc0();
}

extern void FUN_005530e0(int* param_1);
extern uint32_t FUN_00552bc0(int param_1);
extern void operator_delete__(void* ptr);
extern void* thunk_FUN_00533c78(int n);
extern long double FUN_0057c880_fwd(int a, int b, float t);

// 0x57c9e0 — observed shape
void FUN_0057c9e0(void* self, int* param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    FUN_005530e0(param_1);
    typedef void (*Fn)(void*, int);
    uint8_t* vtableBase = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1[0x58]));
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(vtableBase + 0xc));
    fn(selfBytes + 0x44, 2);
    fn(selfBytes + 0x70, 4);
    fn(selfBytes + 0x60, 4);
    fn(selfBytes + 100, 4);
    fn(selfBytes + 0x68, 2);
    void** vtable0 = *reinterpret_cast<void***>(param_1);
    typedef void (*Fn2)(uint32_t);
    Fn2 fn2 = reinterpret_cast<Fn2>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtable0) + 0x2c));
    fn2(*reinterpret_cast<uint32_t*>(selfBytes + 0x50));
    fn2(*reinterpret_cast<uint32_t*>(selfBytes + 0x54));
}

// 0x57ca60 — observed shape
// NEEDS_MANUAL: unaff_EBP (loop bound stack slot) and iStack_4 (other-object cache slot) come from caller stack frame; equality bit-packing preserved from listing.
uint32_t FUN_0057ca60(void* self, int param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint8_t* paramBytes = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    uint32_t uVar4 = FUN_00552bc0(param_1);
    if (static_cast<char>(uVar4) == 0) {
        return uVar4 & 0xffffff00u;
    }
    typedef uint32_t (*CmpFn)(uint32_t);
    {
        void** v0 = *reinterpret_cast<void***>(selfBytes + 0x50);
        CmpFn fn = reinterpret_cast<CmpFn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(v0) + 0x1c));
        uVar4 = fn(*reinterpret_cast<uint32_t*>(paramBytes + 0x50));
    }
    if (static_cast<char>(uVar4) == 0) return uVar4 & 0xffffff00u;
    {
        void** v0 = *reinterpret_cast<void***>(selfBytes + 0x54);
        CmpFn fn = reinterpret_cast<CmpFn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(v0) + 0x1c));
        uVar4 = fn(*reinterpret_cast<uint32_t*>(paramBytes + 0x54));
    }
    if (static_cast<char>(uVar4) == 0) return uVar4 & 0xffffff00u;
    char* pcVar11 = *reinterpret_cast<char**>(selfBytes + 0x58);
    char* pcOther = *reinterpret_cast<char**>(paramBytes + 0x58);
    uint32_t uVar5;
    if (pcVar11 == nullptr) {
        uVar5 = *reinterpret_cast<uint32_t*>(paramBytes + 0x58);
        uVar4 = 0;
        if (uVar5 != 0) return uVar5 & 0xffffff00u;
    } else {
        uVar4 = *reinterpret_cast<uint32_t*>(paramBytes + 0x58);
        uVar5 = 0;
        if (uVar4 == 0) return uVar4 & 0xffffff00u;
    }
    if (pcVar11 != nullptr) {
        uint32_t auStack_c[4] = {0};
        uint32_t* p1 = auStack_c;
        uint32_t* p2 = nullptr; uint32_t* p3 = nullptr;
        FUN_0057c0a0(self, p1, p2, p3);
        // unaff_EBP not recovered: bounded byte-compare of the two buffers
        bool bVar13 = true;
        char* a = pcVar11;
        char* b = pcOther;
        uint32_t count = 0;
        while (true) {
            if (count == 0) break;
            count = count - 1;
            bVar13 = (*a == *b);
            a = a + 1; b = b + 1;
            if (!bVar13) break;
        }
        if (!bVar13) { uint32_t r = uVar4; return r & 0xffffff00u; }
        (void)count;
    }
    float fVar1 = *reinterpret_cast<float*>(paramBytes + 0x5c);
    float fVar2 = *reinterpret_cast<float*>(selfBytes + 0x5c);
    uint16_t cmp1 = static_cast<uint16_t>((fVar2 < fVar1) ? (1u << 8) : 0) |
                    static_cast<uint16_t>(( (fVar2 != fVar2) || (fVar1 != fVar1) ) ? (1u << 10) : 0) |
                    static_cast<uint16_t>((fVar2 == fVar1) ? (1u << 14) : 0);
    uVar4 = (static_cast<uint32_t>(static_cast<uint16_t>(uVar4 >> 16)) << 16) | cmp1;
    if ((fVar2 == fVar1) && (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) ^ *reinterpret_cast<uint8_t*>(paramBytes + 0x44)) & 1) == 0)) {
        uint8_t bVar8x = static_cast<uint8_t>(*reinterpret_cast<uint16_t*>(paramBytes + 0x44));
        uint8_t bVar10x = static_cast<uint8_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0x44));
        uint8_t bVar3 = static_cast<uint8_t>((bVar8x ^ bVar10x) >> 1);
        uVar4 = (uVar4 & 0xffffff00u) | bVar3;
        if ((bVar3 & 1) == 0) {
            uint32_t uVar5b = *reinterpret_cast<uint32_t*>(selfBytes + 0x70);
            uVar4 = uVar5b;
            // iStack_4 slot unrecovered; compare against self's own slots as listed (observed: *(iStack_4+0x70))
            uint8_t* iStack = selfBytes; // [INFERENCE] caller-frame slot
            if (uVar5b == *reinterpret_cast<uint32_t*>(iStack + 0x70)) {
                uint8_t b3 = static_cast<uint8_t>((bVar8x ^ bVar10x) >> 2);
                uVar4 = (uVar4 & 0xffffff00u) | b3;
                if (((b3 & 1) == 0) && (b3 = static_cast<uint8_t>((bVar8x ^ bVar10x) >> 3), uVar4 = (uVar4 & 0xffffff00u) | b3, (b3 & 1) == 0)
                    && (b3 = static_cast<uint8_t>((bVar8x ^ bVar10x) >> 4), uVar4 = (uVar4 & 0xffffff00u) | b3, (b3 & 1) == 0)
                    && (b3 = static_cast<uint8_t>((bVar8x ^ bVar10x) >> 5), uVar4 = (uVar4 & 0xffffff00u) | b3, (b3 & 1) == 0)) {
                    float f1 = *reinterpret_cast<float*>(iStack + 0x60);
                    float f2 = *reinterpret_cast<float*>(selfBytes + 0x60);
                    uint16_t u7 = static_cast<uint16_t>(uVar5b >> 16);
                    uint16_t c2 = static_cast<uint16_t>((f2 < f1) ? (1u << 8) : 0) |
                                  static_cast<uint16_t>(((f2 != f2) || (f1 != f1)) ? (1u << 10) : 0) |
                                  static_cast<uint16_t>((f2 == f1) ? (1u << 14) : 0);
                    uVar4 = (static_cast<uint32_t>(u7) << 16) | c2;
                    if (f2 == f1) {
                        float g1 = *reinterpret_cast<float*>(iStack + 100);
                        float g2 = *reinterpret_cast<float*>(selfBytes + 100);
                        uint16_t c3 = static_cast<uint16_t>((g2 < g1) ? (1u << 8) : 0) |
                                      static_cast<uint16_t>(((g2 != g2) || (g1 != g1)) ? (1u << 10) : 0) |
                                      static_cast<uint16_t>((g2 == g1) ? (1u << 14) : 0);
                        uVar4 = (static_cast<uint32_t>(u7) << 16) | c3;
                        if ((g2 == g1) && (*reinterpret_cast<int16_t*>(selfBytes + 0x68) == *reinterpret_cast<int16_t*>(iStack + 0x68))
                            && (((bVar8x ^ bVar10x) >> 6 & 1) == 0)) {
                            return (uVar4 & 0xffffff00u) | 1u;
                        }
                    }
                }
            }
        }
    }
    return uVar4 & 0xffffff00u;
}

// 0x57cbd0 — observed shape
void FUN_0057cbd0(void* self, uint8_t param_1)
{
    FUN_0057c0f0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x57cbf0 — observed shape
long double FUN_0057cbf0(void* self)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<float*>(selfBytes + 0x5c) < 0.0f) {
        int iVar3;
        if (*reinterpret_cast<int*>(selfBytes + 0x50) == 0) iVar3 = 0;
        else {
            int inner = *reinterpret_cast<int*>(selfBytes + 0x50);
            iVar3 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(inner)) + 0xc);
        }
        operator_delete__(*reinterpret_cast<void**>(selfBytes + 0x58));
        uint32_t* puVar2 = static_cast<uint32_t*>(thunk_FUN_00533c78(iVar3 * 4));
        *reinterpret_cast<uint32_t**>(selfBytes + 0x58) = puVar2;
        *puVar2 = 0;
        uint32_t uVar4 = 0;
        if (iVar3 != 1) {
            do {
                uint32_t uVar1 = uVar4 + 1;
                long double fVar5 = FUN_0057c880(self, static_cast<int>(uVar4), static_cast<int>(uVar1), 1.0f);
                uint32_t* arr = *reinterpret_cast<uint32_t**>(selfBytes + 0x58);
                float* farr = reinterpret_cast<float*>(arr);
                farr[1 * static_cast<int>(uVar4) + 1] = static_cast<float>(fVar5 + static_cast<long double>(farr[uVar4]));
                uVar4 = uVar1;
            } while (uVar4 < static_cast<uint32_t>(iVar3 - 1));
        }
        uint32_t* arr2 = *reinterpret_cast<uint32_t**>(selfBytes + 0x58);
        *reinterpret_cast<uint32_t*>(selfBytes + 0x5c) = *(reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(arr2) + (-4 + iVar3 * 4)));
    }
    return static_cast<long double>(*reinterpret_cast<float*>(selfBytes + 0x5c));
}

// 0x57cc80 — observed shape
// NEEDS_MANUAL: _CIfmod() fractional-modulus operands unrecovered from listing; call preserved as observed.
extern long double _CIfmod_manual(float a, float b);
void FUN_0057cc80(void* self, float param_1, uint32_t* param_2, int* param_3, float* param_4)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int iVar5;
    if (*reinterpret_cast<int*>(selfBytes + 0x50) == 0) iVar5 = 0;
    else { int inner = *reinterpret_cast<int*>(selfBytes + 0x50); iVar5 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(inner)) + 0xc); }
    if (param_1 == 0.0f) { *param_2 = 0; *param_3 = 1; *param_4 = 0.0f; return; }
    if (param_1 < 0.0f) { long double fm = _CIfmod_manual(param_1, 1.0f); param_1 = static_cast<float>(fm + 1.0L); }
    if (param_1 == 1.0f) { *param_2 = static_cast<uint32_t>(iVar5 - 2); *param_3 = iVar5 + -1; *param_4 = 1.0f; return; }
    if (1.0f < param_1) { long double fm = _CIfmod_manual(param_1, 1.0f); param_1 = static_cast<float>(fm); }
    param_1 = param_1 * *reinterpret_cast<float*>(selfBytes + 0x5c);
    uint32_t uVar6 = 0;
    int iVar7 = 1;
    float fStack_18 = 0;
    if (iVar5 == 1) {
        iVar5 = 0;
    } else {
        float* pfVar2 = *reinterpret_cast<float**>(selfBytes + 0x58);
        do {
            pfVar2 = pfVar2 + 1;
            float fVar1 = *pfVar2;
            if ((!(param_1 != param_1) && !(fVar1 != fVar1)) && (param_1 < fVar1 != (param_1 == fVar1))) {
                int base = *reinterpret_cast<int*>(selfBytes + 0x58);
                fStack_18 = param_1 - *reinterpret_cast<float*>(static_cast<intptr_t>(base) + uVar6 * 4);
                param_1 = fStack_18 / (*reinterpret_cast<float*>(static_cast<intptr_t>(base) + iVar7 * 4) - *reinterpret_cast<float*>(static_cast<intptr_t>(base) + uVar6 * 4));
                break;
            }
            uVar6 = uVar6 + 1; iVar7 = iVar7 + 1;
        } while (uVar6 < static_cast<uint32_t>(iVar5 - 1));
        iVar5 = 0;
        // NOTE: listing jumps to LAB_0057cdac (iVar5=0) after segment found; loop-break reproduces that assignment.
    }
    int iter = 0;
    do {
        long double fVar9 = FUN_0057c880(self, static_cast<int>(uVar6), iVar7, param_1);
        long double fVar10 = fVar9 - static_cast<long double>(fStack_18);
        if (fVar10 < 0) fVar10 = -fVar10;
        long double fVar8 = 0.0001L;
        if ((!(fVar10 != fVar10) && !(fVar8 != fVar8)) && (fVar10 < fVar8 != (fVar10 == fVar8))) break;
        int iVar3; int iVar4;
        if (*reinterpret_cast<int*>(selfBytes + 0x50) == 0) { iVar4 = 0; iVar3 = 0; }
        else { int inner = *reinterpret_cast<int*>(selfBytes + 0x50); uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(inner)); iVar4 = *reinterpret_cast<int*>(p + 0x14); iVar3 = *reinterpret_cast<int*>(p + 0x10); }
        float fStack_c = 0;
        void** table = static_cast<void**>(DAT_007287cc);
        typedef void (*Fn)(float, int, int, void*);
        Fn fn = reinterpret_cast<Fn>(table[iVar4]);
        float buf[4] = {0};
        uint8_t stride = (iVar3 != 0) ? *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3) + 4) : 0;
        fn(param_1, static_cast<int>(stride) * static_cast<int>(uVar6) + iVar3, static_cast<int>(stride) * iVar7 + iVar3, buf);
        fStack_c = buf[0];
        iVar5 = iVar5 + 1;
        float denom = sqrtf(buf[2] * buf[2] + buf[1] * buf[1] + fStack_c * fStack_c);
        param_1 = param_1 - static_cast<float>(fVar9 - static_cast<long double>(fStack_18)) / denom;
        iter = iter + 1;
    } while (iVar5 < 0x20);
    *param_2 = uVar6;
    *param_3 = iVar7;
    *param_4 = param_1;
}

extern void* DAT_007288bc;
extern void FUN_00553060(uint32_t param_1);
extern void* FUN_00545600();
float FUN_0057cbf0_fwd(void);
void FUN_0057cc80_fwd(float t, uint32_t* a, int* b, float* c);
extern void FUN_005531c0(int param_1);
extern void* DAT_00728a08;
extern int FUN_00557b10(void* p);
extern void FUN_006b34a0(int n);
extern void FUN_005606f0(uint32_t n, int* p);
extern char FUN_00568540(float t);
extern long double FUN_0056a5f0(uint32_t a, int b, uint32_t c, uint32_t d, void* e);
extern void FUN_00552aa0(int param_1, uint32_t param_2);

// 0x57ce70 — observed shape
void FUN_0057ce70(void* self, float param_1, float* param_2, float* param_3, float* param_4)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 4 & 1) != 0)) {
        uint32_t u2 = 0; int i3 = 0; float f4 = 0;
        FUN_0057cc80(self, param_1, &u2, &i3, &f4);
        *param_2 = static_cast<float>(u2);
        *param_3 = static_cast<float>(i3);
        *param_4 = f4;
        *reinterpret_cast<float*>(selfBytes + 0x48) = *param_2;
        return;
    }
    int iVar6 = *reinterpret_cast<int*>(selfBytes + 0x50);
    int local_8; float* pfVar3;
    if (iVar6 == 0) { local_8 = 0; pfVar3 = nullptr; }
    else { uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar6)); local_8 = *reinterpret_cast<int*>(p + 0xc); pfVar3 = *reinterpret_cast<float**>(p + 0x10); }
    float fVar4 = (pfVar3 != nullptr) ? *pfVar3 : 0.0f;
    if ((!(param_1 != param_1) && !(fVar4 != fVar4)) && (param_1 < fVar4 != (param_1 == fVar4))) {
        *param_2 = 0.0f; *param_3 = 1.4013e-45f; *param_4 = 0.0f; return;
    }
    uint32_t uVar5 = static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(pfVar3) + 4));
    fVar4 = static_cast<float>(local_8 - 1);
    if ((pfVar3 != nullptr) && (*reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar3) + static_cast<size_t>(static_cast<int>(fVar4) * uVar5)) <= param_1)) {
        *param_2 = static_cast<float>(local_8 - 2);
        *param_3 = fVar4;
        *param_4 = 1.0f;
        return;
    }
    float fVar2 = *reinterpret_cast<float*>(selfBytes + 0x48);
    bool bVar1 = true;
    for (;;) {
        if ((static_cast<uint32_t>(fVar4) <= static_cast<uint32_t>(fVar2))) {
            fVar4 = param_1;
            goto LAB_0057cfa7;
        }
        if ((param_1 == *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar3) + static_cast<size_t>(uVar5 * static_cast<int>(fVar2))))
            || ((*reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar3) + static_cast<size_t>(uVar5 * static_cast<int>(fVar2))) < param_1)
                && (param_1 < *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar3) + static_cast<size_t>((static_cast<int>(fVar2) + 1) * uVar5))))) {
            *reinterpret_cast<float*>(selfBytes + 0x48) = fVar2;
            fVar4 = static_cast<float>(static_cast<int>(fVar2) + 1);
            goto LAB_0057cfa7;
        }
        if ((fVar2 == static_cast<float>(local_8 - 2)) && (bVar1)) {
            fVar2 = 0.0f; bVar1 = false;
        } else {
            fVar2 = static_cast<float>(static_cast<int>(fVar2) + 1);
        }
        continue;
LAB_0057cfa7:
        {
            int idx = static_cast<int>(fVar2);
            uint32_t stride = static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(pfVar3) + 4));
            int iVar6b = static_cast<int>(stride) * idx;
            float lo = *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar3) + iVar6b);
            float hi = *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar3) + static_cast<int>(stride) * static_cast<int>(fVar4));
            *param_4 = (param_1 - lo) / (hi - lo);
            *param_2 = fVar2;
            *param_3 = fVar4;
            return;
        }
    }
}

// 0x57cff0 — observed shape
void FUN_0057cff0(void* self, uint32_t param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    FUN_00553060(param_1);
    uint32_t* puVar4 = static_cast<uint32_t*>(FUN_00545600());
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(selfBytes + 0x50);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) { typedef void (*Fn)(int); reinterpret_cast<Fn>(*puVar2)(1); }
        }
        *reinterpret_cast<uint32_t**>(selfBytes + 0x50) = puVar4;
        if (puVar4 != nullptr) { puVar4[1] = puVar4[1] + 1; }
    }
    puVar4 = static_cast<uint32_t*>(FUN_00545600());
    puVar2 = *reinterpret_cast<uint32_t**>(selfBytes + 0x54);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) { typedef void (*Fn)(int); reinterpret_cast<Fn>(*puVar2)(1); }
        }
        *reinterpret_cast<uint32_t**>(selfBytes + 0x54) = puVar4;
        if (puVar4 != nullptr) { puVar4[1] = puVar4[1] + 1; }
    }
    *reinterpret_cast<uint8_t*>(selfBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(selfBytes + 0x44) | 1);
    if ((((static_cast<uint16_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0x44)) >> 4 & 1) != 0)
         && ((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) & 1) != 0))) {
        long double fVar5 = FUN_0057cbf0(self);
        *reinterpret_cast<float*>(selfBytes + 0x5c) = static_cast<float>(fVar5);
        *reinterpret_cast<uint8_t*>(selfBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(selfBytes + 0x44) & 0xfe);
    }
    int iVar3 = *reinterpret_cast<int*>(selfBytes + 0x50);
    if (iVar3 != 0) {
        uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3));
        if (*reinterpret_cast<int*>(p + 0xc) != 0) {
            void** table = static_cast<void**>(DAT_007288bc);
            typedef long double (*Fn)(uint32_t, int);
            Fn fn = reinterpret_cast<Fn>(table[*reinterpret_cast<int*>(p + 0x14)]);
            long double fVar5 = fn(*reinterpret_cast<uint32_t*>(p + 0x10), *reinterpret_cast<int*>(p + 0xc));
            *reinterpret_cast<float*>(selfBytes + 0x6c) = static_cast<float>(fVar5);
        }
    }
}

// 0x57d0b0 — observed shape
void FUN_0057d0b0(int param_1)
{
    int iVar2 = param_1;
    FUN_005531c0(param_1);
    uint8_t* selfBytes = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    int local_param = FUN_00557b10(DAT_00728a08);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(selfBytes + 0xc);
    if (*reinterpret_cast<uint32_t*>(selfBytes + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(selfBytes + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &local_param);
}

// 0x57d100 — observed shape
void FUN_0057d100(void* self, float param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int iVar5 = *reinterpret_cast<int*>(selfBytes + 0x54);
    if (iVar5 != 0) {
        uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar5));
        uint32_t uVar1 = *reinterpret_cast<uint32_t*>(p + 0x14);
        int iVar2 = *reinterpret_cast<int*>(p + 0x10);
        uint32_t uVar3 = *reinterpret_cast<uint32_t*>(p + 0xc);
        int inner50 = *reinterpret_cast<int*>(selfBytes + 0x50);
        if ((iVar2 != 0) && (inner50 != 0)
            && (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(inner50)) + 0x10) != 0)
            && (FUN_00568540(param_1) == 0)) {
            long double fVar8 = FUN_0056a5f0(*reinterpret_cast<uint32_t*>(selfBytes + 0x2c), iVar2, uVar1, uVar3, selfBytes + 0x4c);
            param_1 = static_cast<float>(fVar8);
            float local_38 = 0, local_34 = 0;
            float local_30 = 0, local_2c = 0, local_28 = 0;
            FUN_0057ce70(self, param_1, &local_38, &param_1, &local_34);
            if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 5 & 1) != 0)) {
                float local_24[9] = {0};
                FUN_0057c1f0(self, static_cast<int>(local_38), static_cast<uint32_t>(param_1), local_34, local_24);
                uint32_t* puVar6 = reinterpret_cast<uint32_t*>(local_24);
                uint32_t* puVar7 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(selfBytes + 0x34) + 0x38);
                for (int k = 9; k != 0; k = k - 1) { *puVar7 = *puVar6; puVar6 = puVar6 + 1; puVar7 = puVar7 + 1; }
            }
            FUN_0057c180(self, &local_30, static_cast<int>(local_38), static_cast<int>(param_1), static_cast<uint32_t>(local_34));
            int dst = *reinterpret_cast<int*>(selfBytes + 0x34);
            *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(dst) + 0x5c) = local_30;
            *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(dst) + 0x60) = local_2c;
            *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(dst) + 100) = local_28;
        }
    }
}

// 0x57d200 — observed shape
void FUN_0057d200(void* self, int param_1, uint32_t param_2)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint8_t* paramBytes = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    FUN_00552aa0(param_1, param_2);
    *reinterpret_cast<uint16_t*>(paramBytes + 0x44) = *reinterpret_cast<uint16_t*>(selfBytes + 0x44);
    if (*reinterpret_cast<int**>(selfBytes + 0x50) != nullptr) {
        typedef uint32_t* (*Fn)(uint32_t);
        void** v = *reinterpret_cast<void***>(selfBytes + 0x50);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(v) + 8));
        uint32_t* puVar2 = fn(param_2);
        uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(paramBytes + 0x50);
        if (puVar5 != puVar2) {
            if (puVar5 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar5 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) { typedef void (*D)(int); reinterpret_cast<D>(*puVar5)(1); }
            }
            *reinterpret_cast<uint32_t**>(paramBytes + 0x50) = puVar2;
            if (puVar2 != nullptr) { puVar2[1] = puVar2[1] + 1; }
        }
    }
    if (*reinterpret_cast<int**>(selfBytes + 0x54) != nullptr) {
        typedef uint32_t* (*Fn)(uint32_t);
        void** v = *reinterpret_cast<void***>(selfBytes + 0x54);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(v) + 8));
        uint32_t* puVar2 = fn(param_2);
        uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(paramBytes + 0x54);
        if (puVar5 != puVar2) {
            if (puVar5 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar5 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) { typedef void (*D)(int); reinterpret_cast<D>(*puVar5)(1); }
            }
            *reinterpret_cast<uint32_t**>(paramBytes + 0x54) = puVar2;
            if (puVar2 != nullptr) { puVar2[1] = puVar2[1] + 1; }
        }
    }
    if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 2 & 1) == 0)) {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) & 0xfb);
    } else {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) | 4);
    }
    if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 3 & 1) == 0)) {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) & 0xf7);
    } else {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) | 8);
    }
    *reinterpret_cast<uint32_t*>(paramBytes + 0x70) = *reinterpret_cast<uint32_t*>(selfBytes + 0x70);
    if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 4 & 1) == 0)) {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) & 0xef);
    } else {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) | 0x10);
        if ((*reinterpret_cast<uint8_t*>(paramBytes + 0x44) & 1) != 0) {
            long double fVar6 = FUN_0057cbf0(self);
            *reinterpret_cast<float*>(paramBytes + 0x5c) = static_cast<float>(fVar6);
            *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) & 0xfe);
        }
    }
    if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 5 & 1) == 0)) {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) & 0xdf);
    } else {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) | 0x20);
    }
    *reinterpret_cast<uint32_t*>(paramBytes + 0x60) = *reinterpret_cast<uint32_t*>(selfBytes + 0x60);
    *reinterpret_cast<uint32_t*>(paramBytes + 100) = *reinterpret_cast<uint32_t*>(selfBytes + 100);
    *reinterpret_cast<uint16_t*>(paramBytes + 0x68) = *reinterpret_cast<uint16_t*>(selfBytes + 0x68);
    if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 6 & 1) == 0)) {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) & 0xbf);
    } else {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) | 0x40);
    }
    if (((*reinterpret_cast<uint8_t*>(selfBytes + 0x44) >> 1 & 1) == 0)) {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) & 0xfd);
    } else {
        *reinterpret_cast<uint8_t*>(paramBytes + 0x44) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(paramBytes + 0x44) | 2);
    }
    if (*reinterpret_cast<int*>(selfBytes + 0x58) == 0) {
        *reinterpret_cast<uint32_t*>(paramBytes + 0x5c) = *reinterpret_cast<uint32_t*>(selfBytes + 0x5c);
        return;
    }
    uint32_t uVar3;
    if (*reinterpret_cast<int*>(selfBytes + 0x50) == 0) { uVar3 = 0; }
    else { uint8_t* p = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int*>(selfBytes + 0x50))); uVar3 = *reinterpret_cast<uint32_t*>(p + 0xc); }
    uint32_t* puVar2 = static_cast<uint32_t*>(thunk_FUN_00533c78(static_cast<int>(uVar3 * 4)));
    *reinterpret_cast<uint32_t**>(paramBytes + 0x58) = puVar2;
    uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(selfBytes + 0x58);
    for (uint32_t k = uVar3 & 0x3fffffffu; k != 0; k = k - 1) { *puVar2 = *puVar5; puVar5 = puVar5 + 1; puVar2 = puVar2 + 1; }
    // second loop bound is 0 in listing (iVar4=0); preserved as no-op
    *reinterpret_cast<uint32_t*>(paramBytes + 0x5c) = *reinterpret_cast<uint32_t*>(selfBytes + 0x5c);
}
