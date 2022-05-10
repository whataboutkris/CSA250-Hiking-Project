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

const int DEFAULT_RESERVATION = 50001;
class Node
{
public:
Node () : reNumb(0), memID(0), hikeName(), prev(nullptr), next(nullptr) {}
Node (int theReNumb, int theMemID,std::string theHikeName, Node *prevLink, Node *nextLink)
: reNumb(theReNumb), memID(theMemID), hikeName(theHikeName), prev (prevLink), next (nextLink) {}
int getReNumb( ) const { return reNumb; }
int getMembID( ) const { return membID; }
std::string getHikeName ( ) const {return hikeName; }
Node *getPrev ( ) const { return prev; }
Node *getNext ( ) const { return next; }
void setreNumb(int theReNumb) { reNumb = theReNumb; }
void setMemID(int theMemID) { memID = theMemID; }
void setHikeName(std::string theHikeName) { hikeName = theHikeName; }
void setPrev (Node *prevLink) { prev = prevLink; }
void setNext (Node *nextLink) { next = nextLink; }    
~Node(){}
private:
int reNumb;
int memID;
std::string hikeName;
Node *prev;
Node *next;
};

class Reservations
{
public:
Reservations () : first(nullptr), last(nullptr), numbOfNodes(0) {}
int addReservation(int newMemID, std::string nameOfHike);
//int *findReservation(const int& newReNumb) const;
void cancelReservation(int newReNumb);
void printReservation(int newReNumb, const HikeList& newHikeList, const MemberList& newMemberList) const;
void clearList();
~Reservations();

private:
int *findReservation(const int& newReNumb) const;
Reservations *first;
Reservations *last;
int numbOfNodes;
};

#endif
