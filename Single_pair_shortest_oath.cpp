#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& graph, int start, int dest) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    if (dist[dest] != INT_MAX) {
        cout << "Shortest distance from " << start << " to " << dest << " is: " << dist[dest] << endl;
    } else {
        cout << "No path from " << start << " to " << dest << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<pii>> graph(V);
    cout << "Enter the edges and weights:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    int start, dest;
    cout << "Enter the start vertices: ";
    cin >> start >> dest;
    dijkstra(graph, start, dest);
    return 0;
}
