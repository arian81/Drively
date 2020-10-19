#pragma once
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Time {
	
	int min;
	int sec;
};

struct Cost
{
	float baseComission = 5.0 , rideCost =0, drivelyCut =0,tax =0, total=0;
};
class BaseRide
{
protected:
	BaseRide(string carName, string driverName, string licensePlate, string location, int seatsAvailable);
	string carName , driverName , licensePlate , location;
	int seatsAvailable;
	Time estimatedTime;
	string passengers[4];
	Cost cost;
public:
	virtual void reserveSeat(string passengerName);
	void getRideInfo();
	void getInfoAdmin();
	void getDetailedCostInfo();
};
