//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#include "Observable.h"


void Observable::attach(Observer *observer) {
    observers.push_back(observer);

}

void Observable::detach(Observer *observer) {
    observers.remove(observer);
}

void Observable::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}
