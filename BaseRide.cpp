#include "BaseRide.h"
#include <iostream>

using namespace std;

BaseRide::BaseRide(string carName, string driverName, string licensePlate, string location, int seatsAvailable) : carName(carName), driverName(driverName), licensePlate(licensePlate), location(location), seatsAvailable(seatsAvailable) {};
void BaseRide::reserveSeat(string passengerName) {
	this->seatsAvailable--;
};
void BaseRide::getRideInfo() {

	cout << "Driver's Name :" << driverName << endl;
	cout << ""
}