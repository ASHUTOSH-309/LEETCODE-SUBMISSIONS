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
    // This function will populate the parent map
    void findParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root) return;
        
        if (root->left) {
            parent[root->left] = root;
            findParents(root->left, parent);
        }
        if (root->right) {
            parent[root->right] = root;
            findParents(root->right, parent);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent; // Map to store parent nodes
        //Child to parent mapping is used here
        findParents(root, parent); // Populate the parent map

        unordered_set<TreeNode*> ancestors; // Set to track ancestors of p

        // Trace back from p to the root and store all ancestors
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        // Now, trace back from q and the first ancestor found in the set is the LCA
        while (q) {
            if (ancestors.count(q)) {
                return q;
            }
            q = parent[q];
        }

        return nullptr; // Should not reach here if p and q are guaranteed to be in the tree
    }
};
