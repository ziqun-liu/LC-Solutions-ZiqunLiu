﻿#include<iostream>
#include<vector>
#include<queue>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {
    }
};


class Solution 
{
    // Time complexity O(N) - each node is processed exactly once
    // Space complexity O(N) - to keep the output structure which contains N node values
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        
        queue<TreeNode*> q;
        if (root)
            q.push(root);

        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(level);
        }

        return result;
    }
};


int main()
{

	return 0;
}
