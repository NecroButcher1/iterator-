#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
template<typename T>
class List{
private:
    struct Node{
        T Data;
        Node *next;
    };
    typedef Node* PNode;
    size_t Size;
    PNode head,ptr;
public:
    class Iterator{
    private:
        PNode itr;
        List *tmp;
        size_t idx;
    public:
        Iterator():itr(NULL),tmp(this),idx(0){};
        void operator=(Iterator *p){
            itr=p->itr;
            tmp=p->tmp;
            idx=p->idx;
        }
        void operator++(){
            itr=itr->next;
            idx++;
        }
        T operator*(){
            return itr->Data;
        }
        bool operator==(Iterator& t){
            return((itr->Data==t.itr->Data)&&(idx==t.idx))?true:false;
        }
        bool operator!=(Iterator &t){
            return((itr->Data!=t.itr->Data)||(idx!=t.idx))?true:false;
        }
    };
    List():head(NULL),ptr(NULL),Size(0){};
    bool isEmpty(){
        return((head==NULL)||(ptr==NULL))? true:false;
    }
    unsigned Insert(T _Data){
        unsigned out=0;
        PNode p = new Node;
        if(p==NULL)out=1;
        else{
            p->Data=_Data;
            p->next=NULL;
            Size++;
            if(!head){
                p->next=head;
                head=p;
                ptr=head;
            }
            else{
                p->next=ptr;
                ptr=p;
            }
        }
        return out;
    }
    unsigned Extract(T &_Data){
        unsigned out=0;
        if(!ptr){
            out=1;
            head=NULL;
            Size=0;
        }
        else{
            _Data=ptr->Data;
            ptr=ptr->next;
            Size--;
        }
     return out;
    }
    Iterator *begin(){
        return Iterator(head,this,1);
    }
    Iterator *end(){
        return Iterator(ptr,this,Size);
    }
};


#endif // LIST_H_INCLUDED
