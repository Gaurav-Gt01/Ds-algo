// here we will be printing the length of the shortest common supersequence from the 2 strings

// User function template for C++

#include <string> 
#include <vector>
using namespace std ;

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        int n = s1.length() ;
        int m = s2.length() ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
        
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }
        return m+n-dp[n][m] ;
    }
};