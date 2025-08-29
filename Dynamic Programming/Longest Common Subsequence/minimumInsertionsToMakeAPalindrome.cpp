#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        string ns = rev(s) ;
        
        int n = s.length() ;

        vector<vector<int>> dp(n+1,vector<int>(n+1,0)) ;

        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=n ; j++){
                if(ns[i-1] == s[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1] ;
                }else{
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]) ;
                }
            }
        }

        return n - dp[n][n] ;
    }

    // code to reverse the string 
    string rev(string s){
        int i = 0 ;
        int j = s.length()-1 ;

        while(i<j){
            char ch = s[i] ;
            s[i] = s[j] ;
            s[j] = ch ;
            i++ ;
            j-- ;
        }
        return s ;
    }
};