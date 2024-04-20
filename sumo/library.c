void update();
void arcadeStyleDrive();
void leftDriveSide(int power);
void rightDriveSide(int power);
void spinnerControl();

void testFrontLeft();
void testFrontRight();
void testBackLeft();
void testBackRight();

typedef struct {
    //joystick
    int leftY;
    int rightX;

    //Spinner
    int spinLeft;
    int spinRight;

} buttons;

buttons controller;


void update() {
    //Run this continously to retrieve controller values.
    //joystick
    controller.leftY = vexRT[Ch3];
    controller.rightX = vexRT[Ch1];

    //Spinner
        //Top left shoulder button
    controller.spinLeft = vexRT[Btn5U];
        //Top right shoulder button
    controller.spinRight = vexRT[Btn6U];

}


void leftDriveSide(int power) {
motor[frontLeft] = power;
motor[backLeft] = power;

}

void rightDriveSide(int power) {
motor[frontRight] = power;
motor[backRight] = power;

}

void arcadeStyleDrive() {
    leftDriveSide(controller.leftY + controller.rightX);
    rightDriveSide(controller.leftY - controller.rightX);
}

void spinnerControl() {
    if(controller.spinLeft) {
        motor[spinner] = -127;
    } else if (controller.spinRight) {
        motor[spinner] = 127;
    } else {
        motor[spinner] = 0;
    }
}

//test functions
void testFrontLeft() {
    motor[frontLeft] = 127;
}

void testFrontRight() {
    motor[frontRight] = 127;
}

void testBackLeft() {
    motor[backLeft] = 127;
}

void testBackRight() {
    motor[backRight] = 127;
}
