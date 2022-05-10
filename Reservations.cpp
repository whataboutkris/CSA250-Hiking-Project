<<<<<<< HEAD
#include <iostream>
#include <string>
#include "Reservations.h"
using namespace std;

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
    count = 0;
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
=======
#include <iostream>
#include <string>
#include "Reservations.h"
using namespace std;

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
    count = 0;
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
>>>>>>> d5d056be419a71123008bfdbfc97603e341ea1a2
