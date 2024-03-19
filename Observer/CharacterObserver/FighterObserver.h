// FighterObserver.h

#ifndef COMP345_A1_FIGHTEROBSERVER_H
#define COMP345_A1_FIGHTEROBSERVER_H

#include "../Observer.h"
#include "../../Character/Fighter.h"  // Adjust the path according to your project structure

/**
 * @class FighterObserver
 * @brief Concrete observer for displaying fighter state updates.
 *
 * FighterObserver is a concrete implementation of the Observer class, designed to monitor changes in a Fighter object.
 * When notified of a change, the FighterObserver will update its output to reflect the Fighter's new state.
 */
class FighterObserver : public Observer {
    Fighter *fighter; ///< Pointer to the Fighter being observed.
public:
    /**
     * @brief Constructs a FighterObserver object associated with a specific Fighter.
     *
     * @param fighter Pointer to the Fighter that this observer will monitor.
     */
    explicit FighterObserver(Fighter *fighter) : fighter(fighter) {}

    /**
     * @brief Overridden update method that defines how the observer responds to fighter changes.
     *
     * When the observed Fighter changes, this method is called to update the FighterObserver
     * accordingly. It should define the specific actions to take in response to the Fighter's state change.
     */
    void update() override;
};

#endif //COMP345_A1_FIGHTEROBSERVER_H
