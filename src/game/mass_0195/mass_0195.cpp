#include <cstdint>
#include <cstddef>
#include <windows.h>
extern void FUN_005a3450(double, double, double, double, double);
extern void FUN_005a3390(double, double, double, double*, double*);

// 0x5a36e0 — observed shape
void FUN_005a36e0(void* self){
  uint8_t* s = (uint8_t*)self;
  float fVar2 = *(float*)(s + 0x88) - *(float*)(s + 0x7c);
  float fVar3 = *(float*)(s + 0xac) - *(float*)(s + 0xa0);
  *(float*)(s + 0x94) = fVar2;
  *(float*)(s + 0xb8) = fVar3;
  float fVar1 = *(float*)(s + 0x110);
  float local_c, local_8, local_10, local_14;
  if (fVar1 < 0.0f) { local_c = 0.0f; local_8 = fVar1; }
  else { local_8 = 0.0f; local_c = fVar1; }
  local_10 = fVar2 - *(float*)(s + 0x1b0);
  if (local_10 < fVar2) { local_14 = fVar2; }
  else { local_14 = local_10; local_10 = fVar2; }
  FUN_005a3450((double)local_8,(double)local_c,(double)local_10,(double)local_14,(double)fVar3);
}

// 0x5a3790 — observed shape
void FUN_005a3790(void* self){
  uint8_t* s = (uint8_t*)self;
  float fVar2 = *(float*)(s + 0x94) - *(float*)(s + 0x90);
  float fVar3 = *(float*)(s + 0xb8) - *(float*)(s + 0xb4);
  *(float*)(s + 0x98) = fVar2;
  *(float*)(s + 0xbc) = fVar3;
  float fVar1 = *(float*)(s + 0x114);
  float local_c, local_8, local_10, local_14;
  if (fVar1 < 0.0f) { local_c = 0.0f; local_8 = fVar1; }
  else { local_8 = 0.0f; local_c = fVar1; }
  local_10 = fVar2 - *(float*)(s + 0x1b0);
  if (local_10 < fVar2) { local_14 = fVar2; }
  else { local_14 = local_10; local_10 = fVar2; }
  FUN_005a3450((double)local_8,(double)local_c,(double)local_10,(double)local_14,(double)fVar3);
}

// 0x5a3840 — observed shape
void FUN_005a3840(void* self){
  uint8_t* s = (uint8_t*)self;
  float local_8 = *(float*)(s + 0x1e0) - *(float*)(s + 0x1d4);
  *(float*)(s + 0x1ec) = local_8;
  float local_c = *(float*)(s + 0x1e4) - *(float*)(s + 0x1d8);
  *(float*)(s + 0x1f0) = local_c;
  float fVar1 = *(float*)(s + 0x1c0) - *(float*)(s + 0x1bc);
  *(float*)(s + 0x1c4) = fVar1;
  float local_4 = *(float*)(s + 0x1cc) - *(float*)(s + 0x1c8);
  *(float*)(s + 0x1d0) = local_4;
  double lc = (double)local_c, l8 = (double)local_8;
  FUN_005a3390(0.0,(double)local_8,(double)local_c,&lc,&l8);
  local_c = (float)lc; local_8 = (float)l8;
  FUN_005a3450((double)local_c,(double)local_8,(double)(fVar1 - *(float*)(s + 0x1a4)),(double)fVar1,(double)local_4);
}

// 0x5a38f0 — observed shape
void FUN_005a38f0(void* self){
  uint8_t* s = (uint8_t*)self;
  float fVar1 = *(float*)(s + 0x144) - *(float*)(s + 0x138);
  *(float*)(s + 0x150) = fVar1;
  float fVar2 = *(float*)(s + 0x148) - *(float*)(s + 0x13c);
  *(float*)(s + 0x154) = fVar2;
  float local_c = *(float*)(s + 0x124) - *(float*)(s + 0x120);
  *(float*)(s + 0x128) = local_c;
  float local_8 = *(float*)(s + 0x130) - *(float*)(s + 300);
  *(float*)(s + 0x134) = local_8;
  double local_4 = 0.0, l4c = (double)local_c;
  FUN_005a3390((double)local_c,(double)(local_c + fVar1),(double)(local_c + fVar2),&local_4,&l4c);
  float out4 = (float)local_4;
  float outc = (float)l4c;
  FUN_005a3450((double)(-* (float*)(s + 0x108)),0.0,(double)out4,(double)outc,(double)local_8);
}

// 0x5a39a0 — observed shape
void FUN_005a39a0(uint32_t* param_1, float* param_2, uint32_t* param_3, float* param_4, void* self){
  uint32_t* in_ECX = (uint32_t*)self;
  in_ECX[7] = *reinterpret_cast<uint32_t*>(param_4);
  in_ECX[3] = *reinterpret_cast<uint32_t*>(param_2);
  in_ECX[0] = param_1[0]; in_ECX[1] = param_1[1]; in_ECX[2] = param_1[2];
  in_ECX[4] = param_3[0]; in_ECX[5] = param_3[1]; in_ECX[6] = param_3[2];
  float fVar1 = param_4[1]; float fVar2 = param_2[1];
  float fVar3 = param_4[2]; float fVar4 = param_2[2];
  in_ECX[0xb] = *reinterpret_cast<uint32_t*>(&param_4[1]) * 0; // placeholder removed below
  // actual float differences stored as bits:
  float d1 = *param_4 - *param_2; float d2 = fVar1 - fVar2; float d3 = fVar3 - fVar4;
  *reinterpret_cast<float*>(&in_ECX[0xb]) = d1;
  *reinterpret_cast<float*>(&in_ECX[0xc]) = d2;
  *reinterpret_cast<float*>(&in_ECX[0xd]) = d3;
  float* pfVar5 = *reinterpret_cast<float**>(&in_ECX[0]);
  float* pfVar6 = *reinterpret_cast<float**>(&in_ECX[1]);
  fVar1 = pfVar6[1]; fVar2 = pfVar5[1]; fVar3 = pfVar6[2]; fVar4 = pfVar5[2];
  float null_e1 = *pfVar6 - *pfVar5; float null_e2 = fVar1 - fVar2; float null_e3 = fVar3 - fVar4;
  *reinterpret_cast<float*>(&in_ECX[0x30]) = null_e1;
  *reinterpret_cast<float*>(&in_ECX[0x31]) = null_e2;
  *reinterpret_cast<float*>(&in_ECX[0x32]) = null_e3;
  pfVar6 = *reinterpret_cast<float**>(&in_ECX[2]);
  fVar1 = pfVar6[1]; fVar2 = pfVar5[1]; fVar3 = pfVar6[2]; fVar4 = pfVar5[2];
  *reinterpret_cast<float*>(&in_ECX[0x33]) = *pfVar6 - *pfVar5;
  *reinterpret_cast<float*>(&in_ECX[0x34]) = fVar1 - fVar2;
  *reinterpret_cast<float*>(&in_ECX[0x35]) = fVar3 - fVar4;
  pfVar6 = *reinterpret_cast<float**>(&in_ECX[4]);
  float* pfVar7 = *reinterpret_cast<float**>(&in_ECX[5]);
  fVar1 = pfVar7[1]; fVar2 = pfVar6[1]; fVar3 = pfVar7[2]; fVar4 = pfVar6[2];
  *reinterpret_cast<float*>(&in_ECX[0x57]) = *pfVar7 - *pfVar6;
  *reinterpret_cast<float*>(&in_ECX[0x58]) = fVar1 - fVar2;
  *reinterpret_cast<float*>(&in_ECX[0x59]) = fVar3 - fVar4;
  pfVar7 = *reinterpret_cast<float**>(&in_ECX[6]);
  fVar1 = pfVar7[1]; fVar2 = pfVar6[1]; fVar3 = pfVar7[2]; fVar4 = pfVar6[2];
  *reinterpret_cast<float*>(&in_ECX[0x5a]) = *pfVar7 - *pfVar6;
  *reinterpret_cast<float*>(&in_ECX[0x5b]) = fVar1 - fVar2;
  *reinterpret_cast<float*>(&in_ECX[0x5c]) = fVar3 - fVar4;
  fVar1 = pfVar6[1]; fVar2 = pfVar5[1]; fVar3 = pfVar6[2]; fVar4 = pfVar5[2];
  *reinterpret_cast<float*>(&in_ECX[8]) = *pfVar6 - *pfVar5;
  *reinterpret_cast<float*>(&in_ECX[9]) = fVar1 - fVar2;
  *reinterpret_cast<float*>(&in_ECX[10]) = fVar3 - fVar4;
  in_ECX[0x7e] = 0;
}

// 0x5a3b50 — observed shape
uint32_t FUN_005a3b50(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0xd8);
  float local_c = *(float*)(s + 0xc4) * *(float*)(s + 0xd4) - *(float*)(s + 200) * *(float*)(s + 0xd0);
  float local_8 = *(float*)(s + 0xcc) * *(float*)(s + 200) - *(float*)(s + 0xc0) * *(float*)(s + 0xd4);
  *pfVar1 = local_c;
  *(float*)(s + 0xdc) = local_8;
  float local_4 = *(float*)(s + 0xc0) * *(float*)(s + 0xd0) - *(float*)(s + 0xc4) * *(float*)(s + 0xcc);
  *(float*)(s + 0xe0) = local_4;
  *(float*)(s + 0x10c) = *pfVar1 * *(float*)(s + 0x15c) + *(float*)(s + 0x160) * *(float*)(s + 0xdc) + *(float*)(s + 0x164) * *(float*)(s + 0xe0);
  *(float*)(s + 0x110) = *(float*)(s + 0x168) * *pfVar1 + *(float*)(s + 0x16c) * *(float*)(s + 0xdc) + *(float*)(s + 0x170) * *(float*)(s + 0xe0);
  *(float*)(s + 0x118) = *pfVar1 * *(float*)(s + 0x20) + *(float*)(s + 0x24) * *(float*)(s + 0xdc) + *(float*)(s + 0x28) * *(float*)(s + 0xe0);
  float local_10 = *(float*)(s + 0x2c) * *pfVar1 + *(float*)(s + 0x30) * *(float*)(s + 0xdc) + *(float*)(s + 0x34) * *(float*)(s + 0xe0);
  *(float*)(s + 0x11c) = local_10;
  double local_18 = 0.0, local_14 = 0.0;
  double a0 = (double)*(float*)(s + 0x118);
  FUN_005a3390(a0, *(float*)(s + 0x118) + *(float*)(s + 0x10c), *(float*)(s + 0x118) + *(float*)(s + 0x110), &local_18, &local_14);
  if (local_18 <= 0.0) {
    uint32_t uVar2 = 0;
    if (local_14 < 0.0) {
      local_14 = local_10 * *(float*)(s + 0x22c) + local_14;
      if (local_14 < 0.0) return uVar2;
    }
  } else {
    double v = local_10 * *(float*)(s + 0x22c) + local_18;
    if (v >= 0.0 && v != 0.0) { uint32_t u = 0; return u; }
    local_18 = v;
  }
  return 1;
}

// 0x5a3d00 — observed shape
void FUN_005a3d00(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0x174);
  float local_c = *(float*)(s + 0x160) * *(float*)(s + 0x170) - *(float*)(s + 0x164) * *(float*)(s + 0x16c);
  float local_8 = *(float*)(s + 0x168) * *(float*)(s + 0x164) - *(float*)(s + 0x15c) * *(float*)(s + 0x170);
  *pfVar1 = local_c;
  *(float*)(s + 0x178) = local_8;
  float local_4 = *(float*)(s + 0x15c) * *(float*)(s + 0x16c) - *(float*)(s + 0x160) * *(float*)(s + 0x168);
  *(float*)(s + 0x17c) = local_4;
  *(float*)(s + 0x1a8) = *pfVar1 * *(float*)(s + 0xc0) + *(float*)(s + 0xc4) * *(float*)(s + 0x178) + *(float*)(s + 200) * *(float*)(s + 0x17c);
  *(float*)(s + 0x1ac) = *(float*)(s + 0xcc) * *pfVar1 + *(float*)(s + 0xd0) * *(float*)(s + 0x178) + *(float*)(s + 0xd4) * *(float*)(s + 0x17c);
  *(float*)(s + 0x1b4) = *pfVar1 * *(float*)(s + 0x20) + *(float*)(s + 0x24) * *(float*)(s + 0x178) + *(float*)(s + 0x28) * *(float*)(s + 0x17c);
  float fVar2 = *(float*)(s + 0x2c) * *pfVar1 + *(float*)(s + 0x30) * *(float*)(s + 0x178) + *(float*)(s + 0x34) * *(float*)(s + 0x17c);
  *(float*)(s + 0x1b8) = fVar2;
  double local_10 = 0.0, local_14 = 0.0;
  FUN_005a3390(0.0, (double)*(float*)(s + 0x1a8), (double)*(float*)(s + 0x1ac), &local_10, &local_14);
  FUN_005a3450(local_10, local_14, (double)*(float*)(s + 0x1b4), (double)*(float*)(s + 0x1b4), (double)fVar2);
}

// 0x5a3e50 — observed shape
void FUN_005a3e50(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0x48);
  float local_c = *(float*)(s + 0xc4) * *(float*)(s + 0x164) - *(float*)(s + 200) * *(float*)(s + 0x160);
  float local_8 = *(float*)(s + 200) * *(float*)(s + 0x15c) - *(float*)(s + 0xc0) * *(float*)(s + 0x164);
  *pfVar1 = local_c;
  *(float*)(s + 0x4c) = local_8;
  float local_4 = *(float*)(s + 0xc0) * *(float*)(s + 0x160) - *(float*)(s + 0xc4) * *(float*)(s + 0x15c);
  *(float*)(s + 0x50) = local_4;
  *(float*)(s + 0x78) = *(float*)(s + 0x20) * *pfVar1 + *(float*)(s + 0x24) * *(float*)(s + 0x4c) + *(float*)(s + 0x28) * *(float*)(s + 0x50);
  float fVar2 = *pfVar1 * *(float*)(s + 0x2c) + *(float*)(s + 0x30) * *(float*)(s + 0x4c) + *(float*)(s + 0x34) * *(float*)(s + 0x50);
  *(float*)(s + 0x9c) = fVar2;
  float fVar3 = -* (float*)(s + 0x10c);
  float local_20, local_1c;
  if (fVar3 < 0.0f) { local_20 = 0.0f; local_1c = fVar3; } else { local_1c = 0.0f; local_20 = fVar3; }
  double local_10 = 0.0, local_14 = 0.0;
  FUN_005a3390((double)*(float*)(s + 0x78), (double)*(float*)(s + 0x78), *(float*)(s + 0x1a8) + *(float*)(s + 0x78), &local_10, &local_14);
  FUN_005a3450((double)local_1c,(double)local_20,local_10,local_14,(double)fVar2);
}

// 0x5a3f80 — observed shape
void FUN_005a3f80(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0x54);
  *pfVar1 = *(float*)(s + 0xc4) * *(float*)(s + 0x170) - *(float*)(s + 200) * *(float*)(s + 0x16c);
  *(float*)(s + 0x58) = *(float*)(s + 200) * *(float*)(s + 0x168) - *(float*)(s + 0xc0) * *(float*)(s + 0x170);
  *(float*)(s + 0x5c) = *(float*)(s + 0xc0) * *(float*)(s + 0x16c) - *(float*)(s + 0xc4) * *(float*)(s + 0x168);
  *(float*)(s + 0x7c) = *(float*)(s + 0x20) * *pfVar1 + *(float*)(s + 0x24) * *(float*)(s + 0x58) + *(float*)(s + 0x28) * *(float*)(s + 0x5c);
  float fVar3 = *pfVar1 * *(float*)(s + 0x2c) + *(float*)(s + 0x30) * *(float*)(s + 0x58) + *(float*)(s + 0x34) * *(float*)(s + 0x5c);
  *(float*)(s + 0xa0) = fVar3;
  float fVar2 = -* (float*)(s + 0x110);
  float local_18, local_14;
  if (fVar2 < 0.0f) { local_18 = 0.0f; local_14 = fVar2; } else { local_14 = 0.0f; local_18 = fVar2; }
  fVar2 = *(float*)(s + 0x7c);
  float local_1c = *(float*)(s + 0x7c) - *(float*)(s + 0x1a8);
  float local_20;
  if (local_1c < fVar2) { local_20 = fVar2; } else { local_20 = local_1c; local_1c = fVar2; }
  FUN_005a3450((double)local_14,(double)local_18,(double)local_1c,(double)local_20,(double)fVar3);
}

// 0x5a40b0 — observed shape
void FUN_005a40b0(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0x60);
  *pfVar1 = *(float*)(s + 0xd0) * *(float*)(s + 0x164) - *(float*)(s + 0xd4) * *(float*)(s + 0x160);
  *(float*)(s + 100) = *(float*)(s + 0xd4) * *(float*)(s + 0x15c) - *(float*)(s + 0xcc) * *(float*)(s + 0x164);
  *(float*)(s + 0x68) = *(float*)(s + 0xcc) * *(float*)(s + 0x160) - *(float*)(s + 0xd0) * *(float*)(s + 0x15c);
  *(float*)(s + 0x84) = *(float*)(s + 0x20) * *pfVar1 + *(float*)(s + 0x24) * *(float*)(s + 100) + *(float*)(s + 0x28) * *(float*)(s + 0x68);
  float fVar3 = *pfVar1 * *(float*)(s + 0x2c) + *(float*)(s + 0x30) * *(float*)(s + 100) + *(float*)(s + 0x34) * *(float*)(s + 0x68);
  *(float*)(s + 0xa8) = fVar3;
  float fVar2 = *(float*)(s + 0x10c);
  float local_18, local_14;
  if (fVar2 < 0.0f) { local_18 = 0.0f; local_14 = fVar2; } else { local_14 = 0.0f; local_18 = fVar2; }
  fVar2 = *(float*)(s + 0x84);
  float local_1c = *(float*)(s + 0x1ac) + *(float*)(s + 0x78);
  float local_20;
  if (local_1c < fVar2) { local_20 = fVar2; } else { local_20 = local_1c; local_1c = fVar2; }
  FUN_005a3450((double)local_14,(double)local_18,(double)local_1c,(double)local_20,(double)fVar3);
}

// 0x5a41f0 — observed shape
void FUN_005a41f0(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0x6c);
  *pfVar1 = *(float*)(s + 0xd0) * *(float*)(s + 0x170) - *(float*)(s + 0xd4) * *(float*)(s + 0x16c);
  *(float*)(s + 0x70) = *(float*)(s + 0xd4) * *(float*)(s + 0x168) - *(float*)(s + 0xcc) * *(float*)(s + 0x170);
  *(float*)(s + 0x74) = *(float*)(s + 0xcc) * *(float*)(s + 0x16c) - *(float*)(s + 0xd0) * *(float*)(s + 0x168);
  *(float*)(s + 0x88) = *(float*)(s + 0x20) * *pfVar1 + *(float*)(s + 0x24) * *(float*)(s + 0x70) + *(float*)(s + 0x28) * *(float*)(s + 0x74);
  float fVar3 = *pfVar1 * *(float*)(s + 0x2c) + *(float*)(s + 0x30) * *(float*)(s + 0x70) + *(float*)(s + 0x34) * *(float*)(s + 0x74);
  *(float*)(s + 0xac) = fVar3;
  float fVar2 = *(float*)(s + 0x110);
  float local_18, local_14;
  if (fVar2 < 0.0f) { local_18 = 0.0f; local_14 = fVar2; } else { local_14 = 0.0f; local_18 = fVar2; }
  fVar2 = *(float*)(s + 0x88);
  float local_1c = *(float*)(s + 0x88) - *(float*)(s + 0x1ac);
  float local_20;
  if (local_1c < fVar2) { local_20 = fVar2; } else { local_20 = local_1c; local_1c = fVar2; }
  FUN_005a3450((double)local_14,(double)local_18,(double)local_1c,(double)local_20,(double)fVar3);
}

// 0x5a4330 — observed shape
void FUN_005a4330(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0x180);
  *(float*)(s + 0x1a4) = *(float*)(s + 0x174) * *(float*)(s + 0x174) + *(float*)(s + 0x178) * *(float*)(s + 0x178) + *(float*)(s + 0x17c) * *(float*)(s + 0x17c);
  float local_c = *(float*)(s + 0x178) * *(float*)(s + 0x164) - *(float*)(s + 0x17c) * *(float*)(s + 0x160);
  float local_8 = *(float*)(s + 0x17c) * *(float*)(s + 0x15c) - *(float*)(s + 0x174) * *(float*)(s + 0x164);
  *pfVar1 = local_c;
  *(float*)(s + 0x184) = local_8;
  float local_4 = *(float*)(s + 0x174) * *(float*)(s + 0x160) - *(float*)(s + 0x178) * *(float*)(s + 0x15c);
  *(float*)(s + 0x188) = local_4;
  *(float*)(s + 0x1d4) = *(float*)(s + 0xc0) * *pfVar1 + *(float*)(s + 0xc4) * *(float*)(s + 0x184) + *(float*)(s + 200) * *(float*)(s + 0x188);
  *(float*)(s + 0x1d8) = *pfVar1 * *(float*)(s + 0xcc) + *(float*)(s + 0xd0) * *(float*)(s + 0x184) + *(float*)(s + 0xd4) * *(float*)(s + 0x188);
  *(float*)(s + 0x1bc) = *(float*)(s + 0x20) * *pfVar1 + *(float*)(s + 0x24) * *(float*)(s + 0x184) + *(float*)(s + 0x28) * *(float*)(s + 0x188);
  float fVar2 = *(float*)(s + 0x2c) * *pfVar1 + *(float*)(s + 0x30) * *(float*)(s + 0x184) + *(float*)(s + 0x34) * *(float*)(s + 0x188);
  *(float*)(s + 0x1c8) = fVar2;
  double local_10 = 0.0, local_14 = 0.0;
  FUN_005a3390(0.0, (double)*(float*)(s + 0x1d4), (double)*(float*)(s + 0x1d8), &local_10, &local_14);
  FUN_005a3450(local_10, local_14, (double)*(float*)(s + 0x1bc), (double)(*(float*)(s + 0x1bc) + *(float*)(s + 0x1a4)), (double)fVar2);
}

// 0x5a44b0 — observed shape
void FUN_005a44b0(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0x18c);
  float local_c = *(float*)(s + 0x178) * *(float*)(s + 0x170) - *(float*)(s + 0x17c) * *(float*)(s + 0x16c);
  float local_8 = *(float*)(s + 0x168) * *(float*)(s + 0x17c) - *(float*)(s + 0x174) * *(float*)(s + 0x170);
  *pfVar1 = local_c;
  *(float*)(s + 400) = local_8;
  float local_4 = *(float*)(s + 0x174) * *(float*)(s + 0x16c) - *(float*)(s + 0x178) * *(float*)(s + 0x168);
  *(float*)(s + 0x194) = local_4;
  *(float*)(s + 0x1e0) = *pfVar1 * *(float*)(s + 0xc0) + *(float*)(s + 0xc4) * *(float*)(s + 400) + *(float*)(s + 200) * *(float*)(s + 0x194);
  *(float*)(s + 0x1e4) = *(float*)(s + 0xcc) * *pfVar1 + *(float*)(s + 0xd0) * *(float*)(s + 400) + *(float*)(s + 0xd4) * *(float*)(s + 0x194);
  *(float*)(s + 0x1c0) = *pfVar1 * *(float*)(s + 0x20) + *(float*)(s + 0x24) * *(float*)(s + 400) + *(float*)(s + 0x28) * *(float*)(s + 0x194);
  float fVar2 = *(float*)(s + 0x2c) * *pfVar1 + *(float*)(s + 0x30) * *(float*)(s + 400) + *(float*)(s + 0x34) * *(float*)(s + 0x194);
  *(float*)(s + 0x1cc) = fVar2;
  double local_10 = 0.0, local_14 = 0.0;
  FUN_005a3390(0.0, (double)*(float*)(s + 0x1e0), (double)*(float*)(s + 0x1e4), &local_10, &local_14);
  FUN_005a3450(local_10, local_14, (double)(*(float*)(s + 0x1c0) - *(float*)(s + 0x1a4)), (double)*(float*)(s + 0x1c0), (double)fVar2);
}

// 0x5a4610 — observed shape
void FUN_005a4610(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0xe4);
  *(float*)(s + 0x108) = *(float*)(s + 0xd8) * *(float*)(s + 0xd8) + *(float*)(s + 0xdc) * *(float*)(s + 0xdc) + *(float*)(s + 0xe0) * *(float*)(s + 0xe0);
  float local_c = *(float*)(s + 0xdc) * *(float*)(s + 200) - *(float*)(s + 0xe0) * *(float*)(s + 0xc4);
  float local_8 = *(float*)(s + 0xe0) * *(float*)(s + 0xc0) - *(float*)(s + 0xd8) * *(float*)(s + 200);
  *pfVar1 = local_c;
  *(float*)(s + 0xe8) = local_8;
  float local_4 = *(float*)(s + 0xd8) * *(float*)(s + 0xc4) - *(float*)(s + 0xdc) * *(float*)(s + 0xc0);
  *(float*)(s + 0xec) = local_4;
  *(float*)(s + 0x138) = *(float*)(s + 0x15c) * *pfVar1 + *(float*)(s + 0x160) * *(float*)(s + 0xe8) + *(float*)(s + 0x164) * *(float*)(s + 0xec);
  *(float*)(s + 0x13c) = *pfVar1 * *(float*)(s + 0x168) + *(float*)(s + 0x16c) * *(float*)(s + 0xe8) + *(float*)(s + 0x170) * *(float*)(s + 0xec);
  *(float*)(s + 0x120) = *(float*)(s + 0x20) * *pfVar1 + *(float*)(s + 0x24) * *(float*)(s + 0xe8) + *(float*)(s + 0x28) * *(float*)(s + 0xec);
  float fVar2 = *(float*)(s + 0x2c) * *pfVar1 + *(float*)(s + 0x30) * *(float*)(s + 0xe8) + *(float*)(s + 0x34) * *(float*)(s + 0xec);
  *(float*)(s + 300) = fVar2;
  double local_10 = 0.0, local_14 = 0.0;
  FUN_005a3390((double)*(float*)(s + 0x120), *(float*)(s + 0x138) + *(float*)(s + 0x120), *(float*)(s + 0x13c) + *(float*)(s + 0x120), &local_10, &local_14);
  FUN_005a3450(0.0, (double)*(float*)(s + 0x108), local_10, local_14, (double)fVar2);
}

// 0x5a47a0 — observed shape
void FUN_005a47a0(void* self){
  uint8_t* s = (uint8_t*)self;
  float* pfVar1 = (float*)(s + 0xf0);
  float local_c = *(float*)(s + 0xdc) * *(float*)(s + 0xd4) - *(float*)(s + 0xe0) * *(float*)(s + 0xd0);
  float local_8 = *(float*)(s + 0xcc) * *(float*)(s + 0xe0) - *(float*)(s + 0xd8) * *(float*)(s + 0xd4);
  *pfVar1 = local_c;
  *(float*)(s + 0xf4) = local_8;
  float local_4 = *(float*)(s + 0xd8) * *(float*)(s + 0xd0) - *(float*)(s + 0xdc) * *(float*)(s + 0xcc);
  *(float*)(s + 0xf8) = local_4;
  *(float*)(s + 0x144) = *pfVar1 * *(float*)(s + 0x15c) + *(float*)(s + 0x160) * *(float*)(s + 0xf4) + *(float*)(s + 0x164) * *(float*)(s + 0xf8);
  *(float*)(s + 0x148) = *(float*)(s + 0x168) * *pfVar1 + *(float*)(s + 0x16c) * *(float*)(s + 0xf4) + *(float*)(s + 0x170) * *(float*)(s + 0xf8);
  *(float*)(s + 0x124) = *pfVar1 * *(float*)(s + 0x20) + *(float*)(s + 0x24) * *(float*)(s + 0xf4) + *(float*)(s + 0x28) * *(float*)(s + 0xf8);
  float fVar2 = *(float*)(s + 0x2c) * *pfVar1 + *(float*)(s + 0x30) * *(float*)(s + 0xf4) + *(float*)(s + 0x34) * *(float*)(s + 0xf8);
  *(float*)(s + 0x130) = fVar2;
  double local_10 = 0.0, local_14 = 0.0;
  FUN_005a3390((double)*(float*)(s + 0x124), *(float*)(s + 0x144) + *(float*)(s + 0x124), *(float*)(s + 0x148) + *(float*)(s + 0x124), &local_10, &local_14);
  FUN_005a3450((double)(-* (float*)(s + 0x108)),0.0,local_10,local_14,(double)fVar2);
}

// 0x5a4910 — observed shape
extern float _DAT_00717c5c;
extern uint32_t DAT_00727430, DAT_00727434, DAT_00727438;
extern uint32_t FUN_005a3b50(void*);
extern uint32_t FUN_005a3d00(void*);
extern uint32_t FUN_005a4330(void*);
extern uint32_t FUN_005a44b0(void*);
extern uint32_t FUN_005a3840(void*);
extern uint32_t FUN_005a4610(void*);
extern uint32_t FUN_005a47a0(void*);
extern uint32_t FUN_005a38f0(void*);
extern uint32_t FUN_005a3e50(void*);
extern uint32_t FUN_005a3f80(void*);
extern uint32_t FUN_005a34b0(void*);
extern uint32_t FUN_005a40b0(void*);
extern uint32_t FUN_005a41f0(void*);
extern uint32_t FUN_005a3570(void*);
extern uint32_t FUN_005a3620(void*);
extern uint32_t FUN_005a36e0(void*);
extern uint32_t FUN_005a3790(void*);
uint8_t FUN_005a4910(uint32_t param_1, void* self){
  uint8_t* s = (uint8_t*)self;
  *(uint32_t*)(s + 0x22c) = param_1;
  uint8_t cVar3 = (uint8_t)FUN_005a3b50(self);
  if ((cVar3 != 0) && (cVar3 = (uint8_t)FUN_005a3d00(self), cVar3 != 0)) {
    float fVar2 = *(float*)(s + 0xdc) * *(float*)(s + 0x17c) - *(float*)(s + 0xe0) * *(float*)(s + 0x178);
    *(float*)(s + 0x38) = fVar2;
    *(float*)(s + 0x3c) = *(float*)(s + 0x174) * *(float*)(s + 0xe0) - *(float*)(s + 0xd8) * *(float*)(s + 0x17c);
    *(float*)(s + 0x40) = *(float*)(s + 0xd8) * *(float*)(s + 0x178) - *(float*)(s + 0x174) * *(float*)(s + 0xdc);
    fVar2 = fVar2 * fVar2 + *(float*)(s + 0x3c) * *(float*)(s + 0x3c) + *(float*)(s + 0x40) * *(float*)(s + 0x40);
    *(float*)(s + 0x44) = fVar2;
    if (fVar2 <= _DAT_00717c5c) {
      if (_DAT_00717c5c < fabsf(*(float*)(s + 0x11c))) {
        fVar2 = -(*(float*)(s + 0x118) / *(float*)(s + 0x11c));
        *(float*)(s + 0x20) = fVar2 * *(float*)(s + 0x2c) + *(float*)(s + 0x20);
        *(float*)(s + 0x24) = fVar2 * *(float*)(s + 0x30) + *(float*)(s + 0x24);
        *(float*)(s + 0x28) = fVar2 * *(float*)(s + 0x34) + *(float*)(s + 0x28);
        *(uint32_t*)(s + 0x2c) = DAT_00727430;
        *(uint32_t*)(s + 0x30) = DAT_00727434;
        *(uint32_t*)(s + 0x34) = DAT_00727438;
      }
      cVar3 = (uint8_t)FUN_005a4330(self);
      if ((((cVar3 != 0) && (cVar3 = (uint8_t)FUN_005a44b0(self), cVar3 != 0)) && (cVar3 = (uint8_t)FUN_005a3840(self), cVar3 != 0)) && (((cVar3 = (uint8_t)FUN_005a4610(self), cVar3 != 0 && (cVar3 = (uint8_t)FUN_005a47a0(self), cVar3 != 0)) && (cVar3 = (uint8_t)FUN_005a38f0(self), cVar3 != 0)))) {
        return 1;
      }
    } else {
      cVar3 = (uint8_t)FUN_005a3e50(self);
      if (((cVar3 != 0) && (cVar3 = (uint8_t)FUN_005a3f80(self), cVar3 != 0)) && ((cVar3 = (uint8_t)FUN_005a34b0(self), cVar3 != 0 && ((((cVar3 = (uint8_t)FUN_005a40b0(self), cVar3 != 0 && (cVar3 = (uint8_t)FUN_005a41f0(self), cVar3 != 0)) && (cVar3 = (uint8_t)FUN_005a3570(self), cVar3 != 0)) && ((cVar3 = (uint8_t)FUN_005a3620(self), cVar3 != 0 && (cVar3 = (uint8_t)FUN_005a36e0(self), cVar3 != 0))))))) {
        cVar3 = (uint8_t)FUN_005a3790(self);
        if (cVar3 == 0) return 0;
        return 1;
      }
    }
  }
  return 0;
}

// 0x5a4b20 — observed shape
extern float* FUN_0053ca60(void*, void*);
void FUN_005a4b20(int param_1, void* self){
  uint8_t* s = (uint8_t*)self;
  float local_18 = 0.0f, local_14 = 0.0f, local_10 = 0.0f;
  uint8_t local_c[4] = {0,0,0,0};
  float* pfVar2 = FUN_0053ca60(&local_18, self);
  float fVar1 = *(float*)(param_1 + 0x30);
  float local_8 = fVar1 * pfVar2[1];
  float local_4 = fVar1 * pfVar2[2];
  local_18 = fVar1 * pfVar2[0] + *(float*)(param_1 + 0x24);
  local_14 = local_8 + *(float*)(param_1 + 0x28);
  local_10 = local_4 + *(float*)(param_1 + 0x2c);
  *(float*)(s + 0x3c) = local_18;
  *(float*)(s + 0x40) = local_14;
  *(float*)(s + 0x44) = local_10;
  uint32_t* puVar3 = (uint32_t*)FUN_0053ca60(local_c, s + 0xc);
  *(uint32_t*)(s + 0x48) = puVar3[0]; *(uint32_t*)(s + 0x4c) = puVar3[1]; *(uint32_t*)(s + 0x50) = puVar3[2];
  puVar3 = (uint32_t*)FUN_0053ca60(local_c, s + 0x18);
  *(uint32_t*)(s + 0x54) = puVar3[0]; *(uint32_t*)(s + 0x58) = puVar3[1]; *(uint32_t*)(s + 0x5c) = puVar3[2];
  puVar3 = (uint32_t*)FUN_0053ca60(local_c, s + 0x24);
  *(uint32_t*)(s + 0x60) = puVar3[0]; *(uint32_t*)(s + 100) = puVar3[1]; *(uint32_t*)(s + 0x68) = puVar3[2];
  *(float*)(s + 0x6c) = *(float*)(s + 0x30) * *(float*)(param_1 + 0x30);
  *(float*)(s + 0x70) = *(float*)(s + 0x34) * *(float*)(param_1 + 0x30);
  *(float*)(s + 0x74) = *(float*)(s + 0x38) * *(float*)(param_1 + 0x30);
}

// 0x5a4c20 — observed shape
uint32_t FUN_005a4c20(int param_1, void* self){
  uint8_t* s = (uint8_t*)self; uint8_t* p = (uint8_t*)param_1;
  int iVar1 = *(int*)(p + 0x78);
  int iVar2 = *(int*)(s + 0x78);
  float fVar4 = *(float*)(p + 0x3c) - *(float*)(s + 0x3c);
  float fVar5 = *(float*)(p + 0x40) - *(float*)(s + 0x40);
  float fVar6 = *(float*)(p + 0x44) - *(float*)(s + 0x44);
  float fVar7 = *(float*)(iVar1 + 0x10) - *(float*)(iVar2 + 0x10);
  float fVar8 = *(float*)(iVar1 + 0x14) - *(float*)(iVar2 + 0x14);
  float fVar3 = *(float*)(iVar2 + 4);
  float fVar9 = *(float*)(iVar1 + 0x18) - *(float*)(iVar2 + 0x18);
  float fVar10 = *(float*)(p + 0x48) * *(float*)(s + 0x48) + *(float*)(s + 0x4c) * *(float*)(p + 0x4c) + *(float*)(p + 0x50) * *(float*)(s + 0x50);
  float fVar11 = *(float*)(s + 0x48) * *(float*)(p + 0x54) + *(float*)(p + 0x5c) * *(float*)(s + 0x50) + *(float*)(p + 0x58) * *(float*)(s + 0x4c);
  float fVar12 = *(float*)(p + 0x60) * *(float*)(s + 0x48) + *(float*)(p + 0x68) * *(float*)(s + 0x50) + *(float*)(p + 100) * *(float*)(s + 0x4c);
  float fVar13 = fVar5 * *(float*)(s + 0x4c) + fVar6 * *(float*)(s + 0x50) + fVar4 * *(float*)(s + 0x48);
  float fVar14 = (fVar8 * *(float*)(s + 0x4c) + fVar7 * *(float*)(s + 0x48) + fVar9 * *(float*)(s + 0x50)) * fVar3 + fVar13;
  float fVar15 = fabsf(*(float*)(s + 0x6c)) + fabsf(fVar10 * *(float*)(p + 0x6c)) + fabsf(fVar11 * *(float*)(p + 0x70)) + fabsf(fVar12 * *(float*)(p + 0x74));
  if ((fVar13 <= fVar15) || (fVar14 <= fVar15)) {
    if ((fVar13 < -fVar15) && (fVar14 < -fVar15)) return 0;
    float fVar16 = *(float*)(p + 0x54) * *(float*)(s + 0x54) + *(float*)(p + 0x58) * *(float*)(s + 0x58) + *(float*)(p + 0x5c) * *(float*)(s + 0x5c);
    float fVar15a = *(float*)(s + 0x54) * *(float*)(p + 0x48) + *(float*)(s + 0x58) * *(float*)(p + 0x4c) + *(float*)(s + 0x5c) * *(float*)(p + 0x50);
    float fVar17 = *(float*)(p + 0x60) * *(float*)(s + 0x54) + *(float*)(p + 100) * *(float*)(s + 0x58) + *(float*)(p + 0x68) * *(float*)(s + 0x5c);
    float fVar18 = fVar4 * *(float*)(s + 0x54) + fVar5 * *(float*)(s + 0x58) + fVar6 * *(float*)(s + 0x5c);
    float fVar19 = (fVar7 * *(float*)(s + 0x54) + fVar8 * *(float*)(s + 0x58) + fVar9 * *(float*)(s + 0x5c)) * fVar3 + fVar18;
    float fVar20 = fabsf(*(float*)(s + 0x70)) + fabsf(fVar15a * *(float*)(p + 0x6c)) + fabsf(fVar16 * *(float*)(p + 0x70)) + fabsf(fVar17 * *(float*)(p + 0x74));
    if ((fVar18 <= fVar20) || (fVar19 <= fVar20)) {
      if ((fVar18 < -fVar20) && (fVar19 < -fVar20)) return 0;
      float fVar21_ = *(float*)(p + 0x54) * *(float*)(s + 0x60) + *(float*)(p + 0x58) * *(float*)(s + 100) + *(float*)(p + 0x5c) * *(float*)(s + 0x68);
      float fVar20b = *(float*)(p + 0x48) * *(float*)(s + 0x60) + *(float*)(s + 100) * *(float*)(p + 0x4c) + *(float*)(s + 0x68) * *(float*)(p + 0x50);
      float fVar22 = *(float*)(p + 0x60) * *(float*)(s + 0x60) + *(float*)(p + 100) * *(float*)(s + 100) + *(float*)(p + 0x68) * *(float*)(s + 0x68);
      float fVar23 = fVar4 * *(float*)(s + 0x60) + fVar5 * *(float*)(s + 100) + fVar6 * *(float*)(s + 0x68);
      float fVar24 = (fVar7 * *(float*)(s + 0x60) + fVar8 * *(float*)(s + 100) + fVar9 * *(float*)(s + 0x68)) * fVar3 + fVar23;
      float fVar25 = fabsf(*(float*)(s + 0x74)) + fabsf(fVar20b * *(float*)(p + 0x6c)) + fabsf(fVar21_ * *(float*)(p + 0x70)) + fabsf(fVar22 * *(float*)(p + 0x74));
      if ((fVar23 <= fVar25) || (fVar24 <= fVar25)) {
        if ((fVar23 < -fVar25) && (fVar24 < -fVar25)) return 0;
        fVar25 = fabsf(*(float*)(p + 0x6c)) + fabsf(fVar10 * *(float*)(s + 0x6c)) + fabsf(fVar15a * *(float*)(s + 0x70)) + fabsf(fVar20b * *(float*)(s + 0x74));
        float fVar26 = fVar6 * *(float*)(p + 0x50) + fVar5 * *(float*)(p + 0x4c) + fVar4 * *(float*)(p + 0x48);
        float fVar27 = (fVar9 * *(float*)(p + 0x50) + fVar8 * *(float*)(p + 0x4c) + fVar7 * *(float*)(p + 0x48)) * fVar3 + fVar26;
        if (((fVar26 <= fVar25) || (fVar27 <= fVar25)) && ((-fVar25 <= fVar26 || (-fVar25 <= fVar27)))) {
          fVar25 = fabsf(*(float*)(p + 0x70)) + fabsf(fVar11 * *(float*)(s + 0x6c)) + fabsf(fVar16 * *(float*)(s + 0x70)) + fabsf(fVar21_ * *(float*)(s + 0x74));
          fVar26 = fVar4 * *(float*)(p + 0x54) + fVar5 * *(float*)(p + 0x58) + fVar6 * *(float*)(p + 0x5c);
          fVar27 = (fVar7 * *(float*)(p + 0x54) + fVar9 * *(float*)(p + 0x5c) + fVar8 * *(float*)(p + 0x58)) * fVar3 + fVar26;
          if (((fVar26 <= fVar25) || (fVar27 <= fVar25)) && ((-fVar25 <= fVar26 || (-fVar25 <= fVar27)))) {
            fVar25 = fabsf(*(float*)(p + 0x74)) + fabsf(fVar12 * *(float*)(s + 0x6c)) + fabsf(fVar17 * *(float*)(s + 0x70)) + fabsf(fVar22 * *(float*)(s + 0x74));
            fVar4 = fVar4 * *(float*)(p + 0x60) + fVar5 * *(float*)(p + 100) + fVar6 * *(float*)(p + 0x68);
            fVar3 = (fVar7 * *(float*)(p + 0x60) + fVar8 * *(float*)(p + 100) + fVar9 * *(float*)(p + 0x68)) * fVar3 + fVar4;
            if (((fVar4 <= fVar25) || (fVar3 <= fVar25)) && ((-fVar25 <= fVar4 || (-fVar25 <= fVar3)))) {
              float fVar3b = fabsf(fVar12 * *(float*)(p + 0x70)) + fabsf(fVar11 * *(float*)(p + 0x74)) + fabsf(fVar20b * *(float*)(s + 0x70)) + fabsf(fVar15a * *(float*)(s + 0x74));
              float fVar4b = fVar23 * fVar15a - fVar20b * fVar18;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar24 * fVar15a - fVar20b * fVar19 < -fVar3b)) return 0; }
              else if (fVar3b < fVar24 * fVar15a - fVar20b * fVar19) return 0;
              fVar3b = fabsf(fVar21_ * *(float*)(s + 0x70)) + fabsf(fVar16 * *(float*)(s + 0x74)) + fabsf(fVar12 * *(float*)(p + 0x6c)) + fabsf(fVar10 * *(float*)(p + 0x74));
              fVar4b = fVar23 * fVar16 - fVar21_ * fVar18;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar24 * fVar16 - fVar21_ * fVar19 < -fVar3b)) return 0; }
              else if (fVar3b < fVar24 * fVar16 - fVar21_ * fVar19) return 0;
              fVar3b = fabsf(fVar22 * *(float*)(s + 0x70)) + fabsf(fVar17 * *(float*)(s + 0x74)) + fabsf(fVar11 * *(float*)(p + 0x6c)) + fabsf(fVar10 * *(float*)(p + 0x70));
              fVar4b = fVar23 * fVar17 - fVar22 * fVar18;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar24 * fVar17 - fVar22 * fVar19 < -fVar3b)) return 0; }
              else if (fVar3b < fVar24 * fVar17 - fVar22 * fVar19) return 0;
              fVar3b = fabsf(fVar20b * *(float*)(s + 0x6c)) + fabsf(fVar10 * *(float*)(s + 0x74)) + fabsf(fVar17 * *(float*)(p + 0x70)) + fabsf(fVar16 * *(float*)(p + 0x74));
              fVar4b = fVar20b * fVar13 - fVar23 * fVar10;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar20b * fVar14 - fVar24 * fVar10 < -fVar3b)) return 0; }
              else if (fVar3b < fVar20b * fVar14 - fVar24 * fVar10) return 0;
              fVar3b = fabsf(fVar21_ * *(float*)(s + 0x6c)) + fabsf(fVar11 * *(float*)(s + 0x74)) + fabsf(fVar17 * *(float*)(p + 0x6c)) + fabsf(fVar15a * *(float*)(p + 0x74));
              fVar4b = fVar21_ * fVar13 - fVar23 * fVar11;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar21_ * fVar14 - fVar24 * fVar11 < -fVar3b)) return 0; }
              else if (fVar3b < fVar21_ * fVar14 - fVar24 * fVar11) return 0;
              fVar3b = fabsf(fVar22 * *(float*)(s + 0x6c)) + fabsf(fVar12 * *(float*)(s + 0x74)) + fabsf(fVar16 * *(float*)(p + 0x6c)) + fabsf(fVar15a * *(float*)(p + 0x70));
              fVar4b = fVar22 * fVar13 - fVar23 * fVar12;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar22 * fVar14 - fVar24 * fVar12 < -fVar3b)) return 0; }
              else if (fVar3b < fVar22 * fVar14 - fVar24 * fVar12) return 0;
              fVar3b = fabsf(fVar22 * *(float*)(p + 0x70)) + fabsf(fVar21_ * *(float*)(p + 0x74)) + fabsf(fVar15a * *(float*)(s + 0x6c)) + fabsf(fVar10 * *(float*)(s + 0x70));
              fVar4b = fVar18 * fVar10 - fVar15a * fVar13;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar19 * fVar10 - fVar15a * fVar14 < -fVar3b)) return 0; }
              else if (fVar3b < fVar19 * fVar10 - fVar15a * fVar14) return 0;
              fVar3b = fabsf(fVar16 * *(float*)(s + 0x6c)) + fabsf(fVar11 * *(float*)(s + 0x70)) + fabsf(fVar22 * *(float*)(p + 0x6c)) + fabsf(fVar20b * *(float*)(p + 0x74));
              fVar4b = fVar18 * fVar11 - fVar16 * fVar13;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar19 * fVar11 - fVar16 * fVar14 < -fVar3b)) return 0; }
              else if (fVar3b < fVar19 * fVar11 - fVar16 * fVar14) return 0;
              fVar3b = fabsf(fVar17 * *(float*)(s + 0x6c)) + fabsf(fVar12 * *(float*)(s + 0x70)) + fabsf(fVar21_ * *(float*)(p + 0x6c)) + fabsf(fVar20b * *(float*)(p + 0x70));
              fVar4b = fVar18 * fVar12 - fVar17 * fVar13;
              if (fVar4b <= fVar3b) { if ((fVar4b < -fVar3b) && (fVar19 * fVar12 - fVar17 * fVar14 < -fVar3b)) return 0; }
              else if (fVar3b < fVar19 * fVar12 - fVar17 * fVar14) return 0;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

// NEEDS_MANUAL: 0x5a57f0 — 1484-line Ghidra listing with switch/case blocks; observed operations preserved in summary form below.
// 0x5a57f0 — observed shape
uint32_t FUN_005a57f0(int param_1, float* param_2, uint32_t* param_3, void* self){
// Preserved: leading differences (0x3c/0x40/0x44 minus), iVar2/iVar17 derefs at +0x10/+0x14/+0x18, fVar3 from +4,
// dot products 0x48/0x54/0x60 triplets, fVar5 ABS bounds, fVar5<(>) return 0 early-outs, parametric t computation
// ((fVar5-local_444)*fVar3)/(local_45c-local_444), subsequent axis blocks for 0x54/0x60, further param_1/in_ECX 0x48/0x54/0x60
// dot products, and switch cases 0x0-0xe computing local_454 via FUN_00431450 chains, then FUN_00497ca0 calls and param_3 copy, return 1.
  (void)param_1; (void)param_2; (void)param_3; (void)self;
  return 1;
}

// 0x5a8560 — observed shape
extern void FUN_00491640(void);
void FUN_005a8560(float* param_1, float* param_2, void* self){
  uint8_t* s = (uint8_t*)self;
  float fVar1 = *(float*)(s + 0x70);
  float fVar2 = *(float*)(s + 0x6c);
  float fVar3 = *(float*)(s + 0x74);
  FUN_00491640();
  if (!isnan(fVar2) && ((fVar2 < 0.0001f) != (fVar2 == 0.0001f))) {
    *param_2 = *(float*)(s + 0x48); param_2[1] = *(float*)(s + 0x4c); param_2[2] = *(float*)(s + 0x50); return;
  }
  if (!isnan(fVar1) && ((fVar1 < 0.0001f) != (fVar1 == 0.0001f))) {
    *param_2 = *(float*)(s + 0x54); param_2[1] = *(float*)(s + 0x58); param_2[2] = *(float*)(s + 0x5c); return;
  }
  if (isnan(fVar3) || ((fVar3 < 0.0001f) == (fVar3 == 0.0001f))) {
    fVar1 = *param_1 - *(float*)(s + 0x3c);
    fVar3 = param_1[1] - *(float*)(s + 0x40);
    fVar2 = param_1[2] - *(float*)(s + 0x44);
    *param_2 = (fVar1 * *(float*)(s + 0x48) + fVar3 * *(float*)(s + 0x4c) + fVar2 * *(float*)(s + 0x50)) / (*(float*)(s + 0x6c) * *(float*)(s + 0x6c));
    param_2[1] = (fVar1 * *(float*)(s + 0x54) + fVar3 * *(float*)(s + 0x58) + fVar2 * *(float*)(s + 0x5c)) / (*(float*)(s + 0x70) * *(float*)(s + 0x70));
    param_2[2] = (fVar1 * *(float*)(s + 0x60) + fVar3 * *(float*)(s + 100) + fVar2 * *(float*)(s + 0x68)) / (*(float*)(s + 0x74) * *(float*)(s + 0x74));
    FUN_00491640(); return;
  }
  *param_2 = *(float*)(s + 0x60); param_2[1] = *(float*)(s + 100); param_2[2] = *(float*)(s + 0x68);
}
