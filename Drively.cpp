/*
    Developed by Arian Ahmadinejad
    Drively : Grade 12 Computer Science Project
    2020-10-17
*/

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
        bool isLicensePlate = false;
        std::cout << "\t\t\t\t\tInitializing Drively Setup Procedure";
        for (int i = 0; i < 10; i++)
        {
            std::cout << ".";
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        std::cout << endl << endl;
        PrintLogo();

        std::cout << "\nHow many drivers are available right now ?";
        availableDrivers = IsNum();
        BaseRide** availableRides = new BaseRide * [availableDrivers];
        for (int i = 0; i < availableDrivers; i++)
        {
            std::cout << "Please enter the details for driver #" << i+1 << endl << endl;
            std::cout << "Does this driver accept single rides or shared rides? (single/shared)";
            rideType = IsValidRideType();
            std::cout << "\n\nWhat car does this driver own?  ";
            getline(cin, driverCar);
            std::cout << "\n\nWhat's the name of the driver?  ";
            driverName = IsAlpha();
            std::cout << "\n\nPlease enter the license plate number for " << driverCar << "?  ";
            if (i==0)
            {
                driverLicensePlate = IsAlphaNum();
            }
            else
            {
                do
                {
                    driverLicensePlate = IsAlphaNum();

                    for (int j = 0; j < i; j++)
                    {
                        if (driverLicensePlate == availableRides[j]->licensePlate)
                        {
                            std::cout << "License plate already exists in database.\n" << endl;

                            isLicensePlate = false;
                            break;
                        }
                        else {
                            isLicensePlate = true;
                        }
                    }
                } while (isLicensePlate == false);
            }
            std::cout << "\n\nWhere is " << driverName << " destination ?  ";
            driverDestination = IsAlphaNum();
            if (rideType == "shared") {
                std::cout << "How many seats are available ?";
                seatsAvailable = IsCarSeat();
                availableRides[i] = new SharedRide(rideType, driverCar, driverName, driverLicensePlate, driverDestination, seatsAvailable);
            }
            else {
                seatsAvailable = 1;
                availableRides[i] = new SingleRide(rideType, driverCar, driverName, driverLicensePlate, driverDestination, seatsAvailable);
            }
            

        }
        std::system("pause");
                Clear();
        

//========================================================== MANAGING PHASE =================================================================================================
        string strChoices, passengerName, passengerDestination;
        int ridesCount = availableRides[0]->counter , intChoices;
        bool noRideAvailable = true;

        std::cout << "\t\t\t\t\tInitializing Drively Managing Procedure";
        for (int i = 0; i < 10; i++)
        {
            std::cout << ".";
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        std::cout << endl;
        while (true)
        {
            std::cout << "What can I do for you ?\n" << endl;
            std::cout << "1.Reserve a seat \t 2.Cancel a seat \t 3.Exit\n\n ";
            strChoices = IsAlphaNum();

            if (strChoices == "1" || strChoices.find("reserve") != string::npos)
            {
                std::cout << "\nPlease enter your first and last name \n\n ";
                passengerName = IsAlpha();
                if (passengerName == "exit")
                {
                    continue;
                }
                std::cout << "\nPlease enter your destination \n\n ";
                passengerDestination = IsAlphaNum();
                std::cout << "Here's a list of available rides. Please choose one of them\n" << endl;
                for (int i = 0; i < ridesCount; i++)
                {
                    if (availableRides[i]->seatsAvailable > 0 && availableRides[i]->destination == passengerDestination) {
                        std::cout << "Ride # : " << i+1 << endl <<endl;
                        availableRides[i]->getCarInfo();
                        noRideAvailable = false;
                        std::cout << "==================================================================================================================" << endl;
                    }
                }
                if (noRideAvailable == true)
                {
                    std::cout << "There's no ride available to your destination at this moment. Please try again later.\n" << endl;
                    std::system("pause");
                    Clear();
                }
                else
                {
                    intChoices = IsNum();
                    availableRides[intChoices - 1]->reserveSeat(passengerName);
                    std::cout << "Your ride has been successfully reserved. Your driver is on their way to your location.\n" << endl;
                    std::cout << "Here is your ride details : \n" << endl;
                    availableRides[intChoices - 1]->calculateCost();
                    availableRides[intChoices - 1]->getRideInfo();
                    std::cout << "Do you wish to see a break down of your ride cost ?(yes/no)\n\n ";
                    strChoices = IsAlpha();
                    if (strChoices == "yes")
                    {
                        availableRides[intChoices - 1]->getCostInfo();
                    }
                    noRideAvailable = true;
                    std::system("pause");
                    Clear();
                }
            }

            else if (strChoices == "2" || strChoices.find("cancel") != string::npos)
            {
                std::cout << "which ride is the passenger in ?" << endl;
                for (int i = 0; i < ridesCount; i++)
                {
                    if (availableRides[i]->passengersInCar > 0)
                    {
                        std::cout << "Ride # : " << i + 1 << endl << endl;
                        availableRides[i]->getCarInfo();
                        noRideAvailable = false;
                        std::cout << "==================================================================================================================" << endl;
                    }
                    
                }
                if (noRideAvailable == true) {
                    std::cout << "All rides are empty. No passengers available to cancel.\n" << endl;
                    std::system("pause");
                    Clear();
                }
                else
                {
                    intChoices = IsNum();
                    std::cout << "Which passenger do you want to cancel seats for ?\n" << endl;
                    availableRides[intChoices - 1]->getPassengersList();
                    std::cout << ">\t";
                    passengerName = IsAlpha();
                    if (passengerName == "exit")
                    {
                        continue;
                    }
                    availableRides[intChoices - 1]->cancelSeat(passengerName);
                    noRideAvailable = true;
                    std::system("pause");
                    Clear();
                }
            }
            else if (strChoices == "3" || strChoices.find("exit") != string::npos)
            {
                for (int i = 0; i < availableDrivers; i++)
                {
                    delete availableRides[i];
                }
                delete[] availableRides;
                return 0;
            }
            else {
                std::cout << "\nNot a valid option. Please try again.\n" << endl;
            }
        }
};