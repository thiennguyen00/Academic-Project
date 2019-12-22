#include "student_struct.h"

Student::Student() {}

Student::Student(int new_student_id, double new_gpa, string new_major) {
    this->student_id = new_student_id;
    this->gpa = new_gpa;
    this->major = new_major;
    record_status = false;
}

Student::Student(int new_student_id, double new_gpa, string new_major, int new_record_status) {
    this->student_id = new_student_id;
    this->gpa = new_gpa;
    this->major = new_major;
    this->record_status = new_record_status;
}

bool Student::operator==(const Student &st) {
    return(student_id == st.student_id && gpa == st.gpa && (major.compare(st.major) ==0) && record_status == st.record_status);
}

void Student::print() {
    cout << "Student ID: " << this->student_id << ", Student GPA: " << this->gpa << ", Student Major: " << this->major << ", Student Record Status: " << this->record_status << endl;
}