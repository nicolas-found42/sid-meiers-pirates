// Crouton Alpha Band 5 reconstructed headers
// Clean-room, unverified. No cl 13.10.3077. No PASS.
#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// ---- dispatch family (FUN_00591460 etc.) ----
// Observed: vtable slot 0x0c index functions forwarded via DAT_00728b00 tables.
typedef void (*DispatchFn_591460)(void*, void*, void*, void*, void*);
typedef void (*DispatchFn_5914e0)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
typedef void (*DispatchFn_591590)(void*, void*, void*, void*, void*, void*, void*);
typedef void (*DispatchFn_5915d0)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);

void __cdecl FUN_00591460(void* p1, void* p2, void* p3, void* p4, void* p5);
void __cdecl FUN_005914e0(void* p1, void* p2, void* p3, void* p4, void* p5,
                          void* p6, void* p7, void* p8, void* p9, void* p10);
void __cdecl FUN_00591590(void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void __cdecl FUN_005915d0(void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
                          void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void* __cdecl FUN_00591630(void);
void* __cdecl FUN_00591640(void* obj);

// ---- global accessors ----
void __cdecl FUN_005be900(unsigned int v);
void __cdecl FUN_005be910(unsigned int v);
void __cdecl FUN_005be920(unsigned int v);
unsigned int __cdecl FUN_005bfa10(void);
unsigned int __cdecl FUN_005bd940(void);
unsigned int __cdecl FUN_005be890(void);
void __cdecl FUN_005d7d60(unsigned int v);

// ---- D3D platform ----
int __cdecl FUN_005c0650(void);
void* __cdecl FUN_005c5ec0(void*, void*, unsigned int, int, int, void*, void*, void*, void*, void*, void*, int, int); /* semantic-only, unverified */
unsigned int __cdecl FUN_005bfe80(unsigned int v);
unsigned int __cdecl FUN_005bff40(unsigned int v);
const char* __cdecl FUN_005d8450(unsigned int hr);
const char* __cdecl FUN_005cb9d0(int fmt);

// ---- refcount / pool ----
unsigned int __thiscall FUN_005da3a0(void* self);
int __thiscall FUN_005da3e0(void* self);
void __thiscall FUN_005bf480(void* self);
void* __cdecl FUN_005bf670(void** out);

// ---- predicates / tiny helpers ----
void __cdecl FUN_005bfa20(const char* text);
void __cdecl FUN_005bf9b0(void* dst12, int idx);
void __cdecl FUN_005bf9e0(int idx, unsigned int a, unsigned int b, unsigned int c);
typedef struct { unsigned int lo; unsigned int hi; } Pair8;
Pair8 __cdecl FUN_005bf990(int idx);
unsigned int __thiscall FUN_005bfb30(void* self, unsigned int idx);
unsigned int __thiscall FUN_005bff90(void* self, int which);
unsigned int __cdecl FUN_00594f50(int a, char b);
int __thiscall FUN_0059fcc0(void* self);

// ---- CRT-ish wrappers ----
void __cdecl FUN_005c9a50(const char* fmt, char first);
int __cdecl FUN_005c9a80(char* path, char* drive, char* dir, char* name, char* ext);
int __cdecl FUN_005bfe40(unsigned int v);

// ---- lifecycle ----
void* __thiscall FUN_005c00c0(void* self, unsigned char flags);
void __cdecl FUN_005c86f0(void);
void __cdecl FUN_005c8c10(void* node);

#ifdef __cplusplus
}
#endif
