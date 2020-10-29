/*
	Developed by Arian Ahmadinejad
	Drively : Grade 12 Computer Science Project
	2020-10-17
*/
#include "SingleRide.h"

using namespace std;

// class constructor uses member list initializer to pass the value to base class and sets the proper variables
SingleRide::SingleRide(string rideType, string carName, string driverName, string licensePlate, string destination, int seatsAvailable) : BaseRide(rideType,carName, driverName, licensePlate, destination, seatsAvailable) {};

// A slight change to base class optional receipt function to make it more in line with single ride type
void SingleRide::getCostInfo() {
	cout << "Dear " << *passengers[carCapacity] << ", Here is your detailed cost break down :\n" << endl << "Base trip rate (Same for any ride) :  \t$" << cost.baseComission << "\n \t\t\t\t      +" << endl;
	cout << "Ride cost based on estimated time : \t$" << cost.rideCost << "\n \t\t\t\t      +" << endl << "Driverly's cut (10%): \t\t\t$" << cost.drivelyCut << endl;
	cout << "\t\t\t\t      +" << endl << "HST tax (13%) : \t\t\t$" << cost.tax << "\n\n==================================================\n" << endl;
	cout << "Total trip cost + ($15 single ride commission): \t\t\t$" << cost.total << endl;
}

void SingleRide::calculateCost() {
	double temp = 1;
	temp *= (estimatedTime.min + (double(estimatedTime.sec) / 60));
	temp = round(temp, 2);
	cost.rideCost = temp;
	cost.drivelyCut = round(temp * 0.1, 2);
	cost.total = (cost.rideCost + cost.drivelyCut + cost.baseComission + 15); // $15 commission that only applies to single rides
	cost.tax = round(cost.total * 0.13, 2);
	cost.total += cost.tax;
};