#include"PioneerCarRadio.h"


#pragma warning (disable: 4996)

#ifndef __PIONEERAM_H__
#define __PIONEERAM_H__

/*
	NAME	:	PioneerAM: public PioneerCarRadio
	PURPOSE :	The purpose of this class is to model
				a Pioneer Car Radio that only has the
				AM frequency, using a parent class
				of a PioneerCarRadio for it's methods
*/
class PioneerAM : public PioneerCarRadio
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
	 Name	 : PioneerAM -- CONSTRUCTOR
	 Purpose : to instantiate a new PioneerAM object - given a name and an on value,
			   this class inherits from PioneerCarRadio class.
	 Inputs	 :	name	char*		the name of the radio
			 :	on		Bool		state of the power (on / off)
	 Outputs :	NONE
	 Returns :	NONE
	*/
	PioneerAM(bool on = false, char* name = (char*)"Pioneer XS440-AM") : PioneerCarRadio(on, name)	// constructor
	{
		
	}

	/*
	Name	: PioneerAM -- DESTRUCTOR
	Purpose : to destroy the PioneerAM object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	outputs a final message from the object before being destroyed
	Returns	:	NONE
	*/
	virtual ~PioneerAM()	// destructor
	{
		printf("\nDestroying Pioneer XS440-AM Radio\n");
	}

	/*
	Name	: ToggleFrequency
	Purpose : this virtual mutator method is used to update/change the state of frequency
			: it is overwritten to do nothing as this class doesn't have a FM frequency
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
	*/
	virtual void ToggleFrequency(void)
	{
		// don't allow this class to switch to fm frequency
	}

};



#endif


