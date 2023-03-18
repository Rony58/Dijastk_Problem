#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
using namespace std;

void dijkstra_single_dest(int start, int dest, vector<vector<pair<int, int>>> &graph) {
    int V = graph.size();

    vector<int> dist(V, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == dest) {
            break;
        }

        for (auto v : graph[u]) {
            int w = v.second;
            int new_dist = dist[u] + w;
            if (new_dist < dist[v.first]) {
                dist[v.first] = new_dist;
                pq.push(make_pair(new_dist, v.first));
            }
        }
    }

    cout << "Shortest distance from " << start << " to " << dest << " is: " << dist[dest] << endl;
}
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);
    cout << "Enter the edges and weights:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    int start, dest;
    cout << "Enter the start vertices: ";
    cin >> start >> dest;

    dijkstra_single_dest(start, dest, graph);
}
