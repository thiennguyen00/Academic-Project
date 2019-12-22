#include <iostream>
#include <fstream>
#include "singly_linked_list.h"
using namespace std;


int main() {

   string filename= "students.txt"; // provide full path to file
   ifstream fin(filename); // open the file
   int student_id, record_status;
   double gpa;
   string major;
   Singly_linked_list list;

   // if file can be opened
   if(fin.is_open())
   {   
       fin>>student_id>>gpa>>major>>record_status;
        Student student1(student_id,gpa,major,record_status);
        list.insert_first(student1);
        cout <<"Student 1: \n" << list;

        fin>>student_id>>gpa>>major>>record_status;
        Student student3(student_id,gpa,major,record_status);
        list.insert_first(student3);
        cout <<"Student 3 and student 1: \n" << list;
       

        // read till the end of file
       while(!fin.eof())
       {
            fin>>student_id>>gpa>>major>>record_status;
            Student student2(student_id,gpa,major,record_status);
            list.insert_first(student2);
       }
       fin.close();
       
       cout << "List of students is: \n";
       list.print_list();

       cout << "Adding student 3 to the first of the list: " << endl;
       list.insert_first(student3);
       cout << list;

       cout << "Removing the student after student 3 from the list: \n" << endl;
       list.remove_after(student3); 
       cout << list;
       
       cout << "Removing the first student: \n";
       list.remove_first(); 
       list.print_list();
        
       cout << "Inserting student 3 after student 1: \n";
       list.insert_after(student1, student3 );
       cout << list;
       
   }else
       cout<<"Invalid file"<<endl;


   return 0;
}