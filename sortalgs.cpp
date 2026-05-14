#include "sortalgs.h"

void choice_sort(std::vector<Student>& a)
{
    for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
        if (arr[j] < arr[min_idx]) {
            min_idx = j;
        }
    }
    if (min_idx != i) {
        std::swap(arr[i], arr[min_idx]);
    }
}
}

void bubble_sort(std::vector<Student>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j + 1] < a[j]) {
                Student tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void shaker_sort(std::vector<Student>& a);