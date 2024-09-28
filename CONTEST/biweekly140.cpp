#include <bits/stdc++.h>
#include<iostream>

class Solution
{
public:
    int elementCount(int elem, vector<int> &heights)
    {
        long long count = 0;
        for (auto it : heights)
        {
            if (it == elem)
                count++;
        }
        return count;
    }

    long long maximumTotalSum(vector<int> &maximumHeight)
    {
        long long sum = 0;
        int maximumElement = INT_MIN;

        sort(maximumHeight.begin(), maximumHeight.end());
        maximumElement = maximumHeight[maximumHeight.size() - 1];
        if (maximumHeight.size() > maximumElement)
            return -1;
        vector<bool> MarkerArray(maximumElement + 1);

        for (auto it : maximumHeight)
            MarkerArray[it] = true;

        sum += maximumHeight[0];
        for (int i = 1; i < maximumHeight.size(); i++)
        {
            if (maximumHeight[i - 1] == maximumHeight[i] || elementCount(maximumHeight[i], maximumHeight) > 1)
            {
                int j;
                for (j = maximumHeight[i] - 1; j > 0; j--)
                {
                    if (!MarkerArray[j])
                    {
                        maximumHeight[i] = j;
                        MarkerArray[j] = true;

                        break;
                    }
                }
                if (j == 0)
                    return -1;
            }

            sum += maximumHeight[i];
        }

        return sum;
    }
};