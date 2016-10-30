/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.078
    Rank :      273
    Complexity: O(n * (lgn)^2)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <float.h>

using namespace std;

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

typedef struct {
    double x, y;
} Point;

int N;                      // Number of Points given
Point pnts[10001];
Point minA, minB;           // two points of closest pair
double minDist;             // Distance of closest pair

bool compX(Point a, Point b)
{
    return (a.x < b.x);
}
bool compY(Point a, Point b)
{
    return (a.y < b.y);
}

void checkPair(Point a, Point b)
{
    double d = SQR(b.x-a.x)+SQR(b.y-a.y);
    if(d < minDist) {
        minDist = d;
        minA = a; minB = b;
    }
}

// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
void divideAndConquer(Point p[], int n)
{
    int i, j, cnt;
    vector<Point> strip;

    if(n == 2) checkPair(p[1], p[2]);         /* base cases */
    if(n <= 2) return;

    int mid = n / 2;                            // This is divide step
    divideAndConquer(p, mid);                   // This is the conquer step
    divideAndConquer(p + mid, n - mid);         // This is also conquer step

    /// Conbine step started
    /// Build an vector strip that contains points close (closer than min)
    /// to the line passing through the middle point
    for(i = 1; i <= n; i++)
        if(SQR(p[i].x - p[mid].x) < minDist) strip.push_back(p[i]);
    sort(strip.begin(), strip.end(), compY);                    // Sorting by y-coordinate

    // Find the closest points in strip.
    for(i = 0; i < strip.size(); i++) {
        if(SQR(strip[i].x - p[mid].x) >= minDist) break;
        for(j = i+1; j < strip.size(); j++) {
            if(SQR(strip[i].y - strip[j].y) >= minDist) break;
            checkPair(strip[i], strip[j]);
        }
    }
}

// Make sure points are stored in array from index 1
void closestPair(Point p[], int n)
{
    minDist = DBL_MAX;
    sort(p + 1, p + 1 + n, compX);
    divideAndConquer(p, n);
}

void showPnts()
{
    for(int i = 1; i <= N; i++) {
        printf("%lf %lf\n", pnts[i].x, pnts[i].y);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int i, j;

    while(scanf("%d", &N) == 1) {
        if(N == 0) break;
        for(i = 1; i <= N; i++)
            scanf("%lf %lf", &pnts[i].x, &pnts[i].y);

        closestPair(pnts, N);

        minDist = sqrt(minDist);
        if(minDist >= 10000.0) printf("INFINITY\n");
        else printf("%.4lf\n", minDist);
    }

    return 0;
}
