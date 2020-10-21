/*
 * PTC.h
 *
 *  Created on: Aug 28, 2020
 *      Author: timattt
 */

//-----------------------
// Project Terma Console
//-----------------------

#ifndef GAMECORE_PTC_H_
#define GAMECORE_PTC_H_

#include <string>

//! Project Terma Console Message type
enum PTCMT {
	debug, info, error
};

//! Project Terma Console Message Priority
enum PTCMP {
	low, medium, high
};

class PTC {
public:
	PTC();
	~PTC();

	//---------------------------------------------------------------------
	static PTCMP CURRENT_PRIORITY;
	static bool SAY_DEBUG;
	//---------------------------------------------------------------------

	//---------------------------------------------------------------------
	static void say(std::string mes, PTCMT type = info, PTCMP prior = medium);
	static void sayCreated(std::string mes, PTCMT type = info, PTCMP prior = medium);
	static void sayDestroyed(std::string mes, PTCMT type = info, PTCMP prior = medium);
	static void shutUpDebug();
	//---------------------------------------------------------------------
};

#endif /* GAMECORE_PTC_H_ */
