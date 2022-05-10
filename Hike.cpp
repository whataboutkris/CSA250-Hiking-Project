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
    out << "    Difficulty: " << hike.hikeDifficulty << endl;
    out << "    Duration: " << hike.hikeDuration << " day(s)" << endl;
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

bool Hike::operator<(const Hike& paramObj) const
{
    return hikeLocation < paramObj.hikeLocation;
}
