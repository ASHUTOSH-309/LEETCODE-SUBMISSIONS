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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {

        priority_queue<long long> pq;

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;

                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            pq.push(sum);
        }

        k = k - 1;
        while (k-- && !pq.empty())
        {
            pq.pop();
        }

        if (!pq.empty())
        {
            return pq.top();
        }
        else
        {
            return -1;
        }
    }
};
