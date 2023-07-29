#include "trap.h"
#include <la32r.h>
#include <nutshell.h>

int ret = 0;
volatile int array[1];

#define mmiocheck(cond) \
    do { \
      if (!(cond)) { \
        printf("mmiocheck fail at %s:%d\n", __FILE__, __LINE__); \
        ret = 1; \
      } \
    } while (0)

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
        mmiocheck(random == result);
    }

    uint32_t timer1 = inl(CONFREG_TIMER_ADDR);
    uint32_t timer2 = inl(CONFREG_TIMER_ADDR);
    mmiocheck(timer1 != timer2);

    outl(CONFREG_IO_SIMU_ADDR, 0x12345678);
    result = inl(CONFREG_IO_SIMU_ADDR);
    mmiocheck(result == 0x56781234);

    outl(CONFREG_OPEN_TRACE_ADDR, 0x80000000);
    result = inl(CONFREG_OPEN_TRACE_ADDR);
    mmiocheck(result == 1);
    outl(CONFREG_OPEN_TRACE_ADDR, 0);
    result = inl(CONFREG_OPEN_TRACE_ADDR);
    mmiocheck(result == 0);

    outl(CONFREG_NUM_MONITOR_ADDR, 0xffffffff);
    result = inl(CONFREG_NUM_MONITOR_ADDR);
    mmiocheck(result == 1);
    outl(CONFREG_NUM_MONITOR_ADDR, 0xfffffffe);
    result = inl(CONFREG_NUM_MONITOR_ADDR);
    mmiocheck(result == 0);
    ret = 1;
    if (ret) {
      printf("confreg test fail!\n");
      array[0] = 0;
      ret = result / array[0]; // nemu should assert fail
    } else {
      printf("confreg test pass!\n");
    }
    
    return ret;
}