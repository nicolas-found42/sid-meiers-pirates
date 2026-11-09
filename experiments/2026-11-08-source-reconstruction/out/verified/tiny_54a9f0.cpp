// 0x0054a9f0: mov eax,ecx; mov cl,[esp+4]; mov [eax+0x18],cl; ret 4
// The original returns this in EAX, so the setter returns the object pointer.
struct ByteSetter {
    ByteSetter* set_byte(unsigned char value);
};

ByteSetter* ByteSetter::set_byte(unsigned char value) {
    *(unsigned char*)((char*)this + 0x18) = value;
    return this;
}
