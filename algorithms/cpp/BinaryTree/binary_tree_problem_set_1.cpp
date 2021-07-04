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

void preOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    list.push_back(n->key);
    preOrderRecursive(n->left, list);
    preOrderRecursive(n->right, list);
}
vector<int> preOrderRecursive(Node *root) {
    vector<int> list;
    preOrderRecursive(root, list);
    return list;
}

void inOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    inOrderRecursive(n->left, list);
    list.push_back(n->key);
    inOrderRecursive(n->right, list);
}
vector<int> inOrderRecursive(Node *root) {
    vector<int> list;
    inOrderRecursive(root, list);
    return list;
}

void postOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    postOrderRecursive(n->left, list);
    postOrderRecursive(n->right, list);
    list.push_back(n->key);
}
vector<int> postOrderRecursive(Node *root) {
    vector<int> list;
    postOrderRecursive(root, list);
    return list;
}

/**
 * Given a binary tree, find height of binary tree aka max depth
 * @return
 */
int treeHeight(Node* n) {
    if (NULL == n) return 0;
    return max(treeHeight(n->left), treeHeight(n->right)) + 1;
}

/**
 * Given a binary tree, count leaves of binary tree
 * @return
 */
int countTreeLeaves(Node* n) {
    if (NULL == n) return 0;
    // This is a leaf
    if (NULL == n->left && NULL == n->right) return 1;
    return countTreeLeaves(n->left) + countTreeLeaves(n->right);
}

/**
 * Given a binary tree, find all nodes that are at distance K from root.
 * Distance of root considered as 0
 * @return
 */
void findNodesKdistance(Node* n, int K, vector<Node*> &list) {
    if (NULL == n) return;
    if (K == 0) {
        list.push_back(n);
        return;
    }
    findNodesKdistance(n->left, K-1, list);
    findNodesKdistance(n->right, K-1, list);
}

/**
 * Given a binary tree, Find difference between sums of odd level and even
 * level nodes of a Binary Tree
 * https://www.geeksforgeeks.org/difference-between-sums-of-odd-and-even-levels/
 */
void sumDiffOddEvenLevel(Node* n, int level, int &sum) {
    if (NULL == n) return;
    if (level & 1) sum += n->key;
    else sum -= n->key;
    sumDiffOddEvenLevel(n->left, level+1, sum);
    sumDiffOddEvenLevel(n->right, level+1, sum);
}

/**
 * Given a binary tree, Find Tilt of Binary Tree
 * https://www.geeksforgeeks.org/tilt-binary-tree/
 */
int tiltBinaryTree(Node* n, int &tilt) {
    if (NULL == n) return 0;

    int l = tiltBinaryTree(n->left, tilt);
    int r = tiltBinaryTree(n->right, tilt);
    tilt += abs (l - r);
    return l + r + n->key;
}

/**
 * Given a binary tree, convert it into its mirror
 *      1                  1
 *    /   \              /   \
 *   2     3    -->     3     2
 *  / \                     /   \
 * 4   5                   5     4
 * @return
 */
Node* treeConvertMirror(Node* n) {
    if (NULL == n) return n;
    Node *mLeft = treeConvertMirror(n->left);
    Node *mRight = treeConvertMirror(n->right);
    Node *tmp = mRight;
    n->right = mLeft;
    n->left = tmp;
    return n;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);
    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);

//      1
//    /   \
//   2     3
//  / \
// 4   5

    vector<int> list;
    vector<Node*> nodeList;

    cout << "treeHeight() : " << treeHeight(root) << endl;
    cout << "treeHeight() : " << treeHeight(root->right) << endl;
    cout << "treeHeight() : " << treeHeight(root->right->left) << endl;
    cout << "countTreeLeaves() " << countTreeLeaves(root) << endl;
    cout << "countTreeLeaves() " << countTreeLeaves(root->right) << endl;

    findNodesKdistance(root, 2, nodeList);
    cout << "findNodesKdistance() " << endl;
    for (int i = 0; i < nodeList.size(); i++)
        cout << nodeList[i]->key << " ";
    cout << endl;

    int sum = 0;
    sumDiffOddEvenLevel(root, 1, sum);
    cout << "sumDiffOddEvenLevel() : " << sum << endl;

    int tilt = 0;
    tiltBinaryTree(root, tilt);
    cout << "tiltBinaryTree() : " << tilt << endl;

    Node *mRoot = treeConvertMirror(root);
    cout << "treeConvertMirror() : " << endl;
    list = preOrderRecursive(mRoot);
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;


}

