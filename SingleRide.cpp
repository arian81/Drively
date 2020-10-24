#include "SingleRide.h"


using namespace std;

//float round(float var, int precision);

SingleRide::SingleRide(string rideType, string carName, string driverName, string licensePlate, string location, int seatsAvailable) : BaseRide(rideType,carName, driverName, licensePlate, location, seatsAvailable) {};

void SingleRide::reserveSeat(string passenger) {
	this->passengers[seatsAvailable] = new string(passenger);
	this->seatsAvailable = 0;
	this -> passengersInCar++;
};

void SingleRide::calculateCost() {
	float temp = 1;
	temp *= (estimatedTime.min + (float(estimatedTime.sec) / 60));
	temp = round(temp, 2);
	cost.rideCost = temp;
	cost.drivelyCut = round(temp * 0.1, 2);
	cost.tax = round((cost.rideCost + cost.drivelyCut + cost.baseComission) * 0.13, 2);
	cost.total = (cost.rideCost + cost.drivelyCut + cost.baseComission + cost.tax);
	cost.total += 15;
};

void SingleRide::getCostInfo() {
	cout << "Dear " << passengers[0] << ", Here is your detailed cost break down :\n" << endl << "Base trip rate (Same for any ride) :  \t$" << cost.baseComission << "\n \t\t\t\t      +" << endl;
	cout << "Ride cost based on estimated time : \t$" << cost.rideCost << "\n \t\t\t\t      +" << endl << "Driverly's cut (10%): \t\t\t$" << cost.drivelyCut << endl;
	cout << "\t\t\t\t      +" << endl << "HST tax (13%) : \t\t\t$" << cost.tax << "\n\n==================================================\n" << endl;
	cout << "Total trip cost + ($15 single ride commission): \t\t\t$" << cost.total;
}