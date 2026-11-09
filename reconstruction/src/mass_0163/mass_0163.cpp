#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void* p) noexcept;
extern void operator_delete__(void* p) noexcept;
extern void FUN_00567dc0(void* self) noexcept;
extern void* thunk_FUN_00533c78(std::uint32_t size) noexcept;

extern void* PTR_FUN_006c3aa4;
extern void* PTR_FUN_006c3ab4;

// 0x567d00 — observed shape
void FUN_00567d00(void* self, std::uint8_t param_1) noexcept
{
    FUN_00567dc0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x567d20 — observed shape
void FUN_00567d20(void* self, std::uint32_t param_1, std::uint32_t param_2) noexcept
{
    std::uint32_t* v = reinterpret_cast<std::uint32_t*>(self);
    v[1] = param_1;
    *reinterpret_cast<void**>(v) = PTR_FUN_006c3aa4;
    v[2] = 0;
    v[3] = param_2;
    v[4] = 0;
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::intptr_t>(self) + 0x15) = 0;
}

// 0x567d50 — observed shape
void FUN_00567d50(void* self, std::uint8_t param_1) noexcept
{
    std::uint32_t* v = reinterpret_cast<std::uint32_t*>(self);
    *reinterpret_cast<void**>(v) = PTR_FUN_006c3aa4;
    if (v[4] != 0 && *reinterpret_cast<char*>(reinterpret_cast<std::intptr_t>(self) + 0x15) == '\0') {
        operator_delete__(reinterpret_cast<void*>(static_cast<std::uintptr_t>(v[1])));
    }
    FUN_00567dc0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x567d90 — observed shape
void FUN_00567d90(void* self) noexcept
{
    std::uint32_t* v = reinterpret_cast<std::uint32_t*>(self);
    *reinterpret_cast<void**>(v) = PTR_FUN_006c3aa4;
    v[4] = 0x400;
    std::uint32_t uVar1 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(thunk_FUN_00533c78(0x400)));
    v[1] = uVar1;
    v[3] = 0;
    v[2] = 0;
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::intptr_t>(self) + 0x15) = 0;
}

// 0x567dc0 — observed shape
void FUN_00567dc0(void* self) noexcept
{
    *reinterpret_cast<void**>(self) = PTR_FUN_006c3ab4;
}

extern void FUN_00567a60(void) noexcept;
extern void FUN_00567bb0(void) noexcept;
extern char DAT_00728368;
extern std::size_t fwrite(const void* ptr, std::size_t size, std::size_t nmemb, void* stream) noexcept;
extern int fflush(void* stream) noexcept;

typedef int (*ReadFn)(void* param_1, std::uint32_t param_2);
typedef int (*WriteFn)(void* param_1, std::uint32_t param_2);

// 0x567dd0 — observed shape
int FUN_00567dd0(void* self, std::uint8_t* param_1, std::uint32_t param_2) noexcept
{
    std::uint8_t* puVar1 = param_1;
    std::uint32_t uVar3 = 1;
    int iVar5 = 0;
    int iVar4 = 0;
    if (param_2 < 2) {
        *param_1 = 0;
        return 0;
    }
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    void* vtable = *reinterpret_cast<void**>(selfp);
    ReadFn readFn = reinterpret_cast<ReadFn>(*reinterpret_cast<void**>(reinterpret_cast<std::intptr_t>(vtable) + 8));
    do {
        int iVar2 = readFn(&param_1, 1);
        iVar5 = iVar5 + iVar2;
        if ((iVar2 != 1) || ((char)param_1 == '\n')) break;
        if ((char)param_1 != '\r') {
            puVar1[uVar3 - 1] = (char)param_1;
            iVar4 = iVar4 + 1;
            uVar3 = uVar3 + 1;
        }
    } while (uVar3 < param_2);
    puVar1[iVar4] = 0;
    return iVar5;
}

// 0x567e40 — observed shape
int FUN_00567e40(void* self, char* param_1) noexcept
{
    char cVar1 = *param_1;
    int iVar3 = 0;
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    void* vtable = *reinterpret_cast<void**>(selfp);
    WriteFn writeFn = reinterpret_cast<WriteFn>(*reinterpret_cast<void**>(reinterpret_cast<std::intptr_t>(vtable) + 0xc));
    while (true) {
        if (cVar1 == '\0') {
            return iVar3;
        }
        int iVar2 = writeFn(param_1, 1);
        param_1 = param_1 + 1;
        if (iVar2 != 1) break;
        cVar1 = *param_1;
        iVar3 = iVar3 + 1;
    }
    return iVar3;
}

// 0x567e70 — observed shape
void FUN_00567e70(void) noexcept
{
    if (DAT_00728368 == '\0') {
        DAT_00728368 = 1;
        FUN_00567a60();
        return;
    }
    return;
}

// 0x567e90 — observed shape
void FUN_00567e90(void) noexcept
{
    if (DAT_00728368 == '\0') {
        return;
    }
    DAT_00728368 = 0;
    FUN_00567bb0();
    return;
}

// 0x567eb0 — observed shape
void FUN_00567eb0(void* self, char* param_1) noexcept
{
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    void* filePtr = *reinterpret_cast<void**>(selfp + 0x100);
    if (filePtr != nullptr) {
        char* pcVar2 = param_1;
        char cVar1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        fwrite(param_1, 1, static_cast<std::size_t>(pcVar2 - (param_1 + 1)), filePtr);
        if (*reinterpret_cast<char*>(selfp + 0x104) != '\0') {
            fflush(filePtr);
        }
    }
    return;
}

extern void FUN_00567eb0(void* self, char* param_1) noexcept;
extern int sprintf(char* buf, const char* fmt, ...) noexcept;
extern int fclose(void* stream) noexcept;
extern void* PTR_PTR_00717a8c;
extern void FUN_00576640(int a, std::uint32_t b, void* c, void* d, std::uint32_t e, std::uint32_t f) noexcept;
extern void* PTR_FUN_006fe39c;
extern void* DAT_007284e8;
extern void FUN_00538400(void) noexcept;
extern std::uint32_t FUN_00538460(int param_1) noexcept;
extern void* DAT_007286c8;
typedef std::uint32_t (*CmpFn)(void* a, void* b);

// 0x567f00 — observed shape
void FUN_00567f00(void* self) noexcept
{
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    if (*reinterpret_cast<int*>(selfp + 0x100) != 0) {
        FUN_00567eb0(self, "/******************************************************\n");
        char local_100[256];
        sprintf(local_100, "* %s - Log File Closed\n");
        FUN_00567eb0(self, local_100);
        SYSTEMTIME local_110{};
        GetSystemTime(&local_110);
        sprintf(local_100, "*     %02d/%02d/%04d - %2d:%02d:%02d\n",
                static_cast<unsigned>(local_110.wMonth),
                static_cast<unsigned>(local_110.wDay), static_cast<unsigned>(local_110.wYear),
                static_cast<unsigned>(local_110.wHour), static_cast<unsigned>(local_110.wMinute),
                static_cast<unsigned>(local_110.wSecond));
        FUN_00567eb0(self, local_100);
        FUN_00567eb0(self, "******************************************************/\n");
        fclose(*reinterpret_cast<void**>(selfp + 0x100));
    }
    *reinterpret_cast<std::uint32_t*>(selfp + 0x100) = 0;
    return;
}

// 0x568140 — observed shape
void* FUN_00568140(void) noexcept
{
    return PTR_PTR_00717a8c;
}

// 0x5681c0 — observed shape
void FUN_005681c0(void* self, std::uint32_t param_1, std::uint32_t param_2) noexcept
{
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    std::uint32_t local_4 = *reinterpret_cast<std::uint32_t*>(selfp + 0x10);
    FUN_00576640(0, *reinterpret_cast<std::uint32_t*>(selfp + 0x14), &local_4,
                 reinterpret_cast<void*>(selfp + 0xc), param_1, param_2);
    *reinterpret_cast<std::uint32_t*>(selfp + 0x10) = local_4;
    return;
}

// 0x568200 — observed shape
void FUN_00568200(void* self) noexcept
{
    std::uint32_t* v = reinterpret_cast<std::uint32_t*>(self);
    *reinterpret_cast<void**>(v) = PTR_FUN_006fe39c;
    if (v[4] != 0) {
        void* table = reinterpret_cast<void*>(reinterpret_cast<std::intptr_t>(&DAT_007284e8) + v[5] * 4);
        typedef void (*FreeFn)(std::uint32_t);
        FreeFn fn = reinterpret_cast<FreeFn>(*reinterpret_cast<void**>(table));
        fn(v[4]);
    }
    FUN_00538400();
    return;
}

// 0x568270 — observed shape
std::uint32_t FUN_00568270(void* self, int param_1) noexcept
{
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    std::uint32_t uVar2 = FUN_00538460(param_1);
    if ((((char)uVar2 == '\0') || (*reinterpret_cast<int*>(selfp + 0xc) != *reinterpret_cast<int*>(param_1 + 0xc))) ||
        (uVar2 = *reinterpret_cast<std::uint32_t*>(selfp + 0x14), uVar2 != *reinterpret_cast<std::uint32_t*>(param_1 + 0x14))) {
        return uVar2 & 0xffffff00;
    }
    CmpFn pcVar1 = reinterpret_cast<CmpFn>(*reinterpret_cast<void**>(reinterpret_cast<std::intptr_t>(&DAT_007286c8) + uVar2 * 4));
    std::uint32_t uVar3 = 0;
    if (*reinterpret_cast<int*>(selfp + 0xc) != 0) {
        do {
            void* a = reinterpret_cast<void*>(*reinterpret_cast<std::uint8_t*>(*reinterpret_cast<int*>(selfp + 0x10) + 4) * uVar3 + *reinterpret_cast<int*>(selfp + 0x10));
            void* b = reinterpret_cast<void*>(*reinterpret_cast<std::uint8_t*>(*reinterpret_cast<int*>(param_1 + 0x10) + 4) * uVar3 + *reinterpret_cast<int*>(param_1 + 0x10));
            uVar2 = pcVar1(a, b);
            if ((char)uVar2 == '\0') {
                return uVar2 & 0xffffff00;
            }
            uVar2 = *reinterpret_cast<std::uint32_t*>(selfp + 0xc);
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar2);
    }
    return static_cast<std::uint32_t>((uVar2 & 0xffffff00) | 1);
}

extern void FUN_00538430(int param_1) noexcept;
extern std::uint8_t FUN_00552b90(std::uint32_t param_1) noexcept;
extern std::uint8_t FUN_00552bc0(int param_1) noexcept;
extern void* DAT_00728650;

// 0x568370 — observed shape
void FUN_00568370(void* self, int param_1) noexcept
{
    FUN_00538430(param_1);
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(selfp + 0xc);
    {
        std::int32_t stream = *reinterpret_cast<std::int32_t*>(static_cast<std::intptr_t>(param_1) + 0x160);
        void** vt = *reinterpret_cast<void***>(stream);
        typedef void (*WriteFn)(void* dst, std::uint32_t size);
        reinterpret_cast<WriteFn>(vt[3])(piVar1, 4);
    }
    if (*piVar1 != 0) {
        {
            std::int32_t stream = *reinterpret_cast<std::int32_t*>(static_cast<std::intptr_t>(param_1) + 0x160);
            void** vt = *reinterpret_cast<void***>(stream);
            typedef void (*WriteFn)(void* dst, std::uint32_t size);
            reinterpret_cast<WriteFn>(vt[3])(reinterpret_cast<std::int32_t*>(selfp + 0x14), 4);
        }
        typedef void (*DispatchFn)(int param_1, std::uint32_t param_2, std::int32_t param_3);
        DispatchFn fn = reinterpret_cast<DispatchFn>(
            *reinterpret_cast<void**>(reinterpret_cast<std::intptr_t>(&DAT_00728650) +
                                      *reinterpret_cast<std::int32_t*>(selfp + 0x14) * 4));
        fn(param_1, *reinterpret_cast<std::uint32_t*>(selfp + 0x10), *piVar1);
    }
}

// 0x568480 — observed shape
void FUN_00568480(void* self) noexcept
{
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    std::int32_t container = *reinterpret_cast<std::int32_t*>(selfp + 0x48);
    *reinterpret_cast<std::uint32_t*>(selfp + 0x18) = 0x7f7fffff;
    *reinterpret_cast<std::uint32_t*>(selfp + 0x1c) = 0xff7fffff;
    if (container != 0) {
        float* pfVar1 = *reinterpret_cast<float**>(static_cast<std::intptr_t>(container) + 0x10);
        std::int32_t iVar2 = *reinterpret_cast<std::int32_t*>(static_cast<std::intptr_t>(container) + 0xc);
        if (*pfVar1 < 3.4028235e+38f) {
            *reinterpret_cast<float*>(selfp + 0x18) = *pfVar1;
        }
        std::int32_t off = static_cast<std::int32_t>(static_cast<std::uint32_t>(
                               *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::intptr_t>(pfVar1) + 4)) *
                           (iVar2 - 1));
        float last = *reinterpret_cast<float*>(reinterpret_cast<std::intptr_t>(pfVar1) + off);
        if (-3.4028235e+38f < last) {
            *reinterpret_cast<float*>(selfp + 0x1c) = last;
        }
    }
}

// 0x5684e0 — observed shape
std::uint8_t FUN_005684e0(void* self, std::uint32_t param_1) noexcept
{
    std::uint8_t cVar1 = FUN_00552b90(param_1);
    if (cVar1 == 0) {
        return 0;
    }
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    std::int32_t* obj = *reinterpret_cast<std::int32_t**>(selfp + 0x48);
    if (obj != nullptr) {
        void** vt = *reinterpret_cast<void***>(obj);
        typedef void (*LoadFn)(std::uint32_t param_1);
        reinterpret_cast<LoadFn>(vt[5])(param_1);
    }
    return 1;
}

// 0x568510 — observed shape
bool FUN_00568510(void* self, int param_1) noexcept
{
    std::uint8_t cVar1 = FUN_00552bc0(param_1);
    if (cVar1 == 0) {
        return false;
    }
    std::intptr_t selfp = reinterpret_cast<std::intptr_t>(self);
    std::int32_t* obj = *reinterpret_cast<std::int32_t**>(selfp + 0x48);
    void** vt = *reinterpret_cast<void***>(obj);
    typedef std::uint8_t (*MatchFn)(std::uint32_t param_1);
    cVar1 = reinterpret_cast<MatchFn>(vt[7])(*reinterpret_cast<std::uint32_t*>(
        static_cast<std::intptr_t>(param_1) + 0x48));
    return cVar1 != 0;
}

// 0x568540 — observed shape
std::uint32_t FUN_00568540(void* self, float param_1) noexcept
{
    std::int32_t* in_ECX = reinterpret_cast<std::int32_t*>(self);
    std::uint32_t uVar2 = static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(
                              reinterpret_cast<std::intptr_t>(in_ECX) + 0xc)) >> 3;
    if ((static_cast<std::uint8_t>(uVar2) & 1) != 0) {
        float fVar1 = static_cast<float>(in_ECX[9]);
        if ((fVar1 != param_1) ||
            (*reinterpret_cast<char*>(reinterpret_cast<std::intptr_t>(in_ECX) + 0x40) != '\0')) {
            if (*reinterpret_cast<char*>(reinterpret_cast<std::intptr_t>(in_ECX) + 0x30) != '\0') {
                typedef float (*EvalFn)(float param_1);
                void** vt = *reinterpret_cast<void***>(in_ECX);
                float fVar3 = reinterpret_cast<EvalFn>(vt[0x13])(param_1);
                float fVar4 = static_cast<float>(in_ECX[0xb]);
                if (fVar4 == fVar3 &&
                    *reinterpret_cast<char*>(reinterpret_cast<std::intptr_t>(in_ECX) + 0x40) == '\0') {
                    return 1;
                }
                in_ECX[0xb] = static_cast<std::int32_t>(fVar3);
            }
            *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::intptr_t>(in_ECX) + 0x40) = 0;
            return 0;
        }
    }
    return 1;
}
