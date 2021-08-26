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

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b)    {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a, int b)   {   return a/GCD(a,b)*b;                }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 10000

int items[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

void maxHeapify(int *arr, int heapSize, int p) {
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    int largest = p;
    if (l < heapSize && arr[l] > arr[largest]) largest = l;
    if (r < heapSize && arr[r] > arr[largest]) largest = r;
    if (largest != p) {
        swap(arr[largest], arr[p]);
        maxHeapify(arr, heapSize, largest);
    }
}

void buildMaxHeap(int *arr, int n) {
    for (int i = n/2-1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSortIncreasing(int *arr, int n) {
    buildMaxHeap(arr, n);

    int heapSize = n;
    // Put largest element at last
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapSize--;
        // call max heapify on the reduced heap
        maxHeapify(arr, heapSize, 0);
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    int cnt = sizeof(items) / sizeof(int);
    heapSortIncreasing(items, cnt);
    FOR(i, 0, cnt-1) cout << items[i] << " ";

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
