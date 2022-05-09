#include "Member.h"

#include <iostream>
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

void Member::printMember() const
{
	cout << lName << ", " << fName << "\n"
		<< "Points available: " << points << "\n"
		<< "Membership # " << id << endl;
}

bool Member::operator<(const Member& paramObj) const
{
	return id < paramObj.id;
}
