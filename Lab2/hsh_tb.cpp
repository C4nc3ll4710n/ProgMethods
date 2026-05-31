#include "Student.h"
#include "hsh_tb.h"

unsigned int hsh_fn(const char* s)
{
    unsigned int h = 0;
    unsigned int p = 1;
    while (*s)
    {
        h = h + (*s)*p;
        p = p*31;
        s++;
    }
    return h;
}

void HSH_TB_Delete (HashTable* t)
{
    for (unsigned int i = 0; i< t->size; i++)
    {
        HSH_TB_Node* tmp = t->cells[i];
        while (tmp != nullptr)
        {
            HSH_TB_Node* next = tmp -> nxt;
            delete tmp;
            tmp = next;
        }
    }
    delete [] t->cells; 
    delete t;
}


HashTable* hsh_tb_bld(const Student* a, int n)
{
    HashTable* t = new HashTable;
    t->size = get_prime(n);
    t->cells = new HSH_TB_Node*[t->size];
    t->colls = 0;

    for (int i = 0; i < t->size; i++)
        t->cells[i] = nullptr;
    
    for (int i= 0; i < n; i++)
    {
        unsigned int h = hsh_fn(a[i].name) % t->size;

        HSH_TB_Node* comp = t->cells[h];

        bool dup = false;
        bool empt = false;
        if (comp == nullptr)
            empt = true;
        while(comp != nullptr)
        {
            if (strcmp(comp->student->name, a[i].name) == 0)
            {
                dup = true;
                
                break;
            }
            comp = comp->nxt;

        }

        if (!empt && !dup)
        {
            t->colls++;
            //printf("коллизия %u: '%s'\n", a[i].name);
        }

        HSH_TB_Node* tmp = new HSH_TB_Node;
        tmp->student = &a[i];
        tmp->ind = i;
        tmp->nxt = t->cells[h];
        t->cells[h] = tmp;
    }

    return t;
}