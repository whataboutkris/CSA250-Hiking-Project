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
	h.addHike("Montana", "Somewhere", 2, 'e', 453);
	h.addHike("California", "Zion", 3, 'm', 2904);

	h.addHike(myHike, 98987);
	cout << h.getPrice("Glacier");
	h.printAllLocations();
	h.printByLocation("Montana");

	return 0;
}