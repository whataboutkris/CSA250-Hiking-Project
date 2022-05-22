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

#include "HikeList.h"
#include "MemberList.h"

#include <string>

const int DEFAULT_RESERVATION = 50001;

class Node
{
public:
	Node() : reservationNumber(DEFAULT_RESERVATION), memID(0),hikeName(),
		prev(nullptr), next(nullptr) {}
	Node (int reservationNumb, int theMemID, 
		const std::string& theHikeName, Node *prevLink, Node *nextLink)
		: reservationNumber(reservationNumb), memID(theMemID), 
		hikeName(theHikeName), prev (prevLink), next (nextLink) {}
	int getreservationNumber( ) const { return reservationNumber; }
	int getMembID( ) const { return memID; }
	std::string getHikeName ( ) const {return hikeName; }
	Node *getPrev ( ) const { return prev; }
	Node *getNext ( ) const { return next; }
	void setReservationNumber(int theReNumb) 
		{ reservationNumber = theReNumb; }
	void setMemID(int theMemID) { memID = theMemID; }
	void setHikeName(const std::string& theHikeName) 
		{ hikeName = theHikeName; }
	void setPrev (Node *prevLink) { prev = prevLink; }
	void setNext (Node *nextLink) { next = nextLink; }    
~Node(){}

private:
	int reservationNumber;
	int memID;
	std::string hikeName;
	Node* prev;
	Node* next;
};

class Reservations
{
public:
	Reservations () : first(nullptr), last(nullptr), numbOfNodes(0) {}
	
	int addReservation(int newMemID, const std::string& hikeName);
	void cancelReservation(int newReservationNumber);
	
	void printReservation(int newReservationNumber,
		const HikeList& newHikeList, const MemberList& newMemberList)
		const;
	
	void clearList();
	~Reservations();

private:
	Node* findReservation(int newReservationNumber) const;
	Node *first;
	Node *last;
	int numbOfNodes;
};
#endif
