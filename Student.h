#ifndef STUDENT_H
#define STUDENT_H
#include <string>

struct Student {
    std::string name;
    std::string faculty;
    int group = 0;
    double gpa = 0.0;

    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator<=(const Student& other) const;
    bool operator>=(const Student& other) const;
};

#endif //Student_h