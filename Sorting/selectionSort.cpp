# include <iostream>
using namespace std;

// swapping block :
void swap (int minNum , int i , int arr[]){
    int temp = arr[minNum] ;
    arr[minNum] = arr[i] ;
    arr[i] = temp ;
}

int main(){
    int size;
    cin>>size;

    int arr[size];
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    for(int i = 0 ; i<size-2 ; i++){
        int minNum = i ;
        for(int j = i ; j < size ; j++){
            if(arr[j] < arr[minNum]){
                minNum = j ;
            }
        }
        
        swap(minNum,i,arr);
    }

    for(int i = 0 ; i < size ; i++){
        cout<< arr[i]<< " ";
    }

}


// trying new recursive method :

// # include <iostream>
// using namespace std;

// void selectionSort(int size ,int arr[]){
//      for(int i = 0 ; i<size-2 ; i++){
//         int minNum = i ;
//         for(int j = i ; j < size ; j++){
//             if(arr[j] < arr[minNum]){
//                 minNum = j ;
//             }
//         }
        
//         swap(minNum,i,arr);
//     }

//     for(int i = 0 ; i < size ; i++){
//         cout<< arr[i]<< " ";
//     }
// }

// void swap (int minNum , int i , int arr[]){
//     int temp = arr[minNum] ;
//     arr[minNum] = arr[i] ;
//     arr[i] = temp ;
// }

// int main(){
//     int size;
//     cin>>size;

//     int arr[size];
//     for(int i = 0 ; i < size ; i++){
//         cin>>arr[i];
//     }

//     selectionSort(size,arr);

// }
