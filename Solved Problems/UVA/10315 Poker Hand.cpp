// WRONG ANSWER

#include <iostream>
#include <cstdlib>

using namespace std;

class PokerHand;

int Is_Straight_Flush(PokerHand PH);
int Is_Four(PokerHand PH);
int Is_FullHouse(PokerHand PH);
int Is_Flush(PokerHand PH);
int Is_Straight(PokerHand PH);
int Is_Three(PokerHand PH);
int Is_Two_Pair(PokerHand PH, int &top2, int &top3);
int Is_Pair(PokerHand PH, int &top2, int &top3, int &top4);
void HighCard(PokerHand Black, PokerHand White);			

void PrintPair(PokerHand Black, PokerHand White);
void PrintTwoPair(PokerHand Black, PokerHand White);
void Print(int, int);

/*
int comp(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b; 
	return *x-*y;
}
*/

int sort_function( const void *a, const void *b)
{
   return( strcmp((char *)a,(char *)b) );
}


bool Is_Same(int a, int b)
{
	return (a == b);
}

bool Is_Same(int a, int b, int c)
{
	return (a==b && b==c);
}

class Rank {
public:
	int order, top;
};

class PokerHand {
public:
	char Card[5][3];
	int Value[5];
	char Suit[5];

	int Input();
	void Parse();
	void Show();
	int ConvertValue(char ch);

};

/*int PokerHand ::Input()
{
	return(scanf("%2s %2s %2s %2s %2s", &Card[0], &Card[1], &Card[2], &Card[3], &Card[4]) != EOF);
}*/

int PokerHand::ConvertValue(char ch)
{
	if(ch != 'J' && ch != 'Q' && ch != 'K' && ch != 'A' && ch != 'T')	return (ch-48);
	else if(ch == 'T')	return 10;
	else if(ch == 'J')	return 11;
	else if(ch == 'Q')	return 12;
	else if(ch == 'K')	return 13;
	else if(ch == 'A')	return 14;
}

void PokerHand::Parse()
{
	int i;
	for(i=0; i<5; i++) {
		Value[i] = ConvertValue(Card[i][0]);
		Suit[i] = Card[i][1];
	}
	qsort(Value, 5, sizeof(Value[0]), sort_function);
}

void PokerHand::Show()
{
	int i;
	for(i=0;i<5; i++)
		cout << Value[i] << " ";
	cout << "\t\t";
	for(i=0;i<5; i++)
		cout << Suit[i] << " ";
	cout << "\n";
}

//-------------------------------------------------------------------------------
int Is_Straight_Flush(PokerHand PH)
{
	if(Is_Straight(PH) && Is_Flush(PH)) return PH.Value[4];
	else return 0;
}

//-------------------------------------------------------------------------------
int Is_Four(PokerHand PH)
{
	if(PH.Value[0] == PH.Value[1] && PH.Value[1] == PH.Value[2] && PH.Value[2] == PH.Value[3] && PH.Value[4] != PH.Value[0]) {
		return PH.Value[0];
	}
	else if(PH.Value[1] == PH.Value[2] && PH.Value[2] == PH.Value[3] && PH.Value[3] == PH.Value[4] && PH.Value[4] != PH.Value[0]) {
		return PH.Value[4];
	}
	return 0;
}

//-----------------------------------------------------------------------------------
int Is_FullHouse(PokerHand PH)
{
	if(Is_Same(PH.Value[0], PH.Value[1], PH.Value[2]) && Is_Same(PH.Value[3], PH.Value[4])) {
		return PH.Value[0];	
	}
	else if(Is_Same(PH.Value[2], PH.Value[3], PH.Value[4]) && Is_Same(PH.Value[0], PH.Value[1])) {
		return PH.Value[2];
	}
	return 0;
}

//-------------------------------------------------------------------------------
int Is_Flush(PokerHand PH)
{
	int i, j;
	char suit = PH.Suit[0];
 	
	for(i=1; i<5; i++)
		if(suit != PH.Suit[i])
			return 0;

	return PH.Value[4];
}

//-------------------------------------------------------------------------------
int Is_Straight(PokerHand PH)
{
	int i, j;
	for(i=0, j = PH.Value[i]; i<5; i++, j++)
		if(j != PH.Value[i])
			return 0;

	return PH.Value[4];
}

//--------------------------------------------------------------------------------
int Is_Three(PokerHand PH)
{
	if(Is_Four(PH) || Is_FullHouse(PH)) return 0;
	if(Is_Same(PH.Value[0], PH.Value[1], PH.Value[2]))	return PH.Value[0];
	if(Is_Same(PH.Value[2], PH.Value[3], PH.Value[4]))	return PH.Value[2];
	return 0;
}


//---------------------------------------------------------------------------
int Is_Two_Pair(PokerHand PH, int &top2, int &top3)
{	
	if(Is_Four(PH)) return 0;

	if(Is_Same(PH.Value[0], PH.Value[1]) && Is_Same(PH.Value[2], PH.Value[3])) {
		top2 = PH.Value[0];			top3 = PH.Value[4];
		return PH.Value[2];
	}
	else if(Is_Same(PH.Value[0], PH.Value[1]) && Is_Same(PH.Value[3], PH.Value[4])) {
		top2 = PH.Value[0];			top3 = PH.Value[2];
		return PH.Value[3];
	}
	else if(Is_Same(PH.Value[1], PH.Value[2]) && Is_Same(PH.Value[3], PH.Value[4])) {
		top2 = PH.Value[1];			top3 = PH.Value[0];
		return PH.Value[3];
	}
	return 0;
}

//--------------------------------------------------------------
int Is_Pair(PokerHand PH, int &top2, int &top3, int &top4)
{
	int t1,t2;
	if(Is_Four(PH) || Is_FullHouse(PH) || Is_Two_Pair(PH, t1, t2)) return 0;

	if(Is_Same(PH.Value[0], PH.Value[1])) {
		top2 = PH.Value[4];		top3 = PH.Value[3]; top4 = PH.Value[2];
		return PH.Value[0];
	}
	else if(Is_Same(PH.Value[1], PH.Value[2])) {
		top2 = PH.Value[4];		top3 = PH.Value[3]; top4 = PH.Value[0];
		return PH.Value[1];
	}
	else if(Is_Same(PH.Value[2], PH.Value[3])) {
		top2 = PH.Value[4];		top3 = PH.Value[1]; top4 = PH.Value[0];
		return PH.Value[2];
	}
	else if(Is_Same(PH.Value[3], PH.Value[4])) {
		top2 = PH.Value[2];		top3 = PH.Value[1]; top4 = PH.Value[0];
		return PH.Value[3];
	}
	return 0;
}

//--------------------------------------------------------------

Rank FindRank(PokerHand PH)
{
	Rank rnk;
	int t1, t2, t3, t4;
	
	rnk.order = 1;
	rnk.top = Is_Straight_Flush(PH);
	if(rnk.top) return rnk; 

	rnk.order = 2;
	rnk.top = Is_Four(PH);
	if(rnk.top) return rnk; 

	rnk.order = 3;
	rnk.top = Is_FullHouse(PH);
	if(rnk.top) return rnk; 

	rnk.order = 4;
	rnk.top = Is_Flush(PH);
	if(rnk.top) return rnk; 

	rnk.order = 5;
	rnk.top = Is_Straight(PH);
	if(rnk.top) return rnk; 

	rnk.order = 6;
	rnk.top = Is_Three(PH);
	if(rnk.top) return rnk; 

	rnk.order = 7;
	rnk.top = Is_Two_Pair(PH, t1, t2);
	if(rnk.top) return rnk; 

	rnk.order = 8;
	rnk.top = Is_Pair(PH, t1, t2, t3);
	if(rnk.top) return rnk;

	rnk.order = 9;
	rnk.top = PH.Value[4];
	return rnk;
}


void Calc(PokerHand Black, PokerHand White)
{
	Rank RB, RW;
	
	RB = FindRank(Black);
	RW = FindRank(White);
	
	if(RB.order < RW.order){
		cout << "Black wins.\n";
		return;
	}
	else if(RB.order > RW.order) {
		cout << "White wins.\n";
		return;
	}

	if(RB.order ==	9 || RB.order ==	4) HighCard(Black,  White);
	else if(RB.order == 1 || RB.order == 2 || RB.order == 3 || RB.order == 5 || RB.order == 6) Print(RB.top, RW.top);
	else if(RB.order == 7) PrintTwoPair(Black,  White);
	else if(RB.order == 8) PrintPair(Black,  White);

}

void HighCard(PokerHand Black, PokerHand White)
{
	int i, winner=3;
	
	for(i=4; i>=0; i--) 
		if(Black.Value[i] != White.Value[i]) {	
			if(Black.Value[i] > White.Value[i]) winner = 1;
			else winner = 2;
			break;
		}

	if(winner==1)	cout << "Black wins.\n";
	else if(winner==2)cout << "White wins.\n";
	else cout << "Tie.\n";
}

void Print(int a, int b)
{
	if(a > b)	cout << "Black wins.\n";
	else if(a < b) 	cout << "White wins.\n";
	else cout << "Tie.\n"; 
}

void PrintTwoPair(PokerHand Black, PokerHand White)
{
	int winner = 3;				// 1 for Black, 2 for White. 3 for Tie
	
	int tb1, tb2, tw1, tw2;

	int d;
	Is_Two_Pair(Black, tb1, tb2);
	Is_Two_Pair(White, tw1, tw2);
	
	if(tb1 != tw1)	winner = (tb1 > tw1) ? 1 : 2;	
	if(tb2 != tw2)	winner = (tb2 > tw2) ? 1 : 2;

	if(winner==1)	cout << "Black wins.\n";
	else if(winner==2)cout << "White wins.\n";
	else cout << "Tie.\n";
}

void PrintPair(PokerHand Black, PokerHand White)
{
	int winner = 3;

	int tb1, tb2, tw1, tw2, tb3, tw3; 
	Is_Pair(Black, tb1, tb2, tb3);
	Is_Pair(White, tw1, tw2, tw3);

	if(tb1 != tw1) winner = (tb1 > tw1) ? 1 : 2;	
	if(tb2 != tw2) winner = (tb2 > tw2) ? 1 : 2;
	if(tb3 != tw3) winner = (tb3 > tw3) ? 1 : 2;

	if(winner==1)	cout << "Black wins.\n";
	else if(winner==2)cout << "White wins.\n";
	else cout << "Tie.\n";

}

int main()
{
	PokerHand Black, White;
	Rank RB, RW;

//	freopen("E:\\input.txt", "r", stdin);
//	freopen("E:\\output.txt", "w", stdout);


//	while((scanf("%2s %2s %2s %2s %2s", &Black.Card[0], &Black.Card[1], &Black.Card[2], &Black.Card[3], &Black.Card[4]) == 5) && scanf("%2s %2s %2s %2s %2s", &White.Card[0], &White.Card[1], &White.Card[2], &White.Card[3], &White.Card[4])) {
 	while(scanf("%2s %2s %2s %2s %2s %2s %2s %2s %2s %2s", &Black.Card[0], &Black.Card[1], &Black.Card[2], &Black.Card[3], &Black.Card[4], &White.Card[0], &White.Card[1], &White.Card[2], &White.Card[3], &White.Card[4]) == 10) {
	
		Black.Parse();
//		Black.Show();
		White.Parse();
//		White.Show();
		
//	cout << Is_Three(Black);
//	cout << Is_Three(White);

	Calc(Black, White);

//		cout << RB.order << " " << RW.order << "\n";
	}

	return 0;
}
