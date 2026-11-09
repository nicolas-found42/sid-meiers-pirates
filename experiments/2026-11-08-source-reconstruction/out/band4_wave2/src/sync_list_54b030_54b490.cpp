// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Intrusive-list push (0x0054b030) / unlink (0x0054b490), thread-flag guarded.
// Corpus: analysis/pseudocode/functions/0x54b030.c, 0x54b490.c
// Observed globals: 0x727958 thread id, 0x727940 critical section,
// 0x72795c recursion count, 0x727930 list head, 0x727934 list tail.
// Node layout: +0x1c prev, +0x20 next. this in ECX.
#include <stddef.h>
#include <stdint.h>

typedef struct Node {
    void*  vtable_00;
    int    pad_04;
    int    pad_08;
    int    pad_0c;
    int    pad_10;
    int    pad_14;
    int    pad_18;
    struct Node* prev_1c;
    struct Node* next_20;
} Node;

extern DWORD __declspec(dllimport) GetCurrentThreadId(void);
extern void  __declspec(dllimport) EnterCriticalSection(void* lpCriticalSection);
extern void  __declspec(dllimport) LeaveCriticalSection(void* lpCriticalSection);

extern DWORD g_threadId_727958;
extern uint8_t g_cs_727940[24];
extern int   g_lockCount_72795c;
extern Node* g_listHead_727930;
extern Node* g_listTail_727934;

// 0x0054b030
void __thiscall FUN_0054b030(Node* self)
{
    DWORD tid = GetCurrentThreadId();
    if (g_threadId_727958 != tid) {
        EnterCriticalSection(&g_cs_727940);
        g_threadId_727958 = GetCurrentThreadId();
    }
    g_lockCount_72795c += 1;
    if (g_listHead_727930 == nullptr) {
        g_listHead_727930 = self;
    }
    if (g_listTail_727934 == nullptr) {
        self->prev_1c = nullptr;
    } else {
        g_listTail_727934->next_20 = self;
        self->prev_1c = g_listTail_727934;
    }
    g_listTail_727934 = self;
    self->next_20 = nullptr;
    tid = GetCurrentThreadId();
    if (g_threadId_727958 == tid && --g_lockCount_72795c == 0) {
        g_threadId_727958 = 0;
        LeaveCriticalSection(&g_cs_727940);
    }
}

// 0x0054b490
void __thiscall FUN_0054b490(Node* self)
{
    DWORD tid = GetCurrentThreadId();
    if (g_threadId_727958 != tid) {
        EnterCriticalSection(&g_cs_727940);
        g_threadId_727958 = GetCurrentThreadId();
    }
    g_lockCount_72795c += 1;
    if (g_listHead_727930 == self) {
        g_listHead_727930 = self->next_20;
    }
    if (g_listTail_727934 == self) {
        g_listTail_727934 = self->prev_1c;
    }
    if (self->prev_1c != nullptr) {
        self->prev_1c->next_20 = self->next_20;
    }
    if (self->next_20 != nullptr) {
        self->next_20->prev_1c = self->prev_1c;
    }
    tid = GetCurrentThreadId();
    if (g_threadId_727958 == tid && --g_lockCount_72795c == 0) {
        g_threadId_727958 = 0;
        LeaveCriticalSection(&g_cs_727940);
    }
}
