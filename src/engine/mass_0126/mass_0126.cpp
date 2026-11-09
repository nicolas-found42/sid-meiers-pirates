#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_0053ba20(void** param_1, void* param_2);
extern int* FUN_0053bce0(void** param_1);
extern void FUN_0053b1e0(void* param_1, void* param_2, int param_3);
extern void FUN_00535830(void* param_1);
extern void FUN_00535920(void* self);
extern void thunk_FUN_005405e0(void* param_1);
extern void FUN_005bd960(void* self, void* param_1);
extern void FUN_0053b740(void* param_1, void* param_2);

// 0x53bb90 — observed shape
int* FUN_0053bb90(void* self, int* param_1, void* param_2)
{
  int* piVar1;
  void** puVar2;
  int iVar3;
  if (*(void**)((char*)self + 0xc0) <= param_2) {
    *param_1 = 0;
    return param_1;
  }
  puVar2 = *(void**)(*(int*)((char*)self + 0xb8) + (int)(intptr_t)param_2 * 4);
  if (puVar2 != nullptr) {
    puVar2[1] = (void*)((int)(intptr_t)puVar2[1] + 1);
    puVar2[9] = nullptr;
    void* p2 = param_2;
    FUN_0053ba20(&p2, p2);
    param_2 = p2;
    if (param_2 != nullptr) {
      piVar1 = (int*)((char*)param_2 + 4);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *(void(**)(int))*(void**)param_2;
        fn(1);
      }
    }
  }
  *param_1 = (int)(intptr_t)puVar2;
  if (puVar2 != nullptr) {
    iVar3 = (int)(intptr_t)puVar2[1];
    puVar2[1] = (void*)((int)(intptr_t)puVar2[1] + 1);
    puVar2[1] = (void*)iVar3;
    if (iVar3 == 0) {
      auto fn = *(void(**)(int))*(void**)puVar2;
      fn(1);
    }
  }
  return param_1;
}

// 0x53bc20 — observed shape
int* FUN_0053bc20(void* self, int* param_1, void* param_2)
{
  int* piVar1;
  void** puVar2;
  int iVar3;
  void* puVar4;
  uint32_t uVar5;
  puVar4 = param_2;
  uVar5 = 0;
  if (*(int*)((char*)self + 0xc0) != 0) {
    do {
      puVar2 = *(void**)(*(int*)((char*)self + 0xb8) + uVar5 * 4);
      if (puVar2 != nullptr) {
        iVar3 = (int)(intptr_t)puVar2[1];
        puVar2[1] = (void*)((int)(intptr_t)puVar2[1] + 1);
        if (puVar2 == puVar4) {
          puVar2[9] = nullptr;
          void* p2 = (void*)(intptr_t)uVar5;
          FUN_0053ba20((void**)&param_1, p2);
          if (param_1 != nullptr) {
            piVar1 = (int*)((char*)param_1 + 4);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              auto fn = *(void(**)(int))*(void**)param_1;
              fn(1);
            }
          }
          *param_1 = (int)(intptr_t)puVar2;
          iVar3 = (int)(intptr_t)puVar2[1];
          puVar2[1] = (void*)((int)(intptr_t)puVar2[1] + 1);
          puVar2[1] = (void*)iVar3;
          if (iVar3 == 0) {
            auto fn = *(void(**)(int))*(void**)puVar2;
            fn(1);
          }
          return param_1;
        }
        puVar2[1] = (void*)iVar3;
        if (iVar3 == 0) {
          auto fn = *(void(**)(int))*(void**)puVar2;
          fn(1);
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint32_t*)((char*)self + 0xc0));
  }
  *param_1 = 0;
  return param_1;
}

// 0x53bce0 — observed shape
void* FUN_0053bce0(void* self, void* param_1)
{
  void** puVar1;
  int iVar2;
  int* piVar3;
  void** puVar4;
  void* local_4;
  puVar4 = nullptr;
  if (*(void**)((char*)self + 36) != nullptr) {
    local_4 = self;
    piVar3 = FUN_0053bce0(&local_4);
    puVar1 = (void**)*(void***)piVar3;
    if (puVar1 != nullptr) {
      puVar1[1] = (void*)((int)(intptr_t)puVar1[1] + 1);
      puVar4 = puVar1;
    }
    if (local_4 != nullptr && (iVar2 = (int)(intptr_t)((void**)local_4)[1], ((void**)local_4)[1] = (void*)(iVar2 + -1), iVar2 + -1 == 0)) {
      auto fn = *(void(**)(int))*(void**)local_4;
      fn(1);
    }
  }
  FUN_0053b1e0(param_1, puVar4, 0);
  if (puVar4 != nullptr) {
    piVar3 = (int*)((char*)puVar4 + 4);
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      auto fn = *(void(**)(int))*(void**)puVar4;
      fn(1);
    }
  }
  return param_1;
}

// 0x53bd50 — observed shape
void FUN_0053bd50(void* self, int param_1)
{
  int* piVar1;
  int* piVar2;
  piVar2 = *(int**)((char*)self + 0xd0);
  if (piVar2 != nullptr) {
    while (piVar1 = (int*)*piVar2, param_1 != piVar2[2]) {
      piVar2 = piVar1;
      if (piVar1 == nullptr) {
        return;
      }
    }
    if (piVar2 != nullptr) {
      FUN_00535830(&param_1);
      FUN_00535920(self);
    }
  }
  return;
}

// 0x53be30 — observed shape
void FUN_0053be30(void* self, void* param_1)
{
  int* piVar1;
  void* uVar2;
  uint32_t uVar3;
  uVar2 = param_1;
  thunk_FUN_005405e0(param_1);
  FUN_005bd960(self, &param_1);
  if (*(int*)((char*)self + 0xd8) != 0) {
    FUN_0053b740((char*)self + 0xcc, uVar2);
  }
  uVar3 = 0;
  if (*(int*)((char*)self + 0xc0) != 0) {
    do {
      piVar1 = *(int**)(*(int*)((char*)self + 0xb8) + uVar3 * 4);
      if (piVar1 != nullptr) {
        auto fn = *(void(**)(void*))(*(void**)(*(int*)piVar1) + 0x28);
        fn(uVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint32_t*)((char*)self + 0xc0));
  }
  return;
}

// ---------------------------------------------------------------------------
// Retry batch: 0x53bf20 .. 0x53c7c0
// ---------------------------------------------------------------------------

// x87 80-bit extended results returned through ST0.
using float10 = long double;

extern void FUN_00534660(void* param_1);
extern int FUN_00545630();
extern uint32_t* FUN_00545600();
extern void FUN_0057a3f0(int param_1);
extern void FUN_00535670(void* self);
extern void FUN_00534d60(void* param_1);
extern int FUN_00557b10(int param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t param_1, int* param_2);
extern int FUN_00557b50(const char* name, bool value);
extern int FUN_00557d40(const char* name, uint32_t value);
extern void FUN_0053ad50(void* self);
extern void FUN_0053bac0(void* self);
extern void FUN_00534040(void* self);
extern void FUN_00533d50(void* self, void* param_1);
extern void FUN_00581300(uint32_t index, void** out);
extern int FUN_005b62a0(void** param_1);
extern char* thunk_FUN_00533c78();
extern int sprintf(char* buffer, const char* format, ...);
extern "C" long double fcos(long double value);
extern "C" long double fsin(long double value);
extern "C" double _CIacos();

extern void* PTR_FUN_006c0bd8;
extern void* PTR_FUN_006c0bc4;
extern void* PTR_LAB_006c0bb8;
extern int DAT_00727560;
extern float _DAT_00727c78;

typedef void (*GetItemFn)(void* self, void** out, uint32_t idx, uint32_t value);
typedef void* (*AllocNodeFn)(void* self);
typedef void (*ListNodeDtorFn)(void* self, void* node);

// 0x53bf20 — observed shape
void FUN_0053bf20(void* self, void* param_1)
{
  uint32_t* sself = (uint32_t*)self;
  uint32_t* info = (uint32_t*)param_1;
  uint32_t index;
  uint32_t remaining;
  GetItemFn getItem;
  AllocNodeFn allocNode;
  uint32_t* node;
  void* slot;
  int* refs;
  uint32_t count;

  FUN_00534660(param_1);
  count = (uint32_t)FUN_00545630();
  if (count != 0) {
    FUN_0057a3f0((int)count);
    index = 0;
    do {
      uint32_t item = (uint32_t)(uintptr_t)FUN_00545600();
      slot = nullptr;
      getItem = *(GetItemFn*)((char*)(intptr_t)sself[0] + 0x7c);
      getItem(self, &slot, index, item);
      if (slot != nullptr) {
        refs = (int*)((char*)slot + 4);
        *refs = *refs + -1;
        if (*refs == 0) {
          auto release = *(void(**)(int))*(void**)slot;
          release(1);
        }
      }
      index = index + 1;
    } while (index < count);
  }
  remaining = (uint32_t)FUN_00545630();
  if (info[7] < 0x4010008u) {
    if (remaining != 0) {
      do {
        uint32_t value = (uint32_t)(uintptr_t)FUN_00545600();
        if (value != 0) {
          allocNode = *(AllocNodeFn*)((char*)(intptr_t)sself[0x33] + 4);
          node = (uint32_t*)allocNode(self);
          node[2] = value;
          node[0] = 0;
          node[1] = sself[0x35];
          if (sself[0x35] == 0) {
            sself[0x34] = (uint32_t)(uintptr_t)node;
          }
          else {
            *(uint32_t*)(uintptr_t)sself[0x35] = (uint32_t)(uintptr_t)node;
          }
          sself[0x36] = sself[0x36] + 1;
          sself[0x35] = (uint32_t)(uintptr_t)node;
          FUN_00535670(sself);
        }
        remaining = remaining - 1;
      } while (remaining != 0);
      return;
    }
  }
  else if (remaining != 0) {
    do {
      uint32_t value = (uint32_t)(uintptr_t)FUN_00545600();
      if (value != 0) {
        allocNode = *(AllocNodeFn*)((char*)(intptr_t)sself[0x33] + 4);
        node = (uint32_t*)allocNode(self);
        node[2] = value;
        node[1] = 0;
        node[0] = sself[0x34];
        if (sself[0x34] == 0) {
          sself[0x35] = (uint32_t)(uintptr_t)node;
        }
        else {
          *(uint32_t*)(uintptr_t)(sself[0x34] + 4) = (uint32_t)(uintptr_t)node;
        }
        sself[0x36] = sself[0x36] + 1;
        sself[0x34] = (uint32_t)(uintptr_t)node;
        FUN_00535670(sself);
      }
      remaining = remaining - 1;
    } while (remaining != 0);
  }
}

// 0x53c060 — observed shape
void FUN_0053c060(void* self, void* param_1)
{
  int32_t* obj = (int32_t*)param_1;
  int32_t scratch;
  uint32_t slot;
  bool inRange;
  int32_t stored;
  int32_t present;

  FUN_00534d60(param_1);
  scratch = FUN_00557b10(DAT_00727560);
  slot = (uint32_t)obj[3];
  if ((uint32_t)obj[2] <= slot) {
    FUN_006b34a0(obj[5] + (int)slot);
  }
  FUN_005606f0(slot, &scratch);

  scratch = FUN_00557b50("m_bVisual", *(float*)((char*)self + 0x34) != 0.0f);
  slot = (uint32_t)obj[3];
  if ((uint32_t)obj[2] <= slot) {
    FUN_006b34a0(obj[5] + (int)slot);
  }
  FUN_005606f0(slot, &scratch);

  if (*(int*)((char*)self + 0xd8) != 0) {
    uint32_t* node = *(uint32_t**)((char*)self + 0xd0);
    int32_t index = 0;
    while (node != nullptr) {
      uint32_t value = node[2];
      char name[64];
      node = (uint32_t*)node[0];
      sprintf(name, "effect[%d]", index);
      stored = FUN_00557d40(name, value);
      slot = (uint32_t)obj[3];
      inRange = slot < (uint32_t)obj[2];
      if (!inRange) {
        FUN_006b34a0(obj[5] + (int)slot);
        inRange = slot < (uint32_t)obj[2];
      }
      if (inRange) {
        if (slot < (uint32_t)obj[3]) {
          if (stored == 0) {
            if (((int32_t*)(intptr_t)obj[1])[slot] != 0) {
              present = obj[4] + -1;
              obj[4] = present;
            }
          }
          else if (((int32_t*)(intptr_t)obj[1])[slot] == 0) {
            present = obj[4] + 1;
            obj[4] = present;
          }
        }
        else {
          obj[3] = (int32_t)(slot + 1);
          if (stored != 0) {
            present = obj[4] + 1;
            obj[4] = present;
          }
        }
        ((int32_t*)(intptr_t)obj[1])[slot] = stored;
      }
      index = index + 1;
    }
  }
}

// 0x53c1d0 — observed shape
void FUN_0053c1d0(void* self)
{
  uint32_t* sself = (uint32_t*)self;
  void* scratch;
  uint32_t index;
  uint32_t* node;
  uint32_t* next;
  void** vtbl;
  int* refs;

  sself[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c0bd8;
  scratch = self;
  FUN_0053ad50(self);
  index = 0;
  if (sself[0x30] != 0) {
    do {
      FUN_0053bb90(self, (int*)(void*)&scratch, (void*)(intptr_t)index);
      if (scratch != nullptr) {
        refs = (int*)((char*)scratch + 4);
        *refs = *refs + -1;
        if (*refs == 0) {
          auto release = *(void(**)(int))*(void**)scratch;
          release(1);
        }
      }
      index = index + 1;
    } while (index < sself[0x30]);
  }
  sself[0x33] = (uint32_t)(uintptr_t)&PTR_FUN_006c0bc4;
  node = (uint32_t*)(uintptr_t)sself[0x34];
  while (node != nullptr) {
    next = (uint32_t*)node[0];
    vtbl = (void**)(uintptr_t)sself[0x33];
    ListNodeDtorFn destroy = *(ListNodeDtorFn*)((char*)vtbl + 8);
    destroy(self, node);
    node = next;
  }
  sself[0x36] = 0;
  sself[0x34] = 0;
  sself[0x35] = 0;
  sself[0x33] = (uint32_t)(uintptr_t)&PTR_LAB_006c0bb8;
  FUN_0053bac0(self);
  FUN_00534040(self);
}

// 0x53c280 — observed shape
void FUN_0053c280(void* self, void* param_1, bool flag)
{
  int* refs;
  void* slot;

  if (param_1 != nullptr) {
    refs = (int*)((char*)param_1 + 4);
    *refs = *refs + 1;
    FUN_00533d50(self, self);
    slot = param_1;
    if (!flag) {
      *refs = *refs + 1;
      uint32_t index = *(uint32_t*)((char*)self + 0xc0);
      if (*(uint32_t*)((char*)self + 0xbc) <= index) {
        FUN_0057a3f0(*(int*)((char*)self + 200) + (int)index);
      }
      FUN_00581300(index, &slot);
    }
    else {
      *refs = *refs + 1;
      FUN_005b62a0(&slot);
    }
    *refs = *refs + -1;
    if (*refs == 0) {
      auto release = *(void(**)(int))*(void**)param_1;
      release(1);
    }
    *refs = *refs + -1;
    if (*refs == 0) {
      auto release = *(void(**)(int))*(void**)param_1;
      release(1);
    }
  }
}

// 0x53c320 — observed shape
int* FUN_0053c320(void* self, int* param_1, uint32_t param_2, void* param_3)
{
  void* slot = param_3;
  int* refs;
  uint32_t* element;

  if (*(uint32_t*)((char*)self + 0xc0) <= param_2) {
    if (param_3 != nullptr) {
      FUN_00533d50(self, self);
      refs = (int*)((char*)param_3 + 4);
      *refs = *refs + 1;
    }
    if (*(uint32_t*)((char*)self + 0xbc) <= param_2) {
      FUN_0057a3f0(*(int*)((char*)self + 200) + (int)param_2);
    }
    FUN_00581300(param_2, &slot);
    if (param_3 != nullptr) {
      refs = (int*)((char*)param_3 + 4);
      *refs = *refs + -1;
      if (*refs == 0) {
        auto release = *(void(**)(int))*(void**)param_3;
        release(1);
      }
    }
    *param_1 = 0;
    return param_1;
  }
  element = *(uint32_t**)(*(int*)((char*)self + 0xb8) + param_2 * 4);
  if (element != nullptr) {
    element[1] = element[1] + 1;
    element[9] = 0;
  }
  if (param_3 != nullptr) {
    FUN_00533d50(self, self);
    refs = (int*)((char*)param_3 + 4);
    *refs = *refs + 1;
  }
  FUN_00581300(param_2, &slot);
  if (param_3 != nullptr) {
    refs = (int*)((char*)param_3 + 4);
    *refs = *refs + -1;
    if (*refs == 0) {
      auto release = *(void(**)(int))*(void**)param_3;
      release(1);
    }
  }
  *param_1 = (int)(intptr_t)element;
  if (element != nullptr) {
    uint32_t count = element[1];
    element[1] = count + 1;
    element[1] = count;
    if (count == 0) {
      auto release = *(void(**)(int))*(void**)element;
      release(1);
    }
  }
  return param_1;
}

// 0x53c420 — observed shape
void FUN_0053c420(void* self)
{
  float* m = (float*)self;
  m[0] = 1.0f;
  m[1] = 0.0f;
  m[2] = 0.0f;
  m[3] = 0.0f;
  m[4] = 1.0f;
  m[5] = 0.0f;
  m[6] = 0.0f;
  m[7] = 0.0f;
  m[8] = 1.0f;
}

// 0x53c450 — observed shape
uint32_t FUN_0053c450(void* self, float* param_1)
{
  float* m = (float*)self;
  if ((((m[0] == param_1[0]) && (m[1] == param_1[1])) && (m[2] == param_1[2])) &&
      ((m[3] == param_1[3] && m[4] == param_1[4]) &&
       ((m[5] == param_1[5] && m[6] == param_1[6]) && (m[7] == param_1[7])))) {
    if (m[8] == param_1[8]) {
      return 1;
    }
  }
  return 0;
}

// 0x53c4f0 — observed shape
void FUN_0053c4f0(void* self, float* param_1, float* param_2)
{
  float m[9];
  float* src = (float*)self;
  int i;

  for (i = 0; i < 9; i = i + 1) {
    m[i] = src[i];
    src = src + 1;
  }
  m[0] = m[0] + param_2[0];
  m[1] = m[1] + param_2[1];
  m[2] = m[2] + param_2[2];
  m[3] = m[3] + param_2[3];
  m[4] = m[4] + param_2[4];
  m[5] = m[5] + param_2[5];
  m[6] = m[6] + param_2[6];
  m[7] = m[7] + param_2[7];
  m[8] = m[8] + param_2[8];
  for (i = 0; i < 9; i = i + 1) {
    param_1[i] = m[i];
  }
}

// 0x53c590 — observed shape
void FUN_0053c590(void* self, float* param_1, float* param_2)
{
  float m[9];
  float* src = (float*)self;
  int i;

  for (i = 0; i < 9; i = i + 1) {
    m[i] = src[i];
    src = src + 1;
  }
  m[0] = m[0] - param_2[0];
  m[1] = m[1] - param_2[1];
  m[2] = m[2] - param_2[2];
  m[3] = m[3] - param_2[3];
  m[4] = m[4] - param_2[4];
  m[5] = m[5] - param_2[5];
  m[6] = m[6] - param_2[6];
  m[7] = m[7] - param_2[7];
  m[8] = m[8] - param_2[8];
  for (i = 0; i < 9; i = i + 1) {
    param_1[i] = m[i];
  }
}

// 0x53c630 — observed shape
char* FUN_0053c630(void* self, char* param_1)
{
  float* m = (float*)self;
  char* end = param_1;
  char c;

  do {
    c = *end;
    end = end + 1;
  } while (c != '\0');
  // NEEDS_MANUAL: the allocator size argument was not recovered by the decompiler;
  // the preceding strlen walk leaves the length in a register the listing drops.
  char* text = thunk_FUN_00533c78();
  sprintf(text, "%s = ((%g,%g,%g),(%g,%g,%g),(%g,%g,%g))", param_1,
          (double)m[0], (double)m[1], (double)m[2],
          (double)m[3], (double)m[4], (double)m[5],
          (double)m[6], (double)m[7], (double)m[8]);
  return text;
}

// 0x53c6b0 — observed shape
float10 FUN_0053c6b0(float param_1)
{
  if (param_1 <= -1.0f) {
    return (float10)_DAT_00727c78;
  }
  if (param_1 < 1.0f) {
    // NEEDS_MANUAL: _CIacos reads its operand from the x87 stack; the listing shows
    // no explicit argument, and that operand is param_1.
    float10 fVar1 = (float10)_CIacos();
    return fVar1;
  }
  return (float10)0.0;
}

// 0x53c6f0 — observed shape
void FUN_0053c6f0(void* self, uint32_t* param_1, uint32_t* param_2, uint32_t* param_3)
{
  uint32_t* m = (uint32_t*)self;
  m[0] = param_1[0];
  m[3] = param_1[1];
  m[6] = param_1[2];
  m[1] = param_2[0];
  m[4] = param_2[1];
  m[7] = param_2[2];
  m[2] = param_3[0];
  m[5] = param_3[1];
  m[8] = param_3[2];
}

// 0x53c740 — observed shape
void FUN_0053c740(void* self, float param_1)
{
  float* m = (float*)self;
  float10 fVar1 = fcos((float10)param_1);
  float10 fVar2;

  m[0] = 1.0f;
  m[1] = 0.0f;
  m[2] = 0.0f;
  m[3] = 0.0f;
  m[6] = 0.0f;
  fVar2 = fsin((float10)param_1);
  m[4] = (float)fVar1;
  m[5] = (float)fVar2;
  m[7] = (float)(-fVar2);
  m[8] = (float)fVar1;
}

// 0x53c780 — observed shape
void FUN_0053c780(void* self, float param_1)
{
  float* m = (float*)self;
  float10 fVar1 = fcos((float10)param_1);
  float10 fVar2;

  m[1] = 0.0f;
  m[3] = 0.0f;
  m[4] = 1.0f;
  m[5] = 0.0f;
  m[7] = 0.0f;
  fVar2 = fsin((float10)param_1);
  m[0] = (float)fVar1;
  m[2] = (float)(-fVar2);
  m[6] = (float)fVar2;
  m[8] = (float)fVar1;
}

// 0x53c7c0 — observed shape
void FUN_0053c7c0(void* self, float param_1)
{
  float* m = (float*)self;
  float10 fVar1 = fcos((float10)param_1);
  float10 fVar2;

  m[2] = 0.0f;
  m[5] = 0.0f;
  m[6] = 0.0f;
  m[7] = 0.0f;
  m[8] = 1.0f;
  fVar2 = fsin((float10)param_1);
  m[0] = (float)fVar1;
  m[1] = (float)fVar2;
  m[3] = (float)(-fVar2);
  m[4] = (float)fVar1;
}
