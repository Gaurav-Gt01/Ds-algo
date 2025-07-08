//Inorder Sucessor found by keeping a variable sucessor everytime you find a element who is more than target and then move left 

/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* sucessor = NULL ;
    

    int inOrderSuccessor(Node *root, Node *x) {
        
        if(root == NULL){
            if(sucessor != NULL) return sucessor->data ;
            else return -1 ;
        } ;
        
        if(root->data > x->data){
            sucessor = root ;
            return inOrderSuccessor(root->left , x);
        }else{
            return inOrderSuccessor(root->right , x) ;
        }
        
        return sucessor->data  ;
    }
};