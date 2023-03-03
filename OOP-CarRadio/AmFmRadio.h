/*
 *FILE         : AmFmRadio.h
 *DESCRIPTION  : Stores the struct and class initialization
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include<iostream>
#include <list>
#include <exception>
#include <new.h>
using namespace std;

#pragma warning (disable: 4996)

#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H

#define MAX_AM_FREQ 1700
#define MIN_AM_FREQ 530
#define MAX_FM_FREQ 107.9
#define MIN_FM_FREQ 87.9

#define MAX_LENGTH 250

#define WORLD_MAX 1602
#define WORLD_MIN 531

struct Freqs
{
	int AMFreq = 0;
	double FMFreq = 0;
};

/*
	NAME	:	AmFmRadio
	PURPOSE :	The purpose of this class is to model
				an AM/FM radio with it's features.

*/
class AmFmRadio
{
	/* ====================================== */
	/*              PRIVATE                   */
	/* ====================================== */
private:
	/* -------------- CONSTANTS ------------- */
	/* -------------- ATTRIBUTES ------------ */
	Freqs	button[5];			 // radio station presets
	Freqs	lastFreq;			 // the last station used before switching frequencies

	double  current_station;	 // current radio station

	char	frequency[3];		 // AM or FM frequency 

	int		volume;				 // radio's volume
	int		lastVolume;			 // last volume set before toggling power off

	bool	on;					 // is radio turned on or off
	bool	displayOutput;


	/* ====================================== */
	/*              PUBLIC                    */
	/* ====================================== */
public:
	/* -------------- ATTRIBUTES ------------ */
	/* ---------- METHOD PROTOTYPES --------- */

	//sets each button to the lowest frequency, sets the current station, sets the
	//frequency to AM, sets the volume to 0 and sets on to parameter bool on
	AmFmRadio(bool on);

	//sets each button to the parameter struct Freqs[], sets the current station, sets the
	//frequency to AM, sets the volume to 0 and sets on to parameter bool on
	AmFmRadio(bool on, Freqs presetButtons[5]);

	//deconstructor prints out "Destroying AmFmRadio" when destroyed.
	virtual ~AmFmRadio();

	//switches on to false if true and true if false
	void PowerToggle(void);

	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn(void);

	//toggles frequency between AM and FM and sets current station
	 virtual void ToggleFrequency(void);

	//sets button with current station by being passed a button number
	int SetButton(int button_num);

	//sets current station by being passed a button number
	int SelectCurrentStation(int button_num);

	//sets volume
	int SetVolume(void);
	int SetVolume(int volume);

	//shows volume, button settings, current station, AM or FM
	virtual void ShowCurrentSettings(void);

	//changes frequency up in increments of .2 for FM, 10 for AM
	virtual void ScanUp(void);
	virtual void ScanDown(void);

	//takes a station and sets that as the current station
	void SetCurrent_Station(double station);

	//determines whether or not output should be displayed by takin in a bool
	bool SetDisplayOutput(bool option);

	void SetFrequency(char* frequency);

	void SetPrevFreq(Freqs freq);

	/* ------------- ACCESSORS ------------ */
	double	 GetCurrent_Station(void);	// method
	char* GetFrequency(void);		//
	int		 GetVolume(void);			//
	int		 GetLastVolume(void);		//
	bool	 GetDisplayOutput(void);	//
	double GetLastFreq(void);
	Freqs* GetButtons(void);

};
#endif
