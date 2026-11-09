// Reconstruction batch mass_0034 — Sid Meier's Pirates! (2004) PE32 i386
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern FILE* DAT_008c84c0;
extern int DAT_008c84bc;
extern double _DAT_008c84c8;
extern uint32_t DAT_008c84dc;
extern int DAT_008c8494;
extern int DAT_008e9fd8;
extern int DAT_008ed910;
extern int DAT_008ed8e8;
extern int DAT_008e9fe4;
extern int DAT_00726ae8;
extern int DAT_00726aec;
extern int DAT_00726af0;
extern char DAT_0070c05c;
extern char DAT_0070c054;
extern double DAT_008c84c8b;
extern double DAT_008cabd4;
extern char DAT_008cabc4;
extern int DAT_008cabc0;
extern int DAT_008cabb8;
extern int DAT_008cabbc;
extern int DAT_008cabb0;
extern int DAT_008cabb4;
extern int DAT_007260d8;
extern int DAT_007260d4;
extern char DAT_008cac36;
extern int DAT_008cabd8;
extern int DAT_008cabcc;
extern int DAT_008cabd0;
extern int DAT_008c97c4;
extern int DAT_008c97c0;
extern int DAT_008c9dec;
extern int DAT_008c9df4;
extern int DAT_008e8f7c;
extern int DAT_008e8f80;
extern int DAT_008e8f84;
extern int DAT_00717868;
extern int DAT_00717878;
extern int DAT_00717864;
extern int DAT_00717874;
extern int DAT_00717860;
extern int DAT_00717870;
extern int DAT_00727560;
extern int DAT_00727600;
extern int DAT_00727608;
extern int DAT_007177b8;
extern int DAT_007177c4;
extern int DAT_007177ac;
extern void* PTR_DAT_007271cc;
extern void* PTR_DAT_007271c8;
extern uint8_t DAT_008c8c60;
extern uint8_t DAT_008c8620;
extern uint8_t DAT_008caba8;
extern uint8_t DAT_008cab88;
extern int DAT_006c05dc;
extern int DAT_006c05cc;
extern void* Ordinal_7(void*);
extern void* Ordinal_8();
extern void* Ordinal_9(void*);
extern int FUN_004ac910(uint32_t a0);
extern float FUN_004aaf00();
extern int FUN_004acb00(char* mode);
extern void FUN_004f0af0(uint32_t a0, uint32_t a1);
extern void FUN_004acd50(uint32_t p1, uint32_t p2);
extern void FUN_004acda0();
extern int FUN_004ace40(void* a0, void* a1);
extern void FUN_004ad050(int* out);
extern void FUN_0053c6f0(void* a0, void* a1, void* a2);
extern void FUN_0053c780(float v);
extern void FUN_0053c7c0(float v);
extern void FUN_0053c740(float v);
extern void* FUN_0053c8d0(void* a0, void* a1);
extern void FUN_004ff6b0(void* a0);
extern void FUN_004ff510(float a0, uint32_t a1);
extern void FUN_004ad820();
extern int FUN_00533db0(int a0);
extern int FUN_005f0ddc();
extern void FUN_005be280(const char* name, uint32_t size, void* data);
extern int FUN_00449390(void* a0, void* a1);
extern void FUN_004ad8f0(void* self);
extern void FUN_004adc20(void* a0, void* a1);
extern void FUN_004adb00(void* a0);
extern void FUN_004adb60(void* a0);
extern void FUN_00533d10(float a0, int a1);
extern void FUN_004ae0d0(void* a0, void* a1);
extern void FUN_004bbc10(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7, void* a8);
extern void FUN_004bbe10(void* a0, void* a1);
extern void FUN_004bbf50();
extern void FUN_004e52c0();

// 0x4acb00 — strstr on GetCommandLineA, copy to local buffer, strtok token, overwrite drive prefix with D:\, fopen
FILE* FUN_004acb00(char* param_1, char* in_EAX)
{
    char cVar1;
    char* pcVar3;
    char local_100[256];
    LPSTR _Str = GetCommandLineA();
    pcVar3 = strstr(_Str, in_EAX);
    if (pcVar3 == nullptr) return DAT_008c84c0;
    int iVar2 = -(int)(intptr_t)pcVar3;
    do {
        cVar1 = *pcVar3;
        pcVar3[(int)(local_100 + iVar2 - (char*)0)] = cVar1;
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = strtok(local_100 + 3, " ");
    if (pcVar3 == nullptr) return DAT_008c84c0;
    strncpy(pcVar3 + -3, "D:\\", 3);
    DAT_008c84c0 = fopen(pcVar3 + -3, param_1);
    return DAT_008c84c0;
}

// 0x4acb90 — mode dispatch: 1=return, 2=write header + diff floats, 3=read loop until index 0x14
void FUN_004acb90()
{
    uint32_t uVar1;
    uint32_t* _Str = (uint32_t*)PTR_DAT_007271cc;
    if (DAT_008c84bc != 1) {
        if (DAT_008c84bc == 2) {
            if (*_Str < 0x14) *_Str = 0x14;
            fwrite(_Str, 8, 1, DAT_008c84c0);
            int local_8 = 0;
            float local_4;
            do {
                local_4 = (float)(*(float*)&DAT_008c8c60 + local_8 * 4) ;
                if (*(float*)&DAT_008c8620 + local_8 * 4 != local_4) {
                    fwrite(&local_8, 4, 1, DAT_008c84c0);
                    fwrite(&local_4, 4, 1, DAT_008c84c0);
                }
                local_8 = local_8 + 1;
            } while (local_8 < 0x14);
            return;
        }
        if (DAT_008c84bc == 3) {
            fread(PTR_DAT_007271cc, 8, 1, DAT_008c84c0);
            uVar1 = *_Str;
            while (uVar1 < 0x14) {
                FUN_004ac910(*(uint32_t*)PTR_DAT_007271c8);
                fread(PTR_DAT_007271cc, 8, 1, DAT_008c84c0);
                uVar1 = *_Str;
            }
            if ((*(uint8_t*)((uint8_t*)DAT_008c84c0 + 0xc) & 0x10) != 0) DAT_008c84bc = 1;
        }
    }
    return;
}

// 0x4accc0 — lazy file init via FUN_004acb00, then clock read or cached double
float FUN_004accc0()
{
    int iVar1;
    double fVar2;
    if (DAT_008c84bc == 0) {
        iVar1 = FUN_004acb00(&DAT_0070c05c) ? 1 : 0;
        if (iVar1 == 0) {
            iVar1 = FUN_004acb00(&DAT_0070c054) ? 1 : 0;
            DAT_008c84bc = (iVar1 != 0) + 1;
        } else {
            DAT_008c84bc = 3;
        }
    }
    if (DAT_008c84bc != 3) {
        fVar2 = FUN_004aaf00();
        _DAT_008c84c8 = fVar2;
        return (float)fVar2;
    }
    if (_DAT_008c84c8 == 0.0) fread(&_DAT_008c84c8, 8, 1, DAT_008c84c0);
    return (float)_DAT_008c84c8;
}

// 0x4acd50 — repeat FUN_004f0af0 (in_EAX-1 or 3 to 0 inclusive)
void FUN_004acd50(uint32_t param_1, uint32_t param_2, int in_EAX)
{
    uint32_t uVar1 = 0;
    uint32_t uVar2 = 3;
    if (in_EAX == 0) in_EAX = DAT_008c84dc;
    if (in_EAX != 0) { uVar1 = (uint32_t)(in_EAX - 1); uVar2 = uVar1; }
    for (; uVar1 <= uVar2; uVar1++) FUN_004f0af0(param_1, param_2);
    return;
}

// 0x4acda0 — iterate table stride 0x1c, lerp floats toward DAT_008c8494 target
void FUN_004acda0()
{
    uint32_t uVar1;
    float fVar2, fVar3;
    int iVar4 = DAT_008c8494;
    uint8_t* puVar6 = &DAT_008caba8;
    uint8_t* pcVar5 = &DAT_008cab88;
    do {
        if (*pcVar5 != '\0') {
            uVar1 = *(uint32_t*)(pcVar5 + -4);
            if (uVar1 < (uint32_t)(iVar4 - *(int*)(pcVar5 + -8))) {
                FUN_004acd50(0, 0, 0);
                *pcVar5 = '\0';
            } else {
                fVar3 = (float)(iVar4 - *(int*)(pcVar5 + -8));
                fVar2 = (float)(int)uVar1;
                if ((int)uVar1 < 0) fVar2 = fVar2 + 4.2949673e+09f;
                FUN_004acd50((*(float*)(pcVar5 + -0x10) - *(float*)(pcVar5 + -0x18)) * fVar3 / fVar2 + *(float*)(pcVar5 + -0x18),
                             ((*(float*)(pcVar5 + -0xc) - *(float*)(pcVar5 + -0x14)) * fVar3) / fVar2 + *(float*)(pcVar5 + -0x14), 0);
            }
        }
        puVar6 = puVar6 + 1;
        pcVar5 = pcVar5 + 0x1c;
    } while ((int)(intptr_t)puVar6 < 0x8cabb0);
    return;
}

// 0x4ace40 — CoInitialize, CoCreateInstance CLSCTX_INPROC (1), vtable calls +0xc/+0x10/+0x14/+0x20, GetValue dwDirectXVersionMajor/Minor/szDirectXVersionLetter, WideCharToMultiByte, CoUninitialize
int FUN_004ace40(void* in_EAX_param, int* unaff_ESI, uint16_t* out_major, uint16_t* out_minor, char* out_letter)
{
    HRESULT HVar2 = CoInitialize(nullptr);
    bool bVar4 = -1 < HVar2;
    int piVar1 = (int)((uint32_t)bVar4 << 0x18);
    int* local_34 = nullptr;
    HVar2 = CoCreateInstance((REFIID*)*(void**)&DAT_006c05dc, nullptr, 1, (REFIID*)*(void**)&DAT_006c05cc, (void**)&local_34);
    if (-1 < HVar2) {
        int local_10 = 0x10, local_c = 0x6f, local_8 = 0, local_4 = 0;
        int* piVar6 = local_34;
        int iVar3 = (*(int(**)())(*(int*)local_34 + 0xc))();
        if (-1 < iVar3) {
            wchar_t* pWStack_38 = nullptr;
            iVar3 = (*(int(**)())(piVar1 + 0x10))();
            if (-1 < iVar3) {
                short sVar5 = (short)0 - 6;
                wchar_t* lpWideCharStr = pWStack_38;
                iVar3 = (*(int(**)())(*(int*)pWStack_38 + 0x14))();
                if (-1 < iVar3) {
                    Ordinal_8();
                    iVar3 = (*(int(**)())(*(int*)piVar6 + 0x20))(piVar6, L"dwDirectXVersionMajor");
                    if ((-1 < iVar3) && ((short)(int)(intptr_t)unaff_ESI == 0x13)) {
                        if (in_EAX_param) *(int*)in_EAX_param = piVar1;
                    }
                    Ordinal_9();
                    iVar3 = (*(int(**)(void*, wchar_t*, void*))(**(int**)&local_34 + 8))(local_34, L"dwDirectXVersionMinor", nullptr);
                    if ((-1 < iVar3) && (sVar5 == 0x13)) {
                        if (unaff_ESI) *unaff_ESI = (int)((uint32_t)&local_10);
                        // flag set
                    }
                    Ordinal_9();
                    iVar3 = (*(int(**)(void*, wchar_t*))(*(int*)piVar1 + 0x20))(piVar1, L"szDirectXVersionLetter");
                    if ((-1 < iVar3) && ((short)0 == 8) && Ordinal_7(lpWideCharStr)) {
                        WideCharToMultiByte(0, 0, lpWideCharStr, -1, (LPSTR)&piVar1, 10, nullptr, nullptr);
                    }
                    Ordinal_9(&piVar1);
                    (*(int(**)())(*(int*)piVar1 + 8))();
                }
                (*(int(**)())(*(int*)unaff_ESI + 8))();
            }
        }
        (*(int(**)())(piVar1 + 8))();
    }
    if (bVar4) CoUninitialize();
    return 0x80004005;
}

// 0x4ad050 — call FUN_004ace40(&local_4, &local_9), combine in unaff_ESI slot as (local_8*0x100+local_4)*0x100 + ('a'..'z' mapped)
void FUN_004ad050(int* unaff_ESI)
{
    int iVar1;
    int local_8 = 0;
    int local_4 = 0;
    char local_9 = ' ';
    if (unaff_ESI) *unaff_ESI = 0;
    FUN_004ace40(&local_4, &local_9);
    if (unaff_ESI) {
        iVar1 = (local_8 * 0x100 + local_4) * 0x100;
        if (('`' < local_9) && (local_9 < '{')) iVar1 = iVar1 + -0x60 + (int)local_9;
        *unaff_ESI = iVar1;
    }
    return;
}

// 0x4ad0c0 — guarded init + position/color/FOV update, updates DAT_008e9fd8+0x38/0x5c/0x60/100
void FUN_004ad0c0(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
{
    int iVar1;
    uint8_t local_d8[36], local_b4[36], local_90[36], local_6c[36], local_48[36], local_24[36];
    if ((DAT_008ed910 & 1) == 0) {
        DAT_008ed910 = DAT_008ed910 | 1;
        FUN_0053c6f0(&DAT_007177b8, &DAT_007177c4, &DAT_007177ac);
    }
    if (DAT_008cabc4 == '\0') {
        if (((param_4 != DAT_007260d8) || (param_5 != DAT_008cabb8)) || (param_6 != DAT_008cabbc)) {
            FUN_0053c780((float)param_4 * 1.4629181e-09f);
            FUN_0053c7c0((float)param_5 * 1.4629181e-09f);
            FUN_0053c740((float)param_6 * 1.4629181e-09f);
            iVar1 = DAT_008e9fd8;
            FUN_0053c8d0(local_24, local_90);
            FUN_0053c8d0(local_48, local_d8);
            void* puVar2 = FUN_0053c8d0(local_6c, local_b4);
            uint32_t* puVar4 = (uint32_t*)(iVar1 + 0x38);
            uint32_t* src = (uint32_t*)puVar2;
            for (int i = 9; i != 0; i--) { *puVar4++ = *src++; }
            FUN_004ff6b0(nullptr);
            DAT_007260d8 = param_4; DAT_008cabb8 = param_5; DAT_008cabbc = param_6;
        }
        if (param_7 != DAT_008cabc0) {
            uint32_t uVar8 = (DAT_008cac36 == '\0') ? 0x3faaaaab : 0x3fe38e39;
            FUN_004ff510((float)param_7 * 8.381903e-08f, uVar8);
            DAT_008cabc0 = param_7;
        }
        iVar1 = DAT_008e9fd8;
        if (((param_1 != DAT_007260d4) || (param_2 != DAT_008cabb0)) || (param_3 != DAT_008cabb4)) {
            *(float*)(DAT_008e9fd8 + 0x5c) = (float)param_1;
            DAT_007260d4 = param_1;
            *(float*)(iVar1 + 0x60) = (float)param_2;
            *(float*)(iVar1 + 100) = (float)param_3;
            DAT_008cabb0 = param_2; DAT_008cabb4 = param_3;
            return;
        }
    } else {
        FUN_0053c780((float)DAT_008cabd8 * 1.4629181e-09f);
        FUN_0053c7c0((float)DAT_008cabcc * 1.4629181e-09f);
        FUN_0053c740((float)DAT_008cabd0 * 1.4629181e-09f);
        iVar1 = DAT_008e9fd8;
        FUN_0053c8d0(local_6c, local_b4);
        FUN_0053c8d0(local_48, local_d8);
        void* puVar2 = FUN_0053c8d0(local_24, local_90);
        uint32_t* puVar4 = (uint32_t*)(iVar1 + 0x38);
        uint32_t* src = (uint32_t*)puVar2;
        for (int i = 9; i != 0; i--) { *puVar4++ = *src++; }
        *(uint32_t*)(DAT_008e9fd8 + 0x5c) = DAT_008e8f7c;
        *(uint32_t*)(iVar1 + 0x60) = DAT_008e8f80;
        *(uint32_t*)(iVar1 + 100) = DAT_008e8f84;
        FUN_004ff6b0(nullptr);
    }
    return;
}

// 0x4ad3d0 — same as 0x4ad0c0 but position scaled *0.1
void FUN_004ad3d0(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
{
    int iVar1;
    uint8_t local_d8[36], local_b4[36], local_90[36], local_6c[36], local_48[36], local_24[36];
    if ((DAT_008ed8e8 & 1) == 0) {
        DAT_008ed8e8 = DAT_008ed8e8 | 1;
        FUN_0053c6f0(&DAT_007177b8, &DAT_007177c4, &DAT_007177ac);
    }
    if (DAT_008cabc4 == '\0') {
        if (((param_4 != DAT_007260d8) || (param_5 != DAT_008cabb8)) || (param_6 != DAT_008cabbc)) {
            FUN_0053c780((float)param_4 * 1.4629181e-09f);
            FUN_0053c7c0((float)param_5 * 1.4629181e-09f);
            FUN_0053c740((float)param_6 * 1.4629181e-09f);
            iVar1 = DAT_008e9fd8;
            FUN_0053c8d0(local_24, local_90);
            FUN_0053c8d0(local_48, local_d8);
            void* puVar2 = FUN_0053c8d0(local_6c, local_b4);
            uint32_t* puVar4 = (uint32_t*)(iVar1 + 0x38);
            uint32_t* src = (uint32_t*)puVar2;
            for (int i = 9; i != 0; i--) { *puVar4++ = *src++; }
            FUN_004ff6b0(nullptr);
            DAT_007260d8 = param_4; DAT_008cabb8 = param_5; DAT_008cabbc = param_6;
        }
        if (param_7 != DAT_008cabc0) {
            uint32_t uVar8 = (DAT_008cac36 == '\0') ? 0x3faaaaab : 0x3fe38e39;
            FUN_004ff510((float)param_7 * 8.381903e-08f, uVar8);
            DAT_008cabc0 = param_7;
        }
        iVar1 = DAT_008e9fd8;
        if (((param_1 != DAT_007260d4) || (param_2 != DAT_008cabb0)) || (param_3 != DAT_008cabb4)) {
            DAT_007260d4 = param_1;
            *(float*)(DAT_008e9fd8 + 0x5c) = (float)param_1 * 0.1f;
            DAT_008cabb0 = param_2;
            *(float*)(iVar1 + 0x60) = (float)param_2 * 0.1f;
            *(float*)(iVar1 + 100) = (float)param_3 * 0.1f;
            DAT_008cabb4 = param_3;
            return;
        }
    } else {
        FUN_0053c780((float)DAT_008cabd8 * 1.4629181e-09f);
        FUN_0053c7c0((float)DAT_008cabcc * 1.4629181e-09f);
        FUN_0053c740((float)DAT_008cabd0 * 1.4629181e-09f);
        iVar1 = DAT_008e9fd8;
        FUN_0053c8d0(local_6c, local_b4);
        FUN_0053c8d0(local_48, local_d8);
        void* puVar2 = FUN_0053c8d0(local_24, local_90);
        uint32_t* puVar4 = (uint32_t*)(iVar1 + 0x38);
        uint32_t* src = (uint32_t*)puVar2;
        for (int i = 9; i != 0; i--) { *puVar4++ = *src++; }
        *(uint32_t*)(DAT_008e9fd8 + 0x5c) = DAT_008e8f7c;
        *(uint32_t*)(iVar1 + 0x60) = DAT_008e8f80;
        *(uint32_t*)(iVar1 + 100) = DAT_008e8f84;
        FUN_004ff6b0(nullptr);
    }
    return;
}

// 0x4ad6f0 — FUN_004bbc10 + FUN_004bbe10 + FUN_004bbf50, clear byte at unaff_ESI+0x24
void FUN_004ad6f0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, int* unaff_ESI, uint32_t in_EDX, uint32_t in_ECX, uint32_t in_EAX)
{
    FUN_004bbc10(unaff_ESI, (void*)(intptr_t)param_3, (void*)(intptr_t)param_4, (void*)(intptr_t)param_5, (void*)(intptr_t)in_EDX, (void*)(intptr_t)in_ECX, (void*)(intptr_t)in_EAX, (void*)(intptr_t)0xffffffff, nullptr);
    FUN_004bbe10((void*)(intptr_t)param_1, (void*)(intptr_t)param_2);
    FUN_004bbf50();
    *(uint8_t*)((uint8_t*)unaff_ESI + 0x24) = 0;
    return;
}

// 0x4ad730 — store 3 params at FUN_00533db0(2)+0x28/0x2c/0x30, tail call FUN_004ad820
void FUN_004ad730(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    int iVar1 = FUN_00533db0(2);
    *(uint32_t*)(iVar1 + 0x28) = param_1;
    *(uint32_t*)(iVar1 + 0x2c) = param_2;
    *(uint32_t*)(iVar1 + 0x30) = param_3;
    FUN_004ad820();
    return;
}

// 0x4ad760 — copy 3 dwords from FUN_00533db0(2)+0x28..0x30 into unaff_ESI
void FUN_004ad760(uint32_t* unaff_ESI)
{
    int iVar1 = FUN_00533db0(2);
    unaff_ESI[0] = *(uint32_t*)(iVar1 + 0x28);
    unaff_ESI[1] = *(uint32_t*)(iVar1 + 0x2c);
    unaff_ESI[2] = *(uint32_t*)(iVar1 + 0x30);
    return;
}

// 0x4ad790 — fog = clamp((100-in_ECX)*0.01,0) at FUN_00533db0(2)+0x24, call FUN_004ad820
void FUN_004ad790(int in_ECX)
{
    float fVar1 = (float)(100 - in_ECX) * 0.01f;
    int iVar2 = FUN_00533db0(2);
    if (0.0f <= fVar1) {
        *(float*)(iVar2 + 0x24) = fVar1;
        FUN_004ad820();
        return;
    }
    *(uint32_t*)(iVar2 + 0x24) = 0;
    FUN_004ad820();
    return;
}

// 0x4ad7f0 — return 100 - FUN_005f0ddc() after FUN_00533db0(2)
int FUN_004ad7f0()
{
    FUN_00533db0(2);
    int iVar1 = FUN_005f0ddc();
    return 100 - iVar1;
}

// 0x4ad820 — upload fog params via FUN_005be280(f4FogColor 0x10, f3FogValues 0xc)
void FUN_004ad820()
{
    int iVar1 = FUN_00533db0(2);
    uint8_t local_10[16];
    uint8_t local_20[12];
    if (iVar1 == 0) {
        *(uint32_t*)(local_10 + 12) = 0x3f000000;
        *(float*)(local_10 + 8) = 0.5f;
        *(float*)(local_10 + 4) = 0.5f;
        *(float*)(local_10 + 0) = 0.5f;
    } else {
        *(uint32_t*)(local_10 + 0) = *(uint32_t*)(iVar1 + 0x28);
        *(uint32_t*)(local_10 + 4) = *(uint32_t*)(iVar1 + 0x2c);
        *(uint32_t*)(local_10 + 8) = *(uint32_t*)(iVar1 + 0x30);
        *(uint32_t*)(local_10 + 12) = 0x3f800000;
        *(float*)(local_20 + 0) = 1.0f / *(float*)(DAT_008e9fd8 + 0x13c);
        *(float*)(local_20 + 4) = 1.0f - *(float*)(iVar1 + 0x24);
        *(float*)(local_20 + 8) = 1.0f / (1.0f - *(float*)(local_20 + 4));
    }
    FUN_005be280("f4FogColor", 0x10, local_10);
    FUN_005be280("f3FogValues", 0xc, local_20);
    return;
}

// 0x4ad8f0 — copy 9 dwords from surface at *(int*)(in_ECX[0x10]+0xc), dither-blend noise loop, bump counter at +0x4c
void FUN_004ad8f0(int* in_ECX)
{
    int iVar12 = in_ECX[0x10];
    *(uint8_t*)((uint8_t*)in_ECX + 0x44) = 0;
    if (iVar12 == 0) {
        (*(int(**)())(*(int*)in_ECX + 0x3c))();
        iVar12 = in_ECX[0x10];
    }
    int* piVar13 = (int*)(iVar12 + 0xc);
    int local_24[9];
    int* piVar15 = local_24;
    for (int i = 9; i != 0; i--) { *(piVar15++) = *(piVar13++); }
    if (local_24[0] == 0) {
        uint32_t* puVar14 = (uint32_t*)(*(int*)(iVar12 + 0x40) + *(int*)(iVar12 + 0x34));
        if (puVar14 != nullptr) {
            int iVar9 = **(int**)(iVar12 + 0x38);
            int iVar1 = **(int**)(iVar12 + 0x3c);
            uint32_t uStack_4 = local_24[4];
            uint32_t uVar10 = uStack_4 & DAT_00717868;
            uint8_t bVar6 = (uint8_t)DAT_00717878;
            uint32_t uVar11 = uStack_4 & DAT_00717864;
            uint8_t bVar7 = (uint8_t)DAT_00717874;
            uint32_t uVar2 = uStack_4 & DAT_00717860;
            uint8_t bVar8 = (uint8_t)DAT_00717870;
            int iVar3 = FUN_005f0ddc();
            bVar7 = (uint8_t)(uVar11 >> (bVar7 & 0x1f));
            uint32_t uVar16 = iVar3 << (bVar7 & 0x1f) & local_24[3];
            iVar3 = FUN_005f0ddc();
            bVar6 = (uint8_t)(uVar10 >> (bVar6 & 0x1f));
            uVar10 = iVar3 << (bVar6 & 0x1f) & local_24[5];
            iVar3 = FUN_005f0ddc();
            bVar8 = (uint8_t)(uVar2 >> (bVar8 & 0x1f));
            uVar2 = iVar3 << (bVar8 & 0x1f) & local_24[2];
            iVar3 = FUN_005f0ddc();
            int iVar4 = FUN_005f0ddc();
            int iVar5 = FUN_005f0ddc();
            int iStack_38 = 0;
            uint32_t mask = ((uint32_t)(local_24[8] != '\x18') - 1 & 0x1000000) - 1;
            (void)mask;
            uint32_t uVar11b = ((uint32_t)(*(uint8_t*)&local_24[8] != 0x18) - 1 & 0x1000000) - 1;
            if (0 < iVar1) {
                do {
                    int iStack_30 = iVar9;
                    if (iStack_38 < iVar1 / 2) {
                        if (0 < iVar9) {
                            do {
                                *puVar14 = ~uVar11b & *puVar14 | uVar11b & (uVar16 + uVar10 + uVar2);
                                puVar14 = (uint32_t*)((uint8_t*)puVar14 + *(int*)(iVar12 + 0x48));
                                iStack_30--;
                            } while (iStack_30 != 0);
                        }
                    } else if (0 < iVar9) {
                        do {
                            *puVar14 = ~uVar11b & *puVar14 | uVar11b & ((iVar3 << (bVar7 & 0x1f) & local_24[3]) + (iVar4 << (bVar6 & 0x1f) & local_24[5]) + (iVar5 << (bVar8 & 0x1f) & local_24[2]));
                            puVar14 = (uint32_t*)((uint8_t*)puVar14 + *(int*)(iVar12 + 0x48));
                            iStack_30--;
                        } while (iStack_30 != 0);
                    }
                    iStack_38++;
                } while (iStack_38 < iVar1);
            }
        }
        *(int*)(iVar12 + 0x4c) = *(int*)(iVar12 + 0x4c) + 1;
    }
    return;
}

// 0x4adb00 — vtable +0x40 -> FUN_00449390 chains via DAT_00727560/DAT_00727600, refcount dec + destructor at 0
uint32_t FUN_004adb00(int* param_1)
{
    int iVar2 = (*(int(**)())(*(int*)param_1 + 0x40))();
    uint32_t uVar3 = 0;
    if (iVar2 != 0) {
        iVar2 = FUN_00449390((void*)&DAT_00727560, (void*)(intptr_t)iVar2);
        if (((iVar2 != 0) && (*(int*)(iVar2 + 0xc0) != 0)) && (**(int**)(iVar2 + 0xb8) != 0)) {
            uVar3 = FUN_00449390((void*)&DAT_00727600, **(void***)(iVar2 + 0xb8));
        }
    }
    int* piVar1 = param_1 + 1;
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) (*(int(**)(int))(**(int**)param_1)(1);
    return uVar3;
}

// 0x4adb60 — search list for DAT_00727608, else scan param_1[0x2e]/param_1[0x30] children, refcount dec
uint32_t FUN_004adb60(int* param_1)
{
    uint32_t local_4 = 0;
    if (param_1 != nullptr) {
        uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(**)())(*(int*)param_1 + 4))();
        while (puVar3 != nullptr) {
            if (puVar3 == (uint32_t*)&DAT_00727608) {
                local_4 = FUN_00449390((void*)&DAT_00727608, param_1);
                goto LAB_004adbfd;
            }
            puVar3 = (uint32_t*)puVar3[1];
        }
    }
    if (param_1[0x30] != 0) {
        uint32_t uVar1 = param_1[0x30];
        uint32_t uVar4 = 0;
        do {
            if ((uVar4 < (uint32_t)param_1[0x30]) && (*(int**)(param_1[0x2e] + uVar4 * 4) != nullptr)) {
                int* piVar2 = *(int**)(param_1[0x2e] + uVar4 * 4);
                uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(**)())(*(int*)piVar2 + 4))();
                while (puVar3 != nullptr) {
                    if (puVar3 == (uint32_t*)&DAT_00727608) {
                        local_4 = FUN_00449390((void*)&DAT_00727608, piVar2);
                        break;
                    }
                    puVar3 = (uint32_t*)puVar3[1];
                }
            }
            uVar4++;
        } while (uVar4 < uVar1);
    }
LAB_004adbfd:
    {
        int* piVar2 = param_1 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (*(int(**)(int))(**(int**)param_1)(1);
    }
    return local_4;
}

// 0x4adc20 — publish f3LightDir/f3LightColor/f4AmbientColor, average colors, call FUN_004e52c0 twice
void FUN_004adc20(int* in_EAX, int* in_ECX, int* unaff_EDI)
{
    uint32_t local_28[6];
    float local_10[4];
    if (in_EAX != 0) {
        local_28[0] = *(uint32_t*)(in_EAX + 0x110);
        local_28[1] = *(uint32_t*)(in_EAX + 0x114);
        local_28[2] = *(uint32_t*)(in_EAX + 0x118);
        local_28[3] = *(uint32_t*)(in_EAX + 0xf4);
        local_28[4] = *(uint32_t*)(in_EAX + 0xf8);
        local_28[5] = *(uint32_t*)(in_EAX + 0xfc);
        FUN_005be280("f3LightDir", 0xc, &local_28[0]);
        FUN_005be280("f3LightColor", 0xc, &local_28[3]);
    }
    if (in_ECX != 0) {
        local_10[0] = (*(float*)(in_ECX + 0xe8) * *(float*)(in_ECX + 0xe4) + *(float*)(unaff_EDI + 0xf4) * *(float*)(unaff_EDI + 0xe4)) * 0.5f;
        local_10[1] = (*(float*)(in_ECX + 0xec) * *(float*)(in_ECX + 0xe4) + *(float*)(unaff_EDI + 0xf8) * *(float*)(unaff_EDI + 0xe4)) * 0.5f;
        local_10[2] = (*(float*)(in_ECX + 0xf0) * *(float*)(in_ECX + 0xe4) + *(float*)(unaff_EDI + 0xfc) * *(float*)(unaff_EDI + 0xe4)) * 0.5f;
        local_10[3] = (local_10[2] + local_10[1] + local_10[0]) * 0.16666667f;
        FUN_005be280("f4AmbientColor", 0x10, &local_10[0]);
        local_10[0] += local_10[0];
        local_10[1] += local_10[1];
        local_10[2] += local_10[2];
        for (int i = 2; i != 0; i--) FUN_004e52c0();
    }
    return;
}

// 0x4add70 — lighting/material setup via FUN_004adb00/FUN_004adb60, copies, matrix rows, tail FUN_004adc20
void FUN_004add70(int param_1)
{
    if (DAT_008e9fe4 != 0) {
        uint32_t local_18 = 0, local_14 = 0, local_10 = 0;
        uint32_t local_c = 0, local_8 = 0, local_4 = 0;
        DAT_008cabd4 = param_1;
        FUN_00533d10((float)param_1 * 0.01f, 1);
        int iVar3 = DAT_008e9fe4;
        if (DAT_008e9fe4 != 0) *(int*)(DAT_008e9fe4 + 4) = *(int*)(DAT_008e9fe4 + 4) + 1;
        iVar3 = FUN_004adb00((void*)(intptr_t)iVar3);
        uint32_t* puVar4;
        if (iVar3 == 0) {
            iVar3 = FUN_00533db0(2);
            puVar4 = (uint32_t*)(iVar3 + 0x28);
        } else {
            puVar4 = (uint32_t*)(iVar3 + 0xf4);
        }
        iVar3 = DAT_008e9fe4;
        local_18 = puVar4[0]; local_14 = puVar4[1]; local_10 = puVar4[2];
        if (DAT_008e9fe4 != 0) *(int*)(DAT_008e9fe4 + 4) = *(int*)(DAT_008e9fe4 + 4) + 1;
        iVar3 = FUN_004adb00((void*)(intptr_t)iVar3);
        if (iVar3 != 0) {
            local_c = *(uint32_t*)(iVar3 + 0xf4);
            local_8 = *(uint32_t*)(iVar3 + 0xf8);
            local_4 = *(uint32_t*)(iVar3 + 0xfc);
            FUN_004ae0d0(&local_c, &local_18);
        }
        iVar3 = DAT_008e9fe4;
        if (DAT_008e9fe4 != 0) *(int*)(DAT_008e9fe4 + 4) = *(int*)(DAT_008e9fe4 + 4) + 1;
        uint32_t iVar5 = FUN_004adb60((void*)(intptr_t)iVar3);
        iVar3 = DAT_008c97c4;
        if (iVar5 != 0) {
            int iVar6 = *(int*)(DAT_008c97c4 + 0xc0);
            *(uint32_t*)(DAT_008c97c4 + 0xe4) = *(uint32_t*)(iVar5 + 0xe4);
            *(int*)(iVar3 + 0xc0) = iVar6 + 1;
            *(uint32_t*)(iVar3 + 0xe8) = *(uint32_t*)(iVar5 + 0xe8);
            *(uint32_t*)(iVar3 + 0xec) = *(uint32_t*)(iVar5 + 0xec);
            *(uint32_t*)(iVar3 + 0xf0) = *(uint32_t*)(iVar5 + 0xf0);
            *(int*)(iVar3 + 0xc0) = iVar6 + 2;
            *(uint32_t*)(iVar3 + 0xf4) = *(uint32_t*)(iVar5 + 0xf4);
            *(uint32_t*)(iVar3 + 0xf8) = *(uint32_t*)(iVar5 + 0xf8);
            *(uint32_t*)(iVar3 + 0xfc) = *(uint32_t*)(iVar5 + 0xfc);
            *(int*)(iVar3 + 0xc0) = iVar6 + 3;
            *(uint32_t*)(iVar3 + 0x100) = *(uint32_t*)(iVar5 + 0x100);
            *(uint32_t*)(iVar3 + 0x104) = *(uint32_t*)(iVar5 + 0x104);
            *(uint32_t*)(iVar3 + 0x108) = *(uint32_t*)(iVar5 + 0x108);
            *(int*)(iVar3 + 0xc0) = iVar6 + 4;
        }
        iVar3 = DAT_008e9fe4;
        if (DAT_008e9fe4 != 0) *(int*)(DAT_008e9fe4 + 4) = *(int*)(DAT_008e9fe4 + 4) + 1;
        iVar5 = FUN_004adb00((void*)(intptr_t)iVar3);
        iVar3 = DAT_008c97c0;
        if (iVar5 != 0) {
            uint32_t uVar2 = *(uint32_t*)(iVar5 + 0xe4);
            int iVar6 = *(int*)(DAT_008c97c0 + 0xc0);
            *(int*)(DAT_008c97c0 + 0xc0) = iVar6 + 1;
            *(uint32_t*)(iVar3 + 0xe4) = uVar2;
            *(uint32_t*)(iVar3 + 0xe8) = *(uint32_t*)(iVar5 + 0xe8);
            *(uint32_t*)(iVar3 + 0xec) = *(uint32_t*)(iVar5 + 0xec);
            *(uint32_t*)(iVar3 + 0xf0) = *(uint32_t*)(iVar5 + 0xf0);
            *(int*)(iVar3 + 0xc0) = iVar6 + 2;
            *(uint32_t*)(iVar3 + 0xf4) = *(uint32_t*)(iVar5 + 0xf4);
            *(uint32_t*)(iVar3 + 0xf8) = *(uint32_t*)(iVar5 + 0xf8);
            *(uint32_t*)(iVar3 + 0xfc) = *(uint32_t*)(iVar5 + 0xfc);
            *(int*)(iVar3 + 0xc0) = iVar6 + 3;
            *(uint32_t*)(iVar3 + 0x100) = *(uint32_t*)(iVar5 + 0x100);
            *(uint32_t*)(iVar3 + 0x104) = *(uint32_t*)(iVar5 + 0x104);
            uVar2 = *(uint32_t*)(iVar5 + 0x108);
            *(int*)(iVar3 + 0xc0) = iVar6 + 4;
            *(uint32_t*)(iVar3 + 0x108) = uVar2;
            uint32_t* src = (uint32_t*)(iVar5 + 0x6c);
            uint32_t* dst = (uint32_t*)(iVar3 + 0x38);
            for (int i = 9; i != 0; i--) { *(dst++) = *(src++); }
            FUN_00533d10(0, 0);
            iVar6 = DAT_008c97c0;
            iVar3 = *(int*)(DAT_008c9dec + 0x20);
            int* piVar1 = (int*)(DAT_008c97c0 + 0xc0);
            *(uint32_t*)(DAT_008c97c0 + 0xe4) = *(uint32_t*)(iVar5 + 0xe4);
            *(int*)(iVar6 + 0xc0) = *piVar1 + 1;
            iVar6 = *(int*)(iVar3 + 0xc0);
            *(uint32_t*)(iVar3 + 0xf4) = *(uint32_t*)(iVar5 + 0xf4);
            *(uint32_t*)(iVar3 + 0xf8) = *(uint32_t*)(iVar5 + 0xf8);
            *(uint32_t*)(iVar3 + 0xfc) = *(uint32_t*)(iVar5 + 0xfc);
            *(int*)(iVar3 + 0xc0) = iVar6 + 1;
            *(uint32_t*)(iVar3 + 0xe8) = *(uint32_t*)(iVar5 + 0xe8);
            *(uint32_t*)(iVar3 + 0xec) = *(uint32_t*)(iVar5 + 0xec);
            *(uint32_t*)(iVar3 + 0xf0) = *(uint32_t*)(iVar5 + 0xf0);
            *(int*)(iVar3 + 0xc0) = iVar6 + 2;
            *(uint32_t*)(iVar3 + 0x100) = *(uint32_t*)(iVar5 + 0x100);
            *(uint32_t*)(iVar3 + 0x104) = *(uint32_t*)(iVar5 + 0x104);
            *(uint32_t*)(iVar3 + 0x108) = *(uint32_t*)(iVar5 + 0x108);
            *(int*)(iVar3 + 0xc0) = iVar6 + 3;
            FUN_00533d10(0, 0);
            DAT_00726ae8 = *(uint32_t*)(DAT_008c97c0 + 0x110);
            DAT_00726aec = *(uint32_t*)(DAT_008c97c0 + 0x114);
            DAT_00726af0 = *(uint32_t*)(DAT_008c97c0 + 0x118);
            DAT_008c9df4 = 1;
        }
        FUN_004adc20(nullptr, nullptr, nullptr);
    }
    return;
}
