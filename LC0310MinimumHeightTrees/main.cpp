#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(const int &n, vector<vector<int>> &edges) {
        if (n == 1) return {0}; // One node has no edge
        unordered_map<int, unordered_set<int>> adjacencySets;
        for (const vector<int> &edge: edges) {
            adjacencySets[edge[0]].insert(edge[1]);
            adjacencySets[edge[1]].insert(edge[0]);
        }

        vector<int> leafNodes;
        // Find leaf objects and place them in leafNodes array
        for (int i = 0; i < n; ++i) {
            if (adjacencySets[i].size() == 1)
                leafNodes.push_back(i);
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leafNodes.size(); // Deduct the number of leaf nodes
            vector<int> newLeafNodes;
            // Now traverse the leaf nodes
            for (const int &leafIndex: leafNodes) {
                // Traverse each integer element in leafIndex's corresponding adjacency set
                for (const int &adjNum: adjacencySets[leafIndex]) {
                    // For each integer in the set,
                    // remove leafIndex from this integer's corresponding set.
                    // Note that here adjNum is the index and the leafIndex is the element
                    // to be removed from adjNum's corresponding adjacency set
                    adjacencySets[adjNum].erase(leafIndex);
                    if (adjacencySets[adjNum].size() == 1)
                        newLeafNodes.push_back(adjNum);
                }
            }
            leafNodes = move(newLeafNodes);
        } // End while
        return leafNodes;
    } // Time complexity O(V + E)
      // Space complexity O(V + E)
};

int main() {

    return 0;
}
