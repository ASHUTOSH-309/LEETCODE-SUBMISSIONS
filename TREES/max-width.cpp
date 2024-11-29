#include<bits/stdc++.h>

using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // Use a queue to hold pairs of node and its index
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});  // Start with index 0 for the root

        int global_maxima = 1;

        while (!q.empty()) {
            int size = q.size();
            long long leftmost = 0, rightmost = 0;

            for (int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                long long number = it.second;

                // Normalize the indices relative to the first node at each level
                if (i == 0) leftmost = number;  // First node at the current level
                if (i == size - 1) rightmost = number;  // Last node at the current level

                // Push left child with normalized index
                if (node->left != nullptr) {
                    q.push({node->left, 2 * (number - leftmost)});
                }

                // Push right child with normalized index
                if (node->right != nullptr) {
                    q.push({node->right, 2 * (number - leftmost) + 1});
                }
            }

            // Update the global maximum width of the binary tree
            global_maxima = max(global_maxima, (int)(rightmost - leftmost + 1));
        }

        return global_maxima;
    }
};
