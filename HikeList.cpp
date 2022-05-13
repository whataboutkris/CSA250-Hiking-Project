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

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "HikeList.h"
using namespace std;


void HikeList::addHike(const Hike& hike, double hikePrice)
{
    aMap.insert(make_pair(hike, hikePrice));
}

void HikeList::addHike(const string& hikeLocation, const string& hikeName,
    int hikeDuration, char hikeDifficulty, double hikePrice)
{
    Hike insertHike(hikeLocation, hikeName, hikeDuration, hikeDifficulty);
    aMap.insert(make_pair(insertHike, hikePrice));
}

double HikeList::getPrice(const string& hikeName) const
{
    auto priceGet = find_if(aMap.begin(), aMap.end(), [&hikeName]
        (const auto h) {return h.first.getHikeName() == hikeName;});
    return priceGet->second; 
}

void HikeList::printAllLocations() const
{
    auto it = aMap.begin();
    auto itEnd = aMap.end();
    while (it != itEnd)
    {
        cout << it->first.getLocation() << endl;
        it = aMap.upper_bound(it->first);
    }
}

void HikeList::printByLocation(const string& hikeLocation) const {
    auto iterEnd = aMap.end();
    auto byLocation = find_if(aMap.begin(), iterEnd, [&hikeLocation] 
        (const auto& h) {return h.first.getLocation() == hikeLocation;});
    while (byLocation != iterEnd)
    {
        cout << byLocation->first;
        cout << "    Price: (per person): $ " << byLocation->second << endl << endl;
        byLocation = find_if(++byLocation, iterEnd, [&hikeLocation]
            (const auto& h) {return h.first.getLocation() == hikeLocation; });
    }
   
}

void HikeList::printByDuration() const
{
    multimap<int, string> myMultiMap; 
    auto iter = aMap.begin();
    auto iterEnd = aMap.end();
    for (iter; iter != iterEnd; ++iter)
        myMultiMap.insert(pair<int, string>(iter->first.getDuration(), iter->first.getLocation()));  
    for_each(myMultiMap.begin(), myMultiMap.end(), [](auto& h) {cout << "(" << h.first << ") " << h.second << endl;});
}

void HikeList::printByDuration(int days) const{
    for (auto& i : aMap)
        if (i.first.getDuration() == days) {
            cout << i.first.getHikeName() << " (" << i.first.getLocation() << ")" << endl
                << "Difficulty: " << i.first.getDifficulty() << endl
                << "Duration: " << i.first.getDuration() << endl;
        }
}
void HikeList::printByDifficulty(char hikeDifficulty) const
{
    Hike hike;
    for (auto& i : aMap)
        cout << "(" << hikeDifficulty << ") " << hike.getHikeName() << ", " <<
        hike.getLocation() << endl;
}

void HikeList::printByPrice() const
{
    multimap<double, pair<string, string>> mymultimap;
    auto iter = aMap.begin();
    auto iterEnd = aMap.end();
    for (iter; iter != iterEnd; iter++)
        mymultimap.emplace(iter->second, make_pair(iter->first.getLocation(), iter->first.getHikeName()));

    cout << fixed << showpoint << setprecision(2);

    for (auto& i : mymultimap)
        cout << "$ " << i.first << " - " << i.second.first << " (" <<   
            i.second.second << ")\n";
}

void HikeList::printByHikeName(const string& hikeName) const
{
    auto it = find_if (aMap.begin(), aMap.end(),
        [&hikeName](const pair<const Hike&, double>& h) {return h.first.getHikeName() == hikeName;});       

    cout << fixed << showpoint << setprecision(2);
    cout << it->first.getHikeName() << " (" << it->first.getLocation() << ")\n" <<
        "    Difficulty: " << it->first.getDifficulty() << "\n    Duration: "
        << it->first.getDuration() << " day(s)\n" << "    $" << it->second;
}

void HikeList::clearList()
{
    aMap.clear();
}