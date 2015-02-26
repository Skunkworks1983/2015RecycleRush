#ifndef PUT_UP_H
#define PUT_UP_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Collect: public CommandGroup
{
/*!
 * Toggles the wrists and induct so that a can can be collected
 */
public:
	Collect();
};

#endif
