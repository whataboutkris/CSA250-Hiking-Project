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
#include "Hike.h"
#include "HikeList.h"


using namespace std;
int main()
{
	Hike myHike("Montana", "Glacier", 5, 'e');
	cout << myHike.getDuration();


	HikeList h;
	h.addHike2("Montana", "Somewhere", 2, 'e', 453);
	h.addHike2("California", "Zion", 3, 'm', 2904);
	
	h.addHike1(myHike, 98987);
	cout << h.getPrice("Glacier");
	h.printAllLocations();
	h.printByLocation("Montana");
	h.printByDuration();

	return 0;
}