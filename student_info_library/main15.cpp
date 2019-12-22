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
   Sorted_Singly_linked_list list;

   // if file can be opened
   if(fin.is_open())
   {   
        fin>>student_id>>gpa>>major>>record_status;
        Student student4(student_id,gpa,major,record_status);
        list.insert_first(student4);

       // read till the end of file
       while(!fin.eof())
       {
            fin>>student_id>>gpa>>major>>record_status;
            Student student2(student_id,gpa,major,record_status);
            list.insert_sort(student2);
       }
       fin.close();
       cout << list;
       
   }else
       cout<<"Unable to open file"<<endl;


   return 0;
}