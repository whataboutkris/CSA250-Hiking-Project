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

using namespace std;

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
    Node* toDelete = findReservation(newReservationNumber);

    if (numbOfNodes == 1)
    {
        delete first;
        first = last = nullptr;
    }
    else if (first == toDelete)
    {
        delete toDelete;
        toDelete = nullptr;
        first = last;
        last->setPrev(nullptr);
    }
    else if (last == toDelete)
    {
        delete toDelete;
        toDelete = nullptr;
        last = first;
        first->setNext(nullptr);
    }
    else 
    {
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
    if(printer != nullptr)
    {
        newHikeList.printByHikeName(printer->getHikeName());
    
    cout << "\n         Discounted price using points: $ " << newHikeList.getPrice(printer->getHikeName())
        - (newMemberList.getPoints(printer->getMembID()) / 100) << endl << endl;
    }
    else
        cerr << "This reservation does not exits.";
}

Node* Reservations::findReservation(int newReservation) const
{
    Node* current = first;

    while (current->getreservationNumber() != newReservation)
    {
        current = current->getNext();
    }
    return current;
}

void Reservations::clearReservation()
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
    Reservations.clearList();
}
