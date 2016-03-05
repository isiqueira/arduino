#include "LedOutput.h"
#include "ButtonInput.h"
#include "GeniusGame.h"

LedOutput ledOutput(4, 2);
ButtonInput btnInput(&ledOutput, 4, 8);
GeniusGame game(&btnInput, &ledOutput);

void setup() {
  ledOutput.initialize();
  btnInput.initialize();
  game.start();
}

void loop() {
  game.process();
  delay(100);
}
