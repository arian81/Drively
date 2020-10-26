#include "Functions.h"

int IsNum() {
    string input;
    while (true)
    {
        try
        {
            cout << ">\t";
            getline(cin, input);
            if (input.find_first_not_of("0123456789") != std::string::npos || input.length() == 0)
            {

                throw InvalidInput("letters in number-only input");

            }
            return stoi(input);
        }
        catch (InvalidInput& exp)
        {
            cout << "\nThis prompt only accepts numbers. Please check your input.\n" << endl;
            cout << "Error ! " << exp.what() << endl << endl;
        }
    }
};

string IsAlpha() {
    string input;
    while (true)
    {
        try
        {
            cout << ">\t";
            getline(cin, input);
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != std::string::npos || input.length() == 0)
            {

                throw InvalidInput("numbers in letter-only input");

            }
            return input;
        }
        catch (InvalidInput& exp)
        {
            cout << "\nThis prompt only accepts letters. Please check your input.\n" << endl;
            cout << "Error ! " << exp.what() << endl << endl;
        }
    }

};


string IsAlphaNum() {
    string input;
    while (true)
    {
        try
        {
            cout << ">\t";
            getline(cin, input);
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_ ") != std::string::npos || input.length() == 0)
            {

                throw InvalidInput("Special characters found");

            }
            return input;
        }
        catch (InvalidInput& exp)
        {
            cout << "\nSpecial Characters are prohibited in this prompt. Please check your input.\n" << endl;
            cout << "Error ! " << exp.what() << endl << endl;
        }
    }

};

string IsValidRideType() {
    string input;
    while (true)
    {
        try
        {
            cout << ">\t";
            getline(cin, input);
            if (input != "single" && input != "shared" || input.length() == 0)
            {

                throw InvalidInput("irrelevant input");

            }
            return input;
        }
        catch (InvalidInput& exp)
        {
            cout << "\nRide type can only be 'single' or 'shared'. Please check your input.\n" << endl;
            cout << "Error ! " << exp.what() << endl << endl;
        }
    }

};

int IsCarSeat() {
    string input;
    while (true)
    {
        try
        {
            cout << ">\t";
            getline(cin, input);
            if (input.find_first_not_of("0123456") != std::string::npos || input.length()>1 || input.length() == 0)
            {

                throw OutOfRangeSeat("seat not in range");

            }
            return stoi(input);
        }
        catch (OutOfRangeSeat& exp)
        {
            cout << "\nA car can't have less than zero or more than 6 passenger seats. Please check your input.\n" << endl;
            cout << "Error ! " << exp.what() << endl << endl;
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

void PrintLogo()
{
    cout << "\t\t				  " << "*#############" << endl << "\t\t    			     " << "(###/               *###." << endl;
    cout << "\t\t          		" << "*###/                         .##/" << endl <<"\t\t\t\t    " << "####                                    ##" << endl;
    cout <<" \t\t\t\t (#/                                             / " << endl << "\n\t\t\t    *((((((((((##################(    ____         _               __" << endl << endl << endl;

    cout << "\t\t\t\t     " << "/ __ \\ _____ (_)_   __ ___   / /__  __" << endl << "\t\t\t\t    " << "/ / / // ___// /| | / // _ \\ / // / / /" << endl;
    cout << "\t\t\t\t   " << "/ /_/ // /   / / | |/ //  __// // /_/ /" << endl << "\t\t\t\t  /_____//_/   /_/  |___/ \\___//_/ \\__, /" << endl;
    cout << "\t\t\t\t				  " << "/____/" << endl;
};