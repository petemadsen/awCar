



void setup() {
  Serial.begin(9600);

  motor_init();
  Serial.println(F("[init] motor"));

  head_init();
  Serial.println(F("[init] head"));
  
  Serial.println(F("[init] done"));

  //delay(5 * 1000);
  //motor_demo();
}

void loop()
{
  if (Serial.available() >= 2)
  {
    int cmd = Serial.read();
    int sub = Serial.read();
    while (Serial.available())
      Serial.read();

    if (cmd < '0' || cmd > 'z')
      return;
    Serial.print(">>");
    Serial.println(cmd);

    switch(cmd)
    {
    case 'h':
      switch (sub)
      {
        case 'l':
          head_left();
          break;
        case 'r':
          head_right();
          break;
        case 'f':
          head_front();
          break;
        default:
          Serial.println(F("I don't know sub("));
          Serial.print(sub);
          Serial.println(F(")"));
      }
      break;
    case 'm':
      break;
    default:
      Serial.println(F("I don't know cmd("));
      Serial.print(cmd);
      Serial.println(F(")"));
      break;
    }

#if 0
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
        Serial.print("I don't know (");
        break;
    }
#endif
    Serial.println("--done");
  }
}
