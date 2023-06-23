#ifndef __LA32R_H__
#define __LA32R_H__

#ifndef __ASSEMBLER__

#include <stdint.h>

// note : la32r doesn't has double word, so just use 32bit for ind and outd func

static inline uint8_t  inb(uintptr_t addr) { return *(volatile uint8_t  *)addr; }
static inline uint16_t inw(uintptr_t addr) { return *(volatile uint16_t *)addr; }
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }
static inline uint32_t ind(uintptr_t addr) { return *(volatile uint32_t *)addr; }

static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }
static inline void outw(uintptr_t addr, uint16_t data) { *(volatile uint16_t *)addr = data; }
static inline void outl(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }
static inline void outd(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }

#endif

#endif
