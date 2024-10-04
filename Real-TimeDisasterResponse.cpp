#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

class Graph {
public:
    unordered_map<string, vector<pair<string, int>>> adjacency_list;

    void add_edge(const string& from, const string& to, int weight) {
        adjacency_list[from].push_back({to, weight});
        adjacency_list[to].push_back({from, weight}); // Since it's an undirected graph
    }

    vector<string> get_nodes() {
        vector<string> nodes;
        for (const auto& node : adjacency_list) {
            nodes.push_back(node.first);
        }
        return nodes;
    }
};

class DisasterResponse {
public:
    Graph& graph;

    DisasterResponse(Graph& g) : graph(g) {}

    unordered_map<string, int> dijkstra(const string& start) {
        // Get all nodes and set up distance vector
        vector<string> nodes = graph.get_nodes();
        unordered_map<string, int> distances;

        // Initialize distances with infinity
        for (const string& node : nodes) {
            distances[node] = numeric_limits<int>::max();
        }
        distances[start] = 0;

        // Priority queue to process nodes by the shortest known distance
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int current_distance = pq.top().first;
            string current_node = pq.top().second;
            pq.pop();

            // Skip if we already found a shorter path to this node
            if (current_distance > distances[current_node]) {
                continue;
            }

            // Explore neighbors
            for (const auto& neighbor : graph.adjacency_list[current_node]) {
                string neighbor_node = neighbor.first;
                int weight = neighbor.second;
                int new_distance = current_distance + weight;

                // Update the shortest path if a new shorter path is found
                if (new_distance < distances[neighbor_node]) {
                    distances[neighbor_node] = new_distance;
                    pq.push({new_distance, neighbor_node});
                }
            }
        }

        return distances;
    }
};

int main() {
    Graph disaster_graph;

    // Add roads between important locations
    disaster_graph.add_edge("Hospital", "Shelter", 10);
    disaster_graph.add_edge("Hospital", "SupplyDepot", 20);
    disaster_graph.add_edge("Shelter", "SupplyDepot", 5);
    disaster_graph.add_edge("Shelter", "AffectedArea", 15);
    disaster_graph.add_edge("SupplyDepot", "AffectedArea", 25);

    DisasterResponse response(disaster_graph);
    unordered_map<string, int> shortest_paths = response.dijkstra("Hospital");

    // Output shortest paths from Hospital
    cout << "Shortest paths from Hospital:" << endl;
    for (const auto& pair : shortest_paths) {
        cout << "To " << pair.first << ": " << pair.second << " minutes" << endl;
    }

    return 0;
}
