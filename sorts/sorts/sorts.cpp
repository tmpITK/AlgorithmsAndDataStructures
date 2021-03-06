// sorts.cpp : This file contains the 'main' function. Program execution begins and ends there.
///thanks for the video lecture for Rob Edward from SDSU

#include "pch.h"
#include <iostream>
#include <array>
#include <cassert>
#include <algorithm>
#include "QuickSort.h"
#include "MergeSort.h"

void const printArray(const std::array<int, 10> &arr) {
	for (int elem : arr) {
		std::cout << elem << " ";
	}std::cout << std::endl;
}

void insertionSort(std::array<int, 10> arr) {
	for (int i = 1; i < 10; i++) {
		int j, v = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] <= v) {
				break;
			}
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = v;
	}
	std::cout << "Insertion sorted: ";
	printArray(arr);
}

void shellSort(std::array<int, 10> arr) {
	for (int gap = 5; gap > 0; gap /= 2) {
		for (int i = gap; i < 10; i++) {
			int j, v = arr[i];
			for (j = i; j >= gap; j -= gap) {
				if (arr[j-gap] > v) {
					arr[j] = arr[j-gap];
				}
				else {
					break;
				}
			}
			arr[j] = v;
		}	
	}
	std::cout << "Shell sorted: ";
	printArray(arr);
}

void bubbleSort(std::array<int, 10> arr) {
	for (int i = 1; i < 10; i++) {
		bool swapped = false;
		for (int j = 0; j < 10 - i; j++) {
			if (arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			std::cout << "Early break at iteration " << i  << std::endl;
			break;
		}
	}
	std::cout << "Bubble sorted: ";
	printArray(arr);
}

void testQuickSort() {
	int arr[]{8,3,5,1,0,6,7,9,2,4};
	int size = sizeof(arr) / sizeof(arr[0]);

	QuickSort q;
	q.sort(arr, size);
	std::cout << q << std::endl;

	int arr2[]{3,4,5,2,1};
	q.sort(arr2, 5);
	std::cout << q << std::endl;
}


int main()
{
	
	testQuickSort();
	std::array<int, 10> arr{8,3,5,1,0,6,7,9,2,4};
	std::cout << "Original: ";
	printArray(arr);
	insertionSort(arr);
	shellSort(arr);
	bubbleSort(arr);
	int *array = new int[10] {8, 3, 5, 1, 0, 6, 7, 9, 2, 4};
	MergeSort m(array, 10);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
