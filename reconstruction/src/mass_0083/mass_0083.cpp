#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005071f0(void);
extern void FUN_005141c0(void);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void FUN_00502c80(void* self);
extern uint32_t thunk_FUN_00533c78(uint32_t size);
extern void FUN_00503040(void* self);
extern void* PTR_FUN_00710c40;

// 0x502b90 — observed shape
void FUN_00502b90(void* self, uint8_t param_1) {
    uint32_t** pSelf = (uint32_t**)self;
    *pSelf = (uint32_t*)PTR_FUN_00710c40;
    FUN_005071f0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x502c50 — observed shape
void FUN_00502c50(void* self, uint8_t param_1) {
    FUN_005141c0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x502c80 — observed shape
void FUN_00502c80(void* self) {
    uint32_t* base = (uint32_t*)self;
    uint32_t arr = base[0x12];
    if (arr != 0) {
        int32_t count = (int32_t)base[7];
        int32_t i = 0;
        if (count > 0) {
            do {
                void* item = *(void**)(arr + i * 4);
                if (item != nullptr) {
                    operator_delete__(item);
                    *(uint32_t*)(arr + i * 4) = 0;
                }
                i = i + 1;
            } while (i < count);
        }
        if (*(void**)self + 0x12 != nullptr) {
            // *(self+0x48) check
            operator_delete__(*(void**)((uint8_t*)self + 0x48));
            *(uint32_t*)((uint8_t*)self + 0x48) = 0;
        }
    }
}

// 0x502cd0 — observed shape
void FUN_00502cd0(void* self, int32_t in_EAX, uint32_t param_1, uint8_t param_2, uint8_t param_3,
                  uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7,
                  uint32_t param_8, uint32_t param_9, uint32_t param_10) {
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00502c80(self);
    in_ECX[0] = param_4;
    in_ECX[1] = param_5;
    in_ECX[3] = param_7;
    in_ECX[4] = param_8;
    in_ECX[2] = param_6;
    in_ECX[6] = param_10;
    in_ECX[8] = param_1;
    in_ECX[5] = param_9;
    in_ECX[9] = 0xffffffff;
    in_ECX[10] = 0xffffffff;
    in_ECX[0xb] = 0xffffffff;
    in_ECX[0xc] = 0xffffffff;
    in_ECX[7] = (uint32_t)in_EAX;
    in_ECX[0xd] = 0;
    *(uint8_t*)(in_ECX + 0xe) = param_2;
    *(uint8_t*)((uint8_t*)in_ECX + 0x39) = param_3;
    *(uint8_t*)((uint8_t*)in_ECX + 0x3a) = 0;
    *(uint8_t*)((uint8_t*)in_ECX + 0x3b) = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    uint32_t uVar1 = thunk_FUN_00533c78((uint32_t)in_EAX * 4);
    in_ECX[0x12] = uVar1;
    int32_t iVar5 = 0;
    if ((int32_t)in_ECX[7] > 0) {
        do {
            int32_t iVar4 = (int32_t)in_ECX[8];
            int32_t iVar2 = (int32_t)thunk_FUN_00533c78((uint32_t)(iVar4 * 0x28));
            if (iVar2 != 0 && iVar4 - 1 >= 0) {
                uint32_t* puVar3 = (uint32_t*)(iVar2 + 8);
                do {
                    puVar3[-2] = 0xffffffff;
                    puVar3[-1] = 0xffffffff;
                    puVar3[0] = 0;
                    puVar3[1] = 0;
                    puVar3[2] = 0;
                    puVar3[3] = 0;
                    puVar3[4] = 0;
                    puVar3[5] = 0xffffffff;
                    puVar3[6] = 0;
                    puVar3[7] = 0;
                    puVar3 = puVar3 + 10;
                    iVar4 = iVar4 - 1;
                } while (iVar4 != 0);
            }
            *(int32_t*)(in_ECX[0x12] + iVar5 * 4) = iVar2;
            iVar4 = 0;
            if ((int32_t)in_ECX[8] > 0) {
                int32_t off = 0;
                do {
                    *(int32_t*)(off + *(int32_t*)(in_ECX[0x12] + iVar5 * 4)) = iVar5;
                    *(int32_t*)(*(int32_t*)(in_ECX[0x12] + iVar5 * 4) + 4 + off) = iVar4;
                    iVar4 = iVar4 + 1;
                    off = off + 0x28;
                } while (iVar4 < (int32_t)in_ECX[8]);
            }
            iVar5 = iVar5 + 1;
        } while (iVar5 < (int32_t)in_ECX[7]);
    }
}

// 0x502e10 — observed shape
uint32_t FUN_00502e10(void* self, int32_t param_1, uint32_t param_2, uint32_t param_3,
                      int8_t param_4, int32_t param_5, int8_t param_6, int32_t in_EAX) {
    // Ghidra pseudocode uses unaff_ESI as self register
    uint32_t* unaff_ESI = (uint32_t*)self;
    int32_t* piVar4 = (int32_t*)in_EAX;
    uint32_t result = 0;
    if (param_1 >= 0 && param_1 < (int32_t)unaff_ESI[7] && in_EAX >= 0 &&
        in_EAX < (int32_t)unaff_ESI[8]) {
        if (*(void**)unaff_ESI != nullptr) {
            int32_t (*fn)() = *(int32_t(**)())unaff_ESI;
            int32_t ret = fn(param_2, param_3, unaff_ESI[6]);
            piVar4 = nullptr;
            if (ret == 0) {
                goto LAB_0050302f;
            }
        }
        unaff_ESI[0xb] = param_2;
        unaff_ESI[0xc] = param_3;
        if (param_6 == 0 || *(int8_t*)((uint8_t*)unaff_ESI + 0x3b) != 0 ||
            unaff_ESI[9] != (uint32_t)param_1 ||
            (int32_t*)unaff_ESI[10] != piVar4 ||
            *(int8_t*)((uint8_t*)unaff_ESI + 0x3a) != param_4 ||
            unaff_ESI[0xd] != (uint32_t)param_5) {
            uint32_t node = unaff_ESI[0xf];
            while (node != 0) {
                uint32_t nxt = *(uint32_t*)(node + 0x24);
                *(uint32_t*)(node + 8) = 0;
                *(uint32_t*)(node + 0xc) = 0;
                *(uint32_t*)(node + 0x10) = 0;
                *(uint32_t*)(node + 0x14) = 0;
                *(uint32_t*)(node + 0x18) = 0;
                *(uint32_t*)(node + 0x1c) = 0xffffffff;
                *(uint32_t*)(node + 0x20) = 0;
                *(uint32_t*)(node + 0x24) = 0;
                unaff_ESI[0xf] = nxt;
                node = nxt;
            }
            node = unaff_ESI[0x10];
            while (node != 0) {
                uint32_t nxt = *(uint32_t*)(node + 0x24);
                *(uint32_t*)(node + 8) = 0;
                *(uint32_t*)(node + 0xc) = 0;
                *(uint32_t*)(node + 0x10) = 0;
                *(uint32_t*)(node + 0x14) = 0;
                *(uint32_t*)(node + 0x18) = 0;
                *(uint32_t*)(node + 0x1c) = 0xffffffff;
                *(uint32_t*)(node + 0x20) = 0;
                *(uint32_t*)(node + 0x24) = 0;
                unaff_ESI[0x10] = nxt;
                node = nxt;
            }
            *(int8_t*)((uint8_t*)unaff_ESI + 0x3a) = param_4;
            unaff_ESI[0xd] = (uint32_t)param_5;
            unaff_ESI[10] = (uint32_t)in_EAX;
            unaff_ESI[0x11] = 0;
            unaff_ESI[9] = (uint32_t)param_1;
            *(uint8_t*)((uint8_t*)unaff_ESI + 0x3b) = 0;
            uint32_t cell = *(uint32_t*)(unaff_ESI[0x12] + param_1 * 4) + (uint32_t)in_EAX * 0x28;
            *(uint32_t*)(cell + 0xc) = 0;
            if (*(void**)((uint8_t*)unaff_ESI + 4) == nullptr) {
                *(uint32_t*)(cell + 0x10) = 0;
            } else {
                uint32_t (*fn2)(uint32_t,uint32_t,uint32_t,uint32_t) =
                    *(uint32_t(**)(uint32_t,uint32_t,uint32_t,uint32_t))((uint8_t*)unaff_ESI + 4);
                uint32_t v = fn2(unaff_ESI[9], unaff_ESI[10], unaff_ESI[0xb], unaff_ESI[0xc]);
                *(uint32_t*)(cell + 0x10) = v;
            }
            *(int32_t*)(cell + 8) = (int32_t)(*(uint32_t*)(cell + 0xc) + *(uint32_t*)(cell + 0x10));
            unaff_ESI[0xf] = cell;
            if (unaff_ESI[5] != 0) {
                void (*fn5)(int,uint32_t,int,uint32_t) = *(void(**)(int,uint32_t,int,uint32_t))((uint8_t*)unaff_ESI + 0x14);
                fn5(0, cell, 1, unaff_ESI[6]);
            }
            if (unaff_ESI[4] != 0) {
                void (*fn4)(int,uint32_t,int,uint32_t) = *(void(**)(int,uint32_t,int,uint32_t))((uint8_t*)unaff_ESI + 0x10);
                fn4(0, cell, 0, unaff_ESI[6]);
            }
        }
        int32_t idx2 = (int32_t)unaff_ESI[0xb];
        int32_t* p2 = (int32_t*)unaff_ESI[0xc];
        if (idx2 >= 0 && idx2 < (int32_t)unaff_ESI[7] && (int32_t)p2 >= 0 &&
            (int32_t)p2 < (int32_t)unaff_ESI[8] &&
            (p2 = (int32_t*)(*(uint32_t*)(unaff_ESI[0x12] + idx2 * 4) + (uint32_t)(int32_t)p2 * 0x28),
             p2[7] == 1)) {
            unaff_ESI[0x11] = (uint32_t)p2;
            return ((uint32_t)(p2) >> 8) | 1;
        }
        while (true) {
            uint32_t cur = unaff_ESI[0xf];
            if (cur == 0) {
                cur = 0;
            } else {
                uint32_t prev = unaff_ESI[0x10];
                unaff_ESI[0xf] = *(uint32_t*)(cur + 0x24);
                if (unaff_ESI[5] != 0) {
                    void (*fn5)(int,uint32_t,int,uint32_t) =
                        *(void(**)(int,uint32_t,int,uint32_t))((uint8_t*)unaff_ESI + 0x14);
                    fn5(0, cur, 2, unaff_ESI[6]);
                }
                *(uint32_t*)(cur + 0x1c) = 1;
                unaff_ESI[0x10] = cur;
                *(uint32_t*)(cur + 0x24) = prev;
                piVar4 = nullptr;
                if (unaff_ESI[5] != 0) {
                    uint32_t (*fn5r)(int,uint32_t,int,uint32_t) =
                        *(uint32_t(**)(int,uint32_t,int,uint32_t))((uint8_t*)unaff_ESI + 0x14);
                    piVar4 = (int32_t*)fn5r(0, unaff_ESI[0x10], 3, unaff_ESI[6]);
                }
            }
            unaff_ESI[0x11] = cur;
            if (cur == 0) break;
            FUN_00503040(self);
            int32_t* cell = (int32_t*)unaff_ESI[0x11];
            if (unaff_ESI[0xb] == (uint32_t)cell[0] && unaff_ESI[0xc] == (uint32_t)cell[1]) {
                return ((uint32_t)cell >> 8) | 1;
            }
        }
    }
LAB_0050302f:
    result = (uint32_t)piVar4 & 0xffffff00;
    return result;
}
extern void FUN_00503120(void* self, void* esi, void* edi, void* ebx, int32_t iVar3, int32_t iVar4);
extern void FUN_005031e0(void* self, void* node);
extern void FUN_00506e60(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, void* self);
extern void FUN_005039e0(void* self, uint32_t a, uint32_t b);
extern uint32_t FUN_00507c00(void* self);
extern void FUN_0050c4d0(void* self);
extern void* PTR_FUN_00710dd0;
extern void* PTR_FUN_007116a0;
extern int32_t DAT_0072734c[];
extern int32_t DAT_0072732c[];

// 0x503040 — observed shape
void FUN_00503040(void* self, int32_t in_EAX) {
    // no void* self2
    int32_t in_ECX = (int32_t)self;
    uint32_t uVar2 = (*(int8_t*)(in_ECX + 0x3a) == 0) ? 1 : 0;
    int32_t iVar5 = 0;
    if (uVar2 != 0x3fffffff) {
        do {
            int32_t iVar3 = DAT_0072734c[iVar5] + *(int32_t*)in_EAX;
            if (*(int8_t*)(in_ECX + 0x38) != 0) {
                if (iVar3 < 0) {
                    iVar3 = iVar3 % *(int32_t*)(in_ECX + 0x1c) + *(int32_t*)(in_ECX + 0x1c);
                } else if (*(int32_t*)(in_ECX + 0x1c) <= iVar3) {
                    iVar3 = iVar3 % *(int32_t*)(in_ECX + 0x1c);
                }
            }
            int32_t iVar4 = DAT_0072732c[iVar5] + *((int32_t*)in_EAX + 1);
            if (*(int8_t*)(in_ECX + 0x39) != 0) {
                int32_t lim = *(int32_t*)(in_ECX + 0x20);
                if (iVar4 < 0) {
                    iVar4 = iVar4 % lim + lim;
                } else if (lim <= iVar4) {
                    iVar4 = iVar4 % lim;
                }
            }
            if (iVar3 >= 0 && iVar3 < *(int32_t*)(in_ECX + 0x1c) && iVar4 >= 0 &&
                iVar4 < *(int32_t*)(in_ECX + 0x20) &&
                (*(void**)(in_ECX + 0xc) == nullptr ||
                 (iVar3 = (*(int32_t(*)())*(void**)(in_ECX + 0xc))(), iVar3 != 0))) {
                FUN_00503120(self, nullptr, nullptr, nullptr, iVar3, iVar4);
            }
            iVar5 = iVar5 + 1;
        } while (iVar5 < (int32_t)(uVar2 * 4 + 4));
    }
}

// 0x503120 — observed shape
void FUN_00503120(void* self, void* esi, void* edi, void* ebx) {
    uint32_t* unaff_ESI = (uint32_t*)esi;
    uint32_t unaff_EDI = (uint32_t)edi;
    uint32_t unaff_EBX = (uint32_t)ebx;
    uint32_t uVar3 = unaff_ESI[1];
    uint32_t uVar1 = unaff_ESI[0];
    int32_t iVar2;
    if (*(void**)(unaff_EDI + 8) == nullptr) {
        iVar2 = 1;
    } else {
        iVar2 = (*(int32_t(*)())*(void**)(unaff_EDI + 8))();
    }
    iVar2 = *(int32_t*)(unaff_EBX + 0xc) + iVar2;
    if (unaff_ESI[7] == 0) {
        if (iVar2 < (int32_t)unaff_ESI[3]) {
            unaff_ESI[8] = unaff_EBX;
            unaff_ESI[3] = (uint32_t)iVar2;
            unaff_ESI[2] = unaff_ESI[4] + (uint32_t)iVar2;
            if (*(void**)(unaff_EDI + 0x10) != nullptr) {
                (*(void(*)())*(void**)(unaff_EDI + 0x10))();
                return;
            }
        }
    } else if (unaff_ESI[7] == (uint32_t)-1) {
        unaff_ESI[8] = unaff_EBX;
        unaff_ESI[3] = (uint32_t)iVar2;
        if (*(void**)(unaff_EDI + 4) == nullptr) {
            unaff_ESI[4] = 0;
        } else {
            uint32_t (*fn)(uint32_t,uint32_t,uint32_t,uint32_t) =
                *(uint32_t(**)(uint32_t,uint32_t,uint32_t,uint32_t))(unaff_EDI + 4);
            uVar3 = fn(*(uint32_t*)(unaff_EDI + 0x2c), *(uint32_t*)(unaff_EDI + 0x30), uVar1, uVar3);
            unaff_ESI[4] = uVar3;
        }
        unaff_ESI[2] = unaff_ESI[4] + unaff_ESI[3];
        FUN_005031e0(self, (void*)unaff_EBX);
        if (*(void**)(unaff_EDI + 0x10) != nullptr) {
            (*(void(*)())*(void**)(unaff_EDI + 0x10))();
        }
    }
}

// 0x5031e0 — observed shape
void FUN_005031e0(void* self, void* node) {
    int32_t in_EAX = (int32_t)node;
    int32_t in_ECX = (int32_t)self;
    *(uint32_t*)(in_EAX + 0x1c) = 0;
    int32_t head = *(int32_t*)(in_ECX + 0x3c);
    if (head == 0) {
        *(int32_t*)(in_ECX + 0x3c) = in_EAX;
        *(uint32_t*)(in_EAX + 0x24) = 0;
        if (*(void**)(in_ECX + 0x14) != nullptr) {
            (*(void(*)(int))*(void**)(in_ECX + 0x14))(0);
            return;
        }
    } else {
        int32_t cur = head;
        int32_t prev = 0;
        do {
            int32_t nxt = cur;
            if (*(int32_t*)(in_EAX + 8) <= *(int32_t*)(nxt + 8)) {
                if (prev == 0) {
                    *(int32_t*)(in_EAX + 0x24) = head;
                    *(int32_t*)(in_ECX + 0x3c) = in_EAX;
                    if (*(void**)(in_ECX + 0x14) == nullptr) {
                        return;
                    }
                    (*(void(*)(uint32_t))*(void**)(in_ECX + 0x14))(*(uint32_t*)(in_EAX + 0x24));
                    return;
                }
                *(int32_t*)(prev + 0x24) = in_EAX;
                *(int32_t*)(in_EAX + 0x24) = nxt;
                goto LAB_00503226;
            }
            int32_t nn = *(int32_t*)(nxt + 0x24);
            prev = nxt;
            cur = nn;
        } while (*(int32_t*)(nxt + 0x24) != 0);
        *(int32_t*)(nxt + 0x24) = in_EAX;
LAB_00503226:
        if (*(void**)(in_ECX + 0x14) != nullptr) {
            (*(void(*)(int32_t))*(void**)(in_ECX + 0x14))(prev);
        }
    }
}

// 0x503270 — observed shape
void FUN_00503270(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8,
                  float param_9, float param_10, uint32_t param_11, uint32_t param_12, uint8_t param_13) {
    uint32_t* unaff_EBX = (uint32_t*)self;
    float local_4 = param_9 * 0.5f;
    float local_c = param_10 * 0.5f;
    float local_10 = param_10 * -0.5f;
    float local_8 = param_9 * -0.5f;
    float local_24 = 0.0f;
    float fStack_18 = 0.0f;
    float fStack_14 = 0.0f;
    uint32_t local_28 = 0;
    uint32_t local_20 = 0;
    FUN_00506e60(param_1, 0, param_6, param_7, param_8, 0x3f800000, param_12);
    unaff_EBX[0] = (uint32_t)PTR_FUN_00710dd0;
    *(uint8_t*)(unaff_EBX + 0xa7) = param_13;
    FUN_005039e0(self, param_2, param_11);
    uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(0x2b4);
    if (puVar1 != nullptr) {
        FUN_00506e60(0, param_3, 0, 0, 0, 0x3f800000, (uint32_t)self);
        puVar1[0] = (uint32_t)PTR_FUN_00710c40;
        *(uint8_t*)(puVar1 + 0xac) = 0;
        puVar1[0xa4] = 1;
        puVar1[0xa5] = 1;
    }
    unaff_EBX[0xa6] = (uint32_t)puVar1;
    puVar1 = (uint32_t*)thunk_FUN_00533c78(0x290);
    if (puVar1 != nullptr) {
        FUN_00506e60(0, param_4, 0, 0, 0, 0x3f800000, (uint32_t)self);
        puVar1[0] = (uint32_t)PTR_FUN_007116a0;
    }
    unaff_EBX[0xa4] = (uint32_t)puVar1;
    puVar1 = (uint32_t*)thunk_FUN_00533c78(0x290);
    if (puVar1 != nullptr) {
        FUN_00506e60(0, param_5, 0, 0, 0, 0x3f800000, (uint32_t)self);
        puVar1[0] = (uint32_t)PTR_FUN_007116a0;
    }
    unaff_EBX[0xa5] = (uint32_t)puVar1;
    if (*(uint8_t*)(unaff_EBX + 0xa7) == 0) {
        local_24 = 0.0f;
        local_4 = 0.1f;
        local_8 = 0.1f;
        local_28 = (uint32_t)(param_10 * -0.5f);
        {
            uint32_t obj = unaff_EBX[0xa4];
            void (*fn)(uint32_t*) = *(void(**)(uint32_t*))(*(uint32_t*)obj + 0x98);
            fn(&local_28);
        }
        {
            uint32_t obj = unaff_EBX[0xa5];
            void (*fn)(uint32_t*) = *(void(**)(uint32_t*))(*(uint32_t*)obj + 0x98);
            uint32_t arg = 0;
            fn(&arg);
        }
        float* pf = (float*)FUN_00507c00((void*)unaff_EBX[0xa4]);
        fStack_18 = fStack_18 - (pf[0] - pf[3] < 0 ? -(pf[0] - pf[3]) : (pf[0] - pf[3])) * 0.5f;
        pf = (float*)FUN_00507c00((void*)unaff_EBX[0xa5]);
        fStack_14 = (pf[0] - pf[3] < 0 ? -(pf[0] - pf[3]) : (pf[0] - pf[3])) * 0.5f + fStack_14;
    } else {
        local_28 = 0;
        local_c = 0.0f;
        local_10 = 0.0f;
        local_24 = param_9 * -0.5f;
        {
            uint32_t obj = unaff_EBX[0xa4];
            void (*fn)(uint32_t*) = *(void(**)(uint32_t*))(*(uint32_t*)obj + 0xa4);
            fn(&local_28);
        }
        local_28 = (uint32_t)param_8;
        local_24 = 0.0f;
        {
            uint32_t obj = unaff_EBX[0xa5];
            void (*fn)(uint32_t*) = *(void(**)(uint32_t*))(*(uint32_t*)obj + 0xa4);
            uint32_t arg = 0;
            fn(&arg);
        }
        uint32_t iVar2 = FUN_00507c00((void*)unaff_EBX[0xa4]);
        float d = *(float*)(iVar2 + 4) - *(float*)(iVar2 + 0x10);
        local_10 = (d < 0 ? -d : d) * 0.5f + local_10;
        iVar2 = FUN_00507c00((void*)unaff_EBX[0xa4]);
        d = *(float*)(iVar2 + 4) - *(float*)(iVar2 + 0x10);
        local_c = local_c - (d < 0 ? -d : d) * 0.5f;
    }
    (void)local_20;
    (void)local_4; (void)local_c; (void)local_10; (void)local_8; (void)local_24;
    (void)fStack_18; (void)fStack_14;
    FUN_0050c4d0(self);
}

// 0x503730 — observed shape
void FUN_00503730(void* self, int32_t in_EAX) {
    int32_t in_ECX = (int32_t)self;
    int32_t iVar1 = *(int32_t*)(in_ECX + 0x298);
    if (*(int8_t*)(in_ECX + 0x29c) == 0) {
        *(int32_t*)(iVar1 + 0x290) = in_EAX;
        *(uint32_t*)(iVar1 + 0x294) = 0;
        if (in_EAX == 0) {
            *(uint32_t*)(iVar1 + 0x290) = 1;
        }
        *(uint32_t*)(iVar1 + 0x294) = 1;
    } else {
        *(int32_t*)(iVar1 + 0x294) = in_EAX;
        *(uint32_t*)(iVar1 + 0x290) = 1;
        if (in_EAX == 0) {
            *(uint32_t*)(iVar1 + 0x294) = 1;
            return;
        }
    }
}

extern int32_t FUN_005f0ddc(void);
extern void FUN_0050c550(int32_t v);
extern void FUN_0050c5d0(int32_t v);
extern void FUN_0050c6d0(float v);
extern void FUN_0050c740(float v);
extern void* FUN_00500850(void);
extern uint32_t FUN_00533c78(uint32_t size);
extern void FUN_005235c0(void* rect, int32_t zero, void* obj);
extern void FUN_00507c90(void* p);
extern void FUN_00545cc0(void);
extern void FUN_00507d20(void* p);
extern void FUN_004ff360(float v);
extern void FUN_004ff450(void);
extern void FUN_004cce40(void);
extern void FUN_004ff6b0(uint32_t v);
extern void FUN_0054b970(void);
extern void FUN_0054aa00(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e,
                         uint32_t f, int32_t g);
extern void FUN_00533d10(uint32_t a, uint32_t b);
extern void FUN_00504910(void);
extern void FUN_00504950(void);
extern void FUN_00524e90(void* p);
extern uint32_t* DAT_008ea08c;
extern void* PTR_FUN_007111dc;
extern void* PTR_FUN_007111d0;
extern void* PTR_FUN_007111e8;
extern void* PTR_FUN_00711204;
extern void* PTR_FUN_00712bf8;
extern void* PTR_FUN_00712bf4;
extern uint32_t DAT_008ca4e4;
extern uint32_t DAT_008ca4e8;
extern uint32_t DAT_008ca4ec;
extern uint32_t DAT_008ca4f0;
extern uint8_t DAT_008ea0a4;

// 0x503780 — observed shape
void FUN_00503780(void* self) {
    int32_t base = (int32_t)self;
    int32_t iVar1;
    if (*(int8_t*)(base + 0x29c) == 0) {
        iVar1 = FUN_005f0ddc();
        FUN_0050c550(iVar1 + 1);
        return;
    }
    iVar1 = FUN_005f0ddc();
    FUN_0050c5d0(iVar1 + 1);
}

// 0x5037e0 — observed shape
void FUN_005037e0(void* self) {
    int32_t base = (int32_t)self;
    int32_t iVar1;
    if (*(int8_t*)(base + 0x29c) == 0) {
        iVar1 = FUN_005f0ddc();
        FUN_0050c550(iVar1 + -1);
        return;
    }
    iVar1 = FUN_005f0ddc();
    FUN_0050c5d0(iVar1 + -1);
}

// 0x503840 — observed shape
void FUN_00503840(void* self) {
    int32_t base = (int32_t)self;
    // Both paths issue the same side-effecting query; the branch only records
    // which display mode is active.
    if (*(int8_t*)(base + 0x29c) == 0) {
        FUN_005f0ddc();
        return;
    }
    FUN_005f0ddc();
}

// 0x503890 — observed shape
void FUN_00503890(void* self, int32_t param_1, int32_t param_2) {
    int32_t base = (int32_t)self;
    float fVar1;
    float fVar2;
    float d;
    int32_t iVar3;
    if (*(int8_t*)(base + 0x29c) == 0) {
        float* pfVar4 = (float*)FUN_00507c00(self);
        fVar1 = pfVar4[0];
        fVar2 = pfVar4[3];
        iVar3 = (*(int32_t(*)())((uint8_t*)DAT_008ea08c + 0x58))();
        d = fVar1 - fVar2;
        if (d < 0.0f) d = -d;
        FUN_0050c6d0(((float)param_1 / (float)iVar3) * 1024.0f -
                     (*(float*)(base + 0x5c) - d * 0.5f));
        return;
    }
    int32_t iVar3b = (int32_t)FUN_00507c00(self);
    fVar1 = *(float*)(iVar3b + 4);
    fVar2 = *(float*)(iVar3b + 0x10);
    iVar3 = (*(int32_t(*)())((uint8_t*)DAT_008ea08c + 0x5c))();
    d = fVar1 - fVar2;
    if (d < 0.0f) d = -d;
    FUN_0050c740(((float)param_2 / (float)iVar3) * 768.0f -
                 (-*(float*)(base + 100) - d * 0.5f));
}

// 0x5039e0 — observed shape
// param_1 of the listing is the owning object (register receiver), the EDI
// register held a 4-float rectangle, and the arguments arrive as
// (int x, float, float).
void FUN_005039e0_recon(void* self, float param_2, float param_3, float* rect) {
    int32_t base = (int32_t)self;
    float fStack_14 = 0.0f;
    // stack block &local_10 spans low-to-high addresses: box[0]=local_10,
    // box[1]=fStack_c, box[2]=fStack_8, box[3]=fStack_4.
    float box[4];
    int32_t iVar2;
    int32_t iVar3;

    if (param_3 < 0.0f) {
        int32_t* piVar1 = (int32_t*)FUN_00500850();
        iVar2 = (*(int32_t(*)())((uint8_t*)*piVar1 + 0x38))();
        param_2 = (float)iVar2;
        if (iVar2 < 0) {
            param_2 = param_2 + 4294967296.0f;
        }
        iVar2 = (*(int32_t(*)())((uint8_t*)*piVar1 + 0x34))();
        fStack_14 = (float)iVar2;
        if (iVar2 < 0) {
            fStack_14 = fStack_14 + 4294967296.0f;
        }
    }
    if (*(int8_t*)(base + 0x29c) == 0) {
        if (param_3 < 0.0f) {
            param_3 = fStack_14;
        }
        box[3] = rect[2];
        box[2] = rect[3];
        param_2 = 0.0f;
        iVar2 = FUN_005f0ddc();
        if (0 < iVar2) {
            do {
                box[0] = (float)(int)param_2 * param_3 + rect[0];
                box[1] = box[0] + param_3;
                iVar3 = (int32_t)FUN_00533c78(0x2c4);
                if (iVar3 != 0) {
                    FUN_005235c0(box, 0, self);
                }
                param_2 = (float)((int)param_2 + 1);
            } while ((int)param_2 < iVar2);
        }
        box[1] = rect[1];
        box[0] = rect[1] - param_3;
    } else {
        if (param_3 < 0.0f) {
            param_3 = param_2;
        }
        box[0] = rect[0];
        box[1] = rect[1];
        param_2 = 0.0f;
        iVar2 = FUN_005f0ddc();
        if (0 < iVar2) {
            do {
                box[3] = (float)(int)param_2 * param_3 + rect[2];
                box[2] = box[3] + param_3;
                iVar3 = (int32_t)FUN_00533c78(0x2c4);
                if (iVar3 != 0) {
                    FUN_005235c0(box, 0, self);
                }
                param_2 = (float)((int)param_2 + 1);
            } while ((int)param_2 < iVar2);
        }
        box[3] = rect[3];
        box[2] = rect[3] - param_3;
    }
    iVar2 = (int32_t)FUN_00533c78(0x2c4);
    if (iVar2 != 0) {
        FUN_005235c0(box, 0, self);
    }
}

// 0x503bc0 — observed shape
void FUN_00503bc0(void* param_1) {
    int32_t iVar1 = (int32_t)param_1;
    void* tmp = param_1;
    FUN_00507c90(param_1);
    int32_t obj = *(int32_t*)(iVar1 + 0x15c);
    uint32_t vtbl = *(uint32_t*)obj;
    (*(void(**)(void*, int32_t))(vtbl + 8))(&tmp, 4);
    FUN_00545cc0();
    FUN_00545cc0();
    FUN_00545cc0();
}

// 0x503c00 — observed shape
void FUN_00503c00(void* self, void* param_1) {
    int32_t base = (int32_t)self;
    int32_t* piVar1 = (int32_t*)param_1;
    uint32_t one = 0x3f800000u;
    FUN_00507d20(param_1);
    uint32_t vt58 = *(uint32_t*)piVar1[0x58];
    (*(void(**)(void*, int32_t))(vt58 + 0xc))(&one, 4);
    uint32_t vtSelf = (uint32_t)*piVar1;
    (*(void(**)(uint32_t))(vtSelf + 0x2c))(*(uint32_t*)(base + 0x298));
    (*(void(**)(uint32_t))(vtSelf + 0x2c))(*(uint32_t*)(base + 0x290));
    (*(void(**)(uint32_t))(vtSelf + 0x2c))(*(uint32_t*)(base + 0x294));
}

// 0x503ca0 — observed shape
void FUN_00503ca0(void* self) {
    int32_t* unaff_ESI = (int32_t*)self;
    int32_t* piVar1;
    int32_t iVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    uint32_t uVar5;

    *unaff_ESI = 0;
    unaff_ESI[1] = 0;
    unaff_ESI[0xb] = 0;
    unaff_ESI[9] = 0;
    unaff_ESI[10] = 0;
    unaff_ESI[8] = (int32_t)(uintptr_t)&PTR_FUN_007111dc;
    unaff_ESI[0xf] = 0;
    unaff_ESI[0xd] = 0;
    unaff_ESI[0xe] = 0;
    unaff_ESI[0xc] = (int32_t)(uintptr_t)&PTR_FUN_007111d0;
    unaff_ESI[0x13] = 0;
    unaff_ESI[2] = 0;
    unaff_ESI[3] = 0;
    unaff_ESI[4] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    FUN_0054aa00(0xbf000000u, 0x3f000000u, 0x3ec00000u, 0xbec00000u, 0x44666666u,
                 0x44c00000u, 0);

    iVar2 = (int32_t)FUN_00533c78(0x290);
    if (iVar2 == 0) {
        puVar3 = (uint32_t*)0x0;
    } else {
        puVar3 = (uint32_t*)FUN_00506e60((uint32_t)(uintptr_t)"FullScreen", 0, 0, 0, 0,
                                         0x3f800000u, 0);
    }
    puVar4 = (uint32_t*)unaff_ESI[1];
    if (puVar4 != puVar3) {
        if (puVar4 != (uint32_t*)0x0) {
            piVar1 = (int32_t*)(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void(**)(int32_t))(*puVar4))(1);
            }
        }
        unaff_ESI[1] = (int32_t)puVar3;
        if (puVar3 != (uint32_t*)0x0) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    (*(void(**)(uint32_t, uint32_t, int32_t))(*(uint32_t*)unaff_ESI[1] + 0xa0))(
        0xc4000000u, 0xc3c00000u, 0);
    FUN_00533d10(0, 1);

    iVar2 = (int32_t)FUN_00533c78(0x238);
    if (iVar2 == 0) {
        puVar3 = (uint32_t*)0x0;
    } else {
        puVar3 = (uint32_t*)FUN_004ff360(0x42340000u);
    }
    puVar4 = (uint32_t*)*unaff_ESI;
    if (puVar4 != puVar3) {
        if (puVar4 != (uint32_t*)0x0) {
            piVar1 = (int32_t*)(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void(**)(int32_t))(*puVar4))(1);
            }
        }
        *unaff_ESI = (int32_t)puVar3;
        if (puVar3 != (uint32_t*)0x0) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    FUN_004ff450();
    FUN_004cce40();
    iVar2 = *unaff_ESI;
    *(uint32_t*)(iVar2 + 0x5c) = 0;
    *(uint32_t*)(iVar2 + 0x60) = 0xc4800000u;
    *(uint32_t*)(iVar2 + 100) = 0;
    FUN_004ff6b0(0);

    puVar3 = (uint32_t*)FUN_00533c78(0x14);
    if (puVar3 == (uint32_t*)0x0) {
        puVar3 = (uint32_t*)0x0;
    } else {
        *puVar3 = (uint32_t)(uintptr_t)&PTR_FUN_00711204;
        puVar3[1] = 0x25;
        puVar3[3] = 0;
        puVar4 = (uint32_t*)thunk_FUN_00533c78(0x94);
        puVar3[2] = (uint32_t)(uintptr_t)puVar4;
        for (uVar5 = puVar3[1] & 0x3fffffffu; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        // The byte-tail of the zero-fill is empty: 0x25 dwords cover 0x94 bytes.
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(uint8_t*)puVar4 = 0;
            puVar4 = (uint32_t*)((int32_t)puVar4 + 1);
        }
        *(uint8_t*)(puVar3 + 4) = 1;
        *puVar3 = (uint32_t)(uintptr_t)&PTR_FUN_007111e8;
    }
    unaff_ESI[7] = (int32_t)(uintptr_t)puVar3;
    unaff_ESI[0x10] = 0;
    unaff_ESI[0x11] = 0;
    unaff_ESI[0x12] = 0;
    DAT_008ca4e4 = 0;
    DAT_008ca4ec = 0;
    DAT_008ca4e8 = 0;
    DAT_008ca4f0 = 0;

    puVar3 = (uint32_t*)FUN_00533c78(0x54);
    if (puVar3 == (uint32_t*)0x0) {
        puVar3 = (uint32_t*)0x0;
    } else {
        FUN_0054b970();
        *puVar3 = (uint32_t)(uintptr_t)&PTR_FUN_00712bf8;
        puVar3[0x10] = 0;
        puVar3[0x13] = 1;
        puVar3[0x11] = 0;
        puVar3[0x12] = 0;
        puVar3[0xf] = 0;
        puVar3[0xe] = (uint32_t)(uintptr_t)&PTR_FUN_00712bf4;
        puVar3[0x14] = 0;
    }
    puVar4 = (uint32_t*)unaff_ESI[0x13];
    if (puVar4 != puVar3) {
        if (puVar4 != (uint32_t*)0x0) {
            piVar1 = (int32_t*)(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void(**)(int32_t))(*puVar4))(1);
            }
        }
        unaff_ESI[0x13] = (int32_t)(uintptr_t)puVar3;
        if (puVar3 != (uint32_t*)0x0) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x503ef0 — observed shape
void FUN_00503ef0(void* self) {
    int32_t* unaff_ESI = (int32_t*)self;
    int32_t* piVar1;
    uint32_t* puVar2;
    int32_t iVar3;

    if ((uint32_t*)unaff_ESI[7] != (uint32_t*)0x0) {
        (*(void(**)(int32_t))*(uint32_t*)unaff_ESI[7])(1);
        unaff_ESI[7] = 0;
    }
    puVar2 = (uint32_t*)unaff_ESI[1];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int32_t))(*puVar2))(1);
        }
        unaff_ESI[1] = 0;
    }
    puVar2 = (uint32_t*)*unaff_ESI;
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int32_t))(*puVar2))(1);
        }
        *unaff_ESI = 0;
    }
    iVar3 = unaff_ESI[0x12];
    if (iVar3 != 0) {
        puVar2 = *(uint32_t**)(iVar3 + 0x154);
        if (puVar2 != (uint32_t*)0x0) {
            piVar1 = (int32_t*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void(**)(int32_t))(*puVar2))(1);
            }
            *(uint32_t*)(iVar3 + 0x154) = 0;
        }
        if ((uint32_t*)unaff_ESI[0x11] != (uint32_t*)0x0) {
            (*(void(**)(int32_t))*(uint32_t*)unaff_ESI[0x11])(1);
            unaff_ESI[0x11] = 0;
        }
        unaff_ESI[0x12] = 0;
    }
    puVar2 = (uint32_t*)unaff_ESI[0x13];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int32_t))(*puVar2))(1);
        }
    }
    FUN_00504910();
    FUN_00504950();
    puVar2 = (uint32_t*)unaff_ESI[1];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int32_t))(*puVar2))(1);
        }
    }
    puVar2 = (uint32_t*)*unaff_ESI;
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int32_t))(*puVar2))(1);
        }
    }
}

// 0x503fb0 — observed shape
void FUN_00503fb0(void* self, int32_t* param_1) {
    int32_t in_ECX = (int32_t)self;
    uint32_t* puVar3;
    int32_t* piVar1;
    void* puVar2;
    uint32_t uVar4 = 0;

    if (param_1[0x30] != 0) {
        do {
            piVar1 = *(int32_t**)(param_1[0x2e] + uVar4 * 4);
            if (piVar1 != (int32_t*)0x0) {
                for (puVar2 = (*(void*(*)())((uint8_t*)*piVar1 + 4))(); puVar2 != (void*)0x0;
                     puVar2 = *(void**)((uint8_t*)puVar2 + 4)) {
                    if (puVar2 == (void*)&DAT_008ea0a4) {
                        FUN_00503fb0(self, piVar1);
                        break;
                    }
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < (uint32_t)param_1[0x30]);
    }
    FUN_00524e90(param_1);
    param_1[0x3f] = in_ECX;
    if (param_1[0x3e] != 0) {
        int32_t obj = *(int32_t*)(in_ECX + 0x20);
        uint32_t vtbl = *(uint32_t*)obj;
        puVar3 = (uint32_t*)(*(void*(*)())(vtbl + 4))();
        puVar3[2] = (uint32_t)param_1[0x3e];
        *puVar3 = 0;
        puVar3[1] = *(uint32_t*)(in_ECX + 0x28);
        if (*(void**)(in_ECX + 0x28) == (void*)0x0) {
            *(uint32_t**)(in_ECX + 0x24) = puVar3;
        } else {
            **(uint32_t**)(in_ECX + 0x28) = (uint32_t)(uintptr_t)puVar3;
        }
        *(uint32_t**)(in_ECX + 0x28) = puVar3;
        *(int32_t*)(in_ECX + 0x2c) = *(int32_t*)(in_ECX + 0x2c) + 1;
    }
    (*(void(*)())(*(uint32_t*)param_1 + 0xc0))();
}
