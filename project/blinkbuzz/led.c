#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachine.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
}

// green blinking lights
void greenLights(){
  for(int i = 0; i < 10; i++){ // loop to blink the lights 10 times
    P1OUT = LED_GREEN;         // turn on GREEN LED
    __delay_cycles(800000);    // delay program at 800000 clock cycles
    P1OUT = !LED_GREEN;        // turn off GREEN LED
    __delay_cycles(800000);    // delay again
  }
}
// red blinking lights
void redLights(){
  for(int i = 0; i < 10; i++){ // loop to blink the lights 10 times
    P1OUT = LED_RED;           // turn ON RED LED
    __delay_cycles(800000);    // delay program at 800000 clock cycles
    P1OUT = !LED_RED;          // turn OFF RED LED
    __delay_cycles(800000);    // delay again
  }
}

// alternating green and red lights while delaying clock cycles
void bothLights(){
  for(int j = 0; j < 10; j++){
    P1OUT = LED_RED;
    __delay_cycles(800000);
    P1OUT = LED_GREEN;
    __delay_cycles(800000);
    P1OUT = !LED_RED;
    __delay_cycles(800000);
    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
}

// this method is used to blink the light fast enough to make it dim
void dimLights(){
  for(int j= 0; j <10000; j++){ // turn LEDs on and off 10000 times
    P1OUT = LED_RED;
    P1OUT = LED_GREEN;
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}

// dim blinking both LEDs
void dimBlink(){
  for(int i = 0; i < 20; i++){
    dimLights();
    __delay_cycles(2000000);
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */
    ledFlags |= switch_state_down ? LED_RED : 0;
    ledFlags |= switch_state_down ? 0 : LED_GREEN;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}
