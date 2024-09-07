/*
Time Complexity:
Best Case: O(n log n), When the array is already sorted or nearly sorted.
Average Case: O(n log n), When the array is randomly ordered.
Worst Case: O(n log n), When the array is sorted in reverse order.
*/
/*
Applications of Merge Sort:
    Sorting large datasets
    External sorting (when the dataset is too large to fit in memory)
    Inversion counting
    Merge Sort and its variations are used in library methods of programming languages. For example its variation TimSort is used in Python, Java Android and Swift. The main reason why it is preferred to sort non-primitive types is stability which is not there in QuickSort. For example Arrays.sort in Java uses QuickSort while Collections.sort uses MergeSort.
    It is a preferred algorithm for sorting Linked lists.
    It can be easily parallelized as we can independently sort subarrays and then merge.
    The merge function of merge sort to efficiently solve the problems like union and intersection of two sorted arrays.
*/
/*
Advantages of Merge Sort:
    Stability : Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
    Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN) , which means it performs well even on large datasets.
    Simple to implement: The divide-and-conquer approach is straightforward.
    Naturally Parallel : We independently merge subarrays that makes it suitable for parallel processing.
Disadvantages of Merge Sort:
Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process.
Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
Slower than QuickSort in general. QuickSort is more cache friendly because it works in-place.

*/
// You are using GCC
#include<iostream>
using namespace std;
void merge(int leftArr[],int leftLength,int rightArr[],int rightLength,int arr[]){
    int i=0,l=0,r=0;
    while(l<leftLength && r<rightLength){
        if(leftArr[l]<rightArr[r]){
            arr[i++]=leftArr[l++];
        }
        else{
            arr[i++]=rightArr[r++];
        }
    }
    while(l<leftLength){
        arr[i++]=leftArr[l++];
    }
    while(r<rightLength){
        arr[i++]=rightArr[r++];
    }
}
void mergeSort(int arr[],int len){
    if(len<=1)return;
    int mid=len/2;
    int leftArr[mid];
    int rightArr[len-mid];
    for (int i = 0; i < mid; i++) {
        leftArr[i] = arr[i];
    }
    for (int i = mid; i < len; i++) {
        rightArr[i - mid] = arr[i];
    }
    mergeSort(leftArr,mid);
    mergeSort(rightArr,len-mid);
    merge(leftArr,mid,rightArr,len-mid,arr);
}
int main(){
    int arr[]={8,5,2,1,7,6,3,4};
    int len=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
