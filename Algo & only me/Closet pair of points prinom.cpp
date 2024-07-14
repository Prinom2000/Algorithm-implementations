#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

struct Point {
    int x, y;
};

// Function to calculate the distance between two points
double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// A utility function to find the distance between the closest points of the strip of a given size.
double stripClosest(Point strip[], int size, double d) {
    double min = d; // Initialize the minimum distance as d

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j) {
            if (distance(strip[i], strip[j]) < min) {
                min = distance(strip[i], strip[j]);
            }
        }
    }
    return min;
}

// A recursive function to find the smallest distance.
double closestUtil(Point Px[], Point Py[], int n) {
    if (n <= 3) {
        double min = std::numeric_limits<double>::max();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (distance(Px[i], Px[j]) < min) {
                    min = distance(Px[i], Px[j]);
                }
            }
        }
        return min;
    }

    int mid = n / 2;
    Point midPoint = Px[mid];

    Point Pyl[mid + 1]; // y sorted points on the left of the vertical line
    Point Pyr[n - mid - 1]; // y sorted points on the right of the vertical line

    int li = 0, ri = 0;
    for (int i = 0; i < n; i++) {
        if (Py[i].x <= midPoint.x && li < mid + 1) {
            Pyl[li++] = Py[i];
        } else {
            Pyr[ri++] = Py[i];
        }
    }

    double dl = closestUtil(Px, Pyl, mid);
    double dr = closestUtil(Px + mid, Pyr, n - mid);

    double d = std::min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(Py[i].x - midPoint.x) < d) {
            strip[j] = Py[i], j++;
        }
    }

    return std::min(d, stripClosest(strip, j, d));
}

double closest(Point P[], int n) {
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++) {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    std::sort(Px, Px + n, [](const Point &a, const Point &b) {
        return a.x < b.x;
    });
    std::sort(Py, Py + n, [](const Point &a, const Point &b) {
        return a.y < b.y;
    });

    return closestUtil(Px, Py, n);
}

int main() {
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    std::cout << "The smallest distance is " << closest(P, n) << std::endl;
    return 0;
}

