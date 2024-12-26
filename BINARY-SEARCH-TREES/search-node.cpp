#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {

        TreeNode *node = NULL;

        while (root)
        {

            if (val < root->val)
            {
                root = root->left;
            }
            else if (val > root->val)
            {
                root = root->right;
            }
            else
            {
                node = root;
                break;
            }
        }

        return node;
    }
};