/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw9_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw9_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw9_1.cpp
 * Abstract: displays the performance of quicksort algorithm. This program will also measure the performance insertion
 * sort and merge sort if it’s necessary.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 11/3/2022
 * ##Resources##
 * Insertion Sort: https://www.geeksforgeeks.org/insertion-sort/
 * Merge Sort: https://www.geeksforgeeks.org/merge-sort/
 */

#include <utility>
#include <random>
#include <limits>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//print vector function
void printVector(vector<int> array){
    for(auto i: array){
        cout << i << " ";
    }
    cout << endl;
}

//Function to fill vector with random numbers (random);
static vector<int> generate_data_random(size_t size){
    using value_type = int;
    static uniform_int_distribution<value_type> distribution(0,10000000);
    static default_random_engine generator;

    vector<value_type> data(size);
    generate(data.begin(), data.end(), []() { return distribution(generator); });
    return data;
}

//Swap Function for general use
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}


/*
10) ALGORITHM Partition(A[l..r])
11) // Partitions a subarray by Hoare’s algorithm, using the first 
12) // element as a pivot.
13) // Input: Subarray of array A[0..n−1], defined by its left and 
14) //        right indices l and r (l<r)
15) // Output: Partition of A[l..r], with the split position 
16) //         returned as this function’s value
17) p ← A[l]
18) i ← l
19) j ← r + 1
20)
21) repeat
22)     repeat
23)         i ← i + 1 
24)     until A[i] ≥ p
25)
26)     repeat 
27)         j ← j − 1
28)     until A[j] ≤ p
29)     swap(A[i], A[j])
30) until i ≥ j
31)
32) swap(A[i], A[j]) // undo last swap when i ≥ j
33) swap(A[l], A[j])
34) return j
*/

int Partition(vector<int> array, int l, int r){
    int p = array[l], i = l, j = r+1; 

    do{
        do{
            i++;
        } while (array[i] < p);

        do{
            j--;
        } while (array[j] > p);

        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

    } while (i < j);

    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;

    tmp = array[l];
    array[l] = array[j];
    array[j] = tmp;


    return j;
}

/*
1) ALGORITHM Quicksort(A[l..r])
2) // Sorts a subarray A from the index l to r by quicksort
3) // Input: Subarray of array A[0..n−1], defined by its left and 
4) //        right indices l and r
5) // Output: Subarray A[l..r] sorted in nondecreasing order
6) if l < r
7)     s ← Partition(A[l..r]) // s is a split position
8)     Quicksort(A[l..s-1])
9)     Quicksort(A[s+1..r])
*/

vector<int> quickSort(vector<int> array, int l, int r){
    if(l < r){
        int s = Partition(array, l, r);
        quickSort(array, l, s-1);
        quickSort(array, s+1, r);
    }
    return array;
}

//Insertion Sort Function LINK IN HEADER
void insertionSort(vector<int> arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Merge Sort Function LINK IN HEADER
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo){
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne){
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo){
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end){
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size){
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}


int main()
{
    int size, option;
    bool merge, insert;
    cout << "Enter input size:";
    cin >> size;

    cout << "========== Select Option for Input Numbers ==========" << endl;
    cout << "\t1. Ascending Order" << endl;
    cout << "\t2. Descending Order" << endl;
    cout << "\t3. Random Order" << endl;
    cout << "Choose option:";
    cin >> option;

    vector<int> nums(size+1,0);

    switch (option){
        case 1: //ascending order case
            nums = generate_data_random(size);
            sort(nums.begin(), nums.end());
            break;
        case 2: //descending order case
            nums = generate_data_random(size);
            sort(nums.begin(), nums.end(), greater<int>());
            break;
        case 3: //random order case
            nums = generate_data_random(size);
            break;
        default:
            break;
    }
    
    
    if(size <= 20){
        cout << endl;
        cout << "Numbers generated:";
        printVector(nums);  //output generated numbers
        cout << endl;
    }
    
    // char i,m;
    // cout << "Do you want to run insertion sort(y/n)?";
    // cin >> i;
    // i=='y' ? insert = true : insert = false; 
    // cout << "Do you want to run merge sort(y/n)?";
    // cin >> m;
    // m=='y' ? merge = true : merge = false;

    // cout << "==================== Execution Result ====================" << endl;
    // //print time stat for selected sorting methods (always print quicksort)
    // cout << "============================================================"<< endl;

    // cout << endl;

    // cout <<"========================== Ranking ========================="<<endl;
    // //print final rank from 1-3 based on speed of sorting algorithms
    // string quick = "Quick sort", insert = "Insertion sort", merge = "Merge sort";
    // cout <<"============================================================"<<endl;

    return 0;
}

