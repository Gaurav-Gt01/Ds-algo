// Leetcode 42
// Trapped Water 

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        // precomputations 
        vector<int> prefixMax(n), suffixMax(n);

        // left greatest element 
        prefixMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        // right greatest element 
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        // calculate total water trapped 
        int waterTrapped = 0;
        for (int i = 0; i < n; ++i) {
            waterTrapped += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return waterTrapped;
    }
};