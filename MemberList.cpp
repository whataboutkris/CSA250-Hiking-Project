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
        newMember.setID(DEFAULT_ID);
    }
    else
    {
        int idOffset = static_cast<int>(memberList->size());
        newMember.setID(DEFAULT_ID + idOffset);
    }
    memberList->insert(newMember);
}

void MemberList::addMember(const string& newFirstName, const string& newLastName, int newPoints)
{
    Member newMember = Member(newFirstName, newLastName);
    newMember.addPoints(newPoints);

    if (memberList->empty())
    {
        newMember.setID(DEFAULT_ID);
    }
    else
    {
        int idOffset = static_cast<int>(memberList->size());
        newMember.setID(DEFAULT_ID + idOffset);
    }

    memberList->insert(newMember);
}

int MemberList::getLastID() const
{
    auto lastMember = memberList->rbegin();
    return lastMember->getID();
}

int MemberList::getPoints(int id) const
{
    auto foundMember = find_if(memberList->begin(), memberList->end(), [id](const Member& a) {return a.getID() == id; });
    return foundMember->getPoints();
}

void MemberList::printMember(int id, const string& lName) const
{
    auto foundMember = find_if(memberList->begin(), memberList->end(), [id](const Member& a) {return a.getID() == id; });
    if (foundMember->getLName() == lName)
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

