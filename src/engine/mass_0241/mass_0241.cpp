// Reconstruction batch mass_0241 - Sid Meier's Pirates! (2004) PE32 i386
// Addresses: 0x5e4af0..0x5e5c00 (20 functions)
// Source: Ghidra 12.2 pseudocode, one file per function.
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern int _strcmpi(const char *a, const char *b);
extern int _stricmp(const char *a, const char *b);
extern void* FUN_00533c78(uint32_t size);
extern int* FUN_006b3c00(void);
extern void FUN_006b3da0(uint32_t v);
extern void FUN_006b40a0(uint32_t v);
extern void FUN_006b3db0(uint32_t v);
extern int FUN_005edba0(void);
extern int FUN_005f7bb7(int v);
extern int FUN_005e5060(int* p1, int p2, uint32_t p3, uint32_t p4);
extern void FUN_005e5330(int* p1, int p2, uint32_t p3, int p4);
extern int FUN_005e5540(int* p1, uint32_t p2);
extern uint32_t* FUN_005e5860(int* p1, uint32_t p2);
extern void FUN_005e4af0(int* p1, int p2, uint32_t p3, int p4);
extern void FUN_005e4bb0(int* p1, int p2, uint32_t p3, int p4);
extern void FUN_005e4d40(int* p1, int p2, uint32_t p3, int p4);
extern void FUN_005e4e60(int* p1, int p2, uint32_t p3, int p4);
extern void FUN_005e4f30(int* p1, int p2, uint32_t p3, int p4);
extern int FUN_005e7ab0(void);
extern int FUN_005e7a90(void);
extern int FUN_005e7ad0(void);
extern int FUN_005e7b10(void);
extern int FUN_005e7b40(void);
extern int FUN_005e7b80(void);
extern uint32_t* FUN_005e7bd0(void);
extern int FUN_005e6300(void* name, bool isCubic);
extern void FUN_005e5a50(void* self);
extern int* FUN_005e5960(uint32_t p1, uint32_t p2);
extern int FUN_005e5b50(void* self, char* name);
extern int FUN_005e5bb0(void* self, int value);
extern void operator_delete(void* ptr);

extern void* ExceptionList;
extern char PTR_DAT_006c9838[];
extern char PTR_DAT_006c9834[];
extern char PTR_LAB_006c98ac[];
extern void* PTR_LAB_006c991c;
extern void* PTR_FUN_006c9928;
extern int DAT_007290b8;
extern void* LAB_006b97db;
extern void* LAB_006b97f8;
extern void* LAB_006b9823;

// 0x5e4af0 — observed shape: iterate entries, dispatch desc/description/hidden by strcmpi
void FUN_005e4af0_recon(int* param_1, int param_2, uint32_t param_3, int param_4)
{
    int* piVar1 = param_1;
    uint32_t uVar4 = 0;
    int iVar3;
    uint32_t uStack_2c;
    if (*(int*)(param_2 + 0x1c) != 0) {
        do {
            uint32_t uVar2 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*piVar1 + 0x48))(piVar1, param_3, uVar4);
            (**(void(**)(int*, uint32_t, int))(*piVar1 + 0x10))(piVar1, uVar2, (int)(uintptr_t)&uStack_2c + -0x38);
            iVar3 = _strcmpi((char*)&uStack_2c, "desc");
            if ((iVar3 == 0) || (iVar3 = _strcmpi((char*)&uStack_2c, "description"), iVar3 == 0)) {
                (**(void(**)(int*, uint32_t, int))(*piVar1 + 0xcc))(piVar1, uVar2, param_4 + 0xc);
            } else {
                iVar3 = _strcmpi((char*)&uStack_2c, "hidden");
                if (iVar3 == 0) {
                    (**(void(**)(int*, uint32_t, int*))(*piVar1 + 0x5c))(piVar1, uVar2, &param_1);
                    *(bool*)(param_4 + 0x58) = param_1 != (int*)0x0;
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint32_t*)(param_2 + 0x1c));
    }
}

// 0x5e4bb0 — observed shape: iterate entries, dispatch desc/hidden/color/rect-ish names
void FUN_005e4bb0_recon(int* param_1, int param_2, uint32_t param_3, int param_4)
{
    int* piVar1 = param_1;
    int iVar2 = param_4;
    uint32_t local_50 = 0;
    if (*(int*)(param_2 + 0x1c) != 0) {
        do {
            uint32_t uVar3 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*piVar1 + 0x48))(piVar1, param_3, local_50);
            uint32_t uStack_38;
            uint32_t uStack_34, uStack_30, uStack_3c, uStack_40, uStack_44, uStack_48, uStack_4c;
            (**(void(**)(int*, uint32_t, void*))(*piVar1 + 0x10))(piVar1, uVar3, &uStack_38);
            char* pcStack_2c = (char*)&uStack_38;
            int iVar4 = _strcmpi(pcStack_2c, "desc");
            if ((iVar4 == 0) || (iVar4 = _strcmpi(pcStack_2c, "description"), iVar4 == 0)) {
                (**(void(**)(int*, uint32_t, int))(*piVar1 + 0xcc))(piVar1, uVar3, iVar2 + 0xc);
            } else {
                iVar4 = _strcmpi(pcStack_2c, "hidden");
                if (iVar4 == 0) {
                    (**(void(**)(int*, uint32_t, int*))(*piVar1 + 0x5c))(piVar1, uVar3, &param_1);
                    *(bool*)(iVar2 + 0x44) = param_1 != (int*)0x0;
                } else {
                    iVar4 = _strcmpi(pcStack_2c, "color");
                    if (iVar4 == 0) {
                        (**(void(**)(int*, uint32_t, int*))(*piVar1 + 0x5c))(piVar1, uVar3, &param_1);
                        *(bool*)(iVar2 + 0x45) = param_1 != (int*)0x0;
                    } else {
                        iVar4 = _strcmpi(pcStack_2c, (char*)&PTR_DAT_006c9838);
                        if (iVar4 == 0) {
                            uStack_44 = *(uint32_t*)(iVar2 + 0x38);
                            uStack_4c = *(uint32_t*)(iVar2 + 0x30);
                            uStack_48 = *(uint32_t*)(iVar2 + 0x34);
                            uStack_40 = *(uint32_t*)(iVar2 + 0x3c);
                            (**(void(**)(int*, uint32_t, void*))(*piVar1 + 0x8c))(piVar1, uVar3, &uStack_4c);
                        } else {
                            iVar4 = _strcmpi(pcStack_2c, (char*)&PTR_DAT_006c9834);
                            if (iVar4 == 0) {
                                uStack_34 = *(uint32_t*)(iVar2 + 0x28);
                                uStack_3c = *(uint32_t*)(iVar2 + 0x20);
                                uStack_38 = *(uint32_t*)(iVar2 + 0x24);
                                uStack_30 = *(uint32_t*)(iVar2 + 0x2c);
                                (**(void(**)(int*, uint32_t, void*))(*piVar1 + 0x8c))(piVar1, uVar3, &uStack_3c);
                            }
                        }
                    }
                }
            }
            local_50 = local_50 + 1;
        } while (local_50 < *(uint32_t*)(param_2 + 0x1c));
    }
}

// 0x5e4d40 — observed shape: iterate entries, hidden + two rect names via vtable+0x7c
void FUN_005e4d40_recon(int* param_1, int param_2, uint32_t param_3, int param_4)
{
    int* piVar1 = param_1;
    int iVar2 = param_4;
    uint32_t local_30 = 0;
    if (*(int*)(param_2 + 0x1c) != 0) {
        do {
            uint32_t uVar3 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*piVar1 + 0x48))(piVar1, param_3, local_30);
            int pad;
            (**(void(**)(int*, uint32_t, int))(*piVar1 + 0x10))(piVar1, uVar3, (int)(uintptr_t)&pad + -0x38);
            char* pcStack_2c = (char*)&pad;
            int iVar4 = _strcmpi(pcStack_2c, "desc");
            if ((iVar4 == 0) || (iVar4 = _strcmpi(pcStack_2c, "description"), iVar4 == 0)) {
                (**(void(**)(int*, uint32_t, int))(*piVar1 + 0xcc))(piVar1, uVar3, iVar2 + 0xc);
            } else {
                iVar4 = _strcmpi(pcStack_2c, "hidden");
                if (iVar4 == 0) {
                    (**(void(**)(int*, uint32_t, int*))(*piVar1 + 0x5c))(piVar1, uVar3, &param_1);
                    *(bool*)(iVar2 + 0x1c) = param_1 != (int*)0x0;
                } else {
                    iVar4 = _strcmpi(pcStack_2c, (char*)&PTR_DAT_006c9838);
                    if (iVar4 == 0) {
                        (**(void(**)(int*, uint32_t, int))(*piVar1 + 0x7c))(piVar1, uVar3, iVar2 + 0x18);
                    } else {
                        iVar4 = _strcmpi(pcStack_2c, (char*)&PTR_DAT_006c9834);
                        if (iVar4 == 0) {
                            (**(void(**)(int*, uint32_t, int))(*piVar1 + 0x7c))(piVar1, uVar3, iVar2 + 0x14);
                        }
                    }
                }
            }
            local_30 = local_30 + 1;
        } while (local_30 < *(uint32_t*)(param_2 + 0x1c));
    }
}

// 0x5e4e60 — observed shape: iterate entries, desc + hidden flag via local_30
void FUN_005e4e60_recon(int* param_1, int param_2, uint32_t param_3, int param_4)
{
    uint32_t uVar3 = 0;
    uint32_t local_30 = 0;
    if (*(int*)(param_2 + 0x1c) != 0) {
        do {
            uint32_t uVar1 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*param_1 + 0x48))(param_1, param_3, uVar3);
            int pad;
            (**(void(**)(int*, uint32_t, int))(*param_1 + 0x10))(param_1, uVar1, (int)(uintptr_t)&pad + -0x38);
            char* pcStack_2c = (char*)&pad;
            int iVar2 = _strcmpi(pcStack_2c, "desc");
            if ((iVar2 == 0) || (iVar2 = _strcmpi(pcStack_2c, "description"), iVar2 == 0)) {
                (**(void(**)(int*, uint32_t, int))(*param_1 + 0xcc))(param_1, uVar1, param_4 + 0xc);
            } else {
                iVar2 = _strcmpi(pcStack_2c, "hidden");
                if (iVar2 == 0) {
                    (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x5c))(param_1, uVar1, &local_30);
                    *(bool*)(param_4 + 0x11) = local_30 != 0;
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)(param_2 + 0x1c));
    }
}

// 0x5e4f30 — observed shape: iterate entries, desc/hidden + two int fields via vtable+0x6c
void FUN_005e4f30_recon(int* param_1, int param_2, uint32_t param_3, int param_4)
{
    int* piVar1 = param_1;
    int iVar2 = param_4;
    uint32_t local_34 = 0;
    uint32_t local_30 = 0;
    if (*(int*)(param_2 + 0x1c) != 0) {
        do {
            uint32_t uVar3 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*piVar1 + 0x48))(piVar1, param_3, local_30);
            int pad;
            (**(void(**)(int*, uint32_t, int))(*piVar1 + 0x10))(piVar1, uVar3, (int)(uintptr_t)&pad + -0x38);
            char* pcStack_2c = (char*)&pad;
            int iVar4 = _strcmpi(pcStack_2c, "desc");
            if ((iVar4 == 0) || (iVar4 = _strcmpi(pcStack_2c, "description"), iVar4 == 0)) {
                (**(void(**)(int*, uint32_t, int))(*piVar1 + 0xcc))(piVar1, uVar3, iVar2 + 0xc);
            } else {
                iVar4 = _strcmpi(pcStack_2c, "hidden");
                if (iVar4 == 0) {
                    (**(void(**)(int*, uint32_t, int*))(*piVar1 + 0x5c))(piVar1, uVar3, &param_1);
                    *(bool*)(iVar2 + 0x1c) = param_1 != (int*)0x0;
                } else {
                    iVar4 = _strcmpi(pcStack_2c, (char*)&PTR_DAT_006c9838);
                    if (iVar4 == 0) {
                        (**(void(**)(int*, uint32_t, void*))(*piVar1 + 0x6c))(piVar1, uVar3, &local_34);
                        *(uint32_t*)(iVar2 + 0x18) = local_34;
                    } else {
                        iVar4 = _strcmpi(pcStack_2c, (char*)&PTR_DAT_006c9834);
                        if (iVar4 == 0) {
                            (**(void(**)(int*, uint32_t, void*))(*piVar1 + 0x6c))(piVar1, uVar3, &local_34);
                            *(uint32_t*)(iVar2 + 0x14) = local_34;
                        }
                    }
                }
            }
            local_30 = local_30 + 1;
        } while (local_30 < *(uint32_t*)(param_2 + 0x1c));
    }
}
// 0x5e5060 — observed shape: init fields -1, iterate props (desc/hidden/name/function/target/width/height/depth/type/NTM/NTMIndex), type->kind 1/2/3, file check via CreateFileA
void FUN_005e5060_recon(int* param_1, int param_2, uint32_t param_3, uint32_t param_4)
{
    int iVar1 = (int)param_4;
    *(uint32_t*)(param_4 + 0x2c) = 0xffffffff;
    *(uint32_t*)(param_4 + 0x30) = 0xffffffff;
    *(uint32_t*)(param_4 + 0x34) = 0xffffffff;
    *(uint32_t*)(param_4 + 0x3c) = 0xffffffff;
    uint32_t local_38 = 0;
    int local_30 = 0;
    char* local_34 = (char*)0x0;
    char** ppcVar4 = nullptr;
    uint32_t idx = 0;
    if (*(int*)(param_2 + 0x1c) != 0) {
        do {
            uint32_t uVar2 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*param_1 + 0x48))(param_1, param_3, idx);
            (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x10))(param_1, uVar2, &local_38);
            char* pcStack_2c = (char*)&local_38;
            int iVar3 = _strcmpi(pcStack_2c, "desc");
            if ((iVar3 == 0) || (iVar3 = _strcmpi(pcStack_2c, "description"), iVar3 == 0)) {
                ppcVar4 = (char**)(iVar1 + 0xc);
                goto LAB_005e524a;
            }
            iVar3 = _strcmpi(pcStack_2c, "hidden");
            if (iVar3 == 0) {
                (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x5c))(param_1, uVar2, &local_30);
                *(bool*)(iVar1 + 0x14) = local_30 != 0;
                goto LAB_005e5255;
            }
            iVar3 = _strcmpi(pcStack_2c, "name");
            if (iVar3 == 0) {
                ppcVar4 = (char**)(iVar1 + 0x1c);
            LAB_005e524a:
                (**(void(**)(int*, uint32_t, void*))(*param_1 + 0xcc))(param_1, uVar2, ppcVar4);
            } else {
                iVar3 = _strcmpi(pcStack_2c, "function");
                if (iVar3 == 0) {
                    ppcVar4 = (char**)(iVar1 + 0x20);
                    goto LAB_005e524a;
                }
                iVar3 = _strcmpi(pcStack_2c, "target");
                if (iVar3 == 0) {
                    ppcVar4 = (char**)(iVar1 + 0x24);
                    goto LAB_005e524a;
                }
                iVar3 = _strcmpi(pcStack_2c, "width");
                if (iVar3 == 0) {
                    (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x6c))(param_1, uVar2, &local_38);
                    *(uint32_t*)(iVar1 + 0x2c) = local_38;
                } else {
                    iVar3 = _strcmpi(pcStack_2c, "height");
                    if (iVar3 == 0) {
                        (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x6c))(param_1, uVar2, &local_38);
                        *(uint32_t*)(iVar1 + 0x30) = local_38;
                    } else {
                        iVar3 = _strcmpi(pcStack_2c, "depth");
                        if (iVar3 != 0) {
                            iVar3 = _strcmpi(pcStack_2c, "type");
                            if (iVar3 == 0) {
                                ppcVar4 = &local_34;
                            } else {
                                iVar3 = _strcmpi(pcStack_2c, "NTM");
                                if (iVar3 != 0) {
                                    iVar3 = _strcmpi(pcStack_2c, "NTMIndex");
                                    if (iVar3 == 0) {
                                        (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x6c))(param_1, uVar2, &local_38);
                                        *(uint32_t*)(iVar1 + 0x3c) = local_38;
                                    }
                                    goto LAB_005e5255;
                                }
                                ppcVar4 = (char**)(iVar1 + 0x38);
                            }
                            goto LAB_005e524a;
                        }
                        (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x6c))(param_1, uVar2, &local_38);
                        *(uint32_t*)(iVar1 + 0x34) = local_38;
                    }
                }
            }
        LAB_005e5255:
            idx = idx + 1;
        } while (idx < *(uint32_t*)(param_2 + 0x1c));
        if (local_34 != (char*)0x0) {
            int iVar3 = _strcmpi(local_34, "volume");
            if (iVar3 == 0) {
                *(uint32_t*)(iVar1 + 0x18) = 2;
            } else {
                iVar3 = _strcmpi(local_34, "cube");
                if (iVar3 == 0) {
                    *(uint32_t*)(iVar1 + 0x18) = 3;
                }
            }
            goto LAB_005e52b0;
        }
    }
    *(uint32_t*)(iVar1 + 0x18) = 1;
LAB_005e52b0:
    if (*(LPCSTR*)(iVar1 + 0x1c) != (LPCSTR)0x0) {
        HANDLE hObject = CreateFileA(*(LPCSTR*)(iVar1 + 0x1c), 0x80000000, 1, (LPSECURITY_ATTRIBUTES)0x0, 3, 0, (HANDLE)0x0);
        if (hObject == (HANDLE)0xffffffff) {
            *(uint32_t*)(iVar1 + 0x1c) = 0;
        } else {
            CloseHandle(hObject);
        }
    }
    if ((*(int*)(iVar1 + 0x1c) == 0) && (*(int*)(iVar1 + 0x20) == 0)) {
        if (*(int*)(iVar1 + 0x38) == 0) {
            *(char**)(iVar1 + 0x38) = (char*)"shader";
        }
        int iVar3 = 7;
        bool bVar7 = true;
        char* pcVar5 = *(char**)(iVar1 + 0x38);
        const char* pcVar6 = "shader";
        do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar5 == *pcVar6;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if ((bVar7) && (*(int*)(iVar1 + 0x3c) == -1)) {
            *(int*)(iVar1 + 0x3c) = DAT_007290b8;
            DAT_007290b8 = DAT_007290b8 + 1;
        }
    }
}

// 0x5e5330 — observed shape: iterate props (desc/shadername/implementation/userversion/nbtmethod/usesnir/usestnic), nbt->0x1000/0x2000/0x3000
void FUN_005e5330_recon(int* param_1, int param_2, uint32_t param_3, int param_4)
{
    int iVar1 = param_4;
    int local_38 = 0;
    char* local_34 = (char*)0x0;
    uint32_t local_30 = 0;
    if (*(int*)(param_2 + 8) != 0) {
        do {
            uint32_t uVar2 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*param_1 + 0x48))(param_1, param_3, local_30);
            (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x10))(param_1, uVar2, &local_38);
            char* pcStack_2c = (char*)&local_38;
            int iVar3 = _strcmpi(pcStack_2c, "desc");
            if ((iVar3 == 0) || (iVar3 = _strcmpi(pcStack_2c, "description"), iVar3 == 0)) {
                iVar3 = iVar1 + 8;
            LAB_005e54a2:
                (**(void(**)(int*, uint32_t, int))(*param_1 + 0xcc))(param_1, uVar2, iVar3);
            } else {
                iVar3 = _strcmpi(pcStack_2c, "shadername");
                if (iVar3 == 0) {
                    iVar3 = iVar1 + 4;
                    goto LAB_005e54a2;
                }
                iVar3 = _strcmpi(pcStack_2c, "implementation");
                if (iVar3 == 0) {
                    (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x6c))(param_1, uVar2, &param_4);
                    *(int*)(iVar1 + 0xc) = param_4;
                } else {
                    iVar3 = _strcmpi(pcStack_2c, "userversion");
                    if (iVar3 == 0) {
                        (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x6c))(param_1, uVar2, &param_4);
                        *(int*)(iVar1 + 0x18) = param_4;
                    } else {
                        iVar3 = _strcmpi(pcStack_2c, "nbtmethod");
                        if (iVar3 == 0) {
                            (**(void(**)(int*, uint32_t, void*))(*param_1 + 0xcc))(param_1, uVar2, &local_34);
                        } else {
                            iVar3 = _strcmpi(pcStack_2c, "usesnirenderstate");
                            if (iVar3 == 0) {
                                (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x5c))(param_1, uVar2, &local_38);
                                *(bool*)(iVar1 + 0x24) = local_38 != 0;
                            } else {
                                iVar3 = _strcmpi(pcStack_2c, "usesnilightstate");
                                if (iVar3 == 0) {
                                    (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x5c))(param_1, uVar2, &local_38);
                                    *(bool*)(iVar1 + 0x25) = local_38 != 0;
                                }
                            }
                        }
                    }
                }
            }
            local_30 = local_30 + 1;
        } while (local_30 < *(uint32_t*)(param_2 + 8));
    }
    *(uint32_t*)(iVar1 + 0x20) = 0;
    if (local_34 != (char*)0x0) {
        int iVar3 = _strcmpi(local_34, "NDL");
        if (iVar3 == 0) {
            *(uint32_t*)(iVar1 + 0x20) = 0x1000;
            return;
        }
        iVar3 = _strcmpi(local_34, (char*)&PTR_LAB_006c98ac);
        if (iVar3 == 0) {
            *(uint32_t*)(iVar1 + 0x20) = 0x2000;
            return;
        }
        iVar3 = _strcmpi(local_34, "ATI");
        if (iVar3 == 0) {
            *(uint32_t*)(iVar1 + 0x20) = 0x3000;
        }
    }
}
// 0x5e5540 — observed shape: ATTRIBUTE/GLOBAL name scan with manual char loops, schema dispatch by uStack_30/iStack_24/local_2c, factories FUN_005e7a90..FUN_005e7b80
int FUN_005e5540_recon(int* param_1, uint32_t param_2)
{
    int iVar1;
    int iVar2 = 0;
    uint32_t unaff_EBX = 0;
    uint32_t unaff_ESI = 0;
    uint32_t uStack_34_ptr = 0;
    uint32_t uStack_30 = 0;
    int local_2c = 0;
    uint32_t uStack_28 = 0;
    int iStack_24 = 0;
    int iStack_20 = 0;
    uint32_t uStack_14 = 0;
    int iStack_4 = 0;
    char auStack_8[64] = {0};
    (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x10))(param_1, param_2, &local_2c);
    if (uStack_34_ptr == 0) goto LAB_005e57e1;
    {
        bool bVar5 = false;
        bool bVar6 = true;
        int iVar = 10;
        unsigned char* pbVar3 = (unsigned char*)(uintptr_t)uStack_34_ptr;
        unsigned char* pbVar4 = (unsigned char*)"ATTRIBUTE";
        do {
            if (iVar == 0) break;
            iVar = iVar + -1;
            bVar5 = *pbVar3 < *pbVar4;
            bVar6 = *pbVar3 == *pbVar4;
            pbVar3 = pbVar3 + 1;
            pbVar4 = pbVar4 + 1;
        } while (bVar6);
        iStack_4 = 0;
        if (!bVar6) {
            iStack_4 = (1 - (uint32_t)bVar5) - (uint32_t)(bVar5 != 0);
        }
        auStack_8[0] = 1;
        iVar = 7;
        pbVar3 = (unsigned char*)(uintptr_t)uStack_34_ptr;
        pbVar4 = (unsigned char*)"GLOBAL";
        do {
            if (iVar == 0) break;
            iVar = iVar + -1;
            auStack_8[0] = (char)(*pbVar3 == *pbVar4);
            pbVar3 = pbVar3 + 1;
            pbVar4 = pbVar4 + 1;
        } while ((bool)auStack_8[0]);
    }
    if ((iStack_4 == 0) || ((bool)auStack_8[0] != false)) {
        if (uStack_30 == 1) {
            if (iStack_24 == 1) goto LAB_005e56a1;
            if (local_2c != 3) {
                return 0;
            }
            iVar2 = FUN_005e7ab0();
            *(int*)(iVar2 + 0x40) = iStack_24;
            FUN_005e4bb0(param_1, (int)(uintptr_t)auStack_8 + -0x30, param_2, iVar2);
            iVar1 = (**(int(**)(int*, uint32_t, uint32_t*))(*param_1 + 0x8c))(param_1, param_2, (uint32_t*)(uintptr_t)(iVar2 + 0x10));
            if (iVar1 < 0) {
                *(uint32_t*)(iVar2 + 0x10) = 0;
                *(uint32_t*)(iVar2 + 0x14) = 0;
                *(uint32_t*)(iVar2 + 0x18) = 0;
                *(uint32_t*)(iVar2 + 0x1c) = 0;
            }
        }
        else {
            if (((uStack_30 != 2) && (uStack_30 != 3)) || (iStack_20 != 1)) {
                if ((uStack_30 == 2) || (uStack_30 == 3)) {
                    if (local_2c != 3) {
                        return 0;
                    }
                    iVar2 = FUN_005e7a90();
                    *(uint32_t*)(iVar2 + 0x50) = uStack_28;
                    *(int*)(iVar2 + 0x54) = iStack_24;
                    FUN_005e4af0(param_1, (int)(uintptr_t)auStack_8 + -0x30, param_2, iVar2);
                    if (uStack_30 == 3) {
                        iVar1 = (**(int(**)())(*param_1 + 0x9c))();
                    } else {
                        iVar1 = (**(int(**)(int*, uint32_t, uint32_t*))(*param_1 + 0xb4))(param_1, param_2, (uint32_t*)(uintptr_t)(iVar2 + 0x10));
                    }
                    if (iVar1 < 0) {
                        *(uint32_t*)(iVar2 + 0x48) = 0;
                        *(uint32_t*)(iVar2 + 0x44) = 0;
                        *(uint32_t*)(iVar2 + 0x40) = 0;
                        *(uint32_t*)(iVar2 + 0x3c) = 0;
                        *(uint32_t*)(iVar2 + 0x34) = 0;
                        *(uint32_t*)(iVar2 + 0x30) = 0;
                        *(uint32_t*)(iVar2 + 0x2c) = 0;
                        *(uint32_t*)(iVar2 + 0x28) = 0;
                        *(uint32_t*)(iVar2 + 0x20) = 0;
                        *(uint32_t*)(iVar2 + 0x1c) = 0;
                        *(uint32_t*)(iVar2 + 0x18) = 0;
                        *(uint32_t*)(iVar2 + 0x14) = 0;
                        *(uint32_t*)(iVar2 + 0x4c) = 0x3f800000;
                        *(uint32_t*)(iVar2 + 0x38) = 0x3f800000;
                        *(uint32_t*)(iVar2 + 0x24) = 0x3f800000;
                        *(uint32_t*)(iVar2 + 0x10) = 0x3f800000;
                    }
                    goto LAB_005e57bf;
                }
                if (uStack_30 != 0) goto LAB_005e57e1;
            }
        LAB_005e56a1:
            if (local_2c == 3) {
                iVar2 = FUN_005e7ad0();
                FUN_005e4d40(param_1, (int)(uintptr_t)auStack_8 + -0x30, param_2, iVar2);
                iVar1 = (**(int(**)(int*, uint32_t, int*))(*param_1 + 0x7c))(param_1, param_2, &iStack_4);
                if (iVar1 < 0) {
                    *(uint32_t*)(iVar2 + 0x10) = 0;
                } else {
                    *(int*)(iVar2 + 0x10) = iStack_4;
                }
            } else if (local_2c == 1) {
                iVar2 = FUN_005e7b10();
                FUN_005e4e60(param_1, (int)(uintptr_t)auStack_8 + -0x30, param_2, iVar2);
                iVar1 = (**(int(**)(int*, uint32_t, void*))(*param_1 + 0x5c))(param_1, param_2, auStack_8 + -0x38);
                if (iVar1 < 0) {
                    *(uint8_t*)(iVar2 + 0x10) = 0;
                } else {
                    *(bool*)(iVar2 + 0x10) = unaff_ESI != 0;
                }
            } else {
                if (local_2c != 2) goto LAB_005e57e1;
                iVar2 = FUN_005e7b40();
                FUN_005e4f30(param_1, (int)(uintptr_t)auStack_8 + -0x30, param_2, iVar2);
                iVar1 = (**(int(**)(int*, uint32_t, void*))(*param_1 + 0x6c))(param_1, param_2, auStack_8 + -0x34);
                *(uint32_t*)(iVar2 + 0x10) = (iVar1 < 0) - 1 & uStack_30;
            }
        }
    LAB_005e57bf:
        if (iVar2 == 0) goto LAB_005e57e1;
        *(uint8_t*)(iVar2 + 4) = (uint8_t)auStack_8[0];
    } else {
        iVar2 = FUN_005e6300((void*)(uintptr_t)uStack_34_ptr, uStack_30 == 3);
    }
    if (iVar2 != 0) {
        *(uint32_t*)(iVar2 + 8) = unaff_EBX;
        return iVar2;
    }
LAB_005e57e1:
    if (((local_2c != 5) && (local_2c != 7)) && ((local_2c != 8 && (local_2c != 9)))) {
        return 0;
    }
    iVar2 = FUN_005e7b80();
    *(uint32_t*)(iVar2 + 8) = unaff_EBX;
    FUN_005e5060(param_1, (int)(uintptr_t)auStack_8 + -0x30, param_2, iVar2);
    iVar1 = (**(int(**)(int*, uint32_t, void*))(*param_1 + 0xd4))(param_1, param_2, auStack_8);
    if (iVar1 < 0) {
        *(uint32_t*)(iVar2 + 0x10) = 0;
        return iVar2;
    }
    *(uint32_t*)(iVar2 + 0x10) = uStack_14;
    return iVar2;
}

// 0x5e5860 — observed shape: alloc via FUN_005e7bd0, optional FUN_005e5330, loop children computing max of puVar1[4]/[5]
uint32_t* FUN_005e5860_recon(int* param_1, uint32_t param_2)
{
    uint32_t unaff_EBP = 0;
    uint32_t unaff_ESI = 1;
    uint32_t unaff_EDI = 0;
    uint32_t uStack_4 = 0;
    uint32_t uStack_8 = 0;
    int iStack_14 = 0;
    int iStack_10 = 0;
    char local_1c[32] = {0};
    (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x14))(param_1, param_2, local_1c);
    uint32_t* puVar1 = FUN_005e7bd0();
    *puVar1 = unaff_EDI;
    if (unaff_EBP != 0) {
        FUN_005e5330(param_1, (int)(uintptr_t)local_1c + -0xc, param_2, (int)(uintptr_t)puVar1);
    }
    uStack_8 = 0;
    if (unaff_ESI != 0) {
        while (true) {
            uint32_t uVar2 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*param_1 + 0x38))(param_1, param_2, uStack_8);
            (**(void(**)(int*, uint32_t, void*))(*param_1 + 0x18))(param_1, uVar2, local_1c + -0xc);
            uint32_t uVar4 = 0;
            uint32_t uVar3 = 0;
            if (iStack_14 != 0) {
                uVar4 = FUN_005f7bb7(iStack_14);
            }
            if (iStack_10 != 0) {
                uVar3 = FUN_005f7bb7(iStack_10);
            }
            if ((uint32_t)puVar1[5] < uVar4) {
                puVar1[5] = uVar4;
            }
            if ((uint32_t)puVar1[4] < uVar3) {
                puVar1[4] = uVar3;
            }
            uStack_8 = uStack_8 + 1;
            if (unaff_ESI <= uStack_8) break;
            param_2 = uStack_4;
        }
    }
    return puVar1;
}

// 0x5e5920 — observed shape: vtable+0x20 lookup then FUN_005e5540
void FUN_005e5920_recon(int* param_1, uint32_t param_2)
{
    uint32_t uVar1 = (**(uint32_t(**)(int*, uint32_t, uint32_t))(*param_1 + 0x20))(param_1, 0, param_2);
    FUN_005e5540(param_1, uVar1);
}

// 0x5e5940 — observed shape: vtable+0x30 lookup then FUN_005e5860
void FUN_005e5940_recon(int* param_1, uint32_t param_2)
{
    uint32_t uVar1 = (**(uint32_t(**)(int*, uint32_t))(*param_1 + 0x30))(param_1, param_2);
    FUN_005e5860(param_1, uVar1);
}

// 0x5e5960 — observed shape: SEH + alloc 0xdc, FUN_006b3c00 construct, vtable+0xc init, FUN_006b3da0/FUN_006b40a0
int* FUN_005e5960_recon(uint32_t param_1, uint32_t param_2)
{
    void* pvVar1 = FUN_00533c78(0xdc);
    int* piVar2;
    if (pvVar1 == (void*)0x0) {
        piVar2 = (int*)0x0;
    } else {
        piVar2 = (int*)FUN_006b3c00();
    }
    if (piVar2 == (int*)0x0) {
        return (int*)0x0;
    }
    (**(void(**)(int*, uint32_t))(*piVar2 + 0xc))(piVar2, param_1);
    FUN_006b3da0(param_1);
    FUN_006b40a0(param_2);
    return piVar2;
}
// 0x5e5a00 — observed shape: ECX receiver ctor, set vtable to PTR_LAB_006c991c
void FUN_005e5a00_recon(void* self)
{
    *(void**)self = &PTR_LAB_006c991c;
}

// 0x5e5a30 — observed shape: scalar-deleting dtor calls FUN_005e5a50 then conditional operator_delete
void FUN_005e5a30_recon(void* self, uint8_t param_1)
{
    FUN_005e5a50(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e5a50 — observed shape: SEH, store PTR_FUN_006c9928, call FUN_005edba0, restore PTR_LAB_006c991c
void FUN_005e5a50_recon(void* self)
{
    *(void**)self = &PTR_FUN_006c9928;
    FUN_005edba0();
    *(void**)self = &PTR_LAB_006c991c;
}

// 0x5e5aa0 — observed shape: linked-list teardown at in_ECX[2] chain, release nodes via vtable, double FUN_005edba0 with vtable swaps
void FUN_005e5aa0_recon(int* self)
{
    int iVar1 = self[2];
    *self = iVar1;
    while (iVar1 != 0) {
        int* piVar2 = (int*)*self;
        *self = *piVar2;
        uint32_t* puVar3 = (uint32_t*)piVar2[2];
        if (puVar3 != (uint32_t*)0x0) {
            (**(void(**)(uint32_t*))(*puVar3))(puVar3);
        }
        iVar1 = *self;
    }
    FUN_005edba0();
    self[1] = (int)(uintptr_t)&PTR_FUN_006c9928;
    FUN_005edba0();
    self[1] = (int)(uintptr_t)&PTR_LAB_006c991c;
}

// 0x5e5b30 — observed shape: ECX list pop-front, return node[2] value or 0
uint32_t FUN_005e5b30_recon(int* self)
{
    int* piVar1 = (int*)*self;
    if (piVar1 == (int*)0x0) {
        return 0;
    }
    *self = *piVar1;
    return (uint32_t)piVar1[2];
}

// 0x5e5b50 — observed shape: ECX list scan, return first node whose vtable+4 name matches (stricmp) or null
int* FUN_005e5b50_recon(int* self, char* param_1)
{
    int* piVar1 = (int*)self[2];
    *self = (int)(uintptr_t)piVar1;
    if (piVar1 != (int*)0x0) {
        *self = *piVar1;
        for (piVar1 = (int*)piVar1[2]; piVar1 != (int*)0x0; piVar1 = (int*)piVar1[2]) {
            char* _Str2 = param_1;
            char* _Str1 = (char*)(**(char*(**)(int*))(*piVar1 + 4))(piVar1);
            int iVar2 = _stricmp(_Str1, _Str2);
            if (iVar2 == 0) {
                return piVar1;
            }
            piVar1 = (int*)*self;
            if (piVar1 == (int*)0x0) {
                return (int*)0x0;
            }
            *self = *piVar1;
        }
    }
    return (int*)0x0;
}

// 0x5e5bb0 — observed shape: append node to ECX list (factory via in_ECX+4 chain), increment count at +0x10, return 1
int FUN_005e5bb0_recon(void* self, int param_1)
{
    if (param_1 == 0) {
        return 0;
    }
    uint32_t* puVar1 = (uint32_t*)(**(uint32_t*(**)(void*))(*(int*)((char*)self + 4) + 4))(*(void**)((char*)self + 4));
    puVar1[2] = (uint32_t)param_1;
    *puVar1 = 0;
    puVar1[1] = *(uint32_t*)((char*)self + 0xc);
    if (*(uint32_t**)((char*)self + 0xc) == (uint32_t*)0x0) {
        *(uint32_t**)((char*)self + 8) = puVar1;
        *(uint32_t**)((char*)self + 0xc) = puVar1;
        *(int*)((char*)self + 0x10) = *(int*)((char*)self + 0x10) + 1;
        return 1;
    }
    **(uint32_t**)((char*)self + 0xc) = (uint32_t)(uintptr_t)puVar1;
    *(uint32_t**)((char*)self + 0xc) = puVar1;
    *(int*)((char*)self + 0x10) = *(int*)((char*)self + 0x10) + 1;
    return 1;
}

// 0x5e5c00 — observed shape: find-or-create via FUN_005e5b50 / FUN_005e5960, link via FUN_006b3db0 + FUN_005e5bb0
int FUN_005e5c00_recon(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    int iVar2 = FUN_005e5b50((int*)self, (char*)(uintptr_t)param_1);
    if (iVar2 == 0) {
        int* piVar3 = FUN_005e5960(param_1, 1);
        FUN_006b3db0(param_3);
        int cVar1 = FUN_005e5bb0(self, (int)(uintptr_t)piVar3);
        if (cVar1 != 0) {
            return 1;
        }
        if (piVar3 != (int*)0x0) {
            (**(void(**)(int*))(*piVar3))(piVar3);
        }
    }
    return 0;
}
