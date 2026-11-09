#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <windows.h>

// Extern helpers (non-assigned callees and runtime helpers).
extern void FUN_004f3350(void* self);
extern void FUN_004f4de0(void* self);
extern void FUN_004f0dc0(void* self);
extern void operator_delete__(void* ptr);
extern void operator_delete(void* ptr);
extern int32_t FUN_00412810(void);
extern int32_t FUN_004289d0(void);
extern int32_t FUN_004db210(void);
extern int32_t FUN_00412950(void);
extern uint16_t FUN_0045b5d0(void);
extern void FUN_0044d140(int32_t a, int32_t b, int32_t c);
extern char* builtin_strncpy(char* dst, const char* src, size_t n);

// Forward prototypes for assigned callees defined below.
void FUN_00412f90(int32_t* self);
void FUN_00412f10(int32_t* self, char* src);
void FUN_00413080(int32_t index);
void FUN_00413400(int32_t index);
void FUN_00413430(int32_t param_1);
int32_t FUN_004135d0(int32_t edxParam);

// Extern globals referenced by the supplied listings.
extern uint8_t DAT_008cacd0[];
extern uint8_t DAT_008cacc8[];
extern uint8_t PTR_FUN_006f583c[];
extern uint8_t PTR_FUN_006f5864[];
extern HCURSOR DAT_008cacd8;
extern uint8_t DAT_00007f02[];
extern uint8_t DAT_008142f8[];
extern uint8_t DAT_008142fa[];
extern uint8_t DAT_008142fc[];
extern uint8_t DAT_00814304[];
extern uint8_t DAT_00814308[];
extern uint8_t DAT_0081430c[];
extern uint8_t DAT_00814310[];
extern uint8_t DAT_0081431e[];
extern uint8_t DAT_00814320[];
extern uint8_t DAT_00814322[];
extern uint8_t DAT_00814324[];
extern uint8_t DAT_00814326[];
extern uint8_t DAT_00814328[];
extern uint8_t DAT_0081432a[];
extern uint8_t DAT_0081432c[];
extern uint8_t DAT_0081432e[];
extern uint8_t DAT_00814330[];
extern uint8_t DAT_00814332[];
extern uint8_t DAT_00814336[];
extern uint8_t DAT_00814338[];
extern uint8_t DAT_0081433c[];
extern uint8_t DAT_00814340[];
extern uint8_t DAT_00814344[];
extern uint8_t DAT_00814350[];
extern uint8_t DAT_00814354[];
extern uint8_t DAT_0081435a[];
extern uint8_t DAT_008165d8[];
extern uint8_t DAT_008165de[];
extern uint8_t DAT_00813ecc[];
extern uint8_t DAT_007252f0[];
extern uint8_t DAT_007252d0[];
extern uint8_t DAT_007252d1[];
extern uint8_t DAT_00725350[];
extern uint8_t DAT_00723b08[];
extern uint8_t DAT_00723b0c[];
extern uint8_t DAT_00723b14[];
extern uint8_t DAT_00723b18[];
extern uint8_t DAT_00723b1c[];
extern uint8_t DAT_00723b10[];
extern uint8_t DAT_007b10a0[];
extern int32_t DAT_0085a150;
extern int32_t DAT_00861b74;
extern int32_t DAT_00876be0;
extern uint8_t DAT_00859ef8[];
extern uint8_t DAT_00860b68[];
extern uint8_t DAT_00860b6c[];
extern uint8_t DAT_00860b70[];
extern uint8_t DAT_00860b74[];
extern uint8_t DAT_00860b75[];
extern uint8_t DAT_00860b76[];
extern uint8_t DAT_00860b7c[];
extern uint8_t DAT_0085b170[];
extern uint8_t DAT_0085b174[];
extern uint8_t DAT_0085bff6[];
extern uint8_t DAT_0085bf7e[];
extern uint8_t DAT_0085bfb6[];
extern uint8_t DAT_0085bf7c[];
extern uint8_t DAT_0085a168[];
extern uint8_t DAT_0085a970[];
extern uint8_t DAT_008db618[];
extern uint8_t DAT_008db61c[];
extern uint8_t DAT_008d8918[];
extern uint8_t DAT_008d891c[];
extern uint8_t DAT_008d8920[];
extern int32_t DAT_007267c8;
extern int32_t DAT_007267cc;

// 0x412c50 — observed shape
uint32_t FUN_00412c50(void* self) {
    int32_t* i = reinterpret_cast<int32_t*>(self);
    if (i[8] != 1) {
        int32_t iVar1;
        if (i[11] == 0) {
            iVar1 = i[9];
        } else {
            int32_t* base = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(i[11])));
            iVar1 = base[6];
        }
        return static_cast<uint32_t>(iVar1 - i[16]) / static_cast<uint32_t>((i[12] != 0) + 1);
    }
    if (i[12] == 0) {
        return reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(i[13])))[-1];
    }
    return reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(i[14])))[-1];
}

// 0x412cb0 — observed shape
void FUN_00412cb0(int32_t* self, char* src) {
    *self = static_cast<int32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
    if (src != nullptr) {
        char* pc = src;
        char c;
        do {
            c = *pc;
            ++pc;
        } while (c != '\0');
        size_t sz = static_cast<size_t>(reinterpret_cast<intptr_t>(pc) - reinterpret_cast<intptr_t>(src + 1));
        if (static_cast<int32_t>(sz) >= 0 && src != reinterpret_cast<char*>(&DAT_008cacd0)) {
            if (sz != 0) {
                FUN_004f3350(self);
                char* dst = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)));
                std::memmove(dst, src, sz);
                int32_t len = *reinterpret_cast<int32_t*>(dst - 4);
                dst[len] = 0;
                return;
            }
            FUN_00412f90(self);
        }
    }
}

// 0x412d10 — observed shape
void FUN_00412d10(uint32_t* self) {
    *self = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006f583c));
    FUN_004f4de0(self);
    *self = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006f5864));
    FUN_004f0dc0(self);
    uint32_t* pu = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(self[7]) - 8);
    if (pu != nullptr && pu != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator_delete__(pu);
    }
    self[7] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
}

// 0x412d50 — observed shape
void FUN_00412d50(uint32_t* self, uint8_t param_1) {
    *self = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006f583c));
    FUN_004f4de0(self);
    *self = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006f5864));
    FUN_004f0dc0(self);
    uint32_t* pu = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(self[7]) - 8);
    if (pu != nullptr && pu != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator_delete__(pu);
    }
    self[7] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x412db0 — observed shape
void FUN_00412db0(HCURSOR* self) {
    HCURSOR hCursor = DAT_008cacd8;
    if (DAT_008cacd8 == nullptr) {
        hCursor = LoadCursorA((HINSTANCE)0, (LPCSTR)(INT_PTR)&DAT_00007f02);
    }
    HCURSOR prev = GetCursor();
    self[0] = prev;
    self[1] = hCursor;
    SetCursor(hCursor);
}

// 0x412df0 — observed shape
void FUN_00412df0(int32_t* self, int32_t* srcHolder) {
    *self = static_cast<int32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
    uint8_t* src = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*srcHolder)));
    size_t sz = *reinterpret_cast<size_t*>(src - 4);
    if (static_cast<int32_t>(sz) >= 0 && src != nullptr && src != &DAT_008cacd0) {
        if (sz != 0) {
            FUN_004f3350(self);
            uint8_t* dst = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)));
            std::memmove(dst, src, sz);
            int32_t len = *reinterpret_cast<int32_t*>(dst - 4);
            dst[len] = 0;
            return;
        }
        FUN_00412f90(self);
    }
}

// 0x412e50 — observed shape
void FUN_00412e50(int32_t* self, char* param_1) {
    size_t sz;
    if (param_1 == nullptr) {
        sz = 0;
    } else {
        char* pc = param_1;
        char c;
        do {
            c = *pc;
            ++pc;
        } while (c != '\0');
        sz = static_cast<size_t>(reinterpret_cast<intptr_t>(pc) - reinterpret_cast<intptr_t>(param_1 + 1));
    }
    int32_t base = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self))) - 4);
    if (static_cast<int32_t>(sz) > 0 && base >= 0 && param_1 != nullptr) {
        if (base < base + static_cast<int32_t>(sz)) {
            FUN_004f3350(self);
            uint8_t* dst = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)));
            int32_t cur = *reinterpret_cast<int32_t*>(dst - 4);
            dst[cur] = 0;
        }
        uint8_t* dst = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)));
        int32_t cur = *reinterpret_cast<int32_t*>(dst - 4);
        std::memmove(dst + cur, param_1, sz);
    }
}

// 0x412ec0 — observed shape
void FUN_00412ec0(int32_t* self, int32_t* srcHolder) {
    uint8_t* src = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*srcHolder)));
    size_t sz = *reinterpret_cast<size_t*>(src - 4);
    if (static_cast<int32_t>(sz) >= 0 && src != nullptr && src != reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)))) {
        if (sz != 0) {
            FUN_004f3350(self);
            uint8_t* dst = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)));
            std::memmove(dst, src, sz);
            int32_t len = *reinterpret_cast<int32_t*>(dst - 4);
            dst[len] = 0;
            return;
        }
        FUN_00412f90(self);
    }
}

// 0x412f10 — observed shape
void FUN_00412f10(int32_t* self, char* src) {
    if (src != nullptr) {
        char* pc = src;
        char c;
        do {
            c = *pc;
            ++pc;
        } while (c != '\0');
        size_t sz = static_cast<size_t>(reinterpret_cast<intptr_t>(pc) - reinterpret_cast<intptr_t>(src + 1));
        if (static_cast<int32_t>(sz) >= 0 && src != reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)))) {
            if (sz != 0) {
                FUN_004f3350(self);
                char* dst = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)));
                std::memmove(dst, src, sz);
                int32_t len = *reinterpret_cast<int32_t*>(dst - 4);
                dst[len] = 0;
                return;
            }
            FUN_00412f90(self);
        }
    }
}

// 0x412f70 — observed shape
int32_t FUN_00412f70(int32_t value) {
    if (value < 1) {
        return static_cast<int32_t>((-1 < value) - 1);
    }
    return 1;
}

// 0x412f90 — observed shape
void FUN_00412f90(int32_t* self) {
    uint8_t* buf = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)));
    if (*reinterpret_cast<int32_t*>(buf - 4) != 0) {
        buf[0] = 0;
        *reinterpret_cast<int32_t*>(buf - 4) = 0;
    }
}

// 0x412fb0 — observed shape
void FUN_00412fb0(int32_t* self) {
    uint32_t* pu = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*self)) - 8);
    if (pu != nullptr && pu != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator_delete__(pu);
    }
    *self = static_cast<int32_t>(reinterpret_cast<intptr_t>(&DAT_008cacd0));
}

// 0x412ff0 — observed shape
void FUN_00412ff0(uint32_t* self) {
    *self = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006f5864));
    FUN_004f0dc0(self);
    uint32_t* pu = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(self[7]) - 8);
    if (pu != nullptr && pu != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator_delete__(pu);
    }
    self[7] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
}

// 0x413020 — observed shape
void FUN_00413020(uint32_t* self, uint8_t param_1) {
    *self = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006f5864));
    FUN_004f0dc0(self);
    uint32_t* pu = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(self[7]) - 8);
    if (pu != nullptr && pu != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator_delete__(pu);
    }
    self[7] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x413080 — observed shape
void FUN_00413080(int32_t index) {
    short* eType = reinterpret_cast<short*>(DAT_008142f8);
    if (eType[index * 0x22e] != -1) {
        if (index < 8) {
            FUN_00412f10(nullptr, nullptr);
            DAT_007267c8 = reinterpret_cast<int32_t*>(DAT_008db618)[index * 3];
            DAT_007267cc = reinterpret_cast<int32_t*>(DAT_008db61c)[index * 3];
            return;
        }
        int32_t iVar3 = *reinterpret_cast<short*>(DAT_008142fc + index * 0x45c);
        if (4 < iVar3) {
            iVar3 = 0;
        }
        if (*reinterpret_cast<short*>(DAT_00814326 + index * 0x45c) != -1) {
            iVar3 = (reinterpret_cast<int32_t*>(DAT_00723b10)[eType[index * 0x22e] * 0x44] + iVar3 * 3) * 0x40 +
                    static_cast<int32_t>(*reinterpret_cast<short*>(DAT_00814326 + index * 0x45c));
            FUN_00412f10(nullptr, nullptr);
            DAT_007267c8 = reinterpret_cast<int32_t*>(DAT_008d8918)[iVar3 * 3];
            DAT_007267cc = reinterpret_cast<int32_t*>(DAT_008d891c)[iVar3 * 3];
            return;
        }
        int16_t sVar2 = 0;
        int32_t iVar1 = 0;
        do {
            uint32_t uVar4 = static_cast<uint32_t>(std::rand());
            uVar4 = uVar4 & 0x8000003f;
            if (static_cast<int32_t>(uVar4) < 0) {
                uVar4 = (uVar4 - 1 | 0xffffffc0) + 1;
            }
            sVar2 = static_cast<int16_t>(uVar4);
            int32_t baseIdx = (reinterpret_cast<int32_t*>(DAT_00723b10)[eType[index * 0x22e] * 0x44] + iVar3 * 3) * 0x40 +
                              static_cast<int32_t>(sVar2);
            iVar1 = reinterpret_cast<int32_t*>(DAT_008d8920)[baseIdx * 3];
            *reinterpret_cast<short*>(DAT_00814326 + index * 0x45c) = sVar2;
        } while (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar1)) - 4) == 0);
        int32_t iVar3b = (reinterpret_cast<int32_t*>(DAT_00723b10)[eType[index * 0x22e] * 0x44] + iVar3 * 3) * 0x40 +
                         static_cast<int32_t>(sVar2);
        FUN_00412f10(nullptr, nullptr);
        DAT_007267c8 = reinterpret_cast<int32_t*>(DAT_008d8918)[iVar3b * 3];
        DAT_007267cc = reinterpret_cast<int32_t*>(DAT_008d891c)[iVar3b * 3];
    }
}

// 0x4131d0 — observed shape
int32_t FUN_004131d0(int32_t param_1) {
    char local_8[8];
    if (param_1 != 0x2e && param_1 != 0x2d) {
        builtin_strncpy(local_8, "\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f", 8);
        int32_t iVar5 = reinterpret_cast<int32_t*>(DAT_00860b68)[param_1 * 8];
        int32_t iVar1 = reinterpret_cast<int32_t*>(DAT_00860b6c)[param_1 * 8];
        char cVar8 = 'c';
        char local_11 = -1;
        int32_t iVar3 = 0;
        do {
            if (static_cast<char>(reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                    (reinterpret_cast<int32_t*>(DAT_007252f0)[iVar3] + iVar5) * 0x125 +
                    reinterpret_cast<int32_t*>(DAT_00725350)[iVar3]] < cVar8) {
                cVar8 = reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                        (reinterpret_cast<int32_t*>(DAT_007252f0)[iVar3] + iVar5) * 0x125 +
                        reinterpret_cast<int32_t*>(DAT_00725350)[iVar3]];
            }
            if (static_cast<char>(reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                    (reinterpret_cast<int32_t*>(DAT_007252f4)[iVar3] + iVar5) * 0x125 +
                    reinterpret_cast<int32_t*>(DAT_00725354)[iVar3]] < cVar8) {
                cVar8 = reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                        (reinterpret_cast<int32_t*>(DAT_007252f4)[iVar3] + iVar5) * 0x125 +
                        reinterpret_cast<int32_t*>(DAT_00725354)[iVar3]];
            }
            if (static_cast<char>(reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                    (reinterpret_cast<int32_t*>(DAT_007252f8)[iVar3] + iVar5) * 0x125 +
                    reinterpret_cast<int32_t*>(DAT_00725358)[iVar3]] < cVar8) {
                cVar8 = reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                        (reinterpret_cast<int32_t*>(DAT_007252f8)[iVar3] + iVar5) * 0x125 +
                        reinterpret_cast<int32_t*>(DAT_00725358)[iVar3]];
            }
            if (static_cast<char>(reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                    (reinterpret_cast<int32_t*>(DAT_007252fc)[iVar3] + iVar5) * 0x125 +
                    reinterpret_cast<int32_t*>(DAT_0072535c)[iVar3]] < cVar8) {
                cVar8 = reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                        (reinterpret_cast<int32_t*>(DAT_007252fc)[iVar3] + iVar5) * 0x125 +
                        reinterpret_cast<int32_t*>(DAT_0072535c)[iVar3]];
            }
            iVar3 += 0x10;
        } while (iVar3 < 0x20);
        iVar3 = 0;
        do {
            if (cVar8 < static_cast<char>(reinterpret_cast<char*>(DAT_007b10a0)[iVar1 +
                    (reinterpret_cast<int32_t*>(DAT_007252f0)[iVar3] + iVar5) * 0x125 +
                    reinterpret_cast<int32_t*>(DAT_00725350)[iVar3]])) {
                int32_t iVar9 = 0;
                int32_t iVar6 = 8;
                do {
                    uint32_t uVar4 = static_cast<uint32_t>(iVar9 + iVar3) & 7;
                    int32_t iVar7 = iVar9;
                    if (iVar6 < 5) {
                        iVar7 = iVar6;
                    }
                    if (iVar7 < local_8[uVar4]) {
                        local_8[uVar4] = static_cast<char>(iVar7);
                    }
                    ++iVar9;
                    --iVar6;
                } while (iVar6 > 0);
            }
            ++iVar3;
        } while (iVar3 < 8);
        cVar8 = -1;
        iVar5 = 0;
        uint32_t uVar4c = 0xffffffffu;
        do {
            char cVar2 = static_cast<char>(iVar5);
            if (cVar8 < local_8[iVar5]) {
                cVar8 = local_8[iVar5];
                local_11 = cVar2;
            }
            if ((uVar4c & 1) != 0 && '\x01' < local_8[iVar5 + 1]) {
                local_8[iVar5 + 1] = static_cast<char>(local_8[iVar5 + 1] - 1);
            }
            if (cVar8 < local_8[iVar5 + 1]) {
                local_11 = static_cast<char>(cVar2 + '\x01');
                cVar8 = local_8[iVar5 + 1];
            }
            if (cVar8 < local_8[iVar5 + 2]) {
                local_11 = static_cast<char>(cVar2 + '\x02');
                cVar8 = local_8[iVar5 + 2];
            }
            if ((uVar4c & 1) != 0 && '\x01' < local_8[iVar5 + 3]) {
                local_8[iVar5 + 3] = static_cast<char>(local_8[iVar5 + 3] - 1);
            }
            if (cVar8 < local_8[iVar5 + 3]) {
                local_11 = static_cast<char>(cVar2 + '\x03');
                cVar8 = local_8[iVar5 + 3];
            }
            uVar4c += 4;
            iVar5 += 4;
        } while (static_cast<int32_t>(uVar4c) < 7);
        if (param_1 == 0x26) {
            local_11 = '\x04';
        }
        if (cVar8 != -1) {
            return static_cast<int32_t>(local_11);
        }
    }
    return 4;
}

// 0x413400 — observed shape
void FUN_00413400(int32_t index) {
    int32_t off = index * 0x45c;
    *reinterpret_cast<int16_t*>(DAT_00814332 + off) = 0;
    reinterpret_cast<int16_t*>(DAT_00814330)[index * 0x22e] = 0;
    *reinterpret_cast<int16_t*>(DAT_0081432e + off) = 0;
    *reinterpret_cast<int16_t*>(DAT_0081432c + off) = 0;
}

// 0x413430 — observed shape
void FUN_00413430(int32_t param_1) {
    int16_t sVar1 = reinterpret_cast<short*>(DAT_0081431e)[param_1 * 0x22e];
    int32_t iVar5;
    if (static_cast<int32_t>(sVar1) / 3 < 1) {
        iVar5 = 0;
    } else {
        iVar5 = std::rand() % (static_cast<int32_t>(sVar1) / 3);
    }
    int32_t iVar6 = static_cast<int32_t>(reinterpret_cast<short*>(DAT_008142f8)[param_1 * 0x22e]) * 0x44;
    int32_t iVar2 = reinterpret_cast<int32_t*>(DAT_00723b1c)[iVar6];
    if (iVar5 < reinterpret_cast<int32_t*>(DAT_00723b08)[iVar6] / 2) {
        iVar5 = reinterpret_cast<int32_t*>(DAT_00723b08)[iVar6] / 2;
    }
    if (iVar2 < iVar5) {
        iVar5 = iVar2;
    }
    int32_t iVar18 = reinterpret_cast<int32_t*>(DAT_00723b18)[iVar6];
    int16_t sVar38 = *reinterpret_cast<short*>(DAT_00814338 + param_1 * 0x45c);
    reinterpret_cast<short*>(DAT_00814330)[param_1 * 0x22e] = 0;
    *reinterpret_cast<int16_t*>(DAT_0081432c + param_1 * 0x45c) = 0;
    *reinterpret_cast<int16_t*>(DAT_00814332 + param_1 * 0x45c) = 0;
    *reinterpret_cast<int16_t*>(DAT_0081432e + param_1 * 0x45c) = 0;
    int32_t iVar7 = static_cast<int32_t>(reinterpret_cast<short*>(DAT_00814336)[param_1 * 0x22e]);
    int32_t rem = (iVar2 - iVar18) - iVar5;
    int32_t val38 = reinterpret_cast<int32_t*>(DAT_00860b7c)[static_cast<int32_t>(sVar38) * 8];
    *reinterpret_cast<short*>(DAT_0081432a + param_1 * 0x45c) = static_cast<short>(iVar5);
    int32_t iVar5b;
    if (reinterpret_cast<int32_t*>(DAT_00860b7c)[iVar7 * 8] < val38) {
        iVar5b = (DAT_00861b74 / 2 < static_cast<int32_t>(reinterpret_cast<uint8_t*>(DAT_00860b75)[iVar7 * 0x20])) + 4;
    } else {
        iVar5b = (DAT_00861b74 / 2 < static_cast<int32_t>(reinterpret_cast<uint8_t*>(DAT_00860b75)[iVar7 * 0x20])) + 2;
    }
    if (iVar5b == -1) {
        int16_t sVar4 = *reinterpret_cast<short*>(DAT_00814328 + param_1 * 0x45c);
        uint32_t uVar3 = reinterpret_cast<uint32_t*>(DAT_00814350)[param_1 * 0x117];
        reinterpret_cast<short*>(DAT_00814322)[param_1 * 0x22e] =
            static_cast<short>(reinterpret_cast<short*>(DAT_00814322)[param_1 * 0x22e] + 1);
        *reinterpret_cast<short*>(DAT_00814328 + param_1 * 0x45c) = static_cast<short>(sVar4 / 2 + sVar4);
        reinterpret_cast<uint32_t*>(DAT_00814350)[param_1 * 0x117] = uVar3 | 0x40000;
    } else {
        int32_t local_8;
        if (iVar5b == 2) {
            local_8 = 600;
        } else if (iVar5b == 4) {
            local_8 = 600;
        } else {
            local_8 = 400;
        }
        int16_t sVar4 = static_cast<int16_t>(((reinterpret_cast<int32_t*>(DAT_00860b7c)[iVar7 * 8] + 100) * rem) / local_8);
        *reinterpret_cast<short*>(DAT_00814328 + (param_1 * 0x22e + iVar5b) * 2) = sVar4;
        rem = rem - sVar4;
    }
    if (reinterpret_cast<short*>(DAT_0085bfb6)[iVar7 * 0x4a] < reinterpret_cast<short*>(DAT_0085bfb6)[static_cast<int32_t>(sVar38) * 0x4a]) {
        *reinterpret_cast<short*>(DAT_0081432a + param_1 * 0x45c) =
            static_cast<short>(*reinterpret_cast<short*>(DAT_0081432a + param_1 * 0x45c) + static_cast<short>(rem / 3));
    }
}

// 0x4135d0 — observed shape
int32_t FUN_004135d0(int32_t edxParam) {
    int32_t iVar7 = 8;
    short* psVar4 = reinterpret_cast<short*>(DAT_008165d8);
    do {
        if (*psVar4 == -1) {
            int32_t iVar8 = iVar7 * 0x45c;
            uint32_t* puVar9 = reinterpret_cast<uint32_t*>(DAT_008142f8 + iVar7 * 0x45c);
            for (int32_t iVar6 = 0x117; ; --iVar6) {
                uint32_t uVar3 = static_cast<uint32_t>(DAT_0085a150);
                *puVar9 = 0;
                ++puVar9;
                if (iVar6 == 0) break;
                (void)uVar3;
            }
            uint32_t uVar1 = reinterpret_cast<uint32_t*>(DAT_00814350)[iVar7 * 0x117];
            reinterpret_cast<uint32_t*>(DAT_00814350)[iVar7 * 0x117] = uVar1 | 0x10;
            reinterpret_cast<uint32_t*>(DAT_00814310)[iVar7 * 0x117] = 300;
            *reinterpret_cast<int16_t*>(DAT_00814344 + iVar8) = static_cast<int16_t>(0xffff);
            *reinterpret_cast<uint32_t*>(DAT_00814340 + iVar8) = static_cast<uint32_t>(DAT_0085a150);
            if (edxParam != -1) {
                reinterpret_cast<short*>(DAT_00814336)[iVar7 * 0x22e] = static_cast<short>(edxParam);
                uint32_t uVar10 = static_cast<uint32_t>(reinterpret_cast<short*>(DAT_0085bff6)[edxParam * 0x4a]);
                int32_t iVar6 = reinterpret_cast<int32_t*>(DAT_007252f0)[uVar10];
                *reinterpret_cast<short*>(DAT_008142fc + iVar7 * 0x45c) = static_cast<short>(reinterpret_cast<char*>(DAT_00860b74)[edxParam * 0x20]);
                int32_t iVar5 = static_cast<int32_t>((uVar10 ^ 4) << 0x1d);
                reinterpret_cast<uint32_t*>(DAT_0081433c)[iVar7 * 0x117] = static_cast<uint32_t>(iVar5);
                reinterpret_cast<uint32_t*>(DAT_0081430c)[iVar7 * 0x117] = static_cast<uint32_t>(iVar5);
                int32_t iVar5b = reinterpret_cast<int32_t*>(DAT_00725350)[uVar10];
                int32_t iVar2 = reinterpret_cast<int32_t*>(DAT_00860b6c)[edxParam * 8];
                reinterpret_cast<uint32_t*>(DAT_00814304)[iVar7 * 0x117] =
                    static_cast<uint32_t>((((iVar6 * 3000) / 3 + reinterpret_cast<int32_t*>(DAT_00860b68)[edxParam * 8] * 1000) * 1000));
                reinterpret_cast<uint32_t*>(DAT_00814308)[iVar7 * 0x117] =
                    static_cast<uint32_t>((((iVar5b * 3000) / 3 + iVar2 * 1000) * 1000));
                *reinterpret_cast<int16_t*>(DAT_00814354 + iVar8) = 1;
                reinterpret_cast<uint32_t*>(DAT_00814350)[iVar7 * 0x117] = uVar1 | 0x210;
            }
            return iVar7;
        }
        psVar4 += 0x22e;
        ++iVar7;
    } while (reinterpret_cast<intptr_t>(psVar4) < 0x859ef8);
    return -1;
}

// 0x413710 — observed shape
int32_t FUN_00413710(uint32_t param_1, int32_t param_2, uint32_t param_3) {
    int32_t local_1c = 0;
    int32_t iVar15;
    short* psVar11;
    if (param_2 == 1) {
        uint32_t uVar8 = static_cast<uint32_t>(std::rand());
        uVar8 = uVar8 & 0x80000003u;
        if (static_cast<int32_t>(uVar8) < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
        }
        local_1c = static_cast<int32_t>(uVar8) + 0x6c;
        iVar15 = local_1c * 0x45c;
        psVar11 = reinterpret_cast<short*>(DAT_008142f8 + local_1c * 0x45c);
        if (reinterpret_cast<short*>(DAT_008142f8)[local_1c * 0x22e] != -1) {
            return -1;
        }
        param_3 = param_1;
    } else {
        iVar15 = 0;
        int32_t iVar12c = 0;
        do {
            int32_t r = std::rand();
            local_1c = r % 0x78 + 8;
            if (reinterpret_cast<short*>(DAT_008142f8)[local_1c * 0x22e] == -1) break;
            ++iVar15;
            iVar12c = local_1c;
            (void)iVar12c;
        } while (iVar15 < static_cast<int32_t>((-(static_cast<uint32_t>(param_2 != 0)) & 3) + 1));
        iVar15 = local_1c * 0x45c;
        psVar11 = reinterpret_cast<short*>(DAT_008142f8 + local_1c * 0x45c);
        if (*psVar11 != -1) {
            return -1;
        }
        if (param_1 == 0xffffffffu) {
            int32_t r = std::rand();
            param_1 = static_cast<uint32_t>(r % 0x2c);
            uint32_t uVar8 = static_cast<uint32_t>(reinterpret_cast<int32_t*>(DAT_00860b70)[param_1 * 8]);
            if ((uVar8 & 0xc0000000u) != 0) {
                return -1;
            }
            if (param_1 == static_cast<uint32_t>(DAT_00876be0) && DAT_0085a150 < 2000) {
                return -1;
            }
            int32_t iVar12 = FUN_00412810();
            if (0x73 < iVar12) {
                return -1;
            }
            if ((uVar8 & 2) == 0) {
                return -1;
            }
            if (iVar12 < 3) {
                return -1;
            }
            if (reinterpret_cast<int32_t*>(DAT_00859ef8)[param_1] != 0) {
                int32_t q = FUN_004289d0();
                if (DAT_0085a150 - reinterpret_cast<int32_t*>(DAT_00859ef8)[param_1] <
                    static_cast<int32_t>(300000 / static_cast<long long>(q + 100)) + static_cast<int16_t>(reinterpret_cast<short*>(DAT_0085bf7e)[param_1 * 0x4a])) {
                    return -1;
                }
            }
        }
        if (param_3 == 0xffffffffu) {
            int32_t r = std::rand();
            param_3 = static_cast<uint32_t>(r % 0x2c);
            uint32_t uVar8 = static_cast<uint32_t>(std::rand());
            uVar8 = uVar8 & 0x80000001u;
            bool bVar19 = uVar8 == 0;
            if (static_cast<int32_t>(uVar8) < 0) {
                bVar19 = (uVar8 - 1 | 0xfffffffe) == 0xffffffffu;
            }
            if (!bVar19) {
                param_3 = static_cast<uint32_t>(std::rand());
                param_3 = param_3 & 0x8000007fu;
                if (static_cast<int32_t>(param_3) < 0) {
                    param_3 = (param_3 - 1 | 0xffffff80) + 1;
                }
            }
            if (static_cast<uint32_t>(reinterpret_cast<int32_t*>(DAT_00860b70)[param_3 * 8] & 0xc0000000) != 0) {
                return -1;
            }
            int32_t iVar12 = FUN_00412810();
            if (0x73 < iVar12) {
                return -1;
            }
            if ((reinterpret_cast<uint8_t*>(DAT_00860b70)[param_3 * 8] & 2) == 0) {
                return -1;
            }
            if (param_1 == param_3) {
                return -1;
            }
            char cVar1 = reinterpret_cast<char*>(DAT_00860b74)[param_3 * 0x20];
            if ('\x03' < cVar1) {
                return -1;
            }
            iVar12 = FUN_00412810();
            if (iVar12 < 6) {
                return -1;
            }
            uint32_t uVar8b = (((reinterpret_cast<char*>(DAT_00860b74)[param_1 * 0x20] == cVar1) + 1) * 0x1ce) / 6;
            if (0x2c < static_cast<int32_t>(param_3)) {
                uVar8b = uVar8b >> 2;
            }
            if (static_cast<int32_t>(uVar8b) < iVar12) {
                return -1;
            }
        }
    }
    short* psVar17 = psVar11;
    for (int32_t k = 0x117; k != 0; --k) {
        psVar17[0] = 0;
        psVar17[1] = 0;
        psVar17 += 2;
    }
    reinterpret_cast<int32_t*>(DAT_00859ef8)[param_1] = DAT_0085a150;
    int32_t iVar12_20 = static_cast<int32_t>(param_1) * 0x20;
    *reinterpret_cast<int16_t*>(DAT_008142fa + iVar15) = static_cast<int16_t>(param_2);
    char cVar1 = reinterpret_cast<char*>(DAT_00860b74)[iVar12_20];
    *reinterpret_cast<int16_t*>(DAT_00814326 + iVar15) = static_cast<int16_t>(0xffff);
    *reinterpret_cast<int16_t*>(DAT_008142fc + iVar15) = static_cast<int16_t>(cVar1);
    int16_t sVar3;
    switch (cVar1) {
    case '\0':
        if (static_cast<int32_t>(param_3) < 0x2c) {
            int32_t r = std::rand();
            if ((r % 300 < reinterpret_cast<int32_t*>(DAT_00860b7c)[param_1 * 8]) &&
                (reinterpret_cast<char*>(DAT_00860b74)[param_3 * 0x20] == '\0') && (0x96 < reinterpret_cast<int32_t*>(DAT_00860b7c)[param_3 * 8])) {
                sVar3 = 0x11;
            } else {
                sVar3 = 8;
            }
        } else {
            sVar3 = 0xc;
        }
        break;
    case '\x01':
        if (static_cast<int32_t>(param_3) < 0x2c) {
            int32_t r = std::rand();
            sVar3 = static_cast<int16_t>((((reinterpret_cast<int32_t*>(DAT_00860b7c)[param_1 * 8] <= r % 200) - 1 & 9) + 5));
        } else {
            sVar3 = 1;
        }
        break;
    case '\x02':
        if (static_cast<int32_t>(param_3) < 0x2c) {
            int32_t r = std::rand();
            sVar3 = static_cast<int16_t>((((reinterpret_cast<int32_t*>(DAT_00860b7c)[param_1 * 8] <= r % 200) - 1 & 0xfff9) + 0xc));
        } else {
            sVar3 = 3;
        }
        break;
    case '\x03':
        if (static_cast<int32_t>(param_3) < 0x2c) {
            int32_t r = std::rand();
            sVar3 = static_cast<int16_t>((((reinterpret_cast<int32_t*>(DAT_00860b7c)[param_1 * 8] <= r % 200) - 1 & 9) + 0xd));
        } else {
            sVar3 = 4;
        }
        break;
    default:
        goto def_sw;
    }
    *psVar11 = sVar3;
def_sw:;
    {}
    int32_t iVar9 = reinterpret_cast<int32_t*>(DAT_0085b170)[param_1 * 4];
    int32_t iVar13 = reinterpret_cast<int32_t*>(DAT_0085b174)[param_1 * 4];
    *reinterpret_cast<int32_t*>(DAT_00814308 + iVar15) = iVar13 * 1000;
    int32_t iVar18 = static_cast<int32_t>(reinterpret_cast<short*>(DAT_0085bff6)[param_1 * 0x4a]);
    *reinterpret_cast<int32_t*>(DAT_00814304 + iVar15) = iVar9 * 1000;
    uint16_t uVar4 = static_cast<uint16_t>(param_1);
    *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) = static_cast<int16_t>(uVar4);
    *reinterpret_cast<int16_t*>(DAT_00814338 + iVar15) = static_cast<int16_t>(param_3);
    *reinterpret_cast<int32_t*>(DAT_0081430c + iVar15) = iVar18;
    if (iVar18 == -1) {
        return -1;
    }
    *reinterpret_cast<int32_t*>(DAT_0081433c + iVar15) = iVar18 << 0x1d;
    *reinterpret_cast<int32_t*>(DAT_0081430c + iVar15) = iVar18 << 0x1d;
    *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) = *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) | 8;
    *reinterpret_cast<int32_t*>(DAT_00814310 + iVar15) = 300;
    iVar18 = FUN_004db210();
    *reinterpret_cast<int32_t*>(DAT_00814304 + iVar15) = iVar18 + iVar9 * 1000;
    iVar9 = FUN_004db210();
    *reinterpret_cast<int32_t*>(DAT_00814308 + iVar15) = iVar9 + iVar13 * 1000;
    *reinterpret_cast<int32_t*>(DAT_00814340 + iVar15) = DAT_0085a150;
    sVar3 = *psVar11;
    int16_t sVar5 = reinterpret_cast<short*>(DAT_0085bf7e)[param_1 * 0x4a];
    *reinterpret_cast<int16_t*>(DAT_00814344 + iVar15) = static_cast<int16_t>(0xffff);
    iVar9 = reinterpret_cast<int32_t*>(DAT_00723b18)[sVar3 * 0x44];
    iVar13 = (sVar5 < 100) + 2;
    *reinterpret_cast<int16_t*>(DAT_00814322 + iVar15) = 1;
    char cVar1b;
    if (iVar9 / iVar13 < 1) {
        cVar1b = '\0';
    } else {
        int32_t r = std::rand();
        cVar1b = static_cast<char>(r % (iVar9 / iVar13));
    }
    sVar3 = *psVar11;
    *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15) =
        static_cast<int16_t>(static_cast<uint8_t>(static_cast<char>(reinterpret_cast<int32_t*>(DAT_00723b18)[sVar3 * 0x44] / iVar13) + cVar1b + 1) & 0xfe);
    int16_t sVar3b = static_cast<int16_t>(reinterpret_cast<int32_t*>(DAT_00723b14)[sVar3 * 0x44] / iVar13);
    *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) = sVar3b;
    if (sVar3b < 1) {
        sVar3b = 0;
    } else {
        int32_t r = std::rand();
        sVar3b = static_cast<int16_t>(r % static_cast<int32_t>(sVar3b));
    }
    *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) =
        static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) + sVar3b);
    iVar9 = FUN_004289d0();
    iVar9 = (iVar9 + 0x32) * (reinterpret_cast<int32_t*>(DAT_00723b0c)[*psVar11 * 0x44] + 2);
    int16_t sVar3c = static_cast<int16_t>((iVar9 + ((iVar9 >> 0x1f) & 3)) >> 2);
    *reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) = sVar3c;
    if (*reinterpret_cast<int16_t*>(DAT_008142fc + iVar15) == 0) {
        int16_t t = sVar3c;
        if (t < 1) {
            t = 0;
        } else {
            int32_t r = std::rand();
            t = static_cast<int16_t>(r % static_cast<int32_t>(t));
        }
        *reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) =
            static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) + t);
    }
    FUN_00413430(local_1c);
    if (*reinterpret_cast<int16_t*>(DAT_008142fa + iVar15) == 1) {
        int32_t r = std::rand();
        if (r % 3 == 0) {
            sVar3 = static_cast<int16_t>(0x10 - static_cast<uint16_t>(*reinterpret_cast<int16_t*>(DAT_008142fc + iVar15) != 0));
        } else {
            uint32_t u = static_cast<uint32_t>(std::rand());
            u = u & 0x80000001u;
            if (static_cast<int32_t>(u) < 0) {
                u = (u - 1 | 0xfffffffe) + 1;
            }
            sVar3 = static_cast<int16_t>((u != 0) + 10);
        }
        *psVar11 = sVar3;
        int32_t i12 = static_cast<int32_t>(sVar3) * 0x44;
        int16_t v1 = static_cast<int16_t>(reinterpret_cast<int32_t*>(DAT_00723b18)[i12]);
        uint16_t v2 = static_cast<uint16_t>(reinterpret_cast<int32_t*>(DAT_00723b14)[i12]);
        int32_t v3 = reinterpret_cast<int32_t*>(DAT_00723b1c)[i12];
        *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15) = v1;
        *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) = static_cast<int16_t>(v2);
        *reinterpret_cast<int16_t*>(DAT_00814332 + iVar15) = 0;
        *reinterpret_cast<int16_t*>(DAT_0081432e + iVar15) = 0;
        *reinterpret_cast<int16_t*>(DAT_0081432a + iVar15) = static_cast<int16_t>((v3 - v1) / 2);
        *reinterpret_cast<int16_t*>(DAT_00814322 + iVar15) = 4;
        FUN_00413080(local_1c);
        return local_1c;
    }
    if (*reinterpret_cast<int16_t*>(DAT_008142fa + iVar15) == 2) {
        uint32_t u = static_cast<uint32_t>(std::rand());
        u = u & 0x80000001u;
        bool b = u == 0;
        if (static_cast<int32_t>(u) < 0) {
            b = (u - 1 | 0xfffffffe) == 0xffffffffu;
        }
        *reinterpret_cast<int16_t*>(DAT_00814322 + iVar15) = 3;
        *psVar11 = static_cast<int16_t>(!b + 1);
        int16_t w1 = static_cast<int16_t>(FUN_00412950());
        *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) =
            static_cast<int16_t>(reinterpret_cast<short*>(DAT_00723b14)[static_cast<int32_t>(!b + 1) * 0x44] - w1);
        char c1 = static_cast<char>(FUN_00412950());
        *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15) =
            static_cast<int16_t>(static_cast<uint8_t>(c1 + static_cast<char>(reinterpret_cast<int32_t*>(DAT_00723b18)[*psVar11 * 0x44] / 2) + 1) & 0xfe);
        FUN_00413430(local_1c);
        *reinterpret_cast<int16_t*>(DAT_0081432a + iVar15) =
            static_cast<int16_t>((((reinterpret_cast<int32_t*>(DAT_00723b1c)[*psVar11 * 0x44] -
                                   static_cast<int32_t>(*reinterpret_cast<int16_t*>(DAT_0081432e + iVar15))) -
                                  static_cast<int32_t>(*reinterpret_cast<int16_t*>(DAT_00814332 + iVar15))) -
                                 reinterpret_cast<int32_t*>(DAT_00723b18)[*psVar11 * 0x44]) / 2);
        int32_t x, y;
        do {
            int32_t r = std::rand();
            x = r % 0xb + -5 + reinterpret_cast<int32_t*>(DAT_00860b68)[param_3 * 8];
            int32_t r2 = std::rand();
            y = r2 % 0xb + -5 + reinterpret_cast<int32_t*>(DAT_00860b6c)[param_3 * 8];
        } while (reinterpret_cast<char*>(DAT_007b10a0)[y + x * 0x125] != '\0');
        *reinterpret_cast<int32_t*>(DAT_00814304 + iVar15) = x * 1000000;
        *reinterpret_cast<int32_t*>(DAT_00814308 + iVar15) = y * 1000000;
        *reinterpret_cast<int32_t*>(DAT_0081430c + iVar15) = 0x40000000;
        FUN_00413080(local_1c);
        if (*reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) == -1) {
            *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) = uVar4;
        }
        uVar4 = FUN_0045b5d0();
        *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) = static_cast<int16_t>(uVar4);
        return local_1c;
    }
    int32_t iVar9_20 = static_cast<int32_t>(param_3) * 0x20;
    if (reinterpret_cast<int32_t*>(DAT_0085a168)[static_cast<int32_t>(reinterpret_cast<char*>(DAT_00860b74)[iVar9_20]) + static_cast<int32_t>(reinterpret_cast<char*>(DAT_00860b74)[iVar12_20]) * 8] == 1) {
        uint32_t u = static_cast<uint32_t>(std::rand());
        u = u & 0x80000001u;
        if (static_cast<int32_t>(u) < 0) {
            u = (u - 1 | 0xfffffffe) + 1;
        }
        *psVar11 = static_cast<int16_t>(-(static_cast<uint16_t>(u != 0)) & 0xfff8) + 9;
        if (static_cast<int32_t>(param_3) < 0x2c) {
            uint32_t u2 = static_cast<uint32_t>(std::rand());
            u2 = u2 & 0x80000001u;
            bool b = u2 == 0;
            if (static_cast<int32_t>(u2) < 0) {
                b = (u2 - 1 | 0xfffffffe) == 0xffffffffu;
            }
            int16_t s3;
            if (b) {
                s3 = 1;
            } else {
                uint32_t u3 = static_cast<uint32_t>(std::rand());
                u3 = u3 & 0x80000001u;
                if (static_cast<int32_t>(u3) < 0) {
                    u3 = (u3 - 1 | 0xfffffffe) + 1;
                }
                s3 = static_cast<int16_t>(-(static_cast<uint16_t>(u3 != 0)) & 0xfff9) + 9;
            }
            *psVar11 = s3;
        }
        sVar3 = *psVar11;
        *reinterpret_cast<int16_t*>(DAT_00814322 + iVar15) = 2;
        *reinterpret_cast<int16_t*>(DAT_008142fa + iVar15) = 4;
        int16_t s5 = static_cast<int16_t>(FUN_00412950());
        *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) = static_cast<int16_t>(reinterpret_cast<short*>(DAT_00723b14)[sVar3 * 0x44] - s5);
        char c1 = static_cast<char>(FUN_00412950());
        int32_t i18 = reinterpret_cast<int32_t*>(DAT_00723b18)[*psVar11 * 0x44];
        reinterpret_cast<short*>(DAT_00814324)[iVar15 / 2] =
            static_cast<int16_t>(reinterpret_cast<short*>(DAT_00814324)[iVar15 / 2] | 0x73);
        *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15) =
            static_cast<int16_t>(static_cast<uint8_t>(c1 + static_cast<char>(i18 / 3) + 1) & 0xfe);
        int32_t r = std::rand();
        *reinterpret_cast<int16_t*>(DAT_00814324 + iVar15) = static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_00814324 + iVar15) & static_cast<int16_t>(r));
        FUN_00413430(local_1c);
        int32_t r2 = std::rand();
        if ((r2 % 3 == 0) && (param_2 != 4) && (3000 < DAT_0085a150)) {
            *reinterpret_cast<int16_t*>(DAT_008142fa + iVar15) = 3;
            if (*reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) == -1) {
                *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) = uVar4;
            }
            uVar4 = FUN_0045b5d0();
            *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) = static_cast<int16_t>(uVar4);
            *psVar11 = static_cast<int16_t>(-(static_cast<uint16_t>(*reinterpret_cast<int16_t*>(DAT_008142fc + iVar15) != 0)) & 0xfff6) + 0x10;
            if (static_cast<int32_t>(param_3) < 0x2d) {
                uint32_t u4 = static_cast<uint32_t>(std::rand());
                u4 = u4 & 0x80000001u;
                bool b = u4 == 0;
                if (static_cast<int32_t>(u4) < 0) {
                    b = (u4 - 1 | 0xfffffffe) == 0xffffffffu;
                }
                if (!b) {
                    goto LAB_004140e2;
                }
            } else {
LAB_004140e2:
                *psVar11 = static_cast<int16_t>(static_cast<uint16_t>(*reinterpret_cast<int16_t*>(DAT_008142fc + iVar15) != 0) * 4 + 7);
            }
            uint32_t u5 = static_cast<uint32_t>(std::rand());
            u5 = u5 & 0x80000001u;
            bool b5 = u5 == 0;
            if (static_cast<int32_t>(u5) < 0) {
                b5 = (u5 - 1 | 0xfffffffe) == 0xffffffffu;
            }
            if (b5) {
                *psVar11 = 10;
            }
            uint32_t u6 = static_cast<uint32_t>(std::rand());
            u6 = u6 & 0x80000001u;
            bool b6 = u6 == 0;
            if (static_cast<int32_t>(u6) < 0) {
                b6 = (u6 - 1 | 0xfffffffe) == 0xffffffffu;
            }
            if (b6) {
                int32_t cc = static_cast<int32_t>(reinterpret_cast<char*>(DAT_00860b74)[iVar12_20]);
                *reinterpret_cast<int16_t*>(DAT_008142fa + iVar15) = 2;
                if (cc < 0) {
                    cc = 0;
                } else if (4 < cc) {
                    cc = 4;
                }
                int32_t rr = std::rand();
                *psVar11 = static_cast<int16_t>(reinterpret_cast<char*>(DAT_007252d0)[cc * 5 + rr % 3]);
            }
            sVar3 = *psVar11;
            *reinterpret_cast<int16_t*>(DAT_00814322 + iVar15) = 3;
            int16_t s6 = static_cast<int16_t>(FUN_00412950());
            int16_t s5b = *psVar11;
            *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) = static_cast<int16_t>(reinterpret_cast<short*>(DAT_00723b14)[sVar3 * 0x44] - s6);
            char c2 = static_cast<char>(FUN_00412950());
            char c1b = reinterpret_cast<char*>(DAT_00723b18)[s5b * 0x44];
            *reinterpret_cast<int16_t*>(DAT_00814332 + iVar15) = 0;
            *reinterpret_cast<int16_t*>(DAT_0081432e + iVar15) = 0;
            int16_t s3b = reinterpret_cast<short*>(DAT_00723b1c)[s5b * 0x44];
            uint16_t u7 = static_cast<uint16_t>(static_cast<uint8_t>((c1b - c2) + 1) & 0xfe);
            *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15) = static_cast<int16_t>(u7);
            *reinterpret_cast<int16_t*>(DAT_0081432a + iVar15) = static_cast<int16_t>(s3b - static_cast<int16_t>(u7));
        } else {
            *reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) =
                static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) << 1);
            FUN_00413400(local_1c);
            if (reinterpret_cast<uint8_t*>(DAT_00860b75)[iVar9_20] < reinterpret_cast<uint8_t*>(DAT_00860b75)[iVar12_20]) {
                *reinterpret_cast<int16_t*>(DAT_0081432c + iVar15) =
                    static_cast<int16_t>((reinterpret_cast<short*>(DAT_00723b1c)[*psVar11 * 0x44] - *reinterpret_cast<int16_t*>(DAT_0081432a + iVar15)) -
                                         *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15));
            } else {
                *reinterpret_cast<int16_t*>(DAT_00814330 + iVar15) =
                    static_cast<int16_t>((reinterpret_cast<short*>(DAT_00723b1c)[*psVar11 * 0x44] - *reinterpret_cast<int16_t*>(DAT_0081432a + iVar15)) -
                                         *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15));
            }
            if (0x2c < static_cast<int32_t>(param_3)) {
                uint32_t uu = static_cast<uint32_t>(std::rand());
                uu = uu & 0x80000001u;
                bool bb = uu == 0;
                if (static_cast<int32_t>(uu) < 0) {
                    bb = (uu - 1 | 0xfffffffe) == 0xffffffffu;
                }
                if (!bb) {
                    *reinterpret_cast<int16_t*>(DAT_008142fc + iVar15) = static_cast<int16_t>(reinterpret_cast<char*>(DAT_00860b74)[iVar9_20]);
                    *reinterpret_cast<int16_t*>(DAT_00814338 + iVar15) = uVar4;
                    *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) = static_cast<int16_t>(param_3);
                }
            }
        }
    }
    if (*reinterpret_cast<int16_t*>(DAT_008142fa + iVar15) != 0) {
        goto LAB_004148c2;
    }
    {
        int32_t local_8 = static_cast<int32_t>(*psVar11);
        int32_t i18 = 0;
        int32_t i10 = 0;
        short* p = reinterpret_cast<short*>(DAT_008165de);
        do {
            if (p[-3] != -1 && p[0] > 0) {
                int32_t i14 = 1;
                if (p[0x1c] == *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15)) {
                    i14 = 2;
                }
                if (reinterpret_cast<int32_t*>(DAT_0085a970)[p[0] * 8] == 0xc) {
                    i18 += i14;
                }
                if (reinterpret_cast<int32_t*>(DAT_0085a970)[p[0] * 8] == 0xd) {
                    i10 += i14;
                }
            }
            if (p[0x22b] != -1 && p[0x22e] > 0) {
                int32_t i14 = 1;
                if (p[0x24a] == *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15)) {
                    i14 = 2;
                }
                if (reinterpret_cast<int32_t*>(DAT_0085a970)[p[0x22e] * 8] == 0xc) {
                    i18 += i14;
                }
                if (reinterpret_cast<int32_t*>(DAT_0085a970)[p[0x22e] * 8] == 0xd) {
                    i10 += i14;
                }
            }
            if (p[0x459] != -1 && p[0x45c] > 0) {
                int32_t i14 = 1;
                if (p[0x478] == *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15)) {
                    i14 = 2;
                }
                if (reinterpret_cast<int32_t*>(DAT_0085a970)[p[0x45c] * 8] == 0xc) {
                    i18 += i14;
                }
                if (reinterpret_cast<int32_t*>(DAT_0085a970)[p[0x45c] * 8] == 0xd) {
                    i10 += i14;
                }
            }
            if (p[0x687] != -1 && p[0x68a] > 0) {
                int32_t i14 = 1;
                if (p[0x6a6] == *reinterpret_cast<int16_t*>(DAT_00814336 + iVar15)) {
                    i14 = 2;
                }
                if (reinterpret_cast<int32_t*>(DAT_0085a970)[p[0x68a] * 8] == 0xc) {
                    i18 += i14;
                }
                if (reinterpret_cast<int32_t*>(DAT_0085a970)[p[0x68a] * 8] == 0xd) {
                    i10 += i14;
                }
            }
            p += 0x8b8;
        } while (reinterpret_cast<intptr_t>(p) < 0x859efe);
        if (reinterpret_cast<char*>(DAT_00860b74)[iVar12_20] != reinterpret_cast<char*>(DAT_00860b74)[iVar9_20] &&
            reinterpret_cast<int32_t*>(DAT_0085a168)[static_cast<int32_t>(reinterpret_cast<char*>(DAT_00860b74)[iVar9_20]) + static_cast<int32_t>(reinterpret_cast<char*>(DAT_00860b74)[iVar12_20]) * 8] != -1) {
            goto LAB_004146e4;
        }
        int32_t i14 = std::rand();
        int32_t i13 = 2;
        uint16_t u4tmp = uVar4;
        (void)u4tmp;
        switch (i14 % 5) {
        case 0: {
            int32_t a = reinterpret_cast<int32_t*>(DAT_00860b7c)[param_3 * 8];
            int32_t b = reinterpret_cast<int32_t*>(DAT_00860b7c)[param_1 * 8];
            if (a * b <= (i18 + 2) * 0x1d4c) break;
            if (reinterpret_cast<char*>(DAT_00860b74)[iVar12_20] == '\0') {
                *reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) = 0x1a;
            } else {
                *reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) = static_cast<int16_t>((reinterpret_cast<char*>(DAT_00860b74)[iVar12_20] != '\x03') + 0x16);
            }
            i13 = 2;
            *reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) = static_cast<int16_t>((a * b) / 10);
            FUN_00413400(local_1c);
            *reinterpret_cast<int16_t*>(DAT_00814330 + iVar15) = static_cast<int16_t>(FUN_00412950());
            *reinterpret_cast<int16_t*>(DAT_0081432c + iVar15) = static_cast<int16_t>(FUN_00412950());
            FUN_0044d140(0xc, static_cast<int32_t>(param_1), 0xc);
            *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) = *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) | 0x800000;
            *reinterpret_cast<int16_t*>(DAT_00814322 + iVar15) = 2;
            goto LAB_004146e4;
        }
        case 1: {
            if ((reinterpret_cast<int32_t*>(DAT_00860b7c)[*reinterpret_cast<int16_t*>(DAT_00814338 + iVar15) * 8] <
                 reinterpret_cast<int32_t*>(DAT_00860b7c)[*reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) * 8]) &&
                (reinterpret_cast<char*>(DAT_00860b76)[*reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) * 0x20] <
                 reinterpret_cast<char*>(DAT_00860b76)[*reinterpret_cast<int16_t*>(DAT_00814338 + iVar15) * 0x20]) && (i10 < 3)) {
                int16_t ss;
                if (reinterpret_cast<char*>(DAT_00860b74)[iVar12_20] == '\0') {
                    uint32_t r = static_cast<uint32_t>(std::rand());
                    r = r & 0x80000001u;
                    if (static_cast<int32_t>(r) < 0) {
                        r = (r - 1 | 0xfffffffe) + 1;
                    }
                    ss = static_cast<int16_t>(-(static_cast<uint16_t>(r != 0)) & 0xe) + 7;
                    *reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) = ss;
                } else {
                    if (reinterpret_cast<char*>(DAT_00860b74)[iVar12_20] != '\x03') {
                        uint32_t r = static_cast<uint32_t>(std::rand());
                        r = r & 0x80000001u;
                        if (static_cast<int32_t>(r) < 0) {
                            r = (r - 1 | 0xfffffffe) + 1;
                        }
                        ss = static_cast<int16_t>(-(static_cast<uint16_t>(r != 0)) & 0xe) + 6;
                        *reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) = ss;
                    } else {
                        int32_t r = std::rand();
                        *reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) = static_cast<int16_t>(-(static_cast<uint16_t>(r % 3 != 0)) & 5) + 6;
                    }
                }
                FUN_00413400(local_1c);
                *reinterpret_cast<int16_t*>(DAT_0081432a + iVar15) =
                    static_cast<int16_t>(reinterpret_cast<int32_t*>(DAT_00723b1c)[*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) * 0x44] / 2);
                i13 = 2;
                *reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) =
                    static_cast<int16_t>(reinterpret_cast<char*>(DAT_00860b76)[iVar9_20] * reinterpret_cast<short*>(DAT_00860b7c)[param_1 * 8]);
                FUN_0044d140(0xd, static_cast<int32_t>(param_1), 0xd);
                *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) = *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) | 0x800000;
                *reinterpret_cast<int16_t*>(DAT_00814322 + iVar15) = 3;
                goto LAB_004146e4;
            }
            break;
        }
        case 2: {
            int32_t r = FUN_00412950();
            if (static_cast<int32_t>(static_cast<uint8_t>(reinterpret_cast<uint8_t*>(DAT_00860b75)[*reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) * 0x20])) <= r) {
                *reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) = 3;
                FUN_00413400(local_1c);
                int32_t idx = static_cast<int32_t>(*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15)) * 0x44;
                *reinterpret_cast<int16_t*>(DAT_0081432a + iVar15) =
                    static_cast<int16_t>(reinterpret_cast<short*>(DAT_00723b1c)[idx] - reinterpret_cast<short*>(DAT_00723b18)[idx]);
                FUN_0044d140(0xe, static_cast<int32_t>(param_1), 0xe);
                *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) = *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) | 0x800000;
            }
            break;
        }
        case 3: {
            if ((reinterpret_cast<char*>(DAT_00860b74)[iVar12_20] == reinterpret_cast<char*>(DAT_00860b74)[iVar9_20]) &&
                ((reinterpret_cast<int32_t*>(DAT_00860b70)[param_3 * 8] & 0x800) != 0 ||
                 reinterpret_cast<short*>(DAT_0085bf7c)[param_3 * 0x4a] < -1)) {
                int32_t cc = static_cast<int32_t>(reinterpret_cast<char*>(DAT_00860b74)[iVar12_20]);
                if (cc < 0) {
                    cc = 0;
                } else if (4 < cc) {
                    cc = 4;
                }
                uint32_t r = static_cast<uint32_t>(std::rand());
                r = r & 0x80000003u;
                if (static_cast<int32_t>(r) < 0) {
                    r = (r - 1 | 0xfffffffc) + 1;
                }
                *reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) = static_cast<int16_t>(reinterpret_cast<char*>(DAT_007252d1)[cc * 5 + static_cast<int32_t>(r)]);
                FUN_00413400(local_1c);
                int32_t idx = static_cast<int32_t>(*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15)) * 0x44;
                *reinterpret_cast<int16_t*>(DAT_0081432a + iVar15) = static_cast<int16_t>(reinterpret_cast<int32_t*>(DAT_00723b1c)[idx] / 2);
                *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15) = static_cast<int16_t>(reinterpret_cast<uint16_t>(reinterpret_cast<int32_t*>(DAT_00723b18)[idx]));
                *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) = static_cast<int16_t>(reinterpret_cast<int32_t*>(DAT_00723b14)[idx] / 2);
                uint32_t r2 = static_cast<uint32_t>(std::rand());
                r2 = r2 & 0x800000ffu;
                if (static_cast<int32_t>(r2) < 0) {
                    r2 = (r2 - 1 | 0xffffff00) + 1;
                }
                *reinterpret_cast<int16_t*>(DAT_00814324 + iVar15) = static_cast<int16_t>(r2);
                i13 = 2;
                int16_t ss = reinterpret_cast<short*>(DAT_00860b7c)[param_1 * 8];
                *reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) = static_cast<int16_t>(ss * 5);
                FUN_0044d140(0xf, static_cast<int32_t>(param_1), 0xf);
                *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) = *reinterpret_cast<uint32_t*>(DAT_00814350 + iVar15) | 0x800000;
                local_8 = static_cast<int32_t>(*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15));
                *reinterpret_cast<int16_t*>(DAT_00814322 + iVar15) = 3;
                goto LAB_004146e4;
            }
        }
        }
    LAB_004146e4:
        if (*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) != local_8) {
            int32_t ii = reinterpret_cast<int32_t*>(DAT_00723b18)[*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) * 0x44];
            char cc;
            if (ii / i13 < 1) {
                cc = '\0';
            } else {
                int32_t r = std::rand();
                cc = static_cast<char>(r % (ii / i13));
            }
            int32_t idx = static_cast<int32_t>(*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15)) * 0x44;
            *reinterpret_cast<int16_t*>(DAT_00814320 + iVar15) =
                static_cast<int16_t>(static_cast<uint8_t>(static_cast<char>(reinterpret_cast<int32_t*>(DAT_00723b18)[idx] / i13) + cc + 1) & 0xfe);
            int16_t ss = static_cast<int16_t>(reinterpret_cast<int32_t*>(DAT_00723b14)[idx] / i13);
            *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) = ss;
            if (ss < 1) {
                ss = 0;
            } else {
                int32_t r = std::rand();
                ss = static_cast<int16_t>(r % static_cast<int32_t>(ss));
            }
            *reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) = static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_0081431e + iVar15) + ss);
            uint32_t r = static_cast<uint32_t>(std::rand());
            r = r & 0x80000007u;
            if (static_cast<int32_t>(r) < 0) {
                r = (r - 1 | 0xfffffff8) + 1;
            }
            *reinterpret_cast<int16_t*>(DAT_00814324 + iVar15) =
                static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_00814324 + iVar15) | static_cast<int16_t>(static_cast<uint16_t>(1u << (static_cast<uint8_t>(r) & 0x1f))));
            uint32_t r2 = static_cast<uint32_t>(std::rand());
            r2 = r2 & 0x80000007u;
            if (static_cast<int32_t>(r2) < 0) {
                r2 = (r2 - 1 | 0xfffffff8) + 1;
            }
            *reinterpret_cast<int16_t*>(DAT_00814324 + iVar15) =
                static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_00814324 + iVar15) | static_cast<int16_t>(static_cast<uint16_t>(1u << (static_cast<uint8_t>(r2) & 0x1f))));
        }
    }
LAB_004148c2:;
    {
        int32_t i12 = FUN_004135d0(-1);
        if (i12 != -1) {
            int32_t r = std::rand();
            if (((r % 300 <= static_cast<int32_t>(reinterpret_cast<short*>(DAT_0085bf7e)[*reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) * 0x4a]) ||
                 (r = std::rand(), r % 300 <= static_cast<int32_t>(reinterpret_cast<short*>(DAT_0085bf7e)[*reinterpret_cast<int16_t*>(DAT_00814338 + iVar15) * 0x4a])) &&
                (((r = static_cast<int32_t>(*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15)) % 9, r == 8 || r == 5) ||
                 ((*reinterpret_cast<int16_t*>(DAT_008142fc + iVar15) == static_cast<int16_t>(reinterpret_cast<char*>(DAT_00860b74)[*reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) * 0x20]) &&
                   99 < static_cast<int32_t>(reinterpret_cast<short*>(DAT_0085bf7e)[*reinterpret_cast<int16_t*>(DAT_00814336 + iVar15) * 0x4a]) &&
                   *reinterpret_cast<int16_t*>(DAT_008142fa + iVar15) == 0)))) {
                int32_t i13b = i12 * 0x45c;
                int16_t* srcp = reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15);
                int16_t* dstp = reinterpret_cast<int16_t*>(DAT_008142f8 + i12 * 0x45c);
                for (int32_t k = 0x117; k != 0; --k) {
                    *dstp = *srcp;
                    dstp += 2;
                    srcp += 2;
                }
                *reinterpret_cast<int16_t*>(DAT_0081435a + iVar15) = static_cast<int16_t>(i12);
                int16_t s3 = *reinterpret_cast<int16_t*>(DAT_008142fc + i12 * 0x45c);
                *reinterpret_cast<int16_t*>(DAT_008142fc + i13b + 2) = 0;
                reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e] = static_cast<int16_t>(-(static_cast<uint16_t>(s3 != 0)) & 0xfff6) + 0x10;
                int32_t rr = std::rand();
                if (rr % 3 != 0) {
                    reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e] =
                        static_cast<int16_t>(-(static_cast<uint16_t>(*reinterpret_cast<int16_t*>(DAT_008142fc + i12 * 0x45c) != 0)) & 0xd) + 7;
                }
                uint32_t uu = static_cast<uint32_t>(std::rand());
                uu = uu & 0x80000001u;
                bool bb = uu == 0;
                if (static_cast<int32_t>(uu) < 0) {
                    bb = (uu - 1 | 0xfffffffe) == 0xffffffffu;
                }
                if (bb || reinterpret_cast<short*>(DAT_0085bf7e)[param_1 * 0x4a] < 100 ||
                    reinterpret_cast<int32_t*>(DAT_00723b08)[*reinterpret_cast<int16_t*>(DAT_008142f8 + iVar15) * 0x44] < 8) {
                    reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e] = 10;
                }
                if (reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e] == 6) {
                    uint32_t u2 = static_cast<uint32_t>(std::rand());
                    u2 = u2 & 0x80000003u;
                    bool b2 = u2 == 0;
                    if (static_cast<int32_t>(u2) < 0) {
                        b2 = (u2 - 1 | 0xfffffffc) == 0xffffffffu;
                    }
                    if (b2) {
                        reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e] = 0xf;
                    }
                }
                int16_t s3b = reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e];
                reinterpret_cast<int16_t*>(DAT_00814322)[i12 * 0x22e] = 3;
                int16_t w1 = static_cast<int16_t>(FUN_00412950());
                reinterpret_cast<int16_t*>(DAT_0081431e)[i12 * 0x22e] = static_cast<int16_t>(reinterpret_cast<short*>(DAT_00723b14)[s3b * 0x44] - w1);
                int32_t c1 = FUN_00412950();
                reinterpret_cast<int16_t*>(DAT_00814320)[i12 * 0x22e] =
                    static_cast<int16_t>(static_cast<uint8_t>((reinterpret_cast<int32_t*>(DAT_00723b18)[reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e] * 0x44] - c1) + 1) & 0xfe);
                FUN_00413080(i12);
                uint32_t u50 = reinterpret_cast<uint32_t*>(DAT_00814350)[i12 * 0x117];
                int16_t s3c = reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e];
                *reinterpret_cast<int16_t*>(DAT_00814328 + i13b) = static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_00813ecc + i13b) / 2);
                *reinterpret_cast<int16_t*>(DAT_00814332 + i13b) = 0;
                *reinterpret_cast<int16_t*>(DAT_0081432e + i13b) = 0;
                *reinterpret_cast<int16_t*>(DAT_0081432a + i13b) =
                    static_cast<int16_t>(reinterpret_cast<short*>(DAT_00723b1c)[s3c * 0x44] - reinterpret_cast<int16_t*>(DAT_00814320)[i12 * 0x22e]);
                *reinterpret_cast<int16_t*>(DAT_0081435a + i13b) = static_cast<int16_t>(-local_1c);
                reinterpret_cast<uint32_t*>(DAT_00814350)[i12 * 0x117] = u50 | 1;
                *reinterpret_cast<int16_t*>(DAT_008142fa + i13b) = 6;
                int32_t d1 = FUN_004db210();
                *reinterpret_cast<int32_t*>(DAT_00814304 + iVar15) = *reinterpret_cast<int32_t*>(DAT_00814304 + iVar15) + d1;
                int32_t d2 = FUN_004db210();
                *reinterpret_cast<int32_t*>(DAT_00814308 + iVar15) = *reinterpret_cast<int32_t*>(DAT_00814308 + iVar15) + d2;
                *reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) = static_cast<int16_t>(*reinterpret_cast<int16_t*>(DAT_00814328 + iVar15) << 1);
                FUN_00413080(i12);
                return local_1c;
            }
            reinterpret_cast<int16_t*>(DAT_008142f8)[i12 * 0x22e] = static_cast<int16_t>(0xffff);
        }
    }
    FUN_00413080(local_1c);
    return local_1c;
}
