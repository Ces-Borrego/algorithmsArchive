/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_2.cpp
 * Abstract:Reads the number of input values 
 * from a user. Then, reads the input values from the user. After that, it displays them in 
 * the ascending order. It display the numbers, it uses a short representation if there are 
 * consecutive numbers.
 * ID:2223
 * Name:Cesar Borrego
 * Date: 10/19/2022
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

void printAnswer(vector<int> array);

int main()
{
    int size;
    cin >> size;

    vector<int> nums(size,0);

    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums[i] = a;
    }

    sort(nums.begin(), nums.end());

    printAnswer(nums);

    return 0;
}

void printAnswer(vector<int> array){
    stringstream ans;
    bool cont = false;
    for(int i = 0; i < array.size(); i++){
        if(i != array.size()-1){
            if(cont){
                if(array[i+1] == (array[i]+1)){
                    continue;
                } else {
                    ans << array[i] << " ";
                    cont = false;
                }
            } else {
                if(array[i+1] == (array[i]+1)){
                    ans << array[i] << "-";
                    cont = true;
                } else {
                    ans << array[i] << " ";
                }
            }
        } else {
            ans << array[i] << endl;
        }
    }
    string a = ans.str();
    cout << a << endl;
}
