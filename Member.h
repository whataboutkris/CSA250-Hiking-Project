#pragma once
#ifndef MEMBER_H
#define MEMBER_H

#include<string>

class Member
{
public:
	Member() : id(0), points(0) {};

	Member(const std::string&, const std::string&);

	void addPoints(int);

	void setID(const int&);

	int getID() const;
	std::string getLName() const;
	int getPoints() const;

	void printMember() const;

	~Member() {}

private:
	int id;
	std::string fName;
	std::string lName;
	int points;
};

#endif