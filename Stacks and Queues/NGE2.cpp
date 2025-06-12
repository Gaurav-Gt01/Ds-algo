class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size()) ;

        // create stack2 to start searching for elements if stack1 gives -1
        // tc = O(N)
        stack<int> st2 ;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            st2.push(nums[i]) ;
        }

        stack<int> st1 ;
        for(int i = nums.size()-1;i>=0;i--){// TC = O(N)
            int number = nums[i];
            int answer = 0 ;
            stack<int> st2dup = st2;

            while((!st1.empty()) && st1.top()<=number){ //In total runs for O(N)
                st1.pop();
            }

            if(st1.empty()){
                while((!st2dup.empty()) && st2dup.top()<=number){
                    // TC = O(N) worst case 
                st2dup.pop();
                }
                if(st2dup.empty()) answer = -1 ;
                else answer = st2dup.top() ;
            }
            else answer = st1.top() ;

            ans[i] = answer ;
            st1.push(number) ;
        }
        return ans ;

    }
};