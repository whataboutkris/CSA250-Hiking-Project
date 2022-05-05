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




class Hike {
    friend std::ostream& operator<<(std::ostream& out, const Hike& hike);
public:
    Hike() : hikeDifficulty('e'), hikeDuration(0) {}
        Hike(std::string& const newHikeLocation, std::string& const newHikeName, 
            int newDurationHike, char newHikeDifficulty);
    std::string getLocation () const;
    int getDuration() const;
    char getDifficulty() const;
    std::string getHikeName() const;

private:
    char hikeDifficulty;
    std::string hikeLocation;
    std::string hikeName;
    int hikeDuration;
};



#endif