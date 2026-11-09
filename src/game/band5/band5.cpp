// Band5 source reconstruction — unverified decompiler-derived candidate.
// No cl 13.10.3077. No PASS. See REPORT.md.
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// ---------------------------------------------------------------------------
// FUN_00591460  (0x00591460) — 5-arg 2-index dispatch with null fallback
// Observed corpus: i2 = vt[3](p2); i4 = vt[3](p4);
//   pc = table[DAT_00728b00 + (i4 + i2*6)*4];
//   if (!pc) { retry swapped and call table[(i2 + i4*6)*4](p1,p4,p5,p2,p3); }
//   else pc(p1,p2,p3,p4,p5);
// ---------------------------------------------------------------------------
typedef void (__cdecl *Fn5)(void*, void*, void*, void*, void*);
extern Fn5* g_table_728b00;       // observed base DAT_00728b00; address hypothesis

static int VtIndex_0c(void* obj)
{
    void** vt = *(void***)obj;
    typedef int (__thiscall *F)(void*);
    F f = (F)vt[3];
    return f(obj);
}

void __cdecl FUN_00591460(void* p1, void* p2, void* p3, void* p4, void* p5)
{
    int i2 = VtIndex_0c(p2);
    int i4 = VtIndex_0c(p4);
    Fn5 pc = g_table_728b00[i4 + i2 * 6];
    if (!pc) {
        i2 = VtIndex_0c(p4);
        i4 = VtIndex_0c(p2);
        g_table_728b00[i4 + i2 * 6](p1, p4, p5, p2, p3);
        return;
    }
    pc(p1, p2, p3, p4, p5);
}

// ---------------------------------------------------------------------------
// FUN_005914e0  (0x005914e0) — 10-arg twin of 0x00591460 over DAT_00728b04
// ---------------------------------------------------------------------------
typedef void (__cdecl *Fn10)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern Fn10* g_table_728b04;

void __cdecl FUN_005914e0(void* p1, void* p2, void* p3, void* p4, void* p5,
                          void* p6, void* p7, void* p8, void* p9, void* p10)
{
    int i2 = VtIndex_0c(p2);
    int i4 = VtIndex_0c(p4);
    Fn10 pc = g_table_728b04[i4 + i2 * 6];
    if (!pc) {
        i2 = VtIndex_0c(p4);
        i4 = VtIndex_0c(p2);
        g_table_728b04[i4 + i2 * 6](p1, p4, p5, p2, p3, p6, p7, p8, p10, p9);
        return;
    }
    pc(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
}

// ---------------------------------------------------------------------------
// FUN_00591590  (0x00591590) — 7-arg single-index dispatch over DAT_00728b08
// ---------------------------------------------------------------------------
typedef void (__cdecl *Fn7)(void*, void*, void*, void*, void*, void*, void*);
extern Fn7* g_table_728b08;

void __cdecl FUN_00591590(void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7)
{
    int idx = VtIndex_0c(p2);
    g_table_728b08[idx](p1, p2, p3, p4, p5, p6, p7);
}

// ---------------------------------------------------------------------------
// FUN_005915d0  (0x005915d0) — 12-arg single-index dispatch over DAT_00728b0c
// ---------------------------------------------------------------------------
typedef void (__cdecl *Fn12)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern Fn12* g_table_728b0c;

void __cdecl FUN_005915d0(void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
                          void* p7, void* p8, void* p9, void* p10, void* p11, void* p12)
{
    int idx = VtIndex_0c(p2);
    g_table_728b0c[idx](p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
}

// ---------------------------------------------------------------------------
// FUN_00591630  (0x00591630) — null-guarded indirect call via DAT_00728b14
// ---------------------------------------------------------------------------
typedef void* (__cdecl *Fn0)();
extern Fn0 g_fn_728b14;           // at 0x00728b14

void* __cdecl FUN_00591630(void)
{
    if (!g_fn_728b14)
        return 0;
    return g_fn_728b14();
}

// ---------------------------------------------------------------------------
// FUN_00591640  (0x00591640) — null-guarded indirect 3-arg call via DAT_00728b10
// Observed: fn(*(u32*)(obj+0xc), obj, *(u32*)(obj+0xc))
// ---------------------------------------------------------------------------
typedef void* (__cdecl *Fn3)(void*, void*, void*);
extern Fn3 g_fn_728b10;           // at 0x00728b10

void* __cdecl FUN_00591640(void* obj)
{
    if (!g_fn_728b10)
        return 0;
    void* v = *(void**)((char*)obj + 0xc);
    return g_fn_728b10(v, obj, v);
}

// ---------------------------------------------------------------------------
// FUN_005be900  (0x005be900) / FUN_005be910 (0x005be910) / FUN_005be920
// (0x005be920) — triplet of global dword setters.
// ---------------------------------------------------------------------------
extern unsigned int g_717c64;     // 0x00717c64
extern unsigned int g_717c68;     // 0x00717c68
extern unsigned int g_717c6c;     // 0x00717c6c

void __cdecl FUN_005be900(unsigned int v) { g_717c64 = v; }
void __cdecl FUN_005be910(unsigned int v) { g_717c68 = v; }
void __cdecl FUN_005be920(unsigned int v) { g_717c6c = v; }

// ---------------------------------------------------------------------------
// FUN_005bfa10 (0x005bfa10) / FUN_005bd940 (0x005bd940) / FUN_005be890
// (0x005be890) — global dword getters.
// ---------------------------------------------------------------------------
extern unsigned int g_728d80;     // 0x00728d80
extern unsigned int g_728cf4;     // 0x00728cf4
extern unsigned int g_728cfc;     // 0x00728cfc

unsigned int __cdecl FUN_005bfa10(void) { return g_728d80; }
unsigned int __cdecl FUN_005bd940(void) { return g_728cf4; }
unsigned int __cdecl FUN_005be890(void) { return g_728cfc; }

// ---------------------------------------------------------------------------
// FUN_005d7d60 (0x005d7d60) — global dword setter at 0x00728eb4
// ---------------------------------------------------------------------------
extern unsigned int g_728eb4;     // 0x00728eb4
void __cdecl FUN_005d7d60(unsigned int v) { g_728eb4 = v; }

// ---------------------------------------------------------------------------
// FUN_005c0650 (0x005c0650) — lazy D3D9 bootstrap
// Observed: if (!DAT_00728d74) { if (!DAT_00728d78) {
//   h = LoadLibraryA("D3D9.DLL"); if (!h) return -1;
//   DAT_00728d78 = GetProcAddress(h, "Direct3DCreate9"); if (!fn) return -1; }
//   DAT_00728d74 = fn(0x20); if (!DAT_00728d74) return -1; } return 0;
// ---------------------------------------------------------------------------
extern void* g_d3d9;              // DAT_00728d74
extern FARPROC g_d3dcreate9;      // DAT_00728d78
extern HMODULE g_d3d9dll;         // DAT_00728d70
typedef void* (__cdecl *D3DCreate9Fn)(unsigned int);

int __cdecl FUN_005c0650(void)
{
    if (!g_d3d9) {
        if (!g_d3dcreate9) {
            g_d3d9dll = LoadLibraryA("D3D9.DLL");
            if (!g_d3d9dll)
                return -1;
            g_d3dcreate9 = GetProcAddress(g_d3d9dll, "Direct3DCreate9");
            if (!g_d3dcreate9)
                return -1;
        }
        g_d3d9 = ((D3DCreate9Fn)g_d3dcreate9)(0x20);
        if (!g_d3d9)
            return -1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// FUN_005c5ec0 (0x005c5ec0) — D3D9 device-creation dispatcher (1520 bytes).
// Semantic reconstruction only: behaviour observed is a 13-parameter factory
// that calls FUN_005c0650, allocates renderer/context via FUN_00533c78 +
// FUN_005c5530/FUN_005ccc20, then validates device type, adapter id and
// device validity, emitting the four "Creation failed: ..." strings into
// DAT_00727b30 and finally delegating to FUN_005c06f0. Full control flow
// contains unresolved thiscall/vtable traffic; this candidate preserves the
// observed contract only and MUST NOT be treated as a byte candidate.
// ---------------------------------------------------------------------------
extern char g_err_727b30[256];    // DAT_00727b30
int __cdecl D3D9Init_Proxy(void);
void __cdecl ErrorStr_Proxy(const char*);

void* __cdecl FUN_005c5ec0(void* p1, void* p2, unsigned int flags,
                            int adapter, int dtype, int* mode, void* dev,
                            void* d1, void* d2, void* d3, void* d4, int unk, int mode2)
{
    if (D3D9Init_Proxy() == -1) {
        strncpy(g_err_727b30, "Creation failed: Could not initialize DirectX9", 0xff);
        return 0;
    }
    (void)p1; (void)p2; (void)flags; (void)adapter; (void)dtype;
    (void)mode; (void)dev; (void)d1; (void)d2; (void)d3; (void)d4;
    (void)unk; (void)mode2;
    // UNVERIFIED full factory body; see REPORT.md for unknowns.
    return 0;
}

// ---------------------------------------------------------------------------
// FUN_005bfe80 (0x005bfe80) — identity map 0..16 else 0
// ---------------------------------------------------------------------------
unsigned int __cdecl FUN_005bfe80(unsigned int v)
{
    switch (v) {
    case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 10: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10:
        return v;
    default:
        return 0;
    }
}

// ---------------------------------------------------------------------------
// FUN_005bff40 (0x005bff40) — 0->0x80000000,1->1,2->2,3->4,4->8 else 0
// ---------------------------------------------------------------------------
unsigned int __cdecl FUN_005bff40(unsigned int v)
{
    switch (v) {
    case 0: return 0x80000000u;
    case 1: return 1;
    case 2: return 2;
    case 3: return 4;
    case 4: return 8;
    default: return 0;
    }
}

// ---------------------------------------------------------------------------
// FUN_005d8450 (0x005d8450) — HRESULT -> name table (see REPORT for full map)
// ---------------------------------------------------------------------------
const char* __cdecl FUN_005d8450(unsigned int hr)
{
    if (hr < 0x88760820u) {
        if (hr == 0x8876081fu) return "D3DERR_UNSUPPORTEDFACTORVALUE";
        if (hr < 0x8876081au) {
            if (hr == 0x88760819u) return "D3DERR_UNSUPPORTEDCOLOROPERATION";
            if (hr < 0x80070058u) {
                if (hr == 0x80070057u) return "E_INVALIDARG";
                if (hr == 0x80004005u) return "E_FAIL";
                if (hr == 0x8007000eu) return "E_OUTOFMEMORY";
            } else {
                if (hr == 0x8876017cu) return "D3DERR_OUTOFVIDEOMEMORY";
                if (hr == 0x88760818u) return "D3DERR_WRONGTEXTUREFORMAT";
            }
        } else {
            switch (hr) {
            case 0x8876081au: return "D3DERR_UNSUPPORTEDCOLORARG";
            case 0x8876081bu: return "D3DERR_UNSUPPORTEDALPHAOPERATION";
            case 0x8876081cu: return "D3DERR_UNSUPPORTEDALPHAARG";
            case 0x8876081du: return "D3DERR_TOOMANYOPERATIONS";
            case 0x8876081eu: return "D3DERR_CONFLICTINGTEXTUREFILTER";
            }
        }
    } else {
        switch (hr) {
        case 0x88760821u: return "D3DERR_CONFLICTINGRENDERSTATE";
        case 0x88760822u: return "D3DERR_UNSUPPORTEDTEXTUREFILTER";
        case 0x88760826u: return "D3DERR_CONFLICTINGTEXTUREPALETTE";
        case 0x88760827u: return "D3DERR_DRIVERINTERNALERROR";
        case 0x88760866u: return "D3DERR_NOTFOUND";
        case 0x88760867u: return "D3DERR_MOREDATA";
        case 0x88760868u: return "D3DERR_DEVICELOST";
        case 0x88760869u: return "D3DERR_DEVICENOTRESET";
        case 0x8876086au: return "D3DERR_NOTAVAILABLE";
        case 0x8876086bu: return "D3DERR_INVALIDDEVICE";
        case 0x8876086cu: return "D3DERR_INVALIDCALL";
        }
    }
    return "UNKNOWN!";
}

// ---------------------------------------------------------------------------
// FUN_005cb9d0 (0x005cb9d0) — D3DFMT value -> name table (60 entries).
// FourCC values observed: 0x3154454d MULTI2_ARGB8, 0x34545844 DXT4,
// 0x32595559 YUY2, 0x31545844 DXT1, 0x32545844 DXT2, 0x33545844 DXT3,
// 0x47424752 R8G8_B8G8, 0x35545844 DXT5, 0x42475247 G8R8_G8B8,
// 0x59565955 UYVY. See corpus for full numeric map.
// ---------------------------------------------------------------------------
const char* __cdecl FUN_005cb9d0(int fmt)
{
    if (fmt < 0x3154454e) {
        if (fmt == 0x3154454d) return "D3DFMT_MULTI2_ARGB8";
        switch (fmt) {
        case 0x14: return "D3DFMT_R8G8B8";
        case 0x15: return "D3DFMT_A8R8G8B8";
        case 0x16: return "D3DFMT_X8R8G8B8";
        case 0x17: return "D3DFMT_R5G6B5";
        case 0x18: return "D3DFMT_X1R5G5B5";
        case 0x19: return "D3DFMT_A1R5G5B5";
        case 0x1a: return "D3DFMT_A4R4G4B4";
        case 0x1b: return "D3DFMT_R3G3B2";
        case 0x1c: return "D3DFMT_A8";
        case 0x1d: return "D3DFMT_A8R3G3B2";
        case 0x1e: return "D3DFMT_X4R4G4B4";
        case 0x1f: return "D3DFMT_A2B10G10R10";
        case 0x20: return "D3DFMT_A8B8G8R8";
        case 0x21: return "D3DFMT_X8B8G8R8";
        case 0x22: return "D3DFMT_G16R16";
        case 0x23: return "D3DFMT_A2R10G10B10";
        case 0x24: return "D3DFMT_A16B16G16R16";
        case 0x28: return "D3DFMT_A8P8";
        case 0x29: return "D3DFMT_P8";
        case 0x32: return "D3DFMT_L8";
        case 0x33: return "D3DFMT_A8L8";
        case 0x34: return "D3DFMT_A4L4";
        case 0x3c: return "D3DFMT_V8U8";
        case 0x3d: return "D3DFMT_L6V5U5";
        case 0x3e: return "D3DFMT_X8L8V8U8";
        case 0x3f: return "D3DFMT_Q8W8V8U8";
        case 0x40: return "D3DFMT_V16U16";
        case 0x43: return "D3DFMT_A2W10V10U10";
        case 0x46: return "D3DFMT_D16_LOCKABLE";
        case 0x47: return "D3DFMT_D32";
        case 0x49: return "D3DFMT_D15S1";
        case 0x4b: return "D3DFMT_D24S8";
        case 0x4d: return "D3DFMT_D24X8";
        case 0x4f: return "D3DFMT_D24X4S4";
        case 0x50: return "D3DFMT_D16";
        case 0x51: return "D3DFMT_L16";
        case 0x52: return "D3DFMT_D32F_LOCKABLE";
        case 0x53: return "D3DFMT_D24FS8";
        case 100: return "D3DFMT_VERTEXDATA";
        case 0x65: return "D3DFMT_INDEX16";
        case 0x66: return "D3DFMT_INDEX32";
        case 0x6e: return "D3DFMT_Q16W16V16U16";
        case 0x6f: return "D3DFMT_R16F";
        case 0x70: return "D3DFMT_G16R16F";
        case 0x71: return "D3DFMT_A16B16G16R16F";
        case 0x72: return "D3DFMT_R32F";
        case 0x73: return "D3DFMT_G32R32F";
        case 0x74: return "D3DFMT_A32B32G32R32F";
        case 0x75: return "D3DFMT_CxV8U8";
        }
    } else if (fmt < 0x34545845) {
        if (fmt == 0x34545844) return "D3DFMT_DXT4";
        if (fmt < 0x3259555a) {
            if (fmt == 0x32595559) return "D3DFMT_YUY2";
            if (fmt == 0x31545844) return "D3DFMT_DXT1";
            if (fmt == 0x32545844) return "D3DFMT_DXT2";
        } else if (fmt == 0x33545844) return "D3DFMT_DXT3";
    } else if (fmt < 0x47424753) {
        if (fmt == 0x47424752) return "D3DFMT_R8G8_B8G8";
        if (fmt == 0x35545844) return "D3DFMT_DXT5";
        if (fmt == 0x42475247) return "D3DFMT_G8R8_G8B8";
    } else if (fmt == 0x59565955) return "D3DFMT_UYVY";
    return "UNKNOWN";
}

// ---------------------------------------------------------------------------
// FUN_005da3a0 (0x005da3a0) — refcounted cache resync, returns +0x38
// ---------------------------------------------------------------------------
struct Ref80 {
    unsigned char pad[0x68];
    int count;
};
struct Self_da3 {
    unsigned char pad[0x80];
};
void __thiscall FUN_005bf480(void* self); // forward; defined below

unsigned int __thiscall FUN_005da3a0(void* self)
{
    char* b = (char*)self;
    *(unsigned int*)(b + 0x34) = 0;
    Ref80* held = *(Ref80**)(b + 0x44);
    Ref80* cur = *held;
    Ref80* cached = *(Ref80**)(b + 0x3c);
    if (cached != cur) {
        if (cached) {
            if (--cached->count == 0)
                FUN_005bf480(cached);
        }
        *(Ref80**)(b + 0x3c) = cur;
        if (cur)
            ++cur->count;
    }
    return *(unsigned int*)(b + 0x38);
}

// ---------------------------------------------------------------------------
// FUN_005da3e0 (0x005da3e0) — iterator-advance variant of resync
// ---------------------------------------------------------------------------
int __thiscall FUN_005da3e0(void* self)
{
    char* b = (char*)self;
    Ref80* cached = *(Ref80**)(b + 0x3c);
    if (cached) {
        void** vt = *(void***)cached;
        typedef void (__thiscall *F)(void*, unsigned int);
        F f = (F)vt[3];
        f(cached, *(unsigned int*)(b + 0x34));
    }
    int idx = *(int*)(b + 0x34) + 1;
    *(int*)(b + 0x34) = idx;
    if (idx == *(int*)(b + 0x38))
        return 0;
    Ref80* held = *(Ref80**)(b + 0x44);
    Ref80* cur = *(Ref80**)((char*)held + idx * 4);
    cached = *(Ref80**)(b + 0x3c);
    if (cached != cur) {
        if (cached) {
            if (--cached->count == 0)
                FUN_005bf480(cached);
        }
        *(Ref80**)(b + 0x3c) = cur;
        if (cur)
            ++cur->count;
    }
    return *(int*)(b + 0x38) - *(int*)(b + 0x34);
}

// ---------------------------------------------------------------------------
// FUN_005bf480 (0x005bf480) — multi-slot ref release + heap frees
// ---------------------------------------------------------------------------
static void ReleaseSlot(void** slot)
{
    void* p = *slot;
    if (p) {
        int* cnt = (int*)((char*)p + 4);
        if (--(*cnt) == 0) {
            void** vt = *(void***)p;
            typedef void (__thiscall *Rel)(void*, int);
            Rel r = (Rel)vt[0];
            r(p, 1);
        }
        *slot = 0;
    }
}

void __thiscall FUN_005bf480(void* self)
{
    char* b = (char*)self;
    ReleaseSlot((void**)(b + 0x3c));
    ReleaseSlot((void**)(b + 0x4c));
    ReleaseSlot((void**)(b + 0x50));
    ReleaseSlot((void**)(b + 0x60));
    // FUN_005ca660(*(u32*)(b+0x38)); *(u32*)(b+0x38)=0 (external, unresolved)
    *(unsigned int*)(b + 0x38) = 0;
    operator delete(*(void**)(b + 0x40)); *(void**)(b + 0x40) = 0;
    operator delete(*(void**)(b + 0x44)); *(void**)(b + 0x44) = 0;
    operator delete(*(void**)(b + 0x48)); *(void**)(b + 0x48) = 0;
    operator delete(*(void**)(b + 0x54)); *(void**)(b + 0x54) = 0;
    operator delete(*(void**)(b + 0x58)); *(void**)(b + 0x58) = 0;
    operator delete(*(void**)(b + 0x5c)); *(void**)(b + 0x5c) = 0;
    // FUN_005bf050(); tail zeros and FUN_005bf090(...) external
    *(unsigned int*)(b + 0x14) = 0;
    *(unsigned int*)(b + 0x18) = 0;
    *(unsigned int*)(b + 0x1c) = 0;
    *(unsigned char*)(b + 100) = 0;
}

// ---------------------------------------------------------------------------
// FUN_005bf670 (0x005bf670) — pool pop with refcount touch
// Observed: pool header at DAT_00728d04 (= head,?, free_count, capacity...)
// Quirks preserved: INC then DEC of +0x68 on the popped object.
// ---------------------------------------------------------------------------
extern unsigned int* g_pool_728d04; // DAT_00728d04
void* __cdecl FUN_005bf670(void** out)
{
    unsigned int* pool = g_pool_728d04;
    if (pool[2] == 0) {
        // FUN_005bf560(pool[3]); pool[3] <<= 1;  (grow, external)
        pool[3] <<= 1;
    }
    unsigned int* head = (unsigned int*)*pool;
    int idx = (int)(*(int*)(pool + 1) - 1);
    *(int*)(pool + 1) = idx;
    void* obj = (void*)head[idx];
    if (obj) {
        *(int*)((char*)obj + 0x68) += 1;
        if (*(char*)((char*)obj + 0x65) == 0)
            *(unsigned char*)((char*)obj + 0x65) = 1;
    }
    *out = obj;
    if (obj) {
        int c = *(int*)((char*)obj + 0x68);
        *(int*)((char*)obj + 0x68) = c + 1;
        *(int*)((char*)obj + 0x68) = c;
        if (c == 0)
            FUN_005bf480(obj);
    }
    return *out;
}

// ---------------------------------------------------------------------------
// FUN_005bfa20 (0x005bfa20) — error-string setter into DAT_00727b30
// ---------------------------------------------------------------------------
extern char g_error_727b30[256];

void __cdecl FUN_005bfa20(const char* text)
{
    if (!text) {
        g_error_727b30[0] = 0;
        return;
    }
    strncpy(g_error_727b30, text, 0xff);
    g_error_727b30[0xff] = 0;
}

// ---------------------------------------------------------------------------
// FUN_005bf9b0 (0x005bf9b0) — table read: dst[3] = tab[idx] (12-byte stride)
// ---------------------------------------------------------------------------
extern unsigned int g_tab_728d08[]; // at 0x00728d08

void __cdecl FUN_005bf9b0(void* dst, int idx)
{
    unsigned int* d = (unsigned int*)dst;
    unsigned int* t = g_tab_728d08 + idx * 3;
    d[0] = t[0]; d[1] = t[1]; d[2] = t[2];
}

// ---------------------------------------------------------------------------
// FUN_005bf9e0 (0x005bf9e0) — table write: tab[idx] = {a,b,c}
// ---------------------------------------------------------------------------
void __cdecl FUN_005bf9e0(int idx, unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int* t = g_tab_728d08 + idx * 3;
    t[0] = a; t[1] = b; t[2] = c;
}

// ---------------------------------------------------------------------------
// FUN_005bf990 (0x005bf990) — 8-byte pair read: {DAT_00728d54+idx*8, DAT_00728d50+idx*8}
// ---------------------------------------------------------------------------
typedef struct { unsigned int lo; unsigned int hi; } Pair8_;
extern unsigned int g_pair_lo_728d50[]; // 0x00728d50
extern unsigned int g_pair_hi_728d54[]; // 0x00728d54

Pair8_ __cdecl FUN_005bf990(int idx)
{
    Pair8_ r;
    r.lo = g_pair_lo_728d50[idx];
    r.hi = g_pair_hi_728d54[idx];
    return r;
}

// ---------------------------------------------------------------------------
// FUN_005bfb30 (0x005bfb30) — bounds-checked array fetch (thiscall)
// ---------------------------------------------------------------------------
unsigned int __thiscall FUN_005bfb30(void* self, unsigned int idx)
{
    char* b = (char*)self;
    if (idx < *(unsigned int*)(b + 0x14))
        return *(unsigned int*)(*(unsigned int*)(b + 0x1c) + idx * 4);
    return 0;
}

// ---------------------------------------------------------------------------
// FUN_005bff90 (0x005bff90) — D3D adapter flag mask (thiscall)
// ---------------------------------------------------------------------------
unsigned int __thiscall FUN_005bff90(void* self, int which)
{
    char* b = (char*)self;
    unsigned int base;
    if (which == 1)
        base = *(unsigned int*)(b + 0x468);
    else
        base = *(unsigned int*)(b + 0x46c);
    if (*(int*)(base + 4) == 0)
        return 0;
    return base;
}

// ---------------------------------------------------------------------------
// FUN_00594f50 (0x00594f50) — 3-state matcher
// ---------------------------------------------------------------------------
unsigned int __cdecl FUN_00594f50(int a, char c)
{
    unsigned int u;
    if (a == 0) {
        u = 0;
        if (c) return 1;
    } else if (a == 1) {
        u = 0;
        if (!c) return 1;
    } else {
        u = (unsigned int)(a - 2);
        if (u == 0) return 1;
    }
    return u & 0xffffff00u;
}

// ---------------------------------------------------------------------------
// FUN_0059fcc0 (0x0059fcc0) — emptiness predicate (thiscall)
// ---------------------------------------------------------------------------
int __thiscall FUN_0059fcc0(void* self)
{
    char* b = (char*)self;
    if (*(int*)(b + 0x80) == 0 && *(int*)(b + 0x84) == 0)
        return 0;
    return 1;
}

// ---------------------------------------------------------------------------
// FUN_005c9a50 (0x005c9a50) — vsprintf wrapper (1024-byte stack buffer)
// ---------------------------------------------------------------------------
void __cdecl FUN_005c9a50(const char* fmt, char first)
{
    char buf[1024];
    va_list ap;
    va_start(ap, first);
    vsprintf(buf, fmt, ap);
    va_end(ap);
}

// ---------------------------------------------------------------------------
// FUN_005c9a80 (0x005c9a80) — _splitpath wrapper returning 1
// ---------------------------------------------------------------------------
int __cdecl FUN_005c9a80(char* path, char* drive, char* dir, char* name, char* ext)
{
    _splitpath(path, drive, dir, name, ext);
    return 1;
}

// ---------------------------------------------------------------------------
// FUN_005bfe40 (0x005bfe40) — member test: 0x46/0x49/0x50
// ---------------------------------------------------------------------------
int __cdecl FUN_005bfe40(unsigned int v)
{
    switch (v) {
    case 0x46: case 0x49: case 0x50:
        return 1;
    default:
        return 0;
    }
}

// ---------------------------------------------------------------------------
// FUN_005c00c0 (0x005c00c0) — scalar deleting destructor (thiscall, 1 arg)
// ---------------------------------------------------------------------------
extern void* g_vtable_6c7200; // observed vtable pointer 0x006c7200
void __thiscall BaseDestroy_Proxy(void* self); // base/member destroyer, external

void* __thiscall FUN_005c00c0(void* self, unsigned char flags)
{
    *(void**)self = g_vtable_6c7200;
    BaseDestroy_Proxy(self);
    operator delete(*(void**)((char*)self + 8));
    if (flags & 1)
        operator delete(self);
    return self;
}

// ---------------------------------------------------------------------------
// FUN_005c86f0 (0x005c86f0) — release global handle DAT_00728de4
// ---------------------------------------------------------------------------
extern void* g_handle_728de4; // 0x00728de4
void __cdecl FUN_005c86f0(void)
{
    if (g_handle_728de4) {
        void** vt = *(void***)g_handle_728de4;
        typedef void (__thiscall *Rel)(void*, int);
        Rel r = (Rel)vt[0];
        r(g_handle_728de4, 1);
    }
    g_handle_728de4 = 0;
}

// ---------------------------------------------------------------------------
// FUN_005c8c10 (0x005c8c10) — intrusive list prepend onto DAT_00727868
// ---------------------------------------------------------------------------
extern void* g_list_727868; // 0x00727868
void __cdecl ListLock_Proxy(void);
void __cdecl ListUnlock_Proxy(void);

void __cdecl FUN_005c8c10(void* node)
{
    unsigned int** n = (unsigned int**)node;
    n[2] = 0;
    ListLock_Proxy();
    n[1] = 0;
    *(void**)node = g_list_727868;
    g_list_727868 = node;
    ListUnlock_Proxy();
}
