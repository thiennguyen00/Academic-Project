#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

#include "student_struct.h"


class Singly_linked_list{
protected:
   struct Node
   {
       Student student;
       Node *next;
   };

   Node *head;

public:
   Singly_linked_list();
   Singly_linked_list(Student s);
   ~Singly_linked_list();
   void insert_first(Student s);
   void insert_after(Student prev, Student s);
   void remove_first();
   void remove_after(Student prev);
   void print_list();

};

ostream& operator<<(ostream &out, Singly_linked_list &s);

//Quesiton 5:
class Sorted_Singly_linked_list: public Singly_linked_list {
public:
    void insert_sort(Student s);
};

ostream& operator<<(ostream &out, Sorted_Singly_linked_list &s);


#endif