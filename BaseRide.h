#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

double round(double value, int digits);

struct Time {
	
	int min = 0;
	int sec = 0;
};

struct Cost
{
	double baseComission = 5.0 , rideCost =0, drivelyCut =0,tax =0, total=0;
};

class BaseRide
{
protected:
	string carName , driverName ;

	Time estimatedTime;
	string** passengers = new string* [seatsAvailable];
	Cost cost;
	
public:
	BaseRide(string rideType, string carName, string driverName, string licensePlate, string Destination, int seatsAvailable);
	~BaseRide();
	string rideType , licensePlate , destination;
	int seatsAvailable = 0 , passengersInCar = 0 , carCapacity = seatsAvailable;
	static int counter;
	virtual void reserveSeat(string passengerName);
	virtual void cancelSeat(string passengerName);
	virtual void calculateCost();
	virtual void getRideInfo();
	void getCarInfo();
	virtual void getCostInfo();
	void getPassengersList();
};
