# include <iostream>
using namespace std;

class queueUsingArray {
    public:

    int start = -1 ;
    int end = -1 ;
    static const int n = 10 ;
    int q[n] ;
    int currentSize = 0 ;

    void push(int x){
        if(currentSize == n) return ;
        if(currentSize == 0){
            start++;
            end++;
        }else{
            end = (end+1) % n ;
        }
        q[end] = x ;
        currentSize++ ;
    }

    void pop(){
        if(currentSize == 0) return ;
        if(currentSize == 1){
            start = -1 ;
            end = -1 ;
        }else{
            start = (start+1) % n ;
        }
        currentSize-- ;
    }

    void top(){
        cout<<"The top of the queue is :"<<q[start]<<endl;
    }

    void getSize(){
        cout<<"The current size of the queue is :"<<currentSize<<endl ;
    }

    void printQueue(){
        for(int i = start ; i <= end ; i++){
            cout<<q[i]<<endl;
        }
    }

};

int main() {
    queueUsingArray queue1 ;
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