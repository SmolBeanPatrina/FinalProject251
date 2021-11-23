#include "list.hpp"
#include <iostream>

void DSLinkedList::RemoveHead(){
    if(head == NULL){
        return;
    }
    else{
        Link<DomesticStudent> * to_remove;
        to_remove = head;
        if(head == tail){
            head == NULL;
            tail == NULL;
        }
        else{
            head = head->link;
        }
        delete to_remove;
    }

}
void DSLinkedList::RemoveTail(){
    if(tail == NULL){
        return;
    }
    else{
        Link<DomesticStudent> * to_remove = tail;
        if(head == tail){
            head == NULL;
            tail == NULL;
        }else{

            Link<DomesticStudent> * previous = head;
            while(previous->link != tail){
                previous = previous->link;
            }
            tail = previous;
            tail->link = NULL;
        }
        delete to_remove;
    }

}

void ISLinkedList::RemoveTail(){
    if(tail == NULL){
        return;
    }
    else{
        Link<InternationalStudent> * to_remove = tail;
        if(head == tail){
            head == NULL;
            tail == NULL;
        }else{

            Link<InternationalStudent> * previous = head;
            while(previous->link != tail){
                previous = previous->link;
            }
            tail = previous;
            tail->link = NULL;
        }
        delete to_remove;
    }

}

void SLinkedList::RemoveTail(){
    if(tail == NULL){
        return;
    }
    else{
        Link<Student> * to_remove = tail;
        if(head == tail){
            head == NULL;
            tail == NULL;
        }else{

            Link<Student> * previous = head;
            while(previous->link != tail){
                previous = previous->link;
            }
            tail = previous;
            tail->link = NULL;
        }
        delete to_remove;
    }

}
void ISLinkedList::RemoveHead(){

    if(head == NULL){
        return;
    }
    else{
        Link<InternationalStudent> * to_remove;
        to_remove = head;
        if(head == tail){
            head == NULL;
            tail == NULL;
        }
        else{
            head = head->link;
        }
        delete to_remove;
    }
}
void SLinkedList::RemoveHead(){

    if(head == NULL){
        return;
    }
    else{
        Link<Student> * to_remove;
        to_remove = head;
        if(head == tail){
            head == NULL;
            tail == NULL;
        }
        else{
            head = head->link;
        }
        delete to_remove;
    }
}

DSLinkedList::DSLinkedList(){
    head = NULL;
    tail = NULL;
}

SLinkedList::SLinkedList(){
    head = NULL;
    tail = NULL;
}
void SLinkedList::Sort(){
    MergeSort(&(head));
    set_tail<SLinkedList, Student>(this);
}
void SLinkedList::AddNode(Student x){
    push_node_to_list(this, x);
    set_tail<SLinkedList, Student>(this);
}
void SLinkedList::print(){
    Link<Student> * temp = head;
    while(temp != NULL){
        cout << temp->student;
        temp = temp->link;
    }
}

void DSLinkedList::Sort(){
    MergeSort(&(head));
    set_tail<DSLinkedList, DomesticStudent>(this);
}
void DSLinkedList::print(){
    Link<DomesticStudent> * temp = head;
    while(temp != NULL){
        cout << temp->student;
        temp = temp->link;
    }
}

void DSLinkedList::AddNode(DomesticStudent x){
    push_node_to_list(this, x);
    Sort();
    set_tail<DSLinkedList, DomesticStudent>(this);
}

void ISLinkedList::AddNode(InternationalStudent x){
    push_node_to_list(this, x);
    Sort();
    set_tail<ISLinkedList, InternationalStudent>(this);
}

void ISLinkedList::print(){
    Link<InternationalStudent> * temp = head;
    while(temp != NULL){
        cout << temp->student;
        temp = temp->link;
    }
}

void ISLinkedList::Sort(){
    // ValidateT();
    MergeSort(&head);
    set_tail<ISLinkedList, InternationalStudent>(this);
    
}

ISLinkedList::ISLinkedList(){
    head = NULL;
    tail = NULL;
}

void SLinkedList::MergeLists(DSLinkedList DList, ISLinkedList IList){
    Link<DomesticStudent> * ds_head = DList.head;
    Link<InternationalStudent> * is_head = IList.head;

    while(ds_head != NULL){
        AddNode(ds_head->student);
        ds_head = ds_head->link;
    }
    while(is_head != NULL){
        AddNode(is_head->student);
        is_head = is_head->link;
    }
    
    

}