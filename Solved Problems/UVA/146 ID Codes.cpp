#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
   string s, temp;
	while(getline(cin,s)) {
		if(s == "#") break;
		temp = s;				
      next_permutation(temp.begin(), temp.end());
		reverse(s.begin(), s.end());
		if(s == temp) {
			cout << "No Successor\n";
			continue;
		}
      cout << temp << endl;
  }
}