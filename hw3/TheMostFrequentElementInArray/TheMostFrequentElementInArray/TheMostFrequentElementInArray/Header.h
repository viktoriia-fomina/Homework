#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mostFrequentElement(int size, int* array);
void quickSort(int const size, int* array);
int arrayPartition(int const size, int* array);
int pivotIndex(int const first, int const last, int const * const array);
int middleOfThreeIndex(int const first, int const last, int const * const array);
int indexOfMaxOfTwo(int const index1, int const index2, int const * const array);
int indexOfMinOfTwo(int const index1, int const index2, int const * const array);
void insertionSort(int const size, int* array);
void siftLeft(int const position, int* array);
void swap(int & a, int & b);
void mostFrequentElementTests();