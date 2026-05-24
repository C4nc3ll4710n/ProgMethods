#ifndef HSH_TB_H
#define HSH_TB_H

#include "Student.h"

unsigned long long hsh_fn(const char* s)
{
    unsigned int h = 0;
    unsigned int p = 1;
    while (*s)
    {
        h = h + (*s)*p;
        p = p*31;
    }
    return h;
}

struct HSH_TB_Node {
    const Student* student;
    int ind;
    HSH_TB_Node nxt;
};

struct HashTable {
    HSH_TB_Node** cells;
    int size;
    int colls;
};


#endif //HSH_TB_H