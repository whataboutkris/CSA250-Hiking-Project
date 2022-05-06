#include "MemberList.h"
#include <algorithm>
#include <iterator>

using namespace std;

const int DEFAULT_ID = 111;

MemberList::MemberList()
{
    memberList = new set<Member>();
}

void MemberList::addMember(const string& newFirstName, const string& newLastName)
{
    Member newMember = Member(newFirstName, newLastName);

    if (memberList->empty())
    {
        newMember.id = DEFAULT_ID;
    }
    else
    {
        int idOffset = static_cast<int>(memberList->size());
        newMember.id = DEFAULT_ID + idOffset;
    }
    memberList->insert(newMember);
}

void MemberList::addMember(const string& newFirstName, const string& newLastName, int newPoints)
{
    Member newMember = Member(newFirstName, newLastName);
    newMember.points = newPoints;

    if (memberList->empty())
    {
        newMember.id = DEFAULT_ID;
    }
    else
    {
        int idOffset = static_cast<int>(memberList->size());
        newMember.id = DEFAULT_ID + idOffset;
    }
    
    memberList->insert(newMember);
}

int MemberList::getLastID() const
{
    auto lastMember = memberList->rbegin();
    return lastMember.id;
}

int MemberList::getPoints(int id) const
{
    auto foundMember = find_if(memberList->begin(), memberList->end(), [](Member& a) {return a->id == id;});
    return foundMember->points;
}

void MemberList::printMember(int id, const string& lName) const
{
    auto foundMember = find_if(memberList->begin(), memberList->end(), [](Member& a) {return a->id == id;});
    if (foundMember->id == foundMember->lName)
    {
        foundMember->Member::printMember();
    }
}

void MemberList::clearList()
{
    memberList->clear();
}

MemberList::~MemberList()
{
    delete memberList;
    memberList = nullptr;
}