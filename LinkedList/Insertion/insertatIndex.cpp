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

Node* instertatIndex(Node* head , int ele , int i){


    //if we are told to add the node of an non existant linked list  :
    if(head==nullptr){
        if(i==1){
            Node* onenode = new Node(ele);
            return onenode ;
        }else{
            return nullptr ;
        }
    }

    // if we are told to add the node at the head 
    if(i==1){
        Node* firstnode = new Node(ele);
        firstnode->next = head ;
        return firstnode ;
    }

    // if we are asked to add the node at any other index :
    Node* temp = head ;
    int cnt = 1 ;

    while(temp != nullptr){
        if(cnt > i) break ;
        if(cnt == i-1){
            Node* inserttedNode = new Node(ele) ;
            inserttedNode->next = temp->next ;
            temp->next = inserttedNode ;
        }
        temp = temp->next ;
        cnt++;
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

    Node* ans = instertatIndex(head , 5 , 5) ;

    while(ans != nullptr){
        cout<<ans->data<<endl;
        ans = ans->next ;
    }

    return 0;
}