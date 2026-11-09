// UNVERIFIED: no cl 13.10.3077 on this host. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 6 wave 4 batch 3: owned-string setters + AddRef/Release slots + getter.

#include <stddef.h>

extern void operator_delete__(void* p);
extern void* FUN_00533c78(unsigned int size);

// 0x005dbf40 — owned-string setter at self+0x28: frees old via operator_delete__, allocates copy via FUN_00533c78, stores pointer. Non-empty check; else stores 0. Self-assign guard.
extern "C" void __thiscall Band6Wave4_SetString_5dbf40(void* self_, const char* src) {
    unsigned char* base = (unsigned char*)self_;
    char** slot = (char**)(base + 0x28);
    if (*slot != src) {
        operator_delete__(*slot);
        if (src != (const char*)0 && *src != '\0') {
            const char* p = src;
            do { p++; } while (*(p - 1) != '\0');
            unsigned int len = (unsigned int)(p - src);
            char* dst = (char*)FUN_00533c78(len);
            const char* q = src;
            char* d = dst;
            do {
                char c = *q;
                *d = c;
                q++;
                d++;
            } while (c != '\0');
            *slot = dst;
            return;
        }
        *slot = 0;
    }
}

// 0x005dc150 — shader-wrapper getter: returns word at self+0x3c.
extern "C" int __thiscall Band6Wave4_Get_5dc150(void* self_) {
    const unsigned char* base = (const unsigned char*)self_;
    return *reinterpret_cast<const int*>(base + 0x3c);
}


// 0x005dbfb0 — owned-string setter at self+0x2c: frees old, allocates copy via FUN_00533c78. Self-assign guard; no null-store branch observed.
extern "C" void __thiscall Band6Wave4_SetString_5dbfb0(void* self_, const char* src) {
    unsigned char* base = (unsigned char*)self_;
    char** slot = (char**)(base + 0x2c);
    if (*slot != src) {
        operator_delete__(*slot);
        if (src != (const char*)0 && *src != '\0') {
            const char* p = src;
            do { p++; } while (*(p - 1) != '\0');
            unsigned int len = (unsigned int)(p - src);
            char* dst = (char*)FUN_00533c78(len);
            const char* q = src;
            char* d = dst;
            do {
                char c = *q;
                *d = c;
                q++;
                d++;
            } while (c != '\0');
            *slot = dst;
        }
    }
}

// 0x005dc080 — owned-string setter at self+0x34: frees old, allocates copy; else stores 0. Self-assign guard.
extern "C" void __thiscall Band6Wave4_SetString_5dc080(void* self_, const char* src) {
    unsigned char* base = (unsigned char*)self_;
    char** slot = (char**)(base + 0x34);
    if (*slot != src) {
        operator_delete__(*slot);
        if (src != (const char*)0 && *src != '\0') {
            const char* p = src;
            do { p++; } while (*(p - 1) != '\0');
            unsigned int len = (unsigned int)(p - src);
            char* dst = (char*)FUN_00533c78(len);
            const char* q = src;
            char* d = dst;
            do {
                char c = *q;
                *d = c;
                q++;
                d++;
            } while (c != '\0');
            *slot = dst;
            return;
        }
        *slot = 0;
    }
}

// 0x005dc0f0 — owned-string setter at self+0x38: frees old, allocates copy. Self-assign guard; no null-store branch observed.
extern "C" void __thiscall Band6Wave4_SetString_5dc0f0(void* self_, const char* src) {
    unsigned char* base = (unsigned char*)self_;
    char** slot = (char**)(base + 0x38);
    if (*slot != src) {
        operator_delete__(*slot);
        if (src != (const char*)0 && *src != '\0') {
            const char* p = src;
            do { p++; } while (*(p - 1) != '\0');
            unsigned int len = (unsigned int)(p - src);
            char* dst = (char*)FUN_00533c78(len);
            const char* q = src;
            char* d = dst;
            do {
                char c = *q;
                *d = c;
                q++;
                d++;
            } while (c != '\0');
            *slot = dst;
        }
    }
}

// 0x005dce00 — hub query: virtual +0x18 -> validate via FUN_005de050 -> virtual +0x34. Observed return 1/0.
extern "C" int __thiscall Band6Wave4_Query_5dce00(void* self_) {
    int* obj = (int*)self_;
    typedef int (__thiscall *V18)(void*);
    typedef void (__thiscall *V34)(void*, int);
    extern int __thiscall FUN_005de050(int);
    int first = ((V18)(*(int**)obj)[0x18 / 4])(obj);
    if (first != 0) {
        int second = FUN_005de050(first);
        if (second != 0) {
            ((V34)(*(int**)obj)[0x34 / 4])(obj, second);
            return 1;
        }
    }
    return 0;
}
