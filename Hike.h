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
#ifndef HIKE_H
#define HIKE_H
#include <iostream>
#include <string>
#include "Hike.cpp"
#include <iostream>
using namespace std;


class Hike {
public:
    Hike();
        Hike(string newHikeLocation, string newHikeName, 
            int newDurationHike, char newHikeDifficulty);
	char hikeDifficulty;
    string getLocation();
    int getDuration();
    char getDifficulty();
    string getHikeName();

private:
    friend ostream& operator << (ostream& out, Hike& h);
    string hikeLocation;
    string hikeName;
    int durationHike;

};



#endif