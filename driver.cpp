#include <iostream>
#include "item.h"
#include "itemContainer.h"
using namespace std;

int main()
{
    string pickup="Helmet",pickup2="RiNG",pickup3="ring",pickup4="belt",pickup5="weapon";
    container chest;
    item test(pickup);
    item test2(pickup2);
    item test3(pickup5);
    
    chest.storeItem(test);
    chest.storeItem(test2);
    chest.storeItem(test3);
    chest.getItems();
    chest.getItemStats();
   
    return 0;
}

