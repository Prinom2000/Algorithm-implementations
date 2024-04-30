#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int minCoins(int coins[], int n, int K) {

    int dp[n + 1][K + 1];

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int j = 1; j <= K; ++j)
        dp[0][j] = INT_MAX;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
//            else{
//                if (dp[i][j - coins[i - 1]] == INT_MAX)
//                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
//            }

        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=K; j++){
            cout<< dp[i][j]<< " ";
        }
        cout<< endl;
    }

    return dp[n][K] == INT_MAX ? -1 : dp[n][K];
}

int main() {
    int coins[] = {1, 6,8, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int K = 11;
    cout << "Minimum number of coins required: " << minCoins(coins, n, K) << endl;
    return 0;
}
