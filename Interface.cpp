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
#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

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
}
//void chooseByLocation(HikeList&, MemberList&, Reservations&)
//void chooseByDuration(HikeList&, MemberList&, Reservations&)
//void chooseByDifficulty(HikeList&, MemberList&, Reservations&)
//void chooseByPrice(HikeList&, MemberList&, Reservations&)
//int askIfMember(MemberList&)
//int addNewMember(MemberList&)
//void makeReservation(HikeList&, MemberList&, Reservations&)
//void viewReservation(HikeList&, MemberList&, Reservations&)
//void cancelReservation(HikeList&, MemberList&, Reservations&)
//void askToReserve(HikeList&, MemberList&, Reservations&)