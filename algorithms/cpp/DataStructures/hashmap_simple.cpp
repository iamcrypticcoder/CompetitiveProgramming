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

#define BIG_PRIME 101
#define BUCKET_SIZE 8

struct Node {
    string key, value;
    Node* next = NULL;

    Node();
    Node(string key, string value) {
        this->key = key;
        this->value = value;
    }
};
Node* buckets[BUCKET_SIZE];

int calcHash(string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); ++i) {
        sum = (sum + (int)str[i]) % BIG_PRIME;
    }
    return sum % BIG_PRIME;
}

// Complexity: O(1) ~ O(n)
bool hashMapPut(string key, string value) {
    int hash = calcHash(key);
    int bucketIndex = hash % BUCKET_SIZE;

    // No node available in this bucket
    if (NULL == buckets[bucketIndex]) {
        buckets[bucketIndex] = new Node(key, value);
        return true;
    }

    Node* current = buckets[bucketIndex];
    Node* last = current;

    while (NULL != current) {
        if (current->key == key) {
            current->value = value;
            break;
        }
        last = current;
        current = current->next;
    }

    if (NULL == current) {
        last->next = new Node(key, value);
    }
    return true;
}

// Complexity: O(1) ~ O(n)
string hashMapGet(string key) {
    int hash = calcHash(key);
    int bucketIndex = hash % BUCKET_SIZE;

    Node* current = buckets[bucketIndex];

    while (NULL != current) {
        if (current->key == key) break;
        current = current->next;
    }

    return (NULL == current ? "" :current->value);
}

bool hashMapRemove(string key) {
    int hash = calcHash(key);
    int bucketIndex = hash % BUCKET_SIZE;

    Node* current = buckets[bucketIndex];
    Node* prev = current;

    while (NULL != current) {
        if (current->key == key) break;
        prev = current;
        current = current->next;
    }

    // If matched to first node of linked list
    if (prev == current) {
        buckets[bucketIndex] = prev->next;
        return true;
    }

    prev->next = current->next;
    return true;
}

int main() {
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    hashMapPut("a", "x");
    hashMapPut("b", "y");
    hashMapPut("c", "z");

    cout << hashMapGet("a") << endl;
    cout << hashMapGet("b") << endl;
    cout << hashMapGet("c") << endl << endl;

    // Replace current value
    hashMapPut("a", "xx");

    cout << hashMapGet("a") << endl;
    cout << hashMapGet("b") << endl;
    cout << hashMapGet("c") << endl << endl;

    hashMapRemove("a");

    cout << hashMapGet("a") << endl;
    cout << hashMapGet("b") << endl;
    cout << hashMapGet("c") << endl << endl;
}