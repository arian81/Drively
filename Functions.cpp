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
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
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
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") != std::string::npos)
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