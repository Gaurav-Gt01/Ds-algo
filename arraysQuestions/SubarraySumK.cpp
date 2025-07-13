class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;

        prefixSumFreq[0] = 1; 

        int sum = 0;
        int count = 0;

        for (int i = 0 ; i<nums.size() ; i++) {
            sum += nums[i];
            if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }
            prefixSumFreq[sum]++;
        }

        return count;
    }
};