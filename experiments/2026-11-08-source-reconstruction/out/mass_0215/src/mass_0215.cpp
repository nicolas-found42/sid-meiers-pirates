#include <cstdint>
#include <cstddef>
#include <windows.h>

// 0x5c7220 — observed shape: repeated memcpy of n bytes from +0x14 row to +0x28 row
int FUN_005c7220(void* self) {
  int total = 0;
  char* base = (char*)self;
  uint32_t* src = *(uint32_t**)(base + 0x14);
  uint32_t* dst = *(uint32_t**)(base + 0x28);
  int running = 0;
  uint16_t done = 0;
  if (*(int16_t*)(base + 0xc) != 0) {
    do {
      uint32_t n = *(uint32_t*)(base + 0x20);
      uint32_t* s = src;
      uint32_t* d = dst;
      for (uint32_t k = n >> 2; k != 0; k--) { *d = *s; s++; d++; }
      for (uint32_t k = n & 3; k != 0; k--) { *(uint8_t*)d = *(uint8_t*)s; s = (uint32_t*)((uintptr_t)s + 1); d = (uint32_t*)((uintptr_t)d + 1); }
      dst = (uint32_t*)((uintptr_t)dst + *(int32_t*)(base + 0x24));
      n = *(uint32_t*)(base + 0x20);
      running = running + (int)n;
      src = (uint32_t*)((uintptr_t)src + *(int32_t*)(base + 0x1c));
      done = (uint16_t)(done + 1);
      total = running;
    } while (done < *(uint16_t*)(base + 0xc));
  }
  return total;
}

// 0x5c7290 — observed shape: copy n bytes then zero-pad, linear vs index-table source
int FUN_005c7290(void* self) {
  int baseA = (int)(intptr_t)self;
  uint32_t* srcBase = *(uint32_t**)(baseA + 0x14);
  uint32_t* dstBase = *(uint32_t**)(baseA + 0x28);
  int idxTable = *(int*)(baseA + 0x10);
  uint16_t c = *(uint16_t*)(baseA + 8);
  int total = 0;
  int running = 0;
  uint16_t pad = (uint16_t)(*(int16_t*)(baseA + 4) - c) + 1;
  if (idxTable == 0) {
    uint16_t done = 0;
    uint32_t* rowSrc = srcBase;
    if (*(int16_t*)(baseA + 0xc) != 0) {
      do {
        uint32_t n = *(uint32_t*)(baseA + 0x18);
        uint32_t* s = rowSrc;
        uint32_t* d = dstBase;
        for (uint32_t k = n >> 2; k != 0; k--) { *d = *s; s++; d++; }
        for (uint32_t k = n & 3; k != 0; k--) { *(uint8_t*)d = *(uint8_t*)s; s = (uint32_t*)((uintptr_t)s + 1); d = (uint32_t*)((uintptr_t)d + 1); }
        if (pad != 0) {
          uint32_t* p = (uint32_t*)(*(int*)(baseA + 0x18) + (int)(uintptr_t)dstBase);
          for (uint32_t k = pad; k != 0; k--) { *p = 0; p++; }
        }
        dstBase = (uint32_t*)((uintptr_t)dstBase + *(int*)(baseA + 0x24));
        total = running + *(int*)(baseA + 0x20);
        rowSrc = (uint32_t*)((uintptr_t)rowSrc + *(int*)(baseA + 0x1c));
        done = (uint16_t)(done + 1);
        running = total;
      } while (done < *(uint16_t*)(baseA + 0xc));
    }
  } else {
    uint32_t idx = 0;
    uint16_t done = 0;
    if (*(int16_t*)(baseA + 0xc) != 0) {
      do {
        uint32_t uVar7 = idx & 0xffff;
        idx = idx + 1;
        uint32_t n = *(uint32_t*)(baseA + 0x18);
        uint32_t* s = srcBase + (uint32_t)*(uint16_t*)(idxTable + uVar7 * 2) * (uint32_t)c;
        uint32_t* d = dstBase;
        for (uint32_t k = n >> 2; k != 0; k--) { *d = *s; s++; d++; }
        for (uint32_t k = n & 3; k != 0; k--) { *(uint8_t*)d = *(uint8_t*)s; s = (uint32_t*)((uintptr_t)s + 1); d = (uint32_t*)((uintptr_t)d + 1); }
        dstBase = dstBase + *(int*)(baseA + 0x1c);
        if (pad != 0) {
          uint32_t* p = dstBase;
          for (uint32_t k = pad; k != 0; k--) { *p = 0; p++; }
          dstBase = dstBase + pad;
        }
        running = running + *(int*)(baseA + 0x20);
        done = (uint16_t)(done + 1);
      } while (done < *(uint16_t*)(baseA + 0xc));
      return running;
    }
  }
  return total;
}

// 0x5c73d0 — observed shape: zero-fill when source null, else copy with optional index table
int FUN_005c73d0(void* self) {
  int baseA = (int)(intptr_t)self;
  int idxTable = *(int*)(baseA + 0x10);
  uint32_t* dstBase = *(uint32_t**)(baseA + 0x28);
  uint32_t* srcBase = *(uint32_t**)(baseA + 0x14);
  int total = 0;
  uint16_t c = *(uint16_t*)(baseA + 8);
  if (srcBase == nullptr) {
    uint16_t done = 0;
    if (*(int16_t*)(baseA + 0xc) != 0) {
      uint32_t n = *(uint32_t*)(baseA + 0x20);
      do {
        uint32_t* w = dstBase;
        for (uint32_t k = n >> 2; k != 0; k--) { *w = 0; w++; }
        for (uint32_t k = n & 3; k != 0; k--) { *(uint8_t*)w = 0; w = (uint32_t*)((uintptr_t)w + 1); }
        dstBase = (uint32_t*)((uintptr_t)dstBase + *(int*)(baseA + 0x24));
        n = *(uint32_t*)(baseA + 0x20);
        total += (int)n;
        done = (uint16_t)(done + 1);
      } while (done < *(uint16_t*)(baseA + 0xc));
      return total;
    }
  } else if (idxTable == 0) {
    uint16_t done = 0;
    uint32_t* rowSrc = srcBase;
    if (*(int16_t*)(baseA + 0xc) != 0) {
      do {
        uint32_t n = *(uint32_t*)(baseA + 0x18);
        uint32_t* s = rowSrc;
        uint32_t* d = dstBase;
        for (uint32_t k = n >> 2; k != 0; k--) { *d = *s; s++; d++; }
        for (uint32_t k = n & 3; k != 0; k--) { *(uint8_t*)d = *(uint8_t*)s; s = (uint32_t*)((uintptr_t)s + 1); d = (uint32_t*)((uintptr_t)d + 1); }
        total += *(int*)(baseA + 0x20);
        rowSrc = (uint32_t*)((uintptr_t)rowSrc + *(int*)(baseA + 0x1c));
        dstBase = (uint32_t*)((uintptr_t)dstBase + *(int*)(baseA + 0x24));
        done = (uint16_t)(done + 1);
      } while (done < *(uint16_t*)(baseA + 0xc));
    }
  } else {
    uint16_t idx = 0;
    if (*(int16_t*)(baseA + 0xc) != 0) {
      do {
        uint32_t uVar12 = idx;
        uint32_t n = *(uint32_t*)(baseA + 0x18);
        idx = (uint16_t)(idx + 1);
        uint32_t* s = srcBase + (uint32_t)*(uint16_t*)(idxTable + uVar12 * 2) * (uint32_t)c;
        uint32_t* d = dstBase;
        for (uint32_t k = n >> 2; k != 0; k--) { *d = *s; s++; d++; }
        for (uint32_t k = n & 3; k != 0; k--) { *(uint8_t*)d = *(uint8_t*)s; s = (uint32_t*)((uintptr_t)s + 1); d = (uint32_t*)((uintptr_t)d + 1); }
        dstBase = (uint32_t*)((uintptr_t)dstBase + *(int*)(baseA + 0x24));
        total += *(int*)(baseA + 0x20);
      } while (idx < *(uint16_t*)(baseA + 0xc));
      return total;
    }
  }
  return total;
}

// 0x5c7500 — observed shape: scale int32 by 4.656613e-10 minus 1.0 into float rows
int FUN_005c7500(void* self) {
  int baseA = (int)(intptr_t)self;
  int srcBase = *(int*)(baseA + 0x14);
  float* dst = *(float**)(baseA + 0x28);
  uint16_t limit = (uint16_t)(*(int16_t*)(baseA + 8) - 4);
  uint16_t want = (uint16_t)(*(int16_t*)(baseA + 4) + 1);
  int total = 0;
  uint32_t n = want;
  if ((int16_t)(limit - want) < 1) n = limit;
  uint16_t done = 0;
  if (*(int16_t*)(baseA + 0xc) == 0) return 0;
  do {
    uint32_t filled = 0;
    float* w = dst;
    if ((int16_t)n != 0) {
      filled = n;
      float* cur = dst;
      do {
        w = cur + 1;
        filled--;
        *cur = (float)*(int*)(srcBase - (int)(uintptr_t)dst + (int)(uintptr_t)cur) * 4.656613e-10f - 1.0f;
        cur = w;
      } while (filled != 0);
      filled = n;
    }
    if ((uint16_t)filled < want) {
      for (uint32_t k = (uint32_t)(uint16_t)(want - filled); k != 0; k--) { *w = 0.0f; w++; }
    }
    srcBase += *(int*)(baseA + 0x1c);
    total += *(int*)(baseA + 0x20);
    dst = (float*)((uintptr_t)dst + *(int*)(baseA + 0x24));
    done = (uint16_t)(done + 1);
  } while (done < *(uint16_t*)(baseA + 0xc));
  return total;
}

// 0x5c75d0 — observed shape: scale int32 by 2.3283064e-10 into float rows
int FUN_005c75d0(void* self) {
  int baseA = (int)(intptr_t)self;
  int srcBase = *(int*)(baseA + 0x14);
  float* dst = *(float**)(baseA + 0x28);
  uint16_t limit = (uint16_t)(*(int16_t*)(baseA + 8) - 8);
  uint16_t want = (uint16_t)(*(int16_t*)(baseA + 4) + 1);
  int total = 0;
  uint32_t n = want;
  if ((int16_t)(limit - want) < 1) n = limit;
  uint16_t done = 0;
  if (*(int16_t*)(baseA + 0xc) == 0) return 0;
  do {
    uint32_t filled = 0;
    float* w = dst;
    if ((int16_t)n != 0) {
      filled = n;
      float* cur = dst;
      do {
        w = cur + 1;
        filled--;
        *cur = (float)*(int*)(srcBase - (int)(uintptr_t)dst + (int)(uintptr_t)cur) * 2.3283064e-10f;
        cur = w;
      } while (filled != 0);
      filled = n;
    }
    if ((uint16_t)filled < want) {
      for (uint32_t k = (uint32_t)(uint16_t)(want - filled); k != 0; k--) { *w = 0.0f; w++; }
    }
    srcBase += *(int*)(baseA + 0x1c);
    total += *(int*)(baseA + 0x20);
    dst = (float*)((uintptr_t)dst + *(int*)(baseA + 0x24));
    done = (uint16_t)(done + 1);
  } while (done < *(uint16_t*)(baseA + 0xc));
  return total;
}

// 0x5c76a0 — observed shape: scale int16 by 3.051851e-05 minus 1.0 into float rows
int FUN_005c76a0(void* self) {
  int baseA = (int)(intptr_t)self;
  int16_t* src = *(int16_t**)(baseA + 0x14);
  float* dst = *(float**)(baseA + 0x28);
  uint16_t limit = (uint16_t)(*(int16_t*)(baseA + 8) - 0xc);
  uint16_t want = (uint16_t)(*(int16_t*)(baseA + 4) + 1);
  int total = 0;
  uint16_t n = want;
  if ((int16_t)(limit - want) < 1) n = limit;
  uint16_t done = 0;
  if (*(int16_t*)(baseA + 0xc) == 0) return 0;
  do {
    uint32_t filled = 0;
    float* w = dst;
    if (n != 0) {
      filled = n;
      int16_t* s = src;
      float* cur = dst;
      do {
        int16_t v = *s;
        w = cur + 1;
        s = s + 1;
        filled--;
        *cur = (float)(int)v * 3.051851e-05f - 1.0f;
        cur = w;
      } while (filled != 0);
    }
    if ((uint16_t)filled < want) {
      for (uint32_t k = (uint32_t)(uint16_t)(want - filled); k != 0; k--) { *w = 0.0f; w++; }
    }
    src = (int16_t*)((uintptr_t)src + *(int*)(baseA + 0x1c));
    total += *(int*)(baseA + 0x20);
    dst = (float*)((uintptr_t)dst + *(int*)(baseA + 0x24));
    done = (uint16_t)(done + 1);
  } while (done < *(uint16_t*)(baseA + 0xc));
  return total;
}

// 0x5c7870 — observed shape: scale byte by 0.007874016 minus 1.0 into float rows
int FUN_005c7870(void* self) {
  int baseA = (int)(intptr_t)self;
  uint8_t* src = *(uint8_t**)(baseA + 0x14);
  float* dst = *(float**)(baseA + 0x28);
  uint16_t limit = (uint16_t)(*(int16_t*)(baseA + 8) - 0x14);
  uint16_t want = (uint16_t)(*(int16_t*)(baseA + 4) + 1);
  int total = 0;
  uint16_t n = want;
  if ((int16_t)(limit - want) < 1) n = limit;
  uint16_t done = 0;
  if (*(int16_t*)(baseA + 0xc) == 0) return 0;
  do {
    uint32_t filled = 0;
    float* w = dst;
    if (n != 0) {
      filled = n;
      uint8_t* s = src;
      float* cur = dst;
      do {
        uint8_t v = *s;
        w = cur + 1;
        s = s + 1;
        filled--;
        *cur = (float)v * 0.007874016f - 1.0f;
        cur = w;
      } while (filled != 0);
    }
    if ((uint16_t)filled < want) {
      for (uint32_t k = (uint32_t)(uint16_t)(want - filled); k != 0; k--) { *w = 0.0f; w++; }
    }
    src = src + *(int*)(baseA + 0x1c);
    total += *(int*)(baseA + 0x20);
    dst = (float*)((uintptr_t)dst + *(int*)(baseA + 0x24));
    done = (uint16_t)(done + 1);
  } while (done < *(uint16_t*)(baseA + 0xc));
  return total;
}

// 0x5c7960 — observed shape: scale byte by 0.003921569 into float rows
int FUN_005c7960(void* self) {
  int baseA = (int)(intptr_t)self;
  uint8_t* src = *(uint8_t**)(baseA + 0x14);
  float* dst = *(float**)(baseA + 0x28);
  uint16_t limit = (uint16_t)(*(int16_t*)(baseA + 8) - 0x18);
  uint16_t want = (uint16_t)(*(int16_t*)(baseA + 4) + 1);
  int total = 0;
  uint16_t n = want;
  if ((int16_t)(limit - want) < 1) n = limit;
  uint16_t done = 0;
  if (*(int16_t*)(baseA + 0xc) == 0) return 0;
  do {
    uint32_t filled = 0;
    float* w = dst;
    if (n != 0) {
      filled = n;
      uint8_t* s = src;
      float* cur = dst;
      do {
        uint8_t v = *s;
        w = cur + 1;
        s = s + 1;
        filled--;
        *cur = (float)v * 0.003921569f;
        cur = w;
      } while (filled != 0);
    }
    if ((uint16_t)filled < want) {
      for (uint32_t k = (uint32_t)(uint16_t)(want - filled); k != 0; k--) { *w = 0.0f; w++; }
    }
    src = src + *(int*)(baseA + 0x1c);
    total += *(int*)(baseA + 0x20);
    dst = (float*)((uintptr_t)dst + *(int*)(baseA + 0x24));
    done = (uint16_t)(done + 1);
  } while (done < *(uint16_t*)(baseA + 0xc));
  return total;
}

// 0x5c7bd0 — observed shape: byte copy of up to 4 bytes then zero-fill to 4
int FUN_005c7bd0(void* self) {
  int baseA = (int)(intptr_t)self;
  uint8_t* src = *(uint8_t**)(baseA + 0x14);
  uint32_t* dst = *(uint32_t**)(baseA + 0x28);
  int total = 0;
  uint16_t n = 4;
  if ((int16_t)(*(int16_t*)(baseA + 8) - 0x18) < 1) n = (uint16_t)(*(int16_t*)(baseA + 8) - 0x14);
  uint16_t done = 0;
  if (*(int16_t*)(baseA + 0xc) == 0) return 0;
  for (;;) {
    uint32_t filled = 0;
    if (n == 0) {
      uint32_t pad = (4u - filled) & 0xffff;
      uint32_t* w = dst;
      for (uint32_t k = pad >> 2; k != 0; k--) { *w = 0; w++; }
      for (uint32_t k = (4u - filled) & 3; k != 0; k--) { *(uint8_t*)w = 0; w = (uint32_t*)((uintptr_t)w + 1); }
      dst = (uint32_t*)((uintptr_t)dst + pad);
    } else {
      filled = n;
      uint8_t* s = src;
      uint32_t* d = dst;
      uint32_t k = filled;
      do {
        *(uint8_t*)d = *s;
        d = (uint32_t*)((uintptr_t)d + 1);
        s = s + 1;
        k = k - 1;
      } while (k != 0);
      dst = d;
      if (n < 4) {
        uint32_t pad = (4u - filled) & 0xffff;
        uint32_t* w = dst;
        for (uint32_t t = pad >> 2; t != 0; t--) { *w = 0; w++; }
        for (uint32_t t = (4u - filled) & 3; t != 0; t--) { *(uint8_t*)w = 0; w = (uint32_t*)((uintptr_t)w + 1); }
        dst = (uint32_t*)((uintptr_t)dst + pad);
      }
    }
    total += *(int*)(baseA + 0x20);
    src = src + *(int*)(baseA + 0x1c);
    dst = (uint32_t*)((uintptr_t)dst + *(int*)(baseA + 0x24));
    done = (uint16_t)(done + 1);
    if (*(uint16_t*)(baseA + 0xc) <= done) return total;
  }
}

// 0x5c7ca0 — observed shape: in-place expand through +0x14 delta, zero-fill to 4
int FUN_005c7ca0(void* self) {
  int baseA = (int)(intptr_t)self;
  uint8_t* buf = *(uint8_t**)(baseA + 0x28);
  int delta = *(int*)(baseA + 0x14);
  int total = 0;
  uint16_t n = 4;
  if ((int16_t)(*(int16_t*)(baseA + 8) - 0x1c) < 1) n = (uint16_t)(*(int16_t*)(baseA + 8) - 0x18);
  uint16_t done = 0;
  if (*(int16_t*)(baseA + 0xc) == 0) return 0;
  for (;;) {
    uint32_t filled = 0;
    if (n == 0) {
      uint32_t* w = (uint32_t*)(buf + filled);
      for (uint32_t k = (4u - filled & 0xffff) >> 2; k != 0; k--) { *w = 0; w++; }
      for (uint32_t k = 4u - filled & 3; k != 0; k--) { *(uint8_t*)w = 0; w = (uint32_t*)((uintptr_t)w + 1); }
    } else {
      filled = n;
      uint8_t* cur = buf;
      uint32_t k = filled;
      do {
        *cur = cur[delta - (int)(uintptr_t)buf];
        cur = cur + 1;
        k = k - 1;
      } while (k != 0);
      if (n < 4) {
        uint32_t* w = (uint32_t*)(buf + filled);
        for (uint32_t t = (4u - filled & 0xffff) >> 2; t != 0; t--) { *w = 0; w++; }
        for (uint32_t t = 4u - filled & 3; t != 0; t--) { *(uint8_t*)w = 0; w = (uint32_t*)((uintptr_t)w + 1); }
      }
    }
    total += *(int*)(baseA + 0x20);
    delta += *(int*)(baseA + 0x1c);
    buf = buf + *(int*)(baseA + 0x24);
    done = (uint16_t)(done + 1);
    if (*(uint16_t*)(baseA + 0xc) <= done) return total;
  }
}

// 0x5c7dd0 — observed shape: allocate 0x18 record, vtable PTR_FUN_006c76f4, [5]=1 rest 0
extern void* FUN_00533c78(uint32_t size);
extern uint32_t DAT_00728de0_storage;
extern void* PTR_FUN_006c76f4;
void FUN_005c7dd0(void) {
  uint32_t* rec = (uint32_t*)FUN_00533c78(0x18);
  *(uint32_t**)&DAT_00728de0_storage = rec;
  // published as DAT_00728de0 in listing; extern storage holds it
  extern uint32_t** DAT_00728de0;
  *DAT_00728de0 = rec;
  if (rec == nullptr) {
    *DAT_00728de0 = nullptr;
    return;
  }
  *rec = (uint32_t)(uintptr_t)&PTR_FUN_006c76f4;
  rec[2] = 0;
  rec[5] = 1;
  rec[3] = 0;
  rec[4] = 0;
  rec[1] = 0;
}

// 0x5c7e10 — observed shape: scalar deleting-dtor style: if flag&1 delete ECX
void FUN_005c71a0(void* self);
extern void operator_delete(void* p);
void FUN_005c7e10(void* self, uint8_t flag) {
  FUN_005c71a0(self);
  if ((flag & 1) != 0) operator_delete(self);
}

// 0x5c7e30 — observed shape: dispatch on param_6 type field via table DAT_00728de0, resolve handler pointer
extern uint32_t DAT_00728d98_table[32];
extern uint32_t* DAT_00728de0;
extern uint32_t FUN_005412c0(int16_t v);
typedef uint32_t (*handler_fn)(void*);
uint32_t FUN_005c7e30(uint16_t param_1, int param_2, uint32_t param_3, int param_4, int** param_5, int param_6, uint32_t param_7, uint32_t param_8) {
  uint32_t local_2c = *(uint32_t*)(param_6 + 8);
  uint32_t local_28 = 0;
  int local_24 = 0;
  uint16_t local_20 = param_1;
  uint32_t local_1c = 0;
  int local_18 = 0;
  uint32_t local_14 = 0;
  uint32_t local_10 = 0;
  uint32_t local_8 = param_7;
  uint32_t local_4 = param_8;
  (void)local_20; (void)local_8; (void)local_4; (void)param_3;
  int kind = *(int*)(param_6 + 0xc);
  if (kind == 0x11) return 0;
  local_14 = DAT_00728d98_table[(uint32_t)kind];
  int slot = *(int*)(*(int*)( (uintptr_t)DAT_00728de0 + 4) + kind * 4);
  if (slot == 0) return 0;
  local_24 = slot;
  switch ((int32_t)local_2c) {
    case 0: local_18 = *(int*)(param_2 + 0x20); local_14 = 0xc; local_10 = 0xc; local_24 = 3; break;
    case 1: {
      if (param_4 == 0) return 0;
      uint16_t sub = *(uint16_t*)(param_4 + 0x24);
      local_18 = *(int*)(param_4 + 8);
      if (sub == 1) { local_14 = 4; local_10 = 4; local_24 = 1; }
      else if (sub == 2) { local_14 = 8; local_10 = 8; local_24 = 2; }
      else if (sub == 3) { local_14 = 0xc; local_10 = 0xc; local_24 = 3; }
      else if (sub == 4) { local_24 = 3; local_14 = 0xc; local_10 = 0x10; }
      break;
    }
    case 2: {
      if (param_4 == 0) return 0;
      local_18 = *(int*)(param_4 + 0x10);
      if (local_18 == 0) return 0;
      uint16_t sub = *(uint16_t*)(param_4 + 0x24);
      if (sub == 1) { local_24 = 0x19; local_14 = 1; local_10 = 1; }
      else if (sub == 2) { local_24 = 0x1a; local_14 = 2; local_10 = 2; }
      else if (sub == 3) { local_24 = 0x1b; local_14 = 3; local_10 = 3; }
      else if (sub == 4) { local_24 = 0x1c; local_14 = 4; local_10 = 4; }
      break;
    }
    case 3: local_18 = *(int*)(param_2 + 0x24); local_14 = 0xc; local_10 = 0xc; local_24 = 3; break;
    case 4: local_18 = *(int*)(param_2 + 0x28); local_14 = 0x10; local_10 = 0x10; local_24 = 4; break;
    case 5: case 6: case 7: case 8: case 9: case 10: case 0xb: case 0xc:
      local_18 = (int)FUN_005412c0((int16_t)(*(int16_t*)(param_6 + 8) - 5)); local_14 = 8; local_10 = 8; local_24 = 2; break;
    case 0xd:
      local_18 = *(int*)(param_2 + 0x24) + (uint32_t)*(uint16_t*)(param_2 + 0xc) * 0x18; local_14 = 0xc; local_10 = 0xc; local_24 = 3; break;
    case 0xe:
      local_18 = *(int*)(param_2 + 0x24) + (uint32_t)*(uint16_t*)(param_2 + 0xc) * 0xc; local_14 = 0xc; local_10 = 0xc; local_24 = 3; break;
    case 0xffffffff:
      return 0;
    default:
      if ((int32_t)local_2c < 0) {
        uint32_t uVar3 = local_2c & 0x7fffffff;
        typedef uint32_t (*cb)(uint32_t);
        local_1c = (uint32_t)((cb)(**(void***)((*(int***)param_5) + 0x4c/4)))(uVar3);
        local_1c = (uint32_t)((cb)(**(void***)((*(int***)param_5) + 0x40/4)))(uVar3);
        local_1c = (uint32_t)((cb)(**(void***)((*(int***)param_5) + 0x48/4)))(uVar3);
        local_24 = (int)(uint32_t)((cb)(**(void***)((*(int***)param_5) + 0x38/4)))(uVar3);
      }
      break;
  }
  int handlerBase = *(int*)(slot + 8);
  handler_fn fn = (handler_fn)*(void**)(handlerBase + local_24 * 4);
  if (fn != nullptr) {
    if (param_4 == 0 || *(int*)(param_6 + 8) == 1 || *(int*)(param_6 + 8) == 2) local_1c = 0;
    else local_1c = *(uint32_t*)(param_4 + 0xc);
    local_28 = *(uint32_t*)(param_6 + 0xc);
    return fn(&local_2c);
  }
  return 0;
}

// 0x5c8380 — observed shape: init ECX record: vtable PTR_FUN_006c76f8, [0]=0x11, [6]=1, zero counters
extern void* PTR_FUN_006c76f8;
void FUN_005c8380(void* self) {
  uint32_t* rec = (uint32_t*)self;
  rec[1] = (uint32_t)(uintptr_t)&PTR_FUN_006c76f8;
  rec[3] = 0;
  rec[6] = 1;
  rec[4] = 0;
  rec[5] = 0;
  rec[2] = 0;
  *rec = 0x11;
  uint32_t n = 0;
  if (rec[4] != 0) {
    do {
      *(uint32_t*)(rec[2] + n * 4) = 0;
      n++;
    } while (n < rec[4]);
  }
  rec[4] = 0;
  rec[5] = 0;
}

// 0x5c83d0 — observed shape: install builtin widths table DAT_00728d98 and 0x12 records
extern void FUN_005c8380(void* self);
extern uint32_t* DAT_00728de0;
extern uint32_t DAT_00728d98_table[32];
extern void FUN_006b34a0(int v);
extern void FUN_005d7a30(uint32_t a, uint32_t b);
uint32_t FUN_005c83d0(void) {
  if (*(int*)((uintptr_t)DAT_00728de0 + 0xc) != 0x12) {
    uint32_t widths[18] = {4,8,0xc,0x10,4,4,4,8,4,4,8,4,8,4,4,4,8,0};
    for (int i = 0; i < 17; i++) DAT_00728d98_table[i] = widths[i];
    uint32_t idx = 0;
    do {
      int mem = (int)(uintptr_t)FUN_00533c78(0x1c);
      uint32_t* rec;
      if (mem == 0) rec = nullptr;
      else { FUN_005c8380((void*)(uintptr_t)mem); rec = (uint32_t*)(uintptr_t)mem; }
      *rec = idx;
      FUN_006b34a0(0x26);
      int hdr = (int)(uintptr_t)DAT_00728de0;
      uint32_t* capPtr = (uint32_t*)(uintptr_t)(hdr + 8);
      if (idx < *capPtr || (FUN_006b34a0(*(int*)(hdr + 0x14) + (int)idx), idx < *capPtr)) {
        if (idx < *(uint32_t*)(hdr + 0xc)) {
          if (*(int*)(*(int*)(hdr + 4) + idx * 4) == 0) goto LAB;
        } else {
          *(uint32_t*)(hdr + 0xc) = idx + 1;
LAB:
          *(int*)(hdr + 0x10) = *(int*)(hdr + 0x10) + 1;
        }
        *(uint32_t**)(*(int*)(hdr + 4) + idx * 4) = rec;
      }
      idx++;
    } while (idx < 0x12);
    uint32_t a = 0;
    do {
      uint32_t b = 0;
      do { FUN_005d7a30(a, b); b++; } while (b < 0x21);
      a++;
    } while (a < 0x12);
  }
  return 1;
}

// 0x5c84f0 — observed shape: init ECX object from param_1, alloc arrays, call FUN_005c83d0
extern void FUN_005c83d0(void);
extern void FUN_005d6380(void);
extern void* FUN_00533c78(uint32_t size);
typedef void* (*thunk_fn)(uint32_t);
uint32_t FUN_005c84f0(void* self, int param_1, int param_2) {
  uint8_t* rec = (uint8_t*)self;
  *(int*)(rec + 0xc) = param_1;
  *(uint32_t*)(rec + 0x10) = *(uint32_t*)(param_1 + 0x5d0);
  int* helper = *(int**)(param_1 + 0x60);
  *(int**)(rec + 0x14) = helper;
  ((void(*)(int*))( *(void**)(*helper + 4) ))(helper);
  *(int*)(rec + 0x20) = param_1;
  *(int*)(rec + 0x24) = param_2;
  int arr = (int)(uintptr_t)FUN_00533c78((uint32_t)(param_2 << 4));
  int arrVal = 0;
  if (arr != 0 && param_2 - 1 >= 0) {
    uint32_t* p = (uint32_t*)(arr + 8);
    int left = param_2;
    do {
      *(uint8_t*)(p - 2) = 0;
      p[-1] = 0;
      *p = 0;
      p[1] = 0;
      p = p + 4;
      left--;
    } while (left != 0);
    arrVal = arr;
  } else if (arr != 0) arrVal = arr;
  *(int*)(rec + 0x28) = arrVal;
  uint32_t done = 0;
  if (*(int*)(rec + 0x24) != 0) {
    int off = 0;
    do {
      int count = *(int*)(rec + 0x20);
      int block = (int)(uintptr_t)FUN_00533c78((uint32_t)(count * 0x1c));
      int blockVal = 0;
      if (block != 0 && count - 1 >= 0) {
        int left = count;
        do { FUN_005d6380(); left--; } while (left != 0);
        blockVal = block;
      } else if (block != 0) blockVal = block;
      *(int*)(*(int*)(rec + 0x28) + 8 + off) = blockVal;
      off += 0x10;
      done++;
    } while (done < *(uint32_t*)(rec + 0x24));
  }
  FUN_005c83d0();
  return 1;
}

// 0x5c85e0 — observed shape: tear down DAT_00728de0 registry, delete each entry, zero slots
extern uint32_t* DAT_00728de0;
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
void FUN_005c85e0(void) {
  uint32_t idx = 0;
  uint32_t* hdr = DAT_00728de0;
  if (hdr[3] != 0) {
    do {
      void* entry = *(void**)(hdr[1] + idx * 4);
      if (entry != nullptr) {
        uint32_t k = 0;
        if (*(int*)((uintptr_t)entry + 0x10) != 0) {
          do {
            *(uint32_t*)(*(int*)((uintptr_t)entry + 8) + k * 4) = 0;
            k++;
          } while (k < *(uint32_t*)((uintptr_t)entry + 0x10));
        }
        *(uint32_t*)((uintptr_t)entry + 0x10) = 0;
        *(uint32_t*)((uintptr_t)entry + 0x14) = 0;
        extern void* PTR_FUN_006c76f8;
        *(void**)((uintptr_t)entry + 4) = &PTR_FUN_006c76f8;
        operator_delete__(*(void**)((uintptr_t)entry + 8));
        operator_delete(entry);
        hdr = DAT_00728de0;
      }
      idx++;
    } while (idx < (uint32_t)hdr[3]);
  }
  uint32_t j = 0;
  if (hdr[3] != 0) {
    do {
      *(uint32_t*)(hdr[1] + j * 4) = 0;
      j++;
    } while (j < (uint32_t)hdr[3]);
  }
  hdr[4] = 0;
  hdr[3] = 0;
  if (DAT_00728de0 != nullptr) {
    ((void(*)(uint32_t))(**(void***)(uintptr_t)DAT_00728de0))(1);
  }
}

// 0x5c8680 — observed shape: fetch handler ptr from registry slot, ensure + grow when needed
extern uint32_t* DAT_00728de0;
extern void FUN_005c83d0(void);
extern void FUN_005d7a30(uint32_t a, uint32_t b);
extern void FUN_006b34a0(int v);
extern void FUN_005606f0(uint32_t idx, int* val);
uint32_t FUN_005c8680(int param_1, uint32_t param_2, int param_3) {
  FUN_005c83d0();
  int entry = *(int*)(*(int*)((uintptr_t)DAT_00728de0 + 4) + param_1 * 4);
  if (entry == 0) return 0;
  uint32_t ret = *(uint32_t*)(*(int*)(entry + 8) + param_2 * 4);
  if (param_3 == 0) {
    FUN_005d7a30((uint32_t)param_1, param_2);
    return ret;
  }
  if (*(uint32_t*)(entry + 0xc) <= param_2) {
    FUN_006b34a0(*(int*)(entry + 0x18) + (int)param_2);
  }
  FUN_005606f0(param_2, &param_3);
  return ret;
}

// 0x5c8710 — observed shape: set globals DAT_00728df4/df8/df0 from param_1, addref helper at +0x60
extern int DAT_00728df4;
extern uint32_t DAT_00728df8;
extern int* DAT_00728df0;
void FUN_005c8710(int param_1) {
  DAT_00728df4 = param_1;
  if (param_1 == 0) {
    DAT_00728df8 = 0;
    if (DAT_00728df0 != nullptr) {
      ((void(*)(int*))(**(void***)DAT_00728df0 + 8))((void*)DAT_00728df0);
    }
    DAT_00728df0 = nullptr;
    return;
  }
  int* helper = *(int**)(param_1 + 0x60);
  if (DAT_00728df0 != nullptr) {
    ((void(*)(int*))(**(void***)DAT_00728df0 + 8))((void*)DAT_00728df0);
  }
  DAT_00728df0 = helper;
  if (helper != nullptr) {
    ((void(*)(int*))(**(void***)helper + 4))((void*)helper);
  }
  DAT_00728df8 = *(uint32_t*)(DAT_00728df4 + 0x5cc);
}

// 0x5c8780 — observed shape: if +8 nonzero, call FUN_005bd960 and mask result
extern char FUN_005bd960(uint32_t v, uint32_t* out);
uint32_t FUN_005c8780(void* self, uint32_t param_1) {
  uint8_t* rec = (uint8_t*)self;
  if (*(int*)(rec + 8) == 0) return 0;
  uint32_t out = 0;
  char ok = FUN_005bd960(param_1, &out);
  return (uint32_t)(-(int)(ok != '\0')) & out;
}
