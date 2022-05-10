#pragma once
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

#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservations(ifstream& infile, Reservations& reservations);
{
	int memberID;
	string hikeName;

	while (!infile.eof())
	{
		infile >> memberID >> hikeName;
		reservations.addReservation(memberID, hikeName);
	}
}

void getReservationData(Reservations& reservations)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1);
	}

	createReservations(infile, reservations);

	infile.close();
}