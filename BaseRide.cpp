#include "BaseRide.h"

using namespace std;

double round(double value, int digits)
{
	if (value == 0.0) // otherwise it will return 'nan' due to the log10() of zero
		return 0.0;

	double factor = pow(10.0, digits - ceil(log10(fabs(value))));
	return round(value * factor) / factor;
}

BaseRide::BaseRide(string rideType,string carName, string driverName, string licensePlate, string destination, int seatsAvailable) :rideType(rideType), carName(carName), driverName(driverName), licensePlate(licensePlate), destination(destination), seatsAvailable(seatsAvailable) {
	srand(time(0));
	estimatedTime.min = (rand() % 20) + 1;
	estimatedTime.sec = (rand() % 59) + 1;
	counter++;
	
};

BaseRide::~BaseRide() {
	for (int i = 0; i < seatsAvailable; i++)
	{
		delete[] passengers[i];
	}
	delete[] passengers;
	counter--;
};

void BaseRide::reserveSeat(string passengerName) {
	this->seatsAvailable--;
};

void BaseRide::getRideInfo() {
	cout << driverName << " will pick you up and estimated ride time is " << estimatedTime.min << " minutes and " << estimatedTime.sec << " seconds." << endl;
	cout << "You chose to have a " << rideType << " ride." << endl;
	cout << "Your amount payable is : $" << cost.total << endl;
	cout << "Car Model : " << carName << endl << "License Plate Number : " << licensePlate << endl;
	cout << "If there's any mismatch between this data and actual driver please cancel the ride and report the driver." << endl;
};

void BaseRide::getCarInfo() {
	cout <<"Ride type : " << rideType << "Car Model : " << carName << endl << "Driver Name : " << driverName << endl << "License Plate Number : " << licensePlate << endl << "Destination : " << destination << endl << "Number of seats available : " << seatsAvailable << endl;
};

void BaseRide::getCostInfo() {
	cout << "Here is your detailed cost break down :\n" << endl << "Base trip rate (Same for any ride) :  \t$" << cost.baseComission << "\n \t\t\t\t      +" << endl;
	cout << "Ride cost based on estimated time : \t$" << cost.rideCost << "\n \t\t\t\t      +" << endl << "Driverly's cut (10%): \t\t\t$" << cost.drivelyCut << endl;
	cout << "\t\t\t\t      +" << endl << "HST tax (13%) : \t\t\t$" << cost.tax << "\n\n==================================================\n" << endl;
	cout << "Total trip cost : \t\t\t$" << cost.total << endl;
	cout << cost.total / passengersInCar;
};

void BaseRide::calculateCost() {
	float temp = 1;
	temp *= (estimatedTime.min + (float(estimatedTime.sec) / 60));
	temp = round(temp, 2);
	cost.rideCost = temp;
	cost.drivelyCut = round(temp * 0.1, 2);
	cost.total = (cost.rideCost + cost.drivelyCut + cost.baseComission + 15);
	cost.tax = round(cost.total * 0.13, 2);
	cost.total += cost.tax;
};

void BaseRide::cancelSeat(string passengerName) {
	bool passengerFound = false;
	int deletedPassenger = 0;
	for (int i = carCapacity; i > seatsAvailable; i--)
	{
		if (*passengers[i] == passengerName)
		{
			delete passengers[i];
			deletedPassenger = i;
			seatsAvailable++;
			passengersInCar--;
			passengerFound = true;
		}
	}
	for (int i = deletedPassenger; i > seatsAvailable; i--)
	{
		passengers[i] = passengers[i-1];
	}
	if (passengerFound == false) {
		cout << "Passenger not found. Record already deleted or you have entered the wrong passenger name.\n" << endl;
	}
	else {
		cout << "Passenger successfully deleted.\n" << endl;
	}
};

void BaseRide::getPassengersList() {
	for (int i = carCapacity; i > seatsAvailable; i--)
	{
		cout << *passengers[i] << endl;
	}
}
int BaseRide::counter = 0;