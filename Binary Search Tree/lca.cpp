//LC 235 
// Find the Least Common Ancestor 

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
        if(root == NULL || root==p || root == q) return root ;

        // both are on different sides of the root .... Answer Node 
        if((p->val < root->val && root->val < q->val) || (p->val > root->val && root->val > q->val)) return root ;
        // both are on left side .... Go left 
        else if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left , p , q) ;
        // both are on right side .... Go right 
        else if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right , p , q) ;
        return NULL ;
    }
};