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

    Node* head = new Node(01,nullptr);
    cout<<head->next<<endl;

    Node* node2 = new Node(02,nullptr) ;

    head->next = node2 ;

    cout<<head->next<<" "<<node2;

    return 0;
}