#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define MAX 25

int POS[MAX+1];
stack<int> S[MAX+1];
int numBlocks;

void Init()
{
	int i;
	FOR(i, 0, numBlocks-1) {
		S[i].push(i);
		POS[i] = i;
	}
}

void moveAontoB(int A, int B)
{
	int temp;
	int posA = POS[A];
	int posB = POS[B];
	
	while( (temp = S[posA].top()) != A) {
		S[posA].pop();
		S[temp].push(temp);
		POS[temp] = temp;
	}
	while( (temp = S[posB].top()) != B) {
		S[posB].pop();
		S[temp].push(temp);
		POS[temp] = temp;
	}
	S[posA].pop();
	S[posB].push(A);
	POS[A] = posB;

}

void moveAoverB(int A, int B)
{
	int temp;
	int posA = POS[A];
	int posB = POS[B];
	
	while( (temp = S[posA].top()) != A) {
		S[posA].pop();
		S[temp].push(temp);
		POS[temp] = temp;
	}
	S[posA].pop();
	S[posB].push(A);
	POS[A] = posB;
}

void pileAontoB(int A, int B)
{
	int temp;
	stack<int> tempS;
	int posA = POS[A];
	int posB = POS[B];
	
	while( (temp = S[posA].top()) != A) {					// Taking pile into a temp Stack
		S[posA].pop();
		tempS.push(temp);
	}
	S[posA].pop();
	tempS.push(temp);

	while( (temp = S[posB].top()) != B) {					// Returning Blocks over B
		S[posB].pop();
		S[temp].push(temp);
		POS[temp] = temp;
	}
		
	while(!tempS.empty()) {									// Putting temp Stack onto B.
		S[posB].push(tempS.top());
		POS[tempS.top()] = posB;
		tempS.pop();
	}
}

void pileAoverB(int A, int B)
{
	int temp;
	stack<int> tempS;
	int posA = POS[A];
	int posB = POS[B];
	
	while( (temp = S[posA].top()) != A) {					// Taking pile into a temp Stack
		S[posA].pop();
		tempS.push(temp);
	}
	S[posA].pop();
	tempS.push(temp);
		
	while(!tempS.empty()) {									// Putting temp Stack onto B.
		S[posB].push(tempS.top());
		POS[tempS.top()] = posB;
		tempS.pop();
	}
}

void Output()
{
	vector<int> v;
	int j;

	FOR(i, 0, numBlocks-1) {
		cout << i << ":";

		while(!S[i].empty()) {
			v.push_back(S[i].top());
			S[i].pop();
		}

		j = v.size()-1;
		while(j >= 0)
			cout << " " << v[j--];
		
		if(v.size() != 0) v.clear();
		cout << "\n";
	}
}


int main()
{
//	freopen("output.txt", "w", stdout);

    string s1, s2;
	int a, b;

	cin >> numBlocks;
	Init();

	while(cin >> s1) {
		if(s1 == "quit")
			break;
		cin >> a >> s2 >> b;
		
		if(a == b || POS[a] == POS[b]) continue;

		if(s1 == "move" && s2 == "onto") 
			moveAontoB(a, b);
		else if(s1 == "move" && s2 == "over")
			moveAoverB(a, b);
		else if(s1 == "pile" && s2 == "onto")
			pileAontoB(a, b);
		else if(s1 == "pile" && s2 == "over")
			pileAoverB(a, b);


	}
	Output();


	return 0;
}
