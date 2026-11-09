// UNVERIFIED: no compiler run for this batch. Clean-room reconstruction from
// Ghidra 12.2 pseudocode (analysis profile 59fe0f4e...). No PASS claim.
// Bundled libpng 1.1.4 reader: chunk dispatch, row read, accessors, teardown.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- referenced helpers (declared extern, addresses from the listings) ----
extern int setjmp3(void* env, int arg);
extern void FUN_006565bf(void* png, uint32_t a, uint32_t b, uint32_t c);
extern void FUN_006565dd(void* png, const char* msg);   // noreturn error handler
extern void FUN_006565fe(void* png, const char* msg);   // noreturn error handler
extern int FUN_00656662(const void* buf, uint32_t start, int count);
extern void FUN_006566b0(void* png, int32_t n, int32_t stride);
extern void FUN_00656706(void* png, void* ptr);
extern void FUN_00656711(void* png);
extern void FUN_0065676f(void* png, void* ptr);
extern void FUN_0065755e(void* png, uint32_t arg);
extern uint32_t FUN_006573aa(int param_1);   // defined at 0x6573aa below
extern void FUN_0065893b(void* png);
extern void FUN_00658adc(void* png, void* dst, int len);
extern void FUN_00658b08(void* png, uint32_t a, uint32_t b);
extern int FUN_00692491(int kind);
extern void FUN_006924d9(void* png);
extern void* FUN_006924f1(void* png, uint32_t size);
extern void FUN_0069252a(void* png, void* ptr);
extern void FUN_00692548(void* png, uint32_t w, uint32_t h, int rowbytes);
extern void FUN_00693109(void* p);
extern int FUN_00693225(void* z, const char* version, int size);
extern int FUN_0069323b(void* z, int flush);
extern uint32_t FUN_0069359e(const void* p);
extern void FUN_006935e2(void* png, void* dst, int len);
extern void FUN_006936bf(void* png, void* row, uint32_t value);
extern void FUN_006938d7(void* row_info, int width, uint8_t color_type, uint32_t flags);
extern void FUN_00693ba4(void* png, void* row_info, void* row, int width, uint8_t color_type);
extern void FUN_00693d1d(void* png);
extern void FUN_00693ebc(void* png, uint32_t remaining);
extern void FUN_00693f45(void* png, void* chunk, uint32_t len);
extern void FUN_00694127(void* png, void* chunk, uint32_t len);
extern void FUN_00694242(void* png, void* chunk, uint32_t len);
extern void FUN_0069428a(void* png, void* chunk, uint32_t len);
extern void FUN_0069438d(void* png, void* chunk, uint32_t len);
extern void FUN_00694471(void* png, void* chunk, uint32_t len);
extern void FUN_00694605(void* png, void* chunk, uint32_t len);
extern void FUN_0069464e(void* png);

// ---- referenced globals ----
extern uint32_t DAT_006edc14;   // gamma table, per color type
extern uint32_t DAT_006edc30;   // chromaticity table, per color type

// 0x6568f5 — observed shape
void FUN_006568f5(int param_1, int param_2, int param_3, int param_4, uint32_t* param_5)
{
    if (param_1 != 0 && param_2 != 0) {
        if (param_3 != 0) {
            *(int*)(param_2 + 0x30) = param_3;
        }
        if (param_5 != nullptr) {
            *(uint32_t*)(param_2 + 0x34) = *param_5;
            *(uint32_t*)(param_2 + 0x38) = param_5[1];
            *(uint16_t*)(param_2 + 0x3c) = *(uint16_t*)(param_5 + 2);
            if (param_4 == 0) {
                param_4 = 1;
            }
        }
        *(uint32_t*)(param_2 + 8) = *(uint32_t*)(param_2 + 8) | 0x10;
        *(uint16_t*)(param_2 + 0x16) = (uint16_t)param_4;
    }
}

// 0x656940 — observed shape
int FUN_00656940(char* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    int iVar1;
    int iVar2;
    void* uVar3;
    const char* pcVar4;

    iVar1 = FUN_00692491(1);
    if (iVar1 != 0) {
        iVar2 = setjmp3((void*)iVar1, 0);
        if (iVar2 == 0) {
            FUN_006565bf((void*)iVar1, param_2, param_3, param_4);
            if (param_1 == nullptr || *param_1 != '1') {
                FUN_006565dd((void*)iVar1,
                             "Incompatible libpng version in application and library");
            }
            *(uint32_t*)(iVar1 + 0xa0) = 0x2000;
            uVar3 = FUN_006924f1((void*)iVar1, 0x2000);
            *(void**)(iVar1 + 0x9c) = uVar3;
            *(void**)(iVar1 + 0x84) = (void*)&FUN_006566b0;
            *(void**)(iVar1 + 0x88) = (void*)&FUN_00656706;
            *(int*)(iVar1 + 0x8c) = iVar1;
            iVar2 = FUN_00693225((void*)(iVar1 + 100), "1.1.4", 0x38);
            if (iVar2 == -6) {
                pcVar4 = "zlib version error";
            }
            else if (iVar2 == -4 || iVar2 == -2) {
                pcVar4 = "zlib memory error";
            }
            else {
                if (iVar2 == 0) {
                    *(uint32_t*)(iVar1 + 0x70) = *(uint32_t*)(iVar1 + 0x9c);
                    *(uint32_t*)(iVar1 + 0x74) = *(uint32_t*)(iVar1 + 0xa0);
                    FUN_00658b08((void*)iVar1, 0, 0);
                    return iVar1;
                }
                pcVar4 = "Unknown zlib error";
            }
            FUN_006565dd((void*)iVar1, pcVar4);
        }
        FUN_0069252a((void*)iVar1, *(void**)(iVar1 + 0x9c));
        FUN_006924d9((void*)iVar1);
    }
    return 0;
}

// 0x656a36 — observed shape
void FUN_00656a36(int param_1, int param_2)
{
    int* piVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    int iVar5;
    const char* pcVar6;

    iVar2 = param_1;
    if (7 < *(uint8_t*)(param_1 + 0x11c)) {
        goto LAB_00656aa7;
    }
    uVar4 = (uint32_t)*(uint8_t*)(param_1 + 0x11c);
    iVar5 = -(int)uVar4 + 8;
    FUN_00658adc((void*)param_1, (void*)(param_2 + 0x20 + uVar4), iVar5);
    *(uint8_t*)(iVar2 + 0x11c) = 8;
    iVar5 = FUN_00656662((void*)(param_2 + 0x20), uVar4, iVar5);
    if (iVar5 != 0) {
        if (uVar4 < 4) {
            iVar5 = FUN_00656662((void*)(param_2 + 0x20), uVar4, -(int)uVar4 + 4);
            if (iVar5 != 0) {
                pcVar6 = "Not a PNG file";
                goto LAB_00656aa1;
            }
        }
        pcVar6 = "PNG file corrupted by ASCII conversion";
LAB_00656aa1:
        FUN_006565dd((void*)iVar2, pcVar6);
    }

LAB_00656aa7:
    piVar1 = (int*)(iVar2 + 0x10c);
    while (true) {
        while (true) {
            while (true) {
                while (true) {
                    FUN_00658adc((void*)iVar2, &param_1, 4);
                    uVar3 = FUN_0069359e(&param_1);
                    FUN_00656711((void*)iVar2);
                    FUN_006935e2((void*)iVar2, piVar1, 4);
                    if (*piVar1 != 0x52444849) break;   // "IHDR"
                    FUN_00693f45((void*)iVar2, (void*)param_2, uVar3);
                }
                if (*piVar1 != 0x45544c50) break;       // "PLTE"
                FUN_00694127((void*)iVar2, (void*)param_2, uVar3);
            }
            if (*piVar1 != 0x444e4549) break;           // "IEND"
            FUN_00694242((void*)iVar2, (void*)param_2, uVar3);
        }
        if (*piVar1 == 0x54414449) break;               // "IDAT"
        if (*piVar1 == 0x414d4167) {                    // "gAMA"
            FUN_0069428a((void*)iVar2, (void*)param_2, uVar3);
        }
        else if (*piVar1 == 0x42475273) {               // "sRGB"
            FUN_0069438d((void*)iVar2, (void*)param_2, uVar3);
        }
        else if (*piVar1 == 0x534e5274) {               // "tRNS"
            FUN_00694471((void*)iVar2, (void*)param_2, uVar3);
        }
        else {
            FUN_00694605((void*)iVar2, (void*)param_2, uVar3);
        }
    }
    if ((*(uint32_t*)(iVar2 + 0x58) & 1) == 0) {
        pcVar6 = "Missing IHDR before IDAT";
    }
    else {
        if (*(char*)(iVar2 + 0x116) != '\x03' || (*(uint32_t*)(iVar2 + 0x58) & 2) != 0) {
            *(uint32_t*)(iVar2 + 0x58) = *(uint32_t*)(iVar2 + 0x58) | 4;
            *(uint32_t*)(iVar2 + 0xfc) = uVar3;
            return;
        }
        pcVar6 = "Missing PLTE before IDAT";
    }
    FUN_006565dd((void*)iVar2, pcVar6);
}

// 0x656ba6 — observed shape
void FUN_00656ba6(int param_1, uint32_t param_2)
{
    if ((*(uint8_t*)(param_1 + 0x5c) & 0x40) == 0) {
        FUN_00693d1d((void*)param_1);
    }
    FUN_0065755e((void*)param_1, param_2);
}

// 0x656bc9 — observed shape
void FUN_00656bc9(int param_1, int param_2, int param_3)
{
    int* piVar1;
    char cVar2;
    int iVar3;
    uint32_t uVar4;
    int iVar5;
    const char* pcVar6;
    bool bVar7;

    iVar3 = param_1;
    if ((*(uint8_t*)(param_1 + 0x5c) & 0x40) == 0) {
        FUN_00693d1d((void*)param_1);
    }
    if (*(char*)(iVar3 + 0x113) != '\0' && (*(uint8_t*)(iVar3 + 0x60) & 2) != 0) {
        cVar2 = *(char*)(iVar3 + 0x114);
        if (cVar2 == '\0') {
            if ((*(uint8_t*)(iVar3 + 0xd4) & 7) != 0) {
                bVar7 = param_3 == 0;
LAB_00656cdb:
                if (bVar7) goto LAB_00656c32;
                uVar4 = 0xff;
LAB_00656ce6:
                FUN_006936bf((void*)iVar3, (void*)param_3, uVar4);
LAB_00656c32:
                FUN_0069464e((void*)iVar3);
                return;
            }
        }
        else if (cVar2 == '\x01') {
            if ((*(uint8_t*)(iVar3 + 0xd4) & 7) != 0 || *(uint32_t*)(iVar3 + 0xb8) < 5) {
                if (param_3 == 0) goto LAB_00656c32;
                uVar4 = 0xf;
                goto LAB_00656ce6;
            }
        }
        else if (cVar2 == '\x02') {
            if ((*(uint8_t*)(iVar3 + 0xd4) & 7) != 4) {
                if (param_3 == 0) goto LAB_00656c32;
                bVar7 = (*(uint32_t*)(iVar3 + 0xd4) & 4) == 0;
                goto LAB_00656cdb;
            }
        }
        else if (cVar2 == '\x03') {
            if ((*(uint8_t*)(iVar3 + 0xd4) & 3) != 0 || *(uint32_t*)(iVar3 + 0xb8) < 3) {
                if (param_3 == 0) goto LAB_00656c32;
                uVar4 = 0x33;
                goto LAB_00656ce6;
            }
        }
        else if (cVar2 == '\x04') {
            if ((*(uint8_t*)(iVar3 + 0xd4) & 3) != 2) {
                if (param_3 == 0) goto LAB_00656c32;
                bVar7 = (*(uint32_t*)(iVar3 + 0xd4) & 2) == 0;
                goto LAB_00656cdb;
            }
        }
        else if (cVar2 == '\x05') {
            if ((*(uint8_t*)(iVar3 + 0xd4) & 1) != 0 || *(uint32_t*)(iVar3 + 0xb8) < 2) {
                if (param_3 == 0) goto LAB_00656c32;
                uVar4 = 0x55;
                goto LAB_00656ce6;
            }
        }
        else if (cVar2 == '\x06' && (*(uint8_t*)(iVar3 + 0xd4) & 1) == 0) {
            goto LAB_00656c32;
        }
    }
    if ((*(uint8_t*)(iVar3 + 0x58) & 4) == 0) {
        FUN_006565dd((void*)iVar3, "Invalid attempt to read row data");
    }
    *(uint32_t*)(iVar3 + 0x70) = *(uint32_t*)(iVar3 + 0xdc);
    *(uint32_t*)(iVar3 + 0x74) = *(uint32_t*)(iVar3 + 0xcc);
    do {
        if (*(int*)(iVar3 + 0x68) == 0) {
            if (*(int*)(iVar3 + 0xfc) == 0) {
                do {
                    FUN_00693ebc((void*)iVar3, 0);
                    FUN_00658adc((void*)iVar3, &param_1, 4);
                    uVar4 = FUN_0069359e(&param_1);
                    *(uint32_t*)(iVar3 + 0xfc) = uVar4;
                    FUN_00656711((void*)iVar3);
                    FUN_006935e2((void*)iVar3, (void*)(iVar3 + 0x10c), 4);
                    if (*(int*)(iVar3 + 0x10c) != 0x54414449) {   // "IDAT"
                        FUN_006565dd((void*)iVar3, "Not enough image data");
                    }
                } while (*(int*)(iVar3 + 0xfc) == 0);
            }
            *(uint32_t*)(iVar3 + 0x68) = *(uint32_t*)(iVar3 + 0xa0);
            *(uint32_t*)(iVar3 + 100) = *(uint32_t*)(iVar3 + 0x9c);
            if (*(uint32_t*)(iVar3 + 0xfc) < *(uint32_t*)(iVar3 + 0xa0)) {
                *(uint32_t*)(iVar3 + 0x68) = *(uint32_t*)(iVar3 + 0xfc);
            }
            FUN_006935e2((void*)iVar3, *(void**)(iVar3 + 0x9c), *(int*)(iVar3 + 0x68));
            *(int*)(iVar3 + 0xfc) = *(int*)(iVar3 + 0xfc) - *(int*)(iVar3 + 0x68);
        }
        iVar5 = FUN_0069323b((void*)(iVar3 + 100), 1);
        if (iVar5 == 1) {
            if (*(int*)(iVar3 + 0x74) != 0 || *(int*)(iVar3 + 0x68) != 0 ||
                *(int*)(iVar3 + 0xfc) != 0) {
                FUN_006565dd((void*)iVar3, "Extra compressed data");
            }
            *(uint32_t*)(iVar3 + 0x58) = *(uint32_t*)(iVar3 + 0x58) | 8;
            *(uint32_t*)(iVar3 + 0x5c) = *(uint32_t*)(iVar3 + 0x5c) | 0x20;
            break;
        }
        if (iVar5 != 0) {
            pcVar6 = *(const char**)(iVar3 + 0x7c);
            if (pcVar6 == nullptr) {
                pcVar6 = "Decompression error";
            }
            FUN_006565dd((void*)iVar3, pcVar6);
        }
    } while (*(int*)(iVar3 + 0x74) != 0);
    *(uint8_t*)(iVar3 + 0xfa) = *(uint8_t*)(iVar3 + 0x11a);
    *(uint8_t*)(iVar3 + 0xf9) = *(uint8_t*)(iVar3 + 0x117);
    *(uint8_t*)(iVar3 + 0xfb) = *(uint8_t*)(iVar3 + 0x119);
    *(uint8_t*)(iVar3 + 0xf8) = *(uint8_t*)(iVar3 + 0x116);
    piVar1 = (int*)(iVar3 + 0xf0);
    *piVar1 = *(int*)(iVar3 + 0xd0);
    *(uint32_t*)(iVar3 + 0xf4) =
        (uint32_t)*(uint8_t*)(iVar3 + 0x119) * *(int*)(iVar3 + 0xd0) + 7 >> 3;
    FUN_00693ba4((void*)iVar3, piVar1, (void*)(*(uint8_t**)(iVar3 + 0xdc) + 1),
                 *(int*)(iVar3 + 0xd8) + 1, **(uint8_t**)(iVar3 + 0xdc));
    FUN_00692548((void*)iVar3, *(uint32_t*)(iVar3 + 0xd8), *(uint32_t*)(iVar3 + 0xdc),
                 *(int*)(iVar3 + 200) + 1);
    if (*(int*)(iVar3 + 0x60) != 0) {
        FUN_0065893b((void*)iVar3);
    }
    if (*(char*)(iVar3 + 0x113) == '\0' || (*(uint32_t*)(iVar3 + 0x60) & 2) == 0) {
        if (param_2 != 0) {
            FUN_006936bf((void*)iVar3, (void*)param_2, 0xff);
        }
        if (param_3 == 0) goto LAB_00656f23;
        uVar4 = 0xff;
        iVar5 = param_3;
    }
    else {
        if (*(uint8_t*)(iVar3 + 0x114) < 6) {
            FUN_006938d7(piVar1, *(int*)(iVar3 + 0xdc) + 1, *(uint8_t*)(iVar3 + 0x114),
                         *(uint32_t*)(iVar3 + 0x60));
        }
        if (param_3 != 0) {
            FUN_006936bf((void*)iVar3, (void*)param_3,
                         *(uint32_t*)((char*)&DAT_006edc30 +
                                      (uint32_t)*(uint8_t*)(iVar3 + 0x114) * 4));
        }
        if (param_2 == 0) goto LAB_00656f23;
        uVar4 = *(uint32_t*)((char*)&DAT_006edc14 +
                             (uint32_t)*(uint8_t*)(iVar3 + 0x114) * 4);
        iVar5 = param_2;
    }
    FUN_006936bf((void*)iVar3, (void*)iVar5, uVar4);
LAB_00656f23:
    FUN_0069464e((void*)iVar3);
    if (*(void**)(iVar3 + 0x16c) != nullptr) {
        reinterpret_cast<void (*)(int, uint32_t, uint8_t)>(*(void**)(iVar3 + 0x16c))(
            iVar3, *(uint32_t*)(iVar3 + 0xd4), *(uint8_t*)(iVar3 + 0x114));
    }
}

// 0x656f4e — observed shape
void FUN_00656f4e(int param_1, uint32_t* param_2)
{
    int iVar1;
    int iVar2;
    uint32_t* puVar3;
    int local_8;
    int remaining;

    iVar2 = param_1;
    local_8 = (int)FUN_006573aa(param_1);
    iVar1 = *(int*)(param_1 + 0xbc);
    *(int*)(param_1 + 0xc0) = iVar1;
    if (0 < local_8) {
        do {
            if (iVar1 != 0) {
                puVar3 = param_2;
                remaining = iVar1;
                do {
                    FUN_00656bc9(iVar2, (int)*puVar3, 0);
                    puVar3 = puVar3 + 1;
                    remaining = remaining + -1;
                } while (remaining != 0);
            }
            local_8 = local_8 + -1;
        } while (local_8 != 0);
    }
}

// 0x656f9b — observed shape
void FUN_00656f9b(uint32_t* param_1, int param_2, int param_3)
{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t* puVar5;
    int iVar6;
    uint32_t* puVar7;
    uint32_t local_44[16];

    iVar6 = 0;
    if (param_2 != 0) {
        FUN_0065676f(param_1, (void*)param_2);
    }
    if (param_3 != 0) {
        FUN_0065676f(param_1, (void*)param_3);
    }
    FUN_0069252a(param_1, (void*)param_1[0x27]);
    FUN_0069252a(param_1, (void*)param_1[0x37]);
    FUN_0069252a(param_1, (void*)param_1[0x36]);
    FUN_0069252a(param_1, (void*)param_1[0x5d]);
    FUN_0069252a(param_1, (void*)param_1[0x5e]);
    FUN_0069252a(param_1, (void*)param_1[0x4e]);
    if ((*(uint8_t*)((char*)param_1 + 0x5d) & 0x10) != 0) {
        FUN_00656706(param_1, (void*)param_1[0x41]);
    }
    if ((*(uint8_t*)((char*)param_1 + 0x5d) & 0x20) != 0) {
        FUN_0069252a(param_1, (void*)param_1[0x57]);
    }
    if (param_1[0x51] != 0) {
        iVar4 = 1 << ((8U - (char)param_1[0x4b]) & 0x1f);
        if (0 < iVar4) {
            do {
                FUN_0069252a(param_1, (void*)*(uint32_t*)(param_1[0x51] + iVar6 * 4));
                iVar6 = iVar6 + 1;
            } while (iVar6 < iVar4);
        }
        FUN_0069252a(param_1, (void*)param_1[0x51]);
    }
    FUN_00693109((void*)(param_1 + 0x19));
    uVar1 = param_1[0x12];
    uVar2 = param_1[0x10];
    iVar4 = 0x67;
    puVar5 = param_1;
    puVar7 = local_44;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
    }
    uVar3 = param_1[0x11];
    puVar5 = param_1;
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
    }
    param_1[0x11] = uVar3;
    puVar5 = local_44;
    puVar7 = param_1;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
    }
    param_1[0x10] = uVar2;
    param_1[0x12] = uVar1;
}

// 0x6570b2 — observed shape
void FUN_006570b2(int* param_1, int* param_2, int* param_3)
{
    int iVar1;
    int local_c;
    int local_8;

    iVar1 = 0;
    local_8 = 0;
    local_c = 0;
    if (param_1 != nullptr) {
        local_8 = *param_1;
    }
    if (param_2 != nullptr) {
        iVar1 = *param_2;
    }
    if (param_3 != nullptr) {
        local_c = *param_3;
    }
    if (local_8 != 0) {
        FUN_00656f9b((uint32_t*)local_8, iVar1, local_c);
    }
    if (iVar1 != 0) {
        FUN_006924d9((void*)iVar1);
        *param_2 = 0;
    }
    if (local_c != 0) {
        FUN_006924d9((void*)local_c);
        *param_3 = 0;
    }
    if (local_8 != 0) {
        FUN_006924d9((void*)local_8);
        *param_1 = 0;
    }
}

// 0x657131 — observed shape
uint32_t FUN_00657131(int param_1, int param_2, uint32_t param_3)
{
    if (param_1 == 0 || param_2 == 0) {
        param_3 = 0;
    }
    else {
        param_3 = *(uint32_t*)(param_2 + 8) & param_3;
    }
    return param_3;
}

// 0x657151 — observed shape
uint32_t FUN_00657151(int param_1, int param_2)
{
    uint32_t uVar1;

    if (param_1 == 0 || param_2 == 0) {
        uVar1 = 0;
    }
    else {
        uVar1 = *(uint32_t*)(param_2 + 0xc);
    }
    return uVar1;
}

// 0x65716e — observed shape
uint8_t FUN_0065716e(int param_1, int param_2)
{
    uint8_t uVar1;

    if (param_1 == 0 || param_2 == 0) {
        uVar1 = 0;
    }
    else {
        uVar1 = *(uint8_t*)(param_2 + 0x1d);
    }
    return uVar1;
}

// 0x65718b — observed shape
uint32_t FUN_0065718b(int param_1, int param_2, double* param_3)
{
    uint32_t uVar1;

    if (param_1 == 0 || param_2 == 0 || (*(uint8_t*)(param_2 + 8) & 1) == 0 ||
        param_3 == nullptr) {
        uVar1 = 0;
    }
    else {
        *param_3 = (double)*(float*)(param_2 + 0x28);
        uVar1 = 1;
    }
    return uVar1;
}

// 0x6571ba — observed shape
uint32_t FUN_006571ba(int param_1, int param_2, uint32_t* param_3)
{
    uint32_t uVar1;

    if (param_1 == 0 || param_2 == 0 || (*(uint32_t*)(param_2 + 8) & 0x800) == 0 ||
        param_3 == nullptr) {
        uVar1 = 0;
    }
    else {
        *param_3 = (uint32_t)*(uint8_t*)(param_2 + 0x2c);
        uVar1 = 0x800;
    }
    return uVar1;
}

// 0x6571eb — observed shape
uint32_t FUN_006571eb(int param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4,
                      uint32_t* param_5, uint32_t* param_6, uint32_t* param_7,
                      uint32_t* param_8, uint32_t* param_9)
{
    uint32_t uVar1;
    uint32_t uVar2;

    if (param_1 == 0 || param_2 == nullptr || param_3 == nullptr || param_4 == nullptr ||
        param_5 == nullptr || param_6 == nullptr) {
        return 0;
    }
    *param_3 = *param_2;
    *param_4 = param_2[1];
    *param_5 = (uint32_t)(uint8_t)param_2[6];
    *param_6 = (uint32_t)*(uint8_t*)((char*)param_2 + 0x19);
    if (param_8 != nullptr) {
        *param_8 = (uint32_t)*(uint8_t*)((char*)param_2 + 0x1a);
    }
    if (param_9 != nullptr) {
        *param_9 = (uint32_t)*(uint8_t*)((char*)param_2 + 0x1b);
    }
    if (param_7 != nullptr) {
        *param_7 = (uint32_t)(uint8_t)param_2[7];
    }
    uVar1 = *param_6;
    if (uVar1 == 3) {
        uVar2 = 1;
    }
    else {
        uVar2 = ((uint32_t)(int)(char)uVar1 & 2U) | 1;
    }
    if ((uVar1 & 4) != 0) {
        uVar2 = uVar2 + 1;
    }
    if ((uint32_t)(0x7fffffffu / (uint32_t)((int)(*param_5 * uVar2 + 7) >> 3)) < *param_3) {
        FUN_006565fe((void*)param_1, "Width too large for libpng to process image data.");
    }
    return 1;
}

// 0x6572be — observed shape
uint32_t FUN_006572be(int param_1, int param_2, uint32_t* param_3, uint32_t* param_4)
{
    uint32_t uVar1;

    if (param_1 == 0 || param_2 == 0 || (*(uint8_t*)(param_2 + 8) & 8) == 0 ||
        param_3 == nullptr) {
        uVar1 = 0;
    }
    else {
        *param_3 = *(uint32_t*)(param_2 + 0x10);
        *param_4 = (uint32_t)*(uint16_t*)(param_2 + 0x14);
        uVar1 = 8;
    }
    return uVar1;
}

// 0x6572f6 — observed shape
uint32_t FUN_006572f6(int param_1, int param_2, uint32_t* param_3, uint32_t* param_4,
                      int* param_5)
{
    uint32_t uVar1;

    uVar1 = 0;
    if (param_1 != 0 && param_2 != 0 && (*(uint8_t*)(param_2 + 8) & 0x10) != 0) {
        if (*(char*)(param_2 + 0x19) == '\x03') {
            if (param_3 != nullptr) {
                *param_3 = *(uint32_t*)(param_2 + 0x30);
                uVar1 = 0x10;
            }
            if (param_5 != nullptr) {
                *param_5 = param_2 + 0x34;
            }
        }
        else {
            if (param_5 != nullptr) {
                *param_5 = param_2 + 0x34;
                uVar1 = 0x10;
            }
            if (param_3 != nullptr) {
                *param_3 = 0;
            }
        }
        if (param_4 != nullptr) {
            *param_4 = (uint32_t)*(uint16_t*)(param_2 + 0x16);
            uVar1 = 0x10;
        }
    }
    return uVar1;
}

// 0x657371 — observed shape
void FUN_00657371(int param_1)
{
    if (*(char*)(param_1 + 0x117) == '\x10') {
        *(uint32_t*)(param_1 + 0x60) = *(uint32_t*)(param_1 + 0x60) | 0x10;
    }
}

// 0x65738a — observed shape
void FUN_0065738a(int param_1)
{
    if (*(uint8_t*)(param_1 + 0x117) < 8) {
        *(uint32_t*)(param_1 + 0x60) = *(uint32_t*)(param_1 + 0x60) | 4;
        *(uint8_t*)(param_1 + 0x118) = 8;
    }
}

// 0x6573aa — observed shape
uint32_t FUN_006573aa(int param_1)
{
    uint32_t uVar1;

    if (*(char*)(param_1 + 0x113) == '\0') {
        uVar1 = 1;
    }
    else {
        *(uint32_t*)(param_1 + 0x60) = *(uint32_t*)(param_1 + 0x60) | 2;
        uVar1 = 7;
    }
    return uVar1;
}

// 0x6573cb — observed shape
void FUN_006573cb(int param_1, uint8_t param_2, int param_3)
{
    *(uint8_t*)(param_1 + 0x61) = *(uint8_t*)(param_1 + 0x61) | 0x80;
    *(uint16_t*)(param_1 + 0x11e) = (uint16_t)param_2;
    if (param_3 == 1) {
        *(uint8_t*)(param_1 + 0x5c) = *(uint8_t*)(param_1 + 0x5c) | 0x80;
    }
    else {
        *(uint8_t*)(param_1 + 0x5c) = *(uint8_t*)(param_1 + 0x5c) & 0x7f;
    }
    if (*(char*)(param_1 + 0x116) == '\x02') {
        *(uint8_t*)(param_1 + 0x11b) = 4;
    }
    if (*(char*)(param_1 + 0x116) == '\0' && 7 < *(uint8_t*)(param_1 + 0x117)) {
        *(uint8_t*)(param_1 + 0x11b) = 2;
    }
}
