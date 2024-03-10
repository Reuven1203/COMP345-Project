//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#ifndef COMP345_A1_OBSERVER_H
#define COMP345_A1_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};


#endif //COMP345_A1_OBSERVER_H
