// 0x005366b0: 12-byte struct assignment from +0x90 to +0x28.
struct T {
    void copy();
};

struct Triple {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

void T::copy() {
    *(Triple*)((char*)this + 0x28) = *(Triple*)((char*)this + 0x90);
}
