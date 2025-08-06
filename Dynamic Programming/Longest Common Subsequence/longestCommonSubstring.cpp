#include <string>
#include <vector>
using namespace std;

/*
here what we do is we keep the track
of the length of the longest common substring
by maintaing a varibale maxlen and if the 2 characters are not matching then 
we just return 0 and then fiinally return the maxlen
*/


class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size() ;
        int m = s2.size() ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
        int maxlen = 0 ;
        
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1] ;
                    maxlen = max(maxlen , dp[i][j]) ;
                }else{
                    dp[i][j] = 0 ;
                }
            }
        }
        return maxlen ;
    }
};