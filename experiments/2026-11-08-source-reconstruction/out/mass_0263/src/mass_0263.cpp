#include <cstdint>
#include <cstddef>

// extern helpers referenced by later functions in this batch are declared
// alongside their uses.

// 0x5fc6c4 — observed shape
uint32_t FUN_005fc6c4(void *self) {
    int *ctx = (int *)(intptr_t)self;
    int iVar3;
    uint16_t *puVar7;
    uint16_t *puVar4;
    uint16_t *puVar9;
    {
        iVar3 = ctx[0];
        puVar7 = *(uint16_t **)((intptr_t)ctx[1] + 0x20);
        puVar4 = *(uint16_t **)((intptr_t)iVar3 + 0x20);
        puVar9 = (uint16_t *)(*(int *)((intptr_t)iVar3 + 0x6c) * *(int *)((intptr_t)iVar3 + 0x60) + (intptr_t)puVar4);
    }
    for (; puVar4 < puVar9; puVar4 = puVar4 + *(int *)((intptr_t)iVar3 + 0x60)) {
        int iVar5 = *(int *)((intptr_t)iVar3 + 0x68);
        uint16_t *puVar10 = (uint16_t *)(*(int *)((intptr_t)iVar3 + 0x60) + (intptr_t)puVar4);
        uint16_t *puVar6 = puVar7;
        for (uint16_t *puVar8 = puVar4; puVar8 < puVar4 + iVar5; puVar8 = puVar8 + 2) {
            uint16_t uVar2 = *puVar10;
            uint16_t *puVar1 = puVar10 + 1;
            puVar10 = puVar10 + 2;
            *puVar6 = (uint16_t)(((*puVar1 & 0xffff03e0) + (*puVar8 & 0xffff03e0) + (uVar2 & 0xffff03e0) +
                                 0x40 + (puVar8[1] & 0xffff03e0) >> 2) & 0x3e0 |
                        (uint16_t)((*puVar1 & 0x7c1f) + (*puVar8 & 0x7c1f) + (uVar2 & 0x7c1f) + 0x802 +
                                 (puVar8[1] & 0x7c1f) >> 2) & 0x7c1f);
            puVar6 = puVar6 + 1;
        }
        puVar7 = (uint16_t *)((intptr_t)puVar7 + *(int *)((intptr_t)ctx[1] + 0x60));
        iVar3 = ctx[0];
    }
    return 0;
}

// 0x5fc7c9 — observed shape
uint32_t FUN_005fc7c9(void *self) {
    int *ctx = (int *)(intptr_t)self;
    int iVar1 = ctx[0];
    uint16_t *puVar2 = *(uint16_t **)((intptr_t)iVar1 + 0x20);
    uint16_t *puVar10 = *(uint16_t **)((intptr_t)ctx[1] + 0x20);
    uint16_t *puVar5 = (uint16_t *)(*(int *)((intptr_t)iVar1 + 0x6c) * *(int *)((intptr_t)iVar1 + 0x60) + (intptr_t)puVar2);
    for (; puVar2 < puVar5; puVar2 = puVar2 + *(int *)((intptr_t)iVar1 + 0x60)) {
        int iVar3 = *(int *)((intptr_t)iVar1 + 0x68);
        uint16_t *puVar11 = (uint16_t *)(*(int *)((intptr_t)iVar1 + 0x60) + (intptr_t)puVar2);
        uint16_t *puVar4 = puVar10;
        for (uint16_t *puVar8 = puVar2; puVar8 < puVar2 + iVar3; puVar8 = puVar8 + 2) {
            uint uVar6 = (uint)puVar8[1];
            uint uVar9 = (uint)puVar11[1];
            uint uVar7 = (uint)*puVar11;
            uint uVar12 = (uint)*puVar8;
            puVar11 = puVar11 + 2;
            *puVar4 = (uint16_t)(((uVar9 & 0x83e0) + (uVar12 & 0x83e0) + (uVar7 & 0x83e0) + 0x10040 +
                                  (uVar6 & 0x83e0) ^
                                 (uVar9 & 0x7c1f) + (uVar12 & 0x7c1f) + (uVar7 & 0x7c1f) + 0x802 +
                                  (uVar6 & 0x7c1f)) >> 2) & 0x7c1f ^
                        (uint16_t)((uVar9 & 0x83e0) + (uVar12 & 0x83e0) + (uVar7 & 0x83e0) + 0x10040 +
                                  (uVar6 & 0x83e0) >> 2));
            puVar4 = puVar4 + 1;
        }
        puVar10 = (uint16_t *)((intptr_t)puVar10 + *(int *)((intptr_t)ctx[1] + 0x60));
        iVar1 = ctx[0];
    }
    return 0;
}

// 0x5fc8f2 — observed shape
uint32_t FUN_005fc8f2(void *self) {
    int *ctx = (int *)(intptr_t)self;
    int iVar4 = ctx[0];
    uint16_t *puVar9 = *(uint16_t **)((intptr_t)ctx[1] + 0x20);
    uint16_t *puVar5 = *(uint16_t **)((intptr_t)iVar4 + 0x20);
    uint16_t *puVar11 = (uint16_t *)(*(int *)((intptr_t)iVar4 + 0x6c) * *(int *)((intptr_t)iVar4 + 0x60) + (intptr_t)puVar5);
    for (; puVar5 < puVar11; puVar5 = puVar5 + *(int *)((intptr_t)iVar4 + 0x60)) {
        int iVar6 = *(int *)((intptr_t)iVar4 + 0x68);
        uint16_t *puVar12 = (uint16_t *)(*(int *)((intptr_t)iVar4 + 0x60) + (intptr_t)puVar5);
        uint16_t *puVar7 = puVar9;
        for (uint16_t *puVar10 = puVar5; puVar10 < puVar5 + iVar6; puVar10 = puVar10 + 2) {
            uint uVar8 = (uint)*puVar12;
            uint16_t uVar1 = puVar12[1];
            uint16_t uVar2 = puVar10[1];
            uint16_t uVar3 = *puVar10;
            *puVar7 = (uint16_t)(((uint)(uVar1 & 0xf0f0) + (uint)(uVar3 & 0xf0f0) + (uVar8 & 0xfffff0f0) +
                                  0x2020 + (uint)(uVar2 & 0xf0f0) ^
                                 (uVar1 & 0xffff0f0f) + (uVar3 & 0xffff0f0f) + (uVar8 & 0xffff0f0f) + 0x202
                                  + (uVar2 & 0xffff0f0f)) >> 2) & 0xf0f ^
                        (uint16_t)((uVar1 & 0xf0f0) + (uVar3 & 0xf0f0) + (uVar8 & 0xf0f0) + 0x2020 +
                                  (uVar2 & 0xf0f0) >> 2));
            puVar12 = puVar12 + 2;
            puVar7 = puVar7 + 1;
        }
        puVar9 = (uint16_t *)((intptr_t)puVar9 + *(int *)((intptr_t)ctx[1] + 0x60));
        iVar4 = ctx[0];
    }
    return 0;
}

// 0x5fca29 — observed shape
uint32_t FUN_005fca29(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint8_t *pbVar9 = *(uint8_t **)((intptr_t)ctx[1] + 0x20);
    int iVar4 = ctx[0];
    uint8_t *pbVar5 = *(uint8_t **)((intptr_t)iVar4 + 0x20);
    uint8_t *pbVar12 = pbVar5 + *(int *)((intptr_t)iVar4 + 0x6c) * *(int *)((intptr_t)iVar4 + 0x60);
    for (; pbVar5 < pbVar12; pbVar5 = pbVar5 + *(int *)((intptr_t)iVar4 + 0x60) * 2) {
        int iVar6 = *(int *)((intptr_t)iVar4 + 0x68);
        uint8_t *pbVar10 = pbVar5 + *(int *)((intptr_t)iVar4 + 0x60);
        uint8_t *pbVar7 = pbVar9;
        for (uint8_t *pbVar11 = pbVar5; pbVar11 < pbVar5 + iVar6; pbVar11 = pbVar11 + 2) {
            uint uVar8 = (uint)*pbVar10;
            uint8_t bVar1 = pbVar10[1];
            uint8_t bVar2 = pbVar11[1];
            uint8_t bVar3 = *pbVar11;
            *pbVar7 = (uint8_t)(((uint8_t)((bVar1 & 0x1c) + (bVar3 & 0x1c) + (uVar8 & 0x1c) + 8 + (bVar2 & 0x1c) >> 2)
                        ^ (uint8_t)((uint)(bVar1 & 0xe3) + (uint)(bVar3 & 0xe3) + (uVar8 & 0xffff00e3) + 0x42 +
                                 (uint)(bVar2 & 0xe3) >> 2)) & 0x1c ^
                        (uint8_t)((uint)(bVar1 & 0xe3) + (bVar3 & 0xffff00e3) + (uVar8 & 0xffff00e3) + 0x42 +
                       (uint)(bVar2 & 0xe3) >> 2));
            pbVar10 = pbVar10 + 2;
            pbVar7 = pbVar7 + 1;
        }
        pbVar9 = pbVar9 + *(int *)((intptr_t)ctx[1] + 0x60);
        iVar4 = ctx[0];
    }
    return 0;
}

// 0x5fcb47 — observed shape
uint32_t FUN_005fcb47(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint8_t *puVar8 = *(uint8_t **)((intptr_t)ctx[1] + 0x20);
    int iVar6 = ctx[0];
    uint8_t *pbVar9 = *(uint8_t **)((intptr_t)iVar6 + 0x20);
    uint8_t *pbVar10 = pbVar9 + *(int *)((intptr_t)iVar6 + 0x6c) * *(int *)((intptr_t)iVar6 + 0x60);
    for (; pbVar9 < pbVar10; pbVar9 = pbVar9 + *(int *)((intptr_t)iVar6 + 0x60) * 2) {
        int iVar4 = *(int *)((intptr_t)iVar6 + 0x68);
        uint8_t *pbVar7 = pbVar9 + *(int *)((intptr_t)iVar6 + 0x60);
        uint8_t *puVar5 = puVar8;
        for (uint8_t *pbVar2 = pbVar9; pbVar2 < pbVar9 + iVar4; pbVar2 = pbVar2 + 2) {
            uint8_t *pbVar1 = pbVar7 + 1;
            uint8_t bVar3 = *pbVar7;
            pbVar7 = pbVar7 + 2;
            *puVar5 = (uint8_t)((uint)*pbVar1 + (uint)pbVar2[1] + (uint)bVar3 + 2 + (uint)*pbVar2 >> 2);
            puVar5 = puVar5 + 1;
        }
        puVar8 = puVar8 + *(int *)((intptr_t)ctx[1] + 0x60);
        iVar6 = ctx[0];
    }
    return 0;
}

// 0x5fcbd3 — observed shape
uint32_t FUN_005fcbd3(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint16_t *puVar9 = *(uint16_t **)((intptr_t)ctx[1] + 0x20);
    int iVar4 = ctx[0];
    uint16_t *puVar5 = *(uint16_t **)((intptr_t)iVar4 + 0x20);
    uint16_t *puVar12 = (uint16_t *)(*(int *)((intptr_t)iVar4 + 0x6c) * *(int *)((intptr_t)iVar4 + 0x60) + (intptr_t)puVar5);
    for (; puVar5 < puVar12; puVar5 = puVar5 + *(int *)((intptr_t)iVar4 + 0x60)) {
        int iVar6 = *(int *)((intptr_t)iVar4 + 0x68);
        uint16_t *puVar10 = (uint16_t *)(*(int *)((intptr_t)iVar4 + 0x60) + (intptr_t)puVar5);
        uint16_t *puVar7 = puVar9;
        for (uint16_t *puVar11 = puVar5; puVar11 < puVar5 + iVar6; puVar11 = puVar11 + 2) {
            uint16_t uVar1 = puVar10[1];
            uint uVar8 = (uint)*puVar10;
            uint16_t uVar2 = *puVar11;
            uint16_t uVar3 = puVar11[1];
            *puVar7 = (uint8_t)((uint8_t)((uint)(uVar1 & 0xe3) + (uint)(uVar2 & 0xe3) + (uVar8 & 0xffff00e3) +
                                    0x42 + (uint)(uVar3 & 0xe3) >> 2) ^
                            (uint8_t)((uint)(uVar1 & 0xff1c) + (uVar2 & 0xffffff1c) + (uVar8 & 0xffffff1c) +
                                   0x208 + (uint)(uVar3 & 0xff1c) >> 2)) & 0xe3 ^
                      (uint16_t)((uVar1 & 0xff1c) + (uVar2 & 0xff1c) + (uVar8 & 0xff1c) + 0x208 +
                               (uVar3 & 0xff1c) >> 2);
            puVar10 = puVar10 + 2;
            puVar7 = puVar7 + 1;
        }
        puVar9 = (uint16_t *)((intptr_t)puVar9 + *(int *)((intptr_t)ctx[1] + 0x60));
        iVar4 = ctx[0];
    }
    return 0;
}

// 0x5fcd01 — observed shape
uint32_t FUN_005fcd01(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint16_t *puVar10 = *(uint16_t **)((intptr_t)ctx[1] + 0x20);
    int iVar3 = ctx[0];
    uint16_t *puVar4 = *(uint16_t **)((intptr_t)iVar3 + 0x20);
    uint16_t *puVar7 = (uint16_t *)(*(int *)((intptr_t)iVar3 + 0x6c) * *(int *)((intptr_t)iVar3 + 0x60) + (intptr_t)puVar4);
    for (; puVar4 < puVar7; puVar4 = puVar4 + *(int *)((intptr_t)iVar3 + 0x60)) {
        int iVar5 = *(int *)((intptr_t)iVar3 + 0x68);
        uint16_t *puVar9 = (uint16_t *)(*(int *)((intptr_t)iVar3 + 0x60) + (intptr_t)puVar4);
        uint16_t *puVar6 = puVar10;
        for (uint16_t *puVar8 = puVar4; puVar8 < puVar4 + iVar5; puVar8 = puVar8 + 2) {
            uint16_t *puVar1 = puVar9 + 1;
            uint16_t uVar2 = *puVar9;
            puVar9 = puVar9 + 2;
            *puVar6 = (uint16_t)((*puVar1 & 0xffff00f0) + (*puVar8 & 0xffff00f0) + (uVar2 & 0xffff00f0) +
                               0x20 + (puVar8[1] & 0xffff00f0) >> 2) & 0xf0 |
                      (uint16_t)((*puVar1 & 0xffff0f0f) + (*puVar8 & 0xffff0f0f) + (uint)(uVar2 & 0xf0f) +
                               0x202 + (uint)(puVar8[1] & 0xf0f) >> 2) & 0xf0f;
            puVar6 = puVar6 + 1;
        }
        puVar10 = (uint16_t *)((intptr_t)puVar10 + *(int *)((intptr_t)ctx[1] + 0x60));
        iVar3 = ctx[0];
    }
    return 0;
}

// 0x5fce0a — observed shape
uint32_t FUN_005fce0a(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint16_t *puVar9 = *(uint16_t **)((intptr_t)ctx[1] + 0x20);
    int iVar4 = ctx[0];
    uint16_t *puVar5 = *(uint16_t **)((intptr_t)iVar4 + 0x20);
    uint16_t *puVar12 = (uint16_t *)(*(int *)((intptr_t)iVar4 + 0x6c) * *(int *)((intptr_t)iVar4 + 0x60) + (intptr_t)puVar5);
    for (; puVar5 < puVar12; puVar5 = puVar5 + *(int *)((intptr_t)iVar4 + 0x60)) {
        int iVar6 = *(int *)((intptr_t)iVar4 + 0x68);
        uint16_t *puVar10 = (uint16_t *)(*(int *)((intptr_t)iVar4 + 0x60) + (intptr_t)puVar5);
        uint16_t *puVar7 = puVar9;
        for (uint16_t *puVar11 = puVar5; puVar11 < puVar5 + iVar6; puVar11 = puVar11 + 2) {
            uint16_t uVar1 = puVar10[1];
            uint uVar8 = (uint)*puVar10;
            uint16_t uVar2 = *puVar11;
            uint16_t uVar3 = puVar11[1];
            *puVar7 = (uint16_t)(uint8_t)((uint8_t)((uint)(uVar1 & 0xff) + (uint)(uVar2 & 0xff) +
                                    (uVar8 & 0xffff00ff) + 2 + (uint)(uVar3 & 0xff) >> 2) ^
                            (uint8_t)((uint)(uVar1 & 0xff00) + (uVar2 & 0xffffff00) +
                                   (uVar8 & 0xffffff00) + 0x200 + (uint)(uVar3 & 0xff00) >> 2)) ^
                      (uint16_t)((uVar1 & 0xff00) + (uVar2 & 0xff00) + (uVar8 & 0xff00) + 0x200 +
                               (uVar3 & 0xff00) >> 2);
            puVar10 = puVar10 + 2;
            puVar7 = puVar7 + 1;
        }
        puVar9 = (uint16_t *)((intptr_t)puVar9 + *(int *)((intptr_t)ctx[1] + 0x60));
        iVar4 = ctx[0];
    }
    return 0;
}

// 0x5fcf38 — observed shape
uint32_t FUN_005fcf38(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint8_t *pbVar9 = *(uint8_t **)((intptr_t)ctx[1] + 0x20);
    int iVar4 = ctx[0];
    uint8_t *pbVar5 = *(uint8_t **)((intptr_t)iVar4 + 0x20);
    uint8_t *pbVar12 = pbVar5 + *(int *)((intptr_t)iVar4 + 0x6c) * *(int *)((intptr_t)iVar4 + 0x60);
    for (; pbVar5 < pbVar12; pbVar5 = pbVar5 + *(int *)((intptr_t)iVar4 + 0x60) * 2) {
        int iVar6 = *(int *)((intptr_t)iVar4 + 0x68);
        uint8_t *pbVar10 = pbVar5 + *(int *)((intptr_t)iVar4 + 0x60);
        uint8_t *pbVar7 = pbVar9;
        for (uint8_t *pbVar11 = pbVar5; pbVar11 < pbVar5 + iVar6; pbVar11 = pbVar11 + 2) {
            uint uVar8 = (uint)*pbVar10;
            uint8_t bVar1 = pbVar10[1];
            uint8_t bVar2 = pbVar11[1];
            uint8_t bVar3 = *pbVar11;
            *pbVar7 = (uint8_t)(((uint8_t)((bVar1 & 0xf) + (bVar3 & 0xf) + (uVar8 & 0xf) + 2 + (bVar2 & 0xf) >> 2) ^
                      (uint8_t)((uint)(bVar1 & 0xf0) + (uint)(bVar3 & 0xf0) + (uVar8 & 0xffff00f0) + 0x20 +
                             (uint)(bVar2 & 0xf0) >> 2)) & 0xf ^
                      (uint8_t)((uint)(bVar1 & 0xf0) + (bVar3 & 0xffff00f0) + (uVar8 & 0xffff00f0) + 0x20 +
                             (uint)(bVar2 & 0xf0) >> 2));
            pbVar10 = pbVar10 + 2;
            pbVar7 = pbVar7 + 1;
        }
        pbVar9 = pbVar9 + *(int *)((intptr_t)ctx[1] + 0x60);
        iVar4 = ctx[0];
    }
    return 0;
}

// 0x5fd056 — observed shape
extern int32_t FUN_005fc059(void);
extern void* FUN_00533c78(int size);
extern void FUN_004127b0(void* dst, int stride, int count, void* fn);
extern void FUN_005f6015(void* p);
extern void operator_delete(void* p);
uint32_t FUN_005fd056(void *self) {
    int *ctx = (int *)(intptr_t)self;
    int iVar4 = ctx[1];
    int iVar10 = ctx[0];
    if ((*(int *)((intptr_t)iVar4 + 4) != *(int *)((intptr_t)iVar10 + 4)) || (*(int *)((intptr_t)iVar10 + 0x18)) != 0) {
        return 0x80004005u;
    }
    uint32_t uVar1;
    if ((*(int *)((intptr_t)iVar4 + 0x68) == *(int *)((intptr_t)iVar10 + 0x68)) &&
        (*(int *)((intptr_t)iVar4 + 0x6c) == *(int *)((intptr_t)iVar10 + 0x6c)) &&
        (*(int *)((intptr_t)iVar4 + 0x70) == *(int *)((intptr_t)iVar10 + 0x70)) &&
        (*(int *)((intptr_t)iVar4 + 0x10) == *(int *)((intptr_t)iVar10 + 0x10))) {
        if (*(int *)((intptr_t)iVar4 + 0xc) == 0) {
            uVar1 = (uint32_t)FUN_005fc059();
            return uVar1;
        }
        if (*(int *)((intptr_t)iVar4 + 0x1c) != 0) {
            if (*(int **)((intptr_t)iVar4 + 0x38) != *(int **)((intptr_t)iVar10 + 0x38)) {
                int iVar3 = 0x100;
                bool bVar13 = true;
                int *piVar8 = *(int **)((intptr_t)iVar4 + 0x38);
                int *piVar11 = *(int **)((intptr_t)iVar10 + 0x38);
                do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar13 = *piVar8 == *piVar11;
                    piVar8 = piVar8 + 1;
                    piVar11 = piVar11 + 1;
                } while (bVar13);
                if (!bVar13) goto LAB_005fd156;
            }
        }
        *(int *)((intptr_t)iVar4 + 0x10) = 0;
        *(int *)((intptr_t)*ctx + 0x10) = 0;
        iVar4 = ctx[1];
        uint local_8 = 0;
        if (*(int *)((intptr_t)iVar4 + 0x70) != 0) {
            iVar10 = *ctx;
            uint uVar6 = *(uint *)((intptr_t)iVar4 + 0x6c);
            do {
                uint32_t *puVar2 = (uint32_t *)(*(int *)((intptr_t)ctx[1] + 100) * local_8 + *(int *)((intptr_t)ctx[1] + 0x20));
                uint32_t *puVar7 = (uint32_t *)(*(int *)((intptr_t)iVar10 + 100) * local_8 + *(int *)((intptr_t)iVar10 + 0x20));
                uint local_c = 0;
                if (uVar6 != 0) {
                    do {
                        uVar6 = *(uint *)((intptr_t)iVar4 + 0x74);
                        uint32_t *puVar9 = puVar7;
                        uint32_t *puVar12 = puVar2;
                        for (uint uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                            *puVar12 = *puVar9;
                            puVar9 = puVar9 + 1;
                            puVar12 = puVar12 + 1;
                        }
                        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                            *(uint8_t *)puVar12 = *(uint8_t *)puVar9;
                            puVar9 = (uint32_t *)((intptr_t)puVar9 + 1);
                            puVar12 = (uint32_t *)((intptr_t)puVar12 + 1);
                        }
                        iVar4 = ctx[1];
                        iVar10 = *ctx;
                        puVar2 = (uint32_t *)((intptr_t)puVar2 + *(int *)((intptr_t)iVar4 + 0x60));
                        puVar7 = (uint32_t *)((intptr_t)puVar7 + *(int *)((intptr_t)iVar10 + 0x60));
                        local_c = local_c + 1;
                        uVar6 = *(uint *)((intptr_t)iVar4 + 0x6c);
                    } while (local_c < uVar6);
                }
                local_8 = local_8 + 1;
                iVar4 = ctx[1];
            } while (local_8 < *(uint *)((intptr_t)iVar4 + 0x70));
        }
        uVar1 = 0;
    } else {
LAB_005fd156:
        uVar1 = 0x80004005;
    }
    return uVar1;
}

// 0x5fd160 — observed shape
uint32_t FUN_005fd160(void *self) {
    int *ctx = (int *)(intptr_t)self;
    int iVar1 = ctx[1];
    int iVar2 = ctx[0];
    int iVar3 = *(int *)((intptr_t)iVar1 + 0x68);
    if ((iVar3 == *(int *)((intptr_t)iVar2 + 0x68)) && (*(int *)((intptr_t)iVar1 + 0x6c) == *(int *)((intptr_t)iVar2 + 0x6c)) &&
        (*(int *)((intptr_t)iVar1 + 0x70) == *(int *)((intptr_t)iVar2 + 0x70))) {
        void *local_8 = (void *)FUN_00533c78(iVar3 << 4);
        if (local_8 == (void *)0x0) {
            local_8 = (void *)0x0;
        } else {
            FUN_004127b0(local_8, 0x10, iVar3, (void *)FUN_005f6015);
        }
        if (local_8 != (void *)0x0) {
            if ((*(int *)((intptr_t)ctx[1] + 0x10) != 0) && (*(int *)((intptr_t)*ctx + 0x10) != 0)) {
                *(int *)((intptr_t)ctx[1] + 0x10) = 0;
                *(int *)((intptr_t)*ctx + 0x10) = 0;
            }
            uint uVar5 = 0;
            if (*(int *)((intptr_t)ctx[1] + 0x70) != 0) {
                uint uVar4 = *(uint *)((intptr_t)ctx[1] + 0x6c);
                do {
                    uint uVar6 = 0;
                    if (uVar4 != 0) {
                        do {
                            (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(uVar6, uVar5, local_8);
                            (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(uVar6, uVar5, local_8);
                            uVar4 = *(uint *)((intptr_t)ctx[1] + 0x6c);
                            uVar6 = uVar6 + 1;
                        } while (uVar6 < uVar4);
                    }
                    uVar5 = uVar5 + 1;
                } while (uVar5 < *(uint *)((intptr_t)ctx[1] + 0x70));
            }
            operator_delete(local_8);
            return 0;
        }
    }
    return 0x80004005u;
}

// 0x5fd233 — observed shape
uint32_t FUN_005fd233(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint32_t uVar2;
    if ((char)ctx[2] == '\x01') {
        int iVar3 = ctx[1];
        int iVar1 = ctx[0];
        uint32_t *local_10 = (uint32_t *)(uint32_t)*(uint *)((intptr_t)iVar3 + 0x68);
        if (*(uint *)((intptr_t)iVar3 + 0x68) <= *(uint *)((intptr_t)iVar1 + 0x68)) {
            local_10 = (uint32_t *)(uint32_t)*(uint *)((intptr_t)iVar1 + 0x68);
        }
        uint32_t *puVar4 = local_10;
        uint local_18 = *(uint *)((intptr_t)iVar3 + 0x6c);
        if (*(uint *)((intptr_t)iVar1 + 0x6c) <= *(uint *)((intptr_t)iVar3 + 0x6c)) {
            local_18 = *(uint *)((intptr_t)iVar1 + 0x6c);
        }
        uint local_14 = *(uint *)((intptr_t)iVar3 + 0x70);
        if (*(uint *)((intptr_t)iVar1 + 0x70) <= *(uint *)((intptr_t)iVar3 + 0x70)) {
            local_14 = *(uint *)((intptr_t)iVar1 + 0x70);
        }
        uint32_t *local_8 = (uint32_t *)FUN_00533c78((int)local_10 << 4);
        if (local_8 == (uint32_t *)0x0) {
            local_8 = (uint32_t *)0x0;
        } else {
            FUN_004127b0(local_8, 0x10, local_10, (void *)FUN_005f6015);
        }
        if (local_8 == (uint32_t *)0x0) {
            uVar2 = 0x80004005;
        } else {
            iVar3 = *(int *)((intptr_t)ctx[1] + 0x68);
            local_10 = (uint32_t *)FUN_00533c78(iVar3 << 4);
            if (local_10 == (uint32_t *)0x0) {
                local_10 = (uint32_t *)0x0;
            } else {
                FUN_004127b0(local_10, 0x10, iVar3, (void *)FUN_005f6015);
            }
            if (local_10 == (uint32_t *)0x0) {
                operator_delete(local_8);
                uVar2 = 0x80004005;
            } else {
                iVar3 = ((uint)puVar4 & 0xfffffff) << 2;
                puVar4 = local_8;
                for (; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *puVar4 = 0;
                    puVar4 = puVar4 + 1;
                }
                for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *(uint8_t *)puVar4 = 0;
                    puVar4 = (uint32_t *)((intptr_t)puVar4 + 1);
                }
                puVar4 = local_10;
                for (iVar3 = (*(uint *)((intptr_t)ctx[1] + 0x68) & 0xfffffff) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *puVar4 = 0;
                    puVar4 = puVar4 + 1;
                }
                for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *(uint8_t *)puVar4 = 0;
                    puVar4 = (uint32_t *)((intptr_t)puVar4 + 1);
                }
                if ((*(int *)((intptr_t)ctx[1] + 0x10) != 0) && (*(int *)((intptr_t)*ctx + 0x10) != 0)) {
                    *(uint32_t *)((intptr_t)ctx[1] + 0x10) = 0;
                    *(uint32_t *)((intptr_t)*ctx + 0x10) = 0;
                }
                uint local_c = 0;
                if (local_14 != 0) {
                    do {
                        uint uVar5 = 0;
                        if (local_18 != 0) {
                            do {
                                (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(uVar5, local_c, local_8);
                                (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(uVar5, local_c, local_8);
                                uVar5 = uVar5 + 1;
                            } while (uVar5 < local_18);
                        }
                        uVar5 = local_18;
                        if (local_18 < *(uint *)((intptr_t)ctx[1] + 0x6c)) {
                            do {
                                (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(uVar5, local_c, local_10);
                                uVar5 = uVar5 + 1;
                            } while (uVar5 < *(uint *)((intptr_t)ctx[1] + 0x6c));
                        }
                        local_c = local_c + 1;
                    } while (local_c < local_14);
                }
                if (local_14 < *(uint *)((intptr_t)ctx[1] + 0x70)) {
                    uint uVar5 = *(uint *)((intptr_t)ctx[1] + 0x6c);
                    do {
                        uint uVar6 = 0;
                        if (uVar5 != 0) {
                            do {
                                (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(uVar6, local_14, local_10);
                                uVar5 = *(uint *)((intptr_t)ctx[1] + 0x6c);
                                uVar6 = uVar6 + 1;
                            } while (uVar6 < uVar5);
                        }
                        local_14 = local_14 + 1;
                    } while (local_14 < *(uint *)((intptr_t)ctx[1] + 0x70));
                }
                operator_delete(local_8);
                operator_delete(local_10);
                uVar2 = 0;
            }
        }
    } else {
        uVar2 = 0x80004005;
    }
    return uVar2;
}

// 0x5fd406 — observed shape
uint32_t FUN_005fd406(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint32_t uVar7;
    if ((char)ctx[2] == '\x02') {
        int iVar1 = *(int *)((intptr_t)*ctx + 0x68);
        void *local_8 = (void *)FUN_00533c78(iVar1 << 4);
        if (local_8 == (void *)0x0) {
            local_8 = (void *)0x0;
        } else {
            FUN_004127b0(local_8, 0x10, iVar1, (void *)FUN_005f6015);
        }
        if (local_8 == (void *)0x0) {
            uVar7 = 0x8007000eu;
        } else {
            iVar1 = *(int *)((intptr_t)ctx[1] + 0x68);
            uint32_t *local_c = (uint32_t *)FUN_00533c78(iVar1 << 4);
            if (local_c == (uint32_t *)0x0) {
                local_c = (uint32_t *)0x0;
            } else {
                FUN_004127b0(local_c, 0x10, iVar1, (void *)FUN_005f6015);
            }
            if (local_c == (uint32_t *)0x0) {
                operator_delete(local_8);
                uVar7 = 0x8007000eu;
            } else {
                if ((*(int *)((intptr_t)ctx[1] + 0x10) != 0) && (*(int *)((intptr_t)*ctx + 0x10) != 0)) {
                    *(uint32_t *)((intptr_t)ctx[1] + 0x10) = 0;
                    *(uint32_t *)((intptr_t)*ctx + 0x10) = 0;
                }
                int iVarA = *ctx;
                int iVar8 = ctx[1];
                int iVar2 = *(int *)((intptr_t)iVarA + 0x68);
                uint uVar3 = *(uint *)((intptr_t)iVar8 + 0x68);
                uint local_20 = 0;
                uint local_14 = 0;
                int iVar4 = *(int *)((intptr_t)iVarA + 0x6c);
                uint uVar5 = *(uint *)((intptr_t)iVar8 + 0x6c);
                int iVarB = *(int *)((intptr_t)iVarA + 0x70);
                uint uVar6 = *(uint *)((intptr_t)iVar8 + 0x70);
                if (*(int *)((intptr_t)iVar8 + 0x70) != 0) {
                    do {
                        uint local_24 = 0xffffffff;
                        uint local_28 = 0;
                        uint local_10 = 0;
                        if (*(int *)((intptr_t)iVar8 + 0x6c) != 0) {
                            do {
                                uint local_18 = 0;
                                uint local_1c = 0;
                                if (((local_24 ^ local_28) & 0xffff0000) != 0) {
                                    (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(local_28 >> 0x10, local_20 >> 0x10, local_8);
                                    local_24 = local_28;
                                }
                                if (*(int *)((intptr_t)ctx[1] + 0x68) != 0) {
                                    uint32_t *puVar9 = local_c;
                                    do {
                                        uint32_t *puVar10 = (uint32_t *)((intptr_t)(local_18 >> 0x10) * 0x10 + (intptr_t)local_8);
                                        local_1c = local_1c + 1;
                                        *puVar9 = *puVar10;
                                        puVar9[1] = puVar10[1];
                                        puVar9[2] = puVar10[2];
                                        puVar9[3] = puVar10[3];
                                        puVar9 = puVar9 + 4;
                                        local_18 = local_18 + (uint)(iVar2 << 0x10) / uVar3;
                                    } while (local_1c < *(uint *)((intptr_t)ctx[1] + 0x68));
                                }
                                (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(local_10, local_14, local_c);
                                local_28 = local_28 + (uint)(iVar4 << 0x10) / uVar5;
                                local_10 = local_10 + 1;
                            } while (local_10 < *(uint *)((intptr_t)ctx[1] + 0x6c));
                        }
                        local_20 = local_20 + (uint)(iVarB << 0x10) / uVar6;
                        local_14 = local_14 + 1;
                        iVar8 = ctx[1];
                    } while (local_14 < *(uint *)((intptr_t)iVar8 + 0x70));
                }
                operator_delete(local_8);
                operator_delete(local_c);
                uVar7 = 0;
            }
        }
    } else {
        uVar7 = 0x80004005;
    }
    return uVar7;
}

// 0x5fd5dc — observed shape
extern uint32_t FUN_005fcd01(void* self);
extern uint32_t FUN_005fcbd3(void* self);
extern uint32_t FUN_005fce0a(void* self);
extern uint32_t FUN_005fcf38(void* self);
extern uint32_t FUN_005fc6c4(void* self);
extern uint32_t FUN_005fc7c9(void* self);
extern uint32_t FUN_005fc8f2(void* self);
extern uint32_t FUN_005fca29(void* self);
extern uint32_t FUN_005fcb47(void* self);
extern uint32_t FUN_005fc2db(void* self);
extern uint32_t FUN_005fc56e(void* self);
extern uint32_t FUN_005fc590(void* self);
uint32_t FUN_005fd5dc(void *self) {
    int *ctx = (int *)(intptr_t)self;
    if ((char)ctx[2] != '\x05') {
        return 0x80004005u;
    }
    int iVar23 = *ctx;
    uint uVar22 = *(uint *)((intptr_t)iVar23 + 0x68);
    int iVar15 = ctx[1];
    if (((*(uint *)((intptr_t)iVar15 + 0x68) != uVar22 >> 1) &&
         ((*(uint *)((intptr_t)iVar15 + 0x68) != 1 || (uVar22 != 1)))) ||
        ((*(uint *)((intptr_t)iVar15 + 0x6c) != *(uint *)((intptr_t)iVar23 + 0x6c) >> 1 &&
          ((*(uint *)((intptr_t)iVar15 + 0x6c) != 1 || (*(int *)((intptr_t)iVar23 + 0x6c)) != 1)))) ||
        ((*(int *)((intptr_t)iVar15 + 0x70)) != 1 || (*(int *)((intptr_t)iVar23 + 0x70)) != 1))) {
        return 0x80004005u;
    }
    if ((1 < uVar22) && ((uVar22 & 1) != 0)) {
        *(uint *)((intptr_t)iVar23 + 0x68) = *(uint *)((intptr_t)iVar23 + 0x68) & 0xfffffffe;
        int *piVar1 = (int *)((intptr_t)*ctx + 0x74);
        *piVar1 = *piVar1 - *(int *)((intptr_t)*ctx + 0x78);
    }
    if (1 < *(uint *)((intptr_t)*ctx + 0x6c)) {
        uint *puVar2 = (uint *)((intptr_t)*ctx + 0x6c);
        *puVar2 = *puVar2 & 0xfffffffe;
    }
    if ((*(uint8_t *)((intptr_t)ctx + 10) & 8) != 0) goto switchD_005fd6c7_caseD_14;
    iVar23 = *ctx;
    iVar15 = *(int *)((intptr_t)iVar23 + 4);
    if ((((iVar15 != *(int *)((intptr_t)ctx[1] + 4)) || (*(uint *)((intptr_t)iVar23 + 0x68)) < 2) ||
        (*(uint *)((intptr_t)iVar23 + 0x6c)) < 2) ||
        ((*(int *)((intptr_t)ctx[1] + 0x10)) != 0 || (*(int *)((intptr_t)iVar23 + 0x10)) != 0)))
        goto switchD_005fd6c7_caseD_14;
    if (iVar15 < 0x1e) {
        if (iVar15 == 0x1d) {
            iVar23 = (int)FUN_005fcbd3(self);
        } else {
            switch (iVar15) {
            default:
                goto switchD_005fd6c7_caseD_14;
            case 0x15:
                iVar23 = (int)FUN_005fc2db(self);
                break;
            case 0x16:
                iVar23 = (int)FUN_005fc56e(self);
                break;
            case 0x17:
                iVar23 = (int)FUN_005fc590(self);
                break;
            case 0x18:
                iVar23 = (int)FUN_005fc6c4(self);
                break;
            case 0x19:
                iVar23 = (int)FUN_005fc7c9(self);
                break;
            case 0x1a:
                iVar23 = (int)FUN_005fc8f2(self);
                break;
            case 0x1b:
                iVar23 = (int)FUN_005fca29(self);
                break;
            case 0x1c:
                iVar23 = (int)FUN_005fcb47(self);
            }
        }
    } else if (iVar15 < 0x2a) {
        if (iVar15 == 0x29) goto switchD_005fd6c7_caseD_14;
        if (iVar15 != 0x1e) {
            if (iVar15 != 0x20) {
                if (iVar15 != 0x21) goto switchD_005fd6c7_caseD_14;
                iVar23 = (int)FUN_005fc56e(self);
            } else {
                iVar23 = (int)FUN_005fc2db(self);
            }
        } else {
            iVar23 = (int)FUN_005fcd01(self);
        }
    } else {
        if (iVar15 == 0x32) {
            iVar23 = (int)FUN_005fcb47(self);
        } else if (iVar15 == 0x33) {
            iVar23 = (int)FUN_005fce0a(self);
        } else {
            if (iVar15 != 0x34) goto switchD_005fd6c7_caseD_14;
            iVar23 = (int)FUN_005fcf38(self);
        }
    }
    if (-1 < iVar23) {
        return 0;
    }
switchD_005fd6c7_caseD_14:;
    uint32_t uVar16;
    iVar23 = *(int *)((intptr_t)ctx[1] + 0x68);
    float *local_14 = (float *)FUN_00533c78(iVar23 << 4);
    if (local_14 == (float *)0x0) {
        local_14 = (float *)0x0;
    } else {
        FUN_004127b0(local_14, 0x10, iVar23, (void *)FUN_005f6015);
    }
    if (local_14 == (float *)0x0) {
        uVar16 = 0x8007000eu;
    } else {
        iVar23 = *(int *)((intptr_t)*ctx + 0x68);
        void *local_8;
        void *local_c;
        if (*(int *)((intptr_t)*ctx + 0x6c) == 1) {
            local_8 = (void *)FUN_00533c78(iVar23 << 4);
            if (local_8 == (void *)0x0) {
                local_8 = (void *)0x0;
            } else {
                FUN_004127b0(local_8, 0x10, iVar23, (void *)FUN_005f6015);
            }
            local_c = local_8;
        } else {
            local_8 = (void *)FUN_00533c78(iVar23 << 5);
            if (local_8 == (void *)0x0) {
                local_8 = (void *)0x0;
            } else {
                FUN_004127b0(local_8, 0x10, iVar23 << 1, (void *)FUN_005f6015);
            }
            local_c = (void *)(*(int *)((intptr_t)*ctx + 0x68) * 0x10 + (intptr_t)local_8);
        }
        if (local_8 == (void *)0x0) {
            uVar16 = 0x8007000eu;
        } else {
            void *pvVar17;
            void *local_1c;
            if (*(int *)((intptr_t)*ctx + 0x68) == 1) {
                pvVar17 = local_c;
                local_1c = local_8;
            } else {
                local_1c = (void *)((intptr_t)local_8 + 0x10);
                pvVar17 = (void *)((intptr_t)local_c + 0x10);
            }
            int local_10 = 0;
            if (*(int *)((intptr_t)ctx[1] + 0x6c) != 0) {
                do {
                    (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(local_10 * 2, 0, local_8);
                    if (local_c != local_8) {
                        (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(local_10 * 2 + 1, 0, local_c);
                    }
                    uVar22 = 0;
                    if (*(int *)((intptr_t)ctx[1] + 0x68) != 0) {
                        float *local_18 = local_14;
                        do {
                            int idx = uVar22 * 0x20;
                            float *pfVar18 = (float *)((intptr_t)local_1c + idx);
                            float *pfVar21 = (float *)((intptr_t)local_8 + idx);
                            float fVar3 = pfVar18[1];
                            float fVar4 = pfVar21[1];
                            float fVar5 = pfVar18[2];
                            float fVar6 = pfVar21[2];
                            float fVar7 = pfVar18[3];
                            float fVar8 = pfVar21[3];
                            float *pfVar19 = (float *)((intptr_t)local_c + idx);
                            float fVar9 = pfVar19[1];
                            float fVar10 = pfVar19[2];
                            float fVar11 = pfVar19[3];
                            float *pfVar20 = (float *)((intptr_t)pvVar17 + idx);
                            uVar22 = uVar22 + 1;
                            float fVar12 = pfVar20[1];
                            float fVar13 = pfVar20[2];
                            float fVar14 = pfVar20[3];
                            *local_18 = (*pfVar18 + *pfVar21 + *pfVar19 + *pfVar20) * 0.25f;
                            local_18[1] = (fVar3 + fVar4 + fVar9 + fVar12) * 0.25f;
                            local_18[2] = (fVar5 + fVar6 + fVar10 + fVar13) * 0.25f;
                            local_18[3] = (fVar7 + fVar8 + fVar11 + fVar14) * 0.25f;
                            local_18 = local_18 + 4;
                        } while (uVar22 < *(uint *)((intptr_t)ctx[1] + 0x68));
                    }
                    (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(local_10, 0, local_14);
                    local_10 = local_10 + 1;
                } while (local_10 < *(uint *)((intptr_t)ctx[1] + 0x6c));
            }
            operator_delete(local_8);
            uVar16 = 0;
        }
        operator_delete(local_14);
    }
    return uVar16;
}

// 0x5fd9a4 — observed shape
uint32_t FUN_005fd9a4(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint32_t uVar29;
    if ((char)ctx[2] == '\x05') {
        int iVar31 = *ctx;
        uint uVar27 = *(uint *)((intptr_t)iVar31 + 0x68);
        int iVar28 = ctx[1];
        if (((*(uint *)((intptr_t)iVar28 + 0x68) == uVar27 >> 1) ||
             ((*(uint *)((intptr_t)iVar28 + 0x68) == 1 && (uVar27 == 1)))) &&
            ((*(uint *)((intptr_t)iVar28 + 0x6c) == *(uint *)((intptr_t)iVar31 + 0x6c) >> 1 ||
              ((*(uint *)((intptr_t)iVar28 + 0x6c) == 1 && (*(int *)((intptr_t)iVar31 + 0x6c)) == 1)))) &&
            (*(uint *)((intptr_t)iVar28 + 0x70) == *(uint *)((intptr_t)iVar31 + 0x70) >> 1))) {
            if ((1 < uVar27) && ((uVar27 & 1) != 0)) {
                *(uint *)((intptr_t)iVar31 + 0x68) = *(uint *)((intptr_t)iVar31 + 0x68) & 0xfffffffe;
                int *piVar33 = (int *)((intptr_t)*ctx + 0x74);
                *piVar33 = *piVar33 - *(int *)((intptr_t)*ctx + 0x78);
            }
            if (1 < *(uint *)((intptr_t)*ctx + 0x6c)) {
                uint *puVar1 = (uint *)((intptr_t)*ctx + 0x6c);
                *puVar1 = *puVar1 & 0xfffffffe;
            }
            if (1 < *(uint *)((intptr_t)*ctx + 0x70)) {
                uint *puVar1 = (uint *)((intptr_t)*ctx + 0x70);
                *puVar1 = *puVar1 & 0xfffffffe;
            }
            iVar31 = *(int *)((intptr_t)ctx[1] + 0x68);
            float *local_14 = (float *)FUN_00533c78(iVar31 << 4);
            if (local_14 == (float *)0x0) {
                local_14 = (float *)0x0;
            } else {
                FUN_004127b0(local_14, 0x10, iVar31, (void *)FUN_005f6015);
            }
            if (local_14 == (float *)0x0) {
                uVar29 = 0x8007000eu;
            } else {
                iVar31 = *(int *)((intptr_t)*ctx + 0x68);
                void *local_8;
                void *local_28;
                void *local_1c;
                void *local_24;
                int *piVar33;
                if (*(int *)((intptr_t)*ctx + 0x6c) == 1) {
                    local_8 = (void *)FUN_00533c78(iVar31 << 5);
                    if (local_8 == (void *)0x0) {
                        local_8 = (void *)0x0;
                    } else {
                        FUN_004127b0(local_8, 0x10, iVar31 << 1, (void *)FUN_005f6015);
                    }
                    piVar33 = (int *)((intptr_t)*ctx + 0x68);
                    local_28 = (void *)(*piVar33 * 0x10 + (intptr_t)local_8);
                    local_1c = local_8;
                    local_24 = local_28;
                } else {
                    local_8 = (void *)FUN_00533c78(iVar31 << 6);
                    if (local_8 == (void *)0x0) {
                        local_8 = (void *)0x0;
                    } else {
                        FUN_004127b0(local_8, 0x10, iVar31 << 2, (void *)FUN_005f6015);
                    }
                    piVar33 = (int *)((intptr_t)*ctx + 0x68);
                    iVar31 = *piVar33;
                    local_28 = (void *)(iVar31 * 0x10 + (intptr_t)local_8);
                    local_1c = (void *)(iVar31 * 0x20 + (intptr_t)local_8);
                    local_24 = (void *)(iVar31 * 0x30 + (intptr_t)local_8);
                }
                if (local_8 == (void *)0x0) {
                    uVar29 = 0x8007000eu;
                } else {
                    void *local_34;
                    void *pvVar30;
                    void *pvVar39;
                    void *local_30;
                    if (*piVar33 == 1) {
                        local_34 = local_8;
                        pvVar30 = local_1c;
                        pvVar39 = local_24;
                        local_30 = local_28;
                    } else {
                        local_34 = (void *)((intptr_t)local_8 + 0x10);
                        local_30 = (void *)((intptr_t)local_28 + 0x10);
                        pvVar30 = (void *)((intptr_t)local_1c + 0x10);
                        pvVar39 = (void *)((intptr_t)local_24 + 0x10);
                    }
                    uint local_18 = 0;
                    iVar31 = ctx[1];
                    if (*(int *)((intptr_t)iVar31 + 0x70) != 0) {
                        do {
                            uint local_c = 0;
                            if (*(int *)((intptr_t)iVar31 + 0x6c) != 0) {
                                do {
                                    int idx = local_18 * 2;
                                    (**(void (**)(uint, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(local_c * 2, idx, local_8);
                                    if (local_28 != local_8) {
                                        (**(void (**)(uint, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(local_c * 2, idx + 1, local_28);
                                    }
                                    if (local_1c != local_8) {
                                        (**(void (**)(uint, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(local_c * 2 + 1, idx, local_1c);
                                    }
                                    if ((local_24 != local_28) && (local_24 != local_1c)) {
                                        (**(void (**)(uint, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(local_c * 2 + 1, idx + 1, local_24);
                                    }
                                    uint local_20 = 0;
                                    if (*(int *)((intptr_t)ctx[1] + 0x68) != 0) {
                                        float *local_2c = local_14;
                                        do {
                                            int off = local_20 * 0x20;
                                            float *pfVar34 = (float *)((intptr_t)local_34 + off);
                                            float *pfVar40 = (float *)((intptr_t)local_8 + off);
                                            float fVar3 = pfVar34[1];
                                            float fVar4 = pfVar40[1];
                                            float fVar5 = pfVar34[2];
                                            float fVar6 = pfVar40[2];
                                            float fVar7 = pfVar34[3];
                                            float *pfVar2 = (float *)(off + (intptr_t)local_28);
                                            float fVar8 = pfVar40[3];
                                            float fVar9 = pfVar2[1];
                                            float fVar10 = pfVar2[2];
                                            float fVar11 = pfVar2[3];
                                            float *pfVar35 = (float *)((intptr_t)local_30 + off);
                                            float fVar12 = pfVar35[1];
                                            float fVar13 = pfVar35[2];
                                            float fVar14 = pfVar35[3];
                                            float *pfVar36 = (float *)((intptr_t)local_1c + off);
                                            float fVar15 = pfVar36[1];
                                            float fVar16 = pfVar36[2];
                                            float fVar17 = pfVar36[3];
                                            float *pfVar37 = (float *)((intptr_t)pvVar30 + off);
                                            float fVar18 = pfVar37[1];
                                            float fVar19 = pfVar37[2];
                                            float fVar20 = pfVar37[3];
                                            float *pfVar38 = (float *)((intptr_t)local_24 + off);
                                            float fVar21 = pfVar38[1];
                                            float fVar22 = pfVar38[2];
                                            float fVar23 = pfVar38[3];
                                            float *pfVar32 = (float *)(off + (intptr_t)pvVar39);
                                            local_20 = local_20 + 1;
                                            float fVar24 = pfVar32[1];
                                            float fVar25 = pfVar32[2];
                                            float fVar26 = pfVar32[3];
                                            *local_2c = (*pfVar34 + *pfVar40 + *pfVar2 + *pfVar35 + *pfVar36 + *pfVar37 + *pfVar38 + *pfVar32) * 0.125f;
                                            local_2c[1] = (fVar3 + fVar4 + fVar9 + fVar12 + fVar15 + fVar18 + fVar21 + fVar24) * 0.125f;
                                            local_2c[2] = (fVar5 + fVar6 + fVar10 + fVar13 + fVar16 + fVar19 + fVar22 + fVar25) * 0.125f;
                                            local_2c[3] = (fVar7 + fVar8 + fVar11 + fVar14 + fVar17 + fVar20 + fVar23 + fVar26) * 0.125f;
                                            local_2c = local_2c + 4;
                                        } while (local_20 < *(uint *)((intptr_t)ctx[1] + 0x68));
                                    }
                                    (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(local_c, local_18, local_14);
                                    local_c = local_c + 1;
                                } while (local_c < *(uint *)((intptr_t)ctx[1] + 0x6c));
                            }
                            local_18 = local_18 + 1;
                            iVar31 = ctx[1];
                        } while (local_18 < *(uint *)((intptr_t)iVar31 + 0x70));
                    }
                    operator_delete(local_8);
                    uVar29 = 0;
                }
                operator_delete(local_14);
            }
        } else {
            uVar29 = 0x80004005;
        }
    } else {
        uVar29 = 0x80004005;
    }
    return uVar29;
}

// 0x5fddac — observed shape
// NEEDS_MANUAL: the provider exposes two incoming register operands (`unaff_ESI`,
// `unaff_EDI`) that select the source and destination sample counts; they are
// modelled here as explicit parameters because the observed listing does not
// name them.
extern double ROUND(double v);
uint32_t *FUN_005fddac(int param_1, uint32_t esi_count, uint32_t edi_count) {
    uint32_t unaff_ESI = esi_count;
    uint32_t unaff_EDI = edi_count;
    uint32_t *puVar4 = (uint32_t *)FUN_00533c78(unaff_EDI << 4);
    if (puVar4 != (uint32_t *)0x0) {
        float fVar1 = (float)(int)unaff_ESI;
        if ((int)unaff_ESI < 0) {
            fVar1 = fVar1 + 4.2949673e+09f;
        }
        float fVar2 = (float)(int)unaff_EDI;
        if ((int)unaff_EDI < 0) {
            fVar2 = fVar2 + 4.2949673e+09f;
        }
        uint32_t local_8 = 0;
        uint32_t *puVar6 = puVar4;
        if (unaff_EDI != 0) {
            do {
                float fVar3 = (float)(int)local_8;
                if ((int)local_8 < 0) {
                    fVar3 = fVar3 + 4.2949673e+09f;
                }
                fVar3 = (fVar3 + 0.5f) * (fVar1 / fVar2) + 0.5f;
                uint32_t uVar5 = (uint32_t)ROUND(fVar3);
                uint32_t uVar7 = uVar5 - 1;
                fVar3 = ((float)(int)uVar5 + 1.0f) - fVar3;
                if ((int)uVar7 < 0) {
                    uVar7 = -(uint32_t)(param_1 != 0) & (unaff_ESI - 1);
                }
                if (unaff_ESI <= uVar5) {
                    uVar5 = ~-(uint32_t)(param_1 != 0) & (unaff_ESI - 1);
                }
                puVar6[1] = (uint32_t)fVar3;
                *puVar6 = uVar7;
                puVar6[2] = uVar5;
                local_8 = local_8 + 1;
                puVar6[3] = (uint32_t)(1.0f - fVar3);
                puVar6 = puVar6 + 4;
            } while (local_8 < unaff_EDI);
        }
    }
    return puVar4;
}

// 0x5fde98 — observed shape
uint32_t FUN_005fde98(void *self) {
    int *ctx = (int *)(intptr_t)self;
    float *local_c = (float *)0x0;
    void *local_14 = (void *)0x0;
    uint uVar21 = (uint)ctx[2];
    if ((char)uVar21 != '\x03') {
        return 0x80004005u;
    }
    if ((*(int *)((intptr_t)ctx[1] + 0x70) != 1) || (*(int *)((intptr_t)*ctx + 0x70) != 1)) {
        return 0x80004005u;
    }
    void *pvVar24 = (void *)FUN_005fddac(~(uVar21 >> 0x10) & 1, 0, 0);
    void *pvVar25 = (void *)FUN_005fddac(~(uVar21 >> 0x11) & 1, 0, 0);
    uint32_t uVar29;
    if ((pvVar24 != (void *)0x0) && (pvVar25 != (void *)0x0)) {
        int iVar22 = *(int *)((intptr_t)ctx[1] + 0x68);
        local_c = (float *)FUN_00533c78(iVar22 << 4);
        if (local_c == (float *)0x0) {
            local_c = (float *)0x0;
        } else {
            FUN_004127b0(local_c, 0x10, iVar22, (void *)FUN_005f6015);
        }
        if (local_c != (float *)0x0) {
            iVar22 = *(int *)((intptr_t)*ctx + 0x68);
            local_14 = (void *)FUN_00533c78(iVar22 << 5);
            if (local_14 == (void *)0x0) {
                local_14 = (void *)0x0;
            } else {
                FUN_004127b0(local_14, 0x10, iVar22 << 1, (void *)FUN_005f6015);
            }
            if (local_14 != (void *)0x0) {
                uint local_20 = 0;
                int local_30 = -1;
                int local_1c = -1;
                void *pvVar30 = (void *)(*(int *)((intptr_t)*ctx + 0x68) * 0x10 + (intptr_t)local_14);
                void *local_24 = local_14;
                if (*(int *)((intptr_t)ctx[1] + 0x6c) != 0) {
                    int *local_8 = (int *)((intptr_t)pvVar25 + 8);
                    void *local_10 = pvVar30;
                    do {
                        int iVar23 = local_1c;
                        int iVarA = local_8[-2];
                        uint local_34 = 0;
                        void *pvVar31 = pvVar30;
                        if (iVarA != local_30) {
                            if (iVarA == local_1c) {
                                local_1c = -1;
                                local_30 = iVar23;
                                local_10 = local_24;
                                pvVar31 = local_24;
                                local_24 = pvVar30;
                            } else {
                                (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(iVarA, 0, local_24);
                                local_30 = iVarA;
                            }
                        }
                        iVarA = *local_8;
                        if (iVarA != local_1c) {
                            (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(iVarA, 0, pvVar31);
                            local_1c = iVarA;
                        }
                        pvVar30 = pvVar31;
                        if (*(int *)((intptr_t)ctx[1] + 0x68) != 0) {
                            int *piVar26 = (int *)((intptr_t)pvVar24 + 8);
                            float *local_2c = local_c;
                            do {
                                float fVar3 = (float)piVar26[1];
                                float *pfVar1 = (float *)(*piVar26 * 0x10 + (intptr_t)pvVar31);
                                float fVar4 = pfVar1[1];
                                float fVar5 = pfVar1[2];
                                float fVar6 = pfVar1[3];
                                float fVar7 = (float)piVar26[-1];
                                float *pfVar2 = (float *)(piVar26[-2] * 0x10 + (intptr_t)pvVar31);
                                float *pfVar27 = (float *)(*piVar26 * 0x10 + (intptr_t)local_24);
                                float fVar8 = pfVar2[1];
                                float *pfVar28 = (float *)(piVar26[-2] * 0x10 + (intptr_t)local_24);
                                float fVar9 = pfVar2[2];
                                float fVar10 = pfVar2[3];
                                float fVar11 = (float)local_8[1];
                                float fVar12 = (float)piVar26[1];
                                float fVar13 = pfVar27[1];
                                float fVar14 = pfVar27[2];
                                float fVar15 = pfVar27[3];
                                float fVar16 = (float)piVar26[-1];
                                float fVar17 = pfVar28[1];
                                float fVar18 = pfVar28[2];
                                float fVar19 = pfVar28[3];
                                piVar26 = piVar26 + 4;
                                local_34 = local_34 + 1;
                                float fVar20 = (float)local_8[-1];
                                *local_2c = (fVar16 * *pfVar28 + fVar12 * *pfVar27) * fVar20 +
                                            (fVar7 * *pfVar2 + fVar3 * *pfVar1) * fVar11;
                                local_2c[1] = (fVar16 * fVar17 + fVar12 * fVar13) * fVar20 +
                                              (fVar7 * fVar8 + fVar3 * fVar4) * fVar11;
                                local_2c[2] = (fVar16 * fVar18 + fVar12 * fVar14) * fVar20 +
                                              (fVar7 * fVar9 + fVar3 * fVar5) * fVar11;
                                local_2c[3] = (fVar12 * fVar15 + fVar16 * fVar19) * fVar20 +
                                              (fVar3 * fVar6 + fVar7 * fVar10) * fVar11;
                                pvVar31 = local_10;
                                pvVar30 = local_10;
                                local_2c = local_2c + 4;
                            } while (local_34 < *(uint *)((intptr_t)ctx[1] + 0x68));
                        }
                        (**(void (**)(uint, int, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(local_20, 0, local_c);
                        local_8 = local_8 + 4;
                        local_20 = local_20 + 1;
                    } while (local_20 < *(uint *)((intptr_t)ctx[1] + 0x6c));
                }
                uVar29 = 0;
                goto LAB_005fe209;
            }
        }
    }
    uVar29 = 0x8007000eu;
LAB_005fe209:
    operator_delete(pvVar24);
    operator_delete(pvVar25);
    operator_delete(local_c);
    operator_delete(local_14);
    return uVar29;
}

// 0x5fe23a — observed shape
uint32_t FUN_005fe23a(void *self) {
    int *ctx = (int *)(intptr_t)self;
    float *local_10 = (float *)0x0;
    void *local_28 = (void *)0x0;
    uint uVar40 = (uint)ctx[2];
    if ((char)uVar40 != '\x03') {
        return 0x80004005u;
    }
    void *pvVar42 = (void *)FUN_005fddac(~(uVar40 >> 0x10) & 1, 0, 0);
    void *pvVar43 = (void *)FUN_005fddac(~(uVar40 >> 0x11) & 1, 0, 0);
    void *pvVar44 = (void *)FUN_005fddac(~(uVar40 >> 0x12) & 1, 0, 0);
    uint32_t uVar57;
    if (((pvVar42 != (void *)0x0) && (pvVar43 != (void *)0x0)) && (pvVar44 != (void *)0x0)) {
        int iVar47 = *(int *)((intptr_t)ctx[1] + 0x68);
        local_10 = (float *)FUN_00533c78(iVar47 << 4);
        if (local_10 == (float *)0x0) {
            local_10 = (float *)0x0;
        } else {
            FUN_004127b0(local_10, 0x10, iVar47, (void *)FUN_005f6015);
        }
        if (local_10 != (float *)0x0) {
            iVar47 = *(int *)((intptr_t)*ctx + 0x68);
            local_28 = (void *)FUN_00533c78(iVar47 << 6);
            if (local_28 == (void *)0x0) {
                local_28 = (void *)0x0;
            } else {
                FUN_004127b0(local_28, 0x10, iVar47 << 2, (void *)FUN_005f6015);
            }
            if (local_28 != (void *)0x0) {
                iVar47 = *(int *)((intptr_t)*ctx + 0x68);
                uint local_24 = 0;
                void *local_18 = (void *)(iVar47 * 0x10 + (intptr_t)local_28);
                int iVar45 = ctx[1];
                void *local_2c = (void *)(iVar47 * 0x20 + (intptr_t)local_28);
                void *pvVar52 = (void *)(iVar47 * 0x30 + (intptr_t)local_28);
                void *local_38 = local_28;
                void *local_30 = pvVar52;
                if (*(int *)((intptr_t)iVar45 + 0x70) != 0) {
                    int *local_c = (int *)((intptr_t)pvVar44 + 8);
                    do {
                        uint local_20 = 0;
                        int local_1c = -1;
                        int local_14 = -1;
                        if (*(int *)((intptr_t)iVar45 + 0x6c) != 0) {
                            int *local_8 = (int *)((intptr_t)pvVar43 + 8);
                            do {
                                iVar45 = local_14;
                                void *pvVar41 = local_18;
                                iVar47 = local_8[-2];
                                uint local_48 = 0;
                                void *pvVar53 = pvVar52;
                                if (iVar47 != local_1c) {
                                    if (iVar47 == local_14) {
                                        local_14 = -1;
                                        local_1c = iVar45;
                                        local_18 = local_38;
                                        local_38 = pvVar41;
                                        local_30 = local_2c;
                                        pvVar53 = local_2c;
                                        local_2c = pvVar52;
                                    } else {
                                        (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(iVar47, local_c[-2], local_38);
                                        (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(iVar47, *local_c, local_2c);
                                        local_1c = iVar47;
                                    }
                                }
                                iVar47 = *local_8;
                                if (iVar47 != local_14) {
                                    (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(iVar47, local_c[-2], local_18);
                                    (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(iVar47, *local_c, pvVar53);
                                    local_14 = iVar47;
                                }
                                pvVar52 = pvVar53;
                                if (*(int *)((intptr_t)ctx[1] + 0x68) != 0) {
                                    int *piVar46 = (int *)((intptr_t)pvVar42 + 8);
                                    float *local_3c = local_10;
                                    do {
                                        float fVar2 = (float)piVar46[1];
                                        float *pfVar1 = (float *)(*piVar46 * 0x10 + (intptr_t)local_30);
                                        float fVar3 = pfVar1[1];
                                        float fVar4 = pfVar1[2];
                                        float fVar5 = pfVar1[3];
                                        float fVar6 = (float)piVar46[-1];
                                        iVar47 = piVar46[-2] * 0x10;
                                        float *pfVar49 = (float *)((intptr_t)local_30 + iVar47);
                                        float fVar7 = pfVar49[1];
                                        float fVar8 = pfVar49[2];
                                        float fVar9 = pfVar49[3];
                                        float *pfVar54 = (float *)(*piVar46 * 0x10 + (intptr_t)local_2c);
                                        float *pfVar50 = (float *)((intptr_t)local_2c + iVar47);
                                        float fVar10 = (float)local_8[1];
                                        float fVar11 = (float)piVar46[1];
                                        float fVar12 = pfVar54[1];
                                        float fVar13 = pfVar54[2];
                                        float fVar14 = pfVar54[3];
                                        float fVar15 = (float)piVar46[-1];
                                        float fVar16 = pfVar50[1];
                                        float fVar17 = pfVar50[2];
                                        float fVar18 = pfVar50[3];
                                        float fVar19 = (float)local_8[-1];
                                        float fVar20 = (float)local_c[1];
                                        float *pfVar55 = (float *)((intptr_t)local_18 + *piVar46 * 0x10);
                                        float fVar21 = (float)piVar46[1];
                                        float fVar22 = pfVar55[1];
                                        float fVar23 = pfVar55[2];
                                        float fVar24 = pfVar55[3];
                                        float fVar25 = (float)piVar46[-1];
                                        float *pfVar56 = (float *)((intptr_t)local_18 + iVar47);
                                        float fVar26 = pfVar56[1];
                                        float fVar27 = pfVar56[2];
                                        float fVar28 = pfVar56[3];
                                        float *pfVar51 = (float *)(*piVar46 * 0x10 + (intptr_t)local_38);
                                        float *pfVar48 = (float *)(iVar47 + (intptr_t)local_38);
                                        float fVar29 = (float)local_8[1];
                                        float fVar30 = (float)piVar46[1];
                                        float fVar31 = pfVar51[1];
                                        float fVar32 = pfVar51[2];
                                        float fVar33 = pfVar51[3];
                                        float fVar34 = (float)piVar46[-1];
                                        float fVar35 = pfVar48[1];
                                        float fVar36 = pfVar48[2];
                                        float fVar37 = pfVar48[3];
                                        float fVar38 = (float)local_8[-1];
                                        float fVar39 = (float)local_c[-1];
                                        piVar46 = piVar46 + 4;
                                        local_48 = local_48 + 1;
                                        *local_3c = ((fVar34 * *pfVar48 + fVar30 * *pfVar51) * fVar38 +
                                                     (fVar25 * *pfVar56 + fVar21 * *pfVar55) * fVar29) * fVar39 +
                                                    ((fVar15 * *pfVar50 + fVar11 * *pfVar54) * fVar19 +
                                                     (fVar6 * *pfVar49 + fVar2 * *pfVar1) * fVar10) * fVar20;
                                        local_3c[1] = ((fVar34 * fVar35 + fVar30 * fVar31) * fVar38 +
                                                       (fVar25 * fVar26 + fVar21 * fVar22) * fVar29) * fVar39 +
                                                      ((fVar15 * fVar16 + fVar11 * fVar12) * fVar19 +
                                                       (fVar6 * fVar7 + fVar2 * fVar3) * fVar10) * fVar20;
                                        local_3c[2] = ((fVar34 * fVar36 + fVar30 * fVar32) * fVar38 +
                                                       (fVar25 * fVar27 + fVar21 * fVar23) * fVar29) * fVar39 +
                                                      ((fVar15 * fVar17 + fVar11 * fVar13) * fVar19 +
                                                       (fVar6 * fVar8 + fVar2 * fVar4) * fVar10) * fVar20;
                                        local_3c[3] = ((fVar30 * fVar33 + fVar34 * fVar37) * fVar38 +
                                                       (fVar21 * fVar24 + fVar25 * fVar28) * fVar29) * fVar39 +
                                                      ((fVar11 * fVar14 + fVar15 * fVar18) * fVar19 +
                                                       (fVar2 * fVar5 + fVar6 * fVar9) * fVar10) * fVar20;
                                        local_3c = local_3c + 4;
                                    } while (local_48 < *(uint *)((intptr_t)ctx[1] + 0x68));
                                    pvVar52 = local_30;
                                }
                                (**(void (**)(uint, uint, void*))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(local_20, local_24, local_10);
                                local_8 = local_8 + 4;
                                local_20 = local_20 + 1;
                            } while (local_20 < *(uint *)((intptr_t)ctx[1] + 0x6c));
                        }
                        local_c = local_c + 4;
                        local_24 = local_24 + 1;
                        iVar45 = ctx[1];
                    } while (local_24 < *(uint *)((intptr_t)iVar45 + 0x70));
                }
                uVar57 = 0;
                goto LAB_005fe8ca;
            }
        }
    }
    uVar57 = 0x8007000eu;
LAB_005fe8ca:
    operator_delete(pvVar42);
    operator_delete(pvVar43);
    operator_delete(pvVar44);
    operator_delete(local_10);
    operator_delete(local_28);
    return uVar57;
}

// 0x5fe8fc — observed shape
extern void FUN_00412770(void *p, int size, int count, void *fn);
extern void LAB_005fbd92(void);
void FUN_005fe8fc(void *self, uint8_t param_1) {
    int *in_ECX = (int *)(intptr_t)self;
    if ((param_1 & 2) == 0) {
        operator_delete((void *)*in_ECX);
        if ((param_1 & 1) != 0) {
            operator_delete(in_ECX);
        }
    } else {
        FUN_00412770(in_ECX, 0xc, in_ECX[-1], (void *)LAB_005fbd92);
        if ((param_1 & 1) != 0) {
            operator_delete(in_ECX + -1);
        }
    }
    return;
}

// 0x5fe94b — observed shape
extern int32_t *FUN_005fbd9b(uint32_t a, uint32_t b, uint32_t mode);
extern void FUN_005fbd85(void *p);
uint32_t FUN_005fe94b(void *self) {
    int *ctx = (int *)(intptr_t)self;
    uint uVar15 = (uint)ctx[2];
    int *local_20 = (int *)0x0;
    int *local_1c = (int *)0x0;
    int *local_c = (int *)0x0;
    int *local_18 = (int *)0x0;
    void *local_10 = (void *)0x0;
    int *piVar6 = (int *)FUN_005fbd9b(*(uint32_t *)((intptr_t)*ctx + 0x68), *(uint32_t *)((intptr_t)ctx[1] + 0x68), ~(uVar15 >> 0x10) & 1);
    uint32_t uVar18;
    if (((piVar6 == (int *)0x0) ||
         (local_20 = (int *)FUN_005fbd9b(*(uint32_t *)((intptr_t)*ctx + 0x6c), *(uint32_t *)((intptr_t)ctx[1] + 0x6c), ~(uVar15 >> 0x11) & 1),
          local_20 == (int *)0x0)) ||
        (local_1c = (int *)FUN_005fbd9b(*(uint32_t *)((intptr_t)*ctx + 0x70), *(uint32_t *)((intptr_t)ctx[1] + 0x70), ~(uVar15 >> 0x12) & 1),
         local_1c == (int *)0x0)) {
        uVar18 = 0x80004005;
    } else {
        int iVar3 = *piVar6;
        int iVar4 = *local_20;
        int iVar5 = *local_1c;
        int iVar11 = *(int *)((intptr_t)ctx[1] + 0x70);
        local_c = (int *)FUN_00533c78(iVar11 * 0xc + 4);
        if (local_c == (int *)0x0) {
            local_c = (int *)0x0;
        } else {
            *local_c = iVar11;
            local_c = local_c + 1;
            FUN_004127b0(local_c, 0xc, iVar11, (void *)FUN_005fbd85);
        }
        if (local_c != (int *)0x0) {
            iVar11 = *(int *)((intptr_t)*ctx + 0x68);
            local_10 = (void *)FUN_00533c78(iVar11 << 4);
            if (local_10 == (void *)0x0) {
                local_10 = (void *)0x0;
            } else {
                FUN_004127b0(local_10, 0x10, iVar11, (void *)FUN_005f6015);
            }
            if (local_10 != (void *)0x0) {
                int *piVar17 = local_1c + 1;
                int *piVar13 = nullptr;
                while (piVar17 < (int *)(iVar5 + (intptr_t)local_1c)) {
                    piVar13 = (int *)(*piVar17 + (intptr_t)piVar17);
                    for (int *piVar10 = piVar17 + 1; (piVar17 = piVar13), piVar10 < piVar13; piVar10 = piVar10 + 2) {
                        local_c[*piVar10 * 3 + 2] = local_c[*piVar10 * 3 + 2] + 1;
                    }
                }
                int local_38 = 0;
                piVar17 = local_1c + 1;
                while (piVar17 < (int *)(iVar5 + (intptr_t)local_1c)) {
                    piVar13 = (int *)(*piVar17 + (intptr_t)piVar17);
                    piVar17 = piVar17 + 1;
                    for (int *piVar10 = piVar17; piVar10 < piVar13; piVar10 = piVar10 + 2) {
                        int *piVar7 = local_c + *piVar10 * 3;
                        if (*piVar7 == 0) {
                            if (local_18 == (int *)0x0) {
                                int iVar8 = *(int *)((intptr_t)ctx[1] + 0x6c) * *(int *)((intptr_t)ctx[1] + 0x68);
                                intptr_t iVarA = (intptr_t)FUN_00533c78(iVar8 * 0x10);
                                if (iVarA == 0) {
                                    iVarA = 0;
                                } else {
                                    FUN_004127b0((void *)iVarA, 0x10, iVar8, (void *)FUN_005f6015);
                                }
                                *piVar7 = (int)iVarA;
                                if (iVarA == 0) goto LAB_005fef86;
                            } else {
                                *piVar7 = *local_18;
                                *local_18 = 0;
                                local_18 = (int *)local_18[1];
                            }
                            uint32_t *puVar19 = (uint32_t *)*piVar7;
                            for (int iVarB = (*(int *)((intptr_t)ctx[1] + 0x6c) * *(int *)((intptr_t)ctx[1] + 0x68) & 0xfffffffU) << 2;
                                 iVarB != 0; iVarB = iVarB + -1) {
                                *puVar19 = 0;
                                puVar19 = puVar19 + 1;
                            }
                            for (int iVarB = 0; iVarB != 0; iVarB = iVarB + -1) {
                                *(uint8_t *)puVar19 = 0;
                                puVar19 = (uint32_t *)((intptr_t)puVar19 + 1);
                            }
                        }
                    }
                    int local_2c = 0;
                    for (int *piVar10 = local_20 + 1; piVar10 < (int *)(iVar4 + (intptr_t)local_20);
                         piVar10 = (int *)(iVar11 + (intptr_t)piVar10)) {
                        iVar11 = *piVar10;
                        (**(void (**)(int, int, void*))((intptr_t)*(int *)((intptr_t)*ctx) + 4))(local_2c, local_38, local_10);
                        if (piVar6 + 1 < (int *)(iVar3 + (intptr_t)piVar6)) {
                            float *pfVar14 = (float *)((intptr_t)local_10 + 8);
                            int *local_28 = piVar6 + 1;
                            do {
                                int *piVar7b = (int *)(*local_28 + (intptr_t)local_28);
                                for (int *local_8 = piVar17; local_8 < piVar13; local_8 = local_8 + 2) {
                                    for (int *piVar16 = piVar10 + 1; piVar16 < (int *)(iVar11 + (intptr_t)piVar10);
                                         piVar16 = piVar16 + 2) {
                                        int iVar8 = *(int *)((intptr_t)ctx[1] + 0x68) * *piVar16 * 0x10 + local_c[*local_8 * 3];
                                        for (int *piVar12 = local_28 + 1; piVar12 < piVar7b; piVar12 = piVar12 + 2) {
                                            float *pfVar20 = (float *)(*piVar12 * 0x10 + iVar8);
                                            float fVar2 = (float)piVar12[1] * (float)local_8[1] * (float)piVar16[1];
                                            *pfVar20 = fVar2 * pfVar14[-2] + *pfVar20;
                                            pfVar20 = (float *)(*piVar12 * 0x10 + 4 + iVar8);
                                            *pfVar20 = fVar2 * pfVar14[-1] + *pfVar20;
                                            pfVar20 = (float *)(*piVar12 * 0x10 + 8 + iVar8);
                                            *pfVar20 = fVar2 * *pfVar14 + *pfVar20;
                                            pfVar20 = (float *)(*piVar12 * 0x10 + 0xc + iVar8);
                                            *pfVar20 = fVar2 * pfVar14[1] + *pfVar20;
                                        }
                                    }
                                }
                                pfVar14 = pfVar14 + 4;
                                local_28 = piVar7b;
                            } while (piVar7b < (int *)(iVar3 + (intptr_t)piVar6));
                        }
                        local_2c = local_2c + 1;
                    }
                    for (; piVar17 < piVar13; piVar17 = piVar17 + 2) {
                        int *piVar7c = local_c + *piVar17 * 3;
                        int *piVar10b = piVar7c + 2;
                        *piVar10b = *piVar10b + -1;
                        if (*piVar10b == 0) {
                            iVar11 = ctx[1];
                            int *local_8 = (int *)0x0;
                            if (*(int *)((intptr_t)iVar11 + 0x6c) != 0) {
                                do {
                                    float fVar2 = -1.0f;
                                    iVar11 = *(int *)((intptr_t)iVar11 + 0x68);
                                    int iVar8 = *(int *)((intptr_t)*ctx + 8);
                                    int iVar9 = iVar11 * (int)(intptr_t)local_8 * 0x10 + *piVar7c;
                                    if (iVar8 == 1) {
                                        uVar15 = 0;
                                        if (iVar11 != 0) {
                                            float *pfVar14 = (float *)(iVar9 + 8);
                                            do {
                                                if (0.0f <= pfVar14[-2]) {
                                                    if (1.0f <= pfVar14[-2]) {
                                                        fVar2 = 1.0f;
                                                    } else {
                                                        fVar2 = pfVar14[-2];
                                                    }
                                                } else {
                                                    fVar2 = 0.0f;
                                                }
                                                pfVar14[-2] = fVar2;
                                                if (0.0f <= pfVar14[-1]) {
                                                    if (1.0f <= pfVar14[-1]) {
                                                        fVar2 = 1.0f;
                                                    } else {
                                                        fVar2 = pfVar14[-1];
                                                    }
                                                } else {
                                                    fVar2 = 0.0f;
                                                }
                                                pfVar14[-1] = fVar2;
                                                if (0.0f <= *pfVar14) {
                                                    if (1.0f <= *pfVar14) {
                                                        fVar2 = 1.0f;
                                                    } else {
                                                        fVar2 = *pfVar14;
                                                    }
                                                } else {
                                                    fVar2 = 0.0f;
                                                }
                                                *pfVar14 = fVar2;
                                                if (0.0f <= pfVar14[1]) {
                                                    if (1.0f <= pfVar14[1]) {
                                                        fVar2 = 1.0f;
                                                    } else {
                                                        fVar2 = pfVar14[1];
                                                    }
                                                } else {
                                                    fVar2 = 0.0f;
                                                }
                                                pfVar14[1] = fVar2;
                                                uVar15 = uVar15 + 1;
                                                pfVar14 = pfVar14 + 4;
                                            } while (uVar15 < *(uint *)((intptr_t)ctx[1] + 0x68));
                                        }
                                    } else if (iVar8 == 2) {
                                        uVar15 = 0;
                                        if (iVar11 != 0) {
                                            float *pfVar14 = (float *)(iVar9 + 8);
                                            do {
                                                float fVar1;
                                                if (-1.0f <= pfVar14[-2]) {
                                                    if (1.0f <= pfVar14[-2]) {
                                                        fVar1 = 1.0f;
                                                    } else {
                                                        fVar1 = pfVar14[-2];
                                                    }
                                                } else {
                                                    fVar1 = fVar2;
                                                }
                                                pfVar14[-2] = fVar1;
                                                if (-1.0f <= pfVar14[-1]) {
                                                    if (1.0f <= pfVar14[-1]) {
                                                        fVar1 = 1.0f;
                                                    } else {
                                                        fVar1 = pfVar14[-1];
                                                    }
                                                } else {
                                                    fVar1 = fVar2;
                                                }
                                                pfVar14[-1] = fVar1;
                                                if (-1.0f <= *pfVar14) {
                                                    if (1.0f <= *pfVar14) {
                                                        fVar1 = 1.0f;
                                                    } else {
                                                        fVar1 = *pfVar14;
                                                    }
                                                } else {
                                                    fVar1 = fVar2;
                                                }
                                                *pfVar14 = fVar1;
                                                if (0.0f <= pfVar14[1]) {
                                                    if (1.0f <= pfVar14[1]) {
                                                        fVar1 = 1.0f;
                                                    } else {
                                                        fVar1 = pfVar14[1];
                                                    }
                                                } else {
                                                    fVar1 = 0.0f;
                                                }
                                                pfVar14[1] = fVar1;
                                                uVar15 = uVar15 + 1;
                                                pfVar14 = pfVar14 + 4;
                                            } while (uVar15 < *(uint *)((intptr_t)ctx[1] + 0x68));
                                        }
                                    } else if ((iVar8 == 3) && (uVar15 = 0, iVar11 != 0)) {
                                        float *pfVar14 = (float *)(iVar9 + 8);
                                        do {
                                            float fVar1;
                                            if (-1.0f <= pfVar14[-2]) {
                                                if (1.0f <= pfVar14[-2]) {
                                                    fVar1 = 1.0f;
                                                } else {
                                                    fVar1 = pfVar14[-2];
                                                }
                                            } else {
                                                fVar1 = fVar2;
                                            }
                                            pfVar14[-2] = fVar1;
                                            if (-1.0f <= pfVar14[-1]) {
                                                if (1.0f <= pfVar14[-1]) {
                                                    fVar1 = 1.0f;
                                                } else {
                                                    fVar1 = pfVar14[-1];
                                                }
                                            } else {
                                                fVar1 = fVar2;
                                            }
                                            pfVar14[-1] = fVar1;
                                            if (-1.0f <= *pfVar14) {
                                                if (1.0f <= *pfVar14) {
                                                    fVar1 = 1.0f;
                                                } else {
                                                    fVar1 = *pfVar14;
                                                }
                                            } else {
                                                fVar1 = fVar2;
                                            }
                                            *pfVar14 = fVar1;
                                            if (-1.0f <= pfVar14[1]) {
                                                if (1.0f <= pfVar14[1]) {
                                                    fVar1 = 1.0f;
                                                } else {
                                                    fVar1 = pfVar14[1];
                                                }
                                            } else {
                                                fVar1 = fVar2;
                                            }
                                            pfVar14[1] = fVar1;
                                            uVar15 = uVar15 + 1;
                                            pfVar14 = pfVar14 + 4;
                                        } while (uVar15 < *(uint *)((intptr_t)ctx[1] + 0x68));
                                    }
                                    (**(void (**)(int, int, int))((intptr_t)*(int *)((intptr_t)ctx[1]) + 8))(
                                        (int)(intptr_t)local_8, *piVar17,
                                        ((int *)ctx[1])[0x1a] * (int)(intptr_t)local_8 * 0x10 + *piVar7c);
                                    local_8 = (int *)((intptr_t)local_8 + 1);
                                    iVar11 = ctx[1];
                                } while ((uintptr_t)local_8 < *(uint *)((intptr_t)iVar11 + 0x6c));
                            }
                            piVar7c[1] = (int)(intptr_t)local_18;
                            local_18 = piVar7c;
                        }
                    }
                    local_38 = local_38 + 1;
                    piVar17 = piVar13;
                }
                uVar18 = 0;
                goto LAB_005fef92;
            }
        }
    LAB_005fef86:
        uVar18 = 0x8007000e;
    }
LAB_005fef92:
    if (local_c != (int *)0x0) {
        FUN_005fe8fc((void *)local_c, 3);
    }
    operator_delete(local_1c);
    operator_delete(local_20);
    operator_delete(piVar6);
    operator_delete(local_10);
    operator_delete((void *)0x0);
    return uVar18;
}
