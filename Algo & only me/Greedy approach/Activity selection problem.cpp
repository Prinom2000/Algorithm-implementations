#include <iostream>
#include <algorithm>

using namespace std;

// A structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Comparator function to sort activities by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to find the maximum number of activities
int activitySelection(Activity activities[], int n) {
    // Sort activities by finish time
    sort(activities, activities + n, compare);

    int count = 1; // At least one activity can always be selected
    int lastFinishTime = activities[0].finish;

    // Iterate through the activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinishTime) {
            // Select the activity
            count++;
            lastFinishTime = activities[i].finish;
        }
    }
    return count;
}

int main() {
    // Input: Start and finish times of activities
    Activity activities[] = {
        {10, 20},
        {12, 25},
        {20, 30}
    };
    int n = sizeof(activities) / sizeof(activities[0]); // Number of activities

    // Calculate the maximum number of activities
    int maxActivities = activitySelection(activities, n);

    // Output the result
    cout << "Maximum number of activities: " << maxActivities << endl;

    return 0;
} - 1);
    quickSort(arr, j + 1, right);
}

int main()
{
    int n=3;
    int st[n]={10,12,20};
    int fin[n]={20,15,30};

     quickSort(fin, 0, n - 1);


}
