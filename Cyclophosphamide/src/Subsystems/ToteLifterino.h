#ifndef ToteLifterino_H
#define ToteLifterino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <vector>
using std::vector;

/**
 * By Kaeden Wile
 * 
 * Forklift system that lifts and holds the totes in a stack
 */
class ToteLifterino: public Subsystem
{
private:
	Encoder *positionEncoder;
	Talon *RightLifter;
	Talon *LeftLifter;
	vector<int> destinations;
public:
	/**
	 * Default Constructor. Normal Initialization
	 */
	ToteLifterino();
	/**
	 * Does nothing because SetDefaultCommand call creates circular includes and compile errors
	 */
	void InitDefaultCommand();
	
	/**
	 * Based on the encoder, returns a key from RobotMap.h that corresponds to its current position
	 * If it is in motion and not currently at a destination, returns a key saying that it is in motion.
	 * Doesn't have to be at the exact value for that position, simply close enough as determined by 
	 * the close enough function.
	 * 
	 * @return either TOTE_LIFTER_KEY_0, TOTE_LIFTER_KEY_1, TOTE_LIFTER_KEY_2, TOTE_LIFTER_KEY_3, or TOTE_LIFTER_KEY_MOTION
	 */
	int getStackerPosition();
	/**
	 * Used to check if the stacker is close enough to its encoder value for each position.
	 * Allowed variablitity determined by TOTE_LIFTER_ENCODER_DEADBAND.
	 * Takes a constant and checks if (value > constant - deadband && value < constant + deadband)
	 * @return if the value is close enough to the constant
	 */
	bool closeEnough(int value, int constant);
	/**
	 * Appends the position to the end of the vector of positions
	 * Position should be one of the TOTE_LIFTER_KEY's from RobotMap.h, and not
	 * TOTE_LIFTER_KEY_MOTION.
	 * @param position TOTE_LIFTER_KEY_# to add to the end of destinations array
	 */
	void addDestination(int position);
	/**
	 * Calls closeEnough with the current position and the value for the given key, as found by getValue.
	 * Basically a shortcut composite of closeEnough and getValue for any said key.
	 * Position should be one of the TOTE_LIFTER_KEY's from RobotMap.h, and not TOTE_LIFTER_KEY_MOTION
	 * @param position TOTE_LIFTER_KEY_# to determine if the subsystem is at
	 * @return if the forklift is at the value for the position
	 */
	bool At(int position);
	/**
	 * Contains a switch statement which returns the TOTE_LIFTER_VALUE_# for its corresponding TOTE_LIFTER_KEY_#.
	 * Fails strongly with no default case and no return statement if key is invalid
	 * @param key TOTE_LIFTER_KEY_# to get value of
	 * @return key's corresponding TOTE_LIFTER_VALUE_#
	 */
	int getValue(int key);

	/**
	 * Checks if the stacker is at destinations's 0th value
	 * If it is, deletes that value and moves all other values down 1.
	 */
	void checkAtDestination();
	/**
	 * Method called by the Command. Calls checkAtDestination, then runs towards
	 * the next value in destinations. If destinations is empty, stops motors.
	 */
	void driveTowardsDestination();
};

#endif
