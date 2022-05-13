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

using namespace std;

void displayMenu()
{
    cout << "***************************************************\n"
         << "                HIKING IN THE US                   \n"
         << "***************************************************\n"
         << endl;

    cout << "         1. Browse by location\n"
         << "         2. Browse by duration\n"
         << "         3. Browse by difficulty\n"
         << "         4. Browse by price\n"
         << "         5. Make a reservation\n"
         << "         6. View reservation\n"
         << "         7. Cancel reservation\n"
         << "         8. Exit\n" << endl;
}

void processReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
    cout << "Please make a selection: ";
    int input;
    cin >> input;
    while (input != 8) {
        if (input == 1) {
            cout << "\n";
            chooseByLocation(hikeList, memberList, reservations);
        }
        else if (input == 2) {
            cout << "\n";

        }
        else if (input == 3) {

        }
        else if (input == 4) {

        }
        else if (input == 5) {

        }
        else if (input == 6) {

        }
        else if (input == 7) {

        }
        system("Pause");
        cout << "\n";
        displayMenu();
        cout << "Please make a selection:";
        cin >> input;
    }
        cout << "\n" << "Thank you for visiting!\n";
}

void chooseByLocation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    myHikeList.printAllLocations();
    cout << "" << endl;
    cout << "Choose a location: ";
    string input;
    cin >> input;
    cout << "\n";
    myHikeList.printByLocation(input);
    askToReserve(myHikeList, myMemberList, myReservations);

}

//void chooseByDuration(HikeList&, MemberList&, Reservations&)
//void chooseByDifficulty(HikeList&, MemberList&, Reservations&)
//void chooseByPrice(HikeList&, MemberList&, Reservations&)
void makeReservation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myRerservations) {
    askIfMember(myMemberList);
    cout << "Which hike would you like to reserve (hike name) ?";
    string hikeInput;
    cin >> hikeInput;

    
}
//void viewReservation(HikeList&, MemberList&, Reservations&)
//void cancelReservation(HikeList&, MemberList&, Reservations&)
int askIfMember(MemberList& myMemberList) {
    cout << "Are you a member? (y/n) ";
    char memberInput;
    cin >> memberInput;
    if (memberInput == 'y') {
        cout << "What is your member ID number? ";
        int idInput;
        cin >> idInput;
        cout << "What is your last name? ";
        string lastNameInput;
        cin >> lastNameInput;
        
        //MemberList::printMember(idInput, lastNameInput); // ?
    }
    else {
        addNewMember(myMemberList);
    }
}
int addNewMember(MemberList& myMemberList) {

}
void askToReserve(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {  
    cout << "Would you like to make a reservation? (y/n) ";
    char reservationInput;
    cin >> reservationInput;
    if (reservationInput == 'y') {
        makeReservation(myHikeList, myMemberList, myReservations);
    }
    else {
        cout << "\n";
    }
}