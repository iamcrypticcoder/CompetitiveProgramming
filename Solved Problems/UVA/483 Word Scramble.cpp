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


// This function extracts all the words of a sentence and return as a vector of a string
// Caution : Each word must seperated by one space
vector<string> parseSentence(string main)
{
	vector<string> v;
	string temp = "something";
	int length = main.size(), i, j;

	for(i=0; i< length; i++) {
		temp.clear();
		for(j=i; j< length; j++) {
			if(main[j] == ' ') 	break;
			temp += main[j];
		}
		v.push_back(temp);
		i = j;
	}

	return v;
}



int main()
{
	
	string mainStr;
	vector<string> vs;

	int i;

	while(getline(cin, mainStr))
	{
		vs = parseSentence(mainStr);

		for( i=0; i<vs.size()-1; i++) {
			reverse(vs[i].begin(), vs[i].end());
			cout << vs[i] << " ";
		}
			reverse(vs[i].begin(), vs[i].end());
			cout << vs[i] << "\n";
	}

	return 0;
}