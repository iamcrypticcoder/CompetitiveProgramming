#include <iostream>

using namespace std;

int lastDigit[10][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {6, 2, 4, 8},
        {1, 3, 9, 7},
        {6, 4, 6, 4},
        {5, 5, 5, 5},
        {6, 6, 6, 6},
        {1, 7, 9, 3},
        {6, 8, 4, 2},
        {1, 9, 1, 9}
};

uint solve(uint a, uint b) {
    if (b == 0) return 1;
    a = a % 10;
    return lastDigit[a][b % 4];
}

int main() {
    int i, j, k;
    int TC, tc;
    double cl = clock();

    uint a, b;

    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        scanf("%u %u", &a, &b);
        printf("%u\n", solve(a, b));
    }
    return 0;
}
