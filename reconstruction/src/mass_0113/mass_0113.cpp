#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void _AIL_stream_volume_pan_12();
extern void _AIL_set_stream_volume_pan_12();
extern void _AIL_set_3D_position_16(uint32_t, uint32_t, uint32_t, uint32_t);
extern void _AIL_set_3D_sample_cone_16(uint32_t, float, float, uint32_t);
extern void _AIL_set_3D_orientation_28(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

// 0x52d700 — observed shape
void FUN_0052d700_recon()
{
    _AIL_stream_volume_pan_12();
    _AIL_set_stream_volume_pan_12();
}

// 0x52d750 — observed shape
void FUN_0052d750_recon(void* self, uint32_t param_2, uint32_t param_3)
{
    _AIL_set_3D_position_16(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0xc), param_2, param_3, 0);
}

// 0x52d7e0 — observed shape
void FUN_0052d7e0_recon(void* self, int param_1, int param_2, uint32_t param_3)
{
    _AIL_set_3D_sample_cone_16(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0xc), (float)param_1, (float)param_2, param_3);
}

// 0x52d810 — observed shape
void FUN_0052d810_recon(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7)
{
    _AIL_set_3D_orientation_28(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

// 0x52d840 — observed shape
void FUN_0052d840_recon(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7)
{
    _AIL_set_3D_orientation_28(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0xc), param_2, param_3, param_4, param_5, param_6, param_7);
}

extern void _AIL_set_redist_directory_4(const char*);
extern void _AIL_mem_use_malloc_4(void*);
extern void _AIL_mem_use_free_4(void*);
extern void FUN_00533b70();
extern void _AIL_startup_0();
extern int _AIL_open_digital_driver_16(uint32_t, uint32_t, uint32_t, uint32_t);
extern int FUN_0052d4b0();
extern uint32_t FUN_0052f500(void*, uint32_t, uint32_t, uint32_t);
extern void FUN_0052f570(uint32_t);
extern void _AIL_close_3D_provider_4(int);
extern void _AIL_close_digital_driver_4(int);
extern void _AIL_shutdown_0();
extern void _AIL_close_3D_listener_4(int);
extern int FUN_0052d6d0(uint32_t);
extern int _AIL_set_3D_sample_file_8(uint32_t, uint32_t);
extern uint32_t _AIL_open_stream_12(uint32_t, uint32_t, uint32_t);
extern void _AIL_end_sample_4(uint32_t);
extern void _AIL_end_3D_sample_4(uint32_t);
extern void _AIL_pause_stream_8(uint32_t, uint32_t);
extern void* LAB_0052f3a0;
extern void* LAB_0052f3e0;
extern void* LAB_0052f420;
extern void* LAB_0052f460;
extern void* LAB_0052f4a0;
extern void* LAB_0052f4c0;

// 0x52d880 — observed shape
bool FUN_0052d880_recon(void* self, uint32_t p_ebp, uint32_t p_ebx, uint32_t p_retaddr, uint32_t p_esi)
{
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x34) = 0;
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x38) = 0xffffffff;
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x58) = 0;
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x5c) = 0;
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x60) = 0;
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 100) = 0;
    _AIL_set_redist_directory_4(".\\Miles\\win32");
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x40) = &LAB_0052f3a0;
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x48) = &LAB_0052f3e0;
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x44) = &LAB_0052f420;
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x4c) = &LAB_0052f460;
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x50) = &LAB_0052f4a0;
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x54) = &LAB_0052f4c0;
    _AIL_mem_use_malloc_4(&LAB_0052f4a0);
    _AIL_mem_use_free_4(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x54));
    FUN_00533b70();
    _AIL_startup_0();
    int drv = _AIL_open_digital_driver_16(p_ebp, p_ebx, p_retaddr, 0);
    *reinterpret_cast<int*>(static_cast<char*>(self) + 0x34) = drv;
    if (drv == 0) return false;
    if ((uint8_t)p_esi != 0) {
        int prov = FUN_0052d4b0();
        *reinterpret_cast<int*>(static_cast<char*>(self) + 0x38) = prov;
        if (prov == -1) return false;
    }
    uint32_t r = FUN_0052f500(&LAB_0052f4a0, p_ebx, p_retaddr, p_esi);
    return r != 0;
}

// 0x52d950 — observed shape
uint32_t FUN_0052d950_recon(void* self, uint32_t param_1)
{
    FUN_0052f570(param_1);
    if (((uint8_t)param_1 != 0) && (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x38) != -1)) {
        _AIL_close_3D_provider_4(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x38));
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x38) = 0xffffffff;
    }
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x34) != 0) {
        _AIL_close_digital_driver_4(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x34));
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x34) = 0;
    }
    _AIL_shutdown_0();
    return 1;
}

// 0x52d9c0 — observed shape
int FUN_0052d9c0_recon(int** self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    using Getter = int (*)(uint32_t);
    using ErrCb = void (*)(uint32_t, int);
    Getter get_idx = *reinterpret_cast<Getter*>(*self + 0xac);
    ErrCb err_cb = *reinterpret_cast<ErrCb*>(*self + 0xb0);
    int iVar1 = get_idx(param_1);
    switch (param_1) {
    case 0:
        if (iVar1 != -1) {
            int r = FUN_0052d6d0(param_3);
            if (r == 0) {
                err_cb(0, iVar1);
                return -1;
            }
        }
        break;
    case 1:
        if (iVar1 != -1) {
            uint32_t u;
            if ((iVar1 < 0) || (self[0][4] < iVar1)) u = 0;
            else u = *reinterpret_cast<uint32_t*>(self[0][0x17] + iVar1 * 8);
            int r = _AIL_set_3D_sample_file_8(u, param_1);
            if (r == 0) {
                err_cb(1, iVar1);
                return -1;
            }
        }
        break;
    case 2:
        if (iVar1 != -1) {
            uint32_t s = _AIL_open_stream_12(self[0][0xd], param_1, 0);
            *reinterpret_cast<uint32_t*>(self[0][0x18] + iVar1 * 8) = s;
            if (*reinterpret_cast<int*>(self[0][0x18] + iVar1 * 8) == 0) {
                err_cb(2, iVar1);
                return -1;
            }
            *reinterpret_cast<uint8_t*>(self[0][0x18] + 4 + iVar1 * 8) = 0;
            return iVar1;
        }
        break;
    case 3:
        if (iVar1 != -1) {
            uint32_t s = _AIL_open_stream_12(self[0][0xe], param_1, 0);
            *reinterpret_cast<uint32_t*>(self[0][0x19] + iVar1 * 8) = s;
            if (*reinterpret_cast<int*>(self[0][0x19] + iVar1 * 8) == 0) {
                err_cb(3, iVar1);
                return -1;
            }
            *reinterpret_cast<uint8_t*>(self[0][0x19] + 4 + iVar1 * 8) = 0;
        }
        break;
    }
    return iVar1;
}

// 0x52db30 — observed shape
void FUN_0052db30_recon(int** self, uint32_t param_1, int param_2)
{
    using ErrCb = void (*)(uint32_t, int);
    ErrCb err_cb = *reinterpret_cast<ErrCb*>(*self + 0xb0);
    switch (param_1) {
    case 0:
        if ((param_2 < 0) || (self[0][2] < param_2)) {
            _AIL_end_sample_4(0);
            err_cb(param_1, param_2);
            return;
        }
        _AIL_end_sample_4(*reinterpret_cast<uint32_t*>(self[0][0x16] + param_2 * 8));
        err_cb(param_1, param_2);
        return;
    case 1:
        if ((param_2 < 0) || (self[0][4] < param_2)) {
            _AIL_end_3D_sample_4(0);
            err_cb(param_1, param_2);
            return;
        }
        _AIL_end_3D_sample_4(*reinterpret_cast<uint32_t*>(self[0][0x17] + param_2 * 8));
        err_cb(param_1, param_2);
        return;
    case 2: {
        uint32_t u = *reinterpret_cast<uint32_t*>(self[0][0x18] + param_2 * 8);
        _AIL_pause_stream_8(u, 1);
        break;
    }
    case 3: {
        uint32_t u = *reinterpret_cast<uint32_t*>(self[0][0x19] + param_2 * 8);
        _AIL_pause_stream_8(u, 1);
        break;
    }
    default:
        break;
    }
    err_cb(param_1, param_2);
}

// 0x52dc90 — observed shape
uint32_t FUN_0052dc90_recon(void* self)
{
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x3c) != 0) {
        _AIL_close_3D_listener_4(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x3c));
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x3c) = 0;
    }
    return 1;
}

extern void _AIL_start_3D_sample_4(uint32_t);
extern void _AIL_register_3D_EOS_callback_8(uint32_t, uint32_t);
extern void _AIL_start_stream_4(uint32_t);
extern void _AIL_register_stream_callback_8(uint32_t, uint32_t);
extern void _AIL_start_sample_4(uint32_t);
extern void _AIL_register_EOS_callback_8(uint32_t, uint32_t);
extern void _AIL_set_3D_sample_volume_8(uint32_t, uint32_t);
extern void _AIL_set_sample_volume_pan_12(uint32_t, uint32_t, uint32_t);
extern uint32_t thunk_FUN_00533c78(int);
extern uint32_t _AIL_allocate_sample_handle_4(uint32_t);
extern void _AIL_init_sample_4(int);
extern void _AIL_release_sample_handle_4(uint32_t);
extern void operator_delete__(void*);
extern uint32_t _AIL_allocate_3D_sample_handle_4(uint32_t);

// 0x52dd30 — observed shape
uint32_t FUN_0052dd30_recon(void* self, uint32_t param_1, int param_2)
{
    uint32_t u;
    if (param_2 == -1) return 0;
    switch (param_1) {
    case 0: break;
    case 1:
        if ((param_2 < 0) || (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x10) < param_2)) u = 0;
        else u = *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c) + param_2 * 8);
        _AIL_start_3D_sample_4(u);
        if ((param_2 < 0) || (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x10) < param_2)) {
            _AIL_register_3D_EOS_callback_8(0, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x48));
            return 1;
        }
        _AIL_register_3D_EOS_callback_8(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c) + param_2 * 8), *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x48));
        return 1;
    case 2:
        _AIL_start_stream_4(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x60) + param_2 * 8));
        _AIL_register_stream_callback_8(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x60) + param_2 * 8), *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x44));
        return 1;
    case 3:
        _AIL_start_stream_4(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 100) + param_2 * 8));
        _AIL_register_stream_callback_8(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 100) + param_2 * 8), *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x4c));
        return 1;
    default:
        return 1;
    }
    if ((param_2 < 0) || (*reinterpret_cast<int*>(static_cast<char*>(self) + 8) < param_2)) u = 0;
    else u = *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58) + param_2 * 8);
    _AIL_start_sample_4(u);
    if ((param_2 < 0) || (*reinterpret_cast<int*>(static_cast<char*>(self) + 8) < param_2)) {
        _AIL_register_EOS_callback_8(0, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x40));
        return 1;
    }
    _AIL_register_EOS_callback_8(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58) + param_2 * 8), *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x40));
    return 1;
}

// 0x52e4f0 — observed shape
uint32_t FUN_0052e4f0_recon(int** self, uint32_t param_1, int param_2, uint32_t param_3, uint32_t p_retaddr, uint32_t p_esi)
{
    int iVar1 = param_2;
    if (param_2 == -1) return 0;
    switch (param_1) {
    case 0: break;
    case 1:
        if ((param_2 < 0) || (self[0][4] < param_2)) {
            _AIL_set_3D_sample_volume_8(0, param_3);
            return 1;
        }
        _AIL_set_3D_sample_volume_8(*reinterpret_cast<uint32_t*>(self[0][0x17] + param_2 * 8), param_3);
        return 1;
    case 2: {
        using Cb = void (*)(uint32_t, int, int*);
        Cb cb = *reinterpret_cast<Cb*>(*self + 100);
        cb(2, param_2, &param_2);
        _AIL_set_stream_volume_pan_12(*reinterpret_cast<uint32_t*>(self[0][0x18] + iVar1 * 8), p_retaddr, p_esi);
        return 1;
    }
    case 3:
        FUN_0052d700_recon();
        return 1;
    default:
        return 1;
    }
    {
        using Cb = void (*)(uint32_t, int, int*);
        Cb cb = *reinterpret_cast<Cb*>(*self + 100);
        cb(0, param_2, &param_2);
    }
    if ((iVar1 < 0) || (self[0][2] < iVar1)) {
        _AIL_set_sample_volume_pan_12(0, p_retaddr, p_esi);
        return 1;
    }
    _AIL_set_sample_volume_pan_12(*reinterpret_cast<uint32_t*>(self[0][0x16] + iVar1 * 8), p_retaddr, p_esi);
    return 1;
}

// 0x52ee80 — observed shape
uint32_t FUN_0052ee80_recon(void* self)
{
    uint32_t u = thunk_FUN_00533c78(*reinterpret_cast<int*>(static_cast<char*>(self) + 8) << 3);
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x58) = u;
    int i = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 8)) {
        do {
            uint32_t* slot = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58) + i * 8);
            *slot = 0;
            *(reinterpret_cast<uint8_t*>(slot) + 4) = 1;
            ++i;
        } while (i < *reinterpret_cast<int*>(static_cast<char*>(self) + 8));
    }
    int count = *reinterpret_cast<int*>(static_cast<char*>(self) + 8);
    if (0 < count) {
        int j = 0;
        do {
            uint32_t h = _AIL_allocate_sample_handle_4(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x34));
            *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58) + j * 8) = h;
            int hv = *reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58) + j * 8);
            if (hv == 0) return 0;
            _AIL_init_sample_4(hv);
            *(reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58)) + 4 + j * 8) = 1;
            count = *reinterpret_cast<int*>(static_cast<char*>(self) + 8);
            ++j;
        } while (j < count);
    }
    return *reinterpret_cast<uint8_t*>(&count) | ((count & ~0xff) );
}

// 0x52ef10 — observed shape
uint32_t FUN_0052ef10_recon(void* self)
{
    int i = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 8)) {
        do {
            _AIL_release_sample_handle_4(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58) + i * 8));
            *(reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58)) + 4 + i * 8) = 1;
            ++i;
        } while (i < *reinterpret_cast<int*>(static_cast<char*>(self) + 8));
    }
    operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x58));
    return 1;
}

// 0x52ef50 — observed shape
uint32_t FUN_0052ef50_recon(void* self)
{
    uint32_t u = thunk_FUN_00533c78(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x10) << 3);
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x5c) = u;
    int i = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x10)) {
        do {
            uint32_t* slot = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c) + i * 8);
            *slot = 0;
            *(reinterpret_cast<uint8_t*>(slot) + 4) = 1;
            ++i;
        } while (i < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x10));
    }
    int count = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x10);
    if (0 < count) {
        int j = 0;
        do {
            uint32_t h = _AIL_allocate_3D_sample_handle_4(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x38));
            *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c) + j * 8) = h;
            uint32_t addr = static_cast<uint32_t>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c)) + j * 8;
            if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c) + j * 8) == 0) {
                return addr & 0xffffff00;
            }
            *(reinterpret_cast<uint8_t*>(addr) + 4) = 1;
            count = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x10);
            ++j;
        } while (j < count);
    }
    return *reinterpret_cast<uint8_t*>(&count) | ((count & ~0xff) );
}

extern void _AIL_release_3D_sample_handle_4(uint32_t);
extern int _AIL_sample_status_4(uint32_t);
extern int _AIL_3D_sample_status_4(uint32_t);

// 0x52efe0 — observed shape
uint32_t FUN_0052efe0_recon(void* self)
{
    int i = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x10)) {
        do {
            _AIL_release_3D_sample_handle_4(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c) + i * 8));
            *(reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c)) + 4 + i * 8) = 1;
            ++i;
        } while (i < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x10));
    }
    operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x5c));
    return 1;
}

// 0x52f020 — observed shape
void FUN_0052f020_recon(void* self)
{
    uint32_t u = thunk_FUN_00533c78(*reinterpret_cast<int*>(static_cast<char*>(self) + 0xc) << 3);
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x60) = u;
    int i = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 0xc)) {
        do {
            uint32_t* slot = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x60) + i * 8);
            *slot = 0;
            *(reinterpret_cast<uint8_t*>(slot) + 4) = 1;
            ++i;
        } while (i < *reinterpret_cast<int*>(static_cast<char*>(self) + 0xc));
    }
}

// 0x52f070 — observed shape
void FUN_0052f070_recon(void* self)
{
    uint32_t u = thunk_FUN_00533c78(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) << 3);
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 100) = u;
    int i = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x14)) {
        do {
            uint32_t* slot = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 100) + i * 8);
            *slot = 0;
            *(reinterpret_cast<uint8_t*>(slot) + 4) = 1;
            ++i;
        } while (i < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x14));
    }
}

// 0x52f180 — observed shape
int FUN_0052f180_recon(void* self)
{
    int i = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 8)) {
        do {
            if ((*(reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58)) + 4 + i * 8) != 0) &&
                _AIL_sample_status_4(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58) + i * 8)) == 2) {
                _AIL_init_sample_4(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58) + i * 8));
                *(reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x58)) + 4 + i * 8) = 0;
                return i;
            }
            ++i;
        } while (i < *reinterpret_cast<int*>(static_cast<char*>(self) + 8));
    }
    return -1;
}

// 0x52f1e0 — observed shape
int FUN_0052f1e0_recon(void* self)
{
    int i = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x10)) {
        do {
            if ((*(reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c)) + 4 + i * 8) != 0) &&
                _AIL_3D_sample_status_4(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c) + i * 8)) == 2) {
                *(reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x5c)) + 4 + i * 8) = 0;
                return i;
            }
            ++i;
        } while (i < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x10));
    }
    return -1;
}
