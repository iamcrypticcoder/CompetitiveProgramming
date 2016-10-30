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

VS words;
MSS m;

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string word, line;
    bool isMatch;

    while(getline(cin, line)) {
        if(line == "#") break;

        stringstream ss(line);
        while(ss >> word) {
            string temp = word;
            FOR(i, 0, word.SZ-1)
                word[i] = tolower(word[i]);
            sort(word.begin(), word.end());
            words.PB(word);
            m[word] = temp;
        }
    }

    FOR(i, 0, words.SZ-1) {
        word = words[i];

        isMatch = false;
        FOR(j, i+1, words.SZ-1) {
            if(word == words[j]) {
                words.erase(words.begin() + j);
                isMatch = true;
                j--;
            }
        }
        if(isMatch) {
            words.erase(words.begin() + i);
            i--;
        }
    }

    VS ans;
    FOR(i, 0, words.SZ-1)
        ans.PB(m[words[i]]);

    sort(ans.begin(), ans.end());

    FOR(i, 0, ans.SZ-1)
        cout << ans[i] << "\n";

    words.clear();
    m.clear();


	return 0;
}
