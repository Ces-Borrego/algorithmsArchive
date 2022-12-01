/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_1.cpp
 * Abstract: reads a number of elements in a set 
 * first. Reads the elements of the set. After  
 * that, displays all possible
 * decimal numbers, corresponding binary numbers, and  
 * subsets one by one.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 09/14/2022
 */

#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> decToBinary(int n, int s){
	// array to store binary number
    vector<int> binaryNum(s,0);

	// counter for binary array
	int i = 0;
	while (n > 0) {
		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	return binaryNum;
}

void printSet(set<string> c){
    for(string a: c) cout << a;;    
}

void printVectorLong(vector<int> v, int n){
    if(v.size() != 0){
        if(v.size() < n){    
            for(int o = 0; o < (n-v.size()); o++){
                cout << 0;
            }
            for(int x = v.size()-1; x >= 0; x--){
                cout << v[x];
            }
        } else if(v.size() == n){
            for(int x = v.size()-1; x >= 0; x--){
                cout << v[x];
            }
        } else if(v.size() > n){
            for(int x = n-1; x >= 0; x--){
                cout << v[x];
            }
        }
    } else {
        for(int x = 0; x < n; x++){
            cout << 0;
        }
    }
}

void printVector(vector<int> s){
    for(auto a: s){ 
        cout << a;
    } 
}

void printVectorString(vector<string> s){
    for(auto a: s){
        cout << a;
    }
}

void printAnswer(set<string> s, int n){
    vector<string> array;
    for(auto a: s){
        array.push_back(a);
    }
    // loop for all iterations in set s of size n
    for(int i = 0; i < (pow(2,n)); i++){
        cout << i << ":";
        vector<int> binary = decToBinary(i, n);
        if(n != 0) printVectorLong(binary, n);
        else cout << 0;
        reverse(binary.begin(), binary.end());
        int sum = count(binary.begin(), binary.end(), 1);
        cout << ":";
        string ans = "";
        if(sum != 0){    
            for(int x = 0; x < n; x++){
                if(binary[x] == 1 && x != n-1) ans += array[x] + " ";
                else if(binary[x] == 1 && x == n-1) ans += array[x];
            }
            if(ans[ans.length()-1] == *" ") ans.erase(ans.length()-1, 1);
            cout << ans;
        } else {
            cout << "EMPTY";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
	int size;
    cin >> size;
    set<string> mySet;

     for(int x = 0; x < size; x++){
        string c;
        cin >> c;

        mySet.insert(c);
     }

    // printSet(mySet);
    printAnswer(mySet,size);

	return 0;
}
