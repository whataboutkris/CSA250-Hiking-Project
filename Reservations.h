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
	Node (int theReNumb, int theMemID,std::string theHikeName, Node *prevLink, Node *nextLink)
	: reservationNumber(theReNumb), memID(theMemID), hikeName(theHikeName), prev (prevLink), next (nextLink) {}
	int getreservationNumber( ) const { return reservationNumber; }
	int getMembID( ) const { return membID; }
	std::string getHikeName ( ) const {return hikeName; }
	Node *getPrev ( ) const { return prev; }
	Node *getNext ( ) const { return next; }
	void setReservationNumber(int theReNumb) { reservationNumber = theReNumb; }
	void setMemID(int theMemID) { memID = theMemID; }
	void setHikeName(std::string theHikeName) { hikeName = theHikeName; }
	void setPrev (Node *prevLink) { prev = prevLink; }
	void setNext (Node *nextLink) { next = nextLink; }    
~Node(){}

private:
	int reservationNumber;
	int memberID;
	std::string hikeName;
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
	Reservations () : first(nullptr), last(nullptr), numbOfNodes(0) {}
	int addReservation(int newMemID, std::string hikeName);
	//int *findReservation(const int& newReNumb) const;
	void cancelReservation(int newReservationNumber);
	void printReservation(int newReservationNumber, const HikeList& newHikeList, const MemberList& newMemberList) const;
	void clearList();
~Reservations();

private:
	int *findReservation(const int& newReservationNumber) const;
	Reservations *first;
	Reservations *last;
	int numbOfNodes;

};

#endif
