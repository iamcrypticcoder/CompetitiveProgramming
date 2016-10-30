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

#define SQR(x) ((x)*(x))
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

class HappyNumber {
public:
	bool used[243 + 1];
	bool HAPPY[729 + 1];
	
	void Init();
	bool isHappy(int num);
};

void HappyNumber::Init()
{
	int temp, num;

	memset(HAPPY, 0, sizeof(HAPPY));

	FOR(i, 1, 243) {
		temp = num = i;

		memset(used, 0, sizeof(used));

		while(used[num] != true && HAPPY[num] != true && num != 1) {
			used[num] = 1; temp  = 0;
			while(num != 0) {
				temp += SQR(num % 10);
				num /= 10;
			}
			num = temp;
		}
		if(num == 1 || HAPPY[num] == 1) 
			HAPPY[i] = 1;
	}
	
	FOR(i, 244, 729) {
		temp = num = i;
		temp = 0;
		while(num != 0) {
			temp += SQR(num % 10);
			num /= 10;
		}
		num = temp;
		HAPPY[i] = HAPPY[num];
	}

}

// This function can determine whether a number is HAPPY or NOT up to 999,999,999 because 9^2*9 = 729
bool HappyNumber::isHappy(int num)						
{
	int temp =  num;

	if(num <= 729) return HAPPY[num];

		temp = 0;
		while(num != 0) {
			temp += SQR(num % 10);
			num /= 10;
		}
		num = temp;

	return HAPPY[num];
}

int main()
{
    int TC, tc = 1, input;
    HappyNumber H;
    H.Init();
    
    cin >> TC;
    
    while(cin >> input)
    {
      if(H.isHappy(input))
        cout << "Case #" << tc++ << ": " << input << " is a Happy number.\n";
      else 
        cout << "Case #" << tc++ << ": " << input << " is an Unhappy number.\n";        
              
    }  

    return 0;    
}
