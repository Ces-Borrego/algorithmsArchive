/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_2.cpp
 * Abstract: solve the Knapsack problem.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 09/23/2022
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
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

    reverse(binaryNum.begin(), binaryNum.end());

	return binaryNum;
}

void printItems(vector<pair<int, int>> items){
    for(auto i: items){
        cout << i.first << ":" << i.second << endl;
    }
}

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        if(i == v.size()-1){
            cout << v[i]+1 << endl;
        } else {
            cout << v[i]+1 << " ";
        }
    }
    
}

void printQueue(queue<pair<int, int>> q){
    for(int x = 0; x < q.size();x++){
        cout << q.front().first << ":" << q.front().second << endl;
        q.pop();
    }
    
}

void answer(queue<pair<int,int>> q, vector<pair<int, int>> items, vector<vector<int>> subsets){
    // printQueue(q);
    if(q.size() == 1){
        cout << "Item:";
        int capacity = 0, value = 0;
        vector<int> ind;
        for(int x = 0; x < q.size(); x++){
            value += q.front().second; 
            for(int i = 0; i < subsets[q.front().first].size(); i++){
                if(subsets[q.front().first][i] == 1){
                    capacity += items[i].first;
                    ind.push_back(i);
                }
            }
            q.pop();

            printVector(ind);
        }
        cout << "Capacity:" << capacity << endl;
        cout << "Value:" << value << endl;
    } else {
        cout << "Item:Multiple solutions" << endl;
        int capacity = q.front().first, value = q.front().second;
        while(!q.empty()){
            if((q.front().second > value) || (q.front().first > capacity)){
                value = q.front().second;
                capacity = q.front().first;
                q.pop();
            } else {
                q.pop();
                continue;
            }
        }
        cout << "Capacity:" << capacity << endl;
        cout << "Value:" << value << endl;
    }
}

int main()
{
    //read numItems and capacity
    int numItems, capacity;
    cin >> numItems >> capacity;

    //initialize containers
    vector<pair<int, int>> items;
    pair<int, int> knapsack(capacity, 0);

    //read items
    for(int x = 0; x < numItems; x++){
        int cap, value;
        cin >> cap >> value;
        pair<int, int> item(cap, value);

        items.push_back(item);
    }

    // printItems(items);
    //calculate subsets
    int numSubsets = pow(2, numItems);
    vector<vector<int>> subsets;
    for(int x = 0; x < numSubsets; x++){
        vector<int> bin = decToBinary(x,numItems);
        // printVector(bin);
        subsets.push_back(bin);
    }

    //calculate max value subset based on capacity
    //init container
    queue<pair<int, int>> solutions;
    //iterate through subsets
    for(int x = 0; x < numSubsets; x++){
        //init max vals
        int cap = 0, val = 0;
        //compute max vals of current iteration
        for(int i = 0; i < subsets[x].size(); i++){
            if(subsets[x][i] == 1){
                cap += items[i].first;
                val += items[i].second;
            }
        }
        //determine whether it is a solution or not
        if(cap <= knapsack.first && solutions.empty()){ //first case
            solutions.push(pair<int, int> (x,val));
        } else if(cap <=knapsack.first){                                        //other
            if(solutions.front().second < val){             //replace solution if val is greater than iteration in queue
                solutions.pop();
                solutions.push(pair<int, int> (x,val));
            } else if(solutions.front().second == val){     //push new solution if val is equal to other iteration
                solutions.push(pair<int, int> (x,val));
            }
        }
    }

    // printQueue(solutions);
    answer(solutions, items, subsets);

	return 0;
}

