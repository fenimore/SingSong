#ifndef SingSong
#define SingSong_h

#include "Arduino.h"

class SingSong {
  public:
    SingSong(int buz);
    void playThereminMap(int cm, int max);
    void playThereminScale(int cm, int scale);
    void playScale(int scale);
    void playSong(int song);
  private:
    int _buz;
};


#endif
