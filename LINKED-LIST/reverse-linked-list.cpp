#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;  
};



ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head;
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
