
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> Preorder(TreeNode *root)
{
    vector<int> ans;
    // For Iterative PreOrder Stack is required
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if (curr->right != NULL){
            st.push(curr->right);
        }

        if (curr->left != NULL){
            st.push(curr->left);
        }

    }

    return ans;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << Preorder(root).size() << endl;
    for (auto it : Preorder(root))
    {
        cout << it << "\t";
    }
}
