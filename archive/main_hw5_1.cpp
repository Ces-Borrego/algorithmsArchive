/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw5_1.cpp
 * Abstract: reads an input graph data from a user. Then, 
it should present a path for the travelling salesman problem (TSP).
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 09/28/2022
 */
/*
Class notes: Need 2D array to store graph and edge weights. Use "-1" to indicate no edge connecting
            vertices. Consider 3 vertices in the middle of the route (TSP solution contains the starting
            vertice twice in the route).
            Use another 2D vector to keep track of different permutations.
            Calculate the value of each permutation based on sum of line weights for feach edge.
            i.e. for a graph with 4 vertices, it will have to store all permutations of other 3 vertices.
Test Case Used:
        4
        12
        0 1 2
        0 3 7
        0 2 5
        1 0 2
        1 2 8
        1 3 3
        2 0 5
        2 1 8
        2 3 1
        3 0 7
        3 1 9
        3 2 1
        0
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<int>> getPermutations(vector<int> v){
    vector<vector<int>> permutations;
    do{
        permutations.push_back(v);
    } while(next_permutation(v.begin(), v.end()));
    return permutations;
}

void tsp(vector<vector<int>> matrix, int start, vector<vector<int>> permutations){
    vector<int> solution;
    int minValue = 999;
    for(int i = 0; i < permutations.size(); i++){
        int val = 0;
        int lastVisited = start;
        for(auto x: permutations[i]){
            if(matrix[lastVisited][x] != 0){
                val += matrix[lastVisited][x];
                lastVisited = x;
            }
        }
        val += matrix[permutations[i][permutations[i].size()-1]][start];
        if(val < minValue){
            solution = permutations[i];
            minValue = val;
        }
    }

    cout << "Path:" << start << "->";
    for(int x = 0; x < solution.size(); x++){
        cout << solution[x] << "->";
    }
    cout << start << endl;
    cout << "Cost:" << minValue << endl;
}

void printMatrix(vector<vector<int>> matrix){
    // cout << endl << "--------------" << endl;
    for(auto i: matrix){
        for(auto o: i){
            cout << o << " ";
        }
        cout << endl;
    }
    // cout  << "--------------" << endl;
}

vector<vector<int>> readGraph(int v, int e){
    vector<vector<int>> m(v,vector<int>(v,0));

    for(int x = 0; x < e; x ++){
        int a, b, c;
        cin >> a >> b >> c;
        // cout << a << b << c << endl;
        m[a][b] = c;
    }

    return m;
}

int main() {
    // read vertices and edges
	int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    //init matrix and permutation matrixes
    vector<vector<int>> myMatrix;
    vector<vector<int>> permutations;

    //read matrix
    myMatrix = readGraph(numVertices, numEdges);
    // cout << "myMatrix: " << endl;
    // printMatrix(myMatrix);

    //read start 
    int start;
    cin >> start;

    //determine permutations
    vector<int> vertices;
    for(int x = 0; x < numVertices; x++){
        if(x != start) vertices.push_back(x);
    }
    permutations = getPermutations(vertices);
    // cout << "myPermutations: " << endl;
    // printMatrix(permutations);

    //solve tsp
    tsp(myMatrix, start, permutations);

	return 0;
}

