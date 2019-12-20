#include "singly_linked_list.h"
#include "student_struct.h"

Singly_linked_list::Singly_linked_list()
{
   head = NULL;
}

Singly_linked_list::Singly_linked_list(Student s)
{
   head = new Node;
   head->student = s;
   head->next = NULL;
}

Singly_linked_list::~Singly_linked_list()
{
   while(head != NULL)
   {
       Node *temp = head;
       head = head->next;
       delete(temp);
   }
}

void Singly_linked_list:: insert_first(Student s)
{
    
   Node *curr = new Node;
   curr->student = s;
   curr->next = head;
   head = curr;
}

void Singly_linked_list:: insert_after(Student prev_s, Student s)
{
   Node *node = new Node;
   node->student = s;
   node->next = NULL;

   Node *curr = head;
   Node *prev = head;
   while(curr != NULL)
   {
       if(curr->student == prev_s)
       {
           node->next = curr->next;
           curr->next = node;
           break;
       }
       prev = curr;
       curr = curr->next;
   }

   //prevStudent->next = node;
}

void Singly_linked_list:: remove_first()
{
   if(head != NULL)
   {
       Node *temp = head;
       head = head->next;
       delete(temp);
   }
}

void Singly_linked_list:: remove_after(Student prev_s)
{
   Node *curr = head;
   Node *prev = head;
   while(curr != NULL)
   {
       if(curr->student == prev_s)
       {
           if(prev != NULL){
               prev->next = curr->next;
            }else{
                head = curr->next;
                delete(curr->next);
                return;
            }
       }

       prev = curr;
       curr = curr->next;
   }
}

void Singly_linked_list:: print_list()
{
   Node *curr = head;
   if(curr == NULL)
       cout<<"Empty list"<<endl;
   else{
       while(curr != NULL)
       {
           curr->student.print();
           curr = curr->next;
       }
       cout<<endl;
   }
}

ostream& operator<<(ostream &out, Singly_linked_list &s)
{
   s.print_list();
   return out;
}

// Question 5:

void Sorted_Singly_linked_list:: insert_sort(Student s)
{
   Node *node = new Node;
   node->student = s; //student object
   node->next = NULL; //pointer student 

   Node *curr = head; //linked list pointer curr
   Node *prev = head; // linked list pointer prev
  
       while(curr != NULL)
       {
            if (curr->student.student_id > s.student_id && curr == head){
                insert_first(s);    
            }
            
            if (curr->student.student_id < s.student_id ){
                node->next = curr->next; //pointer of object
                curr->next = node; //pointer of curr linkedlist item
                if(curr->student.student_id > s.student_id){
                    break;
                }
            }
       
            if  (curr->next == NULL && curr->student.student_id < s.student_id){
                insert_after(curr->student, s);  
            }

       prev = curr; //move to next item
       curr = curr->next; //move to next item
       }
}

ostream& operator<<(ostream &out, Sorted_Singly_linked_list &s)
{
   s.print_list();
   return out;
}