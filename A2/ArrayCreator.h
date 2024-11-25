// ArrayCreator.h
#ifndef ARRAYCREATOR_H
#define ARRAYCREATOR_H

#include <vector>

class DataArrayGenerator {
public:
    static const int DEFAULT_MAX_SIZE = 10000;
    static const int DEFAULT_MIN_SIZE = 500;
    static const int DEFAULT_STEP = 100;
    static const int DEFAULT_MAX_VALUE = 6000;
    static const int DEFAULT_MIN_VALUE = 0;

    static std::vector<int> generate_random_array(int size);
    static std::vector<int> generate_reverse_sorted_array(int size);
    static std::vector<int> generate_sorted_array(int size);

private:
    static int generate_random_value(int lower_bound, int upper_bound, int step = 1);
};

#endif // ARRAYCREATOR_H
