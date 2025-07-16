# include <iostream>
using namespace std;

int main() {
    int m , n;
    cout<<"Enter the number of edges (m) and the Nodes(n) :" ;
    cin>>m>>n ;
    vector<int> adj[n+1] ;

    // this runs for the number of edges :
    for(int i = 0 ; i<m ; i++){
        int u , v ;
        cout<<"Enter the edges that is u and v : " ;
        cin>>u>>v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    // print the list storing the edges :
    for(int i = 0 ; i<=m ; i++){
        for(int j = 0 ; j<adj[i].size() ; j++){
            cout<<adj[i][j]<<" " ;
        }
        cout<<endl;
    }
    return 0;
}