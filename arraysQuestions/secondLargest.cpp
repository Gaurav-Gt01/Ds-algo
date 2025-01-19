//  // Function returns the second
//     // largest elements
//     int getSecondLargest(vector<int> &arr) {
//         // Code Here
        
//         // OPTIMAL APPROACH :
//         int n = arr.size();
//         int max = arr[0];
//         int max2 = -1 ;
        
//         for(int i = 1; i<n ; i++){
//              /*
//              The two condtitions that are swapping case and 
//              if the number is smaller
//              than largest but greater than max2
//              */
//             if(arr[i]>max || (arr[i]>max2) && arr[i] != max){ 
//                 if(arr[i] > max){ // Satisfirs condition 1
//                     int temp = max;
//                     max = arr[i] ;
//                     max2 = temp ;
//                 }else max2=arr[i]; // satisfies condition 2 
//             }
//         }
        
//         return max2;
//     }
//     // time complexity = O(N)
//     // space complexity = O(1)
        
//     //  // BUFFER APPROACH :
        
//     //     int n = arr.size() ;
//     //     int max = arr[0];
//     //     int max2 = -1;
        
//     //     for(int i = 0 ; i<n-1 ; i++){
//     //         if(arr[i+1]>max){
//     //             max=arr[i+1];
//     //         }
//     //     }
        
//     //     for(int i = 0;i<n;i++){
//     //         if(arr[i]>max2 && arr[i]!=max){
//     //             max2 = arr[i];
//     //         }
//     //     }
        
//     //     return max2;
//     // }
    
//     // Time Complexity = O(2N)
//     // Space Complexity = O(1) constant time complexity 