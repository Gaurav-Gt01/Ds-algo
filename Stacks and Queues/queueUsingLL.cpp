# include <iostream>
using namespace std;

struct Node{

    Node* next ; 
    int data ;

    // default constructor 
    Node(int data1 , Node* next1){
        data = data1 ;
        next = next1 ;
    }

    // default constructor 
    Node(int data1 ){
        data = data1 ;
        next = nullptr ;
    }

};

class queueUsingLL{
    public :
    Node* start = nullptr;
    Node* end = nullptr ;
    int currentSize = 0 ;

    void push(int x){
        Node* temp = new Node(x) ;
        if(currentSize == 0){
            start = temp ;
            end = temp ;
        }else{
            end->next = temp ;
            end = temp ;
        }
        currentSize++ ;
    }

    void pop(){
        Node* temp = start;
        start = start->next ;
        delete(temp) ;
        currentSize-- ;
    }

    void top(){
        cout<<"The top element is :"<<start->data<<endl ;
    }

    void getSize(){
        cout<<"The current Size of the Queue is :"<<currentSize<<endl;
    }

    void printQueue(){
        Node* temp = start ;
        while(temp != NULL){
            cout<<temp->data<<endl;
            temp = temp->next ;
        }
    }
} ;

int main() {
    queueUsingLL queue1 ;
    queue1.push(2) ;
    queue1.push(3) ;
    queue1.push(4) ;
    queue1.push(5) ;
    queue1.push(6) ;
    queue1.top();
    queue1.getSize() ;
    queue1.push(7) ;
    queue1.pop() ;
    queue1.pop() ;
    queue1.top();
    queue1.pop() ;
    queue1.getSize() ;

    queue1.printQueue() ;

    return 0;
}