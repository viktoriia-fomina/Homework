#pragma once
#include <fstream>

bool readMatrixFromFile(std::ifstream & file, int** matrix, int N);
int readNumberFromFile(std::ifstream & file);
int** createMatrix(int number);
bool transitiveClosure(int** matrix, int** matrixToWrite, int N, std::ofstream & fileToWrite);