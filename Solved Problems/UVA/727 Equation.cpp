#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <vector>
using namespace std;



typedef vector<int> VI;
typedef vector<double> VD;


bool IsOperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/') 
		return true;
	return false;
}

bool IsOperand(char ch)
{
	if(ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '(' && ch != ')') 
		return true;
	return false;
}

int FindPrecedence(char ch)
{
	if(ch == '+' || ch == '-') return 1;
	if(ch == '*' || ch == '/') return 2;
}

int Evaluate(int x, char op, int y)
{
	if(op == '+')	return x+y;
	else if(op == '-') return x-y;
	else if(op == '*') return x*y;
	else if(op == '/') return x/y;
}


list<char> ToPostfix(string exp)
{

	int ptr, precedence;
	char ch, op;

// Converting INFIX TO POSTFIX
	stack<char> S;
	list<char> POST;
	S.push('(');

	ptr = 0;
	while(!S.empty()) {
		ch = exp[ptr++];
		
		if(IsOperand(ch)) POST.push_back(ch);
		else if(IsOperator(ch)) {
			precedence = FindPrecedence(ch);
			op = S.top();
			while(op != '(') {
				if(FindPrecedence(op) < precedence) break;
					POST.push_back(op);
					S.pop();
					op = S.top();
			}

			S.push(ch);
		}
		else if(ch == '(') S.push(ch);
		else if(ch == ')') {
			op = S.top();
			while(op != '(') {
				POST.push_back(S.top());
				S.pop();
				op = S.top();
			}
			S.pop();
		}	
		
	}
	
	return POST;
}


int main()
{
 //   freopen("E:\\input.txt", "r", stdin);
 //   freopen("E:\\output.txt", "w", stdout);
	int TC;
	string EXP, str;
	list<char> POST;
	list<char>::iterator p;
	char ch;

//	POST = ToPostfix("(3+2)*5)");
	

	cin >> TC;

	getline(cin, str);
	getline(cin, str);
	while(TC--) {
		while(getline(cin, str)) {
			if(str.size() == 0) break;
			EXP += str;
		}
		EXP += ")";
		if(EXP.size() <= 1) continue;
		POST = ToPostfix(EXP);
		EXP.clear();

		p = POST.begin();
		while(p != POST.end())
			cout << *p++ ;
		cout << "\n";
		if(TC != 0) cout << "\n";
	}


	return 0;
}
