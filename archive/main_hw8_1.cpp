/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw8_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw8_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw8_1.cpp
 * Abstract: conducts the topological sorting using the Kahn algorithm.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 10/25/2022
 */

#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

void maintenance(vector<vector<int>> a, int v, int e){
    for(int i = 0; i < v; i++){
        cout << i << ":";
        for(int x = 0; x < a[i].size(); x++){
            cout << a[i][x] << " ";
        }
        cout << endl;
    }
}

vector<int> countInDegree(vector<vector<int>> matrix){
    vector<int> inDegrees(matrix.size(), 0);
    for(auto i: matrix){
        for(auto x: i){
            inDegrees[x]++;
        }
    }
    return inDegrees;
}

void printDegrees(vector<int>d){
    for(int x = 0; x < d.size(); x++){
        cout << "In-degree[" << x << "]:" << d[x] << endl;
    }
}

void order(vector<int> d, vector<vector<int>> matrix){
    cout << "Order:";
    queue<int> q;
    int visited = 0;

    for(int i = 0; i < d.size(); i++){
        if(0 == d[i]) {
            q.push(i);
        }
    }

    vector<int> ordered;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        ordered.push_back(u);

        for(int i = 0; i < matrix[u].size(); i++){
            d[matrix[u][i]]--;
            if(d[matrix[u][i]] == 0)
                q.push(matrix[u][i]);
        }

        visited++;
    }

    for(int i = 0; i < ordered.size(); i++){
        if(i != ordered.size()-1){
            cout << ordered[i] << "->";
        } else {
            cout << ordered[i] << endl;
        }
    }
    
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> myEdges(vertices, vector<int>(0));
    for(int x = 0; x < edges; x++){
        int a, b;
        cin >> a >> b;
        myEdges[a].push_back(b);
    }

    // maintenance(myEdges, vertices, edges);

    vector<int> inDegrees = countInDegree(myEdges);
    printDegrees(inDegrees);
    order(inDegrees, myEdges);

    return 0;
}

