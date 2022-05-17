/*
    Cool Kids

    Losenara, Kristian
    Kelley, Bobby
    Lu, Vince
    Chen, Amanda

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "Interface.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void displayMenu()
{
    cout << "***************************************************\n"
         << "                HIKING IN THE US\n"
         << "***************************************************\n" << endl 
         << "        1. Browse by location\n"
         << "        2. Browse by duration\n"
         << "        3. Browse by difficulty\n"
         << "        4. Browse by price\n"
         << "        5. Make a reservation\n"
         << "        6. View reservation\n"
         << "        7. Cancel reservation\n"
         << "        8. Exit\n" << endl;
}

void processReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
    cout << "Please make a selection: ";
    int input;
    cin >> input;
    cout << endl;
    while (input != 8) {
        if (input == 1) {
            chooseByLocation(hikeList, memberList, reservations);
        }
        else if (input == 2) {
            chooseByDuration(hikeList, memberList, reservations);
        }
        else if (input == 3) {
            chooseByDifficulty(hikeList, memberList, reservations);
        }
        else if (input == 4) {
            chooseByPrice(hikeList, memberList, reservations);
        }
        else if (input == 5) {
            makeReservation(hikeList, memberList, reservations);
        }
        else if (input == 6) {
            viewReservation(hikeList, memberList, reservations);
        }
        else if (input == 7) {
            cancelReservation(hikeList, memberList, reservations);
        }
        system("Pause");
        cout << endl << endl;
        displayMenu();
        cout << "Please make a selection: ";
        cin >> input;
        cout << endl << endl;
    }
    cout << "Thank you for visiting!" << endl;
}

void chooseByLocation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    myHikeList.printAllLocations();
    cout << "\nChoose a location: ";
    string input;
    cin >> input;
    cout << endl;
    myHikeList.printByLocation(input);
    askToReserve(myHikeList, myMemberList, myReservations);
}

void chooseByDuration(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    cout << "       (days)" << endl;
    myHikeList.printByDuration();
    cout << "\n" << "How many days are you considering? ";
    int input;
    cin >> input;
    cout << endl;
    myHikeList.printByDuration(input);
    askToReserve(myHikeList, myMemberList, myReservations);
 }

void chooseByDifficulty(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    cout << "Choose difficulty level:\n"
         << "\n        e. easy\n"
         << "        m. moderate\n"
         << "        s. strenous\n"
         << "\nYour choice: ";
    char input;
    cin >> input;
    cout << endl << endl;
    myHikeList.printByDifficulty(input);
    askToReserve(myHikeList, myMemberList, myReservations);
}

void chooseByPrice(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    myHikeList.printByPrice();
    askToReserve(myHikeList, myMemberList, myReservations);
}

void makeReservation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    int id = askIfMember(myMemberList);
    cout << "Which hike would you like to reserve (hike name)? ";
    string hikeInput;
    cin >> hikeInput;
    cout << endl;
    myHikeList.printByHikeName(hikeInput);
    cout << "\n         Discounted price using points: $" << myHikeList.getPrice(hikeInput)
        - (myMemberList.getPoints(id) / 100) << endl << endl;
    
    cout << "         Before proceeding, please make note of your reservation number." << endl;
    cout << "           Reservation #: " << myReservations.addReservation(id, hikeInput) << endl << endl;
    cout << "( *** Will continue to scheduling and payment. *** )" << endl << endl;

}

void viewReservation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations)
{
    cout << "Enter reservation #: ";
    int reservationInput(0);
    cin >> reservationInput;
    cout << endl << endl;
    myReservations.printReservation(reservationInput, myHikeList, myMemberList);
}

void cancelReservation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations)
{
    cout << "Enter reservation #: ";
    int reservationInput(0);
    cin >> reservationInput;
    cout << endl << endl;
    myReservations.printReservation(reservationInput, myHikeList, myMemberList);

    cout << "\nAre you sure you want to cancel this reservation? (y/n) " ;
    char reservationInputChar;
    cin >> reservationInputChar;
    if (reservationInputChar == 'y') 
    {
        myReservations.cancelReservation(reservationInput);
        cout << "\n\nReservation #" << reservationInput << " has been canceled.";
    }
}

int askIfMember(MemberList& myMemberList) {
    cout << "\nAre you a member? (y/n) ";
    char memberInput;
    cin >> memberInput;
    cout << endl;

    if (memberInput == 'y') {
        cout << "What is your member ID number? ";
        int idInput;
        cin >> idInput;
        cout << endl;

        cout << "What is your last name? ";
        string lastNameInput;
        cin >> lastNameInput;
        cout << endl;

        myMemberList.printMember(idInput, lastNameInput); 
        return idInput;
    }
    else {
        addNewMember(myMemberList);
        return myMemberList.getLastID();
    }
    return 0;
}
int addNewMember(MemberList& myMemberList) 
{
    string fName, lName;
    cout << "\n        Let's add you to the member list!\n"
        << "                What is your first name? ";
    cin >> fName;
    cout << "\n                What is your last name? ";
    cin >> lName;
    cout << endl << endl;

    myMemberList.addMember(fName, lName);

    cout << "        Welcome to the club!\n"
        << "                Your member ID number is: " << myMemberList.getLastID() << endl;

    return myMemberList.getLastID();
}
void askToReserve(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {  
    cout << "\nWould you like to make a reservation? (y/n) ";
    char reservationInput;
    cin >> reservationInput;
    if (reservationInput == 'y') {
        makeReservation(myHikeList, myMemberList, myReservations);
    }
    else {
        cout << "\n";
    }
}
