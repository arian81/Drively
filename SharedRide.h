/*
	Developed by Arian Ahmadinejad
	Drively : Grade 12 Computer Science Project
	2020-10-17
*/
#pragma once
#include "BaseRide.h"

// This is a more advanced object with changes to 3 of the base class virtual methods
class SharedRide : public BaseRide
{
public:
	SharedRide(string rideType, string carName, string driverName, string licensePlate, string destination, int seatsAvailable);
	void calculateCost();
	void getCostInfo();
	void getRideInfo();
};

