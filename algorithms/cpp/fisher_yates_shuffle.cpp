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

void randomize(vector<int>& arr) {
    int n = arr.size();
    srand(time(NULL));
    for (int i = n-1; i >= 0; i--) {
        int j = rand() % (i+1);
        swap(arr[i], arr[j]);
    }
}

/**
 * https://bost.ocks.org/mike/shuffle/
 * https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
 */
int main() {
    vector<int> arr {1, 2, 3, 4};

    randomize(arr);
    for (auto x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
