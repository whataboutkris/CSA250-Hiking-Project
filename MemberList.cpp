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

#include "MemberList.h"

#include <iostream>
#include <algorithm>

using namespace std;

MemberList::MemberList()
{
	memberList = new set<Member>();
}

void MemberList::addMember(const string& newFirstName,
	const string& newLastName)
{
	Member newMember = Member(newFirstName, newLastName);

	if (memberList->empty())
	{
		newMember.setID(DEFAULT_ID);
	}
	else
	{
		newMember.setID((memberList->rbegin()->getID()) + 1);
		/*int idOffset = static_cast<int>(memberList->size());
		newMember.setID(DEFAULT_ID + idOffset);*/
	}
	memberList->insert(newMember);
}

void MemberList::addMember(const string& newFirstName,
	const string& newLastName, int newPoints)
{
	Member newMember = Member(newFirstName, newLastName);
	newMember.addPoints(newPoints);

	if (memberList->empty())
	{
		newMember.setID(DEFAULT_ID);
	}
	else
	{
		newMember.setID((memberList->rbegin()->getID()) + 1);
		//int idOffset = static_cast<int>(memberList->size());
		//newMember.setID(DEFAULT_ID + idOffset);
	}

	memberList->insert(newMember);
}

int MemberList::getLastID() const
{
	return memberList->rbegin()->getID();
}

int MemberList::getPoints(int id) const
{
	auto memberIter = find_if(memberList->begin(), memberList->end(),
		[&id](const Member& a) {return a.getID() == id; });
	return memberIter->getPoints();
}

void MemberList::printMember(int id, const string& lName) const
{
	auto foundMemberIter = find_if(memberList->begin(), memberList->end(),
		[&id](const Member& a) {return a.getID() == id; });
	if (foundMemberIter->getLName() == lName)
	{
		foundMemberIter->Member::printMember();
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
