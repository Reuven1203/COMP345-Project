/**
 * @file EventData.h
 * @brief Defines the EventData structure, which encapsulates details about various game events.
 *
 * EventData is used to pass detailed information about events occurring within the game,
 * such as player movements, item interactions, and dice rolls. It supports a variety of event types,
 * each potentially carrying different kinds of data relevant to the event.
 */

#ifndef EVENTDATA_H
#define EVENTDATA_H

#include <iostream>
using namespace std;

/**
 * @struct EventData
 * @brief Struct to store information about specific events in the game.
 *
 * EventData includes details such as event type, coordinates for map events,
 * characters' health points, damage dealt, and more, depending on the event.
 */
struct EventData {
    /**
     * @enum EventType
     * @brief Enumerates the types of events that can occur in the game.
     */
    enum class EventType {
        // Map related events
        MapCreated,
        WallPlaced,
        WallRemoved,
        ChestPlaced,
        PlayerPlaced,
        StartPointPlaced,
        EndPointPlaced,
        // Player movement events
        PlayerMovedUp,
        PlayerMovedDown,
        PlayerMovedLeft,
        PlayerMovedRight,
        // Item related event
        ItemStatRolled,
        // Dice related event
        DiceRolled,
        // Player related event
        AttackedResult,
        TurnOrder,
    } type; ///< The type of event that occurred.

    // Variables to store event-specific data
    int newX, newY; ///< New coordinates for map-related events.
    int rolledStat; ///< Result of a dice roll or new stat value.
    int charCurrentHP; ///< Character's current health points.
    int dmgDealt = 0; ///< Damage dealt in an attack event.
    int charType; ///< Character type: 1 for player, 2 for enemy, 3 for friendly.
    string name, name2; ///< Names involved in the event (e.g., attacker and defender names).
    string statname; ///< Name of the stat that changed.
    string result; ///< Result of the event (e.g., attack hit or miss).

    /**
     * Constructor for events related to attacks.
     */
    EventData(EventType type, string resultOfAtk, string attackerName, string defenderName, int charType, int _currentHP, int _dmgDealt)
        : type(type), result(resultOfAtk), name(attackerName), name2(defenderName), charType(charType), charCurrentHP(_currentHP), dmgDealt(_dmgDealt) {}

    /**
     * Constructor for dice-related events.
     */
    EventData(EventType type, string diceType, int diceResult)
        : type(type), name(diceType), rolledStat(diceResult) {}

    /**
     * Constructor for events where a stat changes.
     */
    EventData(EventType type, string _name, string _statName, int stat)
        : type(type), name(_name), statname(_statName), rolledStat(stat) {}

    /**
     * Constructor for map-related events without character names.
     */
    EventData(EventType type, int x, int y)
        : type(type), newX(x), newY(y) {}

    /**
     * Constructor for map-related events with character names.
     */
    EventData(EventType type, string _name, int x, int y)
        : type(type), name(_name), newX(x), newY(y) {}
};

#endif // EVENTDATA_H
