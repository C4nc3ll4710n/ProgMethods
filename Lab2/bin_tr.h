#ifndef BIN_TR_H
#define BIN_TR_H

#include <vector>
#include <cstring>

#include "Student.h"

struct Bin_Node {
    const Student* student;
    int ind;
    Bin_Node* left;
    Bin_Node* right;

    Bin_Node(const Student* s, int i);
};

Bin_Node* bin_hlpr(Bin_Node* root, Bin_Node* z);
Bin_Node* bin_bld(const Student* s, int n);

void bin_destroy(Bin_Node* root);

#endif //BIN_TR_H