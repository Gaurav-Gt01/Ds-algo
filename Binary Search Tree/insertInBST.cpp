// insert a node in a BST 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* newNode = new TreeNode(val) ;
            return newNode ;
        }
        
        TreeNode* prev = NULL ;
        TreeNode* dummyNode = root ;

        while(root){
            if(root->val < val){
                prev = root ;
                root = root->right ;
            }else{
                prev = root ;
                root = root->left ;
            }
        }

        TreeNode* newNode = new TreeNode(val) ;
        if(prev->val < val) prev->right = newNode ;
        else prev->left = newNode ;

        return dummyNode ;
    }
};