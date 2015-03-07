/*
 * StrafePIDOutput.h
 *
 *  Created on: Mar 4, 2015
 *      Author: s-4020395
 */

#ifndef SRC_UTILITIES_STRAFEPIDOUTPUT_H_
#define SRC_UTILITIES_STRAFEPIDOUTPUT_H_

#include <PIDOutput.h>
#include <CommandBase.h>

/*
 *
 */
class StrafePIDOutput: public PIDOutput {
private:
	DriveBae *driveBae;
public:
	StrafePIDOutput(DriveBae *driveBae);
	virtual ~StrafePIDOutput();
	void PIDWrite(float output);
};

#endif /* SRC_UTILITIES_STRAFEPIDOUTPUT_H_ */
