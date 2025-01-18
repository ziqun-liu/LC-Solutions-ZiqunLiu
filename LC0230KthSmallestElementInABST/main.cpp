#include<iostream>
#include<vector>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution 
{
public:
    class InOrder
    { // Time O(N) - traverse all nodes, space O(N) - store all nodes
    public:
        int kthSmallest(TreeNode* root, int k)
        {
            vector<int> stack;
            dfs(root, stack);
            return stack[k - 1];
        }

        void dfs(TreeNode* node, vector<int> &vector)
        {
            if (!node)
                return;
            dfs(node->left, vector);
            vector.push_back(node->val);
            dfs(node->right, vector);
        }
    };


    class InOrderOptimal
    { // Time O(k) - first k nodes
      // Space O(H) - h is height of tree, the depth of recursive call stack is the height of tree
    public:
        int kthSmallest(TreeNode* root, int k)
        {
            vector<int> vector(2);
            vector[0] = k;
            dfs(root, vector);
            return vector[1];
        }

        void dfs(TreeNode* node, vector<int> &vector)
        {
            if (!node)
                return;
            
            dfs(node->left, vector);
            
            vector[0]--;
            if (vector[0] == 0)
            {
                vector[1] = node->val;
                return;
            }

            dfs(node->left, vector);
        }
    };


    class IterativeDFS
    {
        int kthSmallest(TreeNode* root, int k)
        {
            vector<TreeNode*> stack;
            TreeNode* curr = root;

            while (!stack.empty() || curr)
            {
                while (curr)
                {
                    stack.push_back(curr);
                    curr = curr->left;
                }

                curr = stack.back();
                stack.pop_back();

                k--;
                if (k == 0)
                    return curr->val;

                curr = curr->right;
            }
            return -1;
        }
    };
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
