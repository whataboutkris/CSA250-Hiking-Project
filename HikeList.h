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

#ifndef HIKE_LIST_H
#define HIKE_LIST_H

#include <map>
#include <string>
#include "Hike.h"

class HikeList
{
public:
    HikeList();
    
    void addHike(const Hike&, double hikePrice);
    void addHike(const std::string& hikeLocation, const std::string& hikeName,
                    int hikeDuration, char hikeDifficulty, double hikePrice);
    
    double getPrice(const std::string& hikeName) const;
    
    void printAllLocations() const;
    void printByLocation(const std::string& hikeLocation) const;
    void printByDuration() const;
    void printByDuration(int days) const;
    void printByDifficulty(char hikeDifficulty) const;
    void printByPrice() const;
    void printByHikeName(const std::string& hikeName) const;
    
    void clearList();
    ~HikeList();
private:
    std::multimap<Hike, double> aMap;
};

#endif
