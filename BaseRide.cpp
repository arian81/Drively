#include "BaseRide.h"

using namespace std;

float round(float var, int precision)
{
	float value = (int)(var * (10 * precision) + .5);
	return (float)value / 100;
};

BaseRide::BaseRide(string rideType,string carName, string driverName, string licensePlate, string location, int seatsAvailable) :rideType(rideType), carName(carName), driverName(driverName), licensePlate(licensePlate), location(location), seatsAvailable(seatsAvailable) {
	srand(time(0));
	estimatedTime.min = (rand() % 20) + 1;
	estimatedTime.sec = (rand() % 59) + 1;
	counter++;
	
};
void BaseRide::reserveSeat(string passengerName) {
	this->seatsAvailable--;
};
void BaseRide::getRideInfo() {
	cout << driverName << " will pick you up in " << estimatedTime.min << " minutes and " << estimatedTime.sec << " seconds." << endl;
	cout << "You chose to have a " << rideType << "ride." << endl;
	cout << "Your amount payable is : $" << cost.total << endl;
	cout << "Car Model : " << carName << endl << "License Plate Number : " << licensePlate << endl;
	cout << "If there's any mismatch between this data and actual driver please cancel the ride and report the driver." << endl;
};
void BaseRide::getFullInfo() {
	cout << "Car Model : " << carName << endl << "Driver Name : " << driverName << endl << "License Plate Number : " << licensePlate << endl << "Location : " << location << endl << "Number of seats available : " << seatsAvailable << endl;
};
void BaseRide::getCostInfo() {
	cout << "Here is your detailed cost break down :\n" << endl << "Base trip rate (Same for any ride) :  \t$" << cost.baseComission << "\n \t\t\t\t      +" << endl;
	cout << "Ride cost based on estimated time : \t$" << cost.rideCost << "\n \t\t\t\t      +" << endl << "Driverly's cut (10%): \t\t\t$" << cost.drivelyCut << endl;
	cout << "\t\t\t\t      +" << endl << "HST tax (13%) : \t\t\t$" << cost.tax << "\n\n==================================================\n" << endl;
	cout << "Total trip cost : \t\t\t$" << cost.total << endl;
};
void BaseRide::calculateCost() {
	float temp = 1;
	temp *= (estimatedTime.min + (float(estimatedTime.sec) / 60));
	temp = round(temp, 2);
	cost.rideCost = temp;
	cost.drivelyCut = round(temp * 0.1, 2);
	cost.tax = round((cost.rideCost + cost.drivelyCut + cost.baseComission) * 0.13, 2);
	cost.total = (cost.rideCost +cost.drivelyCut + cost.baseComission + cost.tax);
}

int BaseRide::counter = 0;