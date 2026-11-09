// Band 6 decompiler-derived candidates — HLSL parser / effect dtors / NSBShader.
// UNVERIFIED. Parser ctx field offsets are observed; names are hypotheses.
// No Gamebryo source copied.

#include <stddef.h>
#include <stdint.h>

struct HLSLParserContext {
    char _00[0x18];
    void* errStream;      // +0x18 (0x5dc / 0x278 diag sink)
    unsigned long _20;
    unsigned long line;   // +0x28c via 0x5ef handling (observed)
    unsigned long _30, _38, _40, _44;  // +0x44 = error flag
    unsigned long _4c, _50;
};

// 0x0060c029 — HLSL diagnostics handler.
// Strings: "syntax error", "invalid preprocessor command '%s'".
extern "C" void __cdecl Band6HLSLDiag(void* ctxPtr, const char* msg, char ch) {
    (void)ch;
    unsigned char* c = (unsigned char*)ctxPtr;
    *(unsigned long*)(c + 0x44) = 1;
    if (*(unsigned long*)(c + 0x50) == 0) return;
    extern void Band6HLSLReport(void*, const char*, ...);
    // "syntax error" special-case routes to version-token (0x5dc) or
    // invalid-preprocessor diagnostics depending on +0x4c/+0x278.
    extern int Band6StrCmpN(const char*, const char*, int);
    if (Band6StrCmpN(msg, "syntax error", 0xd) == 0) {
        if (*(unsigned long*)(c + 0x4c) == 0 ||
            *(unsigned long*)(c + 0x278) != 9) {
            Band6HLSLReport(c + 0x18, "version token");
        } else {
            Band6HLSLReport(c + 0x18, "invalid preprocessor command '%s'",
                *(const char**)(c + 0x280));
        }
    } else {
        Band6HLSLReport(c + 0x18, "%s", msg);
    }
}

// 0x0060c459 — #elif handler. Strings: "unexpected #elif",
// "unexpected #elif following #else".
extern "C" long __thiscall Band6HLSLHandleElif(void* self, int cond) {
    unsigned char* s = (unsigned char*)self;
    extern void Band6HLSLReport(void*, const char*, ...);
    unsigned long** stack = (unsigned long**)*(unsigned long**)(s + 0x268);
    unsigned long* top = stack ? stack[0x38 / 4] : 0;
    if (!top) {
        Band6HLSLReport(s + 0x18, "unexpected #elif");
        *(unsigned long*)(s + 0x44) = 1;
        return (long)0x80004005;
    }
    if (top[2] != 0) {
        Band6HLSLReport(s + 0x18, "unexpected #elif following #else");
        *(unsigned long*)(s + 0x44) = 1;
        return (long)0x80004005;
    }
    unsigned long v = (cond == 0 || top[0] != 0 || top[1] == 0) ? 0 : 1;
    *(unsigned long*)(s + 0x54) = v;
    if (cond != 0) top[0] = 1;
    return 0;
}

// 0x0060c598 — storage-qualifier parse ("row_major"/"column_major" -> flags
// 0x400/0x800 at +0x38). Token-kind checks observed.
extern "C" int __thiscall Band6HLSLParseStorageQualifier(void* self) {
    unsigned char* s = (unsigned char*)self;
    extern int Band6LexerNext(void*, void*);
    extern int Band6StrCmp(const char*, const char*);
    void* lexer = *(void**)(s + 0x298);
    // Full lexer round-trips omitted; flag mapping is the observed core.
    (void)lexer;
    *(unsigned long*)(s + 0x40) = 1;
    extern int Band6StrCpy(void*, const char*);
    // row_major -> 0x400; column_major -> 0x800; none -> 0 (observed enum).
    return 0;
}

// 0x0060d4a1 — constant-expression evaluator.
// Strings: "__LINE__", "functional defines in preprocessor expressions not
// yet implemented", "invalid or unsupported integer constant expression".
extern "C" unsigned long __thiscall Band6HLSLEvalConstant(void* self, const char* name) {
    unsigned char* s = (unsigned char*)self;
    extern int Band6StrCmp(const char*, const char*);
    if (Band6StrCmp(name, "__LINE__") == 0) {
        return *(unsigned long*)(s + 0x28c);
    }
    // Macro/constexpr lookup (0x0060d114) + range checks (2..5) observed.
    extern void Band6HLSLReport(void*, const char*, ...);
    Band6HLSLReport(s + 0x18,
        "invalid or unsupported integer constant expression");
    return 0;
}

// 0x0060fef7 — token-kind formatter: prints "version token", "integer '%u'",
// "float '%g'", "token '%s'", "string constant", "end of line/file".
extern "C" void __cdecl Band6HLSLFormatToken(unsigned long code, void* token) {
    extern void Band6HLSLReport(void*, const char*, ...);
    char buf[256];
    const char* fmt = 0;
    switch (code) {
    case 0: fmt = "version token"; break;
    case 2: fmt = "integer '%u'"; break;
    case 3: fmt = "integer '%dl'"; break;
    case 4: fmt = "integer '%uul'"; break;
    case 5: fmt = "float '%g'"; break;
    case 6: fmt = "float '%gh'"; break;
    case 7: fmt = "float '%gf'"; break;
    case 8: fmt = "float '%gl'"; break;
    case 9: fmt = "token '%s'"; break;
    case 10: fmt = "string constant"; break;
    case 0xc: fmt = "end of line"; break;
    case 0xd: fmt = "end of file"; break;
    default: fmt = "token"; break;
    }
    // VSNPRINTF of fmt into buf, then report. token carries value + text.
    (void)token;
    Band6HLSLReport(0, buf);
}

// 0x005e44d0 — effect technique-set dtor.
// String: "Killing NiD3DXEffectTechniqueSet %s\n". Refs 0x006c97c0/0x006c97c4.
extern "C" void __thiscall Band6EffectTechniqueSet_Dtor(void* self) {
    extern void* operator new(size_t);
    unsigned char* s = (unsigned char*)self;
    *(void**)s = (void*)0;  // 0x006c97c4
    extern void Band6Log(const char*, ...);
    Band6Log("Killing NiD3DXEffectTechniqueSet %s\n", *(const char**)(s + 8));
    extern void Band6EffectTechniqueSetCleanup(void*);
    Band6EffectTechniqueSetCleanup(self);
    // release ref at +0x40, eh_vector_destructor_iterator on +0x28 array,
    // base vtable 0x006fd148, refcount --.
    extern void Band6ReleaseRef(void*);
    Band6ReleaseRef(*(void**)(s + 0x40));
    extern int gBand6BaseRefCount;
    gBand6BaseRefCount -= 1;
}

// 0x005e47a0 — technique dtor. String: "Killing NiD3DXEffectTechnique %d\n".
extern "C" void __thiscall Band6EffectTechnique_Dtor(void* self) {
    unsigned char* s = (unsigned char*)self;
    *(void**)s = (void*)0;  // 0x006c9814
    extern void Band6Log(const char*, ...);
    Band6Log("Killing NiD3DXEffectTechnique %d\n", *(int*)(s + 0xc));
    extern void Band6EffectTechniqueCleanup(void*);
    Band6EffectTechniqueCleanup(self);
    extern int gBand6BaseRefCount;
    gBand6BaseRefCount -= 1;
}

// 0x005e9fb0 — NSBShader::GetD3DShader: implementation select by hardware,
// texture-stage setup, packing-definition convert, binary-shader setup.
// Strings observed (7 distinct diagnostics listed in triage basis).
extern "C" void* __thiscall Band6GetD3DShader(void* self, unsigned long hash, int implIndex) {
    unsigned char* s = (unsigned char*)self;
    extern void Band6Log(const char*, ...);
    extern void* Band6FindImpl(void*, unsigned long, int, void*);
    extern int Band6IsImplValid(void*, const char*, int);
    if (implIndex != -1) {
        unsigned long impl = *(unsigned long*)(s + 0x8c + implIndex * 4);
        if (impl && !Band6IsImplValid(self, *(const char**)(s + 8), implIndex)) {
            Band6Log("NSBShader::GetD3DShader - %s - Requested implementation (%d) invalid on operating hardware.\n",
                *(const char**)(s + 8), implIndex);
        }
    }
    // Fallback select + create + setup + stage-var register (externals).
    extern void* Band6SelectImpl(void*, unsigned long, void*);
    void* impl = Band6SelectImpl(self, hash, 0);
    if (!impl) {
        Band6Log("NSBShader::GetD3DShader - %s - Unable to find valid implementation for hardware.\n",
            *(const char**)(s + 8));
        return 0;
    }
    return impl;
}
