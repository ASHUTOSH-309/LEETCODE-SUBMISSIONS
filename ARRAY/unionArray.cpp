#include <iostream>

#include <bits/stdc++.h>

using namespace std;

void printarr(vector<int> &arr)
{
    for (auto it : arr)
        cout << it << "\t";
}

void UnionTwoLists(vector<int> v1, vector<int> v2)
{

    set<int> st;
    for (int i = 0; i < v1.size(); i++)
        st.insert(v1[i]);
    for (int j = 0; j < v2.size(); j++)
        st.insert(v2[j]);

    vector<int> ans;

    for (auto it : st)
    {
        ans.push_back(it);
    }



    printarr(ans);
}

int main()
{
    vector<int> v1 = {1, 2, 3, 0, 3, 0, 2, 6, 7, 0,5};
    vector<int> v2={3,4,5,6};
    //Expected Outcome --> 1...7


    UnionTwoLists(v1,v2);
}