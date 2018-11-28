//These are used for the move() function
#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

void move(int movement, int speed)
{
	//By default, don't move
	int lmtr;
	int rmtr;
	if(movement == LEFT) {
		lmtr = 1;
		rmtr = 1;
	}
	else if(movement == RIGHT) {
		lmtr = -1;
		rmtr = -1;
	}
	else if(movement == FORWARD) {
		lmtr = 1;
		rmtr = -1;
	}
	else if(movement == BACKWARD) {
		lmtr = -1;
		rmtr = 1;
	}
	else {
		lmtr = 0;
		rmtr = 0;
	}

	//Move
	motor[leftMotor] = lmtr * speed;
	motor[rightMotor] = rmtr * speed;
}

void waitForEncoderValue(int value)
{
	//Reset the motor encoders to zero
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);

	//Wait until either motor's encoder shows the wanted value
	waitUntil(getMotorEncoder(leftMotor) == value);
}


/*
void waitForButtonPress(int release)
{
	//Wait until the bumper is pressed
	waitUntil(getBumperValue(bumpSwitch) == 1);

	if(release)
		//Wait until button is released (if needed)
		waitUntil(getBumperValue(bumpSwitch) == 0);
}
*/
