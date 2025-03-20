#pragma once
#include<iostream>
#include<array>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

#define SIZE 10
#define R_MAX 20


void BinarySort(std::array<int,SIZE>&);
void getRadomNumber(std::array<int, SIZE>&);
void Print(std::array<int, SIZE>&);
void ShellSort(std::array<int, SIZE>&);
void QuickSort(std::array<int, SIZE>&, int, int);
void MergeSort(std::array<int, SIZE>&, std::array<int, SIZE>&, int, int);
int maxArea(std::vector<int>& );

