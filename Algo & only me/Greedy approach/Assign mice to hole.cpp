
#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate the minimum time required
int assignMiceToHoles(int mice[], int holes[], int n) {
    // Sort the positions of mice and holes
    sort(mice, mice + n);
    sort(holes, holes + n);

    // Calculate the maximum distance (time) for a mouse to reach a hole
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        maxTime = max(maxTime, abs(mice[i] - holes[i]));
    }

    return maxTime;
}

int main() {
    // Input: Positions of mice and holes
    int mice[] = {4, -4, 2};
    int holes[] = {4, 0, 5};
    int n = sizeof(mice) / sizeof(mice[0]); // Number of mice and holes

    // Calculate the minimum time
    int result = assignMiceToHoles(mice, holes, n);

    // Output the result
    cout << "Minimum time for all mice to get inside holes: " << result << endl;

    return 0;
}
