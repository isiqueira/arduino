#define START_MODE 0
#define REPLAY_MODE 1
#define PLAY_MODE 2

#ifndef GeniusGame_h
#define GeniusGame_h

class GeniusGame{
  private:
    ButtonInput *input;
    LedOutput *ledOutput;

    short gameOrder[100];
    short gamePos = -1;
    short playPos = -1;

    short currentMode = START_MODE;

  public:
    GeniusGame(ButtonInput *in, LedOutput *out){
      input = in;
      ledOutput = out;
      randomSeed(analogRead(0));
    }

    void start(){
      gamePos = -1;
      playPos = -1;
      for(int i=0; i<3; i++){
        ledOutput->blinkAll();
        delay(100);
      }
      currentMode = REPLAY_MODE;
    }

    void replay(){
      gamePos++;
      gameOrder[gamePos] = random(4);
      for (int i=0; i<=gamePos; i++){
        ledOutput->blinkLed(gameOrder[i]);
        delay(200);
      }
      currentMode = PLAY_MODE;
    }

    void finish(){
      for(int i=0; i<5; i++){
        ledOutput->blinkAll();
        delay(50);
      }
    }

    void validateInput(short in){
      playPos++;
      if (in == gameOrder[playPos]){
        if (playPos == gamePos){
          playPos = -1;
          currentMode=REPLAY_MODE;
        } else {
          currentMode=PLAY_MODE;
        }
      } else {
        finish();
        start();
      }
    }

    void process(){
       if (currentMode==REPLAY_MODE){
        replay();
      } else {
        int in = input->read();
        if (in >= 0){
          validateInput(in);
        }
      }
    }

};

#endif
