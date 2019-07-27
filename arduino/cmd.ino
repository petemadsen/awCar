#define CMD_MAX_BUF_SIZE 20
uint8_t cmd_rcv_buffer[CMD_MAX_BUF_SIZE + 1];
uint8_t cmd_rcv_buffer_len = 0;

void cmd_init()
{
}


void cmd_put(Stream& io)
{
	char ch = io.read();

	// end of command
	if (ch < ' ' || ch > 'z')
	{
		if (cmd_rcv_buffer_len)
		{
			cmd_rcv_buffer[cmd_rcv_buffer_len] = 0;
			bool ok = cmd_parse(io);
			cmd_rcv_buffer_len = 0;
			io.println(ok ? F("ok") : F("err"));
		}
		return;
	}

	// new char
	if (cmd_rcv_buffer_len < CMD_MAX_BUF_SIZE)
	{
		cmd_rcv_buffer[cmd_rcv_buffer_len++] = ch;
		return;
	}

	io.println(F("bad"));
}



bool cmd_parse(Stream& io)
{
    int cmd = cmd_rcv_buffer[0];
    int sub = cmd_rcv_buffer[1];

	switch(cmd)
    {
	// head
    case 'h':
      switch (sub)
      {
        case 'l':
          head_max_left();
          break;
        case 'r':
          head_max_right();
          break;
        case 'c':
          head_center();
          break;
        default:
          io.println(F("I don't know sub("));
          io.print(sub);
          io.println(F(")"));
      }
      break;
	// motor
    case 'm':
      break;
    default:
      io.println(F("I don't know cmd("));
      io.print(cmd);
      io.println(F(")"));
      break;
    }
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
    Serial.println("--done");
  }
#endif
