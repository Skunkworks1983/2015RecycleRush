#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

#define DOESNT_EXIST 0x420

#define SAFE_INIT(port, thingy) \
	if (port != 0x420) { \
		thingy \
	}

// Autonomous Configuration Settings
#define AUTO_SCRIPT_MAXLENGTH	(256)
#define AUTO_SCRIPT_MAXLINES	(64)
#define AUTO_SCRIPT_COMMAND_MAXLENGTH	(20)
#define AUTO_SCRIPT_LOCATIONS	"/Commands/Autonomous/"
#define AUTO_SCRIPT_CHARMASK(a,b) ((((int)a) << 8) | ((int)b))

#define AUTONOMOUS_DEFAULT_DISTANCE 5 //units?
#define AUTONOMOUS_DEFAULT_TIME 5 //units?

// C++ changes
#define floaterino float
#define returnerino return

// DriveBase
#define DRIVE_MOTOR_TYPE CANTalon
#define DRIVE_MOTOR_FRONT_LEFT_PORT 15
#define DRIVE_MOTOR_FRONT_RIGHT_PORT 1
#define DRIVE_MOTOR_BACK_LEFT_PORT 14
#define DRIVE_MOTOR_BACK_RIGHT_PORT 0

#define DRIVE_ROT_P  3.0
#define DRIVE_ROT_I 0.0
#define DRIVE_ROT_D 5.0

#define DRIVE_DRIVE_P 0.5
#define DRIVE_DRIVE_I 0.0
#define DRIVE_DRIVE_D 0.0

#define DRIVE_ASPECT_RATIO (0.5)
#define DRIVE_BASE_TICKS_PER_INCH 170
#define GYRO_TIMEOUT 5000 // milliseconds
#define ENCODER_TICKS_PER_REV 360.0

//Tote Intake
#define TOTE_INTAKE_ENCODER_PORT 5, 4
#define TOTE_INTAKE_MOTOR_PORT 10

#define TOTE_INTAKE_MOTOR_FULL 0.2
#define TOTE_INTAKE_PID_FULL 1.0
#define TOTE_INTAKE_ENCODER_TICKS_PER_REV 1024
#define TOTE_INTAKE_DETECTION_THRESHOLD .1
#define TOTE_INTAKE_P 0.005
#define TOTE_INTAKE_I 0.0
#define TOTE_INTAKE_D 0.0
#define TOTE_INTAKE_AUTO_TIME_MS 2.0

// Tote Lifter
#define TOTE_LIFTER_LEFT_PORT 3
#define TOTE_LIFTER_RIGHT_PORT 12
#define TOTE_LIFTER_TOTE_INPUT_PORT 6
#define TOTE_LIFTER_ENCODER_PORTS 8,9

#define TOTE_LIFTER_MAX_DISTANCE 1850
#define TOTE_LIFTER_END_TOLERANCE 30
#define TOTE_LIFTER_TOLERANCE 15

#define TOTE_LIFTER_TICKS_PER_REV 1024

#define TOTE_LIFTER_PID_P .01
#define TOTE_LIFTER_PID_I 0.0
#define TOTE_LIFTER_PID_D .01

#define TOTE_LIFTER_TWO_TOTE 1750 // Old: 1400 // Older: 1300
#define TOTE_LIFTER_ONE_TOTE 1237
#define TOTE_LIFTER_CARRY_HEIGHT 270
#define TOTE_LIFTER_FLOOR_HEIGHT 0

#define TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT 1
#define TOTE_LIFTER_ELEVATOR_BOT_INPUT_PORT 2

#define TOTE_LIFTER_ZERO_SPEED .3

#define TOTE_LIFTER_BANGBANG_TOLERANCE_PID 30
#define TOTE_LIFTER_BANGBANG_TOLERANCE_1 50
#define TOTE_LIFTER_BANGBANG_TOLERANCE_2 100
#define TOTE_LIFTER_BANG_BANG_UP_SPEED .5
#define TOTE_LIFTER_DOWN_SPEED -.3
#define TOTE_LIFTER_TOP_INPUT_WORKS true

#define TOTE_LIFTER_PID_CONSTANT .5

#define TOTE_LIFTER_ENCODER_CLOSE_TO_ZERO 5
#define TOTE_LIFTER_COUNT_ZEROED 100

#define TOTE_LIFTER_TICKS_PER_INCH 64
#define SCORE_HEIGHT_CHANGE_AMOUNT_VALUE_INCHES -4.0
#define COOP_DELTA_INCHES 4.0
#define MAGNET_PORT 420
// Mecanum
#define FIELD_ORIENTED false
#define LOAD_LEFT_ANGLE 45.0
#define LOAD_RIGHT_ANGLE -45.0

// Auto
#define AUTO_DRIVE_SPEED (0.25)
#define AUTO_TURN_SLOW_DOWN (12)
#define AUTO_TURN_SPEED_MIN (0.2)
#define AUTO_TURN_SPEED_MAX (0.5)
#define AUTO_TURN_SPEED_RANGE (AUTO_TURN_SPEED_MAX - AUTO_TURN_SPEED_MIN)
#define AUTO_TURN_GYRO_THRESHOLD (20)

// OI
#define JOYSTICK_DRIVE_DEADBAND (0.05)
#define JOYSTICK_ROT_DEADBAND (0.15)
#define JOYSTICK_DEGREES_PER_TICK 5.0

// Can Collector
#define CAN_MOTOR_TYPE CANTalon
#define CAN_MOTOR_LIFT_LEFT_PORT 13
#define CAN_MOTOR_LIFT_RIGHT_PORT 2

#define CAN_MOTOR_GRAB_LEFT_PORT 11
#define CAN_MOTOR_GRAB_RIGHT_PORT 4
#define CAN_WRIST_SOLENOID_PORT 1, 6
#define CAN_LIFT_POT_PORT 0

#define CAN_SENSOR_PORT 0

#define CAN_POT_UP_POSITION 4.03// practice bot 4.95
#define CAN_POT_DOWN_POSITION 1.533 // practice bot 2.3
#define CAN_POT_KNOCK_POSITION 2.555

#define CAN_LIFT_THRESHOLD 0.1

#define CAN_UP_SPEED 1.0
#define CAN_DOWN_SPEED -1.0
#define CAN_GRAB_SPEED 1.0

#define CAN_ARM_P 0.7
#define CAN_ARM_I 0.0
#define CAN_ARM_D 0.0

// Auto Canerino
#define AUTO_CAN_MOTOR_TYPE Talon

//Downward Dog Craaaw
#define CRAAAW_CAN_DETECTOR_PORT 0
#define CRAAAW_LOCK_LEFT_PORT 2
#define CRAAAW_LOCK_RIGHT_PORT 5

//stack pusher
#define PUSHER_LEFT_PORT 0
#define PUSHER_RIGHT_PORT 7

// Pneumatics
#define COMPRESSOR_PRESSURE_SENSOR_PORT 0
#define COMPRESSOR_RELAY_PORT 0

// Stallable Motor
#define STALLABLE_MOVE_THRESHOLD 0.1
#define STALLABLE_TIME_STOP 1500

#endif
