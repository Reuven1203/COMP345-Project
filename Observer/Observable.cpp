//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#include "Observable.h"
#include "GameObserver/GameObserver.h"
#include "../Events/EventData.h"

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
void Observable::notifyGameObserver(EventData& event)
{
    for (auto observer : observers)
    {
        GameObserver* gameobserver = dynamic_cast<GameObserver*>(observer);
        if (gameobserver)
        {
            gameobserver->update(event);
        }
    }
}

