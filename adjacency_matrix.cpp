#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int to;
    double weight;
};

int main() {
    int V = 5; // number of nodes
    vector<vector<Edge>> warehouseGraph(V);

    // Example: add edge from node 0 to 1 with weight 2.5
    warehouseGraph[0].push_back({1, 2.5});
    warehouseGraph[1].push_back({0, 2.5}); // if undirected

    // Print edges
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": ";
        for (auto &edge : warehouseGraph[i]) {
            cout << "(to: " << edge.to << ", weight: " << edge.weight << ") ";
        }
        cout << "\n";
    }
    return 0;
}
