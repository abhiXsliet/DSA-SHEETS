// https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/



#include <bits/stdc++.h>
using namespace std;
#define N 5
#define sq(x) ((x) * (x))

class line {
    public:
    int a, b, c; // ma + by + c = 0
    line(int a, int b, int c) {
        this->a = a; this->b = b; this->c = c;
    }
};

// The difference is purely in the syntax and the default access levels
// struct has already public access specifier, while class has to define it explicitly.
struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
};

double dist(double x, double y, point p) {
    return sqrt(sq(x - p.x) + sq(y - p.y));
}

// Compute total distance all points when choose point on given line has x-coordinate value as X
double compute(point p[], int n, line l, double X) {
    double res = 0;

    // calculate Y-coordinate for the given line l
    double Y = -1 * (l.a * X + l.c) / l.b;

    // sum all distances
    for (int i = 0; i < n; i++) {
        res += dist(X, Y, p[i]);
    }

    return res;
}

// fn. to find minimum total distance
double findOptimumCostsUtil(line l, point p[], int n) {
    double low  = -1e6;
    double high = 1e6;

    while ((high - low) > 1e-6) {
        // mid1 & mid2 are representative of x-coordinates of search space
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        // find the distances 
        double dist1 = compute(p, n, l, mid1);
        double dist2 = compute(p, n, l, mid2);
        
        // if mid2 point gives more total distance, skip third part
        if (dist1 < dist2) 
            high = mid2;
        // if mid1 point gives more total distance, skip first part
        else 
            low = mid1;
    } 
    // compute optimum distance cost by sending average of low and high as X
    return compute(p, n, l, (low + high) / 2);
}

double findOptimumCosts(line l, int points[N][2]) {
    point p[N];
    // converting 2D array input to point array
    for (int i = 0; i < N; i++) {
        p[i] = point(points[i][0], points[i][1]);
    }
    return findOptimumCostsUtil(l, p, N);
}

// TC : O(N^2)
// SC : O(N)
int main() {
    // line : x - y - 3 = 0
    line l(1, -1, -3);
    
    int points[N][2] = {{ -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }};

    cout << findOptimumCosts(l, points) << endl;
    return 0;
}