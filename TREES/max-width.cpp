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


struct TreeNode{
int val;
TreeNode* left;
TreeNode* right;

TreeNode(int x): val(val){}
}

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int global_maxima=1;
        
        while (!q.empty()) {
            int size = q.size();
            bool leftMostFound = false;

            int leftmost = 0;
            int rightmost = 0;
            int counter = 0;
            int breakbfs=true;
            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                counter++;
                if(node->val != -101) breakbfs=false;
                if (node->left != NULL) {
                    if (!leftMostFound) {
                        leftmost = counter;
                        leftMostFound = true;
                    }
                    rightmost=counter;
                    q.push(node->left);
                }
                else{
                    TreeNode* temp=new TreeNode(-101);
                    q.push(temp);
                }

                counter++;

                if(node->val != -101) breakbfs=false;
                if (node->right != NULL) {

                    if (!leftMostFound) {
                        leftmost = counter;
                        leftMostFound = true;
                    }
                    q.push(node->right);
                    rightmost = counter;
                }
                else{
                    TreeNode* temp=new TreeNode(-101);
                    q.push(temp);
                }


            }

            if(breakbfs) break;
            global_maxima=max(global_maxima,rightmost-leftmost+1);

        }

        return global_maxima;
    }
};