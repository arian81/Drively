#pragma once
#include <exception>
#include <stdexcept>

using namespace std;

class InvalidInput : public invalid_argument
{
	public:
	explicit InvalidInput(const string msg);
};