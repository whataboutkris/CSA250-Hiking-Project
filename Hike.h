/*
    Team name
    // blank line
    Lastname, Firstname // member 1
    Lastname, Firstname // member 2 and so on, if any
    // blank line
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
// blank line

#include <iostream>
#include <string>
#include "Hike.cpp"
#include <iostream>
using namespace std;


class Hike {
public:
    Hike()

	char hikeDifficulty;
private:
    string hikeLocation;
    string hikeName;
    int durationHike;

};

friend ostream &operator << (ostream &out, Hike &h);