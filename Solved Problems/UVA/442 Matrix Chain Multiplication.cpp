#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
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

#define INF 999999999
#define MAX 27

typedef struct {
	int row, col;
} Matrix;

map<char,Matrix> M;

bool IsOperand(char ch)
{
	if(ch >= 'A' && ch <= 'Z')	return 1;
	else return 0;
}

string InfixToPostfix(string exp)
{
	stack<char> S;
	string POST;

	char ch, last, op;
	int ptr;

	S.push('(');
	exp += ')';

	ptr = 0;
	last = '0';
	while(!S.empty()) {
		ch = exp[ptr++];
		
		if(ch == '(') {
			if(IsOperand(last) || last == ')')
				S.push('*');
			S.push(ch);
		}
		else if(IsOperand(ch)) {
			if(IsOperand(last) || last == ')')
				S.push('*');
			POST.push_back(ch);
		}
		else if(ch == ')') {
			op = S.top();
			while(op != '(') {
				POST.push_back(S.top());
				S.pop();
				op = S.top();
			}
			S.pop();
		}

		last = ch;
	}

	return POST;
}

bool Evaluate(string exp, int &multi)
{
	stack<Matrix> S;
	int totalMulti=0, i;
	Matrix a, b, c;
	char ch;
	
	exp += ')';
	
	for(i=0; exp[i] != ')'; i++) {
		ch = exp[i];
		if(IsOperand(ch))
			S.push(M[ch]);
		else if(ch == '*') {
			a = S.top();			S.pop();
			b = S.top();			S.pop();
			if(b.col != a.row) return 0;
			totalMulti += (b.row * b.col * a.col);
			c.row = b.row;
			c.col = a.col;
			S.push(c);
		}
	}
	multi = totalMulti;
	return 1;
}

int main()
{
	int num_of_matrix;
	int temp;
	char ch;
	int row, col, ans;
	string exp;

		cin >> num_of_matrix;

		FOR(i, 1, num_of_matrix) {
			cin >> ch >> row >> col;
			M[ch].row = row;
			M[ch].col = col;
		}

		while(cin >> exp) {
			if(exp.size() == 1) {
				cout << "0\n";
				continue;
			}
			exp.erase(0, 1);
			exp.erase(exp.size()-1, 1);
//			cout << exp << "\n";
			exp = InfixToPostfix(exp);
			if(Evaluate(exp, ans))
				cout << ans << "\n";
			else cout << "error\n";
		}
	return 0;
}
