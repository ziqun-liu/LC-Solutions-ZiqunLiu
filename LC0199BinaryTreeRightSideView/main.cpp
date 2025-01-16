﻿#include<iostream>
#include<vector>
#include<queue>

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
    // Time complexity O(N)
    // Space complexity O(N)
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;
        queue<TreeNode*> q;
        if (root)
            q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                if (i == size - 1)
                    result.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return result;
    }
};