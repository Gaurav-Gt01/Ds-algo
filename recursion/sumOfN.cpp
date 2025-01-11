#include <iostream>
using namespace std ;

// functional way - here we ruturn something to the main block 
int sumofN(int n){
    if(n==1) return 1;
    else{
        return n+sumofN(n-1);
    }
}

// parameterised Way - here we print something and do not retrun anything to the main block .
void sumPara(int n , int sum){
    if(int i = 1 <=n){
        sumPara(n-1,sum+n);
        return ;
    }else{
         cout<<sum;
         return;
    }
    

}

int main(){
    int n ;
    cin>>n ;
    //functional 
    sumofN(n);
    cout<<sumofN(n)<<endl;

    //parameterised 
    sumPara(n,0);

}

// time complexity = 0(N)
// space complexity = 0(N)