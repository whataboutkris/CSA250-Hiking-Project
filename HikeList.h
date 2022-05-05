/*
    Team name
    // blank line
    Lastname, Firstname // member 1
    Lastname, Firstname // member 2 and so on, if any
    // blank line
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef HIKE_LIST_H
#define HIKE_LIST_H

#include <iostream>
#include <string>
#include <map>
#include "Hike.h"

class HikeList
{
public:

private:
    std::multimap<const Hike&, double> m;
};

#endif