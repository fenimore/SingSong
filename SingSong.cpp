/*
  SingSong.cpp - Library Buzzing Theremin.
  Created by Fenimore, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SingSong.h"
#include "pitches.h"
#include "scales.h"
#include "melodies.h"

volatile int val;

SingSong::SingSong(int buz){
  pinMode(buz, OUTPUT);
  _buz = buz;
}


void SingSong::playThereminMap(int cm, int max){
    // Change the mapping based on the range of
    // of centimeters effected
    val = map(cm, 0, max, 31, 4978); // 31 to 4978 I found in pitches.h
    tone(_buz, val);
}

// returns duration of distance in microseconds
void SingSong::playThereminScale(int cm, int scale){
  // tone(buzzer_pin, frequency, duration of note);
  // This is theremin mode
  // TODO: take input for scale
  // case
  if (cm < 5){
    Serial.println("do");
    noTone(_buz);
  }  else if(cm < 10) {
    Serial.println("re");
    tone(_buz, C_MAJOR[0]);
  } else if(cm < 15) {
    Serial.println("re");
    tone(_buz, C_MAJOR[1]);
  } else if(cm < 20) {
    Serial.println("mi");
    tone(_buz, C_MAJOR[2]);
  } else if(cm < 25) {
    Serial.println("fa");
    tone(_buz, C_MAJOR[3]);
  } else if(cm < 30) {
    Serial.println("so");
    tone(_buz, C_MAJOR[4]);
  } else if(cm < 35) {
    Serial.println("la");
    tone(_buz, C_MAJOR[5]);
  } else if(cm < 40) {
    Serial.println("te");
    tone(_buz, C_MAJOR[6]);
  } else if(cm < 45) {
    Serial.println("do");
    tone(_buz, C_MAJOR[7]);
  } //else if(cm > 130) {
    //Serial.println("do");
    //noTone(_buz);
  //} // This doesn't work as expected
}

void SingSong::playScale(int scale){
switch (scale) {
    case 1:
      // for (int i =0; this < scale.length; i++) {}
      for (int i = 0; i < 8; i++) {
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int _noteDuration = 1000 / TEMPO_SCALE[i];
          tone(_buz, C_MAJOR[i], _noteDuration);
          delay(PAUSE_SCALE);
          // stop the tone playing:
          noTone(_buz);
      }
      break;
    case 2:
      // G Minor
      for (int i = 0; i < 8; i++) {
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int _noteDuration = 1000 / TEMPO_SCALE[i];
          tone(_buz, G_MINOR[i], _noteDuration);
          delay(PAUSE_SCALE);
          // stop the tone playing:
          noTone(_buz);
      }
      break;
    case 3:
      // D Major
      for (int i = 0; i < 8; i++) {
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int _noteDuration = 1000 / TEMPO_SCALE[i];
          tone(_buz, D_MAJOR[i], _noteDuration);
          delay(PAUSE_SCALE);
          // stop the tone playing:
          noTone(_buz);
      }
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
    break;
  }
 
}

void SingSong::playSong(int song){
switch (song) {
    case 1:
      // Melody Test
      for (int i = 0; i < (sizeof(MELODY_TEST))-1; i++) {
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int _noteDuration = 1000 / TEMPO_TEST[i];
          tone(_buz, MELODY_TEST[i], _noteDuration);
          delay(PAUSE_SCALE);
          // stop the tone playing:
          noTone(_buz);
      }
      break;
    case 2:
      // MARIO melody
      for (int i = 0; i < (sizeof(MELODY_MARIO))-1; i++) {
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int _noteDuration = 1000 / TEMPO_MARIO[i];
          int _PAUSE = _noteDuration * 1.30;
          tone(_buz, MELODY_MARIO[i], _noteDuration);
          delay(_PAUSE);
          // stop the tone playing:
          noTone(_buz);
      }
      break;
    case 3:
      // MARIO melody
      for (int i = 0; i < (sizeof(MELODY_UNDERWORLD) - 1); i++) {
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int _noteDuration = 1000 / TEMPO_UNDERWORLD[i];
          int _PAUSE = _noteDuration * 2.20;
          tone(_buz, MELODY_UNDERWORLD[i], _noteDuration);
          delay(_PAUSE);
          Serial.println(MELODY_UNDERWORLD[i]);
          // stop the tone playing:
          noTone(_buz);
      }
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
    break;
  }

}

