#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint32_t DAT_00729148;
extern uint32_t DAT_0072914c;
extern uint32_t DAT_00729150;
extern uint32_t DAT_00729154;
extern uint32_t DAT_00729158;
extern uint32_t DAT_00729128;
extern uint32_t DAT_0072912c;
extern uint32_t DAT_00729130;
extern uint32_t DAT_00729134;
extern uint32_t DAT_00729138;
extern uint32_t DAT_0072913c;
extern uint32_t DAT_00729140;
extern uint32_t DAT_00729144;
extern uint32_t DAT_007290e8;
extern uint32_t DAT_007290d0;
extern uint32_t DAT_007290d4;
extern uint32_t DAT_007290d8;
extern uint32_t DAT_007290dc;
extern uint32_t DAT_007290e0;
extern uint32_t DAT_00729224;
extern uint32_t DAT_00729228;
extern uint32_t DAT_0072922c;
extern uint32_t DAT_00729230;
extern uint32_t DAT_00729234;
extern uint32_t DAT_00729238;
extern uint32_t DAT_0072923c;
extern uint32_t DAT_00729240;
extern uint32_t DAT_00729244;
extern uint32_t DAT_00729248;

// 0x5e7b10 — observed shape
uint32_t* FUN_005e7b10()
{
    DAT_0072914c = 0;
    DAT_00729150 = 0;
    DAT_00729154 = 0;
    DAT_00729158 = 0;
    DAT_00729148 = 4;
    return &DAT_00729148;
}

// 0x5e7b40 — observed shape
uint32_t* FUN_005e7b40()
{
    DAT_0072912c = 0;
    DAT_00729130 = 0;
    DAT_00729134 = 0;
    DAT_00729138 = 0;
    DAT_0072913c = 0;
    DAT_00729140 = 0;
    DAT_00729144 = 0;
    DAT_00729128 = 5;
    return &DAT_00729128;
}

// 0x5e7b80 — observed shape
uint32_t* FUN_005e7b80()
{
    uint32_t* p = &DAT_007290e8;
    for (int i = 0x10; i != 0; i--) {
        *p = 0;
        p++;
    }
    DAT_007290e8 = 6;
    return &DAT_007290e8;
}

// 0x5e7ba0 — observed shape
uint32_t* FUN_005e7ba0()
{
    DAT_007290d4 = 0;
    DAT_007290d8 = 0;
    DAT_007290dc = 0;
    DAT_007290e0 = 0;
    DAT_007290d0 = 7;
    return &DAT_007290d0;
}

// 0x5e7bd0 — observed shape
uint32_t* FUN_005e7bd0()
{
    DAT_00729224 = 0;
    DAT_00729228 = 0;
    DAT_0072922c = 0;
    DAT_00729230 = 0;
    DAT_00729234 = 0;
    DAT_00729238 = 0;
    DAT_0072923c = 0;
    DAT_00729240 = 0;
    DAT_00729244 = 0;
    DAT_00729248 = 0;
    return &DAT_00729224;
}

extern uint32_t DAT_00729250;
extern void FUN_005677b0(void* a, void* b);
extern void FUN_005e8870(uint32_t p1);
extern int32_t* FUN_005e8050(uint32_t p2, uint32_t p3, uint32_t p4);
extern void FUN_005edba0();
extern void operator_delete(void* p);
extern void* ExceptionList;

// 0x5e7c60 — observed shape
void FUN_005e7c60()
{
    int32_t next = (int32_t)DAT_00729250 + 1;
    bool wasZero = DAT_00729250 == 0;
    DAT_00729250 = (uint32_t)next;
    if (wasZero) {
        FUN_005677b0((void*)0x005e7c10, (void*)0x005e7c30);
    }
}

// 0x5e7c90 — observed shape
bool FUN_005e7c90(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, int32_t** param_5)
{
    FUN_005e8870(param_1);
    int32_t* piVar1 = FUN_005e8050(param_2, param_3, param_4);
    if (piVar1 != nullptr) {
        auto vtbl = *(int32_t**)piVar1;
        using fn_t = void(__cdecl*)(uint32_t);
        fn_t fn = *(fn_t*)((uint8_t*)vtbl + 0x10);
        fn(param_1);
    }
    *param_5 = piVar1;
    return piVar1 != nullptr;
}

// 0x5e7d00 — observed shape
void FUN_005e7d00(void* self)
{
    *(void**)self = (void*)0x006c9a30;
}

// 0x5e7d30 — observed shape
void FUN_005e7d30(void* self)
{
    void* local_c = ExceptionList;
    ExceptionList = &local_c;
    *(void**)self = (void*)0x006c9a70;
    FUN_005edba0();
    *(void**)self = (void*)0x006c9a30;
    ExceptionList = local_c;
}

// 0x5e7d80 — observed shape
void FUN_005e7d80(void* self, uint8_t param_1)
{
    FUN_005e7d30(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

extern void FUN_005c9dc0();
extern uint32_t FUN_005e7e20(uint8_t* param);
extern void FUN_005c9a50(const char* fmt);
extern void FUN_006b37c0(void** pp);
extern int32_t* FUN_00533c78(uint32_t sz);
extern uint32_t FUN_006b33a0();
extern void FUN_0051ac30(uint32_t v);
extern int32_t* FUN_005e9570();
extern void FUN_006b3460(int32_t* p);
extern void* FUN_005e84a0();
extern char FUN_005e8830(void* ob, uint32_t a, uint32_t b);
extern void FUN_005e8190();
extern void FUN_005c9d90(const char* s);

// 0x5e7da0 — observed shape
void FUN_005e7da0(void* self)
{
    void* local_c = ExceptionList;
    ExceptionList = &local_c;
    *(void**)self = (void*)0x006c9a58;
    OutputDebugStringA("Releasing Binary Shaders!\n");
    FUN_005edba0();
    ((void**)self)[6] = (void*)0x006c9a70;
    FUN_005edba0();
    ((void**)self)[6] = (void*)0x006c9a30;
    FUN_005c9dc0();
    ExceptionList = local_c;
}

// 0x5e7e20 — observed shape
int32_t FUN_005e7e20(void* self, uint8_t* param_1)
{
    uint8_t* base = (uint8_t*)self;
    uint32_t* node = *(uint32_t**)(base + 0x1c);
    for (;;) {
        while (node != nullptr) {
            int32_t entry = (int32_t)node[2];
            node = (uint32_t*)*node;
            if (entry == 0) continue;
            uint8_t* s1 = *(uint8_t**)((uint8_t*)(intptr_t)entry + 8);
            uint8_t* s2 = param_1;
            for (;;) {
                int cmp = 0;
                while (*s1 == *s2 && *s1 != 0) { s1++; s2++; }
                uint8_t b1 = *s1;
                uint8_t b2 = *s2;
                if (b1 != b2) cmp = (b1 < b2) ? -1 : 1;
                if (cmp == 0) return entry;
                break;
            }
        }
        if (node == nullptr) return 0;
    }
}

// 0x5e7e90 — observed shape
void FUN_005e7e90(void* self, uint8_t param_1)
{
    FUN_005e7da0(self);
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x5e7ee0 — observed shape
uint32_t FUN_005e7ee0(void* self, uint32_t* param_1)
{
    uint32_t* obj = param_1;
    void* local_c = ExceptionList;
    if (param_1 == nullptr) return 0;
    ExceptionList = &local_c;
    int32_t found = FUN_005e7e20(self, (uint8_t*)param_1[2]);
    if (found != 0) {
        FUN_005c9a50("Shader %s already in list??\n");
        ExceptionList = local_c;
        return 0;
    }
    obj[1] = obj[1] + 1;
    void* tmp = param_1;
    FUN_006b37c0(&tmp);
    uint32_t cnt = obj[1];
    obj[1] = cnt - 1;
    if (cnt - 1 == 0) {
        using fn_t = void(__cdecl*)(uint32_t);
        (*(fn_t*)*(void**)obj)(1);
    }
    int32_t* slot = (int32_t*)((uint8_t*)self + 0x14);
    if (*slot == 0) {
        uint32_t* np = (uint32_t*)FUN_00533c78(0x4c);
        uint32_t uVar3;
        if (np == nullptr) uVar3 = 0;
        else uVar3 = FUN_006b33a0();
        FUN_0051ac30(uVar3);
        if (*slot == 0) { ExceptionList = local_c; return 1; }
    }
    int32_t* src = FUN_005e9570();
    FUN_006b3460(src);
    int32_t** dst = *(int32_t***)slot;
    int32_t v0 = *(int32_t*)*(int32_t**)(((uint8_t*)src) + 0x1c);
    (void)v0;
    // copy interface slots 0x44/0x48/0x4c/0x50 as in decompilation
    uint32_t offsV1[] = {0x1c,0x20,0x24,0x28,0x2c,0x30,0x34};
    uint32_t offsD[] = {0x44,0x44,0x48,0x48,0x4c,0x4c,0x50};
    for (int i = 0; i < 7; i++) {
        uint32_t val = ((uint32_t(__cdecl*)())*(uint32_t*)((uint8_t*)*(int32_t**)src + offsV1[i]))();
        int32_t cur = *(uint32_t*)slot;
        using fn2_t = void(__cdecl*)(uint32_t);
        fn2_t f2 = *(fn2_t*)((uint8_t*)*(int32_t**)cur + offsD[i]);
        f2(val);
        (void)dst;
    }
    ExceptionList = local_c;
    return 1;
}

// 0x5e8050 — observed shape
uint32_t* FUN_005e8050(uint32_t param_1, uint32_t* param_2, uint32_t param_3)
{
    void* local_c = ExceptionList;
    ExceptionList = &local_c;
    uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0x28);
    uint32_t* puVar5;
    if (puVar3 == nullptr) {
        puVar5 = nullptr;
    } else {
        FUN_005c9d90("NSBShaderLib");
        puVar3[0] = 0x006c9a58;
        puVar3[9] = 0;
        puVar3[7] = 0;
        puVar3[8] = 0;
        puVar3[6] = 0x006c9a70;
        puVar5 = puVar3;
    }
    if (puVar5 != nullptr) {
        uint32_t uVar1 = *param_2;
        void* pvVar4 = FUN_005e84a0();
        char cVar2 = FUN_005e8830(puVar5, uVar1, param_3);
        if (pvVar4 != nullptr) { FUN_005e8190(); operator_delete(pvVar4); }
        if (cVar2 == '\0') {
            using fn_t = void(__cdecl*)(uint32_t);
            (*(fn_t*)*(void**)puVar5)(1);
            ExceptionList = puVar3;
            return nullptr;
        }
    }
    ExceptionList = local_c;
    return puVar5;
}

extern uint32_t DAT_00729258;
extern void operator_delete__(void* p);
extern void FUN_005c9ab0(int32_t id, void* buf, uint32_t n);
extern uint32_t* FUN_005e9e40();
extern char FUN_005ea280(int32_t id);
extern void FUN_005c9b30(const char* src, char* dst, uint32_t n);
extern void* FUN_005e0560(void* p);

// 0x5e8160 — observed shape
void FUN_005e8160()
{
    int32_t next = (int32_t)DAT_00729258 + 1;
    bool wasZero = DAT_00729258 == 0;
    DAT_00729258 = (uint32_t)next;
    if (wasZero) FUN_005677b0((void*)0x005e8120, (void*)0x005e8140);
}

// 0x5e8190 — observed shape
void FUN_005e8190(void* self)
{
    int32_t* fields = (int32_t*)self;
    void* local_c = ExceptionList;
    ExceptionList = &local_c;
    int32_t cur = fields[2];
    fields[0] = cur;
    while (cur != 0) {
        int32_t* node = (int32_t*)*(int32_t*)fields;
        fields[0] = node[0];
        void* pv = (void*)node[2];
        if (pv != nullptr) operator_delete__(pv);
        cur = fields[0];
    }
    FUN_005edba0();
    fields[1] = (int32_t)0x006c9740;
    FUN_005edba0();
    fields[1] = (int32_t)0x006c96e0;
    ExceptionList = local_c;
}

// 0x5e8220 — observed shape
uint32_t FUN_005e8220(void* self)
{
    uint8_t* base = (uint8_t*)self;
    void* local_c = ExceptionList;
    uint8_t* list = *(uint8_t**)(base);
    int32_t loaded = 0;
    bool ok = true;
    ExceptionList = &local_c;
    uint8_t* node = *(uint8_t**)(base + 8);
    if (node != nullptr) {
        *(uint8_t**)base = *(uint8_t**)node;
        int32_t id = *(int32_t*)(node + 8);
        while (id != 0) {
            char buf[260];
            int32_t* head = *(int32_t**)base;
            FUN_005c9ab0(id, buf, 0x104);
            int32_t found = FUN_005e7e20(self, (uint8_t*)buf);
            if (found == 0) {
                FUN_005c9a50("Attempting to load %s\n", id);
                int32_t alloc = (int32_t)FUN_00533c78(0xa4);
                uint32_t* puVar3 = (alloc == 0) ? nullptr : FUN_005e9e40();
                if (puVar3 != nullptr) {
                    if (FUN_005ea280(id) != '\0') {
                        FUN_005c9a50("Loaded %s\n", id);
                        FUN_005e7ee0(self, puVar3);
                        loaded++;
                        goto LAB_005e8338;
                    }
                    FUN_005c9a50("Failed to load %s\n", id);
                    using fn_t = void(__cdecl*)(uint32_t);
                    (*(fn_t*)*(void**)puVar3)(1);
                }
                ok = false;
            } else {
                FUN_005c9a50("%s (%s) already loaded?\n", buf);
            }
        LAB_005e8338:
            node = *(uint8_t**)base;
            if (node == nullptr) break;
            *(uint8_t**)base = *(uint8_t**)node;
            id = *(int32_t*)(node + 8);
        }
        if (loaded != 0) { ExceptionList = local_c; return (uint32_t)(uintptr_t)node; }
    }
    (void)head; (void)list;
    ExceptionList = local_c;
    return (uint32_t)((uintptr_t)node & 0xffffff00u) | (ok ? 1u : 0u);
}

// 0x5e8380 — observed shape
uint32_t FUN_005e8380(char* param_1, const char* param_2)
{
    if (param_1 == nullptr) return 0;
    int count = 1;
    bool eq = true;
    const char* p2 = "";
    const char* p1 = param_1;
    while (count != 0 && eq) {
        count--;
        eq = (*p1 == *p2);
        p1++; p2++;
    }
    if (!eq) {
        char local_100[256];
        FUN_005c9b30(param_1, local_100, 0x100);
        if (_stricmp(local_100, param_2) == 0) {
            FUN_005c9a50("        Found %s File %s\n", param_2, param_1);
            const char* s = param_1;
            while (*s != '\0') s++;
            int32_t allocSize = (int32_t)(intptr_t)(s + (1 - (int)(param_1 + 1)));
            int32_t delta = allocSize - (int32_t)(intptr_t)param_1;
            char* dst = param_1;
            char c;
            do { c = *dst; dst[delta] = c; dst++; } while (c != '\0');
            FUN_005e0560(&allocSize);
            return 1;
        }
    }
    return 0;
}

// 0x5e8450 — observed shape
void FUN_005e8450(void* self)
{
    uint8_t* base = (uint8_t*)self;
    void* local_c = ExceptionList;
    ExceptionList = &local_c;
    *(uint32_t*)(base + 0x10) = 0;
    *(uint32_t*)(base + 8) = 0;
    *(uint32_t*)(base + 0xc) = 0;
    *(uint32_t*)(base + 4) = 0x006c9740;
    FUN_005edba0();
    ExceptionList = local_c;
}
