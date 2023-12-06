#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX; // Infinite value to represent infinite capacity

// This function performs a BFS to find an augmenting path in the residual graph
bool bfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
    int n = residualGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return visited[sink];
}

// Ford-Fulkerson algorithm to find the maximum flow in a flow network
int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residualGraph = graph; // Initialize the residual graph with the given capacities
    vector<int> parent(n);

    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent)) {
        int pathFlow = INF;

        // Find the minimum capacity edge in the augmenting path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Update the residual capacities of edges and reverse edges
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        // Add the path flow to the maximum flow
        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Read the capacities of edges in the graph
    for (int i = 0; i < m; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] = capacity;
    }

    int source, sink;
    cin >> source >> sink; // Source and sink nodes

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "Maximum Flow: " << maxFlow << endl;

    return 0;
}
