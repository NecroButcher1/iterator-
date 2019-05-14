#include <iostream>
#include "List.h"
using namespace std;
int main()
{
    List<int> t;
    int buff_elem;
    for(unsigned i=0;i<5;i++)cin>>buff_elem;
    List<int>::Iterator it;
    it.Beg();
    while(it.Beg()!=it.End()){
        cout<<*it;
        ++it;
    }
    return 0;
}
