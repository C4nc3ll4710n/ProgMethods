#include "bin_tr.h"

Bin_Node::Bin_Node(const Student* s, int i)
{
    this->left = nullptr;
    this->right = nullptr;
    this->ind = i;
    this->student = s;
}

Bin_Node* bin_hlpr(Bin_Node* root, Bin_Node* z)
{
    if (root == nullptr)
        return z;

    Bin_Node* tmp1 = nullptr;
    Bin_Node* tmp2 = root;

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

    int cmp = strcmp(tmp1->student->name, z->student->name);
    if (cmp>0)
        tmp1->left = z;
    else
        tmp1->right = z;

    return root;
}

Bin_Node* bin_bld(const Student* s, int n)
{
    Bin_Node* root = nullptr;
    for (int i = 0; i<n; i++)
    {
        Bin_Node* z = new Bin_Node(&s[i], i);
        root = bin_hlpr(root, z);
    }

    return root;
}

void bin_destroy(Bin_Node* root)
{
    if (root == nullptr)
        return; 
    bin_destroy(root->left); 
    bin_destroy(root->right);
    delete root;
}