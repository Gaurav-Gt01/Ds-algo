class Solution {
    public:
        vector<vector<int>> ans ;
        vector<int> a ;
    
        void helper(int ind , int target , vector<int> &a , vector<int> &ip){
            // base case :
            if(target==0){
                ans.push_back(a) ;
                return ;
            }
    
            // loop from index to end 
            for(int i = ind ; i<ip.size() ; i++){
                // case for not choosing duplicate elements 
                if(i>ind && ip[i] == ip[i-1] ) continue ;
                if(ip[i] > target) break ;
    
                a.push_back(ip[i]) ;
                helper(i+1 , target-ip[i] , a , ip) ;
                a.pop_back() ;
            }
        }
    
    
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin() , candidates.end() ) ;
            helper(0,target,a,candidates) ;
            return ans ;
        }
    };