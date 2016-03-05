#ifndef LedOutput_h
#define LedOutput_h

class LedOutput{
  private:
    short qnt;
    short basePin;

  public:
    LedOutput(short q, short p){
      qnt = q;
      basePin = p;
    }

    void initialize(){
      for (int i=0; i<qnt; i++) pinMode(basePin + i, OUTPUT);
    }

    void turnLedOn(short i){
      digitalWrite(basePin + i, HIGH);
    }

    void turnLedOff(short i){
      digitalWrite(basePin + i, LOW);
    }

    void turnOnlyLedOn(short i){
      turnAllLedsOff();
      turnLedOn(i);
    }
    void turnAllLedsOn(){
      for (int i=0; i<qnt; i++) turnLedOn(i);
    }

    void turnAllLedsOff(){
      for (int i=0; i<qnt; i++) turnLedOff(i);
    }

    void blinkAll(){
      turnAllLedsOn();
      delay(200);
      turnAllLedsOff();
    }

    void blinkLed(short led){
      turnOnlyLedOn(led);
      delay(400);
      turnAllLedsOff();
    }
};

#endif
