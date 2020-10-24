#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

float round(float var, int precision);

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
	
	string carName , driverName , licensePlate , location;
	int seatsAvailable;
	Time estimatedTime;
	string** passengers = new string* [seatsAvailable];
	Cost cost;
	
public:
	BaseRide(string rideType, string carName, string driverName, string licensePlate, string location, int seatsAvailable);
	~BaseRide();
	string rideType;
	virtual void reserveSeat(string passengerName);
	virtual void calculateCost();
	void getRideInfo();
	void getFullInfo();
	virtual void getCostInfo();
	static int counter;
	int passengersInCar = 0;
};
