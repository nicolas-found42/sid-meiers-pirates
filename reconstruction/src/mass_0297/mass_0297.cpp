// Reconstruction batch mass_0297
// Source candidate definitions derived from Ghidra 12.2 pseudocode listings.
#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef uint32_t undefined4;

// 0x63fb92 — observed shape
HRESULT FUN_0063fb92(int* param_1, float* param_2, float* param_3)
{
    float* dst = param_2;
    int fmt = *param_1;
    if (fmt == 1) {
        for (int row = 0; row < 4; ++row) {
            for (int i = 0; i < 4; ++i) {
                dst[row + i * 4] = (float)(uint32_t)(param_3[row * 4 + i] != 0.0f);
            }
        }
    }
    else if (fmt == 2) {
        for (int row = 0; row < 4; ++row) {
            for (int i = 0; i < 4; ++i) {
                dst[row + i * 4] = (float)(int32_t)param_3[row * 4 + i];
            }
        }
    }
    else {
        if (fmt != 3) {
            return 0x80004005;
        }
        param_3 = param_3 + 8;
        for (int i = 0; i < 4; ++i) {
            dst[0] = param_3[-8];
            dst[1] = param_3[-4];
            dst[2] = param_3[0];
            dst[3] = param_3[4];
            dst = dst + 4;
            param_3 = param_3 + 1;
        }
    }
    return 0;
}

// 0x63fc54 — observed shape
HRESULT FUN_0063fc54(int* param_1, float* param_2, float* param_3, float* param_4)
{
    int fmt = *param_1;
    if (fmt == 1) {
        if (param_4 != (float*)0x0) {
            int count = (int)param_4;
            do {
                for (int row = 0; row < 4; ++row) {
                    for (int i = 0; i < 4; ++i) {
                        param_2[row + i * 4] = (float)(uint32_t)(param_3[row * 4 + i] != 0.0f);
                    }
                }
                param_3 = param_3 + 0x10;
                param_2 = param_2 + 0x10;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if (fmt == 2) {
        if (param_4 != (float*)0x0) {
            int count = (int)param_4;
            do {
                for (int row = 0; row < 4; ++row) {
                    for (int i = 0; i < 4; ++i) {
                        param_2[row + i * 4] = (float)(int32_t)param_3[row * 4 + i];
                    }
                }
                param_2 = param_2 + 0x10;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if ((fmt == 3) && (param_4 != (float*)0x0)) {
        float* src = param_3 + 8;
        int count = (int)param_4;
        do {
            float* d = param_2;
            float* s = src;
            for (int i = 0; i < 4; ++i) {
                d[0] = s[-8];
                d[1] = s[-4];
                d[2] = s[0];
                d[3] = s[4];
                d = d + 4;
                s = s + 1;
            }
            param_2 = param_2 + 0x10;
            src = src + 0x10;
            count = count - 1;
        } while (count != 0);
    }
    return 0;
}

// 0x63fd69 — observed shape
HRESULT FUN_0063fd69(int* param_1, int param_2, float* param_3, uint32_t param_4)
{
    float* pfVar7 = param_3;
    int fmt = *param_1;
    uint32_t* puVar1 = (uint32_t*)(param_1 + 5);
    uint32_t* puVar2 = (uint32_t*)(param_1 + 6);
    HRESULT local_c = 0;
    uint32_t width = 4;
    if (*puVar2 < 5) {
        width = *puVar2;
    }
    uint32_t height = 4;
    if (*puVar1 < 5) {
        height = *puVar1;
    }
    if (fmt == 1) {
        for (int i = (int)((param_4 & 0x3ffffff) << 4); i != 0; i = i - 1) {
            *param_3 = 0.0f;
            param_3 = param_3 + 1;
        }
        if (param_4 != 0) {
            uint32_t count = param_4;
            do {
                if (width != 0) {
                    float* row = pfVar7;
                    uint32_t rows = width;
                    do {
                        float* p = row;
                        uint32_t n = height;
                        do {
                            *p = (float)(*(int*)((int)p + (param_2 - (int)pfVar7)) != 0);
                            p = p + 1;
                            n = n - 1;
                        } while (n != 0);
                        row = row + 4;
                        rows = rows - 1;
                    } while (rows != 0);
                }
                param_2 = param_2 + 0x40;
                pfVar7 = pfVar7 + 0x10;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if (fmt == 2) {
        for (int i = (int)((param_4 & 0x3ffffff) << 4); i != 0; i = i - 1) {
            *pfVar7 = 0.0f;
            pfVar7 = pfVar7 + 1;
        }
        if (param_4 != 0) {
            uint32_t count = param_4;
            do {
                if (width != 0) {
                    float* row = param_3;
                    uint32_t rows = width;
                    do {
                        float* p = row;
                        uint32_t n = height;
                        do {
                            *p = (float)*(int*)((int)p + (param_2 - (int)param_3));
                            p = p + 1;
                            n = n - 1;
                        } while (n != 0);
                        row = row + 4;
                        rows = rows - 1;
                    } while (rows != 0);
                }
                param_2 = param_2 + 0x40;
                param_3 = param_3 + 0x10;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if (fmt == 3) {
        for (int i = (int)((param_4 & 0x3ffffff) << 4); i != 0; i = i - 1) {
            *pfVar7 = 0.0f;
            pfVar7 = pfVar7 + 1;
        }
        if (param_4 != 0) {
            uint32_t count = param_4;
            do {
                if (width != 0) {
                    float* row = param_3;
                    uint32_t rows = width;
                    do {
                        float* p = row;
                        uint32_t n = height;
                        do {
                            *p = *(float*)((param_2 - (int)param_3) + (int)p);
                            p = p + 1;
                            n = n - 1;
                        } while (n != 0);
                        row = row + 4;
                        rows = rows - 1;
                    } while (rows != 0);
                }
                param_2 = param_2 + 0x40;
                param_3 = param_3 + 0x10;
                count = count - 1;
            } while (count != 0);
        }
    }
    else {
        local_c = (HRESULT)0x8876086c;
    }
    return local_c;
}

// 0x63fee8 — observed shape
HRESULT FUN_0063fee8(int* param_1, float* param_2, float* param_3, uint32_t param_4)
{
    HRESULT local_10 = 0;
    int fmt = *param_1;
    uint32_t* puVar1 = (uint32_t*)(param_1 + 6);
    uint32_t height = 4;
    if ((uint32_t)param_1[5] < 5) {
        height = (uint32_t)param_1[5];
    }
    uint32_t width = 4;
    if (*puVar1 < 5) {
        width = *puVar1;
    }
    if (fmt == 1) {
        float* out = param_3;
        for (int i = (int)((param_4 & 0x3ffffff) << 4); i != 0; i = i - 1) {
            *out = 0.0f;
            out = out + 1;
        }
        if (param_4 != 0) {
            uint32_t count = param_4;
            do {
                if (width != 0) {
                    float* src = param_2;
                    float* dst = param_3;
                    uint32_t rows = width;
                    do {
                        if (height != 0) {
                            float* d = dst;
                            float* s = src;
                            uint32_t n = height;
                            do {
                                float f = *s;
                                s = s + 1;
                                *d = (float)(f != 0.0f);
                                d = d + 4;
                                n = n - 1;
                            } while (n != 0);
                        }
                        src = src + 4;
                        dst = dst + 1;
                        rows = rows - 1;
                    } while (rows != 0);
                }
                param_2 = param_2 + 0x10;
                param_3 = param_3 + 0x10;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if (fmt == 2) {
        float* out = param_3;
        for (int i = (int)((param_4 & 0x3ffffff) << 4); i != 0; i = i - 1) {
            *out = 0.0f;
            out = out + 1;
        }
        if (param_4 != 0) {
            uint32_t count = param_4;
            do {
                if (width != 0) {
                    float* src = param_2;
                    float* dst = param_3;
                    uint32_t rows = width;
                    do {
                        if (height != 0) {
                            float* d = dst;
                            float* s = src;
                            uint32_t n = height;
                            do {
                                float f = *s;
                                s = s + 1;
                                *d = (float)(int)f;
                                d = d + 4;
                                n = n - 1;
                            } while (n != 0);
                        }
                        src = src + 4;
                        dst = dst + 1;
                        rows = rows - 1;
                    } while (rows != 0);
                }
                param_2 = param_2 + 0x10;
                param_3 = param_3 + 0x10;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if (fmt == 3) {
        float* out = param_3;
        for (int i = (int)((param_4 & 0x3ffffff) << 4); i != 0; i = i - 1) {
            *out = 0.0f;
            out = out + 1;
        }
        if (param_4 != 0) {
            uint32_t count = param_4;
            do {
                if (width != 0) {
                    float* src = param_2;
                    float* dst = param_3;
                    uint32_t rows = width;
                    do {
                        if (height != 0) {
                            float* d = dst;
                            float* s = src;
                            uint32_t n = height;
                            do {
                                *d = *s;
                                d = d + 4;
                                s = s + 1;
                                n = n - 1;
                            } while (n != 0);
                        }
                        src = src + 4;
                        dst = dst + 1;
                        rows = rows - 1;
                    } while (rows != 0);
                }
                param_2 = param_2 + 0x10;
                param_3 = param_3 + 0x10;
                count = count - 1;
            } while (count != 0);
        }
    }
    else {
        local_10 = (HRESULT)0x8876086c;
    }
    return local_10;
}

// 0x64007b — observed shape
HRESULT FUN_0064007b(int* param_1, int param_2, int* param_3, int param_4)
{
    HRESULT local_8 = 0;
    int fmt = *param_1;
    if (fmt == 1) {
        if (param_4 != 0) {
            do {
                uint32_t offset = 0;
                if (*param_3 != 0) {
                    do {
                        for (int i = 0; i < 4; ++i) {
                            *(uint32_t*)(offset + param_2) =
                                (uint32_t)(*(float*)(offset + *param_3) != 0.0f);
                            offset = offset + 4;
                        }
                    } while (offset < 0x40);
                }
                param_2 = param_2 + 0x40;
                param_3 = param_3 + 1;
                param_4 = param_4 - 1;
            } while (param_4 != 0);
        }
    }
    else if (fmt == 2) {
        if (param_4 != 0) {
            int count = param_4;
            do {
                uint32_t offset = 0;
                if (*param_3 != 0) {
                    do {
                        for (int i = 0; i < 4; ++i) {
                            *(uint32_t*)(offset + param_2) =
                                (uint32_t)(int32_t)*(float*)(offset + *param_3);
                            offset = offset + 4;
                        }
                    } while (offset < 0x40);
                }
                param_2 = param_2 + 0x40;
                param_3 = param_3 + 1;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if (fmt == 3) {
        if (param_4 != 0) {
            do {
                uint32_t offset = 0;
                if (*param_3 != 0) {
                    do {
                        for (int i = 0; i < 4; ++i) {
                            *(uint32_t*)(offset + param_2) = *(uint32_t*)(offset + *param_3);
                            offset = offset + 4;
                        }
                    } while (offset < 0x40);
                }
                param_2 = param_2 + 0x40;
                param_3 = param_3 + 1;
                param_4 = param_4 - 1;
            } while (param_4 != 0);
        }
    }
    else {
        local_8 = (HRESULT)0x8876086c;
    }
    return local_8;
}

// 0x64017b — observed shape
HRESULT FUN_0064017b(int* param_1, uint32_t* param_2, uint32_t* param_3, uint32_t param_4)
{
    int fmt = *param_1;
    HRESULT local_c = 0;
    if (fmt == 1) {
        for (uint32_t slice = param_4; slice != 0; slice = slice - 1) {
            uint32_t off = 0;
            if (*param_3 != 0) {
                uint32_t* row = param_2;
                do {
                    uint32_t* p = row;
                    for (int i = 0; i < 4; ++i) {
                        *p = (uint32_t)(*(float*)(off + *param_3) != 0.0f);
                        p = p + 4;
                        off = off + 4;
                    }
                    row = row + 1;
                } while (off < 0x40);
            }
            param_2 = param_2 + 0x10;
            param_3 = param_3 + 1;
        }
    }
    else if (fmt == 2) {
        for (uint32_t slice = param_4; slice != 0; slice = slice - 1) {
            uint32_t off = 0;
            if (*param_3 != 0) {
                uint32_t* row = param_2;
                do {
                    uint32_t* p = row;
                    for (int i = 0; i < 4; ++i) {
                        *p = (uint32_t)(int32_t)*(float*)(off + *param_3);
                        p = p + 4;
                        off = off + 4;
                    }
                    row = row + 1;
                } while (off < 0x40);
            }
            param_2 = param_2 + 0x10;
            param_3 = param_3 + 1;
        }
    }
    else if (fmt == 3) {
        for (uint32_t slice = param_4; slice != 0; slice = slice - 1) {
            uint32_t off = 0;
            if (*param_3 != 0) {
                uint32_t* row = param_2;
                do {
                    uint32_t* p = row;
                    for (int i = 0; i < 4; ++i) {
                        uint32_t* src = (uint32_t*)(off + *param_3);
                        off = off + 4;
                        *p = *src;
                        p = p + 4;
                    }
                    row = row + 1;
                } while (off < 0x40);
            }
            param_2 = param_2 + 0x10;
            param_3 = param_3 + 1;
        }
    }
    else {
        local_c = (HRESULT)0x8876086c;
    }
    return local_c;
}

// 0x6402aa — observed shape
HRESULT FUN_006402aa(int* param_1, int param_2, int* param_3, int param_4)
{
    int fmt = *param_1;
    uint32_t* puVar1 = (uint32_t*)(param_1 + 5);
    uint32_t* puVar2 = (uint32_t*)(param_1 + 6);
    HRESULT local_c = 0;
    uint32_t rows = 4;
    if (*puVar2 < 5) {
        rows = *puVar2;
    }
    uint32_t cols = 4;
    if (*puVar1 < 5) {
        cols = *puVar1;
    }
    if (fmt == 1) {
        for (; param_4 != 0; param_4 = param_4 - 1) {
            if ((undefined4*)*param_3 != (undefined4*)0x0) {
                undefined4* pz = (undefined4*)*param_3;
                for (int i = 0x10; i != 0; i = i - 1) {
                    *pz = 0;
                    pz = pz + 1;
                }
                uint32_t r = 0;
                do {
                    if (cols != 0) {
                        int off = (int)(r << 4);
                        uint32_t c = cols;
                        do {
                            *(float*)(off + *param_3) = (float)(*(int*)(off + param_2) != 0);
                            off = off + 4;
                            c = c - 1;
                        } while (c != 0);
                    }
                    r = r + 1;
                } while (r < rows);
            }
            param_2 = param_2 + 0x40;
            param_3 = param_3 + 1;
        }
    }
    else if (fmt == 2) {
        for (; param_4 != 0; param_4 = param_4 - 1) {
            if ((undefined4*)*param_3 != (undefined4*)0x0) {
                undefined4* pz = (undefined4*)*param_3;
                for (int i = 0x10; i != 0; i = i - 1) {
                    *pz = 0;
                    pz = pz + 1;
                }
                uint32_t r = 0;
                do {
                    if (cols != 0) {
                        int off = (int)(r << 4);
                        uint32_t c = cols;
                        do {
                            *(float*)(off + *param_3) = (float)*(int*)(off + param_2);
                            off = off + 4;
                            c = c - 1;
                        } while (c != 0);
                    }
                    r = r + 1;
                } while (r < rows);
            }
            param_2 = param_2 + 0x40;
            param_3 = param_3 + 1;
        }
    }
    else if (fmt == 3) {
        for (; param_4 != 0; param_4 = param_4 - 1) {
            if ((undefined4*)*param_3 != (undefined4*)0x0) {
                undefined4* pz = (undefined4*)*param_3;
                for (int i = 0x10; i != 0; i = i - 1) {
                    *pz = 0;
                    pz = pz + 1;
                }
                uint32_t r = 0;
                do {
                    if (cols != 0) {
                        int off = (int)(r << 4);
                        uint32_t c = cols;
                        do {
                            *(undefined4*)(off + *param_3) = *(undefined4*)(off + param_2);
                            off = off + 4;
                            c = c - 1;
                        } while (c != 0);
                    }
                    r = r + 1;
                } while (r < rows);
            }
            param_2 = param_2 + 0x40;
            param_3 = param_3 + 1;
        }
    }
    else {
        local_c = (HRESULT)0x8876086c;
    }
    return local_c;
}

// 0x640408 — observed shape
HRESULT FUN_00640408(int* param_1, int* param_2, int* param_3, int* param_4)
{
    HRESULT local_10 = 0;
    int fmt = *param_1;
    uint32_t* puVar1 = (uint32_t*)(param_1 + 6);
    uint32_t cols = 4;
    if ((uint32_t)param_1[5] < 5) {
        cols = (uint32_t)param_1[5];
    }
    uint32_t rows = 4;
    if (*puVar1 < 5) {
        rows = *puVar1;
    }
    if (fmt == 1) {
        if (param_4 != (int*)0x0) {
            int count = (int)param_4;
            do {
                if ((undefined4*)*param_3 != (undefined4*)0x0) {
                    uint32_t r = 0;
                    undefined4* pz = (undefined4*)*param_3;
                    for (int i = 0x10; i != 0; i = i - 1) {
                        *pz = 0;
                        pz = pz + 1;
                    }
                    if (rows != 0) {
                        int* src = param_2;
                        do {
                            if (cols != 0) {
                                int off = (int)(r << 2);
                                int* s = src;
                                uint32_t c = cols;
                                do {
                                    *(float*)(off + *param_3) = (float)(*s != 0);
                                    off = off + 0x10;
                                    s = s + 1;
                                    c = c - 1;
                                } while (c != 0);
                            }
                            src = src + 4;
                            r = r + 1;
                        } while (r < rows);
                    }
                }
                param_2 = param_2 + 0x10;
                param_3 = param_3 + 1;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if (fmt == 2) {
        if (param_4 != (int*)0x0) {
            int count = (int)param_4;
            do {
                if ((undefined4*)*param_3 != (undefined4*)0x0) {
                    uint32_t r = 0;
                    undefined4* pz = (undefined4*)*param_3;
                    for (int i = 0x10; i != 0; i = i - 1) {
                        *pz = 0;
                        pz = pz + 1;
                    }
                    if (rows != 0) {
                        int* src = param_2;
                        do {
                            if (cols != 0) {
                                int off = (int)(r << 2);
                                int* s = src;
                                uint32_t c = cols;
                                do {
                                    *(float*)(off + *param_3) = (float)*s;
                                    off = off + 0x10;
                                    s = s + 1;
                                    c = c - 1;
                                } while (c != 0);
                            }
                            src = src + 4;
                            r = r + 1;
                        } while (r < rows);
                    }
                }
                param_2 = param_2 + 0x10;
                param_3 = param_3 + 1;
                count = count - 1;
            } while (count != 0);
        }
    }
    else if (fmt == 3) {
        if (param_4 != (int*)0x0) {
            int count = (int)param_4;
            do {
                if ((undefined4*)*param_3 != (undefined4*)0x0) {
                    uint32_t r = 0;
                    undefined4* pz = (undefined4*)*param_3;
                    for (int i = 0x10; i != 0; i = i - 1) {
                        *pz = 0;
                        pz = pz + 1;
                    }
                    if (rows != 0) {
                        int* src = param_2;
                        do {
                            if (cols != 0) {
                                int off = (int)(r << 2);
                                int* s = src;
                                uint32_t c = cols;
                                do {
                                    *(int*)(off + *param_3) = *s;
                                    off = off + 0x10;
                                    s = s + 1;
                                    c = c - 1;
                                } while (c != 0);
                            }
                            src = src + 4;
                            r = r + 1;
                        } while (r < rows);
                    }
                }
                param_2 = param_2 + 0x10;
                param_3 = param_3 + 1;
                count = count - 1;
            } while (count != 0);
        }
    }
    else {
        local_10 = (HRESULT)0x8876086c;
    }
    return local_10;
}

// --- shared COM vtable helpers used by the state-block definitions below ---
static inline void com_addref(void* p)
{
    ((void(__stdcall*)(void*))(*(void***)p)[1])(p);
}

static inline void com_release(void* p)
{
    ((void(__stdcall*)(void*))(*(void***)p)[2])(p);
}

static inline uint32_t com_call3(void* p)
{
    return ((uint32_t(__stdcall*)(void*))(*(void***)p)[3])(p);
}

extern int FUN_0063e62c(void* state);
extern int FUN_0063e5ce(void* state);
extern int FUN_0063f9ca(uint32_t src, uint32_t dst, uint32_t desc);
extern int FUN_0063f926(uint32_t src, uint32_t dst, uint32_t desc);
extern int FUN_0063f86e(uint32_t src, uint32_t dst, uint32_t desc);
extern void* PTR_LAB_006ec270;

// 0x64058d — observed shape
int FUN_0064058d(void* self, int* param_1, int* param_2, int* param_3, int param_4, int param_5, int param_6)
{
    uint8_t* s = (uint8_t*)self;
    int* piVar1 = (int*)*param_1;
    int local_c = 0;
    int iVar2 = *piVar1;
    int local_8 = piVar1[4];
    int iVar4 = piVar1[1];
    if (local_8 == 0) {
        local_8 = 1;
    }
    if (-1 < iVar4) {
        if (iVar4 < 4) {
            uint32_t uVar3 = (uint32_t)piVar1[6] * (uint32_t)piVar1[5] * (uint32_t)local_8;
            if (((iVar2 != 1) && (iVar2 != 2)) && (iVar2 != 3)) {
                return -0x7fffbffb;
            }
            int byteLen = (int)uVar3 * 4;
            undefined4* puVar6 = (undefined4*)*param_3;
            undefined4* puVar7 = (undefined4*)*param_2;
            for (uint32_t n = uVar3 & 0x3fffffff; n != 0; n = n - 1) {
                *puVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar7 = puVar7 + 1;
            }
            int rem = 0;
            for (; rem != 0; rem = rem - 1) {
                *(uint8_t*)puVar7 = *(uint8_t*)puVar6;
                puVar6 = (undefined4*)((int)puVar6 + 1);
                puVar7 = (undefined4*)((int)puVar7 + 1);
            }
            *param_2 = *param_2 + byteLen;
            *param_3 = *param_3 + byteLen;
            *param_1 = *param_1 + 0x1c;
            return 0;
        }
        if (iVar4 != 4) {
            if (iVar4 != 5) {
                return -0x7fffbffb;
            }
            uint32_t uVar3 = (uint32_t)piVar1[5];
            *param_1 = (int)(piVar1 + 6);
            for (;;) {
                if (local_8 == 0) {
                    return local_c;
                }
                uint32_t uVar5 = 0;
                *param_1 = (int)(piVar1 + 6);
                if (uVar3 != 0) {
                    do {
                        local_c = FUN_0064058d(self, param_1, param_2, param_3, param_4, param_5, param_6);
                        if (local_c < 0) {
                            return local_c;
                        }
                        uVar5 = uVar5 + 1;
                    } while (uVar5 < uVar3);
                }
                local_8 = local_8 - 1;
            }
        }
        bool bVar9;
        bool bVar8;
        if (iVar2 < 0x10) {
            if (iVar2 == 0xf) {
                for (; local_8 != 0; local_8 = local_8 - 1) {
                    int srcIdx;
                    if (param_5 == 0) {
                        srcIdx = *(int*)*param_3;
                    }
                    else {
                        srcIdx = *(int*)(*(int*)(param_5 + 8) + *(int*)*param_3 * 4);
                    }
                    int src = *(int*)(param_6 + 0x18) + srcIdx * 0x18;
                    int dstIdx;
                    if (param_4 == 0) {
                        dstIdx = *(int*)*param_2;
                    }
                    else {
                        dstIdx = *(int*)(*(int*)(param_4 + 8) + *(int*)*param_2 * 4);
                    }
                    int dst = *(int*)(s + 0x18) + dstIdx * 0x18;
                    if (*(int*)(src + 8) != 0) {
                        com_addref(*(void**)(src + 8));
                    }
                    piVar1 = *(int**)(dst + 8);
                    if (piVar1 != (int*)0x0) {
                        com_release(piVar1);
                        *(undefined4*)(dst + 8) = 0;
                    }
                    *(undefined4*)(dst + 8) = *(undefined4*)(src + 8);
                    *(undefined4*)(dst + 0xc) = *(undefined4*)(src + 0xc);
                    if ((*(int*)(s + 0xc) == *(int*)(param_6 + 0xc)) || (*(int*)(src + 8) == 0)) {
                        if (*(int*)(src + 4) != 0) {
                            com_addref(*(void**)(src + 4));
                        }
                        piVar1 = *(int**)(dst + 4);
                        if (piVar1 != (int*)0x0) {
                            com_release(piVar1);
                            *(undefined4*)(dst + 4) = 0;
                        }
                        *(undefined4*)(dst + 4) = *(undefined4*)(src + 4);
                        *(uint32_t*)(dst + 0x14) =
                            *(uint32_t*)(dst + 0x14) ^
                            (((*(int*)(src + 0x14) << 0x1e) >> 0x1e) ^ *(uint32_t*)(dst + 0x14)) & 2;
                    }
                    else {
                        piVar1 = *(int**)(dst + 4);
                        if (piVar1 != (int*)0x0) {
                            com_release(piVar1);
                            *(undefined4*)(dst + 4) = 0;
                        }
                        if (param_4 != 0) {
                            return -0x7fffbffb;
                        }
                        FUN_0063e62c((void*)dst);
                    }
                    *param_2 = *param_2 + 4;
                    *param_3 = *param_3 + 4;
                }
                goto LAB_006409d3;
            }
            if (iVar2 == 4) {
                if (local_8 != 0) {
                    do {
                        int srcIdx;
                        if (param_5 == 0) {
                            srcIdx = *(int*)*param_3;
                        }
                        else {
                            srcIdx = *(int*)(*(int*)(param_5 + 8) + *(int*)*param_3 * 4);
                        }
                        int src = *(int*)(param_6 + 0x18) + srcIdx * 0x18;
                        int dstIdx;
                        if (param_4 == 0) {
                            dstIdx = *(int*)*param_2;
                        }
                        else {
                            dstIdx = *(int*)(*(int*)(param_4 + 8) + *(int*)*param_2 * 4);
                        }
                        int dst = *(int*)(s + 0x18) + dstIdx * 0x18;
                        if (*(int*)(src + 4) != 0) {
                            com_addref(*(void**)(src + 4));
                        }
                        piVar1 = *(int**)(dst + 4);
                        if (piVar1 != (int*)0x0) {
                            com_release(piVar1);
                            *(undefined4*)(dst + 4) = 0;
                        }
                        *(undefined4*)(dst + 4) = *(undefined4*)(src + 4);
                        *param_2 = *param_2 + 4;
                        *param_3 = *param_3 + 4;
                        local_8 = local_8 - 1;
                    } while (local_8 != 0);
                }
                goto LAB_006409d3;
            }
            if (iVar2 < 5) {
                return -0x7fffbffb;
            }
            if (iVar2 < 10) {
                if (local_8 != 0) {
                    do {
                        int srcIdx;
                        if (param_5 == 0) {
                            srcIdx = *(int*)*param_3;
                        }
                        else {
                            srcIdx = *(int*)(*(int*)(param_5 + 8) + *(int*)*param_3 * 4);
                        }
                        int src = *(int*)(param_6 + 0x18) + srcIdx * 0x18;
                        int dstIdx;
                        if (param_4 == 0) {
                            dstIdx = *(int*)*param_2;
                        }
                        else {
                            dstIdx = *(int*)(*(int*)(param_4 + 8) + *(int*)*param_2 * 4);
                        }
                        int dst = *(int*)(s + 0x18) + dstIdx * 0x18;
                        if (*(int*)(s + 0xc) == *(int*)(param_6 + 0xc)) {
                            if (*(int*)(src + 4) != 0) {
                                com_addref(*(void**)(src + 4));
                            }
                            piVar1 = *(int**)(dst + 4);
                            if (piVar1 != (int*)0x0) {
                                com_release(piVar1);
                                *(undefined4*)(dst + 4) = 0;
                            }
                            *(undefined4*)(dst + 4) = *(undefined4*)(src + 4);
                        }
                        else {
                            piVar1 = *(int**)(dst + 4);
                            if (piVar1 != (int*)0x0) {
                                com_release(piVar1);
                                *(undefined4*)(dst + 4) = 0;
                            }
                            if (param_4 != 0) {
                                return -0x7fffbffb;
                            }
                        }
                        *param_2 = *param_2 + 4;
                        *param_3 = *param_3 + 4;
                        local_8 = local_8 - 1;
                    } while (local_8 != 0);
                }
                goto LAB_006409d3;
            }
            bVar9 = ((uint32_t)iVar2 < 0xeu);
            iVar4 = iVar2 + -0xe;
            bVar8 = (iVar2 == 0xe);
        }
        else {
            if (iVar2 == 0x10) {
                for (; local_8 != 0; local_8 = local_8 - 1) {
                    int srcIdx;
                    if (param_5 == 0) {
                        srcIdx = *(int*)*param_3;
                    }
                    else {
                        srcIdx = *(int*)(*(int*)(param_5 + 8) + *(int*)*param_3 * 4);
                    }
                    int src = *(int*)(param_6 + 0x18) + srcIdx * 0x18;
                    int dstIdx;
                    if (param_4 == 0) {
                        dstIdx = *(int*)*param_2;
                    }
                    else {
                        dstIdx = *(int*)(*(int*)(param_4 + 8) + *(int*)*param_2 * 4);
                    }
                    int dst = *(int*)(s + 0x18) + dstIdx * 0x18;
                    if (*(int*)(src + 8) != 0) {
                        com_addref(*(void**)(src + 8));
                    }
                    piVar1 = *(int**)(dst + 8);
                    if (piVar1 != (int*)0x0) {
                        com_release(piVar1);
                        *(undefined4*)(dst + 8) = 0;
                    }
                    *(undefined4*)(dst + 8) = *(undefined4*)(src + 8);
                    *(undefined4*)(dst + 0xc) = *(undefined4*)(src + 0xc);
                    if ((*(int*)(s + 0xc) == *(int*)(param_6 + 0xc)) || (*(int*)(src + 8) == 0)) {
                        if (*(int*)(src + 4) != 0) {
                            com_addref(*(void**)(src + 4));
                        }
                        piVar1 = *(int**)(dst + 4);
                        if (piVar1 != (int*)0x0) {
                            com_release(piVar1);
                            *(undefined4*)(dst + 4) = 0;
                        }
                        *(undefined4*)(dst + 4) = *(undefined4*)(src + 4);
                        *(uint32_t*)(dst + 0x14) =
                            *(uint32_t*)(dst + 0x14) ^
                            (((*(int*)(src + 0x14) << 0x1e) >> 0x1e) ^ *(uint32_t*)(dst + 0x14)) & 2;
                    }
                    else {
                        piVar1 = *(int**)(dst + 4);
                        if (piVar1 != (int*)0x0) {
                            com_release(piVar1);
                            *(undefined4*)(dst + 4) = 0;
                        }
                        if (param_4 != 0) {
                            return -0x7fffbffb;
                        }
                        FUN_0063e5ce((void*)dst);
                    }
                    *param_2 = *param_2 + 4;
                    *param_3 = *param_3 + 4;
                }
                goto LAB_006409d3;
            }
            if (iVar2 < 0x11) {
                return -0x7fffbffb;
            }
            bVar9 = ((uint32_t)iVar2 < 0x12u);
            iVar4 = iVar2 + -0x12;
            bVar8 = (iVar2 == 0x12);
        }
        if (bVar8 || (bVar9 != (iVar4 < 0))) {
LAB_006409d3:
            *param_1 = *param_1 + 0x14;
            return 0;
        }
    }
    return -0x7fffbffb;
}

// 0x640a26 — observed shape
int FUN_00640a26(void* self, int* param_1, int* param_2, int* param_3, uint32_t param_4, int param_5)
{
    uint8_t* s = (uint8_t*)self;
    int* piVar4 = param_1;
    int* piVar1 = (int*)*param_1;
    int iVar5 = *piVar1;
    int iVar2 = piVar1[1];
    if (iVar2 < 0) {
        return -0x7fffbffb;
    }
    if (iVar2 < 2) {
        undefined4* puVar7 = (undefined4*)*param_2;
        undefined4* puVar9 = (undefined4*)*param_3;
        iVar5 = piVar1[5];
        undefined4* puVar6 = puVar7 + param_4 * 4;
        for (; puVar7 < puVar6; puVar7 = puVar7 + (4 - iVar5)) {
            if (iVar5 != 0) {
                uint32_t n = (uint32_t)iVar5;
                do {
                    *puVar7 = *puVar9;
                    puVar7 = puVar7 + 1;
                    puVar9 = puVar9 + 1;
                    n = n - 1;
                } while (n != 0);
            }
        }
        *param_2 = (int)puVar7;
        *param_3 = (int)puVar9;
    }
    else {
        if (3 < iVar2) {
            if (iVar2 == 4) {
                if (iVar5 == 4) {
                    for (; param_4 != 0; param_4 = param_4 - 1) {
                        iVar5 = FUN_0063f9ca(*(uint32_t*)*param_3, *(uint32_t*)*param_2,
                                             *(uint32_t*)(*(int*)(*(int*)(s + 0xb0) + *(int*)(param_5 + 0x14) * 4) + 0x40));
                        if (iVar5 < 0) {
                            return iVar5;
                        }
                        *param_2 = *param_2 + 4;
                        *param_3 = *param_3 + 4;
                    }
                }
                else if (4 < iVar5) {
                    if (iVar5 < 10) {
                        for (; param_4 != 0; param_4 = param_4 - 1) {
                            iVar5 = FUN_0063f926(*(uint32_t*)*param_3, *(uint32_t*)*param_2,
                                                 *(uint32_t*)(*(int*)(*(int*)(s + 0xb0) + *(int*)(param_5 + 0x14) * 4) + 0x40));
                            if (iVar5 < 0) {
                                return iVar5;
                            }
                            *param_2 = *param_2 + 4;
                            *param_3 = *param_3 + 4;
                        }
                    }
                    else if (iVar5 == 0xf) {
                        for (; param_4 != 0; param_4 = param_4 - 1) {
                            iVar5 = FUN_0063f86e(*(uint32_t*)*param_3, *(uint32_t*)*param_2,
                                                 *(uint32_t*)(*(int*)(*(int*)(s + 0xb0) + *(int*)(param_5 + 0x14) * 4) + 0x40));
                            if (iVar5 < 0) {
                                return iVar5;
                            }
                            *param_2 = *param_2 + 4;
                            *param_3 = *param_3 + 4;
                        }
                    }
                    else if (iVar5 == 0x10) {
                        for (; param_4 != 0; param_4 = param_4 - 1) {
                            iVar5 = FUN_0063f86e(*(uint32_t*)*param_3, *(uint32_t*)*param_2,
                                                 *(uint32_t*)(*(int*)(*(int*)(s + 0xb0) + *(int*)(param_5 + 0x14) * 4) + 0x40));
                            if (iVar5 < 0) {
                                return iVar5;
                            }
                            *param_2 = *param_2 + 4;
                            *param_3 = *param_3 + 4;
                        }
                    }
                }
                *param_1 = *param_1 + 0x14;
                return 0;
            }
            if (iVar2 != 5) {
                return -0x7fffbffb;
            }
            uint32_t uVar3 = (uint32_t)piVar1[5];
            *param_1 = (int)(piVar1 + 6);
            for (;;) {
                if (param_4 == 0) {
                    return 0;
                }
                int* count = (int*)0x0;
                *piVar4 = (int)(piVar1 + 6);
                if (uVar3 != 0) {
                    do {
                        iVar5 = *(int*)(*piVar4 + 0x10);
                        if (iVar5 == 0) {
                            iVar5 = 1;
                        }
                        iVar5 = FUN_00640a26(self, piVar4, param_2, param_3, (uint32_t)iVar5, param_5);
                        if (iVar5 < 0) {
                            return iVar5;
                        }
                        count = (int*)((int)count + 1);
                    } while (count < (int*)uVar3);
                }
                param_4 = param_4 - 1;
            }
        }
        iVar2 = piVar1[5];
        uint32_t uVar3 = (uint32_t)piVar1[6];
        if (iVar5 == 1) {
            if (param_4 != 0) {
                int local_8 = (int)param_4;
                do {
                    param_4 = 0;
                    if (uVar3 != 0) {
                        do {
                            if (iVar2 != 0) {
                                int off = (int)(param_4 << 4);
                                int srcOff = (int)(param_4 << 2);
                                int local_c = iVar2;
                                do {
                                    *(uint32_t*)(off + *param_2) =
                                        (uint32_t)(*(int*)(srcOff + *param_3) != 0);
                                    off = off + 4;
                                    srcOff = srcOff + (int)uVar3 * 4;
                                    local_c = local_c - 1;
                                } while (local_c != 0);
                            }
                            param_4 = param_4 + 1;
                        } while (param_4 < uVar3);
                    }
                    *param_2 = *param_2 + 0x40;
                    *param_3 = *param_3 + (int)(uVar3 * (uint32_t)iVar2 * 4);
                    local_8 = local_8 - 1;
                } while (local_8 != 0);
            }
        }
        else if (iVar5 == 2) {
            if (param_4 != 0) {
                int local_8 = (int)param_4;
                do {
                    param_4 = 0;
                    if (uVar3 != 0) {
                        do {
                            if (iVar2 != 0) {
                                int off = (int)(param_4 << 4);
                                int srcOff = (int)(param_4 << 2);
                                int local_c = iVar2;
                                do {
                                    *(undefined4*)(off + *param_2) = *(undefined4*)(srcOff + *param_3);
                                    off = off + 4;
                                    srcOff = srcOff + (int)uVar3 * 4;
                                    local_c = local_c - 1;
                                } while (local_c != 0);
                            }
                            param_4 = param_4 + 1;
                        } while (param_4 < uVar3);
                    }
                    *param_2 = *param_2 + 0x40;
                    *param_3 = *param_3 + (int)(uVar3 * (uint32_t)iVar2 * 4);
                    local_8 = local_8 - 1;
                } while (local_8 != 0);
            }
        }
        else if ((iVar5 == 3) && (param_4 != 0)) {
            int local_c = (int)param_4;
            do {
                param_4 = 0;
                if (uVar3 != 0) {
                    do {
                        if (iVar2 != 0) {
                            int off = (int)(param_4 << 4);
                            int srcOff = (int)(param_4 << 2);
                            int local_8 = iVar2;
                            do {
                                *(undefined4*)(off + *param_2) = *(undefined4*)(srcOff + *param_3);
                                off = off + 4;
                                srcOff = srcOff + (int)uVar3 * 4;
                                local_8 = local_8 - 1;
                            } while (local_8 != 0);
                        }
                        param_4 = param_4 + 1;
                    } while (param_4 < uVar3);
                }
                *param_2 = *param_2 + 0x40;
                *param_3 = *param_3 + (int)(uVar3 * (uint32_t)iVar2 * 4);
                local_c = local_c - 1;
            } while (local_c != 0);
        }
    }
    *param_1 = *param_1 + 0x1c;
    return 0;
}

// 0x640dc6 — observed shape
int FUN_00640dc6(void* self, int* param_1, int* param_2, int* param_3, uint32_t param_4, uint32_t param_5)
{
    uint8_t* s = (uint8_t*)self;
    int* piVar1 = (int*)*param_1;
    int local_c = 0;
    bool bVar8 = (param_5 != 0);
    int iVar7 = *piVar1;
    param_5 = (uint32_t)piVar1[4];
    int iVar5 = piVar1[1];
    if ((bVar8) || (param_5 == 0)) {
        param_5 = 1;
    }
    if (-1 < iVar5) {
        if (iVar5 < 4) {
            int iVar3 = piVar1[5];
            uint32_t uVar2 = (uint32_t)piVar1[6];
            iVar5 = (((iVar5 != 2) - 1) & 0x30) + 0x10;
            int local_10 = (int)param_5;
            if (iVar7 == 1) {
                if (param_5 != 0) {
                    do {
                        param_4 = 0;
                        if (uVar2 != 0) {
                            do {
                                if (iVar3 != 0) {
                                    int off = (int)(param_4 << 4);
                                    int srcOff = (int)(param_4 << 2);
                                    int local_14 = iVar3;
                                    do {
                                        int* p = (int*)(off + *param_2);
                                        off = off + 4;
                                        *(uint32_t*)(srcOff + *param_3) = (uint32_t)(*p != 0);
                                        srcOff = srcOff + (int)uVar2 * 4;
                                        local_14 = local_14 - 1;
                                    } while (local_14 != 0);
                                }
                                param_4 = param_4 + 1;
                            } while (param_4 < uVar2);
                        }
                        *param_2 = *param_2 + iVar5;
                        *param_3 = *param_3 + (int)(uVar2 * (uint32_t)iVar3 * 4);
                        local_10 = local_10 - 1;
                    } while (local_10 != 0);
                }
            }
            else if (iVar7 == 2) {
                if (param_5 != 0) {
                    do {
                        param_4 = 0;
                        if (uVar2 != 0) {
                            do {
                                if (iVar3 != 0) {
                                    int srcOff = (int)(param_4 << 4);
                                    int off = (int)(param_4 << 2);
                                    int local_14 = iVar3;
                                    do {
                                        *(undefined4*)(off + *param_3) = *(undefined4*)(srcOff + *param_2);
                                        srcOff = srcOff + 4;
                                        off = off + (int)uVar2 * 4;
                                        local_14 = local_14 - 1;
                                    } while (local_14 != 0);
                                }
                                param_4 = param_4 + 1;
                            } while (param_4 < uVar2);
                        }
                        *param_2 = *param_2 + iVar5;
                        *param_3 = *param_3 + (int)(uVar2 * (uint32_t)iVar3 * 4);
                        local_10 = local_10 - 1;
                    } while (local_10 != 0);
                }
            }
            else {
                if (iVar7 != 3) {
                    return -0x7fffbffb;
                }
                if (param_5 != 0) {
                    int local_14 = (int)param_5;
                    do {
                        param_4 = 0;
                        if (uVar2 != 0) {
                            do {
                                if (iVar3 != 0) {
                                    int srcOff = (int)(param_4 << 4);
                                    int off = (int)(param_4 << 2);
                                    int local_10b = iVar3;
                                    do {
                                        *(undefined4*)(off + *param_3) = *(undefined4*)(srcOff + *param_2);
                                        srcOff = srcOff + 4;
                                        off = off + (int)uVar2 * 4;
                                        local_10b = local_10b - 1;
                                    } while (local_10b != 0);
                                }
                                param_4 = param_4 + 1;
                            } while (param_4 < uVar2);
                        }
                        *param_2 = *param_2 + iVar5;
                        *param_3 = *param_3 + (int)(uVar2 * (uint32_t)iVar3 * 4);
                        local_14 = local_14 - 1;
                    } while (local_14 != 0);
                }
            }
            *param_1 = *param_1 + 0x1c;
            return 0;
        }
        if (iVar5 == 4) {
            if (iVar7 == 4) {
                if (param_5 != 0) {
                    do {
                        int idx = *(int*)*param_2;
                        if (param_4 != 0) {
                            idx = *(int*)(*(int*)(param_4 + 8) + idx * 4);
                        }
                        idx = *(int*)(s + 0x18) + idx * 0x18;
                        uint32_t uVar4;
                        if (*(int*)(idx + 4) == 0) {
                            uVar4 = 0;
                        }
                        else {
                            piVar1 = *(int**)(idx + 4);
                            uVar4 = com_call3(piVar1);
                        }
                        *(undefined4*)*param_3 = uVar4;
                        *param_2 = *param_2 + 4;
                        *param_3 = *param_3 + 4;
                        param_5 = param_5 - 1;
                    } while (param_5 != 0);
                }
            }
            else {
                if (iVar7 < 5) {
                    return -0x7fffbffb;
                }
                if (iVar7 < 10) {
                    if (param_5 != 0) {
                        do {
                            int idx = *(int*)*param_2;
                            if (param_4 != 0) {
                                idx = *(int*)(*(int*)(param_4 + 8) + idx * 4);
                            }
                            *(undefined4*)*param_3 = *(undefined4*)(*(int*)(s + 0x18) + 4 + idx * 0x18);
                            if (*(int*)*param_3 != 0) {
                                piVar1 = *(int**)*param_3;
                                com_addref(piVar1);
                            }
                            *param_2 = *param_2 + 4;
                            *param_3 = *param_3 + 4;
                            param_5 = param_5 - 1;
                        } while (param_5 != 0);
                    }
                }
                else if (iVar7 == 0xf) {
                    if (param_5 != 0) {
                        do {
                            int idx = *(int*)*param_2;
                            if (param_4 != 0) {
                                idx = *(int*)(*(int*)(param_4 + 8) + idx * 4);
                            }
                            *(undefined4*)*param_3 = *(undefined4*)(*(int*)(s + 0x18) + 4 + idx * 0x18);
                            if (*(int*)*param_3 != 0) {
                                piVar1 = *(int**)*param_3;
                                com_addref(piVar1);
                            }
                            *param_2 = *param_2 + 4;
                            *param_3 = *param_3 + 4;
                            param_5 = param_5 - 1;
                        } while (param_5 != 0);
                    }
                }
                else {
                    if (iVar7 != 0x10) {
                        return -0x7fffbffb;
                    }
                    if (param_5 != 0) {
                        do {
                            int idx = *(int*)*param_2;
                            if (param_4 != 0) {
                                idx = *(int*)(*(int*)(param_4 + 8) + idx * 4);
                            }
                            *(undefined4*)*param_3 = *(undefined4*)(*(int*)(s + 0x18) + 4 + idx * 0x18);
                            if (*(int*)*param_3 != 0) {
                                piVar1 = *(int**)*param_3;
                                com_addref(piVar1);
                            }
                            *param_2 = *param_2 + 4;
                            *param_3 = *param_3 + 4;
                            param_5 = param_5 - 1;
                        } while (param_5 != 0);
                    }
                }
            }
            *param_1 = *param_1 + 0x14;
            return 0;
        }
        if (iVar5 == 5) {
            uint32_t uVar2 = (uint32_t)piVar1[5];
            *param_1 = (int)(piVar1 + 6);
            int iVar7count = (int)param_5;
            for (;;) {
                if (iVar7count == 0) {
                    return local_c;
                }
                param_5 = 0;
                *param_1 = (int)(piVar1 + 6);
                if (uVar2 != 0) {
                    do {
                        local_c = FUN_00640dc6(self, param_1, param_2, param_3, param_4, 0);
                        if (local_c < 0) {
                            return local_c;
                        }
                        param_5 = param_5 + 1;
                    } while (param_5 < uVar2);
                }
                iVar7count = iVar7count - 1;
            }
        }
    }
    return -0x7fffbffb;
}

// 0x64115d — observed shape
void FUN_0064115d(void* self)
{
    uint8_t* s = (uint8_t*)self;
    int* piVar1 = *(int**)(s + 0xc);
    *(void**)s = &PTR_LAB_006ec270;
    if (piVar1 != (int*)0x0) {
        com_release(piVar1);
        *(undefined4*)(s + 0xc) = 0;
    }
    piVar1 = *(int**)(s + 8);
    if (piVar1 != (int*)0x0) {
        com_release(piVar1);
        *(undefined4*)(s + 8) = 0;
    }
    return;
}

// 0x6411ea — observed shape
HRESULT FUN_006411ea(void* self, int* param_1)
{
    uint8_t* s = (uint8_t*)self;
    if (param_1 != (int*)0x0) {
        com_addref(param_1);
    }
    int* piVar1 = *(int**)(s + 8);
    if (piVar1 != (int*)0x0) {
        com_release(piVar1);
        *(undefined4*)(s + 8) = 0;
    }
    *(int**)(s + 8) = param_1;
    *(int**)(s + 4) = param_1;
    return 0;
}

// 0x64121f — observed shape
HRESULT FUN_0064121f(void* self, int* param_1)
{
    uint8_t* s = (uint8_t*)self;
    if (param_1 != (int*)0x0) {
        com_addref(param_1);
    }
    int* piVar1 = *(int**)(s + 0xc);
    if (piVar1 != (int*)0x0) {
        com_release(piVar1);
        *(undefined4*)(s + 0xc) = 0;
    }
    *(int**)(s + 0xc) = param_1;
    if (param_1 == (int*)0x0) {
        *(undefined4*)(s + 4) = *(undefined4*)(s + 8);
    }
    else {
        *(int*)(s + 4) = (int)(intptr_t)s;
    }
    return 0;
}

// 0x641260 — observed shape
HRESULT FUN_00641260(void* self, uint32_t* param_1)
{
    uint8_t* s = (uint8_t*)self;
    if (*(int*)(s + 0xc) != 0) {
        com_addref(*(void**)(s + 0xc));
    }
    *param_1 = *(uint32_t*)(s + 0xc);
    return 0;
}

// 0x641401 — observed shape
int FUN_00641401(int param_1, int param_2, int* param_3, uint32_t param_4)
{
    uint32_t uVar2 = 0;
    if (param_4 != 0) {
        int* piVar3 = param_3;
        do {
            int value = 0;
            if (*piVar3 != 0) {
                value = -1;
            }
            void* obj = *(void**)(param_1 + 0xc);
            int iVar1 = ((int(__stdcall*)(void*, int, int*, int))(*(void***)obj)[16])
                (obj, param_2 + (int)uVar2, &value, 1);
            if (iVar1 < 0) {
                return iVar1;
            }
            piVar3 = piVar3 + 1;
            uVar2 = uVar2 + 1;
        } while (uVar2 < param_4);
    }
    return 0;
}

extern void* FUN_00533c78(uint32_t size);
extern void operator_delete(void* p);
extern int FUN_006294f9(char* length, int** out);
extern uint32_t FUN_006415c9(void* self, uint32_t param_1);

// 0x6414a6 — observed shape
uint32_t FUN_006414a6(int param_1)
{
    uint32_t local_8 = 0;
    if ((*(int*)(param_1 + 0x3c) != 4) && (*(int*)(param_1 + 0x3c) == 3)) {
        if (*(int*)(param_1 + 0xd0) == *(int*)(param_1 + 0xd4)) {
            uint32_t uVar1 = (uint32_t)(*(int*)(param_1 + 0xd0) * 2 + 1);
            undefined4* puVar2 = (undefined4*)FUN_00533c78(uVar1 * 4);
            if (puVar2 == (undefined4*)0x0) {
                return 0;
            }
            undefined4* puVar5 = puVar2;
            for (uint32_t uVar3 = uVar1 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar5 = 0;
                puVar5 = puVar5 + 1;
            }
            for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *(uint8_t*)puVar5 = 0;
                puVar5 = (undefined4*)((int)puVar5 + 1);
            }
            puVar5 = *(undefined4**)(param_1 + 0xd8);
            undefined4* puVar6 = puVar2;
            for (uint32_t uVar3 = *(uint32_t*)(param_1 + 0xd0) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + 1;
            }
            for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *(uint8_t*)puVar6 = *(uint8_t*)puVar5;
                puVar5 = (undefined4*)((int)puVar5 + 1);
                puVar6 = (undefined4*)((int)puVar6 + 1);
            }
            if (*(void**)(param_1 + 0xd8) != (void*)0x0) {
                operator_delete(*(void**)(param_1 + 0xd8));
                *(undefined4*)(param_1 + 0xd8) = 0;
            }
            *(undefined4**)(param_1 + 0xd8) = puVar2;
            *(uint32_t*)(param_1 + 0xd4) = uVar1;
        }
        *(undefined4*)(param_1 + 0x3c) = 0;
        *(undefined4*)(*(int*)(param_1 + 0xd8) + *(int*)(param_1 + 0xd0) * 4) =
            *(undefined4*)(param_1 + 0xf8);
        *(undefined4*)(param_1 + 0xf8) = 0;
        undefined4* puVar2 = (undefined4*)FUN_00533c78(0x28);
        if (puVar2 == (undefined4*)0x0) {
            puVar2 = (undefined4*)0x0;
        }
        else {
            puVar2[2] = 0xffffffff;
            puVar2[9] = 0;
            puVar2[8] = 0;
            *puVar2 = 0;
            puVar2[1] = 0;
        }
        if (puVar2 != (undefined4*)0x0) {
            puVar2[4] = 4;
            puVar2[5] = *(undefined4*)(param_1 + 0xd0);
            puVar2[9] = *(undefined4*)(param_1 + 0xdc);
            *(int*)(param_1 + 0xd0) = *(int*)(param_1 + 0xd0) + 1;
            *(undefined4*)(param_1 + 0xdc) = puVar2;
            local_8 = ~(uint32_t)(uintptr_t)puVar2;
        }
    }
    return local_8;
}

// 0x6415c9 — observed shape
uint32_t FUN_006415c9(void* self, uint32_t param_1)
{
    uint8_t* s = (uint8_t*)self;
    uint32_t uVar2;
    if (((((int)param_1 < 1) && ((param_1 & 0xffff) != param_1)) &&
         (*(int*)(intptr_t)(~param_1 + 0x10) == 4))) {
        uint32_t uVar1 = *(uint32_t*)(intptr_t)(~param_1 + 0x14);
        if (uVar1 < *(uint32_t*)(s + 0xd0)) {
            uVar2 = *(uint32_t*)(*(int*)(s + 0xd8) + uVar1 * 4);
            return uVar2;
        }
    }
    return 0;
}

// 0x641605 — observed shape
int FUN_00641605(int* param_1, undefined4 param_2)
{
    undefined4* puVar1 = (undefined4*)FUN_006415c9(param_1, (uint32_t)param_2);
    int iVar2;
    if (puVar1 == (undefined4*)0x0) {
        iVar2 = -0x7789f794;
    }
    else {
        do {
            switch (*puVar1) {
            case 0:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t, uint32_t))(*(void***)param_1)[0x50 / 4])
                    (param_1, puVar1[1], puVar1[3], puVar1[2]);
                break;
            case 1:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[0x58 / 4])
                    (param_1, puVar1[1], puVar1[3]);
                break;
            case 2:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t, uint32_t))(*(void***)param_1)[0x60 / 4])
                    (param_1, puVar1[1], puVar1[3], puVar1[2]);
                break;
            case 3:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[0x68 / 4])
                    (param_1, puVar1[1], puVar1[3]);
                break;
            case 4:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t, uint32_t))(*(void***)param_1)[0x70 / 4])
                    (param_1, puVar1[1], puVar1[3], puVar1[2]);
                break;
            case 5:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[0x78 / 4])
                    (param_1, puVar1[1], puVar1[3]);
                break;
            case 6:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t, uint32_t))(*(void***)param_1)[0x80 / 4])
                    (param_1, puVar1[1], puVar1[3], puVar1[2]);
                break;
            case 7:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[0x88 / 4])
                    (param_1, puVar1[1], puVar1[3]);
                break;
            case 8:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t, uint32_t))(*(void***)param_1)[0x90 / 4])
                    (param_1, puVar1[1], puVar1[3], puVar1[2]);
                break;
            case 9:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[0x98 / 4])
                    (param_1, puVar1[1], puVar1[3]);
                break;
            case 10:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t, uint32_t))(*(void***)param_1)[0xa0 / 4])
                    (param_1, puVar1[1], puVar1[3], puVar1[2]);
                break;
            case 0xb: {
                uint32_t uVar3;
                if (*(int*)(puVar1[5] + 4) == 0) {
                    uVar3 = 0;
                }
                else {
                    uVar3 = com_call3(*(void**)(puVar1[5] + 4));
                }
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[200 / 4])
                    (param_1, puVar1[1], uVar3);
                break;
            }
            case 0xc:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[0xd0 / 4])
                    (param_1, puVar1[1], *(undefined4*)(puVar1[5] + 4));
                break;
            case 0xd:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[0xd8 / 4])
                    (param_1, puVar1[1], *(undefined4*)(puVar1[5] + 4));
                break;
            case 0xe:
                iVar2 = ((int(__stdcall*)(void*, uint32_t, uint32_t))(*(void***)param_1)[0xe0 / 4])
                    (param_1, puVar1[1], *(undefined4*)(puVar1[5] + 4));
                break;
            default:
                iVar2 = -0x7fffbffb;
            }
        } while ((-1 < iVar2) && (puVar1 = (undefined4*)puVar1[6], puVar1 != (undefined4*)0x0));
    }
    return iVar2;
}

// 0x6417e8 — observed shape
int FUN_006417e8(int* param_1, int* param_2, int* param_3, int* param_4, int param_5)
{
    int* piVar5 = param_1;
    int* piVar2 = (int*)*param_1;
    int* local_10 = (int*)0x0;
    int local_8 = piVar2[4];
    int iVar3 = piVar2[1];
    int iVar4 = *piVar2;
    int local_c = 0;
    if ((param_5 != 0) || (local_8 == 0)) {
        local_8 = 1;
    }
    if (-1 < iVar3) {
        if (iVar3 < 4) {
            if (((iVar4 != 1) && (iVar4 != 2)) && (iVar4 != 3)) {
                return -0x7fffbffb;
            }
            *param_2 = *param_2 + piVar2[6] * piVar2[5] * local_8 * 4;
            *param_1 = *param_1 + 0x1c;
            goto LAB_00641a55;
        }
        if (iVar3 == 4) {
            if (iVar4 == 4) {
                for (; local_8 != 0; local_8 = local_8 + -1) {
                    local_10 = (int*)0x0;
                    if (*param_3 != 0) {
                        char* pcVar9 = *(char**)*param_2;
                        if (pcVar9 != (char*)0x0) {
                            char* pcVar6 = pcVar9;
                            char cVar1;
                            do {
                                cVar1 = *pcVar6;
                                pcVar6 = pcVar6 + 1;
                            } while (cVar1 != '\0');
                            pcVar6 = (char*)(intptr_t)((int)pcVar6 + 1 - (int)(pcVar9 + 1));
                            local_c = FUN_006294f9(pcVar6, &local_10);
                            if (local_c < 0) {
                                return local_c;
                            }
                            char* pcVar7 = ((char*(__stdcall*)(void*))(*(void***)local_10)[3])(local_10);
                            for (uint32_t uVar8 = (uint32_t)(intptr_t)pcVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                                *(undefined4*)pcVar7 = *(undefined4*)pcVar9;
                                pcVar9 = pcVar9 + 4;
                                pcVar7 = pcVar7 + 4;
                            }
                            for (uint32_t uVar8 = (uint32_t)(intptr_t)pcVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                                *pcVar7 = *pcVar9;
                                pcVar9 = pcVar9 + 1;
                                pcVar7 = pcVar7 + 1;
                            }
                        }
                        *(undefined4*)*param_3 = 4;
                        *(int**)(*param_3 + 4) = local_10;
                        *param_3 = *param_3 + 8;
                    }
                    if (param_4 != (int*)0x0) {
                        *param_4 = *param_4 + 1;
                    }
                    *param_2 = *param_2 + 4;
                }
            }
            else {
                if (iVar4 < 5) {
                    return -0x7fffbffb;
                }
                param_5 = local_8;
                if (iVar4 < 10) {
                    if (local_8 != 0) {
                        do {
                            if (*param_3 != 0) {
                                piVar2 = *(int**)*param_2;
                                if (piVar2 != (int*)0x0) {
                                    com_addref(piVar2);
                                }
                                *(undefined4*)*param_3 = 5;
                                *(int**)(*param_3 + 4) = piVar2;
                                *param_3 = *param_3 + 8;
                            }
                            if (param_4 != (int*)0x0) {
                                *param_4 = *param_4 + 1;
                            }
                            *param_2 = *param_2 + 4;
                            param_5 = param_5 + -1;
                        } while (param_5 != 0);
                    }
                }
                else if (iVar4 == 0xf) {
                    if (local_8 != 0) {
                        do {
                            if (*param_3 != 0) {
                                piVar2 = *(int**)*param_2;
                                if (piVar2 != (int*)0x0) {
                                    com_addref(piVar2);
                                }
                                *(undefined4*)*param_3 = 0xf;
                                *(int**)(*param_3 + 4) = piVar2;
                                *param_3 = *param_3 + 8;
                            }
                            if (param_4 != (int*)0x0) {
                                *param_4 = *param_4 + 1;
                            }
                            *param_2 = *param_2 + 4;
                            param_5 = param_5 + -1;
                        } while (param_5 != 0);
                    }
                }
                else {
                    if (iVar4 != 0x10) {
                        return -0x7fffbffb;
                    }
                    if (local_8 != 0) {
                        do {
                            if (*param_3 != 0) {
                                piVar2 = *(int**)*param_2;
                                if (piVar2 != (int*)0x0) {
                                    com_addref(piVar2);
                                }
                                *(undefined4*)*param_3 = 0x10;
                                *(int**)(*param_3 + 4) = piVar2;
                                *param_3 = *param_3 + 8;
                            }
                            if (param_4 != (int*)0x0) {
                                *param_4 = *param_4 + 1;
                            }
                            *param_2 = *param_2 + 4;
                            param_5 = param_5 + -1;
                        } while (param_5 != 0);
                    }
                }
            }
            *param_1 = *param_1 + 0x14;
            goto LAB_00641a55;
        }
        if (iVar3 == 5) {
            uint32_t uVar8 = (uint32_t)piVar2[5];
            *param_1 = (int)(piVar2 + 6);
            if (local_8 == 0) {
                return 0;
            }
            do {
                param_1 = (int*)0x0;
                *piVar5 = (int)(piVar2 + 6);
                if (uVar8 != 0) {
                    do {
                        local_c = FUN_006417e8(piVar5, param_2, param_3, param_4, 0);
                        if (local_c < 0) {
                            goto LAB_00641a55;
                        }
                        param_1 = (int*)((int)param_1 + 1);
                    } while (param_1 < (int*)uVar8);
                }
                local_8 = local_8 - 1;
            } while (local_8 != 0);
            goto LAB_00641a55;
        }
    }
    local_c = -0x7fffbffb;
LAB_00641a55:
    if (local_10 != (int*)0x0) {
        com_release(local_10);
    }
    return local_c;
}
