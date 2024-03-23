//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#ifndef COMP345_A1_OBSERVABLE_H
#define COMP345_A1_OBSERVABLE_H
#include <list>
#include "Observer.h"
#include "../Utils/utils.h"
#include "../Events/EventData.h"
/**
 * @file Observable.h
 * @brief Declaration of the Observable class as part of the Observer design pattern.
 *
 * This file contains the declaration of the Observable class, which is a crucial component
 * of the Observer design pattern. This class allows observers to be attached or detached and
 * notifies them of changes.
 */

/**
 * @class Observable
 * @brief Class that can be observed by Observer objects.
 *
 * The Observable class represents objects that can be observed by Observer instances. It maintains
 * a list of observers and provides methods to add or remove observers. When the Observable changes,
 * it notifies all registered observers by calling their update method.
 */
class Observable {
    friend class ObservableTest; ///< Friend class for unit testing purposes.
    std::list<Observer*> observers; ///< List of pointers to Observer objects.

public:
    
    /**
     * @brief Attaches an observer to the observable object.
     *
     * Adds an observer to the list of observers. This observer will be notified of changes.
     *
     * @param observer Pointer to the Observer to be attached.
     */
    void attach(Observer* observer);

    /**
     * @brief Detaches an observer from the observable object.
     *
     * Removes an observer from the list of observers. This observer will no longer be notified of changes.
     *
     * @param observer Pointer to the Observer to be detached.
     */
    void detach(Observer* observer);
    

/**
 * @brief Notifies all attached observers of a change.
 *
 * Calls the update method on all attached observers, indicating that something has changed in the observable.
 */

void notify();
void notifyGameObserver(const EventData&);
};

#endif //COMP345_A1_OBSERVABLE_H
