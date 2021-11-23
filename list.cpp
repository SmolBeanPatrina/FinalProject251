#include "list.hpp"
#include <iostream>


DSLinkedList::DSLinkedList(){
    head = NULL;
    tail = NULL;
}
void DSLinkedList::Sort(){
    MergeSort(&(head));
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
}

void ISLinkedList::AddNode(InternationalStudent x){
    push_node_to_list(this, x);
}
void ISLinkedList::print(){
    Link<InternationalStudent> * temp = head;
    while(temp != NULL){
        cout << temp->student;
        temp = temp->link;
    }
}
ISLinkedList::ISLinkedList(){
    head = NULL;
    tail = NULL;
}