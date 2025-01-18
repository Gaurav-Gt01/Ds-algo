// class Solution {
//   public:
//     // Function to sort an array using quick sort algorithm.
//     void quickSort(vector<int>& arr, int low, int high) {
//         // code here
        
//         //base case
//         if(low<high){
//             int part = partition(arr,low,high);
//             quickSort(arr,low,part-1);
//             quickSort(arr,part+1,high);
            
//         }
        
//     }

//   public:
//     // Function that takes last element as pivot, places the pivot element at
//     // its correct position in sorted array, and places all smaller elements
//     // to left of pivot and all greater elements to right of pivot.
//     // int partition(vector<int>& arr, int low, int high) {
    
//     int partition(vector<int>& arr, int low, int high) {
//     int pivot = arr[high]; 
//     int i = low;
//     int j = high - 1; //exclude the partiton index 

//     while (i <= j) {
//         while (arr[i] <= pivot && i < high) {
//             i++;
//         }
//         while (arr[j] > pivot && j >= low) {
//             j--;
//         }
//         if (i < j) {
//             swap(arr[i], arr[j]);
//         }
//     }
    
//     swap(arr[i], arr[high]);
//     return i;
// }
// };