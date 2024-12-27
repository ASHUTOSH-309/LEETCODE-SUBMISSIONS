#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {


            int ans=INT_MIN;
            int size=a.size();

            int aiplusi=a[0];
            // aiplus i will contain the maximum value of a[i]+i till index 0 to j-1;
            for(int j=1;j<size;j++){

                    ans=max(ans, aiplusi+a[j]-j);
                    aiplusi=max(aiplusi,a[j]+j);
            }


            return ans;
    
    }
};