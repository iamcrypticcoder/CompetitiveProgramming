/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Undergraduate Student,
                Khulna University of Engineering and Technology (KUET),
                Khulna, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

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

struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};

typedef struct tree btree;

btree* setValue(int x)
{
	btree *p;
	p = new btree;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void preOrder(btree *bt)
{
	if(bt == NULL) return;
	cout << bt->info << " ";
	preOrder(bt->left);
	preOrder(bt->right);
}


void postOrder(btree *bt)
{
	if(bt == NULL) return;
	postOrder(bt->left);
	postOrder(bt->right);
	cout << bt->info;
}



#define MAXNODE 10001

class BTREE {
public:
	btree *root, *father, *new1;
	bool used[MAXNODE];
	int indexIn[MAXNODE];

	VI IN, POST;
	queue<btree*> Addr;
	queue<int> indexPost;

//	void Init();
	void InputInOrder(VI in);
	void InputPostOrder(VI post);

	void FindChild_PostIn(int parent, int &leftChild, int &rightChild);

	bool BuildTree();
	
//	void DFS(btree *t);

	void TraversePre();
	void TraversePost();
};



void BTREE::InputInOrder(VI in)
{
	int i;
	IN = in;
	for(i=0; i<IN.size(); i++)
		indexIn[IN[i]] = i;
}

void BTREE::InputPostOrder(VI post)
{
	POST = post;
}


void BTREE::FindChild_PostIn(int parent, int &leftChild, int &rightChild)
{
	int index_Post = INF, index_In = INF, i;
	int leftCount, rightCount;

	index_In = indexIn[parent];	
	index_Post = indexPost.front();
	indexPost.pop();

	leftCount = 0;
	for(i = index_In -1; i>=0; i--) {
		if(used[IN[i]] == 1)	break;
		leftCount++;
	}

	rightCount = 0;
	for(i = index_In +1; i<IN.size(); i++) {
		if(used[IN[i]] == 1)	break;
		rightCount++;
	}
	
	if(rightCount != 0) {
		rightChild = POST[index_Post-1];
		indexPost.push(index_Post-1);
	}
	else rightChild = -1;

	if(leftCount != 0) {
		leftChild = POST[index_Post-rightCount-1];
		indexPost.push(index_Post-rightCount-1);
	}
	else leftChild = -1;
	
}



bool BTREE::BuildTree()
{
	int leftChild, rightChild;
	
  memset(used, 0, sizeof(used));
	
		root = setValue(POST[POST.size()-1]);
		Addr.push(root);
		indexPost.push(POST.size()-1);
		used[POST[POST.size()-1]] = 1;
		
		while(!Addr.empty()) {
			father = Addr.front();
			FindChild_PostIn(father->info, leftChild, rightChild);

			if(rightChild > 0) { 
				father->right = setValue(rightChild);
				Addr.push(father->right);
				used[rightChild] = 1;
			}

			if(leftChild > 0) {  
				father->left = setValue(leftChild);
				Addr.push(father->left);
				used[leftChild] = 1;
			}

			Addr.pop();
   }
		
		return 1;

}

void BTREE::TraversePre()
{
	preOrder(root);	
}


void BTREE::TraversePost()
{
	postOrder(root);
}


int toInteger(string str)
{
	int ret = 0, i;
	ret = str[0] - '0';

	for(i = 1; i < str.size(); i++) {
		ret = (ret *= 10)+(str[i] - '0');
	}
	return ret;
}

// This function extracts all the words of a sentence and return as a vector of a string
// Caution : Each word must seperated by one space
vector<string> parseSentence(string main)
{
	vector<string> v;
	string temp = "something";
	int length = main.size(), i, j;

	for(i=0; i<=length; i++) {
		temp.clear();
		for(j=i; j<=length; j++) {
			if(main[j] == ' ') 	break;
			temp += main[j];
		}
		v.push_back(temp);
		i = j;
	}

	return v;
}	






int sum = 0;
int minValue = INF;
int leaf;


void TakeValue(int sum, int lf)
{
   if(minValue > sum) {
     minValue = sum;
     leaf = lf;
   } 
   else if(minValue == sum) 
     if(lf < leaf) leaf = lf;
}

void DFS(btree *t)
{
 if(t == NULL) return;
	sum += t->info;
	DFS(t->left);
	DFS(t->right);
	if(t->left == NULL && t->right == NULL) TakeValue(sum, t->info);
	sum -= t->info;
}

int main()
{
	BTREE b;
	string s;
	VI in, post;
	int temp;

	while(getline(cin, s)) {

		minValue = INF;
		sum = 0;

		istringstream sin1(s);
		while(sin1 >> temp)
			in.push_back(temp);

		getline(cin, s);
		istringstream sin2(s);
		while(sin2 >> temp)
			post.push_back(temp);


	//	b.InputPreOrder(pre);
		b.InputInOrder(in);
		b.InputPostOrder(post);	

		b.BuildTree();
//		b.TraversePre();
		DFS(b.root);
		cout << leaf << "\n";

		in.clear();
		post.clear();
	}
	return 0;
}
