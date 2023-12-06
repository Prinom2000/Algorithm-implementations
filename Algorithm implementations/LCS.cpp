#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3;
vector<vector<int>> dp(maxN, vector<int>(maxN, 0));

int lcs(string S, string S1, int m, int n)
{
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (S[i - 1] == S1[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}
void printTable(int m, int n) {


    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << " | " << dp[i][j];
            if(j == n) cout << " |";
        }
        cout << "\n";

    }

}

// intput:
// BCDAACD
// ACDBAC


int main() {

    string S,S1;
    cin >> S >> S1;

    cout << "Length of LCS is " << lcs(S, S1, S.size(), S1.size());
    cout << "\n";
    printTable(S.size(), S1.size());
    return 0;
}
