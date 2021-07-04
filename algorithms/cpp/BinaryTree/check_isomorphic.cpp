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

bool isIsomorphic(Node* n1, Node* n2) {
    // If both are null, then isomorphic
    if (NULL == n1 && NULL == n2) return true;
    // If only one is null, not isomorphic
    if (NULL == n1 || NULL == n2) return false;

    if (n1->key != n2->key) return false;

    return (isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
            (isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left));
}

/**
 * https://www.geeksforgeeks.org/tree-isomorphism-problem/
 * @return
 */
int main() {
    Node* root1                 = new Node( 1);
    root1->left                 = new Node( 2);
    root1->right                = new Node(3);
    root1->left->left           = new Node(4);
    root1->left->right          = new Node(5);
    root1->left->right->left    = new Node(7);
    root1->left->right->right   = new Node(8);
    root1->right->left          = new Node(6);

    Node* root2                 = new Node( 1);
    root2->left                 = new Node(3);
    root2->right                = new Node(2);
    root2->left->right          = new Node(6);
    root2->right->left          = new Node(4);
    root2->right->right         = new Node(5);
    root2->right->right->left   = new Node(8);
    root2->right->right->right  = new Node(7);

    cout << "isIsomorphic() : " << isIsomorphic(root1, root2) << endl;
}