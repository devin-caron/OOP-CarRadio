/*
 *FILE         : AmFmRadio.cpp
 *DESCRIPTION  : Stores all the functions within the PioneerCarRadio class.
 */

#include <conio.h>
#include "PioneerCarRadio.h"


 /*
	 Name	 : PioneerCarRadio -- CONSTRUCTOR
	 Purpose : to instantiate a new PioneerCarRadio object - given an on value,
			   this class inherits from AmFmRadio class.
	 Inputs	 :	on		Bool		state of the power (on / off)
	 Outputs :	NONE
	 Returns :	NONE
 */
PioneerCarRadio::PioneerCarRadio(bool on, char* names) : AmFmRadio(on)
{
	strcpy(name, names);
}

/* 
	Name	: PioneerCarRadio -- DESTRUCTOR
	Purpose : to destroy the PioneerCarRadio object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	outputs a final message from the object before being destroyed
	Returns	:	NONE
*/
PioneerCarRadio::~PioneerCarRadio()
{
	printf("\nPioneerCarRadio is being destroyed.\n");
}



/*
	Name	: ShowSettings
	Purpose : this method is to be called in order to take a snapshot of the current
			  attribute values
	Inputs	:	NONE
	Outputs	:	A snapshot of the current attribute values
	Returns	:	NONE
*/
void PioneerCarRadio::ShowCurrentSettings(void)
{
	// storing buttons in struct array
	Freqs* buttons = GetButtons();
	char* frequency = GetFrequency();

	// bool variable to check if input loop needs to end
	int endLoop = false;

	// menu loop until user presses 'x'
	do
	{
			// displaying radio attributes
			printf("\n\n%s\n", name);
			if (IsRadioOn() == false)		// if radio is not on
			{
				printf("Radio is off \n");
			}
			else							// else radio is on
			{
				printf("Radio is on \n");

				printf("Volume: %d\n", GetVolume());

				// checking what the frequency is to only display decimal point on FM for proper format
				if (strcmp(frequency, "AM") == 0)
				{
					printf("Current Station:    %.0f %s\n", GetCurrent_Station(), GetFrequency());
				}
				else
				{
					printf("Current Station:   %.1f %s\n", GetCurrent_Station(), GetFrequency());
				}

				printf("AM Buttons:\n");
				for (int i = 0; i < 5; ++i)	  // loop to display all 5 AM buttons
				{
					printf("%d: %6d", i + 1, buttons[i].AMFreq);
					if (i < 4)
					{
						printf(", ");
					}
				}
				if (strcmp(name, "Pioneer XS440") == 0)
				{

					printf("\nFM Buttons:\n");
					for (int j = 0; j < 5; ++j)	   // loop to display all 5 FM buttons
					{
						printf("%d: %6.1f", j + 1, buttons[j].FMFreq);
						if (j < 4)
						{
							printf(", ");
						}
					}
				}
			}
			printf("\n\n");


			// user input function deciding what to do to the pioneer class
			endLoop = GetMenuOption();
	} while (endLoop != true);
}

/*
	Name	: GetMenuOption
	Purpose : this method is used to get a button press
			  from the user and determine if it's a valid
			  radio input and changes the radios attributes
			  if it is. Ends the input if 'x' is entered.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	bool, false if user has not entered 'x'
				True if they have
*/
bool PioneerCarRadio::GetMenuOption()
{
	// Setting accepted menu options for switch statement
	enum menuItems
	{
		kMenuNothing = 0,
		kMenuToggleOnOff = 'o',
		kMenuVolumeUp = '+', kMenuVolumeDown = '_',
		kMenuScanUp = '=', kMenuScanDown = '-',
		kMenuToggleAMFM = 'b',
		kMenuButtonOne = '1', kMenuButtonTwo = '2', kMenuButtonThree = '3', kMenuButtonFour = '4', kMenuButtonFive = '5',
		kMenuSetButtonOne = '!', kMenuSetButtonTwo = '@', kMenuSetButtonThree = '#', kMenuSetButtonFour = '$', kMenuSetButtonFive = '%',
		kMenuQuit = 'x'
	};


	menuItems	choice = kMenuNothing; // storing the enums

	// volume int variable to store the current volume
	int volume = GetVolume();

	// option char variable to store user button press
	char option;
	// using getch() to get a users button press
	option = getch();
	choice = (menuItems)(option);

	bool endLoop = false;	// return value, only true if user ends program with 'x'

	if (IsRadioOn() == false && choice != 'o' && choice != 'x')
	{
		// do nothing if radio is off unless its to power on radio or end program
	}
	else
	{
		// switch statement with all menu inputs
		switch (choice)
		{
		case  kMenuToggleOnOff:		// toggles power
			PowerToggle();
			break;
		case  kMenuVolumeUp:		// increases volume by 1
			volume++;
			SetVolume(volume);
			break;
		case  kMenuVolumeDown:		// decreases volume by 1
			volume--;
			SetVolume(volume);
			break;
		case  kMenuScanUp:			// scans up frequency by 10 for AM and 0.2 for FM
			ScanUp();
			break;
		case  kMenuScanDown:		// scans down frequency by 10 for AM and 0.2 for FM
			ScanDown();
			break;
		case  kMenuToggleAMFM:		//toggles frequency
			ToggleFrequency();
			break;
		case  kMenuButtonOne:		// switches frequency to the frequency stored in button 1
			SelectCurrentStation(0);
			break;
		case  kMenuButtonTwo:		// switches frequency to the frequency stored in button 2
			SelectCurrentStation(1);
			break;
		case  kMenuButtonThree:		// switches frequency to the frequency stored in button 3
			SelectCurrentStation(2);
			break;
		case  kMenuButtonFour:		// switches frequency to the frequency stored in button 4
			SelectCurrentStation(3);
			break;
		case  kMenuButtonFive:		// switches frequency to the frequency stored in button 5
			SelectCurrentStation(4);
			break;
		case  kMenuSetButtonOne:	// sets button 1 to the current frequency
			SetButton(0);
			break;
		case  kMenuSetButtonTwo:	// sets button 2 to the current frequency
			SetButton(1);
			break;
		case  kMenuSetButtonThree:	// sets button 3 to the current frequency
			SetButton(2);
			break;
		case  kMenuSetButtonFour:	// sets button 4 to the current frequency
			SetButton(3);
			break;
		case  kMenuSetButtonFive:	// sets button 5 to the current frequency
			SetButton(4);
			break;
		case  kMenuQuit:			// sets endLoop to true
			endLoop = true;
			break;
		default:					// default case
			break;
		}
	}
	return endLoop;				// if endLoop is true, the main loop will know to end the program
}


char* PioneerCarRadio::GetName(void)
{
	return name;
}

void PioneerCarRadio::SetName(char* newName)
{
	if (strcmp(newName, "Pioneer XS440") == 0)
	{
		strcpy(name, newName);
	}
	if (strcmp(newName, "Pioneer XS440-AM") == 0)
	{
		strcpy(name, newName);
	}
	if (strcmp(newName, "Pioneer XS440-WRLD") == 0)
	{
		strcpy(name, newName);
	}
}