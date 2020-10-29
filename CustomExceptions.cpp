/*
    Developed by Arian Ahmadinejad
    Drively : Grade 12 Computer Science Project
    2020-10-17
*/
#include "CustomExceptions.h"

// custom exceptions inherited from exception library

InvalidInput::InvalidInput(const string msg) : invalid_argument(msg) {};

OutOfRangeSeat::OutOfRangeSeat(const string msg) : out_of_range(msg) {};

OutOfRangeRide::OutOfRangeRide(const string msg) : out_of_range(msg) {};