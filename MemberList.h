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

#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include <string>
#include <set>
#include "Member.h"

const int DEFAULT_ID = 111;

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
