#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

// DriveBase
#define DRIVE_MOTOR_TYPE Talon
#define DRIVE_MOTOR_FRONT_LEFT 1
#define DRIVE_MOTOR_FRONT_RIGHT 0
#define DRIVE_MOTOR_BACK_LEFT 3
#define DRIVE_MOTOR_BACK_RIGHT 2

// Gyro
#define GYRO 5

// Mecanum
#define HALO true // alternative being tank + strafe
#define MECANUM_TUNING_CONSTANT .1 // max 1

// OI
#define OI_JOYSTICK (0)
#define OI_JOYSTICK_DRIVE_DEADBAND (0.05)

#endif
