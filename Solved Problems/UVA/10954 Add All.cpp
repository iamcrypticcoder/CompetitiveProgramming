#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(i=(int)L; i<=(int)U; i++)

priority_queue <int, vector<int>, greater<int> > PQ;

int main()
{
    int N;
    int temp, i, j, k;
    int a, b, totalCost;

    while(cin >> N) {
        if(N == 0) break;

        FOR(i, 0, N-1) {
            cin >> temp;
            PQ.push(temp);
        }

        totalCost = 0;
        while(!PQ.empty()) {
            a = PQ.top();   PQ.pop();
            if(PQ.empty()) break;
            b = PQ.top();   PQ.pop();

            totalCost += (a+b);
            PQ.push(a+b);
        }
        cout << totalCost << "\n";
    }
    return 0;
}

