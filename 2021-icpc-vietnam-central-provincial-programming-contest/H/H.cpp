#include <bits/stdc++.h>

using namespace std;

#define double long double

struct Point {
    double x, y;
    Point(): x(0), y(0) {}
    Point(double _x, double _y): x(_x), y(_y) {}
    Point add(Point other) {
        Point ans(x + other.x, y + other.y);
        return ans;
    }
    Point sub(Point other) {
        Point ans(x - other.x, y - other.y);
        return ans;
    }
    friend istream& operator>>(istream &is, Point &res) {
        return is >> res.x >> res.y;
    }
};

struct Line {
    double a, b, c;
    Line() {}
    Line(Point A, Point B) {
        Point u = B.sub(A);
        Point n(-u.y, u.x);
        a = n.x, b = n.y;
        c = -(a * B.x + b * B.y);
    }
    double dist(Point C) {
        double g = abs(a * C.x + b * C.y + c);
        double h = sqrt(a * a + b * b);
        return g / h;
    }
};

const double EPS = 1e-9;
const double PI = acos(-1);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.precision(17);
    cout << fixed;

    Point A, B, C;
    double R, P;
    cin >> A >> B >> C >> R >> P;
    P /= 100;
    Line AB(A, B);
    double d = AB.dist(C);
    if (d + EPS >= R) {
        cout << "NO\n";
        return 0;
    }
    double alpha = 2 * acos(d / R);
    double other_side = sqrt(R * R - d * d);
    double area = alpha / 2 * R * R - d * other_side;
    double pc = area / (PI * R * R);
    if (abs(pc - P) <= 0.05 + EPS) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}
/*
|a - b| <= 0
|a - b| <= EPS
-EPS <= a - b <= EPS
b - EPS <= a <= b + EPS
a <= b + EPS
b <= a + EPS
*/
