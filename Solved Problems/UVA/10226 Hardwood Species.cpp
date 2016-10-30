#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

map<string, int> Tree;
map<string, int>::iterator it;


int main()
{
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);

    int TC, tc;
    string treeName;
    int numTree;

    cin >> TC;
    getline(cin, treeName);                 // Finish the line for TC input.
    tc = 1;

    while(TC--) {
        if(tc >= 2) cout << "\n";
        if(tc == 1) getline(cin, treeName);

        numTree = 0;
        while(getline(cin, treeName)) {
            if(treeName == "") break;

            Tree[treeName] = Tree[treeName] + 1;
            numTree++;
        }

        for(it = Tree.begin(); it != Tree.end(); it++) {
 //           cout << it->first << " " << it->second;
            cout << it->first << " ";
            printf("%0.4lf\n", (double)it->second*100/numTree);
        }

        tc++;
        Tree.clear();
 //       cout << "Size : " << Tree.size() << " ";
    }

    return 0;
}
