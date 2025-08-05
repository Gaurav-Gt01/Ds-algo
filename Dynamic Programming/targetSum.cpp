// This sum is exactly like number of subsets with a given difference and we compute the target mathematically .

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum) return 0;

        int subsetSum = (totalSum + target) / 2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(subsetSum + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= subsetSum; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[nums.size()][subsetSum];
    }
};