#pragma once
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





#endif
