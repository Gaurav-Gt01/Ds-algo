// Assign cookies using greedy algorithm 
// LC 455 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0 ;
        int j = 0 ;
        int ans = 0 ;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(j<s.size() && i<g.size()){
            int greed = g[i] ;
            
            if(s[j]>=greed){
                ans++ ;
                i++;
            }
            j++;
        }
        return ans ;
    }
};