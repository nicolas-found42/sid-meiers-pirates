#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern int _stricmp(const char*, const char*);
extern void operator_delete(void*);
extern void operator_delete__(void*);

// 0x5df1a0 — observed shape: store param at +0x34; null param clears +0x30/+0x38; else save +0x60 holder, AddRef(0x4)/Release(0x8), cache field at +0x5cc
void FUN_005df1a0(void* self, int param_1)
{
    int** selfv = static_cast<int**>(self);
    *(int*)((char*)self + 0x34) = param_1;
    if (param_1 == 0) {
        int* piVar1 = *(int**)((char*)self + 0x30);
        if (piVar1 != nullptr) {
            (**(void(__stdcall**)(int*))((int*)*piVar1 + 2))(piVar1);
        }
        *(uint32_t*)((char*)self + 0x30) = 0;
        *(uint32_t*)((char*)self + 0x38) = 0;
        return;
    }
    int* piVar1 = *(int**)(param_1 + 0x60);
    int* piVar2 = *(int**)((char*)self + 0x30);
    if (piVar2 != nullptr) {
        (**(void(__stdcall**)(int*))((int*)*piVar2 + 2))(piVar2);
    }
    *(int**)((char*)self + 0x30) = piVar1;
    if (piVar1 != nullptr) {
        (**(void(__stdcall**)(int*))((int*)*piVar1 + 1))(piVar1);
    }
    *(uint32_t*)((char*)self + 0x38) = *(uint32_t*)(*(int*)((char*)self + 0x34) + 0x5cc);
}

// 0x5df640 — observed shape: linear stricmp scan over array at +0x10 count +0x18, returns matching element or 0
int FUN_005df640(void* self, char* param_1)
{
    uint32_t uVar1 = *(uint32_t*)((char*)self + 0x18);
    uint32_t uVar4 = 0;
    if (uVar1 != 0) {
        do {
            int iVar2 = *(int*)(*(int*)((char*)self + 0x10) + uVar4 * 4);
            if (iVar2 != 0) {
                int iVar3 = _stricmp(param_1, *(char**)(iVar2 + 8));
                if (iVar3 == 0) {
                    return iVar2;
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
    }
    return 0;
}

// 0x5df6a0 — observed shape: store param1 at +0x28, dispatch filtered array elements by flags at +0x10 to vtables +0x38..0x48
uint32_t FUN_005df6a0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
    uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9, uint32_t param_10)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    uint32_t iVar2 = param_1;
    in_ECX[10] = param_1;
    param_1 = 0;
    if (in_ECX[6] != 0) {
        do {
            int iVar1 = *(int*)(in_ECX[4] + param_1 * 4);
            if (iVar1 != 0 && (*(int*)(iVar1 + 0x18) != -1 || *(int*)(iVar1 + 0x20) != 0)) {
                uint32_t uVar3 = *(uint32_t*)(iVar1 + 0x10) & 0xf0000000;
                if (uVar3 == 0x20000000) {
                    (**(void(__stdcall**)(uint32_t,int,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t))(*in_ECX + 0x38))
                        (iVar2, iVar1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10);
                } else if (uVar3 == 0x10000000) {
                    (**(void(__stdcall**)(uint32_t,int,uint32_t))(*in_ECX + 0x3c))(iVar2, iVar1, param_10);
                } else if (uVar3 == 0x30000000) {
                    (**(void(__stdcall**)(uint32_t,int,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t))(*in_ECX + 0x40))
                        (iVar2, iVar1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10);
                } else if (uVar3 == 0x40000000) {
                    (**(void(__stdcall**)(uint32_t,int,uint32_t))(*in_ECX + 0x44))(iVar2, iVar1, param_10);
                } else {
                    if (uVar3 != 0x50000000) {
                        return 0x80000040;
                    }
                    (**(void(__stdcall**)(uint32_t,int,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t))(*in_ECX + 0x48))
                        (iVar2, iVar1, param_2, param_3, param_6, param_8, param_9, param_10);
                }
            }
            param_1 = param_1 + 1;
        } while (param_1 < in_ECX[6]);
    }
    return 0;
}

// 0x5df7e0 — observed shape: stricmp index scan over +0x10/+0x18, returns index or 0xffffffff
uint32_t FUN_005df7e0(void* self, char* param_1)
{
    uint32_t uVar1 = *(uint32_t*)((char*)self + 0x18);
    uint32_t uVar3 = 0;
    if (uVar1 != 0) {
        do {
            int iVar2 = *(int*)(*(int*)((char*)self + 0x10) + uVar3 * 4);
            if (iVar2 != 0 && (iVar2 = _stricmp(param_1, *(char**)(iVar2 + 8)), iVar2 == 0)) {
                return uVar3;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar1);
    }
    return 0xffffffff;
}

// 0x5df830 — observed shape: type-table lookup via 0x00729098 init flag and 0x00729060 array indexed by (field+0x10 & 0xff); true iff 0xb
extern uint8_t DAT_00729098;
extern int32_t DAT_00729060[];
extern void FUN_005e0120(void);
bool FUN_005df830(void* self)
{
    uint32_t uVar1 = *(uint32_t*)((char*)self + 0x10);
    if (DAT_00729098 == 0) {
        FUN_005e0120();
    }
    return *(int*)(&DAT_00729060 + (uVar1 & 0xff)) == 0xb;
}

extern uint32_t _DAT_00728ef0;
extern uint32_t _DAT_00728ef4;
extern uint32_t _DAT_00728ef8;
extern uint32_t _DAT_00728efc;
extern uint32_t _DAT_00728f00;
extern uint32_t _DAT_00728f04;
extern uint32_t _DAT_00728f08;
extern uint32_t _DAT_00728f0c;
extern uint32_t _DAT_00728f10;
extern uint32_t _DAT_00728f18;
extern uint32_t _DAT_00728f1c;
extern uint32_t _DAT_00728f20;
extern uint32_t _DAT_00728f24;
extern uint32_t _DAT_00728f28;
extern uint32_t _DAT_00728f2c;
extern uint32_t _DAT_00728f30;
extern uint32_t _DAT_00728f34;
extern uint32_t _DAT_00728f38;
extern uint32_t _DAT_00728f3c;
extern uint32_t _DAT_00728f40;
extern uint32_t _DAT_00728f44;
extern uint32_t DAT_00728ef0;
extern uint32_t DAT_00728ef4;
extern uint32_t DAT_00728f04;
extern uint32_t DAT_00728f18;
extern char FUN_005de940(void);
extern char FUN_005de970(void);
extern char FUN_005de9a0(void);
extern char FUN_005de9d0(void);
extern char FUN_005de180(void);
extern char FUN_005de1b0(void);
extern char FUN_005dea00(void);
extern char FUN_005de150(void);
extern char FUN_005de120(void);

// 0x5df860 — observed shape: dispatch on 0x00729060 type (1=byte, 2=null, 3=quad splat, else probe 005de940..005dea00 filling static buffers)
void* FUN_005df860(void* param_1, void* param_2)
{
    uint32_t uVar1 = *(uint32_t*)((char*)param_1 + 0x10);
    if (DAT_00729098 == 0) {
        FUN_005e0120();
    }
    if (*(int*)(&DAT_00729060 + (uVar1 & 0xff)) == 1) {
        _DAT_00728ef0 = (uint32_t)*(uint8_t*)((char*)param_2 + 0x10);
        return &DAT_00728ef0;
    }
    uVar1 = *(uint32_t*)((char*)param_1 + 0x10);
    if (DAT_00729098 == 0) {
        FUN_005e0120();
    }
    if (*(int*)(&DAT_00729060 + (uVar1 & 0xff)) != 2) {
        uVar1 = *(uint32_t*)((char*)param_1 + 0x10);
        if (DAT_00729098 == 0) {
            FUN_005e0120();
        }
        if (*(int*)(&DAT_00729060 + (uVar1 & 0xff)) == 3) {
            _DAT_00728ef4 = *(uint32_t*)((char*)param_2 + 0x10);
            _DAT_00728ef8 = _DAT_00728ef4;
            _DAT_00728efc = _DAT_00728ef4;
            _DAT_00728f00 = _DAT_00728ef4;
            return &DAT_00728ef4;
        }
        char cVar3 = FUN_005de940();
        if (cVar3 != 0) {
            _DAT_00728f04 = *(uint32_t*)((char*)param_2 + 0x10);
            _DAT_00728f08 = _DAT_00728f04;
            _DAT_00728f0c = _DAT_00728f04;
            _DAT_00728f10 = _DAT_00728f04;
            return &DAT_00728f04;
        }
        cVar3 = FUN_005de970();
        if (cVar3 != 0) {
            uint32_t* puVar2 = *(uint32_t**)((char*)param_2 + 0x14);
            _DAT_00728f04 = *puVar2;
            _DAT_00728f08 = puVar2[1];
            _DAT_00728f0c = *puVar2;
            _DAT_00728f10 = puVar2[1];
            return &DAT_00728f04;
        }
        cVar3 = FUN_005de9a0();
        if (cVar3 != 0) {
            uint32_t* puVar2 = *(uint32_t**)((char*)param_2 + 0x14);
            _DAT_00728f04 = *puVar2;
            _DAT_00728f08 = puVar2[1];
            _DAT_00728f0c = puVar2[2];
            _DAT_00728f10 = 0x3f800000;
            return &DAT_00728f04;
        }
        cVar3 = FUN_005de9d0();
        if (cVar3 != 0) {
            uint32_t* puVar2 = *(uint32_t**)((char*)param_2 + 0x14);
            _DAT_00728f04 = *puVar2;
            _DAT_00728f08 = puVar2[1];
            _DAT_00728f0c = puVar2[2];
            _DAT_00728f10 = puVar2[3];
            return &DAT_00728f04;
        }
        cVar3 = FUN_005de180();
        if (cVar3 != 0) {
            uint32_t* puVar2 = *(uint32_t**)((char*)param_2 + 0x14);
            _DAT_00728f18 = *puVar2;
            _DAT_00728f1c = puVar2[1];
            _DAT_00728f20 = puVar2[2];
            _DAT_00728f24 = 0;
            _DAT_00728f28 = puVar2[3];
            _DAT_00728f2c = puVar2[4];
            _DAT_00728f30 = puVar2[5];
            _DAT_00728f34 = 0;
            _DAT_00728f38 = puVar2[6];
            _DAT_00728f3c = puVar2[7];
            _DAT_00728f40 = puVar2[8];
            _DAT_00728f44 = 0;
            return &DAT_00728f18;
        }
        cVar3 = FUN_005de1b0();
        if (cVar3 != 0) {
            return *(void**)((char*)param_2 + 0x14);
        }
        cVar3 = FUN_005dea00();
        if (cVar3 != 0) {
            _DAT_00728f04 = *(uint32_t*)((char*)param_2 + 0x10);
            _DAT_00728f08 = *(uint32_t*)((char*)param_2 + 0x14);
            _DAT_00728f0c = *(uint32_t*)((char*)param_2 + 0x18);
            _DAT_00728f10 = *(uint32_t*)((char*)param_2 + 0x1c);
            return &DAT_00728f04;
        }
        FUN_005df830(param_1);
    }
    return nullptr;
}

// 0x5dfaf0 — observed shape: switch on field+0x24 / field+0x28 (1..16 cases) fills static vec4/vec16 buffers; case 1 falls through to 005de120/005de150 probes
void* FUN_005dfaf0(void* param_1)
{
    uint32_t* puVar1;
    char cVar2;
    switch (*(uint32_t*)((char*)param_1 + 0x24) / *(uint32_t*)((char*)param_1 + 0x28)) {
    case 1:
        break;
    case 2:
        cVar2 = FUN_005de150();
        puVar1 = *(uint32_t**)((char*)param_1 + 0x2c);
        if (cVar2 == 0) {
            _DAT_00728f04 = *puVar1;
            _DAT_00728f08 = puVar1[1];
            _DAT_00728f0c = *puVar1;
            _DAT_00728f10 = puVar1[1];
            return &DAT_00728f04;
        }
        _DAT_00728ef4 = *puVar1;
        _DAT_00728ef8 = puVar1[1];
        _DAT_00728efc = *puVar1;
        _DAT_00728f00 = puVar1[1];
        return &DAT_00728ef4;
    case 3:
        cVar2 = FUN_005de150();
        puVar1 = *(uint32_t**)((char*)param_1 + 0x2c);
        if (cVar2 == 0) {
            _DAT_00728f04 = *puVar1;
            _DAT_00728f08 = puVar1[1];
            _DAT_00728f0c = puVar1[2];
            _DAT_00728f10 = 0x3f800000;
            return &DAT_00728f04;
        }
        _DAT_00728ef4 = *puVar1;
        _DAT_00728ef8 = puVar1[1];
        _DAT_00728efc = puVar1[2];
        _DAT_00728f00 = 1;
        return &DAT_00728ef4;
    case 4:
        cVar2 = FUN_005de150();
        puVar1 = *(uint32_t**)((char*)param_1 + 0x2c);
        if (cVar2 == 0) {
            _DAT_00728f04 = *puVar1;
            _DAT_00728f08 = puVar1[1];
            _DAT_00728f0c = puVar1[2];
            _DAT_00728f10 = puVar1[3];
            return &DAT_00728f04;
        }
        _DAT_00728ef4 = *puVar1;
        _DAT_00728ef8 = puVar1[1];
        _DAT_00728efc = puVar1[2];
        _DAT_00728f00 = puVar1[3];
        return &DAT_00728ef4;
    default:
        return nullptr;
    case 8:
        puVar1 = *(uint32_t**)((char*)param_1 + 0x2c);
        _DAT_00728f18 = *puVar1;
        _DAT_00728f1c = puVar1[1];
        _DAT_00728f20 = puVar1[2];
        _DAT_00728f24 = puVar1[3];
        _DAT_00728f28 = puVar1[4];
        _DAT_00728f2c = puVar1[5];
        _DAT_00728f30 = puVar1[6];
        _DAT_00728f34 = puVar1[7];
        _DAT_00728f38 = 0;
        _DAT_00728f3c = 0;
        _DAT_00728f40 = 0;
        _DAT_00728f44 = 0;
        _DAT_00728f48 = 0;
        _DAT_00728f4c = 0;
        _DAT_00728f50 = 0;
        _DAT_00728f54 = 0;
        return &DAT_00728f18;
    case 9:
        puVar1 = *(uint32_t**)((char*)param_1 + 0x2c);
        _DAT_00728f18 = *puVar1;
        _DAT_00728f1c = puVar1[1];
        _DAT_00728f20 = puVar1[2];
        _DAT_00728f24 = 0;
        _DAT_00728f28 = puVar1[3];
        _DAT_00728f2c = puVar1[4];
        _DAT_00728f30 = puVar1[5];
        _DAT_00728f34 = 0;
        _DAT_00728f38 = puVar1[6];
        _DAT_00728f3c = puVar1[7];
        _DAT_00728f40 = puVar1[8];
        _DAT_00728f44 = 0;
        _DAT_00728f48 = 0;
        _DAT_00728f4c = 0;
        _DAT_00728f50 = 0;
        _DAT_00728f54 = 0;
        return &DAT_00728f18;
    case 0xc:
        puVar1 = *(uint32_t**)((char*)param_1 + 0x2c);
        _DAT_00728f18 = *puVar1;
        _DAT_00728f1c = puVar1[1];
        _DAT_00728f20 = puVar1[2];
        _DAT_00728f24 = puVar1[3];
        _DAT_00728f28 = puVar1[4];
        _DAT_00728f2c = puVar1[5];
        _DAT_00728f30 = puVar1[6];
        _DAT_00728f34 = puVar1[7];
        _DAT_00728f38 = puVar1[8];
        _DAT_00728f3c = puVar1[9];
        _DAT_00728f40 = puVar1[10];
        _DAT_00728f44 = puVar1[0xb];
        _DAT_00728f48 = 0;
        _DAT_00728f4c = 0;
        _DAT_00728f50 = 0;
        _DAT_00728f54 = 0;
        return &DAT_00728f18;
    case 0x10:
        puVar1 = *(uint32_t**)((char*)param_1 + 0x2c);
        _DAT_00728f18 = *puVar1;
        _DAT_00728f1c = puVar1[1];
        _DAT_00728f20 = puVar1[2];
        _DAT_00728f24 = puVar1[3];
        _DAT_00728f28 = puVar1[4];
        _DAT_00728f2c = puVar1[5];
        _DAT_00728f30 = puVar1[6];
        _DAT_00728f34 = puVar1[7];
        _DAT_00728f38 = puVar1[8];
        _DAT_00728f3c = puVar1[9];
        _DAT_00728f40 = puVar1[10];
        _DAT_00728f44 = puVar1[0xb];
        _DAT_00728f48 = puVar1[0xc];
        _DAT_00728f4c = puVar1[0xd];
        _DAT_00728f50 = puVar1[0xe];
        _DAT_00728f54 = puVar1[0xf];
        return &DAT_00728f18;
    }
    cVar2 = FUN_005de120();
    if (cVar2 != 0) {
        _DAT_00728ef0 = (uint32_t)**(uint8_t**)((char*)param_1 + 0x2c);
        return &DAT_00728ef0;
    }
    cVar2 = FUN_005de150();
    if (cVar2 == 0) {
        _DAT_00728f04 = **(uint32_t**)((char*)param_1 + 0x2c);
        _DAT_00728f08 = _DAT_00728f04;
        _DAT_00728f0c = _DAT_00728f04;
        _DAT_00728f10 = _DAT_00728f04;
        return &DAT_00728f04;
    }
    _DAT_00728ef4 = **(uint32_t**)((char*)param_1 + 0x2c);
    _DAT_00728ef8 = _DAT_00728ef4;
    _DAT_00728efc = _DAT_00728ef4;
    _DAT_00728f00 = _DAT_00728ef4;
    return &DAT_00728ef4;
}

// 0x5dff60 — observed shape: vptr swap, reverse refcount-decrement walk over allocation at +4 (count at -4), deletes backing store
extern void* PTR_FUN_006c93ac;
void FUN_005dff60(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    int* piVar1;
    uint32_t* puVar3;
    int iVar4;
    int iVar5;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c93ac;
    int iVar2 = static_cast<int>(in_ECX[1]);
    if (iVar2 != 0) {
        iVar4 = *(int*)(iVar2 + -4);
        iVar5 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 + -1) {
            do {
                puVar3 = *(uint32_t**)(iVar5 + -4);
                iVar5 = iVar5 + -4;
                if (puVar3 != nullptr) {
                    piVar1 = reinterpret_cast<int*>(puVar3 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (**(void(__stdcall**)(int))*puVar3)(1);
                    }
                }
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
        }
        operator_delete__((void*)(iVar2 + -4));
    }
}

// 0x5dffb0 — observed shape: scalar deleting destructor wrapping 0x5dff60; conditional operator_delete on flag bit 0
void FUN_005dffb0(void* self, uint8_t param_1)
{
    FUN_005dff60(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5dffd0 — observed shape: vptr swap, forward refcount walk with type-flag 0x40000000 hook to FUN_005be1e0, releases +0x30 holder, chains 0056f540/005dff60, decrements DAT_00727444
extern void* PTR_FUN_006c93b0;
extern void* PTR_LAB_006fd148;
extern int DAT_00727444;
extern void FUN_005be1e0(uint32_t);
extern void FUN_0056f540(void);
void FUN_005dffd0(void* self)
{
    uint32_t* puVar1;
    int* piVar2;
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    uint32_t uVar3 = 0;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c93b0;
    if (in_ECX[5] != 0) {
        do {
            puVar1 = *(uint32_t**)(in_ECX[4] + uVar3 * 4);
            if (puVar1 != nullptr) {
                puVar1[1] = puVar1[1] + 1;
                if ((puVar1[4] & 0xf0000000) == 0x40000000) {
                    FUN_005be1e0(puVar1[2]);
                }
                piVar2 = reinterpret_cast<int*>(puVar1 + 1);
                *piVar2 = *piVar2 + -1;
                if (*piVar2 == 0) {
                    (**(void(__stdcall**)(int))*puVar1)(1);
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < in_ECX[5]);
    }
    FUN_0056f540();
    piVar2 = reinterpret_cast<int*>(in_ECX[0xc]);
    in_ECX[0xd] = 0;
    if (piVar2 != nullptr) {
        (**(void(__stdcall**)(int*))((int*)*piVar2 + 2))(piVar2);
    }
    in_ECX[0xc] = 0;
    in_ECX[0xe] = 0;
    FUN_005dff60(self);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
}


extern int FUN_00581300(int, void*);

// 0x5e0070 — observed shape: vtable+0x2c lookup; on -1 store 0x80000010 at +0x2c..+0x30 region (index 0xb) and return it, else call FUN_00581300
int FUN_005e0070(void* self, uint32_t param_1)
{
    int* in_ECX = static_cast<int*>(self);
    int iVar1 = (**(int(__stdcall**)(uint32_t))*in_ECX + 0x2c))(param_1);
    if (iVar1 == -1) {
        in_ECX[0xb] = -0x7ffffff0;
        return in_ECX[0xb];
    }
    uint8_t uStack00000000 = 0;
    FUN_00581300(iVar1, &uStack00000000);
    return in_ECX[0xb];
}

// 0x5e00b0 — observed shape: scalar deleting destructor wrapping 0x5dffd0; conditional operator_delete on flag bit 0
void FUN_005e00b0(void* self, uint8_t param_1)
{
    FUN_005dffd0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e0120 — observed shape: one-time init filling DAT_00729060[0..13]=0..13, DAT_00729050[0..13]=0..13, set DAT_00729098=1
void FUN_005e0120(void)
{
    DAT_00729060[0] = 0;
    DAT_00729060[1] = 1;
    DAT_00729060[2] = 2;
    DAT_00729060[3] = 3;
    DAT_00729060[4] = 4;
    DAT_00729060[5] = 5;
    DAT_00729060[6] = 6;
    DAT_00729060[7] = 7;
    DAT_00729060[8] = 8;
    DAT_00729060[9] = 9;
    DAT_00729060[10] = 10;
    DAT_00729060[11] = 0xb;
    DAT_00729060[12] = 0xc;
    DAT_00729060[13] = 0xd;
    extern uint8_t DAT_00729050[];
    DAT_00729050[0] = 0;
    DAT_00729050[1] = 1;
    DAT_00729050[2] = 2;
    DAT_00729050[3] = 3;
    DAT_00729050[4] = 4;
    DAT_00729050[5] = 5;
    DAT_00729050[6] = 6;
    DAT_00729050[7] = 7;
    DAT_00729050[8] = 8;
    DAT_00729050[9] = 9;
    DAT_00729050[10] = 10;
    DAT_00729050[11] = 0xb;
    DAT_00729050[12] = 0xc;
    DAT_00729050[13] = 0xd;
    DAT_00729098 = 1;
}

extern int FUN_005e0920(uint32_t, uint32_t, uint32_t, uint32_t);

// 0x5e0220 — observed shape: forward 4-arg call to FUN_005e0920, store result to out-param, return bool(result != 0)
bool FUN_005e0220(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, int* param_5)
{
    int iVar1 = FUN_005e0920(param_1, param_2, param_3, param_4);
    *param_5 = iVar1;
    return iVar1 != 0;
}

// 0x5e0280 — observed shape: vptr swap to PTR_FUN_006c9408, call FUN_005e1490, operator_delete backing at +8
extern void* PTR_FUN_006c9408;
extern void FUN_005e1490(void);
void FUN_005e0280(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c9408;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
}

// 0x5e02c0 — observed shape: SEH-frame destructor: vptr PTR_FUN_006c9430 + 005e1490, then vptr PTR_FUN_006c9408 + 005e1490 + delete at +8
extern void* PTR_FUN_006c9430;
extern void* ExceptionList;
extern void* LAB_006b9338;
void FUN_005e02c0(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    void* local_c = ExceptionList;
    void* puStack_8 = &LAB_006b9338;
    (void)puStack_8;
    ExceptionList = &local_c;
    uint32_t local_4 = 0;
    (void)local_4;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c9430;
    FUN_005e1490();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c9408;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
    ExceptionList = local_c;
}

// 0x5e0330 — observed shape: SEH-frame destructor with linked-list element teardown at +8/+4 when flag at +16 set, then same two-phase 005e1490 + delete as 0x5e02c0
extern void* PTR_FUN_006c944c;
void FUN_005e0330(void* self)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    void* local_c = ExceptionList;
    void* puStack_8 = &LAB_006b9338;
    (void)puStack_8;
    ExceptionList = &local_c;
    uint32_t local_4 = 0xffffffff;
    (void)local_4;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c944c;
    if ((*(char*)((char*)self + 0x10) != 0) && (in_ECX[1] != 0)) {
        uint32_t uVar3 = 0;
        do {
            puVar2 = *(uint32_t**)(in_ECX[2] + uVar3 * 4);
            while (puVar2 != nullptr) {
                puVar1 = puVar2 + 1;
                puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
                operator_delete__((void*)(uintptr_t)*puVar1);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < in_ECX[1]);
    }
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c9430;
    FUN_005e1490();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c9408;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
    ExceptionList = local_c;
}

// 0x5e0400 — observed shape: vptr swap + 005e1490 + delete at +8, then scalar-delete if flag bit 0
void FUN_005e0400(void* self, uint8_t param_1)
{
    FUN_005e0280(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e0440 — observed shape: scalar deleting destructor wrapping 0x5e02c0; conditional operator_delete on flag bit 0
void FUN_005e0440(void* self, uint8_t param_1)
{
    FUN_005e02c0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e0460 — observed shape: scalar deleting destructor wrapping 0x5e0330; conditional operator_delete on flag bit 0
void FUN_005e0460(void* self, uint8_t param_1)
{
    FUN_005e0330(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
