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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
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
typedef vector<string> VS;

map<string, char> M;
map<string, char>::iterator Mi;

int main()
{
//   READ("input.txt");
//    WRITE("output.txt");

    int i, j, k;
    int TC, tc;
    string line;

    M[".-"] = 'A';
    M["-..."] = 'B';
    M["-.-."] = 'C';
    M["-.."] = 'D';
    M["."] = 'E';
    M["..-."] = 'F';
    M["--."] = 'G';
    M["...."] = 'H';
    M[".."] = 'I';
    M[".---"] = 'J';
    M["-.-"] = 'K';
    M[".-.."] = 'L';
    M["--"] = 'M';
    M["-."] = 'N';
    M["---"] = 'O';
    M[".--."] = 'P';
    M["--.-"] = 'Q';
    M[".-."] = 'R';
    M["..."] = 'S';
    M["-"] = 'T';
    M["..-"] = 'U';
    M["...-"] = 'V';
    M[".--"] = 'W';
    M["-..-"] = 'X';
    M["-.--"] = 'Y';
    M["--.."] = 'Z';

    M["-----"] = '0';
    M[".----"] = '1';
    M["..---"] = '2';
    M["...--"] = '3';
    M["....-"] = '4';
    M["....."] = '5';
    M["-...."] = '6';
    M["--..."] = '7';
    M["---.."] = '8';
    M["----."] = '9';

    M[".-.-.-"] = '.';
    M["--..--"] = ',';
    M["..--.."] = '?';
    M[".----."] = '\'';
    M["-.-.--"] = '!';
    M["-..-."] = '/';
    M["-.--."] = '(';
    M["-.--.-"] = ')';
    M[".-..."] = '&';
    M["---..."] = ':';
    M["-.-.-."] = ';';
    M["-...-"] = '=';
    M[".-.-."] = '+';
    M["-....-"] = '-';
    M["..--.-"] = '_';
    M[".-..-."] = '"';
    M[".--.-."] = '@';

    cin >> TC;
    getline(cin, line);

    FOR(tc, 1, TC) {
        getline(cin, line);

        string latter = "";
        string message = "";
        int spaceCount = 0;
        FOR(i, 0, line.SZ-1) {
            if(line[i] != ' ') {
                latter += line[i];
                spaceCount = 0;
            }
            else if(line[i] == ' ') {
                spaceCount++;
                if(spaceCount == 2) {
                    message += ' ';
                    spaceCount = 0;
                }
                else if(latter.SZ != 0){
                    message += M[latter];
                    latter = "";
                }
            }
        }
        if(latter.SZ != 0) message += M[latter];

        cout << "Message #" << tc << "\n";
        cout << message << "\n";

        if(tc != TC) {
            cout << "\n";
        }
    }

	return 0;
}
