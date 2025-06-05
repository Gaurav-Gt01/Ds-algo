# include <iostream>
using namespace std;

struct Node{
    Node* next ;
    int data ;

    // constructor
    Node(int data1 , Node* next1){
        data = data1 ;
        next = next1 ;
    }

    // constructor
    Node(int data1 ){
        data = data1 ;
        next = NULL ;
    }
};

class stackUsingLL{
    public :
    Node* top = nullptr ;
    int currentSize = 0  ;

    void push(int x){
        Node* temp = new Node(x,top) ;
        top = temp ;
        currentSize++ ;
    }

    void pop(){
        Node* temp = top ;
        top = top->next ;
        currentSize-- ;
    }

    void topp(){
        cout<<"The current top element of the stack is :"<< top->data<<endl ;
    }

    void getSize(){
        cout<<"The current size of the stack is :"<<currentSize<<endl ;
    }

    void printStack(){
        while(top != NULL){
            cout<<top->data<<endl;
            top = top->next ;
        }
    }

};

int main() {
    stackUsingLL stack1 ;

    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    stack1.topp();
    stack1.getSize();
    stack1.pop() ;
    stack1.pop() ;
    stack1.pop() ;
    stack1.topp();
    stack1.getSize();
    stack1.printStack() ;

    return 0;
}