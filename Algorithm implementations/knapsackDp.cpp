#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3;
vector<vector<int>> dp(maxN, vector<int>(maxN, 0));
vector<int>weight(maxN);
vector<int>price(maxN);

int knapSack(int n, int W)
{

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(price[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
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

void printSequence(int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (dp[i][j] != dp[i - 1][j])
    {
        printSequence(i - 1, j - weight[i - 1]);
        cout << i << " ";
    }
    else if (dp[i][j] == dp[i - 1][j])
        printSequence(i - 1, j);
}

// intput:
// 4 5
// 2 3 4 5
// 3 4 5 6
int main() {

	int n, W;
	cin >>n>> W;

	for(int i = 0; i < n; i++) {
        cin >> weight[i];
	}

	for(int i = 0; i < n; i++) {
        cin >> price[i];
	}

	cout << knapSack(n,W);
	cout << "\n";

	// printTable(n,W);

}
