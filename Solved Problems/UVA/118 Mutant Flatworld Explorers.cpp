#include <stdio.h>
#include <string.h>

struct ROBOT {
	int X;
	int Y;
	char O;
};

int GRID[51][51];
int m, n;

//struct ROBOT robot;

void ChangeOrientation(struct ROBOT *rbt, char direction)
{
	if(direction == 'R') {
		if(rbt->O == 'E')
			rbt->O = 'S';
		else if(rbt->O == 'W')
			rbt->O = 'N';
		else if(rbt->O == 'N')
			rbt->O = 'E';
		else if(rbt->O == 'S')
			rbt->O = 'W';
	}
	else if(direction == 'L'){
		if(rbt->O == 'E')
			rbt->O = 'N';
		else if(rbt->O == 'W')
			rbt->O = 'S';
		else if(rbt->O == 'N')
			rbt->O = 'W';
		else if(rbt->O == 'S')
			rbt->O = 'E';
	}

}

void Forward(struct ROBOT *rbt)
{
	if(rbt->O == 'E')
		rbt->X++;
	else if(rbt->O == 'W')
		rbt->X--;
	else if(rbt->O == 'N')
		rbt->Y++;
	else if(rbt->O == 'S')
		rbt->Y--;

}

int Is_Lost(int X, int Y)
{
	return(X > m || Y > n || X<0 || Y<0);
		
}

int main()
{
	struct ROBOT robot;
	char command[101] = ""; 

	int prev_X, prev_Y, i;
	
	scanf("%d %d", &m, &n);
	while(scanf("%d %d %c", &robot.X, &robot.Y, &robot.O) != EOF) {
	scanf("%s", command);

	for(i=0; i < strlen(command); i++) {
		prev_X = robot.X;
		prev_Y = robot.Y;
		if(command[i] == 'F')
			Forward(&robot);
		else if(command[i] == 'R' || command[i] == 'L')
			ChangeOrientation(&robot, command[i]);
		
		if(Is_Lost(robot.X, robot.Y) == 1) {
			if(GRID[prev_X][prev_Y] == 1) {
				robot.X = prev_X;
				robot.Y = prev_Y;
			}
			else {
				GRID[prev_X][prev_Y] = 1;
				break;
			}
		}
	}
	if(Is_Lost(robot.X, robot.Y) == 1)
		printf("%d %d %c LOST\n", prev_X, prev_Y, robot.O);
	else
		printf("%d %d %c\n", robot.X, robot.Y, robot.O);
	}


 return 0;
}
