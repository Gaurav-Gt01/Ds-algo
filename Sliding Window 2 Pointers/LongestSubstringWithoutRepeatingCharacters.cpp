//Lc 3 
// Sliding window approch 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hashMpp ; // char , freq 
        int n = s.length() ;
        int start = 0 ;
        int end = 0 ;
        int ans = 0 ;

        while(end<n){
            if(hashMpp.find(s[end]) == hashMpp.end()){
                hashMpp[s[end]]++ ;
                int size = end-start+1 ;
                if(size>ans) ans = size ;
                end++ ;
            }else{
                while(hashMpp.find(s[end]) != hashMpp.end()){
                    hashMpp.erase(s[start]) ;
                    start++ ;
                }
            }
            
        }
        return ans ;
    }
};