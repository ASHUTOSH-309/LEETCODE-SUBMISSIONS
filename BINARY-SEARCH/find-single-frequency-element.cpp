#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int ans;

        if (nums.size() == 1)
            return nums[0];
        if (nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];

        if(nums[0]!=nums[1]) return nums[0];    

        int low = 1;
        int high = nums.size() - 2;

        while (low <= high) {
            int mid = (high + low) / 2;

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];

            if (mid % 2 == 0) {

                if (nums[mid] == nums[mid + 1]) {
                    low=mid+1;
                } else {
                    high=mid-1;
                }

            } else {

                if (nums[mid] == nums[mid + 1]) {
                        // odd even
                        high=mid-1;
                } else {
                    //midand mid-1   even odd 
                    low=mid+1;
                }
            }
        }


        return 1;
    }
};


// key observation: for (even,odd) redundant element ---> low=mid+1
// for (odd,even)  redundant element ----> high=mid-1;