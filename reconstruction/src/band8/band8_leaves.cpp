// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
// Band 8: bundled D3DX9 shader-compiler leaves. Third-party bundling: see REPORT.md.
#include <stddef.h>

// 0x00673e38
int __stdcall FUN_00673e38(const int* a, const int* b) {
    for (int i = 0; i < 4; ++i)
        if (a[i] != -1 && a[i] != b[i]) return 0;
    return 1;
}

// 0x0069edd0
int __stdcall FUN_0069edd0(int x) { return x; }

// 0x006ae2d0
int __stdcall FUN_006ae2d0(int* obj, int, int, int sub) {
    int* p = *reinterpret_cast<int**>(obj + 1);
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x2c) - sub;
}

// 0x006ae430
int __stdcall FUN_006ae430(int /*ignored*/) { return 1000000; }
