#include <iostream>
#include <algorithm>

using namespace std;

// Function to find the minimum number of platforms required
int findMinimumPlatforms(int arrival[], int departure[], int n) {
    // Sort arrival and departure times
    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int platforms = 0; // Current platforms in use
    int maxPlatforms = 0; // Maximum platforms needed

    int i = 0, j = 0; // Pointers for arrival and departure arrays

    // Traverse both arrays
    while (i < n && j < n) {
        if (arrival[i] < departure[j]) {
            // A train arrives before another departs
            platforms++;
            i++;
            maxPlatforms = max(maxPlatforms, platforms);
        } else {
            // A train departs
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}

int main() {
    // Input: arrival and departure times
    int arrival[] = {200, 210, 300, 320, 350, 500};
    int departure[] = {230, 340, 320, 430, 400, 520};
    int n = sizeof(arrival) / sizeof(arrival[0]); // Number of schedules

    // Calculate the minimum number of platforms
    int platforms = findMinimumPlatforms(arrival, departure, n);

    // Output the result
    cout << "Minimum number of platforms required: " << platforms << endl;

    return 0;
}

