/*
  Junior Stair Light Project
  ==========================
  This is an Arduino Nano based project. The idea is to illuminate
  a flight of stairs with some dirt cheap LED stripes, also adding
  some animation (dimming). All triggered by IR sensors.
  
  Project cost: 50€ max!
  
  I was equiping my own stairs with some RGBWW  NeoPixels, while a
  friend  of  mine  was  inspired  and  went  out  shopping on the
  internet  on a shoestring. He bought LED stripes from an obscure
  company (XINBAN). 9€ for 8 strips,  30cm  and  15LEDs each, they
  need 12V to operate.  While  crappy, I thought I could still add
  some animation and dimming functionality to it.

  I have used the Arduino-SoftPWM, which allows  you  to  use  all
  digital  AND  analog  pins for PWM. This flight of stairs has 13
  steps, but in this  configuration this project can be used up to
  18 steps.
*/

#include <SoftPWM.h>
SOFTPWM_DEFINE_CHANNEL(2, DDRD, PORTD, PORTD2);  //Arduino pin D2
SOFTPWM_DEFINE_CHANNEL(3, DDRD, PORTD, PORTD3);  //Arduino pin D3
SOFTPWM_DEFINE_CHANNEL(4, DDRD, PORTD, PORTD4);  //Arduino pin D4
SOFTPWM_DEFINE_CHANNEL(5, DDRD, PORTD, PORTD5);  //Arduino pin D5
SOFTPWM_DEFINE_CHANNEL(6, DDRD, PORTD, PORTD6);  //Arduino pin D6
SOFTPWM_DEFINE_CHANNEL(7, DDRD, PORTD, PORTD7);  //Arduino pin D7
SOFTPWM_DEFINE_CHANNEL(8, DDRB, PORTB, PORTB0);  //Arduino pin D8
SOFTPWM_DEFINE_CHANNEL(9, DDRB, PORTB, PORTB1);  //Arduino pin D9
SOFTPWM_DEFINE_CHANNEL(10, DDRB, PORTB, PORTB2);  //Arduino pin D10
SOFTPWM_DEFINE_CHANNEL(11, DDRB, PORTB, PORTB3);  //Arduino pin D11
SOFTPWM_DEFINE_CHANNEL(12, DDRB, PORTB, PORTB4);  //Arduino pin D12
SOFTPWM_DEFINE_CHANNEL(13, DDRB, PORTB, PORTB5);  //Arduino pin D13
SOFTPWM_DEFINE_CHANNEL(14, DDRC, PORTC, PORTC0);  //Arduino pin A0
SOFTPWM_DEFINE_OBJECT_WITH_PWM_LEVELS(20, 100);
SOFTPWM_DEFINE_EXTERN_OBJECT_WITH_PWM_LEVELS(20, 100);

void setup() {
  Serial.begin(19200);
  // begin with 60hz pwm frequency
  Palatis::SoftPWM.begin(60);
  // print interrupt load for diagnostic purposes
  Palatis::SoftPWM.printInterruptLoad();
}

static volatile uint8_t v = 0;
int analog_threshold = 100;
int animation_duration = 30000;
int pra=analogRead(7);
int prb=analogRead(6);
int time_s, time_c;

void loop() {
    delay(100);
    
     // while(true){
     pra=analogRead(7);
     prb=analogRead(6);
     // Serial.println("-----------------");
     Serial.println(pra);
     Serial.println(prb);
     //  delay(1000);
    // }

    
    // Direction 1 on
    if ( pra > analog_threshold ) {
      for (uint8_t i = 2; i < 15; ++i) {
        Serial.print(micros());
        Serial.print(" loop(): ");
        Serial.println(i);
        unsigned long const WAIT = 600000 / Palatis::SoftPWM.PWMlevels() / 2;
        unsigned long nextMicros = 0;
        for (int v = 0; v < Palatis::SoftPWM.PWMlevels() - 1; ++v) {
          while (micros() < nextMicros);
          nextMicros = micros() + WAIT;
          Palatis::SoftPWM.set(i, v);
        }
      }
      
      // set a start timer, so we know how much time has passed
      time_s = millis();
      while(true) {
        delay(100);
        Serial.print(".");
        // read the "other" PRI
        prb=analogRead(6);
        // this exits the while loop when we detect the other PRI triggered
        if ( prb > analog_threshold ) {
          break;
        }
        // this exists the while loop when animation_duration seconds have passed
        time_c = millis();
        if ((time_c - time_s) > animation_duration) {
          break;
        }
      }
      
      // Direction 1 off
      for (uint8_t i = 2; i < 15; ++i) {
        Serial.print(micros());
        Serial.print(" loop(): ");
        Serial.println(i);
        unsigned long const WAIT = 600000 / Palatis::SoftPWM.PWMlevels() / 2;
        unsigned long nextMicros = 0;
        for (int v = Palatis::SoftPWM.PWMlevels() - 1; v >= 0; --v) {
          while (micros() < nextMicros);
          nextMicros = micros() + WAIT;
          Palatis::SoftPWM.set(i, v);
        }
      }
      delay(1000);
    }
    
    pra=analogRead(7);
    prb=analogRead(6);
    // Direction 2 on
    if (prb > analog_threshold) {
      for (uint8_t i = 14; i > 1; --i) {
        Serial.print(micros());
        Serial.print(" loop(): ");
        Serial.println(i);
        unsigned long const WAIT = 600000 / Palatis::SoftPWM.PWMlevels() / 2;
        unsigned long nextMicros = 0;
        for (int v = 0; v < Palatis::SoftPWM.PWMlevels() - 1; ++v) {
          while (micros() < nextMicros);
          nextMicros = micros() + WAIT;
          Palatis::SoftPWM.set(i, v);
        }
      }

      // set a start timer, so we know how much time has passed
      time_s = millis();
      while(true) {
        delay(100);
        Serial.print(".");
        // read the "other" PRI
        prb=analogRead(7);
        // this exits the while loop when we detect the other PRI triggered
        if ( prb > analog_threshold ) {
          break;
        }
        // this exists the while loop when animation_duration seconds have passed
        time_c = millis();
        if ((time_c - time_s) > animation_duration) {
          break;
        }
      }
      
      // Direction 2 off
      for (uint8_t i = 14; i > 1; --i) {
        Serial.print(micros());
        Serial.print(" loop(): ");
        Serial.println(i);
        unsigned long const WAIT = 600000 / Palatis::SoftPWM.PWMlevels() / 2;
        unsigned long nextMicros = 0;
        for (int v = Palatis::SoftPWM.PWMlevels() - 1; v >= 0; --v) {
          while (micros() < nextMicros);
          nextMicros = micros() + WAIT;
         Palatis::SoftPWM.set(i, v);
        }
      }
      delay(1000);
    }    
  }
