#include <stdio.h>
#include <iostream>

using namespace std;

int lastDigit[10001];

void PreCalculate()
{
    lastDigit[1] = 1;
    for(int num = 2; num <= 10000; num++) {
 //       cout << num << "\n";
        int temp = lastDigit[num-1] * num;
 //       cout << temp << "\n";
        while(temp % 10 == 0)
            temp /= 10;

        lastDigit[num] = temp % 100000;             //  Used 100000 > 10000 cause I dont want to loss some data
						    // Example : 45 * 6 = 270 but 5 * 6 = 30(which is wrong)
    }
}


int main()
{
    int N;

    PreCalculate();

    while(cin >> N) {
        printf("%5d -> %d\n", N, lastDigit[N] % 10);

    }

    return 0;
}
