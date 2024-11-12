#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> result;
        if (edges.empty() || !edges.size()) {
            result.push_back(0);
            return result;
        }

        vector<set<int>> adjacencyArray;
        for (const vector<int> &edge : edges) {
            adjacencyArray[edge[0]].insert(edge[1]);
            adjacencyArray[edge[1]].insert(edge[0]);
        }

        // Find leaf objects
        for (int i=0; i<n; ++i) {
            if (adjacencyArray[i].size() == 1)
                result.push_back(i);
        }

        while (n > 2) {

        }
    }
};

int main() {

    return 0;
}
