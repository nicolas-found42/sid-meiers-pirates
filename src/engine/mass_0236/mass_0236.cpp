// Reconstruction batch mass_0236 — Sid Meier's Pirates! (2004), PE32 i386
// Addresses: 0x5e0480..0x5e1070 (20 functions)
// Source: Ghidra 12.2 pseudocode, one corpus file per function.
// Family: hash-container base/derived teardowns, a shader-library manager with
// lazy child object creation, and this-call helper chains.  Original code is
// __thiscall; every recovered register receiver is passed explicitly as `self`.
// MSVC SEH bookkeeping (ExceptionList save/restore plus the local state word
// and the LAB_xxxx handlers) is retained only as the plain ExceptionList save,
// because the state word carries no program data.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// --- referenced helpers -----------------------------------------------------
extern void* ExceptionList;
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void* thunk_FUN_00533c78(std::size_t size);

extern void FUN_005edba0(void* self);           // base sub-object constructor
extern void FUN_005e1490(void* self);           // clear every hash bucket chain
extern void FUN_005e0330(void* self);           // hash-container base destructor
extern void FUN_005c9dc0(void* self);           // base teardown (this-call)
extern void FUN_005e2120(void* self);           // shader/effect item teardown
extern void* FUN_00535540(void** cursor);       // next entry of a list cursor
extern uint8_t FUN_005bd960(int param_1, void* out);
extern int FUN_005e0b30(void);
extern void* FUN_005e0880(void);                // shader-library constructor
extern void FUN_005e2980(void);                 // one-time global library init
extern bool FUN_005e2ce0(void* self, uint32_t param_1, uint32_t param_2);
extern int* FUN_005e2340(void* self);           // iterator: first element
extern int* FUN_005e1c00(void* self);           // iterator: next element
extern int FUN_005e22f0(void* self);            // second iterator: first
extern int FUN_005e1aa0(void* self);            // second iterator: next
extern uint32_t FUN_006b3460(void* item);
extern void FUN_00545310(uint32_t value, int* list);
extern uint32_t FUN_005c9a50(const char* fmt, ...);
extern void FUN_005aead0(void* table, int* cursor, int* out1, int* out2);
extern void FUN_005e1450(void* self);
extern void FUN_005e1470(void* self);
extern void FUN_005e1ca0(void* self);
extern void* FUN_006b33a0(void);                // construct over fresh block
extern void FUN_0051ac30(void* object);

// --- referenced globals / vtables -------------------------------------------
extern void* PTR_FUN_006c9424;
extern void* PTR_LAB_006c93fc;
extern void* PTR_FUN_006c944c;
extern void* PTR_FUN_006c9430;
extern void* PTR_FUN_006c9408;
extern void* PTR_FUN_006c9468;
extern void* PTR_FUN_006c9554;
extern void* PTR_FUN_006c95d4;
extern void* PTR_FUN_006c95f0;

typedef void  (*VirtSet)(void* self, uint32_t value);
typedef uint32_t (*VirtGet)(void* self);
typedef void  (*VirtDel)(void* self, int freeFlag);
typedef void  (*VirtInit)(void* self, uint32_t value);
typedef void* (*VirtNew)(void* self);
typedef int   (*VirtHash)(void* self, uint32_t key);

// 0x5e0480 — observed shape: two-stage base construction; install
// PTR_FUN_006c9424, run the base constructor, then rebind to PTR_LAB_006c93fc.
void FUN_005e0480(void* self)
{
  void* savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;

  *reinterpret_cast<void**>(self) = &PTR_FUN_006c9424;
  FUN_005edba0(self);
  *reinterpret_cast<void**>(self) = &PTR_LAB_006c93fc;

  ExceptionList = savedExceptionList;
}

// 0x5e04d0 — observed shape: hash-container destructor; frees each bucket
// chain payload through operator_delete__, then unwinds two base vtables and
// releases the bucket array at +8.  Flag at +0x10 gates the chain walk.
void FUN_005e04d0(void* self)
{
  uint32_t* ecx = reinterpret_cast<uint32_t*>(self);
  void* savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;

  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c944c;
  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(ecx) + 0x10) != '\0' && ecx[1] != 0) {
    uint32_t* buckets = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(ecx[2]));
    for (uint32_t i = 0; i < ecx[1]; ++i) {
      uint32_t* node = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(buckets[i]));
      while (node != nullptr) {
        uint32_t* payload = node + 1;
        node = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*node));
        operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(*payload)));
      }
    }
  }

  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c9430;
  FUN_005e1490(self);
  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c9408;
  FUN_005e1490(self);
  operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(ecx[2])));

  ExceptionList = savedExceptionList;
}

// 0x5e04e0 — observed shape: forward the key through vtable slot +0x10, then
// register it in the lookup table; always reports 0.
uint32_t FUN_005e04e0(void* self, uint32_t param_1)
{
  VirtInit init = *reinterpret_cast<VirtInit*>(
      static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(self)) + 0x10);
  uint32_t out = 0;

  init(self, param_1);
  FUN_005bd960(static_cast<int>(param_1), &out);
  return 0;
}

// 0x5e0530 — observed shape: linear search of the singly linked list rooted at
// self+0x1c; each node's third word points at an entry whose first int is the
// key.  Returns the entry or null.
int* FUN_005e0530(void* self, int param_1)
{
  uint32_t* node = *reinterpret_cast<uint32_t**>(
      reinterpret_cast<uint8_t*>(self) + 0x1c);

  for (;;) {
    if (node == nullptr) return nullptr;
    uint32_t* entryRef = node + 2;
    node = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*node));
    if (*reinterpret_cast<int*>(static_cast<uintptr_t>(*entryRef)) == param_1) {
      return reinterpret_cast<int*>(static_cast<uintptr_t>(*entryRef));
    }
  }
}

// 0x5e0560 — observed shape: allocate a three-word node through vtable slot
// +4, store the key value plus the previous tail, then link at the tail
// (self+4 head, self+8 tail, self+0xc count).
void FUN_005e0560(void* self, uint32_t* param_1)
{
  uint32_t* ecx = reinterpret_cast<uint32_t*>(self);
  VirtNew allocNode = *reinterpret_cast<VirtNew*>(
      static_cast<uintptr_t>(ecx[0]) + 4);
  uint32_t* node = reinterpret_cast<uint32_t*>(allocNode(self));

  node[2] = *param_1;
  node[0] = 0;
  node[1] = ecx[2];
  if (ecx[2] == 0) {
    ecx[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));
    ecx[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));
    ecx[3] = ecx[3] + 1;
    return;
  }
  *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(ecx[2])) =
      static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));
  ecx[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));
  ecx[3] = ecx[3] + 1;
}

// 0x5e05a0 — observed shape: deleting destructor thunk for 0x5e0480.
void FUN_005e05a0(void* self, uint8_t param_1)
{
  FUN_005e0480(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5e05c0 — observed shape: shader-library destructor; drains the list at
// +0x1c (teardown then free of every entry), destroys the hash base, unwinds
// the +0x18 sub-object through its two vtables, then the outer base.
void FUN_005e05c0(void* self)
{
  uint32_t* ecx = reinterpret_cast<uint32_t*>(self);
  void* savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;

  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c9468;

  void* cursor[2];
  cursor[0] = reinterpret_cast<void*>(static_cast<uintptr_t>(ecx[7]));  // +0x1c
  while (cursor[0] != nullptr) {
    void* item = FUN_00535540(cursor);
    if (item != nullptr) {
      FUN_005e2120(item);          // receiver implicit in the listing (ECX)
      operator_delete(item);
    }
  }

  FUN_005e0330(self);

  void** sub = reinterpret_cast<void**>(ecx + 6);                       // +0x18
  *sub = &PTR_FUN_006c9424;
  cursor[0] = sub;
  FUN_005edba0(sub);
  *sub = &PTR_LAB_006c93fc;
  FUN_005c9dc0(self);              // receiver implicit in the listing (ECX)

  ExceptionList = savedExceptionList;
}

// 0x5e0680 — observed shape: register a shader file.  Rejects a null entry,
// rejects a duplicate key with a log line, otherwise appends to the +0x1c list,
// lazily builds the 0x4c-byte child at +0x14, copies seven values per child
// into the sink object at self+0x50 (pairs through +0x44/+0x48/+0x4c, one
// through +0x50), then drains the second collection.
uint32_t FUN_005e0680(void* self, int* param_1)
{
  uint8_t* s = reinterpret_cast<uint8_t*>(self);
  int* piVar3 = param_1;
  void* savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;

  if (param_1 == nullptr) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(ExceptionList)) & 0xffffff00u;
  }

  uint32_t* node = *reinterpret_cast<uint32_t**>(s + 0x1c);
  for (;;) {
    if (node == nullptr) {
      FUN_005e0560(self, reinterpret_cast<uint32_t*>(&param_1));  // receiver implicit (ECX)

      uint32_t* child = reinterpret_cast<uint32_t*>(s + 0x14);
      if (*reinterpret_cast<int*>(s + 0x14) == 0) {
        int mem = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(0x4c)));
        uint32_t object;
        if (mem == 0) {
          object = 0;
        } else {
          // the fresh block is the implicit receiver of this construction call
          object = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_006b33a0()));
        }
        FUN_0051ac30(reinterpret_cast<void*>(static_cast<uintptr_t>(object)));
      }

      uint32_t objectPtr = *child;
      uint32_t sink = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(objectPtr));
      void* sinkSelf = reinterpret_cast<void*>(static_cast<uintptr_t>(objectPtr));

      int* element = FUN_005e2340(self);
      while (element != nullptr) {
        FUN_006b3460(element);

        VirtGet get = *reinterpret_cast<VirtGet*>(
            static_cast<uintptr_t>(*element) + 0x1c);
        VirtSet set = *reinterpret_cast<VirtSet*>(static_cast<uintptr_t>(sink) + 0x44);
        set(sinkSelf, get(element));

        get = *reinterpret_cast<VirtGet*>(static_cast<uintptr_t>(*element) + 0x20);
        set = *reinterpret_cast<VirtSet*>(static_cast<uintptr_t>(sink) + 0x44);
        set(sinkSelf, get(element));

        get = *reinterpret_cast<VirtGet*>(static_cast<uintptr_t>(*element) + 0x24);
        set = *reinterpret_cast<VirtSet*>(static_cast<uintptr_t>(sink) + 0x48);
        set(sinkSelf, get(element));

        get = *reinterpret_cast<VirtGet*>(static_cast<uintptr_t>(*element) + 0x28);
        set = *reinterpret_cast<VirtSet*>(static_cast<uintptr_t>(sink) + 0x48);
        set(sinkSelf, get(element));

        get = *reinterpret_cast<VirtGet*>(static_cast<uintptr_t>(*element) + 0x2c);
        set = *reinterpret_cast<VirtSet*>(static_cast<uintptr_t>(sink) + 0x4c);
        set(sinkSelf, get(element));

        get = *reinterpret_cast<VirtGet*>(static_cast<uintptr_t>(*element) + 0x30);
        set = *reinterpret_cast<VirtSet*>(static_cast<uintptr_t>(sink) + 0x4c);
        set(sinkSelf, get(element));

        get = *reinterpret_cast<VirtGet*>(static_cast<uintptr_t>(*element) + 0x34);
        set = *reinterpret_cast<VirtSet*>(static_cast<uintptr_t>(sink) + 0x50);
        set(sinkSelf, get(element));

        piVar3 = param_1;
        element = FUN_005e1c00(self);
      }

      int second = FUN_005e22f0(self);
      while (second != 0) {
        uint32_t* sub = *reinterpret_cast<uint32_t**>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(second)) + 0x34);
        VirtGet get = *reinterpret_cast<VirtGet*>(
            static_cast<uintptr_t>(*sub) + 4);
        uint32_t value = get(sub);
        FUN_00545310(value, piVar3);
        second = FUN_005e1aa0(self);
      }

      ExceptionList = savedExceptionList;
      return 1;
    }

    uint32_t* entryRef = node + 2;
    node = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*node));
    if (*reinterpret_cast<int*>(static_cast<uintptr_t>(*entryRef)) == *param_1) break;
  }

  uint32_t uVar6 = FUN_005c9a50("File %s already in list??\n", *param_1);
  ExceptionList = savedExceptionList;
  return uVar6 & 0xffffff00;
}

// 0x5e0840 — observed shape: deleting destructor thunk for 0x5e05c0.
void FUN_005e0840(void* self, uint8_t param_1)
{
  FUN_005e05c0(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5e0860 — observed shape: deleting destructor thunk for 0x5e04d0.
void FUN_005e0860(void* self, uint8_t param_1)
{
  FUN_005e04d0(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5e0920 — observed shape: factory.  With a null name it first forces the
// global library, allocates a 0x3c-byte shader object, binds the name through
// vtable slot +0x10, ensures the singleton, tries the key insert, and back-
// deletes the object (slot 0 with flag 1) if the insert fails.
int* FUN_005e0920(int param_1, uint32_t* param_2, uint32_t param_3)
{
  void* savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;

  if (param_1 == 0) {
    if (FUN_005e0b30() == 0) {
      ExceptionList = savedExceptionList;
      return nullptr;
    }
  }

  int mem = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(0x3c)));
  int* object;
  if (mem == 0) {
    object = nullptr;
  } else {
    object = reinterpret_cast<int*>(FUN_005e0880());
  }

  VirtInit init = *reinterpret_cast<VirtInit*>(
      static_cast<uintptr_t>(*object) + 0x10);
  init(object, static_cast<uint32_t>(param_1));

  uint32_t key = *param_2;
  FUN_005e2980();

  bool ok = FUN_005e2ce0(object, key, param_3);
  if (!ok) {
    VirtDel dtor = *reinterpret_cast<VirtDel*>(static_cast<uintptr_t>(*object));
    dtor(object, 1);
    object = nullptr;
  }

  ExceptionList = savedExceptionList;
  return object;
}

// 0x5e0ce0 — observed shape: lookup returning 0 on failure, otherwise the
// value written by FUN_005bd960 (carried unconditionally through the mask).
uint32_t FUN_005e0ce0(int param_1)
{
  uint32_t local_4 = 0;
  uint8_t found = FUN_005bd960(param_1, &local_4);
  return -static_cast<uint32_t>(found != '\0') & local_4;
}

// 0x5e0d70 — observed shape: select entry at self+8; when it changes, walk the
// whole hash at self+4 and run the per-entry teardown FUN_005e1450.
void FUN_005e0d70(void* self, int param_1)
{
  uint8_t* s = reinterpret_cast<uint8_t*>(self);
  int saved = param_1;

  if (*reinterpret_cast<int*>(s + 8) != param_1) {
    uint32_t* table = *reinterpret_cast<uint32_t**>(s + 4);
    uint32_t count = table[1];
    int cursor = 0;
    if (count != 0) {
      uint32_t* buckets = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(table[2]));
      for (uint32_t i = 0; i < count; ++i) {
        if (buckets[i] != 0) {
          cursor = static_cast<int>(buckets[i]);
          break;
        }
      }
    }
    int local_4 = 0;
    int local_8 = 0;
    while (cursor != 0) {
      FUN_005aead0(table, &cursor, &local_4, &local_8);
      FUN_005e1450(self);
    }
    *reinterpret_cast<int*>(s + 8) = saved;
  }
}

// 0x5e0df0 — observed shape: same as 0x5e0d70 for the selection at self+0xc,
// using the teardown FUN_005e1470.
void FUN_005e0df0(void* self, int param_1)
{
  uint8_t* s = reinterpret_cast<uint8_t*>(self);
  int saved = param_1;

  if (*reinterpret_cast<int*>(s + 0xc) != param_1) {
    uint32_t* table = *reinterpret_cast<uint32_t**>(s + 4);
    uint32_t count = table[1];
    int cursor = 0;
    if (count != 0) {
      uint32_t* buckets = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(table[2]));
      for (uint32_t i = 0; i < count; ++i) {
        if (buckets[i] != 0) {
          cursor = static_cast<int>(buckets[i]);
          break;
        }
      }
    }
    int local_4 = 0;
    int local_8 = 0;
    while (cursor != 0) {
      FUN_005aead0(table, &cursor, &local_4, &local_8);
      FUN_005e1470(self);
    }
    *reinterpret_cast<int*>(s + 0xc) = saved;
  }
}

// 0x5e0e70 — observed shape: walk the hash at self+4 bucket by bucket; for
// every entry run FUN_005e1ca0, then advance to the next entry using the hash
// function in vtable slot +4 of the container.
void FUN_005e0e70(void* self)
{
  uint8_t* s = reinterpret_cast<uint8_t*>(self);
  uint32_t* table = *reinterpret_cast<uint32_t**>(s + 4);
  uint32_t count = table[1];
  uint32_t* entry = nullptr;

  if (count != 0) {
    uint32_t* buckets = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(table[2]));
    for (uint32_t i = 0; i < count; ++i) {
      if (buckets[i] != 0) {
        entry = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(buckets[i]));
        break;
      }
    }
  }

  for (;;) {
    if (entry == nullptr) return;

    uint32_t* next = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*entry));
    uint32_t* container = *reinterpret_cast<uint32_t**>(s + 4);

    if (next == nullptr) {
      VirtHash hash = *reinterpret_cast<VirtHash*>(
          static_cast<uintptr_t>(container[0]) + 4);
      int bucketIndex = hash(container, entry[1]);
      uint32_t uVar5 = static_cast<uint32_t>(bucketIndex) + 1;
      if (uVar5 < container[1]) {
        uint32_t* slot = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(container[2])) + uVar5;
        while (uVar5 < container[1]) {
          next = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*slot));
          if (next != nullptr) break;
          uVar5 = uVar5 + 1;
          slot = slot + 1;
        }
      }
    }

    FUN_005e1ca0(self);
    entry = next;
  }
}

// 0x5e0ef0 — observed shape: hash-container destructor; install
// PTR_FUN_006c9554, clear the buckets, release the bucket array.
void FUN_005e0ef0(void* self)
{
  uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c9554;
  FUN_005e1490(self);
  operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(ecx[2])));
}

// 0x5e0f10 — observed shape: derived hash-container destructor; unwind
// PTR_FUN_006c95d4 then PTR_FUN_006c9554, clearing each level and releasing the
// bucket array.
void FUN_005e0f10(void* self)
{
  uint32_t* ecx = reinterpret_cast<uint32_t*>(self);
  void* savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;

  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c95d4;
  FUN_005e1490(self);
  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c9554;
  FUN_005e1490(self);
  operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(ecx[2])));

  ExceptionList = savedExceptionList;
}

// 0x5e0f80 — observed shape: most-derived hash-container destructor; when the
// +0x10 flag is set, free every bucket-chain payload, then unwind the two base
// vtables and release the bucket array.
void FUN_005e0f80(void* self)
{
  uint32_t* ecx = reinterpret_cast<uint32_t*>(self);
  void* savedExceptionList = ExceptionList;
  ExceptionList = &savedExceptionList;

  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c95f0;
  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(ecx) + 0x10) != '\0' && ecx[1] != 0) {
    uint32_t* buckets = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(ecx[2]));
    for (uint32_t i = 0; i < ecx[1]; ++i) {
      uint32_t* node = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(buckets[i]));
      while (node != nullptr) {
        uint32_t* payload = node + 1;
        node = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*node));
        operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(*payload)));
      }
    }
  }

  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c95d4;
  FUN_005e1490(self);
  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c9554;
  FUN_005e1490(self);
  operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(ecx[2])));

  ExceptionList = savedExceptionList;
}

// 0x5e1030 — observed shape: deleting destructor thunk for 0x5e0ef0.
void FUN_005e1030(void* self, uint8_t param_1)
{
  uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

  *reinterpret_cast<void**>(ecx) = &PTR_FUN_006c9554;
  FUN_005e1490(self);
  operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(ecx[2])));
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5e1070 — observed shape: deleting destructor thunk for 0x5e0f10.
void FUN_005e1070(void* self, uint8_t param_1)
{
  FUN_005e0f10(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}
