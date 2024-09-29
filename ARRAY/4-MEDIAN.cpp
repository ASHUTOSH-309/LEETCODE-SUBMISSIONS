#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        double ans;
        vector<int> MergedArray;

        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] <= nums2[j]) {
                MergedArray.push_back(nums1[i]);
                i++;
            } else {
                MergedArray.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            MergedArray.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            MergedArray.push_back(nums2[j]);
            j++;
        }

        if ((m + n) % 2 == 0) {
            double firstElement = MergedArray[(n + m) / 2];
            double secondElement = MergedArray[(n + m) / 2 - 1];
            ans = (firstElement + secondElement) / 2;
        } else {

            double onlyElement=(m+n)/2;
            ans=MergedArray[onlyElement];

        }

        return ans;
    }
};