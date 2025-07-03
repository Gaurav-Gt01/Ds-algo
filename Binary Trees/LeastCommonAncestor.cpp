// LC 236 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root ;

        if(root == p || root == q){
            return root ;
        }

        TreeNode* left = lowestCommonAncestor(root->left , p , q) ;
        TreeNode* right = lowestCommonAncestor(root->right , p , q) ;

        // if left is NULL then return right 
        if(left == NULL){
            return right ;
        }
        // if right is NULL then return left 
        else if(right == NULL){
            return left ;
        }
        // if no one is NULL we find our answer ans we return the node 
        else{
            return root ;
        }
    }
};