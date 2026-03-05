#include <BleMouse.h>

BleMouse bleMouse("Logitech wireless", "OpenAI", 100);

const int distance = 3;
const int interval = 60000; // 1 second

unsigned long lastMove = 0;

void jiggle() {
  if (!bleMouse.isConnected()) return;

  int x = random(3) - 1;
  int y = random(3) - 1;

  for (int i = 0; i < distance; i++) {
    bleMouse.move(x, y);
    delay(2);
  }

  for (int i = 0; i < distance; i++) {
    bleMouse.move(-x, -y);
    delay(2);
  }
}

void setup() {
  bleMouse.begin();
}

void loop() {

  if (!bleMouse.isConnected()) return;

  unsigned long now = millis();

  if (now - lastMove >= interval) {
    jiggle();
    lastMove = now;
  }

}
