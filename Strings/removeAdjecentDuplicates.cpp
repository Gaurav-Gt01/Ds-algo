#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length() ;
        int i = 0 ;
        if(n==1) return s ;

        while(i+1<n){
            if(s[i]==s[i+1]){
                s.erase(i,2) ;
                i= 0;
                n = s.length() ;
            }
            else i++ ;
        }
        return s ;

    }
};