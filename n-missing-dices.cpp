class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        vector<int> ans(n, 0);

        // rolls contain the record for the m observations
        int m = rolls.size();
        long long sum_all = mean * (m + n);

        // sum of m observation + sum of n observation = sum_all

        long long sum_m = accumulate(rolls.begin(), rolls.end(), 0);
        long long sum_n = sum_all - sum_m;

        
       

        // n=5 sum=11  {2,2,2,3,2}
        long long ans_sum_tracker = 0;
        while (ans_sum_tracker < sum_n) {
            for (int i = 0; i < n; i++) {
                ans_sum_tracker++;
                if (ans_sum_tracker == sum_n){
                    ans[i]++;    
                    break;
                }
                ans[i]++;
            }
            
        }

        return ans;
    }
};