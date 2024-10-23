#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    void bfsAndReplace(TreeNode *root, vector<long long> &levelSums)
    {

        if (root == NULL) return;
        queue<TreeNode *> q;
        root->val = 0;
        q.push(root);

        if (root->left != NULL)  root->left->val = 0;
        if (root->right != NULL) root->right->val = 0;

        long long level = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                long long LeftAndRightSum = 0;

                if (node->right != NULL) LeftAndRightSum += node->right->val;

                if (node->left != NULL) LeftAndRightSum += node->left->val;

                if (node->left != NULL)
                {
                    if (level != 1)
                    {
                        node->left->val = levelSums[level] - LeftAndRightSum;
                    }
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    if (level != 1)
                    {
                        node->right->val = levelSums[level] - LeftAndRightSum;
                    }
                    q.push(node->right);
                }
            }

            level++;
        }
    }

    void bfsAndStoreLevelSums(TreeNode *root, vector<long long> &levelSums)
    {

        queue<TreeNode *> q;
        q.push(root);
        levelSums.push_back(root->val);

        while (!q.empty())
        {

            int size = q.size();
            long long sum = 0;
            for (int i = 0; i < size; i++)
            {

                TreeNode *node = q.front();
                q.pop();

                if (node->left != NULL)
                {
                    q.push(node->left);
                    sum += node->left->val;
                }

                if (node->right != NULL)
                {
                    q.push(node->right);
                    sum += node->right->val;
                }
            }

            if (sum != 0)
                levelSums.push_back(sum);
        }
    }

    TreeNode *replaceValueInTree(TreeNode *root)
    {

        if (root == NULL)
            return root;

        vector<long long> levelSums;
        bfsAndStoreLevelSums(root, levelSums);
        bfsAndReplace(root, levelSums);

        return root;
    }
};