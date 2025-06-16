// sum of minimum of all the subarray
// lc 907

class Solution {
public:
    const long long mod = 1e9+7 ;

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NextSmallerElement(arr) ;
        vector<int> psee = PreviousSmallerEqualElement(arr) ;

        long long ans = 0; 
        
        for(int i = 0 ; i<arr.size() ; i++){
            long long right = nse[i] - i ;
            long long left = i - psee[i] ;

            long long freq = right * left ;
            ans = (ans + ((arr[i] * freq * 1LL)))%mod ;
        }

        return ans ;
        
    }

    vector<int> NextSmallerElement(vector<int> arr){
        stack<int> st ;
        vector<int> nse(arr.size()) ;

        for(int i = arr.size() -1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop() ;
            }
            if(st.empty()){
                nse[i] = arr.size() ;
            }else{
                nse[i] = st.top() ;
            }

            st.push(i) ;
        }

        return nse ;
    }

    vector<int> PreviousSmallerEqualElement(vector<int> arr){
        stack<int> st ;
        vector<int> psee(arr.size()) ;

        for(int i = 0 ; i<arr.size() ;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop() ;
            }
            if(st.empty()){
                psee[i] = -1 ;
            }else{
                psee[i] = st.top() ;
            }

            st.push(i) ;
        }
        return psee ;
    }

};