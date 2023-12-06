#include <bits/stdc++.h>

#define endl "\n"
typedef long long ll;
using namespace std;

const ll INF = LLONG_MAX;

int main() {
    // n: number of nodes, m: number of edges
    ll n, m;
    cin >> n >> m;

    // Initialize the adjacency matrix with INF
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    // Initialize the diagonal elements with 0
    for (ll i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // Read edge weights and update the adjacency matrix
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    // Floyd-Warshall algorithm
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distances between all pairs of nodes
    cout << "Shortest distances between all pairs of nodes:" << endl;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
