// This is the basic approch in which we precompute 2 arrays of nse and pse and then directly find the area 
// This is a good one to see if u want to see how to calculate nse pse and maintain a monotonic stack 
// LC - 84 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = NextSmallerElement(heights);
        vector<int> pse = PreviousSmallerElement(heights);

        long long ans = 0 ;
        for(int i = 0 ; i<heights.size() ; i++){
            long long total = (nse[i] - pse[i] - 1)*heights[i] ;
            ans = max(ans , total) ;
        }
        return ans ;
    }

    vector<int> NextSmallerElement(vector<int>& heights){
        stack<int> st ;
        int n = heights.size() ;
        vector<int> nse(n) ;

        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n ;
                st.push(i) ;
            }else{
                nse[i] = st.top() ;
                st.push(i);
            }
        }

        return nse ;
    }

    vector<int> PreviousSmallerElement(vector<int>& heights){
        stack<int> st ;
        int n = heights.size() ;
        vector<int> pse(n) ;

        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1 ;
                st.push(i) ;
            }else{
                pse[i] = st.top() ;
                st.push(i) ;
            }
        }
        return pse ;
    }
};