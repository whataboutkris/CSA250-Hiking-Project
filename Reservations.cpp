////<<<<<<< HEAD
//#include <iostream>
//#include <string>
//#include "Reservations.h"
//using namespace std;
//
//void Reservations::clearList()
//{
//    if (count == 1)
//    {
//        delete first;
//        first = last = nullptr;
//        count = 0;
//    }
//    else if (count > 1)
//    {
//        Node* current = first;
//        while (first != nullptr)
//        {
//            first = first->getNext();
//            delete current;
//            current = first;
//        }
//        
//        last = nullptr;
//        count = 0;
//    }
//}
//
//Reservations::~Reservations()
//{
//    clearList();
//}
//=======

#include <iostream>
#include <string>
#include "Reservations.h"
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
    
    cout << "   Discounted price using points: $ " << newHikeList.getPrice(printer->getHikeName())
        - (newMemberList.getPoints(printer->getMembID()) / 100) << endl;
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
//>>>>>>> d5d056be419a71123008bfdbfc97603e341ea1a2
