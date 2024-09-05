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
#include<vector>
using namespace std;
void merge(vector<int>&a,int l,int m,int h){
    vector<int>temp;
    int lf=l;
    int ri=m+1;
    while(lf<=m && ri<=h){
        if(a[lf]<=a[ri]){
            temp.push_back(a[lf]);
            lf++;
        }
        else{
            temp.push_back(a[ri]);
            ri++;
        }
    }
    while(lf<=m){
            temp.push_back(a[lf]);
            lf++;
    }
    while(ri<=h){
            temp.push_back(a[ri]);
            ri++;
    }
    for(int i=l;i<=h;i++){
        a[i]=temp[i-l];
    }
}
void mergeS(vector<int>&a,int l,int h){
    if(l>=h)
    return;
    int mid=(l+h)/2;
    mergeS(a,l,mid);
    mergeS(a,mid+1,h);
    merge(a,l,mid,h);
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    mergeS(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}