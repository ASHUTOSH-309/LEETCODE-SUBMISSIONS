#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printarr(vector<int> &arr)
{

    for (auto it : arr)
        cout << it << "\t";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int d = 4;
    vector<int> temp;

    int n = arr.size();
    // right rotate by 4 places

    // final state would be something like 6,7,8,9 1...5

    for (int i = n - d; i < n; i++)
    {
        temp.push_back(arr[i]);
    }
    // n=9 d=4
    for (int i = 0; i < n - d; i++)
    {
        arr[i + d+1] = arr[i];
    }
    int i = 0;
    for (auto it : temp)
    {
        arr[i] = it;
        i++;
    }

    printarr(arr);
}