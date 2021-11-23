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

DSLinkedList::DSLinkedList(){
    head = NULL;
    tail = NULL;
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
    set_tail<DSLinkedList, DomesticStudent>(this);
}

void ISLinkedList::AddNode(InternationalStudent x){
    push_node_to_list(this, x);
}
void ISLinkedList::ValidateT(){
    Link<InternationalStudent> * temp = head;
    int counter = 0;
    vector<int> indices;
    while(temp != NULL){
        if(!(temp->student.valid_toefl())){
            indices.push_back(counter);
        }
        temp = temp->link;
        counter ++;
    }
    for(auto i : indices){
        deleteNode<ISLinkedList, InternationalStudent>(*this, i);
    }
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
    
}

ISLinkedList::ISLinkedList(){
    head = NULL;
    tail = NULL;
}