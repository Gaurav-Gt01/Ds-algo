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

Node* deleteTail(Node* head){
    Node* temp = head ;


    while(temp->next->next != nullptr){
        cout<<temp->data<<endl;
        temp = temp->next ;
    }

    temp->next = nullptr ;
    temp = temp->next ;
    free(temp);

    return head;
}

int main() {

    int arr[5] = {1,2,3,4,5} ;

    Node* head = new Node(arr[0], nullptr) ; // Head node -> Constructor number 2 is called 

    Node* mover = head ; // a mover pointer is pointing to the head 

    for(int i = 1 ;i<5; i++){ 
        Node* temp = new Node(arr[i],nullptr) ; // new node is created 
        mover->next = temp ; // the next of the mover is now pointing to the next node named temp 
        mover = mover->next ; // the next of previous element is pointing to the temp ie the next element 
    }

    Node* answer = deleteTail(head);

    return 0 ;

}