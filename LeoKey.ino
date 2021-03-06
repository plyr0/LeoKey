#include "Keyboard.h"
#include "Menu.h"
#include "LeoKey.h"

int pins[PIN_NO];
unsigned char keys[PIN_NO] = { KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, 'a', 's'};
String input;
Menu menu(keys);

inline bool readInput()
{
	if (Serial.available() > 0)
	{
		input = Serial.readStringUntil('\n');
		input.trim();
		return true;
	}
	return false;
}

inline void readJoy()
{
	for (int i = 0; i < PIN_NO; i++)
	{
		pins[i] = digitalRead(i + PIN_OFFSET);
	}
}

inline void writeKeyboard()
{
	for (int i = 0; i < PIN_NO; i++)
	{
		if (pins[i] == LOW)
		{
			Keyboard.press(keys[i]);
		}
		else
		{
			Keyboard.release(keys[i]);
		}
	}
}

void setup()
{
	Serial.begin(9600);
	Keyboard.begin();
	for (int i = 0; i < PIN_NO; i++)
	{
		pinMode(i + PIN_OFFSET, INPUT_PULLUP);
	}
}

void loop()
{
	if (readInput())
	{
		menu.processInput(input);
	}
	readJoy();
	writeKeyboard();
	delay(1);
}
