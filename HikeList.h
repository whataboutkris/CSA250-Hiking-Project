/*
    Team name

    Lastname, Firstname // member 1
    Lastname, Firstname // member 2 and so on, if any

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef HIKE_LIST_H
#define HIKE_LIST_H

#include <map>
#include "Hike.h"

class HikeList
{
public:
    void addHike1(const Hike&, double hikePrice);
    void addHike2(std::string hikeLocation, std::string hikeName,
        int hikeDuration, char hikeDifficulty, double hikePrice);
    double getPrice(std::string hikeName);
    void printAllLocations();
    void printByLocation(std::string hikeLocation);
    void printByDuration();
    void printByDifficulty();
    void printByPrice();
    void printByHikeName(std::string hikeName);

private:
    std::multimap<const Hike&, double> aMap;
};

#endif