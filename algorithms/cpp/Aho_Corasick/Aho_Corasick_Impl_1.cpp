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

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define MAX 100000
#define MAXS 500
#define MAXC 26

int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];

int buildMatchingMachine(vector<string> keys) {
    memset(out, 0, sizeof out);
    for (int i = 0; i < MAXS; ++i) memset(g[i], -1, sizeof g[i]);

    // Insert keys into regular trie
    int states = 1;
    for (int i = 0; i < keys.size(); ++i) {
        string key = keys[i];
        int curState = 0;
        for (int j = 0; j < key.length(); ++j) {
            int ch = key[j] - 'a';
            if (g[curState][ch] == -1) g[curState][ch] = states++;
            curState = g[curState][ch];
        }
        out[curState] |= (1 << i);
    }

    // Initialize values in fail function
    memset(f, -1, sizeof f);
    queue<int> q;

    for (int ch = 0; ch < MAXC; ++ch) {
        if (g[0][ch] != -1) {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        } else {
            g[0][ch] = 0;
        }
    }

    while (!q.empty()) {
        int state = q.front();
        q.pop();

        for (int ch = 0; ch < MAXC; ++ch) {
            if (g[state][ch] != -1) {
                // Find failure state of removed state
                int failure = f[state];

                // Find the deepest node labeled by proper
                // suffix of string from root to current
                // state.
                while (g[failure][ch] == -1)
                    failure = f[failure];

                failure = g[failure][ch];
                f[g[state][ch]] = failure;

                // Merge output values
                out[g[state][ch]] |= out[failure];

                // Insert the next level node (of Trie) in Queue
                q.push(g[state][ch]);
            }
        }
    }

    return states;
}

int findNextState(int curState, char nextInput) {
    int answer = curState;
    int ch = nextInput - 'a';
    while (g[answer][ch] == -1)
        answer = f[answer];
    return g[answer][ch];
}

void searchWords(vector<string> keys, string text) {
    buildMatchingMachine(keys);

    int curState = 0;
    for (int i = 0; i < text.length(); ++i) {
        curState = findNextState(curState, text[i]);
        if (out[curState] == 0) continue;
        for (int j = 0; j < keys.size(); ++j) {
            if ((out[curState] & (1 << j)) != 0) {
                printf("Word %s appears from %d to %d\n", keys[j].c_str(), i - keys[j].length() + 1, i);
            }
        }
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("input.txt");

    int i, j;
    int TC, tc;
    double cl = clock();

    vector<string> keys;
    keys.push_back("he");
    keys.push_back("she");
    keys.push_back("his");
    keys.push_back("hers");
    keys.emplace_back("");
    keys.emplace_back("a");
    keys.emplace_back("s");
    keys.emplace_back("x");
    keys.emplace_back("xy");
    keys.emplace_back("xyz");
    string text = "ashishers";

    searchWords(keys, text);

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
