#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define FOR(i, L, U) for(i=(int)L; i<=(int)U; i++)

typedef struct {
    int x1, y1;
    int x2, y2;
}line;

typedef struct {
    int x1, y1;
}point;

line LINE[10000];
point POINT[10000];
point pt;


int compare(const void *a, const void *b)
{
    return (max(((line*)b)->y1, ((line*)b)->y2) - max(((line*)a)->y1, ((line*)a)->y2));

}

int main()
{
  //  freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);

    int TC, lines, points;
    int i, j, k;
    int endX;
    int minX, maxX, minY, maxY;

    cin >> TC;

    while(TC--) {
        cin >> lines;

        FOR(i, 0, lines-1)
            cin >> LINE[i].x1 >> LINE[i].y1 >> LINE[i].x2 >> LINE[i].y2;


        qsort(LINE, lines, sizeof(line), compare);
    /*
        FOR(i, 0, lines-1)
            cout << LINE[i].x1 << LINE[i].y1 << LINE[i].x2 << LINE[i].y2 << "\n";
    */
        cin >> points;

        FOR(i, 0, points-1) {
            cin >> pt.x1 >> pt.y1;

            FOR(j, 0, lines-1) {

                minX = min(LINE[j].x1, LINE[j].x2);
                maxX = max(LINE[j].x1, LINE[j].x2);
                minY = min(LINE[j].y1, LINE[j].y2);
                maxY = max(LINE[j].y1, LINE[j].y2);

                if(minY == LINE[j].y1) endX = LINE[j].x1;
                else if(minY == LINE[j].y2) endX = LINE[j].x2;

                if(pt.y1 >= minY) {
                   if(pt.x1 >= minX && pt.x1 <= maxX){
                          pt.x1 = endX;
                          pt.y1 = minY;
                      }
                   }
            }

            cout << pt.x1 << "\n";
        }
        if(TC != 0) cout << "\n";
    }



    return 0;
}
