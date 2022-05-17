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

#include "Reservations.h"

#include <iostream>
#include <string>
using namespace std;

Node* Reservations::findReservation(int newReservation) const
{
    Node* current = first;
    
    while ( current->getreservationNumber() != newReservation)
    {
        current = current->getNext();
    }
    return current;
}


int Reservations::addReservation(int newMemID, const string& hikeName)
{
    if (numbOfNodes == 0)
    {
        first = new Node(DEFAULT_RESERVATION, newMemID, hikeName, nullptr, nullptr);
        last = first;
    }
    else
    {
        last = new Node((last->getreservationNumber()) + 1, newMemID, hikeName, last, nullptr);
        last->getPrev()->setNext(last);
    }

    ++numbOfNodes;
    return last->getreservationNumber();
}

void Reservations::cancelReservation(int newReservationNumber)
{
    if (numbOfNodes == 1)
    {
        Node temp;
        delete first;
        first = last = nullptr;
    }
    else
    {
        Node* toDelete = findReservation(newReservationNumber);
        toDelete->getPrev()->setNext(toDelete->getNext());
        toDelete->getNext()->setPrev(toDelete->getPrev());
        delete toDelete;
        toDelete = nullptr;
    }
    --numbOfNodes;
}

void Reservations::printReservation(int newReservationNumber, 
        const HikeList& newHikeList, const MemberList& newMemberList) const
{
    Node* printer = findReservation(newReservationNumber);
    newHikeList.printByHikeName(printer->getHikeName());
    
    cout << "\n         Discounted price using points: $ " << newHikeList.getPrice(printer->getHikeName())
        - (newMemberList.getPoints(printer->getMembID()) / 100) << endl << endl;
}

void Reservations::clearList()
{
    Node* temp = first;
    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    last = nullptr;
    numbOfNodes = 0;
}

Reservations::~Reservations()
{
    Node *current = first;
    while(current != nullptr)
    {
        Node *temp = current->getNext();
        delete current;
        current = temp;
    }
    first = last = nullptr;
}
