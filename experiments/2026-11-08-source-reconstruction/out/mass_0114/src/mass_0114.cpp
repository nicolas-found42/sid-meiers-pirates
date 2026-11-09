#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void _AIL_close_stream_4(uint32_t stream);

// 0x52f230 — observed shape: self+0xC is count, self+0x60 is strided array base; 8-byte stride, byte at +4 tested for nonzero.
int FUN_0052f230(void* self) {
    int count;
    int index = 0;
    char* entry;
    if (0 < *(int*)((char*)self + 0x0C)) {
        entry = (char*)(*(uintptr_t*)((char*)self + 0x60) + 4);
        do {
            if (*entry != '\0') {
                return index;
            }
            index = index + 1;
            entry = entry + 8;
        } while (index < *(int*)((char*)self + 0x0C));
    }
    return -1;
}

// 0x52f260 — observed shape: index in EAX, self in EDI; bound checked against self+0xC, array at self+0x60, closes stream and zeroes entry.
void FUN_0052f260(void* self, int index) {
    if ((-1 < index) && (index < *(int*)((char*)self + 0x0C))) {
        _AIL_close_stream_4(*(uint32_t*)(*(uintptr_t*)((char*)self + 0x60) + index * 8));
        uint32_t* entry = (uint32_t*)(*(uintptr_t*)((char*)self + 0x60) + index * 8);
        *entry = 0;
        *(uint8_t*)((char*)entry + 4) = 1;
    }
    return;
}

// 0x52f290 — observed shape: self+0x14 is count, self+100 is strided array base; 8-byte stride, byte at +4 tested for nonzero.
int FUN_0052f290(void* self) {
    int index = 0;
    char* entry;
    if (0 < *(int*)((char*)self + 0x14)) {
        entry = (char*)(*(uintptr_t*)((char*)self + 100) + 4);
        do {
            if (*entry != '\0') {
                return index;
            }
            index = index + 1;
            entry = entry + 8;
        } while (index < *(int*)((char*)self + 0x14));
    }
    return -1;
}

// 0x52f2c0 — observed shape: index in EAX, self in EDI; bound checked against self+0x14, array at self+100, closes stream and zeroes entry.
void FUN_0052f2c0(void* self, int index) {
    if ((-1 < index) && (index < *(int*)((char*)self + 0x14))) {
        _AIL_close_stream_4(*(uint32_t*)(*(uintptr_t*)((char*)self + 100) + index * 8));
        uint32_t* entry = (uint32_t*)(*(uintptr_t*)((char*)self + 100) + index * 8);
        *entry = 0;
        *(uint8_t*)((char*)entry + 4) = 1;
    }
    return;
}

// 0x52f500 — observed shape: self fields [2]..[5] zeroed, then virtual calls at +0xA0,+0xB4,+0xC4 chained; optional stack flag selects secondary +0xBC,+0xCC chain; returns 1/0.
uint32_t FUN_0052f500(void* self, char flag) {
    char result;
    int32_t* self_words = (int32_t*)self;
    self_words[2] = 0;
    self_words[3] = 0;
    self_words[4] = 0;
    self_words[5] = 0;
    using VFn = char(*)();
    result = (char)((*(VFn*)(*(intptr_t*)self + 0xA0))());
    if (((result != '\0') && (result = (char)((*(VFn*)(*(intptr_t*)self + 0xB4))()), result != '\0')) &&
        (result = (char)((*(VFn*)(*(intptr_t*)self + 0xC4))()), result != '\0')) {
        if (flag == '\0') {
            return 1;
        }
        result = (char)((*(VFn*)(*(intptr_t*)self + 0xBC))());
        if ((result != '\0') && (result = (char)((*(VFn*)(*(intptr_t*)self + 0xCC))()), result != '\0')) {
            return 1;
        }
    }
    return 0;
}

// 0x52f570 — observed shape: self vtable +0xB8,+200 chain sets flag; param selects +0xC0,+0xD0 chain; CONCAT31 packing preserved.
extern void* DAT_008ecd78;
extern uint32_t DAT_00727080;
extern int FUN_004a95b0(int v);
extern int FUN_005f0ddc(void);
extern void* FUN_005281c0(void* a, int b, float c, uint32_t d, uint32_t e, int f, uint32_t g);
extern char FUN_0052fc80(void);
extern int FUN_0052fd00(void);
extern void FUN_0052fd30(float v);
extern void FUN_0052fd80(float v);
extern void _AIL_stream_ms_position_12(uint32_t stream, int* pos, uint32_t* out);

// 0x52f570 — observed shape: self vtable +0xB8,+200 chain sets flag; param selects +0xC0,+0xD0 chain; CONCAT31 packing preserved.
int FUN_0052f570(void* self, char param_1) {
    uint8_t flag = 1;
    using VFn = int (*)();
    uint32_t result = ((VFn*)(*(intptr_t*)self + 0xB8))();
    if ((char)result == '\0') {
        flag = 0;
    } else {
        result = ((VFn*)(*(intptr_t*)self + 200))();
        if ((char)result == '\0') {
            flag = 0;
        }
    }
    uint32_t packed = (result & 0xFFFFFF00u) | flag;
    if (param_1 == '\0') {
        return (int)packed;
    }
    char extra = (char)((VFn*)(*(intptr_t*)self + 0xC0))();
    if (extra != '\0') {
        char extra2 = (char)((VFn*)(*(intptr_t*)self + 0xD0))();
        if (extra2 != '\0') {
            return (int)packed;
        }
    }
    return (int)(packed & 0xFFFFFF00u);
}

// 0x52f5d0 — observed shape: two 3-word records at self[0..2] and self[3..5]; +0x7C id compare then +0x5C release(1), clear to 0/-1/-1; returns 1.
uint32_t FUN_0052f5d0(void* self) {
    int32_t* words = (int32_t*)self;
    if (self != nullptr && *(intptr_t*)self != 0) {
        using IdFn = int(*)();
        int id = ((IdFn*)(*(intptr_t*)*(intptr_t*)self + 0x7C))();
        if (id == words[1]) {
            if (*(intptr_t*)*(intptr_t*)self != 0) {
                using RelFn = void(*)(int);
                ((RelFn*)(*(intptr_t*)*(intptr_t*)self + 0x5C))(1);
            }
            *(intptr_t*)self = 0;
            words[1] = -1;
            words[2] = -1;
        }
    }
    int32_t* second = words + 3;
    if (second != nullptr && *(intptr_t*)second != 0) {
        using IdFn = int(*)();
        int id = ((IdFn*)(*(intptr_t*)*(intptr_t*)second + 0x7C))();
        if (id == words[4]) {
            if (*(intptr_t*)*(intptr_t*)second != 0) {
                using RelFn = void(*)(int);
                ((RelFn*)(*(intptr_t*)*(intptr_t*)second + 0x5C))(1);
            }
            *(intptr_t*)second = 0;
            words[4] = -1;
            words[5] = -1;
        }
    }
    return 1;
}

// 0x52f640 — observed shape: self+0x24/+0x2C float range, self+0x28 current float; DAT_008ecd78 vtable +0x14 supplies time; FUN_0052fd30 adjusts sample position.
void FUN_0052f640(void* self) {
    using TimeFn = double(*)();
    double t = ((TimeFn*)(*(intptr_t*)DAT_008ecd78 + 0x14))();
    float cur = (float)t;
    if ((*(float*)((char*)self + 0x2C) != *(float*)((char*)self + 0x24)) &&
        (*(float*)((char*)self + 0x28) != 0.0f)) {
        float delta = *(float*)((char*)self + 0x28) - cur;
        if ((*(float*)((char*)self + 0x28) <= cur) || (delta != delta || (delta < 1.0f) == (delta == 1.0f))) {
            if (*(float*)((char*)self + 0x28) < cur) {
                FUN_0052fd30(*(float*)((char*)self + 0x24));
                *(uint32_t*)((char*)self + 0x28) = 0;
            }
        } else if (delta != 0.0f) {
            FUN_0052fd30((1.0f - delta) * (*(float*)((char*)self + 0x24) - *(float*)((char*)self + 0x2C)) +
                           *(float*)((char*)self + 0x2C));
            return;
        }
    }
    return;
}

// 0x52f700 — observed shape: param_1*0x40+DAT_008ed4a0 table lookup; 3-word cache at self; window-stream recreation paths with 0x5C releases and 0x7C id checks; returns 1/0.
extern void* DAT_008ed4a0;
extern void* DAT_008ecd7c;
uint32_t FUN_0052f700(int32_t* self, int param_1, float param_2, uint32_t param_3, uint32_t param_4, char param_5,
                     float param_6, char param_7, int32_t** param_8, int param_9, uint32_t param_10, uint32_t param_11) {
    intptr_t table = (intptr_t)DAT_008ed4a0 + param_1 * 0x40;
    if ((self[1] == *(int32_t*)(table + 4)) && (param_9 == self[2])) {
        if (param_8 != nullptr) {
            *param_8 = (int32_t*)(intptr_t)self[0];
        }
        if (param_2 != -1.0f) {
            FUN_0052fd80(param_2);
            return 1;
        }
        int sample = FUN_004a95b0(*(int32_t*)(table + 0x10) - *(int32_t*)(table + 0x0C));
        sample = sample + *(int32_t*)(table + 0x0C);
        float f = (float)sample;
        if (sample < 0) {
            f = f + 4294967296.0f;
        }
        FUN_0052fd80(f * 0.01f);
        return 1;
    }
    if (param_2 == -1.0f) {
        param_11 = (uint32_t)(*(int32_t*)(table + 0x10) - *(int32_t*)(table + 0x0C));
        DAT_00727080 = DAT_00727080 * 0x343FD + 0x269EC3;
        int rnd = FUN_005f0ddc();
        param_11 = (uint32_t)(*(int32_t*)(table + 0x0C) - rnd);
        param_2 = (float)(int32_t)param_11;
        if ((int32_t)param_11 < 0) {
            param_2 = param_2 + 4294967296.0f;
        }
        param_2 = param_2 * 0.01f;
    }
    if (param_7 == '\0') {
        param_6 = param_6 - param_6 * 0.33f;
    }
    int32_t* second = self + 3;
    if ((second != nullptr && *(intptr_t*)second != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)second + 0x7C))() == self[4])) {
        if (*(intptr_t*)*(intptr_t*)second != 0) {
            ((void(*)(int))(*(intptr_t*)*(intptr_t*)second + 0x5C))(1);
        }
        *(intptr_t*)second = 0;
        self[4] = -1;
        self[5] = -1;
    }
    *(intptr_t*)second = (intptr_t)self[0];
    self[4] = self[1];
    self[5] = self[2];
    if ((second == nullptr || *(intptr_t*)second == 0) ||
        (((int(*)())(*(intptr_t*)*(intptr_t*)second + 0x7C))() != self[4])) {
        int32_t* created = (int32_t*)FUN_005281c0(&DAT_008ecd78, 1, param_2, param_3, param_4, param_9, param_10);
        self[0] = (int32_t)(intptr_t)created;
        self[1] = *(int32_t*)(table + 4);
        self[2] = param_9;
        if ((created != nullptr && ((int(*)())(*(intptr_t*)created + 0x7C))() == self[1]) && (param_5 != '\0')) {
            ((void(*)(int,int))(*(intptr_t*)(intptr_t)self[0] + 0x4C))(1, -1);
        }
    } else {
        param_11 = param_11 & 0xFFFFFF00u;
        char flag = FUN_0052fc80();
        if (flag != '\0') {
            int idx = FUN_0052fd00();
            if (idx == -1) {
                param_11 = (param_11 & 0xFFu) << 8;
            } else {
                param_11 = (param_11 & 0xFFFFFF00u) | (uint8_t)(*(uint8_t*)((char*)(intptr_t)self[6] + 8 + idx * 0x0C));
            }
        }
        int32_t* created = (int32_t*)FUN_005281c0(&DAT_008ecd78, 1, 0, param_3, param_4, param_9, param_10);
        self[0] = (int32_t)(intptr_t)created;
        self[1] = *(int32_t*)(table + 4);
        self[2] = param_9;
        if (created == nullptr) {
            self[0] = *(int32_t*)second;
            self[1] = self[4];
            self[2] = self[5];
            if (*(intptr_t*)*(intptr_t*)second != 0) {
                ((void(*)(int))(*(intptr_t*)*(intptr_t*)second + 0x5C))(1);
            }
            self[4] = -1;
            self[5] = -1;
            *(intptr_t*)second = 0;
            return 0;
        }
        if ((char)param_11 != '\0') {
            int idx = ((int(*)())(*(intptr_t*)*(intptr_t*)second + 0xE8))();
            _AIL_stream_ms_position_12(*(uint32_t*)(*(uintptr_t*)((char*)DAT_008ecd7c + 0x60) + idx * 8), &param_9, &param_11);
            ((void(*)(int))(*(intptr_t*)(intptr_t)self[0] + 0x88))((int)(intptr_t)param_8 % (int)param_6);
            ((void(*)())(*(intptr_t*)(intptr_t)self[0] + 0x24))();
            *(uint8_t*)((char*)self + 32) = 1;
        }
        if (((intptr_t)self[0] != 0 && ((int(*)())(*(intptr_t*)(intptr_t)self[0] + 0x7C))() == self[1]) && (param_5 != '\0')) {
            ((void(*)(int,int))(*(intptr_t*)(intptr_t)self[0] + 0x4C))(1, -1);
        }
        {
            intptr_t v = *(intptr_t*)*(intptr_t*)second;
            double d = ((double(*)())(*(intptr_t*)DAT_008ecd78 + 0x14))(0, 0xBF800000);
            ((void(*)(float,float))(*(intptr_t*)v + 0x38))(param_6, (float)d);
        }
        {
            intptr_t v = (intptr_t)self[0];
            double d = ((double(*)())(*(intptr_t*)DAT_008ecd78 + 0x14))(0, 0);
            ((void(*)(uint32_t,float))(*(intptr_t*)v + 0x3C))(param_3, (float)d);
        }
    }
    if (((intptr_t)self[0] == 0) || (((int(*)())(*(intptr_t*)(intptr_t)self[0] + 0x7C))() != self[1])) {
        if (param_8 != nullptr) {
            *param_8 = nullptr;
        }
        return 0;
    }
    if (param_8 != nullptr) {
        *param_8 = (int32_t*)(intptr_t)self[0];
    }
    return 1;
}

// 0x52faf0 — observed shape: second record (self+3) cleared when id matches and float valid/positive; first record calls +0x38 with DAT time or releases via +0x5C; returns 1.
uint32_t FUN_0052faf0(void* self, float param_1) {
    int32_t* words = (int32_t*)self;
    int32_t* second = words + 3;
    if ((second != nullptr && *(intptr_t*)second != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)second + 0x7C))() == words[4])) {
        if (!(param_1 != param_1 || (param_1 < 0.0f) == (param_1 == 0.0f))) {
            if (*(intptr_t*)*(intptr_t*)second != 0) {
                ((void(*)(int))(*(intptr_t*)*(intptr_t*)second + 0x5C))(1);
            }
        }
    }
    *(intptr_t*)second = 0;
    words[4] = -1;
    words[5] = -1;
    if ((self != nullptr && *(intptr_t*)self != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)self + 0x7C))() == words[1])) {
        if (param_1 != param_1 || (param_1 < 0.0f) == (param_1 == 0.0f)) {
            intptr_t v = *(intptr_t*)*(intptr_t*)self;
            double d = ((double(*)())(*(intptr_t*)DAT_008ecd78 + 0x14))(0, 0xBF800000);
            ((void(*)(float,float))(*(intptr_t*)v + 0x38))(param_1, (float)d);
            return 1;
        }
        if (*(intptr_t*)*(intptr_t*)self != 0) {
            ((void(*)(int))(*(intptr_t*)*(intptr_t*)self + 0x5C))(1);
        }
    }
    words[1] = -1;
    words[2] = -1;
    *(intptr_t*)self = 0;
    return 1;
}

// 0x52fbb0 — observed shape: second record released if ids match param_1; first record delegates to FUN_0052faf0(param_2); byte at self+32 cleared.
extern uint32_t FUN_0052faf0(void* self, float value);
void FUN_0052fbb0(void* self, int param_1, uint32_t param_2) {
    int32_t* words = (int32_t*)self;
    int32_t* second = words + 3;
    if ((second != nullptr && *(intptr_t*)second != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)second + 0x7C))() == words[4]) && (words[4] == param_1)) {
        if (*(intptr_t*)*(intptr_t*)second != 0) {
            ((void(*)(int))(*(intptr_t*)*(intptr_t*)second + 0x5C))(1);
        }
        *(intptr_t*)second = 0;
        words[4] = -1;
        words[5] = -1;
    }
    if ((self != nullptr && *(intptr_t*)self != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)self + 0x7C))() == words[1]) && (words[1] == param_1)) {
        FUN_0052faf0(self, *(float*)&param_2);
    }
    *(uint8_t*)((char*)self + 32) = 0;
    return;
}

// 0x52fc20 — observed shape: first record +0x40/+0x44 true returns 1; else second record must match id and have +0x40 or +0x44 true; else 0.
uint32_t FUN_0052fc20(void* self) {
    int32_t* words = (int32_t*)self;
    if ((self != nullptr && *(intptr_t*)self != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)self + 0x7C))() == words[1])) {
        char flag = (char)((char(*)())(*(intptr_t*)*(intptr_t*)self + 0x40))();
        if (flag != '\0') {
            return 1;
        }
        flag = (char)((char(*)())(*(intptr_t*)*(intptr_t*)self + 0x44))();
        if (flag != '\0') {
            return 1;
        }
    }
    int32_t* second = words + 3;
    if ((second == nullptr || *(intptr_t*)second == 0) ||
        (((int(*)())(*(intptr_t*)*(intptr_t*)second + 0x7C))() != words[4])) {
        return 0;
    }
    char flag = (char)((char(*)())(*(intptr_t*)*(intptr_t*)second + 0x40))();
    if ((flag == '\0') && ((flag = (char)((char(*)())(*(intptr_t*)*(intptr_t*)second + 0x44))()) == '\0')) {
        return 0;
    }
    return 1;
}

// 0x52fc80 — observed shape: both records must id-match; scans self[6]/self[7] 12-byte-stride table for first-record id; FOUND calls FUN_0052fd00; returns 1/0.
uint32_t FUN_0052fc80(void* self) {
    int32_t* words = (int32_t*)self;
    int32_t* second = words + 3;
    if ((self != nullptr && *(intptr_t*)self != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)self + 0x7C))() == words[1]) &&
        (second != nullptr && *(intptr_t*)second != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)second + 0x7C))() == words[4])) {
        int id = ((int(*)())(*(intptr_t*)*(intptr_t*)self + 0x7C))();
        if (words[6] != 0) {
            int index = 0;
            if (0 < words[7]) {
                int32_t* entry = (int32_t*)(intptr_t)(*(intptr_t*)((char*)self + 24) + 4);
                do {
                    if (*entry == id) {
                        if (index == -1) {
                            return 0;
                        }
                        ((int(*)())(*(intptr_t*)*(intptr_t*)second + 0x7C))();
                        int found = FUN_0052fd00();
                        if (found == -1) {
                            return 0;
                        }
                        return 1;
                    }
                    index = index + 1;
                    entry = entry + 3;
                } while (index < words[7]);
            }
        }
    }
    return 0;
}

// 0x52fd00 — observed shape: scans self+0x18/0x1C 12-byte-stride id table for EDI value; returns index or -1.
int FUN_0052fd00(void* self, int target) {
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        int index = 0;
        if (0 < *(int*)((char*)self + 0x1C)) {
            int32_t* entry = (int32_t*)(*(intptr_t*)((char*)self + 0x18) + 4);
            do {
                if (*entry == target) {
                    return index;
                }
                index = index + 1;
                entry = entry + 3;
            } while (index < *(int*)((char*)self + 0x1C));
        }
    }
    return -1;
}

// 0x52fd30 — observed shape: forwards param to +0x78 on first record if id matches, and on second record (self+3) if id matches.
void FUN_0052fd30(void* self, float param_1) {
    int32_t* words = (int32_t*)self;
    if ((self != nullptr && *(intptr_t*)self != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)self + 0x7C))() == words[1])) {
        ((void(*)(float))(*(intptr_t*)*(intptr_t*)self + 0x78))(param_1);
    }
    int32_t* second = words + 3;
    if ((second != nullptr && *(intptr_t*)second != 0) &&
        (((int(*)())(*(intptr_t*)*(intptr_t*)second + 0x7C))() == words[4])) {
        ((void(*)(float))(*(intptr_t*)*(intptr_t*)second + 0x78))(param_1);
    }
    return;
}

// 0x52fd80 — observed shape: NaN or zero input returns early; negative clamps self+0x24 to 0, >1 clamps to 0x3F800000, else stores param; then FUN_0052fd30(self).
extern void FUN_0052fd30(void* self, float v);
void FUN_0052fd80(void* self, float param_1) {
    if (param_1 != param_1 || (param_1 < 0.0f) != (param_1 == 0.0f)) {
        return;
    }
    if (param_1 < 0.0f) {
        *(uint32_t*)((char*)self + 0x24) = 0;
        FUN_0052fd30(self, *(float*)((char*)self + 0x24));
        return;
    }
    if (1.0f < param_1) {
        *(uint32_t*)((char*)self + 0x24) = 0x3F800000;
        FUN_0052fd30(self, *(float*)((char*)self + 0x24));
        return;
    }
    *(float*)((char*)self + 0x24) = param_1;
    FUN_0052fd30(self, param_1);
    return;
}

// 0x52fe10 — observed shape: DAT_008ecd78 vtable +0x14 time; extends self+0x28 to time+param+1 if below time+param; calls FUN_0052fd30 if self+0x28 > time.
void FUN_0052fe10(void* self, float param_1) {
    using TimeFn = double(*)();
    double now = ((TimeFn*)(*(intptr_t*)DAT_008ecd78 + 0x14))();
    if ((double)*(float*)((char*)self + 0x28) < (double)param_1 + now) {
        *(float*)((char*)self + 0x28) = (float)((double)param_1 + now + 1.0);
    }
    if ((double)*(float*)((char*)self + 0x28) <= now) {
        return;
    }
    FUN_0052fd30(self, *(float*)((char*)self + 0x28));
    return;
}

// 0x52fe60 — observed shape: 10 iterations of 64-byte records (EAX+0x3D cursor, stride 0x40); fill pattern with -1/0xBF800000 and zero fields; returns CONCAT31.
uint32_t FUN_0052fe60(void* self) {
    int remaining = 10;
    uint8_t* cursor = (uint8_t*)(self) + 0x3D;
    uint8_t* initial_base = (uint8_t*)(self);
    do {
        uint32_t* base = (uint32_t*)(cursor - 0x39);
        base[0] = 0xFFFFFFFF;
        base[1] = 0xFFFFFFFF;
        base[2] = 0xFFFFFFFF;
        base[3] = 0xFFFFFFFF;
        base[4] = 0xFFFFFFFF;
        base[5] = 0xFFFFFFFF;
        base[6] = 0xFFFFFFFF;
        base[7] = 0xFFFFFFFF;
        base[8] = 0xFFFFFFFF;
        base[9] = 0xFFFFFFFF;
        base[10] = 0xBF800000;
        base[11] = 0;
        *cursor = 0;
        *(uint32_t*)(cursor - 0x11) = 0;
        cursor[-1] = 0;
        *(uint32_t*)(cursor - 9) = 0xBF800000;
        uint8_t* next = cursor + 0x40;
        *(uint32_t*)(cursor - 5) = 0xBF800000;
        cursor = next;
        remaining = remaining - 1;
    } while (remaining != 0);
    return (((uint32_t)((uintptr_t)initial_base >> 8) & 0xFFFFFF) << 24) | 1u;
}

// 0x52fee0 — observed shape: same 10x64-byte fill as 0x52fe60 (-1/0xBF800000/zero pattern); returns void.
void FUN_0052fee0(void* self) {
    int remaining = 10;
    uint8_t* cursor = (uint8_t*)(self) + 0x3D;
    do {
        uint32_t* base = (uint32_t*)(cursor - 0x39);
        base[0] = 0xFFFFFFFF;
        base[1] = 0xFFFFFFFF;
        base[2] = 0xFFFFFFFF;
        base[3] = 0xFFFFFFFF;
        base[4] = 0xFFFFFFFF;
        base[5] = 0xFFFFFFFF;
        base[6] = 0xFFFFFFFF;
        base[7] = 0xFFFFFFFF;
        base[8] = 0xFFFFFFFF;
        base[9] = 0xFFFFFFFF;
        base[10] = 0xBF800000;
        base[11] = 0;
        *cursor = 0;
        *(uint32_t*)(cursor - 0x11) = 0;
        cursor[-1] = 0;
        *(uint32_t*)(cursor - 9) = 0xBF800000;
        remaining = remaining - 1;
        *(uint32_t*)(cursor - 5) = 0xBF800000;
        cursor = cursor + 0x40;
    } while (remaining != 0);
    return;
}

// 0x52ff60 — observed shape: null format uses empty stack buffer, else _vsnprintf into 512-byte buf; returns FUN_0052ffc0(buf) & 0xFFFFFF00.
extern uint32_t FUN_0052ffc0(char* text);
extern int _vsnprintf(char* dest, size_t count, const char* format, ...);
uint32_t FUN_0052ff60(const char* format, ...) {
    char buf[512];
    if (format == nullptr) {
        buf[0] = '\0';
        uint32_t result = FUN_0052ffc0(buf);
        return result & 0xFFFFFF00u;
    }
    va_list args;
    va_start(args, format);
    _vsnprintf(buf, 0x200, format, args);
    va_end(args);
    uint32_t result = FUN_0052ffc0(buf);
    return result & 0xFFFFFF00u;
}
