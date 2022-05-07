#include<iostream>
#include<string>
#include "Hike.h"
#include "HikeList.h"


using namespace std;
int main()
{
	Hike myHike("Montana", "Glacier", 5, 'e');
	myHike.getDuration();
	return 0;
}