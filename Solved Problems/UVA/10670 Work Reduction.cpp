#include <iostream>
#include <math.h>
#include <stdio.h>
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

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
    string name;
    int cost;
}AGENCY;

int N, M, L;
vector<AGENCY> agency;

int minCost(int a, int b)
{
    int ret = 0;
    int reduce, curWork = N;

    while(curWork > M) {
        reduce = curWork - curWork / 2;
        if(curWork - reduce < M) {
            ret += ((curWork - M) * a);
            curWork -= reduce;
            break;
        }

        if((reduce * a) >= b) {
            ret += b;
            curWork -= reduce;
        }
        else {
            ret += (reduce * a);
            curWork -= reduce;
        }
    }

    return  ret;
}

bool comp(AGENCY a, AGENCY b)
{
    if(a.cost < b.cost)
        return true;
    else if(a.cost == b.cost) {
        if(a.name < b.name)
            return true;
        return false;
    }

    return false;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int  i, j ,k;
    int TC, tc;
    string line, name;
    int a, b, cost;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> N >> M >> L;
        getline(cin, line);

        agency = vector<AGENCY>(L+1);

        FOR(i, 1, L) {
            getline(cin, line);
            FOR(i, 0, line.SZ-1) {
                if(line[i] == ':' || line[i] == ',')
                    line[i] = ' ';
            }
            stringstream ss(line);

            ss >> name;
            ss >> a;
            ss >> b;

            cost = minCost(a, b);

            agency[i].name = name;
            agency[i].cost = cost;
        }

        sort(agency.begin()+1, agency.end(), comp);

        cout << "Case " << tc << endl;
        FOR(i, 1, L) {
            cout << agency[i].name << " " << agency[i].cost << "\n";
        }

    }

    return 0;
}

