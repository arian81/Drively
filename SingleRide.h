#pragma once
#include "BaseRide.h"
class SingleRide : public BaseRide
{
	friend void CalculateCost(SingleRide& ride);
public:
	SingleRide(string carName, string driverName, string licensePlate, string location, int seatsAvailable);
	void reserveSeat(string passengerName);

};



