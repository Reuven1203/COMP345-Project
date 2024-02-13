/* Author: Richard Mauricio
   ID:     40224398
*/
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


private:
vector<Item>storedItems;
string name;
};