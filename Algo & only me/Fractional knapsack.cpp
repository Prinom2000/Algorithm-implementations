#include <iostream>
#include <algorithm>

using namespace std;

// A structure to represent an item with profit and weight
struct Item {
    double profit;
    double weight;
};

// Comparator function to sort items by profit/weight ratio
bool compare(Item a, Item b) {
    double r1 = a.profit / a.weight;
    double r2 = b.profit / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum profit for the fractional knapsack
double fractionalKnapsack(int W, Item items[], int n) {
    // Sort items by profit/weight ratio
    sort(items, items + n, compare);

    double totalProfit = 0.0; // Maximum profit
    for (int i = 0; i < n; i++) {
        if (W == 0) break; // If the knapsack is full, stop
        if (items[i].weight <= W) {
            // Take the full item
            totalProfit += items[i].profit;
            W -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalProfit += items[i].profit * (W / items[i].weight);
            W = 0; // Knapsack is full
        }
    }
    return totalProfit;
}

int main() {
    // Input: items and knapsack capacity
    Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    int n = sizeof(items) / sizeof(items[0]); // Number of items
    int W = 50; // Capacity of knapsack

    // Calculate maximum profit
    double maxProfit = fractionalKnapsack(W, items, n);

    // Output the result
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
