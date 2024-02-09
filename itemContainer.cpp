#include <iostream>
#include <vector>
#include "itemContainer.h"
#include "item.h"


using namespace std;

container::container(){
    name="";
    
}
container::~container(){}


//prints item types in container
void container::getItems()
{
    cout<<"List of items in container:"<<endl;
    for(auto &i:storedItems)
    {
        cout<<i.getEquipType()<<" | ";
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


//Store item into vector
void container::storeItem(item& itemObtained)
{
    storedItems.push_back(itemObtained);
}
