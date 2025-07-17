class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans ;
        vector<int> visited(adj.size(),0) ;
        
        if(adj.size() == 0) return ans ;
        
        dfsTraversal(0,visited,adj,ans) ;
        
        return ans ;
    }
    
    void dfsTraversal(int node , vector<int> &visited , vector<vector<int>> &adj , vector<int> &ans){
        visited[node] = 1 ;
        ans.push_back(node) ;
        for(auto it : adj[node]){
            if(visited[it] != 1){
                dfsTraversal(it , visited, adj,ans) ;
            }
        }
        return ;
    }
};