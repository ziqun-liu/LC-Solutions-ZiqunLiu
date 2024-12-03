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
            // Time complexity of priority queue is O(N^2 * log(N))
            // as O(M * log(N)) = O(N*(N-1)/2*log(N)) = O(N^2 * log(N))
            // Worst case of m, the number of edges, is "n choose 2", which is n(n-1)/2
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

        // Find smallest
        int result = -1, minCount = n;
        for (int node = 0; node < n; ++node) { // Time complexity O(N)
            int count = dijkstra(node);
            if (count <= minCount) {
                minCount = count;
                result = node;
            }
        }
        return result;
    } // Time complexity O(N^3 * log(N)), n^2 is each node getting added to heap, log(n) is min heap
      // Adjacency list typically takes O(E + V), E being number of edges and V being number of vertices
      // In the worse case, a dense tree, number of edges can be calculated by V*(V-1)/2. Hence, O(E) = O(V^2)
      // Memorize: Dijkstra's algorithm takes O((V + E) * log(V)) = O((V + V^2) * log(V)) = O(V^2 * log(V))
      // In the end of this problem, the finding smallest step has a loop that takes O(N), and each loop runs dijkstra
      // once and hence the total time complexity is O(V * V^2 * log(V)) = O(V^3 * log(V))

      // Space complexity O(E + V) = O(V^2)

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
