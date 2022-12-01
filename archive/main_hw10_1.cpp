/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw10_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw10_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw10_1.cpp
 * Abstract: provides a few functions such as preOrder, postOrder, height, countLeaves,
 * and countOneChildNodes in a binary search tree
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 11/15/2022
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void printStringVector(vector<string> arr){
    cout << endl << "Commands:" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    } 
    cout << endl;
}

void printIntVector(vector<int> arr){
    cout << endl << "AddList:" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    } 
    cout << endl;
}

// A class to define a tree node.
class Node
{
public:
    // Constructor
    Node(int newData, Node* newLeft, Node* newRight)
    : data(newData), left(newLeft), right(newRight) 
    { 
        // Intentional empty.
    }

public:  // Use "public" to make the program simple (= no getters and setters).
    int data;
    Node *left;
    Node *right;
};


// A class for a BST which may include many Nodes.
class BST
{
public:
    BST( ); 
    void add(int item);
    void height ( ) const;
    void inOrder( ) const;
    void preOrder( ) const;
    void postOrder ( ) const;
    void countLeaves ( ) const;
    void countOneChildNodes ( ) const;
    
private:
    void insert(Node* newNode, Node* subTree);
    int height(Node* subTree) const;
    void inOrder(Node* subTree) const;
    void preOrder(Node* subTree) const;
    void postOrder(Node* subTree) const;
    int countLeaves(Node* subTree) const;
    int countOneChildNodes(Node* subTree) const; 
    Node *root;
};


// Constructor
BST::BST( ) 
: root(nullptr)
{
    // Intentional empty.
}

// Insert a new node under the subtree using recursion
void BST::insert(Node* newNode, Node* subTree)
{
    // Go to left subtree
    if (newNode->data < subTree->data)
    {
        if(subTree->left == nullptr)
        {
            subTree->left = newNode;
        }
        else
        {
            insert(newNode, subTree->left);
        }
    }
    else // Go to right subtree
    {
        if(subTree->right == nullptr)
        {
            subTree->right = newNode;
        }
        else
        {
            insert(newNode, subTree->right);
        }
    }
}


// Add an item to the BST.
// Internally, it calls "insert()" for actual insertion if root is not null.
void BST::add(int item)
{
    Node* newNode = new Node(item, nullptr, nullptr);
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        insert(newNode, root);
    }
}


void BST::inOrder(Node* subTree) const
{
    if (subTree != nullptr)
    {
        inOrder(subTree->left);
        cout << subTree->data << " ";
        inOrder(subTree->right);
    }
}


// Conduct the in-order traversal.
// Actual traversal happens in another function named inOrder() with the root.
// We have two inOrder() functions (= function overloading).
void BST::inOrder( ) const
{
    inOrder(root);
}

//Conduct preOrder traversal
void BST::preOrder(Node* subTree) const{
    if(subTree != nullptr){
        cout << subTree->data << " ";
        preOrder(subTree->left);
        preOrder(subTree->right);
    }
}

void BST::preOrder( ) const {
    preOrder(root);
    cout << endl;
}


//Conduct postOrder traversal
void BST::postOrder(Node* subTree) const{
    if(subTree != nullptr){
        preOrder(subTree->left);
        preOrder(subTree->right);
        cout << subTree->data << " ";
    }
}
void BST::postOrder( ) const{
    postOrder(root);
    cout << endl;
}

//Conduct countLeaves operation
int BST::countLeaves(Node* subTree) const{
    if(subTree != nullptr){
        if(subTree->left == nullptr && subTree->right == nullptr){
            return 1;
        } else if(subTree->left == nullptr && subTree->right != nullptr){
            return countLeaves(subTree->right);
        } else if(subTree->left != nullptr && subTree->right == nullptr){
            return countLeaves(subTree->left);
        } else {
            return countLeaves(subTree->left) + countLeaves(subTree->right);
        }
    } 
    return 0;
}
void BST::countLeaves( ) const{
    cout << countLeaves(root) << endl;
}

//Conduct countOneChildNodes operation
int BST::countOneChildNodes(Node* subTree) const{
    if(subTree != nullptr){
        if(subTree->left != nullptr && subTree->right == nullptr){
            return countOneChildNodes(subTree->left) + 1;
        } else if(subTree->left == nullptr && subTree->right != nullptr){
            return countOneChildNodes(subTree->right) + 1;
        } else if(subTree->left != nullptr && subTree->right != nullptr){
            return countOneChildNodes(subTree->left) + countOneChildNodes(subTree->right);
        } else if(subTree->left == nullptr && subTree->right == nullptr){
            return 0;
        }
    }
    return 0;
}
void BST::countOneChildNodes( ) const{
    cout << countOneChildNodes(root) << endl;
}

//Coduct height operation
int BST::height(Node* subTree) const{
    if(subTree == nullptr){
        return 0;
    } else {
        return max(height(subTree->left),height(subTree->right)) + 1;
    }
}

void BST::height( ) const{
    cout << height(root) - 1 << endl;
}

int main()
{
    // // Sample BST t1
    // // 
    // //        50
    // //       /  \
    // //     20   70
    // //    /  \    \
    // //   10   35   90

    // BST t1;

    // t1.add(50);
    // t1.add(20);
    // t1.add(70);
    // t1.add(10);
    // t1.add(35);
    // t1.add(90);
    
    // cout << "===== Inorder Traversal =====\n";
    // t1.inOrder( );
    // cout << endl;
    BST myTree;

    int size;
    cin >> size;

    // vector<string> commands;
    // vector<int> addList;
    for(int i = 0; i < size; i++){
        string com;
        cin >> com;
        if(com == "add"){
            int f;
            cin >> f;
            myTree.add(f);
        } else {
            if(com == "height"){
                myTree.height();
            } else if(com == "preOrder") {
                myTree.preOrder();
            } else if(com == "postOrder") {
                myTree.postOrder();
            } else if(com == "countLeaves") {
                myTree.countLeaves();
            } else if(com == "countOneChildNodes") {
                myTree.countOneChildNodes();
            }
        }
    }

    return 0;
}

