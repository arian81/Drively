/*
	Developed by Arian Ahmadinejad
	Drively : Grade 12 Computer Science Project
	2020-10-17
*/
#include "SharedRide.h"

// class constructor uses member list initializer to pass the value to base class and sets the proper variables
SharedRide::SharedRide(string rideType, string carName, string driverName, string licensePlate, string destination, int seatsAvailable) : BaseRide(rideType, carName, driverName, licensePlate, destination, seatsAvailable) {};

// Instead of adding $15 single ride commission it adds $5 for each passenger
void SharedRide::calculateCost() {
	double temp = 1;
	temp *= (estimatedTime.min + (double(estimatedTime.sec) / 60));
	temp = round(temp, 2);
	cost.rideCost = temp;
	cost.drivelyCut = round(temp * 0.1, 2);
	cost.total = (cost.rideCost + cost.drivelyCut + cost.baseComission);
	cost.total += 5.0 * passengersInCar;
	cost.tax = round(cost.total * 0.13, 2);
	cost.total += cost.tax;
};

// Changes made to printing output to reflect multiple passengers on this ride
void SharedRide::getCostInfo() {
	//loops through passengers list and prints their names
	cout << "Total ride cost for ";
	for (int i = carCapacity; i > seatsAvailable; i--)
	{
		cout << " " << *passengers[i];
		if (i > 1) {
			cout << ",";
		}
	}
	cout << " is :\n" << endl << "Base trip rate (Same for any ride) :  \t$" << cost.baseComission << "\n \t\t\t\t      +" << endl;
	cout << "Ride cost based on estimated time : \t$" << cost.rideCost << "\n \t\t\t\t      +" << endl << "Driverly's cut (10%): \t\t\t$" << cost.drivelyCut << endl;
	cout << "\t\t\t\t      +" << endl << "HST tax (13%) : \t\t\t$" << cost.tax << endl << "\t\t\t\t      +" << endl << "$5 per person ride commission : \t$" << 5 * passengersInCar << "\n\n==================================================\n" << endl;
	cout << "Total trip cost : \t\t\t$" << cost.total << endl << endl;
	cout << "Amount payable by each passenger : \t$" << round(cost.total / passengersInCar, 3) << endl; // divides the cost between passengers as this is a shared ride
};

// Same as method before slight modification to take account of multiple passengers
void SharedRide::getRideInfo() {
	cout << driverName << " will pick you up. Your estimated ride time is " << estimatedTime.min << " minutes and " << estimatedTime.sec << " seconds." << endl;
	cout << "You chose to have a " << rideType << "ride." << endl;
	cout << "Car Model : " << carName << endl << "License Plate Number : " << licensePlate << endl;
	cout << "Passengers on this ride : " << endl;
	for (int i = carCapacity; i > seatsAvailable; i--)
	{
		cout << *passengers[i] << endl;
	}
	cout << "Amount payable by each passenger is : " << round(cost.total / passengersInCar, 3) << endl;
	cout << "If there's any mismatch between this data and actual driver please cancel the ride and report the driver." << endl;
};