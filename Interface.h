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

#ifndef INTERFACE_H
#define INTERFACE_H

#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

class Interface
{
public:
    void displayMenu();
    void processReservation(HikeList&, MemberList&, Reservations&);
    void chooseByLocation(HikeList&, MemberList&, Reservations&);
    void chooseByDuration(HikeList&, MemberList&, Reservations&);
    void chooseByDifficulty(HikeList&, MemberList&, Reservations&);
    void chooseByPrice(HikeList&, MemberList&, Reservations&);
    int askIfMember(MemberList&);
    int addNewMember(MemberList&);
    void makeReservation(HikeList&, MemberList&, Reservations&);
    void viewReservation(HikeList&, MemberList&, Reservations&);
    void cancelReservation(HikeList&, MemberList&, Reservations&);
    void askToReserve(HikeList&, MemberList&, Reservations&);
private:

};

#endif