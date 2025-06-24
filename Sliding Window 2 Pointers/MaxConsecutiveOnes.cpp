// lc - 1004
// find the longest substring having the maximum ones when u can flip at max k zeros 

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, cnt = 0, ans = 0;
        int n = nums.size();

        while (right < n) {
            if (nums[right] == 0) cnt++;

            while (cnt > k) {
                if (nums[left] == 0) cnt--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};