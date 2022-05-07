/*
    Team name

    Lastname, Firstname // member 1
    Lastname, Firstname // member 2 and so on, if any

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include <iostream>
#include <map>
#include "HikeList.h"
using namespace std;

void HikeList::addHike1(const Hike& what, double hikePrice)
{
    for (auto const& idk : aMap)
        aMap.insert(pair<const Hike&, double>(what, hikePrice));
}

void HikeList::addHike2(string hikeLocation, string hikeName,
    int hikeDuration, char hikeDifficulty, double hikePrice)
{
    Hike what;
    aMap.insert(pair<const Hike&, double>(what, hikePrice));
}

double HikeList::getPrice(string hikeName)
{
    //find_if(aMap.begin(), aMap.end(), hikeName);
}

void HikeList::printAllLocations()
{

}

void HikeList::printByLocation(string hikeLocation)
{

}

void HikeList::printByDuration()
{

}

void HikeList::printByDifficulty()
{

}

void HikeList::printByPrice()
{

}

void HikeList::printByHikeName(string hikeName)
{

}