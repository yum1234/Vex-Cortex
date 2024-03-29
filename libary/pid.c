#pragma config(Sensor, dgtl1,  encoderLT,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  encoderRT,      sensorQuadEncoder)
#pragma config(Motor,  port5,           lt,            tmotorVex393_MC29, PIDControl, reversed, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port6,           rt,            tmotorVex393_MC29, PIDControl, driveRight, encoderPort, dgtl3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void fwd(float inches);
void left();
void right();
void resetEncoders();

const float radius = 2; //inches
const float diameter = 4; //inches
const float pie = 3.1415926535897932384;
const float circumference = diameter*radius;
const float fullRotation = 360; //There are 360 pulses for every rotation in the encoder.

void fwd(float inches)
{
	resetEncoders();
	float rotations = inches/circumference; //if robot travels circumference
	//turns on motors.
	motor[lt] = 30;
	motor[rt] = 30;
	while(SensorValue[encoderLT]/fullRotation < rotations)
	{
    ;
	}
	//turns off motors.
	motor[lt] = 0;
	motor[rt] = 0;
}

void left()
{
	//Simply just turn on left motor to move a distance for 1/4 of a circle while leaving the right one off?
	resetEncoders();
	float rotations = (circumference/4)/circumference;
	motor[lt] = 30;
	while(SensorValue[encoderLT]/fullRotation < rotations)
	{
		;
	}
	motor[lt] = 0;

}

void right()
{
	//Simply just turn on left motor to move a distance for 1/4 of a circle while leaving the right one off?
	resetEncoders();
	float rotations = (circumference/4)/circumference;
	motor[rt] = 30;
	while(SensorValue[encoderRT]/fullRotation < rotations)
	{
		;
	}
	motor[rt] = 0;

}

void spin360()
{
	//Simply just turn on left motor to move a distance for 1/4 of a circle while leaving the right one off?
	resetEncoders();
	float rotations = 1;
	motor[rt] = 30;
	motor[lt] = -30;
	while(SensorValue[encoderRT]/fullRotation < rotations)
	{
		;
	}
	motor[rt] = 0;
	motor[lt] = 0;

}

void resetEncoders()
{
	//resets both encoders
	SensorValue[encoderLT]=0;
	SensorValue[encoderRT]=0;
}
