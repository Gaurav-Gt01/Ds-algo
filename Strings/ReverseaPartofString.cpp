# include <iostream>
using namespace std;

void reverserg(int start , int end , string& s){
    while(start<end){
        char temp = s[end] ;
        s[end] = s[start] ;
        s[start]= temp ;
        start++ ;
        end-- ;
    }
}

int main() {

    string a = "1234 Gaurav" ;
    cout<<a<<endl;
    reverserg(0,3,a) ;
    cout<<a;

    return 0;
}