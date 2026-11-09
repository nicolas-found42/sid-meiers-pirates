// UNVERIFIED: no cl 13.10.3077. No PASS claim. CRT helpers are linked, not matched.
// Band 8 CRT: __aullshr/__allmul/__allshl.
typedef unsigned __int64 uint64;
typedef __int64 int64;

// 0x006b9250 __aullshr
uint64 __aullshr_impl(uint64 value, unsigned count) {
    if (count >= 64) return 0;
    return value >> count;
}
// 0x006b92b0 __allmul
int64 __allmul_impl(unsigned lo1, int hi1, unsigned lo2, int hi2) {
    return (int64)((uint64)lo1 * (uint64)lo2)
         + (int64)((int64)hi1 * (uint64)lo2)
         + (int64)((uint64)lo1 * (int64)hi2);
}
// 0x006b92f0 __allshl
int64 __allshl_impl(int64 value, unsigned count) {
    if (count >= 64) return 0;
    return value << count;
}
