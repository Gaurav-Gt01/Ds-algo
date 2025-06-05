# include <iostream>
using namespace std;

class stackUingArray{
    public :

    static const int n = 10 ;
    int topp = -1 ;
    int st[n] ;
    int size = 0 ;

    void push(int x){
        if(topp >= n){
            cout<<"invalid operation"<<endl ;
            return ;
        }
        topp++ ;
        st[topp] = x ;
        size++ ;
    }
    
    void pop(){
        if(topp == 0){
            cout<<"invalid operation"<<endl ;
            return ;
        }
        topp-- ;
        size-- ;
    }
    
    void top(){
        if(topp >= n){
            cout<<"Invalid operation"<<endl;
            return  ;
        }
        cout<<"The top of the stack is :"<<st[topp]<<endl ;
    }

    int sizee(){
        return size ;
    }

    void printStack(){
        for(int i = topp ; i>=0 ; i--){
            cout<<st[i]<<endl ;
        }
    }


} ;


int main() {
    stackUingArray stack1 ;

    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    cout<<"The size of the stack "<<stack1.sizee()<<endl;
    stack1.pop() ;
    stack1.pop() ;
    stack1.pop() ;
    stack1.top();
    stack1.top();
    cout<<"The size of the stack "<<stack1.sizee()<<endl;
    stack1.printStack() ;

    
 
    return 0;
}