#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>>& graph, int start) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : graph[u]) {
            if (dist[u] != INT_MAX && dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << "Shortest distances from " << start << " to all other vertices:" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] != INT_MAX) {
            cout << i << ": " << dist[i] << endl;
        } else {
            cout << i << ": Not reachable" << endl;
        }
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> graph(V);
    cout << "Enter the Edges:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int start;
    cout << "Enter the start vertex: ";
    cin >> start;
    dijkstra(graph, start);
}
