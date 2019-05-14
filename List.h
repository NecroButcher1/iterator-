#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
template<typename T>
class List{
private:
    struct Node{
        T Data;
        Node* next;
    };
    typedef Node* PNode;
    PNode ptr,head;
public:
    class Iterator{
    private:
        List *tmp;
        PNode itr;
        T value;
    public:
        Iterator(){
            itr=NULL;
        }
        PNode Beg(){
            if(tmp->head){
                itr=tmp->head;
                value=itr->Data;
            }
            else itr=NULL;
            return itr;
        }
        T operator*(){
            return value;
        }
        PNode operator++(){
            itr=itr->next;
            return itr;
        }
        PNode End(){
            if(tmp->head){
                itr=tmp->head;
                while(itr){
                    itr=itr->next;
                }
                value=itr->Data;
            }
            else itr=NULL;
            return itr;
        }
        bool operator==(Iterator &t){
            if(itr==t)return true;
            else return false;
        }
        bool operator!=(Iterator &t){
            if(itr!=t)return true;
            else return false;
        }
    };
    List(){
        ptr=NULL;
        head=NULL;
    }
    unsigned push(T _data){
        unsigned err=0;
        PNode p =new Node;
        if(p==NULL)err=1;
        else{
            p->Data=_data;
            p->next=NULL;
            if(!head){
                p->next=head;
                head=p;
                ptr=p;
            }
            else{
                ptr=head;
                while(ptr->next)ptr=ptr->next;
                p->next=ptr->next;
                ptr->next=p;
            }
        }
        return err;
    }
    unsigned pop(T &_data){
        unsigned err=0;
        if(ptr==NULL)err=1;
        else{
            _data=ptr->Data;
            ptr=ptr->next;
        }
        return err;
    }
};


#endif // LIST_H_INCLUDED
