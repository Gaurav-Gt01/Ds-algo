/*
class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.


    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        for(int i = n-1 ; i>0 ; i--){//outer loop-no of iterations ie n-1 
            for(int j = 0 ; j<=n-2 ; j++){//inner loop - swapping the emements ie 
                if(arr[j+1]<arr[j]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    cnt++;
                }
            }
        }
    }
};


*/