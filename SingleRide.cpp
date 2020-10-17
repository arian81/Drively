#include "SingleRide.h"
void SingleRide::reserveSeat(string passenger) {
	this->seatsAvailable = 0;
	this->passengers[0] = passenger;
}