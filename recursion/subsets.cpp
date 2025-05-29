// leetcode 78 
// subset problem , important for all subsequence problems :

class Solution {
    public:
        vector<vector<int>> ans;
        vector<int> sub;
    
        void helper(vector<int>& nums, int ind) {
            
            // Base case: if index reaches end of array, push current subset and return
            if (ind == nums.size()) {
                ans.push_back(sub);
                return;
            }
    
            // Take 
            sub.push_back(nums[ind]);
            helper(nums, ind + 1);
            sub.pop_back();
    
            // Don't take 
            helper(nums, ind + 1);
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            helper(nums, 0);
            return ans;
        }
    };