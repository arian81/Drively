#pragma once
#include <string>

using namespace std;

class BaseRide
{
protected:
	string carName , driverName , licensePlate , location;
	int seatsAvailable , estimatedTime;
	string passengers[4];
public:
	BaseRide(string carName, string driverName, string licensePlate, string location, int seatsAvailable);
	virtual void reserveSeat(string passengerName);
	void getRideInfo();
};

