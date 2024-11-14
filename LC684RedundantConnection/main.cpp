#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

using namespace std;

class Solution {
    unordered_set<int> seen;
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adjacencyLists;
        vector<int> lastRedundantEdge;

        for (const vector<int> &edge: edges) { // ex. edges = [[1,2],[1,3],[2,3]], edge = [1, 2]
            seen.clear();
            // Check if both nodes in the edge are already connected in the adjacencyLists
            // ex. edge[0] is 1, edge[1] is 2
            // If keys edge[0] and edge[1] are present, do dfs()
            if (adjacencyLists.count(edge[0]) && adjacencyLists.count(edge[1]) && dfs(adjacencyLists, edge[0], edge[1]))
                lastRedundantEdge = edge; // Update the last redundant edge

            // If keys edge[0] and edge[1] are not present, add the edge to the adjacencyLists
            adjacencyLists[edge[0]].push_back(edge[1]);
            adjacencyLists[edge[1]].push_back(edge[0]);
        }
        return lastRedundantEdge;
    }

private:
    bool dfs(const unordered_map<int, vector<int>> &graph, int node, int target) {
        if (seen.find(node) == seen.end()) { // If 'node' hasn't been visited
            seen.insert(node); // Mark 'node' as visited
            if (node == target) return true; // If node is the target, a path exists

            // Explore all neighbors of 'node'
            for (const int &neighbor: graph.at(node)) // Do not use graph[node] as it inserts a key "node"
                if (dfs(graph, neighbor, target)) return true;
        }
        return false;
    }
}; // Time complexity O(N^2)
// Space complexity O(N)

int main() {
    Solution solution;
    vector<vector<int>> edges = {{1, 2},
                                 {2, 3},
                                 {3, 4},
                                 {1, 4},
                                 {1, 5}};
    vector<int> result = solution.findRedundantConnection(edges);
    for (const int &x: result) cout << x << " ";
    return 0;
}
