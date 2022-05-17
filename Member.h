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

#ifndef MEMBER_H
#define MEMBER_H

#include<string>

class Member
{
public:
	Member() : id(0), points(0), fName(), lName() {};
	Member(const std::string&, const std::string&);

	void addPoints(int);
	void setID(const int&);

	int getID() const;
	std::string getLName() const;
	int getPoints() const;
	
	bool operator<(const Member&) const;

	void printMember() const;

	~Member() {}

private:
	int id;
	std::string fName;
	std::string lName;
	int points;
};

#endif
