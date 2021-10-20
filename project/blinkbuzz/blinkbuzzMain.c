#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main() {  

  configureClocks();
  switch_init();
  buzzer_init();
  led_init();
  enableWDTInterrupts();

  or_sr(0x18);  // CPU off, GIE on
} 
