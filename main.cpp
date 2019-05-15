#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List<int> p;
    int buff_elem;
    for(unsigned i=0;i<5;i++){
        cin>>buff_elem;
        p.Insert(buff_elem);
    }
    while(!p.isEmpty()){
        p.Extract(buff_elem);
        cout<<buff_elem;
    }
    List<int>::Iterator it;
    List<int>::Iterator ed;
    it=p.begin();
    ed=p.end();
    while(it!=ed){
        cout<<*it<<" ";
        ++it;
    }
    return 0;
}
