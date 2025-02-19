# include <iostream>
using namespace std;

struct Node{
    int data ;
    Node* next ;

// Constructor called when both the data and the argument is passed (constructor 1 )
    Node(int data1 , Node* next1){
        data = data1 ;
        next = next1 ;
    }
// Constructor called when only data is passed as an argument (constructor 2)
    Node(int data1){
        data = data1 ;
        next = nullptr;
    }

};

int main() {

    int arr[5] = {1,2,3,4,5} ;
    Node* head = new Node(arr[0]);
    Node* mover = head ;

    for(int i = 1 ; i<5 ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp ;
        mover = temp ;
    }

    // start of the travesrsal 
    mover = head ;
    int cnt = 0 ;

    while(mover){ // This runs until mover exists after that it stops 
        cout<<mover->data<<endl;
        mover= mover->next ;
        cnt++ ;
    }
    // end of the traversal 

    cout<<cnt ;

    return 0;
}