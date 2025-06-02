# include <iostream>
using namespace std;

// set the rightmost unset bit :
int setBit(int n ){
    int cnt = 0 ;
    int N = n ;

    while(n%2 != 0){
        n = n >> 1 ;
        cnt++ ;
    }

    return N | (1 << cnt ) ;
}

// swap using xor operator :
void swap(int &a , int &b){
    a = a ^ b ;
    b = a ^ b ;
    a = a ^ b ;
}

int main() {

    cout<<setBit(27) << endl ;

    int a = 10 ;
    int b = 20 ;
    swap(a,b) ;

    cout<< a <<" "<< b ;
    
    return 0;
}