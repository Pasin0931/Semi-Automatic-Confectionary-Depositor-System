void feed(int speed1, int Times) {
  long now_times = millis();
  while (millis() - now_times < Times) {
      motor(1, speed1);    
      read_bt();
    if(bt_red == 1)
    {
      break;
    }else if (limit_base == 0)
    {
      motor(2, 0);    

    }
  }
      motor(1, 0);    

}
