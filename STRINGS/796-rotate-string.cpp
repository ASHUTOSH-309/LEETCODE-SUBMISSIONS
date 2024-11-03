#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {

        if (s.size() != goal.size())
            return false;

        string ss = s + s;
        // we can iterate over ss now and check all the substrings of the size of the goal,
        //  if we encounter any substring similar to the goal then we can return true;
        //  the intution is that when you add s twice, it will consider all the possbilities when
        //  k charcters are placed back from front in the string .

        /*
            example s=abcd
            if we strike off one character then
            s-----> bcda
            2 characters
            s----->cdab
            3 characters
            s-----> dabc
            4 characters
            s-----> abcd

            if we see s+s , then all these possibilities are considered over here 
            as you can iterate over all substrings of size 4 you can get all possible combinations
            s+s= abcdabcd
         */

        for (int i = 0; i <= ss.size() - goal.size(); i++)
        {
            // abcdeabcde
            if (ss.substr(i, goal.size()) == goal)
            {
                return true;
            }
        }
        return false;
    }
};