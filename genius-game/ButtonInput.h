#ifndef ButtonInput_h
#define ButtonInput_h


class ButtonInput{
  private:
    short qnt;
    short basePin;

    short lastIn = -1;
    LedOutput *ledOutput;

  public:
    ButtonInput(LedOutput *out, short q, short p){
      qnt = q;
      basePin = p;
      ledOutput = out;
    }

    void initialize(){
      for (int i=0; i<qnt; i++) {
        pinMode(basePin + i, INPUT);
        digitalWrite(basePin + i, HIGH);
      }
    }

    short read(){
      short in = readPushedBtn();
      if (in >= 0){
        lastIn = in;
        ledOutput->turnLedOn(in);
      } else if (lastIn >= 0){
        ledOutput->turnAllLedsOff();
        in = lastIn;
        lastIn = -1;
        return in;
      }
      return -1;
    }

    short readPushedBtn(){
      for (int i=0; i<qnt; i++) if(digitalRead(basePin + i)==HIGH) return i;
      return -1;
    }
};

#endif
