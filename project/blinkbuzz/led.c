#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  //if (switch_state_changed) {
  if (switch_state_changed) {
    buzzer_set_period(0);
    
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down ? LED_GREEN : LED_RED;

    P1OUT &= (0xff ^ LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}
