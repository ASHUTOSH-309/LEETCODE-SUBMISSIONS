#include<iostream>

#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2)
            return n;

        vector<int> Steps(n + 1, 0);
        Steps[0] = 0;
        Steps[1] = 1;
        Steps[2] = 2;

        for (int i = 3; i <= n; i++) {
            Steps[i] = Steps[i - 1] + Steps[i - 2];
        }

        return Steps[n];
    }
};



int main(){


Solution s1;
cout<<s1.climbStairs(5);



}