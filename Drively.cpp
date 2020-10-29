/*
    Developed by Arian Ahmadinejad
    Drively : Grade 12 Computer Science Project
    2020-10-17
*/

#include <iostream>
#include <exception>
#include <algorithm>
#include <thread>// Used with the chrono library to print a message after specified time
#include <chrono>
// Header files for project classes and functions
#include "BaseRide.h"
#include "SingleRide.h"
#include "Functions.h"
#include "SharedRide.h"

using namespace std;

int main()
{
        //========================================================== SETUP PHASE ====================================================================================================
        // Declaring variables of type int , string used to instantiate the objects
        int availableDrivers = 0, seatsAvailable=0;
        string rideType, driverCar, driverName, driverLicensePlate, driverDestination;
        // Used later as while loop argument to check if license plate already exists in the database
        bool isLicensePlate = false;

        // This section is for aesthetics only and doesn't serve any functionality . Creates a loading screen and prints the app's logo 
        std::cout << "\t\t\t\t\tInitializing Drively Setup Procedure";
        for (int i = 0; i < 10; i++)
        {
            std::cout << ".";
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        std::cout << endl << endl;
        PrintLogo();

        // Ask user for input and make class pointer array with input as length of the array
        std::cout << "\nHow many drivers are available right now ?";
        availableDrivers = IsNum(); // Uses IsNum function to check the input to be only a number and throw exception in case of wrong input
        BaseRide** availableRides = new BaseRide * [availableDrivers];
        // Loop through the class array to gather user input and instantiate objects
        for (int i = 0; i < availableDrivers; i++)
        {
            std::cout << "Please enter the details for driver #" << i+1 << endl << endl;
            std::cout << "Does this driver accept single rides or shared rides? (single/shared)";
            rideType = IsValidRideType(); //Function to check user input to be "single" or "shared" and throw exception in case of any other input
            std::cout << "\n\nWhat car does this driver own?  ";
            getline(cin, driverCar);
            std::cout << "\n\nWhat's the name of the driver?  ";
            driverName = IsAlpha(); //Function to check user input to be only letters and throw exception in case of wrong input
            std::cout << "\n\nPlease enter the license plate number for " << driverCar << "?  ";
            // For license plate we both check the input to not contain special characters and also not already been used in another object. Throws exception in case of wrong input.
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
            driverDestination = IsAlphaNum(); // Check user input to not contain special characters. Throws exception in case of wrong input. 
            // if logic used to check whether the ride type is single or shared and instantiate the appropriate object based on that
            if (rideType == "shared") {
                std::cout << "How many seats are available ?";
                seatsAvailable = IsCarSeat(); // Function to check user input .Car seats can't be more than 6 or negative values. throws exception in case of wrong input.
                availableRides[i] = new SharedRide(rideType, driverCar, driverName, driverLicensePlate, driverDestination, seatsAvailable);
            }
            else {
                seatsAvailable = 1; // Set variable to 1 because in single ride there can be only one passenger
                availableRides[i] = new SingleRide(rideType, driverCar, driverName, driverLicensePlate, driverDestination, seatsAvailable);
            }
            

        }
        // Clears the console when user presses any key
        std::system("pause");
                Clear();
        

//========================================================== MANAGING PHASE =================================================================================================
        //strchoices and intchoices are variables Declared to hold the current user input
        //other variables are used for storing user info and checking user info against database
        string strChoices, passengerName, passengerDestination;
        int ridesCount = availableRides[0]->counter , intChoices;
        bool noRideAvailable = true ;

        std::cout << "\t\t\t\t\tInitializing Drively Managing Procedure";
        for (int i = 0; i < 10; i++)
        {
            std::cout << ".";
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        std::cout << endl;
        // used in a while loop to keep program running until user quits
        while (true)
        {
            std::cout << "What can I do for you ?\n" << endl;
            // Giving user three options : reserve a seat , cancel a seat or exit the program
            std::cout << "1.Reserve a seat \t 2.Cancel a seat \t 3.Exit\n\n ";
            strChoices = IsAlphaNum();
            
            //if logic is used to check which option user chose and calling proper functions based on that (works with both numeric input and string input)
            if (strChoices == "1" || strChoices.find("reserve") != string::npos) // checks if keyword is in input and accepts any string that contains the keyword
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
                //lists the rides that have more than 0 seats available and their destination matches with the user ( this method prevents user from wrong input without the use of exceptions because program won't ask for input if no valid ride is present)
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
                    // checks the user input to be in the range of provided list of rides if not throws exception until correct input is provided
                    while (true)
                    {
                        try
                        {
                            intChoices = IsNum();
                            if (intChoices > ridesCount || intChoices <= 0) {
                                throw OutOfRangeRide("Ride out of range");
                            }
                            else
                            {
                                break;
                            }
                        }
                        catch (OutOfRangeRide& exp)
                        {
                            cout << "Your input is not one of the shown options. Please check your input." << endl;
                            cout << "Error ! " << exp.what() << endl << endl;
                        }
                    }
                    
                    
                    //calling the reserveSeat method from the object methods to reserve a seat for the user
                    availableRides[intChoices - 1]->reserveSeat(passengerName);
                    std::cout << "Your ride has been successfully reserved. Your driver is on their way to your location.\n" << endl;
                    std::cout << "Here is your ride details : \n" << endl;
                    availableRides[intChoices - 1]->calculateCost();//Method that sets the correct values for cost structure of the object
                    availableRides[intChoices - 1]->getRideInfo();// Method that shows the ride details in a user friendly manner
                    //Ask user whether they want a break down of their ride cost because this is a optional feature of the program
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
                // Shows a list of rides that have passengers in the car
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
                // If all of the cars are empty this message is shown and prevents the user from inputting anything
                if (noRideAvailable == true) {
                    std::cout << "All rides are empty. No passengers available to cancel.\n" << endl;
                    std::system("pause");
                    Clear();
                }
                else
                {
                    while (true)
                    {
                        try
                        {
                            intChoices = IsNum();
                            if (intChoices > ridesCount || intChoices <= 0) {
                                throw OutOfRangeRide("Ride out of range");
                            }
                            else
                            {
                                break;
                            }
                        }
                        catch (OutOfRangeRide& exp)
                        {
                            cout << "Your input is not one of the shown options. Please check your input." << endl;
                            cout << "Error ! " << exp.what() << endl << endl;
                        }
                    }
                    std::cout << "Which passenger do you want to cancel seats for ?\n" << endl;
                    availableRides[intChoices - 1]->getPassengersList();
                    passengerName = IsAlpha();
                    // you can exit canceling a seat if you enter exit at this prompt
                    if (passengerName == "exit")
                    {
                        continue;
                    }
                    
                    // call cancelSeat method to cancel the entry belonging to the passenger provided

                    availableRides[intChoices - 1]->cancelSeat(passengerName);
                    noRideAvailable = true; // set bool value to previous state for next call of cancelSeat function

                    std::system("pause");
                    Clear();
                }
            }
            else if (strChoices == "3" || strChoices.find("exit") != string::npos)
            {
                // deleting pointers to class arrays and then deleting the pointer to those pointers in order to prevent memory leakage
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