#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

double round(double value, int digits);

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
	string carName , driverName , licensePlate;

	Time estimatedTime;
	string** passengers = new string* [seatsAvailable];
	Cost cost;
	
public:
	BaseRide(string rideType, string carName, string driverName, string licensePlate, string Destination, int seatsAvailable);
	~BaseRide();
	string rideType;
	virtual void reserveSeat(string passengerName);
	virtual void cancelSeat(string passengerName);
	virtual void calculateCost();
	virtual void getRideInfo();
	void getCarInfo();
	virtual void getCostInfo();
	void getPassengersList();
	string destination;
	int seatsAvailable = 0;
	static int counter;
	int passengersInCar = 0;
	int carCapacity = seatsAvailable;
};
