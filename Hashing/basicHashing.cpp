# include <iostream>
using namespace std ;

int main(){

    // Creating an intitail array
    int arrSize ;
    cout<<"Enter the array size ";
    cin>> arrSize;
    int arr[arrSize];

    cout<<"Enter the numbers of the array ";
    for(int i = 0;i<arrSize;i++){
        cin>>arr[i];
    }

    // Hasing array 
    int hashArray[12] = {0} ;
    for(int i = 0 ; i < arrSize ; i++){
        hashArray[arr[i]] = hashArray[arr[i]]+1 ;

    }

    //Searching the number 
    int q ;
    cout<<"How many numbers are to be searched ?";
    cin >> q;

    cout<<"Enter the numbers to be searched ";
    while(q!=0){
        int number ;
        cin>> number ;
        q--;
        cout<< hashArray[number]<<endl;
    }

}