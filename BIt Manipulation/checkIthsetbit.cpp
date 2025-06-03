# include <iostream>
using namespace std;

int main() {
    int num  ;
    int i  ;

    cout<<"Enter the number :";
    cin>>num ;
    cout<<endl;

    cout<<"Enter the bit to be checked :" ;
    cin>>i ;
    cout<<endl;

    if(num & (1 << i)){
        cout<<"Bit is set  "<<endl;
    }else{
        cout<<"Bit is not set "<<endl ;
    }

    return 0;
}