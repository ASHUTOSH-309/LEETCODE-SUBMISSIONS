#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if(root==NULL ) return ans;
        // Perform Simple Bfs
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        while (!q.empty()) {
            int size = q.size();

            vector<int> Level(size); // List to store current level nodes
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (leftToRight)
                    Level[i] = node->val;
                if (!leftToRight)
                    Level[size - i - 1] = node->val;

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);

             
            }
         ans.push_back(Level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};