#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            unordered_set<int> st;
            int n = arr.size();
    
            // Store indices of each element in a hash map
            for (int i = 0; i < n; i++) {
                st.insert(arr[i]);
            }
    
            int global_length = 0;
    
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int secondlast = arr[i];
                    int last = arr[j];
                    int current_length = 2; // At least two elements in the sequence
    
                    while (st.find(secondlast + last) != st.end()) {
                        int temp = secondlast + last;
                        secondlast = last;
                        last = temp;
                        current_length++;
                    }
    
                    global_length = max(global_length, current_length);
                }
            }
    
            return (global_length >= 3) ? global_length : 0;
        }
    };
    