// LC 98
// Validate a BST 
// intution is that always the value of a node would be in a range and we just check if it is in the range 

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX) ;
    }

    bool isValidBST(TreeNode* root , long long minValue ,long long maxValue){
        if(root == NULL) return true ;

        if(root->val <= minValue || root->val >= maxValue) return false ;

        return isValidBST(root->left , minValue , root->val) && isValidBST(root->right , root->val , maxValue) ;
    }
};