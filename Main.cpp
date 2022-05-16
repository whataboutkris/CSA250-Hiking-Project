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
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationReader.h"


using namespace std;

int main()
{
	
	HikeList myHikeList;
	getHikeData(myHikeList);
	MemberList myMemberList;
	getMemberData(myMemberList);
	Reservations myReservations;
	getReservationData(myReservations);

	displayMenu();
	processReservation(myHikeList, myMemberList, myReservations);

	return 0;
}