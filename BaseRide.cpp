/*
	Developed by Arian Ahmadinejad
	Drively : Grade 12 Computer Science Project
	2020-10-17
*/
#include "BaseRide.h"

using namespace std;

// a function that rounds a number to specific digits
double round(double value, int digits)
{
	if (value == 0.0) // otherwise it will return 'nan' due to the log10() of zero
		return 0.0;

	double factor = std::pow(10.0, digits - std::ceil(std::log10(std::fabs(value))));
	return std::round(value * factor) / factor;
}
// Class constructor gets values from user input variables and sets them using member initializer list
BaseRide::BaseRide(string rideType,string carName, string driverName, string licensePlate, string destination, int seatsAvailable) :rideType(rideType), carName(carName), driverName(driverName), licensePlate(licensePlate), destination(destination), seatsAvailable(seatsAvailable) {
	// Generates a random number for belows 20 for time construct minutes and a random number below 60 for time construct seconds 
	srand(time(0));
	estimatedTime.min = (rand() % 20) + 1;
	estimatedTime.sec = (rand() % 59) + 1;
	// adds one to the counter variable which is a static variable to keep track of how many classes are generated
	counter++;
};

// Class destructor deletes the passengers dynamic array also decreases the static counter by 1
BaseRide::~BaseRide() {
	if (passengersInCar > 0) {
		for (int i = carCapacity; i > seatsAvailable; i--)
		{
			delete passengers[i];
		}
	}
	delete[] passengers;
	counter--;
};

// A method that starts from the end of array and places given input which is passenger names. This method is shared across all classes and doesn't change based on object.
void BaseRide::reserveSeat(string passengerName) {
	this->passengers[seatsAvailable] = new string(passengerName);
	this->seatsAvailable--;
	this->passengersInCar++;
};

// A methods that prints the ride information in a user friendly manner. In the SharedRide class there's a slight modification to parts of this method
void BaseRide::getRideInfo() {
	cout << driverName << " will pick you up and estimated ride time is " << estimatedTime.min << " minutes and " << estimatedTime.sec << " seconds." << endl;
	cout << "You chose to have a " << rideType << " ride." << endl;
	cout << "Your amount payable is : $" << cost.total << endl;
	cout << "Car Model : " << carName << endl << "License Plate Number : " << licensePlate << endl;
	cout << "If there's any mismatch between this data and actual driver please cancel the ride and report the driver." << endl;
};

// A method that shows the information about the driver and car and used in main class to show a list of drives based on specific logic
void BaseRide::getCarInfo() {
	cout <<"Ride type : " << rideType << endl<< "Car Model : " << carName << endl << "Driver Name : " << driverName << endl << "License Plate Number : " << licensePlate << endl << "Destination : " << destination << endl << "Number of seats available : " << seatsAvailable << endl;
};

// A method that prints a receipt like output for the user at their request
void BaseRide::getCostInfo() {
	cout << "Here is your detailed cost break down :\n" << endl << "Base trip rate (Same for any ride) :  \t$" << cost.baseComission << "\n \t\t\t\t      +" << endl;
	cout << "Ride cost based on estimated time : \t$" << cost.rideCost << "\n \t\t\t\t      +" << endl << "Driverly's cut (10%): \t\t\t$" << cost.drivelyCut << endl;
	cout << "\t\t\t\t      +" << endl << "HST tax (13%) : \t\t\t$" << cost.tax << "\n\n==================================================\n" << endl;
	cout << "Total trip cost : \t\t\t$" << cost.total << endl;
	cout << cost.total / passengersInCar;
};

// A method that fills the cost construct with proper values based on calculations done on the time it takes to get to the destination and other factors like tax and base commission for each ride. 
void BaseRide::calculateCost() {
	double temp = 1;
	temp *= (estimatedTime.min + (double(estimatedTime.sec) / 60));
	temp = round(temp, 2);
	cost.rideCost = temp;
	cost.drivelyCut = round(temp * 0.1, 2);
	cost.total = (cost.rideCost + cost.drivelyCut + cost.baseComission);
	cost.tax = round(cost.total * 0.13, 2);
	cost.total += cost.tax;
};

// A method that cancels a seat belonging to specific passenger.
void BaseRide::cancelSeat(string passengerName) {
	bool passengerFound = false; // A bool variable used in logic for checking whether the passenger exist in database or no
	int deletedPassenger = 0; // A constant to keep track of the index of deleted entry to be use while adjusting the array
	for (int i = carCapacity; i > seatsAvailable; i--)
	{
		// Deletes the passenger name from passenger array and adjust seatsAvailable and passengersInCar variables accordingly
		if (*passengers[i] == passengerName)
		{
			delete passengers[i];
			deletedPassenger = i;
			seatsAvailable++;
			passengersInCar--;
			passengerFound = true; // Sets the bool variable to true so the error won't show to the user
		}
	}
	// Shifts each entry after the deleted passenger entry on index up to prevent read access violation errors.
	for (int i = deletedPassenger; i > seatsAvailable; i--)
	{
		passengers[i] = passengers[i-1];
	}
	// Showing a error message in case the entered user doesn't exist in the database.
	if (passengerFound == false) {
		cout << "Passenger not found. Record already deleted or you have entered the wrong passenger name.\n" << endl;
	}
	// Showing a message Informing the user of the successful deletion
	else {
		cout << "Passenger successfully deleted.\n" << endl;
	}
};

// A method used to print the list of passengers in the car. Noticeable point is that the entries in the array are in the form of FIFO and First item is in the last array index so the for loop would start at the end of array and comes down to comply with FIFO structure and avoid read access exceptions.
void BaseRide::getPassengersList() {
	for (int i = carCapacity; i > seatsAvailable; i--)
	{
		cout << *passengers[i] << endl;
	}
}

int BaseRide::counter = 0; // setting the static variable to zero