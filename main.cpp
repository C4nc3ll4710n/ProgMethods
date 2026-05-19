#include <algorithm>
#include <fstream>
#include <iostream>
#include <chrono>

#include "Student.h"
#include "sortalgs.hpp"

using namespace std;

std::chrono::microseconds chrono_time (Student* studs, int n, void (*sort_func)(Student*, int))
{
    std::chrono::time_point<std::chrono::high_resolution_clock> st = std::chrono::high_resolution_clock::now();
    choice_sort(studs, n);
    std::chrono::time_point<std::chrono::high_resolution_clock> stp = std::chrono::high_resolution_clock::now();

    std::chrono::microseconds sort_time = std::chrono::duration_cast<std::chrono::microseconds>(st - stp);

    return sort_time;
}

void norm_sort(Student* a, int n)
{
    std::sort(a, a + n);
}

int main() {

    FILE* f = fopen("students.csv", "r");

    int szs[10] = {100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 75000, 100000};
    char buf[256];

    for (size_t i = 0; i < 10; i++)
    {
        rewind(f);
        Student* studs = new Student[szs[i]];
        Student* chc_studs = new Student[szs[i]];
        Student* shk_studs = new Student[szs[i]];
        Student* bub_studs = new Student[szs[i]];
        if (f == nullptr) { printf("csv пуст\n"); return 1;}
        
        fgets(buf, sizeof(buf), f); 
        for (int j=0; j<szs[i]; j++)
        {
            if (fgets(buf, sizeof(buf), f) == nullptr) { printf("как так???\n"); return 1;}
            studs[j] = Student(buf);
            chc_studs[j] = Student(buf);
            shk_studs[j] = Student(buf);
            bub_studs[j] = Student(buf);
        }

        std::chrono::microseconds chc_time, bub_time, cshk_time, sort_time;

        chc_time = chrono_time(chc_studs, szs[i], choice_sort);
        bub_time = chrono_time(bub_studs, szs[i], bubble_sort);
        cshk_time = chrono_time(shk_studs, szs[i], shaker_sort);
        sort_time = chrono_time(studs, szs[i], norm_sort);
    }
    
}