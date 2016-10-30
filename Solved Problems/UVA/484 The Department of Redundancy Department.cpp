#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

map<int, int> m;
map<int, bool> f;
vector<int> serial;

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int temp, prev;

    while(cin >> temp) {
        m[temp]++;
        if(f.find(temp) == f.end()) {
            f[temp] = true;
            serial.push_back(temp);
        }
    }

    FOR(i, 0, serial.size()-1)
        cout << serial[i] << " " << m[serial[i]] << "\n";



    return 0;
}