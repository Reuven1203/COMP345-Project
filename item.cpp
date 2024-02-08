#include <iostream>
#include "item.h"

using namespace std;

item::item(){}
item::~item(){}


item::item(string x)
{
    this->equipType=x;
}

string item::getEquipType()
{
    return equipType;
}

void item::setEquipType(string type)
{
    this->equipType=type;
}