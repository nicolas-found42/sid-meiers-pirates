#include <cstdint>
#include <cstddef>
#include <cmath>

extern void FUN_005f148d_thunk(float* a, float* b);
extern void FUN_005f8d40(int v);
extern void* g_ptr_7188a4;
extern void* g_ptr_7188ac;
extern void* g_ptr_7188a8;
extern void* g_ptr_718928;

// 0x5f2d50 — observed shape
void FUN_005f2d50(float* param_1, float* param_2, float param_3) {
    float local_8 = (float)std::cos((double)param_3);
    float local_c = (float)std::sin((double)param_3);
    float fVar2 = 1.0f - local_8;
    float local_20 = param_2[0];
    float local_1c = param_2[1];
    float local_18 = param_2[2];
    FUN_005f148d_thunk(&local_20, &local_20);
    float fVar3 = local_1c * local_20 * fVar2;
    float fVar4 = local_1c * local_18 * fVar2;
    float fVar5 = local_18 * local_20 * fVar2;
    param_1[0] = local_20 * local_20 * fVar2 + local_8;
    param_1[1] = fVar3 + local_18 * local_c;
    param_1[2] = fVar5 - local_1c * local_c;
    param_1[3] = 0.0f;
    param_1[4] = fVar3 - local_18 * local_c;
    param_1[5] = local_1c * local_1c * fVar2 + local_8;
    param_1[6] = local_20 * local_c + fVar4;
    param_1[7] = 0.0f;
    param_1[8] = local_1c * local_c + fVar5;
    param_1[9] = fVar4 - local_20 * local_c;
    param_1[10] = local_18 * local_18 * fVar2 + local_8;
    param_1[11] = 0.0f;
    param_1[12] = 0.0f;
    param_1[13] = 0.0f;
    param_1[14] = 0.0f;
    param_1[15] = 1.0f;
}

// 0x5f2e51 — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x7188a4, jumptable not recovered
void FUN_005f2e51() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_7188a4)();
}

// 0x5f2f4e — observed shape
void FUN_005f2f4e(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4) {
    FUN_005f8d40(1);
    ((void(*)(uint32_t, uint32_t, uint32_t, uint32_t))g_ptr_7188ac)(p1, p2, p3, p4);
}

// 0x5f2f7e — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x7188a8, jumptable not recovered
void FUN_005f2f7e() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_7188a8)();
}

// 0x5f329d — observed shape
void FUN_005f329d(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7) {
    FUN_005f8d40(1);
    ((void(*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))g_ptr_718928)(p1, p2, p3, p4, p5, p6, p7);
}
extern void* g_ptr_7188b0;
extern void* g_ptr_71892c;
extern void* g_ptr_718878;

// 0x5f35c9 — observed shape
void FUN_005f35c9(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5) {
    FUN_005f8d40(1);
    ((void(*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))g_ptr_7188b0)(p1, p2, p3, p4, p5);
}

// 0x5f36e2 — observed shape
void FUN_005f36e2(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5) {
    FUN_005f8d40(1);
    ((void(*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))g_ptr_71892c)(p1, p2, p3, p4, p5);
}

// 0x5f37f6 — observed shape
void FUN_005f37f6(float* param_1, float* param_2, float* param_3, float* param_4) {
    float local_10 = param_2[0] - param_3[0];
    float local_c = param_2[1] - param_3[1];
    float local_8 = param_2[2] - param_3[2];
    FUN_005f148d_thunk(&local_10, &local_10);
    float local_1c = local_8 * param_4[1] - local_c * param_4[2];
    float local_18 = local_10 * param_4[2] - local_8 * param_4[0];
    float local_14 = local_c * param_4[0] - local_10 * param_4[1];
    FUN_005f148d_thunk(&local_1c, &local_1c);
    param_1[4] = local_18;
    param_1[8] = local_14;
    float fVar4 = local_c * local_14 - local_8 * local_18;
    float fVar5 = local_8 * local_1c - local_10 * local_14;
    float fVar6 = local_10 * local_18 - local_c * local_1c;
    param_1[0] = local_1c;
    float fVar1 = param_2[0];
    float fVar2 = param_2[1];
    float fVar3 = param_2[2];
    param_1[1] = fVar4;
    param_1[5] = fVar5;
    param_1[9] = fVar6;
    param_1[12] = -(local_14 * fVar3 + local_18 * fVar2 + local_1c * fVar1);
    param_1[2] = local_10;
    param_1[6] = local_c;
    param_1[10] = local_8;
    param_1[13] = -(fVar6 * fVar3 + fVar5 * fVar2 + fVar4 * fVar1);
    param_1[14] = -(local_8 * param_2[2] + local_c * param_2[1] + local_10 * param_2[0]);
    param_1[3] = 0.0f;
    param_1[7] = 0.0f;
    param_1[11] = 0.0f;
    param_1[15] = 1.0f;
}

// 0x5f394e — observed shape
void FUN_005f394e(float* param_1, float param_2, float param_3, float param_4, float param_5) {
    param_1[11] = -1.0f;
    param_1[0] = (param_4 + param_4) / param_2;
    param_1[1] = 0.0f;
    param_1[2] = 0.0f;
    param_1[3] = 0.0f;
    param_1[4] = 0.0f;
    param_1[5] = (param_4 + param_4) / param_3;
    param_1[6] = 0.0f;
    param_1[7] = 0.0f;
    param_1[8] = 0.0f;
    param_1[9] = 0.0f;
    param_5 = param_5 / (param_4 - param_5);
    param_1[10] = param_5;
    param_1[12] = 0.0f;
    param_1[13] = 0.0f;
    param_1[14] = param_5 * param_4;
    param_1[15] = 0.0f;
}

// 0x5f39bc — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x718878, jumptable not recovered
void FUN_005f39bc() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_718878)();
}

extern void* g_ptr_71886c;
extern void* g_ptr_718880;
extern void* g_ptr_718870;
extern void* g_ptr_718858;

// 0x5f3a2d — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x71886c, jumptable not recovered
void FUN_005f3a2d() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_71886c)();
}

// 0x5f3b7c — observed shape
void FUN_005f3b7c(uint32_t p1, uint32_t p2, uint32_t p3) {
    FUN_005f8d40(1);
    ((void(*)(uint32_t, uint32_t, uint32_t))g_ptr_718880)(p1, p2, p3);
}

// 0x5f3b9f — observed shape
float* FUN_005f3b9f(float* param_1, float* param_2, float param_3) {
    float local_18, local_14, local_10;
    FUN_005f148d_thunk(&local_18, param_2);
    float c = (float)std::cos((double)(param_3 * 0.5f));
    float s = (float)std::sin((double)(param_3 * 0.5f));
    param_1[3] = c;
    param_1[0] = local_18 * s;
    param_1[1] = local_14 * s;
    param_1[2] = local_10 * s;
    return param_1;
}

// 0x5f3bfd — observed shape
void FUN_005f3bfd(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4) {
    FUN_005f8d40(1);
    ((void(*)(uint32_t, uint32_t, uint32_t, uint32_t))g_ptr_718870)(p1, p2, p3, p4);
}

// 0x5f3d0e — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x718858, jumptable not recovered
void FUN_005f3d0e() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_718858)();
}

extern void* g_ptr_71885c;
extern void* g_ptr_7188bc;
extern void* g_ptr_7188e8;
extern void* g_ptr_7188ec;
extern void* g_ptr_718898;

// 0x5f3dbf — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x71885c, jumptable not recovered
void FUN_005f3dbf() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_71885c)();
}

// 0x5f3dd2 — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x7188bc, jumptable not recovered
void FUN_005f3dd2() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_7188bc)();
}

// 0x5f3e9e — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x7188e8, jumptable not recovered
void FUN_005f3e9e() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_7188e8)();
}

// 0x5f3f34 — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x7188ec, jumptable not recovered
void FUN_005f3f34() {
    FUN_005f8d40(1);
    ((void(*)())g_ptr_7188ec)();
}

// 0x5f3fe7 — observed shape
void FUN_005f3fe7(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4) {
    FUN_005f8d40(1);
    ((void(*)(uint32_t, uint32_t, uint32_t, uint32_t))g_ptr_718898)(p1, p2, p3, p4);
}

