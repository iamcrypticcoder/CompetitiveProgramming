#include <iostream>
//#include <conio.h>
#include <vector>

using namespace std;

void PRINT(char cube[])
{
	for(int i=0; i<6; i++)
		cout << cube[i] << " ";
	cout << endl;
}

void COPY(char from[], char to[])
{
	for(int i=0; i<6; i++)
		to[i] = from[i];
}
 
bool IS_MATCH(char cube1[], char cube2[])
{
	int i;
	for(i=0; i<6; i++)
		if(cube1[i] != cube2[i])
			return false;

	return true;
}


void ROTATE_H(char a[])
{
	char array[6];
	COPY(a, array);

	a[0] = array[0];		a[1] = array[2];
	a[2] = array[4];		a[3] = array[1];
	a[4] = array[3];		a[5] = array[5];
}

void ROTATE_V(char a[])
{
	char array[6];
	COPY(a, array);

	a[0] = array[4];	a[1] = array[0];
	a[2] = array[2];	a[3] = array[3];
	a[4] = array[5];	a[5] = array[1];

}

void ROTATE_HV(char a[])
{
	char array[6];
	COPY(a, array);

	a[0] = array[2];	a[1] = array[1];
	a[2] = array[5];	a[3] = array[0];
	a[4] = array[4];	a[5] = array[3];

}


int main()
{
	char cube[6] = {'1','2','3','4','5','6'};
	char cube1[7] = "421653";
//	char cube2[6] = {'5', '1', '3', '4', '6', '2'};
	char cube2[7] = "624351";
	char temp[6], temp_H[6], temp_V[6], temp_HV[6], temp_1[6], temp_2[6];
	bool Is_break=0;
	int i, j, k;

	while(scanf("%6s%6s", &cube1, &cube2) != EOF) {
		Is_break = 0;

COPY(cube1, temp);
for(i=0; i<4 && Is_break == 0; i++) {
		//COPY(cube1, temp);
		ROTATE_H(temp);

		if(IS_MATCH(temp, cube2) == true)
			Is_break = 1;
		
		COPY(temp, temp_V);
		COPY(temp, temp_HV);

		for(j=0; j<3 && Is_break == 0; j++) {
			ROTATE_V(temp_V);
			ROTATE_HV(temp_HV);

			if(IS_MATCH(temp_V, cube2) == true || IS_MATCH(temp_HV, cube2) == true)
				Is_break = 1;

			COPY(temp_V, temp_1);
			COPY(temp_HV, temp_2);

			for(k=0; k<3 && Is_break == 0; k++) {
				ROTATE_HV(temp_1);
				ROTATE_V(temp_2);

			if(IS_MATCH(temp_1, cube2) == true || IS_MATCH(temp_2, cube2) == true)
				Is_break = 1;
			}
		}
	}

//******************************************************

COPY(cube1, temp);
for(i=0; i<4 && Is_break == 0; i++) {
		ROTATE_V(temp);

		if(IS_MATCH(temp, cube2) == true)
			Is_break = 1;

		COPY(temp, temp_H);
		COPY(temp, temp_HV);

		for(j=0; j<3 && Is_break == 0; j++) {
			ROTATE_H(temp_H);
			ROTATE_HV(temp_HV);

			if(IS_MATCH(temp_H, cube2) == true || IS_MATCH(temp_HV, cube2) == true)
				Is_break = 1;

			COPY(temp_H, temp_1);
			COPY(temp_HV, temp_2);

			for(k=0; k<3 && Is_break == 0; k++) {
				ROTATE_HV(temp_1);
				ROTATE_H(temp_2);

			if(IS_MATCH(temp_1, cube2) == true || IS_MATCH(temp_2, cube2) == true)
				Is_break = 1;
			}
		}
	}

//*************************************************

COPY(cube1, temp);
for(i=0; i<4 && Is_break == 0; i++) {
		ROTATE_HV(temp);

		if(IS_MATCH(temp, cube2) == true)
			Is_break = 1;
		
		COPY(temp, temp_H);
		COPY(temp, temp_V);
		for(j=0; j<3 && Is_break == 0; j++) {
			ROTATE_H(temp_H);
			ROTATE_V(temp_V);

			if(IS_MATCH(temp_H, cube2) == true || IS_MATCH(temp_V, cube2) == true)
				Is_break = 1;

			COPY(temp_H, temp_1);
			COPY(temp_V, temp_2);

			for(k=0; k<3 && Is_break == 0; k++) {
				ROTATE_V(temp_1);
				ROTATE_H(temp_2);

			if(IS_MATCH(temp_1, cube2) == true || IS_MATCH(temp_2, cube2) == true)
				Is_break = 1;
			}
		}
	}

	if(Is_break == 1)
		cout << "TRUE\n";
	else cout << "FALSE\n";
}				

//	getch();

return 0;
}