#include <iostream>
#include <bits/stdc++.h>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int count = 0;
    void PerformBfs(TreeNode* root, vector<TreeNode *>& parent) {

        if (root == NULL)
            return;
        if (count == 0) {
            parent[root->val] = NULL;
            count++;
        }
    
        PerformBfs(root->left, parent);
        PerformBfs(root->right, parent);

        if (root->left != NULL) {
            parent[root->left->val] = root;
        }
        if (root->right != NULL)
            parent[root->right->val] = root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode *> parent(pow(10, 6));
        PerformBfs(root, parent);

        TreeNode* pvalue = p;
        TreeNode* qvalue = q;

        while (pvalue != NULL) {
            while (qvalue!= NULL) {
                if(pvalue==qvalue){
                    return pvalue;
                }
                qvalue=parent[qvalue->val];
            }

            pvalue=parent[pvalue->val];
        }

        return root;
    }
};