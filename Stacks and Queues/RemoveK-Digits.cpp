// leetcode 402
// remove k digits such that the resultant is the smallest number 
// monotonic stack 

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() == k) return "0";

        stack<char> st;
        int cnt = 0;

        for(int i = 0; i < num.length(); i++) {
            while(!st.empty() && cnt < k && st.top() > num[i]) {
                st.pop();
                cnt++;
            }
            st.push(num[i]);
        }

        // Remove from the end if still some digits need to be removed
        while(cnt < k && !st.empty()) {
            st.pop();
            cnt++;
        }

        string reversed = "";
        while(!st.empty()) {
            reversed.push_back(st.top());
            st.pop();
        }

        // remove the leading zeros / pop all the zeros from the back 
        if(!reversed.empty() && reversed.back() == '0'){
            while(!reversed.empty() && reversed.back() == '0'){
                reversed.pop_back() ;
            }
        }
        
        return reverseString(reversed) ;
    }

    // reverse the string 
    string reverseString(string str){
        int st = 0 ;
        int end = str.length() -1 ;

        while(st<end){
            char temp = str[st] ;
            str[st] = str[end] ;
            str[end] = temp ;

            st++;
            end-- ;
        }

        if(str.empty()) return "0" ;
       
        return str ;
    }
};

// TC -> 0(N) approx 
// SC -> 0(N) approx 