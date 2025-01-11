#include <iostream>

using namespace std ;

void pattern1(int n ){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout << j << " ";

        }

        cout <<endl;
    }
    /*
    
    1 
    1 2 
    1 2 3 
    1 2 3 4 
    1 2 3 4 5 
    
    */
}
void pattern2(int n ){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout << i << " ";

        }

        cout <<endl;
    }
    /*
    
    1 
    2 2 
    3 3 3 
    4 4 4 4 

    */
}
void pattern3(int n ){
    for(int i = n ; i >= 1 ; i = i - 1 ){
        for(int j = i ; j >= 1 ; j = j - 1){
            cout << "*  ";

        }

        cout <<endl;
    }
    /*

* * *
* *
*

*/
}
void pattern4(int n ){
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= n + 1 - i ; j++){
            cout<< j << " " ;
        }
        
        cout <<endl;
    }
/*

1 2 3
1 2 
1 

*/
}
void pattern5(int n ){
    for(int i = 0 ; i < n ; i++ ){
        // space 
        for(int j = 0 ; j < i ; j ++){
            cout<< " " ;
        }

        // star 
        for(int j = 0 ; j < (n*2) - (2*i) - 1  ; j++ ){
            cout<<"*" ;
        }

        // space 
        for(int j = 0 ; j < i  ; j ++){
            cout<< " " ;
        }

        cout <<endl;
    }
    /*
    * * * * *
      * * *
        * 
    */
}

void pattern6(int n){
    for(int i = 0 ; i <= 5 ; i++){

        int num ;

        if(i%2 == 0 ) int num = 0 ;
        else num = 1 ;
        
        for(int j = 1 ; j <= i ; j++){
            cout<< num  ; 
            num = 1 - num ;
        }
    cout<< endl ;
    }

    for(int i = 1 ; i <= j )
}


void pattern7(int n){
    for(int i = 1 ; i <= n ; i++){
        // num 
        for(int j = 1 ; j <= i ;  j++ ){
            cout<< j ;
        }

        //space 
        for(int j = 1 ; j <= 2*n -2*i ; j ++){
            cout<< " ";
        }

        //num 
        for(int j = i  ; j >= 1 ; j-- ){
            cout << j  ;
        }
    cout<< endl ;

    }
    /*
    
    1        1
    12      21
    123    321
    1234  4321
    1234554321

    */
}

void pattern8(int n ){
    int num = 1 ; 

    for(int i = 1 ; i <= n ; i++){
        
        for(int j = 1 ; j <= i ; j++){
            cout << num << " ";
            num = num + 1  ;
        }

        cout <<endl;
    }
    /*
    1 
    2 3 
    4 5 6 
    7 8 9 10 
    */
}

void pattern9(int n ){

    for(int i = 1 ; i <= n ; i++){
        
        for(char ch = 'A' ; ch  < 'A' + i  ; ch++){
            cout << ch << " ";
        }

        cout <<endl;
    }
}

void pattern10(int n ){

    for(int i = 0 ; i <= n ; i++){
        
        for(char ch = 'A' ; ch  < 'A' + n - i   ; ch++){
            cout << ch << " ";
        }

        cout <<endl;
    }
    /*

    A B C D E 
    A B C D 
    A B C 
    A B 
    A 

    */
}

void pattern11(int n){
    for(int i = 1 ; i <= n ; i++){
        char print  = 'A' + i - 1  ;
        for(char ch = 'A' ; ch < 'A' + i ; ch++ ){
            cout<< print ;
            
        }
    
    cout<< endl ;
    }
    /*
    A
    BB
    CCC
    DDDD
    EEEEE

    */
}

void pattern12(int n){
    for(int i = 0 ; i<= n ; i++){
        char ch = 'A';
        // space 
        for(int j = 1 ; j < n-i ; j++){
            cout<<" " ;
        }
        // alphabet print  
        for(int j = 1 ; j <= 2*i - 1 ; j++){
            cout<< "*"  ;
           
        }

        //space 
        for(int j = 1 ; j < n-i ; j++){
            cout<<" " ;
        }

        cout<< endl;
    }
}

int main(){

    int n ;
    cin >> n ;
    
    for(int i = 0 ; i <= n ; i++){
        int p ;
        cin>> p ; 
        pattern12(p) ;
    }
    

    return 0;
}

