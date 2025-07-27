class Solution {
public: 
    // // Memoization of DP :
    // int fib(int n ) {
    //     vector<int> dp(n+1,-1) ;
    //     return fibHelper(n ,dp ) ;
    // }

    // int fibHelper(int n,vector<int> &dp){
    //     if(dp[n] != -1) return dp[n] ;
    //     if(n<=1) return n ;

    //     return dp[n] = fibHelper(n-1,dp)+fibHelper(n-2,dp) ;
    // }

    // // Top down DP:
    // int fib(int n){
    //     if(n<=1) return n ;
    //     vector<int> dp(n+1);
    //     dp[0] = 0 ;
    //     dp[1] = 1 ;

    //     for(int i = 2 ; i<=n ; i++){
    //         dp[i] = dp[i-1] + dp[i-2] ;
    //     } 

    //     return dp[n] ;

    // }


    // Space Optimized Top Down DP :
    int fib(int n){
        if(n<=1) return n ;
        int prev1 = 1 ;
        int prev2 = 0 ;
        int ans = -1 ;

        for(int i =2 ; i<=n ; i++){
            ans = prev1+prev2 ;
            prev2 = prev1 ;
            prev1= ans ;
        }
        return prev1 ;
    }
};
