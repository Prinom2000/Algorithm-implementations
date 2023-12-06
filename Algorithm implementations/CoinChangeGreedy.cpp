#include <bits/stdc++.h>
using namespace std; 

vector<int> coinChangeGreedy(int amount, const vector<int>& coins) {
    vector<int> result;

    int n = coins.size();
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            result.push_back(coins[i]);
            amount -= coins[i];
        }
    }

    return result;
}

int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coins: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> change = coinChangeGreedy(amount, coins);

    cout << "Selected Coins: ";
    for (int coin : change) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}
