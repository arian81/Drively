#pragma once
#include "BaseRide.h"
#include <iostream>
class SingleRide : public BaseRide
{
public:
	SingleRide(string rideType, string carName, string driverName, string licensePlate, string location, int seatsAvailable);
	void reserveSeat(string passengerName);
	void calculateCost();
	void getCostInfo();
	int random = 123;

};



