# FinalProject251

## How to use the main functions

**Universal Functions for the Lists**

- Constructor:
  - only the default consturctors `DSLinkedList`, `ISLinkedList`, `SLinkedList` which sets the head and tail of the list to NULL
- Adding Nodes: 
  - using the member function `AddNode` students can be added to a linked list eg. if `domestic_students` is a 
  list of students then `domestic_students.AddNode(student)` will push `student` to the top of the list
- Sorting:
  - by using the `Sort` member function the lists can be sorted (only for `DSLinkedList` and `ISLinkedList` since `SLinkedList` is sorted when they're made)  used like `domestic_students.Sort()`
- Deleting
  - currently, deleting only works by index by calling the `deleteNode` template function, which is used like
    `deleteNode<ListType, LinkType>(list, index)` where `ListType` can be any of the list types above (eg.            DSLinkedList), LinkType is the related student to the list (eg. when deleting from a DSLinkedList, LinkType is    `DomesticStudent`), `list` is the linked list you'd like to delete from, and `index` is which node you'd like      to delete
  - deleting can also be done through the `SearchName` function
Searching
  


