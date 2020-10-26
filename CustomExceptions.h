#pragma once
#include <exception>
#include <stdexcept>

using namespace std;

class InvalidInput : public invalid_argument
{
	public:
	explicit InvalidInput(const string msg);
};

class OutOfRangeSeat : public out_of_range
{
public:
	explicit OutOfRangeSeat(const string msg);
};