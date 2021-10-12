/*
        Problem Link :
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : [AC, WA, TLE, RTE]
        Time :
        Rank :
        Complexity:
*/

#define _CRT_SECURE_NO_WARNINGS

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
#include <limits.h>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS             1e-9
#define SQR(x)          ((x)*(x))
#define INF             2000000000
#define TO_DEG          57.29577951
#define PI              2*acos(0.0)

#define ALL_BITS                                ((1 << 31) - 1)
#define NEG_BITS(mask)                          (mask ^= ALL_BITS)
#define TEST_BIT(mask, i)                       (mask & (1 << i))
#define ON_BIT(mask, i)                         (mask |= (1 << i))
#define OFF_BIT(mask, i)                        (mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)                         (x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)                (x & (x-1))

typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<uint, uint> PUU;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<uint> VU;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<uint, uint> MUU;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<PII> > VVPII;

int GCD(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline uint srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline LL srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline ULL srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 1000000

inline int parent(int i) { return i / 2; }
inline int left(int i) { return (2 * i); }
inline int right(int i) { return (2 * i + 1); }
inline void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int heapArr[MAX + 1];
int heapSize;
int capacity;

void initHeap() {
    heapSize = 0;
    capacity = MAX;
}

void minHeapify(int parent) {
    int l = left(parent);
    int r = right(parent);
    int smallest = parent;
    if (l <= heapSize && heapArr[l] < heapArr[smallest]) smallest = l;
    if (r <= heapSize && heapArr[r] < heapArr[smallest]) smallest = r;
    if (smallest != parent) {
        swap(heapArr[parent], heapArr[smallest]);
        minHeapify(smallest);
    }
}

// Complexity: O(lg n)
void insertItem(int item) {
    if (heapSize == capacity) return;
    heapSize++;
    heapArr[heapSize] = item;
    int currentNode = heapSize;
    int parentNode = parent(currentNode);

    // Until parent node value is higher than current node
    while (currentNode != 1 && heapArr[parentNode] > heapArr[currentNode]) {
        swap(heapArr[parentNode], heapArr[currentNode]);
        currentNode = parentNode;
        parentNode = parent(currentNode);
    }
}

// Complexity: O(1)
int getMin() {
    return heapArr[1];
}

// Complexity: O(lg n)
int extractMin() {
    if (heapSize == 0) return INT_MAX;
    if (heapSize == 1) {
        heapSize--;
        return heapArr[1];
    }

    int root = heapArr[1];
    heapArr[1] = heapArr[heapSize];
    heapSize--;
    minHeapify(1);
    return root;
}

// Complexity: O(lg n)
void decreaseItem(int index, int newVal) {
    heapArr[index] = newVal;
    int parentNode = parent(index);
    while(index != 1 && heapArr[parentNode] > heapArr[index]) {
        int t = heapArr[parentNode];
        heapArr[parentNode] = heapArr[index];
        heapArr[index] = t;
        index = parentNode;
        parentNode = parent(index);
    }

}

// Complexity: O(lg n)
void deleteItem(int index) {
    // Assign lowest value possible so that it will reach to root
    decreaseItem(index, INT_MIN);
    // Then extract min will remove that item from heap tree. correct ?
    extractMin();
}

void printHeapArray() {
    for(int i = 1; i <= heapSize; i++)
        printf("%d ", heapArr[i]);
    cout << endl;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    vector<int> v {5, 2, 7, 1, 9, 3, 10, 8, 4, 6};

    initHeap();
    for (int x : v)
        insertItem(x);

    printHeapArray();

    while (heapSize > 0) {
        cout << extractMin() << " ";
    }
    cout << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}