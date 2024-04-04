/**
 * @file ItemEditor.h
 * @brief ItemEditor interface to create and save a custom item to a file.
 * @author
 */

#ifndef COMP345_A1_ITEMEDITOR_H
#define COMP345_A1_ITEMEDITOR_H

#include "Item.h"
#include <fstream>

/**
 * @class ItemEditor
 * @brief Interface to create/save custom item to file.
 */
class ItemEditor {
public:
    /**
     * @brief Default Constructor
     */
    ItemEditor();
    /**
     * @brief Run the item editor interface
     */
    void run();
    /**
     * @brief Create a new item from user input
     */
    void createNewItem();
    /**
     * @brief Accessor for item held in ItemEditor class
     * @return item created by ItemEditor
     */
    Item getItem() {
        return item;
    }
private:
    Item item {}; ///< Item held and modified by ItemEditor object
    std::string fileName {}; ///< Name of file where item is saved / to be saved

    /**
     * @brief Internal function to create Helmet item from user input
     */
    void createHelmet();
    /**
     * @brief Internal function to create Armor item from user input
     */
    void createArmor();
    /**
     * @brief Internal function to create Shield item from user input
     */
    void createShield();
    /**
     * @brief Internal function to create Ring item from user input
     */
    void createRing();
    /**
     * @brief Internal function to create Belt item from user input
     */
    void createBelt();
    /**
     * @brief Internal function to create Boots item from user input
     */
    void createBoots();
    /**
     * @brief Internal function to create Weapon item from user input
     */
    void createWeapon();
    /**
     * @brief Internal function to save ask user for filename to save
     */
    void saveItem();
    /**
     * @brief Internal function to save item to file
     * @param filename Name of file where item will be saved
     */
    void save(std::string filename);
};


#endif //COMP345_A1_ITEMEDITOR_H
