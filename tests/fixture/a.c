/*
 * Fixture for tools/match.py.
 *
 * The fixture is compiled twice: once into a linked PE at a fixed .text base,
 * then again into a COFF object that the harness relocates and compares with
 * the linked image. It validates COFF parsing, symbol-address derivation and
 * REL32 application, not MSVC code generation.
 */

__attribute__((noinline)) int add(int a, int b) {
    return a + b;
}

int call_add(void) {
    volatile int left = 1;
    return add(left, 2);
}
