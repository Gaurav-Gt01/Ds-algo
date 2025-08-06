#include <string>
#include <vector>

using namespace std ;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string s1 = str1 ;
        string s2 = str2 ;
        int n= str1.length() ;
        int m= str2.length() ;

        vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

        // Here we create the dp table 
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1] ;
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }	

        int i = n ;
        int j = m ;
        string ans ;

        // We start to traverse the dp table from n,m index to 0,0

        // if the elements are equal then we add them just once in the string 

        /*
        if they are not the same then we add both of them to the string 
        according to which is big and then again move in that direction the way 
        we did in normal lcs printing 
        */

        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                ans.push_back(s1[i-1]) ;
                i-- ;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans.push_back(s1[i-1]) ;
                    i-- ;
                }
                else{
                    ans.push_back(s2[j-1]) ;
                    j-- ;
                }   
                
            }
        }

        /*
        here we check if we have reached 0,0 index if not we add the characters 
        until we reach 0,0
        */

        while(i > 0){
            ans.push_back(s1[i-1]);
            i-- ;
        }

        while(j > 0){
            ans.push_back(s2[j-1]);
            j-- ;
        }

        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
};