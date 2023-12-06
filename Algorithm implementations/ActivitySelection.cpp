#include <bits/stdc++.h>
using namespace std; 

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

vector<Activity> activitySelection(std::vector<Activity>& activities) {
   sort(activities.begin(), activities.end(), compare);

    vector<Activity> selectedActivities;
    selectedActivities.push_back(activities[0]);

    int lastFinishTime = activities[0].finish;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinishTime) {
            selectedActivities.push_back(activities[i]);
            lastFinishTime = activities[i].finish;
        }
    }

    return selectedActivities;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the start and finish time of activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    vector<Activity> selectedActivities = activitySelection(activities);

    cout << "Selected activities:\n";
    for (const Activity& activity : selectedActivities) {
        cout << "Start time: " << activity.start << ", Finish time: " << activity.finish << std::endl;
    }

    return 0;
}
