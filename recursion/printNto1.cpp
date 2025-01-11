# include <iostream>
using namespace std;

void print(int n ){
    if(n>=1){
        cout<< n<<endl ;
        n--;
        print(n);
    }else return ;
}

int main(){
    int n ;
    cin>>n ;
    print(n);
}