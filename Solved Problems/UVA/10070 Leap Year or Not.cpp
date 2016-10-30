#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    string input;
    int mod4, mod100, mod400, mod15, mod55;
    bool isLeap, isHulu, isBulu;

    bool isFirst = true;
    while(cin >> input) {

        if(!isFirst) {
            cout << endl;
        }
        isFirst = false;

        mod4 = mod100 = mod400 = mod15 = mod55 = 0;

        FOR(i, 0, input.size()-1) {
            mod4 = (mod4*10 + input[i]) % 4;
            mod100 = (mod100*10 + input[i] - '0') % 100;
            mod400 = (mod400*10 + input[i] - '0') % 400;
            mod15 = (mod15*10 + input[i] - '0') % 15;
            mod55 = (mod55*10 + input[i] - '0') % 55;
        }

        isLeap = isHulu = isBulu = false;

        if(mod400 == 0 || (mod4 == 0 && mod100 != 0)) {
            cout << "This is leap year.\n";
            isLeap = true;
        }
        if(mod15 == 0) {
            cout << "This is huluculu festival year.\n";
            isHulu = true;
        }
        if(isLeap && mod55 == 0) {
            cout << "This is bulukulu festival year.\n";
            isBulu = true;
        }

        if(!isLeap && !isHulu && !isBulu)
            cout << "This is an ordinary year.\n";
    }



	return 0;
}
