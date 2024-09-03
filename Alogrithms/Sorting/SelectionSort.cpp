//Time Complexity: The time complexity of Selection Sort is O(N2)

/*Advantages of Selection Sort Algorithm:
    Simple and easy to understand.
    Works well with small datasets.

Disadvantages of the Selection Sort Algorithm
    Selection sort has a time complexity of O(n^2) in the worst and average case.
    Does not work well on large datasets.
    Does not preserve the relative order of items with equal keys which means it is not stable.*/
/*

Applications of Selection Sort Algorithm
    Mainly works as a basis for some more efficient algorithms like Heap Sort. Heap Sort mainly uses Heap Data Structure along with the Selection Sort idea.
    Used when memory writes (or swaps) are costly for example EEPROM or Flash Memory. When compared to other popular sorting algorithms, it takes relatively less memory writes (or less swaps) for sorting. But Selection sort is not optimal in terms of memory writes, cycle sort even requires lesser memory writes than selection sort.
    Simple technique and used to introduce sorting in teaching.
    Used as a benchmark for comparison with other algorithms.
*/
#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
