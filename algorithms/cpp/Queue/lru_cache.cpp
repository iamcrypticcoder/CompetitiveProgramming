/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

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
#include <unordered_map>

using namespace std;

int cacheSize;
list<int> cacheList;
unordered_map<int, list<int>::iterator> cacheMap;

void initCache(int n) {
    cacheSize = n;
    cacheList = list<int>(n);
    cacheMap = unordered_map<int, list<int>::iterator>();
}

void refer(int val) {
    // If not present in cache
    if (cacheMap.find(val) == cacheMap.end()) {
        // If cache if already full, remove last element
        if (cacheList.size() == cacheSize) {
            int it = cacheList.back();
            cacheList.pop_back();
            cacheMap.erase(it);
        }
    } else {
        cacheList.erase(cacheMap[val]);
    }
    cacheList.push_front(val);
    cacheMap[val] = cacheList.begin();
}

void printCache() {
    auto it = cacheList.begin();
    while (it != cacheList.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

int main() {
    initCache(4);
    vector<int> v {1, 2, 3, 1, 4, 5};
    for (int i = 0; i < v.size(); i++) {
        refer(v[i]);
    }
    printCache();

    cout << endl;
}