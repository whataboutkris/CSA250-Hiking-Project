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
    else if (input == 8) {
        cout << "Thank you for visiting!";
    }
}

void chooseByLocation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    myHikeList.printAllLocations();
    cout << "" << endl;
    cout << "Choose a location: ";
    string input;
    cin >> input;
    cout << "\n";
    myHikeList.printByLocation(input);
    //askToReserve();

}

//void chooseByDuration(HikeList&, MemberList&, Reservations&)
//void chooseByDifficulty(HikeList&, MemberList&, Reservations&)
//void chooseByPrice(HikeList&, MemberList&, Reservations&)
//void makeReservation(HikeList&, MemberList&, Reservations&)
//void viewReservation(HikeList&, MemberList&, Reservations&)
//void cancelReservation(HikeList&, MemberList&, Reservations&)
//int askIfMember(MemberList&)
//int addNewMember(MemberList&)
void askToReserve(HikeList&, MemberList&, Reservations&) {
    cout << "Would you like to make a reservation? (y/n)";
}