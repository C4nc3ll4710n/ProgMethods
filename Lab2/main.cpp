#include "hlpr.h"
#include "hsh_tb.h"
#include "Student.h"
#include "rb_tr.h"
#include "bin_tr.h"
#include "searchalgs.hpp"

#include <chrono>
#include <map>
#include <string>

int main()
{
    FILE* f = fopen("students.csv", "r");

    char buf[256];
    int K = 10000;

    int sz = 0;
    int szs[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 200000, 500000, 1000000};
    
    std::chrono::time_point<std::chrono::high_resolution_clock> t1, t2;
    long long lin_ns, hsh_ns, rb_ns, bn_ns;


    for (int k = 0; k<10; k++)
    {
        sz = szs[k];
        Student* full = new Student[sz];

        fgets(buf, sizeof(buf), f);
        for (int j = 0; j < sz; j++) {
            fgets(buf, sizeof(buf), f);
            full[j] = Student(buf);
        }
        const char* key = full[0].name;

        std::vector<int> lin_v = lin_srch(full, sz, key);

        t1 = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < K; r++)
            lin_srch(full, sz, key);
        t2 = std::chrono::high_resolution_clock::now();
        lin_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / K;

        HashTable* h = hsh_tb_bld(full, sz);
        std::vector<int> hsh_v = hsh_tb_srch(h, key);

        t1 = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < K; r++)
            hsh_tb_srch(h, key);
        t2 = std::chrono::high_resolution_clock::now();
        hsh_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / K;

        RB_Node* root = rb_bld(full, sz);
        std::vector<int> rb_v = rb_srch(root, key);

        t1 = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < K; r++)
            rb_srch(root, key);
        t2 = std::chrono::high_resolution_clock::now();
        rb_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / K;

        Bin_Node* broot = bin_bld(full, sz);
        std::vector<int> bn_v = bt_srch(broot, key);

        t1 = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < K; r++)
            bt_srch(broot, key);
        t2 = std::chrono::high_resolution_clock::now();
        bn_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / K;

        printf("lin found: %zu\n", lin_v.size());
        printf("hsh found: %zu\n", hsh_v.size());
        printf("rbt found: %zu\n", rb_v.size());
        printf("bnt found: %zu\n", bn_v.size());

        printf("%d lin=%lld hsh=%lld rb=%lld bn=%lld\n", sz, lin_ns, hsh_ns, rb_ns, bn_ns);

        HSH_TB_Delete(h);
        rb_destroy(root);
        bin_destroy(broot);
        delete[] full;

        rewind(f);
    }
    
    fclose(f);

    return 0;
}