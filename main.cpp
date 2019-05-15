#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    List<int> t;
    int buff_elem;
    for(unsigned i=0;i<5;i++){
        cin>>buff_elem;
        t.Push(buff_elem);
    }
    List<int>::Iterator it;
    List<int>::Iterator End;
    it=t.Beg();
    cout<<*it<<"  ";
    End=t.End();
    cout<<*End<<"  ";
   /* while(it!=End){
        cout<<*it;
        ++it;
    }*/
    /*while(!t.isEmpty()){
        t.Pop(buff_elem);
        cout<<buff_elem;
    }*/
    return 0;
}
