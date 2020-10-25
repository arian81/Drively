// Drively.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <algorithm>
#include <thread>
#include <chrono>
#include "BaseRide.h"
#include "SingleRide.h"
#include "Functions.h"
#include "SharedRide.h"
using namespace std;



int main()
{
        //========================================================== SETUP PHASE ====================================================================================================
        int availableDrivers = 0, seatsAvailable=0;
        string rideType, driverCar, driverName, driverLicensePlate, driverDestination;
        cout << "\t\t\t\t\tInitializing Drively";
        /*for (int i = 0; i < 10; i++)
        {
            cout << ".";
            this_thread::sleep_for(chrono::milliseconds(300));
        }*/
        cout << "\nHow many drivers are available right now ? >\t";
        availableDrivers = IsNum();
        BaseRide** availableRides = new BaseRide * [availableDrivers];
        availableRides[0] = new SharedRide("sahred","toyouta", "blob", "asdjf", "toronto", 7);
        availableRides[1] = new SingleRide("single","toyota","mamad","adfjkl","missisauga",1);
        availableRides[2] = new SingleRide("single", "toyota", "mamadagdsgd", "adfjkl", "toronto", 1);
        //SingleRide* holder = dynamic_cast<SingleRide*>(availableRides[0]);
        //CalculateCost(*holder);
        //availableRides[0]->getCostInfo();
        //holder->calculateCost();
       // holder->getCostInfo();
        //cout << holder->counter;



        /*for (int i = 0; i < availableDrivers; i++)
        {
            cout << "Please enter the details for driver #" << i+1 << endl << endl;
            cout << "Does this driver accept single rides or shared rides? (single/shared)  >\t";
            rideType = IsValidRideType();
            cout << "\n\nWhat car does this driver own?  >\t";
            getline(cin, driverCar);
            cout << "\n\nWhat's the name of the driver?  >\t";
            driverName = IsAlpha();
            cout << "\n\nPlease enter the license plate number for " << driverCar << "  >\t";
            driverLicensePlate = IsAlphaNum();
            cout << "\n\nWhere is " << driverName << " destination ?  >\t";
            driverDestination = IsAlphaNum();
            if (rideType == "shared") {
                cout << "How many seats are available ?  >\t";
                seatsAvailable = IsCarSeat();
            }
            else {
                seatsAvailable = 1;
            }
            availableRides[i] = new SingleRide(rideType,driverCar,driverName,driverLicensePlate,driverDestination,seatsAvailable);

        }
        system("pause");
                Clear();
        */

        availableRides[0]->reserveSeat("arian");
        availableRides[0]->reserveSeat("aysan");
        availableRides[0]->reserveSeat("iris");
        //availableRides[0]->calculateCost();
        /*availableRides[0]->getRideInfo();
        availableRides[0]->getCostInfo();*/
        availableRides[0]->getPassengersList();
        availableRides[0]->cancelSeat("aysan");
        availableRides[0]->getPassengersList();

//========================================================== MANAGING PHASE =================================================================================================
        string strChoices , costChoice;
        int intChoices;
        string passengerName , passengerDestination;
        int ridesCount = availableRides[0]->counter;
        bool noRideAvailable = true;
        while (true)
        {
            cout << "What can I do for you ?\n" << endl;
            cout << "1.Reserve a seat \t 2.Cancel a seat \t 3.Exit\n \t>";
            strChoices = IsAlphaNum();

            if (strChoices == "1" || strChoices.find("reserve") != string::npos)
            {
                cout << "\nPlease enter your first and last name \n >\t";
                passengerName = IsAlpha();
                if (passengerName == "exit")
                {
                    continue;
                }
                cout << "\nPlease enter your destination \n >\t";
                passengerDestination = IsAlphaNum();
                cout << "Here's a list of available rides. Please choose one of them\n" << endl;
                for (int i = 0; i < ridesCount; i++)
                {
                    if (availableRides[i]->seatsAvailable > 0 && availableRides[i]->destination == passengerDestination) {
                        cout << "Ride # : " << i+1 << endl <<endl;
                        availableRides[i]->getCarInfo();
                        noRideAvailable = false;
                        cout << "==================================================================================================================" << endl;
                    }
                }
                if (noRideAvailable == true)
                {
                    cout << "There's no ride available to your destination at this moment. Please try again later.\n" << endl;
                    system("pause");
                    Clear();
                }
                else
                {
                    cout << ">\t";
                    intChoices = IsNum();
                    availableRides[intChoices - 1]->reserveSeat(passengerName);
                    cout << "Your ride has been successfully reserved. Your driver is on their way to your location.\n" << endl;
                    cout << "Here is your ride details : \n" << endl;
                    availableRides[intChoices - 1]->calculateCost();
                    availableRides[intChoices - 1]->getRideInfo();
                    cout << "Do you wish to see a break down of your ride cost ?(yes/no)\n >";
                    costChoice = IsAlpha();
                    if (costChoice == "yes")
                    {
                        availableRides[intChoices - 1]->getCostInfo();
                    }
                    system("pause");
                    Clear();
                }
            }
            else if (strChoices == "2" || strChoices.find("cancel") != string::npos)
            {
                cout << "which ride is the passenger in ?" << endl;
                for (int i = 0; i < ridesCount; i++)
                {
                    if (availableRides[i]->passengersInCar > 0)
                    {
                        cout << "Ride # : " << i + 1 << endl << endl;
                        availableRides[i]->getCarInfo();
                        cout << "==================================================================================================================" << endl;
                    }
                    
                }
                cout << ">\t";
                intChoices = IsNum();
                cout << "Which passenger do you want to cancel seats for ?\n" << endl;
                availableRides[intChoices-1]->getPassengersList();
                cout << ">\t";
                passengerName = IsAlpha();
                if (passengerName == "exit")
                {
                    continue;
                }
                availableRides[intChoices-1]->cancelSeat(passengerName);
                system("pause");
                Clear();
            }
            else if (strChoices == "3" || strChoices.find("exit") != string::npos)
            {
                return 0;
            }
            else {
                cout << "\nNot a valid option. Please try again.\n" << endl;
            }
        }
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
