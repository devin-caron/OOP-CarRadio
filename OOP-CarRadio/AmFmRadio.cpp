/*
 *FILE         : AmFmRadio.cpp
 *DESCRIPTION  : Stores all the functions within the AmFmRadio class.
 */

#include "AmFmRadio.h"

 /*
	 Name	 : AmFmRadio -- CONSTRUCTOR
	 Purpose : to instantiate a new AmFmRadio object - given a set of attribute values
	 Inputs	 :	on		Bool		state of the power (on / off)
	 Outputs :	NONE
	 Returns :	Nothing
 */
AmFmRadio::AmFmRadio(bool on)
{
	// two for loops to initialize the radio buttons for AM and FM frequencies
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreq = MIN_AM_FREQ;
	}
	for (int j = 0; j < 5; ++j)
	{
		button[j].FMFreq = MIN_FM_FREQ;
	}
	// setting default values for other object data members
	current_station = MIN_AM_FREQ;
	strcpy(frequency, "AM");
	volume = 0;
	lastVolume = 0;
	AmFmRadio::on = on;
	displayOutput = false;
}
/*
	Name	 : AmFmRadio -- CONSTRUCTOR
	Purpose  : to instantiate a new AmFmRadio object - given a set of attribute values
	Inputs	 :	on					Bool			state of the power (on / off)
				presetButtons		Struct Freqs	radio buttons
	Outputs  :	NONE
	Returns  :	Nothing
*/
AmFmRadio::AmFmRadio(bool on, Freqs presetButtons[5])
{
	// two for loops to initialize the radio buttons for AM and FM frequencie
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreq = presetButtons[i].AMFreq;
	}
	for (int j = 0; j < 5; ++j)
	{
		button[j].FMFreq = presetButtons[j].FMFreq;
	}
	// setting default values for other object data members
	current_station = MIN_AM_FREQ;
	strcpy(frequency, "AM");
	volume = 0;
	lastVolume = 0;
	AmFmRadio::on = on;
	displayOutput = false;
}

/*  -- Method Header Comment
	Name	: AmFmRadio -- DESTRUCTOR
	Purpose : to destroy the AmFmRadio object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	outputs a final message from the object before being destroyed
	Returns	:	Nothing
*/
AmFmRadio::~AmFmRadio()
{
	if (displayOutput == true)
	{
		printf("Destroying AmFmRadio\n");
	}
}


//=======================================================================//

/*
	Name	: GetCurrent_Station
	Purpose : called to return the value of current_station
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
double AmFmRadio::GetCurrent_Station(void)
{
	return current_station;
}
/*
	Name	: GetFrequency
	Purpose : called to return the value of frequency
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
char* AmFmRadio::GetFrequency(void)
{
	return frequency;
}
/*
	Name	: GetVolume
	Purpose : called to return the value of volume
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
int AmFmRadio::GetVolume(void)
{
	return volume;
}
/*
	Name	: GetLastVolume
	Purpose : called to return the value of lastVolume
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
int AmFmRadio::GetLastVolume(void)
{
	return lastVolume;
}
/*
	Name	: GetDisplayOutput
	Purpose : called to return the value of displayOutput
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
bool AmFmRadio::GetDisplayOutput(void)
{
	return displayOutput;
}
/*
	Name	: isRadioOn
	Purpose : called to return the value of on
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
bool AmFmRadio::IsRadioOn(void)
{
	return on;
}
Freqs* AmFmRadio::GetButtons(void)
{
	return button;
}
double AmFmRadio::GetLastFreq(void)
{
	double freq = 0;
	if (strcmp(frequency, "AM") == 0)
	{
		freq = lastFreq.AMFreq;
		return freq;
	}
	else
	{
		freq = lastFreq.FMFreq;
		return freq;
	}
}

//=======================================================================//

/*
	Name	: PowerToggle
	Purpose : this mutator method is used to update/change the state of variable on
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
void AmFmRadio::PowerToggle(void)
{
	if (on == false)
	{
		on = true;
		volume = GetLastVolume();
	}
	else
	{
		on = false;
		lastVolume = GetVolume();
		volume = 0;
	}
}
/*
	Name	: SetVolume
	Purpose : this mutator method is used to update/change the state of volume
	Inputs	:	volume		char[]		takes the volume from user input
	Outputs	:	NONE
	Returns	:	0 for no error or volume being less than 0, 1 for error in else statement, 2 for volume being too high and set to 100
*/
int AmFmRadio::SetVolume(void)
{
	if (on == false)
	{
		volume = 0;
		return 0;
	}
	else
	{
		char buf[20] = "";

		printf("\nEnter the volume level (0 - 100). ");
		fgets(buf, sizeof buf, stdin);
		volume = atoi(buf);

		return AmFmRadio::SetVolume(volume);
	}

}
/*
	Name	: SetVolume
	Purpose : this mutator method is used to update/change the state of volume
	Inputs	:	volume		int		what is to be set as volume
	Outputs	:	NONE
	Returns	:	0 for no error or volume being less than 0, 1 for error in else statement, 2 for volume being too high and set to 100
*/
int AmFmRadio::SetVolume(int volume)
{
	if (on == false)
	{
		this->volume = 0;
		return 0;
	}
	else
	{
		if (volume < 0) //if volume is less than 0, volume = 0
		{
			this->volume = 0;
			return 0;
		}
		if (volume > 100) //if volume is greater than 100, volume = 100
		{
			this->volume = 0;
			return 2;
		}
		else
		{
			this->volume = volume;
		}
		return 1;
	}

}
/*
	Name	: ToggleFrequency
	Purpose : this mutator method is used to update/change the state of frequency
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
void AmFmRadio::ToggleFrequency(void)
{
	if (strcmp(frequency, "AM") == 0)
	{
		strcpy(frequency, "FM");
		if (lastFreq.FMFreq == 0)
		{
			current_station = MIN_FM_FREQ;
		}
		else
		{
			current_station = lastFreq.FMFreq;
		}
	}
	else
	{

		strcpy(frequency, "AM");
		if (lastFreq.AMFreq == 0)
		{
			current_station = MIN_AM_FREQ;
		}
		else
		{
			current_station = lastFreq.AMFreq;
		}
	}

}
/*
	Name	: SetButton
	Purpose : this mutator method is used to update/change the state of Freqs button[]
	Inputs	:	button_num		int		what button to be set
	Outputs	:	NONE
	Returns	:	1 in if statement, 0 out of if statement
*/
int AmFmRadio::SetButton(int button_num)
{
	if ((button_num >= 0) && (button_num <= 4))
	{
		if (strcmp("AM", frequency) == 0)
		{
			button[button_num].AMFreq = current_station;
		}
		else
		{
			button[button_num].FMFreq = current_station;
		}
		return 1;

	}
	return 0;

}

/*
	Name	: SelectCurrentStation
	Purpose : this mutator method is used to update/change the state of current_station
	Inputs	:	button		int		what button number to set to current station
	Outputs	:	NONE
	Returns	:	1 in if statement, 0 out of if statement
*/
int AmFmRadio::SelectCurrentStation(int button_num)
{
	if ((button_num >= 0) && (button_num <= 4))
	{
		if (strcmp("AM", frequency) == 0)
		{
			current_station = button[button_num].AMFreq;
			lastFreq.AMFreq = current_station;
		}
		else
		{
			current_station = button[button_num].FMFreq;
			lastFreq.FMFreq = current_station;
		}

		return 1;
	}
	return 0;
}
/*
	Name	: ShowCurrentSettings
	Purpose : this method is to be called in order to take a snapshot of the current
			  attribute values
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
void AmFmRadio::ShowCurrentSettings(void)
{

	if (on == true)
	{
		printf("\n\nRadio is on. \n");
	}
	else
	{
		printf("\n\nRadio is off. \n");
	}

	printf("\nFrequency: %s\n", frequency);
	printf("Volume: %d\n", volume);
	printf("Current Station: %.1f %s\n", current_station, frequency);
	printf("AM Button Settings: ");
	for (int i = 0; i < 5; ++i)
	{
		printf("%d) %6d ", i + 1, button[i].AMFreq);
	}

	printf("\nFM Button Settings: ");
	for (int j = 0; j < 5; ++j)
	{
		printf("%d) %6.1f ", j + 1, button[j].FMFreq);
	}
}

/*
	Name	: ScanUp
	Purpose : this method is used to scan up the channel
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
void AmFmRadio::ScanUp(void)
{
	if (strcmp("AM", frequency) == 0)
	{
		//if current_station is 1700, the current_station becomes 530
		if (current_station == MAX_AM_FREQ)
		{
			current_station = MIN_AM_FREQ;
		}
		else
		{
			current_station = current_station + 10;
		}
		lastFreq.AMFreq = current_station;
	}
	else
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if (current_station >= MAX_FM_FREQ)
		{
			current_station = MIN_FM_FREQ;
		}
		else
		{
			current_station = current_station + .2;
		}
		lastFreq.FMFreq = current_station;
	}
	if (displayOutput == true)
	{
		printf("\nCurrent station: %.1f %s\n", current_station, frequency);
	}

}

/*
	Name	: ScanDown
	Purpose : this method is used to scan down the channel
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
*/
void AmFmRadio::ScanDown(void)
{
	if (strcmp("AM", frequency) == 0)
	{
		//if current_station is 530, the current_station becomes 1700
		if (current_station == MIN_AM_FREQ)
		{
			current_station = MAX_AM_FREQ;
		}
		else
		{
			current_station = current_station - 10;
		}
		//setting this station as the last station
		lastFreq.AMFreq = current_station;
	}
	else
	{
		//if the current_station is 87.9, the current_station becomes 107.9
		if (current_station == MIN_FM_FREQ)
		{
			current_station = MAX_FM_FREQ;
		}
		else
		{
			current_station = current_station - 0.2;
		}
		//setting this station as the last station
		lastFreq.FMFreq = current_station;
	}

	// displays output when display output is set to true
	if (displayOutput == true)
	{
		printf("\nCurrent station: %.1f %s\n", current_station, frequency);
	}

}
/*
	Name	: SetCurrent_Station
	Purpose : this method is used to set  current_station
	Inputs	:	station		double		the station to be set as current_station
	Outputs	:	NONE
	Returns	:	NONE
*/
void AmFmRadio::SetCurrent_Station(double station)
{
	if (strcmp("AM", frequency) == 0)
	{
		//if station is < 530 or > 1700 it is in range
		if (station >= MIN_AM_FREQ && station <= MAX_AM_FREQ)
		{
			AmFmRadio::current_station = station;
		}
		else
		{
			printf("error\n");
		}
		//setting this station as the last station
		lastFreq.AMFreq = station;
	}
	else
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if (station >= MIN_FM_FREQ && station <= MAX_FM_FREQ)
		{
			AmFmRadio::current_station = station;
		}
		else
		{
			printf("error\n");
		}
		//setting this station as the last station
		lastFreq.FMFreq = station;
	}

	// displays output if display output is set to true
	if (displayOutput == true)
	{
		printf("\nCurrent station: %.1f %s\n", current_station, frequency);
	}
}

/*
	Name	: SetDisplayOutput
	Purpose : this method is used to set whether to display output or not
	Inputs	:	option		bool		value to see if output needs to be displayed
	Outputs	:	NONE
	Returns	:	NONE
*/
bool AmFmRadio::SetDisplayOutput(bool option)
{
	if (option == true)
	{
		displayOutput = true;
	}
	else
	{
		displayOutput = false;
	}
	return displayOutput;
}

void AmFmRadio::SetFrequency(char* frequency)
{
	if (strcmp(frequency, "AM") == 0)
	{
		strcpy(frequency, "AM");
	}
	else
	{
		strcpy(frequency, "FM");
	}
}

void AmFmRadio::SetPrevFreq(Freqs freq)
{
	lastFreq = freq;
}