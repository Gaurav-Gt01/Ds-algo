#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

class Solution {
  public:
    int MOD = 1e9 + 7;

    int countPartitions(vector<int>& arr, int d) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;

        // Edge cases
        if (totalSum < d || (totalSum + d) % 2 != 0)
            return 0;

        int target = (totalSum + d) / 2;
        int n = arr.size();

        vector<int> dp(target + 1, 0);
        dp[0] = 1;  // one way to make sum 0

        for (int i = 0; i < n; i++) {
            vector<int> next(dp);  // copy previous state
            for (int sum = 0; sum <= target; sum++) {
                if (sum >= arr[i]) {
                    next[sum] = (next[sum] + dp[sum - arr[i]]) % MOD;
                }
            }
            dp = next;
        }

        return dp[target];
    }
};
