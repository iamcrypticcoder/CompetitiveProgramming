#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

int digit[21] = {0, 1, 4, 7, 6, 5, 6, 3, 6, 9, 0,
                    1, 6, 3, 6, 5, 6, 7, 4, 9, 0};
int last_digit[101];

void Precalcute()
{
    last_digit[1] = 1;
    for(int i = 1, j = 1; i <= 100; i++, j = j%20+1)
        last_digit[i] = (last_digit[i-1] + digit[j]) % 10;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, ans, sum, series;
    string line;

    Precalcute();

    while(getline(cin, line)) {
        if(line == "0") break;

        if(line.size() >= 3)
            N = atoi(line.substr(line.size()-2).c_str());
        else N = atoi(line.c_str());

        cout << last_digit[N] << "\n";
    }
    return 0;
}
