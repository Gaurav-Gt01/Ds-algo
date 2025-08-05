#include <vector>
using namespace std;

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        
        // n would be the weight in unbounded 
        int n = price.size() ;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)) ;
        
        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<=n ; j++){
                if(j>=i){
                    // here we are checking if we can include the i-th rod
                    // if yes then we take the max of including it or not including it
                    // if we include it then we add the price of the i-th rod and check for
                    // the remaining length (j-i)
                    // if we do not include it then we just take the value from the previous row
                    // for the same length j
                    dp[i][j] = max(price[i-1] + dp[i][j-i] , dp[i-1][j]); 
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][n] ;
    }
};