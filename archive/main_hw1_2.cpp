/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw1_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_2.cpp
 * Abstract: reads input numbers from a user and displays the number(s) in the order of frequencies.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 08/28/2022
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//print array
void printArray(vector<int> a){
    for(int i: a){
        cout << i << " ";
    }
    cout << endl;
}

//print map
void printMap(map<int, int> a){
    for (auto i: a){
        cout << i.first << ":" << i.second << endl; 
    }
}

//print map by frequencies
void printMapByFrequencies(map<int, int> a){
    vector<int> f;
    for(auto i: a){
        f.push_back(i.second);
    }
    sort(f.begin(), f.end());

    // printArray(f);

    for(int j = 0; j < f.size(); j++){    
        for(auto i: a){
            if(f[j] == i.second){
                if(j == f.size()-1){
                    for(int o = 0; o < i.second; o++){
                        if(o == i.second-1) {
                            cout << i.first << endl;
                        }
                        else {
                            cout << i.first << " ";
                        }
                    }
                    break;
                } else {
                    for(int o = 0; o < i.second; o++){
                        cout << i.first << " ";
                    }
                    break;
                }
            }
        }
    }

    
}

//map frequencies
map<int, int> mapFrequencies(vector<int> a){
    map<int, int> freq;
    int count;
    for(int i: a){
        count = 0;
        for(int x: a){
            if(i == x) count++;
        }
        if(freq.find(i) == freq.end()) freq[i] = count;
    }

    return freq;
}

int main()
{
    //init vars
    vector<int> myArray;
    map<int, int> freqMap;
    int s;

    //read input
    cin >> s;
    for(int x = 0; x < s; x++){
        int a;
        cin >> a;
        myArray.push_back(a);
    }

    //map frequencies
    freqMap = mapFrequencies(myArray);

    //print map
    // printMap(freqMap);

    //print map by frequencies
    printMapByFrequencies(freqMap);



    //print Array
    // printArray(myArray);

    return 0;
}