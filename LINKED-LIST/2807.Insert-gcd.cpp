#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

    int findgcd(int num1, int num2)
    {

        int lesser = min(num1, num2);
        long long ans = 1;

        int i = 1;
        for (i = 1; i <= lesser; i++)
        {

            if (!num1 % i && !num2 % i)
            {
                ans = i;
            }
        }

        return i;
    }

public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {

        ListNode *ptr = head;
        long long count = 0;

        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }

        if (count == 1)
            return head;

        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr != NULL)
        {

            ListNode *newNode = new ListNode(gcd(prev->val, curr->val));

            prev->next = newNode;
            newNode->next = curr;

            prev = newNode->next;
            curr = curr->next;
        }

        return head;
    }
};

ListNode* generateLinkedList(ListNode *head)
{

    ListNode *tail = head;
    int count;
    cout << "Enter the number of nodes other than headNode you want in your linked list: ";
    cin >> count;

    while (count != 0)
    {
        int val;
        cout << "Enter value for the node: ";
        cin >> val;
        ListNode *newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
        count--;
    }
    return head;
}

void printLinkedList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val<<"\t";
        head = head->next;
    }
}

int main()
{

    cout << "Welcome to the Linked List generator Program"<<endl;
    int headval;
    cout << "Enter the value for the head Node: ";
    cin >> headval;
    ListNode *head = new ListNode(headval);
    ListNode *tail = head;

   head= generateLinkedList(head);
    printLinkedList(head);
}