/* Author: Richard Mauricio
   ID:     40224398
*/
#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <iostream>
#include <vector>
#include "Item.h"
class container{
public:
container();
~container();

//getters
void getItems();
void getItemStats();

//setters
void storeItem(Item&);


Item removeItemFromChest(int index);
void deleteItemInChest(int index);

private:
vector<Item>storedItems;
string name;
};
#endif // ITEMCONTAINER_H
