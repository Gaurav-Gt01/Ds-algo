#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Creating and initalizing the dp vector 
    vector<vector<int>> dp ;
    Solution(){
        dp = vector<vector<int>>(1001, vector<int>(1001, -1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        return helper(text1,text2,text1.length(),text2.length()) ;
    }

    int helper(string& text1, string& text2,int n , int m ){
        // base case 
        if(m==0 || n == 0) return 0 ;
        if(dp[n][m] != -1) return dp[n][m] ;

        // main code 
        if(text1[n-1] == text2[m-1]) return dp[n][m] =  1+helper(text1,text2,n-1,m-1) ;
        else return dp[n][m] = max(helper(text1,text2,n-1,m) , helper(text1,text2,n,m-1)) ;

    }
};