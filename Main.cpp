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

#include<iostream>
#include<string>
#include "Interface.h"

using namespace std;

int main()
{
	Hike myHike("Montana", "Glacier", 5, 'e');
	cout << myHike.getDuration();

	HikeList h;
	h.addHike("Montana", "Somewhere", 5, 'e', 8453); 
	h.addHike("California", "Zion", 5, 'm', 2904);
	h.addHike(myHike, 98987);
	//cout << h.getPrice("Glacier"); //Crashes in getPrice()
	//h.printAllLocations();
	//h.printByLocation("Montana");
	h.printByDuration(5);

	return 0;
}