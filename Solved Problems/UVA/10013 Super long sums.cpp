#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> table;
vector<int> ans;

void SHOW()
{
	int i;
	for(i=ans.size()-1; i>=0; i--)
		cout << ans[i];

}

int main()
{
	int i, j, B, M, a,b, carry,temp;

	scanf("%d", &B);

	for(i=1; i<= B; i++) {
		carry = 0;
		table.clear();
		ans.clear();
		scanf("%d", &M);
		
		for(j=0; j<M; j++) {
			scanf("%d %d", &a, &b);
			table.push_back(a+b);
		}

		for(j = M-1; j>=0; j--) {
			temp = table[j];
			ans.push_back( (temp+carry) % 10);
			carry = (temp+carry) / 10;
		}
		if(carry) ans.push_back(carry);
		
		//cout << "\n";
		SHOW();
		if(i<B) cout << "\n\n";
		else cout << "\n";
	}
	return 0;
}