#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <cwchar>
#include <cctype>
#include <cstdint>

extern void FUN_004f7fe0(void* self, uint32_t param_1);
extern void FUN_004fd340(void* self);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void FUN_004f77b0(void* self, uint32_t param_2);
extern void* FUN_00533c78(uint32_t size);
extern void FUN_004b0b90(int self);
extern void FUN_004b0df0(uint32_t param_1);
extern void FUN_004f10f0(void* param_1, uint32_t param_2);
extern void FUN_004fe190(void* param_1);
extern void FUN_004f1220(uint32_t param_1, uint32_t param_2);
extern void FUN_004f4e80(uint32_t param_1, uint32_t param_2);
extern void* FUN_004f3050();
extern void* FUN_004f3a80();
extern void FUN_004fe220();
extern void* PTR_FUN_00710694;
extern void* PTR_FUN_006f583c;
extern void* PTR_FUN_007106a4;
extern void* PTR_FUN_0071065c;
extern void* PTR_FUN_00710678;
extern void* PTR_FUN_00704c70;
extern void MT_008cacd0;
extern void MT_008cacd0_w;
extern uint8_t DAT_008cacd0[];
extern uint8_t DAT_008cacc8[];
extern uint8_t DAT_00710810[];
extern uint8_t DAT_00710808[];
extern uint8_t DAT_008cacf0;
extern uint32_t DAT_008cace8;
extern uint32_t DAT_008cacec;
extern uint32_t DAT_007264dc;
void operator_delete__(void* p);

// 0x4f7f80 — observed shape: self in EAX, sets vftable, calls FUN_004f7fe0(0), zero-fills fields at 0x58..0x74/0x98..0x70 etc, sets ptr fields, ends with FUN_004fd340.
void FUN_004f7f80(void* self)
{
    uint32_t* fields = (uint32_t*)self;
    fields[0] = (uint32_t)PTR_FUN_00710694;
    FUN_004f7fe0(self, 0);
    fields[0x16] = (uint32_t)DAT_008cacd0;
    fields[0x10] = 0;
    fields[0x11] = 0;
    fields[0x12] = 0;
    fields[0x13] = 0;
    fields[0x14] = 0;
    fields[0x15] = 0;
    fields[0xf] = (uint32_t)PTR_FUN_006f583c;
    fields[0x19] = 0;
    fields[0x1a] = 0;
    fields[0x1b] = (uint32_t)DAT_008cacd0;
    fields[0x1c] = 0;
    fields[0x1d] = 0;
    FUN_004fd340(self);
}

// 0x4f7fe0 — observed shape: self (ESI), param_1 stored at +0; zeroes enum fields, allocates 0x94 via thunk_FUN_00533c78, memset-like zero loop over (field & 0x3fffffff), then FUN_004f77b0(self+1, 0x32).
void FUN_004f7fe0(void* self, uint32_t param_1)
{
    uint32_t* fields = (uint32_t*)self;
    fields[3] = 0;
    fields[6] = 1;
    fields[4] = 0;
    fields[5] = 0;
    fields[2] = 0;
    fields[1] = (uint32_t)PTR_FUN_007106a4;
    fields[7] = (uint32_t)PTR_FUN_0071065c;
    fields[8] = 0x25;
    fields[10] = 0;
    uint32_t* buf = (uint32_t*)thunk_FUN_00533c78(0x94);
    fields[9] = (uint32_t)buf;
    if (buf) {
        uint32_t n = fields[8] & 0x3fffffff;
        uint32_t* p = buf;
        for (uint32_t i = 0; i != n; i++) {
            *p = 0;
            p++;
        }
        // second byte loop: Ghidra loop with iVar3=0 never iterates; preserved as no-op.
        int i = 0;
        for (; i != 0; i = i + -1) {
            *(uint8_t*)p = 0;
            p = (uint32_t*)((intptr_t)p + 1);
        }
    }
    fields[7] = (uint32_t)PTR_FUN_00710678;
    FUN_004f77b0(fields + 1, 0x32);
    fields[0] = param_1;
}

// 0x4f80b0 — observed shape: self in EAX, param_1; lazy-allocs 0x18-byte object at +8 when null, grow check then FUN_004b0df0(param_1).
void FUN_004f80b0(void* self, uint32_t param_1)
{
    int selfAddr = (int)(intptr_t)self;
    if (*(int*)(selfAddr + 8) == 0) {
        uint32_t* node = (uint32_t*)FUN_00533c78(0x18);
        if (node == 0) {
            node = 0;
        } else {
            node[2] = 0;
            node[5] = 1;
            node[3] = 0;
            node[4] = 0;
            node[1] = 0;
            node[0] = (uint32_t)PTR_FUN_00704c70;
        }
        *(uint32_t**)(selfAddr + 8) = node;
    }
    int iVar1 = *(int*)(selfAddr + 8);
    if (*(uint*)(iVar1 + 8) <= *(uint*)(iVar1 + 0xc)) {
        FUN_004b0b90(iVar1);
    }
    FUN_004b0df0(param_1);
}

// 0x4f8110 — observed shape: param_1 = this pointer; scatters to 0xcccccccc sentinel, branches on +0x2c field; byte-wise scan of result for 0xef/0xbb/0xbe patterns, writes +0x30/+0x14.
void FUN_004f8110(int param_1)
{
    int self = param_1;
    int* p2c = (int*)(param_1 + 0x2c);
    uint32_t tmp = 0xcccccccc;
    if (*p2c == 0) {
        FUN_004f10f0(&tmp, 4);
    } else {
        FUN_004fe190(&tmp);
    }
    uint8_t b0 = (uint8_t)(tmp & 0xff);
    uint8_t b1 = (uint8_t)((tmp >> 8) & 0xff);
    uint8_t b2 = (uint8_t)((tmp >> 16) & 0xff);
    uint8_t b3 = (uint8_t)((tmp >> 24) & 0xff);
    if (b0 == 0xef) {
        if ((b1 != 0xbb) || (b2 != 0xbf)) {
            *(uint32_t*)(self + 0x30) = 0;
            if (*(int*)(self + 0x2c) == 0) {
                FUN_004f1220(0, 0);
                return;
            }
            *(uint32_t*)(*(int*)(self + 0x2c) + 0x14) = 0;
            return;
        }
        int iVar3 = *(int*)(self + 0x2c);
        *(uint32_t*)(self + 0x30) = 1;
        if (iVar3 == 0) {
            FUN_004f1220(3, 0);
            return;
        }
        uint32_t uVar4 = *(uint32_t*)(iVar3 + 0x18);
        if (2 < uVar4) {
            *(uint32_t*)(iVar3 + 0x14) = 3;
            return;
        }
        *(uint32_t*)(iVar3 + 0x14) = uVar4;
        return;
    } else {
        bool bVar5;
        if (b0 == 0xff) {
            bVar5 = (b1 == 0xfe);
        } else {
            if (b0 != 0xfe) {
                if (((b0 == 0) && (b1 == 0)) && (b2 == 0xfe) && (b3 == 0xff)) {
                    *(uint32_t*)(self + 0x30) = 1;
                    FUN_004f4e80(4, 0);
                    return;
                }
                *(uint32_t*)(self + 0x30) = 0;
                if (*(int*)(self + 0x2c) == 0) {
                    FUN_004f1220(0, 0);
                    return;
                }
                *(uint32_t*)(*(int*)(self + 0x2c) + 0x14) = 0;
                return;
            }
            bVar5 = (b1 == 0xff);
        }
        if (!bVar5) {
            *(uint32_t*)(self + 0x30) = 0;
            if (*(int*)(self + 0x2c) == 0) {
                FUN_004f1220(0, 0);
                return;
            }
            *(uint32_t*)(*(int*)(self + 0x2c) + 0x14) = 0;
            return;
        }
        int iVar3 = *(int*)(self + 0x2c);
        *(uint32_t*)(self + 0x30) = 1;
        if (iVar3 == 0) {
            FUN_004f1220(2, 0);
            return;
        }
        uint32_t uVar4 = *(uint32_t*)(iVar3 + 0x18);
        if (1 < uVar4) {
            uVar4 = 2;
        }
        *(uint32_t*)(iVar3 + 0x14) = uVar4;
        return;
    }
}

// 0x4f8250 — observed shape: param_1 = this; wide/narrow depending on +0x30; computes remaining uVar8 = avail - +0x40, writes string/wstring + resets +0x3c.
void FUN_004f8250(int param_1)
{
    int iVar2 = *(int*)(param_1 + 0x2c);
    int iVar4;
    if (iVar2 == 0) {
        iVar4 = *(int*)(param_1 + 0x24);
    } else {
        iVar4 = *(int*)(iVar2 + 0x18);
    }
    if (iVar4 == 0) {
        *(uint32_t*)(param_1 + 0x3c) = 0;
        return;
    }
    if (iVar2 == 0) {
        iVar4 = *(int*)(param_1 + 0x24);
    } else {
        iVar4 = *(int*)(iVar2 + 0x18);
    }
    uint32_t uVar9 = *(uint32_t*)(param_1 + 0x40);
    uint32_t uVar8 = (uint32_t)(iVar4 - (int)uVar9);
    if (iVar2 == 0) {
        FUN_004f1220(uVar9, 0);
    } else {
        if ((int)uVar9 < 1) {
            uVar9 = 0;
        } else if (*(uint32_t*)(iVar2 + 0x18) < uVar9) {
            *(uint32_t*)(iVar2 + 0x14) = *(uint32_t*)(iVar2 + 0x18);
            goto LAB_004f82a9;
        }
        *(uint32_t*)(iVar2 + 0x14) = uVar9;
    }
LAB_004f82a9:
    if (*(int*)(param_1 + 0x30) == 0) {
        uint32_t* uVar5 = (uint32_t*)FUN_004f3050();
        if (*(int*)(param_1 + 0x2c) == 0) {
            FUN_004f10f0(uVar5, uVar8);
        } else {
            FUN_004fe190(uVar5);
        }
        if (uVar8 == 0xffffffff) {
            char* pcVar3 = *(char**)(param_1 + 0x34);
            char* pcVar6 = pcVar3;
            char cVar1;
            do {
                cVar1 = *pcVar6;
                pcVar6++;
            } while (cVar1 != '\0');
            *(int*)(pcVar3 + -4) = (int)(intptr_t)pcVar6 - (int)(intptr_t)(pcVar3 + 1);
        } else {
            *(uint32_t*)(*(int*)(param_1 + 0x34) + -4) = uVar8;
            if (0 < (int)uVar8) {
                *(uint8_t*)(uVar8 + *(int*)(param_1 + 0x34)) = 0;
                *(uint32_t*)(param_1 + 0x3c) = 0;
                return;
            }
        }
    } else {
        uint32_t uVar9b = uVar8 >> 1;
        uint32_t* uVar5 = (uint32_t*)FUN_004f3a80();
        if (*(int*)(param_1 + 0x2c) == 0) {
            FUN_004f10f0(uVar5, uVar8);
        } else {
            FUN_004fe190(uVar5);
        }
        if (uVar9b == 0xffffffff) {
            wchar_t* _Str = *(wchar_t**)(param_1 + 0x38);
            size_t sVar7 = wcslen(_Str);
            *(size_t*)(_Str + -2) = sVar7;
            *(uint32_t*)(param_1 + 0x3c) = 0;
            return;
        }
        *(uint32_t*)(*(int*)(param_1 + 0x38) + -4) = uVar9b;
        if (uVar9b != 0) {
            *(uint16_t*)(*(int*)(param_1 + 0x38) + uVar9b * 2) = 0;
            *(uint32_t*)(param_1 + 0x3c) = 0;
            return;
        }
    }
    *(uint32_t*)(param_1 + 0x3c) = 0;
    return;
}
extern uint32_t FUN_004f84d0(void* self);
extern uint32_t FUN_004f85e0(void* self, void* param_2);
extern void FUN_004f3130(void* self);
extern void FUN_004f1840(void* self);
extern void FUN_00412ec0(void* self);
extern void FUN_00475ff0(uint32_t param_1);
extern void FUN_004f1cc0(void* param_1);
extern void FUN_004f1ba0(void* param_1, void* param_2);
extern void* FUN_004f33d0(void* self);
extern void* FUN_004f3e90(void* self);
extern void FUN_004f3d30(uint32_t param_1);
extern void FUN_004f34c0(void* self);
extern void FUN_004f3450(void* param_1);

// 0x4f83a0 — observed shape: self in ECX, param_1 value, param_2 mode; if +0x20 != 1 delegates around +0x40; else clamped counter at +0x3c with max from +0x34/+0x38.
uint32_t FUN_004f83a0(void* self, uint32_t param_1, int param_2)
{
    int base = (int)(intptr_t)self;
    if (*(int*)(base + 0x20) != 1) {
        if (*(int*)(base + 0x30) != 0) {
            param_1 = param_1 * 2;
        }
        if (param_2 == 0) {
            param_1 = param_1 + *(int*)(base + 0x40);
        }
        int iVar1;
        if (*(int*)(base + 0x2c) == 0) {
            iVar1 = FUN_004f1220(param_1, param_2);
        } else {
            iVar1 = FUN_004fe220();
        }
        uint32_t uVar2 = (uint32_t)(iVar1 - *(int*)(base + 0x40));
        if (*(int*)(base + 0x30) != 0) {
            uVar2 = uVar2 >> 1;
        }
        return uVar2;
    }
    if ((param_1 == 0) && (param_2 == 1)) goto LAB_004f8412;
    int iVar1;
    if (*(int*)(base + 0x30) == 0) {
        iVar1 = *(int*)(base + 0x34);
    } else {
        iVar1 = *(int*)(base + 0x38);
    }
    uint32_t uVar2 = *(uint32_t*)(iVar1 + -4);
    if (param_2 == 0) {
        if (0 < (int)param_1) {
LAB_004f83f7:
            if (param_1 <= uVar2) {
                *(uint32_t*)(base + 0x3c) = param_1;
                return param_1;
            }
            goto LAB_004f83e5;
        }
    } else {
        if (param_2 == 1) {
            if (0 < (int)param_1) {
                param_1 = param_1 + *(int*)(base + 0x3c);
                goto LAB_004f83f7;
            }
            uVar2 = *(uint32_t*)(base + 0x3c);
        } else {
            if (param_2 != 2) goto LAB_004f8412;
            if (-1 < (int)param_1) goto LAB_004f83e5;
        }
        if (-(int)param_1 < (int)uVar2 || -(int)uVar2 == (int)param_1) {
            uVar2 = uVar2 + param_1;
LAB_004f83e5:
            *(uint32_t*)(base + 0x3c) = uVar2;
            return uVar2;
        }
    }
    *(uint32_t*)(base + 0x3c) = 0;
LAB_004f8412:
    return *(uint32_t*)(base + 0x3c);
}

// 0x4f8460 — observed shape: self in EAX; if +0x30 != 1 forwards to FUN_004f84d0 else wide get + wcslen + FUN_004f3130 + conditional delete.
uint32_t FUN_004f8460(void* self)
{
    int base = (int)(intptr_t)self;
    if (*(int*)(base + 0x30) != 1) {
        uint32_t uVar2 = (uint32_t)FUN_004f84d0(self);
        return uVar2;
    }
    wchar_t* local_4 = (wchar_t*)DAT_008cacd0;
    uint32_t uVar2 = (uint32_t)FUN_004f85e0(self, &local_4);
    wchar_t* pwVar1 = local_4;
    if (local_4 != 0) {
        wcslen(local_4);
    }
    FUN_004f3130(self);
    pwVar1 = pwVar1 + -4;
    if ((pwVar1 != 0) && (pwVar1 != (wchar_t*)DAT_008cacc8)) {
        operator_delete__(pwVar1);
    }
    return uVar2;
}

// 0x4f84d0 — observed shape: self (ESI), param_1 = &out char*; if +0x30 != 0 returns 0; if +0x20 == 1 line-skip path else char-by-char via FUN_004f8980 until '\n'.
uint32_t FUN_004f84d0(void* self, int* param_1)
{
    uint32_t* s = (uint32_t*)self;
    if (s[0xc] != 0) {
        return 0;
    }
    int local_4 = (int)(intptr_t)self;
    if (s[8] == 1) {
        int iVar3 = s[0xf];
        if ((*(int*)(s[0xd] + -4) <= iVar3) ||
           (((iVar3 < 0 || (strchr((char*)(s[0xd] + iVar3), 10) == 0)) ||
           (iVar3 = (int)(intptr_t)strchr((char*)(s[0xd] + iVar3), 10) - s[0xd], iVar3 == -1)))) {
            iVar3 = *(int*)(s[0xd] + -4);
        }
        FUN_004f1840(self);
        FUN_00412ec0(self);
        uint32_t* puVar4 = (uint32_t*)(local_4 + -8);
        if ((puVar4 != 0) && (puVar4 != (uint32_t*)DAT_008cacc8)) {
            operator_delete__(puVar4);
        }
        s[0xf] = iVar3 + 1;
        uint32_t uVar5 = (**(uint32_t(**)(uint32_t*))(*(uint32_t**)self + 0x10))();
        if (uVar5 < (uint32_t)s[0xf]) {
            iVar3 = (**(int(**)(uint32_t*))(*(uint32_t**)self + 0x10))();
            s[0xf] = iVar3;
        }
    } else {
        if (*(int*)((uint8_t*)*param_1 + -4) != 0) {
            *(uint8_t*)*param_1 = 0;
            *(uint32_t*)(*param_1 + -4) = 0;
        }
        char cVar1;
        do {
            cVar1 = FUN_004f8980(self, &local_4);
            if (cVar1 != '\0') {
                FUN_00475ff0(local_4);
            }
        } while (((char)local_4 != '\n') && (cVar1 != '\0'));
    }
    FUN_004f1cc0(param_1);
    FUN_004f1ba0(param_1, DAT_00710810);
    return *(uint32_t*)(*param_1 + -4);
}

// 0x4f85e0 — observed shape: wide variant of 0x4f84d0; self->int fields; if +0x30 != 1 returns 0; wchar line-skip via wcschr or per-wchar loop via FUN_004f8a00.
uint32_t FUN_004f85e0(void* self, void* param_2p)
{
    int* s = (int*)self;
    if (s[0xc] != 1) {
        return 0;
    }
    int* piVar1 = s;
    if (s[8] == 1) {
        int iVar4 = s[0xf];
        int* piVar7 = s + 0xe;
        wchar_t* pwVar3;
        if ((((*(int*)(s[0xe] + -4) <= iVar4) || (iVar4 < 0)) ||
           (pwVar3 = wcschr((wchar_t*)(s[0xe] + iVar4 * 2), L'\n'), pwVar3 == 0)) ||
           (iVar4 = ((int)(intptr_t)pwVar3 - *piVar7) >> 1, iVar4 == -1)) {
            iVar4 = *(int*)(*piVar7 + -4);
        }
        FUN_004f33d0(self);
        piVar7 = (int*)param_2p;
        FUN_004f3e90();
        int* piVar5 = s + (-2);
        if ((piVar5 != 0) && (piVar5 != (int*)DAT_008cacc8)) {
            operator_delete__(piVar5);
        }
        piVar1[0xf] = iVar4 + 1;
        uint32_t uVar6 = (**(uint32_t(**)(int*))(*(int**)piVar1 + 0x10))();
        if (uVar6 < (uint32_t)piVar1[0xf]) {
            iVar4 = (**(int(**)(int*))(*(int**)piVar1 + 0x10))();
            piVar1[0xf] = iVar4;
        }
    } else {
        if (*(int*)((uint16_t*)*(int*)param_2p + -2) != 0) {
            *(uint16_t*)*(int*)param_2p = 0;
            *(uint32_t*)(*(int*)param_2p + -4) = 0;
        }
        int tempParam1 = (int)(intptr_t)self;
        char cVar2;
        do {
            cVar2 = (char)FUN_004f8a00(self, &tempParam1);
            if (cVar2 != '\0') {
                FUN_004f3d30(tempParam1);
            }
        } while (((short)tempParam1 != 10) && (cVar2 != '\0'));
    }
    FUN_004f34c0(self);
    FUN_004f3450(DAT_00710808);
    return *(uint32_t*)(*(int*)param_2p + -4);
}

// 0x4f87c0 — observed shape: self in EAX; if +0x30 != 1 delegates to FUN_004f8830; else strlen loop over in_ECX string then FUN_004f3b00 + FUN_004f8880.
extern uint32_t FUN_004f8830(void* self);
extern uint32_t FUN_004f8880(void* self);
extern void FUN_004f3b00(void* param_1);
uint32_t FUN_004f87c0(void* self)
{
    int base = (int)(intptr_t)self;
    if (*(int*)(base + 0x30) != 1) {
        uint32_t uVar3 = FUN_004f8830(self);
        return uVar3;
    }
    char* pcVar2 = *(char**)(base + 0x34);
    uint8_t* local_4 = DAT_008cacd0;
    if (pcVar2 != 0) {
        char cVar1;
        do {
            cVar1 = *pcVar2;
            pcVar2++;
        } while (cVar1 != '\0');
    }
    FUN_004f3b00(&local_4);
    uint32_t uVar3 = FUN_004f8880(self);
    uint32_t* puVar4 = (uint32_t*)(local_4 + -8);
    if ((puVar4 != 0) && (puVar4 != (uint32_t*)DAT_008cacc8)) {
        operator_delete__(puVar4);
    }
    return uVar3;
}
extern void FUN_004f10f0(void* param_1, uint32_t param_2);
extern void FUN_004fe190(void* param_1);
extern int FUN_004f10f0_2(void* param_1, uint32_t param_2);
extern void FUN_004f8e40(void* param_1);
extern uint32_t FUN_004f8830(void* self);

// 0x4f8830 — observed shape: self (ESI), param = &out char*; if +0x30 != 0 returns 0; adjusts length prefix then virtual +0x24 twice with DAT_00710810.
uint32_t FUN_004f8830(void* self, void** param_1)
{
    uint32_t* s = (uint32_t*)self;
    if (s[0xc] != 0) {
        return 0;
    }
    uint8_t* puVar1 = (uint8_t*)*param_1;
    int iVar2 = *(int*)(puVar1 + -4);
    if (*(int*)(puVar1 + -8) < 0) {
        if (iVar2 != 0) {
            *puVar1 = 0;
            *(uint32_t*)(*param_1 + -4) = 0;
        }
        *(int*)(*param_1 + -4) = iVar2;
    }
    uint32_t uVar3 = (**(uint32_t(**)(void*, int))(*(uint32_t**)self + 0x24))(*param_1, iVar2);
    (**(void(**)(void*, int))(*(uint32_t**)self + 0x24))(DAT_00710810, 2);
    return uVar3;
}

// 0x4f8880 — observed shape: wide variant of 0x4f8830; requires +0x30 == 1; wchar length adjust (offsets -2/-4) then virtual +0x24 with DAT_00710808.
uint32_t FUN_004f8880(void* self, void** param_1)
{
    uint32_t* s = (uint32_t*)self;
    if (s[0xc] != 1) {
        return 0;
    }
    uint16_t* puVar1 = (uint16_t*)*param_1;
    int iVar2 = *(int*)(puVar1 + -2);
    if (*(int*)(puVar1 + -4) < 0) {
        if (iVar2 != 0) {
            *puVar1 = 0;
            *(uint32_t*)(*param_1 + -4) = 0;
        }
        *(int*)(*param_1 + -4) = iVar2;
    }
    uint32_t uVar3 = (**(uint32_t(**)(void*, int))(*(uint32_t**)self + 0x24))(*param_1, iVar2);
    (**(void(**)(void*, int))(*(uint32_t**)self + 0x24))(DAT_00710808, 2);
    return uVar3;
}

// 0x4f8900 — observed shape: self in ECX; if +0x30 != 1 delegates to FUN_004f8980; else FUN_004f8a00 to local, on success FUN_004f3130 + copy + delete.
uint32_t FUN_004f8900(void* self)
{
    int base = (int)(intptr_t)self;
    if (*(int*)(base + 0x30) != 1) {
        uint32_t uVar3 = (uint32_t)FUN_004f8980(self, (void*)base);
        return uVar3;
    }
    uint32_t local_c = 0;
    char cVar1 = FUN_004f8a00(self, &local_c);
    if (cVar1 != '\0') {
        uint32_t local_8 = local_c;
        uint8_t* local_10 = DAT_008cacd0;
        FUN_004f3130(self);
        uint32_t* puVar2 = (uint32_t*)(local_10 + -8);
        *(uint8_t*)self = *local_10;
        (void)local_8;
        if ((puVar2 != 0) && (puVar2 != (uint32_t*)DAT_008cacc8)) {
            operator_delete__(puVar2);
        }
    }
    return (cVar1 != '\0') ? 1 : 0;
}

// 0x4f8980 — observed shape: self in ECX, param_1 = &out byte; only when +0x30 == 0; if +0x20 == 1 memory-buffer path (+0x3c index) else FUN_004f10f0/004fe190.
uint32_t FUN_004f8980(void* self, uint8_t* param_1)
{
    int base = (int)(intptr_t)self;
    *param_1 = 0;
    if (*(int*)(base + 0x30) == 0) {
        if (*(int*)(base + 0x20) == 1) {
            uint32_t uVar1 = *(uint32_t*)(base + 0x3c);
            if (uVar1 < *(uint32_t*)(*(int*)(base + 0x34) + -4)) {
                *(uint32_t*)(base + 0x3c) = uVar1 + 1;
                *param_1 = *(uint8_t*)(*(int*)(base + 0x34) + uVar1);
                return 1;
            }
        } else {
            int iVar2;
            if (*(int*)(base + 0x2c) == 0) {
                iVar2 = FUN_004f10f0_2(param_1, 1);
            } else {
                iVar2 = FUN_004fe190(param_1) ? 1 : 0;
            }
            if (iVar2 == 1) {
                return 1;
            }
            *param_1 = 0;
        }
    }
    return 0;
}

// 0x4f8a00 — observed shape: self in ECX, param_1 = &out wchar; mirror of 0x4f8980 for wide mode (+0x30 == 1); reads from +0x38 buffer with *2 stride.
uint32_t FUN_004f8a00(void* self, uint16_t* param_1)
{
    int base = (int)(intptr_t)self;
    *param_1 = 0;
    if (*(int*)(base + 0x30) == 1) {
        if (*(int*)(base + 0x20) == 1) {
            uint32_t uVar1 = *(uint32_t*)(base + 0x3c);
            if (uVar1 < *(uint32_t*)(*(int*)(base + 0x34) + -4)) {
                *(uint32_t*)(base + 0x3c) = uVar1 + 1;
                *param_1 = *(uint16_t*)(*(int*)(base + 0x38) + uVar1 * 2);
                return 1;
            }
        } else {
            int iVar2;
            if (*(int*)(base + 0x2c) == 0) {
                iVar2 = FUN_004f10f0_2(param_1, 2);
            } else {
                iVar2 = FUN_004fe190(param_1) ? 2 : 0;
            }
            if (iVar2 == 2) {
                return 1;
            }
            *param_1 = 0;
        }
    }
    return 0;
}

// 0x4f8a90 — observed shape: self (ESI), in_CL flag; wide-mode calls FUN_004f3b00 then decrements +0x3c via virtual +0x1c or counter decrement.
void FUN_004f8a90(void* self, char in_CL)
{
    uint32_t* s = (uint32_t*)self;
    if (s[0xc] == 1) {
        uint16_t* local_4 = (uint16_t*)DAT_008cacd0;
        FUN_004f3b00(&local_4);
        uint16_t* psVar1 = local_4;
        if ((*local_4 != 0) && (s[0xc] == 1)) {
            if (s[8] == 1) {
                if (s[0xf] != 0) {
                    s[0xf] = s[0xf] + -1;
                }
            } else {
                (**(void(**)(uint32_t, uint32_t))(*(uint32_t**)self + 0x1c))(0xffffffff, 1);
            }
        }
        psVar1 = psVar1 + -4;
        if ((psVar1 != 0) && (psVar1 != (uint16_t*)DAT_008cacc8)) {
            operator_delete__(psVar1);
        }
    } else if ((in_CL != '\0') && (s[0xc] == 0)) {
        if (s[8] == 1) {
            if (s[0xf] != 0) {
                s[0xf] = s[0xf] + -1;
                return;
            }
        } else {
            (**(void(**)(uint32_t, uint32_t))(*(uint32_t**)self + 0x1c))(0xffffffff, 1);
        }
    }
}

// 0x4f8bd0 — observed shape: guards on DAT_008cacf0 / DAT_008cace8/e c; early 0 return when flags clear, else FUN_004f8e40(&param_2).
uint32_t FUN_004f8bd0(void* self, uint32_t param_1, uint8_t param_2)
{
    int selfAddr = (int)(intptr_t)self;
    if ((DAT_008cacf0 == 0) || ((selfAddr != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
        return 0;
    }
    uint32_t uVar1 = (uint32_t)FUN_004f8e40(&param_2);
    return uVar1;
}

// 0x4f8c10 — observed shape: 64-bit shift helper; masks DAT_008cace8/ec with __allshl result and ORs back.
void FUN_004f8c10()
{
    extern uint64_t __allshl();
    uint64_t uVar3 = (uint64_t)__allshl();
    uint32_t uVar1 = (uint32_t)(~((uint32_t)uVar3) & DAT_008cace8);
    uint32_t uVar2 = (uint32_t)(~((uint32_t)(uVar3 >> 32)) & DAT_008cacec);
    uVar3 = (uint64_t)__allshl();
    DAT_008cacec = uVar2 | (uint32_t)(uVar3 >> 32);
    DAT_008cace8 = uVar1 | (uint32_t)uVar3;
}

// 0x4f8c70 — observed shape: two ECX/EAX strings compared case-insensitively (toupper); returns 1 if first ends at ' ' or NUL.
uint32_t FUN_004f8c70(const char* str1, const char* str2)
{
    const char* cur1 = str1;
    const char* cur2 = str2;
    uint8_t bVar2 = (uint8_t)*cur1;
    while (bVar2 != 0) {
        int iVar3;
        if (((char)bVar2 < -0x80) || (0xff < (char)bVar2)) {
            iVar3 = 0;
        } else {
            iVar3 = toupper(bVar2);
        }
        bVar2 = (uint8_t)*cur2;
        int iVar4;
        if (((char)bVar2 < -0x80) || (0xff < (char)bVar2)) {
            iVar4 = 0;
        } else {
            iVar4 = toupper(bVar2);
        }
        if (iVar3 != iVar4) break;
        const char* pbVar1 = cur1 + 1;
        cur1 = cur1 + 1;
        cur2 = cur2 + 1;
        bVar2 = (uint8_t)*pbVar1;
    }
    if ((*cur1 == 0x20) || (*cur1 == 0)) {
        return 1;
    }
    return 0;
}

// 0x4f8cf0 — observed shape: non-contiguous global parser; scans in_EAX for "/R<0-3>" tokens; manipulates DAT_008cace8/ec 64-bit state via __allmul / 0x55555555; sets DAT_008cacf0.
void FUN_004f8cf0(const char* input)
{
    extern uint64_t __allmul(int64_t a, int64_t b, uint32_t c, uint32_t d);
    uint64_t uVar5 = ((uint64_t)DAT_008cacec << 32) | DAT_008cace8;
    if (*input != '\0') {
        uint32_t uVar3 = DAT_007264dc;
        const char* cur = input;
        do {
            DAT_008cacec = (uint32_t)(uVar5 >> 32);
            DAT_008cace8 = (uint32_t)uVar5;
            const char* pcVar4 = cur + 1;
            if ((*cur == '/') && (*pcVar4 == 'R')) {
                pcVar4 = cur + 2;
                uint32_t uVar2 = (uint32_t)(cur[2] - 0x30);
                if (uVar2 < 4) {
                    char cVar1 = cur[3];
                    pcVar4 = cur + 3;
                    DAT_008cacf0 = 1;
                    if ((cVar1 == ' ') || (cVar1 == '\0')) {
                        if ((int)uVar2 < 0) {
                            uVar2 = 0;
                        } else if (3 < (int)uVar2) {
                            uVar2 = 3;
                        }
                        uVar5 = __allmul((int)uVar2, (int)uVar2 >> 31, 0x55555555, 0x55555555);
                    } else {
                        pcVar4 = cur + 4;
                        if ((cVar1 == ':') && (uVar2 = 0, uVar3 != 0)) {
                            do {
                                DAT_008cacec = (uint32_t)(uVar5 >> 32);
                                DAT_008cace8 = (uint32_t)uVar5;
                                char c = (char)FUN_004f8c70(cur, pcVar4);
                                if (c != '\0') {
                                    FUN_004f8c10();
                                }
                                uVar5 = ((uint64_t)DAT_008cacec << 32) | DAT_008cace8;
                                uVar2 = uVar2 + 1;
                                uVar3 = DAT_007264dc;
                            } while (uVar2 < DAT_007264dc);
                        }
                    }
                }
            }
            cur = pcVar4;
        } while (*pcVar4 != '\0');
    }
    DAT_008cacec = (uint32_t)(uVar5 >> 32);
    DAT_008cace8 = (uint32_t)uVar5;
}
