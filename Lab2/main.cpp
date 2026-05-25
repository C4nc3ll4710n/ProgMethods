#include "hlpr.h"
#include "hsh_tb.h"
#include "bin_tr.hpp"
#include "Student.h"
#include "searchalgs.hpp"

int main()
{
    FILE* f = fopen("students.csv", "r");

    char buf[256];

    int sz = 1000000;

    Student* full = new Student[sz];

    fgets(buf, sizeof(buf), f);
    for (int j = 0; j < sz; j++) {
        fgets(buf, sizeof(buf), f);
        full[j] = Student(buf);
    }

    std::vector<int> lin_v = lin_srch(full, sz, "Osu Ugi");

    HashTable* h = hsh_tb_bld(full, sz);
    std::vector<int> hsh_v = hsh_tb_srch(h, "Osu Ugi");


    printf("lin found: %zu\n", lin_v.size());
    printf("hsh found: %zu\n", hsh_v.size());
    
    
    HSH_TB_Delete(h);
    delete[] full;
    fclose(f);

    return 0;
}