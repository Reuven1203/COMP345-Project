#include <iostream>
#include <vector>
#include "item.h"
class container{
public:
container();
~container();

//getters
void getItems();
void getItemStats();

//setters
void storeItem(item&);


private:
vector<item>storedItems;
string name;
};