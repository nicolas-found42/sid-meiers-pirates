#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <cwchar>

extern byte FUN_004f10a0(void *self);
extern void FUN_004f0e40(void *self, int a, void *b, int c);
extern void FUN_004f0dc0(void);
extern void FUN_00412e50(const char *s);
extern void FUN_00412df0(void);
extern void FUN_00412f10(void);
extern void FUN_00412ec0(void);
extern void FUN_004f32e0(void);
extern void FUN_004f3350(void);
extern void FUN_00489300(void);
extern unsigned char DAT_008cacd0[];
extern int DAT_008caccc;
extern int DAT_008cacc8;
extern char *PTR_DAT_00726c0c;
extern void *PTR_FUN_0071050c;
extern void *PTR_LAB_007104f4;
extern void FUN_004fcd60(void *self);
extern void operator_delete(void *p);
extern void operator_delete__(void *p);
extern void FUN_004f3130(void *p);
extern void FUN_004f30d0(int a);
extern void FUN_004f1840(void *self, int edx, int ecx);
extern void FUN_004f1220(void *self, LONG param_1, DWORD param_2);
extern int FUN_004f1280(void *self, int ecx, int edx);

// 0x4f0fd0 — observed shape
int FUN_004f0fd0(void *self) {
    int* a = (int*)self;
    if (a[1] == 0) {
        return 5;
    }
    typedef int (__stdcall *GetSizeFn)(void*);
    GetSizeFn getSize = (GetSizeFn)(*(void**)(*(void**)a + 0x10));
    int size = getSize(a);
    DWORD flProtect = 0;
    DWORD dwAccess = 0;
    int mode = a[8];
    if (mode == 1) {
        dwAccess = 4;
        flProtect = 2;
    } else if (mode < 2 || 3 < mode) {
        flProtect = (DWORD)a[4];
        dwAccess = 0;
    } else {
        dwAccess = 2;
        flProtect = 4;
        if (size == 0) {
            typedef void (__stdcall *SetModeFn)(void*, int);
            SetModeFn setMode = (SetModeFn)(*(void**)(*(void**)a + 0x14));
            setMode(a, 1);
        }
    }
    HANDLE h = CreateFileMappingA((HANDLE)(intptr_t)a[1], nullptr, flProtect, nullptr, 0, nullptr);
    a[2] = (int)(intptr_t)h;
    if (h == nullptr) {
        return 5;
    }
    LPVOID view = MapViewOfFile(h, dwAccess, 0, 0, 0);
    a[3] = (int)(intptr_t)view;
    if (view == nullptr) {
        FUN_004f10a0(self);
        return 6;
    }
    if (a[6] != 0) {
        typedef void (__stdcall *CbFn)(void*, int);
        CbFn cb = (CbFn)(*(void**)(*(void**)a[6] + 0));
        cb((void*)(intptr_t)a[6], 1);
        a[6] = 0;
    }
    a[5] = a[3];
    a[4] = a[3] + size;
    return 0;
}

// 0x4f10a0 — observed shape
byte FUN_004f10a0(void *self) {
    char* b = (char*)self;
    BOOL ok = 1;
    void* view = *(void**)(b + 0xc);
    if (view != nullptr) {
        ok = UnmapViewOfFile(view);
        *(uint32_t*)(b + 0x14) = 0;
        *(uint32_t*)(b + 0x10) = 0;
        *(uint32_t*)(b + 0xc) = 0;
    }
    HANDLE h = *(HANDLE*)(b + 8);
    if (h != nullptr) {
        CloseHandle(h);
        *(uint32_t*)(b + 8) = 0;
    }
    return (uint8_t)(((uint32_t)(ok != 0) - 1) & 6);
}

// 0x4f10f0 — observed shape
uint32_t FUN_004f10f0(uint8_t* param_1, uint32_t param_2, void* self) {
    char* b = (char*)self;
    if (*(HANDLE*)(b + 4) == nullptr) {
        return 0;
    }
    if (*(int*)(b + 8) == 0) {
        if (*(void**)(b + 0x18) == nullptr) {
            DWORD got = param_2;
            BOOL r = ReadFile(*(HANDLE*)(b + 4), param_1, param_2, &got, nullptr);
            return (uint32_t)(-(int32_t)(r != 0) & (int32_t)got);
        }
        typedef uint32_t (__stdcall *VFn)(void*);
        VFn v = (VFn)(*(void**)(*(void**)(b + 0x18) + 8));
        return v((void*)(intptr_t)(*(void**)(b + 0x18)));
    }
    uint32_t* src = *(uint32_t**)(b + 0x14);
    uint32_t* dst = (uint32_t*)param_1;
    for (uint32_t n = param_2 >> 2; n != 0; n--) {
        *dst = *src;
        src++;
        dst++;
    }
    for (uint32_t n = param_2 & 3; n != 0; n--) {
        *(uint8_t*)dst = *(uint8_t*)src;
        src = (uint32_t*)((char*)src + 1);
        dst = (uint32_t*)((char*)dst + 1);
    }
    *(uint32_t*)(b + 0x14) += param_2;
    return param_2;
}

// 0x4f1170 — observed shape
uint32_t FUN_004f1170(void* param_1, uint8_t* out, uint32_t len) {
    DWORD got = len;
    BOOL r = ReadFile(*(HANDLE*)((char*)param_1 + 4), out, len, &got, nullptr);
    return (uint32_t)(-(int32_t)(r != 0) & (int32_t)got);
}

// 0x4f11a0 — observed shape
uint32_t FUN_004f11a0(uint8_t* param_1, uint32_t param_2, void* self) {
    char* b = (char*)self;
    if (*(HANDLE*)(b + 4) == nullptr) {
        return 0;
    }
    if (*(int*)(b + 8) == 0) {
        if (*(void**)(b + 0x18) == nullptr) {
            DWORD put = param_2;
            BOOL r = WriteFile(*(HANDLE*)(b + 4), param_1, param_2, &put, nullptr);
            return (uint32_t)(-(int32_t)(r != 0) & (int32_t)put);
        }
        typedef uint32_t (__stdcall *VFn)(void*);
        VFn v = (VFn)(*(void**)(*(void**)(b + 0x18) + 0x10));
        return v((void*)(intptr_t)(*(void**)(b + 0x18)));
    }
    uint32_t* dst = *(uint32_t**)(b + 0x14);
    uint32_t* src = (uint32_t*)param_1;
    for (uint32_t n = param_2 >> 2; n != 0; n--) {
        *dst = *src;
        src++;
        dst++;
    }
    for (uint32_t n = param_2 & 3; n != 0; n--) {
        *(uint8_t*)dst = *(uint8_t*)src;
        src = (uint32_t*)((char*)src + 1);
        dst = (uint32_t*)((char*)dst + 1);
    }
    *(uint32_t*)(b + 0x14) += param_2;
    return param_2;
}

// 0x4f1220 — observed shape
void FUN_004f1220(void *self, LONG param_1, DWORD param_2) {
    int* a = (int*)self;
    if ((HANDLE)(intptr_t)a[1] == nullptr) {
        return;
    }
    if (a[2] != 0) {
        FUN_004f1280(self, 0, 0);
        return;
    }
    if (a[6] != 0) {
        typedef void (__stdcall *CbFn)(void*);
        CbFn cb = (CbFn)(*(void**)(*(void**)(intptr_t)a[6] + 0xc));
        cb((void*)(intptr_t)a[6]);
        return;
    }
    DWORD r = SetFilePointer((HANDLE)(intptr_t)a[1], param_1, nullptr, param_2);
    if (r == 0xffffffff) {
        typedef void (__stdcall *FailFn)(void*);
        FailFn f = (FailFn)(*(void**)(*(void**)a + 0x10));
        f(self);
    }
}

// 0x4f1280 — observed shape
int FUN_004f1280(void *self, int ecx, int edx) {
    char* b = (char*)self;
    if (ecx == 0) {
        *(int*)(b + 0x14) = *(int*)(b + 0xc) + edx;
    } else if (ecx == 1) {
        *(int*)(b + 0x14) = *(int*)(b + 0x14) + edx;
    } else if (ecx == 2) {
        *(int*)(b + 0x14) = *(int*)(b + 0x10) + edx;
    }
    uint32_t base = *(uint32_t*)(b + 0xc);
    if (*(uint32_t*)(b + 0x14) < base) {
        *(uint32_t*)(b + 0x14) = base;
        return 0;
    }
    if (*(uint32_t*)(b + 0x10) < *(uint32_t*)(b + 0x14)) {
        *(uint32_t*)(b + 0x14) = *(uint32_t*)(b + 0x10);
    }
    return *(int*)(b + 0x14) - (int)base;
}

// 0x4f12d0 — observed shape
void FUN_004f12d0(void *self, int param_1) {
    int* a = (int*)self;
    if (a[1] != 0) {
        typedef void (__stdcall *SetFn)(void*, int, int);
        SetFn set = (SetFn)(*(void**)(*(void**)a + 0x1c));
        set(self, param_1, 0);
        SetEndOfFile((HANDLE)(intptr_t)a[1]);
        set(self, 0, 0);
        DWORD sz = GetFileSize((HANDLE)(intptr_t)a[1], nullptr);
        a[9] = (int)sz;
    }
}

// 0x4f1310 — observed shape
bool FUN_004f1310(void) {
    FUN_00412f10();
    char* end = (char*)DAT_008cacd0 + DAT_008caccc;
    for (char* p = (char*)DAT_008cacd0; p < end; p++) {
        if (*p == '/') {
            *p = '\\';
        }
    }
    DWORD attr = GetFileAttributesA((LPCSTR)DAT_008cacd0);
    return attr != 0xffffffff;
}

// 0x4f1390 — observed shape
uint32_t FUN_004f1390(void *self) {
    if (self != nullptr) {
        FUN_004f0e40(self, 1, nullptr, 0x8000);
    }
    FUN_004f0dc0();
    return 0;
}

// 0x4f14a0 — observed shape
uint32_t FUN_004f14a0(uint32_t param_1) {
    if (*(int*)((char*)PTR_DAT_00726c0c + -4) == 0) {
        if (*(int*)((char*)PTR_DAT_00726c0c + -8) < 0x104) {
            FUN_004f32e0();
            *(uint32_t*)((char*)PTR_DAT_00726c0c + -4) = 0x104;
            *(uint32_t*)((char*)PTR_DAT_00726c0c + -4) = 0;
        }
        BOOL got = SHGetSpecialFolderPathA(nullptr, PTR_DAT_00726c0c, 5, 1);
        if (got == 0) {
            if (*(int*)((char*)PTR_DAT_00726c0c + -4) != 0) {
                *PTR_DAT_00726c0c = 0;
                *(uint32_t*)((char*)PTR_DAT_00726c0c + -4) = 0;
            }
        } else {
            char c;
            char* p = PTR_DAT_00726c0c;
            do {
                c = *p;
                p++;
            } while (c != '\0');
            *(int*)((char*)PTR_DAT_00726c0c + -4) = (int)(intptr_t)p - (int)(intptr_t)(PTR_DAT_00726c0c + 1);
            int len = *(int*)((char*)PTR_DAT_00726c0c + -4);
            if ((PTR_DAT_00726c0c[len - 1] != '\\') && (len > -1)) {
                char slash = '\\';
                if (len < len + 1) {
                    FUN_004f3350();
                    PTR_DAT_00726c0c[*(int*)((char*)PTR_DAT_00726c0c + -4)] = 0;
                }
                memmove(PTR_DAT_00726c0c + len, &slash, 1);
            }
            FUN_00412e50("My Games\\");
            CreateDirectoryA(PTR_DAT_00726c0c, nullptr);
            char* buf = (char*)DAT_008cacd0;
            int oldLen = DAT_008caccc;
            if (DAT_008cacc8 < 0x104) {
                FUN_004f32e0();
                *(int*)((char*)buf + -4) = oldLen;
                buf = buf;
            }
            GetCurrentDirectoryA(0x104, buf);
            char* q = buf;
            do {
                c = *q;
                q++;
            } while (c != '\0');
            int blen = (int)(intptr_t)q - (int)(intptr_t)(buf + 1);
            *(int*)((char*)buf + -4) = blen;
            if (blen != 0) {
                char* r = buf + blen - 1;
                char* last = nullptr;
                if (buf <= buf + blen - 1) {
                    do {
                        char* s = r;
                        if (*s != '\\') break;
                        r = s - 1;
                        last = s;
                    } while (buf <= r);
                    if (last != nullptr) {
                        *last = '\0';
                        *(int*)((char*)buf + -4) = (int)(intptr_t)last - (int)(intptr_t)buf;
                    }
                }
            }
            int lastIdx = *(int*)((char*)buf + -4) - 1;
            if ((lastIdx < *(int*)((char*)buf + -4)) && (lastIdx > -1)) {
                char ch = buf[lastIdx];
                buf[lastIdx] = '\0';
                char* bs = strrchr(buf, '\\');
                buf[lastIdx] = ch;
                if ((bs != nullptr) && ((int)(intptr_t)bs - (int)(intptr_t)buf > -1)) {
                    FUN_004f1840(buf, 0, 0);
                    FUN_00412ec0();
                    int* pp = (int*)((char*)buf + -8);
                    if ((pp != nullptr) && (pp != (int*)&DAT_008cacc8)) {
                        operator_delete__(pp);
                    }
                }
            }
            char slash2 = '\\';
            int blen2 = *(int*)((char*)buf + -4);
            if (blen2 > -1) {
                if (blen2 < blen2 + 1) {
                    FUN_004f3350();
                    buf[*(int*)((char*)buf + -4)] = '\0';
                }
                memmove(buf + blen2, &slash2, 1);
            }
            FUN_00489300();
            CreateDirectoryA(PTR_DAT_00726c0c, nullptr);
            int* pp2 = (int*)((char*)buf + -8);
            if ((pp2 != nullptr) && (pp2 != (int*)&DAT_008cacc8)) {
                operator_delete__(pp2);
            }
        }
    }
    FUN_00412df0();
    return param_1;
}

// 0x4f1700 — observed shape
void FUN_004f1700(void *self, void *param_1) {
    int* esi = (int*)self;
    int* ecx = nullptr;
    esi[1] = 0;
    esi[2] = 0;
    esi[4] = 0;
    esi[5] = 0;
    esi[0] = (int)(intptr_t)PTR_FUN_0071050c;
    esi[7] = 0;
    esi[6] = (int)(intptr_t)ecx;
    esi[3] = 0;
    typedef int (__stdcall *GetSizeFn)(void*);
    GetSizeFn getSize = (GetSizeFn)(*(void**)(*(void**)ecx + 0x10));
    int sz = getSize(ecx);
    esi[1] = (int)(intptr_t)param_1;
    esi[2] = sz;
    esi[4] = 0;
    esi[5] = 0;
    typedef void (__stdcall *CbFn)(void*);
    CbFn cb = (CbFn)(*(void**)(*(void**)esi + 0x14));
    cb(esi);
}

// 0x4f1760 — observed shape
void FUN_004f1760(void *self, uint8_t param_1) {
    int* a = (int*)self;
    a[0] = (int)(intptr_t)PTR_FUN_0071050c;
    FUN_004fcd60(self);
    if ((void*)(intptr_t)a[7] != nullptr) {
        operator_delete__((void*)(intptr_t)a[7]);
        a[7] = 0;
    }
    a[0] = (int)(intptr_t)PTR_LAB_007104f4;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4f17c0 — observed shape
void FUN_004f17c0(void *self) {
    FUN_00412f10();
    char* str = *(char**)((char*)self + 0x1c);
    char* end = str + *(int*)(str + -4);
    for (char* p = str; p < end; p++) {
        if (*p == '/') {
            *p = '\\';
        }
    }
}

// 0x4f1810 — observed shape
void FUN_004f1810(wchar_t *str, void *edi) {
    if (str == nullptr) {
        FUN_004f3130(edi);
        return;
    }
    wcslen(str);
    FUN_004f3130(edi);
}

// 0x4f1840 — observed shape
void FUN_004f1840(void *self, int edx, int ecx) {
    int start = edx;
    int len = ecx;
    if (start < 0) start = 0;
    if (len < 0) len = 0;
    int total = *(int*)(*(char**)self + -4);
    if (total < start + len) {
        len = total - start;
    }
    if (total < start) {
        len = 0;
    }
    if ((start == 0) && (len == total)) {
        FUN_00412df0();
        return;
    }
    FUN_004f30d0(start);
    FUN_00412df0();
}

// 0x4f18c0 — observed shape
void FUN_004f18c0(int *pos, char ch, void *self) {
    int cur = *pos;
    int result;
    if ((cur < *(int*)(*(char**)self + -4)) && (cur > -1)) {
        char* hit = strchr(*(char**)self + cur, ch);
        if (hit != nullptr) {
            result = (int)(hit - *(char**)self);
            goto done;
        }
    }
    result = -1;
done:
    *pos = result;
    if (result < 0) {
        FUN_004f1840(self, result, 0);
        return;
    }
    *pos = result + 1;
    FUN_004f1840(self, result + 1, 0);
}

// 0x4f1930 — observed shape
uint32_t FUN_004f1930(uint32_t param_1, int *pos, void *self, int c1, char c2) {
    int cur = *pos;
    int result;
    if ((cur < *(int*)(*(char**)self + -4)) && (cur > -1)) {
        char* hit = strchr(*(char**)self + cur, (char)c1);
        if (hit != nullptr) {
            result = (int)(hit - *(char**)self);
            goto second;
        }
    }
    result = -1;
second:
    *pos = result;
    if (result > -1) {
        int cur2 = result + 1;
        int result2;
        if ((cur2 < *(int*)(*(char**)self + -4)) && (cur2 > -1)) {
            char* hit2 = strchr(*(char**)self + cur2, c2);
            if (hit2 != nullptr) {
                result2 = (int)(hit2 - *(char**)self);
                goto done2;
            }
        }
        result2 = -1;
done2:
        *pos = result2;
        if (result2 > -1) {
            *pos = result2 + 1;
            FUN_004f1840(self, result2 + 1, 0);
            FUN_00412ec0();
            int* blk = (int*)((char*)c1 + -8);
            if ((blk != nullptr) && (blk != (int*)&DAT_008cacc8)) {
                operator_delete__(blk);
            }
        }
    }
    FUN_00412df0();
    return param_1;
}

// 0x4f1a10 — observed shape
uint32_t FUN_004f1a10(uint32_t param_1, int *pos, void *self) {
    int cur = *pos;
    int idx = *(int*)(*(char**)self + cur + -4) - 1;
    if ((*(int*)(*(char**)self + cur + -4) <= idx) || (idx < 0)) goto tail;
    uint8_t saved = *(uint8_t*)(*(char**)self + cur + idx);
    *(uint8_t*)(*(char**)self + cur + idx) = 0;
    char* dot = strrchr(*(char**)self, '.');
    *(uint8_t*)(idx + *(char**)self) = saved;
    if (dot == nullptr) goto tail;
    int dotPos = (int)(dot - *(char**)self);
    if (dotPos == -1) goto tail;
    int idx2 = *(int*)(*(char**)self + -4) - 1;
    if ((idx2 < *(int*)(*(char**)self + -4)) && (idx2 > -1)) {
        uint8_t saved2 = *(uint8_t*)(*(char**)self + idx2);
        *(uint8_t*)(*(char**)self + idx2) = 0;
        char* bs = strrchr(*(char**)self, '\\');
        *(uint8_t*)(idx2 + *(char**)self) = saved2;
        if (bs != nullptr) {
            int bsPos = (int)(bs - *(char**)self);
            goto check;
        }
        idx2 = -1;
        goto check;
    }
    idx2 = -1;
check:
    if (idx2 < dotPos) {
        FUN_004f1840(self, idx2, 0);
        FUN_00412ec0();
        int* blk = (int*)((char*)pos + -8);
        if ((blk != nullptr) && (blk != (int*)&DAT_008cacc8)) {
            operator_delete__(blk);
        }
    }
tail:
    FUN_00412df0();
    return param_1;
}

// 0x4f1b10 — observed shape
void FUN_004f1b10(int *param_1) {
    uint8_t* str = (uint8_t*)(intptr_t)*param_1;
    if (*(int*)(str + -4) != 0) {
        uint8_t* found = nullptr;
        uint8_t* limit = str + *(int*)(str + -4) - 1;
        if (str <= str + *(int*)(str + -4) - 1) {
            uint8_t* p = limit;
            do {
                uint8_t ch = *p;
                int8_t sch = (int8_t)ch;
                if ((sch > -0x80) && (sch <= 0x7f) && isspace((unsigned)ch) == 0) break;
                p = p - 1;
                found = p + 1;
            } while ((uint8_t*)(intptr_t)*param_1 <= p);
            if (found != nullptr) {
                *found = 0;
                *(int*)(*(char**)param_1 + -4) = (int)(found - (uint8_t*)(intptr_t)*param_1);
            }
        }
    }
}
