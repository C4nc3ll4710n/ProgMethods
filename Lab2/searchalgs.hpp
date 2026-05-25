#ifndef SRC_AL_H 
#define SRC_AL_H

#include <vector>

std::vector<int> lin_srch(const Student* a, int n, const char* key)
{
    std::vector<int> mtchs = {};
    for (int i = 0; i<n; i++){
        if (strcmp(a[i].name, key) == 0)
            mtchs.push_back(i);
    }
    return mtchs;
}


//std::vector<int> bt_srch(const BT_Node* root, const char* key);


//std::vector<int> rb_srch(const RB_Node* a, int n, const char* key);


std::vector<int> hsh_tb_srch(const HashTable* t, const char* key)
{
    std::vector<int> v;
    unsigned int h = hsh_fn(key)%t->size;
    HSH_TB_Node* tmp = t->cells[h];
    while (tmp != nullptr)
    {
        if(strcmp(tmp->student->name, key) == 0)
            v.push_back(tmp->ind);
        tmp = tmp->nxt;
    }

    return v;
}

#endif //SRC_AL_H