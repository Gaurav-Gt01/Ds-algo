#include <vector>
using namespace std;
// total number of ways to make change for a given sum using given coins
// This is a variation of unbounded knapsack problem
// where we can use each coin an infinite number of times
// The problem is to find the total number of ways to make change for a given sum using the given coins

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size() ;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0)) ;
        
        for(int i = 0 ; i<=n ; i++){
            dp[i][0] = 1 ;
        }
        // main body 
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=sum ; j++){
                if(j>=coins[i-1]){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j] ;
                }
                else dp[i][j] = dp[i-1][j] ;
            }
        }
        return dp[n][sum] ;
    }
};