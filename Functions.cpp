#include "Functions.h"

int IsNum() {
    string input;
    while (true)
    {
        try
        {
            getline(cin, input);
            if (input.find_first_not_of("0123456789") != std::string::npos)
            {

                throw InvalidInput("bad input");

            }
            return stoi(input);
        }
        catch (InvalidInput& exp)
        {
            cout << "This prompt only accepts numbers. Please check your input." << endl;
        }
    }
};

string IsAlpha() {
    string input;
    while (true)
    {
        try
        {
            getline(cin, input);
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != std::string::npos)
            {

                throw InvalidInput("bad input");

            }
            return input;
        }
        catch (InvalidInput& exp)
        {
            cout << "This prompt only accepts letters. Please check your input." << endl;
        }
    }

};


string IsAlphaNum() {
    string input;
    while (true)
    {
        try
        {
            getline(cin, input);
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_ ") != std::string::npos)
            {

                throw InvalidInput("bad input");

            }
            return input;
        }
        catch (InvalidInput& exp)
        {
            cout << "Special Characters are prohibited in this prompt. Please check your input." << endl;
        }
    }

};

string IsValidRideType() {
    string input;
    while (true)
    {
        try
        {
            getline(cin, input);
            if (input != "single" && input != "shared")
            {

                throw InvalidInput("bad input");

            }
            return input;
        }
        catch (InvalidInput& exp)
        {
            cout << "Ride type can only be 'single' or 'shared'. Please check your input." << endl;
        }
    }

};

int IsCarSeat() {
    string input;
    while (true)
    {
        try
        {
            getline(cin, input);
            if (input.find_first_not_of("0123456") != std::string::npos || input.length()>1)
            {

                throw InvalidInput("bad input");

            }
            return stoi(input);
        }
        catch (InvalidInput& exp)
        {
            cout << "A car can't have less than zero or more than 6 passenger seats. Please check your input." << endl;
        }
    }
};

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
};