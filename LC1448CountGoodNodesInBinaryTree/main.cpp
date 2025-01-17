#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Use DFS (Depth First Search) to traverse the tree,
// and constantly keep track of the current path maximum.

//     3 -> 1 -> 3 (break) -> 4 -> 5
// max 3,   3,   3            4,   5
class Solution {
public:
    class DFSRecursive1 {
        int count = 0;
    public:
        /**
         * Keep track of the count of good nodes
         * @param node TreeNode
         * @param maxVal int
         * @return
         */
        void dfs(TreeNode* node, int maxVal) {
            // Update maxVal if the current node's value is greater than or equal to maxVal
            // A "good node" in this context should be one whose value is greater than or equal to
            // the maximum value encountered along the path from the root to that node.
            if (node->val >= maxVal) ++count;
            // Traverse left branch
            if (node->left)
                dfs(node->left, max(node->val, maxVal));
            // Traverse right branch
            if (node->right)
                dfs(node->right, max(node->val, maxVal));
        }

        int goodNodes(TreeNode* root) {
            dfs(root, INT_MIN);
            return count;
        }
    };


    class DFSRecursive2
    {
    public:
        int goodNodes(TreeNode* root) {
            return dfs(root, root->val);
        }

        int dfs(TreeNode* node, int maxVal) {
            if (!node)
                return 0;

            int res = (node->val >= maxVal) ? 1 : 0;
            res += dfs(node->left, max(maxVal, node->val));
            res += dfs(node->right, max(maxVal, node->val));

            return res;
        }
    };


    class BFS
    {
        // O(N), O(N)
    public:
        int goodNodes(TreeNode* root)
        {
            int res = 0;
            queue<pair<TreeNode*, int>> q;
            q.push({ root, root->val });

            while (!q.empty())
            {
                auto [node, maxVal] = q.front();
                q.pop();

                if (node->val >= maxVal)
                    ++res;

                if (node->left)
                    q.push({node->left, max(node->val, maxVal)});

                if (node->right)
                    q.push({ node->right, max(node->right, maxVal) });
            }

            return res;
        }
    };
};

int main() {

    return 0;
}
