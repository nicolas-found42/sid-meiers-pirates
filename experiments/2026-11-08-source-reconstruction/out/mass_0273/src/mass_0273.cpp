#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <windows.h>

extern void operator_delete(void *ptr);
extern void FUN_0060bf3b();
extern void* FUN_00533c78(uint32_t size);
extern uint64_t FUN_0060bee5(uint32_t param_1);

// 0x60bf55 — observed shape
void FUN_0060bf55(void *self, uint8_t param_1)
{
    FUN_0060bf3b();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x60bf76 — observed shape
uint32_t FUN_0060bf76(void *self, uint32_t param_1)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    int iVar1 = reinterpret_cast<int>(FUN_00533c78(0xc));
    uint32_t uVar2 = 0;
    if (iVar1 != 0) {
        uint64_t uVar3 = FUN_0060bee5(param_1);
        param_1 = static_cast<uint32_t>(uVar3 >> 0x20);
        iVar1 = static_cast<int>(uVar3);
    }
    if (iVar1 == 0) {
        uVar2 = 0x8007000e;
    } else {
        *reinterpret_cast<uint32_t *>(iVar1 + 4) = *reinterpret_cast<uint32_t *>(base + 0x68);
        *reinterpret_cast<int *>(base + 0x68) = iVar1;
        *reinterpret_cast<uint32_t *>(base + 0x298) = param_1;
        uVar2 = 0;
    }
    return uVar2;
}

// 0x60bfba — observed shape
uint32_t FUN_0060bfba(void *self, uint32_t *param_1, uint32_t *param_2)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    if (param_1 != nullptr) {
        *param_1 = *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(base + 0x26c) + 0x18);
    }
    if (param_2 != nullptr) {
        *param_2 = *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(base + 0x26c) + 0x1c);
    }
    return 0;
}

// 0x60bfe9 — observed shape
uint32_t FUN_0060bfe9(void *self, uint32_t *param_1, int32_t *param_2)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    uint32_t *puVar1 = *reinterpret_cast<uint32_t **>(base + 0x268);
    while (puVar1[0x1b] != 0) {
        puVar1 = reinterpret_cast<uint32_t *>(puVar1[0x1b]);
    }
    if (param_1 != nullptr) {
        *param_1 = *puVar1;
    }
    if (param_2 != nullptr) {
        if (puVar1[1] < *puVar1) {
            *param_2 = 0;
        } else {
            *param_2 = static_cast<int32_t>(puVar1[1] - *puVar1);
        }
    }
    return 0;
}

// 0x60c0e3 — observed shape
uint32_t FUN_0060c0e3(void *self, uint32_t param_1, int32_t param_2)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(base + 0x26c) + 0x1c) = param_1;
    if (*reinterpret_cast<int *>(base + 0x278) != 0xc) {
        int32_t *piVar1 = reinterpret_cast<int32_t *>(*reinterpret_cast<int *>(base + 0x26c) + 0x1c);
        *piVar1 = *piVar1 + -1;
    }
    if (param_2 != 0) {
        *reinterpret_cast<int *>(*reinterpret_cast<int *>(base + 0x26c) + 0x18) = param_2;
    }
    return 0;
}
extern int FUN_00610755(uint32_t a, int32_t *b);
extern void FUN_0060c029();
extern int FUN_0060bcf9(const void *a, int b, void *c, void *d, void *e, uint32_t f, int32_t g, uint32_t h);
extern int FUN_0060bc4a();
extern void FUN_0060bcd8(int a);
extern void FUN_0060fcd3(void *a, void *b, uint32_t c, const char *d, ...);
extern void FUN_0060f81e();
extern int FUN_0060bbf1(int param_1, uint32_t param_2);
extern int FUN_0060fc69(uint32_t a, uint32_t b);

// 0x60c11c — observed shape
int FUN_0060c11c(void *self)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    uint8_t local_118[260];
    char local_21c[260];
    uint32_t local_10 = 0;
    uint8_t *local_8 = nullptr;
    int32_t local_c = 0;
    uint32_t uVar4 = 0;
    uint32_t uVar7 = 0;
    const char *pcVar8 = nullptr;
    int iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298) | 0xc, reinterpret_cast<int32_t *>(base + 0x278));
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = *reinterpret_cast<int *>(base + 0x278);
    if (iVar2 == 10) {
        local_c = 0;
    } else {
        if (iVar2 != 0xb) {
            FUN_0060c029();
            return -0x7fffbffb;
        }
        local_c = 1;
    }
    local_8 = *reinterpret_cast<uint8_t **>(base + 0x280);
    if ((*reinterpret_cast<int *>(base + 0x270) == 0) && (*reinterpret_cast<int *>(*reinterpret_cast<int *>(base + 0x26c) + 0x18) == 0)) {
        pcVar8 = "include interface required to support #include from resource or memory";
        uVar7 = 0x5e1;
        FUN_0060fcd3(base + 0x18, base + 0x278, uVar7, pcVar8);
        *reinterpret_cast<uint32_t *>(base + 0x48) = 1;
        *reinterpret_cast<uint32_t *>(base + 0x44) = 1;
        return -0x7fffbffb;
    }
    iVar2 = *reinterpret_cast<int *>(base + 0x268);
    if (iVar2 != 0) {
        do {
            iVar2 = *reinterpret_cast<int *>(iVar2 + 0x6c);
            uVar4 = uVar4 + 1;
        } while (iVar2 != 0);
        if (0x1f < uVar4) {
            pcVar8 = "too many nested #includes";
            uVar7 = 0x5e2;
            FUN_0060fcd3(base + 0x18, base + 0x278, uVar7, pcVar8);
            *reinterpret_cast<uint32_t *>(base + 0x48) = 1;
            *reinterpret_cast<uint32_t *>(base + 0x44) = 1;
            return -0x7fffbffb;
        }
    }
    if (*reinterpret_cast<int *>(base + 0x270) == 0) {
        LPSTR local_14 = nullptr;
        GetFullPathNameA(reinterpret_cast<const char *>(local_8), 0x104, reinterpret_cast<LPSTR>(local_118), &local_14);
        const uint8_t *pbVar3 = local_118;
        const uint8_t *pbVar5 = local_8;
        bool bVar6 = false;
        iVar2 = 0;
        while (true) {
            uint8_t bVar1 = *pbVar5;
            bVar6 = bVar1 < *pbVar3;
            if (bVar1 != *pbVar3) {
                iVar2 = (1 - static_cast<uint32_t>(bVar6)) - static_cast<uint32_t>(bVar6 != 0);
                break;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar5[1];
            bVar6 = bVar1 < pbVar3[1];
            if (bVar1 != pbVar3[1]) {
                iVar2 = (1 - static_cast<uint32_t>(bVar6)) - static_cast<uint32_t>(bVar6 != 0);
                break;
            }
            pbVar5 = pbVar5 + 2;
            pbVar3 = pbVar3 + 2;
            if (bVar1 == 0) break;
        }
        if (iVar2 != 0) {
            _snprintf(local_21c, 0x104, "%s%s", reinterpret_cast<const char *>(*reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(base + 0x268) + 0x60)), reinterpret_cast<const char *>(local_8));
            GetFullPathNameA(local_21c, 0x104, reinterpret_cast<LPSTR>(local_118), &local_14);
        }
        local_8 = local_118;
    }
    iVar2 = *reinterpret_cast<int *>(base + 0x268);
    if ((iVar2 == 0) || (*reinterpret_cast<int *>(iVar2 + 0x58) == 0)) {
        local_10 = 0;
    } else {
        local_10 = *reinterpret_cast<uint32_t *>(iVar2 + 100);
    }
    iVar2 = reinterpret_cast<int>(FUN_00533c78(0x70));
    if (iVar2 != 0) {
        iVar2 = FUN_0060bc4a();
    }
    if (iVar2 == 0) {
        return -0x7ff8fff2;
    }
    local_c = FUN_0060bcf9(local_8, 0, base, base + 0x278, base + 0x18, *reinterpret_cast<uint32_t *>(base + 0x270), local_c, local_10);
    if (local_c < 0) {
        *reinterpret_cast<uint32_t *>(base + 0x48) = 1;
        *reinterpret_cast<uint32_t *>(base + 0x44) = 1;
        FUN_0060bcd8(1);
        return local_c;
    }
    *reinterpret_cast<uint32_t *>(iVar2 + 0x6c) = *reinterpret_cast<uint32_t *>(base + 0x268);
    *reinterpret_cast<int *>(base + 0x268) = iVar2;
    return 0;
}

// 0x60c315 — observed shape
uint32_t FUN_0060c315(void *self)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    char local_108[256];
    char *pcVar5 = reinterpret_cast<char *>(*reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(base + 0x26c)));
    FUN_0060f81e();
    if (*reinterpret_cast<int *>(base + 0x50) != 0) {
        while ((pcVar5 < reinterpret_cast<char *>(*reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(base + 0x26c)))) && ((*pcVar5 == ' ' || (*pcVar5 == '\t')))) {
            pcVar5 = pcVar5 + 1;
        }
        uint32_t local_8 = 0;
        char *pcVar4 = pcVar5 + 2;
        char *pcVar3 = pcVar5 + 1;
        for (;;) {
            char *pcVar2 = reinterpret_cast<char *>(*reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(base + 0x26c)));
            if (pcVar2 <= pcVar5) break;
            char cVar1 = *pcVar5;
            if (cVar1 == '\\') {
                if ((pcVar3 < pcVar2) && (*pcVar3 == '\n')) {
                    pcVar5 = pcVar5 + 2;
                    pcVar3 = pcVar3 + 2;
                    pcVar4 = pcVar4 + 2;
                } else {
                    if ((pcVar2 <= pcVar4) || ((*pcVar3 != '\r' || (*pcVar4 != '\n')))) {
                        goto LAB_0060c39f;
                    }
                    pcVar5 = pcVar5 + 3;
                    pcVar3 = pcVar3 + 3;
                    pcVar4 = pcVar4 + 3;
                    continue;
                }
            } else {
LAB_0060c39f:
                if (cVar1 != '\r') {
                    local_108[local_8] = cVar1;
                    local_8 = local_8 + 1;
                }
                pcVar5 = pcVar5 + 1;
                pcVar3 = pcVar3 + 1;
                pcVar4 = pcVar4 + 1;
            }
            if (!(local_8 < 0xff)) break;
        }
        local_108[local_8] = '\0';
        FUN_0060fcd3(base + 0x18, base + 0x278, 0, "error: %s", local_108);
        *reinterpret_cast<uint32_t *>(base + 0x48) = 1;
        *reinterpret_cast<uint32_t *>(base + 0x44) = 1;
    }
    return 0;
}

// 0x60c3f9 — observed shape
uint32_t FUN_0060c3f9(void *self, int param_1)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    int iVar1 = reinterpret_cast<int>(FUN_00533c78(0x10));
    uint32_t uVar2 = 0;
    if (iVar1 != 0) {
        iVar1 = FUN_0060bbf1(param_1, *reinterpret_cast<uint32_t *>(base + 0x50));
    }
    if (iVar1 == 0) {
        uVar2 = 0x8007000e;
    } else {
        *reinterpret_cast<uint32_t *>(iVar1 + 0xc) = *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(base + 0x268) + 0x38);
        *reinterpret_cast<int *>(*reinterpret_cast<int *>(base + 0x268) + 0x38) = iVar1;
        if ((*reinterpret_cast<int *>(base + 0x50) == 0) || (param_1 == 0)) {
            uVar2 = 0;
        } else {
            uVar2 = 1;
        }
        *reinterpret_cast<uint32_t *>(base + 0x54) = uVar2;
        uVar2 = 0;
    }
    return uVar2;
}
// 0x60c6d7 — observed shape
int FUN_0060c6d7(void *self)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    uint32_t *local_c = nullptr;
    uint32_t *local_10 = nullptr;
    uint32_t local_8 = 0;
    uint32_t local_14 = 0;
    uint32_t local_18 = 0;
    int iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
    if (iVar2 < 0) goto LAB_0060ca23;
    if (*reinterpret_cast<int *>(base + 0x278) == 1) {
        iVar2 = 2;
        bool bVar11 = true;
        const char *pcVar8 = reinterpret_cast<const char *>(base + 0x280);
        const char *pcVar7 = "(";
        do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar11 = *pcVar8 == *pcVar7;
            pcVar8 = pcVar8 + 1;
            pcVar7 = pcVar7 + 1;
        } while (bVar11);
        if (bVar11) {
            iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
            if (iVar2 < 0) goto LAB_0060ca23;
            local_8 = 0;
            do {
                do {
                    do {
                        iVar2 = *reinterpret_cast<int *>(base + 0x278);
                        if (iVar2 == 1) {
                            int iVar5 = 2;
                            bool bVar11b = true;
                            const char *pcVar8b = reinterpret_cast<const char *>(base + 0x280);
                            const char *pcVar7b = ")";
                            do {
                                if (iVar5 == 0) break;
                                iVar5 = iVar5 + -1;
                                bVar11b = *pcVar8b == *pcVar7b;
                                pcVar8b = pcVar8b + 1;
                                pcVar7b = pcVar7b + 1;
                            } while (bVar11b);
                            if (bVar11b) {
                                iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
                                if (iVar2 < 0) goto LAB_0060ca23;
                                iVar2 = *reinterpret_cast<int *>(base + 0x278);
                                if ((iVar2 == 0xc) || (iVar2 == 0xd)) {
                                    local_18 = 0;
                                    if (local_8 == 0) goto LAB_0060ca21;
                                    goto LAB_0060ca8f;
                                }
                                goto LAB_0060ca06;
                            }
                        }
                        if (iVar2 == 9) {
                            const char *pcVar8c = *reinterpret_cast<const char **>(base + 0x280);
                            iVar2 = 5;
                            bool bVar11c = true;
                            const char *pcVar7c = pcVar8c;
                            const char *pcVar9c = "once";
                            do {
                                if (iVar2 == 0) break;
                                iVar2 = iVar2 + -1;
                                bVar11c = *pcVar7c == *pcVar9c;
                                pcVar7c = pcVar7c + 1;
                                pcVar9c = pcVar9c + 1;
                            } while (bVar11c);
                            if (bVar11c) {
                                local_14 = 0x10;
                            } else {
                                iVar2 = 6;
                                bVar11c = true;
                                pcVar7c = pcVar8c;
                                pcVar9c = "error";
                                do {
                                    if (iVar2 == 0) break;
                                    iVar2 = iVar2 + -1;
                                    bVar11c = *pcVar7c == *pcVar9c;
                                    pcVar7c = pcVar7c + 1;
                                    pcVar9c = pcVar9c + 1;
                                } while (bVar11c);
                                if (bVar11c) {
                                    local_14 = 0xf;
                                } else {
                                    iVar2 = 8;
                                    bVar11c = true;
                                    pcVar7c = pcVar8c;
                                    pcVar9c = "disable";
                                    do {
                                        if (iVar2 == 0) break;
                                        iVar2 = iVar2 + -1;
                                        bVar11c = *pcVar7c == *pcVar9c;
                                        pcVar7c = pcVar7c + 1;
                                        pcVar9c = pcVar9c + 1;
                                    } while (bVar11c);
                                    if (bVar11c) {
                                        local_14 = 0;
                                    } else {
                                        iVar2 = 8;
                                        bVar11c = true;
                                        pcVar8c = pcVar8c;
                                        pcVar7c = "default";
                                        do {
                                            if (iVar2 == 0) break;
                                            iVar2 = iVar2 + -1;
                                            bVar11c = *pcVar8c == *pcVar7c;
                                            pcVar8c = pcVar8c + 1;
                                            pcVar7c = pcVar7c + 1;
                                        } while (bVar11c);
                                        if (!bVar11c) goto LAB_0060ca06;
                                        local_14 = 0xff;
                                    }
                                }
                            }
                        } else if ((((iVar2 != 2) && (iVar2 != 3)) && (iVar2 != 4)) || ((local_14 = *reinterpret_cast<uint32_t *>(base + 0x280), local_14 == 0 || (4 < local_14)))) goto LAB_0060ca06;
                        iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
                        if (iVar2 < 0) goto LAB_0060ca23;
                        if (*reinterpret_cast<int *>(base + 0x278) != 1) goto LAB_0060ca06;
                        iVar2 = 2;
                        bVar11 = true;
                        pcVar8 = reinterpret_cast<const char *>(base + 0x280);
                        pcVar7 = ":";
                        do {
                            if (iVar2 == 0) break;
                            iVar2 = iVar2 + -1;
                            bVar11 = *pcVar8 == *pcVar7;
                            pcVar8 = pcVar8 + 1;
                            pcVar7 = pcVar7 + 1;
                        } while (bVar11);
                        if (!bVar11) goto LAB_0060ca06;
                        iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
                        if (iVar2 < 0) goto LAB_0060ca23;
                        do {
                            do {
                                iVar2 = *reinterpret_cast<int *>(base + 0x278);
                                if (((iVar2 != 2) && (iVar2 != 3)) && (iVar2 != 4)) goto LAB_0060ca06;
                                uint32_t uVar1 = *reinterpret_cast<uint32_t *>(base + 0x280);
                                if (local_8 == (~local_8 + 1 & local_8)) {
                                    if (local_8 == 0) {
                                        iVar2 = 1;
                                    } else {
                                        iVar2 = local_8 * 2;
                                    }
                                    uint32_t *puVar3 = reinterpret_cast<uint32_t *>(FUN_00533c78(iVar2 << 2));
                                    if (puVar3 != nullptr) {
                                        uint32_t *puVar4 = local_c;
                                        uint32_t *puVar10 = puVar3;
                                        for (uint32_t uVar6 = local_8 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                                            *puVar10 = *puVar4;
                                            puVar4 = puVar4 + 1;
                                            puVar10 = puVar10 + 1;
                                        }
                                        for (int iVar2b = 0; iVar2b != 0; iVar2b = iVar2b + -1) {
                                            *reinterpret_cast<uint8_t *>(puVar10) = *reinterpret_cast<uint8_t *>(puVar4);
                                            puVar4 = reinterpret_cast<uint32_t *>(reinterpret_cast<int>(puVar4) + 1);
                                            puVar10 = reinterpret_cast<uint32_t *>(reinterpret_cast<int>(puVar10) + 1);
                                        }
                                        operator_delete(local_c);
                                        if (local_8 == 0) {
                                            iVar2 = 1;
                                        } else {
                                            iVar2 = local_8 * 2;
                                        }
                                        uint32_t *puVar4b = reinterpret_cast<uint32_t *>(FUN_00533c78(iVar2 << 2));
                                        local_c = puVar3;
                                        if (puVar4b != nullptr) {
                                            puVar3 = local_10;
                                            puVar10 = puVar4b;
                                            for (uint32_t uVar6 = local_8 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                                                *puVar10 = *puVar3;
                                                puVar3 = puVar3 + 1;
                                                puVar10 = puVar10 + 1;
                                            }
                                            for (int iVar2c = 0; iVar2c != 0; iVar2c = iVar2c + -1) {
                                                *reinterpret_cast<uint8_t *>(puVar10) = *reinterpret_cast<uint8_t *>(puVar3);
                                                puVar3 = reinterpret_cast<uint32_t *>(reinterpret_cast<int>(puVar3) + 1);
                                                puVar10 = reinterpret_cast<uint32_t *>(reinterpret_cast<int>(puVar10) + 1);
                                            }
                                            operator_delete(local_10);
                                            local_10 = puVar4b;
                                            goto LAB_0060c944;
                                        }
                                    }
                                    iVar2 = -0x7ff8fff2;
                                    goto LAB_0060ca23;
                                }
LAB_0060c944:
                                local_10[local_8] = uVar1;
                                local_c[local_8] = local_14;
                                local_8 = local_8 + 1;
                                iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
                                if (iVar2 < 0) goto LAB_0060ca23;
                            } while (*reinterpret_cast<int *>(base + 0x278) != 1);
                            iVar2 = 2;
                            bVar11 = true;
                            pcVar8 = reinterpret_cast<const char *>(base + 0x280);
                            pcVar7 = ";";
                            do {
                                if (iVar2 == 0) break;
                                iVar2 = iVar2 + -1;
                                bVar11 = *pcVar8 == *pcVar7;
                                pcVar8 = pcVar8 + 1;
                                pcVar7 = pcVar7 + 1;
                            } while (bVar11);
                            if (bVar11) break;
                            iVar2 = 2;
                            bVar11 = true;
                            pcVar8 = reinterpret_cast<const char *>(base + 0x280);
                            pcVar7 = ")";
                            do {
                                if (iVar2 == 0) break;
                                iVar2 = iVar2 + -1;
                                bVar11 = *pcVar8 == *pcVar7;
                                pcVar8 = pcVar8 + 1;
                                pcVar7 = pcVar7 + 1;
                            } while (bVar11);
                        } while (!bVar11);
                        iVar2 = 2;
                        bVar11 = true;
                        pcVar8 = reinterpret_cast<const char *>(base + 0x280);
                        pcVar7 = ";";
                        do {
                            if (iVar2 == 0) break;
                            iVar2 = iVar2 + -1;
                            bVar11 = *pcVar8 == *pcVar7;
                            pcVar8 = pcVar8 + 1;
                            pcVar7 = pcVar7 + 1;
                        } while (bVar11);
                    } while (!bVar11);
                    iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
                    if (iVar2 < 0) goto LAB_0060ca23;
                } while (*reinterpret_cast<int *>(base + 0x278) != 1);
                iVar2 = 2;
                bVar11 = true;
                pcVar8 = reinterpret_cast<const char *>(base + 0x280);
                pcVar7 = ")";
                do {
                    if (iVar2 == 0) break;
                    iVar2 = iVar2 + -1;
                    bVar11 = *pcVar8 == *pcVar7;
                    pcVar8 = pcVar8 + 1;
                    pcVar7 = pcVar7 + 1;
                } while (bVar11);
            } while (!bVar11);
        }
    }
LAB_0060ca06:
    if ((*reinterpret_cast<int *>(base + 0x278) != 0xc) && (*reinterpret_cast<int *>(base + 0x278) != 0xd)) {
        FUN_0060f81e();
    }
    goto LAB_0060ca21;
LAB_0060ca8f:
    iVar2 = FUN_0060fc69(local_10[local_18], local_c[local_18]);
    if (iVar2 < 0) goto LAB_0060ca23;
    local_18 = local_18 + 1;
    if (local_8 <= local_18) goto LAB_0060ca21;
    goto LAB_0060ca8f;
LAB_0060ca21:
    iVar2 = 0;
LAB_0060ca23:
    operator_delete(local_c);
    operator_delete(local_10);
    operator_delete(nullptr);
    *reinterpret_cast<uint32_t *>(base + 0x40) = 1;
    return iVar2;
}

// 0x60cabf — observed shape
int FUN_0060cabf(void *self)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    double local_38[4];
    uint32_t local_10 = 0;
    uint32_t local_14 = 0;
    uint32_t *local_8 = nullptr;
    int iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
    if (iVar2 < 0) goto LAB_0060cdcd;
    if (*reinterpret_cast<int *>(base + 0x278) == 1) {
        iVar2 = 2;
        bool bVar8 = true;
        const char *pcVar4 = reinterpret_cast<const char *>(base + 0x280);
        const char *pcVar6 = "(";
        do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar8 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
        } while (bVar8);
        if (!bVar8) goto LAB_0060cdaf;
        iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
        if (iVar2 < 0) goto LAB_0060cdcd;
        if (*reinterpret_cast<int *>(base + 0x278) != 9) goto LAB_0060cdaf;
        local_10 = *reinterpret_cast<uint32_t *>(base + 0x280);
        iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
        if (iVar2 < 0) goto LAB_0060cdcd;
        if (*reinterpret_cast<int *>(base + 0x278) != 1) goto LAB_0060cdaf;
        iVar2 = 2;
        bVar8 = true;
        pcVar4 = reinterpret_cast<const char *>(base + 0x280);
        pcVar6 = ",";
        do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar8 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
        } while (bVar8);
        if (!bVar8) goto LAB_0060cdaf;
        iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
        if (iVar2 < 0) goto LAB_0060cdcd;
        if (*reinterpret_cast<int *>(base + 0x278) != 9) goto LAB_0060cdaf;
        local_14 = *reinterpret_cast<uint32_t *>(base + 0x280);
        local_8 = nullptr;
        do {
            int32_t local_c = 0;
            iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
            if (iVar2 < 0) goto LAB_0060cdcd;
            if (*reinterpret_cast<int *>(base + 0x278) != 1) goto LAB_0060cdaf;
            iVar2 = 2;
            bVar8 = true;
            pcVar4 = reinterpret_cast<const char *>(base + 0x280);
            pcVar6 = ",";
            do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar8 = *pcVar4 == *pcVar6;
                pcVar4 = pcVar4 + 1;
                pcVar6 = pcVar6 + 1;
            } while (bVar8);
            if (!bVar8) goto LAB_0060cdaf;
            iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
            if (iVar2 < 0) goto LAB_0060cdcd;
            if (*reinterpret_cast<int *>(base + 0x278) == 1) {
                iVar2 = 2;
                bVar8 = true;
                pcVar4 = reinterpret_cast<const char *>(base + 0x280);
                pcVar6 = "-";
                do {
                    if (iVar2 == 0) break;
                    iVar2 = iVar2 + -1;
                    bVar8 = *pcVar4 == *pcVar6;
                    pcVar4 = pcVar4 + 1;
                    pcVar6 = pcVar6 + 1;
                } while (bVar8);
                if (bVar8) {
                    local_c = 1;
                    iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
                    if (iVar2 < 0) goto LAB_0060cdcd;
                }
            }
            iVar2 = *reinterpret_cast<int *>(base + 0x278);
            double dVar1;
            double *pdVar3;
            if (iVar2 == 2) {
LAB_0060cc97:
                dVar1 = static_cast<double>(*reinterpret_cast<int *>(base + 0x280));
                pdVar3 = local_38 + reinterpret_cast<int>(local_8);
                if (*reinterpret_cast<int *>(base + 0x280) < 0) {
                    dVar1 = dVar1 + 4294967296.0;
                }
            } else if (iVar2 == 3) {
                dVar1 = static_cast<double>(*reinterpret_cast<int *>(base + 0x280));
                pdVar3 = local_38 + reinterpret_cast<int>(local_8);
            } else {
                if (iVar2 == 4) goto LAB_0060cc97;
                if ((iVar2 < 5) || (8 < iVar2)) goto LAB_0060cdaf;
                dVar1 = *reinterpret_cast<double *>(base + 0x280);
                pdVar3 = local_38 + reinterpret_cast<int>(local_8);
            }
            bVar8 = local_c != 0;
            *pdVar3 = dVar1;
            if (bVar8) {
                *pdVar3 = -*pdVar3;
            }
            local_8 = reinterpret_cast<uint32_t *>(reinterpret_cast<int>(local_8) + 1);
        } while (reinterpret_cast<int>(local_8) < 4);
        iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
        if (iVar2 < 0) goto LAB_0060cdcd;
        if (*reinterpret_cast<int *>(base + 0x278) != 1) goto LAB_0060cdaf;
        iVar2 = 2;
        bVar8 = true;
        pcVar4 = reinterpret_cast<const char *>(base + 0x280);
        pcVar6 = ")";
        do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar8 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
        } while (bVar8);
        if (!bVar8) goto LAB_0060cdaf;
        iVar2 = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<int32_t *>(base + 0x278));
        if (iVar2 < 0) goto LAB_0060cdcd;
        iVar2 = *reinterpret_cast<int *>(base + 0x278);
        if ((iVar2 != 0xc) && (iVar2 != 0xd)) goto LAB_0060cdaf;
        local_8 = reinterpret_cast<uint32_t *>(FUN_00533c78(0x30));
        if (local_8 == nullptr) {
            local_8 = nullptr;
        } else {
            local_8[10] = 0;
        }
        if (local_8 == nullptr) {
            iVar2 = -0x7ff8fff2;
            goto LAB_0060cdcd;
        }
        *local_8 = local_10;
        local_8[1] = local_14;
        double *pdVar3 = local_38;
        uint32_t *puVar7 = local_8 + 2;
        for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *reinterpret_cast<uint32_t *>(pdVar3);
            pdVar3 = reinterpret_cast<double *>(reinterpret_cast<int>(pdVar3) + 4);
            puVar7 = puVar7 + 1;
        }
        int *piVar5 = reinterpret_cast<int *>(base + 0x3c);
        iVar2 = *piVar5;
        if (iVar2 != 0) {
            do {
                iVar2 = _stricmp(*reinterpret_cast<const char **>(iVar2 + 4), reinterpret_cast<const char *>(local_8[1]));
                if (-1 < iVar2) break;
                piVar5 = reinterpret_cast<int *>(*piVar5 + 0x28);
                iVar2 = *piVar5;
            } while (iVar2 != 0);
        }
        local_8[10] = *reinterpret_cast<uint32_t *>(piVar5);
        *piVar5 = reinterpret_cast<int>(local_8);
    } else {
LAB_0060cdaf:
        if ((*reinterpret_cast<int *>(base + 0x278) != 0xc) && (*reinterpret_cast<int *>(base + 0x278) != 0xd)) {
            FUN_0060f81e();
        }
    }
    iVar2 = 0;
LAB_0060cdcd:
    *reinterpret_cast<uint32_t *>(base + 0x40) = 1;
    return iVar2;
}

extern int FUN_0065aaac(uint32_t a, uint32_t b);
extern void FUN_0060bb27();
extern int32_t DAT_0072be24;

// three-way byte-string compare matching the inline (1 - lt) - (lt != 0) idiom
static int32_t mass0273_strcmp_bsd(const uint8_t *a, const uint8_t *b)
{
    for (;;) {
        uint8_t c1 = *a;
        uint8_t c2 = *b;
        if (c1 != c2) {
            bool lt = c1 < c2;
            return (1 - static_cast<int32_t>(lt)) - static_cast<int32_t>(lt != 0);
        }
        if (c1 == 0) return 0;
        c1 = a[1];
        c2 = b[1];
        if (c1 != c2) {
            bool lt = c1 < c2;
            return (1 - static_cast<int32_t>(lt)) - static_cast<int32_t>(lt != 0);
        }
        a = a + 2;
        b = b + 2;
        if (c1 == 0) return 0;
    }
}

// 0x60cdd8 — observed shape
uint32_t FUN_0060cdd8(const char *param_1)
{
    uint32_t uVar1 = 0x632d80f;
    char cVar2 = '\0';
    if (param_1 == nullptr) {
        uVar1 = 0;
    } else {
        cVar2 = *param_1;
        if (cVar2 == '\0') {
            uVar1 = 0;
        } else {
            do {
                uVar1 = uVar1 * 0x13 + static_cast<int32_t>(cVar2);
                param_1 = param_1 + 1;
                cVar2 = *param_1;
            } while (cVar2 != '\0');
            uVar1 = uVar1 % 0x7f;
        }
    }
    return uVar1;
}

// 0x60ce0f — observed shape
int32_t FUN_0060ce0f(uint32_t *param_1, uint32_t *param_2)
{
    bool bEqual;
    if (mass0273_strcmp_bsd(reinterpret_cast<const uint8_t *>(*param_1),
                            reinterpret_cast<const uint8_t *>(*param_2)) != 0) {
        return 0;
    }
    int32_t iVar5 = static_cast<int32_t>(param_1[1]);
    int32_t iVar8 = static_cast<int32_t>(param_2[1]);
    int32_t iVar2 = iVar8;
    int32_t iVar6 = iVar8;
    if (iVar5 != 0) {
        do {
            iVar6 = 0;
            if (iVar8 == 0) break;
            iVar5 = *reinterpret_cast<int32_t *>(iVar5 + 0xc);
            iVar8 = *reinterpret_cast<int32_t *>(iVar8 + 0xc);
            iVar6 = iVar8;
        } while (iVar5 != 0);
        if (iVar5 != 0) {
            return 0;
        }
    }
    if (iVar6 != 0) {
        return 0;
    }
    iVar5 = static_cast<int32_t>(param_1[2]);
    iVar8 = static_cast<int32_t>(param_2[2]);
    for (;;) {
        if (iVar5 == 0) {
            if (iVar8 == 0) {
                return 1;
            }
            return 0;
        }
        if (iVar8 == 0) {
            return 0;
        }
        iVar6 = *reinterpret_cast<int32_t *>(iVar5 + 0x10);
        if (iVar6 != *reinterpret_cast<int32_t *>(iVar8 + 0x10)) {
            return 0;
        }
        if (iVar6 > 8) {
            if (iVar6 == 9) {
                bool bMatched = false;
                int32_t nCount = 1;
                for (int32_t it = static_cast<int32_t>(param_1[1]); it != 0; it = *reinterpret_cast<int32_t *>(it + 0xc)) {
                    if (mass0273_strcmp_bsd(*reinterpret_cast<const uint8_t **>(it + 0x18),
                                            *reinterpret_cast<const uint8_t **>(iVar5 + 0x18)) == 0) {
                        bMatched = true;
                        break;
                    }
                    nCount = nCount + 1;
                }
                for (int32_t it = iVar2; it != 0; it = *reinterpret_cast<int32_t *>(it + 0xc)) {
                    if (mass0273_strcmp_bsd(*reinterpret_cast<const uint8_t **>(it + 0x18),
                                            *reinterpret_cast<const uint8_t **>(iVar8 + 0x18)) == 0) {
                        bMatched = true;
                        break;
                    }
                    nCount = nCount - 1;
                }
                if (bMatched) {
                    if (nCount != 0) {
                        return 0;
                    }
                    iVar5 = *reinterpret_cast<int32_t *>(iVar5 + 0xc);
                    iVar8 = *reinterpret_cast<int32_t *>(iVar8 + 0xc);
                    continue;
                }
                bEqual = mass0273_strcmp_bsd(*reinterpret_cast<const uint8_t **>(iVar8 + 0x18),
                                             *reinterpret_cast<const uint8_t **>(iVar5 + 0x18)) == 0;
            } else if ((iVar6 < 10) || (0xb < iVar6)) {
                iVar5 = *reinterpret_cast<int32_t *>(iVar5 + 0xc);
                iVar8 = *reinterpret_cast<int32_t *>(iVar8 + 0xc);
                continue;
            } else {
                bEqual = mass0273_strcmp_bsd(*reinterpret_cast<const uint8_t **>(iVar8 + 0x18),
                                             *reinterpret_cast<const uint8_t **>(iVar5 + 0x18)) == 0;
            }
        } else if (iVar6 < 5) {
            if (iVar6 == 1) {
                if (((*reinterpret_cast<char *>(iVar5 + 0x18) != *reinterpret_cast<char *>(iVar8 + 0x18)) ||
                     (*reinterpret_cast<char *>(iVar5 + 0x19) != *reinterpret_cast<char *>(iVar8 + 0x19)) ||
                     (*reinterpret_cast<char *>(iVar5 + 0x1a) != *reinterpret_cast<char *>(iVar8 + 0x1a)) ||
                     (*reinterpret_cast<char *>(iVar5 + 0x1b) != *reinterpret_cast<char *>(iVar8 + 0x1b)))) {
                    return 0;
                }
                iVar5 = *reinterpret_cast<int32_t *>(iVar5 + 0xc);
                iVar8 = *reinterpret_cast<int32_t *>(iVar8 + 0xc);
                continue;
            }
            bEqual = *reinterpret_cast<int32_t *>(iVar5 + 0x18) == *reinterpret_cast<int32_t *>(iVar8 + 0x18);
        } else {
            if (*reinterpret_cast<double *>(iVar5 + 0x18) != *reinterpret_cast<double *>(iVar8 + 0x18)) {
                return 0;
            }
            iVar5 = *reinterpret_cast<int32_t *>(iVar5 + 0xc);
            iVar8 = *reinterpret_cast<int32_t *>(iVar8 + 0xc);
            continue;
        }
        if (!bEqual) {
            return 0;
        }
        iVar5 = *reinterpret_cast<int32_t *>(iVar5 + 0xc);
        iVar8 = *reinterpret_cast<int32_t *>(iVar8 + 0xc);
    }
}

// 0x60d07b — observed shape
bool FUN_0060d07b(void *self, const uint8_t *param_1)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    int32_t iVar2 = static_cast<int32_t>(FUN_0060cdd8(reinterpret_cast<const char *>(param_1)));
    uint32_t *puVar5 = *reinterpret_cast<uint32_t **>(base + 0x6c + iVar2 * 4);
    for (;;) {
        if (puVar5 == nullptr) {
            return false;
        }
        const uint8_t *pbVar3 = reinterpret_cast<const uint8_t *>(*puVar5);
        const uint8_t *pbVar6 = param_1;
        uint8_t bVar1;
        bool bVar7;
        for (;;) {
            bVar1 = *pbVar6;
            bVar7 = bVar1 < *pbVar3;
            if (bVar1 != *pbVar3) {
                iVar2 = (1 - static_cast<int32_t>(bVar7)) - static_cast<int32_t>(bVar7 != 0);
                break;
            }
            if (bVar1 == 0) {
                iVar2 = 0;
                break;
            }
            bVar1 = pbVar6[1];
            bVar7 = bVar1 < pbVar3[1];
            if (bVar1 != pbVar3[1]) {
                iVar2 = (1 - static_cast<int32_t>(bVar7)) - static_cast<int32_t>(bVar7 != 0);
                break;
            }
            pbVar6 = pbVar6 + 2;
            pbVar3 = pbVar3 + 2;
            if (bVar1 == 0) {
                iVar2 = 0;
                break;
            }
        }
        if (iVar2 < 0) {
            return false;
        }
        if (iVar2 == 0) {
            if (puVar5[4] != 0) {
                return true;
            }
            iVar2 = static_cast<int32_t>(puVar5[2]);
            puVar5[4] = 1;
            while ((iVar2 != 0 &&
                    ((*reinterpret_cast<int32_t *>(iVar2 + 0x10) != 9 ||
                      (FUN_0060d07b(self, *reinterpret_cast<const uint8_t **>(iVar2 + 0x18)) == false))))) {
                iVar2 = *reinterpret_cast<int32_t *>(iVar2 + 0xc);
            }
            puVar5[4] = 0;
            return iVar2 != 0;
        }
        puVar5 = reinterpret_cast<uint32_t *>(puVar5[3]);
    }
}

// 0x60d114 — observed shape
uint32_t FUN_0060d114(void *self, const uint8_t *param_1, uint32_t *param_2, uint32_t *param_3)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    if (FUN_0060d07b(self, param_1) != 0) {
        return 0;
    }
    int32_t iVar2 = static_cast<int32_t>(FUN_0060cdd8(reinterpret_cast<const char *>(param_1)));
    for (uint32_t *puVar4 = *reinterpret_cast<uint32_t **>(base + 0x6c + iVar2 * 4); puVar4 != nullptr;
         puVar4 = reinterpret_cast<uint32_t *>(puVar4[3])) {
        const uint8_t *pbVar3 = reinterpret_cast<const uint8_t *>(*puVar4);
        const uint8_t *pbVar5 = param_1;
        uint8_t bVar1;
        bool bVar6;
        for (;;) {
            bVar1 = *pbVar5;
            bVar6 = bVar1 < *pbVar3;
            if (bVar1 != *pbVar3) {
                iVar2 = (1 - static_cast<int32_t>(bVar6)) - static_cast<int32_t>(bVar6 != 0);
                break;
            }
            if (bVar1 == 0) {
                iVar2 = 0;
                break;
            }
            bVar1 = pbVar5[1];
            bVar6 = bVar1 < pbVar3[1];
            if (bVar1 != pbVar3[1]) {
                iVar2 = (1 - static_cast<int32_t>(bVar6)) - static_cast<int32_t>(bVar6 != 0);
                break;
            }
            pbVar5 = pbVar5 + 2;
            pbVar3 = pbVar3 + 2;
            if (bVar1 == 0) {
                iVar2 = 0;
                break;
            }
        }
        if (iVar2 < 0) {
            return 0;
        }
        if (iVar2 == 0) {
            if (param_2 != nullptr) {
                *param_2 = puVar4[1];
            }
            if (param_3 != nullptr) {
                *param_3 = puVar4[2];
            }
            return 1;
        }
    }
    return 0;
}

// 0x60d19b — observed shape
void FUN_0060d19b(uint32_t param_1)
{
    FUN_0065aaac(param_1, 0x10);
    return;
}

// 0x60d1b4 — observed shape
void FUN_0060d1b4(const char *param_1, int param_2, int param_3)
{
    int iVar3 = 0;
    bool bVar1 = false;
    bool bVar2 = false;
    if (param_2 != 0) {
        do {
            if (*param_1 == '\"') {
                if (param_3 != 0) {
                    *reinterpret_cast<uint8_t *>(iVar3 + param_3) = 0x5c;
                }
                iVar3 = iVar3 + 1;
                if (!bVar1) {
                    bVar2 = !bVar2;
                }
            }
            bVar1 = false;
            if ((bVar2) && (*param_1 == '\\')) {
                if (param_3 != 0) {
                    *reinterpret_cast<uint8_t *>(iVar3 + param_3) = 0x5c;
                }
                iVar3 = iVar3 + 1;
                bVar1 = true;
            }
            if (param_3 != 0) {
                *reinterpret_cast<char *>(iVar3 + param_3) = *param_1;
            }
            iVar3 = iVar3 + 1;
            param_1 = param_1 + 1;
            param_2 = param_2 + -1;
        } while (param_2 != 0);
    }
    return;
}

// 0x60d21b — observed shape
int32_t FUN_0060d21b(void *self, int32_t param_1)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    if (param_1 == 0) {
        if (*reinterpret_cast<int32_t *>(base + 0x44) == 0) {
            FUN_0060fcd3(base + 0x18, base + 0x278, 0, "internal error: production failed");
            *reinterpret_cast<uint32_t *>(base + 0x44) = 1;
        }
        param_1 = 0;
    }
    return param_1;
}

// 0x60d256 — observed shape
void FUN_0060d256(void *self)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    void *pvVar1 = *reinterpret_cast<void **>(base + 0xc);
    if (pvVar1 != nullptr) {
        FUN_0060d256(pvVar1);
        operator_delete(pvVar1);
    }
    return;
}

// 0x60d270 — observed shape
void FUN_0060d270(void *self, uint8_t param_1)
{
    FUN_0060d256(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x60d291 — observed shape
void FUN_0060d291(void *self)
{
    uint8_t *base = static_cast<uint8_t *>(self);
    FUN_0060bb27();
    *reinterpret_cast<uint32_t *>(base + 0x2a4) = 1;
    int32_t iVar1 = reinterpret_cast<int32_t>(base);
    *reinterpret_cast<int32_t *>(base + 0x2a8) = DAT_0072be24;
    DAT_0072be24 = iVar1;
    return;
}
