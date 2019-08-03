const int ir_first_pin = pin_ir4;
const int ir_last_pin = pin_ir4;


void ir_init()
{
	pinMode(pin_ir4, INPUT);
}


void ir_loop()
{
/*
	int val = digitalRead(pin_ir4);
	Serial.print("ir4 ");
	Serial.println(val);

	delay(500);
*/
}


bool ir_cmd(int cmd, Stream& io)
{
	switch (cmd)
	{
	case 's':
		io.print("[ir]");
		for (int i=ir_first_pin; i<=ir_last_pin; ++i)
		{
			int val = digitalRead(pin_ir4);
			io.print(" ");
			io.print(val);
		}
		io.println();
		return true;
	default:
		io.println(F("[ir] I don't know("));
		io.print(cmd);
		io.println(F(")"));
		return false;
	}

	return false;
}
