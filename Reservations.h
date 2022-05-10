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

#ifndef RESERVATIONS_H
#define RESERVATIONS_H
#include <iostream>

const int RESERVATION_NUMBER = 50001;

class Node {
public:
	Node() : reservationNumber(RESERVATION_NUMBER), memberID(0), prev(nullptr), next(nullptr) {}
	Node* getNext() const { return next; }


private:
	int reservationNumber;
	int memberID;
	string hikeName;
	Node* prev;
	Node* next;
};




class Reservations {

public:


private:


};

private:
	int reservationNumber;
	int memberID;
	std::string hikeName;
	Node* next;
	Node* prev;
};

class Reservations
{
public:

private:

};

#endif
