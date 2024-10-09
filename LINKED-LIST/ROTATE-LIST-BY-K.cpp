#include<bits/stdc++.h>


using namespace std;

struct ListNode {

    int val;
    ListNode* next;

};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        
        // Find the length of the linked list
        int size = 0;
        ListNode* ptr = head;
        while (ptr != NULL) {
            ptr = ptr->next;
            size++;
        }
        
        // Adjust k to ensure it's within the bounds of the list length
        k = k % size;
        if (k == 0) return head;  // No rotation needed if k is 0 after modulo
        
        // Find the node before the new head (size - k - 1)
        ptr = head;
        for (int i = 0; i < size - k - 1; i++) {
            ptr = ptr->next;
        }
        
        // Perform the rotation
        ListNode* newHead = ptr->next;  // This will be the new head after rotation
        ptr->next = NULL;  // Break the list here
        
        ListNode* end = newHead;
        while (end->next != NULL) {
            end = end->next;
        }
        
        end->next = head;  // Connect the end of the list to the old head
        return newHead;
    }
};
