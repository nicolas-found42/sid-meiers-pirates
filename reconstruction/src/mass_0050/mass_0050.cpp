// Reconstruction batch mass_0050 — Sid Meier's Pirates! (2004) PE32 i386
// Image 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>

extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void FUN_004e6420();
extern void FUN_004cd0a0(uint32_t v);
extern void FUN_004f3350();
extern void FUN_00412df0();
extern void FUN_00412f90();
extern void FUN_00536f80();
extern void FUN_00537af0();

extern void* PTR_FUN_0070d8fc;
extern void* PTR_FUN_0070d8e0;
extern void* PTR_FUN_0070d868;
extern int DAT_008caccc;
extern uint8_t DAT_008cacd0[];
extern float _DAT_007177e4;
extern float _DAT_007177e0;
extern void* DAT_008cacc8;

// 0x4ccbb0 — observed shape: thiscall-like destructor; sets vtable ptr twice via two calls, deletes member at +8, conditionally deletes self.
void FUN_004ccbb0(void* self, uint8_t param_1) {
    uint32_t* obj = static_cast<uint32_t*>(self);
    obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0070d8fc);
    FUN_004e6420();
    obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0070d8e0);
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(obj[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(obj);
    }
}

// 0x4ccda0 — observed shape: copies string/buffer into DAT_008cacd0 at offset DAT_008caccc, with null-term when growing; returns param_1.
uint32_t FUN_004ccda0(uint32_t param_1, uint32_t* param_2, uint32_t in_EAX) {
    FUN_004cd0a0(in_EAX);
    int iVar1 = DAT_008caccc;
    void* _Src = reinterpret_cast<void*>(static_cast<uintptr_t>(*param_2));
    size_t _Size = *reinterpret_cast<size_t*>(reinterpret_cast<char*>(_Src) - 4);
    if ((0 < static_cast<int>(_Size)) && (-1 < DAT_008caccc) && (_Src != nullptr)) {
        if (DAT_008caccc < static_cast<int>(DAT_008caccc + _Size)) {
            FUN_004f3350();
            DAT_008cacd0[DAT_008caccc] = 0;
        }
        memmove(DAT_008cacd0 + iVar1, _Src, _Size);
    }
    FUN_00412df0();
    return param_1;
}

// 0x4cce40 — observed shape: receiver in_ECX dst, source in_EDX; clamps float in_EDX[4] to [in_EDX[5]/k1, k0], copies fields to +0x128..0x140, calls FUN_00536f80.
void FUN_004cce40(void* self, uint32_t* src) {
    uint32_t* dst = static_cast<uint32_t*>(self);
    float fVar2 = *reinterpret_cast<float*>(&src[4]);
    if (fVar2 < *reinterpret_cast<float*>(&src[5]) / _DAT_007177e4) {
        fVar2 = *reinterpret_cast<float*>(&src[5]) / _DAT_007177e4;
    }
    if (fVar2 < _DAT_007177e0) {
        fVar2 = _DAT_007177e0;
    }
    dst[0x4A] = src[0];          // +0x128
    dst[0x4B] = src[1];          // +0x12C (300)
    dst[0x4C] = src[2];          // +0x130
    dst[0x4D] = src[3];          // +0x134
    *reinterpret_cast<float*>(&dst[0x4E]) = fVar2; // +0x138
    dst[0x4F] = src[5];          // +0x13C
    reinterpret_cast<uint8_t*>(dst)[0x140] = reinterpret_cast<uint8_t*>(src)[6];
    FUN_00536f80();
}

// 0x4ccec0 — observed shape: thiscall-like destructor; sets vtable ptr, calls FUN_00537af0, conditionally deletes self.
void FUN_004ccec0(void* self, uint8_t param_1) {
    uint32_t* obj = static_cast<uint32_t*>(self);
    obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0070d868);
    FUN_00537af0();
    if ((param_1 & 1) != 0) {
        operator_delete(obj);
    }
}

// 0x4ccf00 — observed shape: assigns buffer param_1 into *in_EAX string slot, frees old backing if not static DAT_008cacc8, sets in_EAX[1]=param_2.
void FUN_004ccf00(void* param_1, int param_2, uint32_t** in_EAX_ptr) {
    size_t _Size = *reinterpret_cast<size_t*>(reinterpret_cast<char*>(param_1) - 4);
    uint32_t* in_EAX = static_cast<uint32_t*>(*in_EAX_ptr);
    if ((-1 < static_cast<int>(_Size)) && (param_1 != reinterpret_cast<void*>(*in_EAX))) {
        if (_Size == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(reinterpret_cast<void*>(*in_EAX), param_1, _Size);
            *reinterpret_cast<char*>(*in_EAX + *reinterpret_cast<int*>(*in_EAX - 4)) = 0;
        }
    }
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_1) - 8);
    in_EAX[1] = static_cast<uint32_t>(param_2);
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
}
extern void* FUN_0053c6f0(void* a, void* b, void* c);

// 0x4ccf60 — observed shape: trims leading and trailing BL chars from string held via EDI indirection, memmove, updates -4 size.
void FUN_004ccf60(char unaff_BL, int** unaff_EDI_ptr) {
    char* pcVar2 = reinterpret_cast<char*>(*(*unaff_EDI_ptr));
    if (*reinterpret_cast<int*>(pcVar2 - 4) != 0) {
        char cVar1 = *pcVar2;
        char* pcVar3 = pcVar2;
        while (unaff_BL == cVar1) {
            char* pcVar5 = pcVar3 + 1;
            pcVar3 = pcVar3 + 1;
            cVar1 = *pcVar5;
        }
        if (pcVar3 != pcVar2) {
            *reinterpret_cast<char**>(pcVar2 - 4) = pcVar2 + (*reinterpret_cast<int*>(pcVar2 - 4) - static_cast<int>(reinterpret_cast<intptr_t>(pcVar3)));
            memmove(reinterpret_cast<void*>(*(*unaff_EDI_ptr)), pcVar3, *reinterpret_cast<int*>(*(*unaff_EDI_ptr) - 4) + 1);
        }
    }
    pcVar2 = reinterpret_cast<char*>(*(*unaff_EDI_ptr));
    if ((*reinterpret_cast<int*>(pcVar2 - 4) != 0) && (pcVar2 <= pcVar2 + *reinterpret_cast<int*>(pcVar2 - 4) + -1)) {
        char* pcVar3 = pcVar2 + *reinterpret_cast<int*>(pcVar2 - 4) + -1;
        char* pcVar5 = nullptr;
        do {
            char* pcVar4 = pcVar3;
            if (*pcVar4 != unaff_BL) break;
            pcVar3 = pcVar4 + -1;
            pcVar5 = pcVar4;
        } while (pcVar2 <= pcVar4 + -1);
        if (pcVar5 != nullptr) {
            *pcVar5 = '\0';
            *reinterpret_cast<int*>(*(*unaff_EDI_ptr) - 4) = static_cast<int>(reinterpret_cast<intptr_t>(pcVar5) - reinterpret_cast<intptr_t>(*(*unaff_EDI_ptr)));
        }
    }
}

// 0x4ccfd0 — observed shape: copy string *in_EAX into DAT_008cacd0, then append single char param_2 if non-zero; returns param_1.
uint32_t FUN_004ccfd0(uint32_t param_1, char param_2, uint32_t** in_EAX_ptr) {
    uint32_t* in_EAX = *in_EAX_ptr;
    uint8_t* _Src = reinterpret_cast<uint8_t*>(*in_EAX);
    size_t _Size = *reinterpret_cast<size_t*>(_Src - 4);
    if ((-1 < static_cast<int>(_Size)) && (_Src != nullptr) && (_Src != DAT_008cacd0)) {
        if (_Size == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(DAT_008cacd0, _Src, _Size);
            DAT_008cacd0[DAT_008caccc] = 0;
        }
    }
    int iVar1 = DAT_008caccc;
    uint32_t _Size_00 = (param_2 != '\0') ? 1 : 0;
    if ((_Size_00 != 0) && (-1 < DAT_008caccc)) {
        if (DAT_008caccc < static_cast<int>(DAT_008caccc + _Size_00)) {
            FUN_004f3350();
            DAT_008cacd0[DAT_008caccc] = 0;
        }
        memmove(DAT_008cacd0 + iVar1, &param_2, _Size_00);
    }
    FUN_00412df0();
    return param_1;
}

// 0x4cd0a0 — observed shape: single-char assign into *in_EAX string slot; if param_1 zero clears via FUN_00412f90.
void FUN_004cd0a0(char param_1, uint32_t** in_EAX_ptr) {
    uint32_t* in_EAX = *in_EAX_ptr;
    bool bVar1 = param_1 != '\0';
    if (&param_1 != reinterpret_cast<uint8_t*>(*in_EAX)) {
        if (bVar1) {
            FUN_004f3350();
            memmove(reinterpret_cast<void*>(*in_EAX), &param_1, static_cast<uint32_t>(bVar1));
            *reinterpret_cast<uint8_t*>(*in_EAX + *reinterpret_cast<int*>(*in_EAX - 4)) = 0;
            return;
        }
        FUN_00412f90();
    }
}

// 0x4cd100 — observed shape: destructor; resets string to DAT_008cacd0, frees backing if not static, conditionally deletes self.
void FUN_004cd100(void* self, uint8_t param_1) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    if (in_ECX[1] != 0) {
        FUN_004cd100(in_ECX, 1);
        in_ECX[1] = 0;
    }
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(in_ECX[0] - 8);
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    in_ECX[0] = reinterpret_cast<uint32_t>(DAT_008cacd0);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x4cd170 — observed shape: zeroes receiver 0x00..0x3C with in_EAX[4]=0x3f800000, [0xb]=0xFFFFFFFF, refcount-release at [0x10], then copies 9 dwords from FUN_0053c6f0 result to +0x44.
void FUN_004cd170(void* self) {
    uint32_t* in_EAX = static_cast<uint32_t*>(self);
    in_EAX[0xd] = 0;
    in_EAX[0xe] = 0;
    in_EAX[0] = 0;
    in_EAX[1] = 0;
    in_EAX[2] = 0;
    in_EAX[3] = 0;
    in_EAX[4] = 0x3f800000;
    in_EAX[5] = 0;
    in_EAX[6] = 0;
    in_EAX[7] = 0;
    in_EAX[8] = 0;
    in_EAX[9] = 0;
    in_EAX[10] = 0;
    in_EAX[0xb] = 0xffffffff;
    in_EAX[0xc] = 0;
    in_EAX[0xf] = 0;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_EAX[0x10]);
    uint32_t local_48 = 0;
    uint32_t local_44 = 0;
    uint32_t local_40 = 0;
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            auto fn = reinterpret_cast<void(*)(uint32_t)>(*puVar2);
            fn(1);
        }
        in_EAX[0x10] = 0;
    }
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    uint32_t local_3c = 0;
    uint32_t local_38 = 0;
    uint32_t local_34 = 0;
    uint32_t local_30 = 0;
    uint32_t local_2c = 0;
    uint32_t local_28 = 0;
    puVar2 = static_cast<uint32_t*>(FUN_0053c6f0(&local_30, &local_3c, &local_48));
    uint32_t* puVar4 = in_EAX + 0x11;
    for (int iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
    }
}

// 0x4cd250 — observed shape: destructor; sets vtable PTR_FUN_0070d8dc, clears [0x1f], frees and resets 10 string slots at stride 3 dwords ending before +0x21.
void FUN_004cd250(void* self) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0070d8dc);
    in_ECX[0x1f] = 0;
    uint32_t* puVar3 = in_ECX + 0x21;
    int iVar4 = 10;
    do {
        int* piVar1 = reinterpret_cast<int*>(puVar3 - 3);
        puVar3 = puVar3 - 3;
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*piVar1 - 8);
        if ((puVar2 != nullptr) && (puVar2 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
        }
        iVar4 = iVar4 + -1;
        *puVar3 = reinterpret_cast<uint32_t>(DAT_008cacd0);
    } while (iVar4 != 0);
}

// 0x4cd2a0 — observed shape: destructor; if byte +0x11 set, walks bucket array at [2] with [1] count, frees each node's string and node; then base destructor sequence.
void FUN_004cd2a0(void* self) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0070d918);
    if ((reinterpret_cast<char*>(in_ECX)[0x11] != '\0') && (in_ECX[1] != 0)) {
        uint32_t uVar4 = 0;
        do {
            uint32_t* puVar1 = reinterpret_cast<uint32_t*>(in_ECX[2] + uVar4 * 4);
            while (puVar1 != nullptr) {
                int* piVar2 = reinterpret_cast<int*>(puVar1[1]);
                puVar1 = reinterpret_cast<uint32_t*>(*puVar1);
                if (piVar2 != nullptr) {
                    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(*piVar2 - 8);
                    if ((puVar3 != nullptr) && (puVar3 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                        operator_delete__(puVar3);
                    }
                    *piVar2 = reinterpret_cast<int>(DAT_008cacd0);
                    operator_delete(piVar2);
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < in_ECX[1]);
    }
    in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0070d8fc);
    FUN_004e6420();
    in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0070d8e0);
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(in_ECX[2]));
}

extern void* thunk_FUN_00533c78(uint32_t size);
extern uint32_t _DAT_008c95e4;
extern uint32_t _DAT_008c95e8;
extern uint32_t _DAT_008c95e0;
extern uint32_t _DAT_008c95ec;
extern int DAT_008c95f4;
extern int DAT_008c95f0;
extern uint8_t* DAT_008c95f8;

// 0x4cd340 — observed shape: parses RLE sprite block header (type 0xc, cmd 10, sub>=5, w/h fields), decodes rows into DAT_008c95f8, computes frame min/max, returns end-pointer match flag.
uint32_t FUN_004cd340(uint8_t* param_1, int in_ECX) {
    uint8_t* pbVar1 = param_1 + in_ECX + -0x300;
    uint8_t* pbVar3 = param_1;
    if ((((param_1[in_ECX + -0x301] != 0xc) || (pbVar3 = param_1 + 0x80, *param_1 != 10)) ||
         (param_1[1] < 5)) || (((param_1[2] != 1 || (param_1[3] != 8)) || (param_1[0x41] != 1)))) {
        return reinterpret_cast<uintptr_t>(pbVar3) & 0xffffff00u;
    }
    DAT_008c95f4 = (static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 8)) - static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 4))) + 1;
    DAT_008c95f0 = (static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 10)) - static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 6))) + 1;
    int iVar4 = DAT_008c95f0 * DAT_008c95f4;
    int iVar13 = 0;
    int local_18 = 0;
    uint8_t* pbVar5 = static_cast<uint8_t*>(thunk_FUN_00533c78(static_cast<uint32_t>(iVar4 * 4)));
    DAT_008c95f8 = pbVar5;
    if (pbVar5 == nullptr) {
        return 0;
    }
    int* piVar6 = static_cast<int*>(thunk_FUN_00533c78(static_cast<uint32_t>(DAT_008c95f0 * 4)));
    int iVar2 = DAT_008c95f0;
    *piVar6 = 0;
    uint32_t* puVar7 = static_cast<uint32_t*>(thunk_FUN_00533c78(static_cast<uint32_t>(iVar2 * 4)));
    *puVar7 = 0;
    param_1 = pbVar3;
    if (iVar4 != 0) {
        int* local_1c = piVar6;
        do {
            uint8_t bVar12 = *param_1;
            uint8_t bVar8;
            if ((bVar12 & 0xc0) == 0xc0) {
                bVar8 = bVar12 & 0x3f;
                bVar12 = param_1[1];
                param_1 = param_1 + 2;
            } else {
                bVar8 = 1;
                param_1 = param_1 + 1;
            }
            uint32_t uVar11 = static_cast<uint32_t>(bVar8);
            iVar4 = iVar4 - static_cast<int>(uVar11);
            iVar13 = iVar13 + static_cast<int>(uVar11);
            iVar2 = static_cast<uint32_t>(bVar12) * 3;
            uint8_t bVar9 = 0;
            if (bVar8 != 0) {
                bVar9 = bVar8;
                do {
                    *pbVar5 = pbVar1[iVar2];
                    bVar9 = bVar9 - 1;
                    pbVar5[1] = pbVar1[iVar2 + 1];
                    pbVar5[2] = pbVar1[iVar2 + 2];
                    pbVar5[3] = static_cast<uint8_t>((bVar12 == 0xff) - 1);
                    pbVar5 = pbVar5 + 4;
                    uVar11 = uVar11 - 1;
                } while (uVar11 != 0);
            }
            if (bVar12 != 0xff) {
                if (*local_1c == 0) {
                    *local_1c = iVar13;
                }
                *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar7) - reinterpret_cast<intptr_t>(piVar6) + reinterpret_cast<intptr_t>(local_1c)) =
                    static_cast<uint32_t>((static_cast<uint8_t>(bVar9 - 1) - 1) + iVar13);
            }
            if (DAT_008c95f4 <= iVar13) {
                iVar13 = 0;
                local_18 = local_18 + 1;
                local_1c = local_1c + 1;
            }
        } while (iVar4 != 0);
    }
    _DAT_008c95e4 = 0;
    if (0 < local_18) {
        do {
            if (piVar6[_DAT_008c95e4] != 0) break;
            _DAT_008c95e4 = _DAT_008c95e4 + 1;
        } while (static_cast<int>(_DAT_008c95e4) < local_18);
    }
    do {
        _DAT_008c95ec = static_cast<uint32_t>(local_18 - 1);
        if (static_cast<int>(_DAT_008c95ec) < 1) break;
        local_18 = static_cast<int>(_DAT_008c95ec);
    } while (puVar7[_DAT_008c95ec] == 0);
    local_18 = 9999;
    int local_14 = -1;
    _DAT_008c95e8 = 0xffffffffu;
    if (static_cast<int>(_DAT_008c95e4) <= static_cast<int>(_DAT_008c95ec)) {
        uint32_t* piVar10 = puVar7 + _DAT_008c95e4;
        iVar4 = (static_cast<int>(_DAT_008c95ec) - static_cast<int>(_DAT_008c95e4)) + 1;
        do {
            iVar13 = *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar6) - reinterpret_cast<intptr_t>(puVar7) + reinterpret_cast<intptr_t>(piVar10));
            if (iVar13 < local_18) {
                local_18 = iVar13;
            }
            if (local_14 < static_cast<int>(*piVar10)) {
                local_14 = static_cast<int>(*piVar10);
            }
            piVar10 = piVar10 + 1;
            iVar4 = iVar4 + -1;
            _DAT_008c95e8 = static_cast<uint32_t>(local_14);
        } while (iVar4 != 0);
    }
    _DAT_008c95e0 = static_cast<uint32_t>(local_18 - 1);
    _DAT_008c95e8 = _DAT_008c95e8 + -1;
    operator_delete__(piVar6);
    operator_delete__(puVar7);
    return static_cast<uint32_t>(param_1 + 1 == pbVar1);
}

extern void FUN_004f4b20(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern void FUN_004f10f0(void* dst, uint32_t size);
extern uint32_t FUN_004f4de0();
extern void FUN_004f0dc0();

// 0x4cd5d0 — observed shape: reads resource via FUN_004f4b20, allocates local_c bytes, loads, decodes with FUN_004cd340, frees buffers, returns decode result.
uint8_t FUN_004cd5d0(uint32_t in_EAX) {
    uint32_t local_c = 0;
    FUN_004f4b20(in_EAX, 1, 0, 0x8000);
    void* pvVar2 = thunk_FUN_00533c78(local_c);
    FUN_004f10f0(pvVar2, local_c);
    uint8_t uVar1 = static_cast<uint8_t>(FUN_004cd340(static_cast<uint8_t*>(pvVar2), 0));
    FUN_004f4de0();
    if (pvVar2 != nullptr) {
        operator_delete__(pvVar2);
    }
    FUN_004f4de0();
    FUN_004f0dc0();
    return uVar1;
}

extern int FUN_00539210(uint32_t w, uint32_t h, void* fmt, uint32_t flags);
extern void* FUN_00539cc0(int surf, void* fmt);
extern void* DAT_00727484;
extern void* DAT_007179a4;

// 0x4cd6d0 — observed shape: builds power-of-two surface from DAT_008c95f8 (DAT_008c95f4 x DAT_008c95f0), copies rows, zero-pads, returns new surface object; frees source.
int* FUN_004cd6d0(int param_1, int param_2, uint32_t* param_3, uint32_t* param_4, int in_EAX) {
    if (in_EAX == 0) {
        return nullptr;
    }
    FUN_004cd5d0(static_cast<uint32_t>(in_EAX));
    if (*param_3 == 0) {
        *param_3 = static_cast<uint32_t>(DAT_008c95f4 - param_1);
    }
    if (*param_4 == 0) {
        *param_4 = static_cast<uint32_t>(DAT_008c95f0 - param_2);
    }
    uint32_t uVar5 = 1;
    if (1 < static_cast<int>(*param_3)) {
        do {
            uVar5 = uVar5 * 2;
        } while (static_cast<int>(uVar5) < static_cast<int>(*param_3));
    }
    int iVar8 = 1;
    int local_10 = 1;
    if (1 < *param_4) {
        do {
            iVar8 = iVar8 * 2;
            local_10 = iVar8;
        } while (iVar8 < static_cast<int>(*param_4));
    }
    iVar8 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x50)));
    int local_8;
    if (iVar8 == 0) {
        local_8 = 0;
    } else {
        local_8 = FUN_00539210(uVar5, static_cast<uint32_t>(local_10), &DAT_00727484, 1);
    }
    iVar8 = DAT_008c95f4;
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(**reinterpret_cast<int**>(local_8 + 0x40) + *reinterpret_cast<int*>(local_8 + 0x34));
    uint32_t* puVar6 = reinterpret_cast<uint32_t*>(DAT_008c95f8 + (DAT_008c95f4 * param_2 + param_1) * 4);
    int local_c = 0;
    if (0 < local_10) {
        do {
            if (local_c < static_cast<int>(*param_4)) {
                uint32_t* puVar7 = puVar6;
                uint32_t* puVar9 = puVar4;
                for (uint32_t uVar2 = *param_3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
                    *puVar9 = *puVar7;
                    puVar7 = puVar7 + 1;
                    puVar9 = puVar9 + 1;
                }
                for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *reinterpret_cast<uint8_t*>(puVar9) = *reinterpret_cast<uint8_t*>(puVar7);
                    puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar7) + 1);
                    puVar9 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar9) + 1);
                }
                uint32_t uVar2 = *param_3;
                if (static_cast<int>(uVar2) < static_cast<int>(uVar5)) {
                    puVar7 = puVar4 + uVar2;
                    uVar2 = uVar5 - uVar2;
                    for (uVar2 = uVar2 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
                        *puVar7 = 0;
                        puVar7 = puVar7 + 1;
                    }
                    continue;
                }
            } else {
                uint32_t* puVar7 = puVar4;
                uint32_t uVar2 = uVar5;
                for (uVar2 = uVar2 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                }
            }
            puVar4 = puVar4 + uVar5;
            puVar6 = puVar6 + iVar8;
            local_c = local_c + 1;
        } while (local_c < local_10);
    }
    operator_delete__(DAT_008c95f8);
    int* piVar1 = static_cast<int*>(FUN_00539cc0(local_8, &DAT_007179a4));
    auto vtblCall = *reinterpret_cast<void(**)(void)>(static_cast<intptr_t>(*piVar1) + 0x40);
    (void)vtblCall;
    return piVar1;
}

extern void* FUN_0054aad0();
extern void* FUN_0050baf0(void* fn, uint32_t arg);
extern void FUN_0050bbc0(uint32_t v);
extern void FUN_0050ba80();

extern void* FUN_0054b1a0(int surf);
extern void* FUN_00500850();
extern int FUN_005f0ddc();
extern uint32_t FUN_004f5ef0(void* out);
extern void* FUN_004129c0(void* out, uint32_t v);
extern void FUN_00412f10();
extern void* FUN_004d1240;
extern int DAT_008cac18;
extern int DAT_008ea08c;
extern int DAT_00727c30;
extern int DAT_008ca9b8;
extern int DAT_008cac58;
extern int DAT_00726a84;
extern uint32_t DAT_007263bc;
extern uint32_t DAT_007268f4[];
extern void FUN_004dcbf0();
extern int _strnicmp(const char*, const char*, size_t);
extern int _stricmp(const char*, const char*);
extern char* _strupr(char*);

// 0x4cd860 — observed shape: copies filename into 256-byte local, queries texture dims, builds pow2 surface, blits rows (width from puVar5[0xe], pitch puVar5[0x12]), zero-pads, returns surface.
int* FUN_004cd860(int* param_1, const char* name, int in_ECX, int* unaff_retaddr, int iStack_4) {
    char local_104[256];
    if (name == nullptr) {
        return nullptr;
    }
    intptr_t iVar15 = -reinterpret_cast<intptr_t>(name);
    const char* pc = name;
    char cVar1;
    do {
        cVar1 = *pc;
        local_104[reinterpret_cast<intptr_t>(pc) + iVar15] = cVar1;
        pc = pc + 1;
    } while (cVar1 != '\0');
    int* piVar4 = static_cast<int*>(FUN_0054aad0());
    uint32_t* puVar5 = static_cast<uint32_t*>(
        reinterpret_cast<void*(*)(char*, uint32_t)>(*reinterpret_cast<void**>(static_cast<intptr_t>(*piVar4) + 8))(local_104, 0));
    if (*unaff_retaddr == 0) {
        *unaff_retaddr = *reinterpret_cast<int*>(static_cast<intptr_t>(puVar5[0xe])) - iStack_4;
    }
    if (*param_1 == 0) {
        *param_1 = *reinterpret_cast<int*>(static_cast<intptr_t>(puVar5[0xf])) - in_ECX;
    }
    int iVar15b = 1;
    if (1 < *unaff_retaddr) {
        do {
            iVar15b = iVar15b * 2;
        } while (iVar15b < *unaff_retaddr);
    }
    int iVar14 = 1;
    if (1 < *param_1) {
        do {
            iVar14 = iVar14 * 2;
        } while (iVar14 < *param_1);
    }
    int iVar2 = static_cast<int>(puVar5[0x12]);
    int iVar6 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x50)));
    int iStack_120;
    if (iVar6 == 0) {
        iStack_120 = 0;
    } else {
        iStack_120 = FUN_00539210(static_cast<uint32_t>(iVar15b), static_cast<uint32_t>(iVar14), puVar5 + 3, 1);
    }
    uint32_t uVar7 = static_cast<uint32_t>(**reinterpret_cast<int**>(static_cast<intptr_t>(iStack_120) + 0x38) * iVar2);
    iVar6 = *reinterpret_cast<int*>(static_cast<intptr_t>(puVar5[0xe]));
    uint32_t* puVar11 = reinterpret_cast<uint32_t*>(**reinterpret_cast<int**>(static_cast<intptr_t>(iStack_120) + 0x40) +
                                                    *reinterpret_cast<int*>(static_cast<intptr_t>(iStack_120) + 0x34));
    uint32_t* puVar10 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar6 * iVar2 * in_ECX + iVar2 * iStack_4 +
                                                                        *reinterpret_cast<int*>(static_cast<intptr_t>(puVar5[0x10])) + puVar5[0xd]));
    int iStack_11c = 0;
    if (0 < iVar14) {
        do {
            uint32_t uVar8 = uVar7;
            uint32_t* puVar13 = puVar11;
            if (iStack_11c < *param_1) {
                int iVar3 = *unaff_retaddr;
                puVar13 = puVar10;
                uint32_t* puVar12 = puVar11;
                for (uVar8 = static_cast<uint32_t>(iVar3 * iVar2) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                    *puVar12 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar12 = puVar12 + 1;
                }
                for (uVar8 = static_cast<uint32_t>(iVar3 * iVar2) & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                    *reinterpret_cast<uint8_t*>(puVar12) = *reinterpret_cast<uint8_t*>(puVar13);
                    puVar13 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar13) + 1);
                    puVar12 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar12) + 1);
                }
                iVar3 = *unaff_retaddr;
                if (iVar3 < iVar15b) {
                    uVar8 = static_cast<uint32_t>((iVar15b - iVar3) * iVar2);
                    puVar13 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar3 * iVar2 + reinterpret_cast<intptr_t>(puVar11)));
                }
            }
            for (uint32_t uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                *puVar13 = 0;
                puVar13 = puVar13 + 1;
            }
            for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *reinterpret_cast<uint8_t*>(puVar13) = 0;
                puVar13 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar13) + 1);
            }
            puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar11) + uVar7);
            puVar10 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar10) + iVar6 * iVar2);
            iStack_11c = iStack_11c + 1;
        } while (iStack_11c < iVar14);
    }
    piVar4 = static_cast<int*>(FUN_00539cc0(iStack_120, &DAT_007179a4));
    auto notifier = *reinterpret_cast<void(**)(void)>(static_cast<intptr_t>(*piVar4) + 0x40);
    if (notifier) notifier();
    auto dtor = *reinterpret_cast<void(**)(uint32_t)>(static_cast<intptr_t>(*puVar5));
    dtor(1);
    return piVar4;
}

// 0x4cda50 — observed shape: allocates 0x14 context, resolves texture, gets height via vtbl+0x28, builds surface param_1 x param_2, copies rows swapping byte order and forcing alpha, returns surface.
uint32_t FUN_004cda50(uint32_t param_1, uint32_t param_2, uint32_t unaff_ESI, uint32_t unaff_EDI) {
    uint32_t* piVar2 = static_cast<uint32_t*>(FUN_00533c78(0x14));
    uint32_t* piVar9 = nullptr;
    if (piVar2 != nullptr) {
        *piVar2 = 0;
        piVar2[1] = 0;
        piVar9 = piVar2;
    }
    FUN_0050baf0(&FUN_004d1240, param_1);
    uint32_t* puVar8 = reinterpret_cast<uint32_t*>(*piVar9);
    if (puVar8 != nullptr) {
        puVar8[1] = puVar8[1] + 1;
    }
    if (puVar8 != nullptr) {
        piVar2 = puVar8 + 1;
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
            auto dtor = *reinterpret_cast<void(**)(uint32_t)>(static_cast<intptr_t>(*puVar8));
            dtor(1);
        }
    }
    if (puVar8 == nullptr) {
        int local_10 = 0;
        uint32_t local_c[3] = {0, 0, 0};
        return FUN_004cddf0("empty.dds", 0, nullptr, &local_10, reinterpret_cast<int*>(local_c));
    }
    FUN_0050bbc0(0);
    puVar8 = reinterpret_cast<uint32_t*>(*piVar9);
    int local_10 = 0;
    int iStack_14 = 0;
    if (puVar8 != nullptr) {
        puVar8[1] = puVar8[1] + 1;
    }
    int iVar4 = static_cast<int>(reinterpret_cast<intptr_t>(
        reinterpret_cast<int*(*)(void)>(*reinterpret_cast<void**>(static_cast<intptr_t>(*reinterpret_cast<int*>(static_cast<intptr_t>(puVar8[0xb]))) + 0x28))()));
    uint32_t local_c0 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar4) + 0xc);
    piVar2 = puVar8 + 1;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
        auto dtor = *reinterpret_cast<void(**)(uint32_t)>(static_cast<intptr_t>(*puVar8));
        dtor(1);
    }
    int iVar5 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x50)));
    iVar4 = 0;
    if ((iVar5 != 0) && ((iVar5 = FUN_00539210(param_1, param_2, &DAT_00727484, 1)) != 0)) {
        *reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) + 4) = *reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) + 4) + 1;
        iVar4 = iVar5;
        iStack_14 = iVar5;
    }
    iVar5 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_0054b1a0(iVar4)));
    if (iVar5 != 0) {
        *reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) + 4) = *reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) + 4) + 1;
        local_10 = iVar5;
    }
    piVar2 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(static_cast<intptr_t>(local_10) + 0x18) + 0xc);
    int* piVar6;
    if (DAT_008ea08c == 0) {
        piVar6 = nullptr;
    } else {
        piVar6 = *reinterpret_cast<int**>(static_cast<intptr_t>(DAT_00727c30) + 0x60);
    }
    auto blit = *reinterpret_cast<void(**)(int*, uint32_t, int*)>(static_cast<intptr_t>(*piVar6) + 0x80);
    blit(piVar6, local_c0, piVar2);
    FUN_0050ba80();
    operator_delete(piVar9);
    uint32_t* puVar12 = nullptr;
    auto lockSurf = *reinterpret_cast<void(**)(int*, int*, uint32_t)>(static_cast<intptr_t>(*piVar2) + 0x34);
    lockSurf(piVar2, &iStack_14, 0);
    uint32_t* puVar8b = reinterpret_cast<uint32_t*>(**reinterpret_cast<int**>(static_cast<intptr_t>(iVar4) + 0x40) +
                                                    *reinterpret_cast<int*>(static_cast<intptr_t>(iVar4) + 0x34));
    iVar4 = 0;
    if (0 < iStack_14) {
        do {
            uint32_t* puVar10 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(unaff_EDI * static_cast<uint32_t>(iVar4) + unaff_ESI));
            uint32_t* puVar11 = puVar8b;
            for (uint32_t uVar7 = unaff_EDI >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar11 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar11 = puVar11 + 1;
            }
            for (uint32_t uVar7 = unaff_EDI & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *reinterpret_cast<uint8_t*>(puVar11) = *reinterpret_cast<uint8_t*>(puVar10);
                puVar10 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar10) + 1);
                puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar11) + 1);
            }
            int iVar5b = 0;
            if (0 < static_cast<int>(unaff_EDI)) {
                do {
                    intptr_t base = reinterpret_cast<intptr_t>(puVar8b);
                    *reinterpret_cast<uint8_t*>(iVar5b + base) =
                        static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(iVar5b + base) ^
                                             *reinterpret_cast<uint8_t*>(iVar5b + 2 + base));
                    uint8_t* pbVar1 = reinterpret_cast<uint8_t*>(iVar5b + 2 + base);
                    *pbVar1 = static_cast<uint8_t>(*pbVar1 ^ *reinterpret_cast<uint8_t*>(iVar5b + base));
                    *reinterpret_cast<uint8_t*>(iVar5b + base) =
                        static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(iVar5b + base) ^ *pbVar1);
                    *reinterpret_cast<uint8_t*>(iVar5b + 3 + base) = 0xff;
                    iVar5b = iVar5b + 4;
                } while (iVar5b < static_cast<int>(unaff_EDI));
            }
            puVar8b = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar8b) + unaff_EDI);
            iVar4 = iVar4 + 1;
        } while (iVar4 < iStack_14);
    }
    auto unlock = *reinterpret_cast<void(**)(int*)>(static_cast<intptr_t>(*piVar2) + 0x38);
    unlock(piVar2);
    uint32_t uVar3 = FUN_00539cc0(static_cast<int>(reinterpret_cast<intptr_t>(puVar12)), &DAT_007179a4);
    iVar4 = static_cast<int>(puVar12[1]);
    puVar12[1] = static_cast<uint32_t>(iVar4 - 1);
    if (iVar4 - 1 == 0) {
        auto dtor2 = *reinterpret_cast<void(**)(uint32_t)>(static_cast<intptr_t>(*puVar12));
        dtor2(1);
    }
    piVar9 = piVar6 + 1;
    *piVar9 = *piVar9 + -1;
    if (*piVar9 == 0) {
        auto dtor3 = *reinterpret_cast<void(**)(uint32_t)>(static_cast<intptr_t>(*piVar6));
        dtor3(1);
    }
    return uVar3;
}

// 0x4cdc50 — observed shape: creates surface param_2 x param_3, iterates rows via FUN_005f0ddc offsets, writes 4 channels in order 2,0,1,3, returns surface.
uint32_t FUN_004cdc50(int param_1, int param_2, int param_3) {
    uint32_t* local_1c = nullptr;
    int iVar2 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x50)));
    if (iVar2 != 0) {
        uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00539210(static_cast<uint32_t>(param_2), static_cast<uint32_t>(param_3), &DAT_00727484, 1));
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
            local_1c = puVar3;
        }
    }
    int iVar2b = static_cast<int>(local_1c[0x12]);
    int iVar1 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_1) + 0x48);
    int local_20 = 0;
    if (0 < param_3) {
        do {
            int iVar9 = *reinterpret_cast<int*>(static_cast<intptr_t>(local_1c[0xe])) * iVar2b * local_20 +
                        *reinterpret_cast<int*>(static_cast<intptr_t>(local_1c[0x10])) + local_1c[0xd];
            int iVar4 = FUN_005f0ddc();
            int iVar8 = iVar4 * **reinterpret_cast<int**>(static_cast<intptr_t>(param_1) + 0x38) * *reinterpret_cast<int*>(static_cast<intptr_t>(param_1) + 0x48) +
                        **reinterpret_cast<int**>(static_cast<intptr_t>(param_1) + 0x40) + *reinterpret_cast<int*>(static_cast<intptr_t>(param_1) + 0x34);
            iVar4 = 0;
            if (0 < param_2) {
                uint8_t* puVar7 = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar9) + 1);
                intptr_t iVar6 = static_cast<intptr_t>(iVar9) - reinterpret_cast<intptr_t>(puVar7);
                intptr_t iVar10 = iVar6;
                intptr_t iVar9b = iVar6;
                int iVar11 = param_2;
                do {
                    iVar4 = iVar4 * iVar1;
                    uint8_t* src = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar8) + iVar4);
                    puVar7[iVar9b] = src[2];
                    *puVar7 = src[1];
                    puVar7[iVar6 + 2] = src[0];
                    puVar7[iVar10 + 3] = src[3];
                    iVar4 = FUN_005f0ddc();
                    puVar7 = puVar7 + iVar2b;
                    iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
            }
            local_20 = local_20 + 1;
        } while (local_20 < param_3);
    }
    uint32_t uVar5 = FUN_00539cc0(static_cast<int>(reinterpret_cast<intptr_t>(local_1c)), &DAT_007179a4);
    iVar2 = static_cast<int>(local_1c[1]);
    local_1c[1] = static_cast<uint32_t>(iVar2 - 1);
    if (iVar2 - 1 == 0) {
        auto dtor = *reinterpret_cast<void(**)(uint32_t)>(static_cast<intptr_t>(*local_1c));
        dtor(1);
    }
    return uVar5;
}

// 0x4cddf0 — observed shape: dispatches name "SNAP"/"SNAPALL"/"SNAPWITHMENUS"/"SHOT" and 4-char extension ".PCX"/".TGA"/".DDS" to the matching loader, filling size outs when zero.
int* FUN_004cddf0(char* param_1, int param_2, int* param_3, int* param_4, int* param_5) {
    int* piVar3;
    if (param_1 == nullptr) {
        return nullptr;
    }
    int iVar2 = _strnicmp(param_1, "SNAP", 4);
    if (iVar2 == 0) {
        iVar2 = _strnicmp(param_1, "SNAPALL", 7);
        if (iVar2 == 0) {
            DAT_007268f4[DAT_00726a84] = DAT_007263bc;
            DAT_007263bc = DAT_007263bc | 0x81000;
        } else {
            DAT_007268f4[DAT_00726a84] = DAT_007263bc;
            DAT_007263bc = DAT_007263bc & 0xfff7f9ff;
        }
        DAT_00726a84 = DAT_00726a84 + 1;
        piVar3 = static_cast<int*>(reinterpret_cast<intptr_t>(FUN_004cda50(0x400, 0x400, 0, 0)));
        DAT_00726a84 = DAT_00726a84 + -1;
        DAT_007263bc = DAT_007268f4[DAT_00726a84];
        DAT_008ca9b8 = 1;
        if (((*param_4 == 0 && *param_5 == 0) && param_2 == 0) && param_3 == nullptr) {
            *param_4 = 0x400;
            *param_5 = 0x400;
        }
        if (DAT_008cac58 != 0) {
            FUN_004dcbf0();
        }
        return piVar3;
    }
    iVar2 = _stricmp(param_1, "SNAPWITHMENUS");
    if (iVar2 == 0) {
        piVar3 = static_cast<int*>(reinterpret_cast<intptr_t>(FUN_004cda50(0x400, 0x400, 0, 0)));
        DAT_008ca9b8 = 1;
        if (((*param_4 == 0 && *param_5 == 0) && param_2 == 0) && param_3 == nullptr) {
            *param_4 = 0x400;
            *param_5 = 0x400;
            return piVar3;
        }
    } else {
        iVar2 = _stricmp(param_1, "SHOT");
        if (iVar2 == 0) {
            int iVar6 = 0x400;
            int iVar2b = 0x400;
            if (DAT_008cac18 < 0x400) {
                iVar6 = 0x200;
                iVar2b = 0x200;
            }
            uint32_t* puVar4 = reinterpret_cast<uint32_t*>(
                reinterpret_cast<void*(*)(uint32_t)>(*reinterpret_cast<void**>(static_cast<intptr_t>(DAT_008ea08c) + 100))(0));
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
            piVar3 = static_cast<int*>(reinterpret_cast<intptr_t>(FUN_004cdc50(static_cast<int>(reinterpret_cast<intptr_t>(puVar4)), iVar6, iVar2b)));
            if (((*param_3 == 0 && *param_4 == 0) && param_1 == nullptr) && param_2 == 0) {
                *param_3 = iVar6;
                *param_4 = iVar2b;
            }
            if (puVar4 != nullptr) {
                uint32_t* piVar1 = puVar4 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    auto dtor = *reinterpret_cast<void(**)(uint32_t)>(static_cast<intptr_t>(*puVar4));
                    dtor(1);
                }
            }
            return piVar3;
        }
        char* pcVar5 = param_1;
        do {
            char* prev = pcVar5;
            pcVar5 = prev + 1;
        } while (*prev != '\0');
        pcVar5 = pcVar5 - 4;
        iVar2 = _stricmp(pcVar5, ".PCX");
        if (iVar2 == 0) {
            piVar3 = FUN_004cd6d0(param_2, *param_3, reinterpret_cast<uint32_t*>(param_4), reinterpret_cast<uint32_t*>(param_5), 0);
            return piVar3;
        }
        iVar2 = _stricmp(pcVar5, ".TGA");
        if (iVar2 == 0) {
            piVar3 = FUN_004cd860(param_4, reinterpret_cast<const char*>(static_cast<intptr_t>(param_2)), 0, param_5, 0);
            return piVar3;
        }
        iVar2 = _stricmp(pcVar5, ".DDS");
        if (iVar2 == 0) {
            piVar3 = static_cast<int*>(FUN_00500850());
            if ((*param_4 == 0) && (*param_5 == 0)) {
                auto getW = *reinterpret_cast<int*(**)(void)>(static_cast<intptr_t>(*piVar3) + 0x34);
                iVar2 = getW();
                *param_4 = iVar2;
                auto getH = *reinterpret_cast<int*(**)(void)>(static_cast<intptr_t>(*piVar3) + 0x38);
                iVar2 = getH();
                *param_5 = iVar2;
            }
            return piVar3;
        }
        piVar3 = nullptr;
    }
    return piVar3;
}

// 0x4ce080 — observed shape: formats value via FUN_004f5ef0/FUN_004129c0, copies into DAT_008cacd0, frees temporaries, uppercases, calls FUN_00412f10 when self+4 == 9.
uint32_t FUN_004ce080(uint32_t param_1, uint32_t in_ECX) {
    uint8_t* local_8 = nullptr;
    uint32_t local_4 = 0;
    uint32_t uVar1 = FUN_004f5ef0(&local_4);
    uint32_t* puVar2 = static_cast<uint32_t*>(FUN_004129c0(&local_8, uVar1));
    uint8_t* _Src = reinterpret_cast<uint8_t*>(*puVar2);
    size_t _Size = *reinterpret_cast<size_t*>(_Src - 4);
    if (((-1 < static_cast<int>(_Size)) && (_Src != nullptr)) && (_Src != DAT_008cacd0)) {
        if (_Size == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(DAT_008cacd0, _Src, _Size);
            DAT_008cacd0[DAT_008caccc] = 0;
        }
    }
    puVar2 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(local_8) - 8);
    if ((puVar2 != nullptr) && (puVar2 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar2);
    }
    puVar2 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(local_4) - 8);
    local_8 = DAT_008cacd0;
    if ((puVar2 != nullptr) && (puVar2 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar2);
    }
    _strupr(reinterpret_cast<char*>(DAT_008cacd0));
    if (*reinterpret_cast<int*>(static_cast<intptr_t>(in_ECX) + 4) == 9) {
        FUN_00412f10();
    }
    FUN_00412df0();
    return param_1;
}
