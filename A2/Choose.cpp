// Choose.cpp
#include "Choose.h"
#include "ArrayCreator.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>

// Объявите функции сортировки
void merge_segments(int left, int right, std::vector<int>& data);
void simple_insertion_sort(int left, int right, std::vector<int>& data);
void hybrid_sort(int left, int right, std::vector<int>& data, int threshold);
void standard_merge_sort(int left, int right, std::vector<int>& data);

// Реализация метода класса SortingPerformanceTester
void SortingPerformanceTester::execute_tests(const std::string& output_file) {
    std::ofstream csv_file(output_file);
    csv_file << "size;array_type;threshold;time_ms\n";
    std::vector<int> thresholds{0, 5, 10, 20, 30, 50};
    std::vector<std::string> array_types{"random", "reversed", "sorted"};

    for (int threshold : thresholds) {
        for (size_t type_index = 0; type_index < array_types.size(); ++type_index) {
            for (int array_size = DataArrayGenerator::DEFAULT_MIN_SIZE;
                 array_size <= DataArrayGenerator::DEFAULT_MAX_SIZE;
                 array_size += 100) {

                // Генерация массива в зависимости от типа
                std::vector<int> test_array;
                switch (type_index) {
                    case 0:
                        test_array = DataArrayGenerator::generate_random_array(array_size);
                        break;
                    case 1:
                        test_array = DataArrayGenerator::generate_reverse_sorted_array(array_size);
                        break;
                    case 2:
                        test_array = DataArrayGenerator::generate_sorted_array(array_size);
                        break;
                    default:
                        test_array = DataArrayGenerator::generate_random_array(array_size);
                }

                // Копия массива для сортировки
                std::vector<int> sortable_array = test_array;

                // Измерение времени сортировки
                auto start_time = std::chrono::high_resolution_clock::now();
                hybrid_sort(0, sortable_array.size(), sortable_array, threshold);
                auto end_time = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed_time = end_time - start_time;

                // Запись результатов в CSV
                csv_file << array_size << ";\"" << array_types[type_index] << "\";"
                         << threshold << ";" << elapsed_time.count() << "\n";
            }
        }
    }
}
