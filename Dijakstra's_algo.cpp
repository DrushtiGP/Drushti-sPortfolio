#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    double weight;
};

vector<double> dijkstra(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<double> dist(n, 1e9);
    dist[start] = 0.0;

    using NodeDist = pair<double, int>;
    priority_queue<NodeDist, vector<NodeDist>, greater<NodeDist>> pq;
    pq.push({0.0, start});

    while (!pq.empty()) {
        auto nodeDistPair = pq.top();
        pq.pop();
        double curDist = nodeDistPair.first;
        int u = nodeDistPair.second;

        if (curDist > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.to;
            double w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);
    graph[0].push_back({1, 2.0});
    graph[1].push_back({2, 1.0});
    graph[0].push_back({3, 4.0});
    graph[3].push_back({4, 1.0});
    graph[2].push_back({4, 3.0});

    vector<double> distances = dijkstra(0, graph);
    for (int i = 0; i < V; i++) {
        cout << "Distance to node " << i << ": " << distances[i] << endl;
    }
    return 0;
}
