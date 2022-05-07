#include<iostream>
#include<string>
#include "Hike.h"


using namespace std;
int main()
{
	Hike myHike("Montana", "Glacier", 5, 'e');
	cout << myHike;
	return 0;
}