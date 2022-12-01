/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw1_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_1.cpp
 * Abstract: 
 * reads two groups of numbers in which each 
 * group has random integer numbers with possible duplicates. Your program should display
 * the common numbers without any duplicates in the ascending order.
 * ID: 2223
 * Name: Cesar Borrego  
 * Date: 08/28/2022
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

//print array
void printArray(vector<int> a){
    for(int x = 0; x < a.size(); x++){
        cout << a[x] << endl;
    }
}

//print set
void printSet(set<int> a){
    cout << "Answer:";
    if(a.size() != 0){
        int count = 0;
        for(int i: a){
            if(count != a.size()-1) cout << i << " ";
            else cout << i << endl;

            count++;
        }
    } else {
        cout << "NONE" << endl;
    }
}

//get duplicates
set<int> getDuplicates(vector<int> a, vector<int> b){
    set<int> dupes;
    for(int x = 0; x < a.size(); x++){
        for(int y = 0; y < b.size(); y++){
            if(a[x] == b[y]){
                dupes.insert(a[x]);
            }
        }
    }
    return dupes;
}

int main() {
    //init vars input
    vector<int> one, two;
    set<int> dupes;
    int size;

    //read input
    for(int x = 0; x < 2; x++){
        cin >> size;
        for( int y = 0; y < size; y++){
            int a;
            cin >> a;
            if(x == 0){
                one.push_back(a);
            } else {
                two.push_back(a);
            }
        }
    }

    //get dupes
    dupes = getDuplicates(one, two);

    //print dupes
    // cout << endl;
    printSet(dupes);
    

    // print arrays
    // cout << endl << endl;
    // printArray(one);
    // cout << endl;
    // printArray(two);
	return 0;
}
