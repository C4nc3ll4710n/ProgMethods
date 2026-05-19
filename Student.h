#ifndef STUDENT_H
#define STUDENT_H
#include <string>

#include "hlpr.h"

struct Student {
    char*  name;
    char*  faculty;
    int    group;
    double gpa;

    Student();
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator<=(const Student& other) const;
    bool operator>=(const Student& other) const;
};

#endif //Student_h