#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers referenced by the observed listings.
extern void* FUN_004baaa0(void*);
extern void FUN_004db3d0(const char*, uint32_t, void*);
extern void FUN_00533e70(void*);
extern void FUN_004dbda0(void*);
extern void FUN_004db570(uint32_t, void*);
extern void FUN_00533d10(int,int);
extern void FUN_005516a0(void*);
extern int FUN_00551600(int);
extern void FUN_005451a0(uint32_t);
extern void FUN_0042e1d0(int);
extern void FUN_004890c0(void*);
extern void FUN_004dd890(void*);
extern void FUN_00486990(int,int);
extern void FUN_00485380(uint32_t,int,int);
extern char FUN_004afe00(void);
extern void* FUN_00533c78(size_t);
extern void* FUN_00503ca0(void);
extern void* FUN_00502460(void);
extern void FUN_005be280(const char*,int,void*);
extern void* FUN_004dd760(void*,void*,int);
extern void* FUN_004dd800(void*,void*,int);
extern void FUN_00503fb0(void*);
extern void FUN_00534130(void);
extern void FUN_00506040(uint32_t,uint32_t,int,int,uint32_t);
extern void FUN_004dd5d0(void);
extern void FUN_004404ca0(void);
extern void FUN_00487850(void);
extern void FUN_004867b0(void);
extern void FUN_00535920(void*);
extern void FUN_00503ef0(void);
extern void FUN_00508190(void);
extern void FUN_00488fc0(void*,int,uint32_t);
extern void FUN_00404ca0(void);
extern void FUN_00508120(void*);
extern void FUN_00508670(void*,void*);
extern void FUN_00514090(const char*,void*,int,int,int,uint32_t,uint32_t,int);
extern void FUN_00514430(uint32_t,uint32_t,int,uint32_t);
extern void FUN_00481100(void);
extern void FUN_00481180(void);
extern void FUN_004bb500(int);
extern void FUN_004beee0(void);
extern void FUN_004bcd00(int);
extern void FUN_004bcac0(void);
extern void FUN_004bca60(void);
extern void FUN_004bc740(int);
extern void FUN_0045a120(uint32_t);
extern void FUN_004bc7e0(uint32_t,uint32_t);
extern void FUN_004c2810(void*,int);
extern void FUN_00535670(void*);
extern int FUN_0042c6f0(void);
extern void FUN_004889c0(void*,int,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t);
extern void FUN_004f6090(const char*,...);
extern int FUN_00404910(uint32_t);
extern void FUN_004d0cd0(int,int,int);
extern int FUN_0042e440(void);
extern void FUN_004e01e0(void);
extern void FUN_004e0030(int);
extern void FUN_004e02a0(void);
extern void FUN_004dff80(void*);
extern void FUN_0042e730(void);
extern void FUN_004e00d0(void);
extern int FUN_004dcd70(void);
extern void operator_delete(void*);
extern void FUN_00506e60(void*,void*,float,float,float,uint32_t,int);
extern void FUN_00506c60(void*,void*,float,float,float,uint32_t);
extern void FUN_004888e0(int,uint32_t,uint32_t,uint32_t);
extern void FUN_00506040_2(void*,uint32_t,int,int,uint32_t);
extern void FUN_004e0700(void);
extern int FUN_004e0350(void);
extern char FUN_004e0880(void);
extern void FUN_004e0460(void*);
extern void FUN_004e0390(int);
extern void FUN_004874e0(int);
extern void FUN_004862a0(void);
extern void FUN_004af080(void*,int,int,int,void*,int,int,void*,int,uint32_t,int);
extern void FUN_004af030(int,int,int,int,void*,int,uint32_t,int);
extern void FUN_004cddf0(const char*,int,int,void*,void*);
extern void FUN_00509500(void*,void*,int);
extern int FUN_005f0ddc(...);
extern void FUN_004b06c0(void*,int,int,int,uint32_t,int,uint32_t,int);
extern void FUN_004bba60(void*,void*,float,uint32_t,float);
extern void FUN_004879f0(int,int);
extern void FUN_0042fee0(int,int);
extern void FUN_00405230(int,int,int,int);
extern void FUN_0045ba40(void);
extern void FUN_004f60b0(const char*,...);
extern void FUN_004bbb80(int,int,int,int,void*,int,int);
extern void FUN_004bbf50(void);
extern void FUN_004884a0(int,int);

// Extern globals referenced by the observed listings.
extern char* DAT_008ea08c;
extern void* DAT_008e9fd8;
extern char* DAT_0070f1ac;
extern int DAT_008be9c8;
extern int DAT_008be9c4;
extern int DAT_008be9c0;
extern int DAT_00869ab4;
extern int DAT_00861ff8;
extern int DAT_0086c35c;
extern int DAT_0086c360;
extern void* DAT_008c822c;
extern int DAT_008cabd4;
extern void* DAT_008cac40;
extern char DAT_00725d98;
extern void* DAT_008c8274;
extern int DAT_008c8494;
extern void* DAT_00727b28;
extern void* PTR_s_capt_kidd_30pt_fnt_007263c4;
extern void* DAT_008c9dd8;
extern void* DAT_00869b48;
extern int DAT_00869abc;
extern int DAT_008dc30c;
extern int DAT_008dc310;
extern int DAT_008ea008;
extern int DAT_008c97c4;
extern int DAT_008c97c0;
extern int DAT_008cac00;
extern char DAT_008cac27;
extern int DAT_008cab0c;
extern int DAT_0086c330;
extern int DAT_0086c010;
extern int DAT_0086bcf0;
extern int DAT_0086be80;
extern int DAT_0086bb60;
extern int DAT_0086c1a0;
extern int DAT_0085a268;
extern int DAT_0085a26c;
extern int DAT_0085a11c;
extern int DAT_008cac18;
extern int DAT_008c9de0;
extern void* DAT_007272f8;
extern void* DAT_007272e8;
extern int DAT_008c9df4;
extern int DAT_008c8278;
extern void* DAT_00726814;
extern int DAT_00726820;
extern int DAT_008142f8;
extern int DAT_00723b1c;
extern int DAT_00814324;
extern int DAT_0081431a;
extern int DAT_00814318;
extern void* DAT_008d74d8;
extern int DAT_00869aa4;
extern int DAT_00869a88;
extern int DAT_00869ac0;
extern int DAT_00869ac4;
extern int DAT_00869ac8;
extern int DAT_00869ab0;
extern int DAT_00869ab8;
extern int DAT_00869b34;
extern int DAT_00869acc;
extern int DAT_008ca4cc;
extern int DAT_008ca4c8;
extern int DAT_007263a0;
extern int DAT_008be9cf;
extern int DAT_008be9ce;
extern void* PTR_FUN_0070f0d0;
extern void* PTR_LAB_0070f0c4;
extern void* PTR_FUN_0070f1bc;
extern void* PTR_FUN_007116a0;
extern void* PTR_s_TRADE_BUTTON_TO_PLAYER_FOOD_007263d0;
extern void* PTR_s_button_leftArrow_kfm_00726430;
extern void* DAT_008ea09c;

// 0x4dc3f0 — observed shape
void FUN_004dc3f0(void* self) {
    // Ghidra: if (*(char *)(unaff_ESI + 0x24c) != '\0') { ... }
    if (*(char*)((uint8_t*)self + 0x24c) != 0) {
        int** piVar1 = *(int**)(DAT_008ea08c + 0xc);
        {
            uint32_t uVar5 = 0;
            uint32_t count = *(uint32_t*)((uint8_t*)self + 0x1f8);
            if (*(int*)((uint8_t*)self + 0x1f8) != 0) {
                do {
                    void* uVar2 = FUN_004baaa0(nullptr);
                    FUN_004db3d0("TownSneakZPass", 0xffffffffu, uVar2);
                    int* piVar3 = (int*)FUN_004baaa0(nullptr);
                    int iVar4 = (*(int(**)(int*, const char*))(*(int*)*piVar3 + 0x40))(piVar3, "window");
                    if (iVar4 != 0) {
                        *(uint16_t*)(iVar4 + 0x20) = (uint16_t)(*(uint16_t*)(iVar4 + 0x20) | 1);
                    }
                    piVar3 = (int*)FUN_004baaa0(nullptr);
                    iVar4 = (*(int(**)(int*, const char*))(*(int*)*piVar3 + 0x40))(piVar3, "Object02");
                    if (iVar4 != 0) {
                        *(uint16_t*)(iVar4 + 0x20) = (uint16_t)(*(uint16_t*)(iVar4 + 0x20) | 1);
                    }
                    piVar3 = (int*)FUN_004baaa0(nullptr);
                    iVar4 = (*(int(**)(int*, const char*))(*(int*)*piVar3 + 0x40))(piVar3, DAT_0070f1ac);
                    if (iVar4 != 0) {
                        *(uint16_t*)(iVar4 + 0x20) = (uint16_t)(*(uint16_t*)(iVar4 + 0x20) | 1);
                    }
                    void* ctx = DAT_008e9fd8;
                    FUN_004baaa0(DAT_008e9fd8);
                    FUN_00533e70(ctx);
                    uVar5 = uVar5 + 1;
                } while (uVar5 < count);
            }
        }
        (*(void(**)(int**))(*(int*)*piVar1 + 0x38))(piVar1);
        (*(void(**)(int**, void*))(*(int*)*piVar1 + 0x34))(piVar1, DAT_008e9fd8);
        {
            uint32_t uVar5 = 0;
            uint32_t count = *(uint32_t*)((uint8_t*)self + 0x210);
            if (*(int*)((uint8_t*)self + 0x210) != 0) {
                do {
                    void* uVar2 = FUN_004baaa0(nullptr);
                    FUN_004db3d0("TownSneakZPass", 0xffffffffu, uVar2);
                    void* ctx = DAT_008e9fd8;
                    FUN_004baaa0(DAT_008e9fd8);
                    FUN_00533e70(ctx);
                    uVar5 = uVar5 + 1;
                } while (uVar5 < count);
            }
        }
        (*(void(**)(int**))(*(int*)*piVar1 + 0x38))(piVar1);
        if (*(int*)((uint8_t*)self + 0x230) != 0) {
            (*(void(**)(int**, void*))(*(int*)*piVar1 + 0x34))(piVar1, DAT_008e9fd8);
            void* uVar2 = FUN_004baaa0(nullptr);
            FUN_004db3d0("TownSneakZPass", 0xffffffffu, uVar2);
            void* ctx = DAT_008e9fd8;
            FUN_004baaa0(DAT_008e9fd8);
            FUN_00533e70(ctx);
            (*(void(**)(int**))(*(int*)*piVar1 + 0x38))(piVar1);
            return;
        }
    }
    return;
}

// 0x4dc5a0 — observed shape
void FUN_004dc5a0(int param_1) {
    struct Node { int next; int prev; int count; int extra; };
    if (*(char*)(param_1 + 0x24c) != 0) {
        int** piVar1 = *(int**)(DAT_008ea08c + 0xc);
        if (*(int*)(param_1 + 0x234) != 0) {
            (*(void(**)(int**, void*))(*(int*)*piVar1 + 0x34))(piVar1, DAT_008e9fd8);
            void* uVar2 = DAT_008e9fd8;
            FUN_004baaa0(DAT_008e9fd8);
            FUN_00533e70(uVar2);
            (*(void(**)(int**))(*(int*)*piVar1 + 0x38))(piVar1);
        }
        (*(void(**)(int**, void*))(*(int*)*piVar1 + 0x34))(piVar1, DAT_008e9fd8);
        {
            uint32_t uVar6 = 0;
            uint32_t count = *(uint32_t*)(param_1 + 0x1e0);
            if (*(int*)(param_1 + 0x1e0) != 0) {
                do {
                    void* uVar2 = DAT_008e9fd8;
                    FUN_004baaa0(DAT_008e9fd8);
                    FUN_00533e70(uVar2);
                    uVar6 = uVar6 + 1;
                } while (uVar6 < count);
            }
        }
        (*(void(**)(int**))(*(int*)*piVar1 + 0x38))(piVar1);
        if (*(int*)(param_1 + 0x230) != 0) {
            (*(void(**)(int**, void*))(*(int*)*piVar1 + 0x34))(piVar1, DAT_008e9fd8);
            FUN_004dbda0();
            void* t = FUN_004baaa0(nullptr);
            void* r = FUN_004db570(0xffffffffu, t);
            FUN_004db3d0((const char*)r, 0, nullptr);
            void* uVar2 = DAT_008e9fd8;
            FUN_004baaa0(DAT_008e9fd8);
            FUN_00533e70(uVar2);
            (*(void(**)(int**))(*(int*)*piVar1 + 0x38))(piVar1);
        }
        {
            uint32_t uVar6 = 0;
            uint32_t count = *(uint32_t*)(param_1 + 0x1f8);
            if (*(int*)(param_1 + 0x1f8) != 0) {
                do {
                    (*(void(**)(int**, void*))(*(int*)*piVar1 + 0x34))(piVar1, DAT_008e9fd8);
                    int* piVar3 = (int*)FUN_004baaa0(nullptr);
                    piVar3 = (int*)(**(int(**)(int*, void*))(*(int*)*piVar3 + 0x40))(piVar3, DAT_0070f1ac);
                    if (piVar3 != nullptr) {
                        FUN_00533d10(0, 0);
                        (**(void(**)(int*, void*))(*(int*)*piVar3 + 0x60))(piVar3, DAT_008e9fd8);
                        (*(void(**)(int**))(*(int*)*piVar1 + 0x38))(piVar1);
                        (*(void(**)(int**, void*))(*(int*)*piVar1 + 0x34))(piVar1, DAT_008e9fd8);
                    }
                    uint32_t kind = (uint32_t)FUN_004dbda0();
                    FUN_004baaa0(nullptr);
                    const char* pcVar7 = nullptr;
                    switch (kind) {
                    case 0: case 1: pcVar7 = "TownSneakOneLight"; break;
                    case 2: pcVar7 = "TownSneakTwoLight"; break;
                    case 3: pcVar7 = "TownSneakThreeLight"; break;
                    case 4: pcVar7 = "TownSneakFourLight"; break;
                    case 5: pcVar7 = "TownSneakFiveLight"; break;
                    case 6: pcVar7 = "TownSneakSixLight"; break;
                    case 7: pcVar7 = "TownSneakSevenLight"; break;
                    default: pcVar7 = "TownSneakEightLight"; break;
                    }
                    void* t2 = FUN_004baaa0(nullptr);
                    FUN_004db3d0(pcVar7, 0xffffffffu, t2);
                    piVar3 = (int*)FUN_004baaa0(nullptr);
                    int iVar4 = (**(int(**)(int*, const char*))(*(int*)*piVar3 + 0x40))(piVar3, "window");
                    if (iVar4 != 0) *(uint8_t*)(iVar4 + 0x20) = (uint8_t)(*(uint8_t*)(iVar4 + 0x20) & 0xfe);
                    piVar3 = (int*)FUN_004baaa0(nullptr);
                    iVar4 = (**(int(**)(int*, const char*))(*(int*)*piVar3 + 0x40))(piVar3, "Object02");
                    if (iVar4 != 0) *(uint8_t*)(iVar4 + 0x20) = (uint8_t)(*(uint8_t*)(iVar4 + 0x20) & 0xfe);
                    void* uVar2b = DAT_008e9fd8;
                    FUN_004baaa0(DAT_008e9fd8);
                    FUN_00533e70(uVar2b);
                    (*(void(**)(int**))(*(int*)*piVar1 + 0x38))(piVar1);
                    uVar6 = uVar6 + 1;
                } while (uVar6 < count);
            }
        }
        {
            uint32_t uVar6 = 0;
            uint32_t count = *(uint32_t*)(param_1 + 0x210);
            int* unaff_EBP_alias = piVar1;
            int* unaff_EBX_alias = piVar1;
            if (*(int*)(param_1 + 0x210) != 0) {
                do {
                    (**(void(**)(int**, void*))(*(int*)*unaff_EBP_alias + 0x34))(unaff_EBP_alias, DAT_008e9fd8);
                    intptr_t kind = (intptr_t)FUN_004dbda0();
                    int iVar4 = *(int*)(*(int*)(param_1 + 0x204) + uVar6 * 4);
                    int iVar5 = *(int*)(iVar4 + 0x50);
                    while (iVar5 != 0) {
                        FUN_005516a0();
                        if (DAT_008ca4cc == 0 && ((int*)DAT_008ca4c8)[3] != 0) {
                            iVar5 = (int)FUN_00551600(0);
                            if (iVar5 == 0) {
                                int* list = (int*)DAT_008ca4c8;
                                int* piVar3 = (int*)list[1];
                                iVar5 = *piVar3;
                                list[1] = iVar5;
                                if (iVar5 == 0) list[2] = 0;
                                else *(int*)(iVar5 + 4) = 0;
                                iVar5 = piVar3[2];
                                (**(void(**)(int*, int*))(*(int*)*list + 8))(list, piVar3);
                                list[3] = list[3] - 1;
                                DAT_008ca4cc = iVar5;
                                FUN_005451a0(*(uint32_t*)(*(int*)(iVar5 + 8) + 8));
                            }
                        }
                        iVar5 = *(int*)(iVar4 + 0x50);
                    }
                    void* uVar2;
                    if ((*(int*)(iVar4 + 0xbc) == 0) || (1 < DAT_007263a0)) {
                        uVar2 = (void*)(intptr_t)*(int*)(iVar4 + 0x1c);
                    } else {
                        uVar2 = FUN_004baaa0(nullptr);
                    }
                    const char* pcVar7 = nullptr;
                    switch (kind) {
                    case 0: case 1: pcVar7 = "TownSneakOneLight"; break;
                    case 2: pcVar7 = "TownSneakTwoLight"; break;
                    case 3: pcVar7 = "TownSneakThreeLight"; break;
                    case 4: pcVar7 = "TownSneakFourLight"; break;
                    case 5: pcVar7 = "TownSneakFiveLight"; break;
                    case 6: pcVar7 = "TownSneakSixLight"; break;
                    case 7: pcVar7 = "TownSneakSevenLight"; break;
                    default: pcVar7 = "TownSneakEightLight"; break;
                    }
                    FUN_004db3d0(pcVar7, 0xffffffffu, uVar2);
                    iVar4 = *(int*)(*(int*)(param_1 + 0x204) + uVar6 * 4);
                    iVar5 = *(int*)(iVar4 + 0x50);
                    while (iVar5 != 0) {
                        FUN_005516a0();
                        if (DAT_008ca4cc == 0 && ((int*)DAT_008ca4c8)[3] != 0) {
                            iVar5 = (int)FUN_00551600(0);
                            if (iVar5 == 0) {
                                int* list = (int*)DAT_008ca4c8;
                                int* piVar3 = (int*)list[1];
                                iVar5 = *piVar3;
                                list[1] = iVar5;
                                if (iVar5 == 0) list[2] = 0;
                                else *(int*)(iVar5 + 4) = 0;
                                iVar5 = piVar3[2];
                                (**(void(**)(int*, int*))(*(int*)*list + 8))(list, piVar3);
                                list[3] = list[3] - 1;
                                DAT_008ca4cc = iVar5;
                                FUN_005451a0(*(uint32_t*)(*(int*)(iVar5 + 8) + 8));
                            }
                        }
                        iVar5 = *(int*)(iVar4 + 0x50);
                    }
                    if ((*(int*)(iVar4 + 0xbc) != 0) && (DAT_007263a0 < 2)) {
                        FUN_004baaa0(nullptr);
                    }
                    FUN_00533e70(DAT_008e9fd8);
                    (**(void(**)(int**))(*(int*)*unaff_EBX_alias + 0x38))(unaff_EBX_alias);
                    uVar6 = uVar6 + 1;
                } while (uVar6 < count);
            }
        }
        {
            int* unaff_EBP2 = piVar1;
            (**(void(**)(int**, void*))(*(int*)*unaff_EBP2 + 0x34))(unaff_EBP2, DAT_008e9fd8);
            uint32_t uStack_4 = 0;
            uint32_t count = *(uint32_t*)(param_1 + 0x228);
            if (*(int*)(param_1 + 0x228) != 0) {
                do {
                    int iVar4 = *(int*)(*(int*)(param_1 + 0x21c) + uStack_4 * 4);
                    int iVar5 = *(int*)(iVar4 + 0x50);
                    while (iVar5 != 0) {
                        FUN_005516a0();
                        if (DAT_008ca4cc == 0 && ((int*)DAT_008ca4c8)[3] != 0) {
                            iVar5 = (int)FUN_00551600(0);
                            if (iVar5 == 0) {
                                int* list = (int*)DAT_008ca4c8;
                                int* piVar3 = (int*)list[1];
                                iVar5 = *piVar3;
                                list[1] = iVar5;
                                if (iVar5 == 0) list[2] = 0;
                                else *(int*)(iVar5 + 4) = 0;
                                iVar5 = piVar3[2];
                                (**(void(**)(int*, int*))(*(int*)*list + 8))(list, piVar3);
                                list[3] = list[3] - 1;
                                DAT_008ca4cc = iVar5;
                                FUN_005451a0(*(uint32_t*)(*(int*)(iVar5 + 8) + 8));
                                unaff_EBP2 = piVar1;
                            }
                        }
                        iVar5 = *(int*)(iVar4 + 0x50);
                    }
                    if ((*(int*)(iVar4 + 0xbc) != 0) && (DAT_007263a0 < 2)) {
                        FUN_004baaa0(nullptr);
                    }
                    FUN_00533e70(DAT_008e9fd8);
                    uStack_4 = uStack_4 + 1;
                } while (uStack_4 < count);
            }
            (**(void(**)(int**))(*(int*)*unaff_EBP2 + 0x38))(unaff_EBP2);
            (**(void(**)(int**, void*))(*(int*)*unaff_EBP2 + 0x34))(unaff_EBP2, DAT_008e9fd8);
            FUN_00533e70(DAT_008e9fd8);
            (**(void(**)(int**))(*(int*)*unaff_EBP2 + 0x38))(unaff_EBP2);
        }
    }
    return;
}

// 0x4dcbf0 — observed shape
void FUN_004dcbf0(void* self) {
    if (*(char*)((uint8_t*)self + 0x24c) != 0) {
        if (*(int*)((uint8_t*)self + 0x1dc) != 0) {
            uint32_t uVar1 = 0;
            do {
                *(uint32_t*)(*(int*)((uint8_t*)self + 0x1d4) + uVar1 * 4) = 0;
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint32_t*)((uint8_t*)self + 0x1dc));
        }
        *(uint32_t*)((uint8_t*)self + 0x1dc) = 0;
        *(uint32_t*)((uint8_t*)self + 0x1e0) = 0;
        if (*(int*)((uint8_t*)self + 500) != 0) {
            uint32_t uVar1 = 0;
            do {
                *(uint32_t*)(*(int*)((uint8_t*)self + 0x1ec) + uVar1 * 4) = 0;
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint32_t*)((uint8_t*)self + 500));
        }
        *(uint32_t*)((uint8_t*)self + 500) = 0;
        *(uint32_t*)((uint8_t*)self + 0x1f8) = 0;
        if (*(int*)((uint8_t*)self + 0x20c) != 0) {
            uint32_t uVar1 = 0;
            do {
                *(uint32_t*)(*(int*)((uint8_t*)self + 0x204) + uVar1 * 4) = 0;
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint32_t*)((uint8_t*)self + 0x20c));
        }
        *(uint32_t*)((uint8_t*)self + 0x20c) = 0;
        *(uint32_t*)((uint8_t*)self + 0x210) = 0;
        if (*(int*)((uint8_t*)self + 0x224) != 0) {
            uint32_t uVar1 = 0;
            do {
                *(uint32_t*)(*(int*)((uint8_t*)self + 0x21c) + uVar1 * 4) = 0;
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint32_t*)((uint8_t*)self + 0x224));
        }
        *(uint32_t*)((uint8_t*)self + 0x224) = 0;
        *(uint32_t*)((uint8_t*)self + 0x228) = 0;
        *(uint32_t*)((uint8_t*)self + 0x234) = 0;
        *(uint32_t*)((uint8_t*)self + 0x230) = 0;
    }
    return;
}

// 0x4dcd50 — observed shape
void FUN_004dcd50(uint8_t param_1) {
    void* in_ECX = nullptr;
    FUN_004dcd70();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x4dcd70 — observed shape
void FUN_004dcd70(void* self) {
    int* in_ECX = (int*)self;
    *(void**)in_ECX = PTR_FUN_0070f0d0;
    uint32_t* puVar2 = (uint32_t*)in_ECX[1];
    while (puVar2 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)*puVar2;
        (*(void(**)(int*, uint32_t*))(*(int*)*in_ECX + 8))(in_ECX, puVar2);
        puVar2 = puVar1;
    }
    in_ECX[3] = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    *(void**)in_ECX = PTR_LAB_0070f0c4;
    return;
}

// ---------------------------------------------------------------------------
// Additional externs referenced only by the definitions appended below.
extern void FUN_004dd0c0(int*);
extern void FUN_004dd8f0(int*, int* = nullptr, int = 0);
extern void FUN_004de1e0(int*);
extern int  FUN_004dff30(void);
extern void FUN_0042c590(int,int,int);
extern void FUN_00487fd0(int,int);
extern int  DAT_0085a268;
extern int  DAT_0085a26c;
extern int  DAT_008cac04;
extern int  DAT_008cdc98;
extern int  DAT_00726638;
extern int  DAT_0072663c;
extern void* PTR_DAT_00726640;
extern int  DAT_00869ad0;

// 0x4dcf20 — observed shape
uint32_t* FUN_004dcf20(uint32_t* param_1, uint32_t param_2, int* param_3, int* param_4,
                       uint32_t param_5, char in_CL, uint32_t in_EDX) {
    int iVar1;
    int* piVar2;
    int* piVar3;
    int* piVar4;

    for (iVar1 = 0x19; iVar1 <= 0x2f; iVar1 = iVar1 + 1) {
        param_1[iVar1] = 0;
    }
    param_1[1] = 0xffffffffu;
    param_1[2] = in_EDX;
    if (in_CL == '\0') {
        param_1[0x15] = 0xffffffffu;
    } else {
        param_1[0x15] = param_5;
    }
    *param_1 = param_2;
    *(char*)((uint8_t*)param_1 + 0x59) = in_CL;
    param_1[0x12] = 0xffffffffu;
    param_1[0x13] = 0xffffffffu;
    *(uint8_t*)(param_1 + 3) = 0;
    param_1[0x14] = 400;
    *(uint8_t*)(param_1 + 0x16) = 1;
    piVar3 = param_3;
    piVar2 = (int*)(param_1 + 4);
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 - 1) {
        *piVar2 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar2 = piVar2 + 1;
    }
    piVar3 = (int*)(param_1 + 0xb);
    piVar2 = param_4;
    piVar4 = piVar3;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 - 1) {
        *piVar4 = *piVar2;
        piVar2 = piVar2 + 1;
        piVar4 = piVar4 + 1;
    }
    param_1[0x34] = 0;
    DAT_008be9c8 = 0xffffffff;
    DAT_008be9c4 = 0xffffffff;
    DAT_008be9c0 = 0xffffffff;
    param_1[0x38] = 0;
    *(uint8_t*)(param_1 + 0x39) = 0;
    if (*piVar3 == 0) {
        DAT_00869ab4 = DAT_00869ab4 + *param_3;
        DAT_00861ff8 = DAT_00861ff8 + *param_3;
        *param_3 = 0;
    }
    do {
        iVar1 = ((int (*)(int))FUN_0042e1d0)(0);
    } while (iVar1 != 0);
    DAT_0086c35c = 0;
    DAT_0086c360 = 0;
    FUN_004dd0c0((int*)param_1);
    FUN_004dd8f0((int*)param_1);
    piVar2 = (int*)(param_1 + 4);
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 - 1) {
        *param_3 = *piVar2;
        piVar2 = piVar2 + 1;
        param_3 = param_3 + 1;
    }
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 - 1) {
        *param_4 = *piVar3;
        piVar3 = piVar3 + 1;
        param_4 = param_4 + 1;
    }
    return param_1;
}

// 0x4dd090 — observed shape
void FUN_004dd090(void* self) {
    int* piVar1;
    uint32_t* puVar2;
    int iVar3;
    int iVar4;

    FUN_004dd5d0();
    iVar3 = (int)(intptr_t)self + 0xc0;
    iVar4 = 0x17;
    do {
        puVar2 = *(uint32_t**)(iVar3 - 4);
        iVar3 = iVar3 + -4;
        if (puVar2 != nullptr) {
            piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (**(void (***)(int))puVar2)(1);
            }
        }
        iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    return;
}

// 0x4dd0c0 — observed shape
void FUN_004dd0c0(int* param_1) {
    int* piVar1;
    int iVar2;
    char cVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;
    int iVar8;
    int* piVar9;

    param_1[0x33] = 0;
    FUN_004890c0(&DAT_008c822c);
    FUN_004dd890(param_1);
    iVar4 = *param_1;
    if (iVar4 == 0) {
        FUN_00486990(param_1[2], 1);
        goto LAB_004dd1cd;
    }
    if (iVar4 == 2) {
        FUN_00485380(0, 0, 1);
        goto LAB_004dd1cd;
    }
    if (iVar4 == 3) {
        FUN_00485380(6, 0, 1);
        goto LAB_004dd1cd;
    }
    if (param_1[0x15] != -1) {
        cVar3 = FUN_004afe00();
        if (cVar3 != '\0') {
            if (DAT_008cabd4 < 1000) {
                if (0x5db < DAT_008cabd4) goto LAB_004dd133;
LAB_004dd13f:
                iVar4 = 2;
            } else if (DAT_008cabd4 < 0x5dc) {
                iVar4 = 0;
            } else {
LAB_004dd133:
                iVar4 = 1;
                if (0x7ed < DAT_008cabd4) goto LAB_004dd13f;
            }
            FUN_00485380(iVar4 + 3, 0, 0);
            goto LAB_004dd1cd;
        }
    }
    if (DAT_008cabd4 < 1000) {
        if (0x5db < DAT_008cabd4) goto LAB_004dd17f;
LAB_004dd18b:
        uVar5 = 2;
    } else {
        if (DAT_008cabd4 < 0x5dc) {
            FUN_00485380(0, 0, 0);
            goto LAB_004dd1cd;
        }
LAB_004dd17f:
        uVar5 = 1;
        if (0x7ed < DAT_008cabd4) goto LAB_004dd18b;
    }
    FUN_00485380(uVar5, 0, 0);
LAB_004dd1cd:
    iVar4 = (int)(intptr_t)FUN_00533c78(0x50);
    if (iVar4 == 0) {
        iVar4 = 0;
    } else {
        iVar4 = (int)(intptr_t)FUN_00503ca0();
    }
    param_1[0x17] = iVar4;
    puVar6 = (uint32_t*)FUN_00533c78(0xc);
    if (puVar6 == nullptr) {
        puVar6 = nullptr;
    } else {
        *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_0070f1bc;
        puVar6[1] = (uint32_t)(uintptr_t)param_1;
        puVar6[2] = 0xffffffffu;
    }
    param_1[0x18] = (int)(intptr_t)puVar6;
    puVar6 = *(uint32_t**)(param_1[0x17] + 4);
    if (puVar6 != nullptr) {
        puVar6[1] = puVar6[1] + 1;
    }
    puVar6[0x3e] = (uint32_t)param_1[0x18];
    piVar9 = (int*)(puVar6 + 1);
    *piVar9 = *piVar9 + -1;
    if (*piVar9 == 0) {
        (**(void (***)(int))puVar6)(1);
    }
    iVar4 = (int)(intptr_t)FUN_00533c78(4);
    if (iVar4 == 0) {
        DAT_008cac40 = nullptr;
    } else {
        DAT_008cac40 = FUN_00502460();
    }
    *(int*)DAT_008cac40 = param_1[0x17];
    FUN_005be280("f4Depths", 0x10, &DAT_007272f8);
    iVar4 = 0;
    piVar9 = param_1 + 0x19;
    do {
        if ((iVar4 < 0) || (5 < iVar4)) {
            if ((5 < iVar4) && (iVar4 < 0xc)) {
                puVar7 = (uint32_t*)FUN_004dd760(
                    ((void**)&PTR_s_TRADE_BUTTON_TO_PLAYER_FOOD_007263d0)[iVar4],
                    ((void**)&PTR_s_button_leftArrow_kfm_00726430)[iVar4], 0xfffffff6);
                puVar6 = (uint32_t*)*piVar9;
                if (puVar6 != puVar7) {
                    if (puVar6 != nullptr) {
                        piVar1 = (int*)(puVar6 + 1);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            (**(void (***)(int))puVar6)(1);
                        }
                    }
                    *piVar9 = (int)(intptr_t)puVar7;
                    if (puVar7 != nullptr) {
                        puVar7[1] = puVar7[1] + 1;
                    }
                }
                iVar8 = param_1[0x17];
                goto LAB_004dd344;
            }
            if ((((iVar4 == 0x14) || (iVar4 == 0x15)) && (param_1[0x15] != -1)) &&
                (*(char*)((uint8_t*)param_1 + 0x59) != '\0')) {
                puVar7 = (uint32_t*)FUN_004dd800(
                    ((void**)&PTR_s_TRADE_BUTTON_TO_PLAYER_FOOD_007263d0)[iVar4],
                    ((void**)&PTR_s_button_leftArrow_kfm_00726430)[iVar4], 0xfffffff6);
                puVar7[0xa5] = 0;
                puVar7[0xa6] = 1;
                puVar6 = (uint32_t*)*piVar9;
                if (puVar6 != puVar7) {
                    if (puVar6 != nullptr) {
                        piVar1 = (int*)(puVar6 + 1);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            (**(void (***)(int))puVar6)(1);
                        }
                    }
                    *piVar9 = (int)(intptr_t)puVar7;
                    puVar7[1] = puVar7[1] + 1;
                }
                *(uint32_t*)(*piVar9 + 0x68) = 0x3f99999a;
                iVar8 = *piVar9;
                iVar2 = param_1[0x17];
                FUN_00503fb0((void*)(intptr_t)iVar8);
                (*(void (**)(int, int))(intptr_t)(**(int**)(iVar2 + 4) + 0x70))(iVar8, 1);
                FUN_00534130();
                FUN_00533d10(0, 1);
            } else {
                puVar6 = (uint32_t*)*piVar9;
                if (puVar6 != nullptr) {
                    piVar1 = (int*)(puVar6 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (**(void (***)(int))puVar6)(1);
                    }
                    *piVar9 = 0;
                }
            }
        } else {
            puVar7 = (uint32_t*)FUN_004dd760(
                ((void**)&PTR_s_TRADE_BUTTON_TO_PLAYER_FOOD_007263d0)[iVar4],
                ((void**)&PTR_s_button_leftArrow_kfm_00726430)[iVar4], 0xfffffff6);
            puVar6 = (uint32_t*)*piVar9;
            if (puVar6 != puVar7) {
                if (puVar6 != nullptr) {
                    piVar1 = (int*)(puVar6 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (**(void (***)(int))puVar6)(1);
                    }
                }
                *piVar9 = (int)(intptr_t)puVar7;
                if (puVar7 != nullptr) {
                    puVar7[1] = puVar7[1] + 1;
                }
            }
            iVar8 = param_1[0x17];
LAB_004dd344:
            iVar2 = *piVar9;
            FUN_00503fb0((void*)(intptr_t)iVar2);
            (*(void (**)(int, int))(intptr_t)(**(int**)(iVar8 + 4) + 0x70))(iVar2, 1);
            FUN_00534130();
            FUN_00533d10(0, 1);
            FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
        }
        iVar4 = iVar4 + 1;
        piVar9 = piVar9 + 1;
        if (0x16 < iVar4) {
            if (((param_1[0x15] != -1) && ((&DAT_008142f8)[param_1[0x15] * 0x22e] != -1)) &&
                (*(char*)((uint8_t*)param_1 + 0x59) != '\0')) {
                FUN_004e00d0();
            }
            return;
        }
    } while (true);
}

// 0x4dd5d0 — observed shape
void FUN_004dd5d0_recon(void* self) {
    int* piVar1;
    uint32_t* puVar2;
    void* pvVar3;
    char cVar4;
    int* in_EAX = (int*)self;
    void* uVar5;
    int iVar6;
    int* piVar7;

    cVar4 = DAT_00725d98;
    if ((DAT_008be9cf != '\0') || (DAT_008be9ce != '\0')) {
        ((char*)&DAT_00726814)[DAT_00726820] = DAT_00725d98;
        DAT_00726820 = DAT_00726820 + 1;
        if (cVar4 != '\0') {
            FUN_00481100();
        }
        DAT_00725d98 = '\0';
        DAT_008c9df4 = 1;
        FUN_004de1e0(in_EAX);
        FUN_00481180();
        DAT_0086c330 = 0;
    }
    if (((in_EAX[0x15] != -1) && ((char)in_EAX[0x16] == '\0')) &&
        (*(char*)((uint8_t*)in_EAX + 0x59) != '\0')) {
        FUN_00404ca0();
    }
    if (*in_EAX == 0) {
        FUN_00487850();
    } else {
        FUN_004867b0();
    }
    FUN_005be280("f4Depths", 0x10, &DAT_007272e8);
    piVar7 = in_EAX + 0x19;
    iVar6 = 0x17;
    do {
        puVar2 = (uint32_t*)*piVar7;
        if (puVar2 != nullptr) {
            piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (**(void (***)(int))puVar2)(1);
            }
            *piVar7 = 0;
        }
        piVar7 = piVar7 + 1;
        iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (in_EAX[0x33] != 0) {
        uVar5 = FUN_004baaa0(nullptr);
        FUN_00535920(uVar5);
        uVar5 = FUN_004baaa0(nullptr);
        FUN_00535920(uVar5);
    }
    if ((void*)(intptr_t)in_EAX[0x33] != nullptr) {
        (**(void (***)(int))(intptr_t)in_EAX[0x33])(1);
        in_EAX[0x33] = 0;
    }
    pvVar3 = (void*)(intptr_t)in_EAX[0x17];
    if (pvVar3 != nullptr) {
        FUN_00503ef0();
        operator_delete(pvVar3);
        in_EAX[0x17] = 0;
    }
    if ((void*)(intptr_t)in_EAX[0x18] != nullptr) {
        (**(void (***)(int))(intptr_t)in_EAX[0x18])(1);
        in_EAX[0x18] = 0;
    }
    piVar7 = in_EAX + 0x30;
    iVar6 = 3;
    do {
        pvVar3 = (void*)(intptr_t)*piVar7;
        if (pvVar3 != nullptr) {
            FUN_00508190();
            operator_delete(pvVar3);
            *piVar7 = 0;
        }
        piVar7 = piVar7 + 1;
        iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (DAT_008cac40 != nullptr) {
        operator_delete(DAT_008cac40);
        DAT_008cac40 = nullptr;
    }
    FUN_00488fc0(&DAT_008c822c, 0x42, 0xbf800000u);
    return;
}

// 0x4dd760 — observed shape
void* FUN_004dd760_recon(void* param_1, void* param_2, int param_3, int in_EAX, int in_EBX) {
    uint32_t* puVar1;

    puVar1 = (uint32_t*)FUN_00533c78(0x290);
    if (puVar1 == nullptr) {
        return nullptr;
    }
    FUN_00506e60(param_1, param_2, (float)((in_EAX << 10) / 0x280),
                 (float)((in_EBX * 0x300) / 0x1e0), (float)param_3, 0x3f800000, 0);
    *puVar1 = (uint32_t)(uintptr_t)&PTR_FUN_007116a0;
    return puVar1;
}

// 0x4dd800 — observed shape
uint32_t FUN_004dd800_recon(void* param_1, void* param_2, int param_3, int in_EAX, int in_EBX) {
    int iVar1;
    uint32_t uVar2;

    iVar1 = (int)(intptr_t)FUN_00533c78(0x29c);
    if (iVar1 == 0) {
        return 0;
    }
    // The listing consumes the construction result even though the helper is
    // declared void above; call it through its observed result type.
    uVar2 = ((uint32_t (*)(void*,void*,float,float,float,uint32_t))FUN_00506c60)(
        param_1, param_2, (float)((in_EAX << 10) / 0x280),
        (float)((in_EBX * 0x300) / 0x1e0), (float)param_3, 0x3f800000);
    return uVar2;
}

// 0x4dd890 — observed shape
void FUN_004dd890(void* self) {
    int in_EAX = (int)(intptr_t)self;
    int iVar1;
    void* uVar2;
    void** ppuVar3;
    int* piVar4;
    int vtable;

    ppuVar3 = &PTR_s_capt_kidd_30pt_fnt_007263c4;
    piVar4 = (int*)(in_EAX + 0xc0);
    do {
        iVar1 = (int)(intptr_t)FUN_00533c78(0x68);
        if (iVar1 == 0) {
            iVar1 = 0;
        } else {
            iVar1 = (int)(intptr_t)FUN_00508120();
        }
        *piVar4 = iVar1;
        FUN_00508670((void*)(intptr_t)iVar1, *ppuVar3);
        iVar1 = *piVar4;
        vtable = *(int*)(intptr_t)DAT_00727b28;
        uVar2 = (*(void* (**)(int, int))(intptr_t)(vtable + 4))(2, 0);
        ppuVar3 = ppuVar3 + 1;
        piVar4 = piVar4 + 1;
        *(uint32_t*)(iVar1 + 100) = (uint32_t)(uintptr_t)uVar2;
    } while ((intptr_t)ppuVar3 < 0x7263d0);
    return;
}

// 0x4dd8f0 — observed shape
void FUN_004dd8f0(int* param_1, int* in_EBP, int in_EBX) {
    char cVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    int iVar6;
    int* piVar7;
    int* piVar5;
    int extraout_EDX = 0;  // NEEDS_MANUAL: live EDX after FUN_004bcd00, not expressed in pseudocode
    int iVar8;
    int iVar11;
    int iVar12;
    bool bVar9;
    uint64_t uVar10;
    uint32_t* local_20;
    uint32_t* local_1c;

    local_1c = (uint32_t*)(uintptr_t)0xffffffff;
    param_1[0x33] = 0;
    iVar2 = (int)(intptr_t)FUN_00533c78(0x2a0);
    if (iVar2 == 0) {
        local_20 = nullptr;
    } else {
        local_20 = (uint32_t*)(intptr_t)((void* (*)(const char*,void*,int,int,int,uint32_t,uint32_t,int))
                                         FUN_00514090)(
            "MouseOver", *(void**)DAT_008c9dd8, 1, 0, 0, 0x41200000, 0x3f4ccccd, 1);
    }
    if (local_20 != nullptr) {
        *(int*)(local_20 + 4) = *(int*)(local_20 + 4) + 1;
    }
    iVar11 = 0x3f800000;
    FUN_00514430(0x3f800000, 0x3f4ccccd, 0, 0x3f800000);
    iVar2 = param_1[0x17];
    FUN_00503fb0(local_20);
    (*(void (**)(uint32_t*, int))(intptr_t)(**(int**)(iVar2 + 4) + 0x70))(local_20, 1);
    FUN_00534130();
    FUN_00533d10(0, 1);
    cVar1 = DAT_00725d98;
    ((char*)&DAT_00726814)[DAT_00726820] = DAT_00725d98;
    DAT_00726820 = DAT_00726820 + 1;
    if (cVar1 != '\0') {
        FUN_00481100();
    }
    DAT_00725d98 = 0;
    DAT_008c9df4 = 1;
    if ((param_1[0x15] != -1) && (*(char*)((uint8_t*)param_1 + 0x59) != '\0')) {
        iVar2 = ((int (*)(int))FUN_004bb500)(0);
        param_1[0x33] = iVar2;
        *(uint32_t*)(iVar2 + 0x18) = (uint32_t)DAT_008ea008;
        *(uint32_t*)(*(int*)(param_1[0x33] + 0xbc) + 0x18) = (uint32_t)DAT_008ea008;
        FUN_004beee0();
        iVar2 = param_1[0x33];
        if (*(int*)(iVar2 + 0xbc) != 0) {
            FUN_004bcd00(0);
            iVar2 = extraout_EDX;
        }
        *(uint8_t*)(iVar2 + 0x4c) = 0;
        FUN_004bcac0();
        FUN_004bca60();
        FUN_004bc740((&DAT_00814324)[param_1[0x15] * 0x45c] & 1);
        uVar4 = (uint32_t)(param_1[0x15] < 8);
        uVar3 = ((uint32_t (*)(uint32_t))FUN_0045a120)(uVar4);
        FUN_004bc7e0(uVar3, uVar4);
        uVar3 = (uint32_t)(intptr_t)FUN_004baaa0(nullptr);
        FUN_004c2810((void*)(intptr_t)uVar3, 0x80);
        iVar2 = DAT_008c97c4;
        *(uint8_t*)(DAT_008c97c0 + 0xb4) = 1;
        *(uint8_t*)(iVar2 + 0xb4) = 1;
        uVar3 = (uint32_t)(intptr_t)FUN_004baaa0(nullptr);
        FUN_00535670((void*)(intptr_t)uVar3);
        uVar3 = (uint32_t)(intptr_t)FUN_004baaa0(nullptr);
        FUN_00535670((void*)(intptr_t)uVar3);
    }
    cVar1 = (char)param_1[3];
    do {
        if (cVar1 != '\0') {
            if (in_EBP != nullptr) {
                piVar7 = in_EBP + 1;
                *piVar7 = *piVar7 + -1;
                if (*piVar7 == 0) {
                    (**(void (***)(int))in_EBP)(1);
                }
                local_1c = nullptr;
            }
            FUN_00481180();
            DAT_0086c330 = 0;
            if (local_1c != nullptr) {
                piVar7 = (int*)(local_1c + 1);
                *piVar7 = *piVar7 + -1;
                if (*piVar7 == 0) {
                    /* WARNING: Could not emulate address calculation at 0x004de1a4 */
                    /* WARNING: Treating indirect jump as call */
                    (**(void (***)(int))local_1c)(1);
                    return;
                }
            }
            return;
        }
        DAT_008cac00 = DAT_008cac00 + 0x34;
        if (DAT_008cac27 != '\0') {
            *(uint8_t*)(param_1 + 3) = 1;
        }
        if (*param_1 == 0) {
            if (0.0 < DAT_008cab0c) {
                FUN_004de1e0(param_1);
            }
            FUN_004874e0(param_1[1]);
            param_1[1] = -1;
        } else {
            FUN_004862a0();
        }
        FUN_004de1e0(param_1);
        iVar12 = DAT_008dc30c;
        uVar10 = (uint64_t)FUN_0042c6f0();
        iVar2 = (int)(uVar10 >> 0x20);
        iVar8 = (int)uVar10;
        if ((iVar8 < 0xc) || (0x11 < iVar8)) {
            if ((iVar11 != iVar12) || (in_EBX != iVar2)) goto LAB_004ddc2c;
        } else if ((iVar11 != iVar12) || (in_EBX != iVar2)) {
            iVar8 = iVar8 + -0xb;
LAB_004ddc2c:
            if ((param_1[0x12] != iVar8) && (iVar8 != -1)) {
                FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xbf800000u,
                             0xffffffffu);
                iVar12 = DAT_008dc30c;
            }
            iVar2 = DAT_008dc310;
            param_1[0x12] = iVar8;
        }
        iVar11 = *(int*)(param_1[0x18] + 8);
        bVar9 = false;
        if (((-1 < iVar11) && (iVar11 < 6)) || ((5 < iVar11 && (iVar11 < 0xc)))) {
            if ((iVar11 < 0) || (5 < iVar11)) {
                iVar8 = iVar11 + -5;
                if (param_1[iVar11 + 6] == 0) {
                    FUN_004f6090("Drop @ITEM", iVar8);
                } else {
                    FUN_004f6090("Sell @ITEM for @NUM gold", iVar8, param_1[iVar11 + 6]);
                }
                if (param_1[iVar11 + 6] <= param_1[4]) {
                    iVar11 = (&DAT_00869ab4)[iVar8];
                    goto LAB_004ddd46;
                }
            } else {
                iVar8 = iVar11 + 1;
                if (param_1[iVar11 + 0xc] < 1) {
                    uVar4 = ((uint32_t (*)(const char*, ...))FUN_004f6090)("Take @ITEM", iVar8);
                } else {
                    uVar4 = ((uint32_t (*)(const char*, ...))FUN_004f6090)(
                        "Buy @ITEM for @NUM gold", iVar8, param_1[iVar11 + 0xc]);
                }
                if ((param_1[0x15] == -1) || ((char)param_1[0x16] != '\0')) {
                    uVar4 = 1;
                } else {
                    uVar4 = uVar4 & 0xffffff00;
                }
                if ((param_1[iVar11 + 0xc] <= DAT_00869ab4) && (0 < param_1[iVar11 + 5])) {
                    iVar11 = FUN_00404910(uVar4);
LAB_004ddd46:
                    if (((0 < iVar11) && (0 < iVar8)) && (iVar8 < 7)) {
                        bVar9 = true;
                        goto LAB_004ddd5f;
                    }
                }
            }
            bVar9 = false;
        }
LAB_004ddd5f:
        piVar7 = param_1 + 0xd;
        iVar11 = 0;
        if (param_1[0xd] != 0) {
            piVar5 = &DAT_00869abc;
            do {
                iVar8 = *piVar5;
                piVar5 = piVar5 + 1;
                iVar11 = iVar11 + iVar8 * *piVar7;
                piVar7 = piVar7 + 1;
            } while ((intptr_t)piVar5 < 0x869ac9);
        }
        if (param_1[4] < iVar11) {
            iVar11 = param_1[4];
        }
        if (param_1[0x12] == 0x12) {
            iVar8 = FUN_0042c6f0();
            bVar9 = iVar8 == 0x12;
            FUN_004f6090("Sell all cargo for @NUM gold", iVar11);
        }
        if (bVar9) {
            piVar7 = in_EBP;
            (*(void (**)(void*))(intptr_t)(*in_EBP + 200))(&DAT_00869b48);
            if (param_1[0x12] == 0x16) {
                iVar2 = DAT_008dc30c + -0x10;
            } else {
                iVar2 = DAT_008dc30c + 0x10;
            }
            (*(void (**)(float, float, uint32_t))(intptr_t)(*in_EBP + 0xa0))(
                (float)iVar2 * 1.6f, (float)(DAT_008dc310 + -0x10) * 1.6f, 0xc1300000);
            *(uint8_t*)(in_EBP + 8) = *(uint8_t*)(in_EBP + 8) & 0xfe;
            in_EBP = piVar7;
        } else {
            *(uint8_t*)(in_EBP + 8) = *(uint8_t*)(in_EBP + 8) | 1;
        }
        if ((DAT_0086c35c == 1) ||
            ((0 < DAT_0086c360 && (param_1[0x14] < DAT_008c8494 - param_1[0x13])))) {
            iVar11 = param_1[0x14] + -0x1e;
            param_1[0x13] = DAT_008c8494;
            if (iVar11 < 0x32) {
                iVar11 = 0x32;
            }
            param_1[0x14] = iVar11;
            iVar11 = *(int*)(param_1[0x18] + 8);
            if ((iVar11 < 0) || (5 < iVar11)) {
                if ((5 < iVar11) && (iVar11 < 0xc)) {
                    FUN_004dff80(param_1);
                }
            } else {
                iVar8 = iVar11 + 1;
                if ((param_1[0x15] == 0xffffffff) || ((char)param_1[0x16] != '\0')) {
                    uVar4 = 1;
                } else {
                    uVar4 = (uint32_t)param_1[0x15] & 0xffffff00;
                }
                if ((((DAT_00869ab4 < param_1[iVar11 + 0xc]) || (param_1[iVar11 + 5] < 1)) ||
                     (iVar6 = FUN_00404910(uVar4), iVar6 < 1)) || ((iVar8 < 1 || (6 < iVar8)))) {
                    FUN_004889c0(&DAT_008c8274, 0x38, 0xffffffffu, 0xffffffffu, 0xffffffffu,
                                 0xbf800000u, 0xffffffffu);
                    iVar11 = DAT_008c8494;
                    param_1[0x14] = 400;
                    param_1[0x13] = iVar11;
                } else {
                    FUN_004888e0(0x2d, 0xffffffffu, 0xffffffffu, 0xbf800000u);
                    (&DAT_00869ab4)[iVar8] = (&DAT_00869ab4)[iVar8] + 1;
                    param_1[iVar11 + 5] = param_1[iVar11 + 5] + -1;
                    param_1[4] = param_1[4] + param_1[iVar11 + 0xc];
                    iVar8 = DAT_008c8494;
                    DAT_00869ab4 = DAT_00869ab4 - param_1[iVar11 + 0xc];
                    param_1[1] = 1;
                    param_1[0x13] = iVar8;
                }
            }
        } else if (DAT_0086c360 == 0) {
            param_1[0x14] = 400;
        }
        FUN_004d0cd0(0, 0, 0);
        iVar11 = FUN_0042e440();
        if ((iVar11 == 0xd) || (iVar11 == 0x10c)) {
            iVar11 = param_1[0x12] + 0x200;
        }
        if (iVar11 < 0x129) {
            if (iVar11 == 0x128) {
                FUN_004e01e0();
            } else if (iVar11 < 0x126) {
                if (iVar11 == 0x125) {
                    FUN_004e0030(param_1[0x12]);
                } else if ((iVar11 == 0x1b) || (iVar11 == 0x20)) {
                    goto switchD_004de06d_caseD_216;
                }
            } else if (iVar11 == 0x126) {
                FUN_004e02a0();
            } else if (iVar11 == 0x127) {
                FUN_004dff80(param_1);
            }
            goto switchD_004de06d_default;
        }
        switch (iVar11) {
        case 0x212:
        case 0x213: {
            iVar12 = -1;
            if (*param_1 == 0) {
                FUN_0042e730();
                iVar8 = 2;
                piVar7 = param_1 + 6;
                iVar11 = (int)((intptr_t)&DAT_00869aa4 - (intptr_t)param_1);
                do {
                    iVar6 = *(int*)((intptr_t)iVar11 + (intptr_t)piVar7);
                    while ((((0 < iVar6 && (piVar7[7] <= param_1[4])) &&
                             (0 < *(int*)((intptr_t)iVar11 + (intptr_t)piVar7))) &&
                            ((0 < iVar8 && (iVar8 < 7))))) {
                        *piVar7 = *piVar7 + 1;
                        *(int*)((intptr_t)iVar11 + (intptr_t)piVar7) =
                            *(int*)((intptr_t)iVar11 + (intptr_t)piVar7) + -1;
                        DAT_00869ab4 = DAT_00869ab4 + piVar7[7];
                        param_1[4] = param_1[4] - piVar7[7];
                        param_1[1] = 0;
                        iVar6 = *(int*)((intptr_t)iVar11 + (intptr_t)piVar7);
                    }
                    iVar8 = iVar8 + 1;
                    piVar7 = piVar7 + 1;
                } while (iVar8 < 6);
            } else {
                FUN_0042e730();
                iVar11 = 1;
                piVar7 = param_1 + 0xc;
                do {
                    cVar1 = (char)FUN_004dff30();
                    while (cVar1 != '\0') {
                        cVar1 = (char)FUN_004dff30();
                        if (cVar1 == '\0') {
                            param_1[0x14] = 400;
                        } else {
                            piVar5 = (int*)(((intptr_t)&DAT_00869a88 - (intptr_t)param_1)
                                            + (intptr_t)piVar7);
                            *piVar5 = *piVar5 + 1;
                            piVar7[-7] = piVar7[-7] + -1;
                            param_1[4] = param_1[4] + *piVar7;
                            DAT_00869ab4 = DAT_00869ab4 - *piVar7;
                            param_1[1] = 1;
                        }
                        cVar1 = (char)FUN_004dff30();
                    }
                    iVar11 = iVar11 + 1;
                    piVar7 = piVar7 + 1;
                } while (iVar11 < 7);
            }
            break;
        }
        case 0x214:
            goto LAB_004de15e;
        case 0x215:
LAB_004de15e:
            FUN_004e00d0();
            break;
        case 0x216:
switchD_004de06d_caseD_216:
            FUN_0042e730();
            *(uint8_t*)(param_1 + 3) = 1;
        }
switchD_004de06d_default:
        cVar1 = (char)param_1[3];
        in_EBX = iVar2;
        iVar11 = iVar12;
    } while (true);
}

// 0x4de1e0 — observed shape
void FUN_004de1e0(int* param_1) {
    uint16_t uVar1;
    int* piVar2;
    char cVar3;
    short sVar4;
    short sVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int iVar8;
    uint32_t uVar9;
    int iVar10;
    int extraout_ECX = 0;  // NEEDS_MANUAL: live ECX after FUN_005f0ddc, not expressed in pseudocode
    int iVar11;
    uint32_t uVar12;
    int* piVar13;
    short sVar14;
    int iVar15;
    uint32_t* puVar16;
    int iVar17;
    int* piVar18;
    uint32_t uVar19;
    char* pcVar20;
    uint32_t uVar21;
    int* local_c;
    int local_8[2];

    piVar2 = param_1;
    DAT_0086c330 = 0;
    if (*param_1 != 0) {
        DAT_008cac00 = DAT_008cac00 + 30000;
        iVar11 = (int)(((int64_t)DAT_0085a268 * 0x55555555) >> 0x20) - DAT_0085a268;
        DAT_008cac04 = 1;
        FUN_004af080(nullptr, 0, 0, 0, nullptr,
                     -((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2),
                     (iVar11 >> 1) - (iVar11 >> 0x1f),
                     (DAT_0085a26c * 3 + (DAT_0085a26c * 3 >> 0x1f & 3)) >> 2,
                     (DAT_0085a268 * 5) / 3, 0xff000000u, 10);
        iVar11 = (int)(((int64_t)DAT_0085a268 * 0x55555555) >> 0x20) - DAT_0085a268;
        FUN_004af080(nullptr, 0, 0, 0, nullptr, DAT_0085a26c / 2,
                     (iVar11 >> 1) - (iVar11 >> 0x1f), (void*)(intptr_t)(DAT_0085a26c / 2),
                     (DAT_0085a268 * 5) / 3, 0x80000000u, 0xa0);
        DAT_008cac00 = DAT_008cac00 + -30000;
        DAT_008cac04 = 0;
    }
    iVar11 = piVar2[0x12];
    uVar7 = (uint32_t)DAT_0085a268 >> 0x1f;
    if ((iVar11 < 1) || (6 < iVar11)) {
        uVar12 = (uint32_t)DAT_0085a26c >> 0x1f;
        if ((iVar11 != 0x12) && (iVar11 != 0x13)) {
            if (iVar11 == 0x14) {
                FUN_004af030(0x400, 0x20, ((DAT_0085a26c + (int)(uVar12 & 3)) >> 2) + 10,
                             (DAT_0085a268 - ((DAT_0085a268 * 5 + (DAT_0085a268 * 5 >> 0x1f & 0x1f)) >> 5))
                             + 1, (void*)(intptr_t)piVar2[0x36],
                             ((((DAT_0085a268 / 0xe) * 2) / 3) * 2) / 3, 0xffffffffu, 0);
            } else if (iVar11 == 0x15) {
                iVar11 = ((DAT_0085a268 / 0xe) * 2) / 3;
                FUN_004af030(0x400, 0x20, ((DAT_0085a26c + (int)(uVar12 & 3)) >> 2) + 10,
                             (iVar11 - ((DAT_0085a268 * 5 + (DAT_0085a268 * 5 >> 0x1f & 0x1f)) >> 5))
                             + 1 + DAT_0085a268, (void*)(intptr_t)piVar2[0x36], (iVar11 * 2) / 3,
                             0xffffffffu, 0);
            }
            goto LAB_004de619;
        }
        iVar8 = ((DAT_0085a268 / 0xe) * 2) / 3;
        local_c = (int*)(intptr_t)(piVar2[iVar11 + 0x23] * 2);
        iVar15 = (((DAT_0085a268 * 7) / 0xe + (DAT_0085a268 / 0xe) / 3) - DAT_0085a268 / 0x38) + -2
                 + ((DAT_0085a268 + (int)(uVar7 & 7)) >> 3);
        iVar11 = ((DAT_0085a26c * 4) / 0xd + ((DAT_0085a26c + (int)(uVar12 & 0x1f)) >> 5))
                 - piVar2[iVar11 + 0x23];
        param_1 = (int*)(intptr_t)0x20;
        local_8[0] = 0x400;
        uVar6 = (uint32_t)(intptr_t)FUN_004cddf0("textHighlightBar1024.dds", 0, 0, local_8, &param_1);
        piVar13 = param_1;
        piVar18 = local_c;
    } else {
        iVar8 = DAT_0085a268 / 0xe;
        param_1 = (int*)(intptr_t)(DAT_0085a26c / 2);
        local_c = (int*)(intptr_t)0x20;
        local_8[0] = 0x400;
        iVar15 = ((((iVar11 * DAT_0085a268) / 0xe - ((*piVar2 != 0) - 1 & 8))
                   + ((DAT_0085a268 + (int)(uVar7 & 0x7f)) >> 7)) - DAT_0085a268 / 0x38)
                 + ((DAT_0085a268 + (int)(uVar7 & 7)) >> 3);
        iVar11 = ((DAT_0085a26c << 2) / 0xd - (int)(intptr_t)param_1 / 2) + 0x10;
        uVar6 = (uint32_t)(intptr_t)FUN_004cddf0("textHighlightBar1024.dds", 0, 0, local_8, &local_c);
        piVar13 = local_c;
        piVar18 = param_1;
    }
    FUN_004af080((void*)(intptr_t)uVar6, 0, 0, local_8[0], (void*)piVar13, iVar11, iVar15,
                 (void*)piVar18, iVar8, 0xffffffffu, 0);
LAB_004de619:
    uVar7 = (uint32_t)(piVar2[7] + piVar2[10] + piVar2[8] + piVar2[9] + piVar2[5] + piVar2[6]);
    if ((0 < (int)uVar7) && (*piVar2 != 0)) {
        if ((piVar2[0x15] == -1) || ((char)piVar2[0x16] != '\0')) {
            uVar7 = 1;
        } else {
            uVar7 = uVar7 & 0xffffff00;
        }
        iVar11 = FUN_00404910(uVar7);
        if (0 < iVar11) {
            FUN_004f6090("Take All!");
            param_1 = (int*)(intptr_t)((DAT_008cac18 * 100 + (DAT_008cac18 * 100 >> 0x1f & 0x3ff)) >> 10);
            DAT_0085a11c = 100;
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            iVar8 = FUN_005f0ddc();
            iVar15 = DAT_0085a268;
            iVar11 = ((DAT_0085a268 * 7) / 0xe - DAT_0085a268 / 0x38)
                     + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3);
            param_1 = (int*)(intptr_t)((DAT_0085a26c * 4) / 0xd
                     + ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 0x1f)) >> 5));
            iVar10 = DAT_0086c330;
            sVar4 = (short)(intptr_t)param_1 - (short)(iVar8 / 2);
            (&DAT_0086c1a0)[iVar10] = 0x13;
            (&DAT_0086c010)[iVar10] = sVar4;
            (&DAT_0086bcf0)[iVar10] = sVar4 + (short)iVar8;
            sVar4 = (short)iVar11;
            DAT_0086c330 = DAT_0086c330 + 1;
            (&DAT_0086be80)[iVar10] = sVar4;
            (&DAT_0086bb60)[iVar10] = (short)(iVar15 / 0xe) + sVar4;
            FUN_004b06c0(&DAT_00869b48, (int)(intptr_t)param_1, iVar11, 100, 0xffffffffu, 4,
                         0xffffffffu, 0);
            piVar2[0x34] = iVar8;
        }
    }
    iVar11 = 0;
    if (piVar2[0xd] != 0) {
        iVar11 = piVar2[0xe] * DAT_00869ac0 + piVar2[0xf] * DAT_00869ac4
                 + piVar2[0x10] * DAT_00869ac8 + piVar2[0xd] * DAT_00869abc;
    }
    if (piVar2[4] < iVar11) {
        iVar11 = piVar2[4];
    }
    if ((*piVar2 == 0) && (0 < iVar11)) {
        FUN_004f6090("Sell All!", iVar11);
        param_1 = (int*)(intptr_t)((DAT_008cac18 * 100 + (DAT_008cac18 * 100 >> 0x1f & 0x3ff)) >> 10);
        DAT_0085a11c = 100;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
        iVar15 = FUN_005f0ddc();
        param_1 = (int*)(intptr_t)((DAT_0085a26c * 4) / 0xd);
        iVar11 = (int)(intptr_t)param_1 + ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 0x1f)) >> 5);
        FUN_0042c590(0x12, iVar15, DAT_0085a268 / 0xe);
        FUN_004b06c0(&DAT_00869b48, iVar11, extraout_ECX, DAT_0085a11c, 0xffffffffu, 4,
                     0xffffffffu, 0);
        piVar2[0x35] = iVar15;
    }
    FUN_004f6090("@PCNAME", DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
    DAT_0085a11c = 100;
    FUN_00487fd0((DAT_0085a26c << 2) / 0xb, piVar2[0x31]);
    iVar11 = (int)(((int64_t)DAT_0085a268 * 0x6db6db6d) >> 0x20) - DAT_0085a268;
    FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c + (DAT_0085a26c >> 0x1f & 0xf)) >> 4,
                 (iVar11 >> 5) - (iVar11 >> 0x1f), 100, 0xffffffffu, 1, 0xffffffffu, 0);
    FUN_004f6090("@TRADER", *piVar2);
    iVar11 = (int)(((int64_t)DAT_0085a268 * 0x6db6db6d) >> 0x20) - DAT_0085a268;
    FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c * 2) / 5 + 0x20,
                 (iVar11 >> 5) - (iVar11 >> 0x1f), 100, 0xffffffffu, 1, 0xffffffffu, 0);
    iVar17 = DAT_0085a26c * 4;
    iVar11 = iVar17 / 7;
    iVar15 = DAT_0085a268 / 0x38;
    iVar8 = DAT_0085a268 / 0xe;
    iVar10 = DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7);
    param_1 = (int*)(intptr_t)0x10;
    local_8[0] = 0x80;
    uVar6 = (uint32_t)(intptr_t)FUN_004cddf0("optionsSliderBar.dds", 0, 0, local_8, &param_1);
    FUN_004af080((void*)(intptr_t)uVar6, 0, 0, local_8[0], (void*)param_1,
                 (iVar17 / 0xd - iVar11 / 2) + 0x10, (iVar8 - iVar15) + -0xc + (iVar10 >> 3),
                 (void*)(intptr_t)iVar11, 2, 0xffffffffu, 0);
    iVar11 = 0;
    do {
        if (iVar11 == 0) {
            if (*piVar2 == 0) {
                param_1 = (int*)(intptr_t)((((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3)
                          - DAT_0085a268 / 0x38) - 8);
                uVar21 = 0;
                uVar19 = 0x425c0000;
                uVar6 = (uint32_t)FUN_005f0ddc(0x425c0000, 0);
                param_1 = (int*)(intptr_t)((DAT_0085a26c << 2) / 0xd);
                uVar9 = (uint32_t)FUN_005f0ddc(uVar6);
                FUN_004bba60(&DAT_008cdc98, (void*)(intptr_t)uVar9, *(float*)&uVar6, uVar19,
                             *(float*)&uVar21);
            }
            iVar15 = piVar2[4] - piVar2[0x38];
            pcVar20 = (char*)"@NUM gold";
        } else {
            if ((&DAT_008cdc98 + iVar11 * 0x30) != nullptr) {
                param_1 = (int*)(intptr_t)(((DAT_0085a268 * iVar11) / 0xe - DAT_0085a268 / 0x38)
                          + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3));
                uVar21 = 0;
                uVar19 = 0x425c0000;
                uVar6 = (uint32_t)FUN_005f0ddc(0x425c0000, 0);
                param_1 = (int*)(intptr_t)((DAT_0085a26c << 2) / 0xd);
                uVar9 = (uint32_t)FUN_005f0ddc(uVar6);
                FUN_004bba60(&DAT_008cdc98 + iVar11 * 0x30, (void*)(intptr_t)uVar9,
                             *(float*)&uVar6, uVar19, *(float*)&uVar21);
            }
            iVar15 = DAT_0085a268;
            local_8[0] = ((DAT_0085a268 * iVar11) / 0xe - DAT_0085a268 / 0x38)
                         + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3);
            iVar10 = DAT_0085a26c << 2;
            iVar8 = DAT_0086c330;
            sVar5 = (short)local_8[0];
            (&DAT_0086be80)[iVar8] = sVar5;
            sVar4 = (short)(iVar10 / 0xd);
            (&DAT_0086c010)[iVar8] = sVar4;
            (&DAT_0086bb60)[iVar8] = sVar5 + 0x20;
            (&DAT_0086c1a0)[iVar8] = (short)iVar11 + 0xb;
            (&DAT_0086bcf0)[iVar8] = sVar4 + 0x20;
            param_1 = (int*)(intptr_t)(DAT_0085a26c / 2);
            sVar14 = (short)DAT_0086c330 + 1;
            sVar4 = sVar4 - (short)((int)(intptr_t)param_1 / 2);
            DAT_0086c330 = sVar14;
            (&DAT_0086c010)[sVar14] = sVar4;
            (&DAT_0086bcf0)[sVar14] = sVar4 + (short)(intptr_t)param_1;
            DAT_0086c330 = DAT_0086c330 + 1;
            (&DAT_0086c1a0)[sVar14] = (short)iVar11;
            (&DAT_0086be80)[sVar14] = sVar5;
            (&DAT_0086bb60)[sVar14] = (short)(iVar15 / 0xe) + sVar5;
            if (iVar11 == 6) {
                iVar15 = piVar2[10];
                pcVar20 = (char*)"@NUM guns";
            } else {
                iVar15 = piVar2[iVar11 + 4];
                pcVar20 = (char*)"@NUM tons";
            }
        }
        FUN_004f6090(pcVar20, iVar15);
        iVar15 = (DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3;
        FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 0x14 + 0x20 + (DAT_0085a26c * 4) / 0xd + iVar15,
                     (((DAT_0085a268 * iVar11) / 0xe
                       + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0x7f)) >> 7)) - DAT_0085a268 / 0x38)
                     + iVar15, 100, 0xffffffffu, 1, 0xffffffffu, 0);
        if (iVar11 == 0) {
            pcVar20 = (char*)"@NUM gold";
            uVar6 = (uint32_t)DAT_00869ab4;
        } else if (iVar11 == 6) {
            pcVar20 = (char*)"@NUM guns";
            uVar6 = (uint32_t)DAT_00869acc;
        } else {
            pcVar20 = (char*)"@NUM tons";
            uVar6 = (uint32_t)(&DAT_00869ab4)[iVar11];
        }
        FUN_004f6090(pcVar20, uVar6);
        local_c = (int*)(intptr_t)((DAT_008cac18 * 100 + (DAT_008cac18 * 100 >> 0x1f & 0x3ff)) >> 10);
        DAT_0085a11c = 100;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
        iVar8 = DAT_0085a268;
        iVar15 = (DAT_0085a26c * 4) / 0xd;
        local_8[0] = DAT_0085a26c / 0x14;
        uVar7 = (uint32_t)DAT_0085a268 >> 0x1f;
        param_1 = (int*)(intptr_t)((DAT_0085a268 + (int)(uVar7 & 7)) >> 3);
        iVar10 = FUN_005f0ddc();
        if (((iVar15 - iVar10) - (int)(intptr_t)param_1) - local_8[0] < 5) {
            uVar6 = 1;
            iVar8 = ((iVar8 * iVar11) / 0xe + ((iVar8 + (int)(uVar7 & 0x7f)) >> 7)) - iVar8 / 0x38;
            iVar15 = 5;
        } else {
            uVar6 = 2;
            iVar8 = ((iVar8 * iVar11) / 0xe + ((iVar8 + (int)(uVar7 & 0x7f)) >> 7)) - iVar8 / 0x38;
            iVar15 = (iVar15 - (int)(intptr_t)param_1) - local_8[0];
        }
        FUN_004b06c0(&DAT_00869b48, iVar15, iVar8 + (int)(intptr_t)param_1, 100, 0xffffffffu, uVar6,
                     0xffffffffu, 0);
        if (iVar11 == 1) {
            iVar15 = (DAT_00869ab0 + 1) / (int)((DAT_00869b34 & 4 | 8) >> 2);
            if (iVar15 == 0) {
                iVar15 = 0xc;
            } else {
                iVar15 = (DAT_00869ab8 * 10) / iVar15;
            }
            FUN_004f6090("(@NUM months)", iVar15);
            iVar15 = (DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3;
            FUN_004b06c0(&DAT_00869b48, ((DAT_0085a26c * 4) / 0xd - DAT_0085a26c / 0x14) - iVar15,
                         DAT_0085a268 / 0xe + 0x12
                         + (((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0x7f)) >> 7) - DAT_0085a268 / 0x38)
                         + iVar15, 0x33, 0xffffffffu, 2, 0xffffffffu, 0);
        }
        if ((*piVar2 == 0) && (iVar11 != 0)) {
            FUN_004f6090("@NUM gold", piVar2[iVar11 + 0xb]);
            FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c << 2) / 0xd + 0x10,
                         (((DAT_0085a268 * iVar11) / 0xe
                           + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0x7f)) >> 7)) - DAT_0085a268 / 0x38)
                         + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3),
                         100, 0xffffffffu, 4, 0xffffffffu, 0);
        }
        uVar7 = ((uint32_t (*)(const char*, ...))FUN_004f6090)("@ITEM", iVar11);
        if (iVar11 != 0) {
            uVar7 = ((uint32_t (*)(void*,int,int,int,uint32_t,int,uint32_t,int))FUN_004b06c0)(
                &DAT_00869b48, (DAT_0085a26c << 2) / 0xd + 0x10,
                ((((DAT_0085a268 * iVar11) / 0xe - ((*piVar2 != 0) - 1 & 8))
                  + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0x7f)) >> 7)) - DAT_0085a268 / 0x38)
                + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3),
                0x32, 0xffffffffu, 4, 0xffffffffu, 0);
        }
        iVar11 = iVar11 + 1;
    } while (iVar11 < 7);
    if ((piVar2[0x15] == -1) || ((char)piVar2[0x16] != '\0')) {
        uVar7 = 1;
    } else {
        uVar7 = uVar7 & 0xffffff00;
    }
    iVar11 = FUN_00404910(uVar7);
    FUN_004f6090("Space in hold: @NUM tons", iVar11);
    FUN_004879f0(0x18, 0);
    iVar15 = (DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3;
    DAT_0085a11c = 0x43;
    FUN_004b06c0(&DAT_00869b48, ((DAT_0085a26c << 2) / 0xd + (DAT_0085a26c / 0x14) * -2) - iVar15,
                 ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0x1f)) >> 5)
                 + ((DAT_0085a268 * 7) / 0xe - DAT_0085a268 / 0x38) + iVar15, 0x43,
                 (((iVar11 < 0) - 1) & 0xbfbf) - 0xbfc0, 4, 0xffffffffu, 0);
    iVar11 = piVar2[7] + piVar2[10] + piVar2[8] + piVar2[9] + piVar2[5] + piVar2[6];
    if (*piVar2 == 0) {
        pcVar20 = (char*)"Total stock: @NUM tons";
    } else {
        pcVar20 = (char*)"Total cargo: @NUM tons";
    }
    FUN_004f6090(pcVar20, iVar11);
    FUN_004879f0(0x18, 0);
    iVar15 = (DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3;
    DAT_0085a11c = 0x43;
    FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c << 2) / 0xd + iVar15 + 0x20 + (DAT_0085a26c / 0x14) * 2,
                 ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0x1f)) >> 5)
                 + ((DAT_0085a268 * 7) / 0xe - DAT_0085a268 / 0x38) + iVar15, 0x43,
                 (((iVar11 < 0) - 1) & 0xbfbf) - 0xbfc0, 4, 0xffffffffu, 0);
    FUN_0042fee0(DAT_0085a26c + -0x2a, 0x16);
    if (*piVar2 != 0) {
        if (piVar2[4] != 0) {
            if (piVar2[0x38] < piVar2[4]) {
                FUN_004889c0(&DAT_008c822c, 0x42, 0xffffffffu, 0xffffffffu, 0xffffffffu,
                             0xbf800000u, 0xffffffffu);
            } else if ((char)piVar2[0x39] == '\0') {
                FUN_00488fc0(&DAT_008c822c, 0x42, 0xbf800000u);
                FUN_004888e0(0x43, 0xffffffffu, 0xffffffffu, 0xbf800000u);
                *(uint8_t*)(piVar2 + 0x39) = 1;
            }
            FUN_00405230(piVar2[0x38], piVar2[4], (DAT_0085a26c << 2) / 0xd + 8,
                         (((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3) - DAT_0085a268 / 0x38)
                         + 8);
            iVar11 = piVar2[4] - piVar2[0x38];
            if (10 < iVar11) {
                iVar11 = 10;
            }
            iVar15 = piVar2[0x38];
            piVar2[0x38] = iVar15 + iVar11;
            DAT_0085a11c = 0x43;
            FUN_004f6090("@NUM gold pieces plundered!", iVar15 + iVar11);
            FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c << 2) / 0xd + 0x17,
                         (((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3) - DAT_0085a268 / 0x38)
                         + -7, DAT_0085a11c, 0xff000000u, 4, 0xffffffffu, 0);
            DAT_0085a11c = 0x43;
            FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c << 2) / 0xd + 0x18,
                         (((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3) - DAT_0085a268 / 0x38)
                         + -8, 0x43, 0xffc00000u, 4, 0xffffffffu, 0);
        }
        iVar11 = piVar2[0x15];
        if ((iVar11 != -1) && (*(char*)((uint8_t*)piVar2 + 0x59) != '\0')) {
            iVar8 = 0;
            iVar15 = 0;
            if (0 < iVar11) {
                do {
                    iVar10 = ((int (*)(void))FUN_0045ba40)();
                    iVar8 = iVar8 + iVar10;
                    iVar15 = iVar15 + 1;
                } while (iVar15 < iVar11);
            }
            FUN_004f6090("What shall we do with the enemy ship, Captain? ");
            FUN_004f60b0("(@SHIPTYPE, @NUM tons)",
                         (int)(short)(&DAT_008142f8)[piVar2[0x15] * 0x22e],
                         (&DAT_00723b1c)[(short)(&DAT_008142f8)[piVar2[0x15] * 0x22e] * 0x44]);
            iVar15 = DAT_00869ab0 - iVar8;
            iVar11 = ((int (*)(void))FUN_0045ba40)();
            if (iVar15 < iVar11) {
                iVar11 = ((int (*)(void))FUN_0045ba40)();
                FUN_004f60b0(" We are short @NUM crew to keep our fleet sailing at full speed.\n",
                             iVar11 + (iVar8 - DAT_00869ab0));
            } else {
                uVar6 = (uint32_t)((int (*)(int))FUN_0045ba40)(iVar15);
                FUN_004f60b0(" We need @NUM of our @NUM available crew to keep her sailing.\n", uVar6);
            }
            FUN_004879f0(0x30, 0);
            FUN_004b06c0(&DAT_00869b48,
                         ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2) + 10,
                         (((DAT_0085a268 / 0xe) * 3) / 2 + (DAT_0085a268 * 7) / 0xe)
                         - DAT_0085a268 / 0x38 + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3),
                         0x3c, 0xffffffffu, 1, 0xffffffffu, 0);
            FUN_004f6090("Keep her");
            param_1 = (int*)(intptr_t)((DAT_0085a11c * DAT_008cac18
                      + (DAT_0085a11c * DAT_008cac18 >> 0x1f & 0x3ff)) >> 10);
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            iVar11 = FUN_005f0ddc();
            iVar15 = DAT_0085a268;
            piVar2[0x36] = iVar11;
            iVar11 = iVar15 * 5;
            FUN_004b06c0(&DAT_00869b48, ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2) + 0x1a,
                         (iVar15 - ((iVar11 + (iVar11 >> 0x1f & 0x1f)) >> 5)) + 1, 0x3c,
                         0xffffffffu, 1, 0xffffffffu, 0);
            iVar8 = DAT_0085a268;
            iVar11 = piVar2[0x36];
            iVar10 = DAT_0086c330;
            iVar15 = DAT_0085a268 * 5;
            sVar4 = (short)DAT_0085a268;
            sVar5 = (short)((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2) + 6;
            (&DAT_0086c010)[iVar10] = sVar5;
            sVar4 = (sVar4 - (short)((iVar15 + (iVar15 >> 0x1f & 0x1f)) >> 5)) + 1;
            DAT_0086c330 = DAT_0086c330 + 1;
            (&DAT_0086be80)[iVar10] = sVar4;
            (&DAT_0086c1a0)[iVar10] = 0x14;
            (&DAT_0086bcf0)[iVar10] = (short)iVar11 + 0x14 + sVar5;
            (&DAT_0086bb60)[iVar10] = (short)(((iVar8 / 0xe) * 2) / 3) + sVar4;
            FUN_004f6090("Sink her");
            param_1 = (int*)(intptr_t)((DAT_008cac18 * DAT_0085a11c
                      + (DAT_008cac18 * DAT_0085a11c >> 0x1f & 0x3ff)) >> 10);
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            iVar15 = FUN_005f0ddc();
            iVar11 = DAT_0085a268;
            piVar2[0x37] = iVar15;
            FUN_004b06c0(&DAT_00869b48, ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2) + 0x1a,
                         (((iVar11 / 0xe) * 2) / 3
                          - ((iVar11 * 5 + (iVar11 * 5 >> 0x1f & 0x1f)) >> 5)) + 1 + iVar11,
                         0x3c, 0xffffffffu, 1, 0xffffffffu, 0);
            iVar15 = ((DAT_0085a268 / 0xe) * 2) / 3;
            iVar11 = piVar2[0x37];
            param_1 = (int*)(intptr_t)((iVar15
                      - ((DAT_0085a268 * 5 + (DAT_0085a268 * 5 >> 0x1f & 0x1f)) >> 5))
                      + 1 + DAT_0085a268);
            iVar8 = DAT_0086c330;
            sVar4 = (short)((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2) + 6;
            DAT_0086c330 = DAT_0086c330 + 1;
            (&DAT_0086c1a0)[iVar8] = 0x15;
            (&DAT_0086c010)[iVar8] = sVar4;
            (&DAT_0086be80)[iVar8] = (short)(intptr_t)param_1;
            (&DAT_0086bcf0)[iVar8] = (short)iVar11 + 0x14 + sVar4;
            (&DAT_0086bb60)[iVar8] = (short)iVar15 + (short)(intptr_t)param_1;
            cVar3 = ((char (*)(void*))FUN_004e0460)(piVar2);
            if ((cVar3 != '\0') && ((char)piVar2[0x16] != '\0')) {
                FUN_004f6090("Warning - Fleet speed reduced");
                FUN_004b06c0(&DAT_00869b48,
                             ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2) + 0x1c + piVar2[0x36],
                             (DAT_0085a268
                              - ((DAT_0085a268 * 5 + (DAT_0085a268 * 5 >> 0x1f & 0x1f)) >> 5)) + 1,
                             0x33, 0xffc00000u, 1, 0xffffffffu, 0);
            }
            FUN_004e0390((int)(short)(&DAT_008142f8)[piVar2[0x15] * 0x22e]);
            FUN_004bbb80(piVar2[0x33], local_8[0] + -0x15555555, 0xf8e38e39, 0,
                         (void*)(intptr_t)param_1, 0, DAT_008c8494);
            FUN_004bbf50();
            FUN_004f6090("Hull Damage: @NUM%", (int)(short)(&DAT_0081431a)[piVar2[0x15] * 0x22e]);
            FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c + (DAT_0085a26c >> 0x1f & 7)) >> 3,
                         (DAT_0085a268 * 7 + (DAT_0085a268 * 7 >> 0x1f & 7)) >> 3, 0x33,
                         0xffc00000u, 4, 0xffffffffu, 0);
            FUN_004f6090("Sail Damage: @NUM%", (int)(short)(&DAT_00814318)[piVar2[0x15] * 0x22e]);
            FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c + (DAT_0085a26c >> 0x1f & 7)) >> 3,
                         ((DAT_0085a268 * 7 + (DAT_0085a268 * 7 >> 0x1f & 7)) >> 3) + 10, 0x33,
                         0xffc00000u, 4, 0xffffffffu, 0);
            iVar11 = (DAT_0085a268 * 0xb) / 0xc;
            uVar1 = *(uint16_t*)(&DAT_00814324 + piVar2[0x15] * 0x45c);
            iVar15 = -1;
            param_1 = nullptr;
            if ((uVar1 & 1) != 0) {
                iVar15 = 0;
            }
            if ((uVar1 & 2) != 0) {
                iVar15 = iVar15 + 1;
            }
            if ((uVar1 & 4) != 0) {
                iVar15 = iVar15 + 1;
            }
            if ((uVar1 & 8) != 0) {
                iVar15 = iVar15 + 1;
            }
            if ((uVar1 & 0x10) != 0) {
                iVar15 = iVar15 + 1;
            }
            if ((uVar1 & 0x20) != 0) {
                iVar15 = iVar15 + 1;
            }
            if ((uVar1 & 0x40) != 0) {
                iVar15 = iVar15 + 1;
            }
            if ((char)uVar1 < '\0') {
                iVar15 = iVar15 + 1;
            }
            if (iVar15 == -1) {
                FUN_004f6090("No Upgrades");
                param_1 = (int*)(intptr_t)((DAT_008cac18 * 0x33
                          + (DAT_008cac18 * 0x33 >> 0x1f & 0x3ff)) >> 10);
                DAT_0085a11c = 0x33;
                DAT_008c9de0 = DAT_008c9dd8;
                FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                iVar15 = FUN_005f0ddc();
                FUN_004884a0((((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 7)) >> 3) - (iVar15 + 0xc) / 2)
                             + -4, iVar11 + 3);
                FUN_004b06c0(&DAT_00869b48, (DAT_0085a26c + (DAT_0085a26c >> 0x1f & 7)) >> 3,
                             iVar11 + 5, 0x33, 0xffffffffu, 4, 0xffffffffu, 0);
            } else {
                FUN_004884a0((((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 7)) >> 3)
                              - ((iVar15 + 2) * 0x10) / 2) + 4, iVar11 + 3);
                local_c = nullptr;
                puVar16 = (uint32_t*)&DAT_008d74d8;
                do {
                    if (((1 << ((int)(intptr_t)local_c & 0x1f))
                         & (int)*(short*)(&DAT_00814324 + piVar2[0x15] * 0x45c)) != 0) {
                        FUN_004bba60(puVar16,
                                     (void*)(intptr_t)((((DAT_0085a26c
                                                        + (DAT_0085a26c >> 0x1f & 7)) >> 3)
                                                        - (iVar15 * 0x10) / 2) + 4
                                                       + (int)(intptr_t)param_1),
                                     (float)(iVar11 + 0xc), 0x42480000, 0);
                        param_1 = (int*)((intptr_t)param_1 + 0x10);
                    }
                    local_c = (int*)((intptr_t)local_c + 1);
                    puVar16 = puVar16 + 0x30;
                } while ((intptr_t)puVar16 < 0x8d7ad8);
            }
        }
        if ((DAT_00869ad0 == 8) && (*(char*)((uint8_t*)piVar2 + 0x59) == '\0')) {
            FUN_004f6090("Your fleet is full.");
            DAT_0085a11c = 100;
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            FUN_004b06c0(&DAT_00869b48,
                         (DAT_0085a26c * 4) / 0xd
                         + ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 0x1f)) >> 5),
                         (((DAT_0085a268 / 0xe) * 3) / 2 + (DAT_0085a268 * 7) / 0xe)
                         - DAT_0085a268 / 0x38 + ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3),
                         100, 0xffffffffu, 4, 0xffffffffu, 0);
        }
    }
    return;
}

// 0x4dfec0 — observed shape
uint32_t FUN_004dfec0(int in_EAX) {
    switch (in_EAX) {
    case 0:
    case 6:
        return 1;
    case 1:
    case 7:
        return 2;
    case 2:
    case 8:
        return 3;
    case 3:
    case 9:
        return 4;
    case 4:
    case 10:
        return 5;
    case 5:
    case 0xb:
        return 6;
    default:
        return 0xffffffffu;
    }
}

// 0x4dff30 — observed shape
int FUN_004dff30_recon(int in_EAX, int in_ESI) {
    int iVar1;
    uint32_t uVar2;

    if (*(int*)(in_EAX + 0x54) != -1) {
        if (*(char*)(in_EAX + 0x58) == '\0') {
            uVar2 = 0;
            goto LAB_004dff43;
        }
    }
    uVar2 = 1;
LAB_004dff43:
    if ((*(int*)(in_EAX + 0x2c + in_ESI * 4) <= DAT_00869ab4) &&
        (0 < *(int*)(in_EAX + 0x10 + in_ESI * 4))) {
        iVar1 = FUN_00404910(uVar2);
        if ((0 < iVar1) && ((0 < in_ESI && (in_ESI < 7)))) {
            return 1;
        }
    }
    return 0;
}

// 0x4dff80 — observed shape
void FUN_004dff80_recon(int param_1, char unaff_BL, int unaff_EDI) {
    int* piVar1;

    if ((((*(int*)(param_1 + 0x10) < *(int*)(param_1 + 0x2c + unaff_EDI * 4)) ||
          ((&DAT_00869ab4)[unaff_EDI] < 1)) || (unaff_EDI < 1)) || (6 < unaff_EDI)) {
        if (unaff_BL != '\0') {
            FUN_004889c0(&DAT_008c8274, 0x38, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xbf800000u,
                         0xffffffffu);
        }
        *(uint32_t*)(param_1 + 0x50) = 400;
    } else {
        if (unaff_BL != '\0') {
            FUN_004888e0(0x2d, 0xffffffffu, 0xffffffffu, 0xbf800000u);
        }
        piVar1 = (int*)(param_1 + 0x10 + unaff_EDI * 4);
        *piVar1 = *piVar1 + 1;
        (&DAT_00869ab4)[unaff_EDI] = (&DAT_00869ab4)[unaff_EDI] + -1;
        DAT_00869ab4 = DAT_00869ab4 + *(int*)(param_1 + 0x2c + unaff_EDI * 4);
        *(int*)(param_1 + 0x10) = *(int*)(param_1 + 0x10) - *(int*)(param_1 + 0x2c + unaff_EDI * 4);
        *(uint32_t*)(param_1 + 4) = 0;
    }
    if (unaff_BL != '\0') {
        *(uint32_t*)(param_1 + 0x4c) = (uint32_t)DAT_008c8494;
    }
    return;
}

// 0x4e0030 — observed shape
void FUN_004e0030_recon(int param_1, char unaff_BL, int unaff_EDI) {
    char cVar1;

    cVar1 = (char)FUN_004dff30();
    if (cVar1 == '\0') {
        if (unaff_BL != '\0') {
            FUN_004889c0(&DAT_008c8274, 0x38, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xbf800000u,
                         0xffffffffu);
        }
        *(uint32_t*)(unaff_EDI + 0x50) = 400;
    } else {
        if (unaff_BL != '\0') {
            FUN_004888e0(0x2d, 0xffffffffu, 0xffffffffu, 0xbf800000u);
        }
        (&DAT_00869ab4)[param_1] = (&DAT_00869ab4)[param_1] + 1;
        *(int*)(unaff_EDI + 0x10 + param_1 * 4) = *(int*)(unaff_EDI + 0x10 + param_1 * 4) + -1;
        *(int*)(unaff_EDI + 0x10) = *(int*)(unaff_EDI + 0x10) + *(int*)(unaff_EDI + 0x2c + param_1 * 4);
        DAT_00869ab4 = DAT_00869ab4 - *(int*)(unaff_EDI + 0x2c + param_1 * 4);
        *(uint32_t*)(unaff_EDI + 4) = 1;
    }
    if (unaff_BL != '\0') {
        *(uint32_t*)(unaff_EDI + 0x4c) = (uint32_t)DAT_008c8494;
    }
    return;
}

// 0x4e00d0 — observed shape
void FUN_004e00d0_recon(char in_AL, char unaff_BL, int unaff_EDI) {
    int* piVar1;
    uint8_t bVar2;
    uint32_t uVar3;
    uint32_t* puVar4;
    uint32_t uVar5;

    *(char*)(unaff_EDI + 0x58) = unaff_BL;
    if (in_AL != '\0') {
        FUN_004888e0(0x2d, 0xffffffffu, 0xffffffffu, 0xbf800000u);
    }
    piVar1 = *(int**)(unaff_EDI + 0xb4);
    if (piVar1 == nullptr) {
        uVar3 = 0;
    } else {
        puVar4 = (uint32_t*)(*(void* (**)(void))(intptr_t)(*piVar1 + 4))();
        while (puVar4 != nullptr) {
            if (puVar4 == (uint32_t*)&DAT_008ea09c) {
                bVar2 = 1;
                goto LAB_004e0120;
            }
            puVar4 = *(uint32_t**)((uint8_t*)puVar4 + 4);
        }
        bVar2 = 0;
LAB_004e0120:
        uVar3 = -(uint32_t)bVar2 & (uint32_t)(uintptr_t)piVar1;
    }
    uVar5 = (uint32_t)(unaff_BL != '\0');
    if (*(uint32_t*)(uVar3 + 0x290) != uVar5) {
        *(uint32_t*)(uVar3 + 0x290) = uVar5;
        FUN_00506040(*(uint32_t*)(uVar3 + 0x294 + uVar5 * 4), 0x3f800000, 0, 0, 0x3f800000);
    }
    piVar1 = *(int**)(unaff_EDI + 0xb8);
    if (piVar1 == nullptr) {
        uVar3 = 0;
    } else {
        puVar4 = (uint32_t*)(*(void* (**)(void))(intptr_t)(*piVar1 + 4))();
        while (puVar4 != nullptr) {
            if (puVar4 == (uint32_t*)&DAT_008ea09c) {
                bVar2 = 1;
                goto LAB_004e0190;
            }
            puVar4 = *(uint32_t**)((uint8_t*)puVar4 + 4);
        }
        bVar2 = 0;
LAB_004e0190:
        uVar3 = -(uint32_t)bVar2 & (uint32_t)(uintptr_t)piVar1;
    }
    uVar5 = (uint32_t)(unaff_BL == '\0');
    if (*(uint32_t*)(uVar3 + 0x290) != uVar5) {
        *(uint32_t*)(uVar3 + 0x290) = uVar5;
        FUN_00506040(*(uint32_t*)(uVar3 + 0x294 + uVar5 * 4), 0x3f800000, 0, 0, 0x3f800000);
    }
    if (unaff_BL == '\0') {
        FUN_004e0700();
    }
    return;
}

// 0x4e01e0 — observed shape
void FUN_004e01e0_recon(int* self) {
    char cVar1;
    int iVar2;

    iVar2 = self[0x12] + 1;
    switch (self[0x12]) {
    case 6:
        if (*self == 0) {
            iVar2 = FUN_004e0350();
            iVar2 = ((iVar2 < 1) - 1 & 0x11) + 1;
        } else {
            cVar1 = FUN_004e0880();
            if (cVar1 == '\0') {
                iVar2 = (self[0x15] == -1) + 0x14;
            } else {
                iVar2 = 0x13;
            }
        }
        break;
    case 0x13:
        iVar2 = ((self[0x15] == -1) - 1 & 0x13) + 1;
        break;
    case -1:
    case 0x12:
    case 0x15:
        self[0x12] = 1;
        goto LAB_004e0251;
    }
    self[0x12] = iVar2;
LAB_004e0251:
    FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xbf800000u,
                 0xffffffffu);
    return;
}
