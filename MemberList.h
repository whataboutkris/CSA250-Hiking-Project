#pragma once
/*
    Team name

    Lastname, Firstname // member 1
    Kelley, Bobby // member 2 and so on, if any

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"
#include <set>

class MemberList
{
public:
    MemberList();

    void addMember(const std::string&, const std::string&);
    void addMember(const std::string&, const std::string&, int points);

    int getLastID() const;
    int getPoints(int id) const;

    void printMember(int, const std::string&) const;

    void clearList();

    ~MemberList();

private:
    std::set<Member>* memberList;
};

#endif