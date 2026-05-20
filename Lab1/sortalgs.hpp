#ifndef SORTS_H
#define SORTS_H

template<class T>
void choice_sort(T* a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int m = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[m]) {
                m = j;
            }
        }
        if (m != i) {
            T tmp = a[i];
            a[i] = a[m];
            a[m] = tmp;
        }
    }
}

template<class T>
void bubble_sort(T* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j + 1] < a[j]) {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

template<class T>
void shaker_sort(T* a, int n) {
    int left = 0;
    int right = n - 1;
    bool swapped = true;
    
    while (swapped) {
        swapped = false;
        for (int i = left; i<right; i++){
            if (a[i]>a[i+1]) {
                T tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                swapped = true;
            }
        }
        right--;
        if (!swapped) break;
        swapped = false;  
        for (int i = right; i>left; i--){
            if (a[i]<a[i-1]) {
                T tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                swapped = true;
            }
        }
        left++;
    }
}

#endif //SORTS_H