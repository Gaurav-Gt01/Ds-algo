// Max subarray Questions optimally solved using kadanes algorithm 
// LC 53 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int carrySum = 0 ;
        int maxSum = INT_MIN ;

        for(int i = 0 ; i<nums.size() ; i++){
            carrySum += nums[i] ;
            if(carrySum < 0){
                carrySum = 0 ;
                if(maxSum < nums[i]) maxSum = nums[i] ;
                continue ;
            }

            if(carrySum > maxSum) maxSum = carrySum ;
        }

        return maxSum ;
    }
};