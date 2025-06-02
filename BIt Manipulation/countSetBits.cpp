# include <iostream>
using namespace std;

int main() {

    int x = 11 ;
    int cnt = 0 ; 

    while(x != 0) {
        x = x & (x-1) ;
        cnt++ ;
    }

    cout<< cnt;

    return 0;
}