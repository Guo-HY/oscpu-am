#include <am.h>
#include <la32r.h>
#include <klib.h>

extern char _heap_start;
extern char _pmem_end;
int main(const char *args);
void __am_init_uartlite(void);
void __am_uartlite_putchar(char ch);

_Area _heap = {
  .start = &_heap_start,
  .end = &_pmem_end,
};

void _putc(char ch) {
  __am_uartlite_putchar(ch);
}

void _halt(int code) {
  // set $a0 = code
  __asm__ volatile("add.w $r4, %0, $r0" : :"r"(code));
  // syscall 0x11 is nemu trap
  __asm__ volatile("syscall 0x11");

  // should not reach here during simulation
  printf("Exit with code = %d\n", code);

  // should not reach here on FPGA
  while (1);
}

void _trm_init() {
  __am_init_uartlite();
  extern const char __am_mainargs;
  int ret = main(&__am_mainargs);
  _halt(ret);
}
