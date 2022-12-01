/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw8_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw8_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw8_2.cpp
 * Abstract:implements the topological sorting algorithm based on the DFS algorithm
 * ID: 2223
 * Name: Cesar Borrego 
 * Date: 10/25/2022
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printVector(vector<int> array){
    for(auto i: array){
        cout << i << " ";
    }
    cout << endl;
}

void printResult(vector<int> answer, vector<int> starters){
    cout << "This is a DAG." << endl;
    cout << "Start node(s):";
    for(int i = 0; i < starters.size(); i++){
        if(i != starters.size()-1){
            cout << starters[i] << " ";
        } else {
            cout << starters[i] << endl;
        }
    }
    printVector(answer);
    cout << "Topological sort:";
    for(int i = answer.size()-1; i >= 0; i--){
        if(i == 0){
            cout << answer[i] << endl;
        } else {
            cout << answer[i] << "->";
        }
    }
    cout << endl;
}

void maintenance(vector<vector<int>> a, int v, int e){
    for(int i = 0; i < v; i++){
        cout << i << ":";
        for(int x = 0; x < a[i].size(); x++){
            cout << a[i][x] << " ";
        }
        cout << endl;
    }
}

vector<int> findStarters(vector<vector<int>> matrix){
    vector<int> starters;
    bool a = true;
    for(int x = 0; x < matrix.size(); x++){
        for(int i = 0; i < matrix[x].size(); i++){
            if(matrix[x][i] == x) a = false;
        }
        if(a){
            starters.push_back(x);
            a = false;
        }
    }
    return starters;
}

void topoUtil(int v, vector<bool> &visited, stack<int> &stack, vector<vector<int>> matrix){
    visited[v] = true;
    for(int i = 0; i < matrix[i].size(); ++i){
        if(!visited[i]){
            topoUtil(i, visited, stack, matrix);
        }
    }
    stack.push(v);
}

vector<int> topologicalSort(int vertices, int edges, vector<vector<int>> matrix){
    stack<int> stack;
    vector<int> answer;

    vector<bool> visited (vertices, false);
    for(int i = 0; i < visited.size(); i++)
        if(!visited[i]) 
            topoUtil(i, visited, stack, matrix);


    // int numVisited = 0;
    // for(int i = 0; i < visited.size(); i++)
    //     if(visited[i])
    //         numVisited++;

    // if(numVisited != vertices){
    //     cout << "This is not a DAG." << endl;
    // }

    while(!stack.empty()){
        answer.push_back(stack.top());
        stack.pop();
    }

    return answer;
}

int main() {
	int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> myEdges(vertices, vector<int>(0));
    for(int x = 0; x < edges; x++){
        int a, b;
        cin >> a >> b;
        myEdges[a].push_back(b);
    }

    // maintenance(myEdges, vertices, edges);
    vector<int> startNodes = findStarters(myEdges);

    vector<int> result = topologicalSort(vertices, edges, myEdges);
    printResult(result, startNodes);

	return 0;
}