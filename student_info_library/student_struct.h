#ifndef STUDENT_STRUCT_H_
#define STUDENT_STRUCT_H_

#include <iostream>

using namespace std;

struct Student{
protected:   
    double gpa;
    string major;
    bool record_status;

public:
    int student_id;
    Student();
    Student(int, double, string);
    Student(int, double, string, int);
    bool operator == (Student const &);
    void print();
};

#endif