/**
 * @file GameObserver.h
 * @brief Defines the GameObserver class, which is used to observe and log game events.
 *
 * This file declares the GameObserver class which is part of the Observer pattern.
 * It observes changes in game state and logs events for dungeon maps, characters, and dice rolls.
 *
 * @author Richard Mauricio
 */

#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H

#include <fstream>
#include <vector>
#include "../Observer.h"
#include "../Observable.h"
#include "../../Character/Character.h"
#include "../../Dice/Dice.h"
#include "../../Events/EventData.h"
#include "../../Map/map.h"

class dungeonMap;

using namespace std;

/**
 * @class GameObserver
 * @brief Observer for game events, capable of logging changes in dungeon maps, characters, and dice rolls.
 *
 * GameObserver implements the Observer interface and provides mechanisms to attach to various observables like
 * dungeon maps, characters, and dice. It overrides the update method to log relevant events.
 */
class GameObserver : public Observer {
public:
    /**
     * Default constructor.
     */
    GameObserver();

    /**
     * Destructor.
     */
    ~GameObserver();

    /**
     * Attaches the observer to a dungeonMap observable.
     * @param dungeonMap* Pointer to the dungeonMap to observe.
     */
    void attachObservable(dungeonMap* map);

    /**
     * Attaches the observer to a Character observable.
     * @param Character* Pointer to the Character to observe.
     */
    void attachObservable(Character*);

    /**
     * Attaches the observer to a Dice observable.
     * @param Dice* Pointer to the Dice to observe.
     */
    void attachObservable(Dice*);

    /**
     * Detaches the observer from an Observable.
     * @param Observable* Pointer to the Observable to detach from.
     */
    void detachObservable(Observable*);

    /**
     * Updates the observer without specific event data. Overrides Observer's update method.
     */
    void update() override {};

    /**
     * Updates the observer with specific event data.
     * @param event Reference to the EventData object containing event specifics.
     */
    void update(const EventData& event);

    void update(EventData&) override { };

    /**
     * Logs an event. The specifics of the logging mechanism depend on the implementation.
     */
    void logEvent();

private:
    ofstream log; ///< Output file stream for logging events.
    Dice* _dice; ///< Pointer to the Dice observable, if any.
    Character* _char; ///< Pointer to the Character observable, if any.

    vector<dungeonMap*> mapList; ///< List of pointers to the dungeonMap observables.
};

#endif // !GAMEOBSERVER_H
