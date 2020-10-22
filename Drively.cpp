// Drively.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BaseRide.h"
#include "SingleRide.h"
#include <exception>
#include <algorithm>
#include "Functions.h"
using namespace std;



int main()
{
    string userName = "123" , userLocation = "no where";
    

        //========================================================== SETUP PHASE ====================================================================================================
        int availableDrivers = 0, seatsAvailable=0;
        string rideType, driverCar, driverName, driverLicensePlate, driverLocation;
        cout << "How many drivers are available right now ? >\t";
        availableDrivers = IsNum();
        BaseRide** availableRides = new BaseRide * [availableDrivers];
        availableRides[0] = new SingleRide("sahred","toyouta", "blob", "asdjf", "lakdflj", 1);
        availableRides[1] = new SingleRide("single", "toyouta", "blob", "asdjf", "lakdflj", 1);
        //SingleRide* holder = dynamic_cast<SingleRide*>(availableRides[0]);
        //CalculateCost(*holder);
        //availableRides[0]->getCostInfo();
        //holder->calculateCost();
       // holder->getCostInfo();
        //cout << holder->counter;
        for (int i = 0; i < availableDrivers; i++)
        {
            cout << "Please enter the details for driver #" << i << endl << endl;
            cout << "Does this driver accept single rides or shared rides? (single/shared)  >\t";
            rideType = IsValidRideType();
            cout << "\n\nWhat car does this driver own?  >\t";
            getline(cin, driverCar);
            cout << "\n\nWhat's the name of the driver?  >\t";
            driverName = IsAlpha();
            cout << "\n\nPlease enter the license plate number for " << driverCar << "  >\t";
            driverLicensePlate = IsAlphaNum();
            cout << "\n\nWhere is " << driverName << " located ?  >\t";
            driverLocation = IsAlphaNum();
            if (rideType == "shared") {
                cout << "How many seats are available ?  >\t";
                seatsAvailable = IsNum();
            }
            else {
                seatsAvailable = 1;
            }
            availableRides[i] = new SingleRide(rideType,driverCar,driverName,driverLicensePlate,driverLocation,seatsAvailable);

        }

//========================================================== MANAGING PHASE =================================================================================================
    /*do
    {
        cout << "Please enter your first and last name." << endl;
        getline(cin, userName);
    } while (IsLetters(userName) == 0); 
    cin.ignore();
    cout << "What's your current location ? \n >";
    getline(cin, userLocation);
    cout << "Do you want a private trip or you want to share your ride for a reduced price" << endl;
        }*/

    /*SingleRide car1("toyouta","blob","asdjf","lakdflj",1);
    CalculateCost(car1);
    car1.getCostInfo();*/
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
