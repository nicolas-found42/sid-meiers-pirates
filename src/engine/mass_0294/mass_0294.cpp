// Reconstruction batch mass_0294
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Corpus: Ghidra 12.2 pseudocode, analysis/pseudocode/functions/*.c
// Candidate definitions only -- not original source, not text-equivalent to the binary.
// Field accesses are kept as explicit byte offsets to preserve the observed shapes.

#include <cstdint>
#include <cstddef>

// ---------------------------------------------------------------------------
// Referenced helpers (declared extern; definitions live in other translation
// units / other reconstruction batches).
// ---------------------------------------------------------------------------
// Allocation / string / AST helpers (variable arity in the supplied listings).
extern int FUN_0060d19b(...);   // 0x60d19b  allocator
extern int FUN_00533c78(...);   // 0x533c78  allocator (parser instance)
extern int FUN_0065ac49(...);   // 0x65ac49  "<name>" node constructor
extern int FUN_0065ac0a(...);   // 0x65ac0a
extern int FUN_0065ae50(...);   // 0x65ae50
extern int FUN_0065aec0(...);   // 0x65aec0
extern int FUN_0065b01d(...);   // 0x65b01d  statement node constructor
extern int FUN_0065b0f3(...);   // 0x65b0f3  literal node constructor
extern int FUN_0065b168(...);   // 0x65b168  chain element constructor
extern int FUN_0065b182(...);   // 0x65b182
extern int FUN_0065b202(...);   // 0x65b202  arithmetic node constructor
extern int FUN_0065b377(...);   // 0x65b377  declaration descriptor
extern int FUN_0065b469(...);   // 0x65b469
extern int FUN_0065b52c(...);   // 0x65b52c  expression node constructor
extern int FUN_0065b679(...);   // 0x65b679  indexed-access node
extern int FUN_0065b78c(...);   // 0x65b78c
extern int FUN_0065b8b3(...);   // 0x65b8b3
extern int FUN_0065abf1(...);   // 0x65abf1  clone expression node
extern int FUN_00639498(...);   // 0x639498
extern int FUN_0063395f(...);   // 0x63395f
extern int FUN_006357d2(...);   // 0x6357d2
extern int FUN_006328be(...);   // 0x6328be
extern int FUN_0063284b(...);   // 0x63284b
extern int FUN_006328e2(...);   // 0x6328e2
extern int FUN_00632959(...);   // 0x632959
extern int FUN_006329e7(...);   // 0x6329e7
extern int FUN_00632fea(...);   // 0x632fea
extern int FUN_006331d2(...);   // 0x6331d2
extern int FUN_0063324e(...);   // 0x63324e
extern int FUN_0063336c(...);   // 0x63336c
extern int FUN_006333b4(...);   // 0x6333b4
extern int FUN_00633499(...);   // 0x633499
extern int FUN_006335cf(...);   // 0x6335cf
extern int FUN_00633708(...);   // 0x633708
extern int FUN_006337f7(...);   // 0x6337f7
extern int FUN_00634393(...);   // 0x634393
extern int FUN_00634446(...);   // 0x634446
extern int FUN_0063477e(...);   // 0x63477e
extern int FUN_00634aaf(...);   // 0x634aaf
extern int FUN_00634bad(...);   // 0x634bad
extern int FUN_00634cc5(...);   // 0x634cc5
extern int FUN_00634d49(...);   // 0x634d49
extern int FUN_00634e2f(...);   // 0x634e2f
extern int FUN_00634f17(...);   // 0x634f17
extern int FUN_006353a8(...);   // 0x6353a8
extern int FUN_006354e2(...);   // 0x6354e2
extern int FUN_006355bc(...);   // 0x6355bc
extern int FUN_00635a73(...);   // 0x635a73
extern int FUN_00636edb(...);   // 0x636edb  symbol lookup
extern int FUN_00637598(...);   // 0x637598
extern int FUN_0063769f(...);   // 0x63769f
extern int FUN_006378c8(...);   // 0x6378c8
extern int FUN_00638495(...);   // 0x638495
extern int FUN_006385bc(...);   // 0x6385bc  next token
extern int FUN_00639117(...);   // 0x639117
extern int FUN_00633aa9(...);   // 0x633aa9  intrinsic lookup
extern int FUN_006325ec(...);   // 0x6325ec
extern int FUN_0063271d(...);   // 0x63271d
extern int FUN_00632729(...);   // 0x632729
extern int FUN_006327be(...);   // 0x6327be
extern int FUN_0063237b(...);   // 0x63237b
extern int FUN_006323c8(...);   // 0x6323c8  parser failure
extern int FUN_00632420(...);   // 0x632420  release node
extern int FUN_00632455(...);   // 0x632455
extern int FUN_006321f5(...);   // 0x6321f5  error callback
extern int FUN_0060bf76(...);   // 0x60bf76
extern int FUN_0060f49b(...);   // 0x60f49b
extern int FUN_005f7fa4(...);   // 0x5f7fa4  target info query
extern int func_0x00632709(...);
extern int func_0x00633416(...);
extern int func_0x006335b4(...);
extern int func_0x006338c8(...);
extern void FUN_00632325(...);  // 0x632325  variadic error reporter
extern void operator_delete(void*);

extern char PTR_DAT_006e9ca0;   // 0x6e9ca0  string used as a name argument

// 0x6395c3 — observed shape: 2 args; lookup target, require kind 9, resolve
// descriptor, then index into a 0x20-bearing record and forward 3 args.
// 0x6395c3 — observed shape
int FUN_006395c3(int param_1, int param_2)
{
    int iVar1;
    long long uVar2;

    iVar1 = FUN_00639498(param_1);
    if (((iVar1 != 0) && (iVar1 = *(int*)(iVar1 + 0x10), iVar1 != 0)) && (*(int*)(iVar1 + 4) == 9)) {
        uVar2 = FUN_006328be(iVar1);
        iVar1 = (int)((unsigned long long)uVar2 >> 0x20);
        if ((int)uVar2 != 0) {
            iVar1 = FUN_006357d2(param_2,
                                 *(int*)(*(int*)(iVar1 + 0x20) + 8) + 0x10,
                                 iVar1 + 0x30);
            if (iVar1 < 0) {
                return iVar1;
            }
            return 0;
        }
    }
    return -0x7fffbffb;
}

// 0x63961c — observed shape: receiver in ECX; walks a statement chain, allocates
// a "Stmts" node (0x14) plus node (0x30), walks to the terminator (kind 3),
// validates array dimension limits (1..0x10000) and reports 0xbf2/0xc00/0xbf3.
// 0x63961c — observed shape
int FUN_0063961c(void* self, int param_1, int param_2)
{
    int* piVar1;
    int iVar2;
    int* piVar3;
    int iVar4;
    int iVar5;
    int uVar8;
    const char* pcVar7;
    int uVar6;
    int local_14;
    int local_10;
    std::uint32_t local_c;
    void* local_8;

    local_14 = 0;
    piVar3 = &local_14;
    local_8 = self;
    if (param_2 != 0) {
        while (*(int*)(param_2 + 8) != 0) {
            iVar2 = FUN_0060d19b(0x14);
            if (iVar2 == 0) {
                iVar2 = 0;
            } else {
                iVar2 = FUN_0065ac49(0, 0, "Stmts");
            }
            *piVar3 = iVar2;
            if (iVar2 == 0) {
                return 0;
            }
            iVar2 = FUN_0060d19b(0x30);
            if (iVar2 == 0) {
                iVar2 = 0;
            } else {
                iVar2 = FUN_0065b01d(0, 0, 0, 0);
            }
            if (iVar2 == 0) {
                return 0;
            }
            *(int*)(*piVar3 + 8) = iVar2;
            piVar3 = (int*)(*piVar3 + 0xc);
            local_c = 1;
            local_10 = 0;
            if (param_1 != 0) {
                iVar4 = FUN_0065abf1(param_1);
                *(int*)(iVar2 + 0x18) = iVar4;
                if (iVar4 == 0) {
                    return 0;
                }
            }
            for (iVar4 = *(int*)(param_2 + 8); *(int*)(iVar4 + 4) != 3; iVar4 = *(int*)(iVar4 + 8)) {
                iVar5 = FUN_0060d19b(0x18);
                if (iVar5 == 0) {
                    iVar5 = 0;
                } else {
                    iVar5 = FUN_0065b168();
                }
                if (iVar5 == 0) {
                    return 0;
                }
                *(int*)(iVar5 + 0x10) = *(int*)(iVar2 + 0x18);
                *(int*)(iVar2 + 0x18) = iVar5;
                piVar1 = (int*)(iVar5 + 0x14);
                if (*(int*)(iVar4 + 0xc) == 0) {
                    local_10 = 0xc00;
                    *piVar1 = 1;
                } else {
                    iVar5 = FUN_006395c3(*(int*)(iVar4 + 0xc), (int)(std::intptr_t)piVar1);
                    if (iVar5 < 0) {
                        local_10 = 0xbf2;
                        *piVar1 = 1;
                    }
                }
                local_c = (std::uint32_t)*piVar1 * local_c;
            }
            iVar5 = FUN_0065abf1(iVar4);
            *(int*)(iVar2 + 0x14) = iVar5;
            if (iVar5 == 0) {
                return 0;
            }
            if (local_10 == 0xbf2) {
                uVar8 = *(int*)(iVar4 + 0x18);
                pcVar7 = "'%s': array dimensions must be literal scalar expressions";
                uVar6 = 0xbf2;
                FUN_00632325();
                (void)local_8; (void)iVar4; (void)uVar6; (void)pcVar7; (void)uVar8;
                return 0;
            }
            if (local_10 == 0xc00) {
                uVar8 = *(int*)(iVar4 + 0x18);
                pcVar7 = "'%s': array dimensions of type must be explicit";
                uVar6 = 0xc00;
                FUN_00632325();
                (void)local_8; (void)iVar4; (void)uVar6; (void)pcVar7; (void)uVar8;
                return 0;
            }
            if ((local_c == 0) || (0x10000 < local_c)) {
                uVar8 = *(int*)(iVar4 + 0x18);
                pcVar7 = "'%s': array dimension must be between 1 and 65536";
                uVar6 = 0xbf3;
                FUN_00632325();
                (void)local_8; (void)iVar4; (void)uVar6; (void)pcVar7; (void)uVar8;
                return 0;
            }
            iVar2 = FUN_0063395f(iVar2, 1);
            if (iVar2 < 0) {
                return 0;
            }
            param_2 = *(int*)(param_2 + 0xc);
            if (param_2 == 0) {
                return local_14;
            }
        }
    }
    return 0;
}

// 0x6397cc — observed shape: allocate a 0x14 node, build it from the name
// string, run the statement builder on it, then clear its +8 link.
// 0x6397cc — observed shape
int FUN_006397cc(int param_1, int param_2)
{
    int iVar1;
    int uVar2;

    iVar1 = FUN_0060d19b(0x14);
    if (iVar1 == 0) {
        iVar1 = 0;
    } else {
        iVar1 = FUN_0065ac49(param_2, 0, &PTR_DAT_006e9ca0);
    }
    if (iVar1 == 0) {
        uVar2 = 0;
    } else {
        /* receiver for FUN_0063961c is the caller-inherited ECX, not recovered */
        uVar2 = FUN_0063961c(nullptr, param_1, iVar1);
        *(int*)(iVar1 + 8) = 0;
    }
    return uVar2;
}

// 0x639814 — observed shape: validate the index/operand pair, then allocate a
// 0x24 node and build a unary node (tag 1) from it.
// 0x639814 — observed shape
int FUN_00639814(std::uint32_t param_1, int param_2)
{
    std::uint32_t uVar1;
    int iVar2;
    int uVar3;

    uVar1 = param_1;
    if (param_1 != 0) {
        iVar2 = FUN_006395c3(param_2, (int)(std::intptr_t)&param_1);
        if (iVar2 < 0) {
            FUN_00632325();
        } else if ((param_1 == 0) || (4 < param_1)) {
            FUN_00632325();
        } else {
            iVar2 = FUN_0060d19b(0x24);
            if (iVar2 != 0) {
                uVar3 = FUN_0065b202(1, *(int*)(uVar1 + 0x14), 1, (int)param_1, 0);
                return uVar3;
            }
        }
    }
    return 0;
}

// 0x63989a — observed shape: two validated operands (each 1..4), then a binary
// node (tag 2) carrying both operand indexes.
// 0x63989a — observed shape
int FUN_0063989a(std::uint32_t param_1, std::uint32_t param_2, int param_3)
{
    std::uint32_t uVar1;
    int iVar2;
    int uVar3;

    uVar1 = param_1;
    if (param_1 != 0) {
        iVar2 = FUN_006395c3((int)param_2, (int)(std::intptr_t)&param_2);
        if ((iVar2 < 0) || (iVar2 = FUN_006395c3(param_3, (int)(std::intptr_t)&param_1), iVar2 < 0)) {
            FUN_00632325();
        } else if ((param_2 == 0) || (((4 < param_2 || (param_1 == 0)) || (4 < param_1)))) {
            FUN_00632325();
        } else {
            iVar2 = FUN_0060d19b(0x24);
            if (iVar2 != 0) {
                uVar3 = FUN_0065b202(2, *(int*)(uVar1 + 0x14), (int)param_2, (int)param_1, 0);
                return uVar3;
            }
        }
    }
    return 0;
}

// 0x639943 — observed shape: validate the expression, allocate a 0x18 node,
// then splice it in front of the first non-kind-8 node of the chain.
// 0x639943 — observed shape
int FUN_00639943(int param_1, int param_2)
{
    int* piVar1;
    int iVar2;
    int iVar3;

    iVar3 = FUN_006395c3(param_2, (int)(std::intptr_t)&param_2);
    if (iVar3 < 0) {
        FUN_00632325();
    } else {
        iVar3 = FUN_0060d19b(0x18);
        if (iVar3 == 0) {
            iVar3 = 0;
        } else {
            iVar3 = FUN_0065b182(0, param_2);
        }
        if (iVar3 != 0) {
            piVar1 = &param_1;
            iVar2 = param_1;
            while ((iVar2 != 0 && (*(int*)(*piVar1 + 4) == 8))) {
                piVar1 = (int*)(*piVar1 + 0x10);
                iVar2 = *piVar1;
            }
            *(int*)(iVar3 + 0x10) = *piVar1;
            *piVar1 = iVar3;
            return param_1;
        }
    }
    return 0;
}

// 0x6399bc — observed shape: requires kind 0xd on both nodes, builds an
// aggregate node (0x50, tag 0x16), clones the operand from the left kind
// 8/9 shape, then binds an index expression.
// 0x6399bc — observed shape
int FUN_006399bc(int* param_1, std::uint32_t param_2)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    std::uint32_t uVar5;
    int uVar6;
    const char* pcVar7;
    void* self = nullptr; /* ECX receiver, not recovered */

    if (param_1 == (int*)0) {
        return 0;
    }
    if (param_1[1] != 0xd) {
        return 0;
    }
    if (param_2 == 0) {
        return 0;
    }
    if (*(int*)(param_2 + 4) != 0xd) {
        return 0;
    }
    iVar4 = (int)param_2 + 0x30;
    iVar1 = FUN_0060d19b(0x50);
    if (iVar1 == 0) {
        iVar1 = 0;
    } else {
        iVar1 = FUN_0065b52c(0, 0x16, 0, 0, 1, iVar4);
    }
    if (iVar1 == 0) {
        return 0;
    }
    iVar3 = param_1[4];
    uVar6 = *(int*)(param_2 + 0x10);
    if (iVar3 == 0) {
        pcVar7 = "array expected";
        uVar6 = 0xbcd;
    } else {
        if (*(int*)(iVar3 + 4) == 8) {
            if (*(int*)(iVar3 + 0x10) != 0) {
                iVar2 = (*(int(**)(void))(**(int**)(iVar3 + 0x10) + 4))();
                *(int*)(iVar1 + 0x10) = iVar2;
                if (iVar2 == 0) {
                    return 0;
                }
            }
            uVar5 = *(std::uint32_t*)(iVar3 + 0x14);
        } else {
            if (*(int*)(iVar3 + 4) != 9) {
                pcVar7 = "array expected";
                uVar6 = 0xbcd;
                FUN_00632325();
                (void)self; (void)iVar4; (void)uVar6; (void)pcVar7;
                return 0;
            }
            if (*(int*)(iVar3 + 0x10) == 1) {
                iVar2 = FUN_0060d19b(0x24);
                if (iVar2 == 0) {
                    iVar2 = 0;
                } else {
                    iVar2 = FUN_0065b202(0, *(int*)(iVar3 + 0x14), 1, 1,
                                         *(std::uint32_t*)(iVar3 + 0x20) & 0x200);
                }
                *(int*)(iVar1 + 0x10) = iVar2;
                if (iVar2 == 0) {
                    return 0;
                }
                uVar5 = *(std::uint32_t*)(iVar3 + 0x1c);
            } else {
                if (*(int*)(iVar3 + 0x10) != 2) {
                    pcVar7 = "array expected";
                    uVar6 = 0xbcd;
                    FUN_00632325();
                    (void)self; (void)iVar4; (void)uVar6; (void)pcVar7;
                    return 0;
                }
                iVar2 = FUN_0060d19b(0x24);
                if (iVar2 == 0) {
                    iVar2 = 0;
                } else {
                    iVar2 = FUN_0065b202(1, *(int*)(iVar3 + 0x14), 1, *(int*)(iVar3 + 0x1c),
                                         *(std::uint32_t*)(iVar3 + 0x20) & 0x200);
                }
                *(int*)(iVar1 + 0x10) = iVar2;
                if (iVar2 == 0) {
                    return 0;
                }
                uVar5 = *(std::uint32_t*)(iVar3 + 0x18);
            }
        }
        iVar3 = FUN_006328be(uVar6);
        if (iVar3 != 0) {
            iVar3 = (*(int(**)(void))(*param_1 + 4))();
            *(int*)(iVar1 + 0x20) = iVar3;
            if (iVar3 == 0) {
                return 0;
            }
            iVar3 = FUN_0063324e(param_2);
            if (iVar3 == 0) {
                iVar4 = FUN_0065abf1(param_2);
                *(int*)(iVar1 + 0x24) = iVar4;
                if (iVar4 == 0) {
                    return 0;
                }
            } else {
                iVar3 = FUN_006395c3(param_2, (int)(std::intptr_t)&param_2);
                if (iVar3 < 0) {
                    return 0;
                }
                if (uVar5 <= param_2) {
                    FUN_00632325();
                    (void)self; (void)iVar4;
                    param_2 = 0;
                }
                iVar3 = FUN_00632959(*(int*)(iVar1 + 0x10));
                iVar2 = FUN_0060d19b(0x40);
                if (iVar2 == 0) {
                    iVar4 = 0;
                } else {
                    iVar4 = FUN_0065b679(2, iVar3 * (int)param_2, iVar4);
                }
                *(int*)(iVar1 + 0x24) = iVar4;
                if (iVar4 == 0) {
                    return 0;
                }
                *(int*)(iVar1 + 0x1c) = 0x17;
            }
            FUN_0063336c(iVar1);
            return iVar1;
        }
        pcVar7 = "scalar expected";
        uVar6 = 0xbeb;
        FUN_00632325();
        (void)self; (void)iVar4; (void)uVar6; (void)pcVar7;
        return 0;
    }
    FUN_00632325();
    (void)self; (void)iVar4; (void)uVar6; (void)pcVar7;
    return 0;
}

// 0x639be6 — observed shape: builds a binary/unary expression node (0x50);
// large op-code switch maps 0x1c..0x22 to operator tags, validates operand
// categories, selects the assignment/comparison/compound path, then
// relaxes operand types via FUN_006329e7/FUN_0063769f.
// 0x639be6 — observed shape
int FUN_00639be6(void* self, int param_1, int* param_2, int* param_3, int param_4)
{
    int* piVar1;
    int iVar2;
    int iVar3;
    long long uVar4;
    int uVar5;
    int* piVar6;
    const char* pcVar7;
    int* local_18;
    int* local_14;
    int* local_10;
    int* local_c;
    void* local_8;

    piVar1 = param_2;
    local_14 = (int*)0;
    local_18 = (int*)0;
    local_c = (int*)0;
    local_10 = (int*)0;
    if ((param_2 != (int*)0) && (param_2[1] != 0xd)) {
        return 0;
    }
    if (param_3 == (int*)0) {
        if (param_2 != (int*)0) {
            param_2 = param_2 + 0xc;
        } else {
            param_2 = (int*)((char*)self + 0x20);
        }
    } else {
        param_2 = param_3;
        if (param_3[1] != 0xd) {
            return 0;
        }
        param_2 = param_2 + 0xc;
    }
    local_8 = self;
    iVar2 = FUN_0060d19b(0x50);
    if (iVar2 == 0) {
        iVar2 = 0;
    } else {
        iVar2 = FUN_0065b52c(0, param_1, 0, 0, param_4, (int)(std::intptr_t)param_2);
    }
    if (iVar2 == 0) {
        return 0;
    }
    if (piVar1 != (int*)0) {
        iVar3 = (*(int(**)(void))(*piVar1 + 4))();
        *(int*)(iVar2 + 0x20) = iVar3;
        if (iVar3 == 0) {
            return 0;
        }
    }
    iVar3 = 0x15;
    if ((((((param_1 == 0x1c) || (param_1 == 0x1d)) || (param_1 == 0x1e)) ||
          ((param_1 == 0x1f || (param_1 == 0x20)))) || (param_1 == 0x21)) || (param_1 == 0x22)) {
        if (param_1 == 0x1c) {
            piVar6 = (int*)0x7;
            param_1 = iVar3;
        } else if (param_1 == 0x1d) {
            piVar6 = (int*)0x8;
            param_1 = iVar3;
        } else if (param_1 == 0x1e) {
            piVar6 = (int*)0x9;
            param_1 = iVar3;
        } else if (param_1 == 0x1f) {
            piVar6 = (int*)0xa;
            param_1 = iVar3;
        } else if (param_1 == 0x20) {
            piVar6 = (int*)0xb;
            param_1 = iVar3;
        } else if (param_1 == 0x21) {
            iVar3 = 1;
            piVar6 = (int*)0x2;
            param_1 = iVar3;
        } else if (param_1 == 0x22) {
            iVar3 = 1;
            piVar6 = (int*)0x3;
            param_1 = iVar3;
        } else {
            piVar6 = param_3;
        }
        iVar3 = FUN_00639be6(self, (int)(std::intptr_t)piVar6, piVar1, param_3, 0);
        *(int*)(iVar2 + 0x24) = iVar3;
        if (iVar3 == 0) {
            return 0;
        }
        *(int*)(iVar2 + 0x1c) = param_1;
    } else if (param_3 != (int*)0) {
        iVar3 = (*(int(**)(void))(*param_3 + 4))();
        *(int*)(iVar2 + 0x24) = iVar3;
        if (iVar3 == 0) {
            return 0;
        }
    }
    if (*(int*)(iVar2 + 0x20) != 0) {
        local_18 = *(int**)(*(int*)(iVar2 + 0x20) + 0x10);
        local_14 = local_18;
    }
    if ((((param_1 != 0) && (param_1 != 1)) &&
         ((param_1 != 0x14 && (((param_1 != 0x15 && (param_1 != 0x10)) && (param_1 != 0x11)))))) &&
        (((local_14 == (int*)0 || (local_14[1] != 9)) ||
          (iVar3 = FUN_006328e2((int)(std::intptr_t)local_14), iVar3 == 0)))) {
        pcVar7 = "scalar, vector, or matrix expected";
        uVar5 = 0xbce;
        FUN_00632325();
        (void)local_8; (void)param_2; (void)uVar5; (void)pcVar7;
        return 0;
    }
    piVar1 = local_14;
    if (((param_1 == 2) || (param_1 == 3)) || ((param_1 == 0x14 || (param_1 == 0x15)))) {
        iVar3 = FUN_0063284b((int)(std::intptr_t)local_14);
        if (iVar3 == 0) {
            uVar4 = FUN_006331d2(*(int*)(iVar2 + 0x20));
            if ((int)uVar4 == 0) {
                iVar3 = *(int*)(*(int*)((int)((unsigned long long)uVar4 >> 0x20) + 0x10) + 0x10);
                if (((iVar3 == 3) || (iVar3 == 4)) &&
                    (iVar3 = FUN_006328e2((int)(std::intptr_t)piVar1), iVar3 == 0)) {
                    pcVar7 = "object assignments are not allowed inside functions";
                    uVar5 = 0xbf9;
                    FUN_00632325();
                    (void)local_8; (void)param_2; (void)uVar5; (void)pcVar7;
                    return 0;
                }
                goto LAB_ignore_assign_checks;
            }
        }
        pcVar7 = "l-value specifies const object";
        uVar5 = 0xbd1;
        FUN_00632325();
        (void)local_8; (void)param_2; (void)uVar5; (void)pcVar7;
        return 0;
    }
LAB_ignore_assign_checks:
    if (*(int*)(iVar2 + 0x24) != 0) {
        local_10 = *(int**)(*(int*)(iVar2 + 0x24) + 0x10);
        local_c = local_10;
    }
    if ((param_1 == 0x14) || (param_1 == 0x15)) {
        iVar3 = FUN_00634446((int)(std::intptr_t)piVar1, (int)(std::intptr_t)local_c, 0);
        if (iVar3 == 0) {
            FUN_0063477e((int)(std::intptr_t)param_2, 0, (int)(std::intptr_t)piVar1,
                         (int)(std::intptr_t)local_c, 0);
            return 0;
        }
        if (piVar1 != (int*)0) {
            iVar3 = (*(int(**)(void))(*piVar1 + 4))();
            *(int*)(iVar2 + 0x10) = iVar3;
            if (iVar3 == 0) {
                return 0;
            }
        }
        local_10 = piVar1;
    } else if (param_1 == 0) {
        if (piVar1 != (int*)0) {
            iVar3 = (*(int(**)(void))(*piVar1 + 4))();
            *(int*)(iVar2 + 0x10) = iVar3;
            if (iVar3 == 0) {
                return 0;
            }
        }
    } else {
        if (((param_1 != 4) && (param_1 != 5)) &&
            ((param_1 != 6 && (((param_1 != 2 && (param_1 != 3)) && (param_1 != 1)))))) {
            if (((param_1 == 0xc) || (param_1 == 0xd)) ||
                ((param_1 == 0xe ||
                  (((param_1 == 0xf || (param_1 == 0x10)) ||
                    ((param_1 == 0x11 || ((param_1 == 0x12 || (param_1 == 0x13)))))))))) {
                iVar3 = FUN_00634aaf((int)(std::intptr_t)piVar1, (int)(std::intptr_t)local_c,
                                     (int*)(std::intptr_t)&local_18,
                                     (int*)(std::intptr_t)&local_10, (int*)(iVar2 + 0x10));
                if (-1 < iVar3) {
                    *(int*)(*(int*)(iVar2 + 0x10) + 0x14) = 0;
                    goto LAB_report_unify;
                }
            } else {
                iVar3 = FUN_00634aaf((int)(std::intptr_t)piVar1, (int)(std::intptr_t)local_c,
                                     (int*)(std::intptr_t)&local_18,
                                     (int*)(std::intptr_t)&local_10, (int*)(iVar2 + 0x10));
                if (-1 < iVar3) goto LAB_report_unify;
            }
            pcVar7 = "type mismatch";
            uVar5 = 0xbcc;
            FUN_00632325();
            (void)local_8; (void)param_2; (void)uVar5; (void)pcVar7;
            return 0;
        }
        if (piVar1 != (int*)0) {
            iVar3 = (*(int(**)(void))(*piVar1 + 4))();
            *(int*)(iVar2 + 0x10) = iVar3;
            if (iVar3 == 0) {
                return 0;
            }
        }
        FUN_00632729(*(int*)(iVar2 + 0x10), 1);
    }
LAB_report_unify:
    if ((*(int*)(iVar2 + 0x20) != 0) && (piVar1 != local_18)) {
        uVar4 = FUN_006329e7((int)(std::intptr_t)piVar1, (int)(std::intptr_t)local_18);
        if ((int)uVar4 == 0) {
            iVar3 = FUN_0063769f((int)(std::intptr_t)local_18,
                                 (int)((unsigned long long)uVar4 >> 0x20), 0, 0);
            if (iVar3 == 0) {
                return 0;
            }
            *(int*)(iVar2 + 0x20) = iVar3;
        }
    }
    if ((*(int*)(iVar2 + 0x24) != 0) && (local_c != local_10)) {
        uVar4 = FUN_006329e7((int)(std::intptr_t)local_c, (int)(std::intptr_t)local_10);
        if ((int)uVar4 == 0) {
            iVar3 = FUN_0063769f((int)(std::intptr_t)local_10,
                                 (int)((unsigned long long)uVar4 >> 0x20), 0, 0);
            if (iVar3 == 0) {
                return 0;
            }
            *(int*)(iVar2 + 0x24) = iVar3;
        }
    }
    if (*(int*)(iVar2 + 0x10) == 0) {
        *(int*)(iVar2 + 0x10) = 0;
    }
    FUN_0063336c(iVar2);
    iVar3 = FUN_0063324e(iVar2);
    if (iVar3 == 0) {
        return iVar2;
    }
    iVar3 = FUN_00639498(iVar2);
    if (iVar3 == 0) {
        return iVar2;
    }
    return iVar3;
}

// 0x639fff — observed shape: receiver state gate on +0x18, allocate a 0x24
// node (tag 0x15), and either reject or wrap the callee expression, then
// allocate the 0x14 "Stmts" wrapper.
// 0x639fff — observed shape
int FUN_00639fff(void* self, int param_1)
{
    int iVar1;
    int iVar2;
    int uVar3;

    if (*(int*)((char*)self + 0x18) == 0) {
        return 0;
    }
    iVar1 = FUN_0060d19b(0x24);
    if (iVar1 == 0) {
        iVar1 = 0;
    } else {
        iVar1 = FUN_0065b469();
    }
    if (iVar1 == 0) {
        return 0;
    }
    *(int*)(iVar1 + 0x10) = 1;
    iVar2 = *(int*)((char*)self + 0x18);
    if (param_1 == 0) {
        if (*(int*)(iVar2 + 0x20) == 0) goto LAB_0063a08f;
    } else if (*(int*)(iVar2 + 0x20) != 0) {
        uVar3 = FUN_00639be6(self, 0x15, (int*)(std::intptr_t)*(int*)(iVar2 + 0x2c),
                             (int*)(std::intptr_t)param_1, 1);
        *(int*)(iVar1 + 0x14) = uVar3;
        goto LAB_0063a08f;
    }
    FUN_00632325();
LAB_0063a08f:
    iVar2 = FUN_0060d19b(0x14);
    if (iVar2 == 0) {
        return 0;
    }
    uVar3 = FUN_0065ac49(iVar1, 0, "Stmts");
    (void)iVar2;
    return uVar3;
}

// 0x63a0b3 — observed shape: variable-declaration builder. Resolves the
// declaration kind, builds the 0x30 statement node plus a 0x40 declaration
// descriptor, walks the dimension expression chain, validates the declarator
// attribute mask (target specific / inline / const / static / uniform / extern
// / shared / volatile / annotations) and finally installs the initializer.
// 0x63a0b3 — observed shape
int FUN_0063a0b3(void* self, int param_1, std::uint32_t* param_2, std::uint32_t param_3, int param_4)
{
    std::uint32_t* puVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int uVar5;
    int iVar6;
    std::uint32_t uVar7;
    int iVar8;
    int uVar9;
    const char* pcVar10;
    const char* pcVar12;
    const char* local_4c[4];
    const char* local_3c;
    const char* local_38;
    const char* local_34;
    const char* local_30;
    const char* local_2c;
    const char* local_28;
    const char* local_24;
    const char* local_20;
    int local_1c;
    std::uint32_t local_18;
    int local_14;
    int local_10;
    int local_c;
    void* local_8 = self;

    local_34 = "global variables";
    local_30 = "structure members";
    local_2c = "function parameters";
    local_28 = "local variables";
    local_24 = "loop control variables";
    local_20 = "annotation members";
    local_4c[0] = "initial value";
    local_4c[1] = "initializer";
    local_4c[2] = "default value";
    local_4c[3] = "initial value";
    local_3c = "initial value";
    local_38 = "value";
    local_1c = FUN_0063271d();
    if (local_1c == 0) {
        return 0;
    }
    if (*(int*)((char*)self + 0x10) == 0) {
        return 0;
    }
    if (param_1 == 0) {
        return 0;
    }
    local_18 = *(std::uint32_t*)(local_1c + 0x18);
    iVar2 = FUN_0060d19b(0x14);
    if (iVar2 == 0) {
        local_10 = 0;
    } else {
        local_10 = FUN_0065ac49(0, 0, "Stmts");
    }
    if (local_10 == 0) {
        return 0;
    }
    iVar2 = FUN_0060d19b(0x30);
    if (iVar2 == 0) {
        iVar2 = 0;
    } else {
        iVar2 = FUN_0065b01d(1, 0, 0, 0);
    }
    if (iVar2 == 0) {
        return 0;
    }
    *(int*)(local_10 + 8) = iVar2;
    local_c = iVar2;
    iVar3 = FUN_0060d19b(0x40);
    if (iVar3 == 0) {
        iVar3 = 0;
    } else {
        iVar3 = FUN_0065b377();
    }
    if (iVar3 == 0) {
        return 0;
    }
    *(int*)(iVar2 + 0x18) = iVar3;
    if (param_3 != 0) {
        iVar4 = FUN_0065abf1((int)param_3);
        *(int*)(iVar2 + 0x1c) = iVar4;
        if (iVar4 == 0) {
            return 0;
        }
    }
    if (param_2 != (std::uint32_t*)0) {
        iVar4 = FUN_0065abf1((int)(std::intptr_t)param_2);
        *(int*)(iVar3 + 0x30) = iVar4;
        if (iVar4 == 0) {
            return 0;
        }
        do {
            iVar4 = *(int*)((char*)param_2 + 8);
            if ((iVar4 != 0) && (*(int*)(iVar4 + 4) == 3)) {
                iVar4 = FUN_0065abf1(iVar4);
                *(int*)(iVar3 + 0x2c) = iVar4;
                if (iVar4 == 0) {
                    return 0;
                }
            }
            param_2 = *(std::uint32_t**)((char*)param_2 + 0xc);
        } while (param_2 != (std::uint32_t*)0);
    }
    if ((param_4 != 0) && (*(int*)(param_4 + 4) != 0xd)) {
        uVar5 = FUN_00634e2f();
        *(int*)(iVar3 + 0x24) = uVar5;
    }
    param_3 = 1;
    param_2 = (std::uint32_t*)0;
    local_14 = 0;
    if (local_18 != 0) {
        iVar4 = FUN_0065abf1((int)local_18);
        *(int*)(iVar3 + 0x20) = iVar4;
        if (iVar4 == 0) {
            return 0;
        }
    }
    if (*(int*)(param_1 + 4) != 3) {
        do {
            iVar2 = FUN_0060d19b(0x18);
            if (iVar2 == 0) {
                iVar2 = 0;
            } else {
                iVar2 = FUN_0065b168();
            }
            if (iVar2 == 0) {
                return 0;
            }
            if (param_2 != (std::uint32_t*)0) {
                local_14 = 0xc01;
            }
            *(int*)(iVar2 + 0x10) = *(int*)(iVar3 + 0x20);
            puVar1 = (std::uint32_t*)(iVar2 + 0x14);
            if (*(int*)(param_1 + 0xc) == 0) {
                param_2 = puVar1;
                *puVar1 = 1;
            } else {
                /* listing elides the arguments; identical shape to 0x63961c */
                iVar4 = FUN_006395c3(*(int*)(param_1 + 0xc), (int)(std::intptr_t)puVar1);
                if (iVar4 < 0) {
                    local_14 = 0xbf2;
                    *puVar1 = 1;
                }
            }
            param_3 = *puVar1 * param_3;
            *(int*)(iVar3 + 0x20) = iVar2;
            param_1 = *(int*)(param_1 + 8);
        } while (*(int*)(param_1 + 4) != 3);
        iVar2 = local_c;
    }
    iVar4 = FUN_0065abf1(param_1);
    *(int*)(iVar2 + 0x14) = iVar4;
    if (iVar4 == 0) {
        return 0;
    }
    iVar2 = *(int*)(*(int*)((char*)local_8 + 0x10) + 0x10);
    iVar4 = param_1 + 0x10;
    if (local_14 == 0xbf2) {
        FUN_00632325();
        return 0;
    }
    if (local_14 == 0xc01) {
        FUN_00632325();
        return 0;
    }
    if (param_2 != (std::uint32_t*)0) {
        if ((((iVar2 != 0) && (iVar2 != 3)) && (iVar2 != 4)) && (iVar2 != 5)) {
            pcVar10 = local_4c[iVar2 + 6];
            FUN_00632325();
            (void)pcVar10; (void)local_8; (void)iVar4;
            return 0;
        }
        iVar6 = FUN_00632959((int)local_18);
        local_18 = (std::uint32_t)(iVar6 * (int)param_3);
        if (iVar6 * (int)param_3 == 0) {
            *param_2 = 0;
            param_3 = 0;
        } else {
            iVar6 = *(int*)(iVar3 + 0x24);
            if ((iVar6 == 0) || (*(int*)(iVar6 + 4) != 0xd)) {
                pcVar10 = local_4c[iVar2];
                FUN_00632325();
                (void)pcVar10; (void)local_8; (void)iVar4;
                return 0;
            }
            uVar7 = (std::uint32_t)FUN_00632959(*(int*)(iVar6 + 0x10));
            if (uVar7 % local_18 != 0) {
                pcVar10 = local_4c[iVar2];
                FUN_00632325();
                (void)pcVar10; (void)local_8; (void)iVar4;
                return 0;
            }
            *param_2 = uVar7 / local_18;
            param_3 = (uVar7 / local_18) * param_3;
        }
    }
    if ((param_3 == 0) || (0x10000 < param_3)) {
        FUN_00632325();
        return 0;
    }
    iVar6 = FUN_00632959(*(int*)(iVar3 + 0x20));
    *(int*)(iVar3 + 0x14) = iVar6;
    *(int*)(iVar3 + 0x18) = *(int*)(*(int*)((char*)local_8 + 0x10) + 0x10);
    if (*(int*)(*(int*)((char*)local_8 + 0x10) + 0x10) == 1) {
        *(int*)(iVar3 + 0x10) = -1;
    } else {
        *(int*)(iVar3 + 0x10) = *(int*)((char*)local_8 + 0x58);
        *(int*)((char*)local_8 + 0x58) = *(int*)((char*)local_8 + 0x58) + iVar6;
    }
    param_3 = *(std::uint32_t*)(local_1c + 0x10);
    if (*(int*)(local_1c + 0x14) != 0) {
        FUN_00632325();
    }
    if ((param_3 & 0x100) != 0) {
        FUN_00632325();
    }
    if (iVar2 == 1) {
        iVar6 = FUN_0063284b(*(int*)(iVar3 + 0x20));
        if (iVar6 != 0) {
            FUN_00632325();
            goto LAB_0063a490;
        }
        goto LAB_0063a574;
    }
LAB_0063a490:
    if (iVar2 == 2) {
        if (((param_3 & 0x10) != 0) ||
            (iVar6 = FUN_0063284b(*(int*)(iVar3 + 0x20)), iVar6 == 0)) goto LAB_0063a574;
        FUN_00632325();
    }
    if (((iVar2 == 3) || (iVar2 == 4)) &&
        (iVar6 = FUN_006328e2(*(int*)(iVar3 + 0x20)), iVar6 == 0)) {
        FUN_00632325();
    }
    if (iVar2 != 0) goto LAB_0063a574;
    if ((param_3 & 2) == 0) {
        param_3 = param_3 | 0x41;
    } else {
        if ((param_3 & 1) != 0) {
            FUN_00632325();
            param_3 = param_3 & 0xfffffffd;
        }
        if ((param_3 & 2) == 0) {
            param_3 = param_3 | 0x41;
        } else {
            if ((param_3 & 0x40) != 0) {
                FUN_00632325();
                param_3 = param_3 & 0xfffffffd;
            }
            if ((param_3 & 2) == 0) {
                param_3 = param_3 | 0x41;
            }
        }
    }
LAB_0063a574:
    if (iVar2 == 1) {
        if ((((param_3 & 2) != 0) && (iVar2 != 3)) && (iVar2 != 4)) {
            FUN_00632325();
            param_3 = param_3 & 0xfffffffd;
        }
        if ((param_3 & 0x40) != 0) {
            if (iVar2 != 2) {
                FUN_00632325();
                param_3 = param_3 & 0xffffffbf;
            }
            if (((param_3 & 0x40) != 0) && ((param_3 & 0x20) != 0)) {
                FUN_00632325();
                param_3 = param_3 & 0xffffffbf;
            }
        }
        if ((param_3 & 1) != 0) {
            FUN_00632325();
            param_3 = param_3 & 0xfffffffe;
        }
        if ((param_3 & 8) != 0) {
            FUN_00632325();
            param_3 = param_3 & 0xfffffff7;
        }
    }
    if (((((param_3 & 4) != 0) && (iVar2 != 3)) && (iVar2 != 4)) && (iVar2 != 2)) {
        FUN_00632325();
        param_3 = param_3 & 0xfffffffb;
    }
    if (iVar2 == 5) {
        FUN_00632729();
        param_3 = param_3 | 0x40;
    }
    local_18 = 0;
    *(std::uint32_t*)(iVar3 + 0x1c) = param_3;
    if (param_4 == 0) {
        if ((((iVar2 == 0) || (iVar2 == 3)) || (iVar2 == 4)) && ((param_3 & 2) != 0)) {
            uVar5 = FUN_00634bad(5, 0, 0, iVar4);
            *(int*)(iVar3 + 0x24) = uVar5;
        }
    } else {
        int iVar7;
        if (*(int*)(param_4 + 4) == 0xd) {
            uVar5 = 0;
            iVar6 = param_4;
        } else {
            iVar6 = *(int*)(iVar3 + 0x24);
            if (iVar6 == 0) {
                iVar7 = 0;
            } else {
                iVar7 = *(int*)(iVar6 + 0x10);
            }
            iVar8 = FUN_00632959(iVar7);
            uVar5 = 1;
            if (*(int*)(iVar3 + 0x14) != iVar8) {
                FUN_0063477e(iVar4, *(int*)(param_1 + 0x18), *(int*)(iVar3 + 0x20), iVar7, 1);
                *(int*)(iVar3 + 0x24) = 0;
                goto LAB_0063a732;
            }
        }
        uVar5 = FUN_0063769f(*(int*)(iVar3 + 0x20), iVar6, uVar5);
        *(int*)(iVar3 + 0x24) = uVar5;
    }
LAB_0063a732:
    if (*(int*)(iVar3 + 0x24) == 0) {
        if (iVar2 == 0) {
            iVar6 = FUN_0063284b(*(int*)(iVar3 + 0x20));
            if (iVar6 == 0) goto LAB_0063a931;
            if ((param_3 & 2) == 0) goto LAB_0063a8c1;
        } else {
LAB_0063a8c1:
            if ((((iVar2 != 3) && (iVar2 != 4)) ||
                 (iVar6 = FUN_0063284b(*(int*)(iVar3 + 0x20)), iVar6 == 0)) && (iVar2 != 5))
                goto LAB_0063a8fc;
        }
        FUN_00632325();
        (void)local_4c;
LAB_0063a8fc:
        if ((((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) || (*(int*)(iVar3 + 0x2c) == 0))
            goto LAB_0063a931;
        FUN_00632325();
    } else {
        if (iVar2 == 1) {
            pcVar12 = "initializer";
            pcVar10 = "'%s': %s cannot have %ss";
            FUN_00632325();
            (void)pcVar10; (void)pcVar12;
        } else if ((iVar2 != 2) || (FUN_006328e2(*(int*)(iVar3 + 0x20)) != 0)) {
            if (((param_3 & 0x10) == 0) && ((param_3 & 0x20) != 0)) {
                FUN_00632325();
            } else if (((param_3 & 0x50) == 0) ||
                       (FUN_0063324e(*(int*)(iVar3 + 0x24)) != 0)) {
                iVar6 = FUN_00634446(*(int*)(iVar3 + 0x20),
                                     *(int*)(*(int*)(iVar3 + 0x24) + 0x10), 0);
                if (iVar6 != 0) {
                    if ((param_3 & 0x40) != 0) {
                        uVar5 = FUN_00639498(*(int*)(iVar3 + 0x24));
                        *(int*)(iVar3 + 0x28) = uVar5;
                    }
                    if (((param_3 & 0x50) == 0) &&
                        (FUN_0063284b(*(int*)(iVar3 + 0x20)) != 0)) {
                        uVar5 = FUN_00639498(*(int*)(iVar3 + 0x24));
                    } else {
                        uVar5 = 0;
                        if (((param_3 & 0x10) != 0) || ((param_3 & 0x40) == 0)) {
                            uVar5 = *(int*)(iVar3 + 0x24);
                            *(int*)(iVar3 + 0x24) = 0;
                            uVar9 = FUN_00637598();
                            local_18 = (std::uint32_t)FUN_00639be6(
                                nullptr, 0x14, (int*)(std::intptr_t)uVar9,
                                (int*)(std::intptr_t)uVar5, 1);
                            goto LAB_0063a8fc;
                        }
                    }
                    *(int*)(iVar3 + 0x24) = uVar5;
                    goto LAB_0063a8fc;
                }
                FUN_0063477e(iVar4, *(int*)(param_1 + 0x18), *(int*)(iVar3 + 0x20),
                             *(int*)(*(int*)(iVar3 + 0x24) + 0x10), 0);
            } else {
                FUN_00632325();
            }
            *(int*)(iVar3 + 0x24) = 0;
            goto LAB_0063a8fc;
        } else {
            pcVar12 = "default value";
            pcVar10 = "'%s': non-numeric uniform %s cannot have %ss";
            FUN_00632325();
            (void)pcVar10; (void)pcVar12;
        }
        *(int*)(iVar3 + 0x24) = 0;
    }
LAB_0063a931:
    if (((*(int*)(local_c + 0x1c) != 0) && (iVar2 != 0)) && (iVar2 != 2)) {
        FUN_00632325();
        *(int*)(local_c + 0x1c) = 0;
    }
    iVar2 = FUN_0063395f();
    if (iVar2 < 0) {
        return 0;
    }
    if (local_18 != 0) {
        iVar2 = FUN_006333b4((int)local_18);
        *(int*)(local_10 + 0xc) = iVar2;
        if (iVar2 == 0) {
            return 0;
        }
    }
    return local_10;
}

// 0x63a9d8 — observed shape: call-expression builder. Resolves the callee
// against the declared/intrinsic tables, walks the actual-parameter list,
// pairs each declared parameter (input/output flags at +0x1c) with the
// corresponding argument, and reports "undeclared identifier" or
// "does not take %u parameter%s" on mismatch.
// 0x63a9d8 — observed shape
int FUN_0063a9d8(void* self, int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar2;
    int uVar3;
    int iVar4;
    int uVar5;
    int iVar6;
    const char* puVar7;
    const char* pcVar9;
    int local_30;
    int local_2c;
    int local_28;
    int* local_24;
    int* local_20;
    int local_1c;
    int local_18;
    int local_14;
    int local_10;
    int local_c;
    void* local_8;

    local_14 = 0;
    local_1c = 0;
    local_18 = 0;
    local_2c = 0;
    local_30 = 0;
    if ((param_1 == 0) || (*(int*)(param_1 + 4) != 3)) {
        return 0;
    }
    iVar6 = param_1 + 0x10;
    if (*(int*)((char*)self + 0x18) == 0) {
        uVar3 = 0;
    } else {
        uVar3 = *(int*)(*(int*)((char*)self + 0x18) + 0x1c);
    }
    uVar5 = 6;
    if (param_3 != 0) {
        uVar5 = 0x16;
    }
    local_c = iVar6;
    local_8 = self;
    iVar4 = FUN_00636edb(2, iVar6, uVar3, param_2, *(int*)((char*)self + 0x10),
                         uVar5, (int)(std::intptr_t)&local_14, (int)(std::intptr_t)&local_18);
    bool bVar8 = iVar4 == 0;
    if (iVar4 < 0) {
        return 0;
    }
    if (param_3 == 0) {
        if (bVar8) goto LAB_0063ab00;
        iVar4 = FUN_00633aa9(iVar6, param_2, (int)(std::intptr_t)&local_1c,
                             (int)(std::intptr_t)&local_18);
        if (iVar4 < 0) {
            return 0;
        }
        if (iVar4 == 0) {
            bVar8 = true;
            goto LAB_0063aa81;
        }
    LAB_0063aa85:
        iVar4 = FUN_00636edb(2, iVar6, 0, 0, *(int*)((char*)local_8 + 0x10), 2,
                             (int)(std::intptr_t)&local_14, (int)(std::intptr_t)&local_18);
        if (iVar4 < 0) {
            return 0;
        }
        if (iVar4 == 0) {
            bVar8 = true;
        }
    } else {
    LAB_0063aa81:
        if (!bVar8) goto LAB_0063aa85;
    }
    if (param_3 == 0) {
        if (!bVar8) {
            iVar4 = FUN_00633aa9(iVar6, 0, (int)(std::intptr_t)&local_1c,
                                 (int)(std::intptr_t)&local_18);
            if (iVar4 < 0) {
                return 0;
            }
            if (iVar4 != 0) goto LAB_0063aad8;
            bVar8 = true;
        }
    } else {
        if (!bVar8) {
        LAB_0063aad8:
            FUN_00632325();
            (void)local_8; (void)iVar6;
            return 0;
        }
    }
    if (local_1c != 0) {
        local_14 = local_1c;
    }
LAB_0063ab00:
    local_20 = &local_2c;
    local_24 = &local_30;
    iVar4 = param_2;
    for (local_10 = *(int*)(local_14 + 0x24); local_10 != 0; local_10 = *(int*)(local_10 + 0xc)) {
        iVar1 = *(int*)(local_10 + 8);
        iVar2 = *(int*)(local_10 + 0xc);
        bVar8 = false;
        if ((iVar2 != 0) && (iVar6 = local_c, *(int*)(*(int*)(iVar2 + 8) + 4) == 0xc)) {
            bVar8 = true;
            local_10 = iVar2;
        }
        if ((param_3 == 0) || ((*(unsigned char*)(*(int*)(iVar1 + 0x18) + 0x1c) & 0x40) != 0)) {
            if (iVar4 == 0) {
                if (!bVar8) goto LAB_0063acb4;
            } else {
                local_28 = *(int*)(iVar1 + 0x18);
                uVar3 = *(int*)(local_28 + 0x20);
                if (*(int*)(iVar4 + 8) == 0) {
                    param_1 = 0;
                } else {
                    param_1 = *(int*)(*(int*)(iVar4 + 8) + 0x10);
                }
                iVar6 = FUN_0060d19b(0x14);
                if (iVar6 == 0) {
                    iVar6 = 0;
                } else {
                    iVar6 = FUN_0065ac49(0, 0, "Inputs");
                }
                *local_20 = iVar6;
                if (iVar6 == 0) {
                    return 0;
                }
                iVar6 = FUN_0060d19b(0x14);
                if (iVar6 == 0) {
                    iVar6 = 0;
                } else {
                    iVar6 = FUN_0065ac49(0, 0, "Outputs");
                }
                *local_24 = iVar6;
                if (iVar6 == 0) {
                    return 0;
                }
                if ((*(unsigned char*)(local_28 + 0x1c) & 0x10) != 0) {
                    iVar6 = FUN_00634446(uVar3, param_1, 0);
                    if (iVar6 == 0) {
                        uVar5 = uVar3;
                        goto LAB_0063ace9;
                    }
                    uVar5 = FUN_0063769f(uVar3, *(int*)(iVar4 + 8), 0, 0);
                    *(int*)(*local_20 + 8) = uVar5;
                }
                if ((*(unsigned char*)(local_28 + 0x1c) & 0x20) != 0) {
                    iVar6 = FUN_0063284b(param_1);
                    if ((iVar6 != 0) || (iVar6 = FUN_00634446(param_1, uVar3, 0), iVar6 == 0)) {
                        uVar5 = param_1;
                        param_1 = uVar3;
                    LAB_0063ace9:
                        FUN_0063477e(local_c, *(int*)(local_c + 8), uVar5, param_1, 0);
                        return 0;
                    }
                    iVar6 = FUN_00637598();
                    if (iVar6 == 0) {
                        return 0;
                    }
                    iVar6 = FUN_0063769f(param_1, iVar6, 0, 0);
                    if (iVar6 == 0) {
                        return 0;
                    }
                    iVar6 = FUN_00639be6(nullptr, 0x15, (int*)(std::intptr_t)*(int*)(iVar4 + 8),
                                         (int*)(std::intptr_t)iVar6, 1);
                    if (iVar6 == 0) {
                        return 0;
                    }
                    *(int*)(*local_24 + 8) = iVar6;
                }
                iVar4 = *(int*)(iVar4 + 0xc);
                local_20 = (int*)(*local_20 + 0xc);
                local_24 = (int*)(*local_24 + 0xc);
                iVar6 = local_c;
            }
        }
    }
    if (iVar4 == 0) {
    LAB_0063acb4:
        if (local_10 == 0) {
            iVar4 = FUN_0060d19b(0x50);
            if (iVar4 == 0) {
                iVar6 = 0;
            } else {
                iVar6 = FUN_0065b52c(0, (local_1c != 0) + 0x19, 0, 0, 1, iVar6);
            }
            if (iVar6 == 0) {
                return 0;
            }
            if (*(int*)(local_14 + 0x20) != 0) {
                iVar4 = (*(int(**)(void))(**(int**)(local_14 + 0x20) + 4))();
                *(int*)(iVar6 + 0x10) = iVar4;
                if (iVar4 == 0) {
                    return 0;
                }
            }
            *(int*)(iVar6 + 0x20) = local_18;
            iVar4 = FUN_0060d19b(0x14);
            if (iVar4 == 0) {
                iVar4 = 0;
            } else {
                iVar4 = FUN_0065ac49(0, 0, "Parameters");
            }
            *(int*)(iVar6 + 0x24) = iVar4;
            if (iVar4 == 0) {
                return 0;
            }
            *(int*)(iVar4 + 8) = local_2c;
            *(int*)(*(int*)(iVar6 + 0x24) + 0xc) = local_30;
            FUN_0063336c(iVar6);
            iVar4 = FUN_0063324e(iVar6);
            if (iVar4 == 0) {
                return iVar6;
            }
            iVar4 = FUN_00639498(iVar6);
            if (iVar4 == 0) {
                return iVar6;
            }
            return iVar4;
        }
    }
    iVar4 = 0;
    for (; param_2 != 0; param_2 = *(int*)(param_2 + 0xc)) {
        iVar4 = iVar4 + 1;
    }
    puVar7 = "";
    if (local_1c == 0) {
        if (iVar4 == 1) {
            puVar7 = "s";
        }
        uVar3 = *(int*)(iVar6 + 8);
        pcVar9 = "'%s': function does not take %u parameter%s";
    } else {
        if (iVar4 == 1) {
            puVar7 = "s";
        }
        uVar3 = *(int*)(iVar6 + 8);
        pcVar9 = "'%s': intrinsic function does not take %u parameter%s";
    }
    FUN_00632325();
    (void)local_8; (void)iVar6; (void)uVar3; (void)iVar4; (void)puVar7; (void)pcVar9;
    return 0;
}

// 0x63adf0 — observed shape: constant-expression builder. Reads the target
// version/type word, selects the integer literal opcode from its high half
// (0xfffe.. -> 0x1a/0x1b, 0xffff.. -> 0x19/0x1a), then nests two 0x50 nodes
// with a 0x24 literal (kind 3) and a "Value" list.
// 0x63adf0 — observed shape
int FUN_0063adf0(int param_1, int param_2, int param_3, int param_4)
{
    int iVar1;
    int iVar2;
    unsigned char local_1c[4];
    std::uint32_t local_18;
    int local_10;
    int local_8;

    if (param_1 == 0) {
        return 0;
    }
    if (param_2 == 0) {
        return 0;
    }
    iVar2 = param_1 + 0x10;
    local_10 = iVar2;
    iVar1 = FUN_005f7fa4(*(int*)(param_1 + 0x18), 2, (int)(std::intptr_t)local_1c);
    if (iVar1 < 0) {
        FUN_00632325();
        return 0;
    }
    if ((local_18 & 0xffff0000) == 0xfffe0000) {
        param_4 = (std::uint32_t)(param_4 != 0) * 2 + 0x1a;
    } else if ((local_18 & 0xffff0000) == 0xffff0000) {
        param_4 = (std::uint32_t)(param_4 != 0) * 2 + 0x19;
    }
    iVar1 = FUN_0060d19b(0x50);
    if (iVar1 == 0) {
        local_8 = 0;
    } else {
        local_8 = FUN_0065b52c(0, 0x1b, 0, 0, 1, iVar2);
    }
    iVar2 = local_8;
    if (local_8 != 0) {
        iVar1 = FUN_0060d19b(0x24);
        if (iVar1 == 0) {
            iVar1 = 0;
        } else {
            iVar1 = FUN_0065b202(3, param_4, 1, 1, 0x200);
        }
        *(int*)(iVar2 + 0x10) = iVar1;
        if (iVar1 != 0) {
            iVar1 = FUN_0065abf1(param_1);
            *(int*)(iVar2 + 0x20) = iVar1;
            if (iVar1 != 0) {
                iVar1 = FUN_0063a9d8(nullptr, param_2, param_3, 1);
                *(int*)(iVar2 + 0x24) = iVar1;
                if (iVar1 != 0) {
                    iVar2 = FUN_0060d19b(0x50);
                    if (iVar2 == 0) {
                        iVar2 = 0;
                    } else {
                        iVar2 = FUN_0065b52c(0, 0, 0, 0, 1, local_10);
                    }
                    if (iVar2 != 0) {
                        iVar1 = FUN_0060d19b(0x24);
                        if (iVar1 == 0) {
                            iVar1 = 0;
                        } else {
                            iVar1 = FUN_0065b202(3, param_4, 1, 1, 0x200);
                        }
                        *(int*)(iVar2 + 0x10) = iVar1;
                        if (iVar1 != 0) {
                            iVar1 = FUN_0060d19b(0x14);
                            if (iVar1 == 0) {
                                iVar1 = 0;
                            } else {
                                iVar1 = FUN_0065ac49(0, 0, "Value");
                            }
                            *(int*)(iVar2 + 0x20) = iVar1;
                            if (iVar1 != 0) {
                                iVar1 = FUN_0060d19b(0x40);
                                if (iVar1 == 0) {
                                    iVar1 = 0;
                                } else {
                                    iVar1 = FUN_0065b679(4, local_8, local_10);
                                }
                                *(int*)(*(int*)(iVar2 + 0x20) + 8) = iVar1;
                                if (iVar1 != 0) {
                                    FUN_0063336c(iVar2);
                                    return iVar2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// 0x63afb8 — observed shape: opcode dispatcher for the declaration grammar.
// Pops up to four operands from the receiver's free list into the local
// operand stack (apuStack_64), switches on the opcode, builds a node through
// the corresponding constructor, then pushes the result back onto the
// receiver's value stack (offsets +8/+0xc) or reports via FUN_006323c8.
// 0x63afb8 — observed shape
void FUN_0063afb8(void* self, int param_1, int param_2)
{
    int iVar1;
    int iVar2;
    int iVar3;
    unsigned char* puVar4;
    int iVar5;
    unsigned char* puVar6;
    long long lVar7;
    unsigned long long uVar8;
    unsigned long long uVar9;
    const char* pcVar10;
    unsigned int uVar11;
    unsigned int uVar12;
    unsigned char* apuStack_64[4];
    unsigned int uStack_54 = 0;
    unsigned char auStack_24[28];
    unsigned char* local_8;

    puVar6 = (unsigned char*)0;
    local_8 = (unsigned char*)0;
    if (*(int*)((char*)self + 0x44) != 0) {
        return;
    }
    while (param_2 != 0) {
        iVar5 = *(int*)((char*)self + 8);
        param_2 = param_2 - 1;
        if (iVar5 == 0) goto LAB_0063be5a;
        apuStack_64[param_2] = *(unsigned char**)(iVar5 + 8);
        *(int*)((char*)self + 8) = *(int*)(iVar5 + 0xc);
        *(int*)(iVar5 + 8) = 0;
        *(int*)(iVar5 + 0xc) = *(int*)((char*)self + 0xc);
        *(int*)((char*)self + 0xc) = iVar5;
    }
    switch (param_1) {
    case 0:
        iVar5 = FUN_0060d19b(0x20);
        if (iVar5 == 0) break;
        apuStack_64[0] = (unsigned char*)0;
        uVar8 = 0;
        uVar12 = 0;
    code_r0x0063b02d:
        puVar6 = (unsigned char*)FUN_0065aec0(uVar12, uVar8, (unsigned int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b03b;
    case 1:
        iVar5 = FUN_0060d19b(0x20);
        if (iVar5 != 0) {
            uVar8 = *(unsigned long long*)((char*)self + 0x54);
            uVar12 = *(unsigned int*)((char*)self + 0x50);
            goto code_r0x0063b02d;
        }
        break;
    case 2: case 5: case 6: case 7: case 8: case 9: case 10: case 0x12: case 0x14:
    case 0x21: case 0x24: case 0x25: case 0x28: case 0x2a: case 0x2d: case 0x2e:
    case 0x2f: case 0x30: case 0x4e: case 0x51: case 0x56: case 0x59: case 0x5f:
    case 0x61: case 100: case 0x65: case 0x66: case 0x68: case 0x6b: case 0x6e:
    case 0x79: case 0x80: case 0x86: case 0x8c: case 0x93: case 0x97: case 0x9e:
    case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xad: case 0xb5: case 0xb7:
    case 0xb9: case 0xbc: case 0xbd: case 0xbe: case 0xbf: case 0xc0: case 199:
    case 0xd4: case 0xd5: case 0xd6: case 0xdb: case 0xe1: case 0xe3: case 0xe7:
    case 0xea: case 0xef: case 0xf2: case 0xf4: case 0xf6: case 0xfd: case 0x102:
    case 0x104: case 0x105: case 0x106: case 0x108: case 0x109: case 0x10b:
    case 0x10d: case 0x10f: case 0x111: case 0x118: case 0x119: case 0x121:
        puVar6 = apuStack_64[0];
        goto LAB_0063b27e;
    case 3: case 0x52: case 0x62: case 0x6c: case 0x7a: case 0x8d: case 0x94:
    case 0x9f: case 0x107:
        goto code_r0x0063b06f;
    case 4: case 0x2c: case 0x4a: case 0x58: case 0x5c: case 0x5e: case 0x67:
    case 0x74: case 0x75: case 0x78: case 0x88: case 0x8f: case 0x96: case 0x9a:
    case 0xa0: case 0xb3: case 0xb6: case 0xb8: case 0xcc: case 0x101: case 0x117:
        goto code_r0x0063b8b4;
    case 0xb: case 0x15: case 0x81:
        FUN_006327be();
        puVar6 = apuStack_64[0];
        goto LAB_0063b27e;
    case 0xc:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 == 0) break;
        lVar7 = 2;
    code_r0x0063b09d:
        puVar6 = (unsigned char*)FUN_0065b0f3(lVar7, 0);
        goto code_r0x0063b03b;
    case 0xd:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x40; goto code_r0x0063b09d; }
        break;
    case 0xe:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 1; goto code_r0x0063b09d; }
        break;
    case 0xf:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 4; goto code_r0x0063b09d; }
        break;
    case 0x10:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x100; goto code_r0x0063b09d; }
        break;
    case 0x11:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 8; goto code_r0x0063b09d; }
        break;
    case 0x13:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) {
            lVar7 = (long long)((unsigned long long)(std::uintptr_t)apuStack_64[0] << 0x20);
            goto code_r0x0063b09d;
        }
        break;
    case 0x16:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x200; goto code_r0x0063b09d; }
        break;
    case 0x17:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x400; goto code_r0x0063b09d; }
        break;
    case 0x18:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x800; goto code_r0x0063b09d; }
        break;
    case 0x19:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 == 0) goto code_r0x0063b190;
        uVar8 = 0;
    code_r0x0063b7c1:
        apuStack_64[0] = (unsigned char*)FUN_0065b0f3(uVar8, (unsigned int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b192;
    case 0x1a:
        *(unsigned char**)(apuStack_64[0] + 0x18) = apuStack_64[1];
        goto code_r0x0063b19a;
    case 0x1d:
        FUN_0065b0f3(0, 0, *(unsigned int*)(*(int*)(apuStack_64[0] + 8) + 0x18));
        puVar4 = auStack_24;
        puVar6 = apuStack_64[0];
        goto code_r0x0063b19b;
    case 0x1e:
        *(unsigned int*)(apuStack_64[0] + 0x18) = *(unsigned int*)(*(int*)(apuStack_64[1] + 8) + 0x18);
        FUN_00635a73((int)(std::intptr_t)apuStack_64[0]);
        *(unsigned int*)(apuStack_64[0] + 0x18) = 0;
        goto code_r0x0063b1e5;
    case 0x1f:
        /* listing elides the arguments; operands are taken from the stack head */
        puVar6 = (unsigned char*)FUN_0063961c(
            self, (int)(std::intptr_t)apuStack_64[0], (int)(std::intptr_t)apuStack_64[1]);
        goto code_r0x0063b03b;
    case 0x20:
        uVar12 = (unsigned int)FUN_0063961c(
            self, (int)(std::intptr_t)apuStack_64[0], (int)(std::intptr_t)apuStack_64[1]);
        FUN_00632420(uVar12);
        goto code_r0x0063b06f;
    case 0x22:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 == 0) break;
        pcVar10 = "TypeDefs";
    code_r0x0063b237:
        apuStack_64[1] = (unsigned char*)0;
    code_r0x0063b238:
        puVar6 = (unsigned char*)FUN_0065ac49((int)(std::intptr_t)apuStack_64[0],
                                             (int)(std::intptr_t)apuStack_64[1], pcVar10);
        goto code_r0x0063b03b;
    case 0x23:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "TypeDefs"; goto code_r0x0063b238; }
        break;
    case 0x26:
        FUN_00636edb(0, (int)(std::intptr_t)(apuStack_64[0] + 0x10), 0, 0,
                     *(int*)((char*)self + 0x10), 1, (int)(std::intptr_t)&local_8, 0);
        goto code_r0x0063b27b;
    case 0x27:
        iVar5 = FUN_00636edb(0, (int)(std::intptr_t)(apuStack_64[0] + 0x10), 0, 0,
                             *(int*)((char*)self + 0x10), 1, (int)(std::intptr_t)&local_8, 0);
        puVar6 = local_8;
        if (iVar5 == 0) {
            if ((local_8 != (unsigned char*)0) && (*(int*)(local_8 + 4) != 1)) {
                FUN_00632325();
            }
            goto LAB_0063b27e;
        }
    code_r0x0063b27b:
        puVar6 = local_8;
        goto LAB_0063b27e;
    case 0x29:
        FUN_00634393();
        puVar6 = apuStack_64[1];
        goto LAB_0063b27e;
    case 0x2b:
        puVar6 = (unsigned char*)FUN_00639943((int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1]);
        goto code_r0x0063b03b;
    case 0x31:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 == 0) break;
        uVar12 = 0;
    code_r0x0063b32a:
        uVar8 = 0x100000001ULL;
        uVar11 = 0;
    code_r0x0063b32b:
        puVar6 = (unsigned char*)FUN_0065b202(uVar11, uVar12, (int)uVar8, 0);
        goto code_r0x0063b03b;
    case 0x32:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 4; goto code_r0x0063b32a; }
        break;
    case 0x33:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 10; goto code_r0x0063b32a; }
        break;
    case 0x34:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0xb; goto code_r0x0063b32a; }
        break;
    case 0x35:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0xc; goto code_r0x0063b32a; }
        break;
    case 0x36:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar8 = 0x400000001ULL; uVar12 = 0xb; uVar11 = 1; goto code_r0x0063b32b; }
        break;
    case 0x37:
        puVar6 = (unsigned char*)FUN_00639814((std::uint32_t)(std::uintptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1]);
        goto code_r0x0063b03b;
    case 0x38:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar8 = 0x400000004ULL; uVar12 = 0xb; uVar11 = 2; goto code_r0x0063b32b; }
        break;
    case 0x39:
        puVar6 = (unsigned char*)FUN_0063989a((std::uint32_t)(std::uintptr_t)apuStack_64[0],
                                              (std::uint32_t)(std::uintptr_t)apuStack_64[1],
                                              (int)(std::intptr_t)apuStack_64[2]);
        goto code_r0x0063b03b;
    case 0x3a:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0xe; goto code_r0x0063b594; }
        break;
    case 0x3b:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0xf; goto code_r0x0063b594; }
        break;
    case 0x3c:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x10; goto code_r0x0063b594; }
        break;
    case 0x3d:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x11; goto code_r0x0063b594; }
        break;
    case 0x3e:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x12; goto code_r0x0063b594; }
        break;
    case 0x3f:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x13; goto code_r0x0063b594; }
        break;
    case 0x40:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x14; goto code_r0x0063b594; }
        break;
    case 0x41:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x15; goto code_r0x0063b594; }
        break;
    case 0x42:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x16; goto code_r0x0063b594; }
        break;
    case 0x43:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x17; goto code_r0x0063b594; }
        break;
    case 0x44:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x18; goto code_r0x0063b594; }
        break;
    case 0x45:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x19; goto code_r0x0063b594; }
        break;
    case 0x46:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x1a; goto code_r0x0063b594; }
        break;
    case 0x47:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x1b; goto code_r0x0063b594; }
        break;
    case 0x48:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x1c; goto code_r0x0063b594; }
        break;
    case 0x49:
        iVar5 = FUN_0060d19b(0x24);
        if (iVar5 != 0) { uVar12 = 0x1d; goto code_r0x0063b594; }
        break;
    code_r0x0063b594:
        uVar8 = 0x100000001ULL;
        uVar11 = 3;
        goto code_r0x0063b32b;
    case 0x4b: case 0x5d: case 0x76: case 0x89: case 0x90: case 0x9b:
        goto code_r0x0063b1e5;
    case 0x4c: case 0x4d:
        puVar6 = (unsigned char*)FUN_006397cc((int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1]);
        goto code_r0x0063b03b;
    case 0x4f:
        FUN_00634393();
        goto code_r0x0063b1e5;
    case 0x50: case 0x60: case 0x77: case 0x9c:
        goto code_r0x0063b5cc;
    case 0x53: case 99: case 0x8b: case 0x9d:
        goto code_r0x0063b5da;
    case 0x54: case 0x55:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "Semantics"; goto code_r0x0063b237; }
        break;
    case 0x57:
        puVar6 = (unsigned char*)FUN_0065ac0a();
        goto code_r0x0063b03b;
    case 0x5a:
        iVar5 = FUN_0060d19b(0x18);
        if (iVar5 == 0) break;
    code_r0x0063b624:
        puVar6 = (unsigned char*)FUN_0065b8b3();
        goto code_r0x0063b03b;
    case 0x5b:
        iVar5 = FUN_0060d19b(0x18);
        if (iVar5 != 0) goto code_r0x0063b624;
        break;
    case 0x69: case 0x7b:
        puVar6 = apuStack_64[1];
        goto code_r0x0063b64f;
    case 0x6a:
        puVar6 = (unsigned char*)FUN_0065ac0a();
        goto code_r0x0063b64f;
    case 0x6d:
        puVar6 = (unsigned char*)FUN_0063a0b3(
            self, (int)(std::intptr_t)apuStack_64[0],
            (std::uint32_t*)(std::intptr_t)apuStack_64[1],
            (std::uint32_t)(std::uintptr_t)apuStack_64[2],
            (int)(std::intptr_t)apuStack_64[3]);
        goto code_r0x0063b03b;
    case 0x6f:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "VariableDim"; goto code_r0x0063b237; }
        break;
    case 0x70:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "VariableDim"; goto code_r0x0063b238; }
        break;
    case 0x71:
        func_0x006338c8();
        *(int*)((char*)self + 0x18) = 0;
        puVar6 = apuStack_64[0];
        goto LAB_0063b27e;
    case 0x72:
        if ((apuStack_64[0] != (unsigned char*)0) &&
            (iVar5 = *(int*)(apuStack_64[0] + 8), iVar5 != 0)) {
            iVar3 = *(int*)(iVar5 + 0x18);
            *(unsigned char**)(iVar5 + 0x1c) = apuStack_64[1];
            *(unsigned char**)(iVar3 + 0x28) = apuStack_64[2];
            *(int*)(iVar3 + 0x3c) = 1;
            for (iVar3 = *(int*)((char*)self + 0x10); iVar3 != 0; iVar3 = *(int*)(iVar3 + 0x20)) {
                for (iVar2 = FUN_006325ec(); iVar2 != 0; iVar2 = *(int*)(iVar2 + 0xc)) {
                    iVar1 = *(int*)(iVar2 + 8);
                    if (((iVar1 != 0) && (*(int*)(iVar1 + 4) == 6)) &&
                        (*(int*)(iVar1 + 0x24) == *(int*)(iVar5 + 0x24))) {
                        if (*(int*)(*(int*)(*(int*)(iVar2 + 8) + 0x18) + 0x3c) != 0) {
                            FUN_00632325();
                        }
                        *(int*)(*(int*)(*(int*)(iVar2 + 8) + 0x18) + 0x3c) = 1;
                        goto code_r0x0063b770;
                    }
                }
            }
        }
    code_r0x0063b770:
        func_0x006338c8();
        *(int*)((char*)self + 0x18) = 0;
        puVar6 = apuStack_64[0];
        goto LAB_0063b27e;
    case 0x73:
        puVar6 = (unsigned char*)FUN_00639117((int)(std::intptr_t)apuStack_64[1],
                                              (int)(std::intptr_t)apuStack_64[2],
                                              (int)(std::intptr_t)apuStack_64[3]);
        FUN_00632420((unsigned int)(std::intptr_t)puVar6);
    code_r0x0063b64f:
        func_0x00632709();
        goto LAB_0063b27e;
    case 0x7c:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { uVar8 = 0x10; goto code_r0x0063b7c1; }
    code_r0x0063b190:
        apuStack_64[0] = (unsigned char*)0;
    code_r0x0063b192:
        FUN_00632420((unsigned int)(std::uintptr_t)apuStack_64[0]);
        goto code_r0x0063b19a;
    case 0x7d:
        *(unsigned char**)(apuStack_64[0] + 0x18) = apuStack_64[1];
        if ((apuStack_64[0][0x10] & 0x70) == 0) {
            *(unsigned int*)(apuStack_64[0] + 0x10) = *(unsigned int*)(apuStack_64[0] + 0x10) | 0x10;
        }
    code_r0x0063b19a:
        puVar6 = apuStack_64[0];
        puVar4 = apuStack_64[0];
    code_r0x0063b19b:
        FUN_00635a73((int)(std::intptr_t)puVar4);
        goto LAB_0063b27e;
    case 0x82:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x10; goto code_r0x0063b09d; }
        break;
    case 0x83:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x20; goto code_r0x0063b09d; }
        break;
    case 0x84:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x30; goto code_r0x0063b09d; }
        break;
    case 0x85:
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 != 0) { lVar7 = 0x50; goto code_r0x0063b09d; }
        break;
    case 0x87:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 == 0) {
            puVar6 = (unsigned char*)0;
        } else {
            puVar6 = (unsigned char*)FUN_0065ac49(0, 0, "Stmts");
        }
        iVar5 = FUN_00632420((unsigned int)(std::uintptr_t)puVar6);
        if (iVar5 != 0) {
            iVar5 = FUN_0060d19b(0x30);
            if (iVar5 == 0) {
                uVar12 = 0;
            } else {
                uVar12 = (unsigned int)FUN_0065b01d(3, (int)(std::intptr_t)apuStack_64[0],
                                                    (int)(std::intptr_t)apuStack_64[2],
                                                    (int)(std::intptr_t)apuStack_64[1]);
            }
            *(unsigned int*)(puVar6 + 8) = uVar12;
            FUN_00632420(uVar12);
        }
        *(int*)((char*)self + 0x50) = *(int*)((char*)self + 0x50) + 1;
        goto LAB_0063b27e;
    case 0x8a:
        FUN_00632455();
        goto code_r0x0063b8b4;
    case 0x8e:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 == 0) {
            puVar6 = (unsigned char*)0;
        } else {
            puVar6 = (unsigned char*)FUN_0065ac49(0, 0, "Passes");
        }
        iVar5 = FUN_00632420((unsigned int)(std::uintptr_t)puVar6);
        if (iVar5 == 0) goto LAB_0063b27e;
        iVar5 = FUN_0060d19b(0x30);
        if (iVar5 == 0) {
        code_r0x0063b970:
            puVar4 = (unsigned char*)0;
        } else {
            puVar4 = (unsigned char*)FUN_0065b01d(4, (int)(std::intptr_t)apuStack_64[0],
                                                  (int)(std::intptr_t)apuStack_64[2],
                                                  (int)(std::intptr_t)apuStack_64[1]);
        }
        goto code_r0x0063b972;
    case 0x91:
        FUN_00632455();
        *(int*)((char*)self + 0x48) = 0;
    code_r0x0063b8b4:
        puVar6 = (unsigned char*)0;
        goto LAB_0063b27e;
    case 0x92:
        *(int*)((char*)self + 0x48) = 1;
    code_r0x0063b5da:
        puVar6 = (unsigned char*)0;
    code_r0x0063b5dc:
        func_0x006338c8();
        goto LAB_0063b27e;
    case 0x95:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 == 0) {
            puVar6 = (unsigned char*)0;
        } else {
            puVar6 = (unsigned char*)FUN_0065ac49(0, 0, "States");
        }
        iVar5 = FUN_00632420((unsigned int)(std::uintptr_t)puVar6);
        if (iVar5 == 0) goto LAB_0063b27e;
        iVar5 = FUN_0060d19b(0x1c);
        if (iVar5 == 0) goto code_r0x0063b970;
        puVar4 = (unsigned char*)FUN_0065b78c((int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1],
                                              (int)(std::intptr_t)apuStack_64[3]);
    code_r0x0063b972:
        *(unsigned char**)(puVar6 + 8) = puVar4;
        goto code_r0x0063b03c;
    case 0x98:
        *(int*)((char*)self + 0x48) = 1;
        goto LAB_0063b27e;
    case 0x99:
        *(int*)((char*)self + 0x48) = 0;
        goto LAB_0063b27e;
    case 0xa1: case 0xb4:
        puVar6 = (unsigned char*)FUN_006333b4((int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b074;
    case 0xa2:
        apuStack_64[0] = (unsigned char*)0;
        goto code_r0x0063b99d;
    case 0xa3:
    code_r0x0063b99d:
        puVar6 = (unsigned char*)FUN_00639fff(self, (int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b074;
    case 0xa4:
        puVar6 = apuStack_64[0];
        puVar4 = apuStack_64[0];
        apuStack_64[0] = apuStack_64[1];
        goto code_r0x0063b9e2;
    case 0xa5:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "Stmts"; goto code_r0x0063b237; }
        break;
    case 0xa6:
        puVar6 = (unsigned char*)func_0x00633416();
        goto code_r0x0063b074;
    case 0xab: case 0xae:
        puVar6 = (unsigned char*)0;
        puVar4 = apuStack_64[1];
    code_r0x0063b9e2:
        puVar6 = (unsigned char*)FUN_00633499((int)(std::intptr_t)puVar6,
                                              (int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)puVar4);
        goto code_r0x0063b074;
    case 0xac: case 0xaf:
        puVar6 = (unsigned char*)FUN_00633499((int)(std::intptr_t)apuStack_64[1],
                                              (int)(std::intptr_t)apuStack_64[2],
                                              (int)(std::intptr_t)apuStack_64[3],
                                              uStack_54);
        goto code_r0x0063b5dc;
    case 0xb0:
        apuStack_64[2] = (unsigned char*)0;
        goto code_r0x0063ba0e;
    case 0xb1:
    code_r0x0063ba0e:
        puVar6 = (unsigned char*)FUN_00638495((int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1],
                                              (int)(std::intptr_t)apuStack_64[2]);
        goto code_r0x0063b074;
    case 0xb2:
    code_r0x0063b5cc:
        FUN_00632455();
        puVar6 = (unsigned char*)0;
        goto LAB_0063b27e;
    case 0xba:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "DwordExpr"; goto code_r0x0063b237; }
        break;
    case 0xbb:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "DwordExpr"; goto code_r0x0063b238; }
        break;
    case 0xc1:
        uVar8 = 0x3ff0000000000000ULL;
        uVar12 = 1;
        goto code_r0x0063ba79;
    case 0xc2:
        uVar8 = 0;
        uVar12 = 0;
    code_r0x0063ba79:
        puVar6 = (unsigned char*)FUN_00634bad(0, uVar12, (int)uVar8,
                                              (int)((char*)self + 0x20));
        goto code_r0x0063b03b;
    case 0xc3: case 0xc4:
        puVar6 = (unsigned char*)FUN_00634cc5((int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b03b;
    case 0xc5:
        puVar6 = (unsigned char*)FUN_00634d49((int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b03b;
    case 0xc6:
        puVar6 = (unsigned char*)FUN_00637598();
        goto code_r0x0063b03b;
    case 200: case 0xc9:
        uVar12 = 1;
        goto code_r0x0063bac6;
    case 0xca:
        puVar6 = (unsigned char*)FUN_0063a9d8(self, (int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1], 0);
        goto code_r0x0063b03b;
    case 0xcb:
        puVar6 = (unsigned char*)FUN_00632fea((int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b074;
    case 0xcd:
        apuStack_64[0] = apuStack_64[1];
        goto code_r0x0063bb02;
    case 0xce: case 0xcf:
    code_r0x0063bb02:
        puVar6 = (unsigned char*)FUN_006353a8((int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b074;
    case 0xd0:
        uVar12 = 0;
        goto code_r0x0063bb22;
    case 0xd1:
        puVar6 = (unsigned char*)FUN_006354e2((int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b03b;
    case 0xd2:
        uVar12 = 1;
    code_r0x0063bb22:
        puVar6 = (unsigned char*)FUN_0063adf0((int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1],
                                              (int)(std::intptr_t)apuStack_64[2], uVar12);
        goto code_r0x0063b074;
    case 0xd3:
        puVar6 = (unsigned char*)FUN_006355bc((int)(std::intptr_t)apuStack_64[0]);
        goto code_r0x0063b03b;
    case 0xd7:
        puVar6 = (unsigned char*)FUN_006399bc((int*)(std::intptr_t)apuStack_64[0],
                                              (std::uint32_t)(std::uintptr_t)apuStack_64[1]);
        goto code_r0x0063b03b;
    case 0xd8:
        puVar6 = (unsigned char*)FUN_00634f17();
        goto code_r0x0063b03b;
    case 0xd9:
        uVar11 = 1; uVar9 = (unsigned long long)(std::uintptr_t)apuStack_64[0]; uVar12 = 0x21;
        goto code_r0x0063bb72;
    case 0xda:
        uVar11 = 1; uVar9 = (unsigned long long)(std::uintptr_t)apuStack_64[0]; uVar12 = 0x22;
        goto code_r0x0063bb72;
    case 0xdc:
        uVar11 = 1; uVar9 = (unsigned long long)(std::uintptr_t)apuStack_64[0]; uVar12 = 2;
        goto code_r0x0063bb72;
    case 0xdd:
        uVar11 = 1; uVar9 = (unsigned long long)(std::uintptr_t)apuStack_64[0]; uVar12 = 3;
        goto code_r0x0063bb72;
    case 0xde:
        uVar11 = 1; uVar9 = (unsigned long long)(std::uintptr_t)apuStack_64[0]; uVar12 = 4;
        goto code_r0x0063bb72;
    case 0xdf:
        uVar11 = 1; uVar9 = (unsigned long long)(std::uintptr_t)apuStack_64[0]; uVar12 = 5;
        goto code_r0x0063bb72;
    case 0xe0:
        uVar11 = 1; uVar9 = (unsigned long long)(std::uintptr_t)apuStack_64[0]; uVar12 = 6;
        goto code_r0x0063bb72;
    case 0xe2:
        uVar12 = 0;
    code_r0x0063bac6:
        puVar6 = (unsigned char*)FUN_0063769f((int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1],
                                              uVar12, 1);
        goto code_r0x0063b03b;
    case 0xe4:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 7;
        goto code_r0x0063bb72;
    case 0xe5:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 8;
        goto code_r0x0063bb72;
    case 0xe6:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 9;
        goto code_r0x0063bb72;
    case 0xe8:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 10;
        goto code_r0x0063bb72;
    case 0xe9:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0xb;
        goto code_r0x0063bb72;
    case 0xeb:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0xc;
        goto code_r0x0063bb72;
    case 0xec:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0xd;
        goto code_r0x0063bb72;
    case 0xed:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0xe;
        goto code_r0x0063bb72;
    case 0xee:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0xf;
        goto code_r0x0063bb72;
    case 0xf0:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x10;
        goto code_r0x0063bb72;
    case 0xf1:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x11;
        goto code_r0x0063bb72;
    case 0xf3:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x12;
        goto code_r0x0063bb72;
    case 0xf5:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x13;
        goto code_r0x0063bb72;
    case 0xf7:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x15;
        goto code_r0x0063bb72;
    case 0xf8:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x1c;
        goto code_r0x0063bb72;
    case 0xf9:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x1d;
        goto code_r0x0063bb72;
    case 0xfa:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x1e;
        goto code_r0x0063bb72;
    case 0xfb:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x1f;
        goto code_r0x0063bb72;
    case 0xfc:
        uVar11 = 1;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[1] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[0];
        uVar12 = 0x20;
        goto code_r0x0063bb72;
    case 0xfe:
        puVar6 = (unsigned char*)FUN_006378c8((int)(std::intptr_t)apuStack_64[0],
                                              (int)(std::intptr_t)apuStack_64[1],
                                              (int)(std::intptr_t)apuStack_64[2]);
        goto code_r0x0063b03b;
    case 0xff:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "Arguments"; goto code_r0x0063b237; }
        break;
    case 0x100:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 == 0) {
            puVar6 = (unsigned char*)0;
        } else {
            puVar6 = (unsigned char*)FUN_0065ac49((int)(std::intptr_t)apuStack_64[1], 0, "Arguments");
        }
        iVar5 = FUN_00632420((unsigned int)(std::uintptr_t)puVar6);
        if (iVar5 == 0) goto LAB_0063b27e;
    code_r0x0063b06f:
        puVar6 = (unsigned char*)FUN_0065ac0a();
        goto code_r0x0063b074;
    case 0x103:
        iVar5 = FUN_0060d19b(0x14);
        if (iVar5 != 0) { pcVar10 = "Value"; goto code_r0x0063b237; }
        break;
    case 0x10a:
        if ((*(int*)((char*)self + 0x10) != 0) && (*(int*)(*(int*)((char*)self + 0x10) + 0x10) == 7)) {
            FUN_0063237b();
        }
        uVar11 = 0;
        uVar9 = ((unsigned long long)(std::uintptr_t)apuStack_64[0] << 32) |
                (unsigned int)(std::uintptr_t)apuStack_64[1];
        uVar12 = 1;
    code_r0x0063bb72:
        /* FUN_00639be6 receives (param_1 = opcode uVar12, param_2 = uVar9,
           param_3 = uVar11) plus the ECX receiver */
        puVar6 = (unsigned char*)FUN_00639be6(self, (int)uVar12, (int*)(std::intptr_t)uVar9,
                                              (int*)(std::intptr_t)uVar11, 0);
        goto code_r0x0063b03b;
    case 0x10c:
        *(int*)(apuStack_64[0] + 0x18) = -*(int*)(apuStack_64[0] + 0x18);
        puVar6 = apuStack_64[0];
        goto LAB_0063b27e;
    case 0x10e:
        *(double*)(apuStack_64[0] + 0x18) = -*(double*)(apuStack_64[0] + 0x18);
        puVar6 = apuStack_64[0];
        goto LAB_0063b27e;
    case 0x110:
        puVar6 = (unsigned char*)FUN_00633708();
        goto code_r0x0063b074;
    case 0x112: case 0x113: case 0x114: case 0x11a: case 0x11b: case 0x11c:
    case 0x11d: case 0x11e: case 0x11f: case 0x120: case 0x123: case 0x124:
    case 0x125:
        iVar5 = FUN_0060d19b(0x30);
        if (iVar5 == 0) break;
        puVar6 = (unsigned char*)FUN_0065ae50((int)((char*)self + 0x20));
        goto code_r0x0063b03b;
    case 0x115: case 0x116:
        *(int*)((char*)self + 0x1c) = *(int*)(apuStack_64[0] + 0x18);
        puVar6 = apuStack_64[0];
        goto LAB_0063b27e;
    case 0x122:
        puVar6 = (unsigned char*)FUN_006337f7();
        goto code_r0x0063b074;
    case 0x126:
        puVar6 = (unsigned char*)func_0x006335b4();
        goto code_r0x0063b074;
    case 0x127:
        uVar12 = 0;
        goto code_r0x0063be0d;
    case 0x128:
        uVar12 = 1;
    code_r0x0063be0d:
        puVar6 = (unsigned char*)FUN_006335cf(uVar12);
    code_r0x0063b074:
        goto LAB_0063b27e;
    default:
        FUN_006323c8();
        goto LAB_0063b27e;
    }
    puVar6 = (unsigned char*)0;
code_r0x0063b03b:
    puVar4 = puVar6;
code_r0x0063b03c:
    FUN_00632420((unsigned int)(std::uintptr_t)puVar4);
LAB_0063b27e:
    if (*(int*)((char*)self + 0x44) == 0) {
        iVar5 = *(int*)((char*)self + 0xc);
        if (iVar5 == 0) {
            iVar5 = FUN_0060d19b(0x14);
            if (iVar5 == 0) {
                iVar5 = 0;
            } else {
                iVar5 = FUN_0065ac49((int)(std::intptr_t)puVar6,
                                     *(int*)((char*)self + 8), "Stack");
            }
            if (iVar5 == 0) {
            LAB_0063be5a:
                FUN_006323c8();
                return;
            }
        } else {
            *(int*)((char*)self + 0xc) = *(int*)(iVar5 + 0xc);
            *(unsigned char**)(iVar5 + 8) = puVar6;
            *(int*)(iVar5 + 0xc) = *(int*)((char*)self + 8);
        }
        *(int*)((char*)self + 8) = iVar5;
    }
    return;
code_r0x0063b1e5:
    puVar6 = apuStack_64[1];
    goto LAB_0063b27e;
}

// 0x63c30e — observed shape: LALR-style parser driver. It initialises the
// three parser globals (state stack 0x72ba18 / value stack 0x72b248 / the
// lookahead slot 0x72be10 = -1), consults the action table at &DAT_0071aa28,
// and on a reduction looks up the (argument count, rule) pair for the
// reduced token below and calls FUN_0063afb8(rule, argc) before shifting the
// goto state from &DAT_0071a7d8 / &DAT_0071b750.
// The reduction table is a flat 1:1 map extracted from the observed switch
// (token 1..293); entry 0 is unused.
struct TokenRule { unsigned char argc; unsigned short rule; };
static const TokenRule kTokenRule[294] = {
    {0,0x0}, {0,0x0}, {1,0x1}, {1,0x2}, {2,0x3}, {0,0x4}, {1,0x5}, {1,0x6},
    {1,0x7}, {1,0x8}, {1,0x9}, {1,0xa}, {2,0xb}, {0,0xc}, {0,0xd}, {0,0xe},
    {0,0xf}, {0,0x10}, {0,0x11}, {1,0x12}, {1,0x13}, {1,0x14}, {2,0x15}, {0,0x16},
    {0,0x17}, {0,0x18}, {1,0x19}, {2,0x1a}, {1,0x1d}, {2,0x1e}, {2,0x1f}, {2,0x20},
    {1,0x21}, {1,0x22}, {2,0x23}, {1,0x24}, {1,0x25}, {1,0x26}, {1,0x27}, {1,0x28},
    {2,0x29}, {1,0x2a}, {2,0x2b}, {0,0x2c}, {1,0x2d}, {1,0x2e}, {1,0x2f}, {1,0x30},
    {0,0x31}, {0,0x32}, {0,0x33}, {0,0x34}, {0,0x35}, {0,0x36}, {2,0x37}, {0,0x38},
    {3,0x39}, {0,0x3a}, {0,0x3b}, {0,0x3c}, {0,0x3d}, {0,0x3e}, {0,0x3f}, {0,0x40},
    {0,0x41}, {0,0x42}, {0,0x43}, {0,0x44}, {0,0x45}, {0,0x46}, {0,0x47}, {0,0x48},
    {0,0x49}, {2,0x4a}, {3,0x4b}, {3,0x4c}, {4,0x4d}, {1,0x4e}, {2,0x4f}, {0,0x50},
    {1,0x51}, {2,0x52}, {0,0x53}, {1,0x54}, {1,0x55}, {1,0x56}, {2,0x57}, {0,0x58},
    {1,0x59}, {1,0x5a}, {2,0x5b}, {2,0x5c}, {3,0x5d}, {0,0x5e}, {1,0x5f}, {0,0x60},
    {1,0x61}, {2,0x62}, {0,0x63}, {1,0x64}, {1,0x65}, {1,0x66}, {0,0x67}, {1,0x68},
    {2,0x69}, {2,0x6a}, {1,0x6b}, {2,0x6c}, {4,0x6d}, {1,0x6e}, {1,0x6f}, {2,0x70},
    {1,0x71}, {3,0x72}, {4,0x73}, {2,0x74}, {2,0x75}, {3,0x76}, {0,0x77}, {0,0x78},
    {1,0x79}, {2,0x7a}, {2,0x7b}, {1,0x7c}, {2,0x7d}, {1,0x80}, {2,0x81}, {0,0x82},
    {0,0x83}, {0,0x84}, {0,0x85}, {1,0x86}, {3,0x87}, {2,0x88}, {3,0x89}, {0,0x8a},
    {0,0x8b}, {1,0x8c}, {2,0x8d}, {3,0x8e}, {2,0x8f}, {3,0x90}, {0,0x91}, {0,0x92},
    {1,0x93}, {2,0x94}, {5,0x95}, {0,0x96}, {1,0x97}, {0,0x98}, {0,0x99}, {2,0x9a},
    {3,0x9b}, {0,0x9c}, {0,0x9d}, {1,0x9e}, {2,0x9f}, {0,0xa0}, {1,0xa1}, {0,0xa2},
    {1,0xa3}, {2,0xa4}, {1,0xa5}, {0,0xa6}, {1,0xa7}, {1,0xa8}, {1,0xa9}, {1,0xaa},
    {2,0xab}, {5,0xac}, {1,0xad}, {2,0xae}, {5,0xaf}, {2,0xb0}, {3,0xb1}, {0,0xb2},
    {0,0xb3}, {1,0xb4}, {1,0xb5}, {0,0xb6}, {1,0xb7}, {0,0xb8}, {1,0xb9}, {1,0xba},
    {2,0xbb}, {1,0xbc}, {1,0xbd}, {1,0xbe}, {1,0xbf}, {1,0xc0}, {0,0xc1}, {0,0xc2},
    {1,0xc3}, {1,0xc4}, {1,0xc5}, {1,0xc6}, {1,0xc7}, {2,0xc8}, {2,0xc9}, {2,0xca},
    {1,0xcb}, {1,0xcc}, {2,0xcd}, {1,0xce}, {1,0xcf}, {3,0xd0}, {1,0xd1}, {3,0xd2},
    {1,0xd3}, {1,0xd4}, {1,0xd5}, {1,0xd6}, {2,0xd7}, {2,0xd8}, {1,0xd9}, {1,0xda},
    {1,0xdb}, {1,0xdc}, {1,0xdd}, {1,0xde}, {1,0xdf}, {1,0xe0}, {1,0xe1}, {2,0xe2},
    {1,0xe3}, {2,0xe4}, {2,0xe5}, {2,0xe6}, {1,0xe7}, {2,0xe8}, {2,0xe9}, {1,0xea},
    {2,0xeb}, {2,0xec}, {2,0xed}, {2,0xee}, {1,0xef}, {2,0xf0}, {2,0xf1}, {1,0xf2},
    {2,0xf3}, {1,0xf4}, {2,0xf5}, {1,0xfd}, {3,0xfe}, {1,0xf6}, {2,0xf7}, {2,0xf8},
    {2,0xf9}, {2,0xfa}, {2,0xfb}, {2,0xfc}, {1,0xff}, {2,0x100}, {0,0x101}, {1,0x102},
    {1,0x103}, {1,0x104}, {1,0x105}, {1,0x106}, {2,0x107}, {1,0x108}, {1,0x109}, {2,0x10a},
    {1,0x10b}, {1,0x10c}, {1,0x10d}, {1,0x10e}, {1,0x10f}, {2,0x110}, {1,0x111}, {0,0x112},
    {0,0x113}, {0,0x114}, {1,0x115}, {1,0x116}, {0,0x117}, {1,0x118}, {1,0x119}, {0,0x11a},
    {0,0x11b}, {0,0x11c}, {0,0x11d}, {0,0x11e}, {0,0x11f}, {0,0x120}, {1,0x121}, {2,0x122},
    {0,0x123}, {0,0x124}, {0,0x125}, {0,0x126}, {0,0x127}, {0,0x128},
};

// parser state globals (0x72be00..0x72be20)
extern int DAT_0072be00;
extern int DAT_0072be04;
extern int* DAT_0072be08;   // value stack cursor (base 0x72b248)
extern short* DAT_0072be0c; // state stack cursor (base 0x72ba18)
extern int DAT_0072be10;    // lookahead slot, -1 when empty
extern int DAT_0072be14;
extern int _DAT_0072be18;   // overlaps DAT_0072be14 in the listing
extern int DAT_0072be20;    // parser context / error sink
extern short DAT_0072ba18;
extern short DAT_0072bdfe;  // top-of-stack bound (state stack)
extern int _DAT_0072ba18;   // overlaps DAT_0072ba18 in the listing
extern int DAT_0072b248;
// parser tables
extern short DAT_0071aa28[];
extern short DAT_0071aed8[];
extern short DAT_0071b2a0[];
extern short DAT_0071d268[];
extern short DAT_0071b750[];
extern short DAT_0071a7d8[];
extern short DAT_0071b668[];
extern short DAT_0071adf0[];
extern short DAT_0071a588[];

// 0x63c30e — observed shape
int FUN_0063c30e(void)
{
    short sVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    bool bVar5;
    int uVar6;
    int uVar7;

    iVar4 = 0;
    _DAT_0072be18 = 0;
    DAT_0072be14 = 0;
    DAT_0072be0c = (short*)&DAT_0072ba18;
    DAT_0072be08 = (int*)&DAT_0072b248;
    _DAT_0072ba18 = 0;
LAB_0063c349:
    DAT_0072be10 = -1;
LAB_0063c34e:
    iVar2 = (int)(short)DAT_0071aa28[iVar4];
    if (iVar2 == 0) {
        if ((DAT_0072be10 < 0) && (DAT_0072be10 = FUN_006385bc(), DAT_0072be10 < 0)) {
            DAT_0072be10 = 0;
        }
        if (((((short)DAT_0071aed8[iVar4] != 0) &&
              (iVar2 = (short)DAT_0071aed8[iVar4] + DAT_0072be10, -1 < iVar2)) && (iVar2 < 0xd89)) &&
            (*(short*)(&DAT_0071d268 + iVar2 * 2) == DAT_0072be10)) {
            if (&DAT_0072bdfe <= DAT_0072be0c) goto LAB_0063d160;
            iVar4 = (int)*(short*)(&DAT_0071b750 + iVar2 * 2);
            DAT_0072be0c = DAT_0072be0c + 1;
            *DAT_0072be0c = *(short*)(&DAT_0071b750 + iVar2 * 2);
            DAT_0072be08 = DAT_0072be08 + 1;
            *DAT_0072be08 = DAT_0072be00;
            DAT_0072be10 = -1;
            if (0 < DAT_0072be14) {
                DAT_0072be14 = DAT_0072be14 + -1;
            }
            goto LAB_0063c34e;
        }
        if ((((short)DAT_0071b2a0[iVar4] != 0) &&
             (iVar2 = (short)DAT_0071b2a0[iVar4] + DAT_0072be10, -1 < iVar2)) &&
            ((iVar2 < 0xd89 && (*(short*)(&DAT_0071d268 + iVar2 * 2) == DAT_0072be10)))) {
            iVar2 = (int)*(short*)(&DAT_0071b750 + iVar2 * 2);
            goto LAB_0063c432;
        }
        if (DAT_0072be14 == 0) {
            FUN_006321f5(DAT_0072be20, "syntax error");
            _DAT_0072be18 = _DAT_0072be18 + 1;
        }
        if (2 < DAT_0072be14) goto LAB_0063d154;
        DAT_0072be14 = 3;
        while ((((short)DAT_0071aed8[*DAT_0072be0c] == 0 ||
                 (iVar4 = (short)DAT_0071aed8[*DAT_0072be0c] + 0x100, iVar4 < 0)) ||
                ((0xd88 < iVar4 || (*(short*)(&DAT_0071d268 + iVar4 * 2) != 0x100))))) {
            if (DAT_0072be0c < (short*)0x72ba19) {
                DAT_0072be14 = 3;
                return 1;
            }
            DAT_0072be0c = DAT_0072be0c + -1;
            DAT_0072be08 = DAT_0072be08 + -1;
        }
        if ((short*)0x72bdfd < DAT_0072be0c) goto LAB_0063d160;
        sVar1 = *(short*)(&DAT_0071b750 + iVar4 * 2);
        DAT_0072be0c = DAT_0072be0c + 1;
        *DAT_0072be0c = sVar1;
        uVar6 = DAT_0072be00;
    } else {
    LAB_0063c432:
        iVar4 = (int)*(short*)(&DAT_0071a7d8 + iVar2 * 2);
        DAT_0072be04 = DAT_0072be08[1 - iVar4];
        if ((iVar2 >= 1) && (iVar2 <= 293)) {
            uVar7 = kTokenRule[iVar2].argc;
            uVar6 = kTokenRule[iVar2].rule;
            FUN_0063afb8(nullptr, uVar6, uVar7);
        }
        DAT_0072be0c = DAT_0072be0c + -iVar4;
        iVar3 = (int)*DAT_0072be0c;
        DAT_0072be08 = DAT_0072be08 + -iVar4;
        iVar4 = (int)*(short*)(&DAT_0071a588[iVar2]);
        if ((iVar3 == 0) && (iVar4 == 0)) {
            DAT_0072be0c = DAT_0072be0c + 1;
            iVar4 = 0x28;
            *DAT_0072be0c = 0x28;
            DAT_0072be08 = DAT_0072be08 + 1;
            *DAT_0072be08 = DAT_0072be04;
            bVar5 = DAT_0072be10 == 0;
            if (DAT_0072be10 < 0) {
                DAT_0072be10 = FUN_006385bc();
                bVar5 = DAT_0072be10 == 0;
                if (DAT_0072be10 < 0) {
                    DAT_0072be10 = 0;
                    bVar5 = true;
                }
            }
            if (bVar5) {
                return 0;
            }
            goto LAB_0063c34e;
        }
        iVar4 = iVar4 * 2;
        if ((((*(short*)(&DAT_0071b668 + iVar4) == 0) ||
              (iVar2 = *(short*)(&DAT_0071b668 + iVar4) + iVar3, iVar2 < 0)) || (0xd88 < iVar2)) ||
            (*(short*)(&DAT_0071d268 + iVar2 * 2) != iVar3)) {
            sVar1 = *(short*)(&DAT_0071adf0 + iVar4);
        } else {
            sVar1 = *(short*)(&DAT_0071b750 + iVar2 * 2);
        }
        if ((short*)0x72bdfd < DAT_0072be0c) {
        LAB_0063d160:
            FUN_006321f5(DAT_0072be20, "yacc stack overflow");
            return 1;
        }
        DAT_0072be0c = DAT_0072be0c + 1;
        *DAT_0072be0c = sVar1;
        uVar6 = DAT_0072be04;
    }
    iVar4 = (int)sVar1;
    DAT_0072be08 = DAT_0072be08 + 1;
    *DAT_0072be08 = uVar6;
    goto LAB_0063c34e;
LAB_0063d154:
    if (DAT_0072be10 == 0) {
        return 1;
    }
    goto LAB_0063c349;
}

// 0x63d60d — observed shape: device/parser creation entry. Zeroes the output
// pointer, initialises the 0x60-byte receiver block, publishes it in
// DAT_0072be20, then runs the three-stage init and, on success, detaches the
// buffered item at +8 and reports 0x8876086c / 0x80004005 style HRESULTs.
// 0x63d60d — observed shape
std::uint32_t FUN_0063d60d(void* self, int param_1, int param_2, std::uint32_t* param_3)
{
    std::uint32_t uVar1;
    int iVar2;
    int* p = (int*)self;

    if (param_3 == (std::uint32_t*)0) {
        uVar1 = 0x8876086c;
    } else {
        *param_3 = 0;
        p[0] = param_2;
        p[1] = param_1;
        p[2] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        p[0x10] = 0;
        p[0x11] = 0;
        p[0x12] = 1;
        p[0x13] = 0;
        p[0x14] = 0;
        p[0x15] = 0;
        p[0x16] = 0;
        DAT_0072be20 = (int)(std::intptr_t)self;
        uVar1 = (std::uint32_t)FUN_0060bf76(1);
        if (-1 < (int)uVar1) {
            FUN_00632455(0, 0);
            iVar2 = FUN_0063c30e();
            if (iVar2 != 0) {
                p[0x10] = 1;
            }
            uVar1 = (std::uint32_t)FUN_0060f49b();
            if (-1 < (int)uVar1) {
                if (p[0x10] == 0) {
                    *param_3 = (std::uint32_t)*(int*)(p[2] + 8);
                    *(int*)(p[2] + 8) = 0;
                }
                uVar1 = -(std::uint32_t)(p[0x10] != 0) & 0x80004005;
            }
        }
    }
    return uVar1;
}

// 0x63d6bb — observed shape: forwards a run of per-element "present" flags to
// the vtable slot at +0x188 of the object, one call per element, stopping at
// the first negative result.
// 0x63d6bb — observed shape
int FUN_0063d6bb(int* param_1, int param_2, int* param_3, std::uint32_t param_4)
{
    int* piVar1;
    int iVar2;
    int* piVar3;
    std::uint32_t uVar4;

    piVar1 = param_1;
    uVar4 = 0;
    if (param_4 != 0) {
        piVar3 = param_3;
        do {
            param_1 = (int*)0;
            if (*piVar3 != 0) {
                param_1 = (int*)0xffffffff;
            }
            iVar2 = (*(int(**)(int*, int, int**, int))(*piVar1 + 0x188))(
                piVar1, param_2 + (int)uVar4, &param_1, 1);
            if (iVar2 < 0) {
                return iVar2;
            }
            piVar3 = piVar3 + 1;
            uVar4 = uVar4 + 1;
        } while (uVar4 < param_4);
    }
    return 0;
}

// 0x63d708 — observed shape: doubles the capacity at +0x110, allocates
// capacity*8 bytes, copies the used entries (count at +0x10c) plus the
// trailing byte run, frees the old buffer and installs the new one.
// 0x63d708 — observed shape
int FUN_0063d708(void* self)
{
    int* p = (int*)self;
    int* puVar1;
    int uVar2;
    std::uint32_t uVar3;
    int iVar4;
    int* puVar5;
    int* puVar6;

    iVar4 = p[0x44];             /* +0x110 */
    p[0x44] = iVar4 << 1;
    puVar1 = (int*)FUN_00533c78(iVar4 << 3);
    if (puVar1 == (int*)0) {
        uVar2 = (int)0x8007000e;
    } else {
        puVar5 = (int*)p[0x42];  /* +0x108 */
        puVar6 = puVar1;
        for (uVar3 = (std::uint32_t)p[0x43] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(unsigned char*)puVar6 = *(unsigned char*)puVar5;
            puVar5 = (int*)((char*)puVar5 + 1);
            puVar6 = (int*)((char*)puVar6 + 1);
        }
        operator_delete((void*)p[0x42]);
        p[0x42] = (int)(std::intptr_t)puVar1;
        uVar2 = 0;
    }
    return uVar2;
}

// 0x63d772 — observed shape: marks a shader object and all of its
// dependencies as used. Two paths: the non-batched path walks the +0x18
// dependency list directly, the batched path records (row,column) pairs in
// the +0x108 array, growing it through FUN_0063d708 and flagging each target
// slot with bit 2.
// 0x63d772 — observed shape
int FUN_0063d772(void* self, int param_1)
{
    int* p = (int*)self;
    int iVar1;
    int iVar2;
    int* piVar3;
    int* puVar4;
    int* puVar5;

    if (p[0x2d] == 0) {          /* +0xb4 */
        iVar1 = *(int*)(p[0x2c] + *(int*)(param_1 + 0x14) * 4);  /* +0xb0 */
        if (*(int*)(iVar1 + 0x34) != 0) {
            puVar4 = *(int**)(*(int*)(iVar1 + 0x34) + 0x18);
            if ((*(unsigned char*)((char*)p + 0x119) & 1) == 0) {
                piVar3 = puVar4 + 7;
                do {
                    puVar4 = (int*)*piVar3;
                    *puVar4 = 1;
                    *(int*)((std::uint32_t)*(unsigned short*)((char*)puVar4 + 0x16) * 100 +
                            *(int*)((std::uint32_t)*(unsigned short*)(puVar4 + 5) * 100 + 4 +
                                    p[0x0b])) = 1;
                    piVar3 = puVar4 + 7;
                } while (*piVar3 != *(int*)(iVar1 + 0x34));
            } else {
                do {
                    puVar4 = (int*)puVar4[7];
                    *puVar4 = 1;
                    puVar5 = (int*)((std::uint32_t)*(unsigned short*)((char*)puVar4 + 0x16) * 100 +
                                    *(int*)((std::uint32_t)*(unsigned short*)(puVar4 + 5) * 100 + 4 +
                                            p[0x0b]));
                    *puVar5 = 1;
                    if ((*(unsigned char*)(puVar5 + 0xc) & 2) == 0) {
                        if (((std::uint32_t)p[0x44] <= (std::uint32_t)p[0x43]) &&
                            (iVar2 = FUN_0063d708(self), iVar2 < 0)) {
                            return iVar2;
                        }
                        *(unsigned short*)(p[0x42] + p[0x43] * 4) =
                            *(unsigned short*)(puVar4 + 5);
                        *(unsigned short*)(p[0x42] + 2 + p[0x43] * 4) =
                            *(unsigned short*)((char*)puVar4 + 0x16);
                        puVar5[0xc] = puVar5[0xc] | 2;
                        p[0x43] = p[0x43] + 1;
                    }
                } while (puVar4[7] != *(int*)(iVar1 + 0x34));
            }
        }
    } else if (*(std::uint32_t*)(param_1 + 0x14) < (std::uint32_t)p[0x2b]) {
        *(unsigned char*)(*(std::uint32_t*)(param_1 + 0x14) + p[0x2f]) = 1;
        piVar3 = *(int**)(p[0x2e] + *(int*)(param_1 + 0x14) * 4);
        if (piVar3 != (int*)0) {
            if ((*(unsigned char*)((char*)p + 0x119) & 1) == 0) {
                for (; (int*)*piVar3 != (int*)0; piVar3 = piVar3 + 1) {
                    *(int*)*piVar3 = 1;
                    **(int**)(*piVar3 + 8) = 1;
                }
            } else {
                for (; (puVar4 = (int*)*piVar3) != (int*)0; piVar3 = piVar3 + 1) {
                    puVar5 = (int*)puVar4[2];
                    *puVar4 = 1;
                    *puVar5 = 1;
                    if ((*(unsigned char*)(puVar5 + 0xc) & 2) == 0) {
                        if (((std::uint32_t)p[0x44] <= (std::uint32_t)p[0x43]) &&
                            (iVar1 = FUN_0063d708(self), iVar1 < 0)) {
                            return iVar1;
                        }
                        *(unsigned short*)(p[0x42] + p[0x43] * 4) =
                            *(unsigned short*)(puVar4 + 5);
                        *(unsigned short*)(p[0x42] + 2 + p[0x43] * 4) =
                            *(unsigned short*)((char*)puVar4 + 0x16);
                        puVar5[0xc] = puVar5[0xc] | 2;
                        p[0x43] = p[0x43] + 1;
                    }
                }
            }
        }
    }
    return 0;
}

// 0x63d943 — observed shape: teardown of the item stored at +0x38, gated on
// the state word at +0x3c == 4; releases up to four interface pointers of the
// object reached through +0xa4 + row*0xb4, honouring the feature bits at
// +0x118 (0x8 / 0x20 / 0x10).
// 0x63d943 — observed shape
int FUN_0063d943(void* self)
{
    int* p = (int*)self;
    int* piVar1;
    int iVar2;
    int iVar3;

    iVar2 = 0;
    if (p[0x0f] == 4) {          /* +0x3c */
        if (p[0x0e] != 0) {      /* +0x38 */
            piVar1 = (int*)(p[0x0e] + 8);
            *piVar1 = *piVar1 + -1;
            *(int*)(p[0x0e] + 0xc) = 0;
        }
        iVar3 = (std::uint32_t)*(unsigned short*)((char*)p + 0x42) * 0xb4 + p[0x29];
        p[0x0f] = 0;
        if ((*(unsigned char*)((char*)p + 0x118) & 8) != 0) {
            if (*(int*)(iVar3 + 0x88) == 0) {
                iVar2 = 0;
            } else {
                piVar1 = *(int**)(iVar3 + 0x88);
                iVar2 = (*(int(**)(int*))(*piVar1 + 0x14))(piVar1);
            }
            if (-1 < iVar2) {
                if ((*(unsigned char*)((char*)p + 0x118) & 0x20) != 0) {
                    if (*(int*)(iVar3 + 0x90) == 0) {
                        iVar2 = 0;
                    } else {
                        piVar1 = *(int**)(iVar3 + 0x90);
                        iVar2 = (*(int(**)(int*))(*piVar1 + 0x14))(piVar1);
                    }
                    if (iVar2 < 0) {
                        return iVar2;
                    }
                    if (*(int*)(iVar3 + 0x8c) == 0) {
                        iVar2 = 0;
                    } else {
                        piVar1 = *(int**)(iVar3 + 0x8c);
                        iVar2 = (*(int(**)(int*))(*piVar1 + 0x14))(piVar1);
                    }
                    if (iVar2 < 0) {
                        return iVar2;
                    }
                }
                if ((*(unsigned char*)((char*)p + 0x118) & 0x10) != 0) {
                    if (*(int*)(iVar3 + 0x98) == 0) {
                        iVar2 = 0;
                    } else {
                        piVar1 = *(int**)(iVar3 + 0x98);
                        iVar2 = (*(int(**)(int*))(*piVar1 + 0x14))(piVar1);
                    }
                    if (-1 < iVar2) {
                        if (*(int*)(iVar3 + 0x94) == 0) {
                            iVar2 = 0;
                        } else {
                            piVar1 = *(int**)(iVar3 + 0x94);
                            iVar2 = (*(int(**)(int*))(*piVar1 + 0x14))(piVar1);
                        }
                    }
                }
            }
        }
    } else {
        iVar2 = -0x7fffbffb;
    }
    return iVar2;
}

// 0x63da29 — observed shape: clears the batched-dirty flag (bit 0 at +0x119)
// and, when the pair array at +0x108 is non-empty, clears bit 1 in each
// target slot (+0x30) addressed by the recorded (row,column) pair.
// 0x63da29 — observed shape
int FUN_0063da29(void* self)
{
    int* p = (int*)self;
    std::uint32_t* puVar1;
    unsigned short* puVar2;
    std::uint32_t uVar3;

    *(unsigned char*)((char*)p + 0x119) = *(unsigned char*)((char*)p + 0x119) & 0xfe;
    if (p[0x43] != 0) {          /* +0x10c */
        uVar3 = 0;
        if (p[0x43] != 0) {
            do {
                puVar2 = (unsigned short*)(p[0x42] + (int)uVar3 * 4);   /* +0x108 */
                puVar1 = (std::uint32_t*)((std::uint32_t)puVar2[1] * 100 +
                                          *(int*)((std::uint32_t)*puVar2 * 100 + 4 + p[0x0b]) +
                                          0x30);
                *puVar1 = *puVar1 & 0xfffffffd;
                uVar3 = uVar3 + 1;
            } while (uVar3 < (std::uint32_t)p[0x43]);
        }
        p[0x43] = 0;
    }
    return 0;
}
