//SOURCE : http://stackoverflow.com/questions/12934213/how-to-find-out-geometric-median
 
// header files for IO functions and math
#include <cstdio>
#include <cmath>
 
// the maximul value n can take
const int maxn = 50001;
 
// given a point (x, y) on a grid, we can find its left/right/up/down neighbors
// by using these constants: (x + dx[0], y + dy[0]) = upper neighbor etc.
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
 
// controls the precision - this should give you an answer accurate to 3 decimals
const double eps = 0.001;
 
// input and output files
 
// stores a point in 2d space
struct punct
{
    double x, y;
};
 
// how many points are in the input file
int n;
 
// stores the points in the input file
punct a[maxn];
 
// stores the answer to the question
double x, y;
 
// finds the sum of (euclidean) distances from each input point to (x, y)
double dist(double x, double y)
{
    double ret = 0;
 
    for ( int i = 1; i <= n; ++i )
    {
        double dx = a[i].x - x;
        double dy = a[i].y - y;
 
        ret += sqrt(dx*dx + dy*dy); // classical distance formula
    }
 
    return ret;
}
 
// reads the input
void read()
{
    scanf("%d", &n); // read n from the first
 
    // read n points next, one on each line
    for ( int i = 1; i <= n; ++i )
        scanf("%lf %lf", &a[i].x, &a[i].y), // reads a point
        x += a[i].x,
        y += a[i].y; // we add the x and y at first, because we will start by approximating the answer as the center of gravity
 
    // divide by the number of points (n) to get the center of gravity
    x /= n;
    y /= n;
}
 
// implements the solving algorithm
void go()
{
    // start by finding the sum of distances to the center of gravity
    double d = dist(x, y);
 
    // our step value, chosen by experimentation
    double step = 100.0;
 
    // done is used to keep track of updates: if none of the neighbors of the current
    // point that are *step* steps away improve the solution, then *step* is too big
    // and we need to look closer to the current point, so we must half *step*.
    int done = 0;
 
    // while we still need a more precise answer
    while ( step > eps )
    {
        done = 0;
        for ( int i = 0; i < 4; ++i )
        {
            // check the neighbors in all 4 directions.
            double nx = (double)x + step*dx[i];
            double ny = (double)y + step*dy[i];
 
            // find the sum of distances to each neighbor
            double t = dist(nx, ny);
 
            // if a neighbor offers a better sum of distances
            if ( t < d )
            {
                //update the current minimum
                d = t;
                x = nx;
                y = ny;
 
                // an improvement has been made, so
                // don't half step in the next iteration, because we might need
                // to jump the same amount again
                done = 1;
                break;
            }
        }
 
        // half the step size, because no update has been made, so we might have
        // jumped too much, and now we need to head back some.
        if ( !done )
            step /= 2;
    }
}
 
int main()
{
    read();
    go();
    double res = 0.0;
    // print the answer with 4 decimal points
    for(int i = 1; i <= n; i++) {
        res += (double)sqrt((a[i].x-x)*(a[i].x-x) + (a[i].y-y)*(a[i].y-y));
    }
    printf("%.2f\n", res);
    return 0;
} 
