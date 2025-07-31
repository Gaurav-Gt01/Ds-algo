#include <vector>
#include <cmath>
using namespace std;    


class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int arrSum = 0 ;

       for(int i = 0 ; i<nums.size() ; i++){
        arrSum = arrSum + nums[i] ;
       } 

       if(arrSum%2 == 1) return false ;
       arrSum = arrSum/2 ;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(arrSum+1 , false)) ;

        for(int i = 0 ; i<=nums.size() ;i++){
            for(int j = 0 ; j<=arrSum; j++){
                if(i==0) dp[i][j] = false ;
                if(j==0) dp[i][j] = true ;
            }
        }

        for(int i = 1 ; i <= nums.size() ; i++){
            for(int j = 1 ; j<=arrSum ; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j] ;
                }
                else dp[i][j] = dp[i-1][j] ;
            }
        }

        return dp[nums.size()][arrSum] ;
    }
};