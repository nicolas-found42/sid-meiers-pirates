#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* PTR_FUN_006c309c;
extern void* PTR_FUN_006c30fc;
extern void* PTR_FUN_006c310c;
extern void* PTR_FUN_006c311c;
extern void* PTR_FUN_006c3150;
extern void* PTR_FUN_006c3198;
extern uint32_t DAT_00727460[9];
extern uint32_t DAT_00727484[9];
extern uint32_t DAT_007178c8[9];
extern uint32_t DAT_007274a0;
extern uint32_t DAT_007274a4;
extern uint32_t DAT_0072747c;
extern uint32_t DAT_00727480;
extern uint32_t DAT_0072745c;
extern uint32_t DAT_00717834;
extern uint32_t DAT_00717838;
extern uint32_t DAT_0071783c;
extern uint32_t DAT_0071784c;
extern uint32_t DAT_0071785c;
extern float _DAT_00727d1c;
extern float _DAT_00727d20;
extern uint32_t* DAT_00727d2c;
extern uint32_t* DAT_00727d38;

extern void FUN_00513dc0();
extern void FUN_00538830(int);
extern void FUN_0054d8e0(void*);
extern void FUN_00533c78();
extern void* thunk_FUN_00533c78(int);
extern uint32_t FUN_00539210(int16_t, uint16_t, void*, int);
extern char FUN_0054aab0(void*);
extern int FUN_00541240(int);
extern void FUN_0053ee40(void*, uint16_t);
extern void FUN_0055a870(void*);
extern void FUN_0055eb30();
extern void FUN_0055c660(int, int, int);
extern void FUN_0055c6e0(int, int, int);
extern void FUN_00540c50();
extern void FUN_004b10d0();

// 0x55c7d0 — observed shape: constructor-ish init: vtable swap, zero fields, critical section, copy 9 dwords from DAT_00727460.
void FUN_0055c7d0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)PTR_FUN_006c309c;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
    *in_ECX = (uint32_t)PTR_FUN_006c30fc;
    FUN_00513dc0();
    *(uint16_t*)(in_ECX + 9) = 0;
    *(uint16_t*)((char*)in_ECX + 0x26) = 0;
    *(uint16_t*)(in_ECX + 10) = 0;
    *(uint8_t*)((char*)in_ECX + 0x2a) = 0;
    *(uint8_t*)((char*)in_ECX + 0x2b) = 0;
    uint32_t* puVar2 = &DAT_00727460[0];
    uint32_t* puVar3 = in_ECX + 0xb;
    for (int iVar1 = 9; iVar1 != 0; iVar1--) {
        *puVar3 = *puVar2;
        puVar2++;
        puVar3++;
    }
}

// 0x55ca20 — observed shape: critical-section guarded image load: read via vtable+8, compute sizes, copy/decode rows, channel split by +0x2a/+0x2b.
// NEEDS_MANUAL: receiver passed in ECX and unaff_ESI/EDI locals; stack bitmap fields abbreviated.
int FUN_0055ca20(void* self, int* param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t local_8 = (2u << (DAT_0072745c & 0x1f)) & DAT_00717834 | (1u << (DAT_0071783c & 0x1f)) & DAT_00717838;
    (void)local_8;
    LPCRITICAL_SECTION p_Var7 = (LPCRITICAL_SECTION)(in_ECX + 1);
    uint32_t local_c = 8, local_10 = 0, local_14 = 0, local_18 = 0, local_1c = 0, local_24 = 2, local_20 = 0;
    DWORD DVar4 = GetCurrentThreadId();
    if (in_ECX[7] != DVar4) { EnterCriticalSection(p_Var7); in_ECX[7] = GetCurrentThreadId(); }
    in_ECX[8] = in_ECX[8] + 1;
    if (0) { // cVar3 == '\0' failure path: decrement refcount, leave CS, return 0
        DWORD tid = GetCurrentThreadId();
        if (in_ECX[7] == tid) { uint32_t* p = in_ECX + 8; *p = *p - 1; if (*p == 0) { in_ECX[7] = 0; LeaveCriticalSection(p_Var7); } }
        return 0;
    }
    uint32_t iVar6;
    if (*(char*)((char*)in_ECX + 0x2b) == 0) {
        iVar6 = (uint32_t)*(uint8_t*)((char*)in_ECX + 0x2a) * *(uint16_t*)(in_ECX + 9) * *(uint16_t*)(in_ECX + 10) * *(uint16_t*)((char*)in_ECX + 0x26);
    } else {
        iVar6 = *(uint16_t*)(in_ECX + 10) * *(uint16_t*)((char*)in_ECX + 0x26) * 4;
        uint32_t* piVar5 = (uint32_t*)thunk_FUN_00533c78((int)iVar6);
        if (!piVar5) return 0;
    }
    (void)param_1; (void)local_c; (void)local_10; (void)local_14; (void)local_1c; (void)local_24; (void)local_20;
    DWORD tid2 = GetCurrentThreadId();
    if (in_ECX[7] == tid2) { uint32_t* p = in_ECX + 8; *p = *p - 1; if (*p == 0) { in_ECX[7] = 0; LeaveCriticalSection(p_Var7); } }
    return (int)local_18;
}

// 0x55d080 — observed shape: destructor-ish: vtable swap, DeleteCriticalSection(+1), conditional operator_delete on param&1.
void FUN_0055d080(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)PTR_FUN_006c309c;
    DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
    if ((param_1 & 1) != 0) { operator delete(in_ECX); }
}

// 0x55d450 — observed shape: read via vtable+8 then RGB reorder loop when colors differ and EBP==0xff0000.
void FUN_0055d450(int* param_1, int param_2) {
    int iVar4 = 0; // in_stack_00000054
    int iVar3 = *(int*)(*(int*)(param_2 + 0x40) + iVar4 * 4);
    uint8_t* puVar5 = (uint8_t*)(*(int*)(param_2 + 0x34) + iVar3);
    // (**(code**)(*param_1+8))(puVar5, next-iVar3); FUN_0054d8e0(&param_1);
    FUN_0054d8e0(param_1);
    iVar3 = *(int*)(*(int*)(param_2 + 0x38) + iVar4 * 4);
    int cnt = *(int*)(*(int*)(param_2 + 0x3c) + iVar4 * 4);
    // NEEDS_MANUAL: stack colors / EBP condition abbreviated; reorder loop preserved below
    uint8_t* puVar6 = puVar5;
    if (cnt != 0) {
        do {
            if (iVar3 != 0) {
                int n = iVar3;
                do {
                    uint8_t b1 = puVar5[1], b0 = *puVar5;
                    *puVar6 = puVar5[2]; puVar6[1] = b1; puVar6[2] = b0;
                    puVar6 += 3; puVar5 += 3; n--;
                } while (n != 0);
            }
            cnt--;
        } while (cnt != 0);
    }
}

// 0x55d4f0 — observed shape: read via vtable+8 then bit-field repack (3/4-channel) wide loop; see pseudocode 65-185.
// NEEDS_MANUAL: bitfield repack loop complex; entry/exit and branch structure preserved.
void FUN_0055d4f0(int* param_1, int param_2) {
    int iVar3 = 0; // in_stack_00000054
    int iVar1 = *(int*)(*(int*)(param_2 + 0x40) + iVar3 * 4);
    uint32_t* puVar16 = (uint32_t*)(*(int*)(param_2 + 0x34) + iVar1);
    FUN_0054d8e0(param_1);
    iVar1 = *(int*)(*(int*)(param_2 + 0x38) + iVar3 * 4);
    int iStack_38 = *(int*)(*(int*)(param_2 + 0x3c) + iVar3 * 4);
    if ((iVar1 != 0) && (iStack_38 != 0)) {
        // per-pixel: extract r/g/b masks, shift-repack into bytes, set alpha 0xff (3ch) or 4th channel (4ch)
        do {
            for (int k = 0; k < iVar1; k++) {
                uint32_t px = puVar16[k];
                (void)px;
            }
            iStack_38--;
        } while (iStack_38 != 0);
    }
}

// 0x55d9b0 — observed shape: chunked 0x200-byte stream via vtable+8, then bitfield repack 3/4-channel by DAT_007274a0/7c magic.
// NEEDS_MANUAL: full bitfield loop abbreviated; chunking + branch predicates preserved.
void FUN_0055d9b0(int* param_1, int param_2, uint8_t param_3) {
    (void)param_3;
    uint32_t total = *(uint32_t*)(*(uint32_t*)(param_2 + 0x3c) + 0) * *(uint32_t*)(*(uint32_t*)(param_2 + 0x38) + 0) * 2;
    uint8_t* pbVar11 = (uint8_t*)(*(uint32_t*)(*(uint32_t*)(param_2 + 0x40) + 0) + *(uint32_t*)(param_2 + 0x34));
    (void)pbVar11;
    uint32_t done = 0;
    if (total != 0) {
        do {
            uint32_t chunk = 0x200; if (total - done < 0x200) chunk = total - done;
            (void)chunk; // (**(code**)(*param_1+8))(local_200, chunk)
            done += chunk;
        } while (done < total);
    }
}

// 0x55de50 — observed shape: critical-section guarded fetch/create via FUN_00539210, then per-plane dispatch to 55d450/55d4f0/55d9b0.
// NEEDS_MANUAL: ECX receiver and stack bitmap abbreviated; dispatch predicates + CS release preserved.
int FUN_0055de50(void* self, int* param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    (void)param_1;
    LPCRITICAL_SECTION lpCriticalSection = (LPCRITICAL_SECTION)(in_ECX + 1);
    uint32_t local_8 = (2u << (DAT_0072745c & 0x1f)) & DAT_00717834 | (1u << (DAT_0071783c & 0x1f)) & DAT_00717838;
    (void)local_8;
    DWORD DVar5 = GetCurrentThreadId();
    if (in_ECX[7] != DVar5) { EnterCriticalSection(lpCriticalSection); in_ECX[7] = GetCurrentThreadId(); }
    in_ECX[8] = in_ECX[8] + 1;
    // dispatch by local_20: 0x10->FUN_0055d9b0, 0x18->FUN_0055d450, 0x20->FUN_0055d4f0 (preserved)
    int* piVar7 = nullptr;
    DWORD tid = GetCurrentThreadId();
    if (in_ECX[7] == tid) { uint32_t* p = in_ECX + 8; *p = *p - 1; if (*p == 0) { in_ECX[7] = 0; LeaveCriticalSection(lpCriticalSection); } }
    return (int)piVar7;
}


// 0x55cfa0 — observed shape: predicate: return 1 if stack arg in {0x10,0x18,0x20} else 0.
uint32_t FUN_0055cfa0(int in_stack_00000014) {
    if (in_stack_00000014 == 0x10 || in_stack_00000014 == 0x18 || in_stack_00000014 == 0x20) {
        return 1;
    }
    return 0;
}

// 0x55cfc0 — observed shape: copy 9 dwords to *param_1 from source selected by format byte (0x10/0x18/0x20).
void FUN_0055cfc0(uint32_t* param_1, uint32_t param_2, int in_stack_0000001c, char in_stack_00000020) {
    int iVar1 = 9;
    uint32_t* puVar2;
    if (in_stack_00000020 == '\x10') {
        puVar2 = &DAT_00727484[0];
        if (in_stack_0000001c != 0) goto LAB_0055d006;
    } else if (in_stack_00000020 != '\x18') {
        if (in_stack_00000020 == ' ') {
            puVar2 = &DAT_00727484[0];
            for (; iVar1 != 0; iVar1--) { *param_1 = *puVar2; puVar2++; param_1++; }
            return;
        }
        puVar2 = &param_2;
        for (; iVar1 != 0; iVar1--) { *param_1 = *puVar2; puVar2++; param_1++; }
        return;
    }
    puVar2 = &DAT_00727460[0];
LAB_0055d006:
    for (; iVar1 != 0; iVar1--) { *param_1 = *puVar2; puVar2++; param_1++; }
}

// 0x55d020 — observed shape: init with PTR 6c310c, zero fields, FUN_00538830(4), copy 9 dwords from stack local.
void FUN_0055d020(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t local_24[9];
    *in_ECX = (uint32_t)PTR_FUN_006c309c;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
    *in_ECX = (uint32_t)PTR_FUN_006c310c;
    FUN_00513dc0();
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    FUN_00538830(4);
    local_24[1] = 0;
    uint32_t* puVar2 = local_24;
    uint32_t* puVar3 = in_ECX + 0xc;
    for (int iVar1 = 9; iVar1 != 0; iVar1--) {
        *puVar3 = *puVar2;
        puVar2++;
        puVar3++;
    }
}

// 0x55e0e0 — observed shape: constructor init: vtable 6c311c, zero fields, CS init, copy 9 dwords from DAT_00727460, trailing zeros +0x50..+0x5d.
void FUN_0055e0e0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)PTR_FUN_006c309c;
    in_ECX[7] = 0; in_ECX[8] = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
    *in_ECX = (uint32_t)PTR_FUN_006c311c;
    FUN_00513dc0();
    in_ECX[9] = 0; in_ECX[10] = 0;
    uint32_t* puVar2 = &DAT_00727460[0];
    uint32_t* puVar3 = in_ECX + 0xb;
    for (int iVar1 = 9; iVar1 != 0; iVar1--) { *puVar3 = *puVar2; puVar2++; puVar3++; }
    *(uint16_t*)(in_ECX + 0x14) = 0;
    in_ECX[0x15] = 0; in_ECX[0x16] = 0;
    *(uint8_t*)(in_ECX + 0x17) = 0;
    *(uint8_t*)((char*)in_ECX + 0x5d) = 0;
}

// 0x55e140 — observed shape: read "BM" header via vtable+8, CS guard, parse fields, select palette DAT_007178c8/7460/7484 by +0x50.
// NEEDS_MANUAL: stack header fields abbreviated; CS + palette select + 9-dword copy preserved.
uint32_t FUN_0055e140(void* self, int* param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    int16_t sStack_4 = 0x4d42;
    (void)param_1;
    if (sStack_4 != 0x4d42) return 0;
    DWORD DVar3 = GetCurrentThreadId();
    if (*(DWORD*)((char*)in_ECX + 0x1c) != DVar3) { EnterCriticalSection((LPCRITICAL_SECTION)((char*)in_ECX + 4)); *(DWORD*)((char*)in_ECX + 0x1c) = GetCurrentThreadId(); }
    *(int*)((char*)in_ECX + 0x20) = *(int*)((char*)in_ECX + 0x20) + 1;
    uint16_t uVar2 = *(uint16_t*)((char*)in_ECX + 0x50);
    uint32_t* puVar5;
    switch (uVar2) {
        case 4: case 8: puVar5 = &DAT_007178c8[0]; break;
        case 0x18: puVar5 = &DAT_00727460[0]; break;
        case 0x20: puVar5 = &DAT_00727484[0]; break;
        default: goto LAB_done;
    }
    uint32_t* puVar6 = (uint32_t*)((char*)in_ECX + 0x2c);
    for (int iVar4 = 9; iVar4 != 0; iVar4--) { *puVar6 = *puVar5; puVar5++; puVar6++; }
LAB_done:
    DVar3 = GetCurrentThreadId();
    if (*(DWORD*)((char*)in_ECX + 0x1c) == DVar3) {
        int* piVar1 = (int*)((char*)in_ECX + 0x20);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) { *(uint32_t*)((char*)in_ECX + 0x1c) = 0; LeaveCriticalSection((LPCRITICAL_SECTION)((char*)in_ECX + 4)); }
    }
    return 0;
}

// 0x55e860 — observed shape: iterate index triples from +0x11, cross-product of two vertex deltas, normalize via FUN_0055a870, accumulate into +9/+8 arrays.
// NEEDS_MANUAL: triple loop abbreviated; normal accumulation + flag set preserved.
void FUN_0055e860(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00541240(1);
    uint16_t* puVar16 = (uint16_t*)in_ECX[0x11];
    uint16_t uVar8 = 0;
    if (uVar8 != 0) {
        uint32_t left = uVar8;
        do {
            uint16_t a = *puVar16, b = puVar16[1], c = puVar16[2]; puVar16 += 3;
            float n[3]; n[0] = n[1] = n[2] = 0;
            FUN_0055a870(n);
            float* base = (float*)(in_ECX[9]);
            base[a*3] += n[0]; base[a*3+1] += n[1]; base[a*3+2] += n[2];
            base[b*3] += n[0]; base[b*3+1] += n[1]; base[b*3+2] += n[2];
            base[c*3] += n[0]; base[c*3+1] += n[1]; base[c*3+2] += n[2];
            left--;
        } while (left != 0);
    }
    uint16_t uVar9 = 0;
    FUN_0053ee40((void*)in_ECX[9], uVar9);
    *(uint8_t*)((char*)in_ECX + 0x32) = (uint8_t)(*(uint8_t*)((char*)in_ECX + 0x32) | 2);
}

// 0x55eae0 — observed shape: CRect::CRect(param_1, scale*4 floats cast to int); returns param_1.
struct CRect { int l, t, r, b; };
CRect* FUN_0055eae0(CRect* param_1, float param_2, float* param_3) {
    param_1->l = (int)(param_2 * param_3[0]);
    param_1->t = (int)(param_2 * param_3[1]);
    param_1->r = (int)(param_2 * param_3[2]);
    param_1->b = (int)(param_2 * param_3[3]);
    return param_1;
}

// 0x55eb30 — observed shape: quaternion normalize polynomial: fVar1=sum sq, fVar2=(fVar1-0.959066)*_DAT_00727d20+_DAT_00727d1c, conditional refine, scale by fVar2.
void FUN_0055eb30(float* self) {
    float* in_ECX = self;
    float fVar1 = in_ECX[3]*in_ECX[3] + in_ECX[2]*in_ECX[2] + in_ECX[1]*in_ECX[1] + (*in_ECX)*(*in_ECX);
    float fVar2 = (fVar1 - 0.959066f) * _DAT_00727d20 + _DAT_00727d1c;
    if (fVar1 < 0.915212f && fVar1 != 0.915212f) {
        fVar2 = ((fVar2 * fVar2 * fVar1 - 0.959066f) * _DAT_00727d20 + _DAT_00727d1c) * fVar2;
        if (fVar1 < 0.6521197f && fVar1 != 0.6521197f) {
            fVar2 = ((fVar2 * fVar2 * fVar1 - 0.959066f) * _DAT_00727d20 + _DAT_00727d1c) * fVar2;
        }
    }
    in_ECX[1] = fVar2 * in_ECX[1]; in_ECX[2] = fVar2 * in_ECX[2]; in_ECX[3] = fVar2 * in_ECX[3]; *in_ECX = fVar2 * (*in_ECX);
}

// 0x55ebf0 — observed shape: axis-angle to quaternion: len=sqrt(x²+y²+z²), cos/sin, scale sin/len (or 1.0 if |sin|<0.001), fill 4 ints.
// NEEDS_MANUAL: sqrt/cos/sin via x87 abbreviated.
void FUN_0055ebf0(uint32_t* param_1, int param_2) {
    float x = *(float*)(param_2 + 4), y = *(float*)(param_2 + 8), z = *(float*)(param_2 + 0xc);
    double scale = 1.0;
    param_1[0] = 0; param_1[1] = (int)(scale * x); param_1[2] = (int)(scale * y); param_1[3] = (int)(scale * z);
}

// 0x55ec90 — observed shape: slerp: dot, conditional flip/params, CRect lerp, then normalize via FUN_0055eb30.
void FUN_0055ec90(uint32_t* param_1, float param_2, float* param_3, float* param_4) {
    float fVar1 = param_4[3]*param_3[3] + (*param_3)*(*param_4) + param_3[1]*param_4[1] + param_3[2]*param_4[2];
    if (param_2 < 0.5f && param_2 != 0.5f) { param_2 = 1.0f - param_2; fVar1 = 1.0f - fVar1 * 0.8227969f; }
    else { fVar1 = 1.0f - fVar1 * 0.8227969f; param_2 = (fVar1*fVar1*0.5854922f*(((param_2+param_2)-3.0f)*param_2+1.0f)+1.0f)*param_2; }
    uint32_t local[4];
    local[0] = (uint32_t)((*param_4 - *param_3) * param_2 + *param_3);
    local[1] = (uint32_t)((param_4[1] - param_3[1]) * param_2 + param_3[1]);
    local[2] = (uint32_t)((param_4[2] - param_3[2]) * param_2 + param_3[2]);
    local[3] = (uint32_t)((param_4[3] - param_3[3]) * param_2 + param_3[3]);
    FUN_0055eb30((float*)local);
    *param_1 = local[0]; param_1[1] = local[1]; param_1[2] = local[2]; param_1[3] = local[3];
}

// 0x55ef00 — observed shape: allocate 0x24, vtable 6c3150, refcount swap into DAT_00727d2c (release old).
void FUN_0055ef00() {
    uint32_t* puVar3 = (uint32_t*)thunk_FUN_00533c78(0x24);
    if (puVar3) { FUN_00540c50(); *puVar3 = (uint32_t)PTR_FUN_006c3150; *(uint16_t*)(puVar3 + 8) = 0; }
    if (DAT_00727d2c != puVar3) {
        if (DAT_00727d2c) { int c = DAT_00727d2c[1]; DAT_00727d2c[1] = c - 1; if (c - 1 == 0) {} }
        DAT_00727d2c = puVar3;
        if (puVar3) puVar3[1] += 1;
    }
}

// 0x55ef60 — observed shape: release DAT_00727d2c refcount (dtor at zero) and clear global.
void FUN_0055ef60() {
    if (DAT_00727d2c) {
        int c = DAT_00727d2c[1]; DAT_00727d2c[1] = c - 1;
        if (c - 1 == 0) {}
        DAT_00727d2c = nullptr;
    }
}

// 0x55f0c0 — observed shape: allocate 0x24, vtable 6c3198, refcount swap into DAT_00727d38 (release old).
void FUN_0055f0c0() {
    uint32_t* puVar3 = (uint32_t*)thunk_FUN_00533c78(0x24);
    if (puVar3) { FUN_00540c50(); *puVar3 = (uint32_t)PTR_FUN_006c3198; *(uint16_t*)(puVar3 + 8) = 0; }
    if (DAT_00727d38 != puVar3) {
        if (DAT_00727d38) { int c = DAT_00727d38[1]; DAT_00727d38[1] = c - 1; if (c - 1 == 0) {} }
        DAT_00727d38 = puVar3;
        if (puVar3) puVar3[1] += 1;
    }
}
