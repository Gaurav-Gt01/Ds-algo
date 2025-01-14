/*
class Solution {
  public:
    // Please change the array in-place


    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        //outer loop runs for n-1 times :
        for(int i = 0 ; i <= n-1; i++){
            int j=i;
            int cnt = 0;
            while(j>0&&arr[j-1]>arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp ;
                cnt++;
                j--;
            }
            
        }
    }
};
*/