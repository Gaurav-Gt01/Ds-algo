// GFG practise Quesion 
// Here we need to find the boundary of a BT and it is modularised into 3 seperate functions 

/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> ans ;
    stack<int> st ;
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        // add the root node 
        
        if (!(root->left == NULL && root->right == NULL))
        ans.push_back(root->data);
        
        // Left Boundary 
        if(root->left != NULL){
            leftBoundary(root->left) ;
        }
        
        // Add the leaf Nodes 
        leafNodes(root) ;
        
        // Right Boundary reversed 
        if(root->right != NULL){
            rightBoundary(root->right) ;
        }
        while(!st.empty()){
            ans.push_back(st.top()) ;
            st.pop() ;
        }
        
        return ans ;
    }
    
    void leftBoundary(Node * root){
        if((root == NULL ) || (root->left == NULL && root->right == NULL)) return ;
        
        ans.push_back(root->data) ;
        
        if(root->left != NULL)leftBoundary(root->left) ;
        else leftBoundary(root->right) ;
    }
    
    void leafNodes(Node* root){
        // similar to preorder traversal root left right 
        if(root == NULL) return ;
        
        if((root->left==NULL) && (root->right==NULL)) ans.push_back(root->data) ;
        
        leafNodes(root->left) ;
        leafNodes(root->right) ;
    }
    
    void rightBoundary(Node* root){
        
        if((root == NULL) || (root->left==NULL && root->right==NULL)) return ;
        
        st.push(root->data) ;
        
        if(root->right != NULL) rightBoundary(root->right) ;
        else rightBoundary(root->left) ;
    }
    
    
    
    
    
    
    
    
    
    
    
    
};