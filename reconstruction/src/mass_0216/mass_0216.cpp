// Reconstruction batch mass_0216
// Sid Meier's Pirates! (2004), PE32 i386
#include <cstdint>
#include <cstddef>
#include <cstdio>

extern char FUN_005bd960(uint32_t param_1, void* param_2);
extern void FUN_00545310(uint32_t param_1, int* param_2);
extern uint32_t FUN_005477c0(int a, int b, const char* fmt, ...);
extern void FUN_005c9a80(uint32_t param_1, void* p2, void* p3, void* p4, void* p5);
extern int FUN_004fca80(const char* path, int flags);
extern void FUN_005aead0(void* param_1, void* param_2, void* param_3);
extern void FUN_005bfa50(uint32_t param_1);

extern uint32_t DAT_00728de4;
extern char* DAT_00728de8;
extern uint32_t DAT_00728dec;
extern uint32_t DAT_00727444;

// 0x5c87c0 — observed shape
uint32_t FUN_005c87c0(void* self, uint32_t param_1)
{
  char* selfp = (char*)self;
  if (*(int*)(selfp + 0xc) == 0) {
    return 0;
  }
  uint32_t local_4 = 0;
  char cVar1 = FUN_005bd960(param_1, &local_4);
  return -(uint32_t)(cVar1 != '\0') & local_4;
}

// 0x5c8800 — observed shape
void FUN_005c8800(void* self, int* param_1)
{
  char* selfp = (char*)self;
  if ((param_1 != nullptr) && (*(int*)(selfp + 8) != 0)) {
    uint32_t uVar1 = (uint32_t)(*(int(**)(int*))(*(int*)param_1 + 4))(param_1);
    FUN_00545310(uVar1, param_1);
  }
}

// 0x5c8830 — observed shape
void FUN_005c8830(void* self, int* param_1)
{
  char* selfp = (char*)self;
  if ((param_1 != nullptr) && (*(int*)(selfp + 0xc) != 0)) {
    uint32_t uVar1 = (uint32_t)(*(int(**)(int*))(*(int*)param_1 + 4))(param_1);
    FUN_00545310(uVar1, param_1);
  }
}


// 0x5c8860 — observed shape
uint32_t FUN_005c8860(uint32_t param_1, char* param_2)
{
  if (DAT_00728de4 == 0) {
    uint32_t uVar1 = FUN_005477c0(1, 0, "No valid shader program factory\n");
    return uVar1 & 0xffffff00;
  }
  char local_30c[4];
  char local_308[256];
  char local_208[260];
  char local_104[260];
  FUN_005c9a80(param_1, local_30c, local_104, local_208, local_308);
  if ((DAT_00728de8 == nullptr) || (*DAT_00728de8 == '\0')) {
    uint32_t uVar1 = FUN_005477c0(1, 0, "Invalid or no shader program directory\n");
    return uVar1 & 0xffffff00;
  }
  char* pcVar4 = DAT_00728de8;
  char* pcVar2 = nullptr;
  do {
    pcVar2 = pcVar4;
    pcVar4 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  const char* fmt = nullptr;
  if (pcVar2[-1] != '/') {
    pcVar4 = DAT_00728de8;
    do {
      pcVar2 = pcVar4;
      pcVar4 = pcVar2 + 1;
    } while (*pcVar2 != '\0');
    if (pcVar2[-1] != '\\') {
      fmt = "%s\\%s%s";
      goto LAB_005c891e;
    }
  }
  fmt = "%s%s%s";
LAB_005c891e:
  std::sprintf(param_2, fmt, DAT_00728de8, local_208, local_308);
  int iVar3 = FUN_004fca80(param_2, 0);
  if (iVar3 == 0) {
    return 1;
  }
  uint32_t uVar1 = FUN_005477c0(1, 0, "Shader program file not found %s\n", (char*)(uintptr_t)param_1);
  return uVar1 & 0xffffff00;
}

// 0x5c8980 — observed shape
void FUN_005c8980(int param_1)
{
  if (DAT_00728dec != 0) {
    uint32_t uVar1 = 0;
    int local_4 = 0;
    if (*(uint32_t*)(DAT_00728dec + 4) != 0) {
      int* piVar2 = *(int**)(DAT_00728dec + 8);
      do {
        if (*piVar2 != 0) {
          local_4 = (*(int**)(DAT_00728dec + 8))[uVar1];
          goto joined_r0x005c89b4;
        }
        uVar1 = uVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar1 < *(uint32_t*)(DAT_00728dec + 4));
    }
    local_4 = 0;
joined_r0x005c89b4:
    while (local_4 != 0) {
      uint32_t local_8 = 0;
      int local_c = 0;
      FUN_005aead0(&local_4, &local_8, &local_c);
      if (param_1 == local_c) {
        FUN_005bfa50(local_8);
      }
    }
  }
}
// 0x5c8a10 — observed shape
uint32_t FUN_005c8a10(char* param_1)
{
  if (((DAT_00728dec == 0) || (param_1 == nullptr)) || (*param_1 == '\0')) {
    return 0;
  }
  char local_100[256];
  uint32_t local_104 = 0;
  FUN_005c9b30(param_1, local_100);
  char* pcVar3 = local_100 + 1;
  if (local_100[1] == '\0') {
    pcVar3 = param_1;
  }
  uint32_t uVar4 = 0;
  do {
    int iVar2 = tolower((int)(local_100 + uVar4)[(int)(intptr_t)pcVar3 - (int)(intptr_t)local_100]);
    local_100[uVar4] = (char)iVar2;
    if ((char)iVar2 == '\0') break;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  local_104 = 0;
  char cVar1 = FUN_005bd960((uint32_t)(intptr_t)local_100, &local_104);
  return -(uint32_t)(cVar1 != '\0') & local_104;
}

// 0x5c8ad0 — observed shape
void FUN_005c8ad0(void)
{
  operator_delete__(DAT_00728de8);
  DAT_00728de8 = nullptr;
  FUN_005e1490();
  if (DAT_00728dec != 0) {
    (**(void(**)(int))(uint32_t)DAT_00728dec)(1);
  }
  DAT_00728dec = 0;
}

// 0x5c8b10 — observed shape
void FUN_005c8b10(void* self)
{
  uint32_t* ptr = (uint32_t*)self;
  *ptr = (uint32_t)((void**)&PTR_FUN_006c7828);
  if ((*(char*)((char*)self + 16) != '\0') && (ptr[1] != 0)) {
    uint32_t uVar3 = 0;
    do {
      uint32_t* puVar2 = *(uint32_t**)((uint32_t*)ptr[2] + uVar3);
      while (puVar2 != nullptr) {
        uint32_t* puVar1 = puVar2 + 1;
        puVar2 = (uint32_t*)*puVar2;
        operator_delete__((void*)*puVar1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint32_t)ptr[1]);
  }
  *ptr = (uint32_t)((void**)&PTR_FUN_006c77d4);
  FUN_005e1490();
  *ptr = (uint32_t)((void**)&PTR_FUN_006c76fc);
  FUN_005e1490();
  operator_delete__((void*)ptr[2]);
}

// 0x5c8b90 — observed shape
void FUN_005c8b90(void* self)
{
  uint32_t* ptr = (uint32_t*)self;
  *ptr = (uint32_t)((void**)&PTR_FUN_006c7844);
  if ((*(char*)((char*)self + 16) != '\0') && (ptr[1] != 0)) {
    uint32_t uVar3 = 0;
    do {
      uint32_t* puVar2 = *(uint32_t**)((uint32_t*)ptr[2] + uVar3);
      while (puVar2 != nullptr) {
        uint32_t* puVar1 = puVar2 + 1;
        puVar2 = (uint32_t*)*puVar2;
        operator_delete__((void*)*puVar1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint32_t)ptr[1]);
  }
  *ptr = (uint32_t)((void**)&PTR_FUN_006c77f0);
  FUN_005e1490();
  *ptr = (uint32_t)((void**)&PTR_FUN_006c7718);
  FUN_005e1490();
  operator_delete__((void*)ptr[2]);
}

// 0x5c8c50 — observed shape
void FUN_005c8c50(void* self)
{
  uint32_t* ptr = (uint32_t*)self;
  *ptr = (uint32_t)((void**)&PTR_FUN_006c7860);
  if ((*(char*)((char*)self + 16) != '\0') && (ptr[1] != 0)) {
    uint32_t uVar3 = 0;
    do {
      uint32_t* puVar2 = *(uint32_t**)((uint32_t*)ptr[2] + uVar3);
      while (puVar2 != nullptr) {
        uint32_t* puVar1 = puVar2 + 1;
        puVar2 = (uint32_t*)*puVar2;
        operator_delete__((void*)*puVar1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint32_t)ptr[1]);
  }
  *ptr = (uint32_t)((void**)&PTR_FUN_006c780c);
  FUN_005e1490();
  *ptr = (uint32_t)((void**)&PTR_FUN_006c7734);
  FUN_005e1490();
  operator_delete__((void*)ptr[2]);
}
// 0x5c8ec0 — observed shape
int FUN_005c8ec0(char* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7)
{
  if (DAT_00728de4 == 0) {
    return 0;
  }
  if ((param_1 == nullptr) || (*param_1 == '\0')) {
    return 0;
  }
  int iVar1 = FUN_005c8780(param_2);
  if (iVar1 == 0) {
    int* piVar2 = (int*)FUN_005c8a10(param_1);
    iVar1 = 0;
    if (piVar2 != nullptr) {
      iVar1 = (*(int(**)(char*,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t))(*(int*)piVar2 + 0xc))(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
      FUN_005c8800(nullptr, (int*)iVar1);
      return iVar1;
    }
  }
  return iVar1;
}

// 0x5c8f40 — observed shape
int FUN_005c8f40(char* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
  if (DAT_00728de4 == 0) {
    return 0;
  }
  if ((param_1 == nullptr) || (*param_1 == '\0')) {
    return 0;
  }
  int iVar1 = FUN_005c87c0(nullptr, param_2);
  if (iVar1 == 0) {
    int* piVar2 = (int*)FUN_005c8a10(param_1);
    iVar1 = 0;
    if (piVar2 != nullptr) {
      iVar1 = (*(int(**)(char*,uint32_t,uint32_t,uint32_t))(*(int*)piVar2 + 0x14))(param_1, param_2, param_3, param_4);
      FUN_005c8830(nullptr, (int*)iVar1);
      return iVar1;
    }
  }
  return iVar1;
}

// 0x5c8fb0 — observed shape
uint32_t FUN_005c8fb0(int* param_1)
{
  if ((DAT_00728de4 != 0) && (param_1 != nullptr)) {
    int iVar1 = (*(int(**)())(*(int*)param_1 + 0x38))();
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = (*(int(**)())(*(int*)param_1 + 0xc))();
    if (iVar1 != 0) {
      int* piVar2 = (int*)FUN_005c8a10((char*)iVar1);
      if (piVar2 != nullptr) {
        uint32_t uVar3 = (*(uint32_t(**)(int*))(*(int*)piVar2 + 0x1c))(param_1);
        return uVar3;
      }
    }
  }
  return 0;
}

// 0x5c9000 — observed shape
uint32_t FUN_005c9000(int* param_1)
{
  if ((DAT_00728de4 != 0) && (param_1 != nullptr)) {
    int iVar1 = (*(int(**)())(*(int*)param_1 + 0x30))();
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = (*(int(**)())(*(int*)param_1 + 0xc))();
    if (iVar1 != 0) {
      int* piVar2 = (int*)FUN_005c8a10((char*)iVar1);
      if (piVar2 != nullptr) {
        uint32_t uVar3 = (*(uint32_t(**)(int*))(*(int*)piVar2 + 0x20))(param_1);
        return uVar3;
      }
    }
  }
  return 0;
}

// 0x5c9050 — observed shape
void FUN_005c9050(int* param_1)
{
  if ((DAT_00728de4 != 0) && (param_1 != nullptr)) {
    int iVar1 = (*(int(**)())(*(int*)param_1 + 4))();
    if ((iVar1 != 0) && (*(int*)(DAT_00728de4 + 8) != 0)) {
      FUN_005bfa50(iVar1);
    }
  }
}
// 0x5c9080 — observed shape
void FUN_005c9080(int* param_1)
{
  if ((DAT_00728de4 != 0) && (param_1 != nullptr)) {
    int iVar1 = (*(int(**)())(*(int*)param_1 + 4))();
    if ((iVar1 != 0) && (*(int*)(DAT_00728de4 + 0xc) != 0)) {
      FUN_005bfa50(iVar1);
    }
  }
}

// 0x5c90b0 — observed shape
void FUN_005c90b0(void* self, uint8_t param_1)
{
  FUN_005c8b10(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5c90d0 — observed shape
void FUN_005c90d0(void* self, uint8_t param_1)
{
  FUN_005c8b90(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5c90f0 — observed shape
void FUN_005c90f0(void* self, uint8_t param_1)
{
  FUN_005c8c50(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5c9110 — observed shape
void FUN_005c9110(void* self)
{
  uint32_t* ptr = (uint32_t*)self;
  *ptr = (uint32_t)((void**)&PTR_LAB_006fd148);
  ptr[1] = 0;
  DAT_00727444 = DAT_00727444 + 1;
  *ptr = (uint32_t)((void**)&PTR_FUN_006c7750);
  uint32_t* puVar1 = (uint32_t*)FUN_00533c78(0x14);
  if (puVar1 == nullptr) {
    puVar1 = nullptr;
  }
  else {
    *puVar1 = (uint32_t)((void**)&PTR_FUN_006c76fc);
    puVar1[1] = 0x3b;
    puVar1[3] = 0;
    uint32_t* puVar2 = (uint32_t*)thunk_FUN_00533c78(0xec);
    puVar1[2] = (uint32_t)puVar2;
    for (uint32_t uVar3 = puVar1[1] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(uint8_t*)puVar2 = 0;
      puVar2 = (uint32_t*)((char*)puVar2 + 1);
    }
    *(uint8_t*)(puVar1 + 4) = 0;
    *puVar1 = (uint32_t)((void**)&PTR_FUN_006c7828);
  }
  ptr[2] = (uint32_t)puVar1;
  puVar1 = (uint32_t*)FUN_00533c78(0x14);
  if (puVar1 == nullptr) {
    ptr[3] = 0;
    return;
  }
  *puVar1 = (uint32_t)((void**)&PTR_FUN_006c7718);
  puVar1[1] = 0x3b;
  puVar1[3] = 0;
  uint32_t* puVar2 = (uint32_t*)thunk_FUN_00533c78(0xec);
  puVar1[2] = (uint32_t)puVar2;
  for (uint32_t uVar3 = puVar1[1] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uint8_t*)puVar2 = 0;
    puVar2 = (uint32_t*)((char*)puVar2 + 1);
  }
  *(uint8_t*)(puVar1 + 4) = 0;
  *puVar1 = (uint32_t)((void**)&PTR_FUN_006c7844);
  ptr[3] = (uint32_t)puVar1;
}
