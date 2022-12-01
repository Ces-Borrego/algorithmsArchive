/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_2.cpp
 * Abstract: converts a directed weighted graph data 
 * from a user into a corresponding adjacency list 
 * format.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 09/14/2022
 */

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix){
    for(int x = 0; x < matrix.size(); x++){
        cout << x;
        for(int i = 0; i < matrix[x].size(); i++){
            if(matrix[x][i] != 0){
                if(i == matrix[x].size()-1) cout << "->" << i << "," << matrix[x][i];
                else cout << "->" << i << "," << matrix[x][i];
            }
        }
        cout << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> matrix (v, vector<int> (v,0));

    for(int i = 0; i < e; i++){
        int a, b, z;
        cin >> a >> b >> z;
        matrix[a][b] = z;
    }

    printMatrix(matrix);

    return 0;
}

