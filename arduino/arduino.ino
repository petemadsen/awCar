



void setup() {
  Serial.begin(9600);

  motor_init();
  Serial.println("--ready");

  delay(5 * 1000);
  motor_demo();
}

void loop()
{
  if (Serial.available())
  {
    int cmd = Serial.read();
    if (cmd < '0' || cmd > 'z')
      return;
    Serial.print(">>");
    Serial.println(cmd);
    switch(cmd)
    {
      case 's':
        motor_stop();
        break;
      case 'f':
        motor_forward();
        delay(1 * 1000);
        motor_stop();
        break;
      case 'b':
        motor_backward();
        delay(1 * 1000);
        motor_stop();
        break;
      case '1':
        motor_speed(128);
        break;
      case '2':
        motor_speed(192);
        break;
      case '3':
        motor_speed(255);
        break;
      case 'l':
        motor_left();
        break;
      case 'r':
        motor_right();
        break;
      case 'd':
        motor_demo();
        break;
      case 't':
        motor_test();
        break;
      default:
        Serial.println("I don't know");
        break;
    }
    Serial.println("--done");
  }
}
