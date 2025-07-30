    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include <math.h>
    using namespace std;

    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // Memoized KnapSack 0/1 :
        vector<vector<int>> dp(val.size() + 1, vector<int>(W + 1, -1));
        int ans = helper(W, val, wt, val.size(), dp);
        return ans;
    }

    int helper(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp) {
        // base case
        if (dp[n][W] != -1) return dp[n][W];
        if(n == 0 || W == 0) return 0 ;
        
        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1] + helper(W-wt[n-1] , val , wt , n-1 , dp) , helper(W , val , wt ,n-1 , dp)) ;
        }
        else{
            return dp[n][W] =helper(W , val , wt ,n-1 , dp) ;
        }
    }   