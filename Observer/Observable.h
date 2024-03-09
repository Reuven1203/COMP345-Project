//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#ifndef COMP345_A1_OBSERVABLE_H
#define COMP345_A1_OBSERVABLE_H
#include <list>
#include "Observer.h"


class Observable {
    std::list<Observer*> observers;
public:
    void attach(Observer* observer);
    void detach(Observer* observer);
protected:
    void notify();

};


#endif //COMP345_A1_OBSERVABLE_H
