#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
bool CheckEqualTrees(TreeNode *root1, TreeNode *root2) {
    // Handle base case where both trees are empty
    if (!root1 && !root2) return true;
    // If only one of the roots is null, the trees are not equal
    if (!root1 || !root2) return false;

    // Perform simultaneous BFS on both trees
    std::queue<TreeNode *> q1;
    std::queue<TreeNode *> q2;

    q1.push(root1);
    q2.push(root2);

    while (!q1.empty() && !q2.empty()) {
        TreeNode* Nodefrom1 = q1.front();
        TreeNode* Nodefrom2 = q2.front();
        
        q1.pop();
        q2.pop();

        // Check if node values are different
        if (Nodefrom1->val != Nodefrom2->val) {
            return false;
        }

        // Check left children for both nodes
        if (Nodefrom1->left && Nodefrom2->left) {
            q1.push(Nodefrom1->left);
            q2.push(Nodefrom2->left);
        } else if (Nodefrom1->left || Nodefrom2->left) {
            // If only one node has a left child, trees are not equal
            return false;
        }

        // Check right children for both nodes
        if (Nodefrom1->right && Nodefrom2->right) {
            q1.push(Nodefrom1->right);
            q2.push(Nodefrom2->right);
        } else if (Nodefrom1->right || Nodefrom2->right) {
            // If only one node has a right child, trees are not equal
            return false;
        }
    }

    // Both queues should be empty if trees are identical
    return q1.empty() && q2.empty();
}


