#include "arduino.h"
#include "Menu.h"
#include "myscancodes.h"
#include "LeoKey.h"
#include "Keyboard.h"

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
			if (specialKeyCodes[j] == keys[i])
			{
				keyName = specialKeyNames[j];
				break;
			}
		}
		Serial.print(keyName);
		Serial.print("\t");
	}
	Serial.println();
}

void Menu::availSpecialKeys()
{
	Serial.print("a-z A-Z 0-9 !-) ~`-_=+[{]}\\|;:'\",<.>/? ");
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
			if (c >= '0' && c <= '6')
			{
				state = c - '0';

				if (state == DEFAULT_STATE)
				{
					availSpecialKeys();
					state = DEFAULT_STATE;
					mainMenu();
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
	}
	else
	{
		input.toLowerCase();
		const char* strinput = input.c_str();
		bool foundFlag = false;
		for (int i = 0; i < SPECIAL_CHARS_NO; i++)
		{
			if (strcmp(specialKeyNames[i], strinput) == 0)
			{
				keys[state] = specialKeyCodes[i];
				foundFlag = true;
			}
		}
		if (!foundFlag)
		{
			Serial.println("Unknown key!");
		}
	}
	Keyboard.releaseAll();
	state = DEFAULT_STATE;
	mainMenu();
}
