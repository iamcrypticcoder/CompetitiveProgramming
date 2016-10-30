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


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

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
		if(temp.size() > 0)	v.push_back(temp);
		i = j;
	}

	return v;
}	

bool isWord(string str)
{
	for(int i=0; i<str.size(); i++)
		if((str[i] >= 'A' &&  str[i] <= 'Z') || (str[i] >= 'a' &&  str[i] <= 'z'))
			return 1;
	return 0;
}

int main()
{
	string input;
	int count;

	vector<string> vs;

	while(getline(cin, input)) {
		
		for(int i=0; i<input.size(); i++) 
			if( !((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) )
				input[i] = ' ';

		vs = parseSentence(input);

		count = 0;
		for(int i=0; i<vs.size(); i++) {
//			cout << vs[i] << "\n";		
			if(isWord(vs[i]))
				count++;
		
		}
		cout << count << endl;

	}
 
	return 0;
}



// This!has,four.words?       --     4