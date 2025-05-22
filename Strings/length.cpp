# include <iostream>
using namespace std;

int getLength(char ch[]){
    int i = 0 ;
    int cnt = 0 ;
    while(ch[i] != '\0'){
        i++ ;
        cnt++ ;
    }
    return cnt ;
}

int main() {
    char name[10] ;
    cout<<"Enter your name " ;
    cin>>name ;
    cout<<getLength(name) ;

    return 0;
}