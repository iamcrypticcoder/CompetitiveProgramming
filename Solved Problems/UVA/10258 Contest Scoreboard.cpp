#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<vector<bool> > VVB;

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
    int num, time, solved;
}TEAM;

vector<TEAM> team;
VVI penalty;
VVB isSolved;

bool comp(TEAM a, TEAM b)
{
    if(a.solved == b.solved) {
        if(a.time == b.time)
            return (a.num < b.num);
        return (a.time < b.time);
    }
    return a.solved > b.solved;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int conts, prob, time;
    char verdict;
    string line;

    cin >> TC;
    getchar();
    getchar();

    FOR(tc, 1, TC) {
        if(tc > 1) cout << "\n";

        team = vector<TEAM>(101);
        isSolved = vector<vector<bool> >(101);
        FOR(i, 1, isSolved.SZ-1)
            isSolved[i] = vector<bool>(10, false);

        penalty = VVI(101);
        FOR(i, 1, 100)
            penalty[i] = VI(10);

        FOR(i, 1, 100) {
            team[i].num = 0;
            team[i].solved = 0;
            team[i].time = 0;
        }

        while(getline(cin, line)) {
            if(line.SZ == 0) break;
            stringstream ss(line);

            ss >> conts;
            ss >> prob;
            ss >> time;
            ss >> verdict;

            team[conts].num = conts;

            if(verdict == 'I') {
                penalty[conts][prob]++;
            }
            else if(verdict == 'C') {
                if(isSolved[conts][prob] == false) {
                    isSolved[conts][prob] = true;
                    team[conts].time += time;
                    team[conts].time += (penalty[conts][prob] * 20);
                    team[conts].solved++;
                }
            }
        }

        sort(team.begin()+1, team.end(), comp);

        FOR(i, 1, 100) {
            if(team[i].num != 0)
                cout << team[i].num << " " << team[i].solved << " " << team[i].time << "\n";
        }


    }

    return 0;
}

