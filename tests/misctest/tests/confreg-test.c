#include "trap.h"
#include <la32r.h>
#include <nutshell.h>

int main()
{

    printf("begin confreg test!\n");
    uint32_t random = 0;
    uint32_t result = 0;

    for (int i = 0; i < 8; i++) {
        random = rand();
        uintptr_t addr = CONFREG_BASE_ADDR + 0x8000 + 0x10 * i;
        outl(addr, random);
        result = inl(addr);
        assert(random == result);
    }

    uint32_t timer1 = inl(CONFREG_TIMER_ADDR);
    uint32_t timer2 = inl(CONFREG_TIMER_ADDR);
    assert(timer1 != timer2);

    outl(CONFREG_IO_SIMU_ADDR, 0x12345678);
    result = inl(CONFREG_IO_SIMU_ADDR);
    assert(result == 0x56781234);

    outl(CONFREG_OPEN_TRACE_ADDR, 0x80000000);
    result = inl(CONFREG_OPEN_TRACE_ADDR);
    assert(result == 1);
    outl(CONFREG_OPEN_TRACE_ADDR, 0);
    result = inl(CONFREG_OPEN_TRACE_ADDR);
    assert(result == 0);

    outl(CONFREG_NUM_MONITOR_ADDR, 0xffffffff);
    result = inl(CONFREG_NUM_MONITOR_ADDR);
    assert(result == 1);
    outl(CONFREG_NUM_MONITOR_ADDR, 0xfffffffe);
    result = inl(CONFREG_NUM_MONITOR_ADDR);
    assert(result == 0);

    printf("confreg test pass!\n");
    return 0;
}