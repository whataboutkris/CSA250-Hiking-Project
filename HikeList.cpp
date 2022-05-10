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
#include <algorithm>
#include <iomanip>
#include "HikeList.h"
#include "Hike.h"
using namespace std;

void HikeList::addHike1(const Hike& hike, double hikePrice)
{
    for (auto const& i : aMap)
        aMap.insert(pair<const Hike&, double>(hike, hikePrice));
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
    for (auto it = aMap.cbegin(); it != aMap.cend(); ++it)  //how to incorporate upper_bound()?
    {
        cout << it->first.getLocation() << endl;
        it = aMap.upper_bound(it->first);
    }
}

void HikeList::printByLocation(string hikeLocation) {
    auto byLocation = find_if(aMap.begin(), aMap.end(), [&hikeLocation] (Hike&h) {return h.getLocation() == hikeLocation;});
    cout << byLocation->first.getHikeName(); //how to find duplicate locations?

}

void HikeList::printByDuration()
{
    multimap<double, pair<int, string>> multiMapDuration; //(duration, name)
    //aMap.insert();    
}

void HikeList::printByDifficulty(char hikeDifficulty)
{
    Hike hike;
    for (auto& i : aMap)
        cout << "(" << hikeDifficulty << ") " << hike.getHikeName() << ", " <<
        hike.getLocation() << endl;
}

void HikeList::printByPrice()
{
    Hike hike;
    multimap<double, pair<string, string>> mymultimap;

    mymultimap.emplace(aMap, make_pair(hike.getHikeName(), hike.getLocation()));

    cout << fixed << showpoint << setprecision(2);

    for (auto& i : mymultimap)
        cout << "$ " << getPrice << " - " << hike.getLocation() << " (" <<
            hike.getHikeName() << ")\n";
}

void HikeList::printByHikeName(string hikeName)
{
    multimap<const Hike&, double>::iterator it = find_if (aMap.begin(), aMap.end(), [] () {return ;});        //WIP - lambda exp, name, loc, diff, duration, price?

    cout << fixed << showpoint << setprecision(2);
    //cout << hike name << " (" << hike location << ")\n" << 
    //    "    Difficulty: " << hike difficulty << "\n    Duration: " 
    //    << hike duration << " day(s)\n" << "    $" << hike price;
}

void HikeList::clearList()
{

}