# include <iostream>
using namespace std;

struct Node{
    int data ;
    Node* next ;
    Node* prev ;

    Node(int data1 , Node* next1 , Node* prev1){
        data = data1 ;
        next = next1 ;
        prev = prev1 ;
    }

    Node(int data1){
        data = data1 ;
        next = nullptr ;
        prev = nullptr ;
    }
} ;

Node* arrayDLL(int arr[] , int n ){
    Node* head = new Node(arr[0]);
    Node* prev = head ;

    for(int i = 1 ; i<n ; i++){
        Node* temp = new Node(arr[i]) ;
        temp->prev = prev ;
        prev->next = temp ; 
        prev = temp ;
    }

    return prev ;
}

int main() {

    int arr[5] = {1,2,3,4,5} ;
    Node* head = arrayDLL(arr,5) ;

    for(int i = 0 ;i<5 ;i++){
        cout<<head->data<<endl;
        head = head->prev;
    }

    return 0;
}