#include "arduino.h"
#include "Menu.h"
#include "myscancodes.h"
#include "LeoKey.h"

Menu::Menu(unsigned char* keys)
{
	this->keys = keys;
}

void Menu::mainMenu()
{
	String keyName;
	Serial.println(greet);
	for (int i = 0; i < PIN_NO; i++)
	{
		if (keys[i] >= '!' && keys[i] <= '~') 
		{
			keyName = (String)((char)keys[i]);
		}
		else for (int j = 0; j < SPECIAL_CHARS_NO; j++)
		{
			unsigned char specialKeyCode = specialKeyCodes[j] < FIRST_MOD_CODE
				? specialKeyCodes[j] + PRINTABLE_OFFSET
				: specialKeyCodes[j];

			if (specialKeyCode == keys[i])
			{
				keyName = specialKeyNames[j];
				break;
			}
		}
		Serial.print(keyName);
		Serial.print('(');
		Serial.print(keys[i], HEX);
		Serial.print(")\t");
	}
	Serial.println();
}

void Menu::availSpecialKeys()
{
	for (int i = 0; i < SPECIAL_CHARS_NO; i++)
	{
		Serial.print(specialKeyNames[i]);
		Serial.print(' ');
	}
	Serial.println();
}

void Menu::processInput(String input)
{
	Serial.print(state);
	Serial.print(" > ");
	Serial.println(input);

	if (state == DEFAULT_STATE)
	{
		if (input.length() == 1)
		{
			char c = input.charAt(0);
			if (c >= '0' && c <= '7')
			{
				state = c - '0';

				if (state == 7)
				{
					availSpecialKeys();
					state = 6;
					return;
				}

				Serial.print("State ");
				Serial.print(state);
				Serial.print(": ");
				Serial.print(question);
				return;
			}
		}
		Serial.println("Unknown command!");
		mainMenu();
		return;
	}

	if (input.length() == 1)
	{
		keys[state] = input.charAt(0);
		state = DEFAULT_STATE;
		mainMenu();
		return;
	}
	else
	{
		input.toLowerCase();
		const char* strinput = input.c_str();
		for (int i = 0; i < SPECIAL_CHARS_NO; i++)
		{
			if (strcmp(specialKeyNames[i], strinput) == 0)
			{
				keys[state] = specialKeyCodes[i] < FIRST_MOD_CODE
					? specialKeyCodes[i] + PRINTABLE_OFFSET
					: specialKeyCodes[i];
				state = DEFAULT_STATE;
				mainMenu();
				return;
			}
		}
		Serial.println("Unknown key!");
	}
	state = DEFAULT_STATE;
	mainMenu();
}
