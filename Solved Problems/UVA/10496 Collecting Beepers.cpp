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
typedef pair<int, int> II;



#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 20

vector<II> BEPPER;
vector<bool> used;
int X_SIZE, Y_SIZE;
int startX, startY;
int num_of_bepper;
int move, bCollected;
int minMove;

bool on_grid(int x, int y)
{
    return (x >=0 && x <= X_SIZE && y >=0 && y <= Y_SIZE);
}

void BackTrack(int x, int y)
{
    if(bCollected == num_of_bepper) {
        minMove = min(minMove, move + abs(x - startX) + abs(y - startY));
        return;
    }

    FOR(i, 1, num_of_bepper) {
        if(used[i] == false) {
            used[i] = true;
            move += (abs(x - BEPPER[i].first) + abs( y - BEPPER[i].second));
            bCollected++;
            BackTrack(BEPPER[i].first, BEPPER[i].second);
            used[i] = false;
            move -= (abs(x - BEPPER[i].first) + abs( y - BEPPER[i].second));
            bCollected--;
        }
    }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int u, v;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> X_SIZE >> Y_SIZE;
        cin >> startX >> startY;
        cin >> num_of_bepper;

        BEPPER = vector<II>(num_of_bepper+1);

        FOR(i, 1, num_of_bepper) {
            cin >> u >> v;
            II ii = II(u, v);
            BEPPER[i] = ii;
        }

        move = bCollected = 0;
        minMove = INF;

        used = vector<bool>(21, false);
        BackTrack(startX, startY);

        cout << "The shortest path has length " << minMove << "\n";

    }





    return 0;
}

