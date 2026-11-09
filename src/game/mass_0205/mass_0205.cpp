#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00559510(int param_1);
extern int thunk_FUN_00533c78(unsigned int param_1);
extern void FUN_005bd4f0();
extern void FUN_005bd540(int param_1);
extern void FUN_005597c0(int param_1);
extern void FUN_005bd5c0(int param_1);
extern void FUN_005598b0(int param_1);
extern int FUN_00557b10(int param_1);
extern int FUN_00557c30(const char* param_1, unsigned short param_2);
extern void FUN_005606f0(unsigned int param_1, int* param_2);
extern void FUN_006b34a0(int param_1);
extern int rand();
extern float fcos(double param_1);
extern float fsin(double param_1);
extern float* FUN_00502260(void* param_1, float* param_2);
extern unsigned int* FUN_0053ca60(void* param_1, unsigned int* param_2);
extern void FUN_005bbf20(unsigned int param_1);
extern void FUN_00545cc0();
extern void FUN_0056e040(float* param_1, float param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5, unsigned int* param_6);
extern void FUN_005e4780();
extern void FUN_005bbd50();
extern void operator_delete(void* param_1);
extern void FUN_005bbd70(unsigned int param_1);
extern unsigned int* FUN_00545600();
extern unsigned int* FUN_005bbeb0(unsigned int* param_1, unsigned int param_2);
extern void FUN_005bbd20();
extern void FUN_005bbee0(int param_1);
extern int FUN_005bd960(unsigned int param_1, int* param_2);
extern void FUN_005b9220();
extern void FUN_005b9400(int param_1, unsigned int param_2);
extern void thunk_FUN_00513ce0(unsigned int param_1);
extern void FUN_005b9670(unsigned int param_1);
extern void PTR_FUN_006c6938();
extern void PTR_FUN_006c6a20();

// 0x5b9670 — observed shape: self+0xc ushort count; alloc count*0x28 via thunk_FUN_00533c78; do-while FUN_005bd4f0 countdown; self+0x50 store; loop FUN_005bd540 count times; vtable call *(param+0x15c)[1] with (self+0x54,2),(self+0x56,2)
void FUN_005b9670(void* self, int param_1)
{
    uint16_t uVar3 = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0xc);
    int iVar1 = thunk_FUN_00533c78((unsigned int)uVar3 * 0x28);
    if (iVar1 == 0) {
        iVar1 = 0;
    }
    else if (-1 < (int)(uVar3 - 1)) {
        do {
            FUN_005bd4f0();
            uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
    }
    uint16_t uVar2 = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x50) = iVar1;
    if (*reinterpret_cast<int16_t*>(reinterpret_cast<char*>(self) + 0xc) != 0) {
        do {
            FUN_005bd540(param_1);
            uVar2 = uVar2 + 1;
        } while (uVar2 < *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0xc));
    }
    typedef void (*VFn)(void*, int);
    void** vt1 = *reinterpret_cast<void***>(reinterpret_cast<char*>(param_1) + 0x15c);
    VFn f = reinterpret_cast<VFn>(vt1[1]);
    f(reinterpret_cast<char*>(self) + 0x54, 2);
    void** vt2 = *reinterpret_cast<void***>(reinterpret_cast<char*>(param_1) + 0x15c);
    VFn g = reinterpret_cast<VFn>(vt2[1]);
    g(reinterpret_cast<char*>(self) + 0x56, 2);
}

// 0x5b9710 — observed shape: FUN_005597c0(param); loop FUN_005bd5c0 count times (self+0xc ushort); vtable *(param+0x160)[1] with (self+0x54,2),(self+0x56,2)
void FUN_005b9710(void* self, int param_1)
{
    FUN_005597c0(param_1);
    uint16_t uVar1 = 0;
    if (*reinterpret_cast<int16_t*>(reinterpret_cast<char*>(self) + 0xc) != 0) {
        do {
            FUN_005bd5c0(param_1);
            uVar1 = uVar1 + 1;
        } while (uVar1 < *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0xc));
    }
    typedef void (*VFn)(void*, int);
    void** vt1 = *reinterpret_cast<void***>(reinterpret_cast<char*>(param_1) + 0x160);
    VFn f = reinterpret_cast<VFn>(vt1[1]);
    f(reinterpret_cast<char*>(self) + 0x54, 2);
    void** vt2 = *reinterpret_cast<void***>(reinterpret_cast<char*>(param_1) + 0x160);
    VFn g = reinterpret_cast<VFn>(vt2[1]);
    g(reinterpret_cast<char*>(self) + 0x56, 2);
}

// 0x5b97d0 — observed shape: FUN_005598b0; three blocks: get count *(self+0xc), if capacity <= count FUN_006b34a0(*(self+0x14)+count), then FUN_005606f0(count,&tmp); tmp from FUN_00557b10(0x728c70) then FUN_00557c30("NumAddedParticles",*(u16*)(self+0x54)) then FUN_00557c30("AddedParticlesBase",*(u16*)(self+0x56))
void FUN_005b97d0(void* self, int param_1)
{
    FUN_005598b0(param_1);
    int iVar2 = reinterpret_cast<int>(self);
    int tmp = FUN_00557b10(0x728c70);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &tmp);
    tmp = FUN_00557c30("NumAddedParticles", *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0x54));
    uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &tmp);
    tmp = FUN_00557c30("AddedParticlesBase", *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0x56));
    uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &tmp);
}

// 0x5b98f0 — observed shape: rand radii; fVar1=rand* *(float*)(self+0x54)*3.051851e-05; angle=rand*_DAT_00727c80*3.051851e-05; *p2=cos*fVar1, p2[1]=sin*fVar1, p2[2]=(rand*3.051851e-05-0.5)* *(self+0x58); then FUN_00502260 copy back; then FUN_0053ca60 copy to param_3
extern float DAT_00727c80;
void FUN_005b98f0(void* self, uint32_t param_1, float* param_2, uint32_t* param_3)
{
    (void)param_1;
    float local_c[3];
    int iVar2 = rand();
    float fVar1 = (float)iVar2 * *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x54) * 3.051851e-05f;
    iVar2 = rand();
    double fVar5 = (double)(float)iVar2 * (double)DAT_00727c80 * (double)3.051851e-05;
    float fcos_res = fcos(fVar5);
    *param_2 = (float)((double)fcos_res * (double)fVar1);
    float fsin_res = fsin(fVar5);
    param_2[1] = (float)((double)fsin_res * (double)fVar1);
    iVar2 = rand();
    param_2[2] = ((float)iVar2 * 3.051851e-05f - 0.5f) * *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x58);
    float* pfVar3 = FUN_00502260(local_c, param_2);
    *param_2 = *pfVar3;
    param_2[1] = pfVar3[1];
    param_2[2] = pfVar3[2];
    uint32_t* puVar4 = FUN_0053ca60(local_c, param_3);
    *param_3 = *puVar4;
    param_3[1] = puVar4[1];
    param_3[2] = puVar4[2];
}

// 0x5b9b90 — observed shape: FUN_005bbf20(param); FUN_00545cc0();
void FUN_005b9b90(uint32_t param_1)
{
    FUN_005bbf20(param_1);
    FUN_00545cc0();
}

// 0x5b9bc0 — observed shape: base = (int)param_2 as ptr; uVar4 index; if *(short*)(base+0x44)!=0 loop: iVar1=*(base+0x50)+u*0x28; if *(base+0x28)!=0: p2=*(iVar1+0x18)/\*(iVar1+0x1c); clamp [*(self+0x20),*(self+0x24)]; FUN_0056e040(&out,p2,*(self+0x1c +0x10),+0x14,+0xc,&zero); clamp each of 4 locals to [0,1]; store to *(iVar2+u*0x10) as 4 floats
void FUN_005b9bc0(void* self, float param_2)
{
    int base = static_cast<int>(param_2);
    uint16_t uVar4 = 0;
    void* local_14 = self;
    if (*reinterpret_cast<short*>(base + 0x44) != 0) {
        do {
            int iVar2 = *reinterpret_cast<int*>(base + 0x28);
            int iVar1 = *reinterpret_cast<int*>(base + 0x50) + (uint32_t)uVar4 * 0x28;
            if (iVar2 != 0) {
                float p2 = *reinterpret_cast<float*>(iVar1 + 0x18) / *reinterpret_cast<float*>(iVar1 + 0x1c);
                if (p2 <= *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x20)) {
                    p2 = *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x20);
                }
                if (*reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x24) <= p2) {
                    p2 = *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x24);
                }
                int iVar1b = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x1c);
                uint32_t local_18 = 0;
                float local_10 = 0, local_c = 0, local_8 = 0, local_4 = 0;
                FUN_0056e040(&local_10, p2, *reinterpret_cast<uint32_t*>(iVar1b + 0x10), *reinterpret_cast<uint32_t*>(iVar1b + 0x14), *reinterpret_cast<uint32_t*>(iVar1b + 0xc), &local_18);
                if (0.0f <= local_10) { if (1.0f < local_10) local_10 = 1.0f; } else local_10 = 0.0f;
                if (0.0f <= local_c) { if (1.0f < local_c) local_c = 1.0f; } else local_c = 0.0f;
                if (0.0f <= local_8) { if (1.0f < local_8) local_8 = 1.0f; } else local_8 = 0.0f;
                if (0.0f <= local_4) { if (1.0f < local_4) local_4 = 1.0f; } else local_4 = 0.0f;
                float* pfVar5 = reinterpret_cast<float*>((uint32_t)uVar4 * 0x10 + iVar2);
                *pfVar5 = local_10;
                pfVar5[1] = local_c;
                pfVar5[2] = local_8;
                pfVar5[3] = local_4;
                self = local_14;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<uint16_t*>(base + 0x44));
    }
}

// 0x5b9e30 — observed shape: refcounted shared ptr at self+0x1c; if old!=param: dec old[1], if 0 call old vtable (1); store param, inc param[1]; then self+0x20=0,self+0x24=0; if new non-null and *(new+0xc)!=0: self+0x20=*ptr; self+0x24= indexed byte
void FUN_005b9e30(void* self, uint32_t* param_1)
{
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x1c);
    if (puVar2 != param_1) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*VFn)(unsigned int);
                VFn f = reinterpret_cast<VFn>(*puVar2);
                f(1);
            }
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x1c) = param_1;
        if (param_1 != nullptr) {
            param_1[1] = param_1[1] + 1;
        }
    }
    int iVar3 = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x1c);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x24) = 0;
    if (iVar3 != 0) {
        int iVar4 = *reinterpret_cast<int*>(iVar3 + 0xc);
        uint32_t* puVar2b = *reinterpret_cast<uint32_t**>(iVar3 + 0x10);
        if (iVar4 != 0) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20) = *puVar2b;
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x24) = *reinterpret_cast<uint32_t*>((uint32_t)*(uint8_t*)(puVar2b + 1) * (iVar4 + -1) + (int)puVar2b);
        }
    }
}

// 0x5b9e90 — observed shape: FUN_005e4780(); FUN_005bbd50(); if (param&1) operator_delete(self)
void FUN_005b9e90(void* self, unsigned char param_1)
{
    FUN_005e4780();
    FUN_005bbd50();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5ba060 — observed shape: FUN_005bbd70(param); pu= FUN_00545600(); refcounted assign to self+0x1c
void FUN_005ba060(void* self, uint32_t param_1)
{
    FUN_005bbd70(param_1);
    uint32_t* puVar3 = FUN_00545600();
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x1c);
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*VFn)(unsigned int);
                VFn f = reinterpret_cast<VFn>(*puVar2);
                f(1);
            }
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x1c) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x5ba100 — observed shape: pu=FUN_00533c78(0x20); if non-null FUN_005bbd20(), *pu=&PTR_FUN_006c6938, pu[7]=0; FUN_005bbeb0(pu,param); if *(self+0x1c)!=0: pu4=(**(self+0x1c)+8)(param); refcount assign pu[7]=pu4; return pu
void* FUN_005ba100(void* self, uint32_t param_1)
{
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(0x20));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_005bbd20();
        *puVar3 = reinterpret_cast<uint32_t>(&PTR_FUN_006c6938);
        puVar3[7] = 0;
    }
    FUN_005bbeb0(puVar3, param_1);
    if (*reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x1c) != nullptr) {
        typedef uint32_t* (*VFn)(void*, uint32_t);
        void** vt = *reinterpret_cast<void***>(reinterpret_cast<char*>(self) + 0x1c);
        VFn f = reinterpret_cast<VFn>(vt[1]);
        uint32_t* puVar4 = f(*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x1c), param_1);
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(puVar3[7]);
        if (puVar2 != puVar4) {
            if (puVar2 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    typedef void (*VFn0)(unsigned int);
                    VFn0 g = reinterpret_cast<VFn0>(*puVar2);
                    g(1);
                }
            }
            puVar3[7] = reinterpret_cast<uint32_t>(puVar4);
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
    }
    return puVar3;
}

// 0x5ba270 — observed shape: rand x,y,z scaled: local_c=(rand*3.051851e-05-0.5)* *(self+0x54); local_8=(rand*...-0.5)* *(self+0x58); local_4=...* *(self+0x5c); copy to param_2; then FUN_00502260(&local_c,param_2) copy back; then FUN_0053ca60 copy to param_3
void FUN_005ba270(void* self, uint32_t param_1, float* param_2, uint32_t* param_3)
{
    (void)param_1;
    float local_c = 0, local_8 = 0, local_4 = 0;
    int iVar1 = rand();
    int iVar2 = rand();
    int iVar3 = rand();
    local_4 = ((float)iVar3 * 3.051851e-05f - 0.5f) * *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x5c);
    local_c = ((float)iVar2 * 3.051851e-05f - 0.5f) * *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x54);
    local_8 = ((float)iVar1 * 3.051851e-05f - 0.5f) * *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x58);
    *param_2 = local_c;
    param_2[1] = local_8;
    param_2[2] = local_4;
    float* pfVar4 = FUN_00502260(&local_c, param_2);
    *param_2 = *pfVar4;
    param_2[1] = pfVar4[1];
    param_2[2] = pfVar4[2];
    uint32_t* puVar5 = FUN_0053ca60(&local_c, param_3);
    *param_3 = *puVar5;
    param_3[1] = puVar5[1];
    param_3[2] = puVar5[2];
}

// 0x5ba820 — observed shape: pu=FUN_00533c78(0x3c); if non-null FUN_005bbd20(), *pu=&PTR_FUN_006c6a20, pu[7]=0, pu[8..10]=DAT_007177ac/b0/b4, pu[0xb..0xe]=0; FUN_005bbeb0(pu,param); then pu[8..0xe] = *(self+0x20..0x38); return pu
extern unsigned int DAT_007177ac;
extern unsigned int DAT_007177b0;
extern unsigned int DAT_007177b4;
void* FUN_005ba820(void* self, uint32_t param_1)
{
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(0x3c));
    if (puVar1 == nullptr) {
        puVar1 = nullptr;
    } else {
        FUN_005bbd20();
        *puVar1 = reinterpret_cast<uint32_t>(&PTR_FUN_006c6a20);
        puVar1[7] = 0;
        puVar1[8] = DAT_007177ac;
        puVar1[9] = DAT_007177b0;
        puVar1[10] = DAT_007177b4;
        puVar1[0xb] = 0;
        puVar1[0xc] = 0;
        puVar1[0xd] = 0;
        puVar1[0xe] = 0;
    }
    FUN_005bbeb0(puVar1, param_1);
    puVar1[8] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20);
    puVar1[9] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x24);
    puVar1[10] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x28);
    puVar1[0xb] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x2c);
    puVar1[0xc] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x30);
    puVar1[0xd] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x34);
    puVar1[0xe] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x38);
    return puVar1;
}

// 0x5ba8c0 — observed shape: FUN_005bbee0(param); FUN_005bd960(self,&param); iVar1=param; if FUN_005bd960(*(self+0x1c),&param)==0: *(iVar1+0x1c)=*(self+0x1c) else *(iVar1+0x1c)=param
void FUN_005ba8c0(void* self, int param_1)
{
    FUN_005bbee0(param_1);
    FUN_005bd960(reinterpret_cast<uint32_t>(self), &param_1);
    int iVar1 = param_1;
    char cVar2 = (char)FUN_005bd960(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x1c), &param_1);
    if (cVar2 == '\0') {
        *reinterpret_cast<uint32_t*>(iVar1 + 0x1c) = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x1c);
        return;
    }
    *reinterpret_cast<int*>(iVar1 + 0x1c) = param_1;
}

// 0x5bb160 — observed shape: u=0; if (short)param_2[0x11]!=0 loop u: iVar1=param_2[0x14]+u*0x28; f=(param1-*(iVar1+0x20))+*(iVar1+0x18); store; if *(iVar1+0x1c)<f: if *(self+0x1c)!=0 && *(self+0x20)!=0 call vtable (param1,(param1+*(iVar1+0x1c))-f,u,*(self+0x14)); then vtable (*param_2+0x40)(u)
void FUN_005bb160(void* self, float param_1, int* param_2)
{
    uint32_t uVar3 = 0;
    if ((short)param_2[0x11] != 0) {
        do {
            int iVar1 = param_2[0x14] + (uVar3 & 0xffff) * 0x28;
            float fVar2 = (param_1 - *reinterpret_cast<float*>(iVar1 + 0x20)) + *reinterpret_cast<float*>(iVar1 + 0x18);
            *reinterpret_cast<float*>(iVar1 + 0x18) = fVar2;
            if (*reinterpret_cast<float*>(iVar1 + 0x1c) < fVar2) {
                if ((*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x1c) != '\0') && (*reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x20) != nullptr)) {
                    typedef void (*VFn)(float, float, uint32_t, uint32_t);
                    void** vt = *reinterpret_cast<void***>(reinterpret_cast<char*>(self) + 0x20);
                    VFn f = reinterpret_cast<VFn>(vt[0]); // placeholder for +0x44 offset math: (**(self+0x20)+0x44) => index 0x11
                    // More precise: list shows (**(in_ECX+0x20)+0x44) so index = 0x44/4=17
                    typedef void (*VFn2)(float, float, uint32_t, uint32_t);
                    VFn2 ff = reinterpret_cast<VFn2>(vt[17]);
                    (void)f;
                    ff(param_1, (param_1 + *reinterpret_cast<float*>(iVar1 + 0x1c)) - fVar2, uVar3, *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x14));
                }
                typedef void (*VFnB)(uint32_t);
                void** vtB = reinterpret_cast<void**>(*param_2);
                VFnB fb = reinterpret_cast<VFnB>(vtB[16]); // +0x40 /4 =16
                fb(uVar3);
            }
            uVar3 = uVar3 + 1;
        } while ((uint16_t)uVar3 < *(uint16_t*)(param_2 + 0x11));
    }
}

// 0x5bb240 — observed shape: FUN_005bbee0(param); FUN_005bd960(self,&param); iVar1=param; if *(self+0x20)!=0: if FUN_005bd960(*(self+0x20),&param)!=0: *(iVar1+0x20)=param else *(iVar1+0x20)=*(self+0x20)
void FUN_005bb240(void* self, int param_1)
{
    FUN_005bbee0(param_1);
    FUN_005bd960(reinterpret_cast<uint32_t>(self), &param_1);
    int iVar1 = param_1;
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x20) != 0) {
        char cVar2 = (char)FUN_005bd960(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20), &param_1);
        if (cVar2 != '\0') {
            *reinterpret_cast<int*>(iVar1 + 0x20) = param_1;
            return;
        }
        *reinterpret_cast<uint32_t*>(iVar1 + 0x20) = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20);
    }
}

// 0x5bb3f0 — observed shape: FUN_005b9670(param); FUN_00545cc0();
void FUN_005bb3f0(uint32_t param_1)
{
    FUN_005b9670(param_1);
    FUN_00545cc0();
}

// 0x5bb410 — observed shape: uVar2=(ushort)param_1 pointer-encode; if uVar2<*(self+0x44) loop: call (**(self+0x58)+0x78)(&param, idx); refcount release if non-null; then if *(self+0xc)<uVar2: *(self+0x44)=*(self+0xc) else *(self+0x44)=uVar2
void FUN_005bb410(void* self, void* param_1)
{
    uint16_t uVar2 = (uint16_t)(intptr_t)param_1;
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(param_1);
    if (uVar2 < *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0x44)) {
        do {
            typedef void (*VFn)(uint32_t**, uint32_t);
            void** vt = *reinterpret_cast<void***>(reinterpret_cast<char*>(self) + 0x58);
            VFn f = reinterpret_cast<VFn>(vt[30]); // +0x78/4=30
            f(reinterpret_cast<uint32_t**>(&param_1), (uint32_t)(intptr_t)puVar3 & 0xffff);
            if (param_1 != nullptr) {
                uint32_t* pp = reinterpret_cast<uint32_t*>(param_1);
                int iVar1 = pp[1];
                pp[1] = iVar1 + -1;
                if (iVar1 + -1 == 0) {
                    typedef void (*VFn0)(unsigned int);
                    VFn0 g = reinterpret_cast<VFn0>(*pp);
                    g(1);
                }
            }
            puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar3) + 1);
        } while ((uint16_t)(intptr_t)puVar3 < *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0x44));
    }
    if (*reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0xc) < uVar2) {
        *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0x44) = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0xc);
        return;
    }
    *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(self) + 0x44) = uVar2;
}

// 0x5bb480 — observed shape: FUN_005b9400(param1,param2); pu3=(**(self+0x58)+8)(param2); refcount assign *(param1+0x58)=pu3; copy byte *(param1+0x5c)=*(self+0x5c) in all paths
void FUN_005bb480(void* self, int param_1, uint32_t param_2)
{
    FUN_005b9400(param_1, param_2);
    typedef uint32_t* (*VFn)(void*, uint32_t);
    void** vt = *reinterpret_cast<void***>(reinterpret_cast<char*>(self) + 0x58);
    VFn f = reinterpret_cast<VFn>(vt[2]); // +8 /4=2
    uint32_t* puVar3 = f(*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x58), param_2);
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(param_1 + 0x58));
    if (puVar2 == puVar3) {
        *reinterpret_cast<uint8_t*>(param_1 + 0x5c) = *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x5c);
        return;
    }
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*VFn0)(unsigned int);
            VFn0 g = reinterpret_cast<VFn0>(*puVar2);
            g(1);
        }
    }
    *reinterpret_cast<uint32_t**>(param_1 + 0x58) = puVar3;
    if (puVar3 == nullptr) {
        *reinterpret_cast<uint8_t*>(param_1 + 0x5c) = *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x5c);
        return;
    }
    puVar3[1] = puVar3[1] + 1;
    *reinterpret_cast<uint8_t*>(param_1 + 0x5c) = *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x5c);
}

// 0x5bb4f0 — observed shape: thunk_FUN_00513ce0(param); pu=FUN_00545600(); refcount assign to self+0x58
void FUN_005bb4f0(void* self, uint32_t param_1)
{
    thunk_FUN_00513ce0(param_1);
    uint32_t* puVar3 = FUN_00545600();
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x58);
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*VFn)(unsigned int);
                VFn f = reinterpret_cast<VFn>(*puVar2);
                f(1);
            }
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x58) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x5bb7a0 — observed shape: FUN_005e4780(); FUN_005b9220(); if (param&1) operator_delete(self)
void FUN_005bb7a0(void* self, unsigned char param_1)
{
    FUN_005e4780();
    FUN_005b9220();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
