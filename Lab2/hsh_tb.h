#ifndef HSH_TB_H 
#define HSH_TB_H

#include "hlpr.h"
#include "Student.h"

unsigned int hsh_fn(const char* s);

struct HSH_TB_Node {
    const Student* student;
    int ind;
    HSH_TB_Node* nxt;
};

struct HashTable {
    HSH_TB_Node** cells;
    unsigned int size;
    unsigned int colls;
};

void HSH_TB_Delete (HashTable* t);

HashTable* hsh_tb_bld(const Student* a, int n);


#endif //HSH_TB_H