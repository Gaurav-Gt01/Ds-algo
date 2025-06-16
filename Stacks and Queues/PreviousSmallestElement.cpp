class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        vector<int> nse(arr.size()) ; 
        stack<int> st ; 
        
        for(int i = 0 ; i< arr.size() ; i++){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop() ;
            }
            if(!st.empty()){
                nse[i] = st.top() ;
            }else{
                nse[i] = -1 ;
            }
            st.push(arr[i]) ;
        }
        return nse ;
    }
};