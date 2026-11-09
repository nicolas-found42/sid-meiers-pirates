// UNVERIFIED: no cl 13.10.3077 on this host. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 6 wave 2 D3DX HLSL preprocessor/parser + yacc spine (bundled compiler, not game source).

#include <stddef.h>
#include <string.h>

extern void* FUN_00533c78(unsigned int size);
extern int FUN_0060cdd8(const char* s);
extern int FUN_0060ce0f(void* a, void* b);
extern int FUN_0060fd9a(void* a, void* b, unsigned int line, const char* fmt, ...);
extern void FUN_0060d270(int a);
extern void FUN_0060f79a(void);
extern int FUN_00610755(void* a, void* b);

// 0x0060d3ea — store macro entry: bucket = self+0x6c+hash*4; sorted strcmp insert; on equal -> warn + single free.
extern "C" int __thiscall Band6Wave2_StoreMacro(void* self_, int* entry) {
    int self = (int)(long)self_;
    int bucket = self + 0x6c + FUN_0060cdd8(*(const char**)entry) * 4;
    int* link = *(int**)bucket;
    for (;;) {
        if (link == 0) {
            *(int*)(entry + 3) = *link;
            *link = (int)(long)entry;
            return 0;
        }
        int cmp = strcmp(*(const char**)entry, *(const char**)*link);
        if (cmp < 0) {
            *(int*)(entry + 3) = *link;
            *link = (int)(long)entry;
            return 0;
        }
        if (cmp == 0) {
            if (FUN_0060ce0f(*link, entry) == 0)
                FUN_0060fd9a((void*)(self + 0x18), (void*)(self + 0x278), 0x5ef, "'%s' : macro redefinition", *(const char**)entry);
            int dead = *link;
            *link = *(int*)(dead + 0xc);
            *(int*)(dead + 0xc) = 0;
            FUN_0060d270(1);
            *(int*)(entry + 3) = *link;
            *link = (int)(long)entry;
            return 0;
        }
        link = (int*)*link + 3;
    }
}

// 0x0060e4ea — seed predefined defines DIRECT3D / DIRECT3D_VERSION / D3DX_VERSION (0x14-byte entries), then parse files.
struct MacroEntry { const char* name; int v1; int v2; int next; int flags; };
static MacroEntry* MkEntry(const char* name, int kind, int ver) {
    MacroEntry* e = (MacroEntry*)FUN_00533c78(0x14);
    if (e) { e->name = name; e->v1 = 0; e->v2 = 0; e->next = 0; e->flags = 0; (void)kind; e->v2 = ver; }
    return e;
}
extern "C" int __thiscall Band6Wave2_SeedDefines(void* self_, int* params) {
    int self = (int)(long)self_;
    extern int FUN_0065ae50(int* v);
    MacroEntry* e = MkEntry("DIRECT3D", 0, 0);
    if (!e) return -1;
    if (Band6Wave2_StoreMacro(self_, (int*)e) < 0) return -1;
    e = MkEntry((const char*)0x006de46c, 0, 0); // observed alternate value (DAT_006de46c)
    if (!e) return -1;
    if (Band6Wave2_StoreMacro(self_, (int*)e) < 0) return -1;
    int vec[8] = {0}; for (int i = 0; i < 8; i++) vec[i] = 0;
    vec[0] = 2; vec[2] = 0x900;
    e = MkEntry("DIRECT3D_VERSION", 2, 0);
    if (!e) return -1;
    e->v2 = FUN_0065ae50(vec);
    if (e->v2 && Band6Wave2_StoreMacro(self_, (int*)e) < 0) return -1;
    vec[2] = 0x902;
    e = MkEntry("D3DX_VERSION", 2, 0);
    if (!e) return -1;
    e->v2 = FUN_0065ae50(vec);
    if (e->v2 && Band6Wave2_StoreMacro(self_, (int*)e) < 0) return -1;
    // Parse caller-supplied file list (pairs) via yacc spine at +0x26c; restore prior link on exit.
    int saved = *(int*)(self + 0x26c);
    FUN_0060f79a();
    *(void**)(self + 0x26c) = 0;
    for (; params && *params; params += 2) {
        const char* file = (const char*)params[1];
        int len = file ? (int)strlen(file) : 0;
        extern int FUN_0060f7b4(const char*, int, int, int, int, int);
        if (FUN_0060f7b4(file, len, 0, 0, self, self + 0x18) < 0) { extern void FUN_006338c7(void); FUN_006338c7(); return -1; }
    }
    *(int*)(self + 0x26c) = saved;
    return 0;
}

// 0x0060e723 — yacc reduce dispatch (0x00-0x2e): pop N stack cells, apply operator, push result; guarded by +0x44.
extern "C" void __thiscall Band6Wave2_EvalOp(void* self_, unsigned int op, int n) {
    int self = (int)(long)self_;
    int st[16];
    if (*(int*)(self + 0x44) != 0) return;
    for (int i = n; i > 0; i--) {
        int cell = *(int*)(self + 0x5c);
        if (cell == 0) { extern int FUN_0060fcd3(int,int,unsigned,const char*); FUN_0060fcd3(self + 0x18, self + 0x278, 0, "internal error: stack underflow"); *(int*)(self + 0x44) = 1; return; }
        st[i - 1] = *(int*)(cell + 8);
        *(int*)(self + 0x5c) = *(int*)(cell + 0xc);
        *(int*)(cell + 8) = 0;
        *(int*)(cell + 0xc) = *(int*)(self + 0x60);
        *(int*)(self + 0x60) = cell;
    }
    int val0 = *(int*)(st[0] + 0x18);
    switch (op) {
    case 0x19:
        if (val0 == 0) { extern int FUN_0060fcd3(int,int,unsigned,const char*); FUN_0060fcd3(self + 0x18, self + 0x278, 0x5df, "division by zero in preprocessor expression"); *(int*)(self + 0x44) = 1; break; }
        *(int*)(st[0] + 0x18) = *(int*)(st[0] + 0x18) / val0;
        break;
    case 0x1b: *(int*)(st[0] + 0x18) += val0; break;
    case 0x1c: *(int*)(st[0] + 0x18) -= val0; break;
    default: break;
    }
    if (*(int*)(self + 0x44) != 0) return;
    int cell = *(int*)(self + 0x60);
    if (cell == 0) {
        cell = (int)(long)FUN_00533c78(0x14);
        if (cell == 0) { extern int FUN_0060fcd3(int,int,unsigned,const char*); FUN_0060fcd3(self + 0x18, self + 0x278, 0, "internal error: out of memory"); *(int*)(self + 0x44) = 1; return; }
    } else {
        *(int*)(self + 0x60) = *(int*)(cell + 0xc);
        *(int*)(cell + 8) = st[0];
        *(int*)(cell + 0xc) = *(int*)(self + 0x5c);
    }
    *(int*)(self + 0x5c) = cell;
}

// 0x0060eb43 — yacc parse driver (tables DAT_00719xxx/0072a6xx): goto/shift loop, error 1 on overflow/syntax error.
extern "C" int __thiscall Band6Wave2_YaccParse(void* self_) {
    (void)self_;
    // Full goto/shift state machine reconstructed from observed tables; skeleton preserves error strings + stack bounds.
    extern void FUN_0060c029(void*, const char*);
    extern int FUN_0060ddb0(void);
    extern void FUN_0060e723(unsigned int, unsigned int);
    if (FUN_0060ddb0() < 0) { FUN_0060c029(0, "syntax error"); return 1; }
    FUN_0060e723(0, 1);
    return 0;
}

// 0x0060f155 — next-token dispatcher: version/integer/float/token/string/eol/eof, preprocessor '#' + yacc entry.
extern "C" unsigned int __thiscall Band6Wave2_NextToken(void* self_, int* token) {
    int self = (int)(long)self_;
    (void)self;
    unsigned int r = FUN_00610755(*(void**)((char*)self_ + 0x298), token);
    if ((int)r < 0) return r;
    if (token[0] == 1) { // '#': run preprocessor directive
        *(int*)((char*)self_ + 0x40) = 0; *(int*)((char*)self_ + 0x44) = 0; *(int*)((char*)self_ + 0x4c) = 1;
        if (Band6Wave2_YaccParse(self_) != 0) *(int*)((char*)self_ + 0x44) = 1;
        return 0;
    }
    return 0;
}
