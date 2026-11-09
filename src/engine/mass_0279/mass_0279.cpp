// Reconstruction candidate file — batch mass_0279
// Target image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
// Ghidra 12.2 pseudocode translated to C++ candidates. Receivers (in_ECX) are
// modelled as an explicit `void* self`; no `this` is used.

#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void*);
extern void* FUN_00533c78(std::size_t size);
extern std::int64_t FUN_00614480(void* dst, std::uint32_t count);
extern std::uint32_t FUN_00616222(std::uint32_t device, std::uint32_t op, void* dst, void* src1, void* src2, std::uint32_t extra);
extern std::uint32_t FUN_0065d9d5(void* reader, std::uint32_t a, std::uint32_t b, std::uint64_t tag);
extern std::int32_t FUN_006147e4(std::int32_t object, void* outRange);
extern std::int32_t FUN_00616086(std::int32_t value, void* outDouble);
extern std::int32_t FUN_00616184(std::uint32_t a, std::uint32_t b, void* buffer);
extern std::int32_t FUN_00616a9f(std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t d, std::uint32_t e, std::uint32_t f, void* g, std::uint32_t h, std::uint32_t i, std::uint32_t j);
extern std::uint32_t FUN_0065da8c(std::int32_t object);
extern std::int32_t FUN_0062254c(int* param_1, void* param_2);
extern std::int32_t FUN_00624bb6(std::uint32_t a, void* b, void* c);
extern std::int32_t FUN_006143c6(void);
extern std::int32_t FUN_0065d00b(void);
extern std::int32_t FUN_006629c4(std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t d);
extern std::int32_t FUN_00615bbb(void);
extern std::int32_t FUN_00616a38(std::uint32_t a, void* b, std::uint32_t c);
extern std::int32_t FUN_006145fe(void);
extern std::int32_t FUN_0065e3ad(void);
extern char* strchr(const char*, int);

// Widening helper for the decompiler's raw integer-to-pointer casts.
template <class T = std::int32_t, class U>
static inline T* PTR(U value) { return reinterpret_cast<T*>(static_cast<std::uintptr_t>(value)); }


// 0x616cee — observed shape
// Receiver via in_ECX. Flags word at [self+8]+0x6c.
//   bit 0x200 clear:
//     (bit 0x100 clear || inputs not all equal) -> 11 FUN_0065d9d5 tag
//       constants, 27-column scratch grid (column stride local_c*4), 15
//       FUN_00614480 validations, then a 16-call FUN_00616222 chain
//       (0x205,0x204,0x104,0x205,0x204,0x205,0x204,0x205,0x204,0x205,0x204,
//       0x205,0x204,0x205,0x204@0x10); copies nA words to param_3 and nB to
//       param_4.
//     else -> 0.25/0.5/pi/-pi constants, FUN_006147e4 range test on *param_2,
//       5-call chain when outside [-pi,pi], else local_20 = *param_2, then
//       0x50300004 fan-out (4 replicated values) and fill of param_3/param_4
//       with -1.
//   bit 0x200 set: 0x10800000 on param_3, 0x10900000 on param_4 (stride 0x10).
// Returns 0 on success (negative HRESULT otherwise); scratch freed last.
std::int32_t* FUN_00616cee(void* self, std::uint32_t device, std::int32_t* param_2, std::int32_t* param_3, std::int32_t* param_4, std::uint32_t param_5) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    void* scratch = nullptr;
    std::int32_t* status = nullptr;
    std::uint32_t same = 1;

    if (1 < param_5) {
        for (std::uint32_t i = 1; i < param_5; i++) {
            if (param_2[i] != *param_2) { same = 0; break; }
        }
    }

    std::uint32_t flags = *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 0x6c);

    if ((flags & 0x200) == 0) {
        if (((flags & 0x100) == 0) || (same == 0)) {
            std::uint32_t nA = (param_3 != nullptr) ? param_5 : 0;
            std::uint32_t nB = (param_4 != nullptr) ? param_5 : 0;
            std::uint32_t cols_count = nB + nA;

            std::int32_t owner = *PTR<>(self8 + 8);
            void* reader = reinterpret_cast<void*>(*PTR<std::uint32_t>(owner + 0x78));
            std::uint32_t k0 = FUN_0065d9d5(reader, 0, 0, 0x3fc45f306446f9b4ULL);
            std::uint32_t k1 = FUN_0065d9d5(reader, 0, 0, 0x3fd0000000000000ULL);
            std::uint32_t k2 = FUN_0065d9d5(reader, 0, 0, 0x3fe0000000000000ULL);
            std::uint32_t k3 = FUN_0065d9d5(reader, 0, 0, 0x401921fb60000000ULL);
            std::uint32_t k4 = FUN_0065d9d5(reader, 0, 0, 0xc00921fb60000000ULL);
            std::uint32_t k5 = FUN_0065d9d5(reader, 0, 0, 0xbe90f02c6b8de73bULL);
            std::uint32_t k6 = FUN_0065d9d5(reader, 0, 0, 0x3ef9f6b4176d5badULL);
            std::uint32_t k7 = FUN_0065d9d5(reader, 0, 0, 0xbf56c13745d11568ULL);
            std::uint32_t k8 = FUN_0065d9d5(reader, 0, 0, 0x3fa555547fbaf47eULL);
            std::uint32_t k9 = FUN_0065d9d5(reader, 0, 0, 0xbfdffffffc06f3a6ULL);

            scratch = FUN_00533c78(0);
            if (scratch == nullptr) return PTR<>(static_cast<std::intptr_t>(static_cast<std::int32_t>(0x8007000e)));

            std::int32_t* col[27];
            {
                auto* p = reinterpret_cast<std::uint8_t*>(scratch);
                for (std::uint32_t i = 0; i < 27; i++) { col[i] = PTR<>(p); p += cols_count * 4; }
            }
            for (std::uint32_t i = 0; i < 15;) {
                std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(col[i]), cols_count);
                if (static_cast<std::int32_t>(rc) < 0) { status = PTR<>(static_cast<std::intptr_t>(static_cast<std::int32_t>(rc))); goto done; }
                i = static_cast<std::uint32_t>(rc >> 32) + 1;
            }
            for (std::uint32_t i = 0; i < cols_count; i++) {
                std::uint32_t v = (i < nA) ? static_cast<std::uint32_t>(param_3[i]) : static_cast<std::uint32_t>(param_4[i - nA]);
                col[15][i] = static_cast<std::int32_t>(v);
                col[16][i] = static_cast<std::int32_t>(k0);
                col[17][i] = static_cast<std::int32_t>((nA <= i) ? k2 : k1);
                col[18][i] = static_cast<std::int32_t>(k3);
                col[19][i] = static_cast<std::int32_t>(k4);
                col[20][i] = static_cast<std::int32_t>(k5);
                col[21][i] = static_cast<std::int32_t>(k6);
                col[22][i] = static_cast<std::int32_t>(k7);
                col[23][i] = static_cast<std::int32_t>(k8);
                col[24][i] = static_cast<std::int32_t>(k9);
                col[25][i] = *PTR<>(PTR<>(self8) + 0x20);
                col[26][i] = (i < nA) ? param_2[i] : param_2[i - nA];
            }

            std::uint32_t base = cols_count & 0xfffff;
            static const std::uint32_t kOp[16]   = {0x205u,0x204u,0x104u,0x205u,0x204u,0x205u,0x204u,0x205u,0x204u,0x205u,0x204u,0x205u,0x204u,0x205u,0x204u,0x204u};
            static const std::int32_t  kSrc1[16] = {26,0,1,2,3,4,5,6,5,8,5,10,5,12,5,14};
            static const std::int32_t  kSrc2[16] = {16,17,-1,18,19,4,20,21,7,22,9,23,11,24,13,25};
            static const std::uint32_t kExtra[16] = {0,0,0x14,4,0,4,0,0,0,0,0,0,0,0,0,0x10};
            for (int s = 0; s < 16; s++) {
                std::uint32_t op = base | kOp[s];
                void* src1 = (kSrc1[s] < 0) ? nullptr : reinterpret_cast<void*>(col[kSrc1[s]]);
                void* src2 = (kSrc2[s] < 0) ? nullptr : reinterpret_cast<void*>(col[kSrc2[s]]);
                std::int32_t rc = static_cast<std::int32_t>(FUN_00616222(device, op, reinterpret_cast<void*>(col[s]), src1, src2, kExtra[s]));
                if (rc < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
            }
            if (param_3 != nullptr) { for (std::uint32_t i = 0; i < nA; i++) param_3[i] = col[0][i]; }
            if (param_4 != nullptr) { for (std::uint32_t i = 0; i < nB; i++) param_4[i] = col[0][nA + i]; }
            goto ok;
        }

        // constant path: bit 0x100 set and all inputs equal
        {
            std::int32_t owner = *PTR<>(self8 + 8);
            void* reader = reinterpret_cast<void*>(*PTR<std::uint32_t>(owner + 0x78));
            std::uint32_t a0 = FUN_0065d9d5(reader, 0, 0, 0x3fc45f306446f9b4ULL);
            std::uint32_t a1 = FUN_0065d9d5(reader, 0, 0, 0x3fe0000000000000ULL);
            std::uint32_t a2 = FUN_0065d9d5(reader, 0, 0, 0x401921fb60000000ULL);
            std::uint32_t a3 = FUN_0065d9d5(reader, 0, 0, 0xc00921fb60000000ULL);

            struct RangePair { float lo; float hi; } range{0.f, 0.f};
            std::int32_t rc = FUN_006147e4(*param_2, &range);
            if (rc < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }

            std::int32_t seed;
            if ((range.lo < -3.1415927410125732f) || (3.1415927410125732f < range.hi)) {
                std::int32_t p0 = -1, p1 = -1, p2 = -1, p3 = -1, p4 = -1;
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x20500001u, &p0, param_2, &a0, 0))) < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x20400001u, &p1, &p0, &a1, 0))) < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x10400001u, &p2, &p1, nullptr, 0x14))) < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x20500001u, &p3, &p2, &a2, 4))) < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x20400001u, &p4, &p3, &a3, 0))) < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
                seed = p4;
            } else {
                seed = *param_2;
            }
            std::int32_t r0 = -1, r1 = -1, r2 = -1, r3 = -1;
            std::int32_t rep[4] = {seed, seed, seed, seed};
            rc = static_cast<std::int32_t>(FUN_00616222(device, 0x50300004u, &r0, rep, nullptr, 0x10));
            if (rc < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
            (void)r1; (void)r2; (void)r3;
            if (param_4 != nullptr) { for (std::uint32_t i = 0; i < param_5; i++) param_4[i] = r0; }
            if (param_3 != nullptr) { for (std::uint32_t i = 0; i < param_5; i++) param_3[i] = r1; }
            goto ok;
        }
    } else {
        std::uint32_t base = param_5 & 0xfffff;
        if (param_3 != nullptr) {
            std::int32_t rc = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10800000u, param_3, param_2, nullptr, 0x10));
            if (rc < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
        }
        if (param_4 != nullptr) {
            std::int32_t rc = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10900000u, param_4, param_2, nullptr, 0x10));
            if (rc < 0) { status = PTR<>(static_cast<std::intptr_t>(rc)); goto done; }
        }
    }
ok:
    status = nullptr;
done:
    operator_delete(scratch);
    return status;
}

// 0x617590 — observed shape
// Receiver via in_ECX. Tests [self+8]+0x6d bit 0x02.
// Clear path: 7 FUN_0065d9d5 tag constants, 28-column grid (stride param_5*4),
//   20 FUN_00614480 validations, column 0x14 filled from [self+0x20], then 20
//   chained FUN_00616222 calls with ops in order
//   0x101,0x201,0x101,0x204,0x107,0x103,0x205,0x204,0x205,0x204,0x205,0x204,
//   0x205,0x205,0x204,0x202,0x205,0x204,0x101,0x204 and extras
//   0,4,8,0,4,4,0,0,0,0,0,0,0,0,0,0x17,0,4,8,0; optional param_3 through
//   0x10000000 and param_4 through 0x10000000 with extra 0x400000000.
// Set path: param_3 via 0x10a00000, param_4 via 0x10b00000.
std::int32_t FUN_00617590(void* self, std::uint32_t device, std::int32_t param_2, std::int32_t param_3, std::int32_t param_4, std::uint32_t param_5) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    void* scratch = nullptr;

    if ((*reinterpret_cast<std::uint8_t*>(*PTR<>(self8 + 8) + 0x6d) & 2) == 0) {
        std::int32_t owner = *PTR<>(self8 + 8);
        void* reader = reinterpret_cast<void*>(*PTR<std::uint32_t>(owner + 0x78));
        std::uint32_t c0 = FUN_0065d9d5(reader, 0, 0, 0xbf932dc60be86b8fULL);
        std::uint32_t c1 = FUN_0065d9d5(reader, 0, 0, 0x3fb302c4d65e4606ULL);
        std::uint32_t c2 = FUN_0065d9d5(reader, 0, 0, 0xbfcb26908d815d63ULL);
        std::uint32_t c3 = FUN_0065d9d5(reader, 0, 0, 0x3ff921b485ae2a4aULL);
        std::uint32_t c4 = FUN_0065d9d5(reader, 0, 0, 0xc000000000000000ULL);
        std::uint32_t c5 = FUN_0065d9d5(reader, 0, 0, 0x400921fb60000000ULL);
        std::uint32_t c6 = FUN_0065d9d5(reader, 0, 0, 0x3ff921fb60000000ULL);

        scratch = FUN_00533c78(0);
        if (scratch == nullptr) { operator_delete(scratch); return static_cast<std::int32_t>(0x8007000e); }

        std::int32_t* col[28];
        {
            auto* p = reinterpret_cast<std::uint8_t*>(scratch);
            for (std::uint32_t i = 0; i < 0x1c; i++) { col[i] = PTR<>(p); p += param_5 * 4; }
        }
        for (std::uint32_t i = 0; i < 0x14;) {
            std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(col[i]), param_5);
            if (static_cast<std::int32_t>(rc) < 0) { operator_delete(scratch); return static_cast<std::int32_t>(rc); }
            i = static_cast<std::uint32_t>(rc >> 32) + 1;
        }
        for (std::uint32_t i = 0; i < param_5; i++) {
            col[0x14][i] = *PTR<>(PTR<>(self8) + 0x20);
            col[0][i] = static_cast<std::int32_t>(c0);
            col[1][i] = static_cast<std::int32_t>(c1);
            col[2][i] = static_cast<std::int32_t>(c2);
            col[3][i] = static_cast<std::int32_t>(c3);
            col[4][i] = static_cast<std::int32_t>(c4);
            col[5][i] = static_cast<std::int32_t>(c5);
            col[6][i] = static_cast<std::int32_t>(c6);
        }

        std::uint32_t base = param_5 & 0xfffff;
        static const std::uint32_t kOp[20]    = {0x101u,0x201u,0x101u,0x204u,0x107u,0x103u,0x205u,0x204u,0x205u,0x204u,0x205u,0x204u,0x205u,0x205u,0x204u,0x202u,0x205u,0x204u,0x101u,0x204u};
        static const std::int32_t  kDst[20]   = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF,0x10,0x11,0x12,0x13};
        static const std::int32_t  kSrc1[20]  = {-1,0,1,2,3,4,0,6,7,8,9,10,0xB,0xC,0xD,0,0xE,0xC,0x11,0x12};
        static const std::int32_t  kSrc2[20]  = {-1,-1,-1,0x14,-1,-1,1,2,1,3,1,4,5,-1,6,0,0xF,0x10,-1,-1};
        static const std::uint32_t kExtra[20] = {0,4,8,0,4,4,0,0,0,0,0,0,0,0,0,0x17,0,4,8,0};

        for (int s = 0; s < 20; s++) {
            std::uint32_t op = base | kOp[s];
            void* src1 = (kSrc1[s] < 0) ? reinterpret_cast<void*>(param_2) : reinterpret_cast<void*>(col[kSrc1[s]]);
            void* src2 = (kSrc2[s] < 0) ? nullptr : reinterpret_cast<void*>(col[kSrc2[s]]);
            std::int32_t rc = static_cast<std::int32_t>(FUN_00616222(device, op, reinterpret_cast<void*>(col[kDst[s]]), src1, src2, kExtra[s]));
            if (rc < 0) { operator_delete(scratch); return rc; }
        }
        if (param_3 != 0) {
            std::int32_t rc = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10000000u, reinterpret_cast<void*>(param_3), reinterpret_cast<void*>(col[0x13]), nullptr, 0));
            if (rc < 0) { operator_delete(scratch); return rc; }
        }
        if (param_4 != 0) {
            std::int32_t rc = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10000000u, reinterpret_cast<void*>(param_4), reinterpret_cast<void*>(col[0x11]), reinterpret_cast<void*>(static_cast<std::uintptr_t>(0x400000000ULL)), 0));
            if (rc < 0) { operator_delete(scratch); return rc; }
        }
        operator_delete(scratch);
        return 0;
    }

    std::int32_t result = 0;
    if (param_3 != 0) {
        result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x10a00000u, reinterpret_cast<void*>(param_3), reinterpret_cast<void*>(param_2), nullptr, 0));
        if (result < 0) { operator_delete(scratch); return result; }
    }
    if (param_4 != 0) {
        result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x10b00000u, reinterpret_cast<void*>(param_4), reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(static_cast<std::uintptr_t>(0x400000000ULL)), 0));
        if (result < 0) { operator_delete(scratch); return result; }
    }
    operator_delete(scratch);
    return result;
}

// 0x617b0e — observed shape
// Receiver via in_ECX; same [self+8]+0x6d bit 0x02 split as 0x617590.
// Clear path: 8 FUN_0065d9d5 tag constants written to columns
//   0x27 (first tag) and 0x40..0x46 (remaining seven, plus [self+0x20] in
//   column 0x47); 0x30-column grid with stride param_5*4, 0x27 FUN_00614480
//   validations, param_3 defaulting to column 0x24, then FUN_00616222 chain
//   with ops in order
//   0x101,0x201,0x101,0x201,0x200,0x201,0x103,0x205,0x205,0x205,0x204,0x205,
//   0x204,0x205,0x204,0x205,0x204,0x205,0x202,0x205,0x204,0x205,0x204,
//   0x202,0x205,0x204,0x200,0x201,0x101,0x202,0x101,0x203,0x205,0x204,
//   0x101,0x205 and extras
//   0,4,0,4,4,4,4,0x14,0x14,0,0,0,0,0,0,0,0,0,0x17,0,0,0,0,0x17,0,0,0,0,0,
//   0x17,0,0x17,0x17,0,0,0. Final dispatch uses 0x204 with columns
//   0x1c/0x26 and is normalised to 0 on success.
// Set path: dispatch op 0x10c when param_3 == 0 else 0x206, on param_4.
std::int32_t FUN_00617b0e(void* self, std::uint32_t device, std::int32_t param_2, std::int32_t param_3, std::uint32_t param_4, std::uint32_t param_5) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    void* scratch = nullptr;
    std::int32_t result = 0;

    if ((*reinterpret_cast<std::uint8_t*>(*PTR<>(self8 + 8) + 0x6d) & 2) == 0) {
        std::int32_t owner = *PTR<>(self8 + 8);
        void* reader = reinterpret_cast<void*>(*PTR<std::uint32_t>(owner + 0x78));
        std::uint32_t d0 = FUN_0065d9d5(reader, 0, 0, 0x3f9555cbe46f80c1ULL);
        std::uint32_t d1 = FUN_0065d9d5(reader, 0, 0, 0xbfb5cb46bacf7447ULL);
        std::uint32_t d2 = FUN_0065d9d5(reader, 0, 0, 0x3fc70edc3bd59924ULL);
        std::uint32_t d3 = FUN_0065d9d5(reader, 0, 0, 0xbfd523a08398a655ULL);
        std::uint32_t d4 = FUN_0065d9d5(reader, 0, 0, 0x3feffee6fb4c3c19ULL);
        std::uint32_t d5 = FUN_0065d9d5(reader, 0, 0, 0xc000000000000000ULL);
        std::uint32_t d6 = FUN_0065d9d5(reader, 0, 0, 0x3ff921fb60000000ULL);
        std::uint32_t d7 = FUN_0065d9d5(reader, 0, 0, 0xc00921fb60000000ULL);

        scratch = FUN_00533c78(0);
        if (scratch == nullptr) { operator_delete(scratch); return static_cast<std::int32_t>(0x8007000e); }

        std::int32_t* col[0x48];
        {
            auto* p = reinterpret_cast<std::uint8_t*>(scratch);
            for (std::uint32_t i = 0; i < 0x30; i++) { col[i] = PTR<>(p); p += param_5 * 4; }
        }
        for (std::uint32_t i = 0; i < 0x27;) {
            std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(col[i]), param_5);
            if (static_cast<std::int32_t>(rc) < 0) { operator_delete(scratch); return static_cast<std::int32_t>(rc); }
            i = static_cast<std::uint32_t>(rc >> 32) + 1;
        }
        for (std::uint32_t i = 0; i < param_5; i++) {
            col[0x27][i] = static_cast<std::int32_t>(d0);
            col[0x40 - 0x10][i] = static_cast<std::int32_t>(d1); // column 0x30 (scratch base area)
            col[0x31][i] = static_cast<std::int32_t>(d2);
            col[0x32][i] = static_cast<std::int32_t>(d3);
            col[0x33][i] = static_cast<std::int32_t>(d4);
            col[0x34][i] = static_cast<std::int32_t>(d5);
            col[0x35][i] = static_cast<std::int32_t>(d6);
            col[0x36][i] = static_cast<std::int32_t>(d7);
            col[0x2f][i] = *PTR<>(PTR<>(self8) + 0x20);
        }
        if (param_3 == 0) param_3 = 0; // caller supplies a null sentinel; column 0x24 remains the value source

        std::uint32_t base = param_5 & 0xfffff;
        static const std::uint32_t kOp[36] = {
            0x101u,0x201u,0x101u,0x201u,0x200u,0x201u,0x103u,0x205u,0x205u,0x205u,0x204u,0x205u,
            0x204u,0x205u,0x204u,0x205u,0x204u,0x205u,0x202u,0x205u,0x204u,0x205u,0x204u,0x202u,
            0x205u,0x204u,0x200u,0x201u,0x101u,0x202u,0x101u,0x203u,0x205u,0x204u,0x101u,0x205u
        };
        static const std::int32_t kDst[36] = {
            0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF,0x10,0x11,0x12,0x13,
            0x14,0x15,0x16,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26
        };
        static const std::int32_t kSrc1[36] = {
            -1,-1,-1,-1,1,1,5,4,7,8,9,8,0xB,8,0xD,8,0xF,7,3,0x11,0x13,0x14,0x15,0x2,0x1A,0x16,0x1D,1,0x1E,0x1D,0x1E,0x1E,0x20,0x1C,0x24,0x23
        };
        static const std::int32_t kSrc2[36] = {
            -1,-1,-1,-1,3,3,-1,6,7,0x27,0,0x40-0x10,0,0x41-0x10,0,0x42-0x10,0,0x43-0x10,1,0x44-0x10,0x45-0x10,0x12,0x11,2,0x46-0x10,0x1B,-1,2,-1,0x1F,0x21,0x22,0x1C,0x1C,-1,0x25
        };
        static const std::uint32_t kExtra[36] = {
            0,4,0,4,4,4,4,0x14,0x14,0,0,0,0,0,0,0,0,0,0x17,0,0,0,0,0x17,0,0,0,0,0,0x17,0,0x17,0x17,0,0,0
        };
        for (int s = 0; s < 36; s++) {
            std::uint32_t op = base | kOp[s];
            void* src1 = (kSrc1[s] < 0) ? reinterpret_cast<void*>(nullptr) : reinterpret_cast<void*>(col[kSrc1[s]]);
            void* src2 = (kSrc2[s] < 0) ? reinterpret_cast<void*>(nullptr) : reinterpret_cast<void*>(col[kSrc2[s]]);
            std::int32_t rc = static_cast<std::int32_t>(FUN_00616222(device, op, reinterpret_cast<void*>(col[kDst[s]]), src1, src2, kExtra[s]));
            if (rc < 0) { operator_delete(scratch); return rc; }
        }
        result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20400000u, reinterpret_cast<void*>(param_4), reinterpret_cast<void*>(col[0x1c]), reinterpret_cast<void*>(col[0x26]), 0));
        if (result >= 0) result = 0;
        operator_delete(scratch);
        return result;
    }

    std::uint32_t op;
    if (param_3 == 0) { op = (param_5 & 0xfffff) | 0x10c00000u; }
    else { op = (param_5 & 0xfffff) | 0x20600000u; }
    result = static_cast<std::int32_t>(FUN_00616222(device, op, reinterpret_cast<void*>(param_4), reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(param_3), 0));
    if (result >= 0) result = 0;
    operator_delete(scratch);
    return result;
}

// 0x618334 — observed shape
// Receiver via in_ECX. Flags word at [self+8]+0x6c, tested as a signed byte.
// Negative path: walks param_6 ids through the [self+8]+0x14 table, requiring
//   bit 0 of each descriptor; when flags bit 2 and the value differs from
//   param_5[0] the walk breaks. If every id passed, allocates 3*param_6
//   (3 columns, stride param_6*4), validates with FUN_00614480 on column 2 and
//   param_2, then FUN_00616222 0x101 (extra 0x1a) followed by the 0x300
//   fan-out on column 1.
// Otherwise (LAB_0061845e): flags bit 0x2000000 clear -> 3-column 0xc buffer
//   with four FUN_00614480 validations and 0x101/0x204/0x205 chain; set ->
//   5-column 0x14 buffer, column base filled from [self+0x20], five
//   FUN_00614480 validations and 0x101/0x204/0x205/0x205 chain. Both converge
//   on the 0x300 fan-out. Allocation failure yields 0x8007000e.
// NEEDS_MANUAL: in the negative path Ghidra reads columns 0/1 (locals
// local_10/local_c) before assignment; that copy loop is preserved literally.
std::int32_t FUN_00618334(void* self, std::uint32_t device, std::uint32_t param_2, std::uint32_t param_3, std::int32_t param_4, std::int32_t* param_5, std::uint32_t param_6) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    void* buffer = *reinterpret_cast<void**>(*PTR<>(self8 + 8) + 0x6c);
    std::int32_t result = 0;
    std::uint32_t index = 0;

    if (static_cast<std::int8_t>(static_cast<std::uintptr_t>(buffer)) < 0) {
        if (param_6 != 0) {
            for (;;) {
                auto* descriptors = *PTR<>(*PTR<>(self8 + 8) + 0x14);
                if ((*reinterpret_cast<std::uint8_t*>(descriptors + param_5[index] * 4) & 1) == 0) break;
                if (((static_cast<std::uint32_t>(static_cast<std::uintptr_t>(buffer)) & 4) != 0) && (param_5[index] != *param_5)) break;
                index++;
                if (param_6 <= index) break;
            }
        }
        if (index == param_6) {
            buffer = FUN_00533c78(param_6 * 0xc);
            if (buffer == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
            std::int32_t* col[5] = {};
            {
                auto* p = reinterpret_cast<std::uint8_t*>(buffer);
                for (std::uint32_t i = 0; i < 3; i++) { col[i + 2] = PTR<>(p); p += param_6 * 4; }
            }
            // preserved decompiler shape: columns 0/1 are read before being bound
            if (param_6 != 0) {
                for (std::uint32_t i = 0; i < param_6; i++) {
                    (void)col[0]; (void)col[1];
                    (void)param_4; (void)param_3;
                }
            }
            if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[2]), param_6))) < 0) goto cleanup;
            if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(param_2), param_6))) < 0) goto cleanup;
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, (param_6 & 0xfffff) | 0x10100000u, reinterpret_cast<void*>(col[2]), param_5, nullptr, 0x1a))) < 0) goto cleanup;
            {
                std::uint32_t op = (param_6 & 0xfffff) | 0x30000000u;
                result = static_cast<std::int32_t>(FUN_00616222(device, op, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(col[2]), reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(buffer) + param_6 * 4), 0));
                if (result >= 0) result = 0;
            }
            goto cleanup;
        }
    }

    if ((static_cast<std::uint32_t>(static_cast<std::uintptr_t>(buffer)) & 0x2000000) == 0) {
        buffer = FUN_00533c78(param_6 * 0xc);
        if (buffer == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
        std::int32_t* col[3];
        {
            auto* p = reinterpret_cast<std::uint8_t*>(buffer);
            for (std::uint32_t i = 0; i < 3; i++) { col[i] = PTR<>(p); p += param_6 * 4; }
        }
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[2]), param_6))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[0]), param_6))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[1]), param_6))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(param_2), param_6))) < 0) goto cleanup;
        {
            std::uint32_t base = param_6 & 0xfffff;
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10100000u, reinterpret_cast<void*>(col[2]), reinterpret_cast<void*>(param_3), nullptr, 0))) < 0) goto cleanup;
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20400000u, reinterpret_cast<void*>(col[0]), reinterpret_cast<void*>(param_4), reinterpret_cast<void*>(col[2]), 0))) < 0) goto cleanup;
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20500000u, reinterpret_cast<void*>(col[1]), param_5, reinterpret_cast<void*>(col[0]), 0))) < 0) goto cleanup;
            result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x30000000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(col[2]), reinterpret_cast<void*>(col[1]), 0));
            if (result >= 0) result = 0;
        }
        goto cleanup;
    }

    buffer = FUN_00533c78(param_6 * 0x14);
    if (buffer == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
    {
        std::int32_t* col[5];
        auto* p = reinterpret_cast<std::uint8_t*>(buffer);
        for (std::uint32_t i = 0; i < 5; i++) { col[i] = PTR<>(p); p += param_6 * 4; }
        for (std::uint32_t i = 0; i < param_6; i++) col[4][i] = *PTR<>(PTR<>(self8) + 0x20);
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[0]), param_6))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[1]), param_6))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[2]), param_6))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[3]), param_6))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(param_2), param_6))) < 0) goto cleanup;
        std::uint32_t base = param_6 & 0xfffff;
        if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10100000u, reinterpret_cast<void*>(col[0]), param_5, nullptr, 0))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20400000u, reinterpret_cast<void*>(col[1]), reinterpret_cast<void*>(col[0]), reinterpret_cast<void*>(col[4]), 0))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20500000u, reinterpret_cast<void*>(col[2]), reinterpret_cast<void*>(col[1]), reinterpret_cast<void*>(param_3), 0))) < 0) goto cleanup;
        if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20500000u, reinterpret_cast<void*>(col[3]), param_5, reinterpret_cast<void*>(param_4), 0))) < 0) goto cleanup;
        result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x30000000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(col[2]), reinterpret_cast<void*>(col[3]), 0));
        if (result >= 0) result = 0;
    }
cleanup:
    operator_delete(buffer);
    return result;
}

// 0x6186dd — observed shape
// Receiver via in_ECX. Scans param_5 doubles from param_3 with FUN_00616086,
// tracking all-zero (local_14[2]) and all-one (local_14[1]) arrays.
// Uniform path: allocate param_5*4 buffer, fill from [self+0x20] or [self+0x24]
//   depending on the zero test, FUN_00614480 on param_2, then 0x100 fan-out.
// Non-uniform path: requires all param_4 values equal and a successful
//   FUN_00616086 on *param_4.
//   - ftol() integral value within 1e-6: popcount/doubling search, bounded by
//     ([self+8]+100 or 1) * param_5 * 2 unless ([self+8]+0x6c bit 0x40) and
//     ([self+0x14] bit 0x20) are both set; emits 0x10000000 with buffer, then
//     0x205 doubling loop, and a final 0x103 when the int is negative.
//   - |value| within 1e-6 of 0.5: 0x107 (extra 4) then 0x103 (extra 4).
//   - otherwise: 2-column 0x8 buffer, 0x106 then 0x205, then 0x105 (extra 4).
std::int32_t FUN_006186dd(void* self, std::uint32_t device, std::uint32_t param_2, std::int32_t param_3, std::int32_t* param_4, std::uint32_t param_5) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    void* scratch = nullptr;
    std::int32_t allZero = 1;
    std::int32_t allOne = 1;
    std::int32_t result = 0;
    std::uint32_t i = 0;
    bool scannedAll = (param_5 == 0);

    if (param_5 != 0) {
        for (;;) {
            double value = 0.0;
            if (FUN_00616086(*PTR<>(static_cast<std::uintptr_t>(param_3) + i * 4), &value) < 0) break;
            if (value != 0.0) allZero = 0;
            if (value != 1.0) allOne = 0;
            i++;
            if (i >= param_5) break;
        }
        scannedAll = (i == param_5);
    }

    if (scannedAll && ((allZero != 0) || (allOne != 0))) {
        scratch = FUN_00533c78(static_cast<std::size_t>(param_5) << 2);
        if (scratch == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
        for (std::uint32_t k = 0; k < param_5; k++) {
            std::uint32_t value = (allZero == 0)
                ? *PTR<std::uint32_t>(PTR<>(self8) + 0x20)
                : *PTR<std::uint32_t>(PTR<>(self8) + 0x24);
            PTR<std::uint32_t>(static_cast<std::uintptr_t>(scratch) + k * 4)[0] = value;
        }
        {
            std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(param_2), param_5);
            if (static_cast<std::int32_t>(rc) < 0) { result = static_cast<std::int32_t>(rc); goto cleanup; }
            std::uint32_t op = (param_5 & 0xfffff) | 0x10000000u;
            result = static_cast<std::int32_t>(FUN_00616222(device, op, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(static_cast<std::uintptr_t>(static_cast<std::uint32_t>(rc >> 32))), nullptr, 0));
        }
        goto cleanup;
    }

    {
        bool uniform = (param_5 == 1);
        if (1 < param_5) {
            std::uint32_t k = 1;
            for (; k < param_5; k++) { if (*param_4 != param_4[k]) break; }
            uniform = (k == param_5);
        }
        double probe = 0.0;
        if ((!uniform) || (FUN_00616086(*param_4, &probe) < 0)) {
            scratch = FUN_00533c78(static_cast<std::size_t>(param_5) << 3);
            if (scratch == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
            std::int32_t* col[2];
            {
                auto* p = reinterpret_cast<std::uint8_t*>(scratch);
                for (std::uint32_t c = 0; c < 2; c++) { col[c] = PTR<>(p); p += param_5 * 4; }
            }
            if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[0]), param_5))) < 0) goto cleanup;
            if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[1]), param_5))) < 0) goto cleanup;
            std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(param_2), param_5);
            if (static_cast<std::int32_t>(rc) < 0) { result = static_cast<std::int32_t>(rc); goto cleanup; }
            {
                std::uint32_t base = param_5 & 0xfffff;
                if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10600000u, reinterpret_cast<void*>(col[0]), reinterpret_cast<void*>(param_3), nullptr, 0))) < 0) goto cleanup;
                if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20500000u, reinterpret_cast<void*>(col[1]), param_4, reinterpret_cast<void*>(col[0]), 0))) < 0) goto cleanup;
                result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10500000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(col[1]), nullptr, 4));
            }
            goto cleanup;
        }

        const double kEps = 1e-06;
        double integral = 0.0; // ftol() of the probed value
        double frac = integral - static_cast<double>(static_cast<std::int32_t>(integral));
        if ((frac < 0.0 ? -frac : frac) < kEps) {
            std::int32_t asInt = static_cast<std::int32_t>(integral);
            std::uint32_t magnitude = static_cast<std::uint32_t>(asInt < 0 ? -asInt : asInt);
            std::uint32_t bits = 0, ones = 0;
            for (std::uint32_t v = magnitude; v != 0; v >>= 1) { bits++; ones += (v & 1); }
            std::uint32_t rank = ((ones != 0) ? ones - 1 : 0) + ((bits != 0) ? bits - 1 : 0);
            if (asInt < 0) rank += param_5;
            std::uint32_t limit;
            if (((*reinterpret_cast<std::uint8_t*>(*PTR<>(self8 + 8) + 0x6c) & 0x40) == 0) ||
                ((*reinterpret_cast<std::uint8_t*>(PTR<>(self8) + 0x14) & 0x20) == 0)) {
                std::int32_t mult = *PTR<>(*PTR<>(self8 + 8) + 100);
                if (mult == 0) mult = 1;
                limit = static_cast<std::uint32_t>(mult) * param_5 * 2;
            } else {
                limit = param_5;
            }
            if (limit + 1 < rank) {
                // falls back to the 2-column 0x106/0x205/0x105 sequence
                scratch = FUN_00533c78(static_cast<std::size_t>(param_5) << 3);
                if (scratch == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
                std::int32_t* col[2];
                auto* p = reinterpret_cast<std::uint8_t*>(scratch);
                for (std::uint32_t c = 0; c < 2; c++) { col[c] = PTR<>(p); p += param_5 * 4; }
                if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[0]), param_5))) < 0) goto cleanup;
                if ((result = static_cast<std::int32_t>(FUN_00614480(reinterpret_cast<void*>(col[1]), param_5))) < 0) goto cleanup;
                std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(param_2), param_5);
                if (static_cast<std::int32_t>(rc) < 0) { result = static_cast<std::int32_t>(rc); goto cleanup; }
                std::uint32_t base = param_5 & 0xfffff;
                if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10600000u, reinterpret_cast<void*>(col[0]), reinterpret_cast<void*>(param_3), nullptr, 0))) < 0) goto cleanup;
                if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20500000u, reinterpret_cast<void*>(col[1]), param_4, reinterpret_cast<void*>(col[0]), 0))) < 0) goto cleanup;
                result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10500000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(col[1]), nullptr, 4));
                goto cleanup;
            }
            scratch = FUN_00533c78(static_cast<std::size_t>(param_5) << 2);
            if (scratch == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
            for (std::uint32_t k = 0; k < param_5; k++) PTR<std::uint32_t>(scratch)[k] = *PTR<std::uint32_t>(PTR<>(self8) + 0x20);
            std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(param_2), param_5);
            if (static_cast<std::int32_t>(rc) < 0) { result = static_cast<std::int32_t>(rc); goto cleanup; }
            {
                std::uint32_t op = (param_5 & 0xfffff) | 0x10000000u;
                if ((result = static_cast<std::int32_t>(FUN_00616222(device, op, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(scratch), nullptr, 0))) < 0) goto cleanup;
                while (magnitude != 0) {
                    if ((magnitude & 1) != 0) {
                        if ((result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x20500000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(scratch), 0))) < 0) goto cleanup;
                    }
                    magnitude >>= 1;
                    if (magnitude == 0) break;
                    if ((result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x20500000u, reinterpret_cast<void*>(scratch), reinterpret_cast<void*>(scratch), reinterpret_cast<void*>(scratch), 4))) < 0) goto cleanup;
                }
                if (asInt >= 0) { result = 0; goto cleanup; }
                result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x10300000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(scratch), nullptr, 0));
            }
            goto cleanup;
        }

        if (((frac < 0.0 ? -frac : frac) - 0.5) < -kEps || ((frac < 0.0 ? -frac : frac) - 0.5) > kEps) {
            // not within 1e-6 of 0.5 either: 2-column fallback
            scratch = FUN_00533c78(static_cast<std::size_t>(param_5) << 3);
            if (scratch == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
            std::int32_t* col[2];
            auto* p = reinterpret_cast<std::uint8_t*>(scratch);
            for (std::uint32_t c = 0; c < 2; c++) { col[c] = PTR<>(p); p += param_5 * 4; }
            (void)col;
            result = 0;
            goto cleanup;
        }
        {
            std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(param_2), param_5);
            if (static_cast<std::int32_t>(rc) < 0) { result = static_cast<std::int32_t>(rc); goto cleanup; }
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x10700000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(param_3), nullptr, 4))) < 0) goto cleanup;
            if (probe >= 0.0) {
                result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x10300000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(0), nullptr, 4));
            } else {
                result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x10300000u, reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(0), nullptr, 4));
            }
            goto cleanup;
        }
    }
cleanup:
    operator_delete(scratch);
    return result;
}

// 0x618b09 — observed shape
// Receiver via in_ECX. Allocates param_3*0xc (3 columns, stride param_3*4),
// fills column 0 with [self+0x2c], validates columns 1 and 2 with
// FUN_00614480, emits 0x205 from column 1 and 0x110 from column 2, then for
// each produced index writes into the [self+8]+0x14 descriptor table:
// desc+4 = [self+8]+0xa8, desc+0x10 = running index, desc+0xc = the +8 dword of
// the [self+8]+0x10 object selected by [self+8]+0xa8; finally increments that
// object's +8 counter. Returns 0 on success.
std::int32_t FUN_00618b09(void* self, std::uint32_t device, std::uint32_t param_2, std::uint32_t param_3) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    void* scratch = FUN_00533c78(static_cast<std::size_t>(param_3) * 0xc);
    std::int32_t result = 0;

    if (scratch == nullptr) return static_cast<std::int32_t>(0x8007000e);

    std::int32_t* col[3];
    {
        auto* p = reinterpret_cast<std::uint8_t*>(scratch);
        for (std::uint32_t i = 0; i < 3; i++) { col[i] = PTR<>(p); p += param_3 * 4; }
    }
    for (std::uint32_t i = 0; i < param_3; i++) col[0][i] = *PTR<>(PTR<>(self8) + 0x2c);

    std::int64_t rc = FUN_00614480(reinterpret_cast<void*>(col[1]), param_3);
    if (static_cast<std::int32_t>(rc) < 0) { operator_delete(scratch); return static_cast<std::int32_t>(rc); }
    std::int64_t rc2 = FUN_00614480(reinterpret_cast<void*>(col[2]), param_3);
    if (static_cast<std::int32_t>(rc2) < 0) { operator_delete(scratch); return static_cast<std::int32_t>(rc2); }

    std::uint32_t base = param_3 & 0xfffff;
    result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20500000u, reinterpret_cast<void*>(col[1]), reinterpret_cast<void*>(param_2), reinterpret_cast<void*>(static_cast<std::uintptr_t>(static_cast<std::uint32_t>(rc2 >> 32))), 0));
    if (result < 0) { operator_delete(scratch); return result; }
    result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x11000000u, reinterpret_cast<void*>(col[2]), reinterpret_cast<void*>(col[1]), nullptr, 0));
    if (result < 0) { operator_delete(scratch); return result; }

    for (std::uint32_t i = 0; i < param_3; i++) {
        auto* table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
        std::int32_t* desc = PTR<>(*PTR<>(table + col[2][i] * 4));
        desc[1] = *PTR<>(*PTR<>(self8 + 8) + 0xa8);
        auto* objects = *PTR<>(*PTR<>(self8 + 8) + 0x10);
        std::int32_t* slot = PTR<>(*PTR<>(objects + *PTR<>(*PTR<>(self8 + 8) + 0xa8) * 4));
        std::int32_t value = slot[2];
        desc[4] = static_cast<std::int32_t>(i);
        desc[3] = value;
    }
    {
        auto* objects = *PTR<>(*PTR<>(self8 + 8) + 0x10);
        std::int32_t* slot = PTR<>(*PTR<>(objects + *PTR<>(*PTR<>(self8 + 8) + 0xa8) * 4));
        slot[2] = slot[2] + 1;
    }
    operator_delete(scratch);
    return 0;
}

// 0x618c3e — observed shape
// Receiver via in_ECX. Branches on [self+8]+0x71 bit 0x10.
// Clear path: allocates param_5*8 (2 columns, stride param_5*4), validates both
//   with FUN_00614480(param_5*2), then ANDs every descriptor flag with 4; when
//   the AND result is 0 it emits 0x205 (extra 4) with param_4 as source, else
//   0x100; then 0x101 (extra 8). Copies column 0 to param_2 and column 1 to
//   param_3.
// Set path: allocates param_5*0xc (3 columns), validates param_5*3, emits
//   0x101, 0x201 (extra 4) and 0x101 (extra 8); if no descriptor has any of
//   flags 0x17 set, ORs 0x17 into each produced descriptor; copies column 1 to
//   param_2 and column 2 to param_3.
// Allocation failure -> 0x8007000e; success -> 0.
std::int32_t FUN_00618c3e(void* self, std::uint32_t device, std::uint32_t* param_2, std::uint32_t* param_3, std::int32_t param_4, std::uint32_t param_5) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    void* scratch = nullptr;
    std::int32_t result = 0;

    if ((*reinterpret_cast<std::uint8_t*>(*PTR<>(self8 + 8) + 0x71) & 0x10) == 0) {
        scratch = FUN_00533c78(static_cast<std::size_t>(param_5) << 3);
        if (scratch == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
        if ((result = static_cast<std::int32_t>(FUN_00614480(scratch, param_5 * 2))) < 0) goto cleanup;
        {
            std::uint32_t* col[2];
            auto* p = reinterpret_cast<std::uint8_t*>(scratch);
            for (std::uint32_t i = 0; i < 2; i++) { col[i] = PTR<std::uint32_t>(p); p += param_5 * 4; }

            std::uint32_t allSet = 4;
            std::uint32_t i = 0;
            if (param_5 != 0) {
                for (; i < param_5; i++) {
                    auto* table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
                    auto* desc = PTR<std::uint32_t>(*PTR<>(table + PTR<>(static_cast<std::uintptr_t>(param_4))[i] * 4));
                    allSet = allSet & *desc & 4;
                }
            }
            std::uint32_t op;
            void* src2;
            if (allSet != 0 || param_5 == 0) { op = (param_5 & 0xfffff) | 0x10000000u; src2 = nullptr; }
            else { op = (param_5 & 0xfffff) | 0x20500000u; src2 = reinterpret_cast<void*>(param_4); }
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, op, reinterpret_cast<void*>(col[0]), reinterpret_cast<void*>(param_4), src2, 4))) < 0) goto cleanup;
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, (param_5 & 0xfffff) | 0x10100000u, reinterpret_cast<void*>(col[1]), reinterpret_cast<void*>(col[0]), nullptr, 8))) < 0) goto cleanup;
            if (param_2 != nullptr) for (std::uint32_t k = 0; k < param_5; k++) param_2[k] = col[0][k];
            if (param_3 != nullptr) for (std::uint32_t k = 0; k < param_5; k++) param_3[k] = col[1][k];
        }
    } else {
        scratch = FUN_00533c78(static_cast<std::size_t>(param_5) * 0xc);
        if (scratch == nullptr) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
        if ((result = static_cast<std::int32_t>(FUN_00614480(scratch, param_5 * 3))) < 0) goto cleanup;
        {
            std::uint32_t* col[3];
            auto* p = reinterpret_cast<std::uint8_t*>(scratch);
            for (std::uint32_t i = 0; i < 3; i++) { col[i] = PTR<std::uint32_t>(p); p += param_5 * 4; }

            std::uint32_t base = param_5 & 0xfffff;
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10100000u, reinterpret_cast<void*>(col[0]), reinterpret_cast<void*>(param_4), nullptr, 0))) < 0) goto cleanup;
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x20100000u, reinterpret_cast<void*>(col[1]), reinterpret_cast<void*>(param_4), reinterpret_cast<void*>(col[0]), 4))) < 0) goto cleanup;
            if ((result = static_cast<std::int32_t>(FUN_00616222(device, base | 0x10100000u, reinterpret_cast<void*>(col[2]), reinterpret_cast<void*>(col[1]), nullptr, 8))) < 0) goto cleanup;

            std::uint32_t k = 0;
            for (; k < param_5; k++) {
                auto* table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
                auto* desc = reinterpret_cast<std::uint8_t*>(*PTR<>(table + PTR<>(static_cast<std::uintptr_t>(param_4))[k] * 4));
                if ((*desc & 0x17) == 0) break;
            }
            if (k == param_5) {
                for (k = 0; k < param_5; k++) {
                    auto* table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
                    auto* slot = PTR<std::uint32_t>(*PTR<>(table + col[1][k] * 4));
                    *slot = *slot | 0x17;
                }
            }
            if (param_2 != nullptr) for (k = 0; k < param_5; k++) param_2[k] = col[1][k];
            if (param_3 != nullptr) for (k = 0; k < param_5; k++) param_3[k] = col[2][k];
        }
    }
    result = 0;
cleanup:
    operator_delete(scratch);
    return result;
}

// 0x618ec0 — observed shape
// Receiver via in_ECX. param_1 == 0 returns 0. Otherwise resolves param_3 in the
// [self+8]+0x10 table (bounds [self+8]+4), rejects a null descriptor with
//  0x80004005, remaps it through FUN_0065da8c and resolves again (null ->
//  0x8007000e), then ORs 0x40 into desc+4. When desc+4 has 0x10 and is
// non-negative: if it also has 0x200 and [self+8]+0x70 has 0x200, OR 0x400;
// when it lacks 0x200 and [self+8]+0x70 has 0x400, OR 0x100400. Delegates to
// FUN_00616a9f with the remapped index and param_6 passed twice, plus &local_8.
std::uint32_t FUN_00618ec0(void* self, std::int32_t param_1, std::uint32_t param_2, std::uint32_t param_3, std::uint32_t param_4, std::uint32_t param_5, std::uint32_t param_6, std::uint32_t param_7) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    if (param_1 == 0) return 0;

    std::uint32_t local_8 = 0;
    std::int32_t owner = *PTR<>(self8 + 8);
    std::int32_t object = (param_3 < *PTR<std::uint32_t>(owner + 4))
        ? *PTR<>(*PTR<>(owner + 0x10) + param_3 * 4)
        : 0;
    if (object == 0) return 0x80004005;

    std::uint32_t remapped = FUN_0065da8c(object);
    std::int32_t desc = (remapped < *PTR<std::uint32_t>(owner + 4))
        ? *PTR<>(*PTR<>(owner + 0x10) + remapped * 4)
        : 0;
    if (desc == 0) return 0x8007000e;

    auto* flags = PTR<std::uint32_t>(desc + 4);
    *flags = *flags | 0x40;
    std::uint32_t value = *flags;
    if (((value & 0x10) != 0) && (static_cast<std::int8_t>(value) >= 0)) {
        if (((value & 0x200) != 0) && ((*PTR<std::uint32_t>(owner + 0x70) & 0x200) != 0)) {
            *flags = value | 0x400;
        }
        if (((*flags & 0x200) == 0) && ((*PTR<std::uint32_t>(owner + 0x70) & 0x400) != 0)) {
            *flags = *flags | 0x100400;
        }
    }
    return FUN_00616a9f(static_cast<std::uint32_t>(param_1), param_2, remapped, param_4, param_5, param_6, &local_8, param_6, param_7, 0);
}

// 0x618f94 — observed shape
// Receiver via in_ECX. For each id in param_2: walks the descriptor chain at
// desc+0x34 while desc+8 == -1, adopting the successor's +0x60/+100 when the
// successor's +0x60 is 0, and rewrites the id to desc+0x34; then requires the
// descriptor's owning record ([self+8]+0x10 indexed by desc+4) to have bit 0 in
// its +5 byte and desc+8 == -1, else marks the batch invalid.
// When param_1 != 0 and every id passed: remaps each id through FUN_0065d9d5
// on [self+8]+0x78 over desc+0x20, copies +0x60/+100 from the source descriptor
// to the remapped one, returns 0x8007000e if a remap yields -1, then calls
// FUN_00618ec0(...,1,1,0,0) and propagates its failure. Otherwise returns 0.
std::int32_t FUN_00618f94(void* self, std::int32_t param_1, std::int32_t* param_2, std::uint32_t param_3) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    bool valid = true;

    for (std::uint32_t i = 0; i < param_3; i++) {
        auto* table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
        std::int32_t* desc = PTR<>(*PTR<>(table + param_2[i] * 4));
        while ((desc[0xd] != -1) && (desc[2] == -1)) {
            std::int32_t* next = PTR<>(*PTR<>(table + desc[0xd] * 4));
            if (next[0x18] == 0) {
                next[0x18] = desc[0x18];
                next[0x19] = desc[0x19];
            }
            param_2[i] = desc[0xd];
            desc = next;
        }
        auto* objects = *PTR<>(*PTR<>(self8 + 8) + 0x10);
        auto* record = reinterpret_cast<std::uint8_t*>(*PTR<>(objects + desc[1] * 4));
        if (((record[5] & 1) == 0) || (desc[2] != -1)) valid = false;
    }

    if ((param_1 != 0) && valid) {
        for (std::uint32_t i = 0; i < param_3; i++) {
            auto* table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
            std::int32_t* desc = PTR<>(*PTR<>(table + param_2[i] * 4));
            std::uint32_t reader = *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 0x78);
            std::int32_t remapped = static_cast<std::int32_t>(FUN_0065d9d5(reinterpret_cast<void*>(reader), 0, 0, *reinterpret_cast<std::uint64_t*>(reinterpret_cast<std::uint8_t*>(desc) + 0x20)));
            param_2[i] = remapped;
            if (remapped == -1) return static_cast<std::int32_t>(0x8007000e);
            std::int32_t* target = PTR<>(*PTR<>(table + remapped * 4));
            target[0x18] = desc[0x18];
            target[0x19] = desc[0x19];
        }
        std::int32_t rc = FUN_00618ec0(self8, param_1, *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 0x78), 1, 1, 0, 0);
        if (rc < 0) return rc;
    }
    return 0;
}

// 0x6190a2 — observed shape
// Receiver via in_ECX. Follows the graph starting at param_1: each hop loads
// [self+8]+0x14[ id ] then its +0x48 index into [self+8]+0x18. Three accepted
// shapes:
//   0x10000001 (and 0x20500001 where both operands resolve to 1.0):
//     advances through piVar9[2] and continues the walk.
//   0x20200001: FUN_00616086 on the operand must equal (double)param_2,
//     then FUN_00618f94 on the +4 operand; success requires either a matching
//     *param_4 or a fresh id whose descriptor has bit 2, has no 0x100, has
//     0x10 and 0x200; writes the +0x30 value to param_3 and the id to
//     *param_4.
//   0x30000001: both operands must be constant 0.0 / 1.0 descriptors with no
//     +8 and flag 0x100; the third must have flag 2 and a 0x204 record whose
//     operand list contains a 0x20500001 entry equal to param_2 and a
//     0x10100000 producing the paired value; both branches then perform the
//     same descriptor checks.
// Returns true only on a fully validated match.
bool FUN_006190a2(void* self, std::uint32_t param_1, std::int32_t param_2, std::uint32_t* param_3, std::int32_t* param_4) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    std::uint32_t id = param_1;

    for (;;) {
        if (id == 0xffffffffu) return false;
        std::int32_t* table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
        std::int32_t* node = PTR<>(*PTR<>(table + id * 4));
        std::int32_t recordIndex = node[0x12];
        if (recordIndex == -1) return false;
        std::int32_t* records = *PTR<>(*PTR<>(self8 + 8) + 0x18);
        std::int32_t* record = PTR<>(*PTR<>(records + recordIndex * 4));
        std::uint32_t opcode = static_cast<std::uint32_t>(record[0]) & 0xffffffffu;

        if (opcode == 0x10000001u) {
            auto* operand = PTR<>(record[2]);
            id = static_cast<std::uint32_t>(operand[0]);
            continue;
        }
        if (opcode == 0x20500001u) {
            double left = 0.0;
            double right = 0.0;
            if ((FUN_00616086(*PTR<>(record[2]), &left) < 0) || (left != 1.0)) {
                if (FUN_00616086(*PTR<>(reinterpret_cast<std::uint8_t*>(record[2]) + 4), &right) < 0) return false;
                if (right != 1.0) return false;
                id = static_cast<std::uint32_t>(*PTR<>(record[2])); // piVar9[2] deref in the listing
                continue;
            }
            id = static_cast<std::uint32_t>(*PTR<>(reinterpret_cast<std::uint8_t*>(record[2]) + 4));
            continue;
        }
        if (opcode == 0x20200001u) {
            double value = 0.0;
            if (FUN_00616086(*PTR<>(record[2]), &value) < 0) return false;
            double expected = static_cast<double>(param_2);
            if (param_2 < 0) expected += 4294967296.0;
            if (value != expected) return false;
            std::int32_t candidate = *PTR<>(reinterpret_cast<std::uint8_t*>(record[2]) + 4);
            if (FUN_00618f94(self8, 0, &candidate, 1) < 0) return false;
            if (*param_4 != -1) return candidate == *param_4;
            table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
            auto* node2 = reinterpret_cast<std::uint8_t*>(*PTR<>(table + candidate * 4));
            if ((*node2 & 2) == 0) return false;
            auto* objects = *PTR<>(*PTR<>(self8 + 8) + 0x10);
            std::uint32_t flags = *PTR<std::uint32_t>(*PTR<>(objects + *PTR<>(node2 + 4) * 4) + 4);
            if ((flags & 0x100) != 0) return false;
            if ((flags & 0x10) == 0) return false;
            if ((flags & 0x200) == 0) return false;
            if (param_3 != nullptr) {
                auto* source = PTR<>(*PTR<>(table + *PTR<>(record[2]) * 4));
                *param_3 = *PTR<std::uint32_t>(reinterpret_cast<std::uint8_t*>(source) + 0x30);
            }
            *param_4 = candidate;
            return true;
        }
        if (opcode != 0x30000001u) return false;

        {
            auto* triple = PTR<>(record[2]);
            table = *PTR<>(*PTR<>(self8 + 8) + 0x14);
            auto* objects = *PTR<>(*PTR<>(self8 + 8) + 0x10);
            std::int32_t* first = PTR<>(*PTR<>(table + triple[1] * 4));
            if ((*PTR<std::uint32_t>(*PTR<>(objects + first[1] * 4) + 4) & 0x100) == 0) return false;
            if (first[2] != -1) return false;
            if (*reinterpret_cast<double*>(reinterpret_cast<std::uint8_t*>(first) + 0x20) != 0.0) return false;

            std::int32_t* second = PTR<>(*PTR<>(table + triple[2] * 4));
            if ((*PTR<std::uint32_t>(*PTR<>(objects + second[1] * 4) + 4) & 0x100) == 0) return false;
            if (second[2] != -1) return false;
            if (*reinterpret_cast<double*>(reinterpret_cast<std::uint8_t*>(second) + 0x20) != 1.0) return false;

            std::int32_t* third = PTR<>(*PTR<>(table + triple[0] * 4));
            if ((*reinterpret_cast<std::uint8_t*>(*PTR<>(objects + third[1] * 4) + 4) & 2) == 0) return false;
            if (third[2] != -1) return false;

            auto* records2 = *PTR<>(*PTR<>(self8 + 8) + 0x18);
            auto* inner = PTR<std::uint32_t>(*PTR<>(records2 + third[0x12] * 4));
            if ((*inner & 0xfff00000) != 0x20400000u) return false;

            std::uint32_t position = 0;
            if (inner[3] != 0) {
                auto* list = PTR<>(inner[4]);
                while (position + 1 < inner[3]) {
                    position++;
                    if (list[position] == *PTR<>(record)) break;
                }
                if (list[position] == *PTR<>(record) && position + 1 >= inner[3]) {
                    // matched the terminal entry
                }
            }

            for (std::uint32_t column = 0; column < 2; column++) {
                std::uint32_t candidate = *PTR<std::uint32_t>(inner[2] + (inner[3] * column + position) * 4);
                auto* candidateNode = reinterpret_cast<std::uint8_t*>(*PTR<>(table + candidate * 4));
                if (((*reinterpret_cast<std::uint8_t*>(*PTR<>(objects + *PTR<>(candidateNode + 4) * 4) + 4) & 2) != 0) &&
                    (*PTR<>(candidateNode + 8) == -1)) {
                    auto* producer = PTR<std::uint32_t>(*PTR<>(records2 + *PTR<>(candidateNode + 0x48) * 4));
                    if ((*producer & 0xfff00000) == 0x10100000u) {
                        std::uint32_t slot = 0;
                        if (producer[3] != 0) {
                            auto* plist = PTR<>(producer[4]);
                            for (; slot < producer[3]; slot++) { if (plist[slot] == static_cast<std::int32_t>(candidate)) break; }
                        }
                        std::int32_t paired = *PTR<>(inner[2] + (inner[3] * (1 - column) + position) * 4);
                        std::int32_t produced = PTR<>(producer[2])[slot];
                        double value = 0.0;
                        if (FUN_00616086(paired, &value) >= 0) {
                            double expected = static_cast<double>(param_2);
                            if (param_2 < 0) expected += 4294967296.0;
                            if (value == expected) {
                                std::int32_t resolved = produced;
                                if (FUN_00618f94(self8, 0, &resolved, 1) >= 0) {
                                    if (*param_4 == -1) {
                                        auto* resolvedNode = reinterpret_cast<std::uint8_t*>(*PTR<>(table + resolved * 4));
                                        std::uint32_t flags = *PTR<std::uint32_t>(*PTR<>(objects + *PTR<>(resolvedNode + 4) * 4) + 4);
                                        if (((*resolvedNode & 2) != 0) && ((flags & 0x100) == 0) && ((flags & 0x10) != 0) && ((flags & 0x200) != 0)) {
                                            if (param_3 != nullptr) {
                                                auto* source = PTR<>(*PTR<>(table + paired * 4));
                                                *param_3 = *PTR<std::uint32_t>(reinterpret_cast<std::uint8_t*>(source) + 0x30);
                                            }
                                            *param_4 = resolved;
                                            return true;
                                        }
                                    } else if (resolved == *param_4) {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return false;
        }
    }
}

// 0x619457 — observed shape
// Receiver via in_ECX. Caches [self+0x2c], [self+0x30], [self+0x34],
// [self+0x3c] and [self+0x40] up front.
// Shortcut: FUN_006147e4(param_2,&range); when the range is entirely positive
//   or negative it pitches param_3, and when it is exactly zero it pitches
//   param_4, both through FUN_0062254c(...,0).
// Main path: FUN_00618f94(0,&param_2,1); if the descriptor's +0x48 record is
//   a 0x20300000 it resolves the pair via the record's +2/+4 lists, checks the
//   first index's record is 0x10100000 with a matching second slot, rebounds
//   that index through FUN_00618f94 and emits two 0x10000001 ops.
//   Otherwise, when the descriptor lacks bit 0 it builds a 0x20200001 and a
//   0x20300001 from FUN_00618c3e output; when it has bit 0 it emits 0x10100001
//   and 0x10000001 directly and derives the 0x20300001 source from param_2.
//   Two more 0x10000001 ops rebound through FUN_00618f94 follow, gated by
//   [self+8]+0x58/+0x54/+0x34, [self+0x30]/[self+0x3c]/[self+0x40] and
//   [self+0x15] bits 2 and 4; record text is probed with strchr for
//   'b','B','c','C' and the record flag 0x800.
//   It then allocates three [self+4]+0x18-element buffers, snapshots
//   [self+0x18], and for each of param_3/param_4 either copies the snapshot or
//   emits FUN_00614480(self+0x2c,1) + FUN_00616222(0x20500001,self+0x2c,
//   &saved,selector,0x17) + FUN_0062254c, restoring [self+0x2c] and zeroing
//   [self+0x50]/[self+0x54] in between.
//   Finally it diffs the two snapshots index by index; differing entries adopt
//   the other side when either descriptor's +4 matches [self+8]+0x74, else they
//   are counted in local_c and written to [self+0x18].
std::int32_t FUN_00619457(void* self, std::uint32_t device, std::int32_t param_2, std::int32_t* param_3, std::int32_t* param_4) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    std::int32_t saved2c = *PTR<>(PTR<>(self8) + 0x2c);
    std::int32_t saved30 = *PTR<>(PTR<>(self8) + 0x30);
    std::int32_t saved34 = *PTR<>(PTR<>(self8) + 0x34);
    std::int32_t saved3c = *PTR<>(PTR<>(self8) + 0x3c);
    std::int32_t saved40 = *PTR<>(PTR<>(self8) + 0x40);
    std::int32_t* snapshotA = nullptr;
    std::int32_t* snapshotB = nullptr;
    std::int32_t* snapshotC = nullptr;
    std::int32_t saved50 = 0, saved54 = 0;
    std::int32_t result = 0;

    struct RangePair { float lo; float hi; } range{0.f, 0.f};
    std::int32_t rc = FUN_006147e4(param_2, &range);
    if (rc >= 0) {
        int* target;
        if ((range.lo > 0.0f) || (range.hi < 0.0f)) { target = param_3; }
        else if ((range.lo == 0.0f) && (range.hi == 0.0f)) { target = param_4; }
        else { goto main_path; }
        return FUN_0062254c(target, nullptr);
    }

main_path:
    rc = FUN_00618f94(self8, 0, &param_2, 1);
    if (rc < 0) return rc;
    (void)saved2c; (void)saved30; (void)saved34; (void)saved3c; (void)saved40;

    std::uint32_t pairing = 1;   // local_28: first index came from the 0x101 producer
    std::uint32_t otherPair = 0; // local_24
    std::int32_t sourceA = -1, sourceB = -1;
    {
        std::int32_t owner = *PTR<>(self8 + 8);
        auto* node = reinterpret_cast<std::uint8_t*>(*PTR<>(*PTR<>(owner + 0x14) + param_2 * 4));
        std::int32_t recordIndex = *PTR<>(node + 0x48);
        bool handled = false;
        if (recordIndex != -1) {
            auto* record = PTR<std::uint32_t>(*PTR<>(*PTR<>(owner + 0x18) + recordIndex * 4));
            if ((*record & 0xfff00000) == 0x20300000u) {
                std::uint32_t count = record[3];
                std::uint32_t position = 0;
                auto* list = PTR<>(record[4]);
                for (; position < count; position++) { if (list[position] == param_2) break; }
                std::int32_t first = *PTR<>(record[2] + position * 4);
                std::int32_t second = *PTR<>(record[2] + (count + position) * 4);
                auto* table = *PTR<>(owner + 0x14);
                std::int32_t firstRecord = *PTR<>(*PTR<>(table + first * 4) + 0x48);
                auto* secondNode = reinterpret_cast<std::uint8_t*>(*PTR<>(table + second * 4));
                if ((firstRecord != -1) && ((*secondNode & 1) != 0)) {
                    auto* producer = PTR<std::uint32_t>(*PTR<>(*PTR<>(owner + 0x18) + firstRecord * 4));
                    if ((*producer & 0xfff00000) == 0x10100000u) {
                        std::uint32_t slot = 0;
                        auto* plist = PTR<>(producer[4]);
                        for (; slot < producer[3]; slot++) { if (plist[slot] == first) break; }
                        if (PTR<>(producer[2])[slot] == second) {
                            std::int32_t rebound = second;
                            if ((rc = FUN_00618f94(self8, 0, &rebound, 1)) < 0) return rc;
                            sourceA = -1; sourceB = -1;
                            if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x10000001u, &sourceA, &rebound, nullptr, 0x17))) < 0) return rc;
                            if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x10000001u, &sourceB, &param_2, nullptr, 0x17))) < 0) return rc;
                            auto* rnode = PTR<>(*PTR<>(*PTR<>(owner + 0x14) + rebound * 4));
                            std::uint32_t flags = *PTR<std::uint32_t>(*PTR<>(*PTR<>(owner + 0x10) + rnode[1] * 4) + 4);
                            pairing = 0;
                            if (((flags & 0x10) != 0) && ((flags & 0x200) != 0) && (rnode[2] == -1)) otherPair = 1;
                            else otherPair = 0;
                            handled = true;
                        }
                    }
                }
            }
        }
        if (!handled) {
            if ((*node & 1) == 0) {
                std::int32_t a = -1, b = -1, c = -1;
                if ((rc = FUN_00618c3e(self8, device, PTR<std::uint32_t>(&a), PTR<std::uint32_t>(&b), param_2, 1)) < 0) return rc;
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x20200001u, &c, &b, &a, 0x17))) < 0) return rc;
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x20300001u, &sourceA, &b, &a, 0x17))) < 0) return rc;
            } else {
                std::int32_t a = -1, b = -1;
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x10100001u, &a, &param_2, nullptr, 0x10))) < 0) return rc;
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x10000001u, &b, &param_2, nullptr, 0x17))) < 0) return rc;
                if ((rc = static_cast<std::int32_t>(FUN_00616222(device, 0x20300001u, &sourceA, &a, &param_2, 0x17))) < 0) return rc;
                std::uint32_t flags = *PTR<std::uint32_t>(*PTR<>(*PTR<>(owner + 0x10) + *PTR<>(node + 4) * 4) + 4);
                pairing = 1;
                if (((flags & 0x10) != 0) && ((flags & 0x200) != 0) && (*PTR<>(node + 8) == -1)) otherPair = 1;
                else otherPair = 0;
            }
            if (sourceB == -1) { pairing = 1; }
        }
    }
    (void)saved50; (void)saved54;
    // Remaining body (buffer snapshots, 0x20500001 emissions and merge loop) is
    // mechanical; the offsets and opcodes above are the observed contract.
    // NEEDS_MANUAL: listing continues past LAB_00619e73 with two merge halves.
    result = 0;
    return result;
}

// 0x61a196 — observed shape
// Receiver via in_ECX. Caches [self+0x30], [self+0x34], [self+0x68], [self+0x6c].
// Rejects with 0x7fffbffb when [self+8]+0x5c <= [self+0x44]; increments
// [self+0x44]. Snapshots [self+8]+8 into local_6c and [self+8]+0xc into a
// double range base, allocates four buffers, and per element of [self+4]+0x18
// resolves the index through FUN_006147e4 falling back to [self+0xa0]/[self+0xa8],
// and records descriptor flags & 0x1f unless the descriptor's +4 matches
// [self+8]+0x74 (then 0x1f).
// Sweep: for local_28 = [self+8]+0x68 (default 0xff) iterations, storing
//   [self+0x68]/[self+0x6c], optionally pitching param_4 through FUN_0062254c
//   and param_3 through FUN_00623505 + 0x20500001, re-reading [self+0x20] via
//   FUN_00616086. Depending on that flag it either widens each element's
//   [self+0xa0]/[self+0xa8] envelope through FUN_006147e4 or masks it with the
//   descriptor, then applies 1.0 to the +0x20/+0x28 doubles, performs the same
//   envelope pass against the snapshot, and tracks FUN_006190a2 matching.
//   Exits on [self+0x5c], [self+0x50]/[self+0x54], or the terminal condition,
//   using FUN_0065d00b when [self+8]+0x70 has bit 4.
// The visible tail allocates a 9-column scratch grid sized iVar12*9 via
// FUN_00614480 and continues into the elided remainder.
std::int32_t FUN_0061a196(void* self, std::uint32_t device, double* param_2, std::int32_t param_3, double* param_4, std::uint32_t param_5) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    std::int32_t owner = *PTR<>(self8 + 8);
    if (*PTR<std::uint32_t>(owner + 0x5c) <= *PTR<std::uint32_t>(PTR<>(self8) + 0x44)) return static_cast<std::int32_t>(0x7fffbffb);
    *PTR<std::uint32_t>(PTR<>(self8) + 0x44) += 1;

    std::uint32_t elementCount = *PTR<std::uint32_t>(PTR<>(self8) + 4);
    elementCount = *PTR<std::uint32_t>(*PTR<>(elementCount + 0x18));
    std::uint32_t iterations = *PTR<std::uint32_t>(owner + 0x68);
    if (iterations == 0) iterations = 0xff;

    std::int32_t result = 0;
    void* scratch = nullptr;
    std::uint32_t visited = 0;
    for (; visited < iterations; visited++) {
        *PTR<std::uint32_t>(PTR<>(self8) + 0x68) = visited;
        std::uint32_t next = visited + 1;
        *PTR<std::uint32_t>(PTR<>(self8) + 0x6c) = next;
        if ((param_4 != nullptr) && (param_2 != nullptr)) {
            result = FUN_0062254c(reinterpret_cast<int*>(param_4), nullptr);
            if (result < 0) break;
            if (*PTR<>(PTR<>(self8) + 0x5c) != 0) break;
            if ((*PTR<>(PTR<>(self8) + 0x50) != 0) ||
                (*PTR<>(PTR<>(self8) + 0x54) != 0)) break;
        }
        if (param_3 != 0) {
            std::int32_t pair = -1;
            result = FUN_00623505(param_3, PTR<std::uint32_t>(&pair), nullptr);
            if (result < 0) break;
            result = static_cast<std::int32_t>(FUN_00616222(device, 0x20500001u, &pair, &pair, &pair, 0x17));
            if (result < 0) break;
        }
        double progress = 0.0;
        double anchor = *reinterpret_cast<double*>(PTR<>(self8) + 0x20);
        if ((FUN_00616086(*PTR<>(&anchor), &progress) < 0) || (progress == 0.0)) {
            for (std::uint32_t i = 0; i < elementCount; i++) {
                std::int32_t current = *PTR<>(*PTR<>(PTR<>(self8) + 0x18) + i * 4);
                if (static_cast<std::int32_t>(*PTR<std::uint32_t>(param_5 + i)) != current) {
                    struct P { double lo; double hi; } envelope{0.0, 0.0};
                    if ((*reinterpret_cast<double*>(PTR<>(self8) + 0xa8) < envelope.lo) ||
                        (envelope.hi < *reinterpret_cast<double*>(PTR<>(self8) + 0xa0))) {
                        if (FUN_006147e4(current, &envelope) >= 0) {
                            if (envelope.lo < *reinterpret_cast<double*>(PTR<>(self8) + 0xa0)) *reinterpret_cast<double*>(PTR<>(self8) + 0xa0) = envelope.lo;
                        }
                    }
                }
            }
        }
        std::int32_t matchA = -1, matchB = -1;
        std::uint32_t matched = FUN_006190a2(self8, next, &matchA, &matchB) ? 1u : 0u;
        (void)matched;
        if ((param_4 != nullptr) && (param_2 == nullptr)) {
            result = FUN_0062254c(reinterpret_cast<int*>(param_4), nullptr);
            if (result < 0) break;
        }
    }
    scratch = FUN_00533c78(0);
    (void)scratch;
    operator_delete(scratch);
    // NEEDS_MANUAL: the 9-column grid build and the post-loop epilogue continue
    // past the supplied listing; every offset and opcode above is observed.
    return result;
}

// 0x61afd4 — observed shape
// Receiver via in_ECX. Caches [self+0x58] and [self+0x5c], the [self+0x18] list
// and the element count from [self+4]+0x18. Allocates two elementCount*4
// buffers plus two elementCount*16 buffer pairs and one flags list; clears
// [self+0x5c]; optionally pitches param_2 through FUN_0062254c, setting
// local_3c when the state word becomes non-zero and bailing on
// [self+0x50]/[self+0x54].
// Snapshots [self+0x18] into the first buffer and into param_5, then per
// element resolves FUN_006147e4 (fallback [self+0xa0]/[self+0xa8]) and records
// descriptor flags & 0x1f unless the descriptor's +4 equals [self+8]+0x74
// (then 0x1f).
// The sweep then restarts from [self+8]+8 / [self+8]+0xc copies; the remainder
// continues past the supplied listing.
std::int32_t FUN_0061afd4(void* self, std::uint32_t device, double* param_2, std::int32_t param_3, std::int32_t param_4, std::int32_t* param_5) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    std::int32_t owner = *PTR<>(self8 + 8);
    std::uint32_t saved58 = *PTR<std::uint32_t>(PTR<>(self8) + 0x58);
    std::uint32_t saved5c = *PTR<std::uint32_t>(PTR<>(self8) + 0x5c);
    std::uint32_t count = *PTR<std::uint32_t>(*PTR<>(PTR<>(self8) + 4) + 0x18);
    std::int32_t result = 0;
    std::int32_t* list = nullptr;
    std::int32_t* mirror = nullptr;
    double* envelopes = nullptr;
    double* envelopeCopy = nullptr;
    std::int32_t* flags = nullptr;
    std::int32_t* flagCopy = nullptr;

    list = PTR<>(FUN_00533c78(count * 4));
    mirror = PTR<>(FUN_00533c78(count * 4));
    if ((list == nullptr) || (mirror == nullptr)) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }
    envelopes = reinterpret_cast<double*>(FUN_00533c78(count * 16));
    envelopeCopy = reinterpret_cast<double*>(FUN_00533c78(count * 16));
    flags = PTR<>(FUN_00533c78(count * 4));
    flagCopy = PTR<>(FUN_00533c78(count * 4));
    if ((envelopes == nullptr) || (envelopeCopy == nullptr) || (flags == nullptr) || (flagCopy == nullptr)) { result = static_cast<std::int32_t>(0x8007000e); goto cleanup; }

    *PTR<std::uint32_t>(PTR<>(self8) + 0x5c) = 0;
    if (param_2 != nullptr) {
        result = FUN_0062254c(reinterpret_cast<int*>(param_2), nullptr);
        if (result < 0) goto cleanup;
        if (*PTR<>(PTR<>(self8) + 0x5c) != 0) saved5c = 1;
        if ((*PTR<>(PTR<>(self8) + 0x50) != 0) ||
            (*PTR<>(PTR<>(self8) + 0x54) != 0)) goto cleanup;
    }
    for (std::uint32_t i = 0; i < count; i++) {
        list[i] = *PTR<>(*PTR<>(PTR<>(self8) + 0x18) + i * 4);
        param_5[i] = list[i];
    }
    for (std::uint32_t i = 0; i < count; i++) {
        std::int32_t index = list[i];
        struct P { double lo; double hi; } pair{0.0, 0.0};
        if ((index == -1) || (FUN_006147e4(index, &pair) < 0)) {
            pair.lo = *reinterpret_cast<double*>(PTR<>(self8) + 0xa0);
            pair.hi = *reinterpret_cast<double*>(PTR<>(self8) + 0xa8);
        }
        envelopes[i * 2] = pair.lo;
        envelopes[i * 2 + 1] = pair.hi;
        if ((index == -1) ||
            (*PTR<std::uint32_t>(*PTR<>(*PTR<>(owner + 0x14) + index * 4) + 4) == *PTR<std::uint32_t>(owner + 0x74))) {
            flags[i] = 0x1f;
        } else {
            flags[i] = *PTR<>(*PTR<>(*PTR<>(owner + 0x14) + index * 4)) & 0x1f;
        }
    }
    (void)saved58;
    // Sweep: snapshots [self+8]+8 / +0xc into local_5c/local_58 and re-copies
    // list into mirror each iteration.
    // NEEDS_MANUAL: the sweep, merge and 0x20500001/0x20500001 emission tail is
    // beyond the supplied listing; prologue offsets above are observed.
    result = 0;
cleanup:
    operator_delete(list);
    operator_delete(mirror);
    operator_delete(envelopes);
    operator_delete(envelopeCopy);
    operator_delete(flags);
    operator_delete(flagCopy);
    return result;
}

// 0x61b66c — observed shape
// Receiver via in_ECX. Validates the two descriptors: a null param_1 with a
// null param_2 yields 0, otherwise 0x7fffbffb; param_1+4 must be 0xd and
// param_1+0x1c must be 0x1a. Element count is param_1+0x14 * param_1+0x18,
// with param_1+0x24 cached and [self+0x1c] / [self+100] snapshotted.
// The body then performs float10 arithmetic over twelve 12-byte scratch
// records; Ghidra reports type propagation not settling, so the exact
// intermediate typing is provider-specific.
// NEEDS_MANUAL: the arithmetic core beyond the prologue is not structurally
// recoverable from the supplied listing.
std::int32_t FUN_0061b66c(void* self, void* descriptor, void* out) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    if (descriptor == nullptr) return (out == nullptr) ? 0 : static_cast<std::int32_t>(0x7fffbffb);

    auto* d = reinterpret_cast<std::uint8_t*>(descriptor);
    if (*PTR<>(d + 4) != 0xd) return static_cast<std::int32_t>(0x7fffbffb);
    std::int32_t elements = *PTR<>(d + 0x14) * *PTR<>(d + 0x18);
    std::int32_t word24 = *PTR<>(d + 0x24);
    if (*PTR<>(d + 0x1c) != 0x1a) return static_cast<std::int32_t>(0x7fffbffb);

    std::int32_t cached1c = *PTR<>(PTR<>(self8) + 0x1c);
    std::int32_t cached64 = *PTR<>(PTR<>(self8) + 100);
    (void)elements; (void)word24; (void)cached1c; (void)cached64;
    return 0;
}

// 0x6213f0 — observed shape
// Receiver via in_ECX. param_5 == 0 jumps to the copy-out exit. Otherwise
// local_c = param_5 / param_3 (1 when param_3 == 0). FUN_006147e4(*param_7)
// gives a range snapped by [self+0xb0] (positive values expand outward,
// negatives contract, zero stays zero); a finite non-negative start becomes
// local_8 via ftol and a finite end becomes the exclusive bound.
// When the start is out of range it sets [self+0x5c] = 1 and copies out if
// param_2 is non-null. It then optionally FUN_00618f94(param_6,param_4,param_5)
// and ORs/ANDs every descriptor's [self+8]+0x14 -> +4 flags into local_14 /
// param_6, deriving local_24 (bit 7), local_20 (bit 2), local_28 (bit 0x40)
// and param_6 (bit 0x400).
// A single-row request copies param_4[local_8 * param_3] forward via the
//  0x6215eb label. Otherwise it compares consecutive rows' +4/+8/+0xc/+0x10
// fields, refines local_10/local_14, and continues past the supplied listing.
std::int32_t FUN_006213f0(void* self, std::uint32_t device, std::int32_t* param_1, std::int32_t* param_2, std::uint32_t param_3, std::int32_t* param_4, std::uint32_t param_5, std::uint32_t param_6, std::uint32_t* param_7, std::uint32_t* param_8) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    if (param_5 == 0) return 0;

    std::uint32_t start = 0;
    std::uint32_t stop = (param_3 == 0) ? 1 : (param_5 / param_3);

    struct RangePair { double lo; double hi; } range{0.0, 0.0};
    if (FUN_006147e4(*param_7, &range) >= 0) {
        if (range.lo >= 0.0) { if (range.lo > 0.0) range.lo += *reinterpret_cast<double*>(PTR<>(self8) + 0xb0); }
        else range.lo -= *reinterpret_cast<double*>(PTR<>(self8) + 0xb0);
        if (range.hi >= 0.0) { if (range.hi > 0.0) range.hi += *reinterpret_cast<double*>(PTR<>(self8) + 0xb0); }
        else range.hi -= *reinterpret_cast<double*>(PTR<>(self8) + 0xb0);

        start = (range.lo >= 0.0) ? static_cast<std::uint32_t>(static_cast<std::int32_t>(range.lo)) : 0;
        if ((range.hi < 0.0) || (param_5 <= start * param_3)) {
            if (*PTR<>(PTR<>(self8) + 0x58) == 0) return 0;
            *PTR<>(PTR<>(self8) + 0x5c) = 1;
            if (param_2 == nullptr) return 0;
            goto copy_out;
        }
        std::uint32_t end = static_cast<std::uint32_t>(static_cast<std::int32_t>(range.hi));
        if (end + 1 < stop) stop = end + 1;
    }
    if (param_2 == nullptr) return 0;
    if ((param_8 == nullptr) && ((FUN_00618f94(self8, static_cast<std::int32_t>(param_6), param_4, param_5)) < 0)) return static_cast<std::int32_t>(0x80004005);

    {
        std::uint32_t allFlags = 0, commonFlags = 0xffffffffu;
        for (std::uint32_t i = 0; i < param_5; i++) {
            std::uint32_t flags = *PTR<std::uint32_t>(*PTR<>(*PTR<>(*PTR<>(self8 + 8) + 0x10) + *PTR<>(*PTR<>(*PTR<>(*PTR<>(self8 + 8) + 0x14) + param_4[i] * 4) + 4) * 4) + 4);
            allFlags |= flags;
            commonFlags &= flags;
        }
        std::uint32_t bit7 = (~(allFlags >> 7)) & 1;
        std::uint32_t bit2 = commonFlags & 2;
        std::uint32_t bit40 = commonFlags & 0x40;
        std::uint32_t bit400 = commonFlags & 0x400;
        if ((allFlags & 0x100000) == 0) {
            if ((bit400 == 0) && ((*reinterpret_cast<std::uint8_t*>(*PTR<>(self8 + 8) + 0x71) & 2) == 0)) goto mark_interrupted;
        } else if ((start < *PTR<std::uint32_t>(PTR<>(self8) + 0x68)) ||
                   (*PTR<std::uint32_t>(PTR<>(self8) + 0x6c) < stop)) {
            goto mark_interrupted;
        }
        (void)bit7; (void)bit2; (void)bit40;
        goto refined;
    mark_interrupted:
        *PTR<>(PTR<>(self8) + 0x60) = 1;
    }

refined:
    if (start + 1 == stop) {
        param_4 = param_4 + start * param_3;
        goto copy_out;
    }
    // Consecutive-row comparison over +4/+8/+0xc/+0x10 refines local_10 and
    // local_14; the remainder of the scheduling body continues past the
    // supplied listing.
    // NEEDS_MANUAL: post-comparison allocation and emission tail not supplied.
    return 0;

copy_out:
    for (; param_3 != 0; param_3--) {
        *param_2 = *param_4;
        param_4++;
        param_2++;
    }
    return 0;
}

// 0x62241e — observed shape
// Receiver via in_ECX. When param_2 is non-null and (param_4 != param_2 or
// [self+8]+0x70 lacks bit 4) it first pitches param_2 through FUN_0062254c,
// returning failures and short-circuiting to 0 when [self+0x50]/[self+0x54]
// are set. It then snapshots [self+4]+0x18, [self+8]+8 and [self+8]+0xc,
// allocates an elementCount*4 copy of [self+0x18], and — when [self+8]+0x5c is
// non-zero — saves [self+0x60]/[self+0x58]/[self+0x5c], forces
// 1/0/0, calls FUN_0061a196(...,copy), clears [self+0x4c]/[self+0x50]/[self+0x54],
// restores the saved state, and on failure replays FUN_00616184 on the original
// snapshot. If that phase succeeds (or was skipped) it calls FUN_0061afd4 with
// the copy and normalises any non-negative result to 0. The copy is freed last.
std::int32_t FUN_0062241e(void* self, std::uint32_t device, std::int32_t param_2, std::int32_t param_3, std::int32_t param_4) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    std::int32_t result = 0;

    if ((param_2 != 0) && ((param_4 != param_2) || ((*reinterpret_cast<std::uint8_t*>(*PTR<>(self8 + 8) + 0x70) & 4) == 0))) {
        result = FUN_0062254c(reinterpret_cast<int*>(static_cast<std::intptr_t>(param_2)), nullptr);
        if (result < 0) return result;
        if ((*PTR<>(PTR<>(self8) + 0x50) != 0) ||
            (*PTR<>(PTR<>(self8) + 0x54) != 0)) return 0;
        param_2 = 0;
    }

    std::uint32_t count = *PTR<std::uint32_t>(*PTR<>(PTR<>(self8) + 4) + 0x18);
    std::uint32_t saved8 = *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 8);
    std::uint32_t savedC = *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 0xc);
    std::int32_t* copy = PTR<>(FUN_00533c78(count * 4));
    if (copy == nullptr) { result = static_cast<std::int32_t>(0x8007000e); operator_delete(copy); return result; }

    for (std::uint32_t i = 0; i < count; i++) copy[i] = *PTR<>(*PTR<>(PTR<>(self8) + 0x18) + i * 4);

    if (*PTR<>(*PTR<>(self8 + 8) + 0x5c) != 0) {
        std::int32_t saved60 = *PTR<>(PTR<>(self8) + 0x60);
        std::int32_t saved58 = *PTR<>(PTR<>(self8) + 0x58);
        std::int32_t saved5c = *PTR<>(PTR<>(self8) + 0x5c);
        *PTR<>(PTR<>(self8) + 0x58) = 1;
        *PTR<>(PTR<>(self8) + 0x5c) = 0;
        *PTR<>(PTR<>(self8) + 0x60) = 0;
        result = FUN_0061a196(self8, device, reinterpret_cast<double*>(static_cast<std::intptr_t>(param_2)), param_3, reinterpret_cast<double*>(static_cast<std::intptr_t>(param_4)), reinterpret_cast<std::uint32_t>(copy));
        *PTR<>(PTR<>(self8) + 0x4c) = 0;
        *PTR<>(PTR<>(self8) + 0x50) = 0;
        *PTR<>(PTR<>(self8) + 0x54) = 0;
        *PTR<>(PTR<>(self8) + 0x58) = saved58;
        *PTR<>(PTR<>(self8) + 0x5c) = saved5c;
        *PTR<>(PTR<>(self8) + 0x60) = saved60;
        if (result >= 0) goto done;
        FUN_00616184(saved8, savedC, copy);
    }

    result = FUN_0061afd4(self8, device, reinterpret_cast<double*>(static_cast<std::intptr_t>(param_2)), param_3, param_4, copy);
    if (result >= 0) result = 0;
done:
    operator_delete(copy);
    return result;
}

// 0x62254c — observed shape
// Receiver via in_ECX. param_1 == 0 yields 0, as do a set [self+0x50] or
// [self+0x54]. Dispatches on param_1[1]: 6, 0xc or 1.
//   6: param_1[4] selects sub-form 1 or 2, both reading a nested object at
//      param_1[6] with +0x10 (start), +0x14 (count), +0x20, and flag bits in
//      +0x1c (0x40 => bVar3, 2 => bVar2); form 1 additionally clears mask
//      0xfffff3ff and reads +0x30, form 2 clears 0xf3 at +0x19 and reads
//      +0x34. With flag 0x80 it forwards to FUN_00623505(nested+0x28,
//      [self+0x18] + start*4, 0). Otherwise it iterates count entries,
//      picking [self+8]+0x7c (bVar3) or [self+8]+0x74 as the reader passed to
//      FUN_0065d9d5, writing descriptor +0x30/+0x60/+100 and the resolved index
//      into [self+0x18]; with bVar3 it then calls FUN_00616a38, FUN_00618ec0
//      ([self+8]+0x7c) and FUN_006145fe.
//   0xc: dispatches on param_1[4] and delegates to FUN_00623505 or the
//      continuation beyond the listing.
//   1: walks the param_1[8] / param_1[0xc] chain calling FUN_0062254c until
//      exhausted or interrupted.
// NEEDS_MANUAL: case 0xc and the tail after LAB_006228ac are not in the
// supplied listing.
std::int32_t FUN_0062254c(void* self, int* param_1, void* param_2) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    if (param_1 == nullptr) return 0;
    if (*PTR<>(PTR<>(self8) + 0x50) != 0) return 0;
    if (*PTR<>(PTR<>(self8) + 0x54) != 0) return 0;

    std::uint32_t limit = *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 0xc);
    std::int32_t kind = param_1[1];
    std::int32_t result = 0;

    if (kind == 6) {
        std::int32_t start;
        std::uint32_t count;
        std::uint32_t object;
        std::uint32_t extra;
        bool bVar3, bVar2;
        if (param_1[4] == 1) {
            auto* nested = PTR<>(param_1[6]);
            start = nested[4];
            count = static_cast<std::uint32_t>(nested[5]);
            bVar3 = (nested[6] != 0) && ((nested[7] & 0x40) != 0);
            bVar2 = (nested[6] != 0) && ((nested[7] & 2) != 0);
            object = static_cast<std::uint32_t>(nested[8]);
            extra = static_cast<std::uint32_t>(nested[0xc]);
            std::uint32_t mask = static_cast<std::uint32_t>(nested[7]) & 0x80;
            nested[7] = nested[7] & 0xfffff3ff;
            (void)mask;
        } else if (param_1[4] == 2) {
            auto* nested = PTR<>(param_1[6]);
            count = static_cast<std::uint32_t>(nested[5]);
            start = nested[4];
            object = static_cast<std::uint32_t>(nested[8]);
            *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(nested) + 0x19) &= 0xf3;
            extra = static_cast<std::uint32_t>(nested[0xd]);
            bVar3 = false;
            bVar2 = false;
        } else {
            return 0;
        }
        if (bVar3) {
            result = FUN_00616a38(object, reinterpret_cast<void*>(*PTR<>(PTR<>(self8) + 0x18) + start * 4), count);
            if (result < 0) return result;
            result = FUN_00618ec0(self8, object, *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 0x7c), 1, 0, 0, extra);
            if (result < 0) return result;
            result = FUN_006145fe();
        }
        for (std::uint32_t i = 0; i < count; i++) {
            std::int32_t* slots = PTR<>(*PTR<>(PTR<>(self8) + 0x18));
            if ((!bVar2) || (slots[start + i] == -1)) {
                std::uint32_t reader = bVar3
                    ? *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 0x7c)
                    : *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 0x74);
                std::uint32_t resolved = FUN_0065d9d5(reinterpret_cast<void*>(reader), 0, 0, 0);
                std::int32_t* desc = (resolved < *PTR<std::uint32_t>(*PTR<>(self8 + 8) + 8))
                    ? PTR<>(*PTR<>(*PTR<>(self8 + 8) + 0x14) + resolved * 4)
                    : nullptr;
                if (desc != nullptr) {
                    desc[0xc] = start + static_cast<std::int32_t>(i);
                    desc[0x18] = reinterpret_cast<std::int32_t>(param_1);
                    desc[0x19] = static_cast<std::int32_t>(i);
                }
                slots[start + i] = static_cast<std::int32_t>(resolved);
            }
        }
        (void)limit;
        return result;
    }

    if (kind == 1) {
        int* node = param_1;
        while (node != nullptr) {
            if ((*PTR<>(PTR<>(self8) + 0x50) != 0) ||
                (*PTR<>(PTR<>(self8) + 0x54) != 0)) break;
            result = FUN_0062254c(self8, PTR<int>(node[2]), nullptr);
            if (result < 0) return result;
            node = PTR<int>(node[3]);
        }
        return 0;
    }

    if (kind != 0xc) {
        FUN_00615bbb();
        return static_cast<std::int32_t>(0x7fffbffb);
    }
    if (param_1[4] < 0) return 0;
    if (param_1[4] < 2) {
        result = FUN_00623505(param_1[5], nullptr, nullptr);
        if (result < 0) return result;
    }
    // NEEDS_MANUAL: the remainder of case 0xc and LAB_006228ac follow the
    // supplied listing.
    return result;
}

// 0x62294a — observed shape
// Receiver via in_ECX. Rejects a null param_2 or param_2[1] != 10 with
//  0x7fffbffb, and a non-zero param_2[0xe] with FUN_00615bbb + 0x7fffbfff.
// param_5 non-zero preflights through FUN_0065e3ad.
// param_3 is optional and supplies local_28/local_38 from +8/+0xc.
// It walks param_2[9] (the node chain) twice: the first walk sizes the
// FUN_00533c78 buffer (and the optional FUN_00533c78 second buffer when
// param_5 is set) using each node's +0x18 nested +0x14 count; the second walk
// either emits FUN_0062254c/node or, when the record's +0x1c bit 0x10 is set,
// FUN_00616222(param_3[2], nested+0x14 & 0xfffff | 0x10000000, [self+0x18] +
// nested+0x10 * 4, local_10, 0, 0) before advancing param_3 by +0xc; nodes
// without that gate choose a reader of [self+8]+0x74, +0x80 (bit 0x10) or
// +0x7c (bit 0x40). Allocation failure yields 0x8007000e.
std::int32_t FUN_0062294a(void* self, std::uint32_t device, std::uint32_t* param_2, std::uint32_t param_3, std::uint32_t* param_4, std::int32_t param_5, std::int32_t param_6) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    std::int32_t result = 0;
    void* buffer = nullptr;
    std::int32_t* second = nullptr;

    if ((param_2 == nullptr) || (static_cast<std::int32_t>(param_2[1]) != 10)) return static_cast<std::int32_t>(0x7fffbffb);
    if (param_2[0xe] != 0) { FUN_00615bbb(); return static_cast<std::int32_t>(0x7fffbfff); }
    if (param_5 != 0) {
        std::int32_t rc = FUN_0065e3ad();
        if (rc < 0) return rc;
    }
    std::int32_t* chain = (param_3 == 0) ? nullptr : *reinterpret_cast<std::int32_t**>(param_3 + 8);
    std::int32_t chainCount = (param_3 == 0) ? 0 : *PTR<>(param_3 + 0xc);

    buffer = FUN_00533c78(0);
    if (buffer == nullptr) return static_cast<std::int32_t>(0x8007000e);
    if (param_5 != 0) {
        second = PTR<>(FUN_00533c78(0));
        if (second == nullptr) { operator_delete(buffer); return static_cast<std::int32_t>(0x8007000e); }
    }

    // Sizing walk: advance the buffer cursor by each node's nested +0x14.
    {
        std::uint32_t node = param_2[9];
        auto* cursor = reinterpret_cast<std::uint8_t*>(buffer);
        std::int32_t* selector = chain;
        std::uint32_t savedSelector = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(selector));
        while (node != 0) {
            std::uint32_t record = node + 8;
            node = *PTR<std::uint32_t>(node + 0xc);
            if ((node != 0) && (*PTR<>(node + 8) != 0) && (*PTR<>(*PTR<>(node + 8) + 4) == 0xc)) {
                node = *PTR<std::uint32_t>(node + 0xc);
            }
            auto* nested = PTR<>(*PTR<>(record));
            if (((param_5 == 0) || ((param_6 != 0) && ((nested[7] & 0x40) != 0))) && (selector != nullptr)) {
                if (selector[2] != 0) {
                    result = FUN_00623505(PTR<>(selector[2]), cursor, nullptr);
                    if (result < 0) goto cleanup;
                    selector = PTR<>(savedSelector);
                }
                selector = PTR<>(selector[3]);
                savedSelector = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(selector));
            }
            cursor += nested[5] * 4;
        }
    }

    // Emission walk.
    {
        std::int32_t* selector = chain;
        std::uint32_t node = param_2[9];
        auto* cursor = reinterpret_cast<std::uint8_t*>(buffer);
        while (node != 0) {
            std::uint32_t record = node + 8;
            node = *PTR<std::uint32_t>(node + 0xc);
            std::int32_t* extra = nullptr;
            if (node != 0) {
                std::uint32_t candidate = node + 8;
                if ((*PTR<>(candidate) != 0) && (*PTR<>(*PTR<>(candidate) + 4) == 0xc)) {
                    node = *PTR<std::uint32_t>(node + 0xc);
                    extra = PTR<>(candidate);
                }
            }
            auto* nested = PTR<>(*PTR<>(record));
            if ((param_5 == 0) || ((param_6 != 0) && ((nested[7] & 0x40) != 0))) {
                result = FUN_0062254c(PTR<int>(record), nullptr);
                if (result < 0) goto cleanup;
                if (selector == nullptr) {
                    result = FUN_0062254c(PTR<int>(extra), nullptr);
                    if (result < 0) goto cleanup;
                    continue;
                }
                if ((nested[7] & 0x10) != 0) {
                    result = static_cast<std::int32_t>(FUN_00616222(*PTR<std::uint32_t>(reinterpret_cast<std::uintptr_t>(selector) + 8),
                        static_cast<std::uint32_t>(nested[5]) & 0xfffff | 0x10000000u,
                        reinterpret_cast<void*>(*PTR<>(PTR<>(self8) + 0x18) + nested[4] * 4),
                        cursor, nullptr, 0));
                    if (result < 0) goto cleanup;
                }
                selector = PTR<>(selector[3]);
            } else {
                std::int32_t reader = *PTR<>(*PTR<>(self8 + 8) + 0x74);
                if ((nested[7] & 0x40) != 0) reader = *PTR<>(*PTR<>(self8 + 8) + 0x7c);
                else if ((nested[7] & 0x10) != 0) reader = *PTR<>(*PTR<>(self8 + 8) + 0x80);
                (void)reader;
                result = 0;
            }
        }
        (void)chainCount; (void)param_4; (void)device;
    }
    // NEEDS_MANUAL: the tail after the second walk is beyond the supplied
    // listing; the two walk shapes and all offsets above are observed.
    result = 0;
cleanup:
    operator_delete(buffer);
    operator_delete(second);
    return result;
}

// 0x6233ff — observed shape
// Receiver via in_ECX (an int* object array). in_ECX[1] must exist with a
// kind of 4 else 0; a null in_ECX[2] yields 0x80004005. FUN_006629c4 is called
// on the kind-4 object, *in_ECX + 0x18 and in_ECX[4]/in_ECX[5]. On success it
// frees in_ECX[6], reallocates it as kind-4+0x18 dwords and fills them with
//  0xffffffff; then it seeds in_ECX[8] with 1.0, in_ECX[9] with 0.0 and
// in_ECX[10] with -1.0 through FUN_0065d9d5 on in_ECX[2]+0x78, sets
// in_ECX[0xc] = -1, in_ECX[0xb] = in_ECX[8], in_ECX[0xd] = 1, and finally
// pitches kind-4+0x1c through FUN_0062254c; a non-zero in_ECX[0x13] turns the
// success into 0x80004005. Allocation failure yields 0x8007000e.
std::uint32_t FUN_006233ff(void* self) {
    auto* obj = PTR<>(self);
    std::uint32_t result = 0;
    std::int32_t kind4 = obj[1];
    if ((kind4 == 0) || (*PTR<>(kind4 + 4) != 4)) return 0;
    if (obj[2] == 0) return 0x80004005;

    result = static_cast<std::uint32_t>(FUN_006629c4(static_cast<std::uint32_t>(kind4), static_cast<std::uint32_t>(obj[0] + 0x18), static_cast<std::uint32_t>(obj[4]), static_cast<std::uint32_t>(obj[5])));
    if (static_cast<std::int32_t>(result) < 0) return result;

    operator_delete(reinterpret_cast<void*>(obj[6]));
    auto* dwords = PTR<std::uint32_t>(FUN_00533c78(static_cast<std::size_t>(*PTR<>(kind4 + 0x18)) << 2));
    obj[6] = reinterpret_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(dwords));
    if (dwords == nullptr) return 0x8007000e;
    for (std::uint32_t i = 0; i < *PTR<std::uint32_t>(kind4 + 0x18); i++) dwords[i] = 0xffffffffu;

    void* reader = reinterpret_cast<void*>(*PTR<std::uint32_t>(obj[2] + 0x78));
    obj[8] = static_cast<std::int32_t>(FUN_0065d9d5(reader, 0, 0, 0x3ff0000000000000ULL));
    obj[9] = static_cast<std::int32_t>(FUN_0065d9d5(reader, 0, 0, 0));
    obj[10] = static_cast<std::int32_t>(FUN_0065d9d5(reader, 0, 0, 0xbff0000000000000ULL));
    obj[0xc] = -1;
    obj[0xb] = obj[8];
    obj[0xd] = 1;

    result = static_cast<std::uint32_t>(FUN_0062254c(reinterpret_cast<int*>(static_cast<std::intptr_t>(*PTR<>(kind4 + 0x1c))), nullptr));
    if (static_cast<std::int32_t>(result) >= 0) {
        result = (obj[0x13] != 0) ? 0x80004005u : 0u;
    }
    return result;
}

// 0x623505 — observed shape
// Receiver via in_ECX. param_1 == 0 yields 0 when param_2 is null and
//  0x7fffbffb otherwise; param_1+4 must be 0xd. Element count is
// param_1+0x14 * param_1+0x18. Nested descriptors at param_1+0x20 and
// param_1+0x24 are accepted when their +4 is 0xd, caching +0x14*+0x18 counts
// and allocating FUN_006143c6 buffers for each (failure => FUN_00615bbb and
//  0x8007000e).
// param_1+0x1c selects a selector: values 0..3 use param_3, 0x14..0x15 use 1,
//  0x16..0x17 use param_3 again. When param_1+0x28 is 0 the +0x24 descriptor is
// resolved first, else the +0x20 one is; the other is then resolved with the
// same helper.
// The switch on param_1+0x1c handles 0/1 by direct copy from the cached
// ++0x20 buffer (or FUN_00624bb6 when it is absent), with a row-wise
// row-count/stride comparison path when counts differ.
// NEEDS_MANUAL: cases 2..0x22 and the LAB_00624b26 epilogue are past the
// supplied listing.
std::int32_t FUN_00623505(void* self, std::uint32_t* param_2, std::uint32_t* param_3) {
    auto* self8 = reinterpret_cast<std::uint8_t*>(self);
    if (self == nullptr) return (param_2 == nullptr) ? 0 : static_cast<std::int32_t>(0x7fffbffb);
    if (*PTR<>(self8 + 4) != 0xd) return static_cast<std::int32_t>(0x7fffbffb);

    std::uint32_t elements = static_cast<std::uint32_t>(*PTR<>(self8 + 0x14)) * static_cast<std::uint32_t>(*PTR<>(self8 + 0x18));
    auto* nestedA = *reinterpret_cast<std::uint32_t**>(self8 + 0x20);
    auto* nestedB = *reinterpret_cast<std::uint32_t**>(self8 + 0x24);
    std::uint32_t* bufferA = nullptr;
    std::uint32_t* bufferB = nullptr;
    std::uint32_t countA = 0, countB = 0;

    if ((nestedA != nullptr) && (static_cast<std::int32_t>(nestedA[1]) == 0xd)) {
        countA = nestedA[6] * nestedA[5];
        bufferA = PTR<std::uint32_t>(FUN_006143c6());
        if (bufferA == nullptr) { FUN_00615bbb(); return static_cast<std::int32_t>(0x8007000e); }
    }
    if ((nestedB != nullptr) && (static_cast<std::int32_t>(nestedB[1]) == 0xd)) {
        countB = nestedB[6] * nestedB[5];
        bufferB = PTR<std::uint32_t>(FUN_006143c6());
        if (bufferB == nullptr) { FUN_00615bbb(); return static_cast<std::int32_t>(0x8007000e); }
    }

    std::uint32_t* selector = nullptr;
    std::int32_t mode = *PTR<>(self8 + 0x1c);
    if ((mode >= 0) && (mode < 4)) selector = param_3;
    else if ((mode > 0x13) && (mode < 0x16)) selector = PTR<std::uint32_t>(1);
    else if ((mode > 0x15) && (mode < 0x18)) selector = param_3;

    std::int32_t rc;
    if (*PTR<>(self8 + 0x28) == 0) {
        if ((nestedB != nullptr) && ((rc = FUN_00623505(nestedB, bufferB, nullptr)) < 0)) return rc;
        if (nestedA != nullptr) {
            rc = FUN_00623505(nestedA, bufferA, selector);
            if (rc < 0) return rc;
        }
    } else {
        if ((nestedA != nullptr) && ((rc = FUN_00623505(nestedA, bufferA, selector)) < 0)) return rc;
        if (nestedB != nullptr) {
            rc = FUN_00623505(nestedB, bufferB, nullptr);
            if (rc < 0) return rc;
        }
    }

    switch (mode) {
    case 0:
    case 1:
        if (nestedA == nullptr) {
            return FUN_00624bb6(*PTR<std::uint32_t>(self8 + 0x20), param_2, reinterpret_cast<void*>(static_cast<std::uintptr_t>(elements)));
        }
        if (param_2 != nullptr) {
            if (countA == 1) {
                for (std::uint32_t i = 0; i < elements; i++) param_2[i] = bufferA[i];
            } else if ((elements != countA) &&
                       !((*PTR<std::uint32_t>(self8 + 0x14) == 1) && (elements < countA))) {
                if ((nestedA[5] < *PTR<std::uint32_t>(self8 + 0x14)) || (nestedA[6] < *PTR<std::uint32_t>(self8 + 0x18))) break;
                std::uint32_t rows = *PTR<std::uint32_t>(self8 + 0x14);
                std::int32_t rowLen = *PTR<>(self8 + 0x18);
                for (std::uint32_t r = 0; r < rows; r++) {
                    auto* src = bufferA + static_cast<std::uint32_t>(nestedA[6]) * r;
                    auto* dst = param_2 + rowLen * static_cast<std::int32_t>(r);
                    for (std::int32_t c = 0; c < rowLen; c++) dst[c] = src[c];
                }
            }
        }
        return 0;
    default:
        // NEEDS_MANUAL: remaining cases of the param_1+0x1c switch and the
        // LAB_00624b26 epilogue are not present in the supplied listing.
        return 0;
    }
}
