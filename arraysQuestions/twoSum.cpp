// basic 2 sum using a hash map 
// lc 1 

// Time = o(N)
// SC = o(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mpp ;
        vector<int> ans ;
        int n = nums.size() ;

        for(int i = 0 ; i<n ; i++){

            int searchTarget = target - nums[i] ;
            // searchTarget is present in the map
            if(mpp.find(searchTarget) != mpp.end()){
                ans.push_back(i) ;
                ans.push_back(mpp[searchTarget]) ;
                return ans ;
            }
            // value is not present in the map
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[nums[i]] = i ;
            }
        }
        return ans ;
    }
};