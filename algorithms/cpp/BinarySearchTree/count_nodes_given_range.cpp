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
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    Node *left = NULL, *right = NULL;

    Node() {}
    Node(int key) {
        this->key = key;
    }
};

/**
 * Given a sorted array with unique integers make BST with minimal height
 * @return
 */
Node* createMinimalBST(int arr[], int left, int right) {
    if (left > right) return NULL;
    int mid = (left + right) / 2;
    Node* n = new Node(arr[mid]);
    n->left = createMinimalBST(arr, left, mid-1);
    n->right = createMinimalBST(arr, mid+1, right);
    return n;
}
Node* createMinimalBST(int arr[], int cnt) {
    return createMinimalBST(arr, 0, cnt-1);
}

int countNodes(Node* n, int low, int high) {
    if (NULL == n) return 0;

    // If low and high are equal and matched to low and high
    if (low == high && n->key == low)
        return 1;

    // If node val is less then the given range
    if (n->key < low)
        return countNodes(n->right, low, high);

    // If node val is more then the given range
    if (n->key > high)
        return countNodes(n->left, low, high);

    // If node val lies inside range
    return 1 + countNodes(n->left, low, high) +
               countNodes(n->right, low, high);
}


int main() {
    cout << "Create minimal BST:" << endl;
    int arr[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    int count = sizeof arr / sizeof (int);
    Node* root = createMinimalBST(arr, count);

    cout << countNodes(root, 1, 14) << endl;
    cout << countNodes(root, 0, 0) << endl;
    cout << countNodes(root, 15, 15) << endl;

    cout << countNodes(root, 5, 10) << endl;
    cout << countNodes(root, 4, 4) << endl;

    return 0;
}

