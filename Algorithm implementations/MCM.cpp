#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<int> arr;
int dp[500][500];
int N;

// This is just the recursion...
int MCM(int i, int j)
{
    if (i == j)
        return 0;
    int mini = INF;

    for (int k = i; k < j; k++)
    {
        int count = MCM(i, k) + MCM(k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, count);
    }

    return mini;
}

// This is Memo dp... I am going through a transition so everyone can understand

int mcmMemo(int i, int j)
{
    // Just added 4 lines to makes it dp. and the dp table.
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INF;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], mcmMemo(i, k) + mcmMemo(k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    }
    return dp[i][j];
}

// Now the tabular dp all code will stay same, just recursive call will be now replace with table.

int MCMTable(int n)
{

    int mcmTable[n+1][n+1];


    for (int i = 1; i <= n; i++)
        mcmTable[i][i] = 0;

    for (int L = 2; L <= n; L++)
    {
        for (int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            mcmTable[i][j] = INF;
            for (int k = i; k <= j - 1; k++)
            {
                int q = mcmTable[i][k] + mcmTable[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < mcmTable[i][j])
                    mcmTable[i][j] = q;
            }
        }
    }

    return mcmTable[1][n];
}

int main()
{
    cin >> N;
    arr.resize(N + 1);
    for (int i = 0; i <= N; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));

    cout << "Minimum number of multiplications is " << MCM(1, N - 1) << endl;
    cout << "Minimum number of multiplications is " << mcmMemo(1, N - 1) << endl;
    cout << "Minimum number of multiplications is " << MCMTable(N-1) << endl;

    return 0;
}
