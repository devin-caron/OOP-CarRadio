/*
 *FILE         : ultimateRadio.cpp
 *PROJECT      : CAR RADIO (PROG1385 - Assignment 6)
 *PROGRAMMER   : Devin Caron
 *DESCRIPTION  :
 *				This program is based around a Pioneer radio with a user interface and
 *				many features that are in old radios such as: power button, volume up / down,
 *				channel scaning and a toggle between AM and FM frequencies. This program uses
 *              creates a child class and grandchild class that inherent from it. The radio
 *				menu loops until 'x' is pressed then they user has the option to switch between
 *				the three radios and the program is closed when they user enters another 'x'
 *
 */

#include "AmFmRadio.h"
#include "PioneerCarRadio.h"
#include "PioneerAM.h"
#include "PioneerWorld.h"

PioneerCarRadio* createRadio(char* radioName);

int main(int argc, char *argv[])
{
	// check that there is a command argument
	if (argc != 2)
	{
		printf("error no arguments found");
		return 0;
	}

	
	char commandArgument[MAX_LENGTH];		// char array variable to store the command argument

	strcpy(commandArgument, argv[argc - 1]);	// copying the command argument to the variable


    PioneerCarRadio* pRadio = NULL;			// allocating memory for the class

    pRadio = new PioneerCarRadio(false);	// creating a new PioneerCarRadio class with allocated memory
    if (pRadio == NULL)						// checking that there was memory to create
    {
        printf("Not enough memory! \n");
        return 1;
    }

	char newRadio;	// variable to store the user input of switching radios

	//do while loop for the radio menu and selection until the user exits by entering 'x'
	do
	{
		try
		{
			pRadio = createRadio(commandArgument);
		}
		catch (char* commandArgument)        // if argument is not valid the exception gets caught
		{
			printf("\n EXCEPTION! - Invalid command.\n");
			return -1;
		}
		catch (bad_alloc& ba)    //	if the memory can't be allocated the exception is caught
		{
			printf("\n EXCEPTION! - Can't allocate the memory.\n");
			return -2;
		}
		pRadio->ShowCurrentSettings();



		printf("\nPlease enter a radio you would like to switch to: ");
		newRadio = getch();	// getch to get a character from the user 'a' for am and 'w' for world class
		try					// try catch to get possible exeptions
		{
			delete pRadio;
		}
		catch (bad_exception& e)       // bad exception catch
		{
			printf("\nEXCEPTION! - Unknown Exception\n");
			return -3;
		}
		catch (runtime_error& re)		// runtime error catch
		{
			printf("\nEXCEPTION! - Runtime error\n");
			return -4;
		}

		// switch statement to allow the user to switch radios
		switch (newRadio)	
		{
		case 'c':
			pRadio = createRadio((char*)"-car");
			strcpy(commandArgument, "-car");
			break;
		case 'a':
			pRadio = createRadio((char*)"-am");
			strcpy(commandArgument, "-am");
			break;
		case 'w':
			pRadio = createRadio((char*)"-world");
			strcpy(commandArgument, "-world");
			break;
		default:	// default for invalid inputs
			if (newRadio != 'x')
			{
				printf("invalid argument");
			}
			break;
		}

	} while (newRadio != 'x');

    // closing message
    printf("\nGoodbye!\n");

    return 0;
}

/*
	Name	: createRadio
	Purpose : this function is a switch statement
			  used to allow the user to select a
			  new radio to switch to
	Inputs	:	argument	char*		the argument of the argument for the radio
	Outputs	:	NONE
	Returns	:	PioneerCarRadio*: to return the new radio
*/
PioneerCarRadio* createRadio(char* argument)
{
	PioneerCarRadio* radio = NULL;

	char switchOption;
	// converting the char array to a single char for the switch
	if (strcmp(argument, "-car") == 0)
	{
		switchOption = 'c';
	}
	if (strcmp(argument, "-am") == 0)
	{
		switchOption = 'a';
	}
	if (strcmp(argument, "-world") == 0)
	{
		switchOption = 'w';
	}

	// switch to check if the option is valid and create the new radio
	switch (switchOption)
	{	
	case 'c':
		radio = new PioneerCarRadio(false, (char*)"Pioneer XS440");

		if (radio == NULL)	// checking if it alloacated memory
		{
				throw radio;
		}
		return radio;
		break;
	case 'a':
		radio = new PioneerAM();
		if (radio == NULL)	// checking if it alloacated memory
		{
			throw radio;
		}
		return radio;
		break;
	case 'w':
		radio = new PioneerWorld();
		if (radio == NULL)	// checking if it alloacated memory
		{
			throw radio;
		}
		return radio;
		break;
	default:				// default case to throw back the argument
		throw argument;
		break;
	}
}