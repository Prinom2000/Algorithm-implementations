
#include <iostream>

using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    // Base case: If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill dp table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int set[n];
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    if (isSubsetSum(set, n, target))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
