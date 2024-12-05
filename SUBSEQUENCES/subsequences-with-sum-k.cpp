#include<bits/stdc++.h>

using namespace std;
void PrintSubsequencesWithSumK(int index,vector<int>arr,int n,int target,vector<int>&temp,int &sum){
   
    if(index>=n){
        if(sum==target){
            for(auto it: temp) cout<<it<<"\t";
            cout<<endl;
        }
        return;
    }


    temp.push_back(arr[index]);
    sum+=arr[index];
    PrintSubsequencesWithSumK(index+1,arr,n,target,temp,sum);

    temp.pop_back();
    sum-=arr[index];
    PrintSubsequencesWithSumK(index+1,arr,n,target,temp,sum);


}

int main(){

vector<int> arr={1,2,1,-2};
int target=2;
int n=arr.size();

int sum=0;
vector<int> temp;
PrintSubsequencesWithSumK(0,arr,n,target,temp,sum);




}