// Reconstruction batch mass_0293 — Sid Meier's Pirates! (2004), PE32 i386.
// Ghidra 12.2 pseudocode translation. Provider-specific pseudocode, not original source.
#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef unsigned char byte;   // Ghidra byte type used by the listings

// Referenced helpers (addresses as reported by the corpus listings).
extern void *FUN_0060d19b(int size);
extern int   FUN_0065b52c(int a, int b, int c, int d, int e, ...);
extern int   FUN_0065ac49(void *parent, int index, const char *name);
extern void *FUN_0065abf1(...);
extern void  FUN_0063336c(int object);
extern void  FUN_00632325(...);                    // variadic diagnostic reporter
extern void  FUN_00632420(int value);
extern int   FUN_00634393(int a, int b);
extern int   FUN_0065b202(int a, int b, int c, int d, int e);
extern int   FUN_0065b679(int a, ...);
extern int   FUN_0065b6e3(int a, ...);
extern int   FUN_0065b469(void);
extern void  FUN_00632729(void *object, int flag);
extern int   FUN_006328e2(int a);
extern int   FUN_00634aaf(int *a, int *b, int **c, int **d, int *out);
extern int   FUN_00634446(int a, int b, int c);
extern int   FUN_0063302f(int a, int b);
extern unsigned FUN_006331d2(int *a);
extern int   FUN_00633174(double *out, void *src, int *extra);
extern int   FUN_0063324e(int *a);
extern int   FUN_00636edb(int a, void *b, int c, int d, int e, unsigned f, int *g, int *h);
extern void *FUN_00533c78(unsigned size);
extern int   FUN_005f7fa4(void *name, int index, void *out);
extern int   FUN_0065b62d(void *src, void *owner);
extern void  operator_delete(void *p);

// ---------------------------------------------------------------------------
// 0x634e2f — observed shape: advance a chain of nodes until field +4 == 3,
// allocate a 0x50-byte container, seed field +0x20 through a virtual call on
// param_2 when supplied, then append "Types" entries for every child whose
// field +8 names a node of kind 0xd carrying a non-null name at +0x10.
// ---------------------------------------------------------------------------
int FUN_634e2f(int param_1, int *param_2)
{
    int iVar1;
    int iVar2;
    void *uVar3;
    int *piVar4;
    int local_8;

    for (; *(int *)(param_1 + 4) != 3; param_1 = *(int *)(param_1 + 8)) {
    }
    iVar1 = (int)FUN_0060d19b(0x50);
    if (iVar1 == 0) {
        local_8 = 0;
    }
    else {
        local_8 = FUN_0065b52c(0, 0, 0, 0, 1, (void *)(param_1 + 0x10));
    }
    if (local_8 == 0) {
LAB_00634f13:
        local_8 = 0;
    }
    else {
        if (param_2 != (int *)0x0) {
            iVar1 = (**(int (***)(void))(*param_2 + 4))();
            *(int *)(local_8 + 0x20) = iVar1;
            if (iVar1 == 0) goto LAB_00634f13;
        }
        param_1 = *(int *)(local_8 + 0x20);
        piVar4 = (int *)(local_8 + 0x10);
        if (param_1 != 0) {
            do {
                iVar1 = *(int *)(param_1 + 8);
                if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xd)) &&
                    (*(int *)(iVar1 + 0x10) != 0)) {
                    iVar2 = (int)FUN_0060d19b(0x14);
                    if (iVar2 == 0) {
                        iVar2 = 0;
                    }
                    else {
                        iVar2 = FUN_0065ac49(0, 0, "Types");
                    }
                    *piVar4 = iVar2;
                    if (iVar2 == 0) goto LAB_00634f13;
                    uVar3 = FUN_0065abf1(*(void **)(iVar1 + 0x10));
                    *(void **)(*piVar4 + 8) = uVar3;
                    if (*(int *)(*piVar4 + 8) == 0) goto LAB_00634f13;
                    piVar4 = (int *)(*piVar4 + 0xc);
                }
                param_1 = *(int *)(param_1 + 0xc);
            } while (param_1 != 0);
        }
        FUN_0063336c(local_8);
    }
    return local_8;
}

// ---------------------------------------------------------------------------
// 0x6353a8 — observed shape: only a node of kind 0xf with a non-null 32-bit
// value block of more than three entries is accepted; the high word of the
// first value selects one of four type tags, then a container + 0x24-byte
// descriptor + 0x40-byte value object + "Value" child are built in sequence.
// ---------------------------------------------------------------------------
int FUN_6353a8(int param_1)
{
    unsigned uVar1;
    int iVar2;
    int iVar3;
    int iVar4;

    iVar4 = param_1;
    if ((((param_1 != 0) && (*(int *)(param_1 + 4) == 0xf)) &&
         (*(unsigned **)(param_1 + 0x30) != (unsigned *)0x0)) &&
        (3 < *(unsigned *)(param_1 + 0x34))) {
        uVar1 = **(unsigned **)(param_1 + 0x30) & 0xffff0000;
        if (uVar1 == 0x7ffe0000) {
            param_1 = 0x1c;
        }
        else if (uVar1 == 0x7fff0000) {
            param_1 = 0x1b;
        }
        else if (uVar1 == 0xfffe0000) {
            param_1 = 0x1a;
        }
        else {
            if (uVar1 != 0xffff0000) {
                return 0;
            }
            param_1 = 0x19;
        }
        iVar2 = (int)FUN_0060d19b(0x50);
        if (iVar2 == 0) {
            iVar2 = 0;
        }
        else {
            iVar2 = FUN_0065b52c(0, 0, 0, 0, 1, (void *)(iVar4 + 0x10));
        }
        if (iVar2 != 0) {
            iVar3 = (int)FUN_0060d19b(0x24);
            if (iVar3 == 0) {
                iVar3 = 0;
            }
            else {
                iVar3 = FUN_0065b202(3, param_1, 1, 1, 0x200);
            }
            *(int *)(iVar2 + 0x10) = iVar3;
            if (iVar3 != 0) {
                iVar3 = (int)FUN_0060d19b(0x40);
                if (iVar3 == 0) {
                    iVar4 = 0;
                }
                else {
                    iVar4 = FUN_0065b6e3(5, *(void **)(iVar4 + 0x30),
                                          *(void **)(iVar4 + 0x34),
                                          (void *)(iVar4 + 0x10));
                }
                *(int *)(iVar2 + 0x20) = iVar4;
                if (iVar4 != 0) {
                    iVar4 = (int)FUN_0060d19b(0x14);
                    if (iVar4 == 0) {
                        iVar4 = 0;
                    }
                    else {
                        iVar4 = FUN_0065ac49(*(void **)(iVar2 + 0x20), 0, "Value");
                    }
                    if (iVar4 != 0) {
                        *(int *)(iVar2 + 0x20) = iVar4;
                        FUN_0063336c(iVar2);
                        return iVar2;
                    }
                }
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6354e2 — observed shape: ECX receiver's +0x20 owner block builds a
// container, a 0x24-byte descriptor with tag 0x14, a 4-element value object,
// copies an optional source name into +0x18, then attaches "Value".
// ---------------------------------------------------------------------------
int FUN_6354e2(void *self, int param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = (int)FUN_0060d19b(0x50);
    if (iVar1 == 0) {
        iVar1 = 0;
    }
    else {
        iVar1 = FUN_0065b52c(0, 0, 0, 0, 1, (void *)((char *)self + 0x20));
    }
    if (iVar1 != 0) {
        iVar2 = (int)FUN_0060d19b(0x24);
        if (iVar2 == 0) {
            iVar2 = 0;
        }
        else {
            iVar2 = FUN_0065b202(3, 0x14, 1, 1, 0x200);
        }
        *(int *)(iVar1 + 0x10) = iVar2;
        if (iVar2 != 0) {
            iVar2 = (int)FUN_0060d19b(0x40);
            if (iVar2 == 0) {
                iVar2 = 0;
            }
            else {
                iVar2 = FUN_0065b679(4, 0, (void *)((char *)self + 0x20));
            }
            if (iVar2 != 0) {
                *(int *)(iVar1 + 0x20) = iVar2;
                if (param_1 != 0) {
                    iVar3 = (int)FUN_0065abf1((void *)param_1);
                    *(int *)(iVar2 + 0x18) = iVar3;
                    if (iVar3 == 0) {
                        return 0;
                    }
                }
                iVar2 = (int)FUN_0060d19b(0x14);
                if (iVar2 == 0) {
                    iVar2 = 0;
                }
                else {
                    iVar2 = FUN_0065ac49(*(void **)(iVar1 + 0x20), 0, "Value");
                }
                if (iVar2 != 0) {
                    *(int *)(iVar1 + 0x20) = iVar2;
                    FUN_0063336c(iVar1);
                    return iVar1;
                }
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6355bc — observed shape: identical construction to 0x6354e2 except the
// descriptor tag is 0x1d.
// ---------------------------------------------------------------------------
int FUN_6355bc(void *self, int param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = (int)FUN_0060d19b(0x50);
    if (iVar1 == 0) {
        iVar1 = 0;
    }
    else {
        iVar1 = FUN_0065b52c(0, 0, 0, 0, 1, (void *)((char *)self + 0x20));
    }
    if (iVar1 != 0) {
        iVar2 = (int)FUN_0060d19b(0x24);
        if (iVar2 == 0) {
            iVar2 = 0;
        }
        else {
            iVar2 = FUN_0065b202(3, 0x1d, 1, 1, 0x200);
        }
        *(int *)(iVar1 + 0x10) = iVar2;
        if (iVar2 != 0) {
            iVar2 = (int)FUN_0060d19b(0x40);
            if (iVar2 == 0) {
                iVar2 = 0;
            }
            else {
                iVar2 = FUN_0065b679(4, 0, (void *)((char *)self + 0x20));
            }
            if (iVar2 != 0) {
                *(int *)(iVar1 + 0x20) = iVar2;
                if (param_1 != 0) {
                    iVar3 = (int)FUN_0065abf1((void *)param_1);
                    *(int *)(iVar2 + 0x18) = iVar3;
                    if (iVar3 == 0) {
                        return 0;
                    }
                }
                iVar2 = (int)FUN_0060d19b(0x14);
                if (iVar2 == 0) {
                    iVar2 = 0;
                }
                else {
                    iVar2 = FUN_0065ac49(*(void **)(iVar1 + 0x20), 0, "Value");
                }
                if (iVar2 != 0) {
                    *(int *)(iVar1 + 0x20) = iVar2;
                    FUN_0063336c(iVar1);
                    return iVar1;
                }
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x635696 — observed shape: variant conversion between a tagged value
// (tag at +0, payload at +8) and its wide/narrow forms; unsupported tag
// pairs return 0x80004005 (E_FAIL).
// ---------------------------------------------------------------------------
unsigned FUN_635696(int *param_1, int *param_2)
{
    double dVar1;
    int iVar2;
    unsigned uVar3;

    iVar2 = *param_1;
    if (iVar2 == 0) {
        iVar2 = *param_2;
        if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
            param_1[2] = (unsigned)(param_2[2] != 0);
            return 0;
        }
        if (iVar2 == 3) {
            param_1[2] = (unsigned)(*(double *)(param_2 + 2) != 0.0);
            return 0;
        }
        return 0x80004005;
    }
    if ((iVar2 == 1) || (iVar2 == 2)) {
        iVar2 = *param_2;
        if (iVar2 == 0) {
            uVar3 = (unsigned)(param_2[2] != 0);
        }
        else if ((iVar2 == 1) || (iVar2 == 2)) {
            uVar3 = param_2[2];
        }
        else {
            if (iVar2 != 3) {
                return 0x80004005;
            }
            uVar3 = (unsigned)(long long)*(double *)(param_2 + 2);   // ftol
        }
        goto LAB_00635788;
    }
    if (iVar2 == 3) {
        iVar2 = *param_2;
        if (iVar2 == 0) {
            dVar1 = (double)(param_2[2] != 0);
        }
        else if (iVar2 == 1) {
            dVar1 = (double)param_2[2];
        }
        else if (iVar2 == 2) {
            dVar1 = (double)param_2[2];
            if (param_2[2] < 0) {
                dVar1 = dVar1 + 4294967296.0;
            }
        }
        else {
            if (iVar2 != 3) {
                return 0x80004005;
            }
            dVar1 = *(double *)(param_2 + 2);
        }
        *(double *)(param_1 + 2) = dVar1;
        return 0;
    }
    if (iVar2 == 4) {
        if (*param_2 != 4) goto LAB_006356d1;
    }
    else {
        if (iVar2 != 5) {
            return 0x80004005;
        }
LAB_006356d1:
        if (*param_2 != 4) {
            if (*param_2 == 5) {
                param_1[2] = param_2[2];
                param_1[3] = param_2[3];
                return 0;
            }
            return 0x80004005;
        }
        *param_1 = 4;
    }
    uVar3 = param_2[2];
LAB_00635788:
    param_1[2] = uVar3;
    return 0;
}

// ---------------------------------------------------------------------------
// Additional referenced helpers for the remaining definitions.
// ---------------------------------------------------------------------------
extern int   FUN_00632959(void *name);
extern int   FUN_006329e7(void *a, void *b);
extern void *FUN_0063271d(void);
extern int   FUN_0065b377(void);
extern int   FUN_0065b01d(int a, int b, int c, int d);
extern int   FUN_0065b27f(void);
extern int   FUN_0063395f(int a, int b);
extern int   FUN_006325ec(int *a, int b);
extern void  FUN_0063237b(...);
extern int   FUN_00634161(int a, int b, int c, unsigned d);
extern int   FUN_00634270(int a, int b);
extern int   FUN_0063284b(void *a);
extern int   FUN_0063477e(void *a, int b, int *c, int *d, int e);
extern int   FUN_0060f155(void *a);

extern "C" int tolower(int c);
extern "C" int _stricmp(const char *a, const char *b);
extern "C" double fabs(double x);
extern "C" double acos(double x);
extern "C" double asin(double x);
extern "C" double atan2(double y, double x);
extern "C" double ceil(double x);
extern "C" double floor(double x);
extern "C" double fmod(double x, double y);
extern "C" double cos(double x);
extern "C" double cosh(double x);
extern "C" double sin(double x);
extern "C" double sinh(double x);
extern "C" double tan(double x);
extern "C" double tanh(double x);
extern "C" double exp(double x);
extern "C" double log(double x);
extern "C" double log10(double x);
extern "C" double pow(double x, double y);
extern "C" double sqrt(double x);
extern "C" int   _finite(double x);
extern "C" int   _isnan(double x);

// Byte-wise comparison exactly as the listings unroll it (returns 0 on match).
static int recon_strcmp(const char *lhs, const char *rhs)
{
    const unsigned char *a = (const unsigned char *)lhs;
    const unsigned char *b = (const unsigned char *)rhs;
    for (;;) {
        unsigned char ca = *a;
        bool lt = ca < *b;
        if (ca != *b) return (1 - (unsigned)lt) - (unsigned)(lt != 0);
        if (ca == 0) break;
        a++;
        b++;
    }
    return 0;
}

// Prefix comparison of exactly n bytes (the unrolled keyword tester).
static bool recon_eq_n(const char *s, const char *k, int n)
{
    bool same = true;
    do {
        if (n == 0) break;
        n--;
        same = *s == *k;
        s++;
        k++;
    } while (same);
    return same;
}

// ---------------------------------------------------------------------------
// 0x634f17 — observed shape: build a container for a subscript expression.
// Only a node of kind 3 whose child list entry is a node of kind 0xd with a
// four-word selector (param_1[4]) is accepted; the selector is either an
// array index chain (kind 1 child) or a swizzle string (kind 9 child).
// ---------------------------------------------------------------------------
int FUN_634f17(void *self, int *param_1, char *param_2)
{
    int iVar1;
    int iVar2;
    int iVar7;
    int iVar8;
    int iVar10;
    int iVar12;
    int iVar14;
    char cVar3;
    char cVar4;
    int *piVar5;
    int *piVar6;
    int *piVar18;
    int *piVar19;
    char *pcVar13;
    char *pcVar15;
    char *pcVar9;
    char *pszIndex;
    unsigned uVar17;
    int *local_1c;
    int local_14;
    unsigned local_10;
    int local_c;
    char *local_8;

    iVar8 = (int)param_2;
    if (param_2 == (char *)0x0) {
        return 0;
    }
    if (*(int *)((int)param_2 + 4) != 3) {
        return 0;
    }
    if (param_1 == (int *)0x0) {
        return 0;
    }
    if (param_1[1] != 0xd) {
        return 0;
    }
    iVar12 = param_1[4];
    iVar1 = (int)param_2 + 0x10;
    iVar10 = (int)FUN_0060d19b(0x50);
    if (iVar10 == 0) {
        local_c = 0;
    }
    else {
        local_c = FUN_0065b52c(0, 0x17, 0, 0, 1, (void *)iVar1);
    }
    if (local_c == 0) {
        return 0;
    }
    if (iVar12 != 0) {
        if (*(int *)(iVar12 + 4) == 1) {
            param_2 = (char *)0x0;
            local_1c = (int *)iVar12;
            do {
                iVar12 = *(int *)((int)local_1c + 8);
                if ((iVar12 != 0) && (*(int *)(iVar12 + 4) == 6)) {
                    iVar10 = *(int *)(iVar12 + 0x18);
                    if (recon_strcmp(*(const char **)(*(int *)(iVar12 + 0x14) + 0x18),
                                     *(const char **)(iVar8 + 0x18)) == 0) {
                        if (*(int *)(iVar10 + 0x20) != 0) {
                            iVar12 = (**(int (***)(void))(**(int **)(iVar10 + 0x20) + 4))();
                            *(int *)(local_c + 0x10) = iVar12;
                            if (iVar12 == 0) {
                                return 0;
                            }
                        }
                        iVar12 = (int)FUN_0060d19b(0x40);
                        if (iVar12 == 0) {
                            iVar12 = 0;
                        }
                        else {
                            iVar12 = FUN_0065b679(2, (void *)param_2, (void *)iVar1);
                        }
                        *(int *)(local_c + 0x24) = iVar12;
                        goto LAB_0063537a;
                    }
                    iVar12 = FUN_00632959(*(void **)(iVar10 + 0x20));
                    param_2 = (char *)((int)param_2 + iVar12);
                }
                local_1c = *(int **)((int)local_1c + 0xc);
            } while (local_1c != (int *)0x0);
        }
        else if (*(int *)(iVar12 + 4) == 9) {
            piVar5 = *(int **)(iVar12 + 0x18);
            pcVar15 = *(char **)((int)param_2 + 0x18);
            piVar6 = *(int **)(iVar12 + 0x1c);
            uVar17 = *(unsigned *)(iVar12 + 0x20) & 0x200;
            pcVar9 = pcVar15;
            do {
                pcVar13 = pcVar9;
                pcVar9 = pcVar13 + 1;
            } while (*pcVar13 != '\0');
            cVar3 = *pcVar15;
            if (cVar3 == '_') {
                if (*(int *)(iVar12 + 0x10) != 2) goto LAB_00634fff;
                if ((pcVar13 <= pcVar15 + 1) || (local_14 = 3, pcVar15[1] != 'm')) {
                    local_14 = 2;
                }
            }
            else {
                if (cVar3 < 'a') goto LAB_00634fff;
                if (((cVar3 < 'c') || (cVar3 == 'g')) || (cVar3 == 'r')) {
                    if ((*(int *)(iVar12 + 0x10) != 0) && (*(int *)(iVar12 + 0x10) != 1))
                        goto LAB_00634fff;
                    local_14 = 1;
                }
                else {
                    if (((cVar3 < 'w') || ('z' < cVar3)) ||
                        ((*(int *)(iVar12 + 0x10) != 0 && (*(int *)(iVar12 + 0x10) != 1))))
                        goto LAB_00634fff;
                    local_14 = 0;
                }
            }
            local_10 = 0;
            local_1c = (int *)(local_c + 0x24);
            if (pcVar15 < pcVar13) {
                param_2 = pcVar15 + 2;
                local_8 = pcVar15 + 3;
                piVar18 = param_1;
                piVar19 = param_1;
                do {
                    if (3 < local_10) break;
                    if (local_14 == 0) {
                        cVar3 = *pcVar15;
                        if (cVar3 == 'w') {
LAB_0063525a:
                            piVar19 = (int *)0x3;
                        }
                        else if (cVar3 == 'x') {
LAB_00635238:
                            piVar19 = (int *)0x0;
                        }
                        else {
                            if (cVar3 != 'y') {
                                if (cVar3 == 'z') goto LAB_00635256;
                                goto LAB_00634fff;
                            }
LAB_0063523c:
                            piVar19 = (int *)0x1;
                        }
LAB_0063525d:
                        piVar18 = (int *)0x0;
                        pcVar15 = pcVar15 + 1;
                        local_8 = local_8 + 1;
                        param_2 = param_2 + 1;
                    }
                    else {
                        if (local_14 == 1) {
                            cVar3 = *pcVar15;
                            if (cVar3 == 'a') goto LAB_0063525a;
                            if (cVar3 == 'b') {
LAB_00635256:
                                piVar19 = (int *)0x2;
                                goto LAB_0063525d;
                            }
                            if (cVar3 == 'g') goto LAB_0063523c;
                            if (cVar3 == 'r') goto LAB_00635238;
                            goto LAB_00634fff;
                        }
                        if (local_14 == 2) {
                            if (((((pcVar13 <= param_2) || (*pcVar15 != '_')) ||
                                  (cVar3 = pcVar15[1], cVar3 < '1')) ||
                                 (('9' < cVar3 || (cVar4 = *param_2, cVar4 < '1')))) ||
                                ('9' < cVar4))
                                goto LAB_00634fff;
                            local_8 = local_8 + 3;
                            piVar18 = (int *)(cVar3 + -0x31);
                            piVar19 = (int *)(cVar4 + -0x31);
                            pcVar15 = pcVar15 + 3;
                            param_2 = param_2 + 3;
                        }
                        else if (local_14 == 3) {
                            if ((((pcVar13 <= local_8) || (*pcVar15 != '_')) ||
                                 ((pcVar15[1] != 'm' ||
                                   (((cVar3 = *param_2, cVar3 < '0' || ('9' < cVar3)) ||
                                     (cVar4 = *local_8, cVar4 < '0')))))) ||
                                ('9' < cVar4))
                                goto LAB_00634fff;
                            local_8 = local_8 + 4;
                            piVar18 = (int *)(cVar3 + -0x30);
                            piVar19 = (int *)(cVar4 + -0x30);
                            pcVar15 = pcVar15 + 4;
                            param_2 = param_2 + 4;
                        }
                    }
                    if ((piVar5 <= piVar18) || (piVar6 <= piVar19)) goto LAB_00634fff;
                    iVar10 = (int)FUN_0060d19b(0x14);
                    if (iVar10 == 0) {
                        iVar10 = 0;
                    }
                    else {
                        iVar10 = FUN_0065ac49(0, 0, "Swizzle");
                    }
                    *local_1c = iVar10;
                    if (iVar10 == 0) {
                        return 0;
                    }
                    iVar10 = (int)FUN_0060d19b(0x40);
                    if (iVar10 == 0) {
                        iVar10 = 0;
                    }
                    else {
                        iVar10 = FUN_0065b679(2, (void *)((int)piVar18 * (int)piVar6 + (int)piVar19),
                                              (void *)iVar1);
                    }
                    *(int *)(*local_1c + 8) = iVar10;
                    if (iVar10 == 0) {
                        return 0;
                    }
                    local_1c = (int *)(*local_1c + 0xc);
                    local_10 = local_10 + 1;
                } while (pcVar15 < pcVar13);
                if ((pcVar15 < pcVar13) || (4 < local_10)) goto LAB_00634fff;
            }
            iVar10 = *(int *)(local_c + 0x24);
            while ((iVar10 != 0 && (uVar17 == 0))) {
                iVar7 = *(int *)(iVar10 + 0xc);
                if (iVar7 != 0) {
                    iVar14 = iVar7;
                    do {
                        if (*(int *)(*(int *)(iVar10 + 8) + 0x18) ==
                            *(int *)(*(int *)(iVar14 + 8) + 0x18)) {
                            uVar17 = 1;
                            break;
                        }
                        iVar14 = *(int *)(iVar14 + 0xc);
                    } while (iVar14 != 0);
                }
                iVar10 = iVar7;
            }
            iVar10 = (int)FUN_0060d19b(0x24);
            if (iVar10 == 0) {
                iVar12 = 0;
            }
            else {
                iVar12 = FUN_0065b202(local_10 != 1, *(int *)(iVar12 + 0x14), 1, local_10,
                                      -(unsigned)(uVar17 != 0) & 0x200);
            }
            *(int *)(local_c + 0x10) = iVar12;
LAB_0063537a:
            if (iVar12 == 0) {
                return 0;
            }
            iVar12 = (**(int (***)(void))(*param_1 + 4))();
            *(int *)(local_c + 0x20) = iVar12;
            if (iVar12 != 0) {
                FUN_0063336c(local_c);
                return local_c;
            }
        }
    }
LAB_00634fff:
    FUN_00632325(self, iVar1, 0xbca, "invalid subscript '%s'", *(void **)(iVar8 + 0x18));
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6357d2 — observed shape: store a variant payload as an unsigned 32-bit
// value; tags 1/2 copy the payload, tag 0 tests a bool word, tag 3 converts a
// double. Unknown tag returns E_FAIL.
// ---------------------------------------------------------------------------
unsigned FUN_6357d2(unsigned *param_1, int *param_2)
{
    int iVar1;
    unsigned uVar2;

    iVar1 = *param_2;
    if (iVar1 == 0) {
        uVar2 = (unsigned)(param_2[2] != 0);
    }
    else if ((iVar1 == 1) || (iVar1 == 2)) {
        uVar2 = (unsigned)param_2[2];
    }
    else {
        if (iVar1 != 3) {
            return 0x80004005;
        }
        uVar2 = (unsigned)(long long)*(double *)(param_2 + 2);   // ftol
    }
    *param_1 = uVar2;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x635831 — observed shape: store a double into a variant slot, converting
// from the target tag: tag 0 becomes a bool word, tags 1/2 truncate, tag 3
// stores the double itself.
// ---------------------------------------------------------------------------
unsigned FUN_635831(int *param_1, double param_2)
{
    int iVar1;

    iVar1 = *param_1;
    if (iVar1 == 0) {
        if (param_2 == 0.0) {
            iVar1 = 0;
        }
        else {
            iVar1 = 1;
        }
    }
    else {
        if ((iVar1 != 1) && (iVar1 != 2)) {
            if (iVar1 == 3) {
                *(double *)(param_1 + 2) = param_2;
                return 0;
            }
            return 0x80004005;
        }
        iVar1 = (int)(long long)param_2;   // ftol
    }
    param_1[2] = iVar1;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6358a4 — observed shape: semantic comparison of two typed objects. A
// null/non-null mismatch yields 2; string names compare byte-wise; otherwise
// the high/low word pairs of the two decompiled constants must be compatible.
// The remaining loop walks param_1's child list and compares each value node.
// ---------------------------------------------------------------------------
int FUN_6358a4(int param_1, int param_2, int param_3, unsigned param_4)
{
    int *piVar1;
    byte bVar2;
    void *uVar3;
    int iVar4;
    int iVar6;
    int iVar7;
    byte *pbVar5;
    byte *pbVar8;
    bool bVar9;
    unsigned char local_24[4];
    unsigned local_20;
    unsigned char local_18[4];
    unsigned local_14;
    int local_8;

    local_8 = 0;
    if ((param_2 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
        if ((param_2 == 0) != (*(int *)(param_1 + 0x1c) == 0)) {
            local_8 = 2;
        }
    }
    else {
        iVar4 = FUN_005f7fa4(*(void **)(*(int *)(param_1 + 0x1c) + 0x18), 0, local_18);
        if ((iVar4 < 0) ||
            (iVar4 = FUN_005f7fa4(*(void **)(param_2 + 0x18), 0, local_24), iVar4 < 0)) {
            pbVar8 = *(byte **)(*(int *)(param_1 + 0x1c) + 0x18);
            pbVar5 = *(byte **)(param_2 + 0x18);
            do {
                bVar2 = *pbVar5;
                bVar9 = bVar2 < *pbVar8;
                if (bVar2 != *pbVar8) {
LAB_00635959:
                    iVar4 = (1 - (unsigned)bVar9) - (unsigned)(bVar9 != 0);
                    goto LAB_0063595e;
                }
                if (bVar2 == 0) break;
                bVar2 = pbVar5[1];
                bVar9 = bVar2 < pbVar8[1];
                if (bVar2 != pbVar8[1]) goto LAB_00635959;
                pbVar5 = pbVar5 + 2;
                pbVar8 = pbVar8 + 2;
            } while (bVar2 != 0);
            iVar4 = 0;
LAB_0063595e:
            if (iVar4 != 0) {
                return -1;
            }
        }
        else if (local_14 != local_20) {
            if (((local_20 ^ local_14) & 0xffff0000) != 0) {
                return -1;
            }
            if (((local_14 & 0xffff) != 0) && ((local_20 & 0xffff) != 0)) {
                return -1;
            }
            local_8 = 2 - (unsigned)((local_20 & 0xffff) != 0);
        }
    }
    iVar4 = *(int *)(param_1 + 0x24);
    param_1 = param_3;
    if (iVar4 != 0) {
        do {
            piVar1 = (int *)(iVar4 + 8);
            iVar4 = *(int *)(iVar4 + 0xc);
            bVar9 = false;
            if ((iVar4 != 0) && (*(int *)(*(int *)(iVar4 + 8) + 4) == 0xc)) {
                iVar4 = *(int *)(iVar4 + 0xc);
                bVar9 = true;
            }
            if (((param_4 & 0x10) == 0) ||
                ((*(byte *)(*(int *)(*piVar1 + 0x18) + 0x1c) & 0x40) != 0)) {
                if (param_1 == 0) {
                    if (!bVar9) {
                        return -1;
                    }
                }
                else {
                    iVar7 = *(int *)(*piVar1 + 0x18);
                    uVar3 = *(void **)(iVar7 + 0x20);
                    if (*(int *)(param_1 + 8) == 0) {
                        param_2 = 0;
                    }
                    else {
                        param_2 = *(int *)(*(int *)(param_1 + 8) + 0x10);
                    }
                    if ((*(byte *)(iVar7 + 0x1c) & 0x10) != 0) {
                        iVar6 = FUN_00634446((int)uVar3, param_2, 0);
                        if (iVar6 == 0) {
                            return -1;
                        }
                        iVar6 = FUN_00634270((int)uVar3, param_2);
                        local_8 = local_8 + iVar6;
                    }
                    if ((*(byte *)(iVar7 + 0x1c) & 0x20) != 0) {
                        iVar7 = FUN_0063284b((void *)param_2);
                        if (iVar7 != 0) {
                            return -1;
                        }
                        iVar7 = FUN_00634446(param_2, (int)uVar3, 0);
                        if (iVar7 == 0) {
                            return -1;
                        }
                        iVar7 = FUN_00634270(param_2, (int)uVar3);
                        local_8 = local_8 + iVar7;
                    }
                    param_1 = *(int *)(param_1 + 0xc);
                }
            }
        } while (iVar4 != 0);
    }
    if (param_1 == 0) {
        return local_8;
    }
    return -1;
}

// ---------------------------------------------------------------------------
// 0x635a73 — observed shape: ECX receiver's +0x14 "UsageType" child is
// created/looked up; an optional source string is duplicated into its +8
// slot, then the usage type is resolved and two flag bits are cleared.
// ---------------------------------------------------------------------------
int FUN_635a73(void *self, int param_1)
{
    int iVar1;
    int iVar2;

    iVar1 = (int)FUN_0060d19b(0x14);
    if (iVar1 == 0) {
        iVar1 = 0;
    }
    else {
        iVar1 = FUN_0065ac49(0, *(int *)((char *)self + 0x14), "UsageType");
    }
    if (iVar1 == 0) {
LAB_00635ac5:
        FUN_00632420(0);
        iVar1 = -0x7ff8fff2;
    }
    else {
        *(int *)((char *)self + 0x14) = iVar1;
        if (param_1 != 0) {
            iVar2 = (int)FUN_0065abf1((void *)param_1);
            *(int *)(iVar1 + 8) = iVar2;
            if (iVar2 == 0) goto LAB_00635ac5;
            iVar1 = FUN_00634393(iVar2, *(int *)(iVar2 + 0x18));
            if (iVar1 < 0) {
                return iVar1;
            }
            *(byte *)(iVar2 + 0x11) = *(byte *)(iVar2 + 0x11) & 0xf1;
        }
        iVar1 = 0;
    }
    return iVar1;
}

extern int   FUN_00635831(int dst, double value, void *ctx);
extern "C" double log2(double x);
extern "C" int    _fpclass(double x);

// Element accessors for 16-byte tagged records: tag word at +0, value at +8.
static inline double *recon_elem(double *base, int i)
{
    return (double *)((char *)base + 0x10 * i);
}
static inline double recon_val(double *base, int byteOff)
{
    return *(double *)((char *)base + byteOff);
}

// ---------------------------------------------------------------------------
// 0x635aeb — observed shape: evaluate a vector expression node of family
// 0x1a over the element list starting at param_1+0x24. Each list entry whose
// child is a node of kind 0xd supplies a buffer sized rows*columns; the
// opcode lives at descriptor->+8->+0x18 and selects one of the arithmetic
// kernels below. Results are converted back through FUN_00635831.
// ---------------------------------------------------------------------------
int FUN_635aeb(void *self, int param_1, double *param_2)
{
    double *pdVar10;
    double *pdVar15;
    double *pdVar16;
    double *pdVar9;
    double dVar3;
    double dVar4;
    double dVar5;
    double dVar6;
    double dVar20;
    unsigned uVar7;
    int iVar9;
    int iVar11;
    int iVar14;
    int iVar17;
    int local_10;
    int local_14;
    int local_20;
    int local_24;
    int local_28;
    int local_2c;
    double local_34;
    double *local_8;
    double *local_18;
    int desc[4];
    int *node[4];
    double *buf[4];
    int head;

    iVar17 = (int)param_2;
    if (param_1 == 0) {
        if (param_2 == (double *)0x0) {
            return 0;
        }
        return -0x7fffbffb;
    }
    if (*(int *)(param_1 + 4) != 0xd) {
        return -0x7fffbffb;
    }
    local_8 = (double *)(*(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x18));
    if (*(int *)(param_1 + 0x1c) != 0x1a) {
        return -0x7fffbffb;
    }
    for (int k = 0; k < 4; k++) {
        desc[k] = 0;
        node[k] = (int *)0x0;
        buf[k] = (double *)0x0;
    }
    head = *(int *)(param_1 + 0x24);
    local_18 = *(double **)(head + 8);
    if (local_18 != (double *)0x0) {
        local_10 = 0;
        do {
            iVar9 = *(int *)(local_18 + 1);          // entry -> child at +8
            if ((iVar9 != 0) && (*(int *)(iVar9 + 4) == 0xd)) {
                uVar7 = *(int *)(iVar9 + 0x18) * *(int *)(iVar9 + 0x14);
                desc[local_10 / 4] = (int)uVar7;
                node[local_10 / 4] = (int *)iVar9;
                buf[local_10 / 4] = (double *)FUN_00533c78(uVar7 * 0x10);
                if (buf[local_10 / 4] == (double *)0x0) {
                    iVar9 = -0x7ff8fff2;
                    goto cleanup;
                }
                iVar9 = FUN_637c38(self, (unsigned *)node[local_10 / 4],
                                  (int)buf[local_10 / 4]);
                if (iVar9 < 0) goto cleanup;
                local_14 = 0;
                if (uVar7 != 0) {
                    double *p = buf[local_10 / 4];
                    do {
                        iVar9 = FUN_00633174((double *)((char *)p + 8), p,
                                             (int *)(param_1 + 0x30));
                        if (iVar9 < 0) goto cleanup;
                        local_14++;
                        *(unsigned *)p = 3;
                        p = (double *)((char *)p + 0x10);
                    } while (local_14 < (int)uVar7);
                }
            }
            local_10 += 4;
            local_18 = *(double **)((char *)local_18 + 0xc);
        } while (local_18 != (double *)0x0);
    }

    {
        double *a = buf[0];
        double *b = buf[1];
        double *c = buf[2];
        double *r = (double *)((char *)param_2 + 8);
        int n = desc[0];
        int op = *(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0x18);
        pdVar10 = local_8;

        switch (op) {
        case 0:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = fabs(*recon_elem(a, i));
            break;
        case 1:
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                if ((x < -1.0) || (1.0 < x)) {
                    FUN_00632325(self, param_1 + 0x30, 0xbfe, "indefinite acos");
                }
                *recon_elem(r, i) = acos(x);
            }
            break;
        case 2:
            *recon_elem(r, 0) = 1.0;
            for (int i = 0; i < n; i++) {
                if (*recon_elem(a, i) == 0.0) {
                    *recon_elem(r, 0) = 0.0;
                    break;
                }
            }
            break;
        case 3:
            *recon_elem(r, 0) = 0.0;
            for (int i = 0; i < n; i++) {
                if (*recon_elem(a, i) != 0.0) {
                    *recon_elem(r, 0) = 1.0;
                    break;
                }
            }
            break;
        case 4:
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                if ((x < -1.0) || (1.0 < x)) {
                    FUN_00632325(self, param_1 + 0x30, 0xbff, "indefinite asin");
                }
                *recon_elem(r, i) = asin(x);
            }
            break;
        case 5:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = atan2(*recon_elem(a, i), 1.0);
            break;
        case 6:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = atan2(*recon_elem(a, i), *recon_elem(b, i));
            break;
        case 7:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = ceil(*recon_elem(a, i));
            break;
        case 8:
            for (int i = 0; i < n; i++) {
                double av = *recon_elem(a, i);
                double bv = *recon_elem(b, i);
                double cv = *recon_elem(c, i);
                *recon_elem(r, i) = (bv <= av) ? ((av <= cv) ? av : cv) : bv;
            }
            break;
        case 10:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = cos(*recon_elem(a, i));
            break;
        case 0xb:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = cosh(*recon_elem(a, i));
            break;
        case 0xc:
            *recon_elem(r, 0) = recon_val(a, 0x18) * recon_val(b, 0x28) -
                                recon_val(a, 0x28) * recon_val(b, 0x18);
            *recon_elem(r, 1) = recon_val(a, 0x28) * recon_val(b, 0x08) -
                                recon_val(b, 0x28) * recon_val(a, 0x08);
            *recon_elem(r, 2) = recon_val(b, 0x18) * recon_val(a, 0x08) -
                                recon_val(a, 0x18) * recon_val(b, 0x08);
            break;
        case 0xd:
        case 0xe:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = 0.0;
            break;
        case 0xf:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = *recon_elem(a, i) * 57.29577791868205;
            break;
        case 0x10: {
            int dim = *(int *)(node[0] + 0x14);
            if (dim == 1) {
                dVar20 = recon_val(a, 0x08);
            }
            else if (dim == 2) {
                dVar20 = recon_val(a, 0x38) * recon_val(a, 0x08) -
                         recon_val(a, 0x28) * recon_val(a, 0x18);
            }
            else if (dim == 3) {
                dVar20 = (recon_val(a, 0x78) * recon_val(a, 0x38) -
                          recon_val(a, 0x48) * recon_val(a, 0x68)) * recon_val(a, 0x28) +
                         ((recon_val(a, 0x88) * recon_val(a, 0x48) -
                           recon_val(a, 0x58) * recon_val(a, 0x78)) * recon_val(a, 0x08) -
                          (recon_val(a, 0x88) * recon_val(a, 0x38) -
                           recon_val(a, 0x58) * recon_val(a, 0x68)) * recon_val(a, 0x18));
            }
            else {
                if (dim != 4) {
                    iVar9 = -0x7fffbffb;
                    goto cleanup;
                }
                dVar20 = recon_val(a, 0xa8) * recon_val(a, 0xf8) -
                         recon_val(a, 0xb8) * recon_val(a, 0xe8);
                dVar5 = recon_val(a, 0xf8) * recon_val(a, 0x98) -
                        recon_val(a, 0xd8) * recon_val(a, 0xb8);
                dVar6 = recon_val(a, 0x98) * recon_val(a, 0xe8) -
                        recon_val(a, 0xa8) * recon_val(a, 0xd8);
                dVar4 = recon_val(a, 0x88) * recon_val(a, 0xf8) -
                        recon_val(a, 0xc8) * recon_val(a, 0xb8);
                dVar3 = recon_val(a, 0x88) * recon_val(a, 0xe8) -
                        recon_val(a, 0xc8) * recon_val(a, 0xa8);
                local_34 = recon_val(a, 0x88) * recon_val(a, 0xd8) -
                           recon_val(a, 0xc8) * recon_val(a, 0x98);
                *recon_elem(r, 0) =
                    ((local_34 * recon_val(a, 0x78) +
                      (dVar5 * recon_val(a, 0x48) - dVar4 * recon_val(a, 0x58))) *
                         recon_val(a, 0x28) +
                     ((dVar6 * recon_val(a, 0x78) +
                       (dVar20 * recon_val(a, 0x58) - dVar5 * recon_val(a, 0x68))) *
                          recon_val(a, 0x08) -
                      (dVar3 * recon_val(a, 0x78) +
                       (dVar20 * recon_val(a, 0x48) - dVar4 * recon_val(a, 0x68))) *
                          recon_val(a, 0x18))) -
                    (local_34 * recon_val(a, 0x68) +
                     (dVar6 * recon_val(a, 0x48) - dVar3 * recon_val(a, 0x58))) *
                        recon_val(a, 0x38);
                break;
            }
            *recon_elem(r, 0) = dVar20;
            break;
        }
        case 0x11:
            dVar20 = 0.0;
            for (int i = 0; i < n; i++) {
                dVar3 = *recon_elem(b, i) - *recon_elem(a, i);
                dVar20 = dVar3 * dVar3 + dVar20;
            }
            dVar20 = sqrt(dVar20);
            *recon_elem(r, 0) = dVar20;
            break;
        case 0x12:
            *recon_elem(r, 0) = 0.0;
            for (int i = 0; i < n; i++)
                *recon_elem(r, 0) += *recon_elem(b, i) * *recon_elem(a, i);
            break;
        case 0x13:
            *recon_elem(r, 0) = 1.0;
            *recon_elem(r, 1) = *recon_elem(b, 1) * *recon_elem(a, 1);
            *recon_elem(r, 2) = *recon_elem(a, 2);
            *recon_elem(r, 3) = *recon_elem(b, 3);
            break;
        case 0x14:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = exp(*recon_elem(a, i));
            break;
        case 0x15:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = pow(*recon_elem(a, i), *recon_elem(b, i));
            break;
        case 0x16:
            dVar20 = 0.0;
            for (int i = 0; i < n; i++) dVar20 += *recon_elem(b, i) * *recon_elem(a, i);
            for (int i = 0; i < n; i++) {
                dVar3 = *recon_elem(a, i);
                if (0.0 <= dVar20) dVar3 = -dVar3;
                *recon_elem(r, i) = dVar3;
            }
            break;
        case 0x17:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = floor(*recon_elem(a, i));
            break;
        case 0x18:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = fmod(*recon_elem(a, i), *recon_elem(b, i));
            break;
        case 0x19:
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                *recon_elem(r, i) = _finite(x) ? (x - floor(x)) : 0.0;
            }
            break;
        case 0x1b:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = 0.0;
            break;
        case 0x1c:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = _finite(*recon_elem(a, i)) ? 1.0 : 0.0;
            break;
        case 0x1d:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = _finite(*recon_elem(a, i)) ? 0.0 : 1.0;
            break;
        case 0x1e:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = _isnan(*recon_elem(a, i)) ? 1.0 : 0.0;
            break;
        case 0x1f:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = pow(*recon_elem(a, i), *recon_elem(b, i)) * *recon_elem(a, i);
            break;
        case 0x20:
            dVar20 = 0.0;
            for (int i = 0; i < n; i++) {
                dVar3 = *recon_elem(a, i);
                dVar20 = dVar3 * dVar3 + dVar20;
            }
            *recon_elem(r, 0) = sqrt(dVar20);
            break;
        case 0x21:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) =
                    (*recon_elem(b, i) - *recon_elem(a, i)) * *recon_elem(c, i) + *recon_elem(a, i);
            break;
        case 0x22:
            *recon_elem(r, 0) = 1.0;
            *recon_elem(r, 1) = 0.0;
            *recon_elem(r, 2) = 0.0;
            *recon_elem(r, 3) = 1.0;
            if (0.0 < recon_val(a, 0x08)) {
                *recon_elem(r, 1) = recon_val(a, 0x08);
                if (0.0 < recon_val(b, 0x08)) {
                    *recon_elem(r, 2) = pow(recon_val(b, 0x08), recon_val(a, 0x08));
                }
            }
            break;
        case 0x23:
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                if (!_isnan(x) && ((x < 0.0) != (x == 0.0))) {
                    FUN_00632325(self, param_1 + 0x30, 0xbd8, "infinite/indefinite log");
                }
                *recon_elem(r, i) = 0.6931471805599453 * log2(x);
            }
            break;
        case 0x24:
            local_34 = 0.6931471805599453 * log2(10.0);
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                if (!_isnan(x) && ((x < 0.0) != (x == 0.0))) {
                    FUN_00632325(self, param_1 + 0x30, 0xbd8, "infinite/indefinite log");
                }
                *recon_elem(r, i) = (0.6931471805599453 * log2(x)) / local_34;
            }
            break;
        case 0x25:
            local_34 = 0.6931471805599453 * log2(2.0);
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                if (!_isnan(x) && ((x < 0.0) != (x == 0.0))) {
                    FUN_00632325(self, param_1 + 0x30, 0xbd8, "infinite/indefinite log");
                }
                *recon_elem(r, i) = (0.6931471805599453 * log2(x)) / local_34;
            }
            break;
        case 0x26:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = (*recon_elem(a, i) <= *recon_elem(b, i))
                                        ? *recon_elem(b, i)
                                        : *recon_elem(a, i);
            break;
        case 0x27:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = (*recon_elem(b, i) <= *recon_elem(a, i))
                                        ? *recon_elem(b, i)
                                        : *recon_elem(a, i);
            break;
        case 0x29:
        case 0x2a:
        case 0x2b:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = *recon_elem(b, i) * recon_val(a, 0x08);
            break;
        case 0x2c:
        case 0x2f:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = *recon_elem(a, i) * recon_val(b, 0x08);
            break;
        case 0x2d:
        case 0x2e:
        case 0x30:
        case 0x31: {
            int rowsA = *(int *)(node[0] + 0x14);
            int colsA = *(int *)(node[0] + 0x18);
            int rowsB;
            int colsB;
            if (*(int *)(*(int *)(node[1] + 0x10) + 0x10) == 1) {
                rowsB = *(int *)(node[1] + 0x18);
                colsB = *(int *)(node[1] + 0x14);
            }
            else {
                rowsB = *(int *)(node[1] + 0x14);
                colsB = *(int *)(node[1] + 0x18);
            }
            if ((colsA != rowsB) || (colsB * rowsA != (int)local_8)) {
                iVar9 = -0x7fffbffb;
                goto cleanup;
            }
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsB; j++) {
                    dVar20 = 0.0;
                    for (int k = 0; k < colsA; k++) {
                        dVar20 += recon_val(a, 0x08 + 0x10 * (i * colsA + k)) *
                                  recon_val(b, 0x08 + 0x10 * (k * colsB + j));
                    }
                    *recon_elem(r, i * colsB + j) = dVar20;
                }
            }
            break;
        }
        case 0x33:
            dVar20 = 0.0;
            for (int i = 0; i < n; i++) {
                dVar3 = *recon_elem(a, i);
                dVar20 = dVar3 * dVar3 + dVar20;
            }
            dVar20 = (dVar20 == 0.0) ? 0.0 : (1.0 / sqrt(dVar20));
            for (int i = 0; i < n; i++) *recon_elem(r, i) = dVar20 * *recon_elem(a, i);
            break;
        case 0x34:
            for (int i = 0; i < n; i++) {
                double p = pow(*recon_elem(a, i), *recon_elem(b, i));
                *recon_elem(r, i) = p;
                iVar11 = _fpclass(p);
                if ((0 < iVar11) && (iVar11 < 3)) {
                    FUN_00632325(self, param_1 + 0x30, 0xbd8, "indefinite power");
                }
            }
            break;
        case 0x35:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = *recon_elem(a, i) * 0.017453293005625408;
            break;
        case 0x36:
            dVar20 = 0.0;
            for (int i = 0; i < n; i++) dVar20 += *recon_elem(b, i) * *recon_elem(a, i);
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = *recon_elem(a, i) - (dVar20 * *recon_elem(b, i) +
                                                          dVar20 * *recon_elem(b, i));
            break;
        case 0x37: {
            dVar20 = recon_val(c, 0x08);
            dVar3 = 0.0;
            for (int i = 0; i < n; i++) dVar3 += *recon_elem(b, i) * *recon_elem(a, i);
            dVar4 = 1.0 - (1.0 - dVar3 * dVar3) * dVar20 * dVar20;
            if (0.0 <= dVar4) {
                for (int i = 0; i < n; i++)
                    *recon_elem(r, i) = dVar20 * *recon_elem(a, i) -
                                        (dVar3 * dVar20 + sqrt(dVar4)) * *recon_elem(b, i);
            }
            else {
                for (int i = 0; i < n; i++) *recon_elem(r, i) = 0.0;
            }
            break;
        }
        case 0x38:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = floor(*recon_elem(a, i) + 0.5);
            break;
        case 0x39:
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                if (x < 0.0) {
                    FUN_00632325(self, param_1 + 0x30, 0xbd7, "imaginary square root");
                }
                if (x == 0.0) {
                    FUN_00632325(self, param_1 + 0x30, 0xbd9, "division by zero");
                }
                *recon_elem(r, i) = 1.0 / sqrt(x);
            }
            break;
        case 0x3a:
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                if (0.0 <= x) {
                    *recon_elem(r, i) = (x <= 1.0) ? x : 1.0;
                }
                else {
                    *recon_elem(r, i) = 0.0;
                }
            }
            break;
        case 0x3b:
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                *recon_elem(r, i) = (0.0 <= x) ? ((x <= 0.0) ? 0.0 : 1.0) : -1.0;
            }
            break;
        case 0x3c:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = sin(*recon_elem(a, i));
            break;
        case 0x3e:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = sinh(*recon_elem(a, i));
            break;
        case 0x3f:
            for (int i = 0; i < n; i++) {
                double av = *recon_elem(a, i);
                double bv = *recon_elem(b, i);
                double cv = *recon_elem(c, i);
                if (av <= cv) {
                    if (bv <= cv) {
                        *recon_elem(r, i) = 1.0;
                    }
                    else {
                        double t = (cv - av) / (bv - av);
                        double t3 = t * t * t;
                        *recon_elem(r, i) = t * t * 3.0 - (t3 + t3);
                    }
                }
                else {
                    *recon_elem(r, i) = 0.0;
                }
            }
            break;
        case 0x40:
            for (int i = 0; i < n; i++) {
                double x = *recon_elem(a, i);
                if (x < 0.0) {
                    FUN_00632325(self, param_1 + 0x30, 0xbd7, "imaginary square root");
                }
                *recon_elem(r, i) = sqrt(x);
            }
            break;
        case 0x41:
            for (int i = 0; i < n; i++)
                *recon_elem(r, i) = (*recon_elem(b, i) < *recon_elem(a, i)) ? 0.0 : 1.0;
            break;
        case 0x42:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = tan(*recon_elem(a, i));
            break;
        case 0x43:
            for (int i = 0; i < n; i++) *recon_elem(r, i) = tanh(*recon_elem(a, i));
            break;
        case 0x58: {
            int cols = *(int *)(node[0] + 0x18);
            int rows = *(int *)(node[0] + 0x14);
            for (int i = 0; i < cols; i++) {
                for (int j = 0; j < rows; j++) {
                    *(unsigned long long *)((char *)param_2 + 8 +
                                           0x10 * (*(int *)(param_1 + 0x18) * i + j)) =
                        *(unsigned long long *)((char *)a + 8 +
                                                0x10 * (cols * j + i));
                }
            }
            break;
        }
        case 0x59:
            *recon_elem(r, 0) = recon_val(a, 0x28) * 255.001953125;
            *recon_elem(r, 1) = recon_val(a, 0x18) * 255.001953125;
            *recon_elem(r, 2) = recon_val(a, 0x08) * 255.001953125;
            *recon_elem(r, 3) = recon_val(a, 0x38) * 255.001953125;
            break;
        default:
            iVar9 = -0x7fffbffb;
            goto cleanup;
        }
        pdVar10 = local_8;
    }

    {
        bool haveOutput = false;
        for (int e = head;;) {
            e = *(int *)(e + 0xc);
            if (e == 0) break;
            if (*(int *)(e + 8) != 0) {
                haveOutput = true;
                break;
            }
        }
        if (haveOutput && (pdVar10 != (double *)0x0)) {
            char *p = (char *)param_2;
            for (int i = 0; i < (int)local_8; i++, p += 0x10) {
                iVar9 = FUN_00635831((int)p, *(double *)(p + 8),
                                     (void *)(param_1 + 0x30));
                if (iVar9 < 0) goto cleanup;
            }
        }
    }
    iVar9 = 0;
cleanup:
    for (uVar7 = 0; uVar7 < 4; uVar7++) {
        operator_delete((void *)buf[uVar7]);
    }
    return iVar9;
}

extern int FUN_005f7fa4(void *name, int index, void *out);
extern "C" unsigned long strlen(const char *s);
extern const char *PTR_DAT_006e96d4[];
extern int FUN_006358a4(int param_1, int param_2, int param_3, unsigned param_4);
extern int FUN_00635696(int *dst, int *src);
extern unsigned FUN_006357d2(unsigned *out, void *src, ...);

// ---------------------------------------------------------------------------
// 0x636edb — observed shape: resolve an identifier against the enclosing
// contexts (param_5 chain), comparing declared types and running the value /
// reference compatibility helpers; on success it either returns the winning
// symbol through param_7, builds a "Values" list through param_8, or falls
// back to builtin type-name parsing (bool/int/half/float/double + swizzles).
// ---------------------------------------------------------------------------
int FUN_636edb(void *self, int param_1, int param_2, unsigned param_3, unsigned param_4,
               int param_5, unsigned param_6, int *param_7, int *param_8)
{
    unsigned uVar2;
    unsigned uVar3;
    unsigned uVar8;
    int iVar4;
    int iVar5;
    int *piVar6;
    int *piVar9;
    char *pcVar10;
    char *pcVar12;
    short *psVar11;
    char cVar1;
    bool bVar13;
    unsigned long long uVar14;
    unsigned uVar15;
    unsigned uVar16;
    unsigned uVar17;
    unsigned uVar7;
    int local_114[64];
    int local_14;
    unsigned local_10;
    unsigned local_c;
    void *local_8;

    if (param_7 != (int *)0x0) {
        *param_7 = 0;
    }
    if (param_8 != (int *)0x0) {
        *param_8 = 0;
    }
    local_10 = 0xffffffff;
    local_c = 0;
    local_8 = self;
    if (param_5 != 0) {
        do {
            if (local_10 == 0) break;
            local_14 = FUN_006325ec((int *)param_2, param_5);
            while ((local_14 != 0) && (local_10 != 0)) {
                iVar5 = *(int *)(local_14 + 8);
                if (param_1 != *(int *)(iVar5 + 0x10)) {
                    if ((param_6 & 5) != 0) {
                        FUN_00632325(local_8, param_2, 0xbbd,
                                     "'%s': identifier represents a %s, not a %s",
                                     *(void **)(param_2 + 8),
                                     PTR_DAT_006e96d4[*(int *)(iVar5 + 0x10)],
                                     PTR_DAT_006e96d4[param_1]);
                    }
                    if (param_7 != (int *)0x0) {
                        *param_7 = 0;
                    }
                    return 0x80004005;
                }
                uVar8 = 0;
                if ((param_6 & 4) != 0) {
                    uVar8 = FUN_006358a4(*(int *)(iVar5 + 0x18), param_3, param_4, param_6);
                }
                if ((param_6 & 8) != 0) {
                    iVar4 = FUN_00634161(*(int *)(iVar5 + 0x18), param_3, param_4, param_6);
                    uVar8 = uVar8 + iVar4;
                }
                uVar2 = local_10;
                if (uVar8 != 0xffffffff) {
                    if (uVar8 < local_10) {
                        local_c = 0;
                        local_10 = uVar8;
                    }
                    uVar3 = local_c;
                    if ((uVar8 <= uVar2) && (local_c < 0x40)) {
                        local_c = local_c + 1;
                        local_114[uVar3] = iVar5;
                    }
                    if (((local_10 == 0) && (*(int *)(iVar5 + 0x2c) != 0)) &&
                        (*(int *)(iVar5 + 0x28) == 0)) {
                        iVar4 = *(int *)(param_5 + 0x20);
                        if ((iVar4 != 0) && (*(int *)(iVar4 + 0x10) == 4)) {
                            for (iVar4 = FUN_006325ec((int *)param_2, iVar4); iVar4 != 0;
                                 iVar4 = *(int *)(iVar4 + 0xc)) {
                                if (*(int *)(*(int *)(iVar4 + 8) + 0x2c) == 0) {
                                    FUN_0063237b(local_8, param_2, 0xc06,
                                                 "'%s': loop control variable used outside for-loop scope conflicts with a previous declaration in the outer scope; most recent definition used",
                                                 *(void **)(param_2 + 8));
                                    *(int *)(iVar5 + 0x28) = 1;
                                    break;
                                }
                            }
                        }
                        iVar4 = local_14;
                        do {
                            iVar4 = *(int *)(iVar4 + 0xc);
                            if (iVar4 == 0) goto LAB_00637052;
                        } while (*(int *)(*(int *)(iVar4 + 8) + 0x2c) != 0);
                        FUN_0063237b(local_8, param_2, 0xc06,
                                     "'%s': loop control variable used outside for-loop scope conflicts with a previous declaration in the outer scope; most recent definition used",
                                     *(void **)(param_2 + 8));
                        *(int *)(iVar5 + 0x28) = 1;
                    }
                }
LAB_00637052:
                local_14 = *(int *)(local_14 + 0xc);
            }
            param_5 = *(int *)(param_5 + 0x20);
        } while (param_5 != 0);
        if (local_10 == 0xffffffff) goto LAB_006371f0;
        if ((param_6 & 4) != 0) {
            iVar5 = *(int *)(local_114[0] + 0x18);
            uVar8 = 1;
            if (1 < local_c) {
                do {
                    uVar14 = (unsigned long long)FUN_006329e7(
                        *(int **)(iVar5 + 0x20),
                        *(int **)(*(int *)(local_114[uVar8] + 0x18) + 0x20));
                    if (((int)uVar14 == 0) ||
                        (iVar4 = FUN_00634161(iVar5, *(int *)(iVar5 + 0x1c),
                                              *(int *)((int)(uVar14 >> 0x20) + 0x24), 0),
                         iVar4 == -1))
                        break;
                    uVar8 = uVar8 + 1;
                } while (uVar8 < local_c);
                if (uVar8 < local_c) {
                    FUN_00632325(local_8, param_2, 0xbfb, "'%s': ambiguous function call",
                                 *(void **)(param_2 + 8));
                }
            }
        }
        if (param_7 != (int *)0x0) {
            if ((param_6 & 2) != 0) {
                *param_7 = *(int *)(local_114[0] + 0x18);
                goto LAB_00637164;
            }
            if (*(int *)(local_114[0] + 0x18) == 0) goto LAB_00637164;
            iVar5 = (int)FUN_0065abf1((void *)*(int *)(local_114[0] + 0x18));
            *param_7 = iVar5;
            if (iVar5 != 0) goto LAB_00637164;
            goto LAB_0063755c;
        }
LAB_00637164:
        uVar8 = 0;
        if (param_8 != (int *)0x0) {
            param_7 = (int *)0x0;
            piVar9 = (int *)&param_7;
            if (local_c != 0) {
                do {
                    iVar5 = (int)FUN_0060d19b(0x14);
                    if (iVar5 == 0) {
                        iVar5 = 0;
                    }
                    else {
                        iVar5 = FUN_0065ac49(0, 0, "Values");
                    }
                    *piVar9 = iVar5;
                    if (iVar5 == 0) goto LAB_0063755c;
                    iVar5 = (int)FUN_0060d19b(0x40);
                    if (iVar5 == 0) {
                        iVar5 = 0;
                    }
                    else {
                        iVar5 = FUN_0065b679(2, (void *)*(int *)(local_114[uVar8] + 0x24),
                                             (void *)param_2);
                    }
                    *(int *)(*piVar9 + 8) = iVar5;
                    if (iVar5 == 0) goto LAB_0063755c;
                    piVar9 = (int *)(*piVar9 + 0xc);
                    uVar8 = uVar8 + 1;
                } while (uVar8 < local_c);
            }
            *param_8 = (int)param_7;
        }
        goto LAB_00637568;
    }
LAB_006371f0:
    piVar9 = param_7;
    if (((param_6 & 2) != 0) || (param_8 != (int *)0x0)) goto LAB_0063756c;
    if (param_1 == 0) {
        iVar5 = _stricmp(*(char **)(param_2 + 8), "dword");
        if (iVar5 == 0) {
            uVar7 = 4;
LAB_00637238:
            if (piVar9 != (int *)0x0) {
                iVar5 = (int)FUN_0060d19b(0x24);
                if (iVar5 == 0) goto LAB_00637255;
                uVar17 = 1;
                uVar16 = 1;
                uVar15 = 0;
LAB_006372c6:
                iVar5 = FUN_0065b202(uVar15, uVar7, uVar16, uVar17, 0);
LAB_00637257:
                *piVar9 = iVar5;
                goto LAB_0063725b;
            }
        }
        else {
            iVar5 = _stricmp(*(char **)(param_2 + 8), "float");
            if (iVar5 == 0) {
                uVar7 = 0xb;
                goto LAB_00637238;
            }
            iVar5 = _stricmp(*(char **)(param_2 + 8), "vector");
            if (iVar5 == 0) {
                if (piVar9 == (int *)0x0) goto LAB_00637568;
                iVar5 = (int)FUN_0060d19b(0x24);
                if (iVar5 != 0) {
                    uVar17 = 4;
                    uVar16 = 1;
                    uVar7 = 0xb;
                    uVar15 = 1;
                    goto LAB_006372c6;
                }
LAB_00637255:
                iVar5 = 0;
                goto LAB_00637257;
            }
            iVar5 = _stricmp(*(char **)(param_2 + 8), "matrix");
            if (iVar5 == 0) {
                if (piVar9 == (int *)0x0) goto LAB_00637568;
                iVar5 = (int)FUN_0060d19b(0x24);
                if (iVar5 == 0) goto LAB_00637255;
                uVar17 = 4;
                uVar16 = 4;
                uVar7 = 0xb;
                uVar15 = 2;
                goto LAB_006372c6;
            }
            iVar5 = _stricmp(*(char **)(param_2 + 8), "string");
            if (iVar5 != 0) {
                iVar5 = _stricmp(*(char **)(param_2 + 8), "texture");
                if (iVar5 == 0) {
                    uVar7 = 0xf;
                    goto LAB_00637329;
                }
                iVar5 = _stricmp(*(char **)(param_2 + 8), "pixelshader");
                if (iVar5 == 0) {
                    uVar7 = 0x19;
                    goto LAB_00637329;
                }
                iVar5 = _stricmp(*(char **)(param_2 + 8), "vertexshader");
                if (iVar5 == 0) {
                    uVar7 = 0x1a;
                    goto LAB_00637329;
                }
                pcVar10 = *(char **)(param_2 + 8);
                pcVar12 = pcVar10;
                do {
                    iVar5 = *pcVar12;
                    pcVar12 = pcVar12 + 1;
                } while ((char)iVar5 != '\0');
                uVar8 = (unsigned)((int)pcVar12 - ((int)pcVar10 + 1));
                iVar5 = 3;
                if ((uVar8 >= 4) && (recon_eq_n(pcVar10, "bool", 4))) {
                    uVar7 = 0;
                    pcVar10 = pcVar10 + 4;
                    iVar5 = (int)uVar8 - 4;
                }
                else if ((uVar8 >= 3) && (recon_eq_n(pcVar10, "int", 3))) {
                    pcVar10 = pcVar10 + 3;
                    uVar7 = 4;
                    iVar5 = (int)uVar8 - 3;
                }
                else if ((uVar8 >= 4) && (recon_eq_n(pcVar10, "half", 4))) {
                    pcVar10 = pcVar10 + 4;
                    uVar7 = 10;
                    iVar5 = (int)uVar8 - 4;
                }
                else if ((uVar8 >= 5) && (recon_eq_n(pcVar10, "float", 5))) {
                    pcVar10 = pcVar10 + 5;
                    uVar7 = 0xb;
                    iVar5 = (int)uVar8 - 5;
                }
                else {
                    if ((uVar8 < 6) || (!recon_eq_n(pcVar10, "double", 6))) goto LAB_0063756c;
                    pcVar10 = pcVar10 + 6;
                    uVar7 = 0xc;
                    iVar5 = (int)uVar8 - 6;
                }
                (void)psVar11;
                (void)bVar13;
                if (iVar5 == 1) {
                    if (((char)*pcVar10 < '1') || ('4' < (char)*pcVar10)) {
LAB_0063756c:
                        if ((param_6 & 1) != 0) {
                            FUN_00632325(local_8, param_2, 0xbbc,
                                         "undeclared identifier '%s'",
                                         *(void **)(param_2 + 8));
                        }
                        return 1;
                    }
                    if (param_7 == (int *)0x0) goto LAB_00637568;
                    iVar5 = (int)FUN_0060d19b(0x24);
                    if (iVar5 == 0) {
LAB_006374a9:
                        iVar5 = 0;
                        goto LAB_006374ab;
                    }
                    cVar1 = (char)*pcVar10;
                    iVar4 = 1;
                    uVar15 = 1;
                    iVar5 = FUN_0065b202(uVar15, uVar7, iVar4, cVar1 + -0x30, 0);
LAB_006374ab:
                    *param_7 = iVar5;
                    goto LAB_0063725b;
                }
                if (((((iVar5 != 3) || ((char)*pcVar10 < '1')) || ('4' < (char)*pcVar10)) ||
                     ((pcVar10[1] != 'x' || (pcVar10[2] < '1')))) ||
                    ('4' < pcVar10[2]))
                    goto LAB_0063756c;
                if (param_7 != (int *)0x0) {
                    iVar5 = (int)FUN_0060d19b(0x24);
                    if (iVar5 != 0) {
                        cVar1 = pcVar10[2];
                        iVar4 = (char)*pcVar10 + -0x30;
                        uVar15 = 2;
                        iVar5 = FUN_0065b202(uVar15, uVar7, iVar4, cVar1 + -0x30, 0);
                    }
                    goto LAB_006374ab;
                }
                goto LAB_00637568;
            }
            uVar7 = 0xe;
LAB_00637329:
            piVar9 = param_7;
            if (param_7 == (int *)0x0) goto LAB_00637568;
            iVar5 = (int)FUN_0060d19b(0x24);
            if (iVar5 == 0) {
                iVar5 = 0;
            }
            else {
                iVar5 = FUN_0065b202(3, (int)uVar7, 1, 1, 0);
            }
            *piVar9 = iVar5;
LAB_0063725b:
            if (iVar5 == 0) goto LAB_0063755c;
        }
LAB_00637568:
        uVar7 = 0;
    }
    else {
        if (param_1 != 1) goto LAB_0063756c;
        if (!recon_eq_n(*(char **)(param_2 + 8), "NULL", 5)) goto LAB_0063756c;
        if (param_7 == (int *)0x0) goto LAB_00637568;
        iVar5 = (int)FUN_0060d19b(0x40);
        if (iVar5 == 0) {
            iVar5 = 0;
        }
        else {
            iVar5 = FUN_0065b377();
        }
        if (iVar5 != 0) {
            *(unsigned *)(iVar5 + 0x14) = 1;
            *(unsigned *)(iVar5 + 0x18) = 0;
            *(unsigned *)(iVar5 + 0x1c) = 0x202;
            iVar4 = (int)FUN_0060d19b(0x24);
            if (iVar4 == 0) {
                iVar4 = 0;
            }
            else {
                iVar4 = FUN_0065b202(3, 0xd, 1, 1, 0x200);
            }
            *(int *)(iVar5 + 0x20) = iVar4;
            if (iVar4 != 0) {
                iVar4 = (int)FUN_0060d19b(0x40);
                if (iVar4 == 0) {
                    iVar4 = 0;
                }
                else {
                    iVar4 = FUN_0065b6e3(5, (void *)0, (void *)0, (void *)param_2);
                }
                *(int *)(iVar5 + 0x24) = iVar4;
                if (iVar4 != 0) {
                    *param_7 = iVar5;
                    goto LAB_00637568;
                }
            }
        }
LAB_0063755c:
        uVar7 = 0x8007000e;
    }
    return (int)uVar7;
}

// ---------------------------------------------------------------------------
// 0x637598 — observed shape: build a container from a kind-3 node; when no
// source object is supplied it first resolves one through 0x636edb, then
// attaches either a 6-element value object or a virtual-cloned one.
// ---------------------------------------------------------------------------
int FUN_637598(void *self, int param_1, int param_2)
{
    int iVar1;
    int iVar2;
    int iVar3;
    void *uVar4;
    int local_8;

    local_8 = 0;
    if ((param_1 == 0) || (*(int *)(param_1 + 4) != 3)) {
        return 0;
    }
    param_1 = param_1 + 0x10;
    iVar1 = param_2;
    if (param_2 == 0) {
        iVar1 = 0;
        iVar2 = FUN_636edb(self, 1, param_1, 0, 0, *(int *)((char *)self + 0x10), 1,
                           &local_8, 0);
        if (iVar2 != 0) {
            return 0;
        }
        iVar1 = local_8;
    }
    iVar2 = (int)FUN_0060d19b(0x50);
    if (iVar2 == 0) {
        iVar2 = 0;
    }
    else {
        iVar2 = FUN_0065b52c(0, 0, 0, 0, 1, (void *)param_1);
    }
    if (iVar2 != 0) {
        if (*(int *)(iVar1 + 0x24) == 0) {
            iVar3 = (int)FUN_0060d19b(0x40);
            if (iVar3 == 0) {
                iVar3 = 0;
            }
            else {
                iVar3 = FUN_0065b6e3(6, (void *)*(int *)(iVar1 + 0x10),
                                     (void *)*(int *)(iVar1 + 0x14), (void *)param_1);
            }
        }
        else {
            iVar3 = (**(int (***)(void))(**(int **)(iVar1 + 0x24) + 4))();
        }
        *(int *)(iVar2 + 0x20) = iVar3;
        if (iVar3 != 0) {
            uVar4 = FUN_0065abf1((void *)*(int *)(iVar1 + 0x20));
            *(void **)(iVar2 + 0x10) = uVar4;
            if (param_2 != 0) {
                FUN_00632729(uVar4, 0);
            }
            iVar1 = (int)FUN_0060d19b(0x14);
            if (iVar1 == 0) {
                iVar1 = 0;
            }
            else {
                iVar1 = FUN_0065ac49(*(void **)(iVar2 + 0x20), 0, "Value");
            }
            if (iVar1 != 0) {
                *(int *)(iVar2 + 0x20) = iVar1;
                FUN_0063336c(iVar2);
                return iVar2;
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x63769f — observed shape: build a container from two source nodes, first
// lowering a kind-3 param_1 through 0x636edb when needed, then wrapping both
// operands and appending "Types"/"Value" children in param_3 order.
// ---------------------------------------------------------------------------
int FUN_63769f(void *self, int *param_1, int *param_2, int param_3, unsigned param_4)
{
    int *piVar1;
    int iVar2;
    unsigned uVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int *piVar7;
    int *local_c[2];

    piVar1 = param_2;
    local_c[0] = (int *)0x0;
    piVar7 = param_1;
    if ((param_1 != (int *)0x0) && (param_1[1] == 3)) {
        FUN_636edb(self, 0, (int)(param_1 + 4), 0, 0, *(int *)((char *)self + 0x10), 1,
                   (int *)local_c, 0);
        piVar7 = local_c[0];
    }
    param_1 = (int *)((char *)self + 0x20);
    if (param_3 == 0) {
        local_c[0] = (int *)0x0;
        if (param_2 != (int *)0x0) {
            if (param_2[1] != 0xd) {
                return 0;
            }
            local_c[0] = (int *)param_2[4];
            param_1 = param_2 + 0xc;
        }
        iVar2 = FUN_00634446((int)piVar7, (int)local_c[0], (int)param_4);
        if (iVar2 == 0) {
            FUN_0063477e(param_1, 0, piVar7, local_c[0], (int)param_4);
            return 0;
        }
        iVar2 = FUN_0063284b(piVar7);
        if ((iVar2 == 0) && (iVar2 = FUN_0063284b(local_c[0]), iVar2 == 0)) {
            param_2 = (int *)0x0;
        }
        else {
            param_2 = (int *)0x1;
        }
    }
    else {
        if (((piVar7 == (int *)0x0) || (piVar7[1] != 9)) ||
            (iVar2 = FUN_006328e2((int)piVar7), iVar2 == 0))
            goto LAB_006378aa;
        if ((param_2 != (int *)0x0) && (param_2[1] != 1)) {
            return 0;
        }
        param_2 = (int *)FUN_0063284b(piVar7);
    }
    uVar3 = FUN_006331d2(piVar1);
    param_2 = (int *)((uintptr_t)param_2 | uVar3);
    iVar2 = (int)FUN_0060d19b(0x50);
    iVar6 = 0;
    if (iVar2 != 0) {
        iVar6 = FUN_0065b52c(0, 0, 0, 0, 1, param_1);
    }
    if (iVar6 == 0) {
        return 0;
    }
    if (piVar7 != (int *)0x0) {
        iVar2 = (**(int (***)(void))(*piVar7 + 4))();
        *(int *)(iVar6 + 0x10) = iVar2;
        if (iVar2 == 0) {
            return 0;
        }
    }
    if (piVar1 != (int *)0x0) {
        iVar2 = (**(int (***)(void))(*piVar1 + 4))();
        *(int *)(iVar6 + 0x20) = iVar2;
        if (iVar2 == 0) {
            return 0;
        }
    }
    if (param_3 != 0) {
        for (iVar2 = *(int *)(iVar6 + 0x20); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
            iVar5 = *(int *)(iVar2 + 8);
            if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0xd)) {
                iVar5 = FUN_006328e2(*(int *)(iVar5 + 0x10));
                if (iVar5 == 0) goto LAB_006378aa;
                if (param_2 == (int *)0x0) {
                    param_2 = (int *)FUN_0063284b(*(int *)(*(int *)(iVar2 + 8) + 0x10));
                }
            }
        }
    }
    if (param_2 != (int *)0x0) {
        FUN_00632729(*(void **)(iVar6 + 0x10), 1);
    }
    if (param_3 != 0) {
        iVar5 = 0;
        for (iVar2 = *(int *)(iVar6 + 0x20); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
            iVar4 = *(int *)(iVar2 + 8);
            if ((iVar4 != 0) && (*(int *)(iVar4 + 4) == 0xd)) {
                iVar4 = FUN_00632959(*(void **)(iVar4 + 0x10));
                iVar5 = iVar5 + iVar4;
            }
        }
        iVar2 = FUN_00632959(*(void **)(iVar6 + 0x10));
        if (iVar5 != iVar2) {
LAB_006378aa:
            FUN_00632325();
            return 0;
        }
    }
    FUN_0063336c(iVar6);
    return iVar6;
}

// ---------------------------------------------------------------------------
// 0x6378c8 — observed shape: build a container from up to three kind-0xd
// nodes, allocating a 0x18 descriptor when param_1 is present and wrapping
// both "Types" and "Value" chains through 0x63769f.
// ---------------------------------------------------------------------------
int FUN_6378c8(void *self, int param_1, int param_2, int param_3)
{
    int iVar1;
    void *uVar2;
    int iVar3;
    int *piVar4;
    void *uVar5;
    void *uVar6;
    int *local_24;
    int *local_20;
    int local_1c;
    int *local_18;
    int *local_14;
    int local_10;
    int local_c;

    if ((((param_1 != 0) && (*(int *)(param_1 + 4) != 0xd)) ||
         ((param_2 != 0 && (*(int *)(param_2 + 4) != 0xd)))) ||
        ((param_3 != 0 && (*(int *)(param_3 + 4) != 0xd)))) {
        return 0;
    }
    local_10 = param_1 + 0x30;
    if (param_1 == 0) {
        local_10 = (int)self + 0x20;
        local_1c = 0;
    }
    else {
        local_1c = *(int *)(param_1 + 0x10);
    }
    if (param_2 == 0) {
        local_14 = (int *)0x0;
    }
    else {
        local_14 = *(int **)(param_2 + 0x10);
    }
    if (param_3 == 0) {
        local_18 = (int *)0x0;
    }
    else {
        local_18 = *(int **)(param_3 + 0x10);
    }
    local_20 = local_14;
    local_24 = local_18;
    iVar3 = 0;
    iVar1 = (int)FUN_0060d19b(0x50);
    if (iVar1 == 0) {
        local_c = 0;
    }
    else {
        local_c = FUN_0065b52c(0, 0x18, 0, 0, 1, (void *)local_10);
    }
    if (local_c == 0) {
        return 0;
    }
    iVar1 = FUN_006328e2(local_1c);
    if (iVar1 == 0) goto LAB_00637995;
    piVar4 = (int *)(local_c + 0x10);
    iVar1 = FUN_00634aaf(local_14, local_18, &local_20, &local_24, piVar4);
    if (iVar1 < 0) goto LAB_00637995;
    if (*piVar4 == 0) goto LAB_00637a50;
    if (*(int *)(*piVar4 + 4) == 9) {
        iVar1 = (int)FUN_0060d19b(0x24);
        if (iVar1 == 0) goto LAB_00637a20;
        uVar6 = (void *)0x200;
        uVar2 = *(void **)(*piVar4 + 0x1c);
        uVar5 = *(void **)(*piVar4 + 0x18);
LAB_00637a14:
        iVar3 = FUN_0065b202(2, 0, (int)uVar5, (int)uVar2, (int)uVar6);
    }
    else {
        iVar1 = (int)FUN_0060d19b(0x24);
        if (iVar1 != 0) {
            uVar6 = (void *)0x200;
            uVar2 = (void *)FUN_00632959(*piVar4);
            uVar5 = (void *)0x1;
            goto LAB_00637a14;
        }
LAB_00637a20:
        iVar3 = 0;
    }
    if (iVar3 == 0) {
        return 0;
    }
    iVar1 = FUN_00634446(iVar3, local_1c, 0);
    if (iVar1 != 0) {
LAB_00637a50:
        if (param_1 != 0) {
            iVar1 = FUN_63769f(self, iVar3, param_1, 0, 0);
            *(int *)(local_c + 0x20) = iVar1;
            if (iVar1 == 0) {
                return 0;
            }
        }
        iVar1 = (int)FUN_0060d19b(0x50);
        if (iVar1 == 0) {
            iVar1 = 0;
        }
        else {
            iVar1 = FUN_0065b52c(0, 0, 0, 0, 1, (void *)local_10);
        }
        *(int *)(local_c + 0x24) = iVar1;
        if (iVar1 == 0) {
            return 0;
        }
        iVar3 = (int)FUN_0060d19b(0x14);
        if (iVar3 == 0) {
            iVar3 = 0;
        }
        else {
            iVar3 = FUN_0065ac49(0, 0, "Types");
        }
        piVar4 = local_20;
        *(int *)(iVar1 + 0x10) = iVar3;
        if (iVar3 == 0) {
            return 0;
        }
        if (local_20 != (int *)0x0) {
            uVar2 = (void *)(**(int (***)(void))(*local_20 + 4))();
            *(void **)(*(int *)(iVar1 + 0x10) + 8) = uVar2;
            if (*(int *)(*(int *)(iVar1 + 0x10) + 8) == 0) {
                return 0;
            }
        }
        iVar3 = (int)FUN_0060d19b(0x14);
        if (iVar3 == 0) {
            iVar3 = 0;
        }
        else {
            iVar3 = FUN_0065ac49(0, 0, "Value");
        }
        *(int *)(iVar1 + 0x20) = iVar3;
        if (iVar3 == 0) {
            return 0;
        }
        if (param_2 != 0) {
            if ((local_14 == piVar4) || (iVar3 = FUN_006329e7(local_14, piVar4), iVar3 != 0)) {
                uVar2 = FUN_0065abf1((void *)param_2);
            }
            else {
                uVar2 = (void *)FUN_63769f(self, piVar4, (int *)param_2, 0, 0);
            }
            *(void **)(*(int *)(iVar1 + 0x20) + 8) = uVar2;
            if (*(int *)(*(int *)(iVar1 + 0x20) + 8) == 0) {
                return 0;
            }
        }
        iVar3 = (int)FUN_0060d19b(0x14);
        if (iVar3 == 0) {
            iVar3 = 0;
        }
        else {
            iVar3 = FUN_0065ac49(0, 0, "Types");
        }
        piVar4 = local_24;
        *(int *)(*(int *)(iVar1 + 0x10) + 0xc) = iVar3;
        if (iVar3 == 0) {
            return 0;
        }
        if (local_24 != (int *)0x0) {
            uVar2 = (void *)(**(int (***)(void))(*local_24 + 4))();
            *(void **)(*(int *)(*(int *)(iVar1 + 0x10) + 0xc) + 8) = uVar2;
            if (*(int *)(*(int *)(*(int *)(iVar1 + 0x10) + 0xc) + 8) == 0) {
                return 0;
            }
        }
        iVar3 = (int)FUN_0060d19b(0x14);
        if (iVar3 == 0) {
            iVar3 = 0;
        }
        else {
            iVar3 = FUN_0065ac49(0, 0, "Value");
        }
        *(int *)(*(int *)(iVar1 + 0x20) + 0xc) = iVar3;
        if (iVar3 == 0) {
            return 0;
        }
        if (param_3 != 0) {
            if ((local_18 == piVar4) || (iVar3 = FUN_006329e7(local_18, piVar4), iVar3 != 0)) {
                uVar2 = FUN_0065abf1((void *)param_3);
            }
            else {
                uVar2 = (void *)FUN_63769f(self, piVar4, (int *)param_3, 0, 0);
            }
            *(void **)(*(int *)(*(int *)(iVar1 + 0x20) + 0xc) + 8) = uVar2;
            if (*(int *)(*(int *)(*(int *)(iVar1 + 0x20) + 0xc) + 8) == 0) {
                return 0;
            }
        }
        FUN_0063336c(iVar1);
        FUN_0063336c(local_c);
        return local_c;
    }
LAB_00637995:
    FUN_00632325();
    return 0;
}

// ---------------------------------------------------------------------------
// 0x637c38 — observed shape: evaluate a vector expression node into a
// caller-supplied 16-byte-element buffer. Operands come from the node's
// +0x20 and +0x24 children; the opcode at +0x1c selects elementwise,
// matrix, reduction and comparison kernels. Opcode 0x1a is delegated to
// 0x635aeb. The two temporaries are freed before every return.
// ---------------------------------------------------------------------------
int FUN_637c38(void *self, unsigned *param_1, int param_2)
{
    unsigned *puVar1;
    unsigned uVar2;
    int iVar3;
    unsigned *puVar4;
    unsigned uVar5;
    unsigned *puVar6;
    unsigned uVar7;
    unsigned uVar8;
    double *pdVar9;
    int iVar10;
    unsigned local_2c;
    unsigned local_28;
    unsigned local_24;
    void *local_20;
    double local_18;
    unsigned *local_10;
    unsigned *local_c;

    iVar10 = (int)param_1;
    if ((param_1 == (unsigned *)0x0) || (*(int *)((int)param_1 + 4) != 0xd)) {
        return -0x7fffbffb;
    }
    uVar8 = *(int *)((int)param_1 + 0x18) * *(int *)((int)param_1 + 0x14);
    uVar2 = FUN_0063302f(*(int *)((int)param_1 + 0x10), param_2);
    if (uVar8 != uVar2) {
        return -0x7fffbffb;
    }
    iVar3 = *(int *)((int)param_1 + 0x1c);
    if (1 < iVar3) {
        if (iVar3 < 4) {
            return -0x7fffbffb;
        }
        if (0x13 < iVar3) {
            if (iVar3 < 0x16) {
                return -0x7fffbffb;
            }
            if (iVar3 == 0x19) {
                return -0x7fffbffb;
            }
            if (iVar3 == 0x1a) {
                return FUN_635aeb(self, (int)param_1, (double *)param_2);
            }
            if (iVar3 == 0x1b) {
                return -0x7fffbffb;
            }
        }
    }
    uVar2 = *(unsigned *)((int)param_1 + 0x20);
    local_2c = 0;
    local_20 = (void *)0x0;
    local_c = (unsigned *)0x0;
    local_10 = (unsigned *)0x0;
    local_18 = 0.0;
    local_24 = 0;
    uVar7 = 0;
    if ((uVar2 != 0) && (*(int *)(uVar2 + 4) == 0xd)) {
        iVar3 = *(int *)(uVar2 + 0x18) * *(int *)(uVar2 + 0x14);
        local_18 = (double)iVar3;
        local_2c = uVar2;
        local_c = (unsigned *)FUN_00533c78(iVar3 * 0x10);
        uVar7 = uVar2;
        if (local_c != (unsigned *)0x0) goto LAB_00637cf5;
LAB_00637d22:
        iVar3 = -0x7ff8fff2;
        goto done;
    }
LAB_00637cf5:
    uVar5 = *(unsigned *)((int)param_1 + 0x24);
    uVar2 = 0;
    if ((uVar5 != 0) && (*(int *)(uVar5 + 4) == 0xd)) {
        local_24 = *(int *)(uVar5 + 0x18) * *(int *)(uVar5 + 0x14);
        local_20 = (void *)uVar5;
        local_10 = (unsigned *)FUN_00533c78(local_24 * 0x10);
        uVar2 = uVar5;
        if (local_10 == (unsigned *)0x0) goto LAB_00637d22;
    }
    if (*(int *)((int)param_1 + 0x28) == 0) {
        uVar5 = uVar7;
        if ((uVar2 != 0) && (iVar3 = FUN_637c38(self, (unsigned *)uVar2, param_2), iVar3 < 0))
            goto done;
    }
    else {
        uVar5 = uVar2;
        if (uVar7 != 0) {
            iVar3 = FUN_637c38(self, (unsigned *)uVar7, param_2);
            if (iVar3 < 0) goto done;
            uVar5 = (unsigned)(size_t)local_20;
        }
    }
    if ((uVar5 != 0) && (iVar3 = FUN_637c38(self, (unsigned *)uVar5, param_2), iVar3 < 0))
        goto done;

    puVar6 = local_c;
    iVar3 = *(int *)((int)param_1 + 0x1c);
    if (iVar3 < 0) {
LAB_006381aa:
        local_28 = 0;
        if ((int)local_18 != 0) {
            do {
                iVar3 = FUN_00633174((double *)(puVar6 + 2), puVar6,
                                     (int *)((int)param_1 + 0x30));
                if (iVar3 < 0) goto done;
                local_28++;
                *puVar6 = 3;
                puVar6 = puVar6 + 4;
            } while ((int)local_28 < (int)local_18);
        }
        local_28 = 0;
        if (local_24 != 0) {
            puVar6 = local_10;
            do {
                iVar3 = FUN_00633174((double *)(puVar6 + 2), puVar6,
                                     (int *)((int)param_1 + 0x30));
                if (iVar3 < 0) goto done;
                local_28++;
                *puVar6 = 3;
                puVar6 = puVar6 + 4;
            } while (local_28 < local_24);
            uVar7 = local_2c;
        }
        if (((uVar7 != 0) && ((unsigned)local_18 != uVar8)) ||
            ((local_20 != (void *)0 && (local_24 != uVar8))))
            goto switchD_default;
        local_24 = 0;
        if (uVar8 != 0) {
            local_2c = (unsigned)((char *)local_c - (char *)local_10);
            local_28 = (unsigned)(param_2 - (int)local_10);
            pdVar9 = (double *)(local_10 + 2);
            do {
                double fVar13;
                double fVar14;
                if (local_c == (unsigned *)0x0) {
                    fVar13 = 0.0;
                }
                else {
                    fVar13 = *(double *)((char *)pdVar9 + local_2c);
                }
                local_18 = fVar13;
                if (local_10 == (unsigned *)0x0) {
                    local_20 = (void *)0x0;
                }
                else {
                    local_20 = (void *)*(unsigned long long *)pdVar9;
                }
                {
                    double lval = *(double *)&local_20;
                    bool bTake;
                    switch (*(unsigned *)((int)param_1 + 0x1c)) {
                    case 4:
                        fVar14 = 0.0;
                        bTake = (fVar13 != fVar14);
                        fVar13 = bTake ? 0.0 : 1.0;
                        break;
                    case 5:
                        fVar13 = -fVar13;
                        break;
                    case 6:
                        break;
                    case 7:
                        fVar13 = fVar13 * lval;
                        break;
                    case 8:
                        if (lval == 0.0) {
                            FUN_00632325(self, (int)param_1 + 0x30, 0xbd9,
                                         "division by zero");
                            fVar13 = local_18;
                        }
                        fVar13 = fVar13 / lval;
                        break;
                    case 9:
                        if (lval == 0.0) {
                            FUN_00632325(self, (int)param_1 + 0x30, 0xbd9,
                                         "division by zero");
                        }
                        fVar13 = fmod(fVar13, lval);
                        break;
                    case 10:
                        fVar13 = fVar13 + lval;
                        break;
                    case 0xb:
                        fVar13 = fVar13 - lval;
                        break;
                    case 0xc:
                        bTake = (lval <= fVar13);
                        fVar13 = bTake ? 0.0 : 1.0;
                        break;
                    case 0xd:
                        bTake = (lval < fVar13);
                        fVar13 = bTake ? 1.0 : 0.0;
                        break;
                    case 0xe:
                        bTake = (_isnan(fVar13) || _isnan(lval)) ||
                                ((fVar13 < lval) == (fVar13 == lval));
                        fVar13 = bTake ? 0.0 : 1.0;
                        break;
                    case 0xf:
                        bTake = (lval <= fVar13);
                        fVar13 = bTake ? 1.0 : 0.0;
                        break;
                    case 0x10:
                        bTake = (fVar13 != lval);
                        fVar13 = bTake ? 0.0 : 1.0;
                        break;
                    case 0x11: {
                        bool nan = _isnan(fVar13) || _isnan(lval);
                        bool eq = (fVar13 == lval);
                        fVar13 = ((nan != eq) != 0) ? 0.0 : 1.0;
                        break;
                    }
                    case 0x12: {
                        if (fVar13 != 0.0) {
                            bool nan = _isnan(lval);
                            bool z = (lval == 0.0);
                            fVar13 = ((nan != z) != 0) ? 0.0 : 1.0;
                        }
                        else {
                            fVar13 = 0.0;
                        }
                        break;
                    }
                    case 0x13: {
                        bool nan;
                        bool z;
                        if (fVar13 == 0.0) {
                            nan = _isnan(lval);
                            z = (lval == 0.0);
                            fVar13 = ((nan != z) != 0) ? 0.0 : 1.0;
                        }
                        else {
                            fVar13 = 1.0;
                        }
                        break;
                    }
                    default:
                        goto switchD_default;
                    }
                }
                local_24 = local_24 + 1;
                *(double *)((char *)pdVar9 + local_28) = fVar13;
                pdVar9 = pdVar9 + 2;
            } while (local_24 < uVar8);
        }
        local_2c = 0;
        if (uVar8 != 0) {
            do {
                iVar3 = FUN_00635831(param_2, *(double *)(param_2 + 8),
                                     (void *)((int)param_1 + 0x30));
                if (iVar3 < 0) goto done;
                local_2c = local_2c + 1;
                param_2 = param_2 + 0x10;
            } while (local_2c < uVar8);
        }
    }
    else if (iVar3 < 2) {
        if (uVar7 == 0) {
            iVar10 = *(int *)((int)param_1 + 0x20);
            if (iVar10 == 0) {
switchD_default:
                iVar3 = -0x7fffbffb;
                goto done;
            }
            if (*(int *)(iVar10 + 4) == 0xe) {
                if (*(int *)(iVar10 + 0x10) == 6) goto switchD_default;
                iVar3 = FUN_00635696((int *)param_2, (int *)(iVar10 + 0x10));
                if (iVar3 < 0) goto done;
            }
            else {
                if ((iVar10 == 0) || (*(int *)(iVar10 + 4) != 1)) goto switchD_default;
                do {
                    iVar3 = *(int *)(iVar10 + 8);
                    if (iVar3 != 0) {
                        if (*(int *)(iVar3 + 4) == 0xe) {
                            if (*(int *)(iVar3 + 0x10) == 6) goto switchD_default;
                            iVar3 = FUN_00635696((int *)param_2, (int *)(iVar3 + 0x10));
                            if (iVar3 < 0) goto done;
                            param_2 = param_2 + 0x10;
                        }
                        else if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 0xd)) {
                            iVar3 = FUN_637c38(self, (unsigned *)iVar3, param_2);
                            if (iVar3 < 0) goto done;
                            param_2 = param_2 + *(int *)(*(int *)(iVar10 + 8) + 0x18) *
                                                  *(int *)(*(int *)(iVar10 + 8) + 0x14) * 0x10;
                        }
                    }
                    iVar10 = *(int *)(iVar10 + 0xc);
                } while (iVar10 != 0);
            }
        }
        else if ((unsigned)local_18 == 1) {
            local_24 = 0;
            if (uVar8 != 0) {
                do {
                    iVar3 = FUN_00635696((int *)param_2, (int *)local_c);
                    if (iVar3 < 0) goto done;
                    local_24 = local_24 + 1;
                    param_2 = param_2 + 0x10;
                } while (local_24 < uVar8);
            }
        }
        else if (((uVar8 == (unsigned)local_18) ||
                  (puVar1 = (unsigned *)((int)param_1 + 0x14),
                   *(unsigned *)(uVar7 + 0x14) < *puVar1)) ||
                 (uVar5 = *(unsigned *)((int)param_1 + 0x18),
                  *(unsigned *)(uVar7 + 0x18) < uVar5)) {
            local_24 = 0;
            if (uVar8 != 0) {
                iVar10 = param_2;
                do {
                    iVar3 = FUN_00635696((int *)iVar10,
                                         (int *)((char *)puVar6 + (iVar10 - param_2)));
                    if (iVar3 < 0) goto done;
                    local_24 = local_24 + 1;
                    iVar10 = iVar10 + 0x10;
                } while (local_24 < uVar8);
            }
        }
        else {
            param_1 = (unsigned *)0x0;
            if (*puVar1 != 0) {
                do {
                    uVar2 = 0;
                    if (uVar5 != 0) {
                        do {
                            iVar3 = FUN_00635696(
                                (int *)((uVar5 * (int)param_1 + uVar2) * 0x10 + param_2),
                                (int *)(local_c +
                                        (*(int *)(local_2c + 0x18) * (int)param_1 + uVar2) * 4));
                            if (iVar3 < 0) goto done;
                            uVar5 = *(unsigned *)(iVar10 + 0x18);
                            uVar2 = uVar2 + 1;
                        } while (uVar2 < uVar5);
                    }
                    param_1 = (unsigned *)((int)param_1 + 1);
                } while (param_1 < *(unsigned *)(iVar10 + 0x14));
            }
        }
    }
    else if (iVar3 == 0x16) {
        iVar10 = (int)param_1 + 0x30;
        iVar3 = (int)FUN_006357d2(&local_2c, local_10, (void *)iVar10);
        if (iVar3 < 0) goto done;
        if ((unsigned)local_18 <= local_2c * uVar8) {
            FUN_00632325(self, iVar10, 0xbd6, "array index out of bounds");
            goto switchD_default;
        }
        local_24 = 0;
        if (uVar8 != 0) {
            puVar6 = local_c + local_2c * uVar8 * 4;
            do {
                iVar3 = FUN_00635696((int *)param_2, (int *)puVar6);
                if (iVar3 < 0) goto done;
                local_24 = local_24 + 1;
                puVar6 = puVar6 + 4;
                param_2 = param_2 + 0x10;
            } while (local_24 < uVar8);
        }
    }
    else if (iVar3 == 0x17) {
        iVar10 = *(int *)((int)param_1 + 0x24);
        if (*(int *)(iVar10 + 4) == 0xe) {
            iVar3 = (int)FUN_006357d2(&local_2c, (void *)(iVar10 + 0x10),
                                      (void *)((int)param_1 + 0x30));
            if (iVar3 < 0) goto done;
            local_24 = 0;
            if (uVar8 != 0) {
                puVar6 = local_c + local_2c * 4;
                do {
                    iVar3 = FUN_00635696((int *)param_2, (int *)puVar6);
                    if (iVar3 < 0) goto done;
                    local_24 = local_24 + 1;
                    param_2 = param_2 + 0x10;
                    puVar6 = puVar6 + 4;
                } while (local_24 < uVar8);
            }
        }
        else {
            if (*(int *)(iVar10 + 4) != 1) goto switchD_default;
            local_24 = 0;
            if (uVar8 != 0) {
                do {
                    iVar3 = (int)FUN_006357d2(&local_2c, (void *)(*(int *)(iVar10 + 8) + 0x10),
                                              (void *)((int)param_1 + 0x30));
                    if ((iVar3 < 0) ||
                        (iVar3 = FUN_00635696((int *)param_2, (int *)(local_c + local_2c * 4)),
                         iVar3 < 0))
                        goto done;
                    local_24 = local_24 + 1;
                    param_2 = param_2 + 0x10;
                    iVar10 = *(int *)(iVar10 + 0xc);
                } while (local_24 < uVar8);
            }
        }
    }
    else {
        if (iVar3 != 0x18) goto LAB_006381aa;
        local_24 = 0;
        if ((unsigned)local_18 != 0) {
            iVar10 = (int)param_1 + 0x30;
            param_1 = local_10 + uVar8 * 4;
            local_2c = (unsigned)((char *)local_c - (char *)local_10);
            local_28 = (unsigned)(param_2 - (int)local_10);
            puVar6 = local_10;
            do {
                iVar3 = FUN_00633174((double *)&local_20, (void *)(local_2c + (int)puVar6),
                                     (int *)iVar10);
                if (iVar3 < 0) goto done;
                puVar4 = puVar6;
                if (*(double *)&local_20 == 0.0) {
                    puVar4 = param_1;
                }
                iVar3 = FUN_00635696((int *)(local_28 + (int)puVar6), (int *)puVar4);
                if (iVar3 < 0) goto done;
                local_24 = local_24 + 1;
                param_1 = param_1 + 4;
                puVar6 = puVar6 + 4;
            } while (local_24 < (unsigned)local_18);
        }
    }
    iVar3 = 0;
done:
    operator_delete(local_10);
    operator_delete(local_c);
    return iVar3;
}

extern char DAT_006e9a14[];
extern char DAT_006e99f8[];
extern char PTR_DAT_006e99e0[];
extern const char *PTR_DAT_006e98b4;

// ---------------------------------------------------------------------------
// 0x638495 — observed shape: flatten a 1x1 vector node through 0x637c38 and
// 0x633174 when both dimensions are 1 and the node resolves; otherwise build
// a statement descriptor (+0x10 = 2) capturing cloned operands and "Stmts".
// ---------------------------------------------------------------------------
int FUN_638495(void *self, int *param_1, int *param_2, int *param_3)
{
    int iVar1;
    int iVar2;
    unsigned char local_1c[16];
    double local_c;

    if (param_1 != (int *)0x0) {
        if ((param_1[6] * param_1[5] == 1) &&
            (iVar1 = FUN_006328e2(param_1[4]), iVar1 != 0)) {
            iVar1 = FUN_0063324e(param_1);
            if ((iVar1 != 0) &&
                (iVar1 = FUN_637c38(self, (unsigned *)param_1, (int)local_1c), -1 < iVar1) &&
                (iVar1 = FUN_00633174(&local_c, local_1c, param_1 + 0xc), -1 < iVar1)) {
                if (local_c == 0.0) {
                    param_2 = param_3;
                }
                iVar1 = (int)FUN_0065abf1((void *)param_2);
                return iVar1;
            }
            iVar1 = (int)FUN_0060d19b(0x24);
            if (iVar1 == 0) {
                iVar1 = 0;
            }
            else {
                iVar1 = FUN_0065b469();
            }
            if (iVar1 != 0) {
                *(unsigned *)(iVar1 + 0x10) = 2;
                iVar2 = (**(int (***)(void))(*param_1 + 4))();
                *(int *)(iVar1 + 0x18) = iVar2;
                if (iVar2 != 0) {
                    if (param_2 != (int *)0x0) {
                        iVar2 = (**(int (***)(void))(*param_2 + 4))();
                        *(int *)(iVar1 + 0x1c) = iVar2;
                        if (iVar2 == 0) {
                            return 0;
                        }
                    }
                    if (param_3 != (int *)0x0) {
                        iVar2 = (**(int (***)(void))(*param_3 + 4))();
                        *(int *)(iVar1 + 0x20) = iVar2;
                        if (iVar2 == 0) {
                            return 0;
                        }
                    }
                    iVar2 = (int)FUN_0060d19b(0x14);
                    if (iVar2 == 0) {
                        iVar1 = 0;
                    }
                    else {
                        iVar1 = FUN_0065ac49((void *)iVar1, 0, "Stmts");
                    }
                    if (iVar1 != 0) {
                        return iVar1;
                    }
                }
            }
        }
        else {
            FUN_00632325();
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6385bc — observed shape: pull the next token from self+0x20 and map it to
// a token id. Token kinds 0/1 are punctuation (single char or '='-pair
// compound), 2..10 are literals/keywords, 0xd is end of input. Keyword heads
// 9 classify identifiers with a first-character switch, then fall back to
// case-insensitive builtin checks and finally to 0x636edb.
// ---------------------------------------------------------------------------
int FUN_6385bc(void *self)
{
    char cVar1;
    char cVar2;
    char *tok;
    int iVar4;
    int kind;

    for (;;) {
        iVar4 = FUN_0060f155((void *)((char *)self + 0x20));
        if (iVar4 < 0) {
            *(unsigned *)((char *)self + 0x40) = 1;
            return -1;
        }
        switch (*(int *)((char *)self + 0x20)) {
        case 0:
            return 0x151;
        case 1:
            cVar1 = *(char *)((char *)self + 0x29);
            if (cVar1 == '\0') {
                return (int)*(char *)((char *)self + 0x28);
            }
            if (*(char *)((char *)self + 0x2a) != '\0') {
                return 0x151;
            }
            if (cVar1 != '=') {
                cVar2 = *(char *)((char *)self + 0x28);
                if (cVar2 != cVar1) {
                    return 0x151;
                }
                if (cVar2 == '&') {
                    return 0x140;
                }
                if (cVar2 == '+') {
                    return 0x13a;
                }
                if (cVar2 == '-') {
                    return 0x13b;
                }
                if (cVar2 == '|') {
                    return 0x141;
                }
                return 0x151;
            }
            cVar1 = *(char *)((char *)self + 0x28);
            if ('-' < cVar1) {
                if (cVar1 == '/') {
                    return 0x143;
                }
                if (cVar1 == '<') {
                    return 0x13c;
                }
                if (cVar1 == '=') {
                    return 0x13e;
                }
                if (cVar1 == '>') {
                    return 0x13d;
                }
                return 0x151;
            }
            if (cVar1 == '-') {
                return 0x146;
            }
            if (cVar1 == '!') {
                return 0x13f;
            }
            if (cVar1 == '%') {
                return 0x144;
            }
            if (cVar1 == '*') {
                return 0x142;
            }
            if (cVar1 == '+') {
                return 0x145;
            }
            return 0x151;
        case 2:
            return 0x147;
        case 3:
            return 0x148;
        case 4:
            return 0x149;
        case 5:
            return 0x14a;
        case 6:
            return 0x14b;
        case 7:
            return 0x14c;
        case 8:
            return 0x14d;
        case 9:
            tok = *(char **)((char *)self + 0x28);
            kind = -1;
            switch ((unsigned char)*tok) {
            case 'a':
                if (recon_eq_n(tok, "auto", 5)) kind = 0x151;
                else if (recon_eq_n(tok, "asm_fragment", 0xd)) kind = 0x102;
                break;
            case 'b':
                if (recon_eq_n(tok, "bool", 5)) kind = 0x103;
                else if (recon_eq_n(tok, "break", 6)) kind = 0x151;
                break;
            case 'c':
                if (recon_eq_n(tok, "case", 5)) kind = 0x151;
                else if (recon_eq_n(tok, "catch", 6)) kind = 0x151;
                else if (recon_eq_n(tok, "char", 5)) kind = 0x151;
                else if (recon_eq_n(tok, "class", 6)) kind = 0x151;
                else if (recon_eq_n(tok, "column_major", 0xd)) kind = 0x104;
                else if (recon_eq_n(tok, "compile", 8)) kind = 0x105;
                else if (recon_eq_n(tok, "compile_fragment", 0x11)) kind = 0x106;
                else if (recon_eq_n(tok, "const", 6)) kind = 0x107;
                else if (recon_eq_n(tok, "const_cast", 0xb)) kind = 0x151;
                else if (recon_eq_n(tok, "continue", 9)) kind = 0x151;
                break;
            case 'd':
                if (recon_eq_n(tok, "default", 8)) kind = 0x151;
                else if (recon_eq_n(tok, "delete", 7)) kind = 0x151;
                else if (recon_eq_n(tok, "discard", 8)) kind = 0x109;
                else if (recon_eq_n(tok, "do", 3)) kind = 0x10b;
                else if (recon_eq_n(tok, "double", 7)) kind = 0x10a;
                else if (recon_eq_n(tok, "dynamic_cast", 0xd)) kind = 0x151;
                break;
            case 'e':
                if (recon_eq_n(tok, "else", 5)) kind = 0x10c;
                else if (recon_eq_n(tok, "enum", 5)) kind = 0x151;
                else if (recon_eq_n(tok, "explicit", 9)) kind = 0x151;
                else if (recon_eq_n(tok, "extern", 7)) kind = 0x10d;
                break;
            case 'f':
                if (recon_eq_n(tok, "false", 6)) kind = 0x10e;
                else if (recon_eq_n(tok, "float", 6)) kind = 0x10f;
                else if (recon_eq_n(tok, "for", 4)) kind = 0x110;
                else if (recon_eq_n(tok, "friend", 7)) kind = 0x151;
                break;
            case 'g':
                if (recon_eq_n(tok, DAT_006e9a14, 5)) kind = 0x151;
                break;
            case 'h':
                if (recon_eq_n(tok, "half", 5)) kind = 0x111;
                break;
            case 'i':
                if (recon_eq_n(tok, "if", 3)) kind = 0x112;
                else if (recon_eq_n(tok, "in", 3)) kind = 0x113;
                else if (recon_eq_n(tok, "inline", 7)) kind = 0x114;
                else if (recon_eq_n(tok, "inout", 6)) kind = 0x115;
                else if (recon_eq_n(tok, "int", 4)) kind = 0x116;
                break;
            case 'l':
                if (recon_eq_n(tok, DAT_006e99f8, 5)) kind = 0x151;
                break;
            case 'm':
                if (recon_eq_n(tok, "matrix", 7)) kind = 0x117;
                else if (recon_eq_n(tok, "mutable", 8)) kind = 0x151;
                break;
            case 'n':
                if (recon_eq_n(tok, "namespace", 10)) kind = 0x151;
                else if (recon_eq_n(tok, PTR_DAT_006e99e0, 4)) kind = 0x151;
                break;
            case 'o':
                if (recon_eq_n(tok, "out", 4)) kind = 0x118;
                else if (recon_eq_n(tok, "operator", 9)) kind = 0x151;
                break;
            case 'p':
                if (recon_eq_n(tok, "pixelfragment", 0xe)) kind = 0x11a;
                else if (recon_eq_n(tok, "private", 8)) kind = 0x151;
                else if (recon_eq_n(tok, "protected", 10)) kind = 0x151;
                else if (recon_eq_n(tok, "public", 7)) kind = 0x151;
                else if ((*(int *)((char *)self + 0x48) != 0) &&
                         recon_eq_n(tok, "pixelshader", 0xc))
                    kind = 0x11b;
                break;
            case 'r':
                if (recon_eq_n(tok, "register", 9)) kind = 0x11c;
                else if (recon_eq_n(tok, "reinterpret_cast", 0x11)) kind = 0x151;
                else if (recon_eq_n(tok, "row_major", 10)) kind = 0x11e;
                else if (recon_eq_n(tok, "return", 7)) kind = 0x11d;
                break;
            case 's':
                if (recon_eq_n(tok, "sampler1D", 10)) kind = 0x120;
                else if (recon_eq_n(tok, "sampler2D", 10)) kind = 0x121;
                else if (recon_eq_n(tok, "sampler3D", 10)) kind = 0x122;
                else if (recon_eq_n(tok, "samplerCUBE", 0xc)) kind = 0x123;
                else if (recon_eq_n(tok, "sampler_state", 0xe)) kind = 0x124;
                else if (recon_eq_n(tok, "shared", 7)) kind = 0x125;
                else if (recon_eq_n(tok, "short", 6)) kind = 0x151;
                else if (recon_eq_n(tok, "signed", 7)) kind = 0x151;
                else if (recon_eq_n(tok, "sizeof", 7)) kind = 0x151;
                else if (recon_eq_n(tok, "stateblock_state", 0x11)) kind = 0x127;
                else if (recon_eq_n(tok, "static", 7)) kind = 0x128;
                else if (recon_eq_n(tok, "static_cast", 0xc)) kind = 0x151;
                else if (recon_eq_n(tok, "string", 7)) kind = 0x129;
                else if (recon_eq_n(tok, "struct", 7)) kind = 0x12a;
                else if (recon_eq_n(tok, "switch", 7)) kind = 0x151;
                else if (*(int *)((char *)self + 0x48) != 0) {
                    if (recon_eq_n(tok, "sampler", 8)) kind = 0x11f;
                    else if (recon_eq_n(tok, "stateblock", 0xb)) kind = 0x126;
                }
                break;
            case 't':
                if (recon_eq_n(tok, "template", 9)) kind = 0x151;
                else if (recon_eq_n(tok, "texture1D", 10)) kind = 0x12d;
                else if (recon_eq_n(tok, "texture2D", 10)) kind = 0x12e;
                else if (recon_eq_n(tok, "texture3D", 10)) kind = 0x12f;
                else if (recon_eq_n(tok, "textureCUBE", 0xc)) kind = 0x130;
                else if (recon_eq_n(tok, "this", 5)) kind = 0x151;
                else if (recon_eq_n(tok, "throw", 6)) kind = 0x151;
                else if (recon_eq_n(tok, "true", 5)) kind = 0x131;
                else if (recon_eq_n(tok, "try", 4)) kind = 0x151;
                else if (recon_eq_n(tok, "typedef", 8)) kind = 0x132;
                else if (recon_eq_n(tok, "typename", 9)) kind = 0x151;
                else if ((*(int *)((char *)self + 0x48) != 0) &&
                         recon_eq_n(tok, "texture", 8))
                    kind = 300;
                break;
            case 'u':
                if (recon_eq_n(tok, "uniform", 8)) kind = 0x133;
                else if (recon_eq_n(tok, "union", 6)) kind = 0x151;
                else if (recon_eq_n(tok, "unsigned", 9)) kind = 0x151;
                else if (recon_eq_n(tok, "using", 6)) kind = 0x151;
                break;
            case 'v':
                if (recon_eq_n(tok, "vector", 7)) kind = 0x134;
                else if (recon_eq_n(tok, "vertexfragment", 0xf)) kind = 0x135;
                else if (recon_eq_n(tok, "virtual", 8)) kind = 0x151;
                else if (recon_eq_n(tok, "void", 5)) kind = 0x137;
                else if (recon_eq_n(tok, "volatile", 9)) kind = 0x138;
                else if ((*(int *)((char *)self + 0x48) != 0) &&
                         recon_eq_n(tok, "vertexshader", 0xd))
                    kind = 0x136;
                break;
            case 'w':
                if (recon_eq_n(tok, "while", 6)) kind = 0x139;
                break;
            default:
                break;
            }
            if (kind >= 0) {
                return kind;
            }
            iVar4 = tolower((int)(unsigned char)*tok);
            if (iVar4 == 0x61) {
                iVar4 = _stricmp(*(char **)((char *)self + 0x28), PTR_DAT_006e98b4);
                if (iVar4 == 0) {
                    return 0x101;
                }
            }
            else if (iVar4 == 100) {
                iVar4 = _stricmp(*(char **)((char *)self + 0x28), "decl");
                if (iVar4 == 0) {
                    return 0x108;
                }
            }
            else if (iVar4 == 0x70) {
                iVar4 = _stricmp(*(char **)((char *)self + 0x28), "pass");
                if (iVar4 == 0) {
                    return 0x119;
                }
            }
            else if ((iVar4 == 0x74) &&
                     (iVar4 = _stricmp(*(char **)((char *)self + 0x28), "technique"),
                      iVar4 == 0)) {
                return 299;
            }
            iVar4 = FUN_636edb(self, 0, (int)self + 0x20, 0, 0,
                               *(int *)((char *)self + 0x10), 0, 0, 0);
            return (iVar4 != 0) + 0x14f;
        case 10:
            return 0x14e;
        case 0xd:
            return -1;
        default:
            break;
        }
    }
}

// ---------------------------------------------------------------------------
// 0x639117 — observed shape: build a "Stmts" node from param_1 plus an
// optional statement chain param_3; the node carries duplicated symbols and
// is linked into the context at self+0x10. Fails leave the context untouched.
// ---------------------------------------------------------------------------
int FUN_639117(void *self, int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar2;
    int iVar3;
    void *uVar4;
    unsigned char local_5c[16];
    unsigned local_4c;
    unsigned local_48;
    unsigned local_44;
    unsigned local_40;
    unsigned local_3c;
    unsigned local_30;
    int local_1c;
    int local_18;
    int local_14;
    int local_10;
    int local_c;
    int local_8;

    local_18 = 0;
    iVar1 = (int)FUN_0063271d();
    local_1c = iVar1;
    FUN_0065b377();
    if (iVar1 == 0) {
        return 0;
    }
    if (param_1 == 0) {
        return 0;
    }
    local_14 = *(int *)(iVar1 + 0x18);
    local_8 = param_1 + 0x10;
    if ((*(unsigned char *)(iVar1 + 0x10) & 0x40) != 0) {
        FUN_00632325();
    }
    if ((*(unsigned char *)(iVar1 + 0x10) & 1) != 0) {
        FUN_00632325();
    }
    iVar1 = FUN_006328e2(local_14);
    if (iVar1 == 0) {
        FUN_00632325();
    }
    local_10 = 0;
    for (iVar1 = param_2; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        if ((*(int *)(iVar1 + 8) != 0) && (*(int *)(*(int *)(iVar1 + 8) + 4) == 6)) {
            iVar2 = *(int *)(iVar1 + 0xc);
            if ((iVar2 == 0) || (*(int *)(*(int *)(iVar2 + 8) + 4) != 0xc)) {
                if (local_10 != 0) {
                    FUN_00632325();
                }
            }
            else {
                local_10 = 1;
                iVar1 = iVar2;
            }
        }
    }
    iVar1 = (int)FUN_0060d19b(0x14);
    if (iVar1 == 0) {
        local_10 = 0;
    }
    else {
        local_10 = FUN_0065ac49(0, 0, "Stmts");
    }
    if (local_10 == 0) {
        return 0;
    }
    iVar1 = (int)FUN_0060d19b(0x30);
    if (iVar1 == 0) {
        local_c = 0;
    }
    else {
        local_c = FUN_0065b01d(2, 0, 0, 0);
    }
    iVar1 = local_c;
    if (local_c == 0) {
        return 0;
    }
    *(int *)(local_10 + 8) = local_c;
    iVar2 = (int)FUN_0065abf1((void *)param_1);
    *(int *)(iVar1 + 0x14) = iVar2;
    if (iVar2 == 0) {
        return 0;
    }
    iVar2 = (int)FUN_0060d19b(0x40);
    if (iVar2 == 0) {
        iVar2 = 0;
    }
    else {
        iVar2 = FUN_0065b27f();
    }
    if (iVar2 == 0) {
        return 0;
    }
    *(int *)(iVar1 + 0x18) = iVar2;
    *(unsigned *)(iVar2 + 0x18) = *(unsigned *)(local_1c + 0x10);
    if (*(int *)(local_1c + 0x14) != 0) {
        iVar1 = (int)FUN_0065abf1((void *)*(int *)(local_1c + 0x14));
        *(int *)(iVar2 + 0x1c) = iVar1;
        if (iVar1 == 0) {
            return 0;
        }
    }
    if (local_14 != 0) {
        iVar1 = (int)FUN_0065abf1((void *)local_14);
        *(int *)(iVar2 + 0x20) = iVar1;
        if (iVar1 == 0) {
            return 0;
        }
    }
    FUN_00632729(*(void **)(iVar2 + 0x20), 1);
    if (param_3 != 0) {
        if (*(int *)(iVar2 + 0x20) == 0) {
            FUN_00632325();
            param_3 = 0;
        }
        if (param_3 != 0) {
            iVar1 = (int)FUN_0065abf1((void *)param_3);
            *(int *)(iVar2 + 0x34) = iVar1;
            if (iVar1 == 0) {
                return 0;
            }
            do {
                iVar1 = *(int *)(param_3 + 8);
                if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == 3)) {
                    iVar1 = (int)FUN_0065abf1((void *)iVar1);
                    *(int *)(iVar2 + 0x30) = iVar1;
                    if (iVar1 == 0) {
                        return 0;
                    }
                }
                param_3 = *(int *)(param_3 + 0xc);
            } while (param_3 != 0);
        }
    }
    if ((param_2 != 0) && (*(int *)(param_2 + 8) != 0)) {
        iVar1 = (int)FUN_0065abf1((void *)param_2);
        *(int *)(iVar2 + 0x24) = iVar1;
        if (iVar1 == 0) {
            return 0;
        }
    }
    iVar3 = FUN_636edb(self, 2, local_8, *(unsigned *)(iVar2 + 0x1c),
                       *(unsigned *)(iVar2 + 0x24),
                       *(int *)(*(int *)((char *)self + 0x10) + 0x20), 10, &param_2, &local_18);
    iVar1 = param_2;
    if (iVar3 < 0) {
LAB_006393a4:
        FUN_00632325();
        return 0;
    }
    if (iVar3 == 0) {
        iVar3 = FUN_006329e7(*(int **)(iVar2 + 0x20), *(int **)(param_2 + 0x20));
        if (iVar3 == 0) goto LAB_006393a4;
        *(unsigned *)(iVar2 + 0x10) = *(unsigned *)(iVar1 + 0x10);
        *(unsigned *)(iVar2 + 0x14) = *(unsigned *)(iVar1 + 0x14);
        *(unsigned *)(local_c + 0x24) = *(unsigned *)(*(int *)(local_18 + 8) + 0x18);
    }
    else {
        *(unsigned *)(iVar2 + 0x10) = *(unsigned *)((char *)self + 0x58);
        iVar3 = FUN_00632959(*(void **)(iVar2 + 0x20));
        *(int *)(iVar2 + 0x14) = iVar3;
        *(int *)((char *)self + 0x58) = *(int *)((char *)self + 0x58) + iVar3;
    }
    local_4c = *(unsigned *)(iVar2 + 0x10);
    local_48 = *(unsigned *)(iVar2 + 0x14);
    local_40 = 0;
    local_44 = 3;
    local_3c = (unsigned)(size_t)FUN_0065abf1((void *)*(int *)(iVar2 + 0x20));
    local_30 = (unsigned)(size_t)FUN_0065abf1((void *)param_3);
    FUN_00632729((void *)(size_t)local_3c, 0);
    uVar4 = (void *)FUN_637598(self, param_1, (int)local_5c);
    *(void **)(iVar2 + 0x2c) = uVar4;
    if (iVar1 == 0) {
        iVar1 = *(int *)((char *)self + 0x10);
        *(unsigned *)((char *)self + 0x10) = *(unsigned *)(iVar1 + 0x20);
        iVar3 = FUN_0063395f(local_c, 0);
        *(int *)((char *)self + 0x10) = iVar1;
        if (iVar3 < 0) {
            return 0;
        }
        *(int *)((char *)self + 0x54) = *(int *)((char *)self + 0x54) + 1;
    }
    *(unsigned *)(*(int *)((char *)self + 0x10) + 0x14) = *(unsigned *)(local_8 + 8);
    *(int *)((char *)self + 0x18) = iVar2;
    return local_10;
}

// ---------------------------------------------------------------------------
// 0x639498 — observed shape: materialise a kind-0xd node's element array
// through 0x637c38 into a scratch buffer, then rebuild the container chain
// with one "Value" child per element. The scratch buffer is always freed.
// ---------------------------------------------------------------------------
int FUN_639498(void *self, void *param_1)
{
    int iVar1;
    unsigned uVar2;
    void *pvVar3;
    int iVar4;
    int iVar5;
    int *piVar6;
    unsigned local_8;

    iVar1 = (int)param_1;
    if ((param_1 == (void *)0x0) || (*(int *)((int)param_1 + 4) != 0xd)) {
        return 0;
    }
    uVar2 = *(int *)((int)param_1 + 0x18) * *(int *)((int)param_1 + 0x14);
    pvVar3 = (void *)FUN_00533c78(uVar2 * 0x10);
    if ((pvVar3 != (void *)0x0) &&
        (iVar4 = FUN_637c38(self, (unsigned *)param_1, (int)pvVar3), -1 < iVar4)) {
        iVar4 = (int)FUN_0060d19b(0x50);
        if (iVar4 == 0) {
            iVar4 = 0;
        }
        else {
            iVar4 = FUN_0065b52c(0, 0, 0, 0, 1, (void *)(iVar1 + 0x30));
        }
        if (iVar4 != 0) {
            if (*(int *)(iVar1 + 0x10) != 0) {
                iVar5 = (**(int (***)(void))(**(int **)(iVar1 + 0x10) + 4))();
                *(int *)(iVar4 + 0x10) = iVar5;
                if (iVar5 == 0) goto LAB_006395ab;
            }
            local_8 = 0;
            piVar6 = (int *)(iVar4 + 0x20);
            if (uVar2 != 0) {
                param_1 = pvVar3;
                do {
                    iVar5 = (int)FUN_0060d19b(0x14);
                    if (iVar5 == 0) {
                        iVar5 = 0;
                    }
                    else {
                        iVar5 = FUN_0065ac49(0, 0, "Value");
                    }
                    *piVar6 = iVar5;
                    if (iVar5 == 0) goto LAB_006395ab;
                    iVar5 = (int)FUN_0060d19b(0x40);
                    if (iVar5 == 0) {
                        iVar5 = 0;
                    }
                    else {
                        iVar5 = FUN_0065b62d(param_1, (void *)(iVar1 + 0x30));
                    }
                    *(int *)(*piVar6 + 8) = iVar5;
                    if (iVar5 == 0) goto LAB_006395ab;
                    param_1 = (void *)((int)param_1 + 0x10);
                    piVar6 = (int *)(*piVar6 + 0xc);
                    local_8 = local_8 + 1;
                } while (local_8 < uVar2);
            }
            FUN_0063336c(iVar4);
            goto LAB_006395ad;
        }
    }
LAB_006395ab:
    iVar4 = 0;
LAB_006395ad:
    operator_delete(pvVar3);
    return iVar4;
}
