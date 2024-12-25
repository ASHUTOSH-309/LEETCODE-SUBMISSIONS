/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;


};
class Solution {
public:
 /*    int findHeight(TreeNode* root){
            if(root==NULL) return 0;


            int left=findHeight(root->left);
            int right=findHeight(root->right);

            return 1+max(left,right);

    } */


    vector<int> largestValues(TreeNode* root) {

        vector<int> largestValues;
        if(root==NULL) return largestValues;

        queue<TreeNode*> q;
        q.push(root);
        largestValues.push_back(root->val);
       // int heightofTree=findHeight(root);


        //int level=0;

        while (!q.empty()) {

            int size = q.size();
            int maxi = INT_MIN;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                    maxi = max(maxi, node->left->val);
                }

                if (node->right) {
                    q.push(node->right);
                    maxi = max(maxi, node->right->val);
                }
            }
               // if(level!=heightofTree-1)
                   largestValues.push_back(maxi);
                


          // level++;     
        }

        largestValues.pop_back();
        return largestValues;
    }
};