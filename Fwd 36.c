#pragma config(Sensor, dgtl1,  encoderLT,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  encoderRT,      sensorQuadEncoder)
#pragma config(Motor,  port5,           lt,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rt,            tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "libary/movement.c"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//Port 5: Left drive
//Port 6: Right Drive

task main()
{
	wait1Msec(2000);
	fwd(36);

}
