#include"AmFmRadio.h"


#pragma warning (disable: 4996)

#ifndef __PIONEERCARRADIO_H__
#define __PIONEERCARRADIO_H__

/*
	NAME	:	PioneerCarRadio : public AmFmRadio
	PURPOSE :	The purpose of this class is to model
				a Pioneer Car Radio using a parent class
				of an Am Fm Radio for it's methods
*/
class PioneerCarRadio : public AmFmRadio
{
	/* ====================================== */
	/*              PRIVATE                   */
	/* ====================================== */
private:

	char name[MAX_LENGTH];		// the radios name

	/* ====================================== */
	/*              PUBLIC                    */
	/* ====================================== */
public:
	/* -------------- ATTRIBUTES ------------ */
	/* ---------- METHOD PROTOTYPES --------- */
	PioneerCarRadio(bool on = false, char* names = (char*)"Pioneer XS440"); // constructor
	virtual ~PioneerCarRadio();		  // destructor

	virtual void ShowCurrentSettings(void);  // method to display the radio's current settings
	virtual bool GetMenuOption();     // method used to get inputs to the radio and changing the radios attributes

	char* GetName(void);
	void SetName(char* newName);

};



#endif

