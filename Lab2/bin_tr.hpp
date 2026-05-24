#ifndef BN_TR_H
#define BN_TR_H

#include "Student.h"

struct BT_Node {
    const Student* student;
    int ind;
    BT_Node* left;
    BT_Node* right;
};

#endif //BN_TR_H