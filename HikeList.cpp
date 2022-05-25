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

#include "HikeList.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

HikeList::HikeList() {}

void HikeList::addHike(const Hike& hike, double hikePrice)
{
	hikeMap.insert(make_pair(hike, hikePrice));
}

void HikeList::addHike(const string& hikeLocation, const string& hikeName,
	int hikeDuration, char hikeDifficulty, double hikePrice)
{
	Hike insertHike(hikeLocation, hikeName, hikeDuration, hikeDifficulty);
	hikeMap.insert(make_pair(insertHike, hikePrice));
}

double HikeList::getPrice(const string& hikeName) const
{
	auto priceIter = find_if(hikeMap.begin(), hikeMap.end(), [&hikeName]
		(const auto myHike) 
		{return myHike.first.getHikeName() == hikeName;});
	return priceIter->second; 
}

void HikeList::printAllLocations() const
{
	auto it = hikeMap.begin();
	auto itEnd = hikeMap.end();
	while (it != itEnd)
	{
		cout << "\t" << it->first.getLocation() << endl;
		it = hikeMap.upper_bound(it->first);
	}
}

void HikeList::printByLocation(const string& hikeLocation) const 
{
	auto iterEnd = hikeMap.end();
	auto iterByLocation = find_if(hikeMap.begin(), iterEnd,[&hikeLocation]
		(const auto& myHike)
		{return myHike.first.getLocation() == hikeLocation;});
   
	cout << fixed << showpoint << setprecision(2);
	while (iterByLocation != iterEnd && 
		hikeLocation == iterByLocation->first.getLocation())
	{
		cout << iterByLocation->first;
		cout << "\t  Price: (per person): $ " << iterByLocation->second
			<< endl << endl;
		++iterByLocation;
	}
}

void HikeList::printByDuration() const
{
	multimap<int, string> myMultiMap; 
	auto iter = hikeMap.begin();
	auto iterEnd = hikeMap.end();
	for (iter; iter != iterEnd; ++iter)
	{
		myMultiMap.insert(make_pair(iter->first.getDuration(), 
			(iter->first.getHikeName() + ", " +
				iter->first.getLocation())));
	}

	for_each(myMultiMap.begin(), myMultiMap.end(), [](auto& h) 
		{cout << "\t(" << h.first << ") " << h.second << endl;});
}

void HikeList::printByDuration(int days) const
{
	for (const auto& hikeIter : hikeMap)
		if (hikeIter.first.getDuration() == days) {
			cout << hikeIter.first << endl;
		}
}

void HikeList::printByDifficulty(char hikeDifficulty) const
{
	cout << "\t(difficulty level)\n";
	for (const auto& hikeIter : hikeMap)
		if (hikeIter.first.getDifficulty() == hikeDifficulty)
		{
			cout << "\t(" << hikeDifficulty << ") " 
				<< hikeIter.first.getHikeName() << ", "
				<< hikeIter.first.getLocation() << endl;
		}
	cout << endl;
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> mymultimap;
	auto iter = hikeMap.begin();
	auto iterEnd = hikeMap.end();
	for (iter; iter != iterEnd; iter++)
		mymultimap.emplace(iter->second,
			make_pair(iter->first.getLocation(),
				iter->first.getHikeName()));

	cout << fixed << showpoint << setprecision(2);

	for (auto& hikeIter : mymultimap)
	{
		cout << "\t$ ";
		printf("%*.2f", 7, hikeIter.first);
		cout << " - " << hikeIter.second.first << " ("
			<< hikeIter.second.second << ")" << endl;
	}
	cout << endl;
}

void HikeList::printByHikeName(const string& hikeName) const
{
	auto it = find_if (hikeMap.begin(), hikeMap.end(),
		[&hikeName](const auto& h) 
		{return h.first.getHikeName() == hikeName;});       

	cout << fixed << showpoint << setprecision(2);
	cout << it->first << "          $" << it->second;
}

void HikeList::clearList()
{
	hikeMap.clear();
}

HikeList::~HikeList() {}
