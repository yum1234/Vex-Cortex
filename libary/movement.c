#pragma config(Sensor, dgtl1,  encoderLT,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  encoderRT,      sensorQuadEncoder)
#pragma config(Motor,  port5,           lt,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rt,            tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void fwd(float inches);
void left();
void right();
void turn180();
void spin360();
void resetEncoders();

const float radius = 2; //inches
const float diameter = 4; //inches
const float pie = 3.1415926535897932384;
const float circumference = diameter*radius;
const float fullRotation = 180; //There are 360 pulses for every rotation in the encoder.

void fwd(float inches)
{
	resetEncoders();
	float error = 6;
	//6 inches is the discovered error
	float rotations = (inches-error)/circumference;
	//turns on motors.
	motor[lt] = 31;
	motor[rt] = 30;
	while(SensorValue[encoderLT]/fullRotation < rotations)
	{
		/*
		//keeps repeating until rotations exceed calculated value.
		if(SensorValue[encoderLT] > 0.80*rotations)
		{
			//If there is only 20% of rotations left, slow down to account for momentum.
			motor[lt] = 30;
			motor[rt] = 30;
		}
		*/
		;
	}
	//turns off motors.
	motor[lt] = 0;
	motor[rt] = 0;
}
/*
void left()
{
	//Simply just turn on left motor to move a distance for 1/4 of a circle while leaving the right one off?
	resetEncoders();
	float rotations = (circumference/4)/circumference;
	motor[lt] = 100;
	while(SensorValue[encoderLT]/fullRotation < rotations)
	{
		;
	}
	motor[lt] = 0;

}
*/




void turn180()
{
	//Simply just turn on left motor to move a distance for 1/4 of a circle while leaving the right one off?
	resetEncoders();
	//float rotations = (circumference/2)/circumference;
	motor[rt] = 30;
	//motor[lt] = -31;
	while(SensorValue[encoderRT] < 180*6+67)
	{
		;
	}
	motor[rt] = 0;
	motor[lt] = 0;

}

void spin360(float inches)
{
	//Simply just turn on left motor to move a distance for 1/4 of a circle while leaving the right one off?
	//If inches is positive, clockwise
	//If inches are negative, counterclockwise.
	resetEncoders();

	float rotations = inches/circumference;
	//float rotations = 1;
	if(inches > 0)
	{
		//inches is positive, turn clockwise to the right.
		motor[rt] = 30;
		motor[lt] = -30;
	}
	else 
	{
		//inches is negative, turn counterclockwise towards the left.
		motor[rt] = -30;
		motor[lt] = 30;
	}
	
	while(SensorValue[encoderRT]/fullRotation < rotations)
	{
		;
	}
	motor[rt] = 0;
	motor[lt] = 0;

}

void right()
{
	spin360(10.7);
}

void left()
{
	spin360(-10.7);
}

void resetEncoders()
{
	//resets both encoders
	SensorValue[encoderLT]=0;
	SensorValue[encoderRT]=0;
}
