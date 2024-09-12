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
    vector<int> arr = {1, 2, 3, 0, 3, 0, 2, 6, 7, 0};

    int i = 0;

    while (arr[i] != 0)
        i++;

    for (int j = i + 1; j < arr.size(); j++)
    {

        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    printarr(arr);
}