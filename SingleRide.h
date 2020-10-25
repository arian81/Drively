#pragma once
#include "BaseRide.h"
#include <iostream>
class SingleRide : public BaseRide
{
public:
	SingleRide(string rideType, string carName, string driverName, string licensePlate, string destination, int seatsAvailable);
	void reserveSeat(string passengerName);
	//void calculateCost();
	void getCostInfo();

};



