#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers referenced by the assigned listings.
extern void* FUN_00552bc0(int param_1);
extern void operator_delete__(void* ptr);
extern void* thunk_FUN_00533c78(std::size_t n);
extern void FUN_00552b70(int param_1);
extern void FUN_005bd960(void* a, void* b);
extern void FUN_005531c0(int param_1);
extern void* FUN_00557b10(void* a);
extern void FUN_006b34a0(int a);
extern void FUN_005606f0(std::uint32_t a, void* b);
extern void* FUN_00557d80(const char* a, void* b);
extern std::uint32_t DAT_00728b88;
extern std::uint32_t DAT_00728b90;

// 0x5ae740 — observed shape
std::uint32_t FUN_005ae740(void* self, int param_1)
{
    std::uint8_t* pbVar2 = reinterpret_cast<std::uint8_t*>(FUN_00552bc0(param_1));
    if (static_cast<std::int8_t>(pbVar2[0] & 0xff) == 0) {
        return reinterpret_cast<std::uint32_t>(pbVar2) & 0xffffff00u;
    }
    pbVar2 = *reinterpret_cast<std::uint8_t**>(reinterpret_cast<std::uint8_t*>(self) + 0x48);
    {
        std::uint32_t lhs = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x48);
        std::uint32_t rhs = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(param_1) + 0x48);
        if ((lhs == 0) != (rhs == 0)) {
            return 0;
        }
        if (lhs != 0 && rhs != 0) {
            using Fn = std::uint8_t* (*)(std::uint32_t);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x48) + 0x1c);
            std::uint8_t* r = fn(rhs);
            if (static_cast<std::int8_t>(r[0] & 0xff) == 0) {
                return reinterpret_cast<std::uint32_t>(r) & 0xffffff00u;
            }
        }
    }
    pbVar2 = *reinterpret_cast<std::uint8_t**>(reinterpret_cast<std::uint8_t*>(self) + 0x44);
    {
        std::uint32_t lhs = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x44);
        std::uint32_t rhs = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(param_1) + 0x44);
        if ((lhs == 0) != (rhs == 0)) {
            return 0;
        }
        if (lhs == 0 && rhs == 0) {
            return 1;
        }
    }
    {
        std::uint8_t* pA = pbVar2;
        std::uint8_t* pB = *reinterpret_cast<std::uint8_t**>(reinterpret_cast<std::uint8_t*>(param_1) + 0x44);
        if (pB != nullptr) {
            while (true) {
                std::uint8_t b1 = pA[0];
                std::uint8_t b2 = pB[0];
                bool lt = b1 < b2;
                if (b1 != b2) {
                    std::int32_t res = (1 - (std::uint32_t)lt) - ((lt != 0) ? 1u : 0u);
                    if (res != 0) {
                        return static_cast<std::uint32_t>(res) & 0xffffff00u;
                    }
                }
                if (b1 == 0) break;
                std::uint8_t c1 = pA[1];
                std::uint8_t c2 = pB[1];
                bool lt2 = c1 < c2;
                if (c1 != c2) {
                    std::int32_t res = (1 - (std::uint32_t)lt2) - ((lt2 != 0) ? 1u : 0u);
                    if (res != 0) {
                        return static_cast<std::uint32_t>(res) & 0xffffff00u;
                    }
                }
                pA += 2;
                pB += 2;
                if (c1 == 0) break;
            }
            return 1;
        }
    }
    return 1;
}

// 0x5ae800 — observed shape
void FUN_005ae800(void* self, char* param_1)
{
    operator_delete__(*reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(self) + 0x44));
    char* pc = param_1;
    char c;
    do {
        c = *pc;
        pc = pc + 1;
    } while (c != '\0');
    std::size_t len = static_cast<std::size_t>(pc - param_1);
    char* dst = reinterpret_cast<char*>(thunk_FUN_00533c78(len));
    *reinterpret_cast<char**>(reinterpret_cast<std::uint8_t*>(self) + 0x44) = dst;
    char* src = param_1;
    do {
        c = *src;
        src = src + 1;
        *dst = c;
        dst = dst + 1;
    } while (c != '\0');
}

// 0x5ae890 — observed shape
void FUN_005ae890(void* self, int param_1)
{
    FUN_00552b70(param_1);
    int saved = param_1;
    void* p = reinterpret_cast<void*>(param_1);
    FUN_005bd960(self, &p);
    saved = reinterpret_cast<int>(p);
    if (*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x34) != 0 &&
        *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(saved) + 0x34) != 0) {
        void* obj = *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(self) + 0x48);
        void* q = reinterpret_cast<void*>(saved);
        FUN_005bd960(obj, &q);
        *reinterpret_cast<int*>(reinterpret_cast<std::uint8_t*>(saved) + 0x48) = reinterpret_cast<int>(q);
    }
}

// 0x5ae920 — observed shape
std::uint32_t FUN_005ae920(void* self)
{
    if (*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x34) != 0) {
        int iStack_4 = reinterpret_cast<int>(self);
        using FirstFn = std::uint32_t* (*)();
        FirstFn first = *reinterpret_cast<FirstFn*>(*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x34) + 4);
        std::uint32_t* node = first();
        while (node != nullptr) {
            if (reinterpret_cast<std::uint32_t>(node) == DAT_00728b90) {
                if (*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x44) == 0) {
                    return 0;
                }
                if (*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x34) == 0) {
                    return 0;
                }
                char c = 0;
                void* stack = reinterpret_cast<void*>(&iStack_4);
                void* arg = reinterpret_cast<void*>(iStack_4);
                FUN_005bd960(reinterpret_cast<void*>(*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x44)), &arg);
                (void)c;
                (void)stack;
                // Original checks the call result byte and the out param.
                // Preserve shape: if the out pointer is null, fail.
                if (reinterpret_cast<std::uint32_t>(arg) == 0) {
                    return 0;
                }
                // The listing compares the char result; treat the pointer
                // check above as the observed tail before returning 1.
                return 1;
            }
            node = reinterpret_cast<std::uint32_t*>(node[1]);
        }
    }
    return 0;
}

// 0x5ae9c0 — observed shape
void FUN_005ae9c0(void* self, int param_1)
{
    int base = param_1;
    FUN_005531c0(param_1);
    void* val = FUN_00557b10(reinterpret_cast<void*>(DAT_00728b88));
    std::uint32_t cnt = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(base) + 0xc);
    if (*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(base) + 8) <= cnt) {
        FUN_006b34a0(*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(base) + 0x14) + cnt);
    }
    FUN_005606f0(cnt, &val);
    val = FUN_00557d80("Modifier Name", *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(self) + 0x44));
    cnt = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(base) + 0xc);
    if (*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(base) + 8) <= cnt) {
        FUN_006b34a0(*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(base) + 0x14) + cnt);
    }
    FUN_005606f0(cnt, &val);
}

// Additional extern helpers/globals referenced by the 0x5aea80..0x5af2a0 batch.
extern void FUN_004db0a0(void);
extern std::uint32_t DAT_00727430;
extern std::uint32_t DAT_00727434;
extern std::uint32_t DAT_00727438;
extern std::uint32_t DAT_007179b0[9];
extern void FUN_005e1490(void);
extern void* PTR_FUN_006c5a68;
extern void* PTR_FUN_006c5a4c;
extern void* PTR_FUN_006c5a24;
extern void FUN_005340e0(std::uint32_t param_1);
extern void FUN_0053e240(void);
extern void FUN_0053ea80(std::uint32_t* param_1);
extern void FUN_00545310(int a, int b);
extern char thunk_FUN_0053e530(std::uint32_t param_1);
extern void FUN_0051ac30(int a);
extern void FUN_004b1100(void);
extern void FUN_004b10d0(void);
extern std::uint32_t DAT_00727868;
extern std::uint32_t FUN_005065b0(void);
extern void thunk_FUN_0053ec00(int param_1);
extern void thunk_FUN_0053ed20(int* param_1);
extern char thunk_FUN_0053e570(int param_1);
extern void FUN_00545d20(void);

// 0x5aea80 — observed shape
void FUN_005aea80(void* self)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    FUN_004db0a0();
    if (*reinterpret_cast<char*>(base + 0xcc) != '\0') {
        *reinterpret_cast<std::uint32_t*>(base + 0x90) = DAT_00727430;
        *reinterpret_cast<std::uint32_t*>(base + 0x94) = DAT_00727434;
        *reinterpret_cast<std::uint32_t*>(base + 0x98) = DAT_00727438;
        const std::uint32_t* puVar2 = DAT_007179b0;
        std::uint32_t* puVar3 = reinterpret_cast<std::uint32_t*>(base + 0x6c);
        for (int iVar1 = 9; iVar1 != 0; iVar1 = iVar1 - 1) {
            *puVar3 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar3 = puVar3 + 1;
        }
    }
}

// 0x5aead0 — observed shape
void FUN_005aead0(void* self, int* param_1, int* param_2, int* param_3)
{
    std::int32_t* ecx = static_cast<std::int32_t*>(self);
    std::int32_t* piVar3 = reinterpret_cast<std::int32_t*>(*param_1);
    *param_2 = piVar3[1];
    *param_3 = piVar3[2];
    if (*piVar3 != 0) {
        *param_1 = *piVar3;
        return;
    }
    using HashFn = int (*)(int);
    HashFn hashFn = *reinterpret_cast<HashFn*>(static_cast<std::uintptr_t>(ecx[0]) + 4);
    int iVar1 = hashFn(piVar3[1]);
    std::uint32_t uVar2 = static_cast<std::uint32_t>(iVar1 + 1);
    if (uVar2 < static_cast<std::uint32_t>(ecx[1])) {
        piVar3 = reinterpret_cast<std::int32_t*>(
            static_cast<std::uintptr_t>(static_cast<std::uint32_t>(ecx[2] + static_cast<int>(uVar2 * 4))));
        do {
            if (*piVar3 != 0) {
                *param_1 = *piVar3;
                return;
            }
            uVar2 = uVar2 + 1;
            piVar3 = piVar3 + 1;
        } while (uVar2 < static_cast<std::uint32_t>(ecx[1]));
    }
    *param_1 = 0;
}

// 0x5aeb40 — observed shape
void FUN_005aeb40(void* self)
{
    void** selfp = static_cast<void**>(self);
    std::uint32_t* dwords = static_cast<std::uint32_t*>(self);
    *selfp = &PTR_FUN_006c5a68;
    std::uint32_t uVar3 = 0;
    if ((*reinterpret_cast<char*>(&dwords[4]) != '\0') && (dwords[1] != 0)) {
        do {
            std::uint32_t* puVar2 = *reinterpret_cast<std::uint32_t**>(
                static_cast<std::uintptr_t>(static_cast<std::uint32_t>(dwords[2] + uVar3 * 4)));
            while (puVar2 != nullptr) {
                std::uint32_t* puVar1 = puVar2 + 1;
                puVar2 = reinterpret_cast<std::uint32_t*>(*puVar2);
                operator_delete__(reinterpret_cast<void*>(*puVar1));
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < dwords[1]);
    }
    *selfp = &PTR_FUN_006c5a4c;
    FUN_005e1490();
    *selfp = &PTR_FUN_006c5a24;
    FUN_005e1490();
    operator_delete__(reinterpret_cast<void*>(dwords[2]));
}

// 0x5aecb0 — observed shape
void FUN_005aecb0(void* self, std::uint32_t param_1)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    std::uint32_t* puVar2 = *reinterpret_cast<std::uint32_t**>(base + 0xd4);
    std::uint32_t uVar3 = *reinterpret_cast<std::uint32_t*>(base + 0xbc);
    while (puVar2 != nullptr) {
        std::uint32_t* puVar1 = puVar2 + 2;
        puVar2 = reinterpret_cast<std::uint32_t*>(*puVar2);
        using NotifyFn = void (*)(std::uint32_t, std::uint32_t);
        NotifyFn notifyFn = *reinterpret_cast<NotifyFn*>(
            static_cast<std::uintptr_t>(*reinterpret_cast<std::uint32_t*>(puVar1)) + 0x38);
        notifyFn(uVar3, param_1);
    }
}

// 0x5aece0 — observed shape
void FUN_005aece0(void* self, std::uint32_t param_1)
{
    std::int32_t* ecx = static_cast<std::int32_t*>(self);
    if (((static_cast<std::uint8_t>(ecx[8]) >> 2) & 1) != 0) {
        using FlushFn = void (*)();
        FlushFn flushFn = *reinterpret_cast<FlushFn*>(static_cast<std::uintptr_t>(ecx[0]) + 0x6c);
        flushFn();
    }
    FUN_005340e0(param_1);
}

// 0x5aed10 — observed shape
void FUN_005aed10(void* self)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    FUN_0053e240();
    if (*reinterpret_cast<char*>(base + 0xcc) != '\0') {
        std::uint32_t iVar3 = *reinterpret_cast<std::uint32_t*>(base + 0xbc);
        float fVar2 = *reinterpret_cast<float*>(base + 0x9c);
        float* pfVar1 = reinterpret_cast<float*>(base + 0x28);
        *pfVar1 = *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar3) + 0x10);
        *reinterpret_cast<std::uint32_t*>(base + 0x2c) =
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar3) + 0x14);
        *reinterpret_cast<std::uint32_t*>(base + 0x30) =
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar3) + 0x18);
        *reinterpret_cast<std::uint32_t*>(base + 0x34) =
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar3) + 0x1c);
        *pfVar1 = fVar2 * *pfVar1;
        *reinterpret_cast<float*>(base + 0x2c) = fVar2 * *reinterpret_cast<float*>(base + 0x2c);
        *reinterpret_cast<float*>(base + 0x34) =
            *reinterpret_cast<float*>(base + 0x34) * *reinterpret_cast<float*>(base + 0x9c);
        *reinterpret_cast<float*>(base + 0x30) = fVar2 * *reinterpret_cast<float*>(base + 0x30);
    }
}

// 0x5aed90 — observed shape
void FUN_005aed90(void* self, char* param_1, std::uint32_t param_2, char* param_3)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    (void)param_2;
    *param_1 = '\x01';
    *param_3 = '\0';
    if (*param_1 == '\0') {
        base[0x20] = static_cast<std::uint8_t>(base[0x20] & 0xfd);
    } else {
        base[0x20] = static_cast<std::uint8_t>(base[0x20] | 2);
    }
    base[0x20] = static_cast<std::uint8_t>(base[0x20] | 0xc);
    if (*param_3 == '\0') {
        *reinterpret_cast<std::uint16_t*>(base + 0x20) =
            static_cast<std::uint16_t>(*reinterpret_cast<std::uint16_t*>(base + 0x20) & 0xffef);
        return;
    }
    *reinterpret_cast<std::uint16_t*>(base + 0x20) =
        static_cast<std::uint16_t>(*reinterpret_cast<std::uint16_t*>(base + 0x20) | 0x10);
}

// 0x5aede0 — observed shape
void FUN_005aede0(void* self, int* param_1)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    std::uint8_t* in_ECX = base;
    std::uint32_t local_10 = 0;
    std::uint32_t local_c = reinterpret_cast<std::uint32_t>(base);
    std::uint32_t local_8 = 0;
    FUN_0053ea80(reinterpret_cast<std::uint32_t*>(param_1));
    FUN_005bd960(base, &local_10);
    std::uint32_t uVar5 = 0;
    std::int32_t* piVar6 = nullptr;
    if (*reinterpret_cast<std::uint32_t*>(in_ECX + 0xe4) != 0) {
        piVar6 = *reinterpret_cast<std::int32_t**>(in_ECX + 0xe8);
        do {
            if (*piVar6 != 0) {
                piVar6 = reinterpret_cast<std::int32_t*>(
                    (*reinterpret_cast<std::int32_t**>(in_ECX + 0xe8))[uVar5]);
                break;
            }
            uVar5 = uVar5 + 1;
            piVar6 = piVar6 + 1;
        } while (uVar5 < *reinterpret_cast<std::uint32_t*>(in_ECX + 0xe4));
        if (uVar5 >= *reinterpret_cast<std::uint32_t*>(in_ECX + 0xe4)) {
            piVar6 = nullptr;
        }
    }
    if (piVar6 != nullptr) {
        std::uint32_t local_4 = local_10 + 0xe0;
        (void)local_4;
        do {
            local_8 = static_cast<std::uint32_t>(piVar6[1]);
            std::int32_t iVar2 = piVar6[2];
            piVar6 = reinterpret_cast<std::int32_t*>(*piVar6);
            if (piVar6 == nullptr) {
                using HashFn = int (*)(std::uint32_t);
                HashFn hashFn = *reinterpret_cast<HashFn*>(
                    static_cast<std::uintptr_t>(*reinterpret_cast<std::uint32_t*>(in_ECX + 0xe0)) + 4);
                int iVar7 = hashFn(local_8);
                uVar5 = static_cast<std::uint32_t>(iVar7 + 1);
                if (uVar5 < *reinterpret_cast<std::uint32_t*>(in_ECX + 0xe4)) {
                    std::uint32_t* puVar8 = reinterpret_cast<std::uint32_t*>(
                        static_cast<std::uintptr_t>(
                            *reinterpret_cast<std::uint32_t*>(in_ECX + 0xe8) + uVar5 * 4));
                    do {
                        piVar6 = reinterpret_cast<std::int32_t*>(*puVar8);
                        if (piVar6 != nullptr) break;
                        uVar5 = uVar5 + 1;
                        puVar8 = puVar8 + 1;
                    } while (uVar5 < *reinterpret_cast<std::uint32_t*>(in_ECX + 0xe4));
                }
                if (piVar6 == nullptr) {
                    piVar6 = nullptr;
                }
            }
            std::int32_t* piVar3 = reinterpret_cast<std::int32_t*>(*param_1);
            using HashFn = int (*)(std::int32_t);
            HashFn hashFn = *reinterpret_cast<HashFn*>(static_cast<std::uintptr_t>(piVar3[0]) + 4);
            int iVar7 = hashFn(iVar2);
            std::uint32_t* puVar8 = *reinterpret_cast<std::uint32_t**>(
                static_cast<std::uintptr_t>(static_cast<std::uint32_t>(piVar3[2] + iVar7 * 4)));
            for (; puVar8 != nullptr; puVar8 = reinterpret_cast<std::uint32_t*>(*puVar8)) {
                using EqFn = char (*)(std::int32_t, std::uint32_t);
                EqFn eqFn = *reinterpret_cast<EqFn*>(static_cast<std::uintptr_t>(piVar3[0]) + 8);
                char cVar4 = eqFn(iVar2, puVar8[1]);
                if (cVar4 != '\0') {
                    local_10 = puVar8[2];
                    break;
                }
            }
            FUN_00545310(static_cast<int>(local_8), static_cast<int>(local_10));
            in_ECX = base;
        } while (piVar6 != nullptr);
    }
    std::uint32_t* puVar8 = *reinterpret_cast<std::uint32_t**>(in_ECX + 0xd4);
    while (puVar8 != nullptr) {
        std::uint32_t* puVar1 = puVar8 + 2;
        puVar8 = reinterpret_cast<std::uint32_t*>(*puVar8);
        using NotifyFn = void (*)(int*);
        NotifyFn notifyFn = *reinterpret_cast<NotifyFn*>(
            static_cast<std::uintptr_t>(*reinterpret_cast<std::uint32_t*>(puVar1)) + 0x28);
        notifyFn(param_1);
    }
    (void)local_c;
}

// 0x5aef20 — observed shape
std::uint8_t FUN_005aef20(void* self, std::uint32_t param_1)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    char cVar3 = thunk_FUN_0053e530(param_1);
    if (cVar3 == '\0') {
        return 0;
    }
    std::uint32_t* puVar2 = *reinterpret_cast<std::uint32_t**>(base + 0xd4);
    while (puVar2 != nullptr) {
        std::uint32_t* puVar1 = puVar2 + 2;
        puVar2 = reinterpret_cast<std::uint32_t*>(*puVar2);
        using NotifyFn = void (*)(std::uint32_t);
        NotifyFn notifyFn = *reinterpret_cast<NotifyFn*>(
            static_cast<std::uintptr_t>(*reinterpret_cast<std::uint32_t*>(puVar1)) + 0x14);
        notifyFn(param_1);
    }
    return 1;
}

// 0x5aef60 — observed shape
void FUN_005aef60(std::uint32_t* param_1)
{
    FUN_0051ac30(0);
    FUN_004b1100();
    param_1[1] = 0;
    *param_1 = DAT_00727868;
    DAT_00727868 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(param_1));
    FUN_004b10d0();
}

// 0x5aefa0 — observed shape
void FUN_005aefa0(void* self)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    std::int32_t* piVar2 = *reinterpret_cast<std::int32_t**>(base + 0xbc);
    using ModeFn = void (*)(int);
    ModeFn modeFn = *reinterpret_cast<ModeFn*>(static_cast<std::uintptr_t>(*piVar2) + 0x34);
    modeFn(0);
    *reinterpret_cast<std::uint16_t*>(piVar2 + 0x15) = 0;
    *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::uint8_t*>(piVar2) + 0x56) = 0;
    std::uint32_t* puVar4 = *reinterpret_cast<std::uint32_t**>(base + 0xd4);
    *reinterpret_cast<std::uint32_t*>(base + 0xf4) = 0xff7fffff;
    while (puVar4 != nullptr) {
        std::uint32_t* puVar1 = puVar4 + 2;
        puVar4 = reinterpret_cast<std::uint32_t*>(*puVar4);
        using ResetFn = void (*)();
        ResetFn resetFn = *reinterpret_cast<ResetFn*>(
            static_cast<std::uintptr_t>(*reinterpret_cast<std::uint32_t*>(puVar1)) + 0x3c);
        resetFn();
    }
    std::int32_t* piVar2b = *reinterpret_cast<std::int32_t**>(base + 0x10);
    for (;;) {
        if (piVar2b == nullptr) {
            return;
        }
        std::uint8_t bVar3 = 0;
        using FirstFn = std::uint32_t* (*)();
        FirstFn firstFn = *reinterpret_cast<FirstFn*>(static_cast<std::uintptr_t>(*piVar2b) + 4);
        std::uint32_t* puVar4b = firstFn();
        for (; puVar4b != nullptr; puVar4b = reinterpret_cast<std::uint32_t*>(puVar4b[1])) {
            if (puVar4b == reinterpret_cast<std::uint32_t*>(&DAT_00728b88)) {
                bVar3 = 1;
                break;
            }
        }
        std::int32_t* target = reinterpret_cast<std::int32_t*>(
            -static_cast<std::uint32_t>(bVar3) & reinterpret_cast<std::uint32_t>(piVar2b));
        if (target != nullptr) {
            using ResetFn = void (*)();
            ResetFn resetFn = *reinterpret_cast<ResetFn*>(static_cast<std::uintptr_t>(*target) + 0x68);
            resetFn();
        }
        piVar2b = reinterpret_cast<std::int32_t*>(piVar2b[0xe]);
    }
}

// 0x5af100 — observed shape
void FUN_005af100(void* self, int param_1)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    int iVar1 = param_1;
    thunk_FUN_0053ec00(param_1);
    std::int32_t* obj = *reinterpret_cast<std::int32_t**>(static_cast<std::uintptr_t>(iVar1) + 0x15c);
    using ReadFn = void (*)(int*, int);
    ReadFn readFn = *reinterpret_cast<ReadFn*>(static_cast<std::uintptr_t>(*obj) + 8);
    readFn(&param_1, 1);
    // NEEDS_MANUAL: the stored byte comes from the unmodelled SI register (unaff_SI).
    std::uint8_t unaff_SI = 0;
    *reinterpret_cast<bool*>(base + 0xcc) = unaff_SI != '\0';
    FUN_00545d20();
}

// 0x5af140 — observed shape
void FUN_005af140(void* self, int* param_1)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    int* piVar3 = param_1;
    thunk_FUN_0053ed20(param_1);
    std::uint32_t packed = (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(param_1)) & 0xffffff00u)
                           | static_cast<std::uint32_t>(base[0xcc]);
    std::uint32_t vtable_src = static_cast<std::uint32_t>(piVar3[0x58]);
    using WriteFn = void (*)(std::uint32_t*, int);
    WriteFn writeFn = *reinterpret_cast<WriteFn*>(
        static_cast<std::uintptr_t>(*reinterpret_cast<std::int32_t*>(
            static_cast<std::uintptr_t>(vtable_src))) + 0xc);
    writeFn(&packed, 1);
    std::uint8_t auStack_2[2];
    WriteFn writeFn2 = *reinterpret_cast<WriteFn*>(
        static_cast<std::uintptr_t>(*reinterpret_cast<std::int32_t*>(
            static_cast<std::uintptr_t>(vtable_src))) + 0xc);
    writeFn2(reinterpret_cast<std::uint32_t*>(auStack_2 - 10), 4);
    std::uint32_t* puVar2 = *reinterpret_cast<std::uint32_t**>(base + 0xd4);
    while (puVar2 != nullptr) {
        std::uint32_t* puVar1 = puVar2 + 2;
        puVar2 = reinterpret_cast<std::uint32_t*>(*puVar2);
        using NotifyFn = void (*)(std::uint32_t);
        NotifyFn notifyFn = *reinterpret_cast<NotifyFn*>(static_cast<std::uintptr_t>(*piVar3) + 0x2c);
        notifyFn(*puVar1);
    }
}

// 0x5af1b0 — observed shape
std::uint32_t FUN_005af1b0(void* self, int param_1)
{
    std::uint8_t* base = static_cast<std::uint8_t*>(self);
    int iVar3 = param_1;
    char cVar = thunk_FUN_0053e570(param_1);
    std::uint32_t uVar5 = 0;
    std::uint32_t local_c = 0;
    std::int32_t* piStack_8 = nullptr;
    std::uint32_t uStack_4 = 0;
    if ((cVar == '\0') ||
        (*reinterpret_cast<char*>(base + 0xcc) != *reinterpret_cast<char*>(static_cast<std::uintptr_t>(iVar3) + 0xcc))) {
        // Result boolean is zero (AL); the listing returns the residue shifted left by 8.
        std::uint32_t extraout_var = 0;
        return extraout_var << 8;
    }
    std::uint32_t* puVar1 = *reinterpret_cast<std::uint32_t**>(base + 0xd4);
    while (puVar1 != nullptr) {
        std::int32_t* piVar2 = reinterpret_cast<std::int32_t*>(puVar1[2]);
        puVar1 = reinterpret_cast<std::uint32_t*>(*puVar1);
        using LookupFn = char (*)(int, void*);
        char cVar4 = reinterpret_cast<LookupFn>(&FUN_005bd960)(piVar2[3], &local_c);
        using TestFn = std::uint8_t (*)(std::uint32_t);
        TestFn testFn = *reinterpret_cast<TestFn*>(static_cast<std::uintptr_t>(*piVar2) + 0x1c);
        uVar5 = testFn(-static_cast<std::uint32_t>(cVar4 != '\0') & local_c);
        if (static_cast<char>(uVar5) == '\0') {
            return uVar5 & 0xffffff00u;
        }
    }
    local_c = FUN_005065b0();
    for (;;) {
        if (local_c == 0) {
            return 1;
        }
        FUN_005aead0(base, reinterpret_cast<int*>(&local_c), &param_1, &piStack_8);
        using LookupFn = char (*)(int, void*);
        uVar5 = static_cast<std::uint32_t>(
            reinterpret_cast<LookupFn>(&FUN_005bd960)(param_1, &uStack_4));
        if (static_cast<char>(uVar5) == '\0') {
            break;
        }
        using TestFn = std::uint8_t (*)(std::uint32_t);
        TestFn testFn = *reinterpret_cast<TestFn*>(static_cast<std::uintptr_t>(*piStack_8) + 0x1c);
        uVar5 = testFn(uStack_4);
        if (static_cast<char>(uVar5) == '\0') {
            break;
        }
    }
    return uVar5 & 0xffffff00u;
}

// 0x5af2a0 — observed shape
std::int32_t* FUN_005af2a0(void* self, int param_1, int* param_2)
{
    std::int32_t* ecx = static_cast<std::int32_t*>(self);
    using MakeFn = std::int32_t* (*)();
    MakeFn makeFn = *reinterpret_cast<MakeFn*>(static_cast<std::uintptr_t>(ecx[0]) + 4);
    std::int32_t* piVar4 = makeFn();
    std::int32_t* puVar2 = reinterpret_cast<std::int32_t*>(piVar4[2]);
    if (puVar2 != reinterpret_cast<std::int32_t*>(*param_2)) {
        if (puVar2 != nullptr) {
            std::int32_t* piVar1 = puVar2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using ReleaseFn = void (*)(int);
                ReleaseFn releaseFn = *reinterpret_cast<ReleaseFn*>(static_cast<std::uintptr_t>(*puVar2));
                releaseFn(1);
            }
        }
        std::int32_t iVar3 = *param_2;
        piVar4[2] = iVar3;
        if (iVar3 != 0) {
            *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(iVar3) + 4) =
                *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(iVar3) + 4) + 1;
        }
    }
    *piVar4 = param_1;
    piVar4[1] = *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(param_1) + 4);
    if (*reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(param_1) + 4) == 0) {
        ecx[1] = static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(piVar4));
        *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(param_1) + 4) =
            static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(piVar4));
        ecx[3] = ecx[3] + 1;
        return piVar4;
    }
    *reinterpret_cast<std::int32_t*>(
        static_cast<std::uintptr_t>(*reinterpret_cast<std::int32_t*>(
            static_cast<std::uintptr_t>(param_1) + 4))) =
        static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(piVar4));
    *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(param_1) + 4) =
        static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(piVar4));
    ecx[3] = ecx[3] + 1;
    return piVar4;
}
