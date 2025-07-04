// Ceil is the smallest element which is larger than the given element 

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    int ceil = -1 ;
    while(root){
        if(input == root->data){
            return root->data ;
        }
        else if(input > root->data){
            root = root->right ;
        }
        else{
            ceil = root->data ;
            root = root->left ;
        }
    }
    return ceil ;
}