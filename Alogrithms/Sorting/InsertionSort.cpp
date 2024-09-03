//Time Complexity: O(N^2)
/*
Time Complexity of Insertion Sort
Best case: O(n) , If the list is already sorted, where n is the number of elements in the list.
Average case: O(n 2 ) , If the list is randomly ordered
Worst case: O(n 2 ) , If the list is in reverse order
*/
/*
Advantages of Insertion Sort:
    Simple and easy to implement.
    Stable sorting algorithm.
    Efficient for small lists and nearly sorted lists.
    Space-efficient.
    Adoptive. the number of inversions is directly proportional to number of swaps. For example, no swapping happens for a sorted array and it takes O(n) time only.
Disadvantages of Insertion Sort:
    Inefficient for large lists.
    Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases.
Applications of Insertion Sort:
    The list is small or nearly sorted.
    Simplicity and stability are important.
    Used as a subroutine in Bucket Sort
*/
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
