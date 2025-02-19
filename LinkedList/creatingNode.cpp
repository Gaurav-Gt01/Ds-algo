# include <iostream>

using namespace std ;

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
// 1. Create a head node 
// 2. Create a second node and store its pointer to a variable temp.
// 3. Then replace null ptr of the last node with the pointer of the next node .

int main(){
    int arr[5] = {1,2,3,4,5} ;

    Node* head = new Node(arr[0], nullptr) ; // Head node -> Constructor number 2 is called 

    Node* mover = head ; // a mover pointer is pointing to the head 

    cout<<mover->data<<" "<<mover->next<<" "<<mover<<endl;

    for(int i = 1 ;i<5; i++){ 
        Node* temp = new Node(arr[i],nullptr) ; // new node is created 
        mover->next = temp ; // the next of the mover is now pointing to the next node named temp 
        mover = mover->next ; // the next of previous element is pointing to the temp ie the next element 
    }

    cout<<head->data<<" "<<head->next<<" "<<head;
    return 0 ;


    // Points to remeber is that any change made to a pointer makes the changes to the object it is pointing to
}

