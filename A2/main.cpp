// Main.cpp
#include "Choose.h"
#include "Sorts.h"
#include <algorithm>
#include <iostream>
#include <vector>

// Реализации функций сортировки
void merge_segments(int left, int right, std::vector<int>& data) {
    int middle = (left + right) / 2;
    int size1 = middle - left;
    int size2 = right - middle;
    std::vector<int> temp1(size1), temp2(size2);

    for (int i = 0; i < size1; ++i)
        temp1[i] = data[left + i];
    for (int j = 0; j < size2; ++j)
        temp2[j] = data[middle + j];

    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (temp1[i] <= temp2[j]) {
            data[k] = temp1[i];
            ++i;
        } else {
            data[k] = temp2[j];
            ++j;
        }
        ++k;
    }
    while (i < size1) {
        data[k] = temp1[i];
        ++i;
        ++k;
    }
    while (j < size2) {
        data[k] = temp2[j];
        ++j;
        ++k;
    }
}

void simple_insertion_sort(int left, int right, std::vector<int>& data) {
    for (int i = left + 1; i < right; ++i) {
        int current = data[i];
        int j = i - 1;
        while (j >= left && data[j] > current) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = current;
    }
}

void hybrid_sort(int left, int right, std::vector<int>& data, int threshold) {
    if (left + 1 >= right) {
        return;
    }
    if ((right - left) <= threshold) {
        simple_insertion_sort(left, right, data);
        return;
    }
    int middle = (left + right) / 2;
    hybrid_sort(left, middle, data, threshold);
    hybrid_sort(middle, right, data, threshold);
    merge_segments(left, right, data);
}

void standard_merge_sort(int left, int right, std::vector<int>& data) {
    if (left + 1 >= right) {
        return;
    }
    int middle = (left + right) / 2;
    standard_merge_sort(left, middle, data);
    standard_merge_sort(middle, right, data);
    merge_segments(left, right, data);
}

int main() {
    SortingPerformanceTester tester{};
    tester.execute_tests("sorting_results.csv");
    return 0;
}
