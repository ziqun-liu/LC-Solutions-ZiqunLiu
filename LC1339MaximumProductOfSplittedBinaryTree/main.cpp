#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
public:
    class TwoPassDFS {
    public:
        static int maxProduct(TreeNode *root) {
            // max( (total_sum - subtree_sum) * subtree_sum)
            int totSum = getTotalSum(root);
            long long result = 0;
            getMaxProduct(root, totSum, result);
            return result % 1000000007;
        }
        static int getMaxProduct(TreeNode *root, int totSum, long long &result) {
            if (!root)
                return 0;
            int subTreeSum = getMaxProduct(root->left, totSum, result) +
                             getMaxProduct(root->right, totSum, result) +
                             root->val;
            long long kernel = 1LL * subTreeSum * (totSum - subTreeSum);
            result = max(result, kernel);
            return subTreeSum;
        }

        static int getTotalSum(TreeNode *root) {
            if (!root)
                return 0;
            else
                return getTotalSum(root->left) + getTotalSum(root->right) +
                       root->val;
        }
    };
};

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Maximum Product of Split Binary Tree: "
         << Solution::TwoPassDFS::maxProduct(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}

