# include <iostream>
using namespace std;

// Creating Node Class 
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


// Deleting the Node Fucntion 

Node* deleteNode(Node* head, int x) {
    
    // if the LL is empty or the LL has only one element and we are asked t delete that element 
    if((head == nullptr) || (head->next == nullptr && x==1)) return nullptr ;
    
    // if the head is to be removed 
    if(head->data == x){
        Node* temp = head ;
        head = head->next ;
        free(temp);
        return head ;
    }
    
    // if any element in the between is to be removed 

    Node* temp = head ;
    Node* prev = nullptr ;
    
    while(temp != nullptr){
        if(temp->data==x){
            prev->next = prev->next->next ;
            free(temp) ;
            break ;
        }
        prev = temp ;
        temp = temp->next ;
    }
    
    return head ;
}

int main() {

    // Converting the array to a linked list :

    int arr[5] = {1,2,3,4,5} ;

    Node* head = new Node(arr[0], nullptr) ; // Head node -> Constructor number 2 is called 

    Node* mover = head ; // a mover pointer is pointing to the head 

    for(int i = 1 ;i<5; i++){ 
        Node* temp = new Node(arr[i],nullptr) ; // new node is created 
        mover->next = temp ; // the next of the mover is now pointing to the next node named temp 
        mover = mover->next ; // the next of previous element is pointing to the temp ie the next element 
    }

    // Calling the Function and printing the values of the LL:
    
    Node* tem = deleteNode(head,5) ;

    while(tem != NULL){
        cout<<tem->data<<" ";
        tem=tem->next;
    }

    return 0;
}