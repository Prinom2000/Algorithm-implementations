// Dijkstra Algorithm
// Author: Shakib
// Single source multiple destination shortest path

#include <bits/stdc++.h>

#define endl "\n"
typedef long long ll;
using namespace std;

ll n, m;
const ll INF = LLONG_MAX;

vector<int> restore_path(int s, int t, vector<int> const &p)
{
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    // n: number of nodes, m: number of vertex
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);

    // a = from, b = to, c = weight
    ll a, b, c;
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> dis(n + 1, INF);
    vector<int> p(n + 1, -1);
    dis[1] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto &edge : adj[u])
        {
            ll v = edge.first;
            ll w = edge.second;

            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
                p[v] = u;
            }
        }
    }
    // assuming node will start from  1 and end on n.
    int to = n;
    vector<int> path = restore_path(1, to, p);
    if (dis[to] != INF)
    {
        cout << "The choosen path is: \n";

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
    else
        cout << "This destination is unreachable from the source. \n";
    cout << endl;
    return 0;
}
