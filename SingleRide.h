/*
	Developed by Arian Ahmadinejad
	Drively : Grade 12 Computer Science Project
	2020-10-17
*/
#pragma once
#include "BaseRide.h"
#include <iostream>

// inherited class that only changes one of the methods making it really similar to the base class.

class SingleRide : public BaseRide
{
public:
	SingleRide(string rideType, string carName, string driverName, string licensePlate, string destination, int seatsAvailable);
	void getCostInfo();
	void calculateCost();
};



