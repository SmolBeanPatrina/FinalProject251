#ifndef list_hpp

#include "student.hpp"

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
public:
    Link<DomesticStudent> *head, *tail;
    DSLinkedList();
    void AddNode(DomesticStudent x);
    void print();
};

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
                int province_compare = compareProvince(link1->student, link2->student);
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

#endif