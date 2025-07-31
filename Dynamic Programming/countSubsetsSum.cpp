#include <vector>
#include <cmath>
using namespace std;    

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int zeros = 0 ;
        vector<int> finalarr ;
        for(int i = 0 ; i <arr.size() ; i++){
            if(arr[i]!=0){
                finalarr.push_back(arr[i]) ;
            }else{
                zeros++;
            }
        }
        // dp matrix
        vector<vector<int>> dp(finalarr.size()+1,vector<int>(target+1,0)) ;
        
        // initializing the dp matrix 
        for(int i = 0 ; i<=finalarr.size() ; i++){
            for(int j = 0 ; j<=target ; j++){
                if(j==0) dp[i][j] = 1 ;
            }
        }
        
        // setting up the main loop for the dp matrix 
        for(int i = 1 ; i<= finalarr.size() ; i++){
            for(int j = 1 ; j<=target; j++){
                if(finalarr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-finalarr[i-1]] + dp[i-1][j] ;
                }
                else dp[i][j] = dp[i-1][j] ;
            }
        }
        
        int ans = dp[finalarr.size()][target] ;
        
        return ans*pow(2,zeros) ;
        
        
    }
};