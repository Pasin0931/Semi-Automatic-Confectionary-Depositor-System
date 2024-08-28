#include <ATX2.h>
int limit_base, limit_feed, bt_red, bt_green;
int base_motor, feed_motor;
void setup() {

  Serial.begin(9600);
  pinMode(31, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, OUTPUT); //red
  pinMode(27, OUTPUT); //yellow
  pinMode(28, OUTPUT); //green

  digitalWrite(26, HIGH);
  //glcdFillScreen(GLCD_RED);


  //beep();
  delay(1000);

  digitalWrite(26, LOW);
//  glcdClear();
// glcdFillScreen(GLCD_RED);
// glcdClear();
}
void loop() {

  digitalWrite(27, HIGH);
  //glcdFillScreen(GLCD_YELLOW);

  while (true)
  {
    read_bt();
    if (bt_green == 1)
    {
      break;
    }
  }
  digitalWrite(27, LOW);
  digitalWrite(28, HIGH);

  // motor(2,-30); delay(500);
  read_limit();
  while (limit_base != 0)
  {
    read_bt();
    if (bt_red == 1)
    {
      break;
    }
    motor(2, -30); // เดิน
    read_limit();
    if (limit_feed == 0)
    {
      ao();
      feed(-100, 3000);
      motor(2, -30); // เดิน
      delay(500);

    }
    if (limit_base == 0)
    {
      ao();
    }
  }
  ao();
  feed_Home();
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  digitalWrite(28, LOW);

  //motor(2,-30); delay(500); ao();
}
