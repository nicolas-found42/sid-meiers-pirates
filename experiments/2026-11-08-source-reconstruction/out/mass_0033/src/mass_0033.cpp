#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <ctime>

extern "C" {
extern int DAT_008cab6e;
extern int DAT_008cac27;
extern int DAT_0086c35c;
extern int DAT_0086c360;
extern void* DAT_00726b3c;
extern int DAT_008ecd7c;
extern int DAT_008ed620;
extern unsigned int DAT_008ea08c;
extern int DAT_00727c30;
extern unsigned int DAT_008cab6d;
extern int DAT_008cac18;
extern int DAT_008cac1c;
extern void* DAT_00713510;
extern void* DAT_005f0c50;
extern void* ExceptionList;
extern void* PTR_FUN_0070c03c;
extern uint32_t _DAT_008ed61c;
extern int DAT_008ed618;
extern int DAT_0085a11c;
extern int DAT_0085a26c;
extern int DAT_008e9fe0;
extern int DAT_008cacd0;
extern int DAT_008cacc8;
extern int DAT_008cacf0;
extern int DAT_008cace8;
extern int DAT_008cacec;
extern int DAT_008c84d4;
extern int DAT_008c84dc;
extern int DAT_008c84d8;
extern int DAT_008caba8;
extern int DAT_008c84bc;
extern int DAT_008cacc1;
extern uint32_t _DAT_008ee1a8;
extern int DAT_008ee1a4;
extern float DAT_008c8b20;
extern float DAT_008c8b24;
extern int DAT_008c8b28;
extern int DAT_008c8b2c;
extern float DAT_008c8da0;
extern float DAT_008c84e0;
extern void* DAT_006fb738;
extern void* PTR_FUN_00704c70;
}

extern int FUN_0042e1d0(int param_1);
extern int FUN_0042e440();
extern int FUN_00498450();
extern void FUN_004ac130();
extern void FUN_004ac200();
extern void FUN_004ac1d0();
extern void FUN_004abca0();
extern int FUN_004abce0(unsigned int param_1);
extern uint8_t FUN_004abf10();
extern int FUN_005f0ddc();
extern void FUN_00412cb0(unsigned int param_1);
extern void FUN_004ac4b0(int* param_1, char* param_2);
extern int FUN_004bb3e0();
extern void FUN_004ac4b0_next();
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern int _BinkSetSoundSystem_8(int a, int b);
extern int _BinkOpenDirectSound_4_exref;
extern int _BinkOpen_8(int* a, int b);
extern int _BinkGetError_0();
extern void _BinkSetVolume_12(int a, int b);
extern int _BinkWait_4();
extern int _BinkDoFrame_4();
extern int _BinkCopyToBuffer_28(int a, int b);
extern int _BinkNextFrame_4();
extern int _BinkClose_4(int a);
extern void* FUN_005002d0();
extern int FUN_004f5480(unsigned int param_1, unsigned int param_2);
extern void FUN_004129c0(int* a, int* b);
extern void FUN_004f8bd0(const char* fmt, ...);
extern int FUN_004aefd0(int param_1);
extern int FUN_004b06c0(int a, int b, int c, int d, int e, int f, int g, int h);
extern void FUN_004d3c60();
extern void FUN_00533d10(int a, int b);
extern void FUN_00535de0(int a);
extern void FUN_004d1130(int a);
extern void FUN_004ac880();
extern void FUN_004ac2b0();
extern void FUN_004ac860();
extern void FUN_004ac660(int* param_1);
extern unsigned int FUN_004ac8d0(const char* param_1, unsigned char param_2);
extern void FUN_004ac910(float param_1);
extern void FUN_004acb90();
extern unsigned int FUN_004f8e40(const void* param_1);
extern unsigned int FUN_00533c78(unsigned int a);
extern int FUN_00476050();
extern void FUN_00412ec0();
extern void FUN_004ce080(int* param_1);
extern int FUN_00489300();
extern int FUN_00412e50(void* param_1);
extern int FUN_004f4ed0();
extern void FUN_00459f80(void* a, char* b, int c);
extern int FUN_004f5670();
extern void FUN_0045a050();
extern void FUN_004f22c0(void* param_1, int param_2);
extern void FUN_004f18c0(int* a, int b);
extern void FUN_004f1c20();
extern void FUN_004f1b10(void** a);
extern unsigned int FUN_004f31c0(void** a, int b);
extern void FUN_004f1840();
extern unsigned int FUN_004f02c0();
extern void FUN_004f0320();
extern void FUN_004f0420();
extern void FUN_004f5720();

// 0x4aba90 — observed shape
void FUN_4aba90(void* self_param)
{
    uint32_t* self = (uint32_t*)self_param;
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    self[4] = 0;
    self[5] = 0;
}

// 0x4abab0 — observed shape
uint32_t FUN_4abab0(LPCRITICAL_SECTION self_param)
{
    void* local_14;
    void** puStack_10;
    void** puStack_c;
    uint32_t local_8;

    puStack_c = &DAT_00713510;
    puStack_10 = &DAT_005f0c50;
    local_14 = ExceptionList;
    local_8 = 0;
    ExceptionList = &local_14;
    InitializeCriticalSection(self_param);
    ExceptionList = local_14;
    return 0;
}

// 0x4abb50 — observed shape
uint8_t FUN_4abb50(uint32_t param_1)
{
    int iVar1;
    uint8_t uVar2;
    float fVar3;
    void* local_2c;

    if (DAT_008cab6e != 0 || DAT_008cac27 != 0)
        return 0;
    do {
        iVar1 = ShowCursor(0);
    } while (iVar1 < 0);
    do {
        iVar1 = FUN_0042e1d0(0);
    } while (iVar1 != 0);
    DAT_0086c35c = 0;
    DAT_0086c360 = 0;
    uVar2 = 1;
    FUN_004abc50();
    FUN_004abca0();
    fVar3 = (float)FUN_00498450();
    iVar1 = FUN_004abce0(param_1);
    if (iVar1 != 0) {
        iVar1 = FUN_004abf10();
        uVar2 = 1;
        if (iVar1 != 0) {
            uVar2 = 1;
            do {
                if (DAT_00726b3c == nullptr || FUN_0042e440() != 0) {
                    uVar2 = 0;
                    break;
                }
                Sleep(0x14);
                iVar1 = FUN_004abf10();
            } while (iVar1 != 0);
        }
        FUN_004ac130();
    }
    FUN_004ac130();
    FUN_004ac200();
    operator_delete__(local_2c);
    FUN_004ac1d0();
    return uVar2;
}

// 0x4abc50 — observed shape
void FUN_4abc50(void* self_param)
{
    uint32_t* self = (uint32_t*)self_param;
    self[0xb] = 0;
    self[0xe] = 1;
    self[0xc] = 0;
    self[0xd] = 0;
    self[10] = 0;
    self[9] = (uint32_t)&PTR_FUN_0070c03c;
    FUN_004ac200();
    self[0] = 0;
    ((uint8_t*)self)[4] = 0;
    ((uint8_t*)self)[5] = 0;
    self[2] = 0;
    self[3] = 0;
    self[4] = 0;
    self[5] = 0;
    ((uint8_t*)self)[6] = 1;
}

// 0x4abca0 — observed shape
void FUN_4abca0()
{
    int* piVar1;
    piVar1 = nullptr;
    if (DAT_008ecd7c != 0) {
        int** vtable_ptr = (int**)DAT_008ecd7c;
        DAT_008ed620 = ((int(*)())vtable_ptr[3])();
        if (DAT_008ed620 == 0) {
            ((int(*)(int*))(*(int***)DAT_008ecd7c)[3])(&DAT_008ed620);
        }
        _BinkSetSoundSystem_8(_BinkOpenDirectSound_4_exref, DAT_008ed620);
    }
}

// 0x4abce0 — observed shape
uint32_t FUN_4abce0(uint32_t param_1, void* self_param)
{
    int* piVar1;
    int iVar2;
    uint32_t uVar3 = 0;
    int iVar4;
    int* piVar5;
    int* piVar6;
    uint32_t* puVar5;
    uint32_t* puVar7;
    int* self_int = (int*)self_param;
    uint32_t* self = (uint32_t*)self_param;
    uint32_t uVar8;
    uint8_t auStack_136[2];
    int local_134[47];
    uint32_t uStack_78;

    iVar2 = FUN_004f5480(param_1, 0);
    if (iVar2 == 0 ||
        (*(int**)(iVar2 + 0x10) != nullptr &&
         (iVar4 = **(int**)(iVar2 + 0x10), *(char*)(*(int*)(iVar4 + -4) + -1 + iVar4) != '\\')))
        return 0;
    FUN_004129c0(local_134, (int*)(iVar2 + 8));
    iVar2 = _BinkOpen_8(local_134, 0);
    *(int*)self_int = iVar2;
    if (iVar2 == 0) {
        uVar3 = _BinkGetError_0();
        FUN_004f8bd0("Bink error: %s", (const char*)uVar3);
        puVar7 = (uint32_t*)(local_134[0] + -8);
        if (puVar7 == nullptr || puVar7 == (uint32_t*)&DAT_008cacc8)
            return 0;
        operator_delete__(puVar7);
        return 0;
    }
    iVar4 = FUN_005f0ddc();
    _BinkSetVolume_12(iVar2, 0);
    if (DAT_008ea08c == 0)
        piVar5 = nullptr;
    else
        piVar5 = *(int**)(DAT_00727c30 + 0x60);
    ((int(*)(int*, void*))(*(int***)piVar5)[7])(piVar5, auStack_136 + -0xe);
    ((uint8_t*)self)[4] = (uint8_t)((uStack_78 >> 4) & 1);
    if ((uStack_78 >> 4 & 1) == 0) {
        uVar8 = 1;
        iVar4 = local_134[0];
        goto LAB_004abeb5;
    }
    if (DAT_008ea08c == 0)
        piVar5 = nullptr;
    else
        piVar5 = *(int**)(DAT_00727c30 + 0x60);
    piVar1 = (int*)(self + 2);
    iVar2 = ((int(*)(int*, uint32_t, uint32_t, uint32_t, uint32_t, int**, uint32_t))(*(int***)piVar5)[0x24])(
                piVar5, *(uint32_t*)self_int, ((uint32_t*)self_int)[1], 0x32595559, 0, (int**)piVar1, 0);
    if (iVar2 != 0) {
        piVar5 = (int*)FUN_005002d0();
        iVar2 = ((int(*)(int*, uint32_t, uint32_t, uint32_t, uint32_t, int**, uint32_t))(*(int***)piVar5)[0x24])(
                    piVar5, *(uint32_t*)self_int, ((uint32_t*)self_int)[1], 0x16, 0, (int**)piVar1, 0);
        if (iVar2 != 0) {
            piVar6 = (int*)FUN_005002d0();
            piVar5 = (int*)(self + 3);
            iVar2 = ((int(*)(int*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int**, uint32_t))(*(int***)piVar6)[0x17])(
                        piVar6, *(uint32_t*)self_int, ((uint32_t*)self_int)[1], 1, 0x200,
                        (-(uint32_t)(*(char*)((int)self_int + 5) != 0) & 0x32595543) + 0x16, 0, (int**)piVar5, 0);
            if (iVar2 != 0 || ((piVar5 = (int*)*piVar5, piVar5 != nullptr &&
                (iVar2 = ((int(*)(int*, uint32_t, int**))(*(int***)piVar5)[0x12])(piVar5, 0, (int**)piVar1), iVar2 != 0))
                || *piVar1 == 0)) {
                FUN_004ac130();
            }
        }
    } else {
        ((uint8_t*)self)[5] = 1;
        uVar3 = 0;
        iVar2 = 0;
    }
    uVar8 = (uint32_t)(iVar2 == 0);
LAB_004abeb5:
    FUN_00412cb0(uVar3);
    FUN_004ac4b0((int*)(self + 7), (char*)uVar3);
    self[0x11] = 0x50;
    self[0x12] = 0xffffff;
    self[0xf] = 0;
    FUN_004bb3e0();
    puVar7 = (uint32_t*)(iVar4 + -8);
    if (puVar7 != nullptr && puVar7 != (uint32_t*)&DAT_008cacc8)
        operator_delete__(puVar7);
    return uVar8;
}

// 0x4abf10 — observed shape
uint8_t FUN_4abf10(int* self_param)
{
    int iVar1;
    int** ppiVar2;
    int* piVar3;
    int* piVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int** ppiStack_40;
    int** ppiStack_3c;
    int** ppiStack_38;
    int*** pppiStack_34;
    int* piStack_30;
    int iStack_2c;
    uint32_t uStack_28;
    int** ppiStack_24;
    int* piStack_20;

    if (*self_param == 0 || DAT_008cac27 != 0)
        return 0;
    iVar1 = _BinkWait_4();
    if (iVar1 != 0)
        return (uint8_t)DAT_008cab6d;
    piStack_20 = (int*)*self_param;
    ppiStack_24 = (int**)0x4abf48;
    _BinkDoFrame_4();
    if (((char*)self_param)[4] == 0) {
        uVar6 = (uint32_t)(DAT_008cac18 - *(int*)*self_param);
        uVar5 = (uint32_t)(DAT_008cac1c - ((int*)*self_param)[1]);
        if (DAT_008ea08c == 0)
            ppiStack_3c = nullptr;
        else
            ppiStack_3c = *(int***)(DAT_00727c30 + 0x60);
        ppiStack_24 = nullptr;
        uStack_28 = 0;
        iStack_2c = 0;
        piStack_30 = (int*)1;
        pppiStack_34 = nullptr;
        ppiStack_38 = nullptr;
        ppiStack_40 = (int**)0x4ac05e;
        (*(int***) ppiStack_3c)[0x2b]();
        piStack_30 = nullptr;
        if (DAT_008ea08c == 0)
            piVar4 = nullptr;
        else
            piVar4 = *(int**)(DAT_00727c30 + 0x60);
        ppiStack_40 = &piStack_30;
        piVar3 = nullptr;
        ((int(*)(int*, uint32_t, uint32_t))(*(int***)piVar4)[0x12])(piVar4, 0, 0);
        iVar1 = ((int(*)(int*, int**, uint32_t, uint32_t))(*(int***)piVar3)[0xd])(piVar3, &ppiStack_40, 0, 0);
        if (iVar1 != 0)
            goto LAB_004ac0f7;
        ppiStack_40 = *(int***)(*self_param + 4);
        pppiStack_34 = (int***)0x80000003;
        piVar4 = piStack_20;
        ppiStack_3c = (int**)(uVar6 >> 1);
        ppiStack_38 = (int**)(uVar5 >> 1);
        iVar1 = _BinkCopyToBuffer_28(*self_param, (int)self_param);
        ((int(*)(int**))(*(int***)ppiStack_40)[0xe])(ppiStack_40);
        ((int(*)(int*))(*(int***)piVar4)[2])(piVar4);
        if (iVar1 != 0)
            goto LAB_004ac0f7;
    } else {
        piVar4 = (int*)self_param[2];
        ppiStack_24 = nullptr;
        uStack_28 = 0;
        iStack_2c = 0;
        pppiStack_34 = (int***)0x4abf65;
        piStack_30 = piVar4;
        iVar1 = ((int(*)(int*))(*(int***)piVar4)[0xd])(piVar4);
        if (iVar1 != 0)
            goto LAB_004ac0f7;
        ppiStack_40 = *(int***)(*self_param + 4);
        pppiStack_34 = (int***)((-(uint32_t)(*(char*)((int)self_param + 5) != 0) & 10) + 3 | 0x80000000);
        ppiStack_38 = nullptr;
        ppiStack_3c = nullptr;
        ppiVar2 = (int**)_BinkCopyToBuffer_28(*self_param, (int)self_param, (int)piStack_20);
        ((int(*)(int*))(*(int***)piVar4)[0xe])(piVar4);
        if (ppiVar2 != nullptr)
            goto LAB_004ac0f7;
        pppiStack_34 = (int***)0x4abfb5;
        ppiStack_24 = ppiVar2;
        piVar3 = (int*)FUN_005002d0();
        pppiStack_34 = &ppiStack_24;
        ppiStack_40 = ppiVar2;
        ppiStack_3c = ppiVar2;
        ppiStack_38 = ppiVar2;
        ((int(*)(int*))(*(int***)piVar3)[0x12])(piVar3);
        piVar3 = (int*)FUN_005002d0();
        ppiVar2 = ppiStack_38;
        iVar1 = ((int(*)(int*, int*, uint32_t, int**, uint32_t, uint32_t))(*(int***)piVar3)[0x22])(
                    piVar3, piVar4, 0, ppiStack_38, 0, (-(uint32_t)(*(char*)((int)self_param + 6) != 0) & 2));
        if (iVar1 != 0 && *(char*)((int)self_param + 6) != 0) {
            piVar3 = (int*)FUN_005002d0();
            ((int(*)(int*, int*, uint32_t, int**, uint32_t, uint32_t))(*(int***)piVar3)[0x22])(piVar3, piVar4, 0, ppiVar2, 0, 0);
            *(uint8_t*)((int)self_param + 6) = 0;
        }
        ((int(*)(int**))(*(int***)ppiVar2)[2])(ppiVar2);
    }
    pppiStack_34 = (int***)0x4ac0e4;
    FUN_004ac340();
    pppiStack_34 = (int***)0x4ac0e9;
    piVar4 = (int*)FUN_005002d0();
    pppiStack_34 = nullptr;
    ppiStack_38 = nullptr;
    ppiStack_3c = nullptr;
    ppiStack_40 = nullptr;
    ((int(*)(int*))(*(int***)piVar4)[0x11])(piVar4);
LAB_004ac0f7:
    iStack_2c = *self_param;
    DAT_008cab6d = (*(uint32_t*)(iStack_2c + 0xc) < *(uint32_t*)(iStack_2c + 8)) ? 1 : 0;
    if (DAT_008cab6d) {
        piStack_30 = (int*)0x4ac114;
        _BinkNextFrame_4();
    }
    return (uint8_t)DAT_008cab6d;
}

// 0x4ac130 — observed shape
void FUN_4ac130(int* self_param)
{
    int* piVar1;
    piVar1 = (int*)self_param[2];
    if (piVar1 != nullptr) {
        ((int(*)(int*))(*(int***)piVar1)[2])(piVar1);
        self_param[2] = 0;
    }
    piVar1 = (int*)self_param[3];
    if (piVar1 != nullptr) {
        ((int(*)(int*))(*(int***)piVar1)[2])(piVar1);
        self_param[3] = 0;
    }
    piVar1 = (int*)self_param[4];
    if (piVar1 != nullptr) {
        ((int(*)(int*))(*(int***)piVar1)[2])(piVar1);
        self_param[4] = 0;
    }
    piVar1 = (int*)self_param[5];
    if (piVar1 != nullptr) {
        ((int(*)(int*))(*(int***)piVar1)[2])(piVar1);
        self_param[5] = 0;
    }
    if (*self_param != 0)
        _BinkClose_4(*self_param);
    *self_param = 0;
    DAT_008cab6d = 0;
    FUN_004ac200();
}

// 0x4ac1a0 — observed shape
void FUN_4ac1a0(void* self_param, uint8_t param_1)
{
    uint32_t* self = (uint32_t*)self_param;
    self[0] = (uint32_t)&PTR_FUN_0070c03c;
    operator_delete__((void*)self[1]);
    if ((param_1 & 1) != 0)
        operator_delete(self_param);
}

// 0x4ac1d0 — observed shape
void FUN_4ac1d0(uint32_t* self_param)
{
    uint32_t uVar1;
    if (*self_param != 0) {
        uVar1 = 0;
        if (*self_param != 0) {
            do {
                ShowCursor(1);
                uVar1 = uVar1 + 1;
            } while (uVar1 < *self_param);
        }
        *self_param = 0;
    }
}

// 0x4ac200 — observed shape
void FUN_4ac200(uint8_t* self_param)
{
    int* piVar1;
    uint32_t* puVar2;
    uint32_t uVar3 = 0;
    *(uint8_t*)self_param = 0;
    *(uint32_t*)(self_param + 0x24) = 0xffffffff;
    *(uint32_t*)(self_param + 4) = 0;
    *(uint32_t*)(self_param + 0x30) = 0;
    *(uint32_t*)(self_param + 0x34) = 0;
    *(uint32_t*)(self_param + 0x2c) = 0;
    *(uint32_t*)(self_param + 0x28) = 100;
    *(uint32_t*)(self_param + 0x20) = 0;
    if (*(int*)(self_param + 0x14) != 0) {
        if (*(int*)(self_param + 0x14) == 0)
            goto LAB_004ac278;
        do {
            piVar1 = *(int**)(*(int*)(self_param + 0xc) + uVar3 * 4);
            *(uint32_t*)(*(int*)(self_param + 0xc) + uVar3 * 4) = 0;
            if (piVar1 != nullptr)
                *(int*)(self_param + 0x18) = *(int*)(self_param + 0x18) + -1;
            if (uVar3 == (uint32_t)(*(int*)(self_param + 0x14) - 1))
                *(uint32_t*)(self_param + 0x14) = (uint32_t)(*(int*)(self_param + 0x14) - 1);
            if (piVar1 != nullptr) {
                puVar2 = (uint32_t*)(*piVar1 + -8);
                if (puVar2 != nullptr && puVar2 != (uint32_t*)&DAT_008cacc8)
                    operator_delete__(puVar2);
                *piVar1 = DAT_008cacd0;
                operator_delete(piVar1);
            }
LAB_004ac278:
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)(self_param + 0x14));
    }
    uVar3 = 0;
    if (*(int*)(self_param + 0x14) != 0) {
        do {
            *(uint32_t*)(*(int*)(self_param + 0xc) + uVar3 * 4) = 0;
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)(self_param + 0x14));
    }
    *(uint32_t*)(self_param + 0x14) = 0;
    *(uint32_t*)(self_param + 0x18) = 0;
}

// 0x4ac2b0 — observed shape
void FUN_4ac2b0(void* self_param, int in_EAX)
{
    uint8_t* self = (uint8_t*)self_param;
    uint32_t uVar1 = *(uint32_t*)(self + 0x28);
    DAT_0085a11c = (int)uVar1;
    FUN_004aefd0(0);
    int iVar2 = FUN_005f0ddc();
    FUN_004b06c0(**(int**)(*(int*)(self + 0xc) + *(int*)(self + 0x24) * 4),
                 DAT_0085a26c / 2, 0x198 - iVar2, (int)uVar1,
                 (in_EAX << 0x18) | *(uint32_t*)(self + 0x2c), 4, 0xffffffff, 0);
    FUN_004d3c60();
    FUN_00533d10(0, 1);
    FUN_00535de0(6);
    ((int(*)())(*(int***)DAT_008e9fe0)[0x1c])();
    FUN_004d1130(0);
}

// 0x4ac340 — observed shape
void FUN_4ac340(void* self_param)
{
    uint8_t* self = (uint8_t*)self_param;
    int* piVar1;
    DWORD DVar2;
    uint32_t uVar3;

    if (*(int*)(self + 0x14) != 0) {
        if (*self == 0)
            FUN_004ac880();
        if (*(int*)(self + 0x24) >= 0) {
            if ((_DAT_008ed61c & 1) == 0) {
                _DAT_008ed61c = _DAT_008ed61c | 1;
                DAT_008ed618 = (int)timeGetTime();
            }
            DVar2 = timeGetTime();
            uVar3 = (DVar2 - *(int*)(self + 0x34)) - (uint32_t)DAT_008ed618;
            piVar1 = (int*)(*(int*)(self + 0xc) + *(int*)(self + 0x24) * 4);
            if (*(uint32_t*)(*piVar1 + 0x10) <= uVar3) {
                if (uVar3 < *(uint32_t*)(*piVar1 + 4)) {
                    if (*(int*)(self + 4) == 0) {
                        self[4] = 1; self[5] = 0; self[6] = 0; self[7] = 0;
                    }
                    if (*(int*)(self + 4) == 1 && *(int*)(self + 0x30) == 0)
                        *(uint32_t*)(self + 0x30) = (uint32_t)(*(int*)(*piVar1 + 8) + (int)uVar3);
                    if (*(uint32_t*)(self + 0x30) < uVar3) {
                        FUN_004ac2b0(self, 0);
                        self[4] = 2; self[5] = 0; self[6] = 0; self[7] = 0;
                        self[0x30] = 0; self[0x31] = 0; self[0x32] = 0; self[0x33] = 0;
                        return;
                    }
                } else {
                    if (*(int*)(self + 4) == 0) {
                        self[4] = 2; self[5] = 0; self[6] = 0; self[7] = 0;
                    }
                    if (*(int*)(self + 4) == 2 && *(int*)(self + 0x30) == 0)
                        *(uint32_t*)(self + 0x30) = (uint32_t)(*(int*)(*piVar1 + 0xc) + (int)uVar3);
                    if (*(uint32_t*)(self + 0x30) < uVar3) {
                        FUN_004ac860();
                        self[4] = 1; self[5] = 0; self[6] = 0; self[7] = 0;
                        self[0x30] = 0; self[0x31] = 0; self[0x32] = 0; self[0x33] = 0;
                        return;
                    }
                }
                FUN_005f0ddc();
                FUN_004ac2b0(self, 0);
                return;
            }
        }
    }
}

// 0x4ac4b0 — observed shape
void FUN_4ac4b0(int* param_1, char* param_2)
{
    int iVar1;
    char cVar2;
    char* pcVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    int local_1c;
    void** local_18;
    uint32_t* local_14;
    uint32_t local_10 = 0;
    int local_c = 0;
    int local_8 = 0;
    uint32_t local_4 = 1;

    iVar1 = *(int*)(param_2 + -4) + -1;
    if (iVar1 < *(int*)(param_2 + -4) && iVar1 >= 0) {
        cVar2 = param_2[iVar1];
        param_2[iVar1] = 0;
        pcVar3 = strrchr(param_2, 0x2e);
        param_2[iVar1] = cVar2;
        if (pcVar3 != nullptr && (int)pcVar3 - (int)param_2 >= 0) {
            FUN_00476050();
            FUN_00412ec0();
            puVar4 = (uint32_t*)(local_1c + -8);
            if (puVar4 != nullptr && puVar4 != (uint32_t*)&DAT_008cacc8)
                operator_delete__(puVar4);
        }
    }
    FUN_004ce080(&local_1c);
    FUN_00489300();
    puVar4 = (uint32_t*)(local_1c + -8);
    if (puVar4 != nullptr && puVar4 != (uint32_t*)&DAT_008cacc8)
        operator_delete__(puVar4);
    FUN_00412e50(&DAT_006fb738);
    local_18 = &PTR_FUN_00704c70;
    cVar2 = (char)FUN_004f4ed0();
    if (cVar2 != 0 && FUN_00459f80(&local_18, param_2, 1), iVar1 = local_c, local_8 != 0 && FUN_004f5670() != 0) {
        local_1c = iVar1;
        puVar4 = local_14;
        do {
            if (*(int*)((char*)*puVar4 + -4) != 0 && *(char*)*puVar4 != ';') {
                puVar5 = (uint32_t*)FUN_00533c78(0x14);
                if (puVar5 != nullptr) {
                    *puVar5 = (uint32_t)&DAT_008cacd0;
                    FUN_004ac660((int*)puVar4);
                }
                if (*(uint32_t*)(param_1 + 0x10) <= *(uint32_t*)(param_1 + 0x14))
                    FUN_004f5670();
                FUN_004f5720();
            }
            puVar4 = puVar4 + 1;
            local_1c = local_1c + -1;
        } while (local_1c != 0);
        local_1c = 0;
    }
    FUN_0045a050();
    param_2 = param_2 + -8;
    if (param_2 != nullptr && param_2 != (char*)&DAT_008cacc8)
        operator_delete__(param_2);
}

// 0x4ac660 — observed shape
void FUN_4ac660(int* param_1, void* self_param)
{
    int* piVar1;
    uint32_t* puVar2;
    uint32_t uVar3;
    uint8_t* self = (uint8_t*)self_param;
    int local_8;
    int local_4;
    void* param_1_local = &DAT_008cacd0;

    piVar1 = param_1;
    *(uint32_t*)(self + 0x10) = 0;
    *(uint32_t*)(self + 4) = 0;
    *(uint32_t*)(self + 8) = 0x2ee;
    *(uint32_t*)(self + 0xc) = 0x2ee;
    FUN_004f22c0(self, 0x40);
    if (*(int*)(*piVar1 + -4) != 0) {
        local_8 = 0;
        FUN_004f18c0(&local_8, 0x2c);
        FUN_00412ec0();
        puVar2 = (uint32_t*)(local_4 + -8);
        if (puVar2 != nullptr && puVar2 != (uint32_t*)&DAT_008cacc8)
            operator_delete__(puVar2);
        FUN_004f1c20();
        FUN_004f1b10(&param_1_local);
        uVar3 = FUN_004f31c0(&param_1_local, 10);
        *(uint32_t*)(self + 0x10) = uVar3;
        FUN_004f18c0(&local_8, 0x2c);
        FUN_00412ec0();
        puVar2 = (uint32_t*)(local_4 + -8);
        if (puVar2 != nullptr && puVar2 != (uint32_t*)&DAT_008cacc8)
            operator_delete__(puVar2);
        FUN_004f1c20();
        FUN_004f1b10(&param_1_local);
        uVar3 = FUN_004f31c0(&param_1_local, 10);
        *(uint32_t*)(self + 4) = uVar3;
        FUN_004f18c0(&local_8, 0x2c);
        FUN_00412ec0();
        puVar2 = (uint32_t*)(local_4 + -8);
        if (puVar2 != nullptr && puVar2 != (uint32_t*)&DAT_008cacc8)
            operator_delete__(puVar2);
        FUN_004f1c20();
        FUN_004f1b10(&param_1_local);
        uVar3 = FUN_004f31c0(&param_1_local, 10);
        *(uint32_t*)(self + 8) = uVar3;
        FUN_004f18c0(&local_8, 0x2c);
        FUN_00412ec0();
        puVar2 = (uint32_t*)(local_4 + -8);
        if (puVar2 != nullptr && puVar2 != (uint32_t*)&DAT_008cacc8)
            operator_delete__(puVar2);
        FUN_004f1c20();
        FUN_004f1b10(&param_1_local);
        uVar3 = FUN_004f31c0(&param_1_local, 10);
        *(uint32_t*)(self + 0xc) = uVar3;
        FUN_004f1840();
        FUN_00412ec0();
        puVar2 = (uint32_t*)(local_8 + -8);
        if (puVar2 != nullptr && puVar2 != (uint32_t*)&DAT_008cacc8)
            operator_delete__(puVar2);
        FUN_004f1c20();
        FUN_004f1b10(&self);
        FUN_004f22c0(self, 0x40);
        puVar2 = (uint32_t*)((int)param_1_local + -8);
        if (puVar2 != nullptr && puVar2 != (uint32_t*)&DAT_008cacc8)
            operator_delete__(puVar2);
    }
}

// 0x4ac860 — observed shape
void FUN_4ac860(void* self_param)
{
    uint8_t* self = (uint8_t*)self_param;
    if (*self != 0) {
        if (*(int*)(self + 0x24) + 1 < *(int*)(self + 0x14)) {
            *(int*)(self + 0x24) = *(int*)(self + 0x24) + 1;
            return;
        }
        self[0x24] = (uint8_t)-1; self[0x25] = (uint8_t)-1; self[0x26] = (uint8_t)-1; self[0x27] = (uint8_t)-1;
    }
}

// 0x4ac880 — observed shape
void FUN_4ac880(uint8_t* self_param)
{
    uint32_t uVar1 = _DAT_008ed61c & 1;
    DWORD DVar2;
    *self_param = 1;
    if (uVar1 == 0) {
        _DAT_008ed61c = _DAT_008ed61c | 1;
        DAT_008ed618 = (int)timeGetTime();
    }
    DVar2 = timeGetTime();
    *(DWORD*)(self_param + 0x34) = DVar2 - (DWORD)DAT_008ed618;
    if (*self_param != 0) {
        if (*(int*)(self_param + 0x24) + 1 < *(int*)(self_param + 0x14)) {
            *(int*)(self_param + 0x24) = *(int*)(self_param + 0x24) + 1;
            return;
        }
        self_param[0x24] = (uint8_t)-1; self_param[0x25] = (uint8_t)-1; self_param[0x26] = (uint8_t)-1; self_param[0x27] = (uint8_t)-1;
    }
}

// 0x4ac8d0 — observed shape
// NEEDS_MANUAL: variadic / inlined argument packing and extra register params (param_1, param_2/in_EAX) inconsistent between call sites; prototype reconstructed from single-listing shape only.
uint32_t FUN_4ac8d0(uint32_t param_1, uint8_t param_2, int in_EAX)
{
    uint32_t uVar1;
    (void)param_1;
    if (DAT_008cacf0 == 0 || (in_EAX != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))
        return 0;
    uVar1 = FUN_004f8e40(&param_2);
    return uVar1;
}

// 0x4ac910 — observed shape
void FUN_4ac910(int base_EBX, int index_EDI, float param_1)
{
    int iVar1;
    int iVar2;
    float* pfVar3;
    iVar1 = base_EBX + index_EDI * 0x14;
    pfVar3 = (float*)(&DAT_008c8b20 + iVar1 * 4);
    if (param_1 <= 1.0) {
        if (param_1 < -1.0)
            param_1 = -1.0;
    } else {
        param_1 = 1.0;
    }
    if (*pfVar3 == 0.0) {
        if (param_1 != 0.0) {
            iVar2 = DAT_007260cc + DAT_008c84d4;
            (&DAT_008c8b24)[iVar1 * 4] = (float)DAT_008c84d4;
            *(int*)(&DAT_008c8b2c + iVar1 * 0x10) = iVar2;
            FUN_004ac8d0(0, 0, 0);
        }
        if (*pfVar3 == 0.0)
            goto LAB_004ac9e0;
    }
    if (param_1 == 0.0) {
        *(int*)(&DAT_008c8b28 + iVar1 * 0x10) = DAT_008c84d4;
        FUN_004ac8d0(0, 0, 0);
    }
LAB_004ac9e0:
    if (*pfVar3 == param_1) {
        *pfVar3 = param_1;
        return;
    }
    FUN_004ac8d0(0, 0, 0);
    *pfVar3 = param_1;
}

// 0x4aca20 — observed shape
void FUN_4aca20(uint8_t in_AL)
{
    uint32_t uVar1;
    float* pfVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    int iVar2;

    uVar1 = (uint32_t)DAT_008c84d4;
    DAT_008c84dc = DAT_008caba8;
    DAT_008c84d8 = DAT_008c84d4;
    DAT_008c84d4 = FUN_005f0ddc();
    if (DAT_008c84d4 <= (int)uVar1)
        DAT_008c84d4 = (int)uVar1 + 1;
    if (in_AL != 0 && DAT_008c84bc == 3) {
        // fall through to in_AL handling below
    } else {
        if ((_DAT_008ee1a8 & 1) == 0) {
            _DAT_008ee1a8 = _DAT_008ee1a8 | 1;
            DAT_008ee1a4 = (int)FUN_004f02c0();
        }
        if (DAT_008cacc1 == 0) {
            FUN_004f0320();
            FUN_004f0420();
        }
    }
    if (in_AL != 0)
        FUN_004acb90();
    pfVar3 = (float*)&DAT_008c8da0;
    do {
        FUN_4ac910(0, 0, pfVar3[-0x50] + *pfVar3 + pfVar3[0x50] + pfVar3[0xa0]);
        pfVar3 = pfVar3 + 4;
    } while ((uintptr_t)pfVar3 < 0x8c8ee0);
    puVar4 = (uint32_t*)&DAT_008c8b20;
    puVar5 = (uint32_t*)&DAT_008c84e0;
    for (iVar2 = 400; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
    }
}
