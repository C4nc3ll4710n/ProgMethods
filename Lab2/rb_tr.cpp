#include "rb_tr.h"

RB_Node::RB_Node(const Student* s, int i)
{
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->ind = i;
    this->student = s;
    this->color = RED;
}

RB_Node* rb_left_rot(RB_Node* root, RB_Node* x)
{
    RB_Node* y = x->right;

    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;

    return root;
}

RB_Node* rb_right_rot(RB_Node* root, RB_Node* x)
{
    RB_Node* y = x->left;

    x->left = y->right;
    if (y->right != nullptr)
        y->right->parent = x;

    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;

    return root;
}

RB_Node* rb_fix(RB_Node* root, RB_Node* z)
{
    while (z->parent != nullptr && z->parent->color == RED)
    {
        RB_Node* p = z->parent;
        RB_Node* g = p->parent;

        if (p == g->left)
        {
            RB_Node* u = g->right;

            if (u != nullptr && u->color == RED)
            {
                u->color = BLK;
                g->color = RED;
                p->color = BLK;
                z = g;

            }
            else
            {
                if (z == p->right)
                {
                    z = p;
                    root = rb_left_rot(root, z);
                    p = z->parent;
                }
                
                p->color = BLK;
                g->color = RED;
                root = rb_right_rot(root, g);
            }       
        }
        else
        {
            RB_Node* u = g->left;

            if (u != nullptr && u->color == RED)
            {
                u->color = BLK;
                g->color = RED;
                p->color = BLK;
                z = g;

            }
            else
            {
                if (z == p->left)
                {
                    z = p;
                    root = rb_right_rot(root, z);
                    p = z->parent;
                }
                
                p->color = BLK;
                g->color = RED;
                root = rb_left_rot(root, g);
            }       
        }
    }

    root->color = BLK;
    return root;
}

RB_Node* rb_bld_hlpr(RB_Node* root, RB_Node* z)
{
    if (root == nullptr)
    {
        z->parent = nullptr;
        z->color = BLK;
        return z;
    }

    RB_Node* tmp1 = nullptr;
    RB_Node* tmp2 = root;

    while (tmp2 != nullptr)
    {
        int cmp = strcmp(tmp2->student->name, z->student->name);
        if (cmp>0)
        {
            tmp1 = tmp2;
            tmp2 = tmp2->left; 
        }
        else
        {
            tmp1 = tmp2;
            tmp2 = tmp2->right; 
        }
    }

    z->parent = tmp1;
    int cmp = strcmp(tmp1->student->name, z->student->name);
    if (cmp>0)
        tmp1->left = z;
    else
        tmp1->right = z;

    return rb_fix(root, z);
}

RB_Node* rb_bld(const Student* s, int n)
{
    RB_Node* root = nullptr;
    for (int i = 0; i<n; i++)
    {
        RB_Node* z = new RB_Node(&s[i], i);
        root = rb_bld_hlpr(root, z);
    }

    return root;
}



void rb_destroy(RB_Node* root)
{
    if (root == nullptr)
        return; 
    rb_destroy(root->left); 
    rb_destroy(root->right);
    delete root;
    
}