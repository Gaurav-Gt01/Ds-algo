// GFG practise 
// finding the bottom view of a binary tree 
// it is done by storing and updating the key value pair in a map 

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
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans ;
        
        queue<pair<Node* , int>> q ;
        // node , vertical
        map<int,int> mpp ;
        // vertical , value 
        
        if(root==NULL) return ans ;
        q.push({root , 0}) ;
        
        while(!q.empty()){
            int size = q.size() ;
            for(int i = 0 ; i<size ; i++){
                // creating variables for ease 
                auto temp = q.front() ;
                Node* tempNode = temp.first ;
                int verticalTemp = temp.second ;
                
                // inserting the value in the map according to the queue
                mpp[verticalTemp] = tempNode->data ;
                
                if(tempNode->left != NULL) q.push({tempNode->left , verticalTemp-1}) ;
                if(tempNode->right != NULL) q.push({tempNode->right , verticalTemp +1}) ;
                q.pop() ;
            }
        }
        
        // iterator used to traverse the map 
        // the value would be it.second and not mpp[it] 
        for(auto it : mpp){
            ans.push_back(it.second) ;
        }
        
        return ans ;
    }
};