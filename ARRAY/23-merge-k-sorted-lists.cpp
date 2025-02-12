#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

 typedef long long int ll;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head=new ListNode(0);

        priority_queue<ll,vector<ll>,greater<ll>> pq;

        for(int i=0;i<lists.size();i++){
                ListNode* ptr=lists[i];
                while(ptr!=NULL){
                    pq.push(ptr->val);
                    ptr=ptr->next;
                }
        }

        ListNode* tail=head;
        while(!pq.empty()){

            ll ele=pq.top();
            pq.pop();

            ListNode* newNode=new ListNode(ele);

            tail->next=newNode;
            tail=newNode;
        }


        return head->next;
        
    }
};