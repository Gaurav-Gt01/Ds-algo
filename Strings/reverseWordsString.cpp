# include <iostream>
using namespace std;
// reverse a string 
string reverser(string input){

    int end = input.length() - 1 ;
    int i = 0 ;

    while(i<end){
        char temp = input[i];
        input[i] = input[end] ;
        input[end] = temp ;
        end-- ;
        i++ ;
    }
    return input ;    
}

string reverseWordsofString(string str){
    string answer = "" ;
    int i = 0 ;
    string word  ;
    int j = 0 ;

    while(i < str.length()){
        for(j = i ; str[j] != ' ' && str[j] != '\0' ; j++){
          word.push_back(str[j]) ;  
        }
        string revWrd = reverser(word) ;

        for(int a = 0 ; a < revWrd.length() ; a++ ){
            answer.push_back(revWrd[a]) ;
        }
        answer.push_back(' ') ;

        revWrd.clear() ;
        word.clear() ;
        i = j+1 ; ;
    }
    answer.pop_back() ;

    return answer ;
}

int main() {

    cout<<"The reversed sting is :"<<endl ;
    cout<<reverseWordsofString("My name is Gaurav") ;

    return 0;
}