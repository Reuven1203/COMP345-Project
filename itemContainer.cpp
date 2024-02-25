/* Author: Richard Mauricio
   ID:     40224398
*/

#include <iostream>
#include <vector>
#include "itemContainer.h"
#include "Item.h"


using namespace std;

container::container(){
    name="";
    
}
container::~container(){}


//prints Item types in container
void container::getItems()
{
    int counter = 0;
    cout<<"List of items in container:"<<endl;
    for(auto &i:storedItems)
    {
        cout<<counter<<". " << i.getEquipType() << " | ";
        counter++;
    }
    cout<<"\n\n";
}

//prints the stats of items in container
void container::getItemStats()
{
    for(auto &i:storedItems)
    {
        i.printStats();
    }
}


//Store Item into vector
void container::storeItem(Item& itemObtained)
{
    storedItems.push_back(itemObtained);
}

Item container::removeItemFromChest(int index)
{
 
        Item hold = storedItems[index];
        deleteItemInChest(index);
        return hold;
        
    
}

void container::deleteItemInChest(int index)
{
    storedItems.erase(storedItems.begin()+index);
}