#include "list.hpp"
#include <iostream>

DSLinkedList::DSLinkedList(){
    head = NULL;
    tail = NULL;
}

void DSLinkedList::print(){
    Link<DomesticStudent> * temp = head;

    while(temp != NULL){
        cout << temp->student;
        temp = temp->link;
    }

}

void DSLinkedList::AddNode(DomesticStudent x){
    Link<DomesticStudent> * tmp = new Link<DomesticStudent>;
    tmp->student = x;
    tmp->link = nullptr;
    if(head == NULL){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->link = tmp;
        tail = tail->link;
    }
}

