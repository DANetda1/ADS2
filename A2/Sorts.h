// Sorts.h
#ifndef SORTS_H
#define SORTS_H

#include <vector>

void merge_segments(int left, int right, std::vector<int>& data);
void simple_insertion_sort(int left, int right, std::vector<int>& data);
void hybrid_sort(int left, int right, std::vector<int>& data, int threshold);
void standard_merge_sort(int left, int right, std::vector<int>& data);

#endif // SORTS_H
