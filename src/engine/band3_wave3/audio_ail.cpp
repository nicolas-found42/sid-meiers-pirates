// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
#include <cstdint>
#include <cstddef>

// AIL (Miles) imports — declared only, never defined (STYLE rule).
extern int AIL_set_3D_position_16(uint32_t, uint32_t, uint32_t, uint32_t);
extern int AIL_set_3D_velocity_vector_16(uint32_t, uint32_t, uint32_t, uint32_t);
extern int AIL_set_3D_sample_cone_16(void);
extern int AIL_open_3D_listener_4(int);

// 0x0052d730 — forwards (param_1,param_2,param_3,0) to AIL_set_3D_position_16
void FUN_0052d730(uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    AIL_set_3D_position_16(param_1, param_2, param_3, 0);
}

// 0x0052d780 — forwards (param_1,param_2,param_3,param_4) to AIL_set_3D_velocity_vector_16
void FUN_0052d780(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    AIL_set_3D_velocity_vector_16(param_1, param_2, param_3, param_4);
}

// 0x0052d7a0 — forwards (*(param_1+0x0c),param_2,param_3,param_4) to AIL_set_3D_velocity_vector_16
void FUN_0052d7a0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    uint32_t handle = *(uint32_t*)(param_1 + 0x0c);
    AIL_set_3D_velocity_vector_16(handle, param_2, param_3, param_4);
}

// 0x0052d7c0 — calls AIL_set_3D_sample_cone_16 with no arguments
void FUN_0052d7c0(void) {
    AIL_set_3D_sample_cone_16();
}

// 0x0052dc70 — if (this+0x38 == -1) return false; else this+0x3c = AIL_open_3D_listener_4(this+0x38); return !=0
bool FUN_0052dc70(void* self) {
    if (*(int*)((char*)self + 0x38) == -1) {
        return false;
    }
    int rc = AIL_open_3D_listener_4(*(int*)((char*)self + 0x38));
    *(int*)((char*)self + 0x3c) = rc;
    return rc != 0;
}
