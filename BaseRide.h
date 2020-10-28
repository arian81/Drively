#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

double round(double value, int digits);

// a time structure to keep the min and sec for each ride estimated arrival to destination
struct Time {
	
	int min = 0;
	int sec = 0;
};

// a cost structure to hold different parts of total cost making a receipt after reserving seats possible
struct Cost
{
	double baseComission = 5.0 , rideCost =0, drivelyCut =0,tax =0, total=0;
};

// this is the base class used to create the two inherited classes , The three seatsAvailable , passengersIncar and carCapacity are important variables as their used for the logic in different stages of program. None of the functions return anything.
// 5 of the methods are virtual and have different functionalities based on the object
class BaseRide
{
protected:
	string carName , driverName ;

	Time estimatedTime;
	string** passengers = new string* [seatsAvailable]; // an array that keeps track of passenger names in the car
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
	virtual void getCostInfo();
	void getCarInfo();
	void getPassengersList();
};
