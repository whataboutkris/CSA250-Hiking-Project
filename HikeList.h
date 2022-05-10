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

#ifndef HIKE_LIST_H
#define HIKE_LIST_H

#include <map>
#include "Hike.h"

class HikeList
{
public:
    void addHike(const Hike&, double hikePrice);
    void addHike(const std::string& hikeLocation, const std::string& hikeName,
     int hikeDuration, char hikeDifficulty, double hikePrice);
    double getPrice(std::string hikeName);
    void printAllLocations();
    void printByLocation(std::string hikeLocation);
    void printByDuration();
    void printByDuration(int days);
    void printByDifficulty(char hikeDifficulty);
    void printByPrice();
    void printByHikeName(std::string hikeName);
    void clearList();

private:
    std::multimap<const Hike&, double> aMap;
};

#endif