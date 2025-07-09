// sort colours problem solved using dutch flag algorithm 

class Solution {
public:

    // TC = O(N) single pass solution 
    // SC = 0(1)
    
    void sortColors(vector<int>& nums) {
        // Initialize the 3 pointers 
        int low = 0 ;
        int mid = 0 ;
        int high = nums.size()-1;

        while(mid<=high){
            // case 1 when nums[mid] == 0 
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]) ;
                low++ ;
                mid++ ;
            }
            // case 2 when nums[mid] == 1
            else if(nums[mid] == 1){
                mid++ ;
            }
            // case 3 when nums[mid] == 2 
            else{
                swap(nums[mid], nums[high]) ;
                high-- ;
            }
        }
    }
};