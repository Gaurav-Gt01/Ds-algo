#include <string>
#include <vector>
#include <algorithm>   
using namespace std;

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

    // here we fill the dp table using the standard lcs approach

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


    // here we trace the elements of the dp table which are the part of lcs by traversing the dp table backwards
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]){
			ans.push_back(s1[i-1]) ;
			i-- ;
			j--;
		}else{
			if(dp[i-1][j] > dp[i][j-1]){
				i-- ;
			}else j-- ;
			
		}
	}

	reverse(ans.begin() , ans.end()) ;

	return ans ;
}