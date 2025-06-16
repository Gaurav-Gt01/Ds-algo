// Asteroids Clash problem can be solved using any LIFO data data structure 
// LC 735 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size() ;
        // to store the final answer 
        vector<int> ans ;

        for(int i = 0 ; i<n ; i++){
            // if the element is poistive 
            if(asteroids[i]>0) ans.push_back(asteroids[i]) ;

            // if the element is negative 
            else{
                // if the element is smaller 
                while(!ans.empty() && ans.back()>0 && ans.back() < abs(asteroids[i]) ){
                    ans.pop_back() ;
                }
                if(!ans.empty()){
                    // if both are equal 
                    if(ans.back() == abs(asteroids[i])){
                        ans.pop_back() ;
                        continue ;
                    }
                    // if the last element is greater 
                    else if(ans.back() > abs(asteroids[i])){
                        continue ;
                    }
                    //if both are negative
                    else{
                        ans.push_back(asteroids[i]) ;
                    }
                }
                // if the list is empty we just add it in the list 
                else{
                    ans.push_back(asteroids[i]) ;
                }
            }
        }
        return ans ;

    }
};