#include "BaseRide.h"
#include <iostream>

using namespace std;

BaseRide::BaseRide(string carName, string driverName, string licensePlate, string location, int seatsAvailable) : carName(carName), driverName(driverName), licensePlate(licensePlate), location(location), seatsAvailable(seatsAvailable) {
	srand(time(0));
	estimatedTime.min = (rand() % 20) + 1;
	estimatedTime.sec = (rand() % 59) + 1;
	
};
void BaseRide::reserveSeat(string passengerName) {
	this->seatsAvailable--;
};
void BaseRide::getRideInfo() {
	cout << driverName << " will pick you up in " << estimatedTime.min << " minutes and " << estimatedTime.sec << " seconds." << endl;
	cout << "Your amount payable is : $" << cost.total << endl;
	cout << "Car Model : " << carName << endl << "License Plate Number : " << licensePlate << endl;
	cout << "If there's any mismatch between this data and actual driver please cancel the ride and report the driver." << endl;
};
void BaseRide::getInfoAdmin() {
	cout << "Car Model : " << carName << endl << "Driver Name : " << driverName << endl << "License Plate Number : " << licensePlate << endl << "Location : " << location << endl << "Number of seats available : " << seatsAvailable << endl;
};
void BaseRide::getDetailedCostInfo() {
	cout << "Here is your detailed cost break down :\n" << endl << "Base trip rate (Same for any ride) :  \t$" << cost.baseComission << "\n \t\t\t\t      +" << endl;
	cout << "Ride cost based on estimated time : \t$" << cost.rideCost << "\n \t\t\t\t      +" << endl << "Driverly's cut (3%): \t\t\t$" << cost.drivelyCut << endl;
	cout << "\t\t\t\t      +" << endl << "HST tax (13%) : \t\t\t$" << cost.tax << "\n\n==================================================\n" << endl;
	cout << "Total trip cost : \t\t\t$" << cost.total;
};