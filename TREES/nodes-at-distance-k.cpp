#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

void generateParentChildAssociation(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_Track)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left){
            parent_Track[node->left] = node;
            q.push(node->left);
        }
        
        if (node->right){
            parent_Track[node->right] = node;
            q.push(node->right);
        }
    }
}

void PrintNodesAtDistanceK(TreeNode *root, TreeNode *target, int k)
{

    unordered_map<TreeNode *, TreeNode *> parent_Track;
    generateParentChildAssociation(root, parent_Track);
    queue<TreeNode *> q;

    q.push(target);
    int level = 0;

    unordered_map<TreeNode *, bool> visited;
    visited[target] = true;
   
    int level = 0;
    while (!q.empty())
    {

        int size = q.size();
        if (level == k)
            break;
        level++;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                visited[node->left]=true;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]){
                visited[node->right]=true;
                q.push(node->right);
            }
            if(parent_Track[node] && !visited[parent_Track[node]]){
                visited[parent_Track[node]]=true;
                q.push(parent_Track[node]);
            }
        }
    }

    // Loop to print the nodes present at a diustance k from the target node

    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        cout<<node->val<<" ";
    }

}