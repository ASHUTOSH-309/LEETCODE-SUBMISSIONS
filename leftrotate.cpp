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

    // Left rotate the array by D places

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int d = 4;
    // after 4 left rotation---> 5......9,1...4

    vector<int> temp;

    for (int i = 0; i < d; i++)
        temp.push_back(arr[i]);

    // moving each element residing from indexes d to n-1 , d positions ahead
    for (int i = d; i < arr.size(); i++)
        arr[i - d] = arr[i];

    // copy back elements to the trailing indexes

    int i = 0;
    for (int j = arr.size() - d; j <= arr.size() - 1; j++)
    {
        arr[j] = temp[i];
        i++;
    }

    printarr(arr);
}
