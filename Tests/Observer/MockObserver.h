//
// Created by Reuven Ostrofsky on 2024-03-11.
//

#ifndef COMP345_A1_MOCKOBSERVER_H
#define COMP345_A1_MOCKOBSERVER_H
#include "../../Observer/Observer.h"


class MockObserver : public Observer  {
public:
    bool updated = false;

    void  update() override {
        updated = true;
    }

};


#endif //COMP345_A1_MOCKOBSERVER_H
