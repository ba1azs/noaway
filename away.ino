#include <BleMouse.h>

BleMouse bleMouse("Logitech wireless", "aerovad", 100);

const int distance = 50;
const int interval = 1000; // 60 sec

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
  bleMouse.setBatteryLevel(95);   // initial battery level
}

void loop() {

  if (!bleMouse.isConnected()) return;

  unsigned long now = millis();

  if (now - lastMove >= interval) {
    jiggle();
    lastMove = now;
  }

}
