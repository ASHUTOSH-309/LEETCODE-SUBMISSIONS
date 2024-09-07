#include <iostream>
using namespace std;

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        return dfs(head, head, root);
    }

    bool dfs(ListNode *head, ListNode *cur, TreeNode *root)
    {
        if (cur == nullptr)
            return true; // Successfully matched the list,it implies that we have reached at the end of the linked
        // by traversing it completely, a subpath similar to the list has been found in the tree
        if (root == nullptr)
            return false; // Reached the end of the tree without matching, Matching didn't occur along the current //branch, a mismatch is there b/w any of the Treenode values and that of list values

        // current != NULL but root == NULL implies that all node matching didn't occur along this branch, some nodes were left

        if (cur->val == root->val)
        {
            cur = cur->next; // Move to the next list node if value matches
        }
        else if (head->val == root->val)
        {
            head = head->next; // Start new matching attempt if the value matches head of list
        }
        else
        {
            cur = head; // Reset the matching pointer
        }

        return dfs(head, cur, root->left) || dfs(head, cur, root->right); // Recursively check left and right subtrees
    }
};