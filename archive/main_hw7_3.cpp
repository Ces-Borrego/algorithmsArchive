/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_3.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_3.cpp
 * Abstract: reads a number of input values and the 
 * values themselves. Then, puts all negative numbers in front of all positive numbers.
 * ID: 2223
 * Name:Cesar Borrego
 * Date: 10/20/2022
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>a){
    for(int i = 0; i < a.size(); i++){
        if(i != a.size()-1){
            cout << a[i] << " ";
        } else {
            cout << a[i] << endl;
        }
    }
}

void seperateSignsOne(vector<int>&array){
    int i = 0; int j = array.size()-1;
    while(i != j){
        if(array[i] > 0){
            if(array[j] < 0){
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            } else {
                j--;
            }
        } else if(array[j] < 0){
            if(array[i] > 0){
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            } else {
                i++;
            }
        } else {
            if(i+1 == j) break;
            i++;
            j--;
        }
    }
}

void seperateSignsThree(vector<int>&array){
    int i = array.size()-1; int j = array.size()-1;
    while(j >= 0){
        if(array[i] < 0){
            if(array[j] > 0){
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            } else {
                j--;
            }
        } else if(array[i] > 0){
            if(array[j] > 0){
                i--;
                j--;
            } else {
                i--;
            }
        }
    }
}

int main() {
	int size;
    cin >> size;

    vector<int> numsOne(size,0);
    vector<int> numsThree(size,0);

    for(int i = 0; i < size; i++) cin >> numsOne[i];
    numsThree = numsOne;

    seperateSignsOne(numsOne);
    seperateSignsThree(numsThree);

    printVector(numsOne);
    printVector(numsThree);

	return 0;
}

