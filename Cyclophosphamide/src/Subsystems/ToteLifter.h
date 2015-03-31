#ifndef ToteLifterino_H
#define ToteLifterino_H

#include <Commands/Subsystem.h>
#include <PIDOutput.h>
#include <PIDSource.h>
#include <robotmap.h>

/*
 * Subsystem that handles the vertical motion of two CANTalon motor controllers.
 * Positions are set using a setPoint in the PIDController.
 * If failure were to occur in the encoder/zeroing, setMotorSpeed is used for manual control with no safeties
 * Safeties include: mag sensor at top elevator, and craaaw, as well as encoder input limit at TOTE_LIFTER_MAX_DISTANCE
 */
class ToteLifter: public Subsystem, public PIDOutput, public PIDSource {
private:
	DigitalInput *elevatorInput, *craaawInput;
	CANTalon *rightMotor, *leftMotor;
	PIDController *pid;
	Encoder *encoder;
	bool dontUseMagOnPID;
public:
	ToteLifter();
	~ToteLifter();
	void InitDefaultCommand();

	bool getElevatorInput();
	bool getCraaawInput();

	CANTalon *getLeftMotor();
	CANTalon *getRightMotor();

	Encoder *getEncoder();
	PIDController *getPID();

	double getPosition();
	bool closeEnough(float destination);
	/*
	 * For Manual Control
	 */
	void setMotorSpeed(double speed);

	/*
	 * For PID Control
	 */
	void setSetPoints(double setPoint);
	void enablePID(bool enable);
	virtual void PIDWrite(float f);
	virtual double PIDGet();
};

#endif
