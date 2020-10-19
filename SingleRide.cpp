#include "SingleRide.h"

SingleRide::SingleRide(string carName, string driverName, string licensePlate, string location, int seatsAvailable) : BaseRide(carName, driverName, licensePlate, location, seatsAvailable) {
	//cost *= (estimatedTime.min + (float(estimatedTime.sec) / 60));
	//cost = (int)(cost * 100 + .5);
	//cost = (float)cost / 100;
	//cost += 5; // base commission for any trip 
};

void SingleRide::reserveSeat(string passenger) {
	this->seatsAvailable = 0;
	this->passengers[0] = passenger;
}