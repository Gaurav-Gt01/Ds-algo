# include <iostream>
using namespace std;
int i = 1;
void print(int n ){
    while(i<=n){
        cout<< i ;
        cout<<" ";
        i++;
        print(n);
    }
    return;
}

int main(){
    int n ;
    cin>>n ;
    print(n);
}