#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1, text2, text1.length(), text2.length());
    }

    int lcs(string &text1, string &text2, int n, int m) {
        // Base case
        if(n == 0 || m == 0)
            return 0;

        // If last characters match
        if(text1[n - 1] == text2[m - 1])
            return 1 + lcs(text1, text2, n - 1, m - 1);
        
        // If last characters don't match
        return max(lcs(text1, text2, n - 1, m), lcs(text1, text2, n, m - 1));
    }
};