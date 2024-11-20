#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {

        // Firstly, need to initialize an adjacent array
        // each element of which the index is "from", value is "to" and "distance"
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int> &edge: edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        for (int i = 0; i < adj.size(); i++) {
            cout << "From city " << i << ":";
            for (const pair<int, int> &edge: adj[i])
                cout << " to city " << edge.first << " (distance " << edge.second << ")";
            cout << endl;
        }

        // Lambda function implementing dijkstra algorithm
        auto dijkstra = [&](int src) -> int {
            // pair<int, int> is data type
            // vector<pair<int, int>> is the underlying container
            // greater<> is the comparator where the angle bracket is left empty
            // because pair<int, int> can be deduced (I still can't explain properly why)
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.push({0, src}); // 0 is total distance of node, src is node

            // Initialize a set to keep track of all the nodes that
            // we can reach starting from the src node under the threshold
            unordered_set<int> visited;

            while (!pq.empty()) {
                // currDistance is the total distance to reach curr
                auto [currDistance, curr] = pq.top();
                pq.pop();
                if (visited.contains(curr)) continue;
                visited.insert(curr);
                // Traverse neighbors of current node
                for (auto [neighbor, weight]: adj[curr]) {
                    int newDistance = currDistance + weight;
                    if (newDistance <= distanceThreshold)
                        pq.push({newDistance, neighbor});
                }
            }

            // Return all the node we can reach starting from the src node under the threshold
            // Minus 1 due to the src node does not count
            return visited.size() - 1;
        }; // Summarize Dijkstra: from current node, traverse neighbor nodes, update weight if new weight is smaller

        int result = -1, minCount = n;
        for (int node = 0; node < n; ++node) {
            int count = dijkstra(node);
            if (count <= minCount) {
                minCount = count;
                result = node;
            }
        }
        return result;
    } // Time complexity O(N^2 * log(N)), n^2 is each node getting added to heap, log(n) is min heap
      // Space complexity O(N)
};

int main() {
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3},
                                 {1, 2, 1},
                                 {1, 3, 4},
                                 {2, 3, 1}};
    int distanceThreshold = 4;

    cout << Solution::findTheCity(n, edges, distanceThreshold);
    return 0;
}
