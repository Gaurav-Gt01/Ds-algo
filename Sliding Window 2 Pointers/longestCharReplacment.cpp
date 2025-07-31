#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
// Brute force solution :
    // int characterReplacement(string s, int k) {
        
    //     int maxlen = 0 ;
    //     for(int i = 0 ; i<s.length() ; i++){
    //         char ch = s[i] ;
    //         int cnt = 0 ;
    //         for(int j = i ; j<s.length() ; j++){
    //             if(s[j] == ch) cnt++ ;
    //             else{
    //                 if(k!=0){
    //                     cnt++;
    //                     k--;
    //                 }else break ;
    //             }
    //         }
    //         maxlen = max(maxlen,cnt);
    //     }

    //     return maxlen ;
    // }


// Optimal Approch with TC - O(N) and SC - O(1)
int characterReplacement(string s, int k) {
    // hash map to store freq of all 
    vector<int> count(26, 0);
    int maxCount = 0;  
    int start = 0;
    int maxLength = 0;

    for (int end = 0; end < (int)s.size(); ++end) {
        count[s[end] - 'A']++;
        maxCount = max(maxCount, count[s[end] - 'A']);
        // while loop to shrink from the start 
        while ((end - start + 1) - maxCount > k) {
            count[s[start] - 'A']--;
            start++;
        }

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

};