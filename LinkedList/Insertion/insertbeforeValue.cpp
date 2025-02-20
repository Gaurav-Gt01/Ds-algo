# include <iostream>
using namespace std;

struct Node{
    int data ;
    Node* next ;

    Node(int data1){
        data = data1 ;
        next = nullptr ;
    }
};





// Main Function For the Insertion at a particular Value :


Node* instertbeforeValue(Node* head , int ele , int i ){


    //if we are told to add the node of an non existant linked list  :
    if(head==nullptr){
        return nullptr ;
    }

    // if we are told to add the node at the head 
    if(head->data==i){
        Node* firstnode = new Node(ele);
        firstnode->next = head ;
        return firstnode ;
    }

    // if we are asked to add the node at any other index :
    Node* temp = head ;
    Node* prev = nullptr ;

    while(temp != nullptr){
        if(temp->data==i){
            Node* newNode = new Node(ele) ;
            newNode->next = temp ;
            prev->next = newNode ;
        }
        prev = temp ;
        temp = temp->next ;

    }
    return head ;
}




int main() {

    int arr[5] = {2,4,6,8,10} ;

    Node* head = new Node(arr[0]) ;
    Node* mover = head ;
    cout<<head->data<<endl;

    for(int i = 1 ; i<5 ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp ;
        mover = temp ;
        cout<<temp->data<<endl;
    }
    cout<<endl ;

    Node* ans = instertbeforeValue(head , 3 ,100) ;

    while(ans != nullptr){
        cout<<ans->data<<endl;
        ans = ans->next ;
    }

    return 0;
}