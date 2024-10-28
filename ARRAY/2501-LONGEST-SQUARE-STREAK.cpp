#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int root = static_cast<int>(std::sqrt(num)); // Get the integer part of the square root
        return root * root == num; // Check if squaring it gives the original number
    }

    int longestSquareStreak(vector<int>& nums) {
        long long globalCounter = 0;
        map<long long, int> mpp; // Use long long for keys in the map
        for (int ele : nums) {
            mpp[ele]++;
        }

        sort(nums.begin(), nums.end());
        long long maxi = nums[nums.size() - 1];

        for (int i = 0; i < nums.size(); i++) {
            long long counter = 1;
            long long nextNumber = static_cast<long long>(nums[i]) * nums[i]; // Cast to long long to prevent overflow
            while (nextNumber <= maxi) {
                if (mpp[nextNumber]) {
                    counter++;
                    mpp[nextNumber]--;
                    nextNumber = nextNumber * nextNumber;
                } else {
                    break;
                }
            }
            globalCounter = max(globalCounter, counter);
        }
        if(globalCounter == 1) return -1;
        return globalCounter;
    }
};

/* while (nextNumber <= maxi) {
    if (mpp[nextNumber]) {
        counter++;
        mpp[nextNumber]--;
        nextNumber = nextNumber * nextNumber;
    } else {
        break;
    }
}

The while loop squares nextNumber repeatedly, which causes it to grow exponentially. 
Therefore, the number of times nextNumber can be squared before it exceeds maxi is log log(maxi),
as the value grows as powers of 2.

For each i, the inner while loop thus runs in O(log log(maxi)) time.

 */

