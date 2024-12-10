#include<bits/stdc++.h>

using namespace std;




  int maximumLength(string s) {

    int ans=0;

    int start=0;
    int end=0;
// s="cadbzabcd"
    unordered_map<char,int> mpp;
    while(start<s.size()){

        auto it=mpp.find(s[start]);

        if(it==mpp.end()){
          // When element is not present in the map, in the current string under consideration
            if(start-end+1>ans) ans=start-end+1;

        }
        else{
            // if element is found check if it is in the current bound
            if(mpp[s[start]]<end){
                  if(start-end+1>ans) ans=start-end+1;
            }
            else{
                end=mpp[s[start]]+1;
                 if(start-end+1>ans) ans=start-end+1;
                 mpp[s[start]]=start;
            }
        }



        start++;


    }





        
    return ans;


}