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
    for (auto it = aMap.cbegin(); it != aMap.cend(); ++it)  
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
    multimap<double, pair<int, string>> myMultiMap; //(duration, name)
        myMultiMap.insert(aMap.begin(), aMap.end());   // is this correct? + sort by duration?
    //for_each(myMultiMap.begin(), myMultiMap.end(), [myMultiMap](Hike &h) {return h.getLocation() == myMultiMap; }); WIP - Is the lambda for accessing myMultiMap correct in this case?
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
        cout << "$ " << getPrice << " - " << hike.getLocation() << " (" <<   //not sure what to put in the spot of getPrice
            hike.getHikeName() << ")\n";
}

void HikeList::printByHikeName(string hikeName)
{
    multimap<const Hike&, double>::iterator it = find_if (aMap.begin(), aMap.end(),
        [&hikeName](Hike& h) {return h.getHikeName() == hikeName;});        //WIP - I think I got it? -K

    cout << fixed << showpoint << setprecision(2);
    cout << it->first.getHikeName() << " (" << it->first.getLocation() << ")\n" <<
        "    Difficulty: " << it->first.getDifficulty() << "\n    Duration: "
        << it->first.getDuration() << " day(s)\n" << "    $" << it->second;
}

void HikeList::clearList()
{
    aMap.clear();
}