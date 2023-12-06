#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double distance(const Point& a, const Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double bruteForce(vector<Point>& points, int left, int right) {
    double minDist = numeric_limits<double>::max();
    for (int i = left; i <= right; i++) {
        for (int j = i + 1; j <= right; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

double closestPair(vector<Point>& points, int left, int right) {
    if (right - left + 1 <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = (left + right) / 2;
    double dl = closestPair(points, left, mid);
    double dr = closestPair(points, mid + 1, right);
    double minDist = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - points[mid].x) < minDist) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    int stripSize = strip.size();
    for (int i = 0; i < stripSize; i++) {
        for (int j = i + 1; j < stripSize && strip[j].y - strip[i].y < minDist; j++) {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }

    return minDist;
}

double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), compareX);
    return closestPair(points, 0, points.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double minDist = closestPair(points);
    cout << "Closest pair distance: " << minDist << endl;

    return 0;
}
