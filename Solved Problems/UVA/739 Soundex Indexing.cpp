#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;
typedef map<string, string> MSS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int retCode(char ch)
{
    char arr1[] = "AEIOUYWH";
    char arr2[] = "BPFV";
    char arr3[] = "CSKGJQXZ";

    if(strchr(arr1, ch))
        return 0;           // not encoded;
    else if(strchr(arr2, ch))
        return 1;
    else if(strchr(arr3, ch))
        return 2;
    else if(ch == 'D' || ch == 'T')
        return 3;
    else if(ch == 'L')
        return 4;
    else if(ch == 'M' || ch == 'N')
        return 5;
    else if(ch == 'R')
        return 6;

    return 0;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string input, output;
    int prev_code, cur_code;


    cout << "         NAME                     SOUNDEX CODE\n";
    while(cin >> input) {
        output.clear();
        output.PB(input[0]);
     //   output[1] =  output[2] = output[3] = '0';
        prev_code = retCode(input[0]);

        FOR(i, 1, input.SZ-1) {
            cur_code = retCode(input[i]);

            if(cur_code && cur_code != prev_code) {
                output.PB(char(cur_code + '0'));
                prev_code = cur_code;
            }

            if(cur_code != prev_code) prev_code = cur_code;
        }
        while(output.SZ < 4 ) output.PB('0');

        cout << "         " << input;
        FOR(i, 10+input.SZ, 35-1) cout << " ";
        cout << output.substr(0,4) << "\n";
    }
    cout << "                   END OF OUTPUT\n";


	return 0;
}
