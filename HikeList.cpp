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

void HikeList::printByDifficulty(char hikeDifficulty)
{
    //for (auto& i : aMap)                                       //WIP - hike name and loc
    //    cout << "(" << hikeDifficulty << ") " << ? << ", " << 
    //        ? << endl;
}

void HikeList::printByPrice()
{
    //multimap<double, pair<string, string>> mymultimap;              //WIP - price, name, loc?

    //mymultimap.emplace(price, make_pair(hike name, hike location);

    //cout << fixed << showpoint << setprecision(2);

    //for (auto& i : mymultimap)
    //    cout << "$ " << price << " - " << hike location << " (" << 
    //        hike name << ")\n";
}

void HikeList::printByHikeName(string hikeName)
{
    //multimap<const Hike&, double>::iterator it = find_if (aMap.begin(), aMap.end(), [] () {return ;});        //WIP - lambda exp, name, loc, diff, duration, price?

    //cout << fixed << showpoint << setprecision(2);
    //cout << hike name << " (" << hike location << ")\n" << 
    //    "    Difficulty: " << hike difficulty << "\n    Duration: " 
    //    << hike duration << " day(s)\n" << "    $" << hike price;
}

void HikeList::clearList()
{

}