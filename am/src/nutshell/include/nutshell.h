#ifndef __NUTSHELL_H__
#define __NUTSHELL_H__

#include <klib-macros.h>

#include ISA_H // "x86.h", "mips32.h", ...

# define RTC_ADDR     0x3800bff8
# define SCREEN_ADDR  0x40001000
# define SYNC_ADDR    0x40001004
# define FB_ADDR      0x50000000

#define CONFREG_BASE_ADDR        (0xbfaf0000)
#define CONFREG_CR0_ADDR            (CONFREG_BASE_ADDR + 0x8000)
#define CONFREG_CR1_ADDR            (CONFREG_BASE_ADDR + 0x8010)
#define CONFREG_CR2_ADDR            (CONFREG_BASE_ADDR + 0x8020)
#define CONFREG_CR3_ADDR            (CONFREG_BASE_ADDR + 0x8030)
#define CONFREG_CR4_ADDR            (CONFREG_BASE_ADDR + 0x8040)
#define CONFREG_CR5_ADDR            (CONFREG_BASE_ADDR + 0x8050)
#define CONFREG_CR6_ADDR            (CONFREG_BASE_ADDR + 0x8060)
#define CONFREG_CR7_ADDR            (CONFREG_BASE_ADDR + 0x8070)
#define CONFREG_LED_ADDR            (CONFREG_BASE_ADDR + 0xf020)   //32'hbfaf_f020 
#define CONFREG_LED_RG0_ADDR        (CONFREG_BASE_ADDR + 0xf030)  //32'hbfaf_f030 
#define CONFREG_LED_RG1_ADDR        (CONFREG_BASE_ADDR + 0xf040)   //32'hbfaf_f040 
#define CONFREG_NUM_ADDR            (CONFREG_BASE_ADDR + 0xf050)   //32'hbfaf_f050 
#define CONFREG_SWITCH_ADDR         (CONFREG_BASE_ADDR + 0xf060)   //32'hbfaf_f060 
#define CONFREG_BTN_KEY_ADDR        (CONFREG_BASE_ADDR + 0xf070)   //32'hbfaf_f070
#define CONFREG_BTN_STEP_ADDR       (CONFREG_BASE_ADDR + 0xf080)   //32'hbfaf_f080
#define CONFREG_SW_INTER_ADDR       (CONFREG_BASE_ADDR + 0xf090)   //32'hbfaf_f090 
#define CONFREG_TIMER_ADDR          (CONFREG_BASE_ADDR + 0xe000)   //32'hbfaf_e000

#define CONFREG_FREQ_ADDR           (0xbfd0f030)   //32'hbfd0_f030

#define CONFREG_IO_SIMU_ADDR        (CONFREG_BASE_ADDR + 0xff00)   //32'hbfaf_ff00
#define CONFREG_VIRTUAL_UART_ADDR   (CONFREG_BASE_ADDR + 0xff10)   //32'hbfaf_ff10
#define CONFREG_SIMU_FLAG_ADDR      (CONFREG_BASE_ADDR + 0xff20)   //32'hbfaf_ff20 
#define CONFREG_OPEN_TRACE_ADDR     (CONFREG_BASE_ADDR + 0xff30)   //32'hbfaf_ff30
#define CONFREG_NUM_MONITOR_ADDR    (CONFREG_BASE_ADDR + 0xff40)   //32'hbfaf_ff40


#endif
