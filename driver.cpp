#include <iostream>
#include "item.h"

using namespace std;

int main()
{
    string pickup="Helmet";
    item test(pickup);

    cout<<test.getEquipType()<<endl;
    test.getStats(); 
    return 0;
}

