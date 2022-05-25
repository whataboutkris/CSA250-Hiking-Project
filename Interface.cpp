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

#include <iostream>

using namespace std;

void displayMenu()
{
	cout << "***************************************************\n"
		 << "                HIKING IN THE US\n"
		 << "***************************************************\n" 
		 << "\n        1. Browse by location\n"
		 << "        2. Browse by duration\n"
		 << "        3. Browse by difficulty\n"
		 << "        4. Browse by price\n"
		 << "        5. Make a reservation\n"
		 << "        6. View reservation\n"
		 << "        7. Cancel reservation\n"
		 << "        8. Exit\n" << endl;
}

void processReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservations)
{
	cout << "Please make a selection: ";
	int input = 0;
	cin >> input;
	cout << endl;
	while (input < 9)
	{
		if (input == 1)
		{
			chooseByLocation(hikeList, memberList, reservations);
		}
		else if (input == 2)
		{
			chooseByDuration(hikeList, memberList, reservations);
		}
		else if (input == 3)
		{
			chooseByDifficulty(hikeList, memberList, reservations);
		}
		else if (input == 4)
		{
			chooseByPrice(hikeList, memberList, reservations);
		}
		else if (input == 5)
		{
			makeReservation(hikeList, memberList, reservations);
		}
		else if (input == 6)
		{
			viewReservation(hikeList, memberList, reservations);
		}
		else if (input == 7)
		{
			cancelReservation(hikeList, memberList, reservations);
		}
		else if (input == 8) {
			cout << "Thank you for visiting!" << endl;
			break;
		}
		system("Pause");
		cout << endl << endl;
		displayMenu();
		cout << "Please make a selection: ";
		cin >> input;
		cout << endl;
	}
}

void chooseByLocation(HikeList& myHikeList, MemberList& myMemberList,
	Reservations& myReservations) 
{
	myHikeList.printAllLocations();
	cout << "\nChoose a location: ";
	string input;
	cin >> input;
	cout << endl;
	myHikeList.printByLocation(input);  
	askToReserve(myHikeList, myMemberList, myReservations);
}

void chooseByDuration(HikeList& myHikeList, MemberList& myMemberList,
	Reservations& myReservations) 
{
	cout << "\t(days)" << endl;
	myHikeList.printByDuration();
	cout << "\nHow many days are you considering? ";
	int input = 0;
	cin >> input;
	cout << endl;
	myHikeList.printByDuration(input);
	askToReserve(myHikeList, myMemberList, myReservations);
 }

void chooseByDifficulty(HikeList& myHikeList, MemberList& myMemberList,
	Reservations& myReservations) 
{
	cout << "Choose difficulty level:\n"
		 << "\n        e. easy\n"
		 << "        m. moderate\n"
		 << "        s. strenous\n"
		 << "\nYour choice: ";
	char input = ' ';
	cin >> input;
	cout << endl;
	myHikeList.printByDifficulty(input);
	askToReserve(myHikeList, myMemberList, myReservations);
}

void chooseByPrice(HikeList& myHikeList, MemberList& myMemberList,
	Reservations& myReservations) 
{
	myHikeList.printByPrice();
	askToReserve(myHikeList, myMemberList, myReservations);
}

int askIfMember(MemberList& myMemberList) 
{
	cout << "\nAre you a member? (y/n) ";
	char memberInput = ' ';
	cin >> memberInput;
	int idInput = 0;
	cout << endl;
	if (memberInput == 'y')
	{
		cout << "What is your member ID number? ";
		cin >> idInput;
		cout << endl;
		cout << "What is your last name? ";
		string lastNameInput = "";
		cin >> lastNameInput;
		cout << endl;
		myMemberList.printMember(idInput, lastNameInput);
	}
	else
	{
		idInput = addNewMember(myMemberList);
	}
	return idInput;
}

int addNewMember(MemberList& myMemberList)
{
	string fName, lName;
	cout << " \tLet's add you to the member list!\n"
		<< "\t\tWhat is your first name? ";
	cin >> fName;
	cout << "\t\tWhat is your last name? ";
	cin >> lName;
	cout << endl;

	myMemberList.addMember(fName, lName);

	cout << "\tWelcome to the club!\n"
		<< "\t\tYour member ID number is: " << myMemberList.getLastID()
		<< endl << endl;

	return myMemberList.getLastID();
}

void makeReservation(HikeList& myHikeList, MemberList& myMemberList,
	Reservations& myReservations) 
{
	int id = askIfMember(myMemberList);
	cout << "Which hike would you like to reserve (hike name)? ";
	string hikeInput;
	cin >> hikeInput;
	cout << endl;
	myHikeList.printByHikeName(hikeInput);
	
	if (myMemberList.getPoints(id) > 0)
	{
		cout << "\n\n\tDiscounted price using points: $" 
			<< myHikeList.getPrice(hikeInput)
			- (myMemberList.getPoints(id) / 100) << endl << endl;
	}
	else
	{
		cout << endl << endl;
	}

	cout << "\tBefore proceeding, please make note of "
		<< "your reservation number." << endl
	<< "\t Reservation #: " << myReservations.addReservation(id, hikeInput) 
		<< endl << endl
	<< "( *** Will continue to scheduling and payment. *** )" << endl <<endl;

}

void viewReservation(HikeList& myHikeList, MemberList& myMemberList,
	Reservations& myReservations)
{
	cout << "Enter reservation #: ";
	int reservationInput(0);
	cin >> reservationInput;
	cout << endl;
	myReservations.printReservation(reservationInput, myHikeList,
		myMemberList);
	cout << endl;
}

void cancelReservation(HikeList& myHikeList, MemberList& myMemberList,
	Reservations& myReservations)
{
	cout << "Enter reservation #: ";
	int reservationInput(0);
	cin >> reservationInput;
	cout << endl;
	myReservations.printReservation(reservationInput, myHikeList, myMemberList);

	cout << "\nAre you sure you want to cancel this reservation? (y/n) ";
	char reservationInputChar = ' ';
	cin >> reservationInputChar;
	cout << "\n";
	if (reservationInputChar == 'y') 
	{
		myReservations.cancelReservation(reservationInput);
		cout << "\nReservation #" << reservationInput << " has been "
			<< "cancelled.\n\n";
	}
}

void askToReserve(HikeList& myHikeList, MemberList& myMemberList,
	Reservations& myReservations) 
{
	cout << "Would you like to make a reservation? (y/n) ";
	char reservationInput = ' ';
	cin >> reservationInput;
	if (reservationInput == 'y')
	{
		makeReservation(myHikeList, myMemberList, myReservations);
	}
}
