#ifndef RB_TR_H
#define RB_TR_H

#include <vector>
#include <cstring>

#include "Student.h"

enum RB_Color { RED, BLK };

struct RB_Node {
    const Student* student;
    int ind;
    RB_Color color;
    RB_Node* left;
    RB_Node* right;
    RB_Node* parent;

    RB_Node(const Student* s, int i);
};

RB_Node* rb_left_rot(RB_Node* root, RB_Node* x);
RB_Node* rb_right_rot(RB_Node* root, RB_Node* x);

RB_Node* rb_fix(RB_Node* root, RB_Node* x);

RB_Node* rb_bld_hlpr(RB_Node* root, RB_Node* z);
RB_Node* rb_bld(const Student* a, int n);

void rb_destroy(RB_Node* root);

#endif //RB_TR_H