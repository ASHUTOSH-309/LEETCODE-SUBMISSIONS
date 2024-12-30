#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void CountPossibleStrings(int CurrentSize,int& count,int Reqsize,int Zero, int One){

        if(CurrentSize>Reqsize) return;

        if(CurrentSize==Reqsize){
            count++;
            return;
        }

        CountPossibleStrings(CurrentSize+Zero,count,Reqsize,Zero,One);
        CountPossibleStrings(CurrentSize+One,count,Reqsize,Zero,One);
    }


    int countGoodStrings(int low, int high, int zero, int one) {
        int count=0;

        int sum=0;

        for(int i=low;i<=high;i++){
            CountPossibleStrings(0,count,i,zero,one);
            sum+=count;
            count=0;
        }
        return sum;        
    }
};