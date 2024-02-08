#include <iostream>
#include "item.h"

using namespace std;

int main()
{
    string pickup="helmet";
    item test(pickup);

    cout<<test.getEquipType();
    
    return 0;
}

