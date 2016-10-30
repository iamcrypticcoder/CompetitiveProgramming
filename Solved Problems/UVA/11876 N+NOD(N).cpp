/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.438
    Rank :      418
    Complexity:
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define N 1000000
int TC, tc;
int A, B;
int NOD[1000001];
int NNOD[1000001];
int totalNNOD;
bool found;
bool foundA, foundB;

void GenerateNOD()
{
    for(int i=1; i <= N; i++)
        for(int j=i; j <= N; j += i)
            NOD[j]++;
}

void GenerateNNOD()
{
    NNOD[0] = 1;
    int i = 0;
    while(++i) {
        NNOD[i] = NNOD[i-1] + NOD[NNOD[i-1]];
        if(NNOD[i] > N) break;
    }
    totalNNOD = i;
}

int binarySearch(int key)
{
    int low = 0;
    int high = totalNNOD;
    int mid;
    found = false;

    while(low <= high) {
        mid = (low + high) / 2;
        if(key < NNOD[mid]) high = mid - 1;
        else if(key > NNOD[mid]) low = mid + 1;
        else {
            found = true;
            return mid;
        }
    }
    if(NNOD[mid] < key) return mid+1;

    return mid;
}

int main()
{
    GenerateNOD();
    GenerateNNOD();

    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++) {
        scanf("%d %d", &A, &B);
        //cout << binarySearch(A) << " " << binarySearch(B) << endl;
        int b = binarySearch(B);
        foundA = found;
        int a = binarySearch(A);
        foundB = found;
        if(foundA == true)
            cout << "Case " << tc << ": " << b - a + 1 << endl;
        else cout << "Case " << tc << ": " << b - a << endl;
    }

    return 0;
}
