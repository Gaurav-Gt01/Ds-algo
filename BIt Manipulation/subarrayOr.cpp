#include <vector>
#include <set>
using namespace std;

// The basic logic though is that to maintain 3 sets one ans one current and one prev set . For each iteration we copy the current set to the prev set and then add the next eleemnt to the current set and then or it with prev and then store them in current and also we transfer elements from prev to ans set , and finally just return the size of the and set .

class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {

        set<int> all_possible_ors;
        
        set<int> prev_ors; 

        for (int num : arr) {

            set<int> current_ors;
            

            current_ors.insert(num);
            
            for (int prev_or_val : prev_ors) {
                current_ors.insert(prev_or_val | num);
            }
        
            for (int or_val : current_ors) {
                all_possible_ors.insert(or_val);
            }
            
            prev_ors = current_ors; 
        }

        return all_possible_ors.size();
    }
};