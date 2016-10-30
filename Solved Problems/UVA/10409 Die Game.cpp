#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char command[1024][6];

int top, bottom, north, south, east, west;
int top_temp, bottom_temp;

void North()
{
	top = south;
	bottom = 7 - top;
	north = top_temp;
	south = 7 - north;
	top_temp = top;	
	bottom_temp = bottom;
}

void South()
{
	top = north;
	bottom = 7 - top;
	north = bottom_temp;
	south = 7 - north;
	top_temp = top;
	bottom_temp = bottom;
}

void East()
{
	top = west;
	bottom = 7 - top;
	east = top_temp;
	west = 7 - east;
	top_temp = top;
	bottom_temp = bottom;
}

void West()
{
	top = east;
	bottom = 7 - top;
	east = bottom_temp;
	west = 7 - east;
	top_temp = top;
	bottom_temp = bottom;
}


int main()
{
	int num_of_cmds, i;
	
	while(scanf("%d", &num_of_cmds) && num_of_cmds != 0) {

		top_temp = top = 1;		bottom_temp = bottom = 6;		
		north = 2;	south = 5;	
		east = 4;	west = 3;

		for(i =0; i<num_of_cmds; i++) 
			scanf("%s", command[i]);

		for(i =0; i<num_of_cmds; i++) 

		if(strcmp(command[i],"north") == 0) 
			North();
		else if(strcmp(command[i],"south") == 0)
			South();
		else if(strcmp(command[i],"east") == 0)
			East();
		else if(strcmp(command[i],"west") == 0)
			West();
	

		cout << top << endl;
		//printf("%d %d %d %d %d %d\n", top, bottom, north, south, east, west);
	}
return 0;
}