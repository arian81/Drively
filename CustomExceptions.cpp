#include "CustomExceptions.h"

InvalidInput::InvalidInput(const string msg) : invalid_argument(msg) {};

OutOfRangeSeat::OutOfRangeSeat(const string msg) : out_of_range(msg) {};

OutOfRangeRide::OutOfRangeRide(const string msg) : out_of_range(msg) {};