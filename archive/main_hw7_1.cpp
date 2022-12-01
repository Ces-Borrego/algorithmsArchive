/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_1.cpp
 * Abstract: displays the smallest number in an array 
 * with n integer numbers using a divide-and-conquer technique.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 10/19/2022
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printVector(vector<int>array);

void findMinDAC(vector<int> const &array, int begin, int end, int &min);

int main() {
	int size;
    cin >> size;

    vector<int> myNums(size,0);

    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        myNums[i] = a;
    }

    int min = INT_MAX;
    findMinDAC(myNums, 0, size-1, min);

    // printVector(myNums);
    

    cout << min << endl;

	return 0;
}

void printVector(vector<int>array){
    for(auto i:array){
        cout << i << " ";
    }
    cout << endl;
}

void findMinDAC(vector<int> const &array, int start, int end, int &min){
    if(start == end){
        if(min > array[end]){
            min = array[end];  
        }
        return;
    } else if(end-start == 1){
        if(array[start] < array[end]){
            if(min > array[start]) min = array[start];
        } else {
            if(min > array[end]) min = array[end];
        }

        return;
    } else {
        int mid = (start + end)/2;
        // printVector(array);
        findMinDAC(array, start, mid, min);
        findMinDAC(array, mid+1, end, min);
    }
}

