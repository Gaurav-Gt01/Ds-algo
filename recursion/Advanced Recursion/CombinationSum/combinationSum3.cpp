class Solution {
    public:
        vector<vector<int>> ans ;
        vector<int> a ;
    
        void helper(int ind , int k , int n , vector<int> &a){
            // index . number , target , vector to store subsequence 
    
            // base case 
            if(k == 0 && n == 0){
                ans.push_back(a) ;
                return ;
            }
    
           for(int i = ind ; i<=9 ; i++){
            if(i>n) break ;
            a.push_back(i) ;
            helper(i+1,k-1,n-i,a) ;
            a.pop_back() ;
           }
    
        }
        vector<vector<int>> combinationSum3(int k, int n) {
            helper(1 , k , n , a ) ;
            return ans ;
        }
    };