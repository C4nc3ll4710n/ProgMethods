#include "Student.h"
#include <string.h>
#include <math.h>

bool Student::operator<(const Student& other) const {
    if (fabs(gpa - other.gpa) > 1e-9) {
        return gpa > other.gpa;
    }
    int name_cmp = strcmp(name, other.name);
    if (name_cmp != 0) {
        return name_cmp < 0;
    }
    return strcmp(faculty, other.faculty) < 0;
}

bool Student::operator>(const Student& other) const {
    return other < *this;
}

bool Student::operator<=(const Student& other) const {
    return !(other < *this);
}

bool Student::operator>=(const Student& other) const {
    return !(*this < other);
}