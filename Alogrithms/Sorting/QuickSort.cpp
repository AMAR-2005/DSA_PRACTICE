/*
Time Complexity:
    Best Case : Ω (N log (N))
    The best-case scenario for quicksort occur when the pivot chosen at the each step divides the array into roughly equal halves.
    In this case, the algorithm will make balanced partitions, leading to efficient Sorting.
    Average Case: θ ( N log (N))
    Quicksort’s average-case performance is usually very good in practice, making it one of the fastest sorting Algorithm.
    Worst Case: O(N ^ 2)
    The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly unbalanced partitions. When the array is already sorted and the pivot is always chosen as the smallest or largest element. To mitigate the worst-case Scenario, various techniques are used such as choosing a good pivot (e.g., median of three) and using Randomized algorithm (Randomized Quicksort ) to shuffle the element before sorting.
*/
#include<iostream>
using namespace std;
int partition(int arr[],int start,int end){
    int i = start-1 ;
    int pivot =  arr[end];
    for(int j=start; j<=end; j++){
        if(arr[j] < pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[++i],arr[end]);
    return i;
}
void quickSort(int arr[],int start,int end){
    if(end <= start)
    return;
    int pivotIndex = partition(arr, start, end);
    quickSort(arr,start,pivotIndex-1);
    quickSort(arr,pivotIndex+1,end);
}
int main(){
    int arr[] = {8, 2, 5, 3, 9, 4, 7, 6, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, len - 1);
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
}