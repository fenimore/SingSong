#ifndef SingSong
#define SingSong_h

#include "Arduino.h"

class SingSong {
  public:
    SingSong(int buz);
    void playTheremin(int cm, int scale);
    void playScale(int scale);
    void playSong(int song);
  private:
    int _buz;
};


#endif
