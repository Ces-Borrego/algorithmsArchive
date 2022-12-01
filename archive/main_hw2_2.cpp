/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_2.cpp
 * Abstract: reads a set of events and displays the maximum number of events that take place concurrently.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 09/08/2022
 */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> s){
    cout << endl;
    for(int x = 0; x < s.size(); x++){
        cout << x << ":" << s[x] << " ";
    }
}

int main()
{
    int numEvents;
    cin >> numEvents;
    
    vector<int> startTimes;
    vector<int> endTimes;
    vector<int> eventsOccurring(25,0);

    for(int x = 0; x < numEvents; x++){
        int a, b;
        cin >> a >> b;
        startTimes.push_back(a);
        endTimes.push_back(b);
    }

    // printArray(startTimes);
    // printArray(endTimes);

    for(int x = 0; x < numEvents; x++){
        for(int s = startTimes[x]; s <= endTimes[x]; s++){
            eventsOccurring[s]++;
        }
    }

    int maxEvents = eventsOccurring[0];
    for(int x = 0; x < eventsOccurring.size(); x++){
        if(eventsOccurring[x] > maxEvents) maxEvents = eventsOccurring[x];
    }
    // printArray(eventsOccurring);


    cout << "Max events: " << maxEvents << endl;



    return 0;
}

