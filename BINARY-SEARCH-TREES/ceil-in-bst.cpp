#include<bits/stdc++.h>
using namespace std;


struct Node{


    int data;
    Node* left;
    Node* right;
};

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    
    int ans=INT_MAX;
    
    while(root){
        
        if(root->data>input){
            
            ans=min(ans,root->data);
            root=root->left;
            
        }
        else if(root->data < input){
            
            root=root->right;
            
        }
        else{
            ans=root->data;
            break;
            
        }
        
        
        
    }
    if(ans==INT_MAX) return -1;
    return ans;
}