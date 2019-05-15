#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "stdio.h"
template<typename T>
class List{
    struct Node{
        T Data;
        Node *next;
    };
    typedef Node* PNode;
    unsigned errcode;
    unsigned Size;
    PNode ptr,head;
public:
    class Iterator{
    private:
        PNode itr;
        size_t idx;
    public:
        Iterator(){
            itr=NULL;
            idx=0;
        }
        T operator*(){
            return itr->Data;
        }
        PNode operator++(){
            itr=itr->next;
            idx++;
            return itr;
        }
        void operator=(PNode t){
            itr=t;
        }
        bool operator==(Iterator &t){
            if((idx==t.idx)&&(itr->Data==t.itr->Data))return true;
            else return false;
        }
        bool operator!=(Iterator &t){
            if((idx!=t.idx)||(itr->Data==t.itr->Data))return true;
            else return false;
        }
    };
    List(){
        ptr=NULL;
        Size=0;
        errcode=1;
    }
    int Push(T _Data){
        PNode p=new Node;
        errcode=0;
        if(p==NULL)errcode=1;
        else{
            p->Data=_Data;
            Size++;
            if(!head){
                head->next=p;
                p=head;
                ptr=head->next;
            }
            else{
                p->next=ptr;
                ptr=p;
            }
        }
        return errcode;
    }
    int Pop(T &_Data){
        errcode=0;
        Size--;
        if(ptr==NULL){
            errcode=1;
            head=NULL;
        }
        else{
            _Data=ptr->Data;
             ptr=ptr->next;
        }
        return errcode;
    }
    int get(T &_Data){
        errcode=0;
        if(ptr==NULL)errcode=1;
        else{
            _Data=ptr->Data;
        }
        return errcode;
    }
    void doEmpty(){
        while(ptr){
            ptr=ptr->next;
        }
        head=NULL;
        Size=0;
    }
    bool isEmpty(){
        bool r=false;
        if(ptr==NULL)r=true;
        return r;
    }
    PNode Beg(){
        return head;
    }
    PNode End(){
        return ptr;
    }
    ~List(){
        doEmpty();
    }
};

#endif // STACK_H_INCLUDED
