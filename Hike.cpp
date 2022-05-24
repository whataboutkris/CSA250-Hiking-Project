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

#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& myHike) {
    out << "        " << myHike.hikeName << " (" << myHike.hikeLocation << ")" << endl;

    if (myHike.hikeDifficulty == 'e')
    {
        out << "          Difficulty: easy" << endl;

    }
    else if (myHike.hikeDifficulty == 'm')
    {
        out << "          Difficulty: moderate" << endl;
    }
    else
    {
        out << "          Difficulty: strenous" << endl;
    }

    out << "          Duration: " << myHike.hikeDuration << " day(s)" << endl;

    return out;
}

Hike::Hike(const string& newHikeLocation, const string& newHikeName,
    int newDurationHike, char newHikeDifficulty) 
{
    hikeLocation = newHikeLocation;
    hikeName = newHikeName;
    hikeDuration = newDurationHike;
    hikeDifficulty = newHikeDifficulty;
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

bool Hike::operator<(const Hike& myHike) const
{
    return hikeLocation < myHike.hikeLocation;
}

Hike::~Hike() {}