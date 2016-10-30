/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
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

#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

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

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

char teamNames[16][15];
double P[16][16];
double S[16], F[16], W[16];

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    char str[100];

    FOR(i, 0, 15) {
        scanf("%s", teamNames[i]);
    }
    FOR(i, 0, 15) FOR(j, 0, 15) {
            int temp;
            scanf("%d", &temp);
            P[i][j] = (double)temp / 100;
    }

    //     Q[] = P[][] * (P[][]*P[][] + P[][]*P[][]);

    for(int i=0; i<16; i += 4) {
        S[i] = P[i][i+1] * (P[i][i+2]*P[i+2][i+3] + P[i][i+3]*P[i+3][i+2]);
        S[i+1] = P[i+1][i] * (P[i+1][i+2]*P[i+2][i+3] + P[i+1][i+3]*P[i+3][i+2]);

        S[i+2] = P[i+2][i+3] * (P[i+2][i]*P[i][i+1] + P[i+2][i+1]*P[i+1][i]);
        S[i+3] = P[i+3][i+2] * (P[i+3][i]*P[i][i+1] + P[i+3][i+1]*P[i+1][i]);
    }

    int a, b, c, d;
    for(int i=0; i<16; i += 8) {
        a = i + 4;
        b = i + 5;
        c = i + 6;
        d = i + 7;

        for(int j=i; j<i+4; j++) {
            F[j] = S[j] * ( S[a]*P[j][a] + S[b]*P[j][b] + S[c]*P[j][c] + S[d]*P[j][d]);
        }

        a = i;
        b = i+1;
        c = i+2;
        d = i+3;

        for(int j=i+4; j<i+4+4; j++) {
            F[j] = S[j] * ( S[a]*P[j][a] + S[b]*P[j][b] + S[c]*P[j][c] + S[d]*P[j][d]);
        }
    }

    FOR(i, 0, 7) {
        double p = 0.0;
        FOR(j, 8, 15)
            p += (F[j] * P[i][j]);
        W[i] = F[i] * p;
    }
    FOR(i, 8, 15) {
        double p = 0.0;
        FOR(j, 0, 7)
            p += (F[j] * P[i][j]);
        W[i] = F[i] * p;
    }


    FOR(i, 0, 15) {
        printf("%-10s p=%.2lf%%\n", teamNames[i], W[i]*100);

    }
/*
    int e, f, g, h;
    for(int i=0; i<16; i += 16) {
        double p = F[i];

        a = i + 8;
        b = i + 9;
        c = i + 10;
        d = i + 11;
        e = i + 12;
        f = i + 13;
        g = i + 14;
        h = i + 15;

        for(int j=0; j<i+8; j++) {
            W[j] = F[j] * ()
        }
    }


/*
    Q[0] = P[0][1] * (P[0][2]*P[2][3] + P[0][3]*P[3][2]);
    Q[1] = P[1][0] * (P[1][2]*P[2][3] + P[1][3]*P[3][2]);

    Q[2] = P[2][3] * (P[2][0]*P[0][1] + P[2][1]*P[1][0]);
    Q[3] = P[3][2] * (P[3][0]*P[0][1] + P[3][1]*P[1][0]);

    Q[4] = P[4][5] * (P[4][6]*P[6][7] + P[4][7]*P[7][6]);
    Q[5] = P[5][4] * (P[5][]*P[][] + P[][]*P[][]);

    Q[6] = P[6][7] * (P[6][]*P[][] + P[][]*P[][]);
    Q[7] = P[7][6] * (P[7][]*P[][] + P[][]*P[][]);

    Q[8] = P[8][9] * (P[8][]*P[][] + P[][]*P[][]);
    Q[9] = P[9][8] * (P[9][]*P[][] + P[][]*P[][]);
    Q[10] = P[10][11] * (P[10][]*P[][] + P[][]*P[][]);
    Q[11] = P[11][10] * (P[11][]*P[][] + P[][]*P[][]);
    Q[12] = P[12][13] * (P[12][]*P[][] + P[][]*P[][]);
    Q[13] = P[13][12] * (P[13][]*P[][] + P[][]*P[][]);
    Q[14] = P[14][15] * (P[14][]*P[][] + P[][]*P[][]);
    Q[15] = P[15][14] * (P[15][]*P[][] + P[][]*P[][]);
*/




    return 0;
}

