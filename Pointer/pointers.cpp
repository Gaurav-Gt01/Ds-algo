# include <iostream>

using namespace std ;

int main(){
    int x = 5 ;
    int *y = &x ;
    (*y)++;
    cout<<*y ;
    return 0 ;
}

