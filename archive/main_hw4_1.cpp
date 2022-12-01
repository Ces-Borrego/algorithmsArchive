/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_1.cpp
 * Abstract: checks if two strings are anagram or not.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 09/22/2022
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	string wOne, wTwo;
    cin >> wOne >> wTwo;
    
    bool anagram;

    sort(wOne.begin(), wOne.end());
    sort(wTwo.begin(), wTwo.end());

    if(wOne == wTwo){
        anagram = true;
        cout << "ANAGRAM" << endl;
    } else {
        anagram = false;
        cout << "NO ANAGRAM" << endl;
    }

    //compute and print vals and counts if anagram == true
    if(anagram){
        vector<pair<char, int>> chArchive;

        for(int x = 0; x < wOne.length(); x++){
            //take first char
            char a = wOne[x];

            //add to chArchive... account for repeat chars
            bool found = false;
            if(chArchive.empty()){
                pair<char, int> b(a,1);
                chArchive.push_back(b);
            } else {
                pair<char, int> b(a,1);
                for(int i = 0; i < chArchive.size(); i++){
                    if(chArchive[i].first == b.first){
                        chArchive[i].second++;
                        found = true;
                        break;
                    } 
                }
                if(!found) chArchive.push_back(b);
            }

        }

        //print chArchive vals and counts
        for(int i = 0; i < chArchive.size(); i++){
            cout << chArchive[i].first << ":" << chArchive[i].second << endl;
        }
    }

	return 0;
}
