#include <bits/stdc++.h>

#define endl "\n"
typedef long long ll;
using namespace std;

ll n, m;
const ll INF = LLONG_MAX;

struct Edge {
    ll from, to, weight;
};

vector<int> restore_path(int s, int t, vector<int> const &p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // n: number of nodes, m: number of edges
    cin >> n >> m;
    vector<Edge> edges(m);

    for (ll i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    vector<ll> dis(n + 1, INF);
    vector<int> p(n + 1, -1);
    dis[1] = 0;

    int last_updated_node = -1;
    for (int i = 1; i <= n; i++) {
        last_updated_node = -1;
        for (Edge edge : edges) {
            if (dis[edge.from] < INF && dis[edge.from] + edge.weight < dis[edge.to]) {
                dis[edge.to] = dis[edge.from] + edge.weight;
                p[edge.to] = edge.from;
                last_updated_node = edge.to;
            }
        }
    }

    if (last_updated_node != -1) {
        cout << "Negative cycle detected, cannot find shortest paths." << endl;
    } else {
        // Assuming node will start from 1 and end on n.
        int to = n;
        vector<int> path = restore_path(1, to, p);
        if (dis[to] != INF) {
            cout << "The chosen path is:" << endl;
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << " ";
            }
        } else {
            cout << "This destination is unreachable from the source." << endl;
        }
    }

    cout << endl;
    return 0;
}
