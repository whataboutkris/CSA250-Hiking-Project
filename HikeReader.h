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

#include "HikeList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const string HIKES_FILE = "hikes_database.txt";

void createHikeList(ifstream& infile, HikeList& hikeList)
{
	string location,
	       hikeName;
	int duration = 0;
	char difficulty = 'e';
	double price = 0.0;

	while (!infile.eof())
	{
		infile >> location >> hikeName >> duration >> difficulty >> price;
		hikeList.addHike(location, hikeName, duration, difficulty, price);
	}
}

void getHikeData(HikeList& hikeList)
{
	ifstream infile;

	infile.open(HIKES_FILE);

	if (!infile)
	{
		cerr << HIKES_FILE << " does not exist." << endl;
		exit(1);
	}

	createHikeList(infile, hikeList);

	infile.close();
}


