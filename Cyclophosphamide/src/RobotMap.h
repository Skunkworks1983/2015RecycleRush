#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

// C++ changes
#define me this
#define floaterino float

// DriveBase
#define DRIVE_MOTOR_TYPE CANTalon
#define DRIVE_MOTOR_FRONT_LEFT 0
#define DRIVE_MOTOR_FRONT_RIGHT 1
#define DRIVE_MOTOR_BACK_LEFT 3
#define DRIVE_MOTOR_BACK_RIGHT 2
#define DRIVE_P 7.0
#define DRIVE_I 0.0
#define DRIVE_D 0.0

//Tote Intake
#define TOTE_INTAKE_SENSOR 0
#define TOTE_INTAKE_MOTOR 4
#define TOTE_INTAKE_MOTOR_FULL 1.0
#define TOTE_INTAKE_MOTOR_NONE 0.0

// Mecanum
#define ONE_STICK false
#define FIELD_ORIENTED true
#define JOYSTICK_DEGREES_PER_TICK 1.0
#define MECANUM_CORRECTION_THRESHOLD 0.2

// Auto
#define AUTO_DRIVE_SPEED (0.25)
#define AUTO_TURN_GYRO_THRESHOLD (0.25)

// OI
#define OI_JOYSTICK_LEFT (0)
#define OI_JOYSTICK_RIGHT (1)
#define OI_JOYSTICK_DRIVE_DEADBAND (0.05)
#define OI_JOYSTICK_ROT_DEADBAND (0.1)

// Can Collector
#define CAN_MOTOR_TYPE Talon
#define CAN_MOTOR_LIFT_LEFT 420
#define CAN_MOTOR_LIFT_RIGHT 421
#define CAN_MOTOR_GRAB_LEFT 422
#define CAN_MOTOR_GRAB_RIGHT 423

#define CAN_SENSOR 424
#define CAN_BRAKE 427

#define CAN_POT_LIFT_LEFT 425
#define CAN_POT_LIFT_RIGHT 426
#define CAN_POT_UP_POSITION 0.9
#define CAN_POT_DOWN_POSITION 0.1
#define CAN_UP_SPEED 1.0
#define CAN_DOWN_SPEED -1.0
#endif
