// Find the summation of the max-min of all the subarrays generated from the nums array 
// subarray is the contigous part of an array 
// leetcode 2104

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // to calculate minimum 
        vector<int> nse = NextSmallerElement(nums);
        vector<int> psee = PreviousSmallerEqualElement(nums);

        // to calculate maximum
        vector<int> nge = NextGreatestElement(nums);
        vector<int> pgee = PreviousGreatestEqualElement(nums);

        long long ans = 0 ;

        // calculate the sum of the greatest element 
        for(int i = 0 ; i<nums.size() ; i++){
            long long  right = nge[i] - i ;
            long long left = i - pgee[i] ;

            long long freq = right*left ;
            ans = ans + (freq * nums[i]) ;
        }

        // reduce the sum of the smallest element from ans 
        for(int i = 0 ; i<nums.size() ;i++){
            long long right = nse[i] - i ;
            long long left = i -psee[i] ;

            long long freq = right*left;
            ans = ans - (freq*nums[i]) ;
        }
        return ans ;
    }

    // Next Smaller Element 
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

    // Previous Smaller or Equal Element 
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

    // Next Greatest Element 
    vector<int> NextGreatestElement(vector<int> arr){
        stack<int> st ;
        vector<int> nge(arr.size()) ;

        for(int i = arr.size() -1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop() ;
            }
            if(st.empty()){
                nge[i] = arr.size() ;
            }else{
                nge[i] = st.top() ;
            }

            st.push(i) ;
        }

        return nge ;
    }

    // Previous Greatest or Equal Element 
    vector<int> PreviousGreatestEqualElement(vector<int> arr){
        stack<int> st ;
        vector<int> pgee(arr.size()) ;

        for(int i = 0 ; i<arr.size() ;i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop() ;
            }
            if(st.empty()){
                pgee[i] = -1 ;
            }else{
                pgee[i] = st.top() ;
            }

            st.push(i) ;
        }
        return pgee ;
    }
};

