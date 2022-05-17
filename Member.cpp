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

#include "Member.h"

#include <iostream>
#include <iomanip>

using namespace std;

Member::Member(const string& newFName, const string& newLName)
{
	id = 0;
	fName = newFName;
	lName = newLName;
	points = 0;
}

void Member::addPoints(int newPoints)
{
	points += newPoints;
}

void Member::setID(const int& newID)
{
	id = newID;
}

int Member::getID() const
{
	return id;
}

string Member::getLName() const
{
	return lName;
}

int Member::getPoints() const
{
	return points;
}

bool Member::operator<(const Member& paramObj) const
{
	return id < paramObj.id;
}

void Member::printMember() const
{
	
	cout << "        " << lName << ", " << fName << "\n"
		<< "        Points available: " << points << "\n"
		<< "        Membership # " << id << endl << endl;
}
