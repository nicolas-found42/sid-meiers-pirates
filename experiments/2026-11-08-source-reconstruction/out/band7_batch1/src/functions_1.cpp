// 0x0061288b
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 11; 8 params, thiscall (ECX), returns 0 or 0x80040405-style error below.
// Observed: short-length check (<3 chars -> error 0x7d5/0x80040405), register-type dispatch
// on first 2 chars: v_(0x5f76)->input, r_(0x5f72)->temp, c_/b_/i_/s_(0x5f63/0x5f62/0x5f69/0x5f73)->const,
// o_(0x5f6f)->output; per-type counters at this+0x8c..+0xac; vtable/call order via %B_ERR helper.
extern int FUN_0060fcd3(int,int,int,const char*,...);   // error reporter (0x7d5 line, returns 0x80040405 = -0x7fffbffb)
extern int FUN_00610ba0(const char*);                  // 0x00610ba0 hash-bucket lookup: 0 = new name
extern int FUN_0065c485(int,const char*,int**);         // const lookup (-1 => error path)
extern int FUN_0061273f(const char*,unsigned,int);     // register allocator
extern int FUN_00610918(const char*,int&,int&);         // numeric-suffix parse (-1 => invalid)
struct RegInfo { int type; unsigned index; unsigned count; };  // +0x00/+0x04/+0x08
int __thiscall FUN_0061288b(void* self, int ctx, int ctxLine, const short* name, int* addrOp,
    int* typeOut, int* subOut, unsigned* indexOut)
{
    const short* end = name;
    do { ++end; } while (*end != 0);                    // short-length scan (observed loop)
    if ((unsigned)((char*)end - (char*)name) < 3) {
        FUN_0060fcd3(ctx, ctxLine, 0x7d5, "invalid register, input, or constant name '%s'", name);
        return -0x7fffbffb;
    }
    *typeOut = 0; *subOut = 0; *indexOut = 0;
    short tag = *name;
    if (tag == 0x5f76) {  // "v_" input
        int mode = *(int*)((char*)self + 0xb4);
        if (mode < 10 || 12 < mode) {
            *typeOut = 1;
            if (FUN_00610ba0((const char*)name) == 0) {
                if (FUN_00610918((const char*)(name + 1), *(int*)((char*)&typeOut + 0), *(int*)((char*)&name + 0)) < 0)
                    return error(ctx, ctxLine, "Invalid input register '%s' specified", name);
                unsigned* cnt = (unsigned*)((char*)self + 0x9c);
                *indexOut = *cnt; FUN_0061273f((const char*)name, *cnt, 1); *cnt = *cnt + 1;
            } else *indexOut = *(unsigned*)(*(int*)FUN_00610ba0(0) + 4);
            if (addrOp == 0) return 0;
            return error(ctx, ctxLine, "addressing operations are not allowed on input registers '%s'", name);
        }
        if (FUN_00610918((const char*)(name + 1), *(int*)((char*)&addrOp + 0), *(int*)((char*)&name + 0)) >= 0) {
            char sub = *(char*)((char*)&addrOp + 3);
            if (sub == 5) *subOut = 3;
            else if (sub == 10) *subOut = 1;
            else return error(ctx, ctxLine, "Invalid pixel shader input register '%s' specified", name);
            *indexOut = ((unsigned)(int)name >> 24);
            return 0;
        }
        return error(ctx, ctxLine, "Invalid input register '%s' specified", name);
    }
    if (tag == 0x5f72) {  // "r_" temporary
        *typeOut = 0;
        int found = FUN_00610ba0((const char*)name);
        if (found == 0) {
            unsigned* cnt = (unsigned*)((char*)self + 0xa4);
            *indexOut = *cnt; FUN_0061273f((const char*)name, *cnt, 1); *cnt = *cnt + 1;
        } else *indexOut = *(unsigned*)(found + 4);
        if (addrOp == 0) return 0;
        return error(ctx, ctxLine, "addressing operations not allowed on temporary registers '%s'", name);
    }
    if (tag == 0x5f63 || tag == 0x5f62 || tag == 0x5f69 || tag == 0x5f73) {  // c_/b_/i_/s_ constant
        int kind;
        if (tag == 0x5f62) { *typeOut = 14; kind = 0; }
        else if (tag == 0x5f69) { *typeOut = 7; kind = 1; }
        else if (tag == 0x5f73) { *typeOut = 10; kind = 2; }
        else { *typeOut = 2; kind = 3; }
        int found = FUN_00610ba0((const char*)name);
        int* size = 0;
        if (found == 0) {
            int rc = FUN_0065c485(ctxLine, (const char*)name, &size);
            if (rc < 0) return rc;
            if (size == 0) {
                FUN_0060fcd3(ctx, ctxLine, 0x7d5, "constant register '%s' must be defined as a variable '%s'", name, name + 1);
                return -0x7fffbffb;
            }
            unsigned* cnt = (unsigned*)((char*)self + 0x8c + kind * 4);
            *indexOut = *cnt; FUN_0061273f((const char*)name, *cnt, *size);
            *cnt = *cnt + (unsigned)*size;
            *(int*)((char*)self + 0xac) = *(int*)((char*)self + 0xac) + 1;
        } else {
            *indexOut = *(unsigned*)(found + 4);
            size = *(int**)(found + 8);
        }
        if (addrOp == 0) return 0;
        int* limit = *(int**)(*(int*)addrOp + 0x18);
        if (size < limit) {
            FUN_0060fcd3(ctx, ctxLine, 0x7d5, "constant register address out of bounds on constant '%s', size %d, offset %d", name, size, limit);
            return -0x7fffbffb;
        }
        *indexOut = *indexOut + (unsigned)limit;
        return 0;
    }
    if (tag == 0x5f6f && *(int*)((char*)self + 0xb0) != 0) {  // "o_" output (vs_3_0 only)
        *typeOut = 6;
        int found = FUN_00610ba0((const char*)name);
        if (found == 0) {
            if (FUN_00610918((const char*)(name + 1), *(int*)((char*)&typeOut + 0), *(int*)((char*)&name + 0)) < 0)
                return error(ctx, ctxLine, "Invalid output register '%s' specified", name);
            unsigned* cnt = (unsigned*)((char*)self + 0xa0);
            *indexOut = *cnt; FUN_0061273f((const char*)name, *cnt, 1); *cnt = *cnt + 1;
        } else *indexOut = *(unsigned*)(found + 4);
        if (addrOp == 0) return 0;
        return error(ctx, ctxLine, "addressing operations are not allowed on output registers '%s'", name);
    }
    FUN_0060fcd3(ctx, ctxLine, 0x7d5, "'%s' is not a valid register name.  Registers must start with v_, r_, c_, b_, or i_ depending on the register type. (o_ for vs_3_0 only)", name);
    return -0x7fffbffb;
}
static int error(int ctx, int line, const char* msg, const void* arg)
{ FUN_0060fcd3(ctx, line, 0x7d5, msg, arg); return -0x7fffbffb; }

// 0x006294f9
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 11; terminal jmp-style tail call to FUN_00629497 (Ghidra notes terminal call at 0x6294ff).
extern void FUN_00629497(void);
void FUN_006294f9(void) { FUN_00629497(); }

// 0x00656706
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 11; terminal tail call to FUN_0069252a (call at 0x65670c).
extern void FUN_0069252a(void);
void FUN_00656706(void) { FUN_0069252a(); }

// 0x00670ea1
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 11; terminal tail call to FUN_006a3d1c (call at 0x670ea7).
extern void FUN_006a3d1c(void);
void FUN_00670ea1(void) { FUN_006a3d1c(); }

// 0x0063271d
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 12; thiscall (ECX); field at this+0x14 -> null-check, else *(entry+8).
typedef void* ptr;
unsigned __thiscall FUN_0063271d(void* self)
{
    void* e = *(void**)((char*)self + 0x14);
    if (e == 0) return 0;
    return *(unsigned*)((char*)e + 8);
}

// 0x0065c2b3
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 12; thiscall (ECX); (this[1] + 3 >> 2) + 2 — dword count calc.
unsigned __thiscall FUN_0065c2b3(void* self)
{
    return ((*(unsigned*)((char*)self + 4) + 3) >> 2) + 2;
}

// 0x006293f7
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 15; plain cdecl single-arg getter: return *(param+0x0c).
unsigned FUN_006293f7(unsigned* p) { return *(unsigned*)((char*)p + 0xc); }

// 0x00629406
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 15; plain cdecl single-arg getter: return *(param+8).
unsigned FUN_00629406(unsigned* p) { return *(unsigned*)((char*)p + 8); }

// 0x00629384
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 16; thiscall (ECX); installs vtable PTR_FUN_006e1934 then operator_delete(this[3]).
struct VTable29384 { void* slots[4]; };
extern VTable29384 PTR_FUN_006e1934;
extern void operator_delete(void*);
void __thiscall FUN_00629384(void* self)
{
    *(void**)self = &PTR_FUN_006e1934;
    operator_delete(*(void**)((char*)self + 0xc));  // in_ECX[3]
}

// 0x00654820
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 16; terminal tail call to FUN_00692320 (call at 0x654826).
extern void FUN_00692320(void);
void FUN_00654820(void) { FUN_00692320(); }

// 0x00657361
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 16; single-arg: *(param+0x60) |= 1 (set low flag bit).
void FUN_00657361(unsigned* p) { *(unsigned*)((char*)p + 0x60) |= 1u; }

// 0x0065754e
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 16; single-arg: byte at param+0x61 |= 0x10.
void FUN_0065754e(unsigned char* p) { p[0x61] = (unsigned char)(p[0x61] | 0x10); }

// 0x006293c0
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 18; single-arg refcount inc: *(param+4) += 1; return *(param+4).
int FUN_006293c0(int* p) { return ++*(int*)((char*)p + 4); }

// 0x0062ac89
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 18; single-arg refcount inc: *(param+8) += 1; return *(param+8).
int FUN_0062ac89(int* p) { return ++*(int*)((char*)p + 8); }

// 0x0063e524
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 18; single-arg refcount inc: *(param+0x24) += 1; return *(param+0x24).
int FUN_0063e524(int* p) { return ++*(int*)((char*)p + 0x24); }

// 0x00610ba0
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 54; thiscall (ECX = table); case-insensitive hash-bucket lookup (7 buckets).
// Observed: FUN_00610b5f(name) -> 0..6; node = table[hash]; walk node[8] (+0x20) with lstrcmpiA(node->key,name).
// Callers include 0x612896, 0x6a0290. Deep-dive: analysis/team/band7/deep/0x00610ba0.md.
struct HashNode { const char* key; void* aux[7]; HashNode* next; };  // +0x00 key, +0x20 next (observed)
extern int FUN_00610b5f(const char*);   // h*0x13+toupper, %7 (per deep-dive)
extern int __cdecl lstrcmpiA(const char*, const char*);
HashNode* __thiscall FUN_00610ba0(void* table, const char* name)
{
    HashNode* n = *(HashNode**)((char*)table + FUN_00610b5f(name) * 4);
    for (; n; n = n->next)
        if (lstrcmpiA(n->key, name) == 0) return n;
    return 0;
}

// 0x00647b28
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 43; thiscall (ECX = this, frameless); field-initializer leaf. Deep-dive: analysis/team/band7/deep/0x00647b28.md.
// Observed order: [2] |= -1 (OR, not MOV), [9]=[8]=[0]=[1]=0, [4]=3, [0xf]=[0xd]=[10]=0, word(+0x46)=0, [0x10]=0.
struct Obj47b28 { unsigned f00,f04,flat08,u0c,u10,u14,u18,u1c,f20,f24,f28,u2c,u30,f34,u38,f3c,f40;
    unsigned short w46; unsigned short u48; };
void __thiscall FUN_00647b28(Obj47b28* self)
{
    self->flat08 |= 0xFFFFFFFFu;   // observed OR with -1; source form unknown
    self->f20 = self->f24 = self->f00 = self->f04 = 0;
    self->u10 = 3;
    self->f3c = self->f34 = self->f28 = 0;
    self->w46 = 0;
    self->f40 = 0;
}

// 0x00672e90
// UNVERIFIED candidate. cl 13.10.3077 absent; no PASS or byte-match claimed.
// span 61; cdecl 1-dword membership predicate -> 1 if tag in set, else 0. Deep-dive: analysis/team/band7/deep/0x00672e90.md.
// Observed constants: 0x60000000, 0x60500000, 0x60700000, 0x60a00000, 0x60f00000, 0x72e00000.
int __cdecl FUN_00672e90(unsigned tag)
{
    return (tag == 0x60000000u || tag == 0x60500000u || tag == 0x60700000u ||
            tag == 0x60a00000u || tag == 0x60f00000u || tag == 0x72e00000u) ? 1 : 0;
}
