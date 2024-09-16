#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minimize(int a, int b) {

        if (a < b)
            return a;
        else
            return b;
    }
    long long TimeInMinutes(string Timestamp) {

        int minute = stoi(Timestamp.substr(3, 2));
        int hours = stoi(Timestamp.substr(0, 2));

        long long timeinMinutes = hours * 60 + minute;
        long long timeAfterReducingBy24 = 1440 - timeinMinutes;

        return minimize(timeinMinutes, timeAfterReducingBy24);
    }

    int findMinDifference(vector<string>& timePoints) {

        long long mini = INT_MAX;

        for (int i = 0; i < timePoints.size() - 1; i++) {

            int T1 = TimeInMinutes(timePoints[i]);

            for (int j = i + 1; j < timePoints.size(); j++) {
                int T2 = TimeInMinutes(timePoints[j]);
                mini = minimize(abs(T1 - T2), mini);
            }
        }

        return mini;
    }
};