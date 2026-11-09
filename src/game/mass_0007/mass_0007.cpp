// Reconstruction batch mass_0007 — Sid Meier's Pirates! (2004) PE32 i386
// Source reconstruction from Ghidra 12.2 pseudocode corpus.
// Receiver registers (in_ECX/in_EAX/...) are exposed as explicit void* self / first parameter.

#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

// ---------- shared externs (referenced globals observed per listing) ----------
extern float   DAT_00726ae8_f;              // via DAT_00726ae8 (float triple at 0x726ae8)
extern int     DAT_00860970_i;
extern int     DAT_00860974_i;
extern int     DAT_008cac18_i;
extern int     DAT_008cac1c_i;
extern int     DAT_008cac26_c, DAT_008cac27_c, DAT_008cac30_i, DAT_008cac38_i;
extern int     DAT_008cac40_i, DAT_008cace8_i, DAT_008cacec_i, DAT_008cacf0_i;
extern int     DAT_008ed5b0_i, DAT_008ed5b4_c, DAT_0086c334_i, DAT_0086c338_i;
extern int     DAT_0086c33c_i, DAT_0086c340_i, DAT_0086c344_i, DAT_0086c348_i, DAT_0086c34c_i, DAT_0086c350_i;
extern int     DAT_0086c35c_i, DAT_0086c360_i, DAT_0086c330_i;
extern int     DAT_0085a0fc_i, DAT_0085a158_i, DAT_0085a164_i, DAT_0085a11c_i;
extern int     DAT_0085a268_i, DAT_0085a26c_i;
extern int     DAT_008dc30c_i, DAT_008dc310_i;
extern int     DAT_0072637c_i, DAT_00726380_i, DAT_007263bc_i, DAT_007263a8_i, DAT_007263b0_c;
extern int     DAT_00726664_i, DAT_00726668_i, DAT_00726698_i, DAT_00726704_i;
extern int     DAT_00726a84_i, DAT_007268f4_i, DAT_0072540c_i;
extern int     DAT_008e8fdc_i, DAT_008e8fe8_c;
extern int     DAT_008ed61c_i, DAT_008ed618_i;
extern int     DAT_00861b74_i, DAT_00861b70_i, DAT_00861b68_i, DAT_00861b6c_i;
extern int     DAT_008ca92c_i, DAT_008cad20_i, DAT_00869ab0_i, DAT_0081431e_i, DAT_00860eb6_i;
extern void*   DAT_008ea000_p, *DAT_008ea008_p, *DAT_008e9fe8_p, *DAT_008e9fec_p, *DAT_008e9ff0_p, *DAT_008e9ff8_p;
extern void*   DAT_008ea08c_p;
extern void*   DAT_008cabe8_p, *DAT_008c9de4_p, *DAT_008c9dec_p, *DAT_008c9de8_p, *DAT_0072cd78_p, *DAT_0072cd74_p;
extern void*   DAT_008e9fe4_p, *DAT_0086bb5c_p, *DAT_0086bb58_p, *DAT_008c8280_p;
extern void*   DAT_008c9de0_p, *DAT_008c9dd8_p;
extern void*   PTR_DAT_0072680c_p; // int refcount at -4
extern HCURSOR DAT_008cacd8_h;
extern HWND    DAT_00726b8c_h;
extern char    DAT_006f588c_[256];
extern char    DAT_008cacd0_[256];

// helper / cross-function externs
extern void  FUN_004b06c0(uint32_t, uint32_t);
extern int   FUN_004db210();
extern int   FUN_004afaa0(), FUN_00496370(), FUN_004e4d30(), FUN_004ab230();
extern void  FUN_004b2040(), FUN_004e6770(), FUN_004e2730(), FUN_004d9630(), FUN_004d9c80();
extern void  FUN_004af8c0();
extern void  operator_delete(void*);
extern void  operator_delete__(void*);
extern void* FUN_00533c78(size_t);
extern void  FUN_004bdca0(void*, int, int, int, int, int, int, int, int, int);
extern void  FUN_00495390(), FUN_004bcd00(int), FUN_004bdd90(void*, const char*), FUN_004bc7e0(int,int);
extern void  FUN_004baaa0(), FUN_004c03c0(int,int), FUN_004bcac0(), FUN_004bc5c0(int);
extern void  FUN_00534130(), FUN_004c0a40(int), FUN_0046baa0(), FUN_004c0980(int,int), FUN_004c0940(), FUN_004c08b0(int);
extern void  FUN_00535de0(int), FUN_00535e10(), FUN_004abb50(const char*, double);
extern int   FUN_00412f10(), FUN_004f5480(void*, int), FUN_004129c0(int*, int), FUN_00412ec0();
extern void  FUN_00429610(), FUN_0042b6f0(), FUN_0042c000(), FUN_0042b660();
extern int   FUN_0042e1d0(void*), FUN_0051bfc0(void*);
extern uint32_t FUN_004f8e40(void*);
extern void  FUN_004b0560(), FUN_004c5a60(), FUN_004c59b0(), FUN_004c5960(), FUN_004c5910();
extern void  FUN_004aafd0(int), FUN_004e8ea0(void*), FUN_004e9740(), FUN_00498260(void*), FUN_00497fd0(void*);
extern void  FUN_004889c0(void*,int,int,int,int,double,int), FUN_00488fc0(void*,int,double), FUN_004888e0(int,int,int,double);
extern void  FUN_00508190(), FUN_00508670(void*,void*), FUN_004f6090(const char*), FUN_00509500(void*,void*,int);
extern int   FUN_005f0ddc(), FUN_00430190(int,int,const char*,int,int,void*,int,int,int,int);
extern void  FUN_00471ab0(), FUN_0046c8d0(int), FUN_00471e00(int), FUN_00419370(), FUN_0048c0e0(), FUN_0047a040(int);
extern int   FUN_00415860(int,int,int), FUN_00438e30(void*), FUN_004b6070(int), FUN_004ae700(), FUN_004ae720();
extern void  FUN_004c9930(), FUN_00454af0(), FUN_0042e730(), FUN_004b4760(int), FUN_00455ca0();
extern const char* FUN_004f40f0();

// 0x428470 — observed shape: self is float* in ECX, param float*, 3-element compare, 0/1
uint32_t FUN_00428470(void* self, const float* param_1) {
  float* s = (float*)self;
  if (s[0] == param_1[0] && s[1] == param_1[1] && s[2] == param_1[2]) return 0;
  return 1;
}

// 0x4284c0 — observed shape: same 3-float compare, inverted (1/0)
uint32_t FUN_004284c0(void* self, const float* param_1) {
  float* s = (float*)self;
  if (s[0] == param_1[0] && s[1] == param_1[1] && s[2] == param_1[2]) return 1;
  return 0;
}

// 0x428500 — observed shape: tail call to FUN_004b06c0(param1, param2)
void FUN_00428500(uint32_t param_1, uint32_t param_2) {
  FUN_004b06c0(param_1, param_2);
}

// 0x428530 — observed shape: swap float triples: *in_EAX <-> DAT_00726ae8 triple, in_ECX[1],[2] <-> DAT_00726aec/aaf0
void FUN_00428530(void* self_ecx, uint32_t* self_eax) {
  uint32_t* ecx = (uint32_t*)self_ecx;
  uint32_t* eax = (uint32_t*)self_eax;
  extern uint32_t g_726ae8[3];
  uint32_t t2 = g_726ae8[2], t1 = g_726ae8[1];
  g_726ae8[1] = ecx[1]; g_726ae8[2] = ecx[2];
  uint32_t t0 = ecx[0];
  eax[0] = g_726ae8[0]; g_726ae8[0] = t0;
  eax[1] = t1; eax[2] = t2;
}

// 0x428570 — observed shape: computes per-index ship stats, switch(param_1) adjusts
void FUN_00428570(int param_1) {
  extern int DAT_00861b74, DAT_00861b70;
  extern uint8_t DAT_00860b75[], DAT_00860b76[], DAT_00860b7c[];
  extern int16_t DAT_0085bfb4[];
  // NOTE: exact table addresses/offsets preserved from listing (see source listing for byte offsets)
  int iVar11 = param_1 * 0x94;
  uint8_t bVar1 = DAT_00860b75[param_1 * 0x20];
  ((int16_t*)((char*)DAT_0085bfb4 + iVar11))[0] = 1;
  int iVar7 = FUN_004db210();
  int iVar8 = (int8_t)DAT_00860b7c[param_1 * 8];
  // short slots at param*0x4a words from DAT_0085bfb6/b8/ba/bc/be/c0 bases — bool logic below mirrors listing
  auto baseB6 = DAT_0085bfb4 + 1; // 0x85bfb6 as short index 1
  auto baseB8 = DAT_0085bfb4 + 2;
  auto baseBA = DAT_0085bfb4 + 3;
  auto baseBC = DAT_0085bfb4 + 4;
  auto baseBE = DAT_0085bfb4 + 5;
  baseB6[param_1 * 0x4a] = (int16_t)(iVar7 / 0x14) + 3;
  long long u3 = 0x5265cLL / (long long)(iVar8 + 0x32);
  baseB8[param_1 * 0x4a] = (int16_t)(u3 / (long long)(0xfa - iVar7));
  baseBA[param_1 * 0x4a] = (int16_t)(2000 / (long long)(iVar8 + 100 + iVar7));
  baseBC[param_1 * 0x4a] = (int16_t)(iVar8 / (iVar7 / 0x14 + 10)) + 4;
  iVar7 = iVar7 / 10;
  if (iVar7 < 0) iVar7 = 0; else if (0xf < iVar7) iVar7 = 0xf;
  iVar8 = (int8_t)DAT_00860b7c[param_1 * 8];
  baseBE[param_1 * 0x4a] = (int16_t)(iVar8 / (0x19 - iVar7)) + 2;
  int local_c = (int)((uint32_t)bVar1 * 100) / DAT_00861b74;
  if (local_c < 10) local_c = 10; else if (200 < local_c) local_c = 200;
  iVar8 = (iVar8 * 100) / DAT_00861b70;
  if (iVar8 < 10) iVar8 = 10; else if (200 < iVar8) iVar8 = 200;
  int i7 = (iVar8 * 3 + 300) * 2;
  int16_t sVar4 = (int16_t)(i7 / 200);
  int i8 = (iVar8 + 0x32) * 0x10;
  baseB6[param_1 * 0x4a] = sVar4;
  int16_t sVar5 = (int16_t)(i8 / (local_c + 0x50)) + 2;
  baseB8[param_1 * 0x4a] = sVar5;
  int16_t sVar6 = (int16_t)(i7 / (local_c + 0x50));
  baseBA[param_1 * 0x4a] = sVar6;
  int16_t sVar10 = (int16_t)(i8 / (0x122 - local_c)) + 2;
  baseBC[param_1 * 0x4a] = sVar10;
  int8_t cVar2 = DAT_00860b76[param_1 * 0x20];
  int16_t sVar9 = (int16_t)(i7 / (0x122 - local_c));
  baseBE[param_1 * 0x4a] = sVar9;
  DAT_0085bfb4[param_1 * 0x4a + 6] = (int16_t)(0x32 / (int)(((int)((int)cVar2 + 10U) < 0) - 1 & (int)cVar2 + 10U) + 1);
  switch (param_1) {
    case 0: baseBA[iVar11] = sVar6 - sVar6 / 3; return;
    case 1: case 0x26: baseBC[param_1*0x4a] = sVar10/2 + sVar10; return;
    case 2: baseBE[param_1*0x4a] = sVar9/2 + sVar9; return;
    case 6: case 0xd: case 0x18: case 0x19:
      baseBA[iVar11] = sVar6/2 + sVar6; return;
    case 7: baseBC[param_1*0x4a]=sVar10/3+sVar10; baseBE[param_1*0x4a]=sVar9/3+sVar9; return;
    case 8: case 0x21: baseB8[param_1*0x4a]=sVar5/2+sVar5; return;
    case 10: baseB8[param_1*0x4a]=(int16_t)((10-sVar5)/2)+sVar5; return;
    case 0x10: case 0x1d: case 0x25: case 0x2a:
      baseB8[param_1*0x4a]=sVar5/3+sVar5; baseBA[iVar11]=sVar6/3+sVar6; return;
    case 0x13: case 0x23: case 0x2b: baseB6[param_1*0x4a]=sVar4-sVar4/2; return;
    case 0x1f: case 0x22:
      baseBC[param_1*0x4a]=sVar10/3+sVar10; baseBE[param_1*0x4a]=sVar9/3+sVar9;
      baseB8[param_1*0x4a]=sVar5/3+sVar5; baseBA[iVar11]=sVar6/3+sVar6; return;
    default: return;
  }
}

// 0x428950 — observed shape: in_EAX index, 0x2c threshold, clamped table lookup
int FUN_00428950(int idx) {
  extern int DAT_00861b70, DAT_00861b74, DAT_00861b6c;
  extern uint8_t DAT_00860b75[], DAT_00860b76[], DAT_00860b7c[], DAT_00723b00[];
  // int tables indexed idx*8 (bytes) observed in listing
  extern int DAT_00860b80[];
  if ((int)idx > 0x2c) return DAT_00860b80[idx * 8] + 4;
  int denom = (int)DAT_00860b7c[idx * 8] + (uint8_t)DAT_00860b75[idx * 0x20];
  int iVar1 = (((int)(int8_t)DAT_00860b76[idx * 0x20] * 300) / DAT_00861b6c) / denom;
  if (iVar1 < 0) iVar1 = 0; else if (1 < iVar1) iVar1 = 1;
  int cmp1 = DAT_00861b70 <= (int)DAT_00860b7c[idx * 8];
  int cmp2 = DAT_00861b74 <= (int)(uint8_t)DAT_00860b75[idx * 0x20];
  return (int)(int8_t)DAT_00723b00[(cmp1 + cmp2 * 2) * 2 + iVar1];
}

// 0x4289d0 — observed shape: formula on idx, clamp [1,100]
int FUN_004289d0(int idx) {
  extern int DAT_00861b74;
  extern uint8_t DAT_00860b75[];
  extern int DAT_00860b70[];
  extern int8_t DAT_00860b7c[];
  int flag = (DAT_00860b70[idx * 8] & 0x20000) != 0;
  int iVar2 = (int)(((-(uint32_t)flag & 0xffffffe7) + 0x19) * (uint8_t)DAT_00860b75[idx * 0x20]) / DAT_00861b74
            + ((int)(DAT_00860b7c[idx * 8] + ((DAT_00860b7c[idx * 8] >> 31 & 3U))) >> 2);
  if (iVar2 < 1) return 1;
  if (iVar2 < 0x65) return iVar2;
  return 100;
}

// 0x428a30 — observed shape: global-table rebuild; two sweeps + derived fixup loop (0x2c entries)
void FUN_00428a30(int param_1) {
  extern int DAT_00861b68, DAT_00861b6c, DAT_00861b74, DAT_00861b70;
  extern uint8_t DAT_00860b75[];
  extern int DAT_0085bf98[], DAT_0085bf94[], DAT_0085bf9c[];
  extern uint8_t DAT_00860b74_[];
  int iVar6 = 0, iVar7 = 0, iVar13 = 0;
  DAT_00861b68 = 0; DAT_00861b6c = 0;
  uint8_t* pb = DAT_00860b75;
  int* pu = DAT_0085bf98;
  do {
    if (*(int*)(pb - 5) > -1) {
      iVar6 += *pb;
      iVar13 += *(int*)(pb + 7);
      DAT_00861b68 += *(int16_t*)(pu - 6);
      DAT_00861b6c += (int8_t)pb[1];
      for (int k = 0; k < 7; ++k) pu[k] = 0;
      ++iVar7;
    }
    pb += 0x20; pu += 0x25;
  } while ((uintptr_t)pb < 0x8610f5);
  DAT_00861b74 = iVar6 / iVar7;
  // second sweep (full body observed; core assignments preserved, table-pointer form)
  int* l2c = DAT_0085bf94; int* l28 = DAT_0085bf9c; uint8_t* l24 = DAT_00860b74_;
  DAT_00861b70 = iVar13 / iVar7;
  DAT_00861b68 = DAT_00861b68 / iVar7;
  DAT_00861b6c = DAT_00861b6c / iVar7;
  extern uint8_t DAT_00869a88[];
  do {
    if (*(int*)(l24 - 4) > -1) {
      uint8_t u12 = l24[1];
      int i6 = *(int*)(l24 + 8);
      int i7v = (int)((long long)(u12 + 10) * 0x96 / (long long)(i6 + 100));
      int i13 = ((i6 + (i6 >> 31 & 3U)) >> 2) + (int)(((-(uint)((*(uint*)(l24-4) & 0x20000)) & 0xffffffe7) + 0x19) * u12) / DAT_00861b74;
      int i8 = i13 < 1 ? 1 : (i13 > 100 ? 100 : i13);
      uint8_t b = DAT_00869a88[l24[0] * 2];
      i8 = (i8 + 4) * 0x32;
      if (b > 1) i7v += 0xf;
      if (b > 5) i7v += 0x19;
      if (b > 3) i8 += i8 / 2;
      if (b > 7) i8 += i8 / 2;
      if (param_1 == 1) {
        *(int16_t*)((char*)l2c + 0x2e) = (int16_t)i7v; l2c[0] = i8;
      } else if (param_1 != -1) {
        *(int16_t*)((char*)l2c + 0x2e) = (int16_t)((i7v - *(int16_t*)((char*)l2c+0x2e))/3) + *(int16_t*)((char*)l2c+0x2e);
        l2c[0] = (i8 - l2c[0])/3 + l2c[0];
      }
      int n = 1; int* pi = l2c + 2; int16_t* ps = (int16_t*)((char*)l2c + 0x22);
      do {
        int v = (int)(((long long)(i6 + (u12 + 5) * 5) * 4) / (*ps + 2));
        if (n == 2 || n == 4) v /= 2;
        if (param_1 == 0) v = (v - *pi)/3 + *pi;
        *pi = v > 99 ? 99 : v;
        ++n; ++ps; ++pi;
      } while (n < 6);
      i13 = i13 < 1 ? 1 : (i13 > 100 ? 100 : i13);
      i13 += (int)l24[2] * -4;
      int8_t c = i13 < 1 ? (int8_t)((i13 > -1) + -1) : (int8_t)1;
      c = (int8_t)(l24[2] + c); if (c < 0) c = 0; l24[2] = c;
    }
    l28 += 0x25; l2c += 0x25; l24 += 0x20;
  } while ((uintptr_t)l28 < 0x85d90c);
  // rounding sweep
  int16_t* ps15 = (int16_t*)0x85d932; int* pi11 = (int*)0x861100;
  do {
    if (*pi11 == 4) {
      int16_t s9 = *ps15;
      if (0x1a - s9 < 1) s9 = 0; else { int r = rand(); s9 = (int16_t)(r % (0x1a - s9)); }
      *ps15 = *ps15 + s9;
    }
    pi11 += 8; ps15 += 0x4a;
  } while ((uintptr_t)pi11 < 0x861b80);
  int sum = 0; int* p = (int*)0x860bbc;
  do { sum += p[-0x10] + p[-8] + p[8] + *p; p += 0x20; } while ((uintptr_t)p < 0x86113c);
  // final enrichment loop over 0x2c entries
  for (int e = 0; e < 0x2c; ++e) {
    extern int DAT_00860b70[], DAT_00860b7c[];
    if (DAT_00860b70[e * 8] > -1) {
      int v = (0x1130 - sum) / 0x2c + DAT_00860b7c[e * 8];
      if (v < 0) v = 0; else if (199 < v) v = 199;
      DAT_00860b7c[e * 8] = v;
      FUN_00428570(e);
      extern int16_t DAT_0085bf7e[];
      int16_t s9 = DAT_0085bf7e[e * 0x4a];
      if (s9 / 3 < 1) s9 = 0; else { int r = rand(); s9 = (int16_t)(r % (s9 / 3)); }
      DAT_0085bf7e[e * 0x4a] -= s9;
      switch (e) {
        case 0: case 5: {
          extern int DAT_0085bfa4[]; DAT_0085bfa4[e*0x25] = DAT_0085bfa4[e*0x25]/2 + DAT_0085bfa4[e*0x25]; break; }
        case 4: case 0xb: case 0x16: case 0x1b: case 0x22: case 0x2a: {
          extern int16_t DAT_0085bf7c[]; if (DAT_0085bf7c[e*0x4a] > 0) DAT_0085bf7c[e*0x4a]=0; break; }
        case 6: { extern int16_t DAT_0085bf7c[]; if (DAT_0085bf7c[e*0x4a] < 1) DAT_0085bf7c[e*0x4a]=1; break; }
        case 10: case 0x14: case 0x23: case 0x2b: {
          extern int DAT_0085bf9c[]; DAT_0085bf9c[e*0x25]=DAT_0085bf9c[e*0x25]/3+DAT_0085bf9c[e*0x25]; break; }
        case 0xc: { extern int DAT_0085bf9c[]; if (DAT_0085bf9c[e*0x25] < 0x14) DAT_0085bf9c[e*0x25]=0x14; /* fallthrough */ }
        case 9: { extern int DAT_0085bf98[]; DAT_0085bf98[e*0x25]-=DAT_0085bf98[e*0x25]/3; break; }
        case 0xe: case 0x17: case 0x1f: {
          extern int16_t DAT_0085bf7c[]; extern int DAT_0085bf98[];
          if (DAT_0085bf7c[e*0x4a] > -1) DAT_0085bf7c[e*0x4a]=(int16_t)0xffff;
          DAT_0085bf98[e*0x25]=DAT_0085bf98[e*0x25]/3+DAT_0085bf98[e*0x25]; break; }
        case 0x1e: { extern int DAT_0085bfa8[]; DAT_0085bfa8[e*0x25]=DAT_0085bfa8[e*0x25]/2+DAT_0085bfa8[e*0x25]; /* fallthrough */ }
        case 3: case 0x12: case 0x27: {
          extern int DAT_0085bfac[]; DAT_0085bfac[e*0x25]=DAT_0085bfac[e*0x25]/2+DAT_0085bfac[e*0x25]; break; }
      }
    }
  }
}

// 0x4294c0 — observed shape: refcounted shutdown, ordered cleanup of global objects
void FUN_004294c0() {
  uint32_t* g = (uint32_t*)DAT_008e9fe4_p;
  if (g) {
    int r = g[1]; g[1] = r - 1;
    if (r - 1 == 0) (*(void(**)(int))g[0])(1);
    DAT_008e9fe4_p = nullptr;
  }
  FUN_004afaa0(); FUN_00496370(); FUN_004e4d30(); FUN_004ab230();
  auto cleanup = [](void* pv, void (*dtor)()) {
    if (pv) { dtor(); operator_delete(pv); }
  };
  if (DAT_008cabe8_p) { FUN_004b2040(); operator_delete(DAT_008cabe8_p); DAT_008cabe8_p = nullptr; }
  if (DAT_0072cd78_p) { FUN_004e6770(); operator_delete(DAT_0072cd78_p); DAT_0072cd78_p = nullptr; }
  if (DAT_0072cd74_p) { FUN_004e2730(); operator_delete(DAT_0072cd74_p); DAT_0072cd74_p = nullptr; }
  if (DAT_008c9dec_p) { FUN_004d9630(); operator_delete(DAT_008c9dec_p); DAT_008c9dec_p = nullptr; }
  if (DAT_008c9de8_p) { FUN_004d9c80(); operator_delete(DAT_008c9de8_p); DAT_008c9de8_p = nullptr; }
  uint32_t* p = (uint32_t*)DAT_008c9de4_p;
  if (p) {
    int* ref = (int*)(p + 1);
    p[0] = 0x710bfc; // &PTR_LAB_00710bfc
    uint32_t* node = (uint32_t*)(*ref - 8);
    extern uint32_t g_8cacc8;
    if (node && node != &g_8cacc8) operator_delete__(node);
    *ref = 0x8cacd0; // &DAT_008cacd0
    operator_delete(p);
    DAT_008c9de4_p = nullptr;
  }
  if (DAT_0086bb5c_p) (*(void(**)(int))(*(void**)DAT_0086bb5c_p))(1);
  if (DAT_0086bb58_p) (*(void(**)(int))(*(void**)DAT_0086bb58_p))(1);
  FUN_004af8c0();
}

// 0x429610 — observed shape: bulk resource init; long repetitive FUN_004bdca0 + .kfm loads
void FUN_00429610() {
  HCURSOR h = DAT_008cacd8_h;
  if (!h) h = LoadCursorA(nullptr, (LPCSTR)0x7f02);
  HCURSOR prev = GetCursor();
  SetCursor(h);
  FUN_00495390();
  for (int k = 0; k < 2; ++k) {
    uint32_t* obj = (uint32_t*)FUN_00533c78(0xc0);
    void* host = DAT_008ea000_p;
    if (!obj) { (k==0 ? DAT_00860970_i : DAT_00860974_i) = 0; }
    else {
      obj[1] = 0; obj[0] = 0x6fd14c; obj[7] = 0; obj[0x19] = 0;
      extern int DAT_00727444; DAT_00727444 += 1;
      obj[0x2f] = 0;
      FUN_004bdca0(host, 0, 0, 0x80, 0x80, -1, 0, 0, 0, 0);
      (k==0 ? DAT_00860970_i : DAT_00860974_i) = (int)(intptr_t)obj;
    }
  }
  FUN_004c0980(1, 0); FUN_004c0980(1, 0);
  FUN_004bdca0(DAT_008ea000_p, 0,0,0,0,-1,0,0,0,0);
  DAT_00726668_i |= 0x4000;
  if (DAT_00726698_i) {
    DWORD tid = GetCurrentThreadId();
    if ((uint32_t)DAT_008e8fdc_i == tid) goto after_thread_check;
  }
  if (DAT_00726704_i) FUN_004c0940();
  FUN_004c08b0(DAT_00726664_i);
after_thread_check:
  for (int i=0;i<9;++i) FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  if (DAT_008cbad4_i) FUN_004bcd00(0);
  DAT_008cba64_i = 0;
  FUN_004bdd90((void*)0x8cba18, "tartane-lowend.kfm");
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdd90((void*)0x8cbad8, "sloop1-lowend.kfm");
  FUN_004bc7e0(0,0);
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdd90((void*)0x8cbb98, "ship_brigantine-lowend.kfm");
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdd90((void*)0x8cbc58, "barque-lowend.kfm");
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdd90((void*)0x8cbd18, "Fluyt-lowend.kfm");
  FUN_004bc7e0(0,0);
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdd90((void*)0x8cbdd8, "ship_merman-lowend.kfm");
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdd90((void*)0x8cbe98, "frigate-lowend.kfm");
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdd90((void*)0x8cbf58, "FastGalleon-lowend.kfm");
  FUN_004bc7e0(0,0);
  FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdd90((void*)0x8cc018, "treasure_galleon-lowend.kfm");
  for (int i=0;i<9;++i) FUN_004bdca0(DAT_008e9ff8_p,0,0,0,0,-1,0,0,0,0);
  int* slot = (int*)0x8cba58;
  do {
    FUN_004baaa0();
    if (*slot) { *slot = 0; FUN_004c03c0(slot[-9], (char)slot[3]); if (slot[0x1f]) FUN_004bcac0(); }
    FUN_004bc5c0(0); FUN_00534130();
    if (slot[0x1f]) FUN_00534130();
    slot += 0x30;
  } while ((uintptr_t)slot < 0x8cc059);
  FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  extern float _DAT_008ccdc4; _DAT_008ccdc4 = -1.0f;
  FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdca0(DAT_008e9fec_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdca0(DAT_008e9fec_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdca0(DAT_008e9fec_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdca0(DAT_008e9ff0_p,0,0,0,0,-1,0,0,0,0);
  for (int i=0;i<14;++i) FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  for (int i=0;i<5;++i) FUN_004c0a40(0);
  for (int i=0;i<4;++i) FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  for (int i=0;i<3;++i) FUN_004c0a40(0);
  for (int i=0;i<2;++i) FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdca0(DAT_008ea008_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdca0(DAT_008ea008_p,0,0,0,0,-1,0,0,0,0);
  FUN_004bdca0(DAT_008e9fe8_p,0,0,0,0,-1,0,0,0,0);
  extern float _DAT_008cd484; _DAT_008cd484 = -1.0f;
  FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  extern float _DAT_008cd544; _DAT_008cd544 = -1.0f;
  FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  extern float _DAT_008cd604; _DAT_008cd604 = -1.0f;
  FUN_004bdca0(DAT_008ea000_p,0,0,0,0,-1,0,0,0,0);
  extern float _DAT_008cd6c4; _DAT_008cd6c4 = -1.0f;
  // remainder: bulk DAT_008ea008 -1 fills (observed 150+ identical calls with same args)
  for (int i = 0; i < 147; ++i) FUN_004bdca0(DAT_008ea008_p, 0, 0, 0, 0, -1, 0, 0, 0, 0);
  FUN_0046baa0();
  SetCursor(prev);
}

// 0x42b660 — observed shape: BIK intro sequence with float args
void FUN_0042b660() {
  uint32_t stackVals[3] = {0};
  (*(void(**)(void*))(*(void***)DAT_008ea08c_p + 0x74))(stackVals);
  FUN_00535de0(7); FUN_00535e10();
  FUN_004abb50("Pirates!.bik", 1.0); // 0x3f800000
  FUN_0042c000();
  stackVals[0] = 0x3ebcbcbd; stackVals[1] = 0x3f24a4a5; stackVals[2] = 0x3f62e2e3;
  (*(void(**)(void*))(*(void***)DAT_008ea08c_p + 0x74))(&stackVals[0]);
}

// 0x42b6f0 — observed shape: load cursor from file, set class cursor
void FUN_0042b6f0() {
  FUN_00412f10();
  int r = FUN_004f5480((void*)0x8cacd0, 0);
  if (r) {
    int** slot = (int**)(r + 0x10);
    if (!*slot || *(char*)(**(int**)(r + 0x10) + *(int*)(**(int**)(r+0x10) - 4) - 1) == '\\') {
      int out = 0;
      FUN_004129c0(&out, r + 8); FUN_00412ec0();
      void* node = (void*)(out - 8);
      extern uint32_t g_8cacc8;
      if (node && node != &g_8cacc8) operator_delete__(node);
    }
  }
  HCURSOR cur = LoadCursorFromFileA(DAT_008cacd0_);
  SetCursor(cur);
  SetClassLongA(DAT_00726b8c_h, -12, (LONG)cur); // -0xc GCL_HCURSOR
}

// 0x42b810 — observed shape: main menu loop, jumptable dispatch on DAT_007253c0
void FUN_0042b810() {
  FUN_00429610();
  DAT_0085a158_i = 0; DAT_0085a15c_i = 0;
  FUN_0042b6f0();
  extern float _DAT_008c84b0;
  float f = _DAT_008c84b0;
  int choice = 0;
  if (DAT_008cac27_c == 0) {
    do {
      if ((double)(f + 5.0) <= _DAT_008c84b0 || choice != 0) break;
      FUN_004aafd0(0);
      choice = FUN_0042e1d0(DAT_006f588c_);
      if (DAT_0086bb5c_p) {
        char buf[260]; sprintf(buf, "%s_%03X", DAT_006f588c_, choice);
        int* tbl = (int*)DAT_0086bb5c_p;
        int idx = (*(int(**)(const char*))(tbl[0] + 4))(buf);
        for (auto* node = (uint32_t*)*(tbl[2] + idx * 4); node; node = (uint32_t*)*node) {
          char c = (*(char(**)(const char*,int))(tbl[0] + 8))(buf, node[1]);
          if (c) { choice = node[2]; break; }
        }
      }
    } while (DAT_008cac27_c == 0);
  }
menu_loop:
  {
    uint32_t* g = (uint32_t*)DAT_008cabe8_p;
    ((uint8_t*)g)[12] = 0; g[1] = 1; g[0] = 1;
    int holder = DAT_0072cd78_i;
    DAT_0085a11c_i = 100;
    if (DAT_008cac26_c) {
      DAT_008cac27_c = 0; DAT_008cac38_i = 10;
      if ((int8_t)DAT_0085a164_i < 0) FUN_004e8ea0(DAT_0072cd78_p);
      else { int n=0; do { FUN_004e9740(); ++n; } while (n < *(int*)(holder + 0x58)); }
      if (DAT_007263b0_c) { FUN_00498260((void*)0x8e67b0); FUN_00497fd0((void*)0x8e67b0); }
    }
    DAT_008cac26_c = 0;
    if (DAT_008cac27_c) DAT_008cac26_c = 0;
    FUN_004889c0(DAT_008c8280_p, 0x44, -1, -1, -1, -1.0, -1);
    int* ref = (int*)((int)PTR_DAT_0072680c_p - 4);
    if (*ref != 0) choice = 1;
    else {
      choice = 0;
      extern void* DAT_008c9568_p;
      int off = 0;
      do {
        void* old = *(void**)((char*)&DAT_008c9568_p + off);
        if (old) { FUN_00508190(); operator_delete(old); *(void**)((char*)&DAT_008c9568_p + off) = nullptr; }
        uint32_t* obj = (uint32_t*)FUN_00533c78(0x68);
        if (obj) {
          for (int i=5;i<=0x10;++i) obj[i]=0; obj[0x13]=obj[0x14]=obj[0x15]=obj[0x16]=obj[0x17]=0;
          obj[0x18] = DAT_008cad20_i; DAT_008cad20_i = (int)(intptr_t)obj;
          obj[0] = 0;
          extern int DAT_0071779c, DAT_007177a0, DAT_007177a4, DAT_007177a8;
          obj[5]=DAT_0071779c; obj[6]=DAT_007177a0; obj[7]=DAT_007177a4; obj[8]=DAT_007177a8;
          obj[0x19] = 0;
        }
        *(uint32_t**)((char*)&DAT_008c9568_p + off) = obj;
        FUN_00508670(obj, (void*)((char*)0x7261f4 + off));
        int cur = *(int*)((char*)&DAT_008c9568_p + off);
        *(uint32_t*)(cur + 100) = (*(uint32_t(**)(int,int))(*(void***)DAT_00727b28_p + 4))(2, 0);
        off += 4;
      } while (off < 0xc);
      FUN_004f6090("\n Play Sid Meier's Pirates!\n Load A Game\n Change Your System Options\n Visit The Firaxis Website\n Visit The Hall Of Champions\n View Credits\n Quit\n");
      DAT_008c9de0_p = DAT_008c9dd8_p;
      FUN_00509500(DAT_008c9dd8_p, (void*)0x869b48, 0);
      int w = FUN_005f0ddc();
      DAT_008c9de0_p = DAT_008c9dd8_p; DAT_0072540c_i = 0;
      choice = FUN_00430190(DAT_0085a26c_i / 2 - w / 2, 0x46, "pauseMenuBG.dds", 0, DAT_007263a8_i, (void*)0x42b7c0, 0, -1, 0, 0);
      DAT_0072540c_i = 1;
      { uint32_t* q = (uint32_t*)&DAT_008c9568_p;
        do { if (*q) { FUN_00508190(); operator_delete((void*)*q); *q = 0; } ++q; } while ((uintptr_t)q < 0x8c9574);
      }
      if (choice == -2) { FUN_0042b660(); goto menu_loop; }
      if (choice < 0 || 0xf < choice) goto menu_loop;
    }
  }
  extern uint8_t DAT_007253c0[];
  switch ((int8_t)DAT_007253c0[choice]) {
    case 0:
      FUN_00488fc0(DAT_008c8280_p, 0x44, -1.0); FUN_004888e0(0x31, -1, -1, -1.0);
      if (FUN_00471ab0()) {
        extern int DAT_007268f4[];
        DAT_007268f4[DAT_00726a84_i] = DAT_007263bc_i; DAT_00726a84_i += 1; DAT_007263bc_i = 0xffffff;
        FUN_0046c8d0(0); if (!DAT_008cac27_c) FUN_00471e00(0);
        DAT_00726a84_i -= 1; DAT_007263bc_i = DAT_007268f4[DAT_00726a84_i];
      }
      break;
    case 1: FUN_00488fc0(DAT_008c8280_p,0x44,-1.0); FUN_00419370(); break;
    case 2: FUN_00488fc0(DAT_008c8280_p,0x44,-1.0); FUN_0048c0e0(); break;
    case 3: FUN_00488fc0(DAT_008c8280_p,0x44,-1.0); FUN_0047a040(0); break;
    case 4:
      FUN_00488fc0(DAT_008c8280_p,0x44,-1.0);
      do { choice = FUN_00415860(2,0,0); if (choice==-1) break;
        FUN_004f6090("Another dance?\n Sure.\n No, thanks.\n");
        choice = FUN_00430190(DAT_0085a26c_i/2+0x1c, DAT_0085a268_i/3, "daughter.pcx", 0, -1, 0, 0, -1, 0, 0);
      } while (choice==0);
      break;
    case 5:
      FUN_00488fc0(DAT_008c8280_p,0x44,-1.0);
      if (!DAT_008cac27_c) {
        DAT_00869ab0_i=200; DAT_0081431e_i=200; DAT_0085a164_i|=0x10000; DAT_0085a158_i=1; DAT_00860eb6_i=10;
        FUN_00438e30((void*)0); DAT_0085a164_i &= 0xfffeffff;
      }
      break;
    case 6:
      DAT_008ca92c_i=0; FUN_00488fc0(DAT_008c8280_p,0x44,-1.0);
      { extern int DAT_007268f4[]; DAT_007268f4[DAT_00726a84_i]=DAT_007263bc_i; }
      DAT_00726a84_i+=1; DAT_007263bc_i=0xffffff; FUN_0046c8d0(0); FUN_00471e00(1);
      DAT_00726a84_i-=1; { extern int DAT_007268f4[]; DAT_007263bc_i=DAT_007268f4[DAT_00726a84_i]; }
      break;
    case 7:
      FUN_00488fc0(DAT_008c8280_p,0x44,-1.0);
      if (PTR_DAT_0072680c_p && *(int*)((int)PTR_DAT_0072680c_p-4)==0) FUN_004b6070(1);
      if (!DAT_008cac27_c && *(int*)((int)PTR_DAT_0072680c_p-4)!=0) { FUN_004ae700(); FUN_0046c8d0(1); if(!DAT_008cac27_c) FUN_00471e00(1); FUN_004ae720(); }
      break;
    case 8:
      FUN_00488fc0(DAT_008c8280_p,0x44,-1.0);
      FUN_004f6090("Are you sure you want to quit?\n Yes \n No\n");
      choice = FUN_00430190(((DAT_0085a26c_i + (DAT_0085a26c_i>>31 & 3U))>>2) + 0x10, (DAT_0085a268_i + (DAT_0085a268_i>>31 & 3U))>>2 | 1, "pauseMenuBG.dds", 0, -1, 0, 0, -1, 0, 0);
      if (choice==0) return;
      break;
    case 9: FUN_004c9930(); break;
    case 0xb:
      { const char* f = FUN_004f40f0();
        ShellExecuteA(nullptr, nullptr, f, "http://www.firaxis.com", nullptr, 10);
        ShowWindow(DAT_00726b8c_h, 6);
        while (!DAT_008cac27_c && !DAT_00726b3c_c) { WaitMessage(); FUN_0042e1d0(0); } }
      break;
    case 0xc: FUN_00454af0(); FUN_0042e730(); break;
    case 0xd: FUN_004b4760(0); break;
    case 0xe: FUN_00488fc0(DAT_008c8280_p,0x44,-1.0); FUN_00455ca0(); break;
  }
  goto menu_loop;
}

// 0x42c000 — observed shape: message pump loop formatting %s_%03X
void FUN_0042c000() {
  extern int DAT_006f588c_i;
  int c1 = DAT_008cac27_c;
  int c2 = DAT_00726b3c_c;
  while (c2 == 0 && c1 == 0) {
    uint32_t u = FUN_0042e1d0(DAT_006f588c_);
    if (DAT_0086bb5c_p) {
      char buf[256]; sprintf(buf, "%s_%03X", DAT_006f588c_, u);
      FUN_0051bfc0(buf);
    }
    Sleep(0x14);
    c1 = DAT_00726b3c_c; c2 = DAT_008cac27_c;
  }
}

// 0x42c0a0 — observed shape: store 3 params at +0x5c/+0x60/+0x64 (100 decimal) on ECX
void FUN_0042c0a0(void* self, uint32_t p1, uint32_t p2, uint32_t p3) {
  uint32_t* s = (uint32_t*)self;
  s[0x5c / 4] = p1; s[0x60 / 4] = p2; s[100 / 4] = p3;
}

// 0x42c130 — observed shape: guard chain then FUN_004f8e40(&param2)
uint32_t FUN_0042c130(void* self_eax, uint8_t p2) {
  if (!DAT_008cacf0_i || (self_eax && !DAT_008cace8_i && !DAT_008cacec_i)) return 0;
  return FUN_004f8e40(&p2);
}

// 0x42c170 — observed shape: WM_* / key-state handler returning 0/1
uint32_t FUN_0042c170(uint32_t param_1, uint32_t msg, uint32_t wparam) {
  int iVar3 = 0;
  if (DAT_00726b3c_c == 0 && DAT_00726b3e_c == 0) {
    if (DAT_008cac40_i && msg > 0x1ff && msg < 0x20e) FUN_005025d0(DAT_008cac40_i);
    if (msg < 0x201) {
      if (msg == 0x200) {
        DAT_008dc30c_i = (int)((param_1 & 0xffff) * DAT_0072637c_i) / DAT_008cac18_i;
        DAT_008dc310_i = (int)((param_1 >> 16) * DAT_00726380_i) / DAT_008cac1c_i;
      } else switch (msg) {
        case 0x100: DAT_0086c334_i = (int)wparam; break;
        case 0x101: if (wparam == 0x2c) DAT_008cac30_i = 1; break;
        case 0x102: DAT_0086c338_i = (int)wparam; break;
        case 0x104: if (wparam != 0x79) return 0; DAT_0086c334_i = (int)wparam; break;
        case 0x105: if (wparam == 0x2c) { DAT_008cac30_i=1; *(uint8_t*)((char*)DAT_008c9de4_p + 0xc) = 1; } break;
        default: return 0;
      }
    } else switch (msg) {
      case 0x201: case 0x203: iVar3 = 1; DAT_008ed5b0_i |= 1; break;
      case 0x202: DAT_008ed5b0_i &= 0xfffffffe; break;
      case 0x204: case 0x206: iVar3 = 2; DAT_008ed5b0_i |= 2; break;
      case 0x205: DAT_008ed5b0_i &= 0xfffffffd; break;
      case 0x207: iVar3 = 4; break;
      case 0x20a: {
        uint16_t hi = (uint16_t)(wparam >> 16);
        if (!DAT_008e8fe8_c) {
          if (hi < 0x8001) { if (hi < 0x8000 && --DAT_0085a0fc_i < -0xd) DAT_0085a0fc_i = -0xd; }
          else { if (++DAT_0085a0fc_i > 10) DAT_0085a0fc_i = 10; }
        } else if (hi < 0x8001) { if (hi < 0x8000) FUN_004c5a60(); } else FUN_004c59b0();
        break; }
      case 0x20b:
        if (DAT_008e8fe8_c) { if ((int16_t)wparam == 0x20) FUN_004c5960(); else if ((int16_t)wparam == 0x40) FUN_004c5910(); }
        break;
      default: return 0;
    }
    // nonzero fallthrough to common tail
    if (msg >= 0x201) {
      // common tail below
    } else {
      // for sub-0x201 cases that handled (not early return), same tail
    }
  } else return 0;
  uint16_t ks = GetKeyState(0x90);
  if ((ks & 1) && GetAsyncKeyState(0x90) == 0) FUN_004b0560();
  if (iVar3 || DAT_008ed5b0_i != DAT_0086c348_i) {
    DAT_0086c348_i = DAT_008ed5b0_i;
    DAT_0086c33c_i = (int)((param_1 & 0xffff) * DAT_0072637c_i) / DAT_008cac18_i;
    DAT_0086c340_i = (int)((param_1 >> 16) * DAT_00726380_i) / DAT_008cac1c_i;
    DAT_0086c334_i = iVar3; DAT_0086c344_i = iVar3;
    DAT_0086c350_i = (GetAsyncKeyState(0x11) >> 8);
    DAT_0086c34c_i = (GetAsyncKeyState(0x10) >> 8);
  }
  if (DAT_008ed5b4_c) { DAT_0086c338_i = 0x1b; DAT_0086c334_i = 0; return 1; }
  if (DAT_0086c338_i) DAT_0086c334_i = 0;
  return 1;
}

// 0x42c4b0 — observed shape: timeGetTime delta since first call
int FUN_0042c4b0() {
  if ((DAT_008ed61c_i & 1) == 0) { DAT_008ed61c_i |= 1; DAT_008ed618_i = (int)timeGetTime(); }
  DWORD now = timeGetTime();
  return (int)now - DAT_008ed618_i;
}

// 0x42c4e0 — observed shape: waits for message via FUN_0042e1d0(0), timeout param_1 ms
int FUN_0042c4e0(uint32_t param_1) {
  extern int DAT_0086c35c, DAT_0086c360;
  int res = 0;
  if ((DAT_008ed61c_i & 1) == 0) { DAT_008ed61c_i |= 1; DAT_008ed618_i = (int)timeGetTime(); }
  DWORD t0 = timeGetTime();
  int elapsed = (int)t0 - DAT_008ed618_i;
  if (!DAT_008cac27_c) {
    while ((res = FUN_0042e1d0(0)) == 0) {
      if ((DAT_008ed61c_i & 1) == 0) { DAT_008ed61c_i |= 1; DAT_008ed618_i = (int)timeGetTime(); }
      DWORD now = timeGetTime();
      if (param_1 <= (uint32_t)((int)now - DAT_008ed618_i - elapsed)) break;
      Sleep(10);
      if (DAT_008cac27_c) break;
    }
  }
  int v; do { v = FUN_0042e1d0(0); } while (v != 0);
  DAT_0086c35c = 0; DAT_0086c360 = 0;
  return res;
}

// 0x42c590 — observed shape: append entry to 4 parallel arrays, index DAT_0086c330
void FUN_0042c590(void* self_eax, int16_t v1, int16_t v2, int16_t v3, int16_t in_cx, int16_t in_dx) {
  int idx = DAT_0086c330_i;
  extern int16_t DAT_0086c1a0[], DAT_0086c010[], DAT_0086bcf0[], DAT_0086be80[], DAT_0086bb60[];
  DAT_0086c1a0[idx] = v1;
  DAT_0086c010[idx] = in_dx;
  DAT_0086c330_i += 1;
  DAT_0086bcf0[idx] = v2 + in_dx;
  DAT_0086be80[idx] = in_cx;
  DAT_0086bb60[idx] = v3 + in_cx;
  (void)self_eax;
}

// explicit externs used only in this batch (defined once to satisfy no-invented-global rule):
int DAT_00726b3e_c; int DAT_0085a15c_i; int DAT_008cba64_i; int DAT_008cbad4_i;
int DAT_00860eb6_i; int DAT_0072cd78_i; int DAT_0072cd74_i; int DAT_0071779c, DAT_007177a0, DAT_007177a4, DAT_007177a8;
int DAT_00860970; int DAT_00860974; int DAT_00727444;
