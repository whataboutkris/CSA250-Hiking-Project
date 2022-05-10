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
