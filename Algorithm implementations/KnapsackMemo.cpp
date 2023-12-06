#include <iostream>
#include <vector>
#include <cstring> // for memset

using namespace std;

const int MAX_N = 100; // maximum number of items
const int MAX_W = 1000; // maximum knapsack capacity

int n; // number of items
int weights[MAX_N]; // weight of each item
int values[MAX_N]; // value of each item
int capacity; // knapsack capacity

int dp[MAX_N + 1][MAX_W + 1]; // memoization table

int knapsack(int item, int remainingCapacity) {
    if (item == n || remainingCapacity == 0) {
        return 0;
    }

    if (dp[item][remainingCapacity] != -1) {
        return dp[item][remainingCapacity];
    }

    int withoutCurrentItem = knapsack(item + 1, remainingCapacity);
    int withCurrentItem = 0;

    if (weights[item] <= remainingCapacity) {
        withCurrentItem = values[item] + knapsack(item + 1, remainingCapacity - weights[item]);
    }

    dp[item][remainingCapacity] = max(withoutCurrentItem, withCurrentItem);
    return dp[item][remainingCapacity];
}

int main() {
    cin >> n >> capacity;

    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    memset(dp, -1, sizeof(dp)); // Initialize memoization table

    int maxTotalValue = knapsack(0, capacity);
    cout << "Maximum value: " << maxTotalValue << endl;

    return 0;
}
