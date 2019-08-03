void setup()
{
	Serial.begin(9600);

	cmd_init();
	Serial.println(F("[init] cmd"));

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
	while (Serial.available())
	{
		cmd_put(Serial);
	}

	ir_loop();
}
