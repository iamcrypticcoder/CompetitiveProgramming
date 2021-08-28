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

int floor(Node* n, int key) {
    if (NULL == n) return -1;
    if (key == n->key) return key;

    if (key < n->key)
        return floor(n->left, key);

    int f = floor(n->right, key);
    return (f != -1 && f <= key) ? f : n->key;
}

int ceil(Node* n, int key) {
    if (NULL == n) return -1;
    if (n->key == key) return key;

    if (key > n->key)
        return ceil(n->right, key);

    int c = ceil(n->left, key);
    return (c != -1 && c >= key) ? c : n->key;
}



int main() {
    cout << "Create minimal BST:" << endl;
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int count = sizeof arr / sizeof (int);
    Node* root = createMinimalBST(arr, count);

    vector<int> keys {11, 1, 6, 15};
    for (int key : keys)
        printf("Key = %d, Floor = %d, Ceil = %d\n", key, floor(root, key), ceil(root, key));


    return 0;
}

