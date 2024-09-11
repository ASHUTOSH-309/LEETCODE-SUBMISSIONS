#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string DecimalToBinary(int num)
    {
        string ans;
        if (num <= 1)
            return to_string(num);

        while (num != 0)
        {
            ans += to_string(num % 2);
            num /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int minBitFlips(int start, int goal)
    {

        if (start == goal)
            return 0;

        long long count = 0;

        string binary_start = DecimalToBinary(start);
        string binary_goal = DecimalToBinary(goal);

        // start-->10---> 1010
        // end---->7---> 111

        int size_start = binary_start.size();
        int size_goal = binary_goal.size();

        if (size_start > size_goal)
        {
            int dff = abs(size_start - size_goal);

            for (int i = 0; i < dff; i++)
            {
                binary_goal = "0" + binary_goal;
            }
        }
        else
        {

            int dff = abs(size_start - size_goal);
            for (int i = 0; i < dff; i++)
            {
                binary_start = "0" + binary_start;
            }
        }

        for (int j = 0; j < binary_start.size(); j++)
        {

            if (binary_start[j] != binary_goal[j])
                count++;
        }

        return count;
    }
};