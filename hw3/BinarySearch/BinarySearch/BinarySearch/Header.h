#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool binarySearch(int const number, int size, int const * const array);
bool ifElementIsInArray(int const number, int const size, int const * const array);
void quickSort(int const size, int* array);
int arrayPartition(int const size, int* array);
int pivotIndex(int const first, int const last, int const * const array);
int middleOfThreeIndex(int const first, int const last, int const * const array);
int indexOfMaxOfTwo(int const index1, int const index2, int const * const array);
int indexOfMinOfTwo(int const index1, int const index2, int const * const array);
void insertionSort(int const size, int* array);
void siftLeft(int const position, int* array);
void swap(int & a, int & b);