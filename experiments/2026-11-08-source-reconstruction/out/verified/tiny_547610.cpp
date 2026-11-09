// First byte-matched candidate. Original: mov eax,[esp+4]; mov [ecx+0xc],eax; ret 4.
// VC7.1 emits a member function with the packed __thiscall ABI expected by the image.
struct SetterTarget {
    void set_value(unsigned int value);
};

void SetterTarget::set_value(unsigned int value) {
    *(unsigned int*)((char*)this + 0x0c) = value;
}
