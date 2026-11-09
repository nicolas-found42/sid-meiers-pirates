// Band 6 decompiler-derived candidates — small helpers (modulo, array dtor).
// UNVERIFIED. Exact leaf bodies from corpus; helpers are externals.

#include <stddef.h>
#include <stdint.h>

// 0x005e1570 — modulo accessor: return value % this[1].
extern "C" unsigned long __thiscall Band6ModAccessor(const void* self, unsigned long value) {
    unsigned long modulus = *(unsigned long*)((unsigned char*)self + 4);
    return value % modulus;
}

// 0x005e43e0 — array-holder dtor: vtable 0x006c97c0, 4-byte elements via
// eh_vector_destructor_iterator + operator_delete(base-4).
struct Band6ArrayHolder { void* vtable; void* array; };
extern "C" void __thiscall Band6ArrayHolder_Dtor(Band6ArrayHolder* self) {
    self->vtable = (void*)0;  // 0x006c97c0
    void* arr = self->array;
    if (arr) {
        extern void __eh_vector_destructor_iterator__(void*, int, int, void*);
        int count = *(int*)((char*)arr - 4);
        __eh_vector_destructor_iterator__(arr, 4, count, (void*)0);
        operator delete((unsigned char*)arr - 4);
    }
}
