#include<bits/stdc++.h>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

void ver_costs_dis(int start, vector<vector<pair<int, int>>> &graph, vector<int> &ver_costs) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> best_path;
    pq.push(make_pair(ver_costs[start], start));
    best_path[start] = ver_costs[start];

    while (!pq.empty()) {
        int curr_vertex = pq.top().second;
        pq.pop();
        if (best_path.count(curr_vertex) == 0) {
            best_path[curr_vertex] = pq.top().first;
        }
        for (auto neighbor : graph[curr_vertex]) {
            int neighbor_vertex = neighbor.first;
            int path_cost = neighbor.second;
            if (best_path.count(neighbor_vertex) == 0) {
                int new_cost = best_path[curr_vertex] + path_cost + ver_costs[neighbor_vertex];
                pq.push(make_pair(new_cost, neighbor_vertex));
            }
            else if (best_path[curr_vertex] + path_cost + ver_costs[neighbor_vertex] < best_path[neighbor_vertex]) {
                best_path[neighbor_vertex] = best_path[curr_vertex] + path_cost + ver_costs[neighbor_vertex];
                pq.push(make_pair(best_path[neighbor_vertex], neighbor_vertex));
            }
        }
    }

    for (auto vertex : best_path) {
        cout << "Best path to vertex " << vertex.first << " is " << vertex.second << endl;
    }
}

int main() {
    int num_ver, num_edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> num_ver >> num_edges;

    vector<vector<pair<int, int>>> graph(num_ver);
    vector<int> ver_costs(num_ver);

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < num_edges; i++) {
        int s, dest, w;
        cin >> s >> dest >> w;
        graph[s].push_back(make_pair(dest, w));
        graph[dest].push_back(make_pair(s, w));
    }

    cout << "Enter the vertex costs:" << endl;
    for (int i = 0; i < num_ver; i++) {
        cin >> ver_costs[i];
    }
    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    ver_costs_dis(start, graph, ver_costs);
}
