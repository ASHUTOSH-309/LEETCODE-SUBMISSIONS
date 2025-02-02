#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {

        int count = 0;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i - 1] > nums[i]) {
                // if control reaches here it means that , the array given to us
                // is not sorted Now we have to check if it is the result of
                // rotation of not,

                // when sorted array is rotated by k places, then first
                // (k)largest  values of the array comes at the front in
                // ascending order, followed by first (n-k) elements of the
                // sorted array

                /*
                    observation: after rotation array is divided into exactly
                   two non-decreasing sorted portions
                    && obviously the first element of rotated array should be
                   lesser than the last element then only it can be assured that
                   first sorted array was actually a trailing part of the
                   original array


                 */

                if (nums[0] < nums[nums.size() - 1])
                    return false;
                count++;
                if (count > 1)// if more than two sorted portions are created then simply return false, as nums can't be rotated sorted then
                    return false;
            }
        }

        return true;
    }
};