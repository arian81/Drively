#pragma once
#include "BaseRide.h"
class SharedRide : public BaseRide
{
public:
	SharedRide(string rideType, string carName, string driverName, string licensePlate, string location, int seatsAvailable);
	void reserveSeat(string passengerName);
	/*void calculateCost();
	void getCostInfo();*/
};

