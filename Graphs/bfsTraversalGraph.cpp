// TC = O(N)+O(2E) that is the outer loop runs for total of N times that is the number of nodes and the inner loop runs for 2*E times as that is what is stored in the adjecency list 
// SC = 0(2N) the queue and the visited array both of size N .

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        
        // size of the adj List that denotes the number of nodes 
        int n = adj.size() ;
        queue<int> q ;
        // Visited array of size n and set it to zero 
        int visited[n] = {0} ;
        // ans vector , push the initial node in the queue 
        vector<int> ans ;
        if(n == 0) return ans ;
        q.push(0) ;
        visited[0] = 1 ;
        
        // run the loop till the q is not empty 
        while(!q.empty()){
            int temp = q.front() ;
            q.pop() ;
            ans.push_back(temp) ;

            for(auto it : adj[temp]){
                if(visited[it] != 1) q.push(it) ;
                visited[it] = 1 ;
            }
            
        }
        return ans ;
    }
};