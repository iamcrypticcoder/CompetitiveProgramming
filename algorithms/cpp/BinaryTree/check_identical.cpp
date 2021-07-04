/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* parent = NULL;
    Node* left = NULL;
    Node* right = NULL;

    Node() {}
    Node(int key) {
        this->key = key;
    }
    Node(Node* parent, int key) {
        this->parent = parent;
        this->key = key;
    }
};

/**
 * Given 2 binary trees, determine they are identical or not.
 * https://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
 */
bool checkIdenticalTree(Node* n1, Node* n2) {
    if (NULL == n1 && NULL == n2) return true;

    if (NULL == n1 && NULL != n2) return false;
    if (NULL == n2 && NULL != n1) return false;
    if (n1->key != n2->key) return false;

    return checkIdenticalTree(n1->left, n2->left) && checkIdenticalTree(n1->right, n2->right);
}


int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(root1, 2);
    root1->right = new Node(root1, 3);
    root1->left->left = new Node(root1->left, 4);
    root1->left->right = new Node(root1->left, 5);

//      1
//    /   \
//   2     3
//  / \
// 4   5

    Node* root2 = new Node(1);
    root2->left = new Node(root2, 2);
    root2->right = new Node(root2, 3);
    root2->right->left = new Node(root2->right, 4);
    root2->right->right = new Node(root2->right, 5);

//      1
//    /   \
//   2     3
//        / \
//       4   5

    Node* root3 = new Node(1);
    root3->left = new Node(root3, 2);
    root3->right = new Node(root3, 3);
    root3->left->left = new Node(root3->left, 4);
    root3->left->right = new Node(root3->left, 5);

//      1
//    /   \
//   2     3
//  / \
// 4   5

    cout << "checkIdenticalTree() : " <<  checkIdenticalTree(root1, root2) << endl;
    cout << "checkIdenticalTree() : " <<  checkIdenticalTree(root1, root3) << endl;
}

