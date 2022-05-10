/*
    Team name

    Losenara, Kristian
    Kelley, Bobby
    Lu, Vince
    Chen, Amanda

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
    
#ifndef HIKE_H
#define HIKE_H
#include <iostream>
#include <string>




class Hike {
    friend std::ostream& operator<<(std::ostream& out, const Hike& hike);
public:
    Hike() : hikeDifficulty('e'), hikeDuration(0) {}
        Hike(const std::string& newHikeLocation, const std::string& newHikeName,
            int newDurationHike, char newHikeDifficulty);
    std::string getLocation () const;
    int getDuration() const;
    char getDifficulty() const;
    std::string getHikeName() const;
    bool operator<(const Hike&) const;

private:
    char hikeDifficulty;
    std::string hikeLocation;
    std::string hikeName;
    int hikeDuration;
};



#endif