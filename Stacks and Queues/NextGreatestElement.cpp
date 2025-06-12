class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap2; 
        stack<int> stack2 ;

        for(int j = nums2.size()-1 ; j>=0 ; j--){
            while(!stack2.empty() && (stack2.top() <= nums2[j])){
                stack2.pop() ;
            }
            if(!stack2.empty()) hashmap2[nums2[j]] = stack2.top() ;
            else hashmap2[nums2[j]] = -1 ;
            stack2.push(nums2[j]) ;
        }

        vector<int> ans ;

        for(int i = 0 ; i<nums1.size() ; i++){
            int key = nums1[i] ;
            int value = hashmap2[key] ;
            ans.push_back(value) ;
        }

        return ans ;
    }
};