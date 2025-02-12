#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
    
            if(head==NULL) return head;
            ListNode* start=head;
    
            set<int> st;
    
            while(head){
                st.insert(head->val);
                head=head->next;
            }
    
            ListNode* newStart=new ListNode(0);
    
            ListNode* tail=newStart;
            for(int it: st){
                ListNode* newNode=new ListNode(it);
                tail->next=newNode;
                tail=tail->next;
            }
    
    
    
            return newStart->next;
            
        }
    };