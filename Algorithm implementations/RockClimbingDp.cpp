#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> C(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> C[i][j];
        }
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    for (int j = 1; j <= m; ++j) {
        dp[n][j] = C[n][j];
    }
    
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = C[i][j] + min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
        }
    }
    
    int minTotalDanger = INF;
    for (int j = 1; j <= m; ++j) {
        minTotalDanger = min(minTotalDanger, dp[1][j]);
    }
    
    cout << minTotalDanger << endl;
    
    return 0;
}
