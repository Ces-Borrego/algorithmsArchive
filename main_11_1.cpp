/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw11_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw11_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw11_1.cpp
 * Abstract: simulatates the operations of linear probing
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 11/29/2022
 */

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Hash{
    private:    
        int CAPACITY;// number of CAPACITY or size
        vector<pair<int,int>> *table;//table
    public:
        Hash(int size);
        void insert(int x);
        void remove(int x);
        int find(int x);
        int hashFunction(int x){
            return (x % CAPACITY);
        }
        void rehash();
        void displayHash();
};

Hash::Hash(int x){
    this->CAPACITY = x;
    table = new vector<pair<int,int>>(CAPACITY, pair<int,int>(0,0));
}

void Hash::insert(int x){
    int index = hashFunction(x);    //calc index

    //check load factor and rehash if necessary
    int s = table->size();
    if(s/CAPACITY >= 0.5){
        rehash();
    }

    //check index for value
    //if empty then insert and continue 
    //if not then linear probe to next empty cell and insert
    if(table->at(index).second == 0){
        table->at(index).first = x;
        table->at(index).second = 1;
    } else {
        do{
            index++;
            if(index == CAPACITY-1) index = index%CAPACITY;  //if end of vector is reached, return -1
            }while(table->at(index).second != 0);
        table->at(index).first = x;
        table->at(index).second = 1;
    }
    
}

void Hash::remove(int x){
    int index = hashFunction(x); //calc index

    //check index for value given
    //if not there, traverse linearly until value is found
    if(table->at(index).first == x){
        table->at(index).second = 0;
    } else {
        int ind = find(x);
        if(table->at(ind).first == x) table->at(ind).second = 0; //remove value
    }

}

int Hash::find(int x){
    int index = hashFunction(x); //calc index
    //check index for value given
    //if not there, traverse linearly until value is found
    if(table->at(index).second != 0){
        if(table->at(index).first != x){
            do{
                index++;
                if(index == CAPACITY-1) index = index%CAPACITY;  //if end of vector is reached, return -1
            }while(table->at(index).second != 0);
        } else {
            return index;   //else if number is found, return index of the number
        }
    }
}

void Hash::rehash(){
    //find the first prime number that is twice as big as the current capacity
    //set capacity equal to new number
    //recreate table based on new capacity and tranfer over values from old table
    
}



int main()
{
    int size, numCommands;
    cin >> size >> numCommands;

    Hash myTable(size);

    myTable.insert(20);




    return 0;
}

