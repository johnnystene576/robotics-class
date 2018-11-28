#pragma config(Motor,  motor4,          leftMotor,     tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor5,          rightMotor,    tmotorVexIQ, openLoop, encoder)

/*
Robot Code
Copyright (C) 2018 Johnny Stene

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#define DEFAULT_MOTOR_SPEED 50
#define TURNING_MOTOR_SPEED 30
#define TURN_AMOUNT 1000

#include "vexheaders.h" //For move() function, written by me. It's garbage, but hey, it works!

void doTurn(int time)
{
	delay(time); //Do the turn after specified time
	setTouchLEDColor(port2, colorGreen); //For debug
	move(RIGHT, TURNING_MOTOR_SPEED); //Turn right
	delay(TURN_AMOUNT); //Wait until turn complete
	move(FORWARD, DEFAULT_MOTOR_SPEED); //Go forward again
	setTouchLEDColor(port2, colorBlue); //For debug
}

task main()
{
	setTouchLEDColor(port2, colorOrange); //For debug
	//These two lines are for testing right turns, they aren't important
	int debug = 0;
	if(debug) while(1){doTurn(0);move(5, 0);delay(500);}
	setTouchLEDColor(port2, colorBlue); //For debug
	move(FORWARD, DEFAULT_MOTOR_SPEED); //Move forward
	//Turn to go through the labyrinth
	doTurn(3950);
	doTurn(4400);
	doTurn(3100);
	doTurn(2350);
	//Move into the finish
	delay(1050);
	//Start a finishing move
	move(RIGHT, DEFAULT_MOTOR_SPEED);
	delay(200);
	move(LEFT, DEFAULT_MOTOR_SPEED);
	delay(300);
	move(RIGHT, DEFAULT_MOTOR_SPEED);
	delay(100);
	move(100, 0); //Stop
	while(true) { //Finishing move code
  	setTouchLEDColor(port1, colorBlue);
  	setTouchLEDColor(port2, colorOrange);
  	move(LEFT, DEFAULT_MOTOR_SPEED);
  	delay(100);
  	setTouchLEDColor(port2, colorBlue);
  	setTouchLEDColor(port1, colorOrange);
  	move(RIGHT, DEFAULT_MOTOR_SPEED);
  	delay(100);
  	setTouchLEDColor(port1, colorGreen);
  	setTouchLEDColor(port2, colorRed);
  	move(LEFT, DEFAULT_MOTOR_SPEED);
  	delay(100);
  	setTouchLEDColor(port2, colorBlueGreen);
  	setTouchLEDColor(port1, colorYellow);
  	move(RIGHT, DEFAULT_MOTOR_SPEED);
  	delay(100);
  }
}
