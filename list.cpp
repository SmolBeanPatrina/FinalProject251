#include "list.hpp"
#include <iostream>
#include <cmath>

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

    x.set_cgpa(round((x.get_cgpa()*10))/10);
    Link<DomesticStudent> * new_link = new Link<DomesticStudent>;
    new_link->student = x;
    new_link->link = head;
    head = new_link;
}

