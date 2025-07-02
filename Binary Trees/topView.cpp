// GFG practise 
// finding the top view of a Binary Tree 
// it is done by storing the key value pair in a map and not updating if the value is present in the map 

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans ;
        if(root == NULL) return ans ;
        
        queue<pair<Node* , int>> q ;
        map<int , int> mpp ;
        
        q.push({root , 0}) ;
        
        while(!q.empty()){
            int size = q.size() ;
            
            for(int i = 0 ; i<size ; i++){
                auto temp = q.front() ;
                Node* tempNode = temp.first ;
                int tempVertical = temp.second ;
                
                // if it is not present in the map
                if(mpp.find(tempVertical) == mpp.end()){
                    mpp[tempVertical] = tempNode->data ;
                }
                
                if(tempNode->left != NULL) q.push({tempNode->left , tempVertical-1}) ;
                if(tempNode->right != NULL) q.push({tempNode->right , tempVertical+1}) ;
                
                q.pop() ;
            }
        }
        
        for(auto it : mpp){
            ans.push_back(it.second) ;
        }
        return ans ;
    }
};