#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers and globals referenced by the observed listings.
extern void* ExceptionList;
extern void operator_delete(void*);
extern void operator_delete(void*, int);
extern void FUN_005edba0();
extern void FUN_005ea3c0();
extern void FUN_005eefa0();
extern int FUN_00533c78(uint32_t);
extern int FUN_005eeec0();
extern int FUN_005606f0(uint32_t, void*);
extern void FUN_006b34a0(uint32_t);
extern uint8_t FUN_006b5020(uint32_t, void*);
extern void FUN_005c9b90(void*, uint32_t);
extern void FUN_005edbf0();
extern void FUN_005ebdf0();
extern void FUN_005ea870();
extern uint32_t DAT_007187cc;
extern uint32_t DAT_00727444;

// 0x5ed170 — observed shape
void FUN_005ed170(void* self) {
  uint8_t* base = static_cast<uint8_t*>(self);
  *reinterpret_cast<uint32_t*>(base + 0x10) = 0;
  *reinterpret_cast<uint32_t*>(base + 8) = 0;
  *reinterpret_cast<uint32_t*>(base + 0xc) = 0;
  *reinterpret_cast<void**>(base + 4) = reinterpret_cast<void*>(&PTR_FUN_006c9928);
  FUN_005edba0();
}

// 0x5ed1c0 — observed shape
void FUN_005ed1c0(void* self) {
  uint32_t* fields = static_cast<uint32_t*>(self);
  fields[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fd4);
  operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[1])));
}

// 0x5ed1e0 — observed shape
void FUN_005ed1e0(void* self, uint8_t param1) {
  uint32_t* fields = static_cast<uint32_t*>(self);
  fields[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fd4);
  operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[1])));
  if ((param1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5ed210 — observed shape
void FUN_005ed210(void* self) {
  uint32_t* fields = static_cast<uint32_t*>(self);
  for (int i = 0; i <= 0xe; i++) fields[i] = 0;
  *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(self) + 0x3c) = 0;
  fields[0x10] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fd4);
  fields[0x12] = 0;
  fields[0x15] = 1;
  fields[0x13] = 0;
  fields[0x14] = 0;
  fields[0x11] = 0;
  fields[0x13] = 0;
  fields[0x14] = 0;
}

// 0x5ed2b0 — observed shape
void FUN_005ed2b0(void* self) {
  uint32_t* fields = static_cast<uint32_t*>(self);
  operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[0])));
  void* pv = reinterpret_cast<void*>(static_cast<uintptr_t>(fields[2]));
  if (pv != nullptr) {
    FUN_005ea3c0();
    operator_delete(pv);
  }
  if (fields[3] != 0) {
    using Fn = void(__cdecl*)(int);
    auto** vptr = reinterpret_cast<Fn**>(static_cast<uintptr_t>(fields[3]));
    (*vptr)(1);
  }
  if (fields[4] != 0) {
    using Fn = void(__cdecl*)(int);
    auto** vptr = reinterpret_cast<Fn**>(static_cast<uintptr_t>(fields[4]));
    (*vptr)(1);
  }
  for (int i = 5; i <= 0xe; i++) {
    operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[i])));
  }
  uint32_t count = fields[0x13];
  uint32_t idx = 0;
  if (count != 0) {
    do {
      void* elem = *reinterpret_cast<void**>(static_cast<uintptr_t>(fields[0x11] + idx * 4));
      if (elem != nullptr) {
        FUN_005eefa0();
        operator_delete(elem);
        if (idx < fields[0x12]) {
          if (idx < fields[0x13]) {
            if (*reinterpret_cast<int*>(static_cast<uintptr_t>(fields[0x11] + idx * 4)) != 0) {
              fields[0x14] = fields[0x14] + 0xFFFFFFFFu;
            }
          } else {
            fields[0x13] = idx + 1;
          }
          *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(fields[0x11] + idx * 4)) = 0;
        }
      }
      idx = idx + 1;
    } while (idx < count);
  }
  uint32_t clear = 0;
  if (fields[0x13] != 0) {
    do {
      *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(fields[0x11] + clear * 4)) = 0;
      clear = clear + 1;
    } while (clear < fields[0x13]);
  }
  fields[0x13] = 0;
  fields[0x14] = 0;
  fields[0x10] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fd4);
  operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[0x11])));
  uint32_t* rc = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(fields[1]));
  if (rc != nullptr) {
    int* pi = reinterpret_cast<int*>(rc + 1);
    *pi = *pi + -1;
    if (*pi == 0) {
      using Fn = void(__cdecl*)(int);
      auto** vptr = reinterpret_cast<Fn**>(rc);
      (*vptr)(1);
    }
  }
}

// 0x5ed430 — observed shape
uint32_t FUN_005ed430(void* self) {
  return *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x4c);
}

// 0x5ed440 — observed shape
int FUN_005ed440(void* self, uint32_t param1, int param2) {
  uint8_t* base = static_cast<uint8_t*>(self);
  int ret = 0;
  uint32_t limit = *reinterpret_cast<uint32_t*>(base + 0x4c);
  bool cond = (limit <= param1);
  if (!cond) {
    ret = *reinterpret_cast<int*>(*reinterpret_cast<uint32_t*>(base + 0x44) + param1 * 4);
    cond = (ret == 0);
  }
  if (cond && ((char)param2 != 0)) {
    int created = FUN_00533c78(0x60);
    if (created == 0) {
      ret = 0;
    } else {
      ret = FUN_005eeec0();
    }
    param2 = ret;
    if (*reinterpret_cast<uint32_t*>(base + 0x48) <= param1) {
      FUN_006b34a0(*reinterpret_cast<uint32_t*>(base + 0x54) + param1);
    }
    FUN_005606f0(param1, &param2);
  }
  return ret;
}

// 0x5ed4f0 — observed shape
uint32_t FUN_005ed4f0(void* self, uint32_t param1) {
  uint8_t* base = static_cast<uint8_t*>(self);
  if (DAT_007187cc == 0x10001) {
    uint32_t* slot = reinterpret_cast<uint32_t*>(base + 0x14);
    if (FUN_006b5020(param1, slot) == 0) return 0;
    FUN_005c9b90(base + 0x18, *slot);
    FUN_005c9b90(base + 0x1c, *slot);
  } else {
    if (FUN_006b5020(param1, base + 0x14) == 0) return 0;
    if (FUN_006b5020(param1, base + 0x18) == 0) return 0;
    if (FUN_006b5020(param1, base + 0x1c) == 0) return 0;
  }
  if (DAT_007187cc == 0x10001) return 1;
  if (FUN_006b5020(param1, base + 0x20) == 0) return 0;
  if (FUN_006b5020(param1, base + 0x24) == 0) return 0;
  return 1;
}

// 0x5ed5b0 — observed shape
bool FUN_005ed5b0(void* self, uint32_t param1) {
  uint8_t* base = static_cast<uint8_t*>(self);
  if (DAT_007187cc == 0x10001) {
    uint32_t* slot = reinterpret_cast<uint32_t*>(base + 0x28);
    if (FUN_006b5020(param1, slot) == 0) return false;
    FUN_005c9b90(base + 0x2c, *slot);
    FUN_005c9b90(base + 0x30, *slot);
  } else {
    if (FUN_006b5020(param1, base + 0x28) == 0) return false;
    if (FUN_006b5020(param1, base + 0x2c) == 0) return false;
    if (FUN_006b5020(param1, base + 0x30) == 0) return false;
  }
  if (FUN_006b5020(param1, base + 0x34) == 0) return false;
  return FUN_006b5020(param1, base + 0x38) != 0;
}

// 0x5ed660 — observed shape
uint8_t FUN_005ed660(uint32_t param1) {
  uint32_t orig = param1;
  if (FUN_006b5090(param1, &param1) == 0) return 0;
  FUN_006b34a0(param1);
  uint32_t i = 0;
  if (param1 != 0) {
    do {
      int local = FUN_00533c78(0x60);
      if (local == 0) local = 0;
      else local = FUN_005eeec0();
      if (FUN_005eeff0(orig) == 0) return 0;
      FUN_005606f0(i, &local);
      i = i + 1;
    } while (i < param1);
  }
  return 1;
}

// 0x5ed740 — observed shape
uint32_t FUN_005ed740(void* self, int param1, int param2) {
  uint8_t* base = static_cast<uint8_t*>(self);
  void* pv = nullptr;
  if (*reinterpret_cast<int*>(base + 8) != 0) {
    if (FUN_005dbe20() != 0) {
      pv = (void*)FUN_005ca610();
      uint32_t ok = thunk_FUN_005eeb10(pv);
      if ((char)ok == 0) {
        if (pv != nullptr) {
          FUN_005ca3d0();
          operator_delete(pv);
          ok = extraout_EAX;
        }
        return ok & 0xffffff00u;
      }
    }
  }
  if (*reinterpret_cast<void**>(param1 + 0x38) != pv) {
    FUN_005ca660(*reinterpret_cast<void**>(param1 + 0x38));
  }
  int arg = param2;
  *reinterpret_cast<void**>(param1 + 0x38) = pv;
  if (*reinterpret_cast<int**>(base + 0xc) == nullptr) {
    uint32_t* cur = *reinterpret_cast<uint32_t**>(param1 + 0x3c);
    if (cur != nullptr) {
      int* rc = reinterpret_cast<int*>(cur + 1);
      *rc = *rc + -1;
      if (*rc == 0) {
        using Fn = void(__cdecl*)(int);
        auto** vptr = reinterpret_cast<Fn**>(cur);
        (*vptr)(1);
      }
      *reinterpret_cast<uint32_t*>(param1 + 0x3c) = 0;
    }
  } else {
    int vtbl = **reinterpret_cast<int**>(base + 0xc);
    uint32_t val = FUN_005be890(param2);
    using Get = uint32_t*(__cdecl*)(uint32_t);
    uint32_t* next = (uint32_t*)(*(Get*)(vtbl + 0xc))(val);
    uint32_t* cur = *reinterpret_cast<uint32_t**>(param1 + 0x3c);
    if (cur != next) {
      if (cur != nullptr) {
        int* rc = reinterpret_cast<int*>(cur + 1);
        *rc = *rc + -1;
        if (*rc == 0) {
          using Fn = void(__cdecl*)(int);
          auto** vptr = reinterpret_cast<Fn**>(cur);
          (*vptr)(1);
        }
      }
      *reinterpret_cast<uint32_t**>(param1 + 0x3c) = next;
      if (next != nullptr) next[1] = next[1] + 1;
    }
  }
  if (*reinterpret_cast<int**>(base + 0x10) == nullptr) {
    uint32_t* cur = *reinterpret_cast<uint32_t**>(param1 + 0x50);
    if (cur != nullptr) {
      int* rc = reinterpret_cast<int*>(cur + 1);
      *rc = *rc + -1;
      if (*rc == 0) {
        using Fn = void(__cdecl*)(int);
        auto** vptr = reinterpret_cast<Fn**>(cur);
        (*vptr)(1);
      }
      *reinterpret_cast<uint32_t*>(param1 + 0x50) = 0;
    }
  } else {
    int vtbl = **reinterpret_cast<int**>(base + 0x10);
    uint32_t val = FUN_005be890(arg);
    using Get = uint32_t*(__cdecl*)(uint32_t);
    uint32_t* next = (uint32_t*)(*(Get*)(vtbl + 0x10))(val);
    uint32_t* cur = *reinterpret_cast<uint32_t**>(param1 + 0x50);
    if (cur != next) {
      if (cur != nullptr) {
        int* rc = reinterpret_cast<int*>(cur + 1);
        *rc = *rc + -1;
        if (*rc == 0) {
          using Fn = void(__cdecl*)(int);
          auto** vptr = reinterpret_cast<Fn**>(cur);
          (*vptr)(1);
        }
      }
      *reinterpret_cast<uint32_t**>(param1 + 0x50) = next;
      if (next != nullptr) next[1] = next[1] + 1;
    }
  }
  FUN_005beae0(*reinterpret_cast<uint32_t*>(base + 0x30));
  FUN_005beb50(*reinterpret_cast<uint32_t*>(base + 0x34));
  FUN_005bebc0(*reinterpret_cast<uint32_t*>(base + 0x38));
  FUN_005be990(*reinterpret_cast<uint32_t*>(base + 0x1c));
  FUN_005bea00(*reinterpret_cast<uint32_t*>(base + 0x20));
  FUN_005bea70(*reinterpret_cast<uint32_t*>(base + 0x24));
  *reinterpret_cast<uint8_t*>(param1 + 100) = *reinterpret_cast<uint8_t*>(base + 0x3c);
  uint32_t count = *reinterpret_cast<uint32_t*>(base + 0x4c);
  uint32_t ret = count;
  if (DAT_00717c6c < count) {
    return ret & 0xffffff00u;
  }
  uint32_t idx = 0;
  if (count != 0) {
    do {
      if (*reinterpret_cast<int*>(*reinterpret_cast<uint32_t*>(base + 0x44) + idx * 4) != 0) {
        int obj = *reinterpret_cast<int*>(*reinterpret_cast<uint32_t*>(param1 + 0x24) + idx * 4);
        if (obj != 0) {
          *reinterpret_cast<int*>(obj + 100) = *reinterpret_cast<int*>(obj + 100) + 1;
        }
        if (obj == 0) {
          int* slot = (int*)FUN_005cb870(&param2);
          int got = *slot;
          if (got != 0) {
            *reinterpret_cast<int*>(got + 100) = *reinterpret_cast<int*>(got + 100) + 1;
            obj = got;
          }
          if (param2 != 0) {
            int rc = *reinterpret_cast<int*>(param2 + 100) + -1;
            *reinterpret_cast<int*>(param2 + 100) = rc;
            if (rc == 0) FUN_005cb7c0();
          }
        }
        uint32_t ok2 = thunk_FUN_005f0740(obj);
        if ((char)ok2 == 0) {
          if (obj != 0) {
            int* rc = reinterpret_cast<int*>(obj + 100);
            *rc = *rc + -1;
            if (*rc == 0) FUN_005cb7c0();
          }
          return ret & 0xffffff00u;
        }
        FUN_005bf1f0(idx, obj);
        if (obj != 0) {
          int* rc = reinterpret_cast<int*>(obj + 100);
          *rc = *rc + -1;
          if (*rc == 0) FUN_005cb7c0();
        }
      }
      idx = idx + 1;
    } while (idx < count);
  }
  return (uint32_t)(count & 0xFFFFFF00u) | 1u;
}

// 0x5ed9e0 — observed shape
bool FUN_005ed9e0(void* self, int param1) {
  uint8_t* base = static_cast<uint8_t*>(self);
  uint32_t u = (uint32_t)param1;
  if (FUN_006b5020(param1, nullptr) == 0) return false;
  if (0x10005 < DAT_007187cc) {
    int local = 0;
    if (FUN_006b5090(u, &local) == 0) return false;
    if (local == 0) {
      uint32_t* cur = *reinterpret_cast<uint32_t**>(base + 4);
      if (cur != nullptr) {
        int* rc = reinterpret_cast<int*>(cur + 1);
        *rc = *rc + -1;
        if (*rc == 0) {
          using Fn = void(__cdecl*)(int);
          auto** vptr = reinterpret_cast<Fn**>(cur);
          (*vptr)(1);
        }
        *reinterpret_cast<uint32_t*>(base + 4) = 0;
      }
    } else {
      int alloc = FUN_00533c78(0x1c);
      uint32_t made = (alloc == 0) ? 0 : FUN_005edf90();
      FUN_0051ac30(made);
      using Iface = uint8_t(__cdecl*)(uint32_t);
      uint8_t ok = (**(Iface*)(**(int**)(base + 4) + 8))(u);
      if (ok == 0) return false;
    }
  }
  uint32_t* slot = reinterpret_cast<uint32_t*>(base + 8);
  void* old = reinterpret_cast<void*>(*slot);
  if (old != nullptr) {
    FUN_005ea3c0();
    operator_delete(old);
  }
  *slot = 0;
  if (FUN_005e8960(u, slot) != 0 && FUN_005ed4f0(u) != 0) {
    if (*reinterpret_cast<uint32_t**>(base + 0xc) != nullptr) {
      using Fn = void(__cdecl*)(int);
      auto** vptr = reinterpret_cast<Fn**>(**(uint32_t**)(base + 0xc));
      (*vptr)(1);
    }
    *reinterpret_cast<uint32_t*>(base + 0xc) = 0;
    if (FUN_005e8880(u, reinterpret_cast<uint32_t*>(base + 0xc)) != 0 && FUN_005ed5b0(u) != 0) {
      if (*reinterpret_cast<uint32_t**>(base + 0x10) != nullptr) {
        using Fn = void(__cdecl*)(int);
        auto** vptr = reinterpret_cast<Fn**>(**(uint32_t**)(base + 0x10));
        (*vptr)(1);
      }
      *reinterpret_cast<uint32_t*>(base + 0x10) = 0;
      if (FUN_005e8880(u, reinterpret_cast<uint32_t*>(base + 0x10)) != 0) {
        int n = 0;
        if (FUN_006b5090(u, &n) != 0) {
          *reinterpret_cast<bool*>(base + 0x3c) = (n != 0);
          return FUN_005ed660(u) != 0;
        }
      }
    }
  }
  return false;
}

// 0x5edba0 — observed shape
void FUN_005edba0(void* self) {
  uint32_t* fields = static_cast<uint32_t*>(self);
  uint32_t* node = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(fields[1]));
  while (node != nullptr) {
    uint32_t* next = reinterpret_cast<uint32_t*>(*node);
    using Fn = void(__cdecl*)(uint32_t*);
    auto** vptr = reinterpret_cast<Fn**>(static_cast<uintptr_t>(fields[0]));
    (*vptr)(node);
    node = next;
  }
  fields[3] = 0;
  fields[1] = 0;
  fields[2] = 0;
}

// 0x5edbe0 — observed shape
void FUN_005edbe0(void* self) {
  static_cast<uint32_t*>(self)[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006c9fd8);
}

// 0x5edbf0 — observed shape
void FUN_005edbf0(void* self) {
  static_cast<uint32_t*>(self)[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fe4);
  FUN_005edba0();
  static_cast<uint32_t*>(self)[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006c9fd8);
}

// 0x5edc60 — observed shape
void FUN_005edc60(void* self, uint8_t param1) {
  FUN_005edbf0();
  if ((param1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5edd10 — observed shape
void FUN_005edd10(void* self, uint32_t param1) {
  FUN_005ebdf0();
  uint32_t* fields = static_cast<uint32_t*>(self);
  fields[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006ca088);
  fields[0x17] = 0;
  FUN_005c9b90(fields + 0x17, param1);
}

// 0x5edd90 — observed shape
void FUN_005edd90(void* self) {
  uint32_t* fields = static_cast<uint32_t*>(self);
  fields[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006ca088);
  operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[0x17])));
  FUN_005ea870();
}

// 0x5eddb0 — observed shape
void FUN_005eddb0(void* self) {
  uint32_t* fields = static_cast<uint32_t*>(self);
  fields[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006ca0b0);
  uint32_t* head = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(fields[4]));
  fields[2] = reinterpret_cast<uint32_t>(head);
  if (head != nullptr) {
    fields[2] = *head;
    uint32_t* node = reinterpret_cast<uint32_t*>(head[2]);
    while (node != nullptr) {
      using Fn = void(__cdecl*)(int);
      auto** vptr = reinterpret_cast<Fn**>(node);
      (*vptr)(1);
      node = reinterpret_cast<uint32_t*>(fields[2]);
      if (node == nullptr) break;
      fields[2] = *node;
    }
  }
  FUN_005edba0();
  fields[3] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fe4);
  FUN_005edba0();
  fields[3] = reinterpret_cast<uint32_t>(&PTR_LAB_006c9fd8);
  fields[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006fd148);
  DAT_00727444 = DAT_00727444 + 0xFFFFFFFFu;
}

// 0x5edf90 — observed shape
void FUN_005edf90(void* self) {
  uint32_t* fields = static_cast<uint32_t*>(self);
  fields[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006fd148);
  fields[1] = 0;
  DAT_00727444 = DAT_00727444 + 1;
  fields[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006ca0b0);
  fields[6] = 0;
  fields[4] = 0;
  fields[5] = 0;
  fields[3] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fe4);
  fields[2] = 0;
  FUN_005edba0();
}
