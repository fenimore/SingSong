#include "pitches.h"

// Scales are eight notes, with the last being do
const int C_MAJOR[] = {
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4
};
const int G_MINOR[] = {
  NOTE_G3, NOTE_A3, NOTE_CS3, NOTE_C3, NOTE_D3, NOTE_FS3, NOTE_F3, NOTE_G4
};
const int D_MAJOR[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, 0, NOTE_A4, NOTE_B4
};

const int TEMPO_SCALE[] = {
  8, 8, 8, 8, 8, 8, 8, 4
};
const int PAUSE_SCALE = 1000 / 8 * 1.8;


// SCRAP
//magic numbers that make the intervals sound pleasing
//const double gap = 1.148698355;  //ratio of consecutive notes (pentatonic)
                             // it's the 5th root of 2
//double gap = 1.059463094;  //ratio of consecutive notes (chromatic)
                              // its the 12th root of 2


