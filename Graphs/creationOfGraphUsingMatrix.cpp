# include <iostream>
using namespace std;

int main() {
    int m , n ;
    cout<<"Enter the number of edges and nodes m and n ";
    cin>>m>>n ;
    // m is the number of edges and n is the number of nodes 
    int adj[n+1][n+1] ;
    memset(adj , 0 , sizeof(adj)) ;

    for(int i = 0 ; i<m ; i++){
        cout<<"Enter the two nodes"<<endl;
        cout<<"Enter u" ;
        int u ;
        cin>>u ;
        cout<<"Enter v" ;
        int v ;
        cin>>v ;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
    }

    for(int i = 0 ; i<n+1 ; i++){
        for(int j = 0 ; j<n+1 ; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}