#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printarr(vector<int> &arr)
{

    for (auto it : arr)
        cout << it << "\t";
}

vector<int> findArrayIntersection(vector<int> v1, vector<int> v2, vector<int> &ans)
{

    int sizev1 = v1.size();
    int sizev2 = v2.size();

    int i = 0, j = 0;

    while (i < sizev1 && j < sizev2)
    {
        if (v1[i] < v2[j])
            i++;
        else if (v1[i] > v2[j])
            j++;
        else
        {
            ans.push_back(v1[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int main()
{

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 6};
    vector<int> v2 = {3, 4, 5};
    // Intersection result==> {3,4,5}

    vector<int> ans;
    findArrayIntersection(v1, v2, ans);

    printarr(ans);
}