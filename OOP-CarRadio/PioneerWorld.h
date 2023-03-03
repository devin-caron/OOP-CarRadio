#include"PioneerAM.h"


#pragma warning (disable: 4996)




#ifndef __PIONEERWORLD_H__
#define __PIONEERWORLD_H__

/*
	NAME	:	PioneerWorld: public PioneerAM
	PURPOSE :	The purpose of this class is to model
				a Pioneer Car Radio that only has the
				AM frequency and different minimum and
				max frequencies, using a parent class
				of a PioneerAM for it's methods
*/
class PioneerWorld : public PioneerAM
{
	/* ====================================== */
	/*              PRIVATE                   */
	/* ====================================== */
private:



	/* ====================================== */
	/*              PUBLIC                    */
	/* ====================================== */
public:
	/* -------------- ATTRIBUTES ------------ */
	/* ---------- METHOD PROTOTYPES --------- */

	/*
	 Name	 : PioneerWorld -- CONSTRUCTOR
	 Purpose : to instantiate a new PioneerWorld object - given a name and an on value,
			   this class inherits from PioneerAM class. This class also sets the current
			   station and buttons to it's specific frequency.
	 Inputs	 :	name	char*		the name of the radio
			 :	on		Bool		state of the power (on / off)
	 Outputs :	NONE
	 Returns :	NONE
	*/
	PioneerWorld(bool on = false, char* name = (char*)"Pioneer XS440-WRLD") : PioneerAM(on, name)	// constructor
	{
		// set the current station to pioneer world's minimum frequency
		SetCurrent_Station(WORLD_MIN);
		
		// set the buttons to pioneer world's minimum frequency
		for (int i = 0; i < 5; i++)
		{
			SetButton(i);
		}
	}

	/*
	Name	: PioneerWorld -- DESTRUCTOR
	Purpose : to destroy the PioneerWorld object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	outputs a final message from the object before being destroyed
	Returns	:	NONE
	*/
	virtual ~PioneerWorld()	// destructor
	{
		printf("\nDestroying Pioneer XS440-WRLD Radio\n");
	}



	/*
	Name	: ScanDown
	Purpose : this virtual mutator method is used to scan down the
			  frequency, this method has been overwritten to decrease
			  by 9 for this class
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
	*/
	virtual void ScanDown(void)
	{
		Freqs prevFreq;
		prevFreq.AMFreq = GetLastFreq();

		// check that the frequency isn't at the minimum
		if (GetCurrent_Station() == WORLD_MIN)
		{
			SetCurrent_Station(WORLD_MAX);
		}
		// decrease frequency by 9
		else
		{
			SetCurrent_Station(GetCurrent_Station() - 9);
		}
		SetPrevFreq(prevFreq);	// set the previous frequency
	}

	/*
	Name	: ScanUp
	Purpose : this virtual mutator method is used to scan up the
			  frequency, this method has been overwritten to increase
			  by 9 for this class
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
	*/
	virtual void ScanUp(void)
	{
		Freqs prevFreq;
		prevFreq.AMFreq = GetLastFreq();

		// check that the frequency isn't at the max
		if (GetCurrent_Station() == WORLD_MAX)
		{
			SetCurrent_Station(WORLD_MIN);
		}
		// increase frequency by 9
		else
		{
			SetCurrent_Station(GetCurrent_Station() + 9);
		}
		SetPrevFreq(prevFreq);	// set the previous frequency
	}

};


#endif