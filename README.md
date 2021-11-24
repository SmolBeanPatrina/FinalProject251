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
- Searching
  - searching can be done using 3 different templates
  - the basic format is as follows: `SearchMethod<ListType, LinkType>(list, parameter)` where `SearchMethod` should be replaced with one of the Search functions `SearchID`, `SearchCGPA`, `SearchScore`, or `SearchName` and `parameter` should be replaced with the value you want. 
  - `SearchName` takes another argument: `SearchName<ListType, LinkType>(list, parameter, remove)` where remove is a bool, that when true will delete the found students
- Creating a merged list
  - simply call the `SLinkedList` constructor which will automatically make the new SLinkedList a sorted and merged version of a `DSLinkedList` and a `ISLinkedList`.
  - eg  `SLinkedList students(domestic_students, international_students`

## Left To Do

- filtering and printing for the Student list, although will be very similar to previous functions
- error checking  -> lots to do
- unit test
- innovation marks
- slides  -> should probably start before
  


