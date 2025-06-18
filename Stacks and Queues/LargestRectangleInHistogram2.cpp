// This is the better approch to find the solution of this and it does not need any precomputations needed 
// Lc - 84 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st ;
        int n = heights.size() ;
        int ans = 0 ;

        for(int i = 0 ; i<n ; i++){
            // if stack is empty just push the element 
            if(st.empty()) st.push(i) ;
            // stack is not empty and top ekement is greater than the current element 
            while(!st.empty() && heights[st.top()] > heights[i] ){
                int nse = i ;
                int index = st.top();
                st.pop() ;

                int pse = -1 ;
                if(!st.empty()){
                    pse = st.top() ;
                }

                int area = heights[index] * (nse - pse -1);
                ans = max(area,ans) ;
            }
            st.push(i) ;
        }

        while(!st.empty()){
            int index = st.top() ;
            int nse = n ;
            st.pop() ;

            int pse = -1 ;
            if(!st.empty()) pse = st.top() ;

            int area = heights[index] * (nse - pse -1) ;
            ans = max(ans , area ) ;
        }
        return ans ;
    }
};

