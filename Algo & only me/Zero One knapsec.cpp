#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
    int n = 4;
    int weight[] = { 2, 3, 4, 5 };
    int profit[] = { 3, 4, 5, 6 };
    int W = 8;

    cout << knapSack(W, weight, profit, n);
    return 0;
}
