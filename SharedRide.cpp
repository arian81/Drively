#include "SharedRide.h"

SharedRide::SharedRide(string rideType, string carName, string driverName, string licensePlate, string location, int seatsAvailable) : BaseRide(rideType, carName, driverName, licensePlate, location, seatsAvailable) {};

void SharedRide::reserveSeat(string passenger) {
	this->passengers[seatsAvailable] =new string (passenger);
	this->seatsAvailable--;
	this->passengersInCar++;
	
};

BaseRide::~BaseRide(){
	for (int i = 0; i < seatsAvailable; i++)
	{
		delete[] passengers[i];
	}
	delete[] passengers;
}