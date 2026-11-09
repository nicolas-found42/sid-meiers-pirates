#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <windows.h>

extern "C" int LAB_005620f0(const void*, const void*);
extern "C" int LAB_00562130(const void*, const void*);

extern void* thunk_FUN_00533c78(std::size_t size);
extern void FUN_00533cb0(int n);
extern void FUN_0055f300(int n);
extern void FUN_00551190();
extern void FUN_00538400();
extern void FUN_00545310(std::uint32_t a, float b);
extern void FUN_005623c0(int n);
extern void FUN_00562440();
extern char FUN_005624c0(void* p);
extern void FUN_005e1490();
extern void FUN_005423b0(void** a, void** b, int c);
extern int FUN_00541360(std::uint32_t a, std::uint32_t b, int c);
extern void FUN_00538630(int p);
extern std::uint8_t FUN_00562530(void* p);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void* PTR_FUN_006c34bc;
extern void* PTR_FUN_006c34f0;
extern void* PTR_FUN_006c350c;
extern void* PTR_LAB_006c34b8;

std::uint16_t FUN_005625a0(void* self);
void* FUN_00562630(void* self, int* param_1, int* param_2);
void FUN_00562730(void* self, int* param_1, int* param_2, int param_3);
void FUN_00562830(int* param_1, int param_2, int param_3);
int FUN_005629d0(void* self, void* param_1);
void FUN_00562a30(void* self, void* param_1);
std::uint32_t FUN_00562ad0(int param_1, int param_2);
void FUN_00563bd0(int* param_1, int param_2, int* param_3);

// 0x5625a0 — observed shape
std::uint16_t FUN_005625a0(void* self)
{
    std::uint32_t* in_ECX = static_cast<std::uint32_t*>(self);
    std::uint16_t uVar1;
    std::uint16_t uVar2;
    std::uint16_t uVar3;
    std::uint32_t uVar4;
    uVar1 = *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(in_ECX) + 10);
    uVar2 = static_cast<std::uint16_t>(in_ECX[2]);
    if (uVar1 < uVar2) {
        uVar4 = in_ECX[1] + 1;
        in_ECX[1] = uVar4;
        if (uVar4 < static_cast<std::uint32_t>((reinterpret_cast<int*>(in_ECX[4]))[2])) {
            *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(in_ECX) + 10) =
                *reinterpret_cast<std::uint16_t*>(in_ECX[4] + uVar4 * 2);
            return uVar1;
        }
        *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(in_ECX) + 10) = 0xffff;
        return uVar1;
    }
    if (uVar1 == uVar2) {
        uVar4 = in_ECX[1] + 1;
        in_ECX[1] = uVar4;
        if (uVar4 < static_cast<std::uint32_t>((reinterpret_cast<int*>(in_ECX[4]))[2])) {
            uVar3 = *reinterpret_cast<std::uint16_t*>(in_ECX[4] + uVar4 * 2);
        } else {
            uVar3 = 0xffff;
        }
        *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(in_ECX) + 10) = uVar3;
    }
    uVar4 = in_ECX[0] + 1;
    in_ECX[0] = uVar4;
    if (uVar4 < static_cast<std::uint32_t>((reinterpret_cast<int*>(in_ECX[3]))[2])) {
        *(in_ECX + 2) = *reinterpret_cast<std::uint16_t*>(in_ECX[3] + uVar4 * 2);
        return uVar2;
    }
    *(in_ECX + 2) = 0xffff;
    return uVar2;
}

// 0x562630 — observed shape
void* FUN_00562630(void* self, int* param_1, int* param_2)
{
    std::uint16_t uVar1;
    std::uint32_t* puVar2;
    std::uint32_t uVar4;
    std::uint32_t uVar5;
    std::uint32_t* puVar6;
    int iVar7;
    std::uint16_t local_8;
    std::uint16_t local_6;
    std::uint16_t local_4[2];
    uVar1 = *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(param_2) + 12);
    uVar5 = static_cast<std::uint32_t>(uVar1);
    puVar2 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(static_cast<std::size_t>(uVar5 * 2)));
    if (uVar5 != 0) {
        puVar6 = puVar2;
        for (uVar4 = static_cast<std::uint32_t>(uVar1 >> 1); uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar6 = 0xffffffff;
            puVar6 = puVar6 + 1;
        }
        for (uVar4 = static_cast<std::uint32_t>((uVar1 & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
            *reinterpret_cast<std::uint16_t*>(puVar6) = 0xffff;
            puVar6 = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::intptr_t>(puVar6) + 2);
        }
    }
    uVar4 = 0;
    iVar7 = 0;
    if (*reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(self) + 0x1e) != 0) {
        do {
            typedef void (__cdecl* Callback)(std::uint16_t, std::uint16_t*, std::uint16_t*, std::uint16_t*);
            Callback cb = reinterpret_cast<Callback>(*reinterpret_cast<void**>(*param_2 + 0x48));
            cb(*reinterpret_cast<std::uint16_t*>(*param_1 + uVar4 * 2), &local_8, &local_6, local_4);
            if (*reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(puVar2) + static_cast<std::uint32_t>(local_8) * 2) == -1) {
                *reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(puVar2) + static_cast<std::uint32_t>(local_8) * 2) = static_cast<short>(iVar7);
                iVar7 = iVar7 + 1;
            }
            if (*reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(puVar2) + static_cast<std::uint32_t>(local_6) * 2) == -1) {
                *reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(puVar2) + static_cast<std::uint32_t>(local_6) * 2) = static_cast<short>(iVar7);
                iVar7 = iVar7 + 1;
            }
            if (*reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(puVar2) + static_cast<std::uint32_t>(local_4[0]) * 2) == -1) {
                *reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(puVar2) + static_cast<std::uint32_t>(local_4[0]) * 2) = static_cast<short>(iVar7);
                iVar7 = iVar7 + 1;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(self) + 0x1e));
    }
    std::uint32_t uVar3 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(thunk_FUN_00533c78(static_cast<std::size_t>(iVar7 * 2))));
    *reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(self) + 0x1c) = static_cast<short>(iVar7);
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::intptr_t>(self) + 0xc) = uVar3;
    uVar4 = 0;
    if (uVar5 != 0) {
        do {
            uVar1 = *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(puVar2) + uVar4 * 2);
            if (uVar1 != 0xffff) {
                *reinterpret_cast<short*>(*reinterpret_cast<std::intptr_t*>(reinterpret_cast<std::intptr_t>(self) + 0xc) + static_cast<std::uint32_t>(uVar1) * 2) = static_cast<short>(uVar4);
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar5);
    }
    return puVar2;
}

// 0x562730 — observed shape
void FUN_00562730(void* self, int* param_1, int* param_2, int param_3)
{
    std::uint16_t* puVar2;
    std::uint32_t uVar4;
    std::uint16_t local_8;
    std::uint16_t local_6;
    std::uint16_t local_4[2];
    void* uVar1 = thunk_FUN_00533c78(static_cast<std::size_t>(*reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(self) + 0x1e) * 6));
    uVar4 = 0;
    *reinterpret_cast<void**>(reinterpret_cast<std::intptr_t>(self) + 0x14) = uVar1;
    if (*reinterpret_cast<short*>(reinterpret_cast<std::intptr_t>(self) + 0x1e) != 0) {
        int iVar3 = 0;
        do {
            typedef void (__cdecl* Callback)(std::uint16_t, std::uint16_t*, std::uint16_t*, std::uint16_t*);
            Callback cb = reinterpret_cast<Callback>(*reinterpret_cast<void**>(*param_2 + 0x48));
            cb(*reinterpret_cast<std::uint16_t*>(*param_1 + uVar4 * 2), &local_8, &local_6, local_4);
            puVar2 = reinterpret_cast<std::uint16_t*>(*reinterpret_cast<std::intptr_t*>(reinterpret_cast<std::intptr_t>(self) + 0x14) + iVar3);
            *puVar2 = *reinterpret_cast<std::uint16_t*>(param_3 + static_cast<std::uint32_t>(local_8) * 2);
            puVar2[1] = *reinterpret_cast<std::uint16_t*>(param_3 + static_cast<std::uint32_t>(local_6) * 2);
            puVar2[2] = *reinterpret_cast<std::uint16_t*>(param_3 + static_cast<std::uint32_t>(local_4[0]) * 2);
            uVar4 = uVar4 + 1;
            iVar3 = iVar3 + 6;
        } while (uVar4 < *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(self) + 0x1e));
    }
}

// 0x5627d0 — observed shape
void FUN_005627d0(void* self, std::uint8_t param_1)
{
    std::uint32_t* in_ECX = static_cast<std::uint32_t*>(self);
    *in_ECX = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c34bc));
    FUN_00551190();
    std::uint32_t* puVar1 = reinterpret_cast<std::uint32_t*>(in_ECX[4]);
    if (puVar1 != nullptr) {
        if (puVar1[-1] == 0) {
            operator_delete__(puVar1 + -1);
        } else {
            typedef void (__cdecl* Callback)(int);
            Callback cb = reinterpret_cast<Callback>(*puVar1);
            cb(3);
        }
    }
    FUN_00538400();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x562830 — observed shape
void FUN_00562830(int* param_1, int param_2, int param_3)
{
    int* piVar1;
    float fVar;
    std::uint32_t uVar2;
    std::uint32_t uVar7;
    std::uint32_t local_8;
    local_8 = 0;
    do {
        piVar1 = reinterpret_cast<int*>(param_3 + static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(param_2 + local_8 * 2)) * 0xc);
        uVar2 = static_cast<std::uint32_t>(piVar1[2]);
        uVar7 = 0;
        if (uVar2 != 0) {
            do {
                std::uint32_t uVar3 = *reinterpret_cast<std::uint32_t*>(*piVar1 + uVar7 * 8);
                typedef std::uint32_t (__cdecl* HashFn)(std::uint32_t);
                HashFn hf = reinterpret_cast<HashFn>(*reinterpret_cast<void**>(*param_1 + 4));
                int iVar6 = static_cast<int>(hf(uVar3));
                for (std::uint32_t* puVar4 = *reinterpret_cast<std::uint32_t**>(param_1[2] + iVar6 * 4); puVar4 != nullptr; puVar4 = reinterpret_cast<std::uint32_t*>(*puVar4)) {
                    typedef char (__cdecl* PredFn)(std::uint32_t, std::uint32_t);
                    PredFn pf = reinterpret_cast<PredFn>(*reinterpret_cast<void**>(*param_1 + 8));
                    char cVar5 = pf(uVar3, puVar4[1]);
                    if (cVar5 != '\0') {
                        fVar = *reinterpret_cast<float*>(*piVar1 + 4 + uVar7 * 8);
                        if (fVar <= static_cast<float>(puVar4[2])) goto LAB_005628c6;
                        break;
                    }
                }
                FUN_00545310(uVar3, *reinterpret_cast<float*>(*piVar1 + 4 + uVar7 * 8));
            LAB_005628c6:
                uVar7 = uVar7 + 1;
            } while (uVar7 < uVar2);
        }
        local_8 = local_8 + 1;
        if (2 < local_8) {
            return;
        }
    } while (true);
}

// 0x562990 — observed shape
void FUN_00562990(void* self, std::uint8_t param_1)
{
    std::uint32_t* in_ECX = static_cast<std::uint32_t*>(self);
    *in_ECX = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c34f0));
    FUN_005e1490();
    operator_delete__(reinterpret_cast<void*>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x5629d0 — observed shape
int FUN_005629d0(void* self, void* param_1)
{
    std::uint32_t* in_ECX = static_cast<std::uint32_t*>(self);
    short sVar1 = *reinterpret_cast<short*>(*in_ECX);
    short sVar2 = *reinterpret_cast<short*>(*static_cast<std::uint32_t*>(param_1));
    int iVar3 = 0;
    while ((sVar1 != -1 || (sVar2 != -1))) {
        FUN_005625a0(self);
        iVar3 = iVar3 + 1;
    }
    return iVar3;
}

// 0x562a30 — observed shape
void FUN_00562a30(void* self, void* param_1)
{
    std::uint32_t* in_ECX = static_cast<std::uint32_t*>(self);
    std::uint32_t* in_param = static_cast<std::uint32_t*>(param_1);
    short sVar1 = *reinterpret_cast<short*>(*in_ECX);
    std::uint32_t iVar3 = in_ECX[2];
    std::uint32_t iVar4 = in_param[2];
    short sVar2 = *reinterpret_cast<short*>(*in_param);
    std::uint32_t iVar7 = 0;
    std::uint32_t iVar6 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(thunk_FUN_00533c78(static_cast<std::size_t>((iVar4 + iVar3) * 2))));
    while ((sVar1 != -1 || (sVar2 != -1))) {
        std::uint16_t uVar5 = FUN_005625a0(self);
        *reinterpret_cast<std::uint16_t*>(iVar6 + iVar7 * 2) = uVar5;
        iVar7 = iVar7 + 1;
    }
    operator_delete__(reinterpret_cast<void*>(*in_ECX));
    in_ECX[1] = iVar4 + iVar3;
    *in_ECX = iVar6;
    in_ECX[2] = iVar7;
}

// 0x562ad0 — observed shape
std::uint32_t FUN_00562ad0(int param_1, int param_2)
{
    std::uint32_t uVar2 = 0;
    do {
        char cVar1 = FUN_00562530(reinterpret_cast<void*>(param_2 + static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(param_1 + uVar2 * 2)) * 0xc));
        if (cVar1 == '\0') {
            return 0;
        }
        uVar2 = uVar2 + 1;
    } while (uVar2 < 3);
    return 1;
}

// 0x562b10 — observed shape
void FUN_00562b10(void* self, int param_1, int param_2, std::uint32_t param_3)
{
    std::uint32_t* in_ECX = static_cast<std::uint32_t*>(self);
    std::uint32_t uVar2 = 0;
    if (param_3 != 0) {
        do {
            if (*reinterpret_cast<int*>(param_2 + uVar2 * 4) == param_1) {
                std::uint32_t iVar1 = in_ECX[1];
                if (in_ECX[2] == iVar1) {
                    if (iVar1 == 0) {
                        iVar1 = 1;
                    } else {
                        iVar1 = iVar1 * 2;
                    }
                    FUN_00533cb0(static_cast<int>(iVar1));
                }
                *reinterpret_cast<short*>(*in_ECX + in_ECX[2] * 2) = static_cast<short>(uVar2);
                in_ECX[2] = in_ECX[2] + 1;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < param_3);
    }
}

// 0x562b70 — observed shape
void FUN_00562b70(void* self, int param_1, int* param_2, std::uint32_t param_3, int param_4,
                  char param_5, char param_6, std::uint8_t param_7, int param_8)
{
    std::intptr_t in_ECX = reinterpret_cast<std::intptr_t>(self);
    int* piVar1;
    int* piVar2;
    void* uVar3;
    std::uint32_t uVar4;
    void* pvVar5;
    std::uint32_t* puVar6;
    std::uint32_t uVar7;
    std::uint16_t uVar8;
    std::uint32_t* puVar9;
    int* piVar10;
    std::uint32_t uVar11;
    int iVar12;
    std::uint8_t* puVar13;

    uVar4 = static_cast<std::uint32_t>(param_2[2]);
    if (param_2[2] <= static_cast<int>(static_cast<std::uint32_t>(param_7))) {
        uVar4 = static_cast<std::uint32_t>(param_7);
    }
    *reinterpret_cast<short*>(in_ECX + 0x20) = static_cast<short>(uVar4);
    *reinterpret_cast<std::uint16_t*>(in_ECX + 0x1e) = *reinterpret_cast<std::uint16_t*>(param_1 + 8);
    uVar3 = thunk_FUN_00533c78(static_cast<std::size_t>((uVar4 & 0xffff) << 1));
    *reinterpret_cast<void**>(in_ECX + 4) = uVar3;
    uVar4 = 0;
    if (*reinterpret_cast<short*>(in_ECX + 0x20) != 0) {
        do {
            if (uVar4 < static_cast<std::uint32_t>(param_2[2])) {
                uVar8 = *reinterpret_cast<std::uint16_t*>(*param_2 + uVar4 * 2);
            } else {
                uVar8 = 0;
            }
            *reinterpret_cast<std::uint16_t*>(*reinterpret_cast<std::intptr_t*>(in_ECX + 4) + uVar4 * 2) = uVar8;
            uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x20));
    }
    pvVar5 = FUN_00562630(self, reinterpret_cast<int*>(param_1), reinterpret_cast<int*>(param_3));
    FUN_00562730(self, reinterpret_cast<int*>(param_1), reinterpret_cast<int*>(param_3), reinterpret_cast<std::intptr_t>(pvVar5));
    operator_delete__(pvVar5);
    if (param_5 != '\0') {
        *reinterpret_cast<std::uint16_t*>(in_ECX + 0x24) = static_cast<std::uint16_t>(param_7);
        iVar12 = static_cast<int>(static_cast<std::uint32_t>(param_7) * static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x1c)));
        uVar3 = thunk_FUN_00533c78(static_cast<std::size_t>(iVar12 * 4));
        *reinterpret_cast<void**>(in_ECX + 8) = uVar3;
        uVar3 = thunk_FUN_00533c78(static_cast<std::size_t>(iVar12));
        *reinterpret_cast<void**>(in_ECX + 0x10) = uVar3;
        pvVar5 = thunk_FUN_00533c78(static_cast<std::size_t>(param_8 * 4));
        uVar4 = 0;
        if (param_2[2] != 0) {
            do {
                *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::intptr_t>(pvVar5) +
                    static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(*reinterpret_cast<std::intptr_t*>(in_ECX + 4) + uVar4 * 2)) * 4) = uVar4;
                uVar4 = uVar4 + 1;
            } while (uVar4 < static_cast<std::uint32_t>(param_2[2]));
        }
        piVar10 = *reinterpret_cast<int**>(in_ECX + 8);
        puVar13 = *reinterpret_cast<std::uint8_t**>(in_ECX + 0x10);
        std::uint32_t idx = 0;
        if (*reinterpret_cast<short*>(in_ECX + 0x1c) != 0) {
            do {
                piVar2 = reinterpret_cast<int*>(param_4 + static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(*reinterpret_cast<std::intptr_t*>(in_ECX + 0xc) + idx * 2)) * 0xc);
                uVar4 = 0;
                if (piVar2[2] != 0) {
                    do {
                        piVar1 = reinterpret_cast<int*>(*piVar2 + uVar4 * 8);
                        *piVar10 = piVar1[1];
                        piVar10 = piVar10 + 1;
                        *puVar13 = *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::intptr_t>(pvVar5) + *piVar1 * 4);
                        puVar13 = puVar13 + 1;
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < static_cast<std::uint32_t>(piVar2[2]));
                }
                if (uVar4 < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x24)) {
                    do {
                        *piVar10 = 0;
                        piVar10 = piVar10 + 1;
                        *puVar13 = 0;
                        puVar13 = puVar13 + 1;
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x24));
                }
                idx = idx + 1;
            } while (idx < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x1c));
        }
        operator_delete__(pvVar5);
        return;
    }
    iVar12 = static_cast<int>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x20)) * static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x1c)));
    *reinterpret_cast<std::uint16_t*>(in_ECX + 0x24) = *reinterpret_cast<std::uint16_t*>(in_ECX + 0x20);
    puVar6 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(static_cast<std::size_t>(iVar12 * 4)));
    *reinterpret_cast<std::uint32_t**>(in_ECX + 8) = puVar6;
    std::uint32_t idx = 0;
    std::uint32_t* out = puVar6;
    if (*reinterpret_cast<short*>(in_ECX + 0x1c) != 0) {
        do {
            piVar10 = reinterpret_cast<int*>(param_4 + static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(*reinterpret_cast<std::intptr_t*>(in_ECX + 0xc) + idx * 2)) * 0xc);
            uVar4 = 0;
            if (param_2[2] != 0) {
                do {
                    uVar7 = static_cast<std::uint32_t>(piVar10[2]);
                    uVar11 = 0;
                    if (uVar7 != 0) {
                        puVar6 = reinterpret_cast<std::uint32_t*>(*piVar10);
                        puVar9 = puVar6;
                        do {
                            if (*puVar9 == static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(*param_2 + uVar4 * 2))) {
                                uVar7 = puVar6[uVar11 * 2 + 1];
                                goto LAB_00562d86;
                            }
                            uVar11 = uVar11 + 1;
                            puVar9 = puVar9 + 2;
                        } while (uVar11 < uVar7);
                        puVar6 = out;
                    }
                    uVar7 = 0;
                    out = puVar6;
                LAB_00562d86:
                    *out = uVar7;
                    puVar6 = out + 1;
                    uVar4 = uVar4 + 1;
                    out = puVar6;
                } while (uVar4 < static_cast<std::uint32_t>(param_2[2]));
            }
            if (uVar4 < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x20)) {
                do {
                    *puVar6 = 0;
                    puVar6 = puVar6 + 1;
                    uVar4 = uVar4 + 1;
                } while (uVar4 < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x20));
                out = puVar6;
            }
            idx = idx + 1;
        } while (idx < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x1c));
    }
    if (param_6 != '\0') {
        puVar13 = static_cast<std::uint8_t*>(thunk_FUN_00533c78(static_cast<std::size_t>(iVar12)));
        uVar4 = 0;
        *reinterpret_cast<std::uint8_t**>(in_ECX + 0x10) = puVar13;
        if (*reinterpret_cast<short*>(in_ECX + 0x1c) != 0) {
            do {
                uVar7 = 0;
                if (*reinterpret_cast<short*>(in_ECX + 0x20) != 0) {
                    do {
                        *puVar13 = static_cast<std::uint8_t>(uVar7);
                        puVar13 = puVar13 + 1;
                        uVar7 = uVar7 + 1;
                    } while (uVar7 < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x20));
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < *reinterpret_cast<std::uint16_t*>(in_ECX + 0x1c));
        }
    }
}

// 0x562e30 — observed shape
void FUN_00562e30(void* self, int param_1)
{
    std::intptr_t in_ECX = reinterpret_cast<std::intptr_t>(self);
    typedef void (__cdecl* StreamFn)(void* stream, void* dst, int n);
    void* stream = *reinterpret_cast<void**>(param_1 + 0x15c);
    StreamFn readFn = *reinterpret_cast<StreamFn*>(*reinterpret_cast<void**>(stream) + 8);
    std::uint8_t flag = 0;

    readFn(stream, reinterpret_cast<void*>(in_ECX + 0x1c), 2);
    readFn(stream, reinterpret_cast<void*>(in_ECX + 0x1e), 2);
    std::uint16_t* puVar1 = reinterpret_cast<std::uint16_t*>(in_ECX + 0x20);
    readFn(stream, puVar1, 2);
    readFn(stream, reinterpret_cast<void*>(in_ECX + 0x22), 2);
    readFn(stream, reinterpret_cast<void*>(in_ECX + 0x24), 2);
    void* uVar2 = thunk_FUN_00533c78(static_cast<std::size_t>(static_cast<std::uint32_t>(*puVar1) << 1));
    *reinterpret_cast<void**>(in_ECX + 4) = uVar2;
    readFn(stream, uVar2, static_cast<int>(static_cast<std::uint32_t>(*puVar1) << 1));
    if (*reinterpret_cast<std::uint32_t*>(param_1 + 0x1c) < 0xa000112) {
        flag = 1;
    } else {
        readFn(stream, &flag, 1);
    }
    if (flag != 0) {
        uVar2 = thunk_FUN_00533c78(static_cast<std::size_t>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x1c)) << 1));
        *reinterpret_cast<void**>(in_ECX + 0xc) = uVar2;
        readFn(stream, uVar2, static_cast<int>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x1c)) << 1));
    }
    int iVar6 = static_cast<int>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x24)) * static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x1c)));
    std::uint8_t flag8 = 0;
    if (*reinterpret_cast<std::uint32_t*>(param_1 + 0x1c) < 0xa000112) {
        flag8 = 1;
    } else {
        readFn(stream, &flag8, 1);
    }
    if (flag8 != 0) {
        uVar2 = thunk_FUN_00533c78(static_cast<std::size_t>(iVar6 * 4));
        *reinterpret_cast<void**>(in_ECX + 8) = uVar2;
        readFn(stream, uVar2, iVar6 * 4);
    }
    int iVar4;
    if (*reinterpret_cast<std::uint16_t*>(in_ECX + 0x22) == 0) {
        iVar4 = static_cast<int>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x1e)) * 3);
    } else {
        uVar2 = thunk_FUN_00533c78(static_cast<std::size_t>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x22)) << 1));
        *reinterpret_cast<void**>(in_ECX + 0x18) = uVar2;
        readFn(stream, uVar2, static_cast<int>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x22)) << 1));
        iVar4 = 0;
        if (*reinterpret_cast<short*>(in_ECX + 0x22) != 0) {
            std::uint16_t* puVar3 = *reinterpret_cast<std::uint16_t**>(in_ECX + 0x18);
            std::uint32_t uVar5 = static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x22));
            do {
                iVar4 = iVar4 + static_cast<int>(*puVar3);
                puVar3 = puVar3 + 1;
                uVar5 = uVar5 - 1;
            } while (uVar5 != 0);
        }
    }
    std::uint8_t flag14 = 0;
    if (*reinterpret_cast<std::uint32_t*>(param_1 + 0x1c) < 0xa000112) {
        flag14 = 1;
    } else {
        readFn(stream, &flag14, 1);
    }
    if (flag14 != 0) {
        uVar2 = thunk_FUN_00533c78(static_cast<std::size_t>(iVar4 * 2));
        *reinterpret_cast<void**>(in_ECX + 0x14) = uVar2;
        readFn(stream, uVar2, iVar4 * 2);
    }
    std::uint8_t flag10 = 0;
    readFn(stream, &flag10, 1);
    if (flag10 != 0) {
        uVar2 = thunk_FUN_00533c78(static_cast<std::size_t>(iVar6));
        *reinterpret_cast<void**>(in_ECX + 0x10) = uVar2;
        readFn(stream, uVar2, iVar6);
    }
}

// 0x563030 — observed shape
void FUN_00563030(void* self, int param_1)
{
    std::intptr_t in_ECX = reinterpret_cast<std::intptr_t>(self);
    typedef void (__cdecl* StreamFn)(void* stream, void* src, int n);
    void* stream = *reinterpret_cast<void**>(param_1 + 0x160);
    StreamFn writeFn = *reinterpret_cast<StreamFn*>(*reinterpret_cast<void**>(stream) + 0xc);

    writeFn(stream, reinterpret_cast<void*>(in_ECX + 0x1c), 2);
    writeFn(stream, reinterpret_cast<void*>(in_ECX + 0x1e), 2);
    std::uint16_t* puVar1 = reinterpret_cast<std::uint16_t*>(in_ECX + 0x20);
    writeFn(stream, puVar1, 2);
    writeFn(stream, reinterpret_cast<void*>(in_ECX + 0x22), 2);
    writeFn(stream, reinterpret_cast<void*>(in_ECX + 0x24), 2);
    writeFn(stream, *reinterpret_cast<void**>(in_ECX + 4), static_cast<int>(static_cast<std::uint32_t>(*puVar1) << 1));
    std::uint8_t flagC = (*reinterpret_cast<int*>(in_ECX + 0xc) != 0) ? 1 : 0;
    writeFn(stream, &flagC, 1);
    if (flagC != 0) {
        writeFn(stream, *reinterpret_cast<void**>(in_ECX + 0xc), static_cast<int>(static_cast<std::uint32_t>(*puVar1) << 1));
    }
    int iVar4 = static_cast<int>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x24)) * static_cast<std::uint32_t>(*puVar1));
    std::uint8_t flag8 = (*reinterpret_cast<int*>(in_ECX + 8) != 0) ? 1 : 0;
    writeFn(stream, &flag8, 1);
    if (flag8 != 0) {
        writeFn(stream, *reinterpret_cast<void**>(in_ECX + 8), iVar4 * 4);
    }
    int iVar3;
    if (*reinterpret_cast<std::uint16_t*>(in_ECX + 0x22) == 0) {
        iVar3 = static_cast<int>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x1e)) * 3);
    } else {
        writeFn(stream, *reinterpret_cast<void**>(in_ECX + 0x18), static_cast<int>(static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x22)) << 1));
        std::uint32_t uVar2 = static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(in_ECX + 0x22));
        iVar3 = 0;
        if (uVar2 != 0) {
            std::uint16_t* puVar = *reinterpret_cast<std::uint16_t**>(in_ECX + 0x18);
            do {
                iVar3 = iVar3 + static_cast<int>(*puVar);
                puVar = puVar + 1;
                uVar2 = uVar2 - 1;
            } while (uVar2 != 0);
        }
    }
    std::uint8_t flag14 = (*reinterpret_cast<int*>(in_ECX + 0x14) != 0) ? 1 : 0;
    writeFn(stream, &flag14, 1);
    if (flag14 != 0) {
        writeFn(stream, *reinterpret_cast<void**>(in_ECX + 0x14), iVar3 * 2);
    }
    std::uint8_t flag10 = (*reinterpret_cast<int*>(in_ECX + 0x10) != 0) ? 1 : 0;
    writeFn(stream, &flag10, 1);
    if (flag10 != 0) {
        writeFn(stream, *reinterpret_cast<void**>(in_ECX + 0x10), iVar4);
    }
}

// 0x5631f0 — observed shape
int* FUN_005631f0(int param_1, int param_2)
{
    std::uint32_t uVar1;
    std::uint32_t uVar2;
    int iVar3;
    int* piVar4;
    int iVar5;
    int iVar6;
    std::uint32_t uVar7;
    std::uint32_t uVar8;
    int* local_14;
    int local_10;

    piVar4 = static_cast<int*>(thunk_FUN_00533c78(static_cast<std::size_t>(param_1 * 0xc + 4)));
    if (piVar4 == nullptr) {
        local_14 = nullptr;
    } else {
        local_14 = piVar4 + 1;
        *piVar4 = param_1;
        if (-1 < param_1 + -1) {
            piVar4 = local_14;
            iVar6 = param_1;
            do {
                *piVar4 = 0;
                piVar4[1] = 0;
                piVar4[2] = 0;
                piVar4 = piVar4 + 3;
                iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
        }
    }
    uVar1 = *reinterpret_cast<std::uint32_t*>(param_2 + 0x44);
    uVar8 = 0;
    if (uVar1 != 0) {
        local_10 = 0;
        do {
            uVar7 = 0;
            iVar6 = *reinterpret_cast<int*>(param_2 + 0x48) + local_10;
            if (*reinterpret_cast<short*>(iVar6 + 0x48) != 0) {
                do {
                    uVar2 = *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::intptr_t*>(iVar6 + 0x44) + 4 + uVar7 * 8);
                    piVar4 = local_14 + static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(*reinterpret_cast<std::intptr_t*>(iVar6 + 0x44) + uVar7 * 8)) * 3;
                    iVar5 = piVar4[1];
                    if (piVar4[2] == iVar5) {
                        if (iVar5 == 0) {
                            iVar5 = 1;
                        } else {
                            iVar5 = iVar5 * 2;
                        }
                        FUN_005623c0(iVar5);
                    }
                    iVar5 = piVar4[2];
                    iVar3 = *piVar4;
                    *reinterpret_cast<std::uint32_t*>(iVar3 + iVar5 * 8) = uVar8;
                    *reinterpret_cast<std::uint32_t*>(iVar3 + 4 + iVar5 * 8) = uVar2;
                    piVar4[2] = piVar4[2] + 1;
                    uVar7 = uVar7 + 1;
                } while (uVar7 < *reinterpret_cast<std::uint16_t*>(iVar6 + 0x48));
            }
            uVar8 = uVar8 + 1;
            local_10 = local_10 + 0x4c;
        } while (uVar8 < uVar1);
    }
    for (; param_1 != 0; param_1 = param_1 + -1) {
        FUN_00562440();
    }
    return local_14;
}

// 0x563300 — observed shape
void FUN_00563300(std::uint8_t param_1, int* param_2)
{
    int iVar1;
    std::uint32_t* puVar2;
    std::uint32_t* puVar3;
    int* piVar4;
    char cVar5;
    std::uint32_t uVar6;
    int iVar7;
    std::uint32_t uVar8;
    std::uint32_t uVar9;
    int local_14;
    std::uint32_t local_8;
    std::uint32_t local_4;

    piVar4 = param_2;
    while (true) {
        local_14 = -1;
        int idx = 0;
        if (piVar4[2] == 0) {
            return;
        }
        do {
            iVar1 = *reinterpret_cast<int*>(*piVar4 + idx * 4);
            uVar8 = static_cast<std::uint32_t>(idx + 1);
            if (uVar8 < static_cast<std::uint32_t>(piVar4[2])) {
                uVar9 = uVar8;
                do {
                    iVar7 = *reinterpret_cast<int*>(*piVar4 + uVar9 * 4);
                    // receiver (ECX) for FUN_005629d0 is not materialized in the listing
                    uVar6 = static_cast<std::uint32_t>(FUN_005629d0(nullptr, reinterpret_cast<void*>(static_cast<std::intptr_t>(iVar7))));
                    if ((uVar6 <= param_1) &&
                        (iVar7 = (*reinterpret_cast<int*>(iVar7 + 8) + *reinterpret_cast<int*>(iVar1 + 8)) - static_cast<int>(uVar6), local_14 < iVar7)) {
                        local_8 = static_cast<std::uint32_t>(idx);
                        local_14 = iVar7;
                        local_4 = uVar9;
                    }
                    uVar9 = uVar9 + 1;
                } while (uVar9 < static_cast<std::uint32_t>(piVar4[2]));
            }
            idx = static_cast<int>(uVar8);
        } while (uVar8 < static_cast<std::uint32_t>(piVar4[2]));
        if (local_14 < 0) break;
        // receiver (ECX) for FUN_00562a30 is not materialized in the listing
        FUN_00562a30(nullptr, reinterpret_cast<void*>(static_cast<std::intptr_t>(*reinterpret_cast<int*>(*piVar4 + local_4 * 4))));
        puVar2 = *reinterpret_cast<std::uint32_t**>(*piVar4 + local_4 * 4);
        if (puVar2 != nullptr) {
            operator_delete__(reinterpret_cast<void*>(*puVar2));
            operator_delete(puVar2);
        }
        iVar1 = piVar4[2];
        piVar4[2] = iVar1 + -1;
        *reinterpret_cast<std::uint32_t*>(*piVar4 + local_4 * 4) = *reinterpret_cast<std::uint32_t*>(*piVar4 + (iVar1 + -1) * 4);
        puVar2 = *reinterpret_cast<std::uint32_t**>(*piVar4 + local_8 * 4);
        uVar8 = 0;
        if (piVar4[2] != 0) {
            do {
                puVar3 = *reinterpret_cast<std::uint32_t**>(*piVar4 + uVar8 * 4);
                if ((puVar3 == puVar2) || (cVar5 = FUN_005624c0(puVar3), cVar5 == '\0')) {
                    uVar8 = uVar8 + 1;
                } else {
                    if (puVar3 != nullptr) {
                        operator_delete__(reinterpret_cast<void*>(*puVar3));
                        operator_delete(puVar3);
                    }
                    iVar1 = piVar4[2];
                    piVar4[2] = iVar1 + -1;
                    *reinterpret_cast<std::uint32_t*>(*piVar4 + uVar8 * 4) = *reinterpret_cast<std::uint32_t*>(*piVar4 + (iVar1 + -1) * 4);
                }
            } while (uVar8 < static_cast<std::uint32_t>(piVar4[2]));
        }
    }
}

// 0x563440 — observed shape
std::uint32_t FUN_00563440(int param_1, std::uint32_t param_2, std::uint32_t param_3, int param_4, char param_5)
{
    std::uint32_t uVar2 = 0;
    if (*reinterpret_cast<int*>(param_1 + 8) != 0) {
        do {
            if ((*reinterpret_cast<char*>(uVar2 + param_4) == param_5) &&
                (FUN_00562ad0(static_cast<int>(param_2), static_cast<int>(param_3)) != 0)) {
                *reinterpret_cast<std::uint8_t*>(uVar2 + param_4) = 1;
                return uVar2;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *reinterpret_cast<std::uint32_t*>(param_1 + 8));
    }
    return 0xffffffff;
}

// 0x5634a0 — observed shape
void FUN_005634a0(void* self, int param_1)
{
    std::intptr_t in_ECX = reinterpret_cast<std::intptr_t>(self);
    std::uint32_t* puVar1;
    std::uint32_t* puVar2;
    std::uint32_t* puVar3;
    std::uint32_t uVar4;

    FUN_00538630(param_1);
    puVar1 = reinterpret_cast<std::uint32_t*>(in_ECX + 0xc);
    typedef void (__cdecl* StreamFn)(void* stream, void* dst, int n);
    void* stream = *reinterpret_cast<void**>(param_1 + 0x15c);
    StreamFn readFn = *reinterpret_cast<StreamFn*>(*reinterpret_cast<void**>(stream) + 8);
    readFn(stream, puVar1, 4);
    uVar4 = *puVar1;
    puVar2 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(static_cast<std::size_t>(uVar4 * 0x2c + 4)));
    if (puVar2 == nullptr) {
        puVar3 = nullptr;
    } else {
        puVar3 = puVar2 + 1;
        *puVar2 = uVar4;
        if (-1 < static_cast<int>(uVar4 - 1)) {
            puVar2 = puVar3;
            do {
                *puVar2 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&PTR_LAB_006c34b8));
                puVar2[1] = 0;
                puVar2[2] = 0;
                puVar2[3] = 0;
                puVar2[4] = 0;
                puVar2[5] = 0;
                puVar2[6] = 0;
                *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(puVar2) + 0x22) = 0;
                puVar2[10] = 0;
                puVar2 = puVar2 + 0xb;
                uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
        }
    }
    *reinterpret_cast<std::uint32_t**>(in_ECX + 0x10) = puVar3;
    uVar4 = 0;
    if (*puVar1 != 0) {
        do {
            // EBX receiver is not materialized in the listing; the per-record object at +0x2c stride is used
            FUN_00562e30(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(&puVar3[uVar4 * 0xb])), param_1);
            uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar1);
    }
}

// 0x5635a0 — observed shape
void FUN_005635a0(void* self, std::uint8_t param_1)
{
    std::uint32_t* in_ECX = static_cast<std::uint32_t*>(self);
    *in_ECX = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c350c));
    FUN_005e1490();
    *in_ECX = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c34f0));
    FUN_005e1490();
    operator_delete__(reinterpret_cast<void*>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x5635e0 — observed shape
std::uint32_t FUN_005635e0(int* param_1, std::uint32_t param_2, std::uint8_t param_3, int param_4)
{
    std::intptr_t base = reinterpret_cast<std::intptr_t>(param_1);
    int iVar1;
    std::uint32_t uVar2;
    int* piVar3;
    std::uint32_t* puVar4;
    int iVar5;
    std::uint32_t* puVar6;
    std::uint32_t uVar7;
    std::uint32_t uVar8;
    std::uint32_t uVar9;
    int* piVar10;
    std::uint32_t uVar11;
    void* puVar12;
    void* local_60;
    std::uint32_t uStack_5c;
    std::uint32_t uStack_58;
    std::uint32_t uStack_54;
    void* local_50;
    float fStack_4c;
    float fStack_48;
    std::uint32_t uStack_44;
    int* piStack_40;
    std::uint32_t uStack_3c;
    std::uint32_t local_34;
    int iStack_30;
    std::uint32_t uStack_2c;
    std::uint32_t local_28;
    std::uint16_t local_24;
    std::uint32_t local_22;
    std::uint32_t* local_1c;
    std::uint32_t local_18;
    std::uint32_t uStack_14;
    void* local_10;
    std::uint32_t local_c;
    std::uint32_t* local_8;
    std::uint32_t local_4;

    uVar2 = static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(base + 12));
    uVar11 = static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(base + 0x3c));
    local_10 = &PTR_FUN_006c34f0;
    local_c = 0x25;
    local_4 = 0;
    local_28 = uVar11;
    local_8 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(0x94));
    {
        std::uint32_t* puVar12w = local_8;
        for (uVar8 = local_c; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar12w = 0;
            puVar12w = puVar12w + 1;
        }
    }
    local_10 = &PTR_FUN_006c350c;
    local_1c = nullptr;
    local_18 = 0;
    FUN_005423b0(&local_60, &local_50, 1);
    local_34 = 0;
    if (uVar11 != 0) {
        do {
            uVar8 = local_34;
            typedef void (__cdecl* TripFn)(std::uint32_t, std::uint16_t*, std::uint32_t*, std::uint16_t*);
            TripFn cb = *reinterpret_cast<TripFn*>(*reinterpret_cast<void**>(*param_1 + 0x48));
            cb(local_34, &local_24, &local_22, reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(&local_22) + 2));
            if (((local_24 != static_cast<std::uint16_t>(local_22)) &&
                 (static_cast<std::uint16_t>(local_22) != *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(&local_22) + 2))) &&
                (*reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(&local_22) + 2) != local_24)) {
                FUN_00562830(reinterpret_cast<int*>(&local_10), reinterpret_cast<int*>(&local_24), param_4);
                uStack_2c = param_2 & 0xff;
                uStack_3c = local_4;
                if (uStack_2c < local_4) {
                    do {
                        uVar8 = 0;
                        if (local_c != 0) {
                            do {
                                if (local_8[uVar8] != 0) {
                                    piVar3 = reinterpret_cast<int*>(local_8[uVar8]);
                                    goto LAB_005636f4;
                                }
                                uVar8 = uVar8 + 1;
                            } while (uVar8 < local_c);
                        }
                        piVar3 = nullptr;
                    LAB_005636f4:
                        fStack_48 = 3.4028235e+38f;
                        do {
                            fStack_4c = static_cast<float>(piVar3[2]);
                            iVar5 = piVar3[1];
                            piVar3 = reinterpret_cast<int*>(*piVar3);
                            if (piVar3 == nullptr) {
                                typedef std::uint32_t (__cdecl* HashFn)(int);
                                HashFn hf = *reinterpret_cast<HashFn*>(reinterpret_cast<void**>(local_10)[1]);
                                uVar8 = hf(iVar5);
                                do {
                                    uVar8 = uVar8 + 1;
                                    if (local_c <= uVar8) {
                                        piVar3 = nullptr;
                                        break;
                                    }
                                    piVar3 = reinterpret_cast<int*>(local_8[uVar8]);
                                } while (piVar3 == nullptr);
                            }
                            if (fStack_4c < fStack_48) {
                                fStack_48 = fStack_4c;
                                iStack_30 = iVar5;
                            }
                        } while (piVar3 != nullptr);
                        uStack_54 = 0;
                        do {
                            uVar8 = *reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(&local_24) + uStack_54 * 2);
                            uStack_44 = uVar8;
                            if (local_18 == 0) {
                                puVar4 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(4));
                                operator_delete__(local_1c);
                                local_1c = puVar4;
                                local_18 = 1;
                            }
                            *local_1c = uVar8;
                            piStack_40 = reinterpret_cast<int*>(param_4 + uVar8 * 0xc);
                            uVar11 = 1;
                            uStack_14 = 1;
                            uStack_5c = static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(local_50) + uVar8 * 2));
                            uStack_58 = uStack_5c;
                            for (; uStack_5c != 0; uStack_5c = uStack_5c - 1) {
                                uVar8 = static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(local_60) + uStack_5c * 2 - 2));
                                iVar5 = FUN_00541360(uVar8, uStack_44, 1);
                                if (iVar5 != 0) break;
                                puVar12 = reinterpret_cast<void*>(param_4 + uVar8 * 0xc);
                                {
                                    std::uint32_t* puVar12w = static_cast<std::uint32_t*>(puVar12);
                                    uVar7 = static_cast<std::uint32_t>(piStack_40[2]);
                                    if (uVar7 == puVar12w[2]) {
                                        uVar9 = 0;
                                        if (uVar7 != 0) {
                                            piVar3 = reinterpret_cast<int*>(*puVar12w);
                                            std::intptr_t iVar5d = reinterpret_cast<std::intptr_t>(*piStack_40) - reinterpret_cast<std::intptr_t>(piVar3);
                                            do {
                                                if (*reinterpret_cast<int*>(iVar5d + reinterpret_cast<std::intptr_t>(piVar3)) != *piVar3) goto LAB_005638c4;
                                                uVar9 = uVar9 + 1;
                                                piVar3 = piVar3 + 2;
                                            } while (uVar9 < uVar7);
                                        }
                                        if (uVar11 == local_18) {
                                            if (local_18 == 0) {
                                                uVar7 = 1;
                                            } else {
                                                uVar7 = local_18 * 2;
                                            }
                                            if (uVar7 != local_18) {
                                                if (uVar7 == 0) {
                                                    puVar4 = nullptr;
                                                } else {
                                                    puVar4 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(static_cast<std::size_t>(uVar7 * 4)));
                                                    if (uVar11 != 0) {
                                                        puVar6 = puVar4;
                                                        do {
                                                            *puVar6 = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::intptr_t>(local_1c) - reinterpret_cast<std::intptr_t>(puVar4) + reinterpret_cast<std::intptr_t>(puVar6));
                                                            puVar6 = puVar6 + 1;
                                                            uVar11 = uVar11 - 1;
                                                        } while (uVar11 != 0);
                                                        uVar11 = uStack_14;
                                                    }
                                                }
                                                operator_delete__(local_1c);
                                                local_1c = puVar4;
                                                local_18 = uVar7;
                                            }
                                        }
                                        local_1c[uVar11] = uVar8;
                                        uVar11 = uVar11 + 1;
                                        uStack_14 = uVar11;
                                    }
                                }
                            LAB_005638c4:
                                ;
                            }
                            if (uStack_58 < uVar2 - 1) {
                                do {
                                    uVar8 = static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::intptr_t>(local_60) + uStack_58 * 2 + 2));
                                    iVar5 = FUN_00541360(uVar8, uStack_44, 1);
                                    if (iVar5 != 0) break;
                                    uVar7 = static_cast<std::uint32_t>(piStack_40[2]);
                                    puVar12 = reinterpret_cast<void*>(param_4 + uVar8 * 0xc);
                                    {
                                        std::uint32_t* puVar12w = static_cast<std::uint32_t*>(puVar12);
                                        if (uVar7 == puVar12w[2]) {
                                            uVar9 = 0;
                                            if (uVar7 != 0) {
                                                piVar3 = reinterpret_cast<int*>(*puVar12w);
                                                std::intptr_t iVar5d = reinterpret_cast<std::intptr_t>(*piStack_40) - reinterpret_cast<std::intptr_t>(piVar3);
                                                do {
                                                    if (*reinterpret_cast<int*>(iVar5d + reinterpret_cast<std::intptr_t>(piVar3)) != *piVar3) goto LAB_005639b4;
                                                    uVar9 = uVar9 + 1;
                                                    piVar3 = piVar3 + 2;
                                                } while (uVar9 < uVar7);
                                            }
                                            if (uVar11 == local_18) {
                                                if (local_18 == 0) {
                                                    uVar7 = 1;
                                                } else {
                                                    uVar7 = local_18 * 2;
                                                }
                                                if (uVar7 != local_18) {
                                                    if (uVar7 == 0) {
                                                        puVar4 = nullptr;
                                                    } else {
                                                        puVar4 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(static_cast<std::size_t>(uVar7 * 4)));
                                                        if (uVar11 != 0) {
                                                            puVar6 = puVar4;
                                                            do {
                                                                *puVar6 = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::intptr_t>(local_1c) - reinterpret_cast<std::intptr_t>(puVar4) + reinterpret_cast<std::intptr_t>(puVar6));
                                                                puVar6 = puVar6 + 1;
                                                                uVar11 = uVar11 - 1;
                                                            } while (uVar11 != 0);
                                                            uVar11 = uStack_14;
                                                        }
                                                    }
                                                    operator_delete__(local_1c);
                                                    local_1c = puVar4;
                                                    local_18 = uVar7;
                                                }
                                            }
                                            local_1c[uVar11] = uVar8;
                                            uVar11 = uVar11 + 1;
                                            uStack_14 = uVar11;
                                        }
                                    }
                                LAB_005639b4:
                                    uStack_58 = uStack_58 + 1;
                                } while (uStack_58 < uVar2 - 1);
                            }
                            iVar5 = iStack_30;
                            uVar8 = 0;
                            if (uVar11 != 0) {
                                do {
                                    iVar1 = *reinterpret_cast<int*>(param_4 + 8 + local_1c[uVar8] * 0xc);
                                    piVar3 = reinterpret_cast<int*>(param_4 + local_1c[uVar8] * 0xc);
                                    uVar7 = 0;
                                    if (iVar1 != 0) {
                                        piVar10 = reinterpret_cast<int*>(*piVar3);
                                    LAB_005639f4:
                                        if (*piVar10 != iVar5) goto code_r0x005639f8;
                                        if (uVar7 < static_cast<std::uint32_t>(iVar1 - 1)) {
                                            do {
                                                puVar12 = reinterpret_cast<void*>(*piVar3 + uVar7 * 8);
                                                *reinterpret_cast<std::uint32_t*>(puVar12) = *reinterpret_cast<std::uint32_t*>(*piVar3 + 8 + uVar7 * 8);
                                                *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::intptr_t>(puVar12) + 4) = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::intptr_t>(puVar12) + 12);
                                                uVar7 = uVar7 + 1;
                                            } while (uVar7 < static_cast<std::uint32_t>(piVar3[2] - 1));
                                        }
                                        iVar1 = piVar3[2];
                                        piVar3[2] = iVar1 + -1;
                                        if (iVar1 + -1 == 0) {
                                            operator_delete__(local_60);
                                            operator_delete__(local_50);
                                            operator_delete__(local_1c);
                                            local_10 = &PTR_FUN_006c350c;
                                            FUN_005e1490();
                                            local_10 = &PTR_FUN_006c34f0;
                                            FUN_005e1490();
                                            operator_delete__(local_8);
                                            return 0;
                                        }
                                        FUN_00562440();
                                    }
                                LAB_00563a40:
                                    uVar8 = uVar8 + 1;
                                } while (uVar8 < uVar11);
                            }
                            uStack_54 = uStack_54 + 1;
                        } while (uStack_54 < 3);
                        uStack_3c = uStack_3c - 1;
                        if (uStack_3c == uStack_2c) break;
                        FUN_005e1490();
                        FUN_00562830(reinterpret_cast<int*>(&local_10), reinterpret_cast<int*>(&local_24), param_4);
                    } while (true);
                }
                FUN_005e1490();
                uVar11 = local_28;
                uVar8 = local_34;
            }
            local_34 = uVar8 + 1;
        } while (local_34 < uVar11);
    }
    if (uVar2 != 0) {
        puVar4 = reinterpret_cast<std::uint32_t*>(param_4 + 8);
        std::uint32_t nRemain = uVar2;
        do {
            if (static_cast<std::uint32_t>(param_3) < *puVar4) {
                qsort(reinterpret_cast<void*>(puVar4[-2]), *puVar4, 8, LAB_005620f0);
                *puVar4 = param_3;
                FUN_00562440();
            }
            puVar4 = puVar4 + 3;
            nRemain = nRemain - 1;
        } while (nRemain != 0);
    }
    operator_delete__(local_60);
    operator_delete__(local_50);
    operator_delete__(local_1c);
    local_10 = &PTR_FUN_006c350c;
    FUN_005e1490();
    local_10 = &PTR_FUN_006c34f0;
    FUN_005e1490();
    operator_delete__(local_8);
    return 1;
code_r0x005639f8:
    uVar7 = uVar7 + 1;
    piVar10 = piVar10 + 2;
    if (static_cast<std::uint32_t>(piVar3[2]) <= uVar7) goto LAB_00563a40;
    goto LAB_005639f4;
}

// 0x563bd0 — observed shape
void FUN_00563bd0(int* param_1, int param_2, int* param_3)
{
    std::intptr_t base = reinterpret_cast<std::intptr_t>(param_1);
    int* piVar1;
    std::uint16_t uVar2;
    short sVar3;
    std::uint32_t* puVar4;
    char cVar5;
    int* piVar6;
    std::uint32_t uVar7;
    int iVar8;
    short* psVar9;
    std::uint32_t uVar10;
    std::uint32_t uVar11;
    std::uint32_t uStack_18;
    std::uint32_t local_14;
    std::uint16_t local_8;
    std::uint8_t local_6[2];
    std::uint16_t local_4[2];

    uVar2 = *reinterpret_cast<std::uint16_t*>(base + 0x3c);
    local_14 = 0;
    if (uVar2 != 0) {
        do {
            typedef void (__cdecl* TripFn)(std::uint32_t, std::uint16_t*, std::uint8_t*, std::uint16_t*);
            TripFn cb = *reinterpret_cast<TripFn*>(*reinterpret_cast<void**>(*param_1 + 0x48));
            cb(local_14, &local_8, local_6, local_4);
            if (((local_8 != *reinterpret_cast<std::uint16_t*>(local_6)) &&
                 (*reinterpret_cast<std::uint16_t*>(local_6) != local_4[0])) &&
                (local_4[0] != local_8)) {
                piVar6 = static_cast<int*>(FUN_00533c78(0xc));
                if (piVar6 == nullptr) {
                    piVar6 = nullptr;
                } else {
                    piVar6[0] = 0;
                    piVar6[1] = 0;
                    piVar6[2] = 0;
                }
                uStack_18 = 0;
                do {
                    piVar1 = reinterpret_cast<int*>(param_2 + static_cast<std::uint32_t>(*reinterpret_cast<std::uint16_t*>(local_6 + uStack_18 * 2 - 2)) * 0xc);
                    uVar11 = static_cast<std::uint32_t>(piVar1[2]);
                    uVar10 = 0;
                    if (uVar11 != 0) {
                        do {
                            sVar3 = *reinterpret_cast<short*>(*piVar1 + uVar10 * 8);
                            uVar7 = 0;
                            bool found = false;
                            if (piVar6[2] != 0) {
                                psVar9 = reinterpret_cast<short*>(*piVar6);
                                do {
                                    if (*psVar9 == sVar3) {
                                        if (uVar7 != 0xffffffff) {
                                            found = true;
                                        }
                                        break;
                                    }
                                    uVar7 = uVar7 + 1;
                                    psVar9 = psVar9 + 1;
                                } while (uVar7 < static_cast<std::uint32_t>(piVar6[2]));
                            }
                            if (found) goto LAB_00563ccf;
                            iVar8 = piVar6[1];
                            if (piVar6[2] == iVar8) {
                                if (iVar8 == 0) {
                                    iVar8 = 1;
                                } else {
                                    iVar8 = iVar8 * 2;
                                }
                                FUN_00533cb0(iVar8);
                            }
                            *reinterpret_cast<short*>(*piVar6 + piVar6[2] * 2) = sVar3;
                            piVar6[2] = piVar6[2] + 1;
                        LAB_00563ccf:
                            uVar10 = uVar10 + 1;
                        } while (uVar10 < uVar11);
                    }
                    uStack_18 = uStack_18 + 1;
                } while (uStack_18 < 3);
                qsort(reinterpret_cast<void*>(*piVar6), static_cast<std::size_t>(piVar6[2]), 2, LAB_00562130);
                uVar11 = 0;
                if (param_3[2] != 0) {
                    do {
                        puVar4 = *reinterpret_cast<std::uint32_t**>(*param_3 + uVar11 * 4);
                        cVar5 = FUN_005624c0(piVar6);
                        if (cVar5 != '\0') {
                            operator_delete__(reinterpret_cast<void*>(*piVar6));
                            operator_delete(piVar6);
                            break;
                        }
                        cVar5 = FUN_005624c0(puVar4);
                        if (cVar5 == '\0') {
                            uVar11 = uVar11 + 1;
                        } else {
                            if (puVar4 != nullptr) {
                                operator_delete__(reinterpret_cast<void*>(*puVar4));
                                operator_delete(puVar4);
                            }
                            iVar8 = param_3[2];
                            param_3[2] = iVar8 + -1;
                            *reinterpret_cast<std::uint32_t*>(*param_3 + uVar11 * 4) = *reinterpret_cast<std::uint32_t*>(*param_3 + (iVar8 + -1) * 4);
                        }
                    } while (uVar11 < static_cast<std::uint32_t>(param_3[2]));
                }
                if (uVar11 == static_cast<std::uint32_t>(param_3[2])) {
                    uVar11 = static_cast<std::uint32_t>(param_3[1]);
                    if (param_3[2] == static_cast<int>(uVar11)) {
                        if (uVar11 == 0) {
                            iVar8 = 1;
                        } else {
                            iVar8 = static_cast<int>(uVar11 * 2);
                        }
                        FUN_0055f300(iVar8);
                    }
                    *reinterpret_cast<int**>(*param_3 + param_3[2] * 4) = piVar6;
                    param_3[2] = param_3[2] + 1;
                }
            }
            local_14 = local_14 + 1;
        } while (local_14 < uVar2);
    }
}
