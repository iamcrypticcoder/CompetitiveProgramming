/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/


#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef vector<int> VI;



int main()
{
    int TC, tc;
    int input, minQ;
    VI ans;

    cin >> TC;


    while(TC--) {
        cin >> input;
        if(input < 10) {
            cout << input << "\n";
            continue;
        }

        if(ans.size() != 0) ans.clear();
        for(int i=9; i>=2; i--) {
            if(input % i == 0) {
                ans.push_back(i);
                input /= i;
            }
        }

        if(input != 1) {                            // Means not found.
            cout << "-1\n";
            continue;
        }

        minQ = 0;
        for(int i=0; i<ans.size(); i++) {
            minQ += ( pow(10.0, (double)i) * ans[i] );
        }


        cout << minQ << "\n";

    }

    return 0;
}
