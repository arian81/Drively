#pragma once
#include "BaseRide.h"
class SingleRide : public BaseRide
{
	SingleRide(string carName, string driverName, string licensePlate, string location, int seatsAvailable);
	void reserveSeat(string passengerName);
};

