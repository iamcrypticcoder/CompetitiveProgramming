#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

VS scenes;
string ansMovie;
VI permu;
VS sceneUsed;

int PSScore(string s1, string s2)
{
    int minLength = min(s1.SZ, s2.SZ);
    FORD(i, minLength, 1) {
        if(s1.substr(s1.size() - i) == s2.substr(0, i))
            return i;
    }
    return 0;
}

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    int n;

   // cout << PSScore("ABCD", "BCDE");
    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        cin >> n;

        scenes = VS(n+1);
        permu = VI(n+1);
        FOR(i, 1, n) {
            cin >> scenes[i];
            permu[i] = i;
        }

        int minLength = INF;
        do {
            ansMovie = scenes[permu[1]];
            FOR(i, 2, n) {
                int scr = PSScore(ansMovie, scenes[permu[i]]);
                ansMovie = ansMovie + scenes[permu[i]].substr(scr);
            }
            minLength = min(minLength, (int)ansMovie.SZ);
        } while(next_permutation(permu.begin()+1, permu.end()));

        cout << "Case " << tc << ": ";
        cout << minLength << "\n";

    }

    return 0;
}

