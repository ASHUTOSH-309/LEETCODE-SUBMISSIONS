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
    int LongestPathLength;
    int findMaxHeight(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = findMaxHeight(root->left);
        int rightHeight = findMaxHeight(root->right);

        LongestPathLength = max(LongestPathLength, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
            LongestPathLength=0;
        findMaxHeight(root);
        return LongestPathLength;
    }
};