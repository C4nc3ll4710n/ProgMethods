#include <algorithm>
#include <fstream>
#include <chrono>

#include "Student.h"
#include "sortalgs.hpp"

std::chrono::microseconds chrono_time (Student* studs, int n, void (*sort_func)(Student*, int))
{
    std::chrono::time_point<std::chrono::high_resolution_clock> st = std::chrono::high_resolution_clock::now();
    sort_func(studs, n);
    std::chrono::time_point<std::chrono::high_resolution_clock> stp = std::chrono::high_resolution_clock::now();

    std::chrono::microseconds sort_time = std::chrono::duration_cast<std::chrono::microseconds>(stp - st);

    return sort_time;
}

void norm_sort(Student* a, int n)
{
    std::sort(a, a + n);
}

int main() {

    FILE* f = fopen("students.csv", "r");

    size_t szs_l = 10;
    int szs[szs_l] = {10, 100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000};
    char buf[256];

    Student* full = new Student[100000];
    fgets(buf, sizeof(buf), f);
    for (int j = 0; j < 100000; j++) {
        fgets(buf, sizeof(buf), f);
        full[j] = Student(buf);
    }

    FILE* tf = fopen("timings.csv", "w");
    fprintf(tf, "n,choice,bubble,shaker,std\n");

    for (size_t i = 0; i < szs_l; i++)
    {
        rewind(f);
        Student* studs = new Student[szs[i]];
        Student* chc_studs = new Student[szs[i]];
        Student* shk_studs = new Student[szs[i]];
        Student* bub_studs = new Student[szs[i]];
        if (f == nullptr) { printf("csv пуст\n"); return 1;}
        
        for (int j=0; j<szs[i]; j++)
        {
            chc_studs[j] = full[j];
            bub_studs[j] = full[j];
            shk_studs[j] = full[j];
            studs[j]     = full[j];
        }

        std::chrono::microseconds chc_time, bub_time, cshk_time, sort_time;

        chc_time = chrono_time(chc_studs, szs[i], choice_sort);
        bub_time = chrono_time(bub_studs, szs[i], bubble_sort);
        cshk_time = chrono_time(shk_studs, szs[i], shaker_sort);
        sort_time = chrono_time(studs, szs[i], norm_sort);

        
        fprintf(tf, "%d,%lld,%lld,%lld,%lld\n",
            szs[i],
            (long long)chc_time.count(),
            (long long)bub_time.count(),
            (long long)cshk_time.count(),
            (long long)sort_time.count());
        fflush(tf);

        if (i == 9) {
            FILE* out = fopen("students_sorted.csv", "w");
            fprintf(out, "name,faculty,group,gpa\n");
            for (int j = 0; j < szs[i]; j++) {
                fprintf(out, "%s,%s,%d,%.2f\n",
                        studs[j].name, studs[j].faculty, studs[j].group, studs[j].gpa);
            }
            fclose(out);
        }

        delete[] chc_studs; delete[] bub_studs; delete[] shk_studs; delete[] studs;
    }

    delete[] full;
    fclose(f);
    fclose(tf);
    
}