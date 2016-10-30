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

int N, M;
VI X, Y, Z;
int move;

void Print()
{
    if(move > 0) cout << "\n";
    cout << "A=>";
    if(X.SZ != 0) cout << "   " << X[0];
    FOR(i, 1, X.SZ-1)
        cout << " " << X[i];
    cout << "\n";

    cout << "B=>";
    if(Y.SZ != 0) cout << "   " << Y[0];
    FOR(i, 1, Y.SZ-1)
        cout << " " << Y[i];
    cout << "\n";

    cout << "C=>";
    if(Z.SZ != 0) cout << "   " << Z[0];
    FOR(i, 1, Z.SZ-1)
        cout << " " << Z[i];
    cout << "\n";
}

void Tower(int N, char x, char y, char z)
{
    if(move > M) {
        return;
    }
    if(N >= 1) {
        Tower(N-1, x, z, y);
        if(x == 'x' && y == 'y') {
            int temp = X[X.SZ-1];
            X.pop_back();
            Y.PB(temp);
        }
        else if(x == 'x' && y == 'z') {
            int temp = X[X.SZ-1];
            X.pop_back();
            Z.PB(temp);
        }
        else if(x == 'y' && y == 'x') {
            int temp = Y[Y.SZ-1];
            Y.pop_back();
            X.PB(temp);
        }
        else if(x == 'y' && y == 'z') {
            int temp = Y[Y.SZ-1];
            Y.pop_back();
            Z.PB(temp);
        }
        else if(x == 'z' && y == 'x') {
            int temp = Z[Z.SZ-1];
            Z.pop_back();
            X.PB(temp);
        }
        else if(x == 'z' && y == 'y') {
            int temp = Z[Z.SZ-1];
            Z.pop_back();
            Y.PB(temp);
        }
        move++;
        if(move <= M ) Print();
        Tower(N-1, z, y, x);
    }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;


    tc = 1;
    while(cin >> N >> M) {
        if(N == 0 && M == 0) break;

        FORD(i, N, 1)
            X.PB(i);

        move = 0;

        cout << "Problem #" << tc << "\n\n";

        Print();

        Tower(N, 'x', 'z', 'y');


        cout << "\n";

        X.clear();
        Y.clear();
        Z.clear();

        tc++;
    }

    return 0;
}

