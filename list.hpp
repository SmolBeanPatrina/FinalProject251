#ifndef list_hpp
#define list_hpp
#include <cmath>
#include "student.hpp"
#include <iostream>
#include <vector>

template <class type>
void SwapLinks(type &s1, type &s2)
{
    type temp_stu = s1;
    s1 = s2;
    s2 = temp_stu;
}

template <class type>
struct Link
{
    type student;
    Link<type> *link;
};

class DSLinkedList
{

    private:
    public:
        Link<DomesticStudent> *head, *tail;
        DSLinkedList();
        void Sort();
        void AddNode(DomesticStudent x);
        void print();
        void RemoveHead();
        void RemoveTail();
        template <class list_type, class type>
        friend void push_node_to_list(list_type list, type x);
};
class ISLinkedList
{

    private:
    public:
        Link<InternationalStudent> *head, *tail;
        ISLinkedList();
        void Sort();
        void ValidateT();
        void RemoveHead();
        void RemoveTail();
        void AddNode(InternationalStudent x);
        void print();
        template <class list_type, class type>
        friend void push_node_to_list(list_type list, type x);
};

template <class list_type, class link_type>
void set_tail(list_type * list){
    Link<link_type> * temp_link = list->head;
    if(temp_link->link == NULL){
        list->tail = list->head;
        return;
    }
    while(temp_link->link != NULL){
        temp_link = temp_link->link;
    }
    list->tail = temp_link;
}

template <class list_type, class type>
void push_node_to_list(list_type list, type x){
    x.set_cgpa(round((x.get_cgpa()*10))/10);
    Link<type> * new_link = new Link<type>;
    new_link->student = x;
    new_link->link = list->head;
    list->head = new_link;
}
template <class type>
type *MergeSorted(type *link1, type *link2, int mode)
{

    type *result = NULL;

    if (link1 == NULL)
    {
        return link2;
    }
    else if (link2 == NULL)
    {
        return link1;
    }

    if (mode == 1)
    {
        int research_compare = compareResearchScore(link1->student, link2->student);
        if (research_compare == 1)
        {
            result = link1;
            result->link = MergeSorted(link1->link, link2, 1);
        }
        else if (research_compare == -1)
        {
            result = link2;
            result->link = MergeSorted(link1, link2->link, 1);
        }
        else if (research_compare == 0)
        {
            int cgpa_compare = compareCGPA(link1->student, link2->student);
            if (cgpa_compare == 1)
            {
                result = link1;
                result->link = MergeSorted(link1->link, link2, 1);
            }
            else if (cgpa_compare == -1)
            {
                result = link2;
                result->link = MergeSorted(link1, link2->link, 1);
            }
            else if (cgpa_compare == 0)
            {
                int province_compare = compareLocation(link1->student, link2->student);
                if (province_compare < 0)
                {
                    result = link1;
                    result->link = MergeSorted(link1->link, link2, 1);
                }
                else if (province_compare > 0)
                {
                    result = link2;
                    result->link = MergeSorted(link1, link2->link, 1);
                }
            }
        }
    }
    return result;
}

template <class type>
void SplitList(type *root, type **front, type **back)
{

    type *ptr1;
    type *ptr2;
    ptr2 = root;
    ptr1 = root->link;

    while (ptr1 != NULL)
    {
        ptr1 = ptr1->link;
        if (ptr1 != NULL)
        {
            ptr2 = ptr2->link;
            ptr1 = ptr1->link;
        }
    }

    *front = root;
    *back = ptr2->link;
    ptr2->link = NULL;
}

template <class type>
void MergeSort(type **thead)
{
    type *head = *thead;
    type *ptr1;
    type *ptr2;

    if ((head == NULL) || (head->link == NULL))
    {
        return;
    }

    SplitList(head, &ptr1, &ptr2);

    MergeSort(&ptr1);
    MergeSort(&ptr2);

    *thead = MergeSorted(ptr1, ptr2, 1);
}

template<class list_type, class link_type>
int GetSize(list_type list){
    int counter = 0;
    Link<link_type> * temp = list.head;
    while(temp != NULL){
        counter ++;
        temp = temp->link;
    }

    return counter;
}

template <class list_type, class link_type>
void deleteNode(list_type & list, int position){ // VALIDATING TOEFL DOESN'T WORK WITH CURRENT METHOD
    int size = 0;
    int counter = 1;
    size = GetSize<list_type, link_type>(list) - 1;
    if(position == 0){
        list.RemoveHead();
        return;
    }
    if(position == size){
        list.RemoveTail();
    }
    if(size > 1 && position != size){
        Link<link_type> * node_to_delete = list.head->link;
        Link<link_type> * previous = list.head;
        while(node_to_delete != NULL){
            if(counter == position){
                break;
            }
            previous = node_to_delete;
            node_to_delete = node_to_delete->link;
            counter++;
        }

        previous->link = node_to_delete->link;
        free(node_to_delete);
    }


}


// template <class list_type, class link_type>
// void deleteNode(list_type list, int position)
// {
//     Link<link_type> *temp = list.head;
//     // If linked list is empty
//     if (list.head == NULL)
//     {
//         return;
//     }
//     // If head needs to be removed
//     if (position == 0)
//     {
//         // Change head
//         list.head = temp->link;
//         // Free old head
//         free(temp);
//         return;
//     }

//     // Find previous node of the node to be deleted
//     for (int i = 0; temp != NULL && i < position - 1; i++)
//     {
//         temp = temp->link;
//     }
//     // If position is more than number of nodes
//     if (temp == NULL || temp->link == NULL)
//     {
//         return;
//     }
//     // Node temp->next is the node to be deleted
//     // Store pointer to the next of node to be deleted
//     Link<link_type> *next = temp->link->link;

//     // Unlink the node from linked list
//     free(temp->link); // Free memory

//     // Unlink the deleted node from list
//     temp->link = next;
// }

template <class list_type, class link_type>
void SearchID(list_type list, int id)
{
    int counter = 0;
    Link<link_type> *temp_link = list.head;
    while (temp_link != NULL)
    {
        if (temp_link->student.get_appid() == id)
        {
            cout << temp_link->student;
            counter += 1;
        }
        temp_link = temp_link->link;
    }
    if (counter == 0)
    {
        cout << "\nNo matching students\n";
    }
}
template <class list_type, class link_type>
void SearchCGPA(list_type list, float cgpa)
{
    int counter = 0;
    Link<link_type> *temp_link = list.head;
    while (temp_link != NULL)
    {
        if (temp_link->student.get_cgpa() == cgpa)
        {
            cout << temp_link->student;
            counter += 1;
        }
        temp_link = temp_link->link;
    }
    if (counter == 0)
    {
        cout << "\nNo matching students\n";
    }
}
template <class list_type, class link_type>
void SearchScore(list_type list, float score)
{
    int counter = 0;
    Link<link_type> *temp_link = list.head;
    while (temp_link != NULL)
    {
        if (temp_link->student.get_res_score() == score)
        {
            cout << temp_link->student;
            counter += 1;
        }
        temp_link = temp_link->link;
    }
    if (counter == 0)
    {
        cout << "\nNo matching students\n";
    }
}
template <class list_type, class link_type>
void SearchName(list_type & list, string name, bool remove)
{
    int counter = 0;
    int index = 0;

    vector<int> to_remove;

    string lower_name = name;
    to_lowercase(lower_name);
    remove_space(lower_name);

    cout << endl << "Matching Students: ";

    Link<link_type> *temp_link = list.head;
    while (temp_link != NULL)
    {
        string stu_name = (temp_link->student.get_fname() + temp_link->student.get_lname());
        to_lowercase(stu_name);
        remove_space(stu_name);

        if (lower_name == stu_name)
        {
            cout << temp_link->student;

            to_remove.push_back(index);

            counter++;
        }
        index++;
        temp_link = temp_link->link;
    }
    if (counter == 0)
    {
        cout << "\nNo matching students\n";
    }
    if (remove)
    {
        for (auto x : to_remove)
        {
            deleteNode<list_type, link_type>(list, x);
        }
    }
}

#endif