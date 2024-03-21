//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#ifndef COMP345_A1_OBSERVER_H
#define COMP345_A1_OBSERVER_H
#include "../Utils/utils.h"
/**
 * @file Observer.h
 * @brief Declaration of the Observer class as part of the Observer design pattern.
 *
 * This file contains the declaration of the Observer class, an essential part
 * of the Observer design pattern. This class serves as a base class for any
 * observers in the pattern, providing a virtual update method that must be
 * implemented by concrete observers.
 */

/**
 * @class Observer
 * @brief Abstract base class for observers in the Observer design pattern.
 *
 * Observer is an abstract base class that defines an interface for all concrete
 * observers that need to be notified about changes in their subject. It provides
 * a pure virtual update method that must be overridden by derived classes to define
 * how they should be updated.
 */

class Observable;

class Observer {
public:
    

    /**
     * @brief Virtual destructor for the Observer class.
     *
     * Ensures proper cleanup of derived classes when deleting instances of Observer.
     */
    virtual ~Observer() = default;

    /**
     * @brief Pure virtual update method that must be implemented by concrete observers.
     *
     * This method is called to notify the observer of changes in the subject it is observing.
     * Concrete observers must override this method to specify how they should respond to these changes.
     */
    virtual void update() = 0;
    virtual void update(Observable*)=0;
};

#endif //COMP345_A1_OBSERVER_H
