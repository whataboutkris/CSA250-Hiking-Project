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

#include <iostream>
#include <map>
#include "HikeList.h"
#include "Hike.h"
using namespace std;

void HikeList::addHike1(const Hike& what    , double hikePrice)
{
    for (auto const& idk : aMap)
        aMap.insert(pair<const Hike&, double>(what , hikePrice));
}

void HikeList::addHike2(string  hikeLocation, string hikeName,
    int hikeDuration, char hikeDifficulty, double hikePrice)
{
    Hike insertHike;
    aMap.insert(pair<const Hike&, double>(insertHike, hikePrice));
}

double HikeList::getPrice(string hikeName)
{
    auto priceGet = find_if(aMap.begin(), aMap.end(), [&hikeName](Hike& h) {return h.getHikeName() == hikeName;});
    return priceGet->second;
}

void HikeList::printAllLocations()
{
    //for (auto it = aMap.cbegin(); it != aMap.cend(); ++it)  //WIP - need to test+ incorporate upperbound
    //{
    //    cout << it->first<< endl;
    //}
}

void HikeList::printByLocation(string hikeLocation) {
    //find_if(aMap.begin(), aMap.end(), [&hikeLocation] () {
    //    cout << ???;});

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