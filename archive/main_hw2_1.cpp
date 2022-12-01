/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_1.cpp
 * Abstract: checks if an input string is a palindrome or not.
 * ID: 2223
 * Name: Cesar Borrego 
 * Date: 09/6/2022
 */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string lowerCase(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main() {
	string word;
    cin >> word;

    word = lowerCase(word);

    int i = 0;
    bool proved = true;
    for(int x = word.length()-1; x>=0; x--){
        if(int(word.at(i)) < 97 || int(word.at(i)) > 122){
            if(int(word.at(i)) < 49 || int(word.at(i)) > 57){
                i++;
            }
        }
        if(int(word.at(x)) < 97 || int(word.at(x)) > 122){
            if(int(word.at(x)) < 49 || int(word.at(x)) > 57){
                x--;
            }
        }

        if(word.at(i) != word.at(x)) proved = false;

        if(i == x) break;
        else i++;
    }
    if(proved) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;


	return 0;
}
