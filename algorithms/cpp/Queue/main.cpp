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

int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ret = INT_MIN;

    deque<pair<int, int>> dq;
    dq.push_back(make_pair(points[0][0], points[0][1]));
    for (int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];
        while (!dq.empty() && abs(x - dq.back().first) > k)
            dq.pop_front();

        auto it = dq.begin();
        while (it != dq.end()) {
            pair<int, int> p = *it;
            ret = max(ret, y + p.second + abs(x - p.first));
            it++;
        }
        dq.push_back(make_pair(x, y));
    }
    return ret;
}

int shortestSubarray(vector<int>& nums, int k) {
    int ret = INT_MAX;
    int n = nums.size();
    int prefixSum[n + 1];
    prefixSum[0] = 0;
    prefixSum[1] = nums[0];
    for (int i = 2; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }

    deque<int> dq;
    dq.push_back(1);
    for (int i = 2; i <= n; i++) {
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.back()-1] <= 0)
            dq.pop_back();

        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()-1] >= k) {
            ret = min(ret, i - dq.front() + 1);
            dq.pop_front();
        }

        dq.push_back(i);
    }
    return ret == INT_MAX ? -1 : ret;
}

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> sum = vector<vector<int>>(m+1);
    for (int i = 0; i <= m; i++)
        sum[i] = vector<int>(n+1, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<vector<int>> ret = vector<vector<int>>(m);
    for (int i = 0; i < m; i++) ret[i] = vector<int>(n, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a = i - k < 1 ? 1 : i - k;
            int b = j - k < 1 ? 1 : j - k;
            int c = i + k > m ? m : i + k;
            int d = j + k > n ? n : j + k;

            ret[i-1][j-1] = sum[c][d] - sum[a-1][b] - sum[c][b-1] + sum[a-1][b-1];
            cout << ret[i-1][j-1] << " ";
        }
        cout << endl;
    }
    return ret;
}

bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

string frequencySort(string s) {
    unordered_map<int, int> freqMap;
    for (int i = 0; i < s.length(); i++) {
        freqMap[s[i]]++;
    }
    cout << "Here 1";

    vector<pair<int, int>> pairs;
    for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
        pairs.push_back(make_pair(it->first, it->second));
    }
    sort(pairs.begin(), pairs.end(), compare);
    cout << "Here 2";

    string ret = "";
    for (int i = 0; i < pairs.size(); i++)
        if (pairs[i].second > 0) {
            char ch = (char)pairs[i].first;
            string s(pairs[i].second, ch);
            ret += s;
        }
    cout << "Here 3";
    return ret;
}

vector<string> topKFrequent(vector<string>& words, int k) {
    // Calc freq of words
    unordered_map<string, int> countMap;
    for (string w : words)
        countMap[w] += 1;

    // Init PQ
    auto comp = [](pair<string, int> p1, pair<string, int> p2) {
        if (p1.second == p2.second)
            return (p1.first.compare(p2.first) < 0);
        return p1.second > p2.second;
    };
    priority_queue<
            pair<string, int>,
            vector<pair<string, int>>,
            decltype(comp)> pq(comp);

    for (auto p : countMap) {
        printf("%s -> %d\n", p.first.c_str(), p.second);
        pq.push(p);
        if (pq.size() > k) pq.pop();
    }
    cout << "pq.size() = " << pq.size() << endl;

    vector<string> ret(k);
    for (int i = 0; i < k; i++) {
        ret[i] = pq.top().first;
        pq.pop();
    }

    return ret;
}

int countNicePairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<string, int> countMap;
    for (int x : nums) {
        string a = to_string(x);
        string b = a;
        reverse(b.begin(), b.end());
        string c = string(a.length(), 'x');
        for (int i = 0; i < a.length(); i++)
            c[i] = (char) (abs(a[i] - b[i]) + '0');
        countMap[c] += 1;
        cout << c << " = " << countMap[c] << endl;
    }
    int ret = 0;
    for (auto p : countMap) {
        int c = p.second;
        if (c < 2) continue;;
        ret += (c * (c-1) / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
//    vector<vector<int>> mat;
//    mat.push_back(vector<int> {1, 2, 3});
//    mat.push_back(vector<int> {4, 5, 6});
//    mat.push_back(vector<int> {7, 8, 9});
//    vector<vector<int>> ret = matrixBlockSum(mat, 1);

//    vector<int> v {1, 2, 2, 3, 8};
//    auto it = upper_bound(v.begin(), v.end(), 0);
//    cout << *it << endl;
//    cout << it - v.begin() << endl;

//    string s1 = "abd";
//    string s2 = "abc";
//    cout << s1.compare(s2) << endl;
//    vector<string> v {"i","love","leetcode","i","love","coding"};
//
//    topKFrequent(v, 2);

    vector<string> v {"i","love","leetcode","i","love","coding"};
    auto comp = [](string s1, string s2) {
        return s1 > s2;
    };
    sort(v.begin(), v.end(), comp);
    for (string str : v) {
        cout << str << " ";
    }
    cout << endl;
}