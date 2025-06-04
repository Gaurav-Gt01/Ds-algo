# include <iostream>
using namespace std;

// the mat would contain the map of the chess board and the positions having the queens would be set as 0 
bool safePosition(vector<vector<int>> mat , int n , int row , int col){

    int flag = 1 ;
    // check if row and column are safe
    for(int i = 0 ; i<n ; i++){
        if(mat[row][i] == 0 || mat[i][col] == 0){
            flag = 0 ;
            break ;
        }
    }
    if(flag == 0) return false ;

    // check if the position is diagonally safe 
    int i = row ;
    int j = col ;
    while(i<n && j<n){
        if(mat[i][j] == 0){
            flag = 0 ;
            break ;
        }
        i++ ;
        j++ ;
    }
    if(flag == 0) return false ;

    i = row ;
    j = col ;
    while(i<n && j>=0){
        if(mat[i][j] == 0){
            flag = 0 ;
            break ;
        }
        i++ ;
        j-- ;
    }
    if(flag == 0) return false ;

    i = row ;
    j = col ;
    while(i>=0 && j<n){
        if(mat[i][j] == 0){
            flag = 0 ;
            break ;
        }
        i-- ;
        j++ ;
    }
    if(flag == 0) return false ;

    i = row ;
    j = col ;
    while(i>=0 && j>=0){
        if(mat[i][j] == 0){
            flag = 0 ;
            break ;
        }
        i-- ;
        j-- ;
    }

    if(flag == 0) return false ;

    return true ;

}

int main() {
    vector<vector<int>> mat = {{1,1,0,1},{0,1,1,1},{1,1,1,1},{1,0,1,1}} ;
    int n = 4 ;
    bool safePos = safePosition(mat , 4 , 2 , 3) ;

    cout<<"the position is :"<< safePos <<endl;

    return 0;
}