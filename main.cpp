// Sort Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "./include/main.h"
using namespace std;

void swap(int *x, int *y)
{
    if (*x == *y)
        return;
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int intArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << intArray[i] << "\t";
    }

    std::cout << std::endl;
}

void BubbleSort(int intArray[], int n)
{
    for (int firstUnsortedIndex = 0; firstUnsortedIndex < n - 1; firstUnsortedIndex++)
        for (int i = firstUnsortedIndex + 1; i < n; i++)
        {
            if (intArray[firstUnsortedIndex] > intArray[i])
                swap(&intArray[firstUnsortedIndex], &intArray[i]);
        }
}

void SelectionSort(int intArray[], int n)
{

    for (int lastUnsortedIndex = n - 1; lastUnsortedIndex > 0; lastUnsortedIndex--)
    {
        int largest = 0;

        for (int i = 1; i <= lastUnsortedIndex; i++)
            if (intArray[i] > intArray[largest])
                largest = i;

        swap(&intArray[largest], &intArray[lastUnsortedIndex]);
    }
}

void InsertionSort(int intArray[], int n)
{

    for (int firstUnsortedIndex = 1; firstUnsortedIndex < n; firstUnsortedIndex++)
    {

        int newElement = intArray[firstUnsortedIndex];
        int i;
        for (i = firstUnsortedIndex; i > 0 && intArray[i - 1] > newElement; i--)
        {
            intArray[i] = intArray[i - 1];
        }

        intArray[i] = newElement;
    }
}

void ShellSort(int intArray[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int newElement = intArray[i];

            int j = i;

            while (j >= gap && intArray[j - gap] > newElement)
            {
                intArray[j] = intArray[j - gap];
                j -= gap;
            }

            intArray[j] = newElement;
        }
    }
}

// void merge(int inputArray[], int start, int mid, int end)
// {
//     if (inputArray[mid - 1] <= inputArray[mid])
//     {
//         return;
//     }

//     int i = start;
//     int j = mid;
//     int tempIndex = 0;

//     //const int *temp = new int[end - start]
//     //int temp[] = new int[end - start]
// }

// void MergeSort(int inputArray[], int start, int end)
// {
//     if (end - start < 2)
//     {
//         return;
//     }

//     int mid = (start + end) / 2;
//     MergeSort(inputArray, start, mid);
//     MergeSort(inputArray, mid, end);
//     merge(inputArray, start, mid, end);
// }

int main()
{
    int intArray[] = {9, -7, 45, 10, -15, 23, -56};
    int n = std::end(intArray) - std::begin(intArray);
    std::cout << "Array length: " << n << std::endl;

    ShellSort(intArray, n);

    std::cout << "Array sorted by Shell sort:\t";
    printArray(intArray, n);
}
