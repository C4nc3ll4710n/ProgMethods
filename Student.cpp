#include "Student.h"

Student::Student()
{
    name    = nullptr;
    faculty = nullptr;
    group   = 0;
    gpa     = 0.0;
}
    
Student::Student(const Student& other)
{
    name    = cp_str(other.name);
    faculty = cp_str(other.faculty);
    group   = other.group;
    gpa     = other.gpa;
}

Student::Student(char* csv_st)
{
    //Imixerob Obaryzute,Reverse,227,5.21
    name    = cp_str(strtok(csv_st, ","));
    faculty = cp_str(strtok(NULL, ","));
    group   = atoi(strtok(NULL, ","));
    gpa     = atof(strtok(NULL, ","));
}
    
Student& Student::operator=(const Student& other)
{
    if (this == &other) return *this;

    delete[] name;
    delete[] faculty;
    name    = cp_str(other.name);
    faculty = cp_str(other.faculty);
    group   = other.group;
    gpa     = other.gpa;
    return *this;
}

    
Student::~Student() {
    delete[] name;
    delete[] faculty;
}

bool Student::operator<(const Student& other) const
{
    if (gpa - other.gpa > 1e-9 || other.gpa - gpa > 1e-9)
        return gpa < other.gpa;
    else if (strcmp(name, other.name) != 0)
        return strcmp(name, other.name) < 0;
    else
        return strcmp(faculty, other.faculty) < 0;
}

bool Student::operator<=(const Student& other) const
{
    return !(*this > other);
}

bool Student::operator>(const Student& other) const
{
    return (other < *this);
}

bool Student::operator>=(const Student& other) const
{
    return !(other < *this);
}