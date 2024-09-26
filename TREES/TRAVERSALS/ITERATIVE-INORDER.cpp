
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

vector<int> Inorder(TreeNode *root)
{
    vector<int> ans;
    // For Iterative Inorder Stack is required
    stack<TreeNode *> st;

    st.push(root);

    TreeNode *curr = root;

    while (!st.empty())
    {

        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }

    return ans;
}

int main()
{

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    for (auto it : Inorder(root))
    {
        cout << it << "\t";
    }
}
