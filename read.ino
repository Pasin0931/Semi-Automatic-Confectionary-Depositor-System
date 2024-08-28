void read_limit()
{
  limit_base = digitalRead(30);
  limit_feed = digitalRead(31);
  //Serial.print(limit_base);  Serial.print(",");  Serial.println(limit_feed);
}

void read_bt()
{
  bt_red = digitalRead(24);
  bt_green = digitalRead(25);
  //Serial.print(bt_red);  Serial.print(",");  Serial.println(bt_green);
}
