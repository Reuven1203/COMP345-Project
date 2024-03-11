//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#ifndef COMP345_A1_CHARACTERDISPLAY_H
#define COMP345_A1_CHARACTERDISPLAY_H
#include "../Observer.h"
#include "../../Character/Character.h"

/**
 * @file CharacterDisplay.h
 * @brief Declaration of the CharacterDisplay class, a concrete observer for character state changes.
 *
 * This file contains the declaration of the CharacterDisplay class, which is a concrete observer that
 * responds to changes in a Character object's state. It is part of the Observer design pattern implementation
 * in the context of character state monitoring.
 */

/**
 * @class CharacterDisplay
 * @brief Concrete observer for displaying character state updates.
 *
 * CharacterDisplay is a concrete implementation of the Observer class, designed to monitor changes in a Character object.
 * When notified of a change, the CharacterDisplay will update its display to reflect the Character's new state.
 */
class CharacterDisplay : public Observer {
    Character *character; ///< Pointer to the Character being observed.

public:
    /**
     * @brief Constructs a CharacterDisplay object associated with a specific Character.
     *
     * @param character Pointer to the Character that this display will observe.
     */
    explicit CharacterDisplay(Character *character) : character(character) {}

    /**
     * @brief Overridden update method that defines how the display responds to character changes.
     *
     * When the observed Character changes, this method is called to update the CharacterDisplay
     * accordingly. It should define the specific actions to take in response to the Character's state change.
     */
    void update() override;
};

#endif //COMP345_A1_CHARACTERDISPLAY_H
