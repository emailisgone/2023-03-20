#ifndef SORTING2_H
#define SORTING2_H

#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <vector>
#include <chrono>

#define DATA_SAMPLE 100

// O(n^2), etc.
void shuffleArray(std::vector<int>& array);
void bubbleSort(std::vector<int>& array, std::chrono::nanoseconds& duration);
void cocktailShakerSort(std::vector<int>& array, std::chrono::nanoseconds& duration);
int getNextGap(int gap);
void combSort(std::vector<int>& array, std::chrono::nanoseconds& duration);
void selectionSort(std::vector<int>& array, std::chrono::nanoseconds& duration);
void insertionSort(std::vector<int>& array, std::chrono::nanoseconds& duration);
void gnomeSort(std::vector<int>& array, std::chrono::nanoseconds& duration);
void shellSort(std::vector<int>& array, std::chrono::nanoseconds& duration);

// O(log n) / O(n*log n) / etc.
int qSPartition(std::vector<int>& array, int left, int right);
void quickSort(std::vector<int>& array, int left, int right, std::chrono::nanoseconds& duration);
struct Node;
struct Node *newNode(int item);
void storeSorted(Node *root, std::vector<int>& array, int& i);
Node* insert(Node* node, int key);
void treeSort(std::vector<int>& array, std::chrono::nanoseconds& duration);
void merge(std::vector<int>& array, int p, int q, int r);
void mergeSort(std::vector<int>& array, int left, int right, std::chrono::nanoseconds& duration);
void heapSort(std::vector<int>& array, std::chrono::nanoseconds& duration);
void strandSort(std::vector<int>& array, std::chrono::nanoseconds& duration);

#endif