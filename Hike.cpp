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
#include "Hike.h"
using namespace std;

    Hike::Hike(const string& newHikeLocation, const string& newHikeName,
    int newDurationHike, char newHikeDifficulty) {
    hikeLocation = newHikeLocation;
    hikeName = newHikeName;
    hikeDuration = newDurationHike;
    hikeDifficulty = newHikeDifficulty;
}

    ostream& operator<<(ostream& out, const Hike& hike) {
    out << hike.hikeName << " (" << hike.hikeLocation << ")" << endl;
    out << "Difficulty: " << hike.hikeDifficulty << endl;
    out << "Duration: " << hike.hikeDuration << " day(s)" << endl;
    return out;
}

string Hike::getLocation() const {
    return hikeLocation;
}



int Hike::getDuration() const {
    return hikeDuration;
}



char Hike::getDifficulty() const {
    return hikeDifficulty;
}


string Hike::getHikeName() const {
    return hikeName;
}
