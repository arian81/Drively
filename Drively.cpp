// Drively.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BaseRide.h"
#include "SingleRide.h"
#include <exception>
#include <algorithm>
using namespace std;

class InvalidInput : public invalid_argument {
public:
    explicit InvalidInput(const string& msg) : invalid_argument(msg) {};
};

void intInputCheck(string msg,int &input) {
    while (std::cout << msg && !(std::cin >> input)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Only numeric input is valid. Please try again.\n";
    }
}

bool IsLetters(string input)
{
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    for (int i = 0; i < input.size(); i++)
    {
        int uppercaseChar = toupper(input[i]); //Convert character to upper case version of character
        if (uppercaseChar < 'A' || uppercaseChar > 'Z') //If character is not A-Z
        {
            cout << "First and last name only consist of letters. Please check your input." << endl;
            return false;
        }
    }
    //At this point, we have gone through every character and checked it.
    return true; //Return true since every character had to be A-Z
}

float round(float var,int precision)
{
    float value = (int)(var * (10*precision) + .5);
    return (float)value / 100;
}

void CalculateCost(SingleRide& ride) {
    float cost = 1;
    cost *= (ride.estimatedTime.min + (float(ride.estimatedTime.sec) / 60));
    /*cost = (int)(cost * 100 + .5);
    cost = (float)cost / 100;*/
    cost = round(cost, 2);
    ride.cost.rideCost = cost;
    ride.cost.drivelyCut = round(cost * 0.03,2);
    ride.cost.tax = round((ride.cost.rideCost + ride.cost.drivelyCut + ride.cost.baseComission) * 0.13,2);
    ride.cost.total = (ride.cost.rideCost + ride.cost.drivelyCut + ride.cost.baseComission + ride.cost.tax);
}

int main()
{
    /*int userType;
    string userName = "123" , userLocation;

    intInputCheck("Select your user status : \n 1.Customer \t\t 2.Admin \n >", userType);
    cin.ignore();
    try {
        if (userType == 1) {
            do
            {
                cout << "Please enter your first and last name." << endl;
                getline(cin, userName);
            } while (IsLetters(userName) == 0); 
            cin.ignore();
            cout << "What's your current location ? \n >";
            getline(cin, userLocation);
            cout << "Do you want a private trip or you want to share your ride for a reduced price" << endl;
        }
            
      
        else if (userType == 2) {

        }
        else {
            throw invalid_argument("Invalid input");
        }
    }
    catch(invalid_argument &exp){
        cout << "You can either choose a Customer account or Admin account. Your input is invalid." << endl;
    }*/
    SingleRide car1("toyouta","blob","asdjf","lakdflj",1);
    CalculateCost(car1);
    car1.getDetailedCostInfo();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
