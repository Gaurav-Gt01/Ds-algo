// very very important pattern 

class Solution {
    public:
        vector<vector<int>> ans ;
        vector<int> arr ;
    
        void helper(int i, int k , vector<int>& arr , vector<int>& c){
            // base termination condition :
            if(i == c.size()){
                if(k == 0) ans.push_back(arr) ;
                return ;
            }
    
            // take the same element 
            if(c[i] <= k){
                arr.push_back(c[i]) ;
                helper(i , k-c[i] , arr ,c) ;
                arr.pop_back() ;
            }
            // move on to the next element 
            helper(i+1,k,arr,c) ;
        }
    
        
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            helper(0,target,arr, candidates) ;
            return ans ;
        }
    };
    