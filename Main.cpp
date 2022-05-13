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

#include<iostream>
#include<string>
#include "Interface.h"

using namespace std;

int main()
{
	Hike myHike("Montana", "Glacier", 5, 'e');
	Hike myHike1("Montana", "uuuuuu", 5, 'm');
	Hike myHike2("Montana", "auuugh", 5, 's');

	HikeList myHikeList;
	myHikeList.addHike(myHike, 999);
	myHikeList.addHike(myHike1, 111);
	myHikeList.addHike(myHike2, 222);
	myHikeList.addHike("Utah", "Somewhere", 5, 'e', 8453); 
	myHikeList.addHike("California", "Zion", 5, 'm', 2904);
	MemberList myMemberList;
	myMemberList.addMember("Mike", "Hawk");

	Reservations myReservations;
	myReservations.addReservation(111, "FakeHike");
	
	//h.addHike(myHike, 98987);
	//cout << h.getPrice("Glacier"); 
	//h.printAllLocations();
	//h.printByLocation("Montana");
	//h.printByDuration(5);
	displayMenu();
	processReservation(myHikeList, myMemberList, myReservations);

	return 0;
}