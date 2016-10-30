#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define INF 99999

struct tree {
	char info;
	struct tree *left;
	struct tree *right;
};

typedef struct tree btree;


btree* setValue(char x)
{
	btree *p;
	p = new btree;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void postOrder(btree *bt)
{
	if(bt == NULL) return;
	postOrder(bt->left);
	postOrder(bt->right);
	cout << bt->info;
}

string IN, PRE;
bool used[100];

void FindChild(char parent, char &leftChild, char &rightChild)
{
	int indexPre = INF, indexIn = INF, i;
	int leftCount, rightCount;

	for(i=0; i<PRE.size(); i++) {
		if(indexPre != INF && indexIn != INF)	break;
		if(PRE[i] == parent) indexPre = i;
		if(IN[i] == parent) indexIn = i;
	}

	leftCount = 0;
	for(i = indexIn -1; i>=0; i--) {
		if(used[IN[i]] == 1)	break;
		leftCount++;
	}

	rightCount = 0;
	for(i = indexIn +1; i<IN.size(); i++) {
		if(used[IN[i]] == 1)	break;
		rightCount++;
	}
	
	leftChild = leftCount != 0 ? PRE[indexPre+1] : '\0';
	rightChild = rightCount != 0 ? PRE[indexPre+leftCount+1] : '\0';
	
}

btree *root, *father, *new1;
queue<btree*> Q;

int main()
{
	char leftChild, rightChild;
	
	
	while(cin >> PRE >> IN) {
		
	
	memset(used, 0, sizeof(used));
	root = setValue(PRE[0]);
	Q.push(root);
	used[PRE[0]] = 1;
	while(!Q.empty()) {
		father = Q.front();
		FindChild(father->info, leftChild, rightChild);
		if(leftChild != '\0') {  
			father->left = setValue(leftChild);
			Q.push(father->left);
			used[leftChild] = 1;
		}
		if(rightChild != '\0') { 
			father->right = setValue(rightChild);
			Q.push(father->right);
			used[rightChild] = 1;
		}
		Q.pop();
	}

	postOrder(root);
	cout << "\n";
	PRE.clear();
	IN.clear();
	}

	return 0;
}
