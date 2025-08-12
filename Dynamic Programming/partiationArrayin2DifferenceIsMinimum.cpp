// In this question u have to just think of finding the sum of 1 partition which is in the range from 0 to sum of all elements and then u have to simpley calculate where range - 2S is mimimum .


// this is a high level approch and is very complex
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto getSubsets = [](vector<int>& arr) {
            int m = arr.size();
            vector<vector<int>> res(m + 1);  
            int total = 1 << m;
            for (int mask = 0; mask < total; ++mask) {
                int sum = 0;
                int bits = __builtin_popcount(mask);
                for (int i = 0; i < m; ++i) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                    }
                }
                res[bits].push_back(sum);
            }
            return res;
        };

        auto L = getSubsets(left);
        auto R = getSubsets(right);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int mini = INT_MAX;

        for (int k = 0; k <= n; ++k) {
            auto& A = L[k];
            auto& B = R[n - k];
            sort(B.begin(), B.end());
            for (int a : A) {
                int target = totalSum / 2 - a;
                auto it = lower_bound(B.begin(), B.end(), target);
                if (it != B.end()) {
                    int sum = a + *it;
                    mini = min(mini, abs(totalSum - 2 * sum));
                }
                if (it != B.begin()) {
                    --it;
                    int sum = a + *it;
                    mini = min(mini, abs(totalSum - 2 * sum));
                }
            }
        }

        return mini;
    }
};