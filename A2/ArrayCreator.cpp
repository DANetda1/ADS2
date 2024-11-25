// ArrayCreator.cpp
#include "ArrayCreator.h"
#include <algorithm>
#include <random>

std::vector<int> DataArrayGenerator::generate_random_array(int size) {
    std::vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        array[i] = generate_random_value(DEFAULT_MIN_VALUE, DEFAULT_MAX_VALUE);
    }
    return array;
}

std::vector<int> DataArrayGenerator::generate_reverse_sorted_array(int size) {
    std::vector<int> array = generate_random_array(size);
    std::sort(array.rbegin(), array.rend());
    return array;
}

std::vector<int> DataArrayGenerator::generate_sorted_array(int size) {
    std::vector<int> array = generate_random_array(size);
    std::sort(array.begin(), array.end());
    int swaps_count = generate_random_value(size / 200, size / 100);
    for (int i = 0; i < swaps_count; ++i) {
        int idx1 = generate_random_value(0, size - 1);
        int idx2 = generate_random_value(0, size - 1);
        std::swap(array[idx1], array[idx2]);
    }
    return array;
}

int DataArrayGenerator::generate_random_value(int lower_bound, int upper_bound, int step) {
    static std::random_device random_device;
    static std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(lower_bound, upper_bound);
    return (distribution(generator) / step) * step;
}
