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
        cout << "\n";
        displayMenu();
        cout << "Please make a selection:";
        cin >> input;
    }
    cout << "\nThank you for visiting!\n";
}

void chooseByLocation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    myHikeList.printAllLocations();
    cout << "\nChoose a location: ";
    string input;
    cin >> input;
    cout << "\n";
    myHikeList.printByLocation(input);
    askToReserve(myHikeList, myMemberList, myReservations);
}

void chooseByDuration(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    myHikeList.printByDuration();
    cout << "\nHow many days are you considering? ";
    int input;
    cin >> input;
    cout << "\n";
    myHikeList.printByDuration(input);
    askToReserve(myHikeList, myMemberList, myReservations);
 }

void chooseByDifficulty(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    cout << "\nChoose difficulty level:\n"
         << "        e. easy\n"
         << "        m. moderate\n"
         << "        s. strenous\n"
         << "Your choice: ";
    char input;
    cin >> input;
    cout << "\n";
    myHikeList.printByDifficulty(input);
    askToReserve(myHikeList, myMemberList, myReservations);
}

void chooseByPrice(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    myHikeList.printByPrice();
    askToReserve(myHikeList, myMemberList, myReservations);
}

void makeReservation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations) {
    int id = askIfMember(myMemberList);
    cout << "Which hike would you like to reserve (hike name) ?";
    string hikeInput;
    cin >> hikeInput;

    myHikeList.printByHikeName(hikeInput);
    cout << "       Discounted price using points: $ " << myHikeList.getPrice(hikeInput)
        - (myMemberList.getPoints(id) / 100) << endl;
    
    myReservations.addReservation(id, hikeInput);
}

void viewReservation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations)
{
    cout << "Enter reservation #: ";
    int reservationInput(0);
    cin >> reservationInput;
    myReservations.printReservation(reservationInput, myHikeList, myMemberList);
}

void cancelReservation(HikeList& myHikeList, MemberList& myMemberList, Reservations& myReservations)
{
    cout << "Enter reservation #: ";
    int reservationInput(0);
    cin >> reservationInput;
    myReservations.printReservation(reservationInput, myHikeList, myMemberList);

    cout << "Are you sure you want to cancel this reservation? (y/n) " ;
    char reservationInput;
    cin >> reservationInput;
    if (reservationInput == 'y') 
    {
        myReservations.cancelReservation(reservationInput);
        cout << "Reservation #" <<  reservationInput << " has been canceled.";
    }
    else
    {
        processReservation(myHikeList, myMemberList, myReservations)
     }
}

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
        
        myMemberList.printMember(idInput, lastNameInput); 
    }
    else {
        addNewMember(myMemberList);
    }
}
int addNewMember(MemberList& myMemberList) 
{
    string fName, lName;
    cout << "       Let's add you to the member list!\n"
         << "               What is your first name? ";
    cin >> fName;
    cout << "\n               What is your last name? ";
    cin >> lName;

    myMemberList.addMember(fName, lName);
    cout << endl;

    cout << "\n       Welcome to the club!\n"
         << "               Your member ID number is: " << myMemberList.getLastID();

    return myMemberList.getLastID();
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
